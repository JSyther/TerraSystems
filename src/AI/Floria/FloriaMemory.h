#pragma once

#include <Arduino.h>

struct SFloriaMemory
{
    // =========================================================
    // ENVIRONMENT — BEFORE
    // =========================================================

    float Temperature = 0.0f;
    float Humidity = 0.0f;
    float Pressure = 0.0f;

    float LightLevel = 0.0f;
    float UVLevel = 0.0f;

    float CO2Level = 0.0f;
    float AirQuality = 0.0f;


    // =========================================================
    // WATER — BEFORE
    // =========================================================

    float WaterLevel = 0.0f;
    float WaterTemperature = 0.0f;
    float WaterFlowRate = 0.0f;

    float WaterPH = 0.0f;
    float WaterEC = 0.0f;
    float WaterTDS = 0.0f;


    // =========================================================
    // NUTRIENTS — BEFORE
    // =========================================================

    float NutrientLevel = 0.0f;
    float NutrientEC = 0.0f;

    float Nitrogen = 0.0f;
    float Phosphorus = 0.0f;
    float Potassium = 0.0f;


    // =========================================================
    // ROOT ENVIRONMENT — BEFORE
    // =========================================================

    float RootTemperature = 0.0f;
    float RootMoisture = 0.0f;
    float RootOxygen = 0.0f;


    // =========================================================
    // PLANT — BEFORE
    // =========================================================

    float PlantHealth = 0.0f;
    float PlantGrowth = 0.0f;
    float PlantStress = 0.0f;

    float LeafTemperature = 0.0f;
    float LeafMoisture = 0.0f;


    // =========================================================
    // SYSTEM — BEFORE
    // =========================================================

    float BatteryLevel = 0.0f;
    float SystemTemperature = 0.0f;

    bool bWaterAvailable = false;
    bool bNutrientsAvailable = false;
    bool bSystemHealthy = true;


    // =========================================================
    // ACTION
    // =========================================================

    uint16_t IrrigationDuration = 0;
    uint16_t NutrientDuration = 0;

    bool bIrrigationPerformed = false;
    bool bNutrientsAdded = false;

    bool bVentilationChanged = false;
    bool bLightingChanged = false;


    // =========================================================
    // ENVIRONMENT — AFTER
    // =========================================================

    float TemperatureAfter = 0.0f;
    float HumidityAfter = 0.0f;
    float PressureAfter = 0.0f;

    float LightLevelAfter = 0.0f;
    float UVLevelAfter = 0.0f;

    float CO2LevelAfter = 0.0f;
    float AirQualityAfter = 0.0f;


    // =========================================================
    // WATER — AFTER
    // =========================================================

    float WaterLevelAfter = 0.0f;
    float WaterTemperatureAfter = 0.0f;
    float WaterFlowRateAfter = 0.0f;

    float WaterPHAfter = 0.0f;
    float WaterECAfter = 0.0f;
    float WaterTDSAfter = 0.0f;


    // =========================================================
    // NUTRIENTS — AFTER
    // =========================================================

    float NutrientLevelAfter = 0.0f;
    float NutrientECAfter = 0.0f;

    float NitrogenAfter = 0.0f;
    float PhosphorusAfter = 0.0f;
    float PotassiumAfter = 0.0f;


    // =========================================================
    // ROOT ENVIRONMENT — AFTER
    // =========================================================

    float RootTemperatureAfter = 0.0f;
    float RootMoistureAfter = 0.0f;
    float RootOxygenAfter = 0.0f;


    // =========================================================
    // PLANT — AFTER
    // =========================================================

    float PlantHealthAfter = 0.0f;
    float PlantGrowthAfter = 0.0f;
    float PlantStressAfter = 0.0f;

    float LeafTemperatureAfter = 0.0f;
    float LeafMoistureAfter = 0.0f;


    // =========================================================
    // SYSTEM — AFTER
    // =========================================================

    float BatteryLevelAfter = 0.0f;
    float SystemTemperatureAfter = 0.0f;

    bool bWaterAvailableAfter = false;
    bool bNutrientsAvailableAfter = false;
    bool bSystemHealthyAfter = true;


    // =========================================================
    // TIME
    // =========================================================

    uint32_t Timestamp = 0;
    uint32_t Duration = 0;

  // =========================================================
    // RESET
    // =========================================================

    void Reset()
    {
        // Environment — Before
        Temperature = 0.0f;
        Humidity = 0.0f;
        Pressure = 0.0f;
        LightLevel = 0.0f;
        UVLevel = 0.0f;
        CO2Level = 0.0f;
        AirQuality = 0.0f;

        // Water — Before
        WaterLevel = 0.0f;
        WaterTemperature = 0.0f;
        WaterFlowRate = 0.0f;
        WaterPH = 0.0f;
        WaterEC = 0.0f;
        WaterTDS = 0.0f;

        // Nutrients — Before
        NutrientLevel = 0.0f;
        NutrientEC = 0.0f;
        Nitrogen = 0.0f;
        Phosphorus = 0.0f;
        Potassium = 0.0f;

        // Root — Before
        RootTemperature = 0.0f;
        RootMoisture = 0.0f;
        RootOxygen = 0.0f;

        // Plant — Before
        PlantHealth = 0.0f;
        PlantGrowth = 0.0f;
        PlantStress = 0.0f;
        LeafTemperature = 0.0f;
        LeafMoisture = 0.0f;

        // System — Before
        BatteryLevel = 0.0f;
        SystemTemperature = 0.0f;
        bWaterAvailable = false;
        bNutrientsAvailable = false;
        bSystemHealthy = true;

        // Action
        IrrigationDuration = 0;
        NutrientDuration = 0;
        bIrrigationPerformed = false;
        bNutrientsAdded = false;
        bVentilationChanged = false;
        bLightingChanged = false;

        // Environment — After
        TemperatureAfter = 0.0f;
        HumidityAfter = 0.0f;
        PressureAfter = 0.0f;
        LightLevelAfter = 0.0f;
        UVLevelAfter = 0.0f;
        CO2LevelAfter = 0.0f;
        AirQualityAfter = 0.0f;

        // Water — After
        WaterLevelAfter = 0.0f;
        WaterTemperatureAfter = 0.0f;
        WaterFlowRateAfter = 0.0f;
        WaterPHAfter = 0.0f;
        WaterECAfter = 0.0f;
        WaterTDSAfter = 0.0f;

        // Nutrients — After
        NutrientLevelAfter = 0.0f;
        NutrientECAfter = 0.0f;
        NitrogenAfter = 0.0f;
        PhosphorusAfter = 0.0f;
        PotassiumAfter = 0.0f;

        // Root — After
        RootTemperatureAfter = 0.0f;
        RootMoistureAfter = 0.0f;
        RootOxygenAfter = 0.0f;

        // Plant — After
        PlantHealthAfter = 0.0f;
        PlantGrowthAfter = 0.0f;
        PlantStressAfter = 0.0f;
        LeafTemperatureAfter = 0.0f;
        LeafMoistureAfter = 0.0f;

        // System — After
        BatteryLevelAfter = 0.0f;
        SystemTemperatureAfter = 0.0f;
        bWaterAvailableAfter = false;
        bNutrientsAvailableAfter = false;
        bSystemHealthyAfter = true;

        // Time
        Timestamp = 0;
        Duration = 0;
    }
};