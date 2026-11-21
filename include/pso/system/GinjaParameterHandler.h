#ifndef PSO_SYSTEM_GINJAPARAMETERHANDLER_H
#define PSO_SYSTEM_GINJAPARAMETERHANDLER_H

#include "types.h"

// Native dispatch passes a value and its changed-bit mask in r3/r4. Only
// the channel-count handler consumes the second word.
typedef void (*GinjaParameterHandler)(u32 value, u32 changed);

#endif
