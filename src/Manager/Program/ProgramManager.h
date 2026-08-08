#pragma once

#include "Configuration/ProgramConfig.h"

class ProgramManager
{
private:

    EProgramType ActiveProgram = EProgramType::None;
public:
    void Start(EProgramType Program);
    void BeginProgram();
    void UpdateProgram();
    void Stop();
    void Tick();
    EProgramType GetActiveProgram() const;


private:
    void InitializeProgram();
};


extern ProgramManager GProgramManager;