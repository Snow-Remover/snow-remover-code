#ifndef _ROBOT_HARDWARE_MAIN_H_
#define _ROBOT_HARDWARE_MAIN_H_


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
