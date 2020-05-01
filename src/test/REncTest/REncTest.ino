//Testing for the rotary encoder dial and switch


#define EN_BUT A2 //Button on rotary encoder
#define EN_CLK 2 //Clock on rotary encoder
#define EN_DAT A3 //Data on rotary encoder
#define EN_POS 1 //Number of keyboards to rotate between

#define EN_DELAY 30 //In millis
#define SWITCH_DELAY 30 //In millis

unsigned long lastSwitch = 0;
unsigned long lastRotation = 0;
int enPosition = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
