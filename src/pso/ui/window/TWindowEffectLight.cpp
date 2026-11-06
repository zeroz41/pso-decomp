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

struct Quad_802AD1CC { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

struct Light_802AD1CC { u8 pad0[0x1C]; f32 x; f32 y; };

extern "C" {
s32 __cvt_fp2unsigned(f32);
extern const f32 lbl_805DE0E0;
extern const f32 lbl_805DE0E8;
extern const f32 lbl_805DE0EC;
extern const f32 lbl_805DE0F0;
extern const f32 TWindowEffectLight__data_805DE0E4;
s32 is_split_screen(void);
void TCameraCtrl__sub_80068EF0(void);
s32 is_window_display_enabled(void);
void TWindowEffectLight__sub_802AD040(void *, f32);
void begin_screen_draw(s32);
extern s32 lbl_805D63F0;
extern const f32 lbl_805DE0F4;
extern const f32 lbl_805DE0F8;
extern const f32 lbl_805DE0FC;
extern const f32 lbl_805DE100;
extern const f32 lbl_805DE104;
extern const f32 lbl_805DE108;
extern const f32 lbl_805DE128;
extern const f32 lbl_805DE12C;
extern const f32 lbl_805DE130;
extern s32 lbl_805D3E60;
extern s32 tl_window;
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern const f32 lbl_805DE10C;
extern const f32 lbl_805DE110;
extern const f32 lbl_805DE114;
extern const f32 lbl_805DE118;
extern const f32 lbl_805DE11C;
extern const f32 lbl_805DE120;
extern const f32 lbl_805DE124;


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
          TWindowEffectLight__sub_802AD040(window_effect_light, lbl_805DE0F4);
          break;
        case 4:
          TWindowEffectLight__sub_802AD040(window_effect_light, lbl_805DE128);
          break;
        case 5:
          TWindowEffectLight__sub_802AD040(window_effect_light, lbl_805DE12C);
          break;
        case 6:
          TWindowEffectLight__sub_802AD040(window_effect_light, lbl_805DE130);
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
        s *= lbl_805DE10C;
    }
    set_draw_texture_and_color(2, color);
    q.x0 = ((Light_802AD1CC *)this)->x - lbl_805DE110 * s;
    q.y0 = ((Light_802AD1CC *)this)->y - lbl_805DE114 * s;
    q.x1 = ((Light_802AD1CC *)this)->x + lbl_805DE110 * s;
    q.y1 = ((Light_802AD1CC *)this)->y + lbl_805DE114 * s;
    q.u0 = lbl_805DE118;
    q.v0 = lbl_805DE11C;
    q.u1 = lbl_805DE120;
    q.v1 = lbl_805DE124;
    draw_textured_quad_at_depth((f32 *)&q, TWindowEffectLight__data_805DE0E4);
}

void TWindowEffectLight__sub_802AD040(void *window, f32 f) {
    Quad_802AD1CC q;
    f32 h;
    f32 dx;
    f32 w2;
    f32 x1v;
    f32 x0v;
    f32 new_var;
    f32 vy;
    float new_var3;
    f32 *new_var2;
    s32 color = ((TWindowEffectLight *)window)->calc_alpha() | 0xFFFFFF;
    f32 s = ((TWindowEffectLight *)window)->calc_scale();
    set_draw_texture_and_color(2, color);
    dx = TWindowEffectLight__data_805DE0E4 * (f - lbl_805DE0F4);
    h = lbl_805DE0F8 * s;

    q.x0 = ((Light_802AD1CC *)window)->x - dx - h;
    new_var2 = &((Light_802AD1CC *)window)->x;
    q.y0 = ((Light_802AD1CC *)window)->y - h;
    q.x1 = ((Light_802AD1CC *)window)->x - dx;
    q.y1 = ((Light_802AD1CC *)window)->y + h;
    q.u0 = lbl_805DE0FC;
    q.v0 = TWindowEffectLight__data_805DE0E4;
    q.u1 = lbl_805DE100;
    q.v1 = lbl_805DE104;
    draw_textured_quad_at_depth((f32 *)&q, TWindowEffectLight__data_805DE0E4);

    q.x0 = ((Light_802AD1CC *)window)->x + dx;
    q.y0 = ((Light_802AD1CC *)window)->y - h;
    q.x1 = q.x0 + h;
    q.y1 = ((Light_802AD1CC *)window)->y + h;
    q.u0 = lbl_805DE100;
    q.v0 = TWindowEffectLight__data_805DE0E4;
    q.u1 = lbl_805DE108;
    q.v1 = lbl_805DE104;
    draw_textured_quad_at_depth((f32 *)&q, TWindowEffectLight__data_805DE0E4);

    if (f > lbl_805DE0F4) {
        x0v = (*new_var2) - dx;
        w2 = lbl_805DE100;
        if (((!lbl_805DE100) && (!lbl_805DE100)) && (!lbl_805DE100)) {
        }
        x1v = ((Light_802AD1CC *)window)->x + dx;
        q.x0 = x0v;
        vy = ((Light_802AD1CC *)window)->y;
        q.x1 = x1v;
        new_var = vy - h;
        new_var3 = vy + h;
        if (((!window) && (!window)) && (!window)) {
        }
        q.y0 = new_var;
        q.y1 = new_var3;
        q.u0 = w2;
        q.v0 = TWindowEffectLight__data_805DE0E4;
        q.u1 = w2;
        w2 = lbl_805DE104;
        q.v1 = w2;
        draw_textured_quad_at_depth((f32 *)&q, TWindowEffectLight__data_805DE0E4);
    }
}

u32 TWindowEffectLight::calc_alpha() {
    u8 *arg0 = (u8 *)this;
  float new_var;
  new_var = lbl_805DE0F0 * ((f32) (*((s16 *) (((s8 *) arg0) + 0x26))));
  return (u32)__cvt_fp2unsigned(lbl_805DE0EC * ((new_var * lbl_805DE0E8) + lbl_805DE0E0));
}

f32 TWindowEffectLight::calc_scale() {
    u8 *arg0 = (u8 *)this;
  float new_var2;
  s16 *new_var;
  new_var2 = TWindowEffectLight__data_805DE0E4 * ((f32) (*(new_var = (s16 *) (((s8 *) arg0) + 0x26))));
  return (new_var2 * lbl_805DE0E8) + lbl_805DE0E0;
}

}
