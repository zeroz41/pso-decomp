#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubStatusDisp.h"

s32 TWindowBase::get_array_entry(int i) { return ((s32*)*(void**)((char*)this + 0x28))[i]; }
