#include "Hardware.h"


namespace Robot
{
  namespace Hardware
  {

    AdafruitMotorShield::Shield Main::motor_shield = AdafruitMotorShield::Shield();
    StepperMotor Main::lidar_stepper_motor = StepperMotor(motor_shield.get_stepper_motor(2), 200, StepperMotor::StepType::Single);
    DCMotor Main::left_track_motor = DCMotor(motor_shield.get_dc_motor(1));
    DCMotor Main::right_track_motor = DCMotor(motor_shield.get_dc_motor(2));
    ServoMotor Main::plow_servo_motor = ServoMotor(9, Measurement::Angle::from_degrees(90.0));
    LIDARSensor Main::lidar_sensor = LIDARSensor();


    void Main::setup()
    {
      motor_shield.begin();
      if (!lidar_stepper_motor.setup())
      {
        Serial.println("ERROR seting up lidar_stepper_motor.");
        end();
      }
      lidar_sensor.setup();
      if (!left_track_motor.setup())
      {
        Serial.println("ERROR seting up left_track_motor.");
        end();
      }
      if (!right_track_motor.setup())
      {
        Serial.println("ERROR seting up right_track_motor.");
        end();
      }
      plow_servo_motor.setup();
    }


    void Main::tick()
    {
      lidar_stepper_motor.tick();
    }

  }
}
