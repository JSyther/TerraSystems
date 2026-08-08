#include "ProgramManager.h"
#include "Programs/Test/RelayTest.h"
#include "Programs/Standby/Standby.h"
#include "Programs/DHT11/DHT11Program.h"
#include "Programs/Standoff/Standoff.h"
#include "Programs/InfraredProgram/InfraredProgram.h"
#include "Programs/Ultrasonic/UltrasonicProgram.h"
#include "Programs/AudioSensorProgram/AudioSensorProgram.h"
#include "Programs/MotionSensor/MotionSensorProgram.h"

ProgramManager GProgramManager;


void ProgramManager::Start(EProgramType Program)
{
    ActiveProgram = Program;
    BeginProgram();
}

void ProgramManager::Stop()
{
    ActiveProgram = EProgramType::None;

    GRelayTest.Stop();
}


void ProgramManager::BeginProgram()
{
    switch (ActiveProgram)
    {
        case EProgramType::RelayTest:
        GRelayTest.Start();
        break;

        case EProgramType::Standby:
        GStandby.Begin();
        break;

        case EProgramType::Standoff:
        GStandoff.Begin();
        break;

        case EProgramType::DHT11Program:
        GDHT11Program.Begin();
        break;

        case EProgramType::InfraredProgram:
        GInfraredProgram.Begin();
        break;

        case EProgramType::UltrasonicProgram:
        GUltrasonicProgram.Begin();
        break;

        case EProgramType::AudioSensorProgram:
        GAudioSensorProgram.Begin();
        break;

        case EProgramType::MotionSensorProgram:
        GMotionSensorProgram.Begin();
        break;

        default:
        break;
    }
}

void ProgramManager::UpdateProgram()
{
    switch (ActiveProgram)
    {
        case EProgramType::RelayTest:
        GRelayTest.Update();
        break;

        case EProgramType::Standby:
        GStandby.Update();
        break;

        case EProgramType::DHT11Program:
        GDHT11Program.Update();
        break;

        case EProgramType::Standoff:
        GStandoff.Shutdown();
        break;

        case EProgramType::InfraredProgram:
        GInfraredProgram.Update();
        break;

        case EProgramType::UltrasonicProgram:
        GUltrasonicProgram.Update();
        break;

        case EProgramType::AudioSensorProgram:
        GAudioSensorProgram.Update();
        break;

        case EProgramType::MotionSensorProgram:
        GMotionSensorProgram.Update();
        break;
    
        default:
        break;
    }
}


EProgramType ProgramManager::GetActiveProgram() const
{
    return ActiveProgram;
}
