#include "pso/effect/sprite/TQuadSpriteSclColRot.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/TObjChara.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/render/TextureState.h"
#include "pso/ui/window/SmallFontText.h"
#include "pso/ui/window/WindowTextDraw.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include <string.h>
#include "pso/ui/chat/TWindowChatSymbol.h"
#include <stdlib.h>
#include "pso/object/base/CollisionActorLookup.h"
#define PSO_SDK_COMPACT_MATH
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/WindowTextEntry.h"
#undef PSO_SDK_COMPACT_MATH


extern "C" {
f32 xyz_distance(void *, void *);

}


extern "C" {
f32 vec3_dot(void *, void *);
void rotate_matrix_y(s32, s32);
__declspec(section ".rodata") extern const char window_fukidasi_class_name_string[] = "TWindowFukidasi";
}

extern const u32 balloon_color_table[16] = {
    0xFFFFC8C8, 0xFFA2FF9D, 0xFFFBFFB5, 0xFFB0F8FF, 0xFFD1ADFF, 0xFFFFBF7C, 0xFFA5B6FB, 0xFFFFB99C,
    0xFF90D29B, 0xFF8BB5EE, 0xFFFFB5DA, 0xFFFFFF8C, 0xFFE6E8CA, 0xFFDEFFBD, 0xFFC6C2FF, 0xFFFFE1EB,
};

extern const Vec fukidasi_forward_vec = {0.0f, 0.0f, -1.0f};
WindowFukidasiLayoutEntries window_fukidasi_layout_entries = {1, {1, 3, 0, 0, 0x3F000000, 0xFFFFFFFF, 0, 0}};
u32 window_fukidasi_addition_params[5] = {0, 0, 0x476A6000, 0, 0x7023};
const char *TWindowFukidasi::class_name = window_fukidasi_class_name_string;

extern "C" {

saddr get_zero_vec2();
}

void TWindowFukidasi::clear_flag2c_bit100() { this->window_flags &= 0xfffffeff; }

void TWindowFukidasi::set_flag2c_bit200() { this->window_flags |= 0x200; }

void TWindowFukidasi::clear_flag2c_bit200() { this->window_flags &= 0xfffffdff; }

void TWindowFukidasi::set_flag2c_bit100() { this->window_flags |= 0x100; }
TWindowFukidasi::TWindowFukidasi(u16 speaker, const char *text, s32 client, f32 scale)
    : TWindowAddition((u8 *)window_fukidasi_addition_params, (s16)client, (u8 *)get_zero_vec2()) {
    init_balloon(speaker, text, client, scale);
}

TWindowFukidasi::~TWindowFukidasi() {
    if (this->is_flag_set() != 0) {
        this->clear_visible_flag();
        TWindowCtrl::release_slot((s8 *)&this->slot);
    }
    if ((uaddr)this->name != 0U) {
        mem_free(this->name);
        this->name = 0;
    }
}

