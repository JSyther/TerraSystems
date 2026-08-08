#include "MotionSensor.h"

#include "Configuration/PinConfig.h"

MotionSensor GMotionSensor;

void MotionSensor::Initialize()
{
    pinMode(PinConfig::MotionSensor, INPUT);

    MotionSensorConfiguration.bDetected = false;
    MotionSensorConfiguration.bWasMotionDetected = false;

    MotionSensorConfiguration.InitializeTime = millis();
    MotionSensorConfiguration.LastTriggerTime = 0;
}

void MotionSensor::Begin()
{

}

void MotionSensor::Update()
{
    const unsigned long currentTime = millis();

    MotionSensorConfiguration.bDetected = false;

    const bool bCheckTime = currentTime - MotionSensorConfiguration.LastCheckTime >= MotionSensorConfiguration.UpdateIntervalMs;

    if (!bCheckTime)
    {
        return;
    }

    MotionSensorConfiguration.LastCheckTime = currentTime;

    const bool bMotion = digitalRead(PinConfig::MotionSensor) == HIGH;

    const bool bWarmingUp = currentTime - MotionSensorConfiguration.InitializeTime < MotionSensorConfiguration.WarmupDurationMs;

    if (bWarmingUp)
    {
        MotionSensorConfiguration.bWasMotionDetected = bMotion;
        return;
    }

    const bool bCooldownFinished = currentTime - MotionSensorConfiguration.LastTriggerTime >= MotionSensorConfiguration.CooldownMs;

    const bool bNewMotion = bMotion & !MotionSensorConfiguration.bWasMotionDetected && bCooldownFinished;

    MotionSensorConfiguration.bWasMotionDetected = bMotion;

    if (!bNewMotion)
    {
        return;
    }

    MotionSensorConfiguration.bDetected = true;
    MotionSensorConfiguration.LastTriggerTime = currentTime;

    if (MotionSensorConfiguration.bDebugEnabled)
    {
        Serial.println(F("Motion detected."));
    }
}

bool MotionSensor::IsDetected() const
{
    return MotionSensorConfiguration.bDetected;
}

unsigned long MotionSensor::GetDisplayDurationMs() const
{
    return MotionSensorConfiguration.DisplayDurationMs;
}