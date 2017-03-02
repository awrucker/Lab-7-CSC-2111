@echo off
cls

::Set drive letter if no args given
if [%1] == [] goto noArgs
goto yesArgs

:noArgs
set DRIVE_LETTER=%CD:~0,1%
goto continue

:yesArgs
set DRIVE_LETTER=%1:
:continue
cd .\CSC2110\
start /wait build_CSC2110.bat %DRIVE_LETTER%
start /wait build_random.bat %DRIVE_LETTER%
cd ..\GUI\
start /wait build_GUI.bat %DRIVE_LETTER%
cd ..\




