//Testing for the rotary encoder dial and switch

#define EN_BUT A2 //Button on rotary encoder
#define EN_CLK 2 //Clock on rotary encoder
#define EN_DAT A3 //Data on rotary encoder
#define EN_POS 1 //Number of keyboards to rotate between

#define EN_DELAY 200 //In millis
#define SWITCH_DELAY 30 //In millis

unsigned long lastSwitch = 0;
unsigned long lastRotation = 0;

volatile int enPosition = 0;

boolean prevClk = false;
boolean prevDat = false;

boolean currentClk = false;
boolean currentDat = false;


void setup() {
  //Set pins to output/input
  pinMode(EN_CLK, INPUT);
  pinMode(EN_DAT, INPUT);
  
  //Attach on change interrupt to clock
  attachInterrupt(INT1, readEncoder,CHANGE);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(enPosition);
}

void readEncoder(){
  //Read values
  currentClk = digitalRead(EN_CLK);
  currentDat = digitalRead(EN_DAT);
  
  //Check last switched time
  if (!(millis() - lastRotation < EN_DELAY)){
    //Determine which direction it moved
    enPosition++;
    //change enPosition
    lastRotation = millis();
  } 
  //Set to prev to current
  prevClk = currentClk;
  prevDat = prevDat;
}
