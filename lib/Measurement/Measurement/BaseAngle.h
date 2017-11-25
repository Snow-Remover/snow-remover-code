#ifndef _MEASUREMENT_BASE_ANGLE_H_
#define _MEASUREMENT_BASE_ANGLE_H_


namespace Measurement
{
  
  class CoterminalAngle;
  class Angle;
  
  template <class AnyAngle>
  class BaseAngle
  {
    
    public:
    
    static AnyAngle from_degrees(const float degrees);
    static AnyAngle from_radians(const float radians);
    static AnyAngle from_revolutions(const float revolutions);
    static AnyAngle zero();
    
    BaseAngle();
    
    float degrees() const;
    float radians() const;
    float revolutions() const;
    Angle to_angle() const;
    CoterminalAngle to_coterminal_angle() const;
    AnyAngle operator+(const AnyAngle& other_angle) const;
    BaseAngle<AnyAngle>& operator+=(const AnyAngle& other_angle);
    AnyAngle operator-(const AnyAngle& other_angle) const;
    BaseAngle<AnyAngle>& operator-=(const AnyAngle& other_angle);
    template <typename Numeric>
    AnyAngle operator*(const Numeric number) const;
    template <typename Numeric>
    BaseAngle<AnyAngle>& operator*=(const Numeric number);
    template <typename Numeric>
    AnyAngle operator/(const Numeric number) const;
    template <typename Numeric>
    BaseAngle<AnyAngle>& operator/=(const Numeric number);
    template <typename Numeric>
    Numeric operator/(const AnyAngle& other_angle) const;
    AnyAngle operator%(AnyAngle& other_angle) const;
    BaseAngle<AnyAngle>& operator%=(AnyAngle& other_angle);
    BaseAngle<AnyAngle>& operator=(const AnyAngle& other_angle);
    
    protected:
    
    float _degrees;
    
    virtual void _set_degrees(const float degrees);
    void _set_radians(const float radians);
    void _set_revolutions(const float revolutions);
    
  };
  
}

#endif
