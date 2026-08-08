#include "AudioManager.h"
#include "Configuration/AudioConfig.h"
#include "Devices/Buzzer/Buzzer.h"


AudioManager GAudioManager;


void AudioManager::Initialize()
{
    GBuzzer.Initialize();
}


void AudioManager::Beep()
{
    GBuzzer.Play(AudioData::NOTE_C1, 20);
}


void AudioManager::DoubleBeep()
{
    GBuzzer.Play(AudioData::NOTE_C2, 20);

    delay(100);

    GBuzzer.Play(AudioData::NOTE_C2, 20);
}


void AudioManager::Error()
{
    GBuzzer.Play(AudioData::NOTE_A3, 300);

    delay(100);

    GBuzzer.Play(AudioData::NOTE_A3, 300);
}


void AudioManager::Success()
{
    GBuzzer.Play(AudioData::NOTE_C5, 50);
    delay(25);
    GBuzzer.Play(AudioData::NOTE_E5, 25);
    delay(25);
    GBuzzer.Play(AudioData::NOTE_G5, 25);
    delay(25);
    GBuzzer.Play(AudioData::NOTE_A5, 100);

}


void AudioManager::Startup()
{
    GBuzzer.Play(AudioData::NOTE_C4, 150);

    delay(100);

    GBuzzer.Play(AudioData::NOTE_E4, 150);

    delay(100);

    GBuzzer.Play(AudioData::NOTE_G4, 250);
}

void AudioManager::ShuttingDown()
{
    GBuzzer.Play(AudioData::NOTE_G4, 120);
    delay(150);

    GBuzzer.Play(AudioData::NOTE_E4, 120);
    delay(150);

    GBuzzer.Play(AudioData::NOTE_D4, 120);
    delay(150);

    GBuzzer.Play(AudioData::NOTE_C4, 450);
    delay(500);

    GBuzzer.Stop();
}

void AudioManager::Shutdown()
{
    GBuzzer.Play(AudioData::NOTE_G4, 150);

    delay(100);

    GBuzzer.Play(AudioData::NOTE_E4, 150);

    delay(100);

    GBuzzer.Play(AudioData::NOTE_C4, 250);
}


void AudioManager::PlayTone(uint16_t Frequency, uint16_t Duration)
{
    GBuzzer.Play(Frequency, Duration);
}


void AudioManager::Stop()
{
    GBuzzer.Stop();
}

void AudioManager::PlayAudio(const char* Audio)
{
    Serial.print("PLAY:");
    Serial.println(Audio);
}

void AudioManager::StartWaterPump()
{
    GBuzzer.Play(AudioData::NOTE_C4, 100);

    delay(80);

    GBuzzer.Play(AudioData::NOTE_G4, 150);
}


void AudioManager::StopWaterPump()
{
    GBuzzer.Play(AudioData::NOTE_G4, 100);

    delay(80);

    GBuzzer.Play(AudioData::NOTE_C4, 150);
}


void AudioManager::StartReversePump()
{
    GBuzzer.Play(AudioData::NOTE_E4, 100);

    delay(80);

    GBuzzer.Play(AudioData::NOTE_A4, 150);
}


void AudioManager::StopReversePump()
{
    GBuzzer.Play(AudioData::NOTE_A4, 100);

    delay(80);

    GBuzzer.Play(AudioData::NOTE_E4, 150);
}

void AudioManager::PlayMelody()
{
    GBuzzer.Play(AudioData::NOTE_C5, 180);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_D5, 180);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_E5, 180);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_G5, 250);
    delay(50);

    GBuzzer.Play(AudioData::NOTE_E5, 180);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_G5, 220);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_C6, 350);
    delay(80);

    GBuzzer.Play(AudioData::NOTE_B5, 180);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_A5, 180);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_G5, 220);
    delay(40);

    GBuzzer.Play(AudioData::NOTE_E5, 180);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_D5, 180);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_C5, 250);
    delay(50);

    GBuzzer.Play(AudioData::NOTE_G4, 220);
    delay(30);

    GBuzzer.Play(AudioData::NOTE_C5, 450);
}