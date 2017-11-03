void setup() {
  Serial.begin(9600);

  while (!Serial) {
    ;//wait for serial port to become available
  }

}

void loop() {
  Serial.println(0x7e);
  Serial.println(34);
  Serial.println(0x7d);
  delay(1000);

}
