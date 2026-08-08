#include "UltrasonicSensor.h"
#include "Configuration/PinConfig.h"
#include <Arduino.h>

UltrasonicSensor GUltrasonicSensor;

void UltrasonicSensor::Initialize()
{
    pinMode(PinConfig::UltrasonicTrigger, OUTPUT);
    pinMode(PinConfig::UltrasonicEcho, INPUT);

    digitalWrite(PinConfig::UltrasonicTrigger, LOW);

    Data.Distance = 0.0f;
    Data.bObjectDetected = false;
}

void UltrasonicSensor::Update()
{
    MeasureDistance();
}

void UltrasonicSensor::MeasureDistance()
{
    constexpr uint8_t SampleCount = 5;

    unsigned long TotalDuration = 0;
    uint8_t ValidSamples = 0;

    for (uint8_t i = 0; i < SampleCount; ++i)
    {
        digitalWrite(PinConfig::UltrasonicTrigger, LOW);
        delayMicroseconds(2);

        digitalWrite(PinConfig::UltrasonicTrigger, HIGH);
        delayMicroseconds(UltrasonicConfig::Data.Trigger.PulseDuration);
        digitalWrite(PinConfig::UltrasonicTrigger, LOW);

        const unsigned long Duration = pulseIn
        (
            PinConfig::UltrasonicEcho,
            HIGH,
            30000UL
        );

        if (Duration == 0)
        {
            continue;
        }

        TotalDuration += Duration;
        ++ValidSamples;
    }

    if (ValidSamples == 0)
    {
        Data.Distance = 0.0f;
        Data.bObjectDetected = false;

        Serial.println("NO ECHO");
        return;
    }

    const float AverageDuration = (float)TotalDuration / ValidSamples;

    Data.Distance = AverageDuration / 58.0f;

    Data.bObjectDetected =
        Data.Distance >= Data.MinimumDistance &&
        Data.Distance <= Data.MaximumDistance;

    Serial.print("Samples: ");
    Serial.print(ValidSamples);

    Serial.print(" | Distance: ");
    Serial.print(Data.Distance, 1);

    Serial.print(" cm | Detected: ");
    Serial.println(Data.bObjectDetected ? "YES" : "NO");
}

float UltrasonicSensor::GetDistance() const
{
    return Data.Distance;
}

bool UltrasonicSensor::IsObjectDetected() const
{
    return Data.bObjectDetected;
}