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
      _serial.begin(9600);
      Positioning::setup();
      RotationCompensation::setup();
      TranslationCompensation::setup();
      MotorMixer::setup();
    }
    
    
    void Main::start()
    {
      _messenger.write("|started");
      _navigation_timer.reset();
      _position_timer.reset();
    }
    
    
    void Main::tick()
    {
      Positioning::tick();
      RotationCompensation::tick();
      TranslationCompensation::tick();
      MotorMixer::tick();
      _messenger.tick();
      
      if (_navigation_timer.is_complete())
      {
        _update_navigation();
        _navigation_timer.increment_interval();
      }
      
      if (_position_timer.is_complete())
      {
        _update_position();
        _position_timer.increment_interval();
      }
    }
    
    
    //
    // private
    //
    
    
    PeriodicTimer Main::_navigation_timer = PeriodicTimer(1000, PeriodicTimer::Units::Milliseconds);
    PeriodicTimer Main::_position_timer = PeriodicTimer(1000, PeriodicTimer::Units::Milliseconds);
    MessageBuffer Main::_messenger = MessageBuffer(_serial, 40);
    SoftwareSerial Main::_serial(10, 11);
    
    void Main::_update_position()
    {
      _messenger.write("|position " + String(Positioning::get().x().meters()) + " " + String(Positioning::get().y().meters()) + " " + String(Positioning::get().heading().degrees()));
    }
    
    
    void Main::_update_navigation()
    {
      if (RotationCompensation::is_complete() && TranslationCompensation::is_complete())
        _messenger.write("|move_complete");
      
      if (_messenger.available())
      {
        String message = _messenger.read();
        
        if (message.indexOf("|translate") == 0)
        {
          float x = message.substring(11, 15).toFloat();
          float y = message.substring(16, 20).toFloat();
          Location location(Measurement::Distance::from_meters(x), Measurement::Distance::from_meters(y));
          TranslationCompensation::set_target(location);
        }
        
        if (message.indexOf("|rotate") == 0)
        {
          TranslationCompensation::end();
          float heading = message.substring(8, 13).toFloat();
          _messenger.write(String(heading));
          RotationCompensation::set_target(Measurement::CoterminalAngle::from_degrees(heading));
        }
        
        if (message.indexOf("|plow") == 0)
        {
          if (message.indexOf("up") != -1)
            Plow::up();
          if (message.indexOf("down") != -1)
            Plow::down();
        }
        
      }
    }
    
    
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
