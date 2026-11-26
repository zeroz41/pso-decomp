#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TGameListRow.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include <string.h>

void TGameListRow::fill(s32 locked, const char *name, s8 player_count, s8 max_players, s8 difficulty, s8 mark, s8 level, s32 index) {
    saddr len;
    if (locked != 0) {
        this->icon = 0x18;
    } else {
        this->icon = 0x33;
    }
    len = measure_string_len(name);
    this->text = (char *)mem_alloc(len + 1);
    strncpy(this->text, name, len);
    *((s8 *)len + (saddr)this->text) = 0;
    this->level = level;
    this->mark = mark;
    this->difficulty = difficulty;
    this->player_count = player_count;
    this->max_players = max_players;
    this->index = index;
    this->flags |= 5;
}

const char *TGameListRow::get_difficulty_text(s8 difficulty) {
    return (const char *)TWindowSubStatusDisp::get_message_10(difficulty + 0x113);
}

const char *TGameListRow::get_mark_text(s8 mark) {
    if (mark == 0) {
        return NULL;
    }
    return (const char *)TWindowSubStatusDisp::get_message_10(mark + 0x110);
}

const char *TGameListRow::get_level_text(s8 level) {
    if (level == 0) {
        return NULL;
    }
    return (const char *)TWindowSubStatusDisp::get_message_10(level + 0x10D);
}

void TGameListRow::render(WindowDrawContext *context) {
  WindowDrawContext *win = context;
  f32 scale;
  f32 y;
  ItemListPosition pos;
  static const char *separator = "/";
  if (get_flag_4_bit() == 0)
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
  draw_window_text((f32 *)&pos, get_level_text(this->level), -1, 0, 100000.0f);
  pos.x += 108.0f;
  draw_window_text((f32 *)&pos, get_mark_text(this->mark), -1, 0, 100000.0f);
  pos.x += 96.0f;
  draw_window_text((f32 *)&pos, get_difficulty_text(this->difficulty), -1, 0, 100000.0f);
  pos.x += 126.0f;
  text_builder_reset();
  text_builder_append_int(this->player_count);
  text_builder_append(separator);
  text_builder_append_int(this->max_players);
  draw_window_text((f32 *)&pos, (const char *)(get_shared_text_buffer()), -1, 0, 100000.0f);
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
    this->level = -1;
    this->mark = -1;
    this->difficulty = -1;
    this->player_count = -1;
    this->max_players = -1;
    this->text = NULL;
    this->index = 0;
}

int TGameListRow::get_flag_4_bit() { return (this->flags >> 2) & 1; }

