void setup() {
  // assign digital pin 2 as output
  pinMode(2, OUTPUT);

}

void loop() {
  // set pin 2 to high (5 Volts)
  digitalWrite(2, HIGH);
  // pause for half a second
  delay(500);
  // switch pin 2 to low (0 Volts)
  digitalWrite(2, LOW);
  // pause for half a second
  delay(500);
}
