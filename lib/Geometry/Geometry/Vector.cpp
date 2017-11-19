#include "Geometry.h"


namespace Geometry
{
  
  //
  // public
  //
  
  
  Vector::Vector()
  {
    _x = 0.0;
    _y = 0.0;
  }
  
  
  Vector::Vector(float x, float y)
  {
    _x = x;
    _y = y;
  }
  
  
  float Vector::x() const
  {
    return _x;
  }
  
  
  float Vector::y() const
  {
    return _y;
  }
  
  
  Vector Vector::operator-(const Vector& other_vector) const
  {
    return Vector(x() - other_vector.x(), y() - other_vector.y());
  }
  
  
  Vector& Vector::operator-=(const Vector& other_vector)
  {
    _x = x() - other_vector.x();
    _y = y() - other_vector.y();
    return *this;
  }
  
  
  float Vector::dot_product(const Vector other_vector) const
  {
    return x() * other_vector.x() + y() * other_vector.y();
  }
  
  
  //
  // private
  //
  
  
}
