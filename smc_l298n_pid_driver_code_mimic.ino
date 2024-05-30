#include <Wire.h>
#include "serial_i2c_comm_api.h"

///////// my sepcial delay function ///////////////
void delayMs(int ms) {
  for (int i = 0; i < ms; i += 1) {
    delayMicroseconds(1000);
  }
}
//////////////////////////////////////////////////


////////////////////// MAIN CODE ////////////////////////////////////////

unsigned long serialCommTime, serialCommSampleTime = 10; //ms -> (1000/sampleTime) hz

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2);

  serialCommTime = millis();
}


void loop() {
  ////////// using the serial communiaction API ////////////////////////
  if ((millis() - serialCommTime) >= serialCommSampleTime) {
    serialReceiveAndSendData();
    serialCommTime = millis();
  }
  /////////////////////////////////////////////////////////////////////

}
