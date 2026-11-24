#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TUnk_804EF440.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowSubStatusDisp_80338740.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include <string.h>

void fill_game_list_row(void *row, s32 locked, const char *name, s8 player_count, s8 max_players, s8 difficulty, s8 mark, s8 level, s32 index) {
    saddr len;
    if (locked != 0) {
        *(s8 *)((s8 *)row + 0x1C) = 0x18;
    } else {
        *(s8 *)((s8 *)row + 0x1C) = 0x33;
    }
    len = (s32)measure_string_len(name);
    *(s32 *)((s8 *)row + 0x24) = (saddr)mem_alloc((len + 1));
    strncpy((char *)(*(saddr *)((s8 *)row + 0x24)), name, (int)len);
    *(s8 *)((s8 *)len + (*(s32 *)((s8 *)row + 0x24))) = 0;
    *(s8 *)((s8 *)row + 0x1D) = level;
    *(s8 *)((s8 *)row + 0x1E) = mark;
    *(s8 *)((s8 *)row + 0x1F) = difficulty;
    *(s8 *)((s8 *)row + 0x20) = player_count;
    *(s8 *)((s8 *)row + 0x21) = max_players;
    *(s32 *)((s8 *)row + 0x18) = index;
    *(u16 *)((s8 *)row + 0) = (u16) (*(u16 *)((s8 *)row + 0) | 5);
}

extern "C" {
void TWindowSubStatusDisp__sub_803387F8(void *arg0, s8 arg1) {
    (saddr)TWindowSubStatusDisp::get_message_10(arg1 + 0x113);
}
saddr TWindowSubStatusDisp::query_status_field(void *arg0, s8 arg1) {
    if (arg1 == 0) {
        return 0;
    }
    return (saddr)TWindowSubStatusDisp::get_message_10(arg1 + 0x110);
}
saddr TWindowSubStatusDisp::get_flag_or_zero(void *arg0, s8 arg1) {
    if (arg1 == 0) {
        return 0;
    }
    return (saddr)TWindowSubStatusDisp::get_message_10(arg1 + 0x10D);
}

void TUnk_804EF440::render(WindowDrawContext *context) {
  WindowDrawContext *win = context;
  f32 scale;
  f32 y;
  ItemListPosition pos;
  static const char *separator = "/";
  if (TWindowSubStatusDisp__sub_80338B88(this) == 0)
  {
    return;
  }
  y = win->inner_y + this->y;
  if ((this->height + y) < win->clip_y0)
  {
    return;
  }
  if ((win->inner_y + this->y) > win->clip_y1)
  {
    return;
  }
  if (win->open_tick < 0)
  {
    return;
  }
  pos.x = win->inner_x + this->x;
  pos.y = win->inner_y + this->y;
  scale = -1.0f / (0.1495f + win->depth);
  draw_item_list_icon(win, &pos, (u8)this->icon, -1, scale);
  pos.x += 18.0f;
  set_text_draw_params(win, 1, 1, (f32)scale, 100000.0f);
  draw_window_text((f32 *)&pos, this->text, -1, 1, 100000.0f);
  pos.x += 210.0f;
  draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_flag_or_zero(this, this->m_1d)), -1, 0, 100000.0f);
  pos.x += 108.0f;
  draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::query_status_field(this, this->m_1e)), -1, 0, 100000.0f);
  pos.x += 96.0f;
  draw_window_text((f32 *)&pos, (const char *)(((saddr (*)(void *, s8)) TWindowSubStatusDisp__sub_803387F8)(this, this->m_1f)), -1, 0, 100000.0f);
  pos.x += 126.0f;
  text_builder_reset();
  text_builder_append_int(this->m_20);
  text_builder_append((u8 *)separator);
  text_builder_append_int(this->m_21);
  draw_window_text((f32 *)&pos, (const char *)(get_shared_text_buffer()), -1, 0, 100000.0f);
}

void TUnk_804EF440::update() {}

TUnk_804EF440::~TUnk_804EF440() {
    if (this->text != NULL) {
        mem_free(this->text);
        this->text = NULL;
    }
}

TUnk_804EF440::TUnk_804EF440(u8 *rec, s32 m_2) : TUnk_804CF998(m_2) {
    this->height = 18.0f;
    this->icon = 51;
    this->m_1d = -1;
    this->m_1e = -1;
    this->m_1f = -1;
    this->m_20 = -1;
    this->m_21 = -1;
    this->text = NULL;
    this->m_18 = 0;
}

int TWindowSubStatusDisp__sub_80338B88(void* p) { return (*(u16*)((char*)p + 0x0) >> 2) & 0x1; }

}
