// include servo library
#include <Servo.h>

// instantiate a servo object to control servo
Servo myServo;

// assign analog pin for servo
int servoPin = 3;


void setup() {
  // initialize serial communications
  Serial.begin(9600);
  // attach pin 3 to the servo object
  myServo.attach(servoPin);
}


void loop() {
  // declare variable analogValue and assign analog input from pin A0
  int analogValue = analogRead(A0);

  // print pressure sensor reading to serial monitor
  Serial.println(analogValue);

  // map pressure sensor range (0-985) to servo range of motion (0-180 degrees)
  int servoAngle = map(analogValue, 0, 985, 0, 179);

  // move servo to angle proportionate to presure sensor reading
  myServo.write(servoAngle);
}
