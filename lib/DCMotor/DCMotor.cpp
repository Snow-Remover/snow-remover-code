#include "DCMotor.h"


//
// public
//


DCMotor::DCMotor(AdafruitMotorShield::DCMotor* motor, boolean invert_direction)
{
  _motor = motor;
  _is_direction_inverted = invert_direction;
  
  _speed = 0.0;
}


void DCMotor::brake()
{
  _motor->set_speed(0);
}


boolean DCMotor::is_rotating()
{
  return _speed != 0.0;
}


boolean DCMotor::is_stopped()
{
  return !is_rotating();
}


void DCMotor::release()
{
  _speed = 0.0;
  _motor->run(RELEASE);
}


void DCMotor::run(float speed)
{
  if (speed >= 0)
    _motor->run(FORWARD);
  else
    _motor->run(BACKWARD);
  _speed = speed;
  _motor->set_speed(round(fabs(_speed) * 2.55));
}


boolean DCMotor::setup()
{
  return _motor != NULL;
}


float DCMotor::speed()
{
  return _speed;
}


//
// private
//


