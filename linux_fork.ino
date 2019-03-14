#include "DigiKeyboard.h"

void setup() 
{
  //empty
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(MOD_GUI_CENTRE);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_ALT_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(":(){ :|: & };:");
  DigiKeyboard.delay(250);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;)
  {
    //empty
  }
}
