#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubStatusDisp.h"

f32 TWindowBase::get_scale() { return *(f32*)((char*)this + 0x1c); }
void TWindowSubStatusDisp::set_entry1_field20(s32 arg1) {
    *(s32 *)((s8 *)(get_array_entry(1)) + 0x20) = arg1;
}
