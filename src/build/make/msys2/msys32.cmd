@echo off
setlocal

set PATH=c:\msys64\mingw32\bin;c:\msys64\usr\bin;%PATH%

set "USERNAME=appveyor"
set "USERDOMAIN=APPVYR-WIN"

mingw32-make.exe -f Make_ming.mak clean
mingw32-make.exe -f Make_ming.mak ARCH=i686 -j8 CXXFLAGS="-DFEAT_PROPORTIONAL_FONTS" DIRECTX=yes COLOR_EMOJI=no  GUI=yes OLE=no IME=yes MBYTE=yes FEATURES=HUGE OPTIMIZE=MAXSPEED STATIC_STDCPLUS=yes NETBEANS=no ICONV=yes TERMINAL=yes DEBUG=no

mingw32-make.exe -f Make_ming.mak clean
mingw32-make.exe -f Make_ming.mak ARCH=i686 -j8                                      DIRECTX=no  COLOR_EMOJI=no  GUI=no  OLE=no IME=yes MBYTE=yes FEATURES=HUGE OPTIMIZE=MAXSPEED STATIC_STDCPLUS=yes NETBEANS=no ICONV=yes TERMINAL=yes DEBUG=no

exit /b
