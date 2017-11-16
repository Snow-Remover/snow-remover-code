#include "StepperMotor.h"


//
// public
//


StepperMotor::StepperMotor(AdafruitMotorShield::StepperMotor* motor, const unsigned int revolution_step_count, const StepType step_type, const boolean invert_direction)
: _step_timer(0, PeriodicTimer::Units::Microseconds)
{
  _motor = motor;
  switch (step_type)
  {
    case StepType::Single:
      _native_step_type = SINGLE;
      _revolution_step_count = revolution_step_count;
      break;
    case StepType::Double:
      _native_step_type = DOUBLE;
      _revolution_step_count = revolution_step_count;
      break;
    case StepType::Interleave:
      _native_step_type = INTERLEAVE;
      _revolution_step_count = revolution_step_count * 2;
      break;
    case StepType::Microstep:
      _native_step_type = MICROSTEP;
      _revolution_step_count = revolution_step_count * MICROSTEPS;
      break;
  }
  _is_direction_inverted = invert_direction;
  
  _current_step = 0;
  _desired_step = 0;
  _desired_angle = Measurement::Angle::zero();
  _infinite_rotation = false;
}


Measurement::Angle StepperMotor::angle()
{
  return Measurement::Angle::from_revolutions((float)_current_step / _revolution_step_count);
}


const Measurement::Angle StepperMotor::desired_angle()
{
  if (_infinite_rotation)
    return angle();
  else
    return _desired_angle;
}


long StepperMotor::desired_step()
{
  if (_infinite_rotation)
    return _current_step;
  else
    return _desired_step;
}


boolean StepperMotor::is_rotating()
{
  return (_infinite_rotation || _current_step != _desired_step);
}


boolean StepperMotor::is_stopped()
{
  return !is_rotating();
}


void StepperMotor::reset()
{
  stop();
  _current_step = 0;
  _desired_step = 0;
  _desired_angle = Measurement::Angle::zero();
}


void StepperMotor::rotate(const Measurement::Angle angle, const Measurement::AngularVelocity angular_velocity)
{
  stop();
  if (angular_velocity <= Measurement::AngularVelocity::zero()) return;
  _desired_angle += angle;
  _desired_step = round(_desired_angle.revolutions() * _revolution_step_count);
  _set_angular_velocity(angular_velocity.absolute());
  if (angle >= Measurement::Angle::zero())
    _set_direction(Direction::Forward);
  else
    _set_direction(Direction::Reverse);
}


void StepperMotor::rotate(const Measurement::AngularVelocity angular_velocity)
{
  stop();
  if (angular_velocity > Measurement::AngularVelocity::zero())
    _set_direction(Direction::Forward);
  else if (angular_velocity < Measurement::AngularVelocity::zero())
    _set_direction(Direction::Reverse);
  else
    return;
  _set_angular_velocity(angular_velocity.absolute());
  _infinite_rotation = true;
}


void StepperMotor::rotate(const long steps, const Measurement::AngularVelocity angular_velocity)
{
  stop();
  if (angular_velocity <= Measurement::AngularVelocity::zero()) return;
  _desired_step += steps;
  _desired_angle = Measurement::Angle::from_revolutions((float)_desired_step / _revolution_step_count);
  _set_angular_velocity(angular_velocity.absolute());
  if (steps >= 0)
    _set_direction(Direction::Forward);
  else
    _set_direction(Direction::Reverse);
}


void StepperMotor::rotate_to(const Measurement::Angle angle, const Measurement::AngularVelocity angular_velocity)
{
  stop();
  if (angular_velocity <= Measurement::AngularVelocity::zero()) return;
  _desired_step = round(angle.revolutions() * _revolution_step_count);
  _desired_angle = angle;
  _set_angular_velocity(angular_velocity.absolute());
  if (_current_step < _desired_step)
    _set_direction(Direction::Forward);
  else
    _set_direction(Direction::Reverse);
}


void StepperMotor::rotate_to(const long step, const Measurement::AngularVelocity angular_velocity)
{
  stop();
  if (angular_velocity <= Measurement::AngularVelocity::zero()) return;
  _desired_step = step;
  _desired_angle = Measurement::Angle::from_revolutions((float)_desired_step / _revolution_step_count);
  _set_angular_velocity(angular_velocity.absolute());
  if (_current_step < _desired_step)
    _set_direction(Direction::Forward);
  else
    _set_direction(Direction::Reverse);
}


void StepperMotor::stop()
{
  _desired_step = _current_step;
  _desired_angle = Measurement::Angle::from_revolutions((float)_desired_step / _revolution_step_count);
  _infinite_rotation = false;
}


long StepperMotor::step()
{
  return _current_step;
}


void StepperMotor::tick()
{
  if (is_rotating() && _step_timer.is_complete())
  {
    _make_step();
    _step_timer.increment_interval();
  }
}


//
// private
//


void StepperMotor::_make_step()
{
  _motor->step(_native_direction, _native_step_type);
  if (_direction == Direction::Forward)
    _current_step++;
  else
    _current_step--;
}


void StepperMotor::_set_angular_velocity(const Measurement::AngularVelocity angular_velocity)
{
  //order these calculations appropriately to avoid roundoff error
  float step_time = 1 / angular_velocity.revolutions_per_second(); // s per rev
  step_time = step_time * 1000000; // us per rev
  step_time = step_time / _revolution_step_count; // us per step
  _step_timer = PeriodicTimer((unsigned long)step_time, PeriodicTimer::Units::Microseconds);
  _step_timer.reset();
}


void StepperMotor::_set_direction(const Direction direction)
{
  _direction = direction;
  if ((direction == Direction::Forward) ^ _is_direction_inverted)
    _native_direction = FORWARD;
  else
    _native_direction = BACKWARD;
}

