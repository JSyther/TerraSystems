#include "AudioSensor.h"

#include "Configuration/PinConfig.h"
#include "Configuration/AudioSensorConfig.h"

AudioSensor GAudioSensor;

void AudioSensor::Initialize()
{
    pinMode(PinConfig::AudioSensor, INPUT);

    m_Level = 0;
    m_Detected = false;
    m_LastSampleTime = 0;
    m_LastTriggerTime = 0;
}

bool AudioSensor::Update()
{
    const unsigned long currentTime = millis();

    // Wait until the next sound measurement.
    if (currentTime - m_LastSampleTime < AudioSensorConfig::SampleIntervalMs)
    {
        return false;
    }

    m_LastSampleTime = currentTime;

    int minimumLevel = 1023;
    int maximumLevel = 0;

    // Measure the sound wave amplitude over a short time window.
    for (uint8_t index = 0; index < AudioSensorConfig::SampleCount; ++index)
    {
        const int sample = analogRead(PinConfig::AudioSensor);

        if (sample < minimumLevel)
        {
            minimumLevel = sample;
        }

        if (sample > maximumLevel)
        {
            maximumLevel = sample;
        }

        delayMicroseconds(AudioSensorConfig::SampleDelayUs);
    }

    // The difference represents sound intensity.
    m_Level = maximumLevel - minimumLevel;

    if (AudioSensorConfig::DebugEnabled)
    {
        Serial.print(F("Audio level: "));
        Serial.println(m_Level);
    }

    const bool isAboveThreshold = m_Level >= AudioSensorConfig::Threshold;
    const bool isCooldownFinished =
        currentTime - m_LastTriggerTime >= AudioSensorConfig::CooldownMs;

    if (isAboveThreshold && isCooldownFinished)
    {
        m_Detected = true;
        m_LastTriggerTime = currentTime;
        return true;
    }

    m_Detected = false;
    return false;
}

int AudioSensor::GetLevel() const
{
    return m_Level;
}

bool AudioSensor::IsDetected() const
{
    return m_Detected;
}