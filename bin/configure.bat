@echo off
setlocal enableextensions enabledelayedexpansion
set "param1=%~1"

cd ..
mkdir build && cd build    

echo Configure in progress...
echo -------------------------------
rem Configure
cmake ..