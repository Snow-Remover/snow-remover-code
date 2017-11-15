#include "Robot.h"


namespace Robot
{
  
  void Main::setup()
  {
    Hardware::Main::setup();
    Vision::setup();
    Navigation::setup();
  }
  
  
  void Main::start()
  {
    //Vision::start();
    //Navigation::start();
  }
  
  
  void Main::tick()
  {
    Hardware::Main::tick();
    Vision::tick();
    Navigation::tick();
  }
  
}
