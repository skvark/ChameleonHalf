ChameleonHalf
=============

Flora color sensor (TCS34725) and BlinkM i2c bus controller application for Sailfish OS (Jolla).


Notes
=====

VDD is set automatically upon application startup. When the application is closed, VDD will be set off.

Current version supports only BlinkM's fadeToRGBColor method. Automatic color changing via the Flora color sensor will be added later. I'll probably modify this later into a daemon which communicates with another app via dbus.

To test: Connect Jolla's 3,3 V to blinkM +, GND to -, SCL to SCL and SDA to SDA. Use with caution :)
