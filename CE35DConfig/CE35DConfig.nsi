!include "MUI.nsh"
!addplugindir "${NSISDIR}\Plugins\x86-unicode"

Name "CE35D_Config"
OutFile "application\CE35D_Config.exe"

RequestExecutionLevel admin
BrandingText "Intellect module, 2020"

!define MUI_ICON "CE35DConfig\iml_logo.ico"
!define MUI_UNICON "CE35DConfig\iml_logo.ico"


InstallDir "$PROGRAMFILES\Intellect module\CE35D_Config_win32"
SetCompressor lzma

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_LANGUAGE "Russian"

Section "CE35D_Config"
SetShellVarContext all

SetOutPath "$INSTDIR"
File /nonfatal /a /r "CE35DConfig-bin\"

WriteUninstaller "$INSTDIR\Uninstall.exe"
SetShellVarContext all
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CE35D_Config_win32" "DisplayName" "CE35D_Config"
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CE35D_Config_win32" "UninstallString" '"$INSTDIR\Uninstall.exe"'
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CE35D_Config_win32" "DisplayIcon" '"$INSTDIR\CE35DConfig_win32.exe"'
/*ExecWait  '"$INSTDIR\CDM v2.12.00 WHQL Certified.exe"'*/
SectionEnd

Section "Start Menu Shortcuts"
SetShellVarContext all
  CreateDirectory "$SMPROGRAMS\Intellect module\CE35D_Config_win32"
  CreateShortcut "$SMPROGRAMS\Intellect module\CE35D_Config_win32\Uninstall.lnk" "$INSTDIR\Uninstall.exe" "" "$INSTDIR\Uninstall.exe" 0
  CreateShortcut "$SMPROGRAMS\Intellect module\CE35D_Config_win32\iNode CE-35D Config.lnk" "$INSTDIR\CE35DConfig_win32.exe" "" "$INSTDIR\CE35DConfig_win32.exe" 0
SectionEnd

Section "Desktop Shortcuts"
SetShellVarContext all
  CreateShortcut "$DESKTOP\iNode CE-35D Config.lnk" "$INSTDIR\CE35DConfig_win32.exe" "$INSTDIR\CE35DConfig_win32.exe" ""
SectionEnd

Section "Uninstall"
SetShellVarContext all
StrCpy $0 "CE35DConfig_win32.exe"
DetailPrint "Killing all processed called '$0'"
KillProc::KillProcesses
DetailPrint "Killed $0 processes"

RMDIR /r  "$INSTDIR"
RMDIR /r  "$SMPROGRAMS\Intellect module\CE35D_Config_win32"
RMDIR  "$SMPROGRAMS\Intellect module"
Delete "$DESKTOP\iNode CE-35D Config.lnk"
DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CE35D_Config_win32"
SectionEnd
