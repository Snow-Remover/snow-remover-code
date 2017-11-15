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


  void Vision::tick()
  {

    Hardware::LIDARSensor* sensor = &Hardware::Main::lidar_sensor; // use this to access lidar
    StepperMotor* motor = &Hardware::Main::lidar_stepper_motor; // use this to access motor

    Serial.println(sensor->distance());

    //suggestions

    //rotate 'motor' to Angle 0
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


}
