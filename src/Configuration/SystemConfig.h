#pragma once

#include <Arduino.h>

enum class ESystemState : uint8_t
{
    Initializing,
    Operational,
    Shutdown
};
