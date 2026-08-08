#include "InfraredReceiver.h"
#include "Configuration/PinConfig.h"

#include "Devices/Display/Display.h"
#include "Audio/AudioManager.h"

#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <IRremote.hpp>


InfraredReceiver GInfraredReceiver;

static bool GSignalAvailable = false;

void InfraredReceiver::Initialize()
{
    IrReceiver.begin(PinConfig::IRReceiver, ENABLE_LED_FEEDBACK);

    GSignalAvailable = false;
}

void InfraredReceiver::Update()
{
    if (!IrReceiver.decode())
    {
        return;
    }

    Data.RawData      = IrReceiver.decodedIRData.decodedRawData;
    Data.Address      = IrReceiver.decodedIRData.address;
    Data.Command      = IrReceiver.decodedIRData.command;
    Data.Protocol     = static_cast<uint8_t>(IrReceiver.decodedIRData.protocol);
    Data.NumberOfBits = IrReceiver.decodedIRData.numberOfBits;
    Data.Flags        = IrReceiver.decodedIRData.flags;

    if (Data.Protocol == 7 && Data.Address == 0x40)
    {
        switch (Data.Command)
        {
            case 0x01:
                // Button 1
                break;

            case 0x02:
                // Button 2
                break;

            case 0x03:
                // Button 3
                break;

            case 0x04:
                // Button 4
                break;

            case 0x05:
                // Button 5
                break;

            case 0x06:
                // Button 6
                break;

            default:
                break;
        }
    }

    IrReceiver.resume();
}

bool InfraredReceiver::Available() const
{
    return GSignalAvailable;
}

uint32_t InfraredReceiver::Read() const
{
    return IrReceiver.decodedIRData.decodedRawData;
}

void InfraredReceiver::Resume()
{
    IrReceiver.resume();

    GSignalAvailable = false;
}

uint32_t InfraredReceiver::GetRawData() const
{
    return IrReceiver.decodedIRData.decodedRawData;
}

uint16_t InfraredReceiver::GetAddress() const
{
    return IrReceiver.decodedIRData.address;
}

uint16_t InfraredReceiver::GetCommand() const
{
    return IrReceiver.decodedIRData.command;
}

uint8_t InfraredReceiver::GetProtocol() const
{
    return static_cast<uint8_t>(IrReceiver.decodedIRData.protocol);
}

uint8_t InfraredReceiver::GetNumberOfBits() const
{
    return IrReceiver.decodedIRData.numberOfBits;
}

void InfraredReceiver::PrintDebug()
{
    IrReceiver.printIRResultRawFormatted(&Serial, true);
}

const FInfraredReceiver& InfraredReceiver::GetData() const
{
    return Data;
}