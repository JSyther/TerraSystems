#include "MotionSensorProgram.h"

#include "Audio/AudioManager.h"
#include "Devices/Display/Display.h"
#include "Devices/LED/LED.h"
#include "Sensors/Motion/MotionSensor.h"

MotionSensorProgram GMotionSensorProgram;

void MotionSensorProgram::Begin()
{
    GDisplay.Show("MOTION SENSOR", "READY");

    bBegin = true;
}

void MotionSensorProgram::Update()
{
    if (!bBegin)
    {
        return;
    }

    const unsigned long currentTime = millis();

    GMotionSensor.Update();

    if (GMotionSensor.IsDetected())
    {
        Serial.println(F("Motion program triggered."));

        GDisplay.Show("MOTION DETECTED", "ALERT ACTIVE");

        GAudioManager.Success();

        GLED.EnableRed();
        GLED.DisableGreen();

        bMotionAlertActive = true;
        LastMotionTime = currentTime;

        return;
    }

    const bool bAlertFinished =    bMotionAlertActive &&
        currentTime - LastMotionTime >=
        GMotionSensor.GetDisplayDurationMs();

    if (!bAlertFinished)
    {
        return;
    }

    GDisplay.Show("MOTION SENSOR", "NOT DETECTED");

    GLED.DisableRed();
    GLED.EnableGreen();

    bMotionAlertActive = false;
}