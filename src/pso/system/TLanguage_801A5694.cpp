#include "types.h"
#include "pso/system/TLanguage.h"

extern "C" {

s32 draw_string__9TLanguageFPvPvl();
s32 GXDrawDone();
s32 init_and_load_tlut(s32, u16, s16, u16 *);

s32 DCStoreRange(u16 *, s32);

void TLanguage::decode_font_data(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 n;
    s32 i;
    u16 *p;
    u16 temp_r3;

    draw_string__9TLanguageFPvPvl();
    n = *(s16 *)((s8 *)arg1 + 0xA);
    p = *(u16 **)((s8 *)arg1 + 0);
    for (i = n; i > 0; i--) {
        temp_r3 = *p;
        if (temp_r3 & 0x8000) {
            *p = temp_r3 ^ 0x7FFF;
        } else {
            *p = temp_r3 ^ 0xFFF;
            *p |= 0x7000;
        }
        p += 1;
    }
    DCStoreRange(*(u16 **)((s8 *)arg1 + 0), 0x40000);
    init_and_load_tlut(arg3, *(u16 *)((s8 *)arg1 + 4), *(s16 *)((s8 *)arg1 + 0xA), *(u16 **)((s8 *)arg1 + 0));
    GXDrawDone();
}

}
