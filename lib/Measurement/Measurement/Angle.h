#ifndef _MEASUREMENT_ANGLE_H_
#define _MEASUREMENT_ANGLE_H_


namespace Measurement
{
  
  class Angle : public BaseAngle<Angle>, public Comparable<Angle>
  {
    friend BaseAngle;
    
    public:
    
    static Angle revolution();
    
    using BaseAngle::BaseAngle;
    
    Angle absolute();
    Angle operator-();
    using BaseAngle<Angle>::operator-;
    
    protected:
    
    Comparable<Angle>::Comparison _compare_with(const Angle other_angle) const;
    void _set_degrees(float degrees);
    void _set_revolutions(float revolutions);
    
  };
  
}

#endif
