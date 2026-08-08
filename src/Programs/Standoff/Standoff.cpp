#include "Standoff.h"

#include "Devices/Display/Display.h"
#include "Devices/LED/LED.h"
#include "Devices/Buzzer/Buzzer.h"
#include "Devices/WaterPump/WaterPump.h"
#include "Manager/Audio/AudioManager.h"

Standoff GStandoff;

void Standoff::Begin()
{
    
    GDisplay.Show
    (
        "SYSTEM",
        "SHUTTING DOWN"
    );

}

void Standoff::Shutdown()
{
    GWaterPump.StopPump();
    GLED.DisableGreen();
    GLED.DisableRed();
    GBuzzer.Stop();
    
    GDisplay.Show
    (
        "SYSTEM",
        "OFFLINE"
    );

    while (true)
    {
        delay(1000);
    }
}