#include "types.h"
#include "pso/player/TObjPlayer_80141D1C.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct Self_800FFB38 {
    u8 pad[0x20];
    u32 *list;
};

extern "C" {
f32 sin_table_lookup(s32, f32, f32);
extern const f32 lbl_805DAA68;
extern const f32 lbl_805DAA6C;
extern const f32 lbl_805DAA70;
extern const f32 lbl_805DAA74;
extern const f32 lbl_805DAA78;
s32 TObjMotion::get_item_ptr(s32 arg1) {
    return (*(s32 *)&this->motion_buffer) + (arg1 * 0x30);
}
#pragma push
#pragma fp_contract on
s32 TObjPlayer::interpolate_along_curve(void *arg1) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f31;
    f32 temp_orig;
    temp_f1 = *(f32 *)((s8 *)arg1 + 8);
    if ((temp_f1 < lbl_805DAA68) || (temp_f1 > lbl_805DAA6C)) {
        return 0;
    }
    temp_f2 = temp_f1 - lbl_805DAA6C;
    temp_f31 = temp_f2 / lbl_805DAA70;
    *(f32 *)((s8 *)arg1 + 0) = (lbl_805DAA74 * temp_f31) * sin_table_lookup(*(s32 *)&this->room + (s32) (lbl_805DAA78 * temp_f31), lbl_805DAA70, temp_f2) + *(f32 *)((s8 *)arg1 + 0);
    return 1;
}
#pragma pop

void TAdSinglePlyChrSelectGC::transform_vertex_list() {
    f32 v[3];
    s32 stride;
    u32 *p;
    s32 i;
    s32 n;
    s32 kind;
    i = 0;
    p = ((Self_800FFB38 *)this)->list;
    do {
        switch ((u8)p[0]) {
        case 0x29:
            kind = 3;
            break;
        case 0x2C:
            kind = 4;
            break;
        default:
            kind = -1;
            break;
        }
        if (kind < 0) {
            return;
        }
        n = p[1] >> 16;
        stride = (kind + 3) * 4;
        p += 2;
        while (n > 0) {
            v[0] = TAdSinglePlyChrSelectGC__sub_80141EA0(p[0]);
            v[1] = TAdSinglePlyChrSelectGC__sub_80141EA0(p[1]);
            v[2] = TAdSinglePlyChrSelectGC__sub_80141EA0(p[2]);
            if (((TObjPlayer *)this)->interpolate_along_curve(v) != 0) {
                p[0] = TAdSinglePlyChrSelectGC__sub_80141E8C(v[0]);
                p[1] = TAdSinglePlyChrSelectGC__sub_80141E8C(v[1]);
                p[2] = TAdSinglePlyChrSelectGC__sub_80141E8C(v[2]);
            }
            p = (u32 *)((u8 *)p + stride);
            n--;
        }
        i++;
    } while (i < 1000);
}

}
