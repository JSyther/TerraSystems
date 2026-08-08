#pragma once

#include <Arduino.h>

class RelayTest
{
public:
    void Begin();
    void Start();
    void Stop();
    void Update();
    bool IsRunning() const;

private:

    bool bRunning = false;

    unsigned long StateStartTime = 0;


    void EnterPumpStart();
    void EnterPumpWait();

    void EnterReverseStart();
    void EnterReverseWait();
};


extern RelayTest GRelayTest;