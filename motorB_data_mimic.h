#ifndef MOTORB_DATA_MIMIC_H
#define MOTORB_DATA_MIMIC_H

unsigned long motorB_pos_update_time, motorB_pos_update_sample_time = 10; // ms -> (1000/sampleTime) hz
float max_ctrl_pwmB = 250, min_ctrl_pwmB = 50;
float max_update_freqB = 200, min_update_freqB = 5; // in Hz

void computeMotorBSampleTime(float ctrl_pwm)
{
  float update_freq = ((ctrl_pwm - min_ctrl_pwmB) * (max_update_freqB - min_update_freqB) / (max_ctrl_pwmB - min_ctrl_pwmB)) + min_ctrl_pwmB;
  float sample_time = 1000.00 / update_freq;
  motorB_pos_update_sample_time = (unsigned long)sample_time;
}

bool forwardB = true;
bool stopMotorB = true;

//-------------------------------------------------------------------//
float pprB = 1000;

String setPPRB(float ppr)
{
  pprB = ppr;
  return "1";
}

String sendPPRB()
{
  String data = String(pprB);
  return data;
}
//-------------------------------------------------------------------//

//-------------------------------------------------------------------//
float dirB = 1.00;

String setDIRB(float dir)
{
  if (dir > 0.0)
    dirB = 1.00;
  else
    dirB = -1.00;
  return "1";
}

String sendDIRB()
{
  String data = String(dirB);
  return data;
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
float motorB_pos_data = 0.0000;

void updateMotorBPosDataVal()
{
  if (forwardB)
  {
    motorB_pos_data += 0.0025;
  }
  else
  {
    motorB_pos_data -= 0.0025;
  }
}
//-------------------------------------------------------------------//

//-------------------------------------------------------------------//

float motorB_vel_data = 0.000;
int min_velB = 2500, max_velB = 6500;

void updateMotorBVelDataVal()
{
  int rand_vel_reading = random(min_velB, max_velB);
  motorB_vel_data = (float)rand_vel_reading / 1000.0;

  if (!stopMotorB)
  {
    if (forwardB)
      motorB_vel_data * 1.00;
    else
      motorB_vel_data * -1.00;
  }
  else
    motorB_vel_data = 0.000;
}
//-------------------------------------------------------------------//

// int motorPosDataArrayLength = sizeof(motorPosDataMimic) / sizeof(motorPosDataMimic[0]);
#endif