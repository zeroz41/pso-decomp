#include "types.h"
#include "pso/unk/text_803D8030.h"
struct E_803D8030 { u8 pad[0x10]; };

extern "C" {
extern E_803D8030 *lbl_805D76D4;
extern E_803D8030 *lbl_805D76D0;
extern s32 lbl_805D76CC;
extern s32 lbl_805D76C8;
extern E_803D8030 *debug_text_record_cursor;
extern E_803D8030 *debug_text_pool_cursor;
extern s32 debug_text_global_count;
extern f32 debug_text_scale;
void fn_803D8030(E_803D8030 *p, s32 n, s32 x);
#pragma push
#pragma scheduling off
void fn_803D8030(E_803D8030 *p, s32 n, s32 x) {
    lbl_805D76D4 = p;
    lbl_805D76D0 = p + n;
    lbl_805D76CC = n;
    lbl_805D76C8 = x;
    debug_text_record_cursor = p;
    debug_text_pool_cursor = p + n;
    debug_text_global_count = -1;
    debug_text_scale = 16.0f;
}
#pragma pop

void fn_803D8064(u16 arg0) {
    debug_text_scale = (f32)arg0;
}

}
