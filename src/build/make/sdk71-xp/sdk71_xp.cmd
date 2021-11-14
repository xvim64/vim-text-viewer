@echo off
setlocal

call "C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\SetEnv.cmd"

set "USERNAME=appveyor"
set "USERDOMAIN=APPVYR-WIN"

nmake.exe -f Make_mvc.mak clean
nmake.exe -f Make_mvc.mak "DEFINES=-DFEAT_PROPORTIONAL_FONTS" GUI=yes OLE=no DIRECTX=yes COLOR_EMOJI=no FEATURES=HUGE IME=yes MBYTE=yes ICONV=yes DEBUG=no CSCOPE=yes OPTIMIZE=MAXSPEED TERMINAL=yes

exit /b
