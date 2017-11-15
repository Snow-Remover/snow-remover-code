#include "Hardware.h"


namespace Robot
{
  namespace Hardware 
  {
    
    //
    // public
    //
    
    
    LIDARSensor::LIDARSensor()
    {
      _lidar_lite = LIDARLite();
      _is_setup = false;
    }
    
    
    int LIDARSensor::distance()
    {
      if (!_is_setup) return false;
      
      // 1 of 100 measurements with receiver bias correction
      return _lidar_lite.distance();
      
      // 99 of 100 measurements without receiver bias correction
      //_lidar_lite.distance(false);
      
      // maybe use a class varible to keep track of which one to take
    }
    
    
    void LIDARSensor::setup()
    {
      _lidar_lite.begin(0, true);
      _lidar_lite.configure(0);
      _is_setup = true;
    }
    
    
    //
    // private
    //
    
    
  }
}
  
