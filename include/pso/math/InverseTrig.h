#ifndef PSO_MATH_INVERSETRIG_H
#define PSO_MATH_INVERSETRIG_H

#include "types.h"
#include <math.h>

// The f32 forms of the C library's acos and asin. Each one sits at the end of
// the first file that calls it: acosf in TBoss2Fin.cpp, asinf in TBoss6Mine.cpp.
f32 acosf(f32 x);
f32 asinf(f32 x);

#endif
