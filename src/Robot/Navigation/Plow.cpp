#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    void Plow::down()
    {
      ServoMotor* motor = &Hardware::Main::plow_servo_motor;
      motor->turn_to_angle(Measurement::Angle::from_degrees(0.0));
    }
    
    
    void Plow::up()
    {
      ServoMotor* motor = &Hardware::Main::plow_servo_motor;
      motor->turn_to_angle(Measurement::Angle::from_degrees(180.0));
    }
    
    
    //
    // private
    //
    
    
  }
} 
