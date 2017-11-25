#ifndef _GEOMETRY_LINE_H_
#define _GEOMETRY_LINE_H_


namespace Geometry
{
  
  class Line
  {
    
    public:
    
    enum class Side { UpRight, DownLeft, OnLine };
    
    static Line from_points(const Point point_1, const Point point_2);
    static Line from_point_and_direction(const Point point, const Point direction);
    
    Line();
    Line(const Line& other_line);
    Line(const Point point, const Point direction);
    
    Point point() const;
    Point direction() const;
    Side get_side_of(const Point point) const;
    Point intersects_with(Line other_line) const;
    Line perpendicular_through(const Point point) const;
    boolean operator==(const Line other_line) const;
    boolean operator!=(const Line other_line) const;
    //float distance_to(Vector point) const;
    
    
    private:
    
    Point _point;
    Point _direction;
    
  };
  
}

#endif
