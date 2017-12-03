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
      
      static PeriodicTimer _navigation_timer;
      static PeriodicTimer _position_timer;
      static MessageBuffer _messenger;
      static SoftwareSerial _serial;
      
      static void _update_position();
      static void _update_navigation();
      
    };
    
  }
}

#endif
