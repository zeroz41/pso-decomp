#include "types.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/lappy/TObjEneLappy.h"

s32 TWindowLockOn::get_target_id() { return *(s32*)((char*)this + 0x370); }
