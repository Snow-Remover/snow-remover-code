#ifndef _MEASUREMENT_ANGULAR_VELOCITY_H_
#define _MEASUREMENT_ANGULAR_VELOCITY_H_


namespace Measurement
{
  
  class AngularVelocity : public Comparable<AngularVelocity>
  {
    
    public:
    
    static AngularVelocity from_degrees_per_second(const float degrees_per_second);
    static AngularVelocity from_revolutions_per_second(const float revolutions_per_second);
    static AngularVelocity zero();
    
    AngularVelocity();
    
    AngularVelocity absolute() const;
    float degrees_per_second() const;
    float revolutions_per_second() const;
    
    protected:
    
    float _degrees_per_second;
    
    Comparable<AngularVelocity>::Comparison _compare_with(const AngularVelocity other_angular_velocity) const;
    void _set_degrees_per_second(float degrees_per_second);
    void _set_revolutions_per_second(float revolutions_per_second);
    
  };
  
}

#endif
