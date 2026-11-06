#ifndef PSO_UI_UI_SPRITE_H
#define PSO_UI_UI_SPRITE_H
#include "types.h"
#include "pso/ui/UISpriteConstants.h"
#include "pso/math/TMath.h"

struct UISpriteTint {
    f32 alpha;
    f32 channels[3];
};

extern "C" {
void draw_ui_sprite_tinted(s32 sprite_id, const vec2f* position, const vec2f* scale,
                          const UISpriteTint* tint, f32 depth);
void draw_ui_sprite_shaded(s32 sprite_id, const vec2f* position, const vec2f* scale,
                          f32 depth, f32 alpha, f32 brightness);
void draw_ui_sprite_scaled(s32 sprite_id, const vec2f* position, const vec2f* scale,
                          f32 depth, f32 alpha);
void draw_ui_sprite_opaque(s32 sprite_id, const vec2f* position, const vec2f* scale,
                           f32 depth);
void draw_ui_sprite(s32 sprite_id, const vec2f* position, f32 depth, f32 alpha);
}

#include <stddef.h>
typedef char UISpriteTintSize[(sizeof(UISpriteTint) == 0x10) ? 1 : -1];
typedef char UISpriteTintAlphaOffset[(offsetof(UISpriteTint, alpha) == 0) ? 1 : -1];
typedef char UISpriteScaleSize[(sizeof(vec2f) == 8) ? 1 : -1];
#endif
