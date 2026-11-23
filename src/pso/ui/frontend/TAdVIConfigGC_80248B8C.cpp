#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"

s32 TAdVIConfigGC::draw_with_layer(s32 arg0, s32 size, s32 client) {
    s32 temp_r31;

    TAdVIConfigGC__sub_80267704(0x23);
    temp_r31 = (saddr)TWindowSubStatusDisp__sub_80248BE8(arg0, size, client);
    TAdVIConfigGC__sub_80267704(3);
    return temp_r31;
}
