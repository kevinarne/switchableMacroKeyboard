# Switchable Macro Keyboard
Many programs, such as Inkscape, have some pretty intricate keyboard shortcuts that I find challenging to use regularly, so I've made a macro keyboard that can be switched between different macro keyboards.

At the moment, the code only supports sending static strings, like "Hooray" or "Wow, that's crazy," but eventually it will also support modifier keys like shift and control.

# Components
* Arduino Pro Micro
* 12 x Cherry MX buttons
* 12 x diodes
* 3D printed housing
* 3D printed knob
* LCD Panel
* 7 x 10k ohm resistors
* 1 x rotary encoder
* Micro USB cable
* Custom PCB (see gerber.zip)

# Programming
To program using the Arduino environment, make sure to set your board to Arduino Leonardo. There are several test sketches in the src/test folder that you can use to test individual components in isolation, but the main sketch is in the src/macroKeyMain folder along with the keyboards.h file that contains the different macro keyboards to be loaded.

If you simply want this to work as a macro keyboard, but with your own commands, you should only have to change the keyboards.h file and upload the code to your Arduino Pro Micro.

Note: the main sketch has no checks on any of the data in keyboards.h. Although the code may compile and upload, **failure to correctly format keyboards.h can result in index out of bounds errors, causing the keyboard to stop working until power cycled.**

You will need to have the following libraries installed:
* Wire.h
* LiquidCrystal_I2C.h
* Keyboard.h
