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
      _update_timer.reset();
      Positioning::setup();
      RotationCompensation::setup();
      TranslationCompensation::setup();
      MotorMixer::setup();
    }
    
    
    void Main::start()
    {
      _update_timer.reset();
    }
    
    
    void Main::tick()
    {
      Positioning::tick();
      RotationCompensation::tick();
      TranslationCompensation::tick();
      MotorMixer::tick();
      //if (_update_timer.is_complete())
      //{
      //  _update_timer.increment_interval();
      //}
    }
    
    
    //
    // private
    //
    
    
    PeriodicTimer Main::_update_timer = PeriodicTimer(1000, PeriodicTimer::Units::Milliseconds);
    
    
    //void Main::_freeze()
    //{
      //RotationCompensation::freeze();
      //TranslationCompensation::freeze();
    //}
    
    
    //void Main::_move()
    //{
      //// preserve order of these, Translation sets target of Rotation
      ////Positioning::update();
      //TranslationCompensation::update();
      //RotationCompensation::update();
    //}
    
    
  }
}
