
/**********************************************************************
  Filename    : Drive Stepper Motor
  Description : Use ULN2003 to drive the stepper motor.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
// Conncet the port of the stepper motor driver
const int buttonPin = 13;
int outPorts[] = {33, 27, 26, 25};
const int potentiometerPin = 15;

int potentiometerState = 0;
int angle = 0;
int buttonState = 1;
int choice = 0;

void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Button Test");
  // set pins to output
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  int tempButtonState = digitalRead(buttonPin);
  if(tempButtonState == 0 && buttonState == 1){
    runFortune();
    delay(5000); //pause while we tell fortune
  }
  buttonState = tempButtonState;
  int tempPotentiometerState = analogRead(potentiometerPin);
  if(tempPotentiometerState != potentiometerState){
    makeChoice(tempPotentiometerState);
  }
  potentiometerState = tempPotentiometerState;
}

void runFortune(){
  // rotate to start -- reset angle
  moveAngle(true, 360 - angle, 3);
  // Rotate 2 full turns
  moveAround(true, 2, 2);
  // Rotate to end point
  Serial.println(choice);
  if(choice == 0){
    angle = 0;
  }else if(choice == 1){
    angle = 60;
  }else if(choice == 2){
    angle = 120;
  }else if(choice == 3){
    angle = 180;
  }else if(choice == 4){
    angle = 240;
  }else if(choice == 5){
    angle = 300;
  }
  moveAngle(true, angle, 3);
  // Rotate a full turn towards another direction
}

//Suggestion: the motor turns precisely when the ms range is between 3 and 20
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

void moveAround(bool dir, int turns, byte ms){
  for(int i=0;i<turns;i++)
    moveSteps(dir,32*64,ms);
}
void moveAngle(bool dir, int angle, byte ms){
  moveSteps(dir,(angle*32*64/360),ms);
}

void makeChoice(int potentiometerReading){
  Serial.println(potentiometerReading);
  if(potentiometerReading < 585){
    choice = 3;  
  }else if(potentiometerReading < 1170){
    choice = 0;  
  }else if(potentiometerReading < 1755){
    choice = 2;  
  }else if(potentiometerReading < 2340){
    choice = 1;  
  }else if(potentiometerReading < 2925){
    choice = 4;  
  }else if(potentiometerReading < 3510){
    choice = 5;  
  }else{
    choice = random(6); 
  }
}
