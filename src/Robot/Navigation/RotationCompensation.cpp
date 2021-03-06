#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    boolean RotationCompensation::is_complete()
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
      _update_timer.reset();
    }
    
    
    void RotationCompensation::tick()
    {
      if (_update_timer.is_complete())
      {
        _update();
        _update_timer.increment_interval();
      }
    }
    
    
    boolean RotationCompensation::is_facing_target()
    {
      Measurement::CoterminalAngle tolerance = Measurement::CoterminalAngle::from_degrees(30.0);
      return _current_heading().is_between(_target_heading - tolerance, _target_heading + tolerance);
    }
    
    
    //
    // private
    //
    
    
    PeriodicTimer RotationCompensation::_update_timer = PeriodicTimer(200, PeriodicTimer::Units::Milliseconds);
    Measurement::CoterminalAngle RotationCompensation::_target_heading;
    
    
    Measurement::CoterminalAngle RotationCompensation::_current_heading()
    {
      return Positioning::get().heading();
    }
    
    
    void RotationCompensation::_update()
    {
      //Serial.print("target_heading: ");
      //Serial.print(_target_heading.degrees());
      //Serial.println();
      if (is_complete())
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
    
    
  }
} 
