// Testing for the rotary encoder dial and switch
// Valuable resource for understanding rotary encoders: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/

#define EN_BUT A2 // Button on rotary encoder
#define EN_CLK 7 // Clock on rotary encoder
#define EN_DAT A3 // Data on rotary encoder
#define EN_POS 3 // Number of keyboards to rotate between

#define EN_DELAY 50 // In millis
#define SWITCH_DELAY 30 // In millis

unsigned long lastSwitch = 0;
unsigned long lastRotation = 0;

volatile int enPosition = 0;

boolean prevClk = false;
boolean prevDat = false;

boolean currentClk = false;
boolean currentDat = false;

void setup() 
{
  // Set pins to output/input
  pinMode(EN_CLK, INPUT);
  pinMode(EN_DAT, INPUT);
  
  // Attach on change interrupt to clock
  attachInterrupt(INT4, readEncoder,CHANGE);

  Serial.begin(9600);
}

void loop() 
{
  Serial.println(enPosition);
}

// Function for the interrupt
void readEncoder()
{
  // Read values
  currentClk = digitalRead(EN_CLK);
  currentDat = digitalRead(EN_DAT);
  
  // Check last switched time
  if (!(millis() - lastRotation < EN_DELAY) && currentClk)
  {
    // Determine which direction it moved
    if (currentClk == currentDat) // Counter clockwise
    { 
      enPosition--;
    }
    else // Clockwise
    { 
      enPosition++;
    }

    lastRotation = millis();
  } 
  
  // Set to prev to current
  prevClk = currentClk;
  prevDat = prevDat;
}
