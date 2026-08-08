#pragma once 

#include <Arduino.h>

enum class EWaterPumpState : uint8_t
{
    Idle,
    PumpStart,
    PumpWait,
    ReverseStart,
    ReverseWait
};
