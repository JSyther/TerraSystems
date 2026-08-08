#pragma once

#include <stdint.h>
#include "Configuration/InfraredConfig.h"

class InfraredReceiver
{
public:
    void Initialize();
    void Update();
    bool Available() const;
    uint32_t Read() const;
    void Resume();

    uint32_t GetRawData() const;
    uint16_t GetAddress() const;
    uint16_t GetCommand() const;
    uint8_t GetProtocol() const;
    uint8_t GetNumberOfBits() const;
    void PrintDebug();

    const FInfraredReceiver& GetData() const;

private:
    FInfraredReceiver Data;

    bool bAvailable = false;
};

extern InfraredReceiver GInfraredReceiver;