void TWindowFukidasi::run_task() {
  switch (state)
  {
    case 1:
      calc_text_size(&target_size[0]);
      tween_ticks = 6;
      this->clear_flag();
      this->set_flag2c_bit100();
      state = 2U;
    case 2:
      if (this->approach(1.0f) != 0)
    {
      state = 3U;
    }
      this->sync_display_pos();
      break;
    case 3:
      set_active();
      this->set_flag2c_bit100();
      state = 4U;
    case 4:
      if (balloon_flags & 8)
    {
      hide_ticks = (s16) ((hide_ticks) - 1);
      m_58 += 0.1f;
      this->sort_depth += 0.1f;
      if ((hide_ticks) < 0)
      {
        state = 7U;
      }
    }
      break;
    case 5:
      this->clamp_text_size(target_size);
      tween_ticks = 6;
      this->clear_flag();
      this->set_flag2c_bit100();
      state = 6U;
    case 6:
      if (this->approach(0.5f) != 0)
    {
      state = 1U;
    }
      this->sync_display_pos();
      break;
    case 7:
      this->clear_flag();
      this->clear_flag2c_bit100();
      this->window_flags = (s32) ((this->window_flags) & 0xFFFFFFFE);
      balloon_flags = (u8) (balloon_flags | 0x10);
      state = 8U;
    case 8:
      if (this->approach(0.0f) != 0)
    {
      state = 9U;
    }
      this->sync_display_pos();
      break;
    case 9:
      this->queue_destruction();
      break;
  }
  this->update_reveal_timer();
  if (this->is_active() != 0)
  {
    update_window_entry_list(&entry_list);
  }
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::render() {
    f32 off[2];
    WindowDrawContext *v;
    switch (state) {
    case 0:
        project_anchor(NULL, head_position);
        this->place_rect_at_head_or_slot();
        balloon_center[0] = 0.5f * target_size[0] + target_position[0];
        balloon_center[1] = 0.5f * target_size[1] + target_position[1];
        state = 1;
        break;
    case 2:
        this->refresh_rect_placement();
        break;
    case 4:
        this->refresh_rect_placement();
        break;
    case 6:
        this->refresh_rect_placement();
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
    set_texture_list(hud_texlist);
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
    end_screen_draw();
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
    draw_rotated_quad(&slice->x);
    slice->x = left + fullWidth - cap;
    slice->x = context->pivot[0] + context->scale[0] * (slice->x - context->pivot[0]);
    slice->u = (194.0f - cap) / 256.0f;
    draw_rotated_quad(&slice->x);
    w = (fullWidth - 64.0f) * context->scale[0];
    if (w >= 0.0f) {
        slice->x = 32.0f + left;
        slice->x = context->pivot[0] + context->scale[0] * (slice->x - context->pivot[0]);
        slice->edge_a_x = w;
        slice->u = 0.5078125f;
        draw_rotated_quad(&slice->x);
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
void TWindowFukidasi::draw_name_plate(WindowDrawContext *context, u32 argb) {
  f32 pos[2];
  TexturedQuad q;
  f32 scale;
  f32 textW;
  s32 alpha;
  s32 alphaBits;
  s32 color;
  f32 left;
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
        q.x0 = (left = pos[0]) + k;
      }
      q.y0 = pos[1];
      q.x1 = 12.0f + ((left + textW) - 16.0f);
      q.y1 = 19.0f + q.y0;
      q.u0 = 0.62890625f;
      q.v0 = 0.92578125f;
      q.u1 = 0.69140625f;
      q.v1 = 1.0f;
      context->transform_quad(&q);
      draw_textured_quad_at_depth(&q.x0, scale);
    }
    end_screen_draw();
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

#pragma pop
void TWindowFukidasi::init_balloon(u16 speaker, const char *str, s32 client, f32 scale) {
    u32 len;

    m_name = class_name;
    this->state = 0;
    this->balloon_flags = 0;
    this->content_kind = 2;
    this->slot = -1;
    this->speaker_id = speaker;
    this->client_index = client;
    if (str != NULL) {
        len = TWindowKeyBoardSoft::strnlen(str, (u32)0x18);
        this->name = (char *)mem_alloc(len + 1);
        strncpy(this->name, str, len + 1);
    } else {
        this->name = 0;
    }
    set_color(speaker);
    this->tail_scale = 0.0f;
    this->scale = scale;
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
    this->balloon_flags = (u8) (this->balloon_flags & ~0x50);
    if (flags & 2) {
        this->balloon_flags = (u8) (this->balloon_flags | 8);
    } else {
        this->balloon_flags = (u8) (this->balloon_flags & 0xFFFFFFF7);
    }
    if (flags & 0x20) {
        this->balloon_flags = (u8) (this->balloon_flags | 2);
        this->set_flag();
        this->set_flag2c_bit200();
        this->slot = 4;
        return;
    }
    this->balloon_flags = (u8) (this->balloon_flags & 0xFFFFFFFD);
}

// Dead-stripped from the DOL: no code of it survives, only its literal (1e6,
// pooled between set_text's 200 and init_flags's 60000). It measures a text entry
// the way set_text does but without its 200 wrap width, using the
// 1e6 "no limit" width draw_name_plate clips names with.
void TWindowFukidasi::measure_text_unbounded(WindowTextEntry *entry) {
    reinterpret_cast<WindowTextEntry *>(entry)->measure_text(1000000.0f);
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::set_text(const char *str, s32 flags) {
  u32 length;
  WindowTextEntry *entry;
  init_flags(flags);
  clear_flag();
  if (content_kind != 0)
  {
    content_kind = 0U;
    entry_list.destroy_all_items();
    init_window_layout_entries(
        &entry_list,
        reinterpret_cast<const void *>(&window_fukidasi_layout_entries.value),
        client_index);
  }
  entry = (WindowTextEntry *)get_array_entry(0);
  if (flags & 1)
  {
    set_text_entry_string(entry, (uaddr)str, 0x20);
  }
  else
  {
    set_text_entry_string(entry, (uaddr)str, 0);
  }
  if (flags & 4)
  {
    entry->flags |= 0x40;
    measure_message_text_width_default(entry);
  }
  else
  {
    entry->measure_text(200.0f);
  }
  if (flags & 0x80)
  {
    entry->flags |= 0x200;
  }
  else
  {
    entry->flags &= 0xFFFFFDFF;
  }
  entry->color = 0xFF000000;
  length = TWindowKeyBoardSoft::strnlen(str, (u32)(0x100));
  hide_ticks = (s16) ((3.3f * ((f32) length)) + 55.5f);
  if (TWindowSubStatusDisp::get_card_window_scale((int) ((s32) client_index)) > 0.0f)
  {
    open_tick = 0;
  }
  play_sound_effect(0x53705, 0, 0, 0);
  if (state != 0)
  {
    state = 5U;
  }
}

#pragma pop
void TWindowFukidasi::open(u32 *symbol, s32 flags) {
    s32 restart;
    u8 current;

    restart = 0;
    init_flags(flags);
    if (content_kind != 1) {
        content_kind = 1U;
        entry_list.destroy_all_items();
        ((TWindowSubSymbolChat *)&entry_list)->init_layout_entries(client_index);
        if (state != 0) {
            restart = 1;
        }
    } else {
        current = state;
        if ((current != 0) && (current != 4)) {
            restart = 1;
        }
    }
    if (restart != 0) {
        state = 5U;
        clear_flag();
        if (TWindowSubStatusDisp::get_card_window_scale(client_index) > 0.0f) {
            open_tick = 0;
        }
    }
    set_symbol_chat_parts(&entry_list, symbol);
    TWindowSubSymbolChat::play_symbol_sound(((u32) *symbol >> 5U) & 0xF);
    hide_ticks = 0x5A;
}

#pragma push
#pragma fp_contract on
s32 TWindowFukidasi::clamp_position(f32 *pos, f32 scale_factor) {
    f32 min_x;
    f32 max_x;
    f32 min_y;
    f32 max_y;
    s32 clamped;

    clamped = 0;
    min_x = 20.0f + TWindowCtrlMain::get_left(this->client_index);
    if (pos[0] < min_x) {
        pos[0] = min_x;
        clamped = 1;
    }
    max_x = (TWindowCtrlMain::get_right(this->client_index) - 20.0f) - (this->frame_size[0] * scale_factor);
    if (pos[0] > max_x) {
        pos[0] = max_x;
        clamped = 1;
    }
    min_y = 40.0f + TWindowCtrlMain::get_top(this->client_index);
    if (pos[1] < min_y) {
        pos[1] = min_y;
        clamped = 1;
    }
    max_y = (TWindowCtrlMain::get_bottom(this->client_index) - 40.0f) - (this->frame_size[1] * scale_factor);
    if (pos[1] > max_y) {
        pos[1] = max_y;
        clamped = 1;
    }
    return clamped;
}

#pragma pop
void TWindowFukidasi::set_color(u16 color) {
    this->balloon_color = 0xFFF8F8F8;
    TObjChara *chara;
    if (((u32)color < 0xCU) && ((chara = get_player_by_client_id((u32)color)) != 0) && (chara->obj_isState3_324() == 0)) {
        this->balloon_color = (s32) balloon_color_table[(u16)color];
    }
}

#pragma push
#pragma fp_contract on
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

#pragma pop
void TWindowFukidasi::update_reveal_timer() {
    u32 flags;

    if (is_active() != 0 && open_tick < 0x1000000) {
        open_tick += TWindowSubStatusDisp::get_card_window_flags(client_index) + 1;
    }
    flags = window_flags;
    if ((flags & 2) && (!(flags & 1) || (flags & 4))) {
        window_flags &= ~4;
        request_balloon_hide();
    }
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::follow_anchor() {
    f32 cx;
    f32 cy;
    f32 dx;
    f32 dy;

    cx = 0.5f * target_size[0] + target_position[0];
    cy = 0.5f * target_size[1] + target_position[1];
    if (balloon_flags & 0x40) {
        balloon_center[0] = cx;
        balloon_center[1] = cy;
    } else {
        dx = 0.21f * (cx - balloon_center[0]);
        dy = 0.21f * (cy - balloon_center[1]);
        if (fabs_float(dx) < 0.1f) {
            balloon_center[0] = cx;
        } else {
            balloon_center[0] += dx;
        }
        if (fabs_float(dy) < 0.1f) {
            balloon_center[1] = cy;
        } else {
            balloon_center[1] += dy;
        }
    }
    if (tween_ticks == 0) {
        frame_size[0] = target_size[0];
        frame_size[1] = target_size[1];
    } else {
        frame_size[0] += (target_size[0] - frame_size[0]) / (f32)tween_ticks;
        frame_size[1] += (target_size[1] - frame_size[1]) / (f32)tween_ticks;
        tween_ticks--;
    }
    frame_position[0] = balloon_center[0] - 0.5f * frame_size[0];
    frame_position[1] = balloon_center[1] - 0.5f * frame_size[1];
    clamp_position(frame_position, tail_scale);
    balloon_center[0] = 0.5f * frame_size[0] + frame_position[0];
    balloon_center[1] = 0.5f * frame_size[1] + frame_position[1];
    project_anchor(NULL, head_position);
}

s32 TWindowFukidasi::is_speaker_far_or_offscreen() {
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
    if (this->is_flag_set() != 0) {
        m = -50.0f;
    } else {
        m = 0.0f;
    }
    if (scr[0] < TWindowCtrlMain::get_left(client_index) - m) {
        return 1;
    }
    if (scr[1] < TWindowCtrlMain::get_top(client_index) - m) {
        return 1;
    }
    if (scr[0] > m + TWindowCtrlMain::get_right(client_index)) {
        return 1;
    }
    if (scr[1] > m + TWindowCtrlMain::get_bottom(client_index)) {
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
    this->set_balloon_visible();
    return this->get_flag_bit1() != 0 ? 1 : 0;
}

#pragma pop
s32 TWindowFukidasi::project_anchor(f32 *pos, f32 *out) {
    TObjCollidable *e;
    f32 tmp[3];

    if (speaker_id == 0xFFFF) {
        return 0;
    }
    e = find_entity_by_id(speaker_id);
    if (e == NULL) {
        return 0;
    }
    if (get_player_by_client_id(speaker_id) != 0 && (u32)TObjPlayer::get_battle_ctrl_flag(speaker_id) == 0) {
        return 0;
    }
    if (pos == NULL) {
        pos = tmp;
    }
    pos[0] = e->position.x;
    pos[1] = e->position.y + scale;
    pos[2] = e->position.z;
    if (out == NULL) {
        return 1;
    }
    push_matrix();
    project_world_to_screen(0, (const Vec *)pos, out);
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

// Dead-stripped from the DOL: no code of it survives, only its literal (0.0,
// pooled between rest_balloon's 65536 and project_anchor's 320). It clears
// the width init_balloon zeroes when it sets the balloon up.
// from that role.
void TWindowFukidasi::clear_width() {
    frame_size[0] = 0.0f;
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::refresh_rect_placement() {
    if (is_speaker_far_or_offscreen() != 0) {
        const NJS_POINT2 *m;
        if (slot == -1) {
            set_flag();
            set_flag2c_bit200();
            slot = alloc_nearest_free_slot();
        }
        m = TWindowCtrl::get_message_by_type(slot, client_index);
        target_position[0] = m->x - 0.5f * target_size[0];
        target_position[1] = m->y - 0.5f * target_size[1];
        clamp_position(target_position, 1.0f);
    } else {
        f32 a[2];
        f32 c[2];
        f32 d[2];
        f32 e[2];
        f32 *res;
        if (slot != -1) {
            clear_visible_flag();
            clear_flag2c_bit200();
            TWindowCtrl::release_slot(&slot);
        }
        res = NULL;
        if (is_overlapped() == 0) {
            if (shift_rect_with_head(target_position, a) != 0) {
                res = a;
            }
            if (rest_balloon(a, c) != 0) {
                res = c;
            }
        } else {
            clear_overlapped();
            if (shift_rect_with_head(target_position, a) != 0) {
                res = a;
            }
            if (try_place_bubble(a, d) != 0) {
                res = d;
            }
            if (res != d && rest_balloon(d, c) != 0) {
                res = c;
            }
            if (res == NULL && find_random_free_position(target_position, e) != 0) {
                res = e;
            }
        }
        if (res != NULL) {
            target_position[0] = res[0];
            target_position[1] = res[1];
        }
    }
}

#pragma pop
s32 TWindowFukidasi::shift_rect_with_head(f32 *rect, f32 *out) {
    f32 x = head_position[0];
    f32 y = head_position[1];
    project_anchor(0, head_position);
    out[0] = rect[0] + (head_position[0] - x);
    out[1] = rect[1] + (head_position[1] - y);
    clamp_position(out, 1.0f);
    if (draw_resolved_window(out, target_size, 4) == 0) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 TWindowFukidasi::rest_balloon(f32 *rect, f32 *out) {
    NJS_POINT2 *o = (NJS_POINT2 *)out;
    f32 world[3];
    f32 edge[2];
    f32 dist;
    f32 dx;
    f32 dy;
    f32 reach;
    f32 t;
    s32 a;
    s32 angle;
    project_anchor(world, NULL);
    reach = 1000.0f / xyz_distance(&camera_ctrl_instance->pos, world);
    dx = (0.5f * frame_size[0] + rect[0]) - head_position[0];
    dy = (0.5f * frame_size[1] + rect[1]) - head_position[1];
    dist = newton_sqrtf(dx * dx + dy * dy);
    if (dist < 3.0f) {
        angle = 0xD400;
    } else {
        a = (s32) (10430.38043493439 * ((f64)atan2_float(dy, dx)));
        edge[0] = dx - reach * cos_table_lookup(a);
        edge[1] = dy - reach * sin_table_lookup(a);
        edge[0] /= 14.0f + frame_size[0];
        edge[1] /= 10.0f + frame_size[1];
        angle = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    }
    get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    if (fabs_float(dist - newton_sqrtf(edge[0] * edge[0] + edge[1] * edge[1])) < 10.0f) {
        return 0;
    }
    o->x = (head_position[0] + edge[0]) - 0.5f * target_size[0];
    o->y = (head_position[1] + edge[1]) - 0.5f * target_size[1];
    if (clamp_position(&o->x, 1.0f) != 0) {
        return 0;
    }
    if (draw_resolved_window(&o->x, target_size, 4) == NULL) {
        return 1;
    }
    t = 0.000030517578f * (f32) rand();
    edge[0] += t * (dx - edge[0]);
    edge[1] += t * (dy - edge[1]);
    o->x = (head_position[0] + edge[0]) - 0.5f * target_size[0];
    o->y = (head_position[1] + edge[1]) - 0.5f * target_size[1];
    if (draw_resolved_window(&o->x, target_size, 4) == NULL) {
        return 1;
    }
    angle = (s32) ((f32) a + (32768.0f * (0.000030517578f * (f32) rand()) - 16384.0f));
    get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o->x = (head_position[0] + edge[0]) - 0.5f * target_size[0];
    o->y = (head_position[1] + edge[1]) - 0.5f * target_size[1];
    if (clamp_position(&o->x, 1.0f) != 0) {
        return 0;
    }
    if (draw_resolved_window(&o->x, target_size, 4) == NULL) {
        return 1;
    }
    angle = (s32) (65536.0f * (0.000030517578f * (f32) rand()));
    get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o->x = (head_position[0] + edge[0]) - 0.5f * target_size[0];
    o->y = (head_position[1] + edge[1]) - 0.5f * target_size[1];
    if (clamp_position(&o->x, 1.0f) != 0) {
        return 0;
    }
    return (u32) __cntlzw((uaddr) draw_resolved_window(&o->x, target_size, 4)) >> 5;
}

#pragma push
#pragma fp_contract on
s32 TWindowFukidasi::try_place_bubble(f32 *rect, f32 *o) {
    f32 world[3];
    f32 edge[2];
    f32 dx;
    f32 dy;
    f32 reach;
    s32 a;
    s32 angle;
    project_anchor(world, NULL);
    reach = 1000.0f / xyz_distance(&camera_ctrl_instance->pos, world);
    dx = (0.5f * frame_size[0] + rect[0]) - head_position[0];
    dy = (0.5f * frame_size[1] + rect[1]) - head_position[1];
    a = (s32) (10430.38043493439 * ((f64)atan2_float(dy, dx)));
    edge[0] = dx - reach * cos_table_lookup(a);
    edge[1] = dy - reach * sin_table_lookup(a);
    edge[0] /= 14.0f + frame_size[0];
    edge[1] /= 10.0f + frame_size[1];
    angle = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    get_boundary_offset(angle + 0x8000, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o[0] = (head_position[0] + edge[0]) - 0.5f * target_size[0];
    o[1] = (head_position[1] + edge[1]) - 0.5f * target_size[1];
    if (clamp_position(o, 1.0f) != 0) {
        return 0;
    }
    if (draw_resolved_window(o, target_size, 4) == NULL) {
        return 1;
    }
    angle = (s32) ((f32) a + (32768.0f * (0.000030517578f * (f32) rand()) - 16384.0f));
    get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o[0] = (head_position[0] + edge[0]) - 0.5f * target_size[0];
    o[1] = (head_position[1] + edge[1]) - 0.5f * target_size[1];
    if (clamp_position(o, 1.0f) != 0) {
        return 0;
    }
    return (u32) __cntlzw((uaddr) draw_resolved_window(o, target_size, 4)) >> 5;
}

#pragma pop
s32 TWindowFukidasi::find_random_free_position(f32 *rect, f32 *out) {
    f32 x = TWindowCtrlMain::get_left(client_index);
    f32 w = (TWindowCtrlMain::get_right(client_index) - TWindowCtrlMain::get_left(client_index)) - target_size[0];
    f32 y;
    f32 h;
    f32 t;
    t = 0.000030517578f * (f32) rand();
    out[0] = t * w + x;
    y = TWindowCtrlMain::get_top(client_index);
    h = (TWindowCtrlMain::get_bottom(client_index) - TWindowCtrlMain::get_top(client_index)) - target_size[1];
    t = 0.000030517578f * (f32) rand();
    out[1] = t * h + y;
    return (u32) __cntlzw((uaddr) draw_resolved_window(out, target_size, 4)) >> 5;
}

void TWindowFukidasi::place_rect_at_head_or_slot() {
    if (is_speaker_far_or_offscreen() != 0) {
        const NJS_POINT2 *m;
        if (slot == -1) {
            set_flag();
            set_flag2c_bit200();
            slot = alloc_nearest_free_slot();
        }
        m = TWindowCtrl::get_message_by_type(slot, client_index);
        target_position[0] = m->x - 0.5f * target_size[0];
        target_position[1] = m->y - 0.5f * target_size[1];
        clamp_position(target_position, 1.0f);
    } else {
        f32 p[2];
        if (slot != -1) {
            clear_visible_flag();
            clear_flag2c_bit200();
            TWindowCtrl::release_slot(&slot);
        }
        project_anchor((f32 *)(0), p);
        target_position[0] = p[0] - 0.5f * target_size[0];
        target_position[1] = p[1] - 0.5f * target_size[1];
    }
}

#pragma pop
// Dead-stripped from the DOL: no code of it survives, only its literals (1000, 0.5,
// 19 and 10430.38), pooled between
// approach's 0.011 and find_random_free_position's 2^-15. It aims from the
// middle of the 19-unit name plate draw_name_plate puts on the balloon's top edge at
// the tail tip draw_tail places 1000/distance short of the speaker, with the
// same atan2 scale.
s32 TWindowFukidasi::calc_name_plate_angle(f32 *world, f32 *scr, f32 *rect, f32 *size) {
    f32 reach = 1000.0f / xyz_distance(&camera_ctrl_instance->pos, world);
    f32 dx = (0.5f * size[0] + rect[0]) - scr[0];
    f32 dy = ((0.5f * size[1] + rect[1]) - 19.0f) - (scr[1] - reach);
    return (s32) (10430.38043493439 * atan2_float(dy, dx));
}

void TWindowFukidasi::request_balloon_hide() {
    if (!(this->balloon_flags & 0x10)) {
        this->state = 7;
    }
}

s32 TWindowFukidasi::approach(f32 target) {
    f32 x;

    x = 0.47f * (target - this->tail_scale);
    if (fabs_float(x) < 0.011f) {
        this->tail_scale = target;
        return 1;
    }
    this->tail_scale = (f32) (this->tail_scale + x);
    return 0;
}

void TWindowFukidasi::sync_display_pos() { this->content_scale[0] = this->tail_scale; this->content_scale[1] = this->tail_scale; }

void TWindowFukidasi::calc_text_size(f32 *out) {
    WindowTextEntry *e;
    switch (content_kind) {
    case 0:
        e = (WindowTextEntry *)get_array_entry(0);
        out[0] = 0.1f + (8.0f + e->width);
        out[1] = 0.1f + (20.0f + e->height);
        break;
    case 1:
        get_symbol_chat_frame_size(&entry_list, out);
        break;
    case 2:
        break;
    }
}

void TWindowFukidasi::clamp_text_size(f32 *out) {
    f32 size[2];
    calc_text_size(size);
    if (target_size[0] > size[0]) {
        out[0] = size[0];
    } else {
        out[0] = target_size[0];
    }
    if (target_size[1] > size[1]) {
        out[1] = size[1];
    } else {
        out[1] = target_size[1];
    }
}

s32 TWindowFukidasi::check_card_match_enabled(const char *text) {
    if (content_kind != 0) {
        return 0;
    }
    return (u32) __cntlzw(strcmp(static_cast<WindowTextEntry *>(get_array_entry(0))->get_text(), text)) >> 5;
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::rearm_balloon(saddr flags) {
    u32 n;

    if (is_closed() != 0) {
        state = 5;
    }
    init_flags(flags);
    switch (content_kind) {
    case 0:
        n = TWindowKeyBoardSoft::strnlen(static_cast<WindowTextEntry *>(get_array_entry(0))->get_text(), (u32)0x100);
        hide_ticks = (s16) ((3.3f * (f32) n) + 55.5f);
        break;
    case 1:
        hide_ticks = 0x5A;
        break;
    case 2:
        break;
    }
}

#pragma pop
s32 TWindowFukidasi::is_speech_balloon_ready() {
    s32 t = content_kind;
    switch (t) {
    case 0:
        return static_cast<WindowTextEntry *>(get_array_entry(0))->is_fully_shown();
    case 1:
    case 2:
        break;
    }
    return 0;
}

void TWindowFukidasi::show_immediately() {
    s32 t;
    state = 4;
    balloon_flags |= 0x40;
    calc_text_size(target_size);
    refresh_rect_placement();
    set_active();
    set_flag2c_bit100();
    save_position();
    tail_scale = 1.0f;
    sync_display_pos();
    open_tick = 0x186A0;
    t = content_kind;
    switch (t) {
    case 0:
        ((WindowTextEntry *)get_array_entry(0))->reveal_all();
        break;
    case 1:
    case 2:
        break;
    }
}
