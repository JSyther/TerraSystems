#include <stdint.h>

struct FInfraredReceiver
{
    uint32_t RawData = 0;
    uint16_t Address = 0;
    uint16_t Command = 0;
    uint8_t Protocol = 0;
    uint8_t NumberOfBits = 0;
    uint8_t Flags = 0;
};

struct FInfraredTransmitter
{
    uint32_t TestCode = 0x20DF10EF;

    uint16_t SendInterval = 2000;
    uint16_t BlinkDuration = 100;

    uint8_t BlinkCount = 2;

    bool EnableFeedback = true;
};

struct FInfraredData
{
    FInfraredReceiver Receiver;
    FInfraredTransmitter Transmitter;
};

namespace IRButton
{
    constexpr uint16_t Address = 0x40;

    constexpr uint16_t Key1 = 0x01;
    constexpr uint16_t Key3 = 0x03;
    constexpr uint16_t Key4 = 0x04;
    constexpr uint16_t Key5 = 0x05;
    constexpr uint16_t Key6 = 0x06;
}

namespace IRConfig
{
    constexpr uint8_t MaxCodes = 10;

    struct FIRButton
    {
        uint32_t RawData = 0;
        uint16_t Address = 0;
        uint16_t Command = 0;
    };

    struct FIRProfile
    {
        FIRButton Buttons[MaxCodes];
        uint8_t Count = 0;

        void Clear()
        {
            Count = 0;
        }

        bool Store(uint32_t RawData, uint16_t Address, uint16_t Command)
        {
            for (uint8_t i = 0; i < Count; ++i)
            {
                if (Buttons[i].Address == Address &&
                    Buttons[i].Command == Command)
                {
                    return false;
                }
            }

            if (Count >= MaxCodes)
            {
                return false;
            }

            Buttons[Count].RawData = RawData;
            Buttons[Count].Address = Address;
            Buttons[Count].Command = Command;

            ++Count;

            return true;
        }
    };

    inline FIRProfile Profile;
}