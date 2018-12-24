#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "appmodel.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setInfo();
    void setDayOfWeek();

    void makeRequest(const QString &city);
    void adjustLabels();
    void setImages();

public slots:

    void replyFinished(QNetworkReply* reply);

private slots:

    void on_request_btn_clicked();
    void on_repeat_btn_clicked();

private:
    AppModel *mod = new AppModel;
    Ui::MainWindow *ui;
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
};

#endif // MAINWINDOW_H
