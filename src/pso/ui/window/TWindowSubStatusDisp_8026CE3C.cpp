#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowQuantity.h"

f32 TWindowBase::get_scale() { return sort_depth; }
void TWindowQuantity::set_quantity(s32 quantity) {
    *(s32 *)((s8 *)(get_array_entry(1)) + 0x20) = quantity;
}
