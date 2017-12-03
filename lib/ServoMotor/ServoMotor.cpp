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
  _servo.attach(_pin);
  _servo.write(round(_inital_angle.degrees()));
  
  _is_setup = true;
}


void ServoMotor::turn_to_angle(Measurement::Angle angle)
{
	if (!_is_setup)
	  return;
  
  _servo.write(round(angle.degrees()));
}


//
// private
//
