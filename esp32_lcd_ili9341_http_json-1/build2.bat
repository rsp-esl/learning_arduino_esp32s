@echo off
set SKETCH_NAME=esp32_lcd_ili9341_http_json-1
set SKETCH_PATH_NAME=C:\Work\Arduino_CLI\%SKETCH_NAME%\%SKETCH_NAME%.ino
set SKETCH_BUILD_PATH=C:\Users\%USERNAME%\AppData\Local\Temp\build_%SKETCH_NAME%
set SKETCH_CACHE_PATH=C:\Users\%USERNAME%\AppData\Local\Temp\cache_%SKETCH_NAME%
::
md %SKETCH_BUILD_PATH%
md %SKETCH_CACHE_PATH%
::
set ARDUINO_PATH=C:\Work\arduino-1.8.7
set ARDUINO_USER_PATH=C:\Users\%USERNAME%\Documents\Arduino
set ARDUINO_LOCAL_PATH=C:\Users\%USERNAME%\AppData\Local\Arduino15
set ARDUINO_PACKAGES_PATH=%ARDUINO_LOCAL_PATH%\packages
set ARDUINO_ESP32=%ARDUINO_LOCAL_PATH%\packages\esp32
set ARUINO_BUILDER=%ARDUINO_PATH%\arduino-builder 
set FQBN=esp32:esp32:lolin32:FlashFreq=80,PartitionScheme=min_spiffs,UploadSpeed=921600
::
%ARUINO_BUILDER% -compile -logger=machine ^
  -hardware %ARDUINO_PATH%\hardware ^
  -hardware %ARDUINO_PACKAGES_PATH% ^
  -tools %ARDUINO_PATH%\tools-builder ^
  -tools %ARDUINO_PACKAGES_PATH% ^
  -built-in-libraries %ARDUINO_PATH%\libraries ^
  -libraries %ARDUINO_USER_PATH%\libraries ^
  -build-path  %SKETCH_BUILD_PATH% ^
  -build-cache %SKETCH_CACHE_PATH% ^
  -ide-version=10807 ^
  -warnings=none ^
  -fqbn=%FQBN% ^
  -prefs=build.warn_data_percentage=75 ^
  -prefs=runtime.tools.xtensa-esp32-elf-gcc.path=%ARDUINO_ESP32%\tools\xtensa-esp32-elf-gcc\1.22.0-80-g6c4433a-5.2.0 ^
  -prefs=runtime.tools.xtensa-esp32-elf-gcc-1.22.0-80-g6c4433a-5.2.0.path=%ARDUINO_ESP32%\tools\xtensa-esp32-elf-gcc\1.22.0-80-g6c4433a-5.2.0 ^
  -prefs=runtime.tools.mkspiffs.path=%ARDUINO_ESP32%\tools\mkspiffs\0.2.3 ^
  -prefs=runtime.tools.mkspiffs-0.2.3.path=%ARDUINO_ESP32%\tools\mkspiffs\0.2.3 ^
  -prefs=runtime.tools.esptool_py.path=%ARDUINO_ESP32%\tools\esptool_py\2.6.0 ^
  -prefs=runtime.tools.esptool_py-2.6.0.path=%ARDUINO_ESP32%\tools\esptool_py\2.6.0 ^
  %SKETCH_PATH_NAME%
::
echo "===================================="
echo "%SKETCH_PATH_NAME%"
echo "%SKETCH_BUILD_PATH%"
echo "%SKETCH_CACHE_PATH%"
echo "===================================="
dir %SKETCH_BUILD_PATH%
echo "===================================="

echo "Done..."
pause
