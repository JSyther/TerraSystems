#include "Display.h"
#include "Devices/Buzzer/Buzzer.h"

Display GDisplay;

uint8_t Display::GetCenteredColumn(const char* Text) const
{
    const uint8_t Length = strlen(Text);

    return (16 - Length) / 2;
}

void Display::Initialize()
{
    LCD.init();
    LCD.backlight();
    LCD.clear();

    LastTop[0] = '\0';
    LastBottom[0] = '\0';
}

void Display::Clear()
{
    LCD.clear();
}

void Display::Show(const char* Top, const char* Bottom)
{
    if (strcmp(LastTop, Top) == 0 &&
        strcmp(LastBottom, Bottom) == 0)
    {
        return;
    }

    strcpy(LastTop, Top);
    strcpy(LastBottom, Bottom);

    LCD.setCursor(0, 0);
    LCD.print("                "); 

    LCD.setCursor(0, 1);
    LCD.print("                ");

    LCD.setCursor(GetCenteredColumn(Top), 0);
    LCD.print(Top);

    LCD.setCursor(GetCenteredColumn(Bottom), 1);
    LCD.print(Bottom);
}

void Display::ShowAnimated(const char* Top, const char* Bottom, float DurationSeconds)
{
    LCD.clear();

    const uint8_t TopLength = strlen(Top);
    const uint8_t BottomLength = strlen(Bottom);

    const float CharacterDelay =
        DurationSeconds / (TopLength + BottomLength);

    LCD.setCursor(GetCenteredColumn(Top), 0);

    for (uint8_t i = 0; i < TopLength; ++i)
    {
        LCD.print(Top[i]);

        GBuzzer.Play(random(1850, 2550), 0.02f);

        delay(static_cast<unsigned long>(CharacterDelay * 1000.0f));
    }

    LCD.setCursor(GetCenteredColumn(Bottom), 1);

    for (uint8_t i = 0; i < BottomLength; ++i)
    {
        LCD.print(Bottom[i]);

        GBuzzer.Play(random(1850, 2550), 0.02f);

        delay(static_cast<unsigned long>(CharacterDelay * 1000.0f));
    }

    GBuzzer.Stop();
}

void Display::Blink(const char* Top,const char* Bottom,uint8_t Count,float IntervalSeconds)
{
    const unsigned long DelayMs =
        static_cast<unsigned long>(IntervalSeconds * 1000.0f);

    for (uint8_t i = 0; i < Count; ++i)
    {
        LCD.clear();
        delay(DelayMs);

        LCD.setCursor(GetCenteredColumn(Top), 0);
        LCD.print(Top);

        LCD.setCursor(GetCenteredColumn(Bottom), 1);
        LCD.print(Bottom);

        delay(DelayMs);
    }
}

void Display::FloatText(const char* Top,const char* Bottom,float DurationSeconds)
{
    const uint8_t TopLength = strlen(Top);
    const uint8_t BottomLength = strlen(Bottom);

    const uint8_t TopStart = GetCenteredColumn(Top);
    const uint8_t BottomStart = GetCenteredColumn(Bottom);

    const uint8_t Steps = 6;

    const unsigned long DelayMs =
        static_cast<unsigned long>((DurationSeconds / Steps) * 1000.0f);

    for (uint8_t i = 0; i < Steps; ++i)
    {
        LCD.clear();

        LCD.setCursor(TopStart, (i % 2 == 0) ? 0 : 1);
        LCD.print(Top);

        LCD.setCursor(BottomStart, (i % 2 == 0) ? 1 : 0);
        LCD.print(Bottom);

        delay(DelayMs);
    }

    Show(Top, Bottom);
}