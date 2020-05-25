#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); // Initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Hello, world!");

}

void loop()
{
  // Sit on your hands
}
