@echo off
echo Running tests...
setlocal enableextensions
REM cleanup from last run
del *.tmp output expected test.cdc null_file runtests.log 2>NUL
rd /S /Q binary 2>NUL
REM unmangle test.in to expected and test.cdc
REM warning there be tabs below - edit at your own risk
> test.cdc findstr /V /C:"	" ..\test\test.in
> expected.tmp findstr /C:"		" ..\test\test.in
for /F "tokens=1 delims=	" %%i in (expected.tmp) DO >> expected echo %%i
REM run compiler 
coldcc -o -W -t test.cdc 1>output 2>NUL
> output.tmp findstr /V /C:"Cleaning up name holders...done." output
copy output.tmp output 2>NUL 1>NUL
fc /l /n /a expected output 1>runtests.log
if ERRORLEVEL 1 goto :fail
echo All Tests pass.
del output expected runtests.log 2>NUL
goto :end
:fail
echo Tests failed.
:end
del *.tmp test.cdc null_file 2>NUL
rd /S /Q binary 2>NUL
endlocal
