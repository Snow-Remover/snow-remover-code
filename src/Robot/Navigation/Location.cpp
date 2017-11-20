#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    Location::Location()
    {
      _x = Measurement::Distance::zero();
      _y = Measurement::Distance::zero();
    }
    
    
    Location::Location(const Measurement::Distance x, const Measurement::Distance y)
    {
      _x = x;
      _y = y;
    }
    
    
    const Measurement::Distance Location::x() const
    {
      return _x;
    }
    
    
    const Measurement::Distance Location::y() const
    {
      return _y;
    }
    
    
    //
    // private
    //
    
    
    
  }
} 
