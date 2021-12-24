@echo off
setlocal

:_64bit

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64"

set "USERNAME=appveyor"
set "USERDOMAIN=APPVYR-WIN"

nmake -f Make_mvc.mak clean
nmake -f Make_mvc.mak "DEFINES=-DFEAT_PROPORTIONAL_FONTS" GUI=yes OLE=no DIRECTX=yes COLOR_EMOJI=yes FEATURES=HUGE IME=yes MBYTE=yes ICONV=yes DEBUG=no CSCOPE=yes OPTIMIZE=MAXSPEED TERMINAL=yes

nmake -f Make_mvc.mak clean
nmake -f Make_mvc.mak                                     GUI=no  OLE=no DIRECTX=no  COLOR_EMOJI=yes FEATURES=HUGE IME=yes MBYTE=yes ICONV=yes DEBUG=no CSCOPE=yes OPTIMIZE=MAXSPEED TERMINAL=yes

exit /b
