const int buttonPin = 13;
int outPorts[] = {33, 27, 26, 25};
int angle = 0;
int buttonState = 1;

void setup() {
 Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  // set pins to output
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  
}

void loop() {
  int tempButtonState = digitalRead(buttonPin);
  if(tempButtonState == 0 && buttonState == 1){
    moveSteps(true, 20, 3);
    
  }
  buttonState = tempButtonState;
}

void moveSteps(bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir); // Rotate a step
    delay(constrain(ms,3,20));        // Control the speed
  }
}



void moveOneStep(bool dir) {
  // Define a variable, use four low bit to indicate the state of port
  static byte out = 0x01;
  // Decide the shift direction according to the rotation direction
  if (dir) {  // ring shift left
    out != 0x08 ? out = out << 1 : out = 0x01;
  }
  else {      // ring shift right
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  // Output singal to each port
  for (int i = 0; i < 4; i++) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}
