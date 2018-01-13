#ifndef _ROBOT_NAVIGATION_NAVIGATION_H_
#define _ROBOT_NAVIGATION_NAVIGATION_H_

// this header is only used to include the necessity headers to compile
//   code in this directory

#include <Arduino.h>
#include <Wire.h>
#include <Pozyx.h>
#include <Pozyx_definitions.h>
#include <SoftwareSerial.h>

#include "NativeExtensions.h"
#include "Measurement.h"
#include "Geometry.h"
#include "Math.h"
#include "Timer.h"
#include "PeriodicTimer.h"
#include "MessageBuffer.h"

#include "../Hardware/Hardware.h"
#include "../Vision.h"

#include "MotorMixer.h"
#include "Location.h"
#include "Position.h"
#include "Positioning.h"
#include "RotationCompensation.h"
#include "TranslationCompensation.h"
#include "Plow.h"
#include "Main.h"

//#include "../Robot.h"

#endif
