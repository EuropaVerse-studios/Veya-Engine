@echo off
echo.
echo ========================================
echo VEYA ENGINE - Compilazione
echo ========================================
echo.

if not exist build mkdir build

echo [1/4] Compilazione PixelFont.cpp...
cl /c /EHsc Rendering/PixelFont.cpp /I"SDL3\include" /nologo
if %ERRORLEVEL% NEQ 0 goto error

echo [2/4] Compilazione Menu.cpp...
cl /c /EHsc UI/Menu.cpp /I"SDL3\include" /nologo
if %ERRORLEVEL% NEQ 0 goto error

echo [3/4] Compilazione Engine.cpp...
cl /c /EHsc Core/Engine.cpp /I"SDL3\include" /nologo
if %ERRORLEVEL% NEQ 0 goto error

echo [4/4] Compilazione main.cpp...
cl /c /EHsc main.cpp /I"SDL3\include" /nologo
if %ERRORLEVEL% NEQ 0 goto error

echo.
echo Organizzazione file...
move *.obj build\ >nul 2>&1

echo.
echo ========================================
echo Linking...
echo ========================================
echo.

cl build\PixelFont.obj build\Menu.obj build\Engine.obj build\main.obj ^
   /link /LIBPATH:"SDL3\lib\x64" SDL3.lib ^
   /SUBSYSTEM:CONSOLE /OUT:VeyaEngine.exe /nologo

if %ERRORLEVEL% NEQ 0 goto error

echo.
echo ========================================
echo Compilazione riuscita!
echo ========================================
echo.
echo File .obj in: build\
echo Eseguibile: VeyaEngine.exe
echo.

if not exist SDL3.dll (
    copy SDL3\lib\x64\SDL3.dll . >nul
)

echo Eseguo il programma...
echo.
VeyaEngine.exe
goto end

:error
echo.
echo ========================================
echo ERRORE!
echo ========================================
pause

:end