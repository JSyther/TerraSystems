#pragma once

class UltrasonicProgram
{
public:
    void Begin();
    void Update();

private:
    void MeasureDistance();
    void UpdateDisplay();
    void UpdateLED();
    void UpdateBuzzer();

private:
    bool bUltrasonicProgramBegin = false;
    unsigned long LastBeepTime = 0;
};

extern UltrasonicProgram GUltrasonicProgram;