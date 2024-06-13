#ifndef DATA_MIMIC_H
#define DATA_MIMIC_H

#include "motorA_data_mimic.h"
#include "motorB_data_mimic.h"

//-------------------------------------------------------------------//
String setPWM(int pwmA, int pwmB)
{
  /////////////////////////////////////////////
  float checkDirA = (float)pwmA * dirA;
  if (checkDirA > 0.00)
    forwardA = true;
  else
    forwardA = false;

  int ctrl_pwmA = abs(pwmA);

  if (ctrl_pwmA < 50)
  {
    stopMotorA = true;
  }
  else if ((50 <= ctrl_pwmA) && (ctrl_pwmA <= 250))
  {
    stopMotorA = false;
    computeMotorASampleTime(ctrl_pwmA);
  }
  else
  {
    ctrl_pwmA = 250;
    stopMotorA = false;
    computeMotorASampleTime(ctrl_pwmA);
  }
  ////////////////////////////////////////////////B


  /////////////////////////////////////////////////
  float checkDirB = (float)pwmB * dirB;
  if (checkDirB > 0.00)
    forwardB = true;
  else
    forwardB = false;

  int ctrl_pwmB = abs(pwmB);

  if (ctrl_pwmB < 50)
  {
    stopMotorB = true;
  }
  else if ((50 <= ctrl_pwmB) && (ctrl_pwmB <= 250))
  {
    stopMotorB = false;
    computeMotorBSampleTime(ctrl_pwmB);
  }
  else
  {
    ctrl_pwmB = 250;
    stopMotorB = false;
    computeMotorBSampleTime(ctrl_pwmB);
  }
  //////////////////////////////////////////////

  return "1";
}
//-------------------------------------------------------------------//
#endif