@echo off
setlocal enableextensions enabledelayedexpansion
set "param1=%~1"

cd ../build
echo Build in progress...
echo -------------------------------

rem Build
cmake --build .

exit /B