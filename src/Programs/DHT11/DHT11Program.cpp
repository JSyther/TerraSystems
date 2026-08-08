#include "DHT11Program.h"

#include "Devices/Display/Display.h"
#include "Devices/WaterPump/WaterPump.h"
#include "Devices/LED/LED.h"
#include "Manager/Audio/AudioManager.h"

DHT11Program GDHT11Program;


void DHT11Program::Begin()
{
    Sensor.Initialize();

    GLED.Off();

}


void DHT11Program::Update()
{
    Sensor.Update();

    static bool bEmergencyScreen = false;
    static unsigned long EmergencyTimer = millis();

    static bool bShowHumidity = false;
    static unsigned long NormalTimer = millis();

    const float Temperature = Sensor.GetTemperature();
    const float Humidity = Sensor.GetHumidity();

    char Line1[17];
    char Line2[17];

    char TemperatureValue[8];
    char HumidityValue[8];

    dtostrf(Temperature, 4, 1, TemperatureValue);
    dtostrf(Humidity, 4, 1, HumidityValue);

    if (Temperature < 28.0f)
    {
        GLED.EnableGreen();
        GLED.DisableRed();

        bEmergencyScreen = false;

        if (millis() - NormalTimer >= 5000)
        {
            NormalTimer = millis();

            bShowHumidity = !bShowHumidity;

            GAudioManager.Beep();
        }

        if (bShowHumidity)
        {
            snprintf(Line1, sizeof(Line1), "HUMIDITY");
            snprintf(Line2, sizeof(Line2), "%s %%", HumidityValue);
        }
        else
        {
            snprintf(Line1, sizeof(Line1), "TEMPERATURE");
            snprintf(Line2, sizeof(Line2), "%s C", TemperatureValue);
        }

        GDisplay.Show(Line1, Line2);
    }
    else
    {
    GLED.EnableRed();
    GLED.DisableGreen();

    if (!bEmergencyScreen)
    {
        bEmergencyScreen = true;
        EmergencyTimer = millis();

        GWaterPump.StartPump();
        GAudioManager.DoubleBeep();
    }

    unsigned long Elapsed = millis() - EmergencyTimer;

    if (Elapsed < 5000)
    {
        GDisplay.Show
        (
            "EMERGENCY",
            "WATER PUMPING"
        );

        return;
    }

    if (Elapsed < 10000)
    {
        snprintf(Line1, sizeof(Line1), "TEMPERATURE");
        snprintf(Line2, sizeof(Line2), "%s C", TemperatureValue);

        GDisplay.Show(Line1, Line2);

        return;
    }

    if (Elapsed < 15000)
    {
        snprintf(Line1, sizeof(Line1), "HUMIDITY");
        snprintf(Line2, sizeof(Line2), "%s %%", HumidityValue);

        GDisplay.Show(Line1, Line2);
        return;
    }

    EmergencyTimer = millis();
    GAudioManager.DoubleBeep();
    }
}