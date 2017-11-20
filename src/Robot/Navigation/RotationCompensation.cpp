#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    void RotationCompensation::freeze()
    {
      MotorMixer::set_left_rotation_input(0.0);
      MotorMixer::set_right_rotation_input(0.0);
    }
    
    
    void RotationCompensation::setup()
    {
      _target_angle = _current_angle();
    }
    
    
    void RotationCompensation::set_target(Measurement::CoterminalAngle angle)
    {
      _target_angle = angle;
    }
    
    
    boolean RotationCompensation::is_compete()
    {
      Measurement::CoterminalAngle tolerance = Measurement::CoterminalAngle::from_degrees(5.0);
      return _current_angle().is_between(_target_angle - tolerance, _target_angle + tolerance);
    }
    
    
    void RotationCompensation::tick()
    {
      if (is_compete())
      {
        MotorMixer::set_left_rotation_input(0.0);
        MotorMixer::set_right_rotation_input(0.0);
      }
      else
      {
        Measurement::Angle error = (_target_angle - _current_angle())
          .to_angle_between(Measurement::Angle::from_revolutions(-0.5), Measurement::Angle::from_revolutions(0.5));
        Serial.println(error.degrees());
        float motor_input = error.degrees() * 10;
        if (motor_input > 100.0)
          motor_input = 100.0;
        else if (motor_input < -100.0)
          motor_input = -100.0;
        MotorMixer::set_left_rotation_input(motor_input);
        MotorMixer::set_right_rotation_input(-motor_input);
      }
    }
    
    
    //
    // private
    //
    
    
    Measurement::CoterminalAngle RotationCompensation::_target_angle;
    
    
    Measurement::CoterminalAngle RotationCompensation::_current_angle()
    {
      return Positioning::get().angle();
    }
    
  }
} 
