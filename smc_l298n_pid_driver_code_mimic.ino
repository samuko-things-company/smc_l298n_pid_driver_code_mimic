#include <Wire.h>
#include "serial_i2c_comm_api.h"

///////// my sepcial delay function ///////////////
void delayMs(int ms)
{
  for (int i = 0; i < ms; i += 1)
  {
    delayMicroseconds(1000);
  }
}
//////////////////////////////////////////////////

////////////////////// MAIN CODE ////////////////////////////////////////

unsigned long serialCommTime, serialCommSampleTime = 10; // ms -> (1000/sampleTime) hz

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(2);

  serialCommTime = millis();
  motorA_pos_update_time = millis();
  motorB_pos_update_time = millis();
}

void loop()
{
  ////////// using the serial communiaction API ////////////////////////
  if ((millis() - serialCommTime) >= serialCommSampleTime)
  {
    serialReceiveAndSendData();
    serialCommTime = millis();
  }
  /////////////////////////////////////////////////////////////////////

  ////////// update motorA pos data ////////////////////////
  if (!stopMotorA)
  {
    if ((millis() - motorA_pos_update_time) >= motorA_pos_update_sample_time)
    {
      updateMotorAPosDataVal();
      updateMotorAVelDataVal();
      motorA_pos_update_time = millis();
    }
  }
  else
  {
    motorA_vel_data = 0.000;
    motorA_pos_update_time = millis();
  }
  /////////////////////////////////////////////////////////////////////


  ////////// update motorB pos data ////////////////////////
  if (!stopMotorB)
  {
    if ((millis() - motorB_pos_update_time) >= motorB_pos_update_sample_time)
    {
      updateMotorBPosDataVal();
      updateMotorBVelDataVal();
      motorB_pos_update_time = millis();
    }
  }
  else
  {
    motorB_vel_data = 0.000;
    motorB_pos_update_time = millis();
  }
  /////////////////////////////////////////////////////////////////////
}
