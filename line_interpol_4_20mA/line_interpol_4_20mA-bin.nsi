Unicode True
!include "MUI.nsh"

Name "Line interpol 4_20mA"
OutFile "application\line_interpol_4_20mA_setup.exe"

RequestExecutionLevel admin
BrandingText "Intellect module, 2021"

!define MUI_ICON "line_interpol_4_20mA\iml_logo.ico"
!define MUI_UNICON "line_interpol_4_20mA\iml_logo.ico"


InstallDir "$PROGRAMFILES\Intellect module\line_interpol_4_20mA_win32"
SetCompressor lzma

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_LANGUAGE "Russian"

Section "line_interpol_4_20mA"
SetShellVarContext all

SetOutPath "$INSTDIR"
File /nonfatal /a /r "line_interpol_4_20mA-bin\"

WriteUninstaller "$INSTDIR\Uninstall.exe"
SetShellVarContext all
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\line_interpol_4_20mA_win32" "DisplayName" "Line interpol 4_20mA"
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\line_interpol_4_20mA_win32" "UninstallString" '"$INSTDIR\Uninstall.exe"'
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\line_interpol_4_20mA_win32" "DisplayIcon" '"$INSTDIR\line_interpol_4_20mA_win32.exe"'
SectionEnd

Section "Start Menu Shortcuts"
SetShellVarContext all
  CreateDirectory "$SMPROGRAMS\Intellect module\line_interpol_4_20mA_win32"
  CreateShortcut "$SMPROGRAMS\Intellect module\line_interpol_4_20mA_win32\Uninstall.lnk" "$INSTDIR\Uninstall.exe" "" "$INSTDIR\Uninstall.exe" 0
  CreateShortcut "$SMPROGRAMS\Intellect module\line_interpol_4_20mA_win32\Line interpol 4_20mA.lnk" "$INSTDIR\line_interpol_4_20mA_win32.exe" "" "$INSTDIR\line_interpol_4_20mA_win32.exe" 0
SectionEnd

Section "Desktop Shortcuts"
SetShellVarContext all
  CreateShortcut "$DESKTOP\Line interpol 4_20mA.lnk" "$INSTDIR\line_interpol_4_20mA_win32.exe" "$INSTDIR\line_interpol_4_20mA_win32.exe" ""
SectionEnd

Section "Uninstall"
SetShellVarContext all
StrCpy $0 "line_interpol_4_20mA_win32.exe"
DetailPrint "Killing all processed called '$0'"
KillProc::KillProcesses
DetailPrint "Killed $0 processes"

RMDIR /r  "$INSTDIR"
RMDIR /r  "$SMPROGRAMS\Intellect module\line_interpol_4_20mA_win32"
RMDIR  "$SMPROGRAMS\Intellect module"
Delete "$DESKTOP\Line interpol 4_20mA.lnk"
DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\line_interpol_4_20mA_win32"
SectionEnd
