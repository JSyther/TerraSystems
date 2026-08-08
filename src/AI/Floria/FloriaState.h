#pragma once

#include <stdint.h>

struct SFloriaState
{
    // =========================================================
    // ENVIRONMENT
    // =========================================================

    float Temperature = 0.0f;
    float Humidity = 0.0f;
    float Pressure = 0.0f;

    float LightLevel = 0.0f;
    float UVLevel = 0.0f;

    float CO2Level = 0.0f;
    float AirQuality = 0.0f;

    // =========================================================
    // WATER
    // =========================================================

    float WaterLevel = 0.0f;
    float WaterTemperature = 0.0f;
    float WaterFlowRate = 0.0f;

    float WaterPH = 0.0f;
    float WaterEC = 0.0f;
    float WaterTDS = 0.0f;

    // =========================================================
    // NUTRIENTS
    // =========================================================

    float NutrientLevel = 0.0f;
    float NutrientEC = 0.0f;

    float Nitrogen = 0.0f;
    float Phosphorus = 0.0f;
    float Potassium = 0.0f;

    // =========================================================
    // ROOT / GROWTH ENVIRONMENT
    // =========================================================

    float RootTemperature = 0.0f;
    float RootMoisture = 0.0f;
    float RootOxygen = 0.0f;

    // =========================================================
    // PLANT
    // =========================================================

    float PlantHealth = 0.0f;
    float PlantGrowth = 0.0f;
    float PlantStress = 0.0f;

    float LeafTemperature = 0.0f;
    float LeafMoisture = 0.0f;

    // =========================================================
    // SYSTEM
    // =========================================================

    float BatteryLevel = 0.0f;
    float SystemTemperature = 0.0f;

    bool bWaterAvailable = false;
    bool bNutrientsAvailable = false;
    bool bSystemHealthy = true;

    // =========================================================
    // TIME
    // =========================================================

    uint32_t Timestamp = 0;

    uint32_t SecondsSinceStart = 0;

    uint16_t Day = 0;
    uint16_t Hour = 0;
    uint16_t Minute = 0;

    // =========================================================
    // RESET
    // =========================================================

    void Reset()
    {
        // Environment
        Temperature = 0.0f;
        Humidity = 0.0f;
        Pressure = 0.0f;
        LightLevel = 0.0f;
        UVLevel = 0.0f;
        CO2Level = 0.0f;
        AirQuality = 0.0f;

        // Water
        WaterLevel = 0.0f;
        WaterTemperature = 0.0f;
        WaterFlowRate = 0.0f;
        WaterPH = 0.0f;
        WaterEC = 0.0f;
        WaterTDS = 0.0f;

        // Nutrients
        NutrientLevel = 0.0f;
        NutrientEC = 0.0f;
        Nitrogen = 0.0f;
        Phosphorus = 0.0f;
        Potassium = 0.0f;

        // Root
        RootTemperature = 0.0f;
        RootMoisture = 0.0f;
        RootOxygen = 0.0f;

        // Plant
        PlantHealth = 0.0f;
        PlantGrowth = 0.0f;
        PlantStress = 0.0f;
        LeafTemperature = 0.0f;
        LeafMoisture = 0.0f;

        // System
        BatteryLevel = 0.0f;
        SystemTemperature = 0.0f;

        bWaterAvailable = false;
        bNutrientsAvailable = false;
        bSystemHealthy = true;

        // Time
        Timestamp = 0;
        SecondsSinceStart = 0;
        Day = 0;
        Hour = 0;
        Minute = 0;
    }
};