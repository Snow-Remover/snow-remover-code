#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    Position::Position()
    {
      _x = Measurement::Distance::zero();
      _y = Measurement::Distance::zero();
      _heading = Measurement::CoterminalAngle::zero();
    }
    
    
    Position::Position(const Measurement::Distance x, const Measurement::Distance y, const Measurement::CoterminalAngle heading)
    {
      _x = x;
      _y = y;
      _heading = heading;
    }
    
    
    const Measurement::Distance Position::x() const
    {
      return _x;
    }
    
    
    const Measurement::Distance Position::y() const
    {
      return _y;
    }
    
    
    const Location Position::location() const
    {
      return Location(_x, _y);
    }
    
    
    const Measurement::CoterminalAngle Position::heading() const
    {
      return _heading;
    }
    
    
    //
    // private
    //
    
    
    
  }
} 
