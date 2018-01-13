#ifndef _ROBOT_VISION_H_
#define _ROBOT_VISION_H_


// handles the vision component of the robot
// currently only offers 1D sight but ideally would be expanded to output
//   more detailed 3D data on the surrounding objects
// used by the Navigation component to know when to stop the robot

namespace Robot
{

  class Vision
  {

    public:

    Vision();

    static void setup();
    static void start();
    static unsigned int closest_obj();
    static void tick();

    private:

    static Measurement::Angle _increment_angle;
    static int _current_increment;
    static unsigned int _obj_distance;
    static unsigned int _last_obj_distance;
    static int _increment_direction;

  };

}

#endif
