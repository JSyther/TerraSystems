#include "UltrasonicProgram.h"

#include "Sensors/Ultrasonic/UltrasonicSensor.h"
#include "Devices/Display/Display.h"
#include "Audio/AudioManager.h"
#include "Devices/LED/LED.h"

UltrasonicProgram GUltrasonicProgram;

void UltrasonicProgram::Begin()
{
    GDisplay.Show
    (
        "ULTRASONIC",
        "INITIALIZING"
    );

    bUltrasonicProgramBegin = true;
}

void UltrasonicProgram::Update()
{
    if(!bUltrasonicProgramBegin) return;

    MeasureDistance();
    UpdateDisplay();
    UpdateLED();
    UpdateBuzzer();
}

void UltrasonicProgram::MeasureDistance()
{
    GUltrasonicSensor.Update();
}

void UltrasonicProgram::UpdateDisplay()
{
    char TopLine[17];
    char BottomLine[17];
    char Distance[8];

    dtostrf
    (
        GUltrasonicSensor.GetDistance(),
        5,
        1,
        Distance
    );

    snprintf
    (
        TopLine,
        sizeof(TopLine),
        "DISTANCE"
    );

    snprintf
    (
        BottomLine,
        sizeof(BottomLine),
        "%s CM",
        Distance
    );

    GDisplay.Show
    (
        TopLine,
        BottomLine
    );
}

void UltrasonicProgram::UpdateLED()
{
    const float Distance = GUltrasonicSensor.GetDistance();

    if (Distance <= 0.0f)
    {
        GLED.DisableRed();
        GLED.DisableGreen();
        return;
    }

    if (Distance <= 15.0f)
    {
        GLED.DisableGreen();
        GLED.BlinkRed(5, 0.025f);
        return;
    }

    if (Distance <= 30.0f)
    {
        GLED.DisableGreen();
        GLED.BlinkRed(3, 0.025f);
        return;
    }

    GLED.DisableRed();

    if (Distance > 125.0f)
    {
        GLED.BlinkGreen(1, 0.250f);
    }
    else if (Distance > 100.0f)
    {
        GLED.BlinkGreen(2, 0.200f);
    }
    else if (Distance > 75.0f)
    {
        GLED.BlinkGreen(3, 0.150f);
    }
    else if (Distance > 60.0f)
    {
        GLED.BlinkGreen(4, 0.100f);
    }
    else
    {
        GLED.EnableGreen();
    }
}

void UltrasonicProgram::UpdateBuzzer()
{
    const float Distance = GUltrasonicSensor.GetDistance();

    if (Distance <= 0.0f)
    {
        return;
    }

    if (Distance <= 15.0f)
    {
        if (millis() - LastBeepTime >= 15)
        {
            LastBeepTime = millis();
            GAudioManager.Error();
            //GAudioManager.PlayCriticalAudio();
        }

        return;
    }

    if (Distance <= 30.0f)
    {
        if (millis() - LastBeepTime >= 50)
        {
            LastBeepTime = millis();
            GAudioManager.Error();
        }

        return;
    }

    // Termina acess = dotnet run -- COM4 9600 "C:\Users\Mehmet\Desktop\Projects\TerraSystems\src" 
    // Temporary audio play on pc 
    // if(Distance <= 150 &&  millis() - LastBeepTime >= 450)
    // {
    //     GAudioManager.PlayTargetDetectedAudio();
    // }

    uint16_t Interval = 50;

    if (Distance > 125.0f)
    {
        Interval = 400;
    }
    else if (Distance > 100.0f)
    {
        Interval = 300;
    }
    else if (Distance > 75.0f)
    {
        Interval = 200;
    }
    else if (Distance > 60.0f)
    {
        Interval = 100;
    }

    if (millis() - LastBeepTime >= Interval)
    {
        LastBeepTime = millis();
        GAudioManager.Beep();
    }
}