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
    
    
    boolean RotationCompensation::is_compete()
    {
      Measurement::CoterminalAngle tolerance = Measurement::CoterminalAngle::from_degrees(10.0);
      return _current_heading().is_between(_target_heading - tolerance, _target_heading + tolerance);
    }
    
    
    void RotationCompensation::set_target(Measurement::CoterminalAngle heading)
    {
      _target_heading = heading;
    }
    
    
    void RotationCompensation::setup()
    {
      _target_heading = _current_heading();
    }
    
    
    void RotationCompensation::update()
    {
      //Serial.print("target_heading: ");
      //Serial.print(_target_heading.degrees());
      //Serial.println();
      if (is_compete())
      {
        MotorMixer::set_left_rotation_input(0.0);
        MotorMixer::set_right_rotation_input(0.0);
      }
      else
      {
        Measurement::Angle error = (_target_heading - _current_heading())
          .to_angle_between(Measurement::Angle::from_revolutions(-0.5), Measurement::Angle::from_revolutions(0.5));
        //Serial.print("heading error: ");
        //Serial.print(error.degrees());
        //Serial.println();
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
    
    
    Measurement::CoterminalAngle RotationCompensation::_target_heading;
    
    
    Measurement::CoterminalAngle RotationCompensation::_current_heading()
    {
      return Positioning::get().heading();
    }
    
  }
} 
