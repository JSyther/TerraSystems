#pragma once

#include <Arduino.h>

class AudioSensor
{
public:
    void Initialize();
    bool Update();

    int GetLevel() const;
    bool IsDetected() const;

private:
    int m_Level = 0;
    bool m_Detected = false;

    unsigned long m_LastSampleTime = 0;
    unsigned long m_LastTriggerTime = 0;
};

extern AudioSensor GAudioSensor;