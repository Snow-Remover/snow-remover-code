#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_


#include <Arduino.h>

#include "NativeExtensions.h"
#include "AdafruitMotorShield.h"


class DCMotor
{
  
  public:
  
  DCMotor(AdafruitMotorShield::DCMotor* motor, boolean invert_direction = false);
  
  void brake();
  boolean is_rotating();
  boolean is_stopped();
  void release();
  void run(float speed);
  boolean setup();
  float speed();
  
  private:
  
  float _speed;
  boolean _is_direction_inverted;
  AdafruitMotorShield::DCMotor* _motor;
  
};

#endif
