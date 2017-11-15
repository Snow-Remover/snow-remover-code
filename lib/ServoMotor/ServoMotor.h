#ifndef _SERVO_MOTOR_H_
#define _SERVO_MOTOR_H_

/* This class abstracts the functionality of a servo motor.
 * 
 * Ideally we use VarSpeedServo.h to have the servo move to its inital
 * angle slowly, however I am not convinced that it actually run any slower. 
 */

#include <Arduino.h>

#include "VarSpeedServo.h" 
#include "Measurement.h"


class ServoMotor
{
  
  public:
  
  ServoMotor(int pin, Measurement::Angle inital_angle);
  
  void setup();
  void turn_to_angle(Measurement::Angle angle);
  
  private:
  
  Measurement::Angle _inital_angle;
  boolean _is_setup;
  int _pin;
  VarSpeedServo _var_speed_servo;
  
};

#endif
