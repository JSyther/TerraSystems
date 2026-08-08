#pragma once
#include <stdint.h>

enum class EProgramType : uint8_t
{
    None = 0,
    Standby,
    Standoff,
    RelayTest,
    DHT11Program,
    InfraredProgram,
    UltrasonicProgram,
    AudioSensorProgram,
    MotionSensorProgram,
    Flora,
    Irrigation,
    Calibration,
    Maintenance,

    Max
};