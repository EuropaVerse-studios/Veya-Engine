@echo off
REM ========================================
REM Script di compilazione per Windows
REM ========================================

echo.
echo ========================================
echo Compilazione del Game Engine...
echo ========================================
echo.

REM Compila con cl.exe (compilatore Visual Studio)
REM /EHsc = abilita exception handling C++
REM /I = Include directory (dove sono gli header SDL3)
REM /link = opzioni del linker
REM /LIBPATH = dove sono le librerie SDL3
REM SDL3.lib = collega la libreria SDL3

cl /EHsc main.cpp ^
   /I"SDL3\include" ^
   /link /LIBPATH:"SDL3\lib\x64" SDL3.lib ^
   /SUBSYSTEM:CONSOLE

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo Compilazione riuscita!
    echo ========================================
    echo.
    echo Eseguo il programma...
    echo.
    main.exe
) else (
    echo.
    echo ========================================
    echo ERRORE durante la compilazione!
    echo ========================================
    echo.
    echo Controlla:
    echo 1. Hai aperto "Developer Command Prompt for VS 2022"?
    echo 2. La cartella SDL3 e' presente?
    echo 3. Hai scaricato SDL3-VC.zip?
    echo.
    pause
)
