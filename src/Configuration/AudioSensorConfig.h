#pragma once

#include <Arduino.h>

namespace AudioSensorConfig
{
    // Analog sound threshold, from 0 to 1023.
    // Calibrate this value based on ambient noise.
    constexpr int Threshold = 220;

    // Time between sound level measurements.
    constexpr unsigned long SampleIntervalMs = 20;

    // Delay before the sensor can trigger again.
    constexpr unsigned long CooldownMs = 300;

    // Print raw audio levels to the Serial Monitor.
    constexpr bool DebugEnabled = false;

    constexpr unsigned long DebugIntervalMs = 10;

    // Number of analog samples used for one measurement.
    constexpr uint8_t SampleCount = 32;

    // Delay between analog samples.
    constexpr unsigned int SampleDelayUs = 200;

    constexpr unsigned long DetectionMessageDurationMs = 2000;
}