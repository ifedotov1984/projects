!include "MUI.nsh"
!addplugindir "${NSISDIR}\Plugins\x86-unicode"

Name "IML_Ethernet_Loader"
OutFile "application\IML_Ethernet_Loader_setup.exe"

RequestExecutionLevel admin
BrandingText "Intellect module, 2020"

!define MUI_ICON "IMLEthernetLoader\iml_logo.ico"
!define MUI_UNICON "IMLEthernetLoader\iml_logo.ico"


InstallDir "$PROGRAMFILES\Intellect module\IML_Ethernet_Loader_win32"
SetCompressor lzma

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_LANGUAGE "Russian"

Section "IML_Ethernet_Loader"
SetShellVarContext all

SetOutPath "$INSTDIR"
File /nonfatal /a /r "IMLEthernetLoader-bin\"

WriteUninstaller "$INSTDIR\Uninstall.exe"
SetShellVarContext all
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\IML_Ethernet_Loader_win32" "DisplayName" "IML Ethernet Loader"
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\IML_Ethernet_Loader_win32" "UninstallString" '"$INSTDIR\Uninstall.exe"'
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\IML_Ethernet_Loader_win32" "DisplayIcon" '"$INSTDIR\IMLEthernetLoader_win32.exe"'
/*ExecWait  '"$INSTDIR\CDM v2.12.00 WHQL Certified.exe"'*/
SectionEnd

Section "Start Menu Shortcuts"
SetShellVarContext all
  CreateDirectory "$SMPROGRAMS\Intellect module\IML_Ethernet_Loader_win32"
  CreateShortcut "$SMPROGRAMS\Intellect module\IML_Ethernet_Loader_win32\Uninstall.lnk" "$INSTDIR\Uninstall.exe" "" "$INSTDIR\Uninstall.exe" 0
  CreateShortcut "$SMPROGRAMS\Intellect module\IML_Ethernet_Loader_win32\IML Ethernet Loader.lnk" "$INSTDIR\IMLEthernetLoader_win32.exe" "" "$INSTDIR\IMLEthernetLoader_win32.exe" 0
SectionEnd

Section "Desktop Shortcuts"
SetShellVarContext all
  CreateShortcut "$DESKTOP\IML Ethernet Loader.lnk" "$INSTDIR\IMLEthernetLoader_win32.exe" "$INSTDIR\IMLEthernetLoader_win32.exe" ""
SectionEnd

Section "Uninstall"
SetShellVarContext all
StrCpy $0 "IMLEthernetLoader_win32.exe"
DetailPrint "Killing all processed called '$0'"
KillProc::KillProcesses
DetailPrint "Killed $0 processes"

RMDIR /r  "$INSTDIR"
RMDIR /r  "$SMPROGRAMS\Intellect module\IML_Ethernet_Loader_win32"
RMDIR  "$SMPROGRAMS\Intellect module"
Delete "$DESKTOP\IML Ethernet Loader.lnk"
DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\IML_Ethernet_Loader_win32"
SectionEnd
