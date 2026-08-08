#pragma once

#include <stdint.h>

class InfraredProgram
{
public:
    void Begin();
    void Update();

private:
    void UpdateDisplay();
    void SendTestSignal();
    void ReceiveTestSignal();

private:
    bool bLastReceiveState = false;
    bool bTransmissionSucceeded = false;
    bool bSignalReceived = false;
    uint32_t LastReceivedCode = 0;
    uint32_t TestCode = 0x20DF10EF;
    unsigned long LastTransmitTime = 0;
    unsigned long LastDisplayUpdateTime = 0;

private:
    bool bButtonPressed = false;
    uint16_t LastCommand = 0;
};


extern InfraredProgram GInfraredProgram;