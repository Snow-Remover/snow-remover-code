#ifndef _MEASUREMENT_H_
#define _MEASUREMENT_H_

#include <Arduino.h>

#include "NativeExtensions.h"
#include "Comparable.h"

// arduino library implements some macros that make a mess
// undefine them here
#ifdef degrees
#undef degrees
#endif
#ifdef radians
#undef radians
#endif

#include "Measurement/BaseAngle.h"
#include "Measurement/Angle.h"
#include "Measurement/CoterminalAngle.h"
#include "Measurement/AngularVelocity.h"
#include "Measurement/Distance.h"

// Include implementation file at the end of the header. This way,
// implementation is still separated from declaration, but is accessible
// to the compiler.
#include "Measurement/BaseAngle.tpp"

#endif
