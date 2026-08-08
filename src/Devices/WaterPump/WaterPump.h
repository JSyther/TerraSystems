#pragma once

#include "Configuration/PumpConfig.h"

class WaterPump
{
private:
    EWaterPumpState State = EWaterPumpState::Idle;

public:
    void Initialize();

    void SwitchState(EWaterPumpState NewState);

    EWaterPumpState GetState() const;
    
    void Update();
    void StartPump();
    void StopPump();

    void StartReverse();
    void StopReverse();
};

extern WaterPump GWaterPump;