#include "AudioSensorProgram.h"
#include "Configuration/AudioSensorConfig.h"
#include "Audio/AudioManager.h"
#include "Devices/Display/Display.h"
#include "Devices/LED/LED.h"

AudioSensorProgram GAudioSensorProgram;

void AudioSensorProgram::Begin()
{
    GDisplay.Show("AUDIO DETECTOR", "ACTIVE");
    delay(3 * 1000);
    bAudioSensorProgramBegin = true;
}

void AudioSensorProgram::Update()
{
    if (!bAudioSensorProgramBegin)
    {
        return;
    }

    const unsigned long currentTime = millis();

    // Return to the normal screen after the alert message expires.
    if (m_IsDetectionMessageVisible &&
        currentTime - m_DetectionMessageStartTime >=
            AudioSensorConfig::DetectionMessageDurationMs)
    {
        GDisplay.Show("AUDIO DETECTION", "LISTENING...");

        m_IsDetectionMessageVisible = false;
    }

    const bool isDetected = GAudioSensor.Update();
    const int audioLevel = GAudioSensor.GetLevel();

    if (currentTime - m_LastLogTime >= AudioSensorConfig::DebugIntervalMs)
    {
        m_LastLogTime = currentTime;

        Serial.print(F("Audio level: "));
        Serial.println(audioLevel);
    }

    if (!isDetected)
    {
        return;
    }

    Serial.print(F("Audio detected. Level: "));
    Serial.println(audioLevel);

    GDisplay.Show("AUDIO DETECTED", "ALERT ACTIVE");

    m_DetectionMessageStartTime = currentTime;
    m_IsDetectionMessageVisible = true;

    GAudioManager.Success();

    GLED.EnableGreen();
    GLED.DisableRed();
}