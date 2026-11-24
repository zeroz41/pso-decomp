#include "pso/effect/sprite/TQuadSpriteSclColRot.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/TObjChara.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowSubStatusDisp_800FBD74.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include <string.h>
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet_80247EFC.h"

struct Fuki_80250A24 {
    u8 pad0[0x38];
    f32 size[2];
    u8 pad40[0x48 - 0x40];
    f32 rsize[2];
    u8 pad50[0x90 - 0x50];
    f32 center[2];
};

struct Fuki_802506E8 {
    u8 pad0[0x38];
    f32 size[2];
    u8 pad40[0x48 - 0x40];
    f32 rsize[2];
    u8 pad50[0x90 - 0x50];
    f32 center[2];
};
extern "C" {
f32 * get_message_by_type__11TWindowCtrlFScl(u8, int);
int rand(void);
f32 xyz_distance(void *, void *);
s32 rest_balloon__15TWindowFukidasiFv(Fuki_80250A24 *b, f32 *rect, f32 *arg2);
s32 try_place_bubble__15TWindowFukidasiFPvPvPv(Fuki_802506E8 *b, f32 *rect, f32 *o);
struct Entry_80250380 { u8 pad[0x10]; f32 w; f32 h; };
struct Fuki_80250380 { u8 pad[0x24]; u8 entries[0x4C]; u8 phase; u8 options; u8 kind; };
struct Fuki_80250314 { u8 pad[0x38]; f32 anchor[2]; };

struct Fuki_80250F70 {
    u8 pad0[0x38]; f32 anchor[2];
    u8 pad40[0x50];
    f32 head[2];
};

struct Fuki_802504C0 {
    u8 pad0[0x20]; s16 viewport; u8 pad22[0xE];
    f32 rect[2]; f32 anchor[2];
    u8 pad40[0x30];
    u8 phase; u8 options; u8 kind; u8 slot;
};

struct Fuki_80250F70;
struct Fuki_802504C0;

struct Fuki_80251028 {
    u8 pad0[0x20]; s16 viewport; u8 pad22[0xE];
    f32 rect[2]; f32 anchor[2];
    u8 pad40[0x30];
    u8 phase; u8 options; u8 kind; u8 slot;
};

struct Fuki_80251380 {
    u8 pad0[0x20];
    s16 viewport;
};



struct Fuki_802511E4 {
    u8 pad0[0x76];
    u16 id;
    u8 pad78[4];
    f32 height;
};

struct Ent_802511E4 {
    u8 pad0[0x38];
    f32 pos[3];
};

struct Fuki_80251594 {
    u8 pad0[0x30];
    f32 rect[2];
    f32 anchor[2];
    f32 pos[2];
    f32 size[2];
    u32 steps;
    u8 pad54[0x71 - 0x54];
    u8 options;
    u8 pad72[0x80 - 0x72];
    f32 margin;
    u8 pad84[4];
    f32 center[2];
    f32 head[2];
};

Ent_802511E4 * find_entity_by_id(u16);
void TWindowSubSymbolChat__sub_802483F0(int a0, void *a1);
s32 draw_resolved_window__15TWindowFukidasiFllll(Fuki_80250F70 *, f32 *, f32 *, s32);
}

void complete_speech_balloon(u8 *arg0);
s32 is_speech_balloon_ready(u8 *window_base);
extern "C" {
void clamp_text_size__15TWindowFukidasiFPvPv(Fuki_80250314 *b, f32 *out);
s32 TWindowFukidasi__sub_802505C0(Fuki_80251028 *b, f32 *rect, f32 *out);
s32 shift_rect_with_head__15TWindowFukidasiFPvPvPv(Fuki_80250F70 *b, f32 *rect, f32 *out);
void refresh_rect_placement__15TWindowFukidasiFPv(Fuki_80251028 *b);
void set_text__15TWindowFukidasiFPvii(u8 *arg0, saddr arg1, saddr arg2);
void TWindowFukidasi__sub_80252C38(void *p);
s32 fn_80252CBC(void);
s32 reset_float_field__15TWindowHelpItemFv();
s32 measure_message_text_width(int, f32);
}

void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
extern "C" {
f32 vec3_dot(void *, void *);
void project_world_to_screen(s32, f32 *, f32 *);
void rotate_vector_by_matrix(saddr, void *, void *);
void rotate_matrix_y(s32, s32);
void rotate_matrix_z(s32, s32);
void rotate_matrix_x(s32, s32);
__declspec(section ".rodata") extern const char TWindowFukidasi__class_name_string[] = "TWindowFukidasi";
}

extern const u32 TWindowFukidasi__balloon_color_table[16] = {
    0xFFFFC8C8, 0xFFA2FF9D, 0xFFFBFFB5, 0xFFB0F8FF, 0xFFD1ADFF, 0xFFFFBF7C, 0xFFA5B6FB, 0xFFFFB99C,
    0xFF90D29B, 0xFF8BB5EE, 0xFFFFB5DA, 0xFFFFFF8C, 0xFFE6E8CA, 0xFFDEFFBD, 0xFFC6C2FF, 0xFFFFE1EB,
};

extern const Vec fukidasi_forward_vec = {0.0f, 0.0f, -1.0f};
struct WindowFukidasiLayoutEntries { s32 value; u32 remaining[8]; };
WindowFukidasiLayoutEntries window_fukidasi_layout_entries = {1, {1, 3, 0, 0, 0x3F000000, 0xFFFFFFFF, 0, 0}};
u32 window_fukidasi_addition_params[5] = {0, 0, 0x476A6000, 0, 0x7023};
extern u8 identity_matrix[];
const char *window_fukidasi_class_name = TWindowFukidasi__class_name_string;

#define F70_80250A24 ((Fuki_80250F70 *)b)
#define CLAMP_80250A24 ((s32 (*)(Fuki_80250F70 *, f32 *, f32))clamp_position__15TWindowFukidasiFPvf)
#define F70_802506E8 ((Fuki_80250F70 *)b)
#define CLAMP_802506E8 ((s32 (*)(Fuki_80250F70 *, f32 *, f32))clamp_position__15TWindowFukidasiFPvf)
extern "C" {
struct Fuki_80251790 {
    u8 pad0[0x20];
    s16 card_slot;
    u8 pad22[0x2C - 0x22];
    u32 flags;
    u8 pad30[0x5C - 0x30];
    s32 frame;
};

saddr get_zero_vec2();
}

void TWindowFukidasi::clear_flag2c_bit100() { this->window_flags &= 0xfffffeff; }

void TWindowFukidasi::set_flag2c_bit200() { this->window_flags |= 0x200; }

void TWindowFukidasi::clear_flag2c_bit200() { this->window_flags &= 0xfffffdff; }

void TWindowFukidasi::set_flag2c_bit100() { this->window_flags |= 0x100; }
extern "C" {
TWindowFukidasi::TWindowFukidasi(u16 speaker, s32 text, s32 client, f32 scale)
    : TWindowAddition((u8 *)window_fukidasi_addition_params, (s16)client, (u8 *)get_zero_vec2()) {
    init_balloon(speaker, text, client, scale);
}
}

TWindowFukidasi::~TWindowFukidasi() {
    if (this->is_flag_set() != 0) {
        this->clear_visible_flag();
        TWindowCtrl::release_slot((s8 *)&this->m_73);
    }
    if ((uaddr)this->name != 0U) {
        mem_free(this->name);
        this->name = 0;
    }
}

void TWindowFukidasi::run_task() {
    u8 *arg0 = (u8 *)this;
  switch (*((u8 *) (((s8 *) arg0) + 0x70)))
  {
    case 1:
      ((TWindowFukidasi *)arg0)->calc_text_size(&this->target_size[0]);
      *((s32 *) (((s8 *) arg0) + 0x50)) = 6;
      ((TWindowFukidasi *)arg0)->clear_flag();
      ((TWindowFukidasi *)arg0)->set_flag2c_bit100();
      *((u8 *) (((s8 *) arg0) + 0x70)) = 2U;
    case 2:
      if (((TWindowFukidasi *)arg0)->approach(1.0f) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 3U;
    }
      ((TWindowFukidasi *)arg0)->sync_display_pos();
      break;
    case 3:
      TWindowFukidasi__sub_80252C38(arg0);
      ((TWindowFukidasi *)arg0)->set_flag2c_bit100();
      *((u8 *) (((s8 *) arg0) + 0x70)) = 4U;
    case 4:
      if ((*((u8 *) (((s8 *) arg0) + 0x71))) & 8)
    {
      *((s16 *) (((s8 *) arg0) + 0x74)) = (s16) ((*((s16 *) (((s8 *) arg0) + 0x74))) - 1);
      *((f32 *) (((s8 *) arg0) + 0x58)) += 0.1f;
      this->sort_depth += 0.1f;
      if ((*((s16 *) (((s8 *) arg0) + 0x74))) < 0)
      {
        *((u8 *) (((s8 *) arg0) + 0x70)) = 7U;
      }
    }
      break;
    case 5:
      ((void (*)(void *, void *))clamp_text_size__15TWindowFukidasiFPvPv)(arg0, ((u8 *) arg0) + 0x38);
      *((s32 *) (((s8 *) arg0) + 0x50)) = 6;
      ((TWindowFukidasi *)arg0)->clear_flag();
      ((TWindowFukidasi *)arg0)->set_flag2c_bit100();
      *((u8 *) (((s8 *) arg0) + 0x70)) = 6U;
    case 6:
      if (((TWindowFukidasi *)arg0)->approach(0.5f) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 1U;
    }
      ((TWindowFukidasi *)arg0)->sync_display_pos();
      break;
    case 7:
      ((TWindowFukidasi *)arg0)->clear_flag();
      ((TWindowFukidasi *)arg0)->clear_flag2c_bit100();
      this->window_flags = (s32) ((this->window_flags) & 0xFFFFFFFE);
      *((u8 *) (((s8 *) arg0) + 0x71)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x71))) | 0x10);
      *((u8 *) (((s8 *) arg0) + 0x70)) = 8U;
    case 8:
      if (((TWindowFukidasi *)arg0)->approach(0.0f) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 9U;
    }
      ((TWindowFukidasi *)arg0)->sync_display_pos();
      break;
    case 9:
      ((TObject *)arg0)->queue_destruction();
      break;
  }
  ((TWindowFukidasi *)arg0)->update_reveal_timer();
  if (((TWindowFukidasi *)arg0)->is_active() != 0)
  {
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(((u8 *) arg0) + 0x24));
  }
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::render() {
    f32 off[2];
    WindowDrawContext *v;
    switch (static_cast<u8>(m_70)) {
    case 0:
        project_anchor(NULL, head_position);
        this->place_rect_at_head_or_slot();
        balloon_center[0] = 0.5f * target_size[0] + target_position[0];
        balloon_center[1] = 0.5f * target_size[1] + target_position[1];
        m_70 = 1;
        break;
    case 2:
        ((void (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(this);
        break;
    case 4:
        ((void (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(this);
        break;
    case 6:
        ((void (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(this);
        break;
    case 8:
        this->place_rect_at_head_or_slot();
        break;
    case 9:
        break;
    }
    follow_anchor();
    v = get_draw_context();
    v->scale[0] /= TCameraCtrl::get_view_scale();
    v->scale[1] /= TCameraCtrl::get_fov();
    off[0] = 3.0f * tail_scale;
    off[1] = 2.5f * tail_scale;
    draw_body(v, (u32)(0xFF000000), off, 0.0299f + draw_depth);
    draw_tail(v, (u32)(0xFF000000), off, 0.01495f + draw_depth);
    off[0] = 0.0f;
    off[1] = 0.0f;
    draw_body(v, static_cast<u32>(balloon_color), off, 0.01495f + draw_depth);
    draw_tail(v, static_cast<u32>(balloon_color), off, 0.04485f + draw_depth);
    if (is_active() != 0) {
        draw_visible_window_entries(
            this,
            &entry_list,
            v);
        draw_name_plate(v, static_cast<u32>(balloon_color));
    }
}

void TWindowFukidasi::draw_body(WindowDrawContext *context, u32 argb, f32 *offset, f32 depth) {
    RotatedQuadSpriteRect s;
    f32 width;
    f32 capY;
    f32 mid;
    f32 d;
    f32 t;
    width = frame_size[0] + 0.342f * frame_size[1];
    s.edge_a_y = 0.0f;
    s.edge_a_v = 0.0f;
    s.edge_b_u = 0.0f;
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(1, argb);
    if (frame_size[1] < 64.0f) {
        capY = 0.5f * frame_size[1];
    } else {
        capY = 32.0f;
    }
    s.depth = -1.0f / depth;
    s.y = frame_position[1] + offset[1];
    s.edge_b_y = capY;
    s.v = 0.0f;
    s.edge_b_v = capY / 256.0f;
    s.y = context->pivot[1] + context->scale[1] * (s.y - context->pivot[1]);
    s.edge_b_y *= context->scale[1];
    draw_body_row(&s, context, offset[0], 0.0f, width, capY);
    s.y = (frame_size[1] + (frame_position[1] + offset[1])) - capY;
    s.y = context->pivot[1] + context->scale[1] * (s.y - context->pivot[1]);
    t = 96.0f - capY;
    s.v = t / 256.0f;
    draw_body_row(&s, context, offset[0], frame_size[1] - capY, width, capY);
    d = frame_size[1] - 64.0f;
    mid = d * context->scale[1];
    if (mid >= 0.0f) {
        f32 y = 32.0f + frame_position[1];
        s.y = y + offset[1];
        s.y = context->pivot[1] + context->scale[1] * (s.y - context->pivot[1]);
        s.v = 0.125f;
        s.edge_b_y = mid;
        draw_body_row(&s, context, offset[0], 32.0f, width, d);
    }
    TWindowSubStatusDisp::get_player();
}

void TWindowFukidasi::draw_body_row(RotatedQuadSpriteRect *slice, WindowDrawContext *context, f32 offsetX, f32 rowTop, f32 fullWidth, f32 rowHeight) {
    f32 left;
    f32 cap;
    f32 w;

    if (fullWidth < 64.0f) {
        cap = 0.5f * fullWidth;
    } else {
        cap = 32.0f;
    }
    left = offsetX + (frame_position[0] - 0.342f * rowTop);

    slice->x = left;
    slice->edge_a_x = cap;
    slice->edge_b_x = 0.342f * -rowHeight;
    slice->u = 0.3828125f;
    slice->edge_a_u = cap / 256.0f;
    slice->x = context->pivot[0] + context->scale[0] * (slice->x - context->pivot[0]);
    slice->edge_a_x *= context->scale[0];
    slice->edge_b_x *= context->scale[0];
    DVDConvertEntrynumToPath(&slice->x);
    slice->x = left + fullWidth - cap;
    slice->x = context->pivot[0] + context->scale[0] * (slice->x - context->pivot[0]);
    slice->u = (194.0f - cap) / 256.0f;
    DVDConvertEntrynumToPath(&slice->x);
    w = (fullWidth - 64.0f) * context->scale[0];
    if (w >= 0.0f) {
        slice->x = 32.0f + left;
        slice->x = context->pivot[0] + context->scale[0] * (slice->x - context->pivot[0]);
        slice->edge_a_x = w;
        slice->u = 0.5078125f;
        DVDConvertEntrynumToPath(&slice->x);
    }
}

void TWindowFukidasi::draw_tail(WindowDrawContext *context, u32 color, f32 *off, f32 depth) {
    NJS_POINT2 verts[3];
    f32 pos[3];
    NJS_POINT2COL prim;
    NJS_COLOR colors[3];
    f32 scr[2];
    f32 cx;
    f32 cy;
    f32 x0;
    f32 s;
    f32 y0;
    s32 angle;
    if (this->is_balloon_visible() != 0) {
        this->project_anchor(pos, scr);
        cx = balloon_center[0];
        cy = balloon_center[1];
        angle = 10430.38043493439 * atan2_float(cy - scr[1], cx - scr[0]);
        s = 1000.0f / xyz_distance(&camera_ctrl_instance->pos, pos);
        x0 = s * cos_table_lookup(angle) + scr[0];
        y0 = s * sin_table_lookup(angle) + scr[1];
        prim.p = verts;
        prim.tex = NULL;
        prim.col = colors;
        prim.num = 3;
        colors[2].color = colors[1].color = colors[0].color = (color << 8) | (color >> 24);
        verts[0].x = x0;
        verts[0].y = y0;
        verts[1].x = off[0] + (tail_scale * (12.0f * cos_table_lookup(angle + 0x4000)) + cx);
        verts[1].y = off[1] + (tail_scale * (12.0f * sin_table_lookup(angle + 0x4000)) + cy);
        verts[2].x = off[0] + (tail_scale * (12.0f * cos_table_lookup(angle - 0x4000)) + cx);
        verts[2].y = off[1] + (tail_scale * (12.0f * sin_table_lookup(angle - 0x4000)) + cy);
        draw_polygon_2d(&prim, 3, 2, 0.04485f + draw_depth);
    }
}

#pragma pop
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
extern "C" {
void TWindowFukidasi::draw_name_plate(WindowDrawContext *context, u32 argb) {
  f32 pos[2];
  TexturedQuad q;
  f32 scale;
  f32 textW;
  s32 alpha;
  s32 alphaBits;
  s32 color;
  f32 new_var;
  char *name_text;
  name_text = name;
  if ((name_text != 0) && (context->open_tick >= 0))
  {
    textW = (f32) ((u32) get_name_text_width(name_text));
    if (context->open_tick < 6)
    {
      alpha = (s32) (0.16666667f * ((f32) ((s32) (context->open_tick * 0xFF))));
    }
    else
    {
      alpha = 0xFF;
    }
    alphaBits = alpha << 24;
    color = argb & 0xffffff;
    color |= alphaBits & 0xff000000;
    pos[0] = context->x - 11.0f;
    pos[1] = context->y - 10.0f;
    scale = -1.0f / (0.0598f + context->depth);
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, color);
    q.x0 = pos[0];
    q.y0 = pos[1];
    q.x1 = 16.0f + q.x0;
    q.y1 = 19.0f + q.y0;
    q.u0 = 0.56640625f;
    q.v0 = 0.92578125f;
    q.u1 = 0.62890625f;
    q.v1 = 1.0f;
    context->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, scale);
    if (textW < 20.0f)
    {
      q.x0 = 12.0f + ((20.0f + pos[0]) - 16.0f);
    }
    else
    {
      q.x0 = 12.0f + ((pos[0] + textW) - 16.0f);
    }
    q.y0 = pos[1];
    q.x1 = 16.0f + q.x0;
    q.y1 = 19.0f + q.y0;
    q.u0 = 0.69140625f;
    q.v0 = 0.92578125f;
    q.u1 = 0.75390625f;
    q.v1 = 1.0f;
    context->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, scale);
    if (textW > 20.0f)
    {
      {
        f32 k = 16.0f;
        q.x0 = (new_var = pos[0]) + k;
      }
      q.y0 = pos[1];
      q.x1 = 12.0f + ((new_var + textW) - 16.0f);
      q.y1 = 19.0f + q.y0;
      q.u0 = 0.62890625f;
      q.v0 = 0.92578125f;
      q.u1 = 0.69140625f;
      q.v1 = 1.0f;
      context->transform_quad(&q);
      draw_textured_quad_at_depth(&q.x0, scale);
    }
    TWindowSubStatusDisp::get_player();
    pos[0] += 6.0f;
    if (textW < 20.0f)
    {
      pos[0] = (0.5f * (20.0f - textW)) + pos[0];
    }
    pos[1] += 3.0f;
    set_text_draw_params(context, 0, 1, -1.0f / (0.07475f + context->depth), 100000.0f);
    draw_small_font_string_clipped(pos, name, alphaBits, 1000000.0f);
  }
}
}

#pragma pop
extern "C" {
void TWindowFukidasi::init_balloon(u16 speaker, s32 str, s32 client, f32 scale) {
    u32 len;

    *(s32 *)((s8 *)this + 0) = (saddr) window_fukidasi_class_name;
    this->m_70 = 0;
    this->m_71 = 0;
    *(s8 *)&this->unk_72 = 2;
    this->m_73 = -1;
    this->speaker_id = speaker;
    this->client_index = client;
    if (str != 0) {
        len = TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)0x18);
        this->name = (char *)mem_alloc(len + 1);
        strncpy(this->name, (const char *)str, len + 1);
    } else {
        this->name = 0;
    }
    set_color(speaker);
    this->tail_scale = 0.0f;
    this->m_7c = scale;
    this->frame_size[0] = 0.0f;
    this->frame_size[1] = 0.0f;
    this->clear_flag();
    this->clear_flag2c_bit100();
}

void TWindowFukidasi::init_flags(s32 flags) {
    this->m_58 = 0.0f;
    this->set_depth(60000.0f);
    if (this->is_closed() != 0) {
        this->window_flags = (s32) (this->window_flags | 1);
    }
    this->m_71 = (u8) (this->m_71 & ~0x50);
    if (flags & 2) {
        this->m_71 = (u8) (this->m_71 | 8);
    } else {
        this->m_71 = (u8) (this->m_71 & 0xFFFFFFF7);
    }
    if (flags & 0x20) {
        this->m_71 = (u8) (this->m_71 | 2);
        this->set_flag();
        this->set_flag2c_bit200();
        this->m_73 = 4;
        return;
    }
    this->m_71 = (u8) (this->m_71 & 0xFFFFFFFD);
}

// Dead-stripped from the DOL: no code of it survives, only its literal (1e6 at
// 0x805DCD54, pooled between set_text's 200 and init_flags's 60000). It measures a
// text entry the way set_text does but without its 200 wrap width, using the
// 1e6 "no limit" width draw_name_plate clips names with. Name inferred from that role.
void TWindowFukidasi::measure_text_unbounded(int entry) {
    measure_message_text_width(entry, 1000000.0f);
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void set_text__15TWindowFukidasiFPvii(u8 *arg0, saddr str, saddr flags) {
  u32 new_var;
  u8 *entry;
  ((TWindowFukidasi *)arg0)->init_flags(flags);
  ((TWindowFukidasi *)arg0)->clear_flag();
  if (((u8) (*((u8 *) (((s8 *) arg0) + 0x72)))) != 0)
  {
    *((u8 *) (((s8 *) arg0) + 0x72)) = 0U;
    reinterpret_cast<WindowLayoutEntries *>((arg0 + 0x24))->destroy_all_items();
    init_window_layout_entries(
        reinterpret_cast<WindowLayoutEntries *>(arg0 + 0x24),
        reinterpret_cast<const void *>(&window_fukidasi_layout_entries.value),
        (int) (*((s16 *) (((s8 *) arg0) + 0x20))));
  }
  entry = (u8 *) ((TWindowBase *)arg0)->get_array_entry(0);
  if (flags & 1)
  {
    set_text_entry_string(entry, str, 0x20);
  }
  else
  {
    set_text_entry_string(entry, str, 0);
  }
  if (flags & 4)
  {
    *((u16 *) (((s8 *) entry) + 0)) = (u16) ((*((u16 *) (((s8 *) entry) + 0))) | 0x40);
    measure_message_text_width_default(entry);
  }
  else
  {
    measure_message_text_width((saddr) entry, 200.0f);
  }
  if (flags & 0x80)
  {
    *((u16 *) (((s8 *) entry) + 0)) = (u16) ((*((u16 *) (((s8 *) entry) + 0))) | 0x200);
  }
  else
  {
    *((u16 *) (((s8 *) entry) + 0)) = (u16) ((*((u16 *) (((s8 *) entry) + 0))) & 0xFFFFFDFF);
  }
  *((s32 *) (((s8 *) entry) + 0x24)) = 0xFF000000;
  new_var = TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)(0x100));
  *((s16 *) (((s8 *) arg0) + 0x74)) = (s16) ((3.3f * ((f32) new_var)) + 55.5f);
  if (TWindowSubStatusDisp::get_card_window_scale((int) ((s32) (*((s16 *) (((s8 *) arg0) + 0x20))))) > 0.0f)
  {
    *((s32 *) (((s8 *) arg0) + 0x5C)) = 0;
  }
  play_sound_effect(0x53705, 0, 0, 0);
  if (((u8) (*((u8 *) (((s8 *) arg0) + 0x70)))) != 0)
  {
    *((u8 *) (((s8 *) arg0) + 0x70)) = 5U;
  }
}
}

#pragma pop
extern "C" {
void open__15TWindowFukidasiFPvPvi(u8 *arg0, u32 *arg1, s32 flags) {
    s32 var_r31;
    u8 temp_r0;

    var_r31 = 0;
    ((TWindowFukidasi *)arg0)->init_flags(flags);
    if ((u8) *(u8 *)((s8 *)arg0 + 0x72) != 1) {
        *(u8 *)((s8 *)arg0 + 0x72) = 1U;
        reinterpret_cast<WindowLayoutEntries *>((arg0 + 0x24))->destroy_all_items();
        ((TWindowSubSymbolChat *)(arg0 + 0x24))->init_layout_entries(*(s16 *)((s8 *)arg0 + 0x20));
        if ((u8) *(u8 *)((s8 *)arg0 + 0x70) != 0) {
            var_r31 = 1;
        }
    } else {
        temp_r0 = *(u8 *)((s8 *)arg0 + 0x70);
        if ((temp_r0 != 0) && (temp_r0 != 4)) {
            var_r31 = 1;
        }
    }
    if (var_r31 != 0) {
        *(u8 *)((s8 *)arg0 + 0x70) = 5U;
        ((TWindowFukidasi *)arg0)->clear_flag();
        if (TWindowSubStatusDisp::get_card_window_scale(*(s16 *)((s8 *)arg0 + 0x20)) > 0.0f) {
            *(s32 *)((s8 *)arg0 + 0x5C) = 0;
        }
    }
    set_symbol_chat_parts(&((TWindowFukidasi *)arg0)->entry_list, (void *)arg1);
    TWindowSubSymbolChat::play_symbol_sound(((u32) *arg1 >> 5U) & 0xF);
    *(s16 *)((s8 *)arg0 + 0x74) = 0x5A;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
s32 TWindowFukidasi::clamp_position(void *arg1, f32 farg0) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    s32 var_r31;

    var_r31 = 0;
    temp_f1 = 20.0f + TWindowCtrlMain::get_position_z(this->client_index);
    if (*(f32 *)((s8 *)arg1 + 0) < temp_f1) {
        *(f32 *)((s8 *)arg1 + 0) = temp_f1;
        var_r31 = 1;
    }
    temp_f1_2 = (TWindowCtrlMain::get_ctrl_field14(this->client_index) - 20.0f) - (this->frame_size[0] * farg0);
    if (*(f32 *)((s8 *)arg1 + 0) > temp_f1_2) {
        *(f32 *)((s8 *)arg1 + 0) = temp_f1_2;
        var_r31 = 1;
    }
    temp_f1_3 = 40.0f + TWindowCtrlMain::get_field10(this->client_index);
    if (*(f32 *)((s8 *)arg1 + 4) < temp_f1_3) {
        *(f32 *)((s8 *)arg1 + 4) = temp_f1_3;
        var_r31 = 1;
    }
    temp_f1_4 = (TWindowCtrlMain::get_field_18(this->client_index) - 40.0f) - (this->frame_size[1] * farg0);
    if (*(f32 *)((s8 *)arg1 + 4) > temp_f1_4) {
        *(f32 *)((s8 *)arg1 + 4) = temp_f1_4;
        var_r31 = 1;
    }
    return var_r31;
}
}

#pragma pop
extern "C" {
void TWindowFukidasi::set_color(u16 color) {
    this->balloon_color = 0xFFF8F8F8;
    TObjChara *chara;
    if (((u32)color < 0xCU) && ((chara = get_player_by_client_id((u32)color)) != 0) && (chara->obj_isState3_324() == 0)) {
        this->balloon_color = (s32) TWindowFukidasi__balloon_color_table[(u16)color];
    }
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TWindowFukidasi::get_boundary_offset(s32 angle, f32 *out) {
    f32 ax;
    f32 ay;
    f32 kx;
    f32 ky;
    s32 neg;
    ax = 0.5f * (0.5f * target_size[0] + 14.0f);
    ay = 0.5f * (0.5f * target_size[1] + 10.0f);
    out[0] = ax * cos_table_lookup(angle);
    out[1] = ay * sin_table_lookup(angle);
    if ((angle + 0x2000) & 0x4000) {
        kx = sin_table_lookup(angle - 0x4000) / cos_table_lookup(angle - 0x4000);
        if (!(angle & 0x8000)) {
            kx = -kx;
        }
        if (angle & 0x8000) {
            ky = -1.0f;
        } else {
            ky = 1.0f;
        }
    } else {
        neg = (angle + 0x2000) & 0x8000;
        if (neg) {
            kx = -1.0f;
        } else {
            kx = 1.0f;
        }
        ky = sin_table_lookup(angle) / cos_table_lookup(angle);
        if (neg) {
            ky = -ky;
        }
    }
    out[0] += ax * kx;
    out[1] += ay * ky;
}
}

#pragma pop
extern "C" {
void TWindowFukidasi::update_reveal_timer() {
    Fuki_80251790 *b = (Fuki_80251790 *)this;
    u32 flags;

    if (((TWindowFukidasi *)b)->is_active() != 0 && b->frame < 0x1000000) {
        b->frame += TWindowSubStatusDisp::get_card_window_flags(b->card_slot) + 1;
    }
    flags = b->flags;
    if ((flags & 2) && (!(flags & 1) || (flags & 4))) {
        b->flags &= ~4;
        ((TWindowFukidasi *)b)->request_balloon_hide();
    }
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TWindowFukidasi::follow_anchor() {
    Fuki_80251594 *b = (Fuki_80251594 *)this;
    f32 cx;
    f32 cy;
    f32 dx;
    f32 dy;

    cx = 0.5f * b->anchor[0] + b->rect[0];
    cy = 0.5f * b->anchor[1] + b->rect[1];
    if (b->options & 0x40) {
        b->center[0] = cx;
        b->center[1] = cy;
    } else {
        dx = 0.21f * (cx - b->center[0]);
        dy = 0.21f * (cy - b->center[1]);
        if (fabs_float(dx) < 0.1f) {
            b->center[0] = cx;
        } else {
            b->center[0] += dx;
        }
        if (fabs_float(dy) < 0.1f) {
            b->center[1] = cy;
        } else {
            b->center[1] += dy;
        }
    }
    if (b->steps == 0) {
        b->size[0] = b->anchor[0];
        b->size[1] = b->anchor[1];
    } else {
        b->size[0] += (b->anchor[0] - b->size[0]) / (f32)b->steps;
        b->size[1] += (b->anchor[1] - b->size[1]) / (f32)b->steps;
        b->steps--;
    }
    b->pos[0] = b->center[0] - 0.5f * b->size[0];
    b->pos[1] = b->center[1] - 0.5f * b->size[1];
    ((TWindowFukidasi *)b)->clamp_position(b->pos, b->margin);
    b->center[0] = 0.5f * b->size[0] + b->pos[0];
    b->center[1] = 0.5f * b->size[1] + b->pos[1];
    project_anchor(NULL, b->head);
}

s32 TWindowFukidasi::is_speaker_far_or_offscreen() {
    Fuki_802504C0 *arg0 = (Fuki_802504C0 *)this;
    f32 pos[3];
    f32 scr[2];
    f32 m;
    f32 xx;
    f32 yy;
    f32 zz;
    clear_flag_20();
    if (project_anchor(pos, scr) == 0) {
        return 1;
    }
    if (((TWindowFukidasi *)arg0)->is_flag_set() != 0) {
        m = -50.0f;
    } else {
        m = 0.0f;
    }
    if (scr[0] < TWindowCtrlMain::get_position_z(((Fuki_80251380 *)arg0)->viewport) - m) {
        return 1;
    }
    if (scr[1] < TWindowCtrlMain::get_field10(((Fuki_80251380 *)arg0)->viewport) - m) {
        return 1;
    }
    if (scr[0] > m + TWindowCtrlMain::get_ctrl_field14(((Fuki_80251380 *)arg0)->viewport)) {
        return 1;
    }
    if (scr[1] > m + TWindowCtrlMain::get_field_18(((Fuki_80251380 *)arg0)->viewport)) {
        return 1;
    }
    Vec v = fukidasi_forward_vec;
    f32 d[3];
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    rotate_matrix_x(0, camera_ctrl_instance->pitch);
    rotate_matrix_z(0, camera_ctrl_instance->roll);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    d[0] = pos[0] - camera_ctrl_instance->pos.x;
    d[1] = pos[1] - camera_ctrl_instance->pos.y;
    d[2] = pos[2] - camera_ctrl_instance->pos.z;
    if (vec3_dot(&v, d) <= 0.0f) {
        return 1;
    }
    xx = d[0] * d[0];
    yy = d[1] * d[1];
    zz = d[2] * d[2];
    if (zz + (xx + yy) > 40.0f * m + 14400.0f) {
        return 1;
    }
    ((TWindowFukidasi *)arg0)->set_balloon_visible();
    return ((TWindowFukidasi *)arg0)->get_flag_bit1() != 0 ? 1 : 0;
}
}

#pragma pop
extern "C" {
s32 TWindowFukidasi::project_anchor(f32 *pos, f32 *out) {
    Fuki_80250F70 *arg0 = (Fuki_80250F70 *)this;
    Fuki_802511E4 *b = (Fuki_802511E4 *)arg0;
    Ent_802511E4 *e;
    f32 tmp[3];

    if (b->id == 0xFFFF) {
        return 0;
    }
    e = find_entity_by_id(b->id);
    if (e == NULL) {
        return 0;
    }
    if (get_player_by_client_id(b->id) != 0 && (u32)TObjPlayer::get_battle_ctrl_flag(b->id) == 0) {
        return 0;
    }
    if (pos == NULL) {
        pos = tmp;
    }
    pos[0] = e->pos[0];
    pos[1] = e->pos[1] + b->height;
    pos[2] = e->pos[2];
    if (out == NULL) {
        return 1;
    }
    push_matrix();
    project_world_to_screen(0, pos, out);
    pop_matrix();
    if (is_split_screen() != 0) {
        out[0] -= (f32)TCameraCtrl::get_viewport_x();
        out[0] /= TCameraCtrl::get_view_scale();
        out[1] -= (f32)TCameraCtrl::get_viewport_y();
        out[1] /= TCameraCtrl::get_fov();
    }
    out[0] += TCameraCtrl::view_params.screen.projection.center_x - 320.0f;
    out[1] += TCameraCtrl::view_params.screen.projection.center_y - 240.0f;
    return 1;
}

// Dead-stripped from the DOL: no code of it survives, only its literal (0.0 at
// 0x805DCD30, pooled between rest_balloon's 65536 and project_anchor's 320). It
// clears the width init_balloon zeroes when it sets the balloon up. Name inferred
// from that role.
void TWindowFukidasi::clear_width() {
    frame_size[0] = 0.0f;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void refresh_rect_placement__15TWindowFukidasiFPv(Fuki_80251028 *b) {
    if (((TWindowFukidasi *)b)->is_speaker_far_or_offscreen() != 0) {
        f32 *m;
        if ((s8)b->slot == -1) {
            ((TWindowFukidasi *)b)->set_flag();
            ((TWindowFukidasi *)b)->set_flag2c_bit200();
            b->slot = ((TWindowFukidasi *)b)->alloc_nearest_free_slot();
        }
        m = get_message_by_type__11TWindowCtrlFScl(b->slot, b->viewport);
        b->rect[0] = m[0] - 0.5f * b->anchor[0];
        b->rect[1] = m[1] - 0.5f * b->anchor[1];
        ((TWindowFukidasi *)b)->clamp_position(b->rect, 1.0f);
    } else {
        f32 a[2];
        f32 c[2];
        f32 d[2];
        f32 e[2];
        f32 *res;
        if ((s8)b->slot != -1) {
            ((TWindowFukidasi *)b)->clear_visible_flag();
            ((TWindowFukidasi *)b)->clear_flag2c_bit200();
            TWindowCtrl::release_slot((s8 *)&b->slot);
        }
        res = NULL;
        if (((TWindowFukidasi *)b)->is_bit10_set() == 0) {
            if (shift_rect_with_head__15TWindowFukidasiFPvPvPv((Fuki_80250F70 *)b, b->rect, a) != 0) {
                res = a;
            }
            if (rest_balloon__15TWindowFukidasiFv((Fuki_80250A24 *)(b), a, c) != 0) {
                res = c;
            }
        } else {
            ((TWindowFukidasi *)b)->hide();
            if (shift_rect_with_head__15TWindowFukidasiFPvPvPv((Fuki_80250F70 *)b, b->rect, a) != 0) {
                res = a;
            }
            if (try_place_bubble__15TWindowFukidasiFPvPvPv((Fuki_802506E8 *)(b), a, d) != 0) {
                res = d;
            }
            if (res != d && rest_balloon__15TWindowFukidasiFv((Fuki_80250A24 *)(b), d, c) != 0) {
                res = c;
            }
            if (res == NULL && TWindowFukidasi__sub_802505C0(b, b->rect, e) != 0) {
                res = e;
            }
        }
        if (res != NULL) {
            b->rect[0] = res[0];
            b->rect[1] = res[1];
        }
    }
}
}

#pragma pop
extern "C" {
s32 shift_rect_with_head__15TWindowFukidasiFPvPvPv(Fuki_80250F70 *b, f32 *rect, f32 *out) {
    f32 x = b->head[0];
    f32 y = b->head[1];
    ((TWindowFukidasi *)b)->project_anchor(0, b->head);
    out[0] = rect[0] + (b->head[0] - x);
    out[1] = rect[1] + (b->head[1] - y);
    ((TWindowFukidasi *)b)->clamp_position(out, 1.0f);
    if (((TWindowFukidasi *)b)->draw_resolved_window(out, b->anchor, 4) == 0) {
        return 1;
    }
    return 0;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
s32 rest_balloon__15TWindowFukidasiFv(Fuki_80250A24 *b, f32 *rect, f32 *arg2) {
    NJS_POINT2 *o = (NJS_POINT2 *)arg2;
    f32 world[3];
    f32 edge[2];
    f32 dist;
    f32 dx;
    f32 dy;
    f32 reach;
    f32 t;
    s32 a;
    s32 angle;
    ((TWindowFukidasi *)F70_80250A24)->project_anchor(world, NULL);
    reach = 1000.0f / xyz_distance(&camera_ctrl_instance->pos, world);
    dx = (0.5f * b->rsize[0] + rect[0]) - b->center[0];
    dy = (0.5f * b->rsize[1] + rect[1]) - b->center[1];
    dist = newton_sqrtf(dx * dx + dy * dy);
    if (dist < 3.0f) {
        angle = 0xD400;
    } else {
        a = (s32) (10430.38043493439 * ((f64)atan2_float(dy, dx)));
        edge[0] = dx - reach * cos_table_lookup(a);
        edge[1] = dy - reach * sin_table_lookup(a);
        edge[0] /= 14.0f + b->rsize[0];
        edge[1] /= 10.0f + b->rsize[1];
        angle = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    }
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    if (fabs_float(dist - newton_sqrtf(edge[0] * edge[0] + edge[1] * edge[1])) < 10.0f) {
        return 0;
    }
    o->x = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o->y = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, 1.0f) != 0) {
        return 0;
    }
    if (((TWindowFukidasi *)b)->draw_resolved_window((f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    t = 0.000030517578f * (f32) rand();
    edge[0] += t * (dx - edge[0]);
    edge[1] += t * (dy - edge[1]);
    o->x = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o->y = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (((TWindowFukidasi *)b)->draw_resolved_window((f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) ((f32) a + (32768.0f * (0.000030517578f * (f32) rand()) - 16384.0f));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o->x = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o->y = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, 1.0f) != 0) {
        return 0;
    }
    if (((TWindowFukidasi *)b)->draw_resolved_window((f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) (65536.0f * (0.000030517578f * (f32) rand()));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o->x = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o->y = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, 1.0f) != 0) {
        return 0;
    }
    return (u32) __cntlzw((uaddr) ((TWindowFukidasi *)b)->draw_resolved_window((f32 *)o, b->size, 4)) >> 5;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
s32 try_place_bubble__15TWindowFukidasiFPvPvPv(Fuki_802506E8 *b, f32 *rect, f32 *o) {
    f32 world[3];
    f32 edge[2];
    f32 dx;
    f32 dy;
    f32 reach;
    s32 a;
    s32 angle;
    ((TWindowFukidasi *)F70_802506E8)->project_anchor(world, NULL);
    reach = 1000.0f / xyz_distance(&camera_ctrl_instance->pos, world);
    dx = (0.5f * b->rsize[0] + rect[0]) - b->center[0];
    dy = (0.5f * b->rsize[1] + rect[1]) - b->center[1];
    a = (s32) (10430.38043493439 * ((f64)atan2_float(dy, dx)));
    edge[0] = dx - reach * cos_table_lookup(a);
    edge[1] = dy - reach * sin_table_lookup(a);
    edge[0] /= 14.0f + b->rsize[0];
    edge[1] /= 10.0f + b->rsize[1];
    angle = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle + 0x8000, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o[0] = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o[1] = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_802506E8(F70_802506E8, o, 1.0f) != 0) {
        return 0;
    }
    if (((TWindowFukidasi *)b)->draw_resolved_window(o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) ((f32) a + (32768.0f * (0.000030517578f * (f32) rand()) - 16384.0f));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o[0] = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o[1] = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_802506E8(F70_802506E8, o, 1.0f) != 0) {
        return 0;
    }
    return (u32) __cntlzw((uaddr) ((TWindowFukidasi *)b)->draw_resolved_window(o, b->size, 4)) >> 5;
}
}

#pragma pop
#undef F70_80250A24
#undef CLAMP_80250A24
#undef F70_802506E8
#undef CLAMP_802506E8
extern "C" {
s32 TWindowFukidasi__sub_802505C0(Fuki_80251028 *b, f32 *rect, f32 *out) {
    f32 x = TWindowCtrlMain::get_position_z(b->viewport);
    f32 w = (TWindowCtrlMain::get_ctrl_field14(b->viewport) - TWindowCtrlMain::get_position_z(b->viewport)) - b->anchor[0];
    f32 y;
    f32 h;
    f32 t;
    t = 0.000030517578f * (f32) rand();
    out[0] = t * w + x;
    y = TWindowCtrlMain::get_field10(b->viewport);
    h = (TWindowCtrlMain::get_field_18(b->viewport) - TWindowCtrlMain::get_field10(b->viewport)) - b->anchor[1];
    t = 0.000030517578f * (f32) rand();
    out[1] = t * h + y;
    return (u32) __cntlzw((u32) ((TWindowFukidasi *)b)->draw_resolved_window(out, b->anchor, 4)) >> 5;
}

void TWindowFukidasi::place_rect_at_head_or_slot() {
    Fuki_802504C0 *b = (Fuki_802504C0 *)this;
    if (is_speaker_far_or_offscreen() != 0) {
        f32 *m;
        if ((s8)b->slot == -1) {
            ((TWindowFukidasi *)b)->set_flag();
            ((TWindowFukidasi *)b)->set_flag2c_bit200();
            b->slot = ((TWindowFukidasi *)b)->alloc_nearest_free_slot();
        }
        m = get_message_by_type__11TWindowCtrlFScl(b->slot, b->viewport);
        b->rect[0] = m[0] - 0.5f * b->anchor[0];
        b->rect[1] = m[1] - 0.5f * b->anchor[1];
        ((TWindowFukidasi *)b)->clamp_position(b->rect, 1.0f);
    } else {
        f32 p[2];
        if ((s8)b->slot != -1) {
            ((TWindowFukidasi *)b)->clear_visible_flag();
            ((TWindowFukidasi *)b)->clear_flag2c_bit200();
            TWindowCtrl::release_slot((s8 *)&b->slot);
        }
        project_anchor((f32 *)(0), p);
        b->rect[0] = p[0] - 0.5f * b->anchor[0];
        b->rect[1] = p[1] - 0.5f * b->anchor[1];
    }
}
}

#pragma pop
extern "C" {
// Dead-stripped from the DOL: no code of it survives, only its literals (1000, 0.5
// and 19 at 0x805DCD08-0x805DCD13 and 10430.38 at 0x8044ED70), pooled between
// approach's 0.011 and TWindowFukidasi__sub_802505C0's 2^-15. It aims from the
// middle of the 19-unit name plate draw_name_plate puts on the balloon's top edge at
// the tail tip draw_tail places 1000/distance short of the speaker, with the
// same atan2 scale. Name inferred from that role.
s32 TWindowFukidasi::calc_name_plate_angle(f32 *world, f32 *scr, f32 *rect, f32 *size) {
    f32 reach = 1000.0f / xyz_distance(&camera_ctrl_instance->pos, world);
    f32 dx = (0.5f * size[0] + rect[0]) - scr[0];
    f32 dy = ((0.5f * size[1] + rect[1]) - 19.0f) - (scr[1] - reach);
    return (s32) (10430.38043493439 * atan2_float(dy, dx));
}

void TWindowFukidasi::request_balloon_hide() {
    if (!(this->m_71 & 0x10)) {
        this->m_70 = 7;
    }
}

s32 TWindowFukidasi::approach(f32 farg0) {
    f32 x;

    x = 0.47f * (farg0 - this->tail_scale);
    if (fabs_float(x) < 0.011f) {
        this->tail_scale = farg0;
        return 1;
    }
    this->tail_scale = (f32) (this->tail_scale + x);
    return 0;
}

void TWindowFukidasi::sync_display_pos() { this->content_scale[0] = this->tail_scale; this->content_scale[1] = this->tail_scale; }

void TWindowFukidasi::calc_text_size(f32 *out) {
    Entry_80250380 *e;
    switch (((Fuki_80250380 *)this)->kind) {
    case 0:
        e = (Entry_80250380 *)((TWindowBase *)this)->get_array_entry(0);
        out[0] = 0.1f + (8.0f + e->w);
        out[1] = 0.1f + (20.0f + e->h);
        break;
    case 1:
        TWindowSubSymbolChat__sub_802483F0((saddr)((Fuki_80250380 *)this)->entries, (void *)out);
        break;
    case 2:
        break;
    }
}

void clamp_text_size__15TWindowFukidasiFPvPv(Fuki_80250314 *b, f32 *out) {
    f32 size[2];
    ((TWindowFukidasi *)b)->calc_text_size((f32 *)size);
    if (b->anchor[0] > size[0]) {
        out[0] = size[0];
    } else {
        out[0] = b->anchor[0];
    }
    if (b->anchor[1] > size[1]) {
        out[1] = size[1];
    } else {
        out[1] = b->anchor[1];
    }
}
}

s32 TWindowFukidasi::check_card_match_enabled(const char *text) {
    if ((u8) *(u8 *)((s8 *)this + 0x72) != 0) {
        return 0;
    }
    return (u32) __cntlzw(strcmp((const char *)((TWindowSubComCard *)((TWindowBase *)this)->get_array_entry(0))->get_field_20(), text)) >> 5;
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::rearm_balloon(saddr flags) {
    u32 n;

    if (is_closed() != 0) {
        *(s8 *)((s8 *)((u8 *)this) + 0x70) = 5;
    }
    init_flags(flags);
    switch ((s32) (*(u8 *)((s8 *)((u8 *)this) + 0x72))) {
    case 0:
        n = TWindowKeyBoardSoft::strnlen((s8 *)(((TWindowSubComCard *)(void *)((TWindowBase *)this)->get_array_entry(0))->get_field_20()), (u32)0x100);
        *(s16 *)((s8 *)((u8 *)this) + 0x74) = (s16) ((3.3f * (f32) n) + 55.5f);
        break;
    case 1:
        *(s16 *)((s8 *)((u8 *)this) + 0x74) = 0x5A;
        break;
    case 2:
        break;
    }
}

#pragma pop
s32 is_speech_balloon_ready(u8 *window_base) {
    s32 t = *(window_base + 0x72);
    switch (t) {
    case 0:
        ((TWindowBase *)window_base)->get_array_entry(0);
        return fn_80252CBC();
    case 1:
    case 2:
        break;
    }
    return 0;
}

void complete_speech_balloon(u8 *arg0) {
    s32 t;
    *(s8 *)(arg0 + 0x70) = 4;
    *(u8 *)(arg0 + 0x71) |= 0x40;
    ((TWindowFukidasi *)arg0)->calc_text_size((f32 *)(arg0 + 0x38));
    ((s32 (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(arg0);
    TWindowFukidasi__sub_80252C38(arg0);
    ((TWindowFukidasi *)arg0)->set_flag2c_bit100();
    ((TWindowBase *)arg0)->save_position();
    *(f32 *)(arg0 + 0x80) = 1.0f;
    ((TWindowFukidasi *)arg0)->sync_display_pos();
    *(s32 *)(arg0 + 0x5C) = 0x186A0;
    t = *(u8 *)(arg0 + 0x72);
    switch (t) {
    case 0:
        ((TWindowBase *)arg0)->get_array_entry(0);
        reset_float_field__15TWindowHelpItemFv();
        break;
    case 1:
    case 2:
        break;
    }
}
