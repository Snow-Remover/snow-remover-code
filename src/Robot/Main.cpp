#include "Robot.h"


namespace Robot
{
  
  void Main::setup()
  {
    Hardware::Main::setup();
    Navigation::Main::setup();
    Vision::setup();
  }
  
  
  void Main::start()
  {
    Navigation::Main::start();
    Vision::start();
  }
  
  
  void Main::tick()
  {
    Hardware::Main::tick();
    Navigation::Main::tick();
    Vision::tick();
  }
  
}
