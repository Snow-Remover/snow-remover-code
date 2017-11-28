
namespace Measurement
{
  
  //
  // public
  //
  
  
  template <typename Numeric>
  Distance Distance::operator*(const Numeric number) const
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
  Distance Distance::operator/(const Numeric number) const
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
  Numeric Distance::operator/(const Distance& other_distance) const
  {
    return meters() / other_distance.meters();
  }
  
  
  //
  // private
  //
   
   
}
