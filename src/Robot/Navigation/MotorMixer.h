#ifndef _ROBOT_NAVIGATION_MOTOR_MIXER_H_
#define _ROBOT_NAVIGATION_MOTOR_MIXER_H_


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
      
      private:
      
      static const float _speed_scaling; // to limit the voltage to the motor if the power source may be too high
      static float _left_translation_input;
      static float _right_translation_input;
      static float _left_rotation_input;
      static float _right_rotation_input;
      
    };
    
  }  
}

#endif
