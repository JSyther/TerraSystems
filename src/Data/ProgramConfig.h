#pragma once
#include <stdint.h>

enum class EProgramType : uint8_t
{
    None = 0,

    RelayTest,
    Flora,
    Irrigation,
    Calibration,
    Maintenance,

    Max
};