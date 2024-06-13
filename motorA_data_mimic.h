#ifndef MOTORA_DATA_MIMIC_H
#define MOTORA_DATA_MIMIC_H

unsigned long motorA_pos_update_time, motorA_pos_update_sample_time = 10; // ms -> (1000/sampleTime) hz
float max_ctrl_pwmA = 250, min_ctrl_pwmA = 50;
float max_update_freqA = 200, min_update_freqA = 5; // in Hz

void computeMotorASampleTime(float ctrl_pwm)
{
  float update_freq = ((ctrl_pwm - min_ctrl_pwmA) * (max_update_freqA - min_update_freqA) / (max_ctrl_pwmA - min_ctrl_pwmA)) + min_ctrl_pwmA;
  float sample_time = 1000.00 / update_freq;
  motorA_pos_update_sample_time = (unsigned long)sample_time;
}

bool forwardA = true;
bool stopMotorA = true;

//-------------------------------------------------------------------//
float pprA = 1000;

String setPPRA(float ppr)
{
  pprA = ppr;
  return "1";
}

String sendPPRA()
{
  String data = String(pprA);
  return data;
}
//-------------------------------------------------------------------//

//-------------------------------------------------------------------//
float dirA = 1.00;

String setDIRA(float dir)
{
  if (dir > 0.0)
    dirA = 1.00;
  else
    dirA = -1.00;
  return "1";
}

String sendDIRA()
{
  String data = String(dirA);
  return data;
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
float motorA_pos_data = 0.0000;

void updateMotorAPosDataVal()
{
  if (forwardA)
  {
    motorA_pos_data += 0.0025;
  }
  else
  {
    motorA_pos_data -= 0.0025;
  }
}
//-------------------------------------------------------------------//

//-------------------------------------------------------------------//

float motorA_vel_data = 0.000;
int min_velA = 2500, max_velA = 6500;

void updateMotorAVelDataVal()
{
  int rand_vel_reading = random(min_velA, max_velA);
  motorA_vel_data = (float)rand_vel_reading / 1000.0;

  if (!stopMotorA)
  {
    if (forwardA)
      motorA_vel_data * 1.00;
    else
      motorA_vel_data * -1.00;
  }
  else
    motorA_vel_data = 0.000;
}
//-------------------------------------------------------------------//

// int motorPosDataArrayLength = sizeof(motorPosDataMimic) / sizeof(motorPosDataMimic[0]);
#endif