#pragma once

#include <Arduino.h>

class Time
{
public:

    static void Initialize();

    static void Update();

    static void Synchronize(uint32_t Timestamp);

    static uint32_t Timestamp();

    static uint32_t Milliseconds();

    static uint32_t Seconds();

    static bool Synchronized();

    static bool Elapsed(uint32_t StartTime, uint32_t Duration);

    static bool ElapsedMilliseconds(uint32_t StartTime, uint32_t Duration);

    static bool ElapsedSeconds(uint32_t StartTime, uint32_t Duration);

    static uint32_t Since(uint32_t StartTime);

    static uint32_t SinceSeconds(uint32_t StartTime);

private:

    static uint32_t UnixTimestamp;

    static uint32_t SynchronizationMillis;

    static bool bSynchronized;
};