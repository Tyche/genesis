@echo off
echo Building configuration information...
call version.bat ..\etc\version
call systype.bat
echo Copying header files to include directory...
copy *.h ..\src\include 2>NUL 1>NUL
echo Configuration finished - type make now.
endlocal
