#include <Arduino.h>

//need to be included here as well due to Arduino-mk bug
#include <Pozyx.h>
#include <Pozyx_definitions.h>
#include <SoftwareSerial.h>
#include <Servo.h>


#include "Robot/Robot.h"


// setup every task (eg. pin modes)
// some return false to indicate an error
void setup()
{
  Serial.begin(9600);
  //Serial.println("begin...");
  Robot::Main::setup();

  Robot::Main::start();
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
  Robot::Main::tick();
}
