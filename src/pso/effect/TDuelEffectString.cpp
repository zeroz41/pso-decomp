#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include <math.h>
#include "types.h"
#include "pso/effect/TDuelEffectString.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/sprite/TQuadSprite.h"

extern "C" {
}

const char *TDuelEffectString::class_name = "TDuelEffectString";

extern const DuelEffectQuad duel_start_banner_layout = { -96.0f, -24.0f, 192.0f, 48.0f, 64.0f, 133.0f };
extern const DuelEffectQuad duel_end_banner_layout[2] = {
    { -121.0f, -24.0f, 192.0f, 48.0f, 64.0f, 85.0f },
    { 37.0f, -24.0f, 192.0f, 48.0f, 64.0f, 181.0f },
};

void TDuelEffectString::draw_layout_quad(const DuelEffectQuad *quad, f32 scale) {
    QuadSpriteRect rect;
    f32 depth;

    TCameraCtrl::get_camera_no();
    depth = -1.0f / TWindowCtrlMain::get_scale();
    rect.x0 = quad->x * scale + pos[0];
    rect.y0 = quad->y * scale + pos[1];
    rect.x1 = scale * (quad->x + quad->w) + pos[0];
    rect.y1 = scale * (quad->y + quad->h) + pos[1];
    rect.u0 = quad->u;
    rect.v0 = quad->v;
    rect.u1 = quad->u + quad->w;
    rect.v1 = quad->v + quad->h;
    rect.u0 *= 0.00390625f;
    rect.v0 *= 0.00390625f;
    rect.u1 *= 0.00390625f;
    rect.v1 *= 0.00390625f;
    draw_textured_quad_at_depth(&rect.x0, depth);
}

void TDuelEffectString::render_end_banner(f32 scale) {
    s32 i;
    for (i = 0; i < 2; i++) {
        draw_layout_quad(&duel_end_banner_layout[i], scale);
    }
}

void TDuelEffectString::render_start_banner(f32 scale) {
    draw_layout_quad(&duel_start_banner_layout, scale);
}

void TDuelEffectString::calc_scale_and_alpha(f32 *scale, f32 *alpha, s32 time) {
    if (time < 10) {
        *scale = 2.5f - 1.5f * ((f32)time / 10.0f);
    } else {
        *scale = 1.0f + 0.2f * ((time - 10) / 20.0f);
    }
    if (time < 5) {
        *alpha = (f32)(time / 5);
        return;
    }
    *alpha = 1.0f - ((time - 5) / 25.0f);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TDuelEffectString::render() {
    f32 scale;
    f32 alpha;
    s32 color;

    calc_scale_and_alpha(&scale, &alpha, timer);
    color = (u32)(4278190080.0f * alpha) | 0xFF0000 | 0xFFFF;
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(6, color);
    switch (kind) {
    case 0:
        render_start_banner(scale);
        break;
    case 1:
        render_end_banner(scale);
        break;
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TDuelEffectString::run_task() {
    timer++;
    if (timer >= 30.0f) {
        queue_destruction();
    }
}

TDuelEffectString::~TDuelEffectString() {}

TDuelEffectString::TDuelEffectString(TObject *parent, f32 *screen_pos, s32 banner_kind) : TObject(parent) {
    m_name = class_name;
    pos[0] = screen_pos[0];
    pos[1] = screen_pos[1];
    kind = banner_kind;
    timer = 0;
}

f32 pow(f32 x, f32 y) {
    return (f32)pow((f64)x, (f64)y);
}
