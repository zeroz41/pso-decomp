#include "pso/ui/MenuText.h"
#include "types.h"
#include "pso/ui/TAdTitleTexGC.h"
#include "pso/TObjWarpString.h"


#pragma push
#pragma opt_common_subs off
void TAdTitleTexGC::sub_802A4D74(s32 arg1, u8 *arg2, u8 *arg3) {
    u8 *arg0 = (u8 *)this;
    draw_menu_text(22.0f + *(f32 *)((s8 *)arg0 + 0x1C), 1.0f + *(f32 *)((s8 *)arg0 + 0x20), (const char *)arg2, arg1);
    draw_menu_text(22.0f + *(f32 *)((s8 *)arg0 + 0x3C), 1.0f + *(f32 *)((s8 *)arg0 + 0x40), (const char *)arg3, arg1);
}

#pragma pop
