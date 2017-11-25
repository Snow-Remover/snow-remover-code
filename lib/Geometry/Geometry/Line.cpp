#include "Geometry.h"


namespace Geometry
{
  
  //
  // public
  //
  
  
  Line Line::from_points(const Point point_1, const Point point_2)
  {
    Point direction = point_2 - point_1;
    return Line(point_1, direction);
  }
  
  
  Line Line::from_point_and_direction(const Point point, const Point direction)
  {
    return Line(point, direction);
  }
  
  
  Line::Line()
  {
    _point = Point();
    _direction = Point();
  }
  
  
  Line::Line(const Line& other_line)
  {
    _point = other_line.point();
    _direction = other_line.direction();
  }
  
  
  Line::Line(const Point point, const Point direction)
  {
    _point = point;
    _direction = direction;
  }
  
  
  Point Line::point() const
  {
    return _point;
  }
  
  
  Point Line::direction() const
  {
    return _direction;
  }
  
  
  Line::Side Line::get_side_of(const Point point) const
  {
    float dot_product = direction().cross_product(point - this->point());
    if (dot_product > 0.0)
      return Side::UpRight;
    else if (dot_product < 0.0)
      return Side::DownLeft;
    else
      return Side::OnLine;
  }
  
  
  Point Line::intersects_with(Line other_line) const
  {
    float x;
    float y;
    if (direction().x() == 0.0) // workaround for infinite slope
    {
      x = 0.0;
      // y = ((ya2*(x-xp2)) / xa2) + yp2
      y = ((other_line.direction().y()*(x-other_line.point().x())) / other_line.direction().x()) + other_line.point().y();
    }
    else if (other_line.direction().x() == 0.0) // workaround for infinite slope
    {
      x = 0.0;
      // y = ((ya1*(x-xp1)) / xa1) + yp1
      y = ((direction().y()*(x-point().x())) / direction().x()) + point().y();
    }
    else
    {
      // x = ((ya1*xp1)/(xa1) - (ya2*xp2)/(xa2) - yp1 + yp2) / ((ya1/xa1) - (ya2/xa2))
      x = ( ((direction().y()*point().x())/(direction().x())) - ((other_line.direction().y()*other_line.point().x())/(other_line.direction().x())) - point().y() + other_line.point().y()) / ((direction().y()/direction().x()) - (other_line.direction().y()/other_line.direction().x()));
      // y = ((ya1*(x-xp1)) / xa1) + yp1
      y = ((direction().y()*(x-point().x())) / direction().x()) + point().y();
    }
    return Point(x, y);
  }
  
  
  boolean Line::operator==(const Line other_line) const
  {
    return point() == other_line.point() && direction() == other_line.direction();
  }
  
  
  boolean Line::operator!=(const Line other_line) const
  {
    return !(*this == other_line);
  }
  
  
  Line Line::perpendicular_through(const Point point) const
  {
    Point perpendicular_direction = Point(-direction().y(), direction().x());
    return Line::from_point_and_direction(point, perpendicular_direction);
  }
  
  
  //float Plane::distance_to(Vector vector) const
  //{
    //Vector difference = vector_2() - vector_1();
    //Vector perpendicular_vector = Vector(difference.x(), -difference.y());
    //return (vector - vector_1()).dot_product(perpendicular_vector);
  //}
  
  
  
  
  
  //
  // private
  //
  
  
}
