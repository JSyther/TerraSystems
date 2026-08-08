#pragma once

#include <Arduino.h>
#include <DHT.h>


class DHT11Sensor
{

private:
    DHT Sensor;
    float Temperature = 0.0f;
    float Humidity = 0.0f;


public:
    DHT11Sensor();

public:
    void Initialize();
    void Update();


public:
    float GetTemperature() const;
    float GetHumidity() const;

};