#include "RelayTest.h"

#include "Devices/WaterPump/WaterPump.h"
#include "Devices/Display/Display.h"
#include "Devices/LED/LED.h"
#include "Manager/Audio/AudioManager.h"


RelayTest GRelayTest;


void RelayTest::Begin()
{
    bRunning = false;
    StateStartTime = 0;
}


void RelayTest::Start()
{
    if (bRunning)
        return;

    bRunning = true;

    EnterPumpStart();
}


void RelayTest::Stop()
{
    GWaterPump.SwitchState(EWaterPumpState::Idle);

    GLED.Off();

    bRunning = false;
}


void RelayTest::Update()
{
    if (!bRunning)
    {
        return;
    }


    unsigned long CurrentTime = millis();


    switch (GWaterPump.GetState())
    {

    case EWaterPumpState::PumpStart:

        if (CurrentTime - StateStartTime >= 3000)
            EnterPumpWait();

        break;


    case EWaterPumpState::PumpWait:

        if (CurrentTime - StateStartTime >= 2000)
            EnterReverseStart();

        break;


    case EWaterPumpState::ReverseStart:

        if (CurrentTime - StateStartTime >= 3000)
            EnterReverseWait();

        break;


    case EWaterPumpState::ReverseWait:

        if (CurrentTime - StateStartTime >= 2000)
            EnterPumpStart();

        break;


    default:
        break;
    }
}


bool RelayTest::IsRunning() const
{
    return bRunning;
}


void RelayTest::EnterPumpStart()
{
    StateStartTime = millis();
    GWaterPump.SwitchState(EWaterPumpState::PumpStart);
    GLED.EnableGreen();
    GLED.DisableRed();
    GDisplay.Show("RELAY TEST", "WATER PUMPING");
    GAudioManager.StartWaterPump();
}


void RelayTest::EnterPumpWait()
{
    StateStartTime = millis();
    GWaterPump.SwitchState(EWaterPumpState::PumpWait);
    GLED.EnableRed();
    GLED.DisableGreen();
    GDisplay.Show("RELAY TEST", "STAND-BY");
    GAudioManager.StopWaterPump();
}


void RelayTest::EnterReverseStart()
{
    StateStartTime = millis();
    GWaterPump.SwitchState(EWaterPumpState::ReverseStart);
    GLED.EnableGreen();
    GLED.DisableRed();
    GDisplay.Show("RELAY TEST", "REVERSE PUMPING");
    GAudioManager.StartReversePump();
}


void RelayTest::EnterReverseWait()
{
    StateStartTime = millis();
    GWaterPump.SwitchState(EWaterPumpState::ReverseWait);
    GLED.EnableRed();
    GLED.DisableGreen();
    GDisplay.Show("RELAY TEST", "WAIT");
    GAudioManager.StopReversePump();
}