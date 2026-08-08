#include "Buzzer.h"

#include "Configuration/PinConfig.h"


Buzzer GBuzzer;


void Buzzer::Initialize()
{
    pinMode(PinConfig::Buzzer, OUTPUT);

    noTone(PinConfig::Buzzer);
}


void Buzzer::Play(uint16_t Frequency, uint16_t Duration)
{
    tone(PinConfig::Buzzer, Frequency, Duration);

    delay(Duration);

    noTone(PinConfig::Buzzer);
}


void Buzzer::Stop()
{
    noTone(PinConfig::Buzzer);
}