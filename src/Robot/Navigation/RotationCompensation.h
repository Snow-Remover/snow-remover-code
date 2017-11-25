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
      static boolean is_compete();
      static void set_target(Measurement::CoterminalAngle heading);
      static void setup();
      static void update();
      
      private:
      
      static Measurement::CoterminalAngle _target_heading;
      
      static Measurement::CoterminalAngle _current_heading();
      
    };
    
  }  
}

#endif
