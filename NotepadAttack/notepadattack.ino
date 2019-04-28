#include "DigiKeyboard.h"
void setup() 
{
  //left empty deliberately
}
void loop() 
{
DigiKeyboard.delay(10000);
DigiKeyboard.update();
DigiKeyboard.delay(100);
// meta+r, delete content, start notepad
DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // meta+r
DigiKeyboard.delay(100);
DigiKeyboard.sendKeyStroke(76); // Clean it up
DigiKeyboard.delay(50);
DigiKeyboard.println("notepad.exe");
DigiKeyboard.delay(200);
DigiKeyboard.println("Hello, your PC has been found to have an extremely severe vulnerability, please phone the emergency IT Help-desk on 01234 567 890");
}
