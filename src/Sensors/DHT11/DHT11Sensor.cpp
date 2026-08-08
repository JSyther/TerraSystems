#include "DHT11Sensor.h"
#include "Configuration/PinConfig.h"


DHT11Sensor::DHT11Sensor()
: Sensor(PinConfig::DHT, DHT11)
{

}


void DHT11Sensor::Initialize()
{
    Sensor.begin();
}


void DHT11Sensor::Update()
{
    float NewHumidity = Sensor.readHumidity();
    float NewTemperature = Sensor.readTemperature();


    if (!isnan(NewHumidity))
    {
        Humidity = NewHumidity;
    }


    if (!isnan(NewTemperature))
    {
        Temperature = NewTemperature;
    }
}


float DHT11Sensor::GetTemperature() const
{
    return Temperature;
}


float DHT11Sensor::GetHumidity() const
{
    return Humidity;
}