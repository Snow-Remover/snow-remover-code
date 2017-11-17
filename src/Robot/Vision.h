#ifndef _ROBOT_VISION_H_
#define _ROBOT_VISION_H_


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
