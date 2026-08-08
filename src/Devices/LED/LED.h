#pragma once

#include <Arduino.h>

class LED
{
public:
    void Initialize();

    void Update();

    // General
    void On();
    void Off();

    // Red LED
    void EnableRed();
    void DisableRed();
    void BlinkRed(uint8_t Count, float IntervalSeconds);
    bool IsRedOn() const;

    // Green LED
    void EnableGreen();
    void DisableGreen();
    void BlinkGreen(uint8_t Count, float IntervalSeconds);
    bool IsGreenOn() const;

private:
    bool bRedLedEnabled = false;
    bool bGreenLedEnabled = false;
};

extern LED GLED;