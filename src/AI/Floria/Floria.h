#pragma once

#include <Arduino.h>

#include "FloriaState.h"
#include "FloriaDecision.h"
#include "FloriaMemory.h"

class Floria
{
public:

    void Initialize();

    void Update(const SFloriaState& State);

    void Learn(
        const SFloriaState& PreviousState,
        const SFloriaDecision& PreviousDecision,
        const SFloriaState& State
    );

    const SFloriaDecision& GetDecision() const;

    const SFloriaState& GetState() const;

    SFloriaMemory& GetMemory();

    void Reset();

private:

    struct SIrrigationKnowledge
    {
        float Score[5][5] = {};

        uint16_t Samples[5][5] = {};
    };

private:

    SFloriaState CurrentState;

    SFloriaDecision CurrentDecision;

    SFloriaMemory Memory;

    SIrrigationKnowledge IrrigationKnowledge;

private:

    uint8_t GetIrrigationIndex(
        const SFloriaState& State
    ) const;

    uint16_t SelectIrrigationDuration(
        const SFloriaState& State
    );

    float EvaluateIrrigationResult(
        const SFloriaState& PreviousState,
        const SFloriaState& State
    ) const;

    void UpdateIrrigationKnowledge(
        const SFloriaState& PreviousState,
        const SFloriaDecision& Decision,
        const SFloriaState& State
    );
};