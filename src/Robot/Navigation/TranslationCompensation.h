#ifndef _ROBOT_NAVIGATION_TRANSLATION_COMPENSATION_H_
#define _ROBOT_NAVIGATION_TRANSLATION_COMPENSATION_H_


namespace Robot
{
  namespace Navigation
  {
    
    class TranslationCompensation
    {
      
      public:
      
      static void freeze();
      static boolean is_compete();
      static void set_target(Location location);
      static void setup();
      static void update();
      
      private:
      
      static Geometry::Point _start_point;
      static Geometry::Point _finish_point;
      static boolean _complete;
      
      static Geometry::Point _robot_point();
      
    };
    
  }  
}

#endif
