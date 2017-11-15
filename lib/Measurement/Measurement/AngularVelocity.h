#ifndef _MEASUREMENT_ANGULAR_VELOCITY_H_
#define _MEASUREMENT_ANGULAR_VELOCITY_H_


namespace Measurement
{
  
  class AngularVelocity
  {
    
    public:
    
    static AngularVelocity from_degrees_per_second(const float degrees_per_second);
    static AngularVelocity from_revolutions_per_second(const float revolutions_per_second);
    static AngularVelocity zero();
    
    AngularVelocity();
    
    float degrees_per_second() const;
    float revolutions_per_second() const;
    
    AngularVelocity operator=(const AngularVelocity other_angular_velocity);
    
    protected:
    
    float _degrees_per_second;
    
    void _set_degrees_per_second(float degrees_per_second);
    void _set_revolutions_per_second(float revolutions_per_second);
    
  };
  
}

#endif
