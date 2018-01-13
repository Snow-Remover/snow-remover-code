#ifndef _ROBOT_NAVIGATION_TRANSLATION_COMPENSATION_H_
#define _ROBOT_NAVIGATION_TRANSLATION_COMPENSATION_H_

// one of two tasks that will compare the desired and actual position
//   and adjust the motors to compensate for the error
// this one will propel the robot forward until it reaches the desired position

namespace Robot
{
  namespace Navigation
  {
    
    class TranslationCompensation
    {
      
      public:
      
      static void end();
      static boolean is_complete();
      static void set_target(Location location);
      static void setup();
      static void tick();
      
      private:
      
      static PeriodicTimer _adjustment_timer;
      static PeriodicTimer _complete_timer;
      static Geometry::Point _start_point;
      static Geometry::Point _finish_point;
      static boolean _complete;
      
      static Geometry::Point _robot_point();
      static void _adjustment_update();
      static void _complete_update();
      
    };
    
  }  
}

#endif
