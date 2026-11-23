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

  ItemListRow(u8 *rec, s32 m_2);
  virtual ~ItemListRow();
  virtual void update();
  virtual void render(WindowDrawContext *context);
  s32 get_item();
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
void *__ct__11ItemListRowFPUcl(void *p, u8 *rec, s32 m_2);
}

#endif
