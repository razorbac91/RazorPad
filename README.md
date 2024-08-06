
![image](https://github.com/razorbac91/RazorPad/assets/10536718/f698e480-2277-45ee-a4cd-efb995287c78)

# RazorPad
Very simple 8 keys, with 5 way navigation switch, bluetooth controller intended to work with Drive Mode Dashboard 2, Osmand or similar navigation apps

BE AWARE!!! I'm not a programmer nor a skilled maker, i just don't want to spend 150 or more euros for commercial controller (that is surely better engineered, water resistant, FW mainteined, etc, etc) so i gathered info around other free project and mixed them on something functional FOR ME.

The code is actually intended for ESP32 C3 Dev Module (I use a C3 super mini, Lolin mini and Lolin pico (with battery and voltage measurement) ESP32)

The project is actually built with the last ESP32 BleKeyboard 0.3.2-beta from https://github.com/T-vK/ESP32-BLE-Keyboard/releases/download/0.3.2-beta/ESP32-BLE-Keyboard.zip

Some of the inspiration come from:
- https://github.com/StylesRallyIndustries/RallyController
- https://jaxeadv.com/barbuttons
- https://github.com/MartinRV84
- and others around the net i'm surely fotgetting

Useful link:
- https://www.drivemodedashboard.com/controller-implementation-guide/
- https://www.mouser.it/datasheet/2/15/skqu-1155891.pdf  5 WAY NAVIGATION SWITCH DATASHEET

I also uploaded my STL file but be aware they are actually untested cause my Z Axis stepper driver gave up on these days so i can't actualy print it

# Arduino IDE settings for compiling Razorpad with C3 SuperMini Board:

Arduino Preferences: https://raw.githubusercontent.com/espressif/arduino-esp32/ghpages/package_esp32_index.json

Libraries to install:
![image](https://github.com/user-attachments/assets/6bd323f6-e0af-47b6-9b4a-c4f2a68e49fb)
![image](https://github.com/user-attachments/assets/966a3756-8721-4b3b-8cf7-d9e94572f3e3)

Arduino Library: Bounce2 https://github.com/thomasfredericks/Bounce2

Arduino Library: Keyboard https://github.com/T-vK/ESP32-BLE-Keyboard/releases/download/0.3.2-beta/ESP32-BLE-Keyboard.zip

Due to a bug in 0.3.2-beta, a small change needs to be made to

My Documents\Arduino\libraries\ESP32-BLE-Keyboard-0.3.2-beta\BleKeyboard.cpp. (Open in Notepad++ https://notepad-plusplus.org/downloads/)

On line 130 change :

From pSecurity->setAuthenticationMode(ESP_LE_AUTH_REQ_SC_MITM_BOND);
to pSecurity->setAuthenticationMode(ESP_LE_AUTH_BOND);

FROM
![image](https://github.com/user-attachments/assets/5ed9cc95-36b2-4fe1-8c95-40c2d3813d5b)

TO
![image](https://github.com/user-attachments/assets/026f87ed-45cf-458f-abdd-730ed958f070)

![image](https://github.com/user-attachments/assets/2e88c748-172d-4978-a878-178c6150066e)

Setup Board Manager with 2.0.17 – NOT with 3.0.3

Select Board: “Lolin C3 Mini” in Tools/Boards Manager

# SKQUCAA010 5 way Wire & Pin Layout for C3 Super Mini
![image](https://github.com/user-attachments/assets/02abe3b1-cf7d-4908-a3ee-88e812793d36)

- SKQUCAA010 Thru-hole 5-way Navigation Switch: https://www.adafruit.com/product/504
- Joystick Nubbin Cap: https://www.adafruit.com/product/4697
- ESP32-C3 Super Mini Board: https://www.aliexpress.com/item/1005006149784075.html?spm=a2g0o.order_list.order_list_main.410.75a31802JBM6nc
- 8mm Waterproof Momentary Buttons: https://www.aliexpress.com/item/1005001644121542.html?spm=a2g0o.order_list.order_list_main.400.75a31802JBM6nc
- 6mm Blue LED indicator Light (Optional): https://www.aliexpress.com/item/33037940893.html?spm=a-2g0o.order_list.order_list_main.5.1edd1802e15SGl

# HS1 5 Way Joystick Wire & Pin Layout for C3 Super Mini
![image](https://github.com/user-attachments/assets/1b0dd105-806e-4217-a93a-bab29cc6fcbd)

- 5 Way Castle Joystick: https://ruff ycontrols.com/product/hs1-series/
- ESP32-C3 Super Mini Board: https://www.aliexpress.com/item/1005006149784075.html?spm=a2g0o.order_list.order_list_main.410.75a31802JBM6nc
- 8mm Waterproof Momentary Buttons: https://www.aliexpress.com/item/1005001644121542.html?spm=a2g0o.order_list.order_list_main.400.75a31802JBM6nc
- 6mm Blue LED indicator Light (Optional): https://www.aliexpress.com/item/33037940893.html?spm=a-2g0o.order_list.order_list_main.5.1edd1802e15SGl
