#ifndef PSO_OBJECT_BASE_HITELIGIBILITY_H
#define PSO_OBJECT_BASE_HITELIGIBILITY_H

#include "types.h"

class TObjCollidable;

extern "C" s32 obj_is_hit_receivable(const TObjCollidable *target);

#endif
