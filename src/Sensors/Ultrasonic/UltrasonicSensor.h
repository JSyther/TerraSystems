#pragma once

#include "Configuration/UltrasonicConfig.h"

class UltrasonicSensor
{
public:
    void Initialize();
    void Update();

    float GetDistance() const;

    bool IsObjectDetected() const;

private:
    void MeasureDistance();

private:
    FUltrasonicSensor Data;
};

extern UltrasonicSensor GUltrasonicSensor;