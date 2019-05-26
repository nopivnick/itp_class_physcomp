// Noah Pivnick
// ITP Intro to Physical Computing: Week 4

// Attribution: the code for this week's build borrows heavily from the 
// [Love-O-Meter] project in the Arduino Projects Book that accompanies 
// the Arduino Starter kit and Project 7: Control a servo motor with a 
// FSR from the ITP Physical Computing website.

// include servo library
#include <Servo.h>

// instantiate a servo object to control servo
Servo myServo;

// assign analog pin for servo
int servoPin = 11;


void setup() {
  // initialize serial communications
  Serial.begin(9600);

  pinMode(2, OUTPUT);   // set the pin to be an output for the green LED
  pinMode(3, OUTPUT);   // set the pin to be an output for the green LED
  pinMode(4, OUTPUT);   // set the pin to be an output for the yellow LED
  pinMode(5, OUTPUT);   // set the pin to be an output for the yellow LED
  pinMode(6, OUTPUT);   // set the pin to be an output for the yellow LED
  pinMode(7, OUTPUT);   // set the pin to be an output for the red LED

  // attach pin to the servo object
  myServo.attach(servoPin);
}


void loop() {
  // declare variable analogValue and assign analog input from pin A0
  int analogValue = analogRead(A0);
  // int lightScale = 0;

  // print pressure sensor reading to serial monitor
  Serial.println(analogValue);

  // if pressure sensor value is 0, turn off all LEDs
  if (analogValue <= 0) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  // if pressure sensor value increases, turn one LED on
  else if (analogValue >= 10 && analogValue <= 150) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  // if pressure sensor value increases, turn a second LED on
  else if (analogValue >= 150 * 2 && analogValue <= 150 * 3) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  // if pressure sensor value increases, turn third LEDs on
  else if (analogValue >= 150 * 3 && analogValue <= 150 * 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  // if pressure sensor value increases, turn a fourth LED on
  else if (analogValue >= 150 * 4 && analogValue <= 150 * 5) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  // if pressure sensor value increases, turn a fifth LED on
  else if (analogValue >= 150 * 5 && analogValue <= 150 * 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }

  // if pressure sensor value increases, turn all LEDs on
  else if (analogValue >= 150 * 6 && analogValue <= 150 * 7) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }
  delay(1);

  //  // map pressure sensor range (0-985) to LED scale (0-5)
  //  lightScale = map(analogValue, 0, 985, 0, 5);

  // map pressure sensor range (0-985) to servo range of motion (0-180 degrees)
  int servoAngle = map(analogValue, 0, 985, 0, 179);

  // move servo to angle proportionate to presure sensor reading
  myServo.write(servoAngle);

  //  if (analogValue >= 150 * 6) {
  //    myServo.write(179);
  //  } else if (analogValue <= 150 * 7) {
  //    myServo.write(0);
  //  }

}
