void setup() {
  Serial.begin(9600);

  while (!Serial) {
    ;//wait for serial port to become available
  }

}

void loop() {
  Serial.println("Hello World");
  delay(1000);

}
