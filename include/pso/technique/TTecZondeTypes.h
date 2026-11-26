#ifndef PSO_TECHNIQUE_TTECZONDETYPES_H
#define PSO_TECHNIQUE_TTECZONDETYPES_H

#include "types.h"

// One bolt of Zonde: it starts at `start`, travels along the unit vector `dir` for `len`.
struct ZondeBolt { Vec start; Vec dir; f32 len; };

#endif
