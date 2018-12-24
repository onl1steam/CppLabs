#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appmodel.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    adjustLabels();
    setDayOfWeek();
    setImages();
}

void MainWindow::setDayOfWeek()
{
    mod->define_dayOfWeek();
    ui->day1->setText(mod->getDayOfWeek(1));
    ui->day2->setText(mod->getDayOfWeek(2));
    ui->day3->setText(mod->getDayOfWeek(3));
    ui->day4->setText(mod->getDayOfWeek(4));
}

void MainWindow::adjustLabels()
{
    // main labels
    ui->main_temp->setGeometry(55-ui->main_temp->text().length() / 2, 220, 70, 70);
    ui->cityLabel->setGeometry(30-ui->cityLabel->text().length() / 2, 50, 450, 15);
    ui->main_description->setGeometry(30-ui->main_description->text().length() / 2, 75, 450, 15);
    ui->feels_like_lbl->adjustSize();
    ui->humidity_lbl->adjustSize();
    ui->wind_lbl->adjustSize();
    ui->precipitation_lbl->adjustSize();
    ui->pressure_lbl->adjustSize();
}

void MainWindow::setImages()
{
    QPixmap img = QPixmap(":/images/weather_icons/113.png");
    // main images
    img = QPixmap(":/images/weather_icons/barometer.png");
    ui->pressure_img->setPixmap(img.scaled(24,24,Qt::KeepAspectRatio));
    img = QPixmap(":/images/weather_icons/precipitation.png");
    ui->precipitation_img->setPixmap(img.scaled(24,24,Qt::KeepAspectRatio));
    img = QPixmap(":/images/weather_icons/feels_like.png");
    ui->feels_like_img->setPixmap(img.scaled(24,24,Qt::KeepAspectRatio));
    img = QPixmap(":/images/weather_icons/humidity.png");
    ui->humidity_img->setPixmap(img.scaled(24,24,Qt::KeepAspectRatio));
    img = QPixmap(":/images/weather_icons/wind.png");
    ui->wind_img->setPixmap(img.scaled(24,24,Qt::KeepAspectRatio));
    img = QPixmap(":/images/weather_icons/113.png");
    // daily images
    ui->day1_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
    img = QPixmap(":/images/weather_icons/113.png");
    ui->day2_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
    img = QPixmap(":/images/weather_icons/113.png");
    ui->day3_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
    img = QPixmap(":/images/weather_icons/113.png");
    ui->day4_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
}

void MainWindow::makeRequest(const QString &city)
{
    mod->setCity(city);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(mod->getUrl(city))));
}

void MainWindow::replyFinished(QNetworkReply* reply)
{
    QJsonParseError parseError;
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll(),&parseError);
    QJsonObject object = document.object();
    QString error = object["data"].toObject()["error"].toArray().at(0)["msg"].toString();
    if (error != "")
    {
        QMessageBox msgBox;
        msgBox.setText("Город не найден!");
        msgBox.exec();
        return;
    }
    QJsonObject data = object["data"].toObject();
    // Распределение данных
    QJsonArray request = data["request"].toArray();
    QJsonValue day1 = data["weather"].toArray().at(0)["hourly"].toArray().at(0);
    QJsonValue day2 = data["weather"].toArray().at(1)["hourly"].toArray().at(0);
    QJsonValue day3 = data["weather"].toArray().at(2)["hourly"].toArray().at(0);
    QJsonValue day4 = data["weather"].toArray().at(3)["hourly"].toArray().at(0);
    QJsonValue day5 = data["weather"].toArray().at(4)["hourly"].toArray().at(0);
    // 1 день
    mod->setDescription(0, day1["lang_ru"].toArray().at(0)["value"].toString());
    mod->setTemperature(0, day1["tempC"].toString() + "°");
    mod->setWeatherCode(0, day1["weatherCode"].toString());
    mod->setFeels_Like(0, day1["FeelsLikeC"].toString() + "°");
    mod->setHumidity(0, day1["humidity"].toString() + "%");
    mod->setWind(0, day1["windspeedKmph"].toString() + " км/ч");
    mod->setPrecipitation(0, day1["precipMM"].toString() + " мм");
    // Перевод давления в атмосферы
    int pressure_val = day1["pressure"].toString().toDouble() / 1.333;
    mod->setPressure(0, QString::number(pressure_val) + " мм рт.ст.");
    // 2 день
    mod->setDescription(1, day2["lang_ru"].toArray().at(0)["value"].toString());
    mod->setTemperature(1, day2["tempC"].toString() + "°");
    mod->setWeatherCode(1, day2["weatherCode"].toString());
    // 3 день
    mod->setDescription(2, day3["lang_ru"].toArray().at(0)["value"].toString());
    mod->setTemperature(2, day3["tempC"].toString() + "°");
    mod->setWeatherCode(2, day3["weatherCode"].toString());
    // 4 день
    mod->setDescription(3, day4["lang_ru"].toArray().at(0)["value"].toString());
    mod->setTemperature(3, day4["tempC"].toString() + "°");
    mod->setWeatherCode(3, day4["weatherCode"].toString());
    // 5 день
    mod->setDescription(4, day5["lang_ru"].toArray().at(0)["value"].toString());
    mod->setTemperature(4, day5["tempC"].toString() + "°");
    mod->setWeatherCode(4, day5["weatherCode"].toString());
    // Город
    QString city = request.at(0)["query"].toString();
    // Заполнение данных
    ui->cityLabel->setText(city);
    setInfo();
}

void MainWindow::setInfo()
{
    QString url;
    QPixmap img;
    // Актуальная дата
    ui->main_temp->setText(mod->getTemperature(0));
    ui->main_description->setText(mod->getDescription(0));
    ui->wind_lbl->setText(mod->getWind(0));
    ui->humidity_lbl->setText(mod->getHumidity(0));
    ui->precipitation_lbl->setText(mod->getPrecipitation(0));
    ui->feels_like_lbl->setText(mod->getFeels_Like(0));
    ui->pressure_lbl->setText(mod->getPressure(0));
    url = ":/images/weather_icons/" + mod->getWeatherCode(0) + ".png";
    img = QPixmap(url);
    ui->actual_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
    // 2 день
    ui->day1_temp->setText(mod->getTemperature(1));
    ui->day1_desc->setText(mod->getDescription(1));
    url = ":/images/weather_icons/" + mod->getWeatherCode(1) + ".png";
    img = QPixmap(url);
    ui->day1_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
    // 3 день
    ui->day2_temp->setText(mod->getTemperature(2));
    ui->day2_desc->setText(mod->getDescription(2));
    url = ":/images/weather_icons/" + mod->getWeatherCode(2) + ".png";
    img = QPixmap(url);
    ui->day2_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
    // 4 день
    ui->day3_temp->setText(mod->getTemperature(3));
    ui->day3_desc->setText(mod->getDescription(3));
    url = ":/images/weather_icons/" + mod->getWeatherCode(3) + ".png";
    img = QPixmap(url);
    ui->day3_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
    // 5 день
    ui->day4_temp->setText(mod->getTemperature(4));
    ui->day4_desc->setText(mod->getDescription(4));
    url = ":/images/weather_icons/" + mod->getWeatherCode(4) + ".png";
    img = QPixmap(url);
    ui->day4_img->setPixmap(img.scaled(64,64,Qt::KeepAspectRatio));
    adjustLabels();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_request_btn_clicked()
{
    makeRequest(ui->cityEdit->toPlainText());
}

void MainWindow::on_repeat_btn_clicked()
{
    makeRequest(mod->getCity());
}

