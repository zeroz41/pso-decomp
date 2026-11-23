#ifndef PSO_UI_ITEMLISTROW_H
#define PSO_UI_ITEMLISTROW_H

#include "types.h"
#include "pso/unk/TUnk_804CF998.h"

// A window list row: two icons, a label and a suffix (case 8 of init_window_layout_entries).
class ItemListRow : public TUnk_804CF998
{
public:
  s32 item;
  u8 status_icon;
  u8 category_icon;
  u8 pad1e[2];
  char *label;
  char *suffix;
  s32 status_style;
  s32 category_style;
  s32 style;
  s32 suffix_style;

  ItemListRow(u8 *rec, s32 client);
  virtual ~ItemListRow();
  virtual void update();
  virtual void render(WindowDrawContext *context);
  s32 get_item();
  void advance_state();
  void finalize_state();
  void reset();
  void update_stat_line(s32 value);
  void update_stat_line_if_positive(s32 count);
  void update_item_icon_colors(void *item);
  void update_item_colors(saddr item);
  void select_item_icon(s32 item_data, u8 arg2, u8 arg3, s32 arg4);
  void setup_entry_msg_d1(s32 arg1);
  void setup_entry_msg_d0(s32 arg1);
  void init_no_item_entry(s32 arg1);
  void init_entry(u8 status_icon, u8 category_icon, u8 status_style, u32 src, s32 item);
  void setup_stat_line(s32 src, s32 arg2, s32 arg3);
  void init_status_entry_by_flag(s32 flag, u32 src, s32 item);
  void init_list_entry(u8 icon, s32 src, s32 arg3);
  void init_status_entry(u8 category_icon, u32 src, s32 item);
  void set_inventory_item(void *item, s32 count, s32 sid);
  void update_from_player(void *item, s32 price, s32 index);
  void init_item_row(void *item, s32 arg2);
  void set_item_info(void *a1, s32 index, s32 count);
  void set_ground_item(void *it, s32 index);
  void init_display(s32 src, s32 arg2);
  saddr replace_owned_string(saddr src, saddr buf, s32 mask, s32 copy);
  void calc_row_width();
};

struct ItemListPosition
{
  f32 x;
  f32 y;
};

#include <stddef.h>
LAYOUT_ASSERT(ItemListRow_size, sizeof(ItemListRow) == 0x38);
LAYOUT_ASSERT(ItemListRow_icons_offset, offsetof(ItemListRow, status_icon) == 0x1C);
LAYOUT_ASSERT(ItemListRow_label_offset, offsetof(ItemListRow, label) == 0x20);

extern "C" {
void draw_item_list_icon(WindowDrawContext *context, ItemListPosition *position, s32 icon, s32 style, f32 depth);
// ItemListRow::ItemListRow(u8 *, s32), called by init_window_layout_entries.
void *__ct__11ItemListRowFPUcl(void *p, u8 *rec, s32 client);
}

#endif
