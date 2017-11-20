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
      _angle = Measurement::CoterminalAngle::zero();
    }
    
    
    Position::Position(const Measurement::Distance x, const Measurement::Distance y, const Measurement::CoterminalAngle angle)
    {
      _x = x;
      _y = y;
      _angle = angle;
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
    
    
    const Measurement::CoterminalAngle Position::angle() const
    {
      return _angle;
    }
    
    
    //
    // private
    //
    
    
    
  }
} 
