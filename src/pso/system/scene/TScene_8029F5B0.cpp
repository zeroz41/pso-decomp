#include "types.h"
#include "pso/system/scene/TScene_8029F5B0.h"
#include "pso/player/TObjPlayer.h"

typedef struct { u8 r, g, b, a; } GXColor_8029F5F8;
extern "C" {
extern f32 TScene__visibility_radius_margin;
s32 GXPixModeSync();
s32 GXSetTexCopySrc(s32, s32, s32, s32);
s32 GXSetTexCopyDst(s32, s32, s32, s32);
s32 GXSetCopyClear(GXColor_8029F5F8, s32);
s32 GXCopyTex(s32, s32);
s32 GXSetZMode(s32, s32, s32);
extern GXColor_8029F5F8 lbl_805E1220;
s32 GXSetTexCoordGen2(s32, s32, s32, s32, s32, s32);

void fn_8029F5B0(s32 a0, s32 a1, s32 a2, s32 a3) {
    GXSetTexCoordGen2(a0, a1, a2, a3, 0, 0x7D);
}

    extern int TScene__data_805D5FE0;
void TScene__sub_8029F5D8(void) { TScene__data_805D5FE0 = 0; }

void TScene__sub_8029F5E4(f32 farg0) {
    TScene__visibility_radius_margin = farg0;
}

void TScene__sub_8029F5EC(void) { TScene__data_805D5FE0 = 1; }
void TObjPlayer::copy_efb_to_texture() {
    GXColor_8029F5F8 clr = lbl_805E1220;
    GXSetZMode(0, 7, 1);
    GXSetCopyClear(clr, 0xFFFFFF);
    GXSetTexCopySrc(0, 0, 0x280, 0x1E0);
    GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
    GXCopyTex(*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this + 0x1C)) + 8)) + 0xC)) + 0x20), 1);
    GXPixModeSync();
}

}
