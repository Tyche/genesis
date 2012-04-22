@echo off
echo Building version configuration information...
setlocal enableextensions
set VERFILE=%1
set VERINC=%CD%\version.h
set VERCFG=%CD%\version.cfg
for /F "tokens=1-3 delims=." %%i in (%VERFILE%) do set VERSION=%%i %%j %%k 
for /F "tokens=1" %%i in ("%VERSION%") do set VMAJOR=%%i
for /F "tokens=2" %%i in ("%VERSION%") do set VMINOR=%%i
for /F "tokens=3" %%i in ("%VERSION%") do set VPATCH=%%i
for /F "tokens=2 delims=-" %%i in ("%VPATCH%") do set VRELEASE=%%i
for /F "tokens=1 delims=-" %%i in ("%VPATCH%") do set VPATCH=%%i
if "%VRELEASE%"=="" set VRELEASE=%VPATCH%
set VERSION="%VMAJOR%.%VMINOR%.%VPATCH%-%VRELEASE%"
>  %VERINC% echo #ifndef cdc_version_h
>> %VERINC% echo #define cdc_version_h
>> %VERINC% echo #define VERSION_MAJOR %VMAJOR%
>> %VERINC% echo #define VERSION_MINOR %VMINOR%
>> %VERINC% echo #define VERSION_PATCH %VPATCH%
>> %VERINC% echo #define VERSION_RELEASE "%VRELEASE%"
>> %VERINC% echo #endif
>  %VERCFG% echo VERSION=%VERSION%
>> %VERCFG% echo VMAJOR=%VMAJOR%
>> %VERCFG% echo VMINOR=%VMINOR%
>> %VERCFG% echo VPATCH=%VPATCH%
echo %VERSION%
endlocal
