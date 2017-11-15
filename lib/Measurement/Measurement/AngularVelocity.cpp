#include "Measurement.h"


namespace Measurement
{
  
  //
  // public
  //
  
  
  AngularVelocity AngularVelocity::from_degrees_per_second(const float degrees_per_second)
  {
    AngularVelocity new_angular_velocity;
    new_angular_velocity._set_degrees_per_second(degrees_per_second);
    return new_angular_velocity;
  }
  
  
  AngularVelocity AngularVelocity::from_revolutions_per_second(const float revolutions_per_second)
  {
    AngularVelocity new_angular_velocity;
    new_angular_velocity._set_revolutions_per_second(revolutions_per_second);
    return new_angular_velocity;
  }
  
  
  AngularVelocity AngularVelocity::zero()
  {
    return AngularVelocity();
  }
  
  
  AngularVelocity::AngularVelocity()
  {
    _degrees_per_second = 0.0;
  }
  
  
  float AngularVelocity::degrees_per_second() const
  {
    return _degrees_per_second;
  }
  
  
  float AngularVelocity::revolutions_per_second() const
  {
    return _degrees_per_second / 360.0;
  }
  
  
  AngularVelocity AngularVelocity::operator=(const AngularVelocity other_angular_velocity)
  {
    return AngularVelocity::from_degrees_per_second(other_angular_velocity.degrees_per_second());
  }
  
  
  //
  // private
  //
  
  
  void AngularVelocity::_set_degrees_per_second(float degrees_per_second)
  {
    _degrees_per_second = degrees_per_second;
  }
  
  
  void AngularVelocity::_set_revolutions_per_second(float revolutions_per_second)
  {
    _set_degrees_per_second(revolutions_per_second * 360.0);
  }
  
  
}
