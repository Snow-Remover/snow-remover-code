#ifndef _ROBOT_NAVIGATION_TRANSLATION_COMPENSATION_H_
#define _ROBOT_NAVIGATION_TRANSLATION_COMPENSATION_H_


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
