#ifndef _ROBOT_HARDWARE_MAIN_H_
#define _ROBOT_HARDWARE_MAIN_H_

// this directory configures and sets up all the hardware that the rest
//   of the code will interact with
// it is separated to keep the rest of the code clean and allow any adjustment
//   to the hardware (eg. replacing a motor) to be done simply

namespace Robot
{
  namespace Hardware 
  {
    
    class Main
    {
      
      public:
      
      static AdafruitMotorShield::Shield motor_shield;
      static StepperMotor lidar_stepper_motor;
      static DCMotor left_track_motor;
      static DCMotor right_track_motor;
      static ServoMotor plow_servo_motor;
      static LIDARSensor lidar_sensor;
      
      static void setup();
      static void tick();
      
    };
    
  }
}

#endif
