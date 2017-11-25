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
    
    
    void MotorMixer::update()
    {
      DCMotor* left_motor = &Hardware::Main::left_track_motor;
      DCMotor* right_motor = &Hardware::Main::right_track_motor;
      float left_output = _speed_scaling * ((_left_translation_input + _left_rotation_input) / 2);
      float right_output = _speed_scaling * ((_right_translation_input + _right_rotation_input) / 2);
      left_motor->run(left_output);
      right_motor->run(right_output);
      //Serial.print("left motor: ");
      //Serial.println(left_output);
      //Serial.print("right motor: ");
      //Serial.println(right_output);
    }
    
    
    //
    // private
    //
    
    
    const float MotorMixer::_speed_scaling = 1;
    float MotorMixer::_left_translation_input = 0.0;
    float MotorMixer::_right_translation_input = 0.0;
    float MotorMixer::_left_rotation_input = 0.0;
    float MotorMixer::_right_rotation_input = 0.0;
    
  }
}
