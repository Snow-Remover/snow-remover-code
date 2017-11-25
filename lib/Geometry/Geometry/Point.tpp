namespace Geometry
{
  
  //
  // public
  //
  
  
  template <typename Numeric>
  Point Point::operator*(Numeric number) const
  {
    return Point(x() * number, y() * number);
  }
  
  
  template <typename Numeric>
  Point& Point::operator*=(Numeric number)
  {
    _x *= number;
    _y *= number;
    return *this;
  }
  
  
  template <typename Numeric>
  Point Point::operator/(Numeric number) const
  {
    return Point(x() / number, y() / number);
  }
  
  
  template <typename Numeric>
  Point& Point::operator/=(Numeric number)
  {
    _x /= number;
    _y /= number;
    return *this;
  }
  
  
  //
  // private
  //
  
  
}
