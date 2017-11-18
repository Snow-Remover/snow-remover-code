#include "Hardware.h"


namespace Robot
{
  namespace Hardware
  {

    AdafruitMotorShield::Shield Main::motor_shield = AdafruitMotorShield::Shield();
    StepperMotor Main::lidar_stepper_motor = StepperMotor(motor_shield.get_stepper_motor(1), 200, StepperMotor::StepType::Single);
    ServoMotor Main::plow_servo_motor = ServoMotor(9, Measurement::Angle::from_degrees(90.0));
    LIDARSensor Main::lidar_sensor = LIDARSensor();


    void Main::setup()
    {
      motor_shield.begin();
      plow_servo_motor.setup();
      lidar_sensor.setup();
    }


    void Main::tick()
    {
      lidar_stepper_motor.tick();
    }

  }
}
