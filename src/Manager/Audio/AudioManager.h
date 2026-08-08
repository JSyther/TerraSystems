#pragma once

#include <Arduino.h>

class AudioManager
{
public:

    void Initialize();

    // Basic Sounds
    void Beep();
    void DoubleBeep();
    void Error();
    void Success();

    // System Sounds
    void Startup();
    void ShuttingDown();
    void Shutdown();

    // Custom
    void PlayTone(uint16_t Frequency, uint16_t Duration);
    void Stop();
    void PlayAudio(const char* Audio);

    // WaterPump
    void StartWaterPump();
    void StopWaterPump();

    void StartReversePump();
    void StopReversePump();

    void PlayMelody();
};


extern AudioManager GAudioManager;