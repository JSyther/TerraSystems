#pragma once

#include <Arduino.h>

namespace PinConfig
{
    // LEDs
    constexpr uint8_t Red           = 2;
    constexpr uint8_t Green         = 3;

    // Relays
    constexpr uint8_t WaterPump     = 4;
    constexpr uint8_t ReversePump   = 5;

    // Buzzer
    constexpr uint8_t Buzzer        = 6;

    // Digital Sensors
    constexpr uint8_t DHT                 = 7;
    constexpr uint8_t IRTransmitter       = 8;
    constexpr uint8_t IRReceiver          = 9;
    constexpr uint8_t UltrasonicTrigger   = 10;
    constexpr uint8_t UltrasonicEcho      = 11;

    // Analog Sensors
    constexpr uint8_t AudioSensor   = A0;
    constexpr uint8_t MotionSensor  = A1;
    constexpr uint8_t PHSensor      = A2;

    // I2C
    constexpr uint8_t SDA           = A4;
    constexpr uint8_t SCL           = A5;
}