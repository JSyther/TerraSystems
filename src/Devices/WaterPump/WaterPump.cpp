#include "WaterPump.h"
#include "Configuration/PinConfig.h"

WaterPump GWaterPump;


void WaterPump::Initialize()
{
    pinMode(PinConfig::WaterPump, OUTPUT);
    pinMode(PinConfig::ReversePump, OUTPUT);

    digitalWrite(PinConfig::WaterPump, HIGH);
    digitalWrite(PinConfig::ReversePump, HIGH);

    State = EWaterPumpState::Idle;
}


void WaterPump::SwitchState(EWaterPumpState NewState)
{
    State = NewState;
    Update();
}


EWaterPumpState WaterPump::GetState() const
{
    return State;
}


void WaterPump::Update()
{
    switch (State)
    {
        case EWaterPumpState::Idle:
            StopPump();
            StopReverse();
            break;


        case EWaterPumpState::PumpStart:
            StartPump();
            break;


        case EWaterPumpState::PumpWait:
            StopPump();
            break;


        case EWaterPumpState::ReverseStart:
            StartReverse();
            break;


        case EWaterPumpState::ReverseWait:
            StopReverse();
            break;
    }
}

void WaterPump::StartPump()
{
    digitalWrite(PinConfig::WaterPump, LOW);
}


void WaterPump::StopPump()
{
    digitalWrite(PinConfig::WaterPump, HIGH);
}


void WaterPump::StartReverse()
{
    digitalWrite(PinConfig::ReversePump, LOW);
}


void WaterPump::StopReverse()
{
    digitalWrite(PinConfig::ReversePump, HIGH);
}