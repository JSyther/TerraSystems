#include "InfraredTransmitter.h"
#include "Configuration/PinConfig.h"
#include <IRremote.hpp>


InfraredTransmitter GInfraredTransmitter;


void InfraredTransmitter::Initialize()
{
    IrSender.begin(PinConfig::IRTransmitter);
}


void InfraredTransmitter::Update()
{

}


void InfraredTransmitter::Send(uint32_t Code)
{
    IrSender.sendNECRaw(Code, 0);
}


void InfraredTransmitter::Send(uint32_t Code, uint8_t Repeats)
{
    IrSender.sendNECRaw(Code, Repeats);
}


void InfraredTransmitter::SendNEC(uint16_t Address, uint16_t Command)
{
    IrSender.sendNEC(Address, Command, 0);
}


void InfraredTransmitter::Stop()
{
    
}