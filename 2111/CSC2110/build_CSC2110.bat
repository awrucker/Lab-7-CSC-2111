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

g++ %CXXFLAGS% -c String.cpp
g++ %CXXFLAGS% -c Tokens.cpp
g++ %CXXFLAGS% -c ReadFile.cpp
g++ %CXXFLAGS% -c WriteFile.cpp
g++ %CXXFLAGS% -c Keyboard.cpp
g++ %CXXFLAGS% -c Matrix.cpp
g++ %CXXFLAGS% -c Poly.cpp
g++ %CXXFLAGS% -c CD.cpp
g++ %CXXFLAGS% -c Song.cpp
g++ %CXXFLAGS% -c Integer.cpp
g++ %CXXFLAGS% -c Double.cpp
g++ %CXXFLAGS% -c HighPerformanceCounter.cpp
g++ %CXXFLAGS% -c Permutation.cpp

IF EXIST "libCSC2110.a" (
	move "libCSC2110.a" "libCSC2110.a.old"
)

ar -r libCSC2110.a *.o

del *.o




exit