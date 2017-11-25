#ifndef _GEOMETRY_POINT_H_
#define _GEOMETRY_POINT_H_


namespace Geometry
{
  
  class Point
  {
    
    public:
    
    Point();
    Point(const Point& other_point);
    Point(float x, float y);
    
    float x() const;
    float y() const;
    Point to_point() const;
    Point normalized() const;
    float length() const;
    float dot_product(const Point other_point) const;
    float cross_product(const Point other_point) const;
    Measurement::CoterminalAngle angle_to(const Point other_point) const;
    Point operator+(const Point other_point) const;
    Point& operator+=(const Point& other_point);
    Point operator-() const;
    Point operator-(const Point other_point) const;
    Point& operator-=(const Point& other_point);
    template <typename Numeric>
    Point operator*(Numeric number) const;
    template <typename Numeric>
    Point& operator*=(Numeric number);
    template <typename Numeric>
    Point operator/(Numeric number) const;
    template <typename Numeric>
    Point& operator/=(Numeric number);
    Point& operator=(const Point other_point);
    boolean operator==(const Point other_point) const;
    boolean operator!=(const Point other_point) const;
    
    private:
    
    float _x;
    float _y;
    
  };
  
}

#endif
