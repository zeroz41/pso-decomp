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

void fn_802AEAA4(SelCurSprites *o, s32 frame) {
    s32 i;
    for (i = 0; i < o->count; i++) {
        switch (((TAdSinglePlyChrSelectGC *)o)->get_selected_slot()) {
        case 0:
            o->frame[i].u0 = 0.0625f;
            o->frame[i].v0 = 0.875f;
            o->frame[i].u1 = 0.125f;
            o->frame[i].v1 = 0.9453125f;
            o->left[i].u0 = 0.0f;
            o->left[i].v0 = 0.875f;
            o->left[i].u1 = 0.0625f;
            o->left[i].v1 = 0.9453125f;
            o->right[i].u0 = 0.125f;
            o->right[i].v0 = 0.875f;
            o->right[i].u1 = 0.1875f;
            o->right[i].v1 = 0.9453125f;
            break;
        case 1:
            o->frame[i].u0 = 0.25390625f;
            o->frame[i].v0 = 0.875f;
            o->frame[i].u1 = 0.31640625f;
            o->frame[i].v1 = 0.9453125f;
            o->left[i].u0 = 0.19140625f;
            o->left[i].v0 = 0.875f;
            o->left[i].u1 = 0.25390625f;
            o->left[i].v1 = 0.9453125f;
            o->right[i].u0 = 0.31640625f;
            o->right[i].v0 = 0.875f;
            o->right[i].u1 = 0.37890625f;
            o->right[i].v1 = 0.9453125f;
            break;
        }
    }
}
}
