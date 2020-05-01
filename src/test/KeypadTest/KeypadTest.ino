#define KEY_DELAY 30 //In millis

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
    pinMode(cols[i], OUTPUT);  
  }

  Serial.begin(9600);

}

void loop() {
  keyboardScan();
  //printMatrixSerial();
  sendKeys();
  delay(KEY_DELAY);
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
        Serial.println(keys[r][c]);
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
