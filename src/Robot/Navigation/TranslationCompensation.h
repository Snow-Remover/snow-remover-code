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
      static void setup();
      static void set_target(Location location);
      static boolean is_compete();
      static void tick();
      
      private:
      
      static Location _last_location;
      static Location _target_location;
      
      static Location _current_location();
      
    };
    
  }  
}

#endif
