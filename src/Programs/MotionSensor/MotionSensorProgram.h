#pragma once

class MotionSensorProgram
{
public:
    void Begin();
    void Update();

private:
    bool bBegin = false;
    bool bMotionAlertActive = false;
    unsigned long LastMotionTime = 0;
};

extern MotionSensorProgram GMotionSensorProgram;