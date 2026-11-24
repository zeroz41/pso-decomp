#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/TWindowEffectLight.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/WindowDrawContext.h"

#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

#pragma readonly_strings on

extern "C" {
s32 __cvt_fp2unsigned(f32);
const char *TWindowEffectLight__name = "TWindowEffectLight";
extern saddr tl_window;


#pragma fp_contract on
/* Built with deferred code generation: functions are emitted in reverse source order, and the vtable precedes render's switch table in .data. */
#pragma defer_codegen on
void *TWindowEffectLight::create(void *position, s16 effect_kind, u32 player_id) {
    return new TWindowEffectLight(position, effect_kind, player_id);
}

}

TWindowEffectLight::TWindowEffectLight(void *position, s16 arg2, u32 id) : TObject((TObject *)tl_window) {
    this->m_name = TWindowEffectLight__name;
    copy_vec2(&x, position);
    WindowDrawContext::adjust_pos_for_split_screen(reinterpret_cast<NJS_POINT2 *>(&x), TCameraCtrl::get_split_screen_view_index(id));
    effect_kind = arg2;
    age = -1;
    player_id = id;
}

TWindowEffectLight::~TWindowEffectLight() {}


void TWindowEffectLight::run_task() {
    if (++this->age >= 8) {
        queue_destruction();
    }
}

void TWindowEffectLight::render() {
  if ((is_window_display_enabled() != 0) && ((is_split_screen() == 0) || ((s32)this->player_id == (s32)TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no()))))
  {
    TParticleCtrl::begin_effect_render();
    TCameraCtrl::restore_full_screen_view();
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    {
      switch (this->effect_kind)
      {
        case 0:
          draw_outline_quad(0xAA0E);
          break;
        case 1:
          draw_outline_quad(0xFF2417);
          break;
        case 2:
          draw_outline_quad(0xFFFFFF);
          break;
        case 3:
          sub_802AD040(20.0f);
          break;
        case 4:
          sub_802AD040(39.0f);
          break;
        case 5:
          sub_802AD040(77.0f);
          break;
        case 6:
          sub_802AD040(191.0f);
          break;
      }
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
    TCameraCtrl::restore_saved_view();
    TParticleCtrl::end_effect_render();
  }
}

void TWindowEffectLight::draw_outline_quad(s32 color) {
    TexturedQuad q;
    f32 s;
    f32 w;
    f32 h;
    color |= this->calc_alpha();
    s = this->calc_scale();
    if (TCameraCtrl::get_camera_id() <= 2 && TCameraCtrl::get_camera_id() == 2) {
        s *= 0.7f;
    }
    set_draw_texture_and_color(2, color);
    q.x0 = x - 25.0f * s;
    q.y0 = y - 21.5f * s;
    q.x1 = x + 25.0f * s;
    q.y1 = y + 21.5f * s;
    q.u0 = 0.79296875f;
    q.v0 = 0.60546875f;
    q.u1 = 0.98828125f;
    q.v1 = 0.7734375f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
}

void TWindowEffectLight::sub_802AD040(f32 f) {
    TexturedQuad q;
    f32 h;
    f32 dx;
    s32 color = ((TWindowEffectLight *)this)->calc_alpha() | 0xFFFFFF;
    f32 s = ((TWindowEffectLight *)this)->calc_scale();
    set_draw_texture_and_color(2, color);
    dx = 0.5f * (f - 20.0f);
    h = 10.0f * s;

    q.x0 = x - dx - h;
    q.y0 = y - h;
    q.x1 = x - dx;
    q.y1 = y + h;
    q.u0 = 0.9140625f;
    q.v0 = 0.5f;
    q.u1 = 0.953125f;
    q.v1 = 0.578125f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);

    q.x0 = x + dx;
    q.y0 = y - h;
    q.x1 = q.x0 + h;
    q.y1 = y + h;
    q.u0 = 0.953125f;
    q.v0 = 0.5f;
    q.u1 = 0.9921875f;
    q.v1 = 0.578125f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);

    if (f > 20.0f) {
        q.x0 = x - dx;
        q.y0 = y - h;
        q.x1 = x + dx;
        q.y1 = y + h;
        q.u0 = 0.953125f;
        q.v0 = 0.5f;
        q.u1 = 0.953125f;
        q.v1 = 0.578125f;
        draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    }
}

u32 TWindowEffectLight::calc_alpha() {
    s16 frame = this->age;
    return (u32)__cvt_fp2unsigned(4278190080.0f * (-1.0f * (f32)frame / 8.0f + 1.0f));
}

f32 TWindowEffectLight::calc_scale() {
    s16 frame = this->age;
    return 0.5f * (f32)frame / 8.0f + 1.0f;
}

