@echo off
REM ========================================
REM Pulisce i file di compilazione
REM ========================================

echo.
echo Pulizia file di build...
echo.

if exist build rmdir /s /q build
if exist VeyaEngine.exe del VeyaEngine.exe
if exist *.obj del *.obj

echo.
echo Fatto! File di build eliminati.
echo.
pause
