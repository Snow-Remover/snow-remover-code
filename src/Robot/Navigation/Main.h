#ifndef _ROBOT_NAVIGATION_MAIN_H_
#define _ROBOT_NAVIGATION_MAIN_H_


namespace Robot
{
  namespace Navigation
  {
    
    class Main
    {
      
      public:
      
      static void setup();
      static void start();
      static void tick();
      
      private:
      
      static PeriodicTimer _update_timer;
      
    };
    
  }
}

#endif
