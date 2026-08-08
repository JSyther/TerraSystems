#include "LED.h"
#include "Configuration/PinConfig.h"

LED GLED;

void LED::Initialize()
{
    pinMode(PinConfig::Red, OUTPUT);
    pinMode(PinConfig::Green, OUTPUT);

    Off();
}

void LED::Update()
{
}

void LED::On()
{
    digitalWrite(PinConfig::Red, HIGH);
    digitalWrite(PinConfig::Green, HIGH);
}

void LED::Off()
{
    digitalWrite(PinConfig::Red, LOW);
    digitalWrite(PinConfig::Green, LOW);
}
void LED::EnableRed()
{
    if (bRedLedEnabled)
    {
        return;
    }

    digitalWrite(PinConfig::Red, HIGH);
    bRedLedEnabled = true;
}

void LED::DisableRed()
{
    if (!bRedLedEnabled)
    {
        return;
    }

    digitalWrite(PinConfig::Red, LOW);
    bRedLedEnabled = false;
}

void LED::BlinkRed(uint8_t Count, float IntervalSeconds)
{
    const unsigned long DelayMs =
        static_cast<unsigned long>(IntervalSeconds * 1000.0f);

    for (uint8_t i = 0; i < Count; ++i)
    {
        EnableRed();
        delay(DelayMs);

        DisableRed();
        delay(DelayMs);
    }
}

bool LED::IsRedOn() const
{
    return bRedLedEnabled;
}

void LED::EnableGreen()
{
    if (bGreenLedEnabled)
    {
        return;
    }

    digitalWrite(PinConfig::Green, HIGH);
    bGreenLedEnabled = true;
}

void LED::DisableGreen()
{
    if (!bGreenLedEnabled)
    {
        return;
    }

    digitalWrite(PinConfig::Green, LOW);
    bGreenLedEnabled = false;
}

void LED::BlinkGreen(uint8_t Count, float IntervalSeconds)
{
    const unsigned long DelayMs =
        static_cast<unsigned long>(IntervalSeconds * 1000.0f);

    for (uint8_t i = 0; i < Count; ++i)
    {
        EnableGreen();
        delay(DelayMs);

        DisableGreen();
        delay(DelayMs);
    }
}

bool LED::IsGreenOn() const
{
    return bGreenLedEnabled;
}