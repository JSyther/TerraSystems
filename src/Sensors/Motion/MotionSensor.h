#pragma once

#include <Arduino.h>

#include "Configuration/MotionSensorConfig.h"

class MotionSensor
{
public:
    void Initialize();
    void Begin();
    void Update();

    bool IsDetected() const;
    unsigned long GetDisplayDurationMs() const;

private:
    FMotionSensorConfig MotionSensorConfiguration;
};

extern MotionSensor GMotionSensor;