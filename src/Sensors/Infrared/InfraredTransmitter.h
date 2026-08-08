#pragma once

#include <Arduino.h>

class InfraredTransmitter
{
public:

    void Initialize();
    void Update();
    void Stop();

    // Generic
    void Send(uint32_t Code);
    void Send(uint32_t Code, uint8_t Repeats);

    // NEC
    void SendNEC(uint16_t Address, uint16_t Command);
    void SendNEC(uint16_t Address, uint16_t Command, uint8_t Repeats);

    // İleride eklenecek protokoller
    // void SendSony(...);
    // void SendSamsung(...);
    // void SendLG(...);
    // void SendPanasonic(...);
    // void SendRC5(...);
    // void SendRC6(...);
};

extern InfraredTransmitter GInfraredTransmitter;