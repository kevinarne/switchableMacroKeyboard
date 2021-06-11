/*
  MacroKeyboard.cpp - Library for managing Kevin's macrokeyboard
  Created by Kevin Arne, June 6, 2021
*/

#include "Arduino.h"
#include "MacroKeyboard.h"


MacroKeyboard::MacroKeyboard()
{
  Serial.begin(9600);
  printSuccess();
}

void MacroKeyboard::printSuccess()
{
  Serial.println("Success")
}
