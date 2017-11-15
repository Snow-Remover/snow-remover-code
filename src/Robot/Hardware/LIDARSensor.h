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
      
      unsigned int distance();
      void setup();
      void tick();
      
      private:
      
      
    };
    
  }
}

#endif
