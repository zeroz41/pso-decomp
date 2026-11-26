#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXManage.h>
#undef PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSCache.h>
#include "pso/system/TLanguage.h"
#include "pso/unk/text_803DAFA8.h"

extern "C" {

s32 draw_string__9TLanguageFPvPvl();
}

void TLanguage::decode_font_data(void *arg0, void *arg1, s32 arg2, s32 tlut_name) {
    s32 n;
    s32 i;
    u16 *p;
    u16 value;

    draw_string__9TLanguageFPvPvl();
    n = *(s16 *)((s8 *)arg1 + 0xA);
    p = *(u16 **)((s8 *)arg1 + 0);
    for (i = n; i > 0; i--) {
        value = *p;
        if (value & 0x8000) {
            *p = value ^ 0x7FFF;
        } else {
            *p = value ^ 0xFFF;
            *p |= 0x7000;
        }
        p += 1;
    }
    DCStoreRange(*(u16 **)((s8 *)arg1 + 0), 0x40000);
    init_and_load_tlut(tlut_name, *(u16 *)((s8 *)arg1 + 4), *(s16 *)((s8 *)arg1 + 0xA), *(u16 **)((s8 *)arg1 + 0));
    GXDrawDone();
}
