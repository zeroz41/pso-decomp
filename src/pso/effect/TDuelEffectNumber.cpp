#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/effect/TDuelEffectNumber.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"

extern "C" {
}

const char *TDuelEffectNumber::class_name = "TDuelEffectNumber";

// Texel origin of each digit's 64x85 cell in the duel texture.
extern const f32 duel_number_uv_table[6][2] = {
    { 0.0f, 170.0f }, { 0.0f, 0.0f }, { 64.0f, 0.0f }, { 128.0f, 0.0f }, { 192.0f, 0.0f }, { 0.0f, 85.0f },
};

void TDuelEffectNumber::draw_digit_quad(QuadSpriteRect *quad, f32 *center, f32 depth, f32 scale, f32 alpha) {
    scale *= 0.5;
    quad->x0 = center[0] - 64.0f * scale;
    quad->y0 = center[1] - 85.0f * scale;
    quad->x1 = center[0] + 64.0f * scale;
    quad->y1 = center[1] + 85.0f * scale;
    set_constant_material_color((u32)(4278190080.0f * alpha) | 0xFF0000 | 0xFFFF);
    draw_textured_quad_at_depth(&quad->x0, depth);
}

#pragma push
#pragma fp_contract on
void TDuelEffectNumber::draw_echo(QuadSpriteRect *quad) {
    f32 depth;
    f32 scale;
    f32 half;

    if (timer >= 5 && timer < 20) {
        TCameraCtrl::get_camera_no();
        depth = -1.0f / TWindowCtrlMain::get_scale();
        half = 0.5f;
        scale = half * ((timer - 5) / 15.0f) + 1.0f;
        draw_digit_quad(quad, pos, depth, scale, timer < 10 ? half : half - half * ((timer - 10) / 10.0f));
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TDuelEffectNumber::draw_digit(QuadSpriteRect *quad) {
    f32 depth;
    f32 scale;
    f32 alpha;

    TCameraCtrl::get_camera_no();
    depth = -1.0f / TWindowCtrlMain::get_scale();
    if (timer < 5) {
        scale = 2.0f - ((f32)timer / 5.0f);
        alpha = 0.5f;
        alpha = alpha * (f32)(timer / 5) + alpha;
    } else if (timer < 25) {
        alpha = scale = 1.0f;
    } else {
        scale = 1.0f;
        alpha = scale - ((f32)(timer - 25) / 5.0f);
    }
    draw_digit_quad(quad, pos, depth, scale, alpha);
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TDuelEffectNumber::calc_digit_uv(QuadSpriteRect *quad, s32 index) {
    quad->u0 = duel_number_uv_table[index][0];
    quad->v0 = duel_number_uv_table[index][1];
    quad->u1 = 64.0f + quad->u0;
    quad->v1 = 85.0f + quad->v0;
    quad->u0 *= 0.00390625f;
    quad->v0 *= 0.00390625f;
    quad->u1 *= 0.00390625f;
    quad->v1 *= 0.00390625f;
}
#pragma pop

void TDuelEffectNumber::render() {
    QuadSpriteRect quad;

    calc_digit_uv(&quad, digit);
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(6, -1);
    draw_digit(&quad);
    draw_echo(&quad);
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}

void TDuelEffectNumber::run_task() {
    timer++;
    if ((f32)timer >= 30.0f) {
        queue_destruction();
    }
}

TDuelEffectNumber::~TDuelEffectNumber() {}

TDuelEffectNumber::TDuelEffectNumber(TObject *parent, f32 *screen_pos, s32 digit_value) : TObject(parent) {
    m_name = class_name;
    pos[0] = screen_pos[0];
    pos[1] = screen_pos[1];
    digit = digit_value;
    timer = 0;
}
