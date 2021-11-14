@echo off
setlocal

:_64bit

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" amd64

set WinSdk71=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A
set INCLUDE=%WinSdk71%\Include;%INCLUDE%
set LIB=%WinSdk71%\Lib\x64;%LIB%
set CL=/D_USING_V110_SDK71_

set "USERNAME=appveyor"
set "USERDOMAIN=APPVYR-WIN"

nmake -f Make_mvc.mak clean
nmake -f Make_mvc.mak "DEFINES=-DFEAT_PROPORTIONAL_FONTS" WINVER=0x0501 SUBSYSTEM_VER=5.02 GUI=yes OLE=no DIRECTX=yes COLOR_EMOJI=no FEATURES=HUGE IME=yes MBYTE=yes ICONV=yes DEBUG=no CSCOPE=yes OPTIMIZE=MAXSPEED TERMINAL=yes

exit /b
