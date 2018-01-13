#ifndef _ROBOT_NAVIGATION_ROTATION_COMPENSATION_H_
#define _ROBOT_NAVIGATION_ROTATION_COMPENSATION_H_

// one of two tasks that will compare the desired and actual position
//   and adjust the motors to compensate for the error
// this one will try to keep the robot facing the correct direction

namespace Robot
{
  namespace Navigation
  {
    
    class RotationCompensation
    {
      
      public:
      
      static boolean is_complete();
      static void set_target(Measurement::CoterminalAngle heading);
      static void setup();
      static void tick();
      static boolean is_facing_target();
      
      private:
      
      static PeriodicTimer _update_timer;
      static Measurement::CoterminalAngle _target_heading;
      
      static Measurement::CoterminalAngle _current_heading();
      static void _update();
      
    };
    
  }  
}

#endif
