#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct SelCurSpriteUV {
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    u8 pad10[0x10];
};

struct SelCurSprites {
    u8 pad0[0xA8];
    s32 count;
    u8 padAC[0xCC - 0xAC];
    SelCurSpriteUV frame[16];
    SelCurSpriteUV left[16];
    SelCurSpriteUV right[16];
};

extern "C" {
extern const f32 lbl_805DE1B0; /* 0.0625 */
extern const f32 lbl_805DE1B4; /* 0.875 */
extern const f32 lbl_805DE1B8; /* 0.125 */
extern const f32 lbl_805DE1BC; /* 0.9453125 */
extern const f32 lbl_805DE1C0; /* 0.0 */
extern const f32 lbl_805DE1C4; /* 0.1875 */
extern const f32 lbl_805DE1C8; /* 0.25390625 */
extern const f32 lbl_805DE1CC; /* 0.31640625 */
extern const f32 lbl_805DE1D0; /* 0.19140625 */
extern const f32 lbl_805DE1D4; /* 0.37890625 */

void fn_802AEAA4(SelCurSprites *o, s32 frame) {
    s32 i;
    for (i = 0; i < o->count; i++) {
        switch (((TAdSinglePlyChrSelectGC *)o)->get_selected_slot()) {
        case 0:
            o->frame[i].u0 = lbl_805DE1B0;
            o->frame[i].v0 = lbl_805DE1B4;
            o->frame[i].u1 = lbl_805DE1B8;
            o->frame[i].v1 = lbl_805DE1BC;
            o->left[i].u0 = lbl_805DE1C0;
            o->left[i].v0 = lbl_805DE1B4;
            o->left[i].u1 = lbl_805DE1B0;
            o->left[i].v1 = lbl_805DE1BC;
            o->right[i].u0 = lbl_805DE1B8;
            o->right[i].v0 = lbl_805DE1B4;
            o->right[i].u1 = lbl_805DE1C4;
            o->right[i].v1 = lbl_805DE1BC;
            break;
        case 1:
            o->frame[i].u0 = lbl_805DE1C8;
            o->frame[i].v0 = lbl_805DE1B4;
            o->frame[i].u1 = lbl_805DE1CC;
            o->frame[i].v1 = lbl_805DE1BC;
            o->left[i].u0 = lbl_805DE1D0;
            o->left[i].v0 = lbl_805DE1B4;
            o->left[i].u1 = lbl_805DE1C8;
            o->left[i].v1 = lbl_805DE1BC;
            o->right[i].u0 = lbl_805DE1CC;
            o->right[i].v0 = lbl_805DE1B4;
            o->right[i].u1 = lbl_805DE1D4;
            o->right[i].v1 = lbl_805DE1BC;
            break;
        }
    }
}
}
