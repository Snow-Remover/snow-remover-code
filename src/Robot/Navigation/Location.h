#ifndef _ROBOT_NAVIGATION_LOCATION_H_
#define _ROBOT_NAVIGATION_LOCATION_H_


namespace Robot
{
  namespace Navigation
  {
    
    class Location
    {
      
      public:
      
      Location();
      Location(const Measurement::Distance x, const Measurement::Distance y);
      const Measurement::Distance x() const;
      const Measurement::Distance y() const;
      
      private:
      
      Measurement::Distance _x;
      Measurement::Distance _y;
      
    };
    
  }
}

#endif
