#ifndef _ROBOT_NAVIGATION_POSITION_H_
#define _ROBOT_NAVIGATION_POSITION_H_


namespace Robot
{
  namespace Navigation
  {
    
    class Position
    {
      
      public:
      
      Position();
      Position(const Measurement::Distance x, const Measurement::Distance y, const Measurement::CoterminalAngle angle);
      const Measurement::Distance x() const;
      const Measurement::Distance y() const;
      const Location location() const;
      const Measurement::CoterminalAngle angle() const;
      
      private:
      
      Measurement::Distance _x;
      Measurement::Distance _y;
      Measurement::CoterminalAngle _angle;
      
    };
    
  }
}

#endif
