#include "Standby.h"

#include "Devices/LED/LED.h"
#include "Devices/Display/Display.h"
#include "Manager/Audio/AudioManager.h"


Standby GStandby;


extern LED GLED;
extern Display GDisplay;


void Standby::Begin()
{
    GLED.EnableRed();

    GDisplay.Show("Terra Systems", "FLORA GEN V1.");

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
            GDisplay.Show("Terra Systems", "FLORA GEN V1.");

            bFutureMessage = false;
        }
        else
        {
            GDisplay.Show("For Future", "Generations.");

            bFutureMessage = true;
        }
    }

    if(bPlayMelody)
    {
        GAudioManager.PlayMelody();
    }
}