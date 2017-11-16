#include <Arduino.h>

#include "MessageBuffer.h"
#include "StepperMotor.h"
#include "ServoMotor.h"
#include "AdafruitMotorShield.h"
#include "Measurement.h"

AdafruitMotorShield::Shield motor_shield = AdafruitMotorShield::Shield();
StepperMotor stepper_motor = StepperMotor(motor_shield.get_stepper_motor(1), 200, StepperMotor::StepType::Single);
MessageBuffer messenger = MessageBuffer(Serial, 40);


// setup every task (eg. pin modes)
// some return false to indicate an error
void setup()
{
  Serial.begin(9600);
  messenger.write("started");
  motor_shield.begin();
}


// this is the reactor loop
// no calls should block here!
// if they do, all other tasks will miss deadlines
// the tick() method is called for each task
//    often the task will simply return
//    sometimes the task will have work do to, it will quickly run and return
//    execution to the ractor loop for the next task
void loop()
{
  stepper_motor.tick();
  messenger.tick();
  
  if (messenger.available())
  {
    String message = messenger.read();
    messenger.write("");
    
    float revolutions = 0;
    Measurement::Angle angle = Measurement::Angle::zero();
    float revolutions_per_second = 0;
    Measurement::AngularVelocity angular_velocity = Measurement::AngularVelocity::zero();
    
    if (message.indexOf("angle") == 0)
    {
      messenger.write("revolutions: " + String(stepper_motor.angle().revolutions()));
    }
    
    if (message.indexOf("desired_angle") == 0)
    {
      messenger.write("revolutions: " + String(stepper_motor.desired_angle().revolutions()));
    }
    
    if (message.indexOf("is_rotating") == 0)
    {
      messenger.write("is_rotating: " + String(stepper_motor.is_rotating()));
    }
    
    if (message.indexOf("reset") == 0)
    {
      stepper_motor.reset();
    }
    
    if (message.indexOf("rotate ") == 0)
    {
      revolutions_per_second = message.substring(7, 11).toFloat();
      angular_velocity = Measurement::AngularVelocity::from_revolutions_per_second(revolutions_per_second);
      messenger.write("revolutions_per_second: " + String(angular_velocity.revolutions_per_second()));
      stepper_motor.rotate(angular_velocity);
    }
    
    if (message.indexOf("rotate_angle ") == 0)
    {
      revolutions = message.substring(13, 17).toFloat();
      angle = Measurement::Angle::from_revolutions(revolutions);
      messenger.write("revolutions: " + String(angle.revolutions()));
      revolutions_per_second = message.substring(18, 22).toFloat();
      angular_velocity = Measurement::AngularVelocity::from_revolutions_per_second(revolutions_per_second);
      messenger.write("revolutions_per_second: " + String(angular_velocity.revolutions_per_second()));
      stepper_motor.rotate(angle, angular_velocity);
    }
    
    if (message.indexOf("rotate_to_angle ") == 0)
    {
      revolutions = message.substring(16, 20).toFloat();
      angle = Measurement::Angle::from_revolutions(revolutions);
      messenger.write("revolutions: " + String(angle.revolutions()));
      revolutions_per_second = message.substring(21, 25).toFloat();
      angular_velocity = Measurement::AngularVelocity::from_revolutions_per_second(revolutions_per_second);
      messenger.write("revolutions_per_second: " + String(angular_velocity.revolutions_per_second()));
      stepper_motor.rotate_to(angle, angular_velocity);
    }
    
    if (message.indexOf("stop") == 0)
    {
      stepper_motor.stop();
    }
    
  }
  
}
