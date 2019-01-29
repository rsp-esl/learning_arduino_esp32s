@echo off
set ARDUINO_CLI_DIR=C:\Work\Arduino_CLI
set SKETCH_DIR=C:\Work\Arduino_CLI
set SKETCH_NAME=esp32_lcd_ili9341_http_json_air4thai-1
set SKETCH_FULLNAME=%SKETCH_DIR%\%SKETCH_NAME%
echo "Build '%SKETCH_FULLNAME%'..."
%ARDUINO_CLI_DIR%\arduino-cli.exe compile --config-file %SKETCH_DIR%\.cli-config.yml --fqbn esp32:esp32:esp32 %SKETCH_FULLNAME%
echo "Done..."
pause
