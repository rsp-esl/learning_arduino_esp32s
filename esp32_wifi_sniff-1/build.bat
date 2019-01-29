@echo off
set SKETCH_NAME=esp32_wifi_sniff-1
set SKETCH_DIR=C:\Work\Arduino_CLI
set SKETCH_FULLNAME=%SKETCH_DIR%\%SKETCH_NAME%
set ARDUINO_CLI_DIR=C:\Work\Arduino_CLI
set BUILD_PATH=C:\Temp\%SKETCH_NAME%\build
echo "Build '%SKETCH_FULLNAME%'..."
%ARDUINO_CLI_DIR%\arduino-cli.exe compile ^
  --fqbn=esp32:esp32:esp32:PartitionScheme=min_spiffs %SKETCH_FULLNAME% ^
  --build-path %BUILD_PATH% ^
  --build-cache-path %BUILD_PATH%\..\..\arduino-esp32-cache

echo "Done..."
pause
