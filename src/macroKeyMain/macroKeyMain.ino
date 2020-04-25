#define ENPIN A1
#define ROTBUT A2
#define LCDSER 10
#define EN_CLK 2
#define EN_DAT A3


int rows[] = {3,7,8,9};
int cols[] = {4,5.6};

void setup() {
  //Setup rows as outputs
  //Setup cols as inputs
  //Setup ENPIN as input
  //Setup ROTBUT as input
  //Setup ENCLK and ENDAT as inputs
  
  //Start software serial with LCDSER
  //Attach interrupt to ENCLK
}

void loop() {
  //if keyboard debouncing done
    //Check for keyboard input
  //if rotary encoder debouncing done
    //Check for rotary encoder input

  //Check for millis wrap around (nope, use this: https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover)
}

void keyboardScan(){
  //Iterate through rows
  for (int r = 0; r < 4; r++){
    //Set row to high
    for (int c = 0; c < 3; c++){ //Heh c++
      //Read each column
      //Update matrix of pressed buttons
      //If already pressed: don't update last pressed
      //Else: update last pressed value for that spot. last pressed = millis()
    }
    //Set row to low
  }
}
