#ifndef _STEPPER_MOTOR_H_
#define _STEPPER_MOTOR_H_

/* This class abstracts the functionality of a stepper motor.
 * 
 * We use this to conveniently turn angles you specify while keeping track
 * of its positon.
 * 
 * This class is a task. As such the 'tick()' method must be called
 * often to ensure we dont miss sending any steps to the motor shield,
 * causing the motor to become out of sync with the postion we are tracking.
 */

#include <Arduino.h>
#include <Wire.h>

#include "Math.h"
#include "AdafruitMotorShield.h"
#include "PeriodicTimer.h"
#include "Measurement.h"


class StepperMotor
{
  
  public:
  
  enum class Direction { Forward, Reverse };
  enum class StepType { Single, Double, Interleave, Microstep };
  
  StepperMotor(AdafruitMotorShield::StepperMotor* motor, const unsigned int num_steps, const StepType step_type, const boolean invert_direction = false);
  
  Measurement::Angle angle();
  const Measurement::Angle desired_angle();
  long desired_step();
  boolean is_rotating();
  boolean is_stopped();
  void reset();
  void rotate(const Measurement::Angle angle, const Measurement::AngularVelocity angular_velocity);
  void rotate(const Measurement::AngularVelocity angular_velocity);
  void rotate(const long steps, const Measurement::AngularVelocity angular_velocity);
  void rotate_to(const Measurement::Angle angle, const Measurement::AngularVelocity angular_velocity);
  void rotate_to(const long step, const Measurement::AngularVelocity angular_velocity);
  void stop();
  long step();
  void tick();
  
  private:
  
  long _current_step;
  Measurement::Angle _desired_angle;
  long _desired_step;
  Direction _direction;
  boolean _infinite_rotation;
  boolean _is_direction_inverted;
  AdafruitMotorShield::StepperMotor* _motor;
  int _native_direction;
  int _native_step_type;
  unsigned int _revolution_step_count;
  PeriodicTimer _step_timer;
  
  void _make_step();
  void _set_direction(const Direction direction);
  void _set_angular_velocity(const Measurement::AngularVelocity angular_velocity);
  
};

#endif
