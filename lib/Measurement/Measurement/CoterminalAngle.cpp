#include "Measurement.h"


namespace Measurement
{
  
  //
  // public
  //
  
  
  boolean CoterminalAngle::is_between(const CoterminalAngle start_angle, const CoterminalAngle end_angle)
  {
    Angle temp_start_angle = start_angle.to_angle();
    Angle temp_end_angle = end_angle.to_angle();
    Angle temp_this_angle = to_angle();
    
    //fix jump of angle
    if (temp_end_angle < temp_start_angle )
    {
      temp_end_angle += Angle::revolution();
      if (temp_this_angle < temp_start_angle)
        temp_this_angle += Angle::revolution();
    }
    
    return temp_this_angle.is_between(temp_start_angle, temp_end_angle);
  }
  
  
  CoterminalAngle CoterminalAngle::difference_from(const CoterminalAngle other_angle)
  {
    Angle difference_angle = (to_angle() - other_angle.to_angle()).absolute();
    if (difference_angle > Angle::revolution() / 2)
      difference_angle = Angle::revolution() - difference_angle;
    return difference_angle.to_coterminal_angle();
  }
  
  
  boolean CoterminalAngle::operator==(const CoterminalAngle other_angle)
  {
    return degrees() == other_angle.degrees();
  }
  
  
  boolean CoterminalAngle::operator!=(const CoterminalAngle other_angle)
  {
    return !(*this == other_angle);
  }
  
  
  //
  // private
  //
  
  
  void CoterminalAngle::_clean()
  {
    while (_degrees > 360.0)
      _degrees -= 360.0;
    while (_degrees < 0)
      _degrees += 360.0;
  }
  
  
  void CoterminalAngle::_set_degrees(const float degrees)
  {
    _degrees = degrees;
    _clean();
  }
  
  
  void CoterminalAngle::_set_revolutions(const float revolutions)
  {
    _set_degrees(revolutions * 360.0);
  }
  
  
}