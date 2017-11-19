#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_


#include <Arduino.h>

#include "AdafruitMotorShield.h"


class DCMotor
{
  
  public:
  
  //enum class Direction { Forward, Reverse };
  
  DCMotor(AdafruitMotorShield::DCMotor* motor, boolean invert_direction = false);
  
  boolean is_rotating();
  boolean is_stopped();
  void release();
  void run(float speed);
  float speed();
  void brake();
  
  private:
  
  float _speed;
  boolean _is_direction_inverted;
  AdafruitMotorShield::DCMotor* _motor;
  
};

#endif
