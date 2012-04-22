@echo off
echo Building system type configuration information...
setlocal enableextensions
set SYSINC=%CD%\systype.h
set SYSCFG=%CD%\systype.cfg
set CPU=i686
set VENDOR=pc
set SYSTEM=bcc63win32
>  %SYSINC% echo #ifndef cdc_systype_h
>> %SYSINC% echo #define cdc_systype_h
>> %SYSINC% echo #define SYSTEM_TYPE "%CPU%-%VENDOR%-%SYSTEM%"
>> %SYSINC% echo #define sys_%SYSTEM% 
>> %SYSINC% echo #define vendor_%VENDOR% 
>> %SYSINC% echo #define cpu_%CPU% 
>> %SYSINC% echo #endif
>  %SYSCFG% echo SYS=%SYSTEM%
>> %SYSCFG% echo CPU=%CPU%
>> %SYSCFG% echo VENDOR=%VENDOR%
echo %CPU%-%VENDOR%-%SYSTEM%
endlocal
