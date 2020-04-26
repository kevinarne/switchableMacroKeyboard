#define ENA_PIN A1 //Enable pin that disables keyboard output
#define LCD_SER 10 //Pin for the software serial communication to the LCD panel

#define EN_BUT A2  //Button on rotary encoder
#define EN_CLK 2 //Clock on rotary encoder
#define EN_DAT A3 //Data on rotary encoder

#define KEY_DELAY 30 //In millis
#define EN_DELAY 30 //In millis
#define SWITCH_DELAY 30 //In millis

//Need variables to store relevant states for rotary encoder

unsigned long lastSwitch = 0;
unsigned long lastRotation = 0;


//rows and cols are the pins associated with the rows and columns of switches
int rows[] = {3,7,8,9};
int cols[] = {4,5,6};

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

void setup() {
  //Setup rows as outputs
  for (int i = 0; i < 4; i++){
    pinMode(rows[i], OUTPUT);  
  }
  //Setup cols as inputs
  for (int i = 0; i < 3; i ++){
    pinMode(cols[i], OUTPUT);  
  }
  //Setup ENA_PIN as input
  pinMode(ENA_PIN, INPUT);
  
  //Setup EN_BUT as input
  pinMode(EN_BUT, INPUT);
  //Setup EN_CLK and EN_DAT as inputs
  pinMode(EN_CLK, INPUT);
  pinMode(EN_DAT, INPUT);

  
  //Start software serial with LCDSER
  //Attach interrupt to ENCLK
}

void loop() {
  keyboardScan();
  //Send buttons to be sent
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
      if (value){
        //Check the previous value
        //If already pressed: don't update last pressed
        //else, do update last pressed 
          //Update to be sent
      }else{
        //Check the previous value
        //If already pressed
          //Check time elapsed
          //Set to false if time elapsed is long enough
      }
            
      //Else: update last pressed value for that spot. last pressed = millis()
    }
    //Set row to low
    digitalWrite(rows[r], LOW);
  }
}
