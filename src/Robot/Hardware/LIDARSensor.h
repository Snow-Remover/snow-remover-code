#ifndef _ROBOT_HARDWARE_LIDAR_SENSOR_H_
#define _ROBOT_HARDWARE_LIDAR_SENSOR_H_


namespace Robot
{
  namespace Hardware
  {

    class LIDARSensor
    {

      public:

      LIDARSensor();

      int distance();
      void setup();
      //void tick();

      private:

      boolean _is_setup;
      LIDARLite _lidar_lite;
      int _biasCount;

    };

  }
}

#endif
