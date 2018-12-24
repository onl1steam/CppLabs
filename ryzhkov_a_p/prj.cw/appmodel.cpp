#include "appmodel.h"
#include "QDate"
#include "QDebug"
#include "QString"

void AppModel::define_dayOfWeek()
{
    for(int i = 0; i < 5; i++) {
        QDate date = QDate().currentDate();
        QString str = date.addDays(i).toString("ddd");
        forecast[i].dayOfWeek = str;
    }
}

QString AppModel::getUrl(const QString &city)
{
    url = "http://api.worldweatheronline.com/premium/v1/weather.ashx?key=cebcb30c79bb4211936200546180112&tp=24&num_of_days=5&format=json&lang=ru&q=" + city;
    return url;
}

// setters

void AppModel::setCity(const QString &value)
{
    city = value;
}

void AppModel::setDayOfWeek(const int &index, const QString &value)
{
    forecast[index].dayOfWeek = value;
}

void AppModel::setDescription(const int &index, const QString &value)
{
    forecast[index].description = value;
}

void AppModel::setFeels_Like(const int &index, const QString &value)
{
    forecast[index].feels_like = value;
}

void AppModel::setHumidity(const int &index, const QString &value)
{
    forecast[index].humidity = value;
}

void AppModel::setPrecipitation(const int &index, const QString &value)
{
    forecast[index].precipitation = value;
}

void AppModel::setPressure(const int &index, const QString &value)
{
    forecast[index].pressure = value;
}

void AppModel::setTemperature(const int &index, const QString &value)
{
    forecast[index].temperature = value;
}

void AppModel::setWeatherCode(const int &index, const QString &value)
{
    forecast[index].weatherCode = value;
}

void AppModel::setWind(const int &index, const QString &value)
{
    forecast[index].wind = value;
}


// getters

QString AppModel::getDayOfWeek(const int &index)
{
    return forecast[index].dayOfWeek;
}

QString AppModel::getCity()
{
    return city;
}

QString AppModel::getDescription(const int &index)
{
    return forecast[index].description;
}

QString AppModel::getFeels_Like(const int &index)
{
    return forecast[index].feels_like;
}

QString AppModel::getHumidity(const int &index)
{
    return forecast[index].humidity;
}

QString AppModel::getPrecipitation(const int &index)
{
    return forecast[index].precipitation;
}

QString AppModel::getPressure(const int &index)
{
    return forecast[index].pressure;
}

QString AppModel::getTemperature(const int &index)
{
    return forecast[index].temperature;
}

QString AppModel::getWeatherCode(const int &index)
{
    return forecast[index].weatherCode;
}

QString AppModel::getWind(const int &index)
{
    return forecast[index].wind;
}











