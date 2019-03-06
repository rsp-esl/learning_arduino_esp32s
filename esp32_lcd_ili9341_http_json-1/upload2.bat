@echo off
:: the first argument is the COM port
set PORT=%1
set SKETCH_NAME=esp32_lcd_ili9341_http_json-1
set SKETCH_PATH_NAME=C:\Work\Arduino_CLI\%SKETCH_NAME%\%SKETCH_NAME%.ino
set SKETCH_BUILD_PATH=C:\Users\%USERNAME%\AppData\Local\Temp\build_%SKETCH_NAME%
set SKETCH_CACHE_PATH=C:\Users\%USERNAME%\AppData\Local\Temp\cache_%SKETCH_NAME%
::
set ARDUINO_PATH=C:\Work\arduino-1.8.7
set ARDUINO_USER_PATH=C:\Users\%USERNAME%\Documents\Arduino
set ARDUINO_LOCAL_PATH=C:\Users\%USERNAME%\AppData\Local\Arduino15
set ARDUINO_PACKAGES_PATH=%ARDUINO_LOCAL_PATH%\packages
::
set ARDUINO_PACKAGES_ESP32=%ARDUINO_LOCAL_PATH%\packages\esp32
set ESPTOOL=%ARDUINO_PACKAGES_ESP32%\tools\esptool_py\2.6.0\esptool.exe 
::
%ESPTOOL% --port %PORT% --chip esp32 --baud 921600 ^
  --before default_reset --after hard_reset ^
  write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect ^
  0xe000  %ARDUINO_PACKAGES_ESP32%\hardware\esp32\1.0.1/tools/partitions/boot_app0.bin ^
  0x1000  %ARDUINO_PACKAGES_ESP32%\hardware\esp32\1.0.1/tools/sdk/bin/bootloader_dio_80m.bin ^
  0x10000 %SKETCH_BUILD_PATH%\%SKETCH_NAME%.ino.bin ^
  0x8000  %SKETCH_BUILD_PATH%\%SKETCH_NAME%.ino.partitions.bin

echo "Done..."
pause
