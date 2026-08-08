#pragma once

#include <Arduino.h>

enum class EFloriaDecisionType : uint8_t
{
    None,

    Irrigation,
    NutrientDosing,

    Ventilation,
    Lighting,

    WaterManagement,

    Monitoring,
    Calibration,

    Emergency
};

struct SFloriaDecision
{
    EFloriaDecisionType Type = EFloriaDecisionType::None;

    // =========================================================
    // IRRIGATION
    // =========================================================

    bool bIrrigation = false;
    uint16_t IrrigationDuration = 0;


    // =========================================================
    // NUTRIENT DOSING
    // =========================================================

    bool bNutrientDosing = false;
    uint16_t NutrientDuration = 0;


    // =========================================================
    // WATER MANAGEMENT
    // =========================================================

    bool bWaterPump = false;
    bool bReversePump = false;

    uint16_t WaterPumpDuration = 0;
    uint16_t ReversePumpDuration = 0;


    // =========================================================
    // VENTILATION
    // =========================================================

    bool bVentilation = false;
    uint8_t VentilationLevel = 0;


    // =========================================================
    // LIGHTING
    // =========================================================

    bool bLighting = false;
    uint8_t LightingLevel = 0;


    // =========================================================
    // SAFETY
    // =========================================================

    bool bEmergency = false;
    bool bSystemShutdown = false;


    // =========================================================
    // DECISION INFORMATION
    // =========================================================

    float Confidence = 0.0f;

    uint32_t Duration = 0;


    // =========================================================
    // RESET
    // =========================================================

    void Reset()
    {
        Type = EFloriaDecisionType::None;

        bIrrigation = false;
        IrrigationDuration = 0;

        bNutrientDosing = false;
        NutrientDuration = 0;

        bWaterPump = false;
        bReversePump = false;

        WaterPumpDuration = 0;
        ReversePumpDuration = 0;

        bVentilation = false;
        VentilationLevel = 0;

        bLighting = false;
        LightingLevel = 0;

        bEmergency = false;
        bSystemShutdown = false;

        Confidence = 0.0f;
        Duration = 0;
    }
};