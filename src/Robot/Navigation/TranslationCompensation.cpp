#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    void TranslationCompensation::freeze()
    {
      MotorMixer::set_left_translation_input(0.0);
      MotorMixer::set_right_translation_input(0.0);
    }
    
    
    void TranslationCompensation::setup()
    {
      _last_location = _current_location();
      _target_location = _last_location;
    }
    
    
    void TranslationCompensation::set_target(Location location)
    {
      _target_location = location;
    }
    
    
    boolean TranslationCompensation::is_compete()
    {
    }
    
    
    void TranslationCompensation::tick()
    {
    }
    
    
    //
    // private
    //
    
    
    Location TranslationCompensation::_last_location;
    Location TranslationCompensation::_target_location;
    
    
    Location TranslationCompensation::_current_location()
    {
      return Positioning::get().location();
    }
    
  }
} 
