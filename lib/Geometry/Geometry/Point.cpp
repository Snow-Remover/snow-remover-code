#include "Geometry.h"


namespace Geometry
{
  
  //
  // public
  //
  
  
  Point::Point()
  {
    _x = 0.0;
    _y = 0.0;
  }
  
  
  Point::Point(const Point& other_point)
  {
    _x = other_point.x();
    _y = other_point.y();
  }
  
  
  Point::Point(float x, float y)
  {
    _x = x;
    _y = y;
  }
  
  
  float Point::x() const
  {
    return _x;
  }
  
  
  float Point::y() const
  {
    return _y;
  }
  
  
  Point Point::to_point() const
  {
    return Point(x(), y());
  }
  
  
  Point Point::normalized() const
  {
    return to_point() / length();
  }
  
  
  float Point::length() const
  {
    return sqrt(pow(x(), 2) + pow(y(), 2));
  }
  
  
  float Point::dot_product(const Point other_point) const
  {
    return x() * other_point.x() + y() * other_point.y();
  }
  
  
  float Point::cross_product(const Point other_point) const
  {
    return x() * other_point.y() - other_point.x() * y();
  }
  
  
  Measurement::CoterminalAngle Point::angle_to(const Point other_point) const
  {
    Point direction = other_point - to_point();
    if (direction.x() != 0.0)
      return Measurement::CoterminalAngle::from_radians(atan2(direction.y(), direction.x()));
    else
    {
      if (direction.y() > 0.0)
        return Measurement::CoterminalAngle::from_revolutions(0);
      else if (direction.y() < 0.0)
        return Measurement::CoterminalAngle::from_revolutions(0.5);
      else
      {
        Serial.println("Error in Point::angle_to, angle does not exist, both points overlap.");
        end();
        return Measurement::CoterminalAngle::zero();
      }
    }
  }
  
  
  Point Point::operator+(const Point other_point) const
  {
    return Point(x() + other_point.x(), y() + other_point.y());
  }
  
  
  Point& Point::operator+=(const Point& other_point)
  {
    _x += other_point.x();
    _y += other_point.y();
    return *this;
  }
  
  
  Point Point::operator-() const
  {
    return Point(-x(), -y());
  }
  
  
  Point Point::operator-(const Point other_point) const
  {
    return Point(x() - other_point.x(), y() - other_point.y());
  }
  
  
  Point& Point::operator-=(const Point& other_point)
  {
    _x -= other_point.x();
    _y -= other_point.y();
    return *this;
  }
  
  
  Point& Point::operator=(const Point other_point)
  {
    _x = other_point.x();
    _y = other_point.y();
    return *this;
  }
  
  
  boolean Point::operator==(const Point other_point) const
  {
    return x() == other_point.x() && y() == other_point.y();
  }
  
  
  boolean Point::operator!=(const Point other_point) const
  {
    return !(*this == other_point);
  }
  
  
  //
  // private
  //
  
  
}
