#pragma once

#include <Arduino.h>

class Buzzer
{
public:
    void Initialize();
    void Play(uint16_t Frequency, uint16_t Duration);
    void Stop();
};

extern Buzzer GBuzzer;