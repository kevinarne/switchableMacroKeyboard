#include <SoftwareSerial.h>
#include <Keyboard.h>
#include "keyboards.h"

#define ENA_PIN A1 //Enable pin that disables keyboard output
//#define LCD_SER 10 //Pin for the software serial communication to the LCD panel

#define EN_BUT A2  //Button on rotary encoder
#define EN_CLK 7 //Clock on rotary encoder
#define EN_DAT A3 //Data on rotary encoder

#define KEY_DELAY 30 //In millis
#define EN_DELAY 30 //In millis
#define SWITCH_DELAY 30 //In millis


//SoftwareSerial lcdSerial (A0, LCD_SER);  //RX, TX

//Need variables to store relevant states for rotary encoder

unsigned long lastSwitch = 0;
unsigned long lastRotation = 0;
volatile int enPosition = 0;
boolean prevClk = false;
boolean prevDat = false;

boolean currentClk = false;
boolean currentDat = false;


//rows and cols are the pins associated with the rows and columns of switches
int rows[] = {10,6,8,9};
int cols[] = {4,A0,5};

//Keeps track of whether a button has been pressed
boolean pressed[4][3] = {{false,false,false},
                         {false,false,false},
                         {false,false,false},
                         {false,false,false}};

//Keeps track of when a button was last pressed for debouncing
unsigned long lastPressed[4][3] = {{0,0,0},
                                   {0,0,0},
                                   {0,0,0},
                                   {0,0,0}};

//Keeps track of buttons to be sent
boolean toBeSent[4][3] = {{false,false,false},
                         {false,false,false},
                         {false,false,false},
                         {false,false,false}};

String keys[4][3] = {{"7","8","9"},
                     {"4","5","6"},
                     {"1","2","3"},
                     {"-","0","."}};

void setup() {
  //Setup rows as outputs
  for (int i = 0; i < 4; i++){
    pinMode(rows[i], OUTPUT);  
  }
  //Setup cols as inputs
  for (int i = 0; i < 3; i ++){
    pinMode(cols[i], INPUT);  
  }
  //Setup ENA_PIN as input
  pinMode(ENA_PIN, INPUT);
  
  //Setup EN_BUT as input
  pinMode(EN_BUT, INPUT);
  //Setup EN_CLK and EN_DAT as inputs
  pinMode(EN_CLK, INPUT);
  pinMode(EN_DAT, INPUT);

  
  //Start software serial with LCDSER
  //lcdSerial.begin(9600);

  Serial.begin(9600);
  
  //Attach interrupt to ENCLK
  attachInterrupt(INT4, readEncoder,CHANGE);
  
}

void loop() {
  keyboardScan();
  //Check enable pin
  int enabled = digitalRead(ENA_PIN);
  if (enabled){
    //Send buttons to be sent to keyboard
    sendKeys();  
  } else {
    Serial.println("Disabled");
    //Send buttons to serial  
  }
  //Set buttons to be sent to false
  
  //if rotary encoder debouncing done
    //Check for rotary encoder input

  //Check for millis wrap around (nope, use this: https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover)
}

void keyboardScan(){
  //Iterate through rows
  for (int r = 0; r < 4; r++){
    //Set row to high
    digitalWrite(rows[r], HIGH);
    for (int c = 0; c < 3; c++){ //Heh c++
      //Read each column
      int value = digitalRead(cols[c]);
      //Update matrix of pressed buttons
      if (value){ //Button is pressed
        //Check the previous value
        if (pressed[r][c]){ //If button previously pressed
          //Don't update last pressed
        } else { //Button was not previously pressed
          //Set pressed to true
          pressed[r][c] = true;
          //set last pressed to millis()
          lastPressed[r][c] = millis();
          //Set flag for the value to be sent
          toBeSent[r][c] = true;
        }
      }else{ //The button is not pressed
        if (pressed[r][c]){ //Button was previously pressed
            //timeExpired is true if enough time has passed since the last pressing
            //Or if the clock has reset
            boolean timeExpired = !(millis()-lastPressed[r][c] < KEY_DELAY);
            
            if (timeExpired){ //Enough time has elapsed since it was pressed
              //Set the pressed value back to false
              pressed[r][c] = false;
            }
         }
      }            
    }
    //Set row to low
    digitalWrite(rows[r], LOW);
  }
}


void sendKeys(){
  //Iterate through rows and cols
  for (int r = 0; r < 4; r++){
    for (int c = 0; c < 3; c++){
      if (toBeSent[r][c]){
        Serial.println(KEYBOARDS[enPosition][r][c]);
        toBeSent[r][c] = false;
      }  
    }  
  }  
}

void printMatrixSerial(){
  Serial.println("Pressed matrix:");
  for (int r = 0; r < 4; r++){
    for (int c = 0; c < 3; c++){
      Serial.print(pressed[r][c]);
      Serial.print("  ");
    } 
    Serial.println(""); 
  }
}

//Function for the interrupt
void readEncoder(){
  //Read values
  currentClk = digitalRead(EN_CLK);
  currentDat = digitalRead(EN_DAT);
  
  //Check last switched time
  if (!(millis() - lastRotation < EN_DELAY) && currentClk){
    //Determine which direction it moved
    if (currentClk == currentDat) //Counter clockwise
    { 
      enPosition--;
      if (enPosition < 0) //Check for negative position
      {
        enPosition = NUM_KB-1;
      }
    }
    else //Clockwise
    { 
      enPosition++;
      if (enPosition >= NUM_KB) //Check for overflow
      {
        enPosition = 0;
      }
    }
    Serial.println(enPosition);
    lastRotation = millis();
  } 
  
  //Set to prev to current
  prevClk = currentClk;
  prevDat = prevDat;
}
