@echo off
echo ====================================
echo Compiling Sri Lankan Parliamentary System...
echo ====================================
echo.

gcc Admin_loging.c main.c compenents.c ui.c registration.c admin.c election_admin.c party_agent.c PO.c RO.c -o hima

if %errorlevel% neq 0 (
    echo.
    echo ====================================
    echo Compilation FAILED!
    echo ====================================
    pause
    exit /b 1
)

echo.
echo ====================================
echo Compilation Successful!
echo Opening Program in New Terminal...
echo ====================================
echo.

start cmd /k "hima.exe"

timeout /t 2 /nobreak >nul
exit