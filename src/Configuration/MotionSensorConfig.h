#pragma once

#include <Arduino.h>

struct FMotionSensorConfig
{
    // Configuration
    unsigned long WarmupDurationMs = 30000;
    unsigned long CooldownMs = 3000;
    bool bDebugEnabled = true;

    // Runtime data
    bool bDetected = false;
    bool bWasMotionDetected = false;

    unsigned long InitializeTime = 0;
    unsigned long LastTriggerTime = 0;
    unsigned long DisplayDurationMs = 2000;
    unsigned long UpdateIntervalMs = 3000;
    unsigned long LastCheckTime = 0;
};
