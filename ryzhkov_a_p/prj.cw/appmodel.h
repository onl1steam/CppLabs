#ifndef APPMODEL_H
#define APPMODEL_H

#include "QString"
#include <QtNetwork/QNetworkAccessManager>

class AppModel
{
public:
    AppModel() = default;

    void define_dayOfWeek();
    QString getUrl(const QString &city);

    // setters
    void setPressure(const int &index ,const QString &value);
    void setPrecipitation(const int &index, const QString &value);
    void setWeatherCode(const int &index, const QString &value);
    void setDayOfWeek(const int &index, const QString &value);
    void setTemperature(const int &index, const QString &value);
    void setDescription(const int &index, const QString &value);
    void setHumidity(const int &index, const QString &value);
    void setWind(const int &index, const QString &value);
    void setFeels_Like(const int &index, const QString &value);
    void setCity(const QString &value);

    // getters
    QString getPressure(const int &index);
    QString getPrecipitation(const int &index);
    QString getWeatherCode(const int &index);
    QString getDayOfWeek(const int &index);
    QString getTemperature(const int &index);
    QString getDescription(const int &index);
    QString getHumidity(const int &index);
    QString getWind(const int &index);
    QString getFeels_Like(const int &index);
    QString getCity();

private:

    struct Weather_data
    {
        QString pressure;
        QString precipitation;
        QString weatherCode;
        QString dayOfWeek;
        QString temperature;
        QString description;
        QString humidity;
        QString wind;
        QString feels_like;
    };
    QString city;
    Weather_data *forecast = new Weather_data[5];
    QString url = "http://api.worldweatheronline.com/premium/v1/weather.ashx?key=cebcb30c79bb4211936200546180112&tp=24&num_of_days=5&format=json&lang=ru";
};

#endif // APPMODEL_H
