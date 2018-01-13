#ifndef _ROBOT_NAVIGATION_MOTOR_MIXER_H_
#define _ROBOT_NAVIGATION_MOTOR_MIXER_H_

// two of the Navigation tasks input the motor they need
//  this task will average these requests and output the final speed
//  to the Hardware component

namespace Robot
{
  namespace Navigation
  {
    
    class MotorMixer
    {
      
      public:
      
      static void set_left_translation_input(float speed);
      static void set_right_translation_input(float speed);
      static void set_left_rotation_input(float speed);
      static void set_right_rotation_input(float speed);
      static void setup();
      static void tick();
      
      private:
      
      static PeriodicTimer _update_timer;
      static const float _speed_scaling; // to limit the voltage to the motor if the power source may be too high
      static float _left_translation_input;
      static float _right_translation_input;
      static float _left_rotation_input;
      static float _right_rotation_input;
      
      static void _update();
      
    };
    
  }  
}

#endif
