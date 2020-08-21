@echo off
setlocal enableextensions enabledelayedexpansion
set "param1=%~1"

rem 0...
echo Hint: 
echo   build   : Normal build
echo   build sa: Static analysis build
echo -------------------------------
cd ..

rem 1. Del build directory
rmdir /s /q "build"

rem 2. Static analysis
if "!param1!" == "sa" (
  echo Static analysis in progress...
  echo -------------------------------
  mkdir build && cd build	
  cmake ..
  rem // Working
  cmake --build . -- "/p:RunCodeAnalysis=true" "/p:CodeAnalysisRuleSet=NativeRecommendedRules.ruleset"
  rem cmake --build . -- "/p:RunCodeAnalysis=true" "/p:CodeAnalysisRuleSet=AllRules.ruleset"
  exit /B
)

rem 3. Normal Build
echo Build in progress...
echo -------------------------------
mkdir build && cd build	
cmake ..
cmake --build .
exit /B