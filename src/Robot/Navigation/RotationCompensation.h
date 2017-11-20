#ifndef _ROBOT_NAVIGATION_ROTATION_COMPENSATION_H_
#define _ROBOT_NAVIGATION_ROTATION_COMPENSATION_H_


namespace Robot
{
  namespace Navigation
  {
    
    class RotationCompensation
    {
      
      public:
      
      static void freeze();
      static void set_target(Measurement::CoterminalAngle angle);
      static void setup();
      static boolean is_compete();
      static void tick();
      
      private:
      
      static Measurement::CoterminalAngle _target_angle;
      
      static Measurement::CoterminalAngle _current_angle();
      
    };
    
  }  
}

#endif
