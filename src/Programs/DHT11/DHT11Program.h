#pragma once

#include "Sensors/DHT11/DHT11Sensor.h"


class DHT11Program
{
private:

    DHT11Sensor Sensor;
    
private:
    void UpdateTemperatureState(float Temperature);

public:
    void Begin();
    void Update();

};

extern DHT11Program GDHT11Program;