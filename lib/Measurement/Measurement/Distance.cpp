#include "Measurement.h"


namespace Measurement
{
  
  //
  // public
  //
  
  
  Distance Distance::from_meters(const float meters)
  {
    Distance new_distance;
    new_distance._set_meters(meters);
    return new_distance;
  }
  
  
  Distance Distance::from_centimeters(const float centimeters)
  {
    Distance new_distance;
    new_distance._set_centimeters(centimeters);
    return new_distance;
  }
  
  
  Distance Distance::from_millimeters(const float millimeters)
  {
    Distance new_distance;
    new_distance._set_millimeters(millimeters);
    return new_distance;
  }
  
  
  Distance Distance::zero()
  {
    return Distance();
  }
  
  
  Distance::Distance()
  {
    _meters = 0.0;
  }
  
  
  float Distance::meters() const
  {
    return _meters;
  }
  
  
  float Distance::centimeters() const
  {
    return _meters * 100.0;
  }
  
  
  float Distance::millimeters() const
  {
    return _meters * 1000.0;
  }
  
  
  Distance Distance::absolute() const
  {
    return Distance::from_meters(abs(meters()));
  }
  
  
  Distance Distance::operator+(const Distance& other_distance)
  {
    return Distance::from_meters(meters() + other_distance.meters());
  }
  
  
  Distance& Distance::operator+=(const Distance& other_distance)
  {
    _set_meters(meters() + other_distance.meters());
    return *this;
  }
  
  
  Distance Distance::operator-()
  {
    return Distance::from_meters(-meters());
  }
  
  
  Distance Distance::operator-(const Distance& other_distance)
  {
    return Distance::from_meters(meters() - other_distance.meters());
  }
  
  
  Distance& Distance::operator-=(const Distance& other_distance)
  {
    _set_meters(meters() - other_distance.meters());
    return *this;
  }
  
  
  template <typename Numeric>
  Distance Distance::operator*(const Numeric number)
  {
    return Distance::from_meters(meters() * number);
  }
  
  
  template <typename Numeric>
  Distance& Distance::operator*=(const Numeric number)
  {
    _set_meters(meters() * number);
    return *this;
  }
  
  
  template <typename Numeric>
  Distance Distance::operator/(const Numeric number)
  {
    return Distance::from_meters(meters() / number);
  }
  
  
  template <typename Numeric>
  Distance& Distance::operator/=(const Numeric number)
  {
    _set_meters(meters() / number);
    return *this;
  }
  
  
  template <typename Numeric>
  Numeric Distance::operator/(const Distance& other_distance)
  {
    return meters() / other_distance.meters();
  }
  
  
  Distance Distance::operator%(Distance& other_distance)
  {
    return Distance::from_meters(fmod(meters(), other_distance.meters()));
  }
  
  
  Distance& Distance::operator%=(Distance& other_distance)
  {
    _set_meters(fmod(meters(), other_distance.meters()));
    return *this;
  }
  
  
  Distance& Distance::operator=(const Distance& other_distance)
  {
    _set_meters(other_distance.meters());
    return *this;
  }
  
  
  //
  // private
  //
  
  
  Comparable<Distance>::Comparison Distance::_compare_with(const Distance other_distance) const
  {
    if (meters() < other_distance.meters())
      return Comparable::Comparison::Less;
    else if (meters() > other_distance.meters())
      return Comparable::Comparison::Greater;
    else
      return Comparable::Comparison::Equal;
  }
  
  
  void Distance::_set_meters(float meters)
  {
    _meters = meters;
  }
  
  
  void Distance::_set_centimeters(float centimeters)
  {
    _set_meters(centimeters / 100.0);
  }
  
  
  void Distance::_set_millimeters(float millimeters)
  {
    _set_meters(millimeters / 1000.0);
  }
  
  
}
