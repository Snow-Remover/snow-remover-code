#include "Measurement.h"


namespace Measurement
{
  
  //
  // public
  //
  
  
  Angle Angle::revolution()
  {
    return Angle::from_degrees(360.0);
  }
  
  
  Angle Angle::absolute() const
  {
    return Angle::from_degrees(abs(degrees()));
  }
  
  
  Angle Angle::operator-() const
  {
    return Angle::from_degrees(-degrees());
  }
  
  
  //
  // private
  //
  
  
  Comparable<Angle>::Comparison Angle::_compare_with(const Angle other_angle) const
  {
    if (degrees() < other_angle.degrees())
      return Comparable::Comparison::Less;
    else if (degrees() > other_angle.degrees())
      return Comparable::Comparison::Greater;
    else
      return Comparable::Comparison::Equal;
  }
  
  
  void Angle::_set_degrees(float degrees)
  {
    _degrees = degrees;
  }
  
  
}
