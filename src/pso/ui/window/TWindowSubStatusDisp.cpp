#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

saddr TWindowBase::get_array_entry(int i) { return ((saddr *)*(void **)((char *)this + 0x28))[i]; }
