#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <Arduino.h>

#include "Math.h"
#include "Measurement.h"
#include "NativeExtensions.h"

#include "Geometry/Point.h"
#include "Geometry/Line.h"

// Include implementation file at the end of the header. This way,
// implementation is still separated from declaration, but is accessible
// to the compiler.
#include "Geometry/Point.tpp"

#endif
