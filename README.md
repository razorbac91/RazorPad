![image](https://github.com/razorbac91/RazorPad/assets/10536718/c6ea84c1-d5b8-4720-ac4e-ae8e3e8c0bb8)



# RazorPad
Very simple 8 keys, with 5 way navigation switch, bluetooth controller intended to work with Drive Mode Dashboard 2, Osmand or similar navigation apps

BE AWARE!!! I'm not a programmer nor a skilled maker, i just don't want to spend 150 or more euros for commercial controller (that is surely better engineered, water resistant, FW mainteined, etc, etc) so i gathered info around other free project and mixed them on something functional FOR ME.

The code is actually intended for a standard ESP32 Dev Module (I use a D1 mini ESP32)
I'm trying to make it functional with ESP32 C3 super mini to reduce the overall dimensions, but at the moment i'm unable to getting it working due to known incompatibility with blekeyboard library.
IF ANYONE KNOW A SOLUTION, YOU ARE WELCOME

The project is actually built with the last ESP32 BleKeyboard 0.3.2-beta from https://github.com/T-vK/ESP32-BLE-Keyboard/releases

Some of the inspiration come from:
- https://github.com/StylesRallyIndustries/RallyController
- https://jaxeadv.com/barbuttons

Useful link:
- https://www.drivemodedashboard.com/controller-implementation-guide/
