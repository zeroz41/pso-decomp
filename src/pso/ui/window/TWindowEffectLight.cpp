#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowEffectLight.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/render_util.h"

#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

struct Quad_802AD1CC { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

struct Light_802AD1CC { u8 pad0[0x1C]; f32 x; f32 y; };

extern "C" {
s32 __cvt_fp2unsigned(f32);
s32 is_split_screen(void);
void TCameraCtrl__sub_80068EF0(void);
s32 is_window_display_enabled(void);
void TWindowEffectLight__sub_802AD040(void *, f32);
void begin_screen_draw(s32);
extern s32 lbl_805D63F0;
extern s32 lbl_805D3E60;
extern s32 tl_window;
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32 idx, s32 arg1);


}
extern "C" {

void *__nw__7TObjectFUl(int);
s32 queue_destruction__7TObjectFv();

}

#pragma fp_contract on
/* Built with deferred code generation: functions are emitted in reverse source order, and the vtable precedes render's switch table in .data. */
#pragma defer_codegen on

extern "C" {

void *TWindowEffectLight::create(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = ((void *(*)(void *, void *, void *, void *))__ct__18TWindowEffectLightFPvsUl)(o, arg0, arg1, arg2);
    }
    return o;
}

}

TWindowEffectLight::TWindowEffectLight(void *arg1, s16 arg2, u32 id) : TObject((TObject *)tl_window) {
    *(s32 *)((s8 *)this + 0) = lbl_805D3E60;
    ((TWindowSubSymbolChatPartsSet *)(((u8 *)this) + 0x1C))->copy_vec2(arg1);
    ((TWindowKeyBoardSoft *)(((u8 *)this) + 0x1C))->adjust_pos_for_split_screen(TCameraCtrl::get_split_screen_view_index(id));
    *(s16 *)((s8 *)this + 0x24) = arg2;
    *(s16 *)((s8 *)this + 0x26) = -1;
    *(u32 *)((s8 *)this + 0x28) = id;
}

TWindowEffectLight::~TWindowEffectLight() {}

extern "C" {

void run_task__18TWindowEffectLightFv(void *arg0) {
    s32 temp_r4;

    temp_r4 = *(s16 *)((s8 *)arg0 + 0x26) + 1;
    *(s16 *)((s8 *)arg0 + 0x26) = temp_r4;
    if ((s16)temp_r4 >= 8) {
        queue_destruction__7TObjectFv();
    }
}

void render__18TWindowEffectLightFv(u8 *window_effect_light) {
  s16 temp_r0;
  temp_r0 = 0x28;
  if ((is_window_display_enabled() != 0) && ((is_split_screen() == 0) || (((s32) (*((s32 *) (((s8 *) window_effect_light) + temp_r0)))) == ((s32) TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no())))))
  {
    TParticleCtrl::begin_effect_render();
    TCameraCtrl::restore_full_screen_view();
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    temp_r0 = *((s16 *) (((s8 *) window_effect_light) + 0x24));
    {
      switch (temp_r0)
      {
        case 0:
          ((TWindowEffectLight *)window_effect_light)->draw_outline_quad(0xAA0E);
          break;
        case 1:
          ((TWindowEffectLight *)window_effect_light)->draw_outline_quad(0xFF2417);
          break;
        case 2:
          ((TWindowEffectLight *)window_effect_light)->draw_outline_quad(0xFFFFFF);
          break;
        case 3:
          TWindowEffectLight__sub_802AD040(window_effect_light, 20.0f);
          break;
        case 4:
          TWindowEffectLight__sub_802AD040(window_effect_light, 39.0f);
          break;
        case 5:
          TWindowEffectLight__sub_802AD040(window_effect_light, 77.0f);
          break;
        case 6:
          TWindowEffectLight__sub_802AD040(window_effect_light, 191.0f);
          break;
      }
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
    TCameraCtrl__sub_80068EF0();
    TParticleCtrl::end_effect_render();
  }
}

void TWindowEffectLight::draw_outline_quad(s32 color) {
    Quad_802AD1CC q;
    f32 s;
    f32 w;
    f32 h;
    color |= this->calc_alpha();
    s = this->calc_scale();
    if (TCameraCtrl::get_camera_id() <= 2 && TCameraCtrl::get_camera_id() == 2) {
        s *= 0.7f;
    }
    set_draw_texture_and_color(2, color);
    q.x0 = ((Light_802AD1CC *)this)->x - 25.0f * s;
    q.y0 = ((Light_802AD1CC *)this)->y - 21.5f * s;
    q.x1 = ((Light_802AD1CC *)this)->x + 25.0f * s;
    q.y1 = ((Light_802AD1CC *)this)->y + 21.5f * s;
    q.u0 = 0.79296875f;
    q.v0 = 0.60546875f;
    q.u1 = 0.98828125f;
    q.v1 = 0.7734375f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
}

void TWindowEffectLight__sub_802AD040(void *window, f32 f) {
    Quad_802AD1CC q;
    f32 h;
    f32 dx;
    s32 color = ((TWindowEffectLight *)window)->calc_alpha() | 0xFFFFFF;
    f32 s = ((TWindowEffectLight *)window)->calc_scale();
    set_draw_texture_and_color(2, color);
    dx = 0.5f * (f - 20.0f);
    h = 10.0f * s;

    q.x0 = ((Light_802AD1CC *)window)->x - dx - h;
    q.y0 = ((Light_802AD1CC *)window)->y - h;
    q.x1 = ((Light_802AD1CC *)window)->x - dx;
    q.y1 = ((Light_802AD1CC *)window)->y + h;
    q.u0 = 0.9140625f;
    q.v0 = 0.5f;
    q.u1 = 0.953125f;
    q.v1 = 0.578125f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);

    q.x0 = ((Light_802AD1CC *)window)->x + dx;
    q.y0 = ((Light_802AD1CC *)window)->y - h;
    q.x1 = q.x0 + h;
    q.y1 = ((Light_802AD1CC *)window)->y + h;
    q.u0 = 0.953125f;
    q.v0 = 0.5f;
    q.u1 = 0.9921875f;
    q.v1 = 0.578125f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);

    if (f > 20.0f) {
        q.x0 = ((Light_802AD1CC *)window)->x - dx;
        q.y0 = ((Light_802AD1CC *)window)->y - h;
        q.x1 = ((Light_802AD1CC *)window)->x + dx;
        q.y1 = ((Light_802AD1CC *)window)->y + h;
        q.u0 = 0.953125f;
        q.v0 = 0.5f;
        q.u1 = 0.953125f;
        q.v1 = 0.578125f;
        draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    }
}

u32 TWindowEffectLight::calc_alpha() {
    s16 frame = *(s16 *)((u8 *)this + 0x26);
    return (u32)__cvt_fp2unsigned(4278190080.0f * (-1.0f * (f32)frame / 8.0f + 1.0f));
}

f32 TWindowEffectLight::calc_scale() {
    s16 frame = *(s16 *)((u8 *)this + 0x26);
    return 0.5f * (f32)frame / 8.0f + 1.0f;
}

}
