#include "System.h"

#include "Devices/Buzzer/Buzzer.h"
#include "Devices/Display/Display.h"
#include "Devices/LED/LED.h"
#include "Devices/WaterPump/WaterPump.h"
#include "Sensors/Infrared/InfraredReceiver.h"
#include "Sensors/Infrared/InfraredTransmitter.h"
#include "Sensors/Ultrasonic/UltrasonicSensor.h"
#include "Sensors/Audio/AudioSensor.h"
#include "Sensors/Motion/MotionSensor.h"

#include "Manager/Program/ProgramManager.h"

System GSystem;

void System::Initialize()
{
    Serial.begin(9600);
    Serial.println("SYSTEM STARTED");

    InitializeSystems();
    GProgramManager.Start(ProgramType);
    State = ESystemState::Operational;
}

void System::Update()
{
    if (State != ESystemState::Operational)
    {
        return;
    }
    GProgramManager.UpdateProgram();
}

ESystemState System::GetSystemState() const
{
    return State;
}

EProgramType System::GetProgramType() const
{
    return ProgramType;
}

void System::InitializeSystems()
{
    State = ESystemState::Initializing;
    InitializeDevices();
    InitializeSensors();
}

void System::InitializeDevices()
{
    GDisplay.Initialize();
    GLED.Initialize();
    GBuzzer.Initialize();
    GWaterPump.Initialize();
}

void System::InitializeSensors()
{
    GInfraredTransmitter.Initialize();
    GInfraredReceiver.Initialize();
    GUltrasonicSensor.Initialize();
    GAudioSensor.Initialize();
    GMotionSensor.Initialize();
}