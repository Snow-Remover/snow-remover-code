#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    void MotorMixer::set_left_translation_input(float speed)
    {
      _left_translation_input = speed;
    }
    
    
    void MotorMixer::set_right_translation_input(float speed)
    {
      _right_translation_input = speed;
    }
    
    
    void MotorMixer::set_left_rotation_input(float speed)
    {
      _left_rotation_input = speed;
    }
    
    
    void MotorMixer::set_right_rotation_input(float speed)
    {
      _right_rotation_input = speed;
    }
    
    
    static void MotorMixer::setup()
    {
      _update_timer.reset();
      _update();
    }
    
    
    void MotorMixer::tick()
    {
      if (_update_timer.is_complete())
      {
        _update();
        _update_timer.increment_interval();
      }
    }
    
    
    //
    // private
    //
    
    
    PeriodicTimer MotorMixer::_update_timer = PeriodicTimer(200, PeriodicTimer::Units::Milliseconds);
    const float MotorMixer::_speed_scaling = 1;
    float MotorMixer::_left_translation_input = 0.0;
    float MotorMixer::_right_translation_input = 0.0;
    float MotorMixer::_left_rotation_input = 0.0;
    float MotorMixer::_right_rotation_input = 0.0;
    
    
    void MotorMixer::_update()
    {
      DCMotor* left_motor = &Hardware::Main::left_track_motor;
      DCMotor* right_motor = &Hardware::Main::right_track_motor;
      float left_output;
      float right_output;
      
      if (Vision::closest_obj() <= 40)
      {
        left_output = 0;
        right_output = 0;
      }
      else
      {
        left_output = _speed_scaling * ((_left_translation_input + _left_rotation_input) / 2);
        right_output = _speed_scaling * ((_right_translation_input + _right_rotation_input) / 2);
      }
      
      left_motor->run(left_output);
      right_motor->run(right_output);
      //Serial.print("left motor: ");
      //Serial.println(left_output);
      //Serial.print("right motor: ");
      //Serial.println(right_output);
    }
    
  }
}
