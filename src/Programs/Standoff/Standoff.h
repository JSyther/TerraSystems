#pragma once

class Standoff
{
public:
    void Begin();
    void Shutdown();
};

extern Standoff GStandoff;