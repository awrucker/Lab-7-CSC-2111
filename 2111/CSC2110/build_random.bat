@echo off
cls

set CXXFLAGS=-g -O0

::Set drive letter if no args given
if [%1] == [] goto noArgs
goto yesArgs

:noArgs
set DRIVE_LETTER=%CD:~0,2%
goto continue

:yesArgs
set DRIVE_LETTER=%1:
:continue
set PATH=%DRIVE_LETTER%\TDM-GCC-64\bin

g++ %CXXFLAGS% -c Random.cpp

IF EXIST "librandom.a" (
	move "librandom.a" "librandom.a.old"
)

ar -r librandom.a *.o

del *.o




exit