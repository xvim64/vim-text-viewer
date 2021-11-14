@echo off
pushd "%~dp0"
patch gui.c        < gui.c.patch
patch option.h     < option.h.patch
patch optiondefs.h < optiondefs.h.patch
exit /b
