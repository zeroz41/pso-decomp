#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"

s32 TAdVIConfigGC::draw_with_layer(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    TAdVIConfigGC__sub_80267704(0x23);
    temp_r31 = (s32)TWindowSubStatusDisp__sub_80248BE8(arg0, arg1, arg2);
    TAdVIConfigGC__sub_80267704(3);
    return temp_r31;
}
