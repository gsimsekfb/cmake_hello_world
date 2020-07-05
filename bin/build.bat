
@echo off
setlocal enableextensions enabledelayedexpansion

rem ...
cd ..
mkdir build && cd build	
cmake ..
cmake --build .