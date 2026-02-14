@echo off
echo.
echo ========================================
echo Compilazione VEYA ENGINE
echo ========================================
echo.

echo [1/4] Compilazione PixelFont.cpp...
cl /c /EHsc Rendering/PixelFont.cpp /I"SDL3\include"

echo [2/4] Compilazione Menu.cpp...
cl /c /EHsc UI/Menu.cpp /I"SDL3\include"

echo [3/4] Compilazione Engine.cpp...
cl /c /EHsc Core/Engine.cpp /I"SDL3\include"

echo [4/4] Compilazione main.cpp...
cl /c /EHsc main.cpp /I"SDL3\include"

echo.
echo ========================================
echo Linking...
echo ========================================
echo.

cl PixelFont.obj Menu.obj Engine.obj main.obj ^
   /link /LIBPATH:"SDL3\lib\x64" SDL3.lib ^
   /SUBSYSTEM:CONSOLE /OUT:VeyaEngine.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo Compilazione riuscita!
    echo ========================================
    echo.
    if not exist SDL3.dll (
        copy SDL3\lib\x64\SDL3.dll .
    )
    echo Eseguo il programma...
    echo.
    VeyaEngine.exe
) else (
    echo.
    echo ========================================
    echo ERRORE!
    echo ========================================
    pause
)
