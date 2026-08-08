#include "InfraredProgram.h"

#include "Devices/Display/Display.h"
#include "Sensors/Infrared/InfraredReceiver.h"
#include "Sensors/Infrared/InfraredTransmitter.h"
#include "Devices/LED/LED.h"
#include "Manager/Audio/AudioManager.h"

InfraredProgram GInfraredProgram;

void InfraredProgram::Begin()
{
    bTransmissionSucceeded = false;
    bSignalReceived = false;
    LastReceivedCode = 0;

    GDisplay.Show
    (
        "INFRARED TEST",
        "INITIALIZING"
    );
}


void InfraredProgram::Update()
{
    ReceiveTestSignal();
}

void InfraredProgram::SendTestSignal()
{
    
}
void InfraredProgram::ReceiveTestSignal()
{
    GInfraredReceiver.Update();

    const auto& Data = GInfraredReceiver.GetData();

    if (Data.Protocol != 7 || Data.Address != 0x40)
    {
        bButtonPressed = false;
        return;
    }

    if (bButtonPressed && Data.Command == LastCommand)
    {
        return;
    }

    bButtonPressed = true;
    LastCommand = Data.Command;

    switch (Data.Command)
    {
        case 0x01:
            GDisplay.Show("BUTTON 1", "PRESSED");
            GLED.EnableRed();
            GLED.DisableGreen();
            break;

        case 0x02:
            GDisplay.Show("BUTTON 2", "PRESSED");
            GLED.EnableGreen();
            GLED.DisableRed();
            break;

        case 0x03:
            GDisplay.Show("BUTTON 3", "PRESSED");
            GAudioManager.Beep();
            GLED.DisableRed();
            GLED.DisableGreen();
            break;

        case 0x04:
            GDisplay.Show("BUTTON 4", "PRESSED");
            GAudioManager.DoubleBeep();
            break;

        case 0x05:
            GDisplay.Show("BUTTON 5", "PRESSED");
            GLED.DisableRed();
            GLED.DisableGreen();
            break;

        case 0x06:
            GDisplay.Show("BUTTON 6", "PRESSED");
            GAudioManager.Success();
            break;
    }
}

void InfraredProgram::UpdateDisplay()
{
    char TopLine[17];
    char BottomLine[17];

    if (!bSignalReceived)
    {
        GDisplay.Show
        (
            "IR TEST",
            "WAITING..."
        );
        return;
    }

    GDisplay.Show
    (
        "NOT",
        "PROCEED..."
    );

    snprintf
    (
        TopLine,
        sizeof(TopLine),
        "TX:%04lX",
        (unsigned long)(TestCode & 0xFFFF)
    );

    snprintf
    (
        BottomLine,
        sizeof(BottomLine),
        "RX:%04lX",
        (unsigned long)(LastReceivedCode & 0xFFFF)
    );

    GDisplay.Show
    (
        TopLine,
        BottomLine
    );
}