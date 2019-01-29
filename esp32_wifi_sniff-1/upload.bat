@echo off
:: the first argument is the COM port
set PORT=%1
set SKETCH_NAME=esp32_wifi_sniff-1
set SKETCH_DIR=C:\Work\Arduino_CLI
set SKETCH_FULLNAME=%SKETCH_DIR%\%SKETCH_NAME%
set ARDUINO_ESP32_PATH=C:\Users\%USERNAME%\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.1
set ESPTOOL=%ARDUINO_ESP32_PATH%\tools\esptool.py 
echo "Upload '%SKETCH_FULLNAME%'..."
:: esptool.py -p %PORT% flash_id
:: esptool.py --chip esp32 -b 921600 -p %PORT% erase_flash
%ESPTOOL% -p %PORT% --chip esp32 -b 921600 ^
 --before default_reset --after hard_reset ^
 write_flash -z --flash_mode dio --flash_freq 80m --flash_size=detect ^
 0xe000   %ARDUINO_ESP32_PATH%\tools\partitions\boot_app0.bin ^
 0x1000   %ARDUINO_ESP32_PATH%\tools\sdk\bin\bootloader_dio_80m.bin ^
 0x10000  %SKETCH_FULLNAME%\%SKETCH_NAME%.esp32.esp32.esp32.bin

echo "Done..."
pause
