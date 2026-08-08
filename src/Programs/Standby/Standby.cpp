#include "Standby.h"

#include "Devices/LED/LED.h"
#include "Devices/Display/Display.h"
#include "Audio/AudioManager.h",


Standby GStandby;


extern LED GLED;
extern Display GDisplay;


void Standby::Begin()
{
    GLED.EnableRed();

    GDisplay.Show("TerraSystems", "STANDBY");

    LastUpdateTime = millis();

    bFutureMessage = false;
}


void Standby::Update()
{
    GLED.EnableRed();

    if (millis() - LastUpdateTime >= 5000)
    {
        LastUpdateTime = millis();


        if (bFutureMessage)
        {
            GDisplay.Show("TerraSystems", "STANDBY");

            bFutureMessage = false;
        }
        else
        {
            GDisplay.Show("For Future", "Generations");

            bFutureMessage = true;
        }
    }

    if(bPlayMelody)
    {
        GAudioManager.PlayMelody();
    }
}