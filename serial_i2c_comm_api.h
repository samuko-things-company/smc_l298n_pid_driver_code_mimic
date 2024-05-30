#ifndef SERIAL_I2C_COMM_API_H
#define SERIAL_I2C_COMM_API_H
#include<Arduino.h>
#include "data_mimic.h"


// extra functions //
String getMotorAData(){
  float pos = getMotorPosDataVal();
  float vel = getMotorVelDataVal();

  String data = String(pos, 4);
  data += ",";
  data += String(vel, 4);
  return data;
}
/////////////////////






///////////////// SERIAL COMMUNICATION //////////////////////
String ser_msg = "";

String serMsg = "", serMsgBuffer, serDataBuffer[3];

void serialReceiveAndSendData() {
  int indexPos = 0, i = 0;

  if (Serial.available() > 0) {
    while (Serial.available())
    {
      serMsg = Serial.readString();
    }
    serMsg.trim();
    if (serMsg != "") {
      do {
        indexPos = serMsg.indexOf(',');
        if (indexPos != -1) {
          serMsgBuffer = serMsg.substring(0, indexPos);
          serMsg = serMsg.substring(indexPos + 1, serMsg.length());
          serDataBuffer[i] = serMsgBuffer;
          serMsgBuffer = "";
        }
        else {
          if (serMsg.length() > 0)
            serDataBuffer[i] = serMsg;
        }
        i += 1;
      } while (indexPos >= 0);
    }


    if (serDataBuffer[0] != ""){

      if (serDataBuffer[0] == "/dataA") {
        ser_msg = getMotorAData();
        Serial.println(ser_msg);
        ser_msg = "";
      }

      else if (serDataBuffer[0] == "/pwm") {
        ser_msg = setPWM(constrain(serDataBuffer[1].toInt(), -255, 255), constrain(serDataBuffer[2].toInt(), -255, 255));
        Serial.println(ser_msg);
        ser_msg = "";
      }

      else if (serDataBuffer[0] == "/pprA") {
        if (serDataBuffer[1]=="") ser_msg = sendPPRA();
        else ser_msg = setPPRA(serDataBuffer[1].toFloat());
        Serial.println(ser_msg);
        ser_msg = "";
      }

      else if (serDataBuffer[0] == "/rdirA") {
        if (serDataBuffer[1]=="") ser_msg = sendDIRA();
        else ser_msg = setDIRA(serDataBuffer[1].toFloat());
        Serial.println(ser_msg);
        ser_msg = "";
      }


    } else {
      ser_msg = "0";
      Serial.println(ser_msg);
      ser_msg = "";
    }
  }
  
  serMsg = "";
  serMsgBuffer = "";
  serDataBuffer[0] = "";
  serDataBuffer[1] = "";
  serDataBuffer[2] = "";
}
//////////////////////////////////////////////////////////////////////////




#endif
