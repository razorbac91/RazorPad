
![rendering razorpad](https://github.com/razorbac91/RazorPad/assets/10536718/4065ad4d-dacd-46bf-baef-4fa530ee5d5d)



# RazorPad
Very simple 8 keys, with 5 way navigation switch, bluetooth controller intended to work with Drive Mode Dashboard 2, Osmand or similar navigation apps

BE AWARE!!! I'm not a programmer nor a skilled maker, i just don't want to spend 150 or more euros for commercial controller (that is surely better engineered, water resistant, FW mainteined, etc, etc) so i gathered info around other free project and mixed them on something functional FOR ME.

The code is actually intended for a standard ESP32 Dev Module (I use a C3 super mini, Lolin mini and Lolin pico (with battery and voltage measurement) ESP32)

The project is actually built with the last ESP32 BleKeyboard 0.3.2-beta from https://github.com/T-vK/ESP32-BLE-Keyboard/releases

Some of the inspiration come from:
- https://github.com/StylesRallyIndustries/RallyController
- https://jaxeadv.com/barbuttons
- https://github.com/MartinRV84
- and others around the net i'm surely fotgetting

Useful link:
- https://www.drivemodedashboard.com/controller-implementation-guide/
- https://www.mouser.it/datasheet/2/15/skqu-1155891.pdf  5 WAY NAVIGATION SWITCH DATASHEET
- https://www.adafruit.com/product/4697 % way navigation switch rubber cap for increase water tightening 



I also uploaded my STL file but be aware they are actually untested cause my Z Axis stepper driver gave up on these days so i can't actualy print it

Schematics example for ESP32 C3 Super mini with SKQUCAA010 5 way navigation button and 3 push button:

![image](https://github.com/razorbac91/RazorPad/assets/10536718/fb6b67c5-3a9c-4f42-b4b6-5ea17b96bde5)

![image](https://github.com/razorbac91/RazorPad/assets/10536718/7b30a73c-8d8b-4389-9ef2-23c3b3c800ac)


