#include "Robot.h"


namespace Robot
{

  //
  // public
  //


  Vision::Vision()
  {
  }


  void Vision::setup()
  {
  }


  void Vision::start()
  {
  }

  unsigned int Vision::closest_obj()
  {
    return _last_obj_distance;
  }


  void Vision::tick()
  {

    Hardware::LIDARSensor* sensor = &Hardware::Main::lidar_sensor; // use this to access lidar
    StepperMotor* motor = &Hardware::Main::lidar_stepper_motor; // use this to access motor


    if (motor->is_stopped()) {

      unsigned int temp_distance = sensor->distance();
      if (temp_distance < _obj_distance) {
        _obj_distance = temp_distance;
      }

      _current_increment += _increment_direction;
      Measurement::Angle current_angle = _increment_angle * _current_increment;

      if (current_angle < Measurement::Angle::zero()) {
        _increment_direction = 1;
        current_angle = _increment_angle * _current_increment;
        _last_obj_distance = _obj_distance;
        _obj_distance = 101;

        Serial.println(_last_obj_distance);
      }

      if (current_angle > Measurement::Angle::revolution()) {
        _increment_direction = -1;
        current_angle = _increment_angle * _current_increment;
        _last_obj_distance = _obj_distance;
        _obj_distance = 101;

        Serial.println(_last_obj_distance);
      }

      Measurement::AngularVelocity angular_velocity = Measurement::AngularVelocity::from_revolutions_per_second(0.5);
      motor->rotate_to(current_angle, angular_velocity);
    }




    //rotate 'motor' to next angle
    //wait for motor.is_stopped()
    //get reading
    //rotate 'motor' to next angle
    //wait for motor.is_stopped()
    //get reading
    //rotate 'motor' to next angle
    //wait for motor.is_stopped()
    //get reading
    //...
    //rotate 'motor' to Angle 0
    //repeat


  }


  //
  // private
  //

  Measurement::Angle Vision::_increment_angle =  Measurement::Angle::from_degrees(5);
  int Vision::_current_increment = 0;
  unsigned int Vision::_obj_distance = 101;
  unsigned int Vision::_last_obj_distance = 101;
  int Vision::_increment_direction = 1;

}
