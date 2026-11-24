#include "types.h"
#include "pso/system/scene/TScene_8029F5B0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/scene/TScene.h"
#include "pso/render/GinjaRenderTarget.h"

typedef struct { u8 r, g, b, a; } GXColor_8029F5F8;
extern "C" {
s32 GXPixModeSync();
s32 GXSetTexCopySrc(s32, s32, s32, s32);
s32 GXSetTexCopyDst(s32, s32, s32, s32);
s32 GXSetCopyClear(GXColor_8029F5F8, s32);
s32 GXCopyTex(void *, s32);
s32 GXSetZMode(s32, s32, s32);
s32 GXSetTexCoordGen2(s32, s32, s32, s32, s32, s32);

void fn_8029F5B0(s32 a0, s32 func, s32 a2, s32 mtx) {
    GXSetTexCoordGen2(a0, func, a2, mtx, 0, 0x7D);
}
}

void TScene::end_reflection_pass() { reflection_pass_active = 0; }

void TScene::set_visibility_radius_margin(f32 margin) { visibility_radius_margin = margin; }

void TScene::begin_reflection_pass() { reflection_pass_active = 1; }

void GinjaRenderTarget::copy_efb_to_texture() {
    GXColor_8029F5F8 clr = {0, 0, 0, 0};
    GXSetZMode(0, 7, 1);
    GXSetCopyClear(clr, 0xFFFFFF);
    GXSetTexCopySrc(0, 0, 0x280, 0x1E0);
    GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
    GXCopyTex(texture_list.textures->texture->surface->header.pixels, 1);
    GXPixModeSync();
}
