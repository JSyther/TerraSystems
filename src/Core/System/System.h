#pragma once

#include <Arduino.h>
#include "Configuration/SystemConfig.h"
#include "Configuration/ProgramConfig.h"

class System
{
public:
    void Initialize();
    void Update();

    ESystemState GetSystemState() const;
    EProgramType GetProgramType() const;

private:
    EProgramType ProgramType = EProgramType::Standby;

private:
    void InitializeSystems();
    void InitializeDevices();
    void InitializeSensors();

private:
    ESystemState State = ESystemState::Initializing;
};

extern System GSystem;