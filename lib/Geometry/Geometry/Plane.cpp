#include "Geometry.h"


namespace Geometry
{
  
  //
  // public
  //
  
  
  Plane::Plane(const Vector vector_1, const Vector vector_2)
  {
    _vector_1 = vector_1;
    _vector_2 = vector_2;
  }
  
  
  Vector Plane::vector_1() const
  {
    return _vector_1;
  }
  
  
  Vector Plane::vector_2() const
  {
    return _vector_2;
  }
  
  
  float Plane::distance_to(Vector vector) const
  {
    Vector difference = vector_2() - vector_1();
    Vector perpendicular_vector = Vector(difference.x(), -difference.y());
    return (vector - vector_1()).dot_product(perpendicular_vector);
  }
  
  
  //Plane Plane::perpendicular()
  //{
  //  Vector difference = vector_2() - vector_1();
  //  return Plane(difference.x(), -difference.y())
  //}
  
  
  //
  // private
  //
  
  
}
