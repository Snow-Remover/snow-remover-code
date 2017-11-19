#ifndef _GEOMETRY_PLANE_H_
#define _GEOMETRY_PLANE_H_


namespace Geometry
{
  
  class Plane
  {
    
    public:
    
    Plane(const Vector vector_1, const Vector vector_2);
    
    Vector vector_1() const;
    Vector vector_2() const;
    float distance_to(Vector point) const;
    //Plane perpendicular();
    
    private:
    
    Vector _vector_1;
    Vector _vector_2;
    
  };
  
}

#endif
