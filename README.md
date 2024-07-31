# arduino-playground
My playground for Arduino projects. It not that complicated, but I wanted to get in touch with embedded and C++. Arduino is fun because it combines the two.

Currently, there are the following Arduino projects:
+ Temperature Control - A DHT sensor, 3 LED and the LCD, what a hot combination
+ Safe Control - Play it safe with a Keypad and an LCD
+ Surveillance - The ultrasonic sound of movement, from left to right

My default structure for projects is:
+ one sensor .ino file encapsulating a sensor with lib/hw config as well as providing higher level methods
+ one main .ino file orchestrating the sensors

It pretty much felt enough for the stuff I am doing.