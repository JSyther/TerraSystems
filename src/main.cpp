#include <Arduino.h>
#include "Core/System/System.h"

void setup()
{
  GSystem.Initialize();
}

void loop()
{
  GSystem.Update();
}