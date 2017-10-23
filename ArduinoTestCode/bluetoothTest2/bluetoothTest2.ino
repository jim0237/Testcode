//   The circuit:
// * RX is digital pin 10 (connect to TX of other device)
// * TX is digital pin 11 (connect to RX of other device)
 
  #include <SoftwareSerial.h>
  SoftwareSerial mySerial(10, 11); // RX, TX
  
    char state = '2';
    void setup() {
      Serial.begin(9600);
      pinMode(LED_BUILTIN, OUTPUT);
      mySerial.begin(9600); // Default communication rate of the Bluetooth module
      mySerial.println("LED: SETUP COMPLETE");
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3000);
      digitalWrite(LED_BUILTIN, LOW); 
      delay(3000);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3000);
      digitalWrite(LED_BUILTIN, LOW);
    }
    void loop() {
      if(mySerial.available()){ // Checks whether data is comming from the serial port
        state = mySerial.read(); // Reads the data from the serial port
         if (state == '0') {
          digitalWrite(LED_BUILTIN, LOW);  // Turn LED OFF
          mySerial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
          Serial.print("OFF");
          state = 0;
         }
         else if (state == '1') {
          digitalWrite(LED_BUILTIN, HIGH);
          mySerial.println("LED: ON");
          Serial.print("ON");
          state = 0;
         } 
      }
    }
