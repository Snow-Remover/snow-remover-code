#ifndef _ROBOT_MAIN_H_
#define _ROBOT_MAIN_H_

// parent for all the machine's functionality
// keeps the main file clean


namespace Robot
{
  
  class Main
  {
    
    public:
    
    static void setup();
    static void start();
    static void tick();
    
  };
  
}

#endif
