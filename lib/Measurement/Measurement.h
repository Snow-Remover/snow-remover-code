#ifndef _MEASUREMENT_H_
#define _MEASUREMENT_H_

#include <Arduino.h>

#include "Comparable.h"

// arduino library implements degrees(rad) as a macro, eww
#ifdef degrees
#undef degrees
#endif

#include "Measurement/BaseAngle.h"
#include "Measurement/Angle.h"
#include "Measurement/CoterminalAngle.h"
#include "Measurement/AngularVelocity.h"

// Include implementation file at the end of the header. This way,
// implementation is still separated from declaration, but is accessible
// to the compiler.
#include "Measurement/BaseAngle.tpp"

#endif
