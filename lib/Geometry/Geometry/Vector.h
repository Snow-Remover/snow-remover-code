#ifndef _GEOMETRY_VECTOR_H_
#define _GEOMETRY_VECTOR_H_


namespace Geometry
{
  
  class Vector
  {
    
    public:
    
    Vector();
    Vector(float x, float y);
    
    float x() const;
    float y() const;
    Vector operator-(const Vector& other_vector) const;
    Vector& operator-=(const Vector& other_vector);
    float dot_product(const Vector other_vector) const;
    
    private:
    
    float _x;
    float _y;
    
  };
  
}

#endif
