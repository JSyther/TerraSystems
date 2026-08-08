#pragma once

#include "Sensors/Audio/AudioSensor.h"

class AudioSensorProgram
{
public:
    void Begin();
    void Update();

private:
    bool bAudioSensorProgramBegin = false;
    unsigned long m_LastLogTime = 0;
    AudioSensor m_AudioSensor;
    unsigned long m_DetectionMessageStartTime = 0;
    bool m_IsDetectionMessageVisible = false;
};

extern AudioSensorProgram GAudioSensorProgram;