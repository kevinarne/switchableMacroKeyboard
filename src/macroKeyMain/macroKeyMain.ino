void setup() {

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
