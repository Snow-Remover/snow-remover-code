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
      DCMotor* motor = &Hardware::Main::left_track_motor;
      _left_translation_input = speed;
      float output = _speed_scaling * ((_left_translation_input + _left_rotation_input) / 2);
      motor->run(output);
    }
    
    
    void MotorMixer::set_right_translation_input(float speed)
    {
      DCMotor* motor = &Hardware::Main::right_track_motor;
      _right_translation_input = speed;
      float output = _speed_scaling * ((_right_translation_input + _right_rotation_input) / 2);
      motor->run(output);
    }
    
    
    void MotorMixer::set_left_rotation_input(float speed)
    {
      DCMotor* motor = &Hardware::Main::left_track_motor;
      _left_rotation_input = speed;
      float output = _speed_scaling * ((_left_translation_input + _left_rotation_input) / 2);
      motor->run(output);
    }
    
    
    void MotorMixer::set_right_rotation_input(float speed)
    {
      DCMotor* motor = &Hardware::Main::right_track_motor;
      _right_rotation_input = speed;
      float output = _speed_scaling * ((_right_translation_input + _right_rotation_input) / 2);
      motor->run(output);
    }
    
    
    //
    // private
    //
    
    
    const float MotorMixer::_speed_scaling = 0.5;
    float MotorMixer::_left_translation_input = 0.0;
    float MotorMixer::_right_translation_input = 0.0;
    float MotorMixer::_left_rotation_input = 0.0;
    float MotorMixer::_right_rotation_input = 0.0;
    
  }
}
