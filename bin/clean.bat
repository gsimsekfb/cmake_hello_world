@echo off
setlocal enableextensions enabledelayedexpansion

rem Delete build directory
echo Clean in progress...
echo -------------------------------

cd ..
rmdir /s /q "build"