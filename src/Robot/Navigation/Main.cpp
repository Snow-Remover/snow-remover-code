#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    void Main::setup()
    {
      _tick_timer.reset();
      Positioning::setup();
      RotationCompensation::setup();
      TranslationCompensation::setup();
    }
    
    
    void Main::start()
    {
      _tick_timer.reset();
    }
    
    
    void Main::tick()
    {
      if (_tick_timer.is_complete())
      {
        if (Vision::closest_obj() <= 100)
          _freeze();
        else
          _move();
        _tick_timer.increment_interval();
      }
    }
    
    
    //
    // private
    //
    
    
    PeriodicTimer Main::_tick_timer = PeriodicTimer(100, PeriodicTimer::Units::Milliseconds);
    
    
    void Main::_freeze()
    {
      RotationCompensation::freeze();
      TranslationCompensation::freeze();
    }
    
    
    void Main::_move()
    {
      RotationCompensation::tick();
      //TranslationCompensation::tick();
    }
    
    
  }
}
