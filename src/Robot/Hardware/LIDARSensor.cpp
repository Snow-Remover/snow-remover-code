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
      _biasCount = 0;
    }


    int LIDARSensor::distance()
    {
      if (!_is_setup) return false;


      if (_biasCount == 0) {
        // 1 of 100 measurements with receiver bias correction
        return _lidar_lite.distance();
      } else {
        // 99 of 100 measurements without receiver bias correction
        return _lidar_lite.distance(false);
      }

      //increments or resets bias counter
      if (_biasCount < 99) {
        _biasCount++;
      } else {
        _biasCount = 0;
      }
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
