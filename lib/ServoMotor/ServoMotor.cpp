#include "ServoMotor.h"


//
// public
//


ServoMotor::ServoMotor(int pin, Measurement::Angle inital_angle)
{
  _pin = pin;
  _inital_angle = inital_angle;
  _is_setup = false;
}


void ServoMotor::setup()
{
  _var_speed_servo.attach(_pin);
  _var_speed_servo.slowmove(_inital_angle.degrees(), 1);
  
  _is_setup = true;
}


void ServoMotor::turn_to_angle(Measurement::Angle angle)
{
	if (!_is_setup)
	  return;
  
  _var_speed_servo.write(angle.degrees());
}


//
// private
//
