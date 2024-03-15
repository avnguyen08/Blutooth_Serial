/*
 Takes in Serial Input for Arduino Serial Monitor and Outputs it to defined rx and tx pins.
 Used to communicate with HC05 via AT commands
*/

#define MYTX 5
#define MYRX 4
void setup() {
  // initialize both serial ports:
  Serial.begin(19200);
  Serial1.begin(19200, SERIAL_8N1, MYRX, MYTX);
}


void loop() {
  if (Serial.available()) {        // If anything comes in Serial (USB),
    Serial1.write(Serial.read());  // read it and send it out Serial1 (pins 0 & 1)
  }

  if (Serial1.available()) {       // If anything comes in Serial1 (pins 0 & 1)
    Serial.write(Serial1.read());  // read it and send it out Serial (USB)
  }
} c