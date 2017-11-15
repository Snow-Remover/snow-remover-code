
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
  AnyAngle BaseAngle<AnyAngle>::operator+(const AnyAngle other_angle)
  {
      return AnyAngle::from_degrees(degrees() + other_angle.degrees());
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator+=(const AnyAngle other_angle)
  {
    return AnyAngle::from_degrees(degrees() + other_angle.degrees());
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator-(const AnyAngle other_angle)
  {
      return AnyAngle::from_degrees(degrees() - other_angle.degrees());
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator-=(const AnyAngle other_angle)
  {
      return AnyAngle::from_degrees(degrees() - other_angle.degrees());
  }
  
  
  template <class AnyAngle>
  template <typename Numeric>
  AnyAngle BaseAngle<AnyAngle>::operator*(const Numeric number)
  {
      return AnyAngle::from_degrees(degrees() * number);
  }
  
  
  template <class AnyAngle>
  template <typename Numeric>
  AnyAngle BaseAngle<AnyAngle>::operator/(const Numeric number)
  {
    return AnyAngle::from_degrees(degrees() / number);
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator/(const AnyAngle other_angle)
  {
    return AnyAngle::from_degrees(degrees() / other_angle.degrees());
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator%(AnyAngle other_angle)
  {
    return AnyAngle::from_degrees(fmod (degrees(), other_angle.degrees()));
  }
  
  
  template <class AnyAngle>
  AnyAngle BaseAngle<AnyAngle>::operator=(const AnyAngle other_angle)
  {
    return AnyAngle::from_degrees(other_angle.degrees());
  }
  
  
  //
  // private
  //
  
  
}
  
