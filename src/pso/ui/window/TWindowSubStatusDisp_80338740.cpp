#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TGameListRow.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowSubStatusDisp_80338740.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include <string.h>

void fill_game_list_row(void *row_entry, s32 locked, const char *name, s8 player_count, s8 max_players, s8 difficulty, s8 mode, s8 episode, s32 index) {
    TGameListRow *row = (TGameListRow *)row_entry;
    saddr len;
    if (locked != 0) {
        row->icon = 0x18;
    } else {
        row->icon = 0x33;
    }
    len = (s32)measure_string_len(name);
    row->text = (char *)mem_alloc((len + 1));
    strncpy(row->text, name, (int)len);
    *(char *)(len + (saddr)row->text) = 0;
    row->episode = episode;
    row->mode = mode;
    row->difficulty = difficulty;
    row->player_count = player_count;
    row->max_players = max_players;
    row->index = index;
    row->flags |= 5;
}

void get_difficulty_name(void *unused, s8 value) {
    (saddr)TWindowSubStatusDisp::get_message_10(value + 0x113);
}
saddr TWindowSubStatusDisp::get_game_mode_name(void *unused, s8 value) {
    if (value == 0) {
        return 0;
    }
    return (saddr)TWindowSubStatusDisp::get_message_10(value + 0x110);
}
saddr TWindowSubStatusDisp::get_episode_name(void *unused, s8 value) {
    if (value == 0) {
        return 0;
    }
    return (saddr)TWindowSubStatusDisp::get_message_10(value + 0x10D);
}

void TGameListRow::render(WindowDrawContext *context) {
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
  set_text_draw_params(win, 1, 1, scale, 100000.0f);
  draw_window_text((f32 *)&pos, this->text, -1, 1, 100000.0f);
  pos.x += 210.0f;
  draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_episode_name(this, this->episode)), -1, 0, 100000.0f);
  pos.x += 108.0f;
  draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_game_mode_name(this, this->mode)), -1, 0, 100000.0f);
  pos.x += 96.0f;
  draw_window_text((f32 *)&pos, (const char *)(((saddr (*)(void *, s8)) get_difficulty_name)(this, this->difficulty)), -1, 0, 100000.0f);
  pos.x += 126.0f;
  text_builder_reset();
  text_builder_append_int(this->player_count);
  text_builder_append(separator);
  text_builder_append_int(this->max_players);
  draw_window_text((f32 *)&pos, get_shared_text_buffer(), -1, 0, 100000.0f);
}

void TGameListRow::update() {}

TGameListRow::~TGameListRow() {
    if (this->text != NULL) {
        mem_free(this->text);
        this->text = NULL;
    }
}

TGameListRow::TGameListRow(u8 *rec, s32 client) : TWindowLayoutRect(client) {
    this->height = 18.0f;
    this->icon = 51;
    this->episode = -1;
    this->mode = -1;
    this->difficulty = -1;
    this->player_count = -1;
    this->max_players = -1;
    this->text = NULL;
    this->index = 0;
}

int TWindowSubStatusDisp__sub_80338B88(void* p) { return (*(u16*)((char*)p + 0x0) >> 2) & 0x1; }

