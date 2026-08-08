#pragma once

#include <stdint.h>

struct FUltrasonicSensor
{
    float Distance = 0.0f;

    uint16_t MinimumDistance = 2;      // cm
    uint16_t MaximumDistance = 400;    // cm

    uint16_t WarningDistance = 30;     // cm
    uint16_t CriticalDistance = 10;    // cm

    bool bObjectDetected = false;
};

struct FUltrasonicTrigger
{
    uint16_t PulseDuration = 10;       // µs
};

struct FUltrasonicData
{
    FUltrasonicSensor Sensor;
    FUltrasonicTrigger Trigger;
};

namespace UltrasonicConfig
{
    inline FUltrasonicData Data;
}