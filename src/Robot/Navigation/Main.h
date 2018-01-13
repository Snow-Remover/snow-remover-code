#ifndef _ROBOT_NAVIGATION_MAIN_H_
#define _ROBOT_NAVIGATION_MAIN_H_

// the navigation code allows the robot to know is location and orientation in 2D space
// it will listen to the serial for any updates to the requested position of the robot
// it will then compare its current position to the requested position and adjust the track motors accordingly

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
