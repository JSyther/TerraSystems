#include "Floria.h"

namespace
{
    constexpr uint16_t IrrigationDurations[5] =
    {
        2,
        4,
        6,
        8,
        10
    };

    constexpr uint8_t IrrigationStateCount = 5;
    constexpr uint8_t IrrigationActionCount = 5;
    constexpr uint16_t ExplorationSamples = 10;
}

void Floria::Initialize()
{
    Reset();
}

void Floria::Update(const SFloriaState& State)
{
    CurrentState = State;
    CurrentDecision.Reset();

    if (!State.bSystemHealthy)
    {
        CurrentDecision.Type = EFloriaDecisionType::Emergency;
        CurrentDecision.bEmergency = true;
        return;
    }

    if (!State.bWaterAvailable)
    {
        CurrentDecision.Type = EFloriaDecisionType::Monitoring;
        return;
    }

    const uint16_t IrrigationDuration =
        SelectIrrigationDuration(State);

    if (IrrigationDuration == 0)
    {
        CurrentDecision.Type = EFloriaDecisionType::Monitoring;
        return;
    }

    CurrentDecision.Type =
        EFloriaDecisionType::Irrigation;

    CurrentDecision.bIrrigation = true;
    CurrentDecision.bWaterPump = true;

    CurrentDecision.IrrigationDuration =
        IrrigationDuration;

    CurrentDecision.WaterPumpDuration =
        IrrigationDuration;
}

void Floria::Learn(
    const SFloriaState& PreviousState,
    const SFloriaDecision& PreviousDecision,
    const SFloriaState& State)
{
    if (!PreviousDecision.bIrrigation)
    {
        return;
    }

    UpdateIrrigationKnowledge(
        PreviousState,
        PreviousDecision,
        State);
}

const SFloriaDecision& Floria::GetDecision() const
{
    return CurrentDecision;
}

const SFloriaState& Floria::GetState() const
{
    return CurrentState;
}

SFloriaMemory& Floria::GetMemory()
{
    return Memory;
}

void Floria::Reset()
{
    CurrentState.Reset();
    CurrentDecision.Reset();
    Memory.Reset();

    for (uint8_t State = 0;
         State < IrrigationStateCount;
         ++State)
    {
        for (uint8_t Action = 0;
             Action < IrrigationActionCount;
             ++Action)
        {
            IrrigationKnowledge.Score[State][Action] = 0.0f;
            IrrigationKnowledge.Samples[State][Action] = 0;
        }
    }
}

uint8_t Floria::GetIrrigationIndex(
    const SFloriaState& State) const
{
    if (State.RootMoisture < 20.0f)
    {
        return 0;
    }

    if (State.RootMoisture < 30.0f)
    {
        return 1;
    }

    if (State.RootMoisture < 40.0f)
    {
        return 2;
    }

    if (State.RootMoisture < 50.0f)
    {
        return 3;
    }

    return 4;
}

uint16_t Floria::SelectIrrigationDuration(
    const SFloriaState& State)
{
    const uint8_t StateIndex =
        GetIrrigationIndex(State);

    uint16_t TotalSamples = 0;

    for (uint8_t Action = 0;
         Action < IrrigationActionCount;
         ++Action)
    {
        TotalSamples +=
            IrrigationKnowledge.Samples
            [StateIndex][Action];
    }

    if (TotalSamples < ExplorationSamples)
    {
        return IrrigationDurations[
            TotalSamples % IrrigationActionCount
        ];
    }

    uint8_t BestAction = 0;

    float BestScore =
        IrrigationKnowledge.Score
        [StateIndex][0];

    for (uint8_t Action = 1;
         Action < IrrigationActionCount;
         ++Action)
    {
        const float Score =
            IrrigationKnowledge.Score
            [StateIndex][Action];

        if (Score > BestScore)
        {
            BestScore = Score;
            BestAction = Action;
        }
    }

    return IrrigationDurations[BestAction];
}

float Floria::EvaluateIrrigationResult(
    const SFloriaState& PreviousState,
    const SFloriaState& State) const
{
    const float MoistureChange =
        State.RootMoisture -
        PreviousState.RootMoisture;

    if (PreviousState.RootMoisture < 30.0f)
    {
        if (MoistureChange >= 10.0f &&
            MoistureChange <= 30.0f)
        {
            return 1.0f;
        }

        if (MoistureChange > 30.0f)
        {
            return 0.25f;
        }

        return -0.5f;
    }

    if (PreviousState.RootMoisture >= 45.0f)
    {
        if (MoistureChange > 10.0f)
        {
            return -1.0f;
        }

        return 0.5f;
    }

    if (MoistureChange >= 5.0f &&
        MoistureChange <= 20.0f)
    {
        return 1.0f;
    }

    if (MoistureChange > 20.0f)
    {
        return 0.25f;
    }

    return -0.3f;
}

void Floria::UpdateIrrigationKnowledge(
    const SFloriaState& PreviousState,
    const SFloriaDecision& Decision,
    const SFloriaState& State)
{
    const uint8_t StateIndex =
        GetIrrigationIndex(PreviousState);

    uint8_t ActionIndex = 0;

    for (uint8_t Action = 0;
         Action < IrrigationActionCount;
         ++Action)
    {
        if (Decision.IrrigationDuration ==
            IrrigationDurations[Action])
        {
            ActionIndex = Action;
            break;
        }
    }

    const float Score =
        EvaluateIrrigationResult(
            PreviousState,
            State);

    const uint16_t Samples =
        IrrigationKnowledge.Samples
        [StateIndex][ActionIndex];

    const float PreviousScore =
        IrrigationKnowledge.Score
        [StateIndex][ActionIndex];

    const float UpdatedScore =
        PreviousScore +
        (
            (Score - PreviousScore) /
            static_cast<float>(Samples + 1)
        );

    IrrigationKnowledge.Score
        [StateIndex][ActionIndex] =
        UpdatedScore;

    IrrigationKnowledge.Samples
        [StateIndex][ActionIndex]++;
}