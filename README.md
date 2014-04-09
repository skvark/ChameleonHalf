ChameleonHalf
=============

Flora color sensor (TCS34725) and BlinkM i2c bus controller application for Sailfish OS (Jolla).


Notes
=====

VDD is set automatically upon application startup. When the application is closed, VDD will be set off.

Chameleon mode may be a little unstable but works most of the time just fine. Color sensor values may need some postprocessing so that the sensor values correspond better to the RGB LED values. 

I'll probably modify this later into a daemon which communicates with another app via dbus.

To test: Connect Jolla's 3,3 V to blinkM +, GND to -, SCL to SCL and SDA to SDA. Use with caution :)

Links
=====

* [Fading & app demo video](https://vimeo.com/91090091)
* [Color sensor polling and fading combined](https://vimeo.com/91553447)
* [talk.maemo.org thread](http://talk.maemo.org/showthread.php?t=92754)
