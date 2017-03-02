@echo off
cls

::Set drive letter if no args given
if [%1] == [] goto noArgs
goto yesArgs

:noArgs
set DRIVE_LETTER=%CD:~0,2%
goto continue

:yesArgs
set DRIVE_LETTER=%1:

:continue
set PATH=%DRIVE_LETTER%\TDM-GCC-64\bin;%DRIVE_LETTER%\TDM-GCC-64\wxWidgets-3.1.0\lib\gcc510TDM_x64_dll;c:\windows\system32;c:\"Program Files"\KDiff3
set PROJECT_PATH=.

mingw32-make DRIVE_LETTER="%DRIVE_LETTER%" CURRENT_DIR="%PROJECT_PATH%"

