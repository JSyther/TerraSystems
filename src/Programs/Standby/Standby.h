#pragma once

class Standby
{

public:
    void Begin();
    void Update();

private:
    unsigned long LastUpdateTime = 0;
    bool bFutureMessage = false;
    bool bPlayMelody = false;
};

extern Standby GStandby;