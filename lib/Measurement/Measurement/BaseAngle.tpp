
namespace Measurement
{
  
  //
  // public
  //
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::from_degrees(const float degrees)
  {
    AnyAngle new_angle;
    new_angle._set_degrees(degrees);
    return new_angle;
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::from_radians(const float radians)
  {
    AnyAngle new_angle;
    new_angle._set_radians(radians);
    return new_angle;
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::from_revolutions(const float revolutions)
  {
    AnyAngle new_angle;
    new_angle._set_revolutions(revolutions);
    return new_angle;
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::zero()
  {
    return AnyAngle();
  }
  
  
  template <class AnyAngle>
  BaseAngle<AnyAngle>::BaseAngle()
  {
    _degrees = 0.0;
  }
  
  
  template <class AnyAngle>
  float BaseAngle<AnyAngle>::degrees() const
  {
    return _degrees;
  }
  
  
  template <class AnyAngle>
  float BaseAngle<AnyAngle>::radians() const
  {
    return _degrees * (M_PI / 180.0);
  }
  
  
  template <class AnyAngle>
  float BaseAngle<AnyAngle>::revolutions() const
  {
    return _degrees / 360.0;
  }
  
  
  template <class AnyAngle>
  Angle BaseAngle<AnyAngle>::to_angle() const
  {
    return Angle::from_degrees(degrees());
  }
  
  template <class AnyAngle>
  CoterminalAngle BaseAngle<AnyAngle>::to_coterminal_angle() const
  {
    return CoterminalAngle::from_degrees(degrees());
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator+(const AnyAngle& other_angle) const
  {
    return AnyAngle::from_degrees(degrees() + other_angle.degrees());
  }
  
  
  template <class AnyAngle>
  BaseAngle<AnyAngle>& BaseAngle<AnyAngle>::operator+=(const AnyAngle& other_angle)
  {
    _set_degrees(degrees() + other_angle.degrees());
    return *this;
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator-(const AnyAngle& other_angle) const
  {
    return AnyAngle::from_degrees(degrees() - other_angle.degrees());
  }
  
  
  template <class AnyAngle>
  BaseAngle<AnyAngle>& BaseAngle<AnyAngle>::operator-=(const AnyAngle& other_angle)
  {
    _set_degrees(degrees() - other_angle.degrees());
    return *this;
  }
  
  
  template <class AnyAngle>
  template <typename Numeric>
  AnyAngle BaseAngle<AnyAngle>::operator*(const Numeric number) const
  {
    return AnyAngle::from_degrees(degrees() * number);
  }
  
  
  template <class AnyAngle>
  template <typename Numeric>
  BaseAngle<AnyAngle>& BaseAngle<AnyAngle>::operator*=(const Numeric number)
  {
    _set_degrees(degrees() * number);
    return *this;
  }
  
  
  template <class AnyAngle>
  template <typename Numeric>
  AnyAngle BaseAngle<AnyAngle>::operator/(const Numeric number) const
  {
    return AnyAngle::from_degrees(degrees() / number);
  }
  
  
  template <class AnyAngle>
  template <typename Numeric>
  BaseAngle<AnyAngle>& BaseAngle<AnyAngle>::operator/=(const Numeric number)
  {
    _set_degrees(degrees() / number);
    return *this;
  }
  
  
  template <class AnyAngle>
  template <typename Numeric>
  Numeric BaseAngle<AnyAngle>::operator/(const AnyAngle& other_angle) const
  {
    return degrees() / other_angle.degrees();
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator%(AnyAngle& other_angle) const
  {
    return AnyAngle::from_degrees(fmod (degrees(), other_angle.degrees()));
  }
  
  
  template <class AnyAngle>
  BaseAngle<AnyAngle>& BaseAngle<AnyAngle>::operator%=(AnyAngle& other_angle)
  {
    _set_degrees(fmod(degrees(), other_angle.degrees()));
    return *this;
  }
  
  
  template <class AnyAngle>
  BaseAngle<AnyAngle>& BaseAngle<AnyAngle>::operator=(const AnyAngle& other_angle)
  {
     _set_degrees(other_angle.degrees());
     return *this;
  }
  
  
  //
  // private
  //
  
  
  template <class AnyAngle>
  void BaseAngle<AnyAngle>::_set_radians(const float radians)
  {
    _set_degrees(radians * (180.0 / M_PI));
  }
  
  
  template <class AnyAngle>
  void BaseAngle<AnyAngle>::_set_revolutions(const float revolutions)
  {
    _set_degrees(revolutions * 360.0);
  }
  
  
}
  
