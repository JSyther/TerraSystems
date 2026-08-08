#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Display
{
    
private:
    LiquidCrystal_I2C LCD{0x27, 16, 2};

    char LastTop[17];
    char LastBottom[17];

    uint8_t GetCenteredColumn(const char* Text) const;

public:
    void Initialize();
    void Clear();

    void Show(const char* Top, const char* Bottom);
    void ShowAnimated(const char* Top, const char* Bottom, float DurationSeconds);
    void Blink(const char* Top, const char* Bottom, uint8_t Count, float IntervalSeconds);
    void FloatText(const char* Top, const char* Bottom, float DurationSeconds);
};

extern Display GDisplay;