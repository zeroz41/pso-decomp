#include "types.h"
#include <string.h>
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/unk/TWindowLayoutRect.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/unk/text_803DA798.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/map/FloorArea.h"
#include "pso/render/render_util.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/PlayerSlots.h"
#include "pso/item/item_create.h"
#include "pso/unk/TLobby_8001D6A0.h"

#pragma readonly_strings on


// HUD sprite-sheet pixel origin (u, v) of each item icon, indexed by get_entry_ptr.
extern const NJS_POINT2 status_disp_item_icon_coord_table[51] = {
    { 161.0f, 98.0f },
    { 179.0f, 98.0f },
    { 197.0f, 98.0f },
    { 215.0f, 98.0f },
    { 233.0f, 98.0f },
    { 161.0f, 116.0f },
    { 179.0f, 116.0f },
    { 197.0f, 116.0f },
    { 215.0f, 116.0f },
    { 233.0f, 116.0f },
    { 161.0f, 134.0f },
    { 179.0f, 134.0f },
    { 197.0f, 134.0f },
    { 215.0f, 134.0f },
    { 233.0f, 134.0f },
    { 161.0f, 152.0f },
    { 179.0f, 152.0f },
    { 197.0f, 152.0f },
    { 215.0f, 152.0f },
    { 233.0f, 152.0f },
    { 161.0f, 170.0f },
    { 179.0f, 170.0f },
    { 197.0f, 170.0f },
    { 215.0f, 170.0f },
    { 233.0f, 170.0f },
    { 233.0f, 224.0f },
    { 197.0f, 224.0f },
    { 215.0f, 224.0f },
    { 72.0f, 238.0f },
    { 90.0f, 238.0f },
    { 108.0f, 238.0f },
    { 126.0f, 238.0f },
    { 161.0f, 188.0f },
    { 179.0f, 188.0f },
    { 197.0f, 188.0f },
    { 215.0f, 188.0f },
    { 233.0f, 188.0f },
    { 161.0f, 206.0f },
    { 179.0f, 206.0f },
    { 197.0f, 206.0f },
    { 215.0f, 206.0f },
    { 233.0f, 206.0f },
    { 161.0f, 224.0f },
    { 179.0f, 224.0f },
    { 54.0f, 238.0f },
    { 197.0f, 80.0f },
    { 215.0f, 80.0f },
    { 233.0f, 80.0f },
    { 197.0f, 62.0f },
    { 215.0f, 62.0f },
    { 233.0f, 62.0f },
};

void ItemListRow::advance_state() {
    if ((u8) this->category_icon == 0x14) {
        this->category_icon = 0x15U;
    }
}

void ItemListRow::finalize_state() {
    if ((u8) this->category_icon == 0x15) {
        this->category_icon = 0x14U;
    }
}


void ItemListRow::reset() {
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->status_style = -1;
    this->category_style = -1;
    this->style = -1;
    this->suffix_style = -1;
    this->item = 0;
    if (this->suffix != NULL && (this->flags & 0x10)) {
        mem_free(this->suffix);
    }
    this->suffix = NULL;
    if (this->label != NULL && (this->flags & 8)) {
        mem_free(this->label);
    }
    this->label = NULL;
    this->flags = (u16) (this->flags & ~0x1BFD);
}



void ItemListRow::update_stat_line(s32 value) {
    text_builder_reset();
    text_builder_append("\xD7");
    text_builder_append_int(value);
    this->suffix = replace_owned_string(get_shared_text_buffer(), this->suffix, 0x10, 1);
}

void ItemListRow::update_stat_line_if_positive(s32 count) {
    if (count > 0) {
        update_stat_line(count);
    }
}


void ItemListRow::update_item_icon_colors(TItem *item) {
    s16 requirement;
    s32 item_flags;
    s32 equip_requirements;
    s32 usable_action_flags;
    s32 identified;
    TObjPlayer *player;

    if (item->is_wrapped() != 0) {
        this->style = -1;
        return;
    }
    player = get_player_by_client_id(this->client);
    if (player != 0) {
        item_flags = item->test_item_flags(8);
        usable_action_flags = item->get_usable_action_flags(0x10, player);
        equip_requirements = item->check_equip_requirements(player, &requirement);
        identified = item->is_identified();
        if (usable_action_flags != 0) {
            if (item_flags != 0) {
                this->status_icon = 0x30;
            } else {
                this->status_icon = 0x2F;
            }
        } else if (item_flags != 0) {
            this->status_icon = 0xC;
        } else {
            if ((identified == 0) && (item->is_rare_item() != 0)) {
                this->status_icon = 0x19;
            } else if (requirement & 1) {
                this->status_icon = 0x13;
            } else {
                this->status_icon = 0x33;
            }
            this->status_style = -1;
        }
        if (identified == 0) {
            this->category_style = -1;
            this->style = 0xFF00FFFC;
            return;
        }
        if (equip_requirements != 0) {
            this->category_style = -1;
            if (item->is_custom_name_srank() != 0) {
                this->style = 0xFFFE3C28;
                return;
            }
            if (item->get_name_style() == 2) {
                this->flags |= 0x800;
                return;
            }
            if ((u8)item->calc_display_grade() >= 9U) {
                this->style = -0x1600;
                return;
            }
            if (item->has_bonus_stats() != 0) {
                this->style = 0xFF61E853;
                return;
            }
            if (item->get_usable_action_flags(0x10000, player) != 0U) {
                this->style = 0xFF909090;
                return;
            }
            this->style = -1;
            return;
        }
        if (requirement & 1) {
            this->style = 0xFF909090;
            this->category_style = 0xFFAAAAAA;
            return;
        }
        this->style = 0xFF909090;
        this->category_style = 0xFFAAAAAA;
    }
}

void ItemListRow::update_item_colors(TItemData *item) {
    s32 requirement;
    s32 equip_requirements;
    s32 item_flags;
    TObjPlayer *player;

    if (TItemData::is_wrapped(item) != 0) {
        this->style = -1;
        return;
    }
    player = get_player_by_client_id(this->client);
    if (player != NULL) {
        equip_requirements = check_equip_requirements(player, item, &requirement);
        item_flags = item->check_item_flags();
        if ((u8) this->status_icon == 0x33) {
            if ((item_flags == 0) && (TItemData::is_rare_item(item) != 0)) {
                this->status_icon = 0x19U;
            } else if (requirement & 1) {
                this->status_icon = 0x13U;
            }
            this->status_style = -1;
        }
        if (item_flags == 0) {
            this->category_style = -1;
            this->style = 0xFF00FFFC;
            return;
        }
        if (equip_requirements != 0) {
            this->category_style = -1;
            if (TItemData::is_custom_name_srank(item) != 0) {
                this->style = 0xFFFE3C28;
                return;
            }
            if (item->get_name_style() == 2) {
                this->flags |= 0x800;
                return;
            }
            if ((u8)item->calc_display_grade() >= 9U) {
                this->style = -0x1600;
                return;
            }
            if (item->has_bonus_stats() != 0) {
                this->style = 0xFF61E853;
                return;
            }
            if (item->calc_action_flags(0x10000, player) != 0U) {
                this->style = 0xFF909090;
                return;
            }
            this->style = -1;
            return;
        }
        if (requirement & 1) {
            this->style = 0xFF909090;
            this->category_style = 0xFFAAAAAA;
            return;
        }
        this->style = 0xFF909090;
        this->category_style = 0xFFAAAAAA;
    }
}

void ItemListRow::select_item_icon(s32 item_data, u8 item_type, u8 item_group, s32 wrapped) {
    if (wrapped != 0) {
        this->category_icon = 8;
        return;
    }
    switch (item_data) {
    case 1:
        this->category_icon = 0;
        return;
    case 3:
        this->category_icon = 1;
        return;
    case 2:
        this->category_icon = 2;
        return;
    default:
        switch ((s32) item_type) {
        case 1:
            if (item_group == 3) {
                this->category_icon = 4;
                return;
            }
            if (item_group == 2) {
                this->category_icon = 0xA;
                return;
            }
            this->category_icon = 0xB;
            return;
        case 2:
            this->category_icon = 3;
            return;
        case 3:
            if (item_group == 0) {
                this->category_icon = 5;
                return;
            }
            if (item_group == 1) {
                this->category_icon = 7;
                return;
            }
            if (item_group == 2) {
                this->category_icon = 6;
                return;
            }
            this->category_icon = 8;
            return;
        case 4:
            this->category_icon = 9;
            return;
        case 0:
        default:
            this->category_icon = 0x33;
            return;
        }
        break;
    }
}

void ItemListRow::setup_entry_msg_d1(s32 item) {
    this->x = -18.0f;
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->label = replace_owned_string((const char *)TWindowSubStatusDisp::get_message_10(0xD1), this->label, 8, 1);
    this->style = 0xFF909090;
    this->item = item;
    this->flags |= 0xC5;
}

void ItemListRow::setup_entry_msg_d0(s32 item) {
    this->x = 0.0f;
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->label = replace_owned_string((const char *)TWindowSubStatusDisp::get_message_10(0xD0), this->label, 8, 1);
    this->style = 0xFF909090;
    this->item = item;
    this->flags |= 0xC5;
}

void ItemListRow::init_no_item_entry(s32 item) {
    this->x = 0.0f;
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->label = replace_owned_string((const char *)TWindowSubStatusDisp::get_message_10(0xCF), this->label, 8, 1);
    this->style = 0xFF909090;
    this->item = item;
    this->flags |= 0xC5;
}

void ItemListRow::init_entry(u8 status_icon, u8 category_icon, u8 status_style, u32 src, s32 item) {
    this->x = 0.0f;
    this->status_icon = status_icon;
    this->category_icon = category_icon;
    this->status_style = (s32) status_style;
    this->category_style = -1;
    this->label = replace_owned_string((const char *)src, this->label, 8, 1);
    this->style = -1;
    this->item = item;
    this->flags |= 0x245;
}

void ItemListRow::init_meseta(s32 meseta, s32 item) {
    this->x = 0.0f;
    this->status_icon = 0x33;
    this->category_icon = 9;
    text_builder_reset();
    text_builder_append_int(meseta);
    text_builder_append((const char *)TWindowSubStatusDisp::get_meseta_unit());
    this->suffix = replace_owned_string(get_shared_text_buffer(), this->suffix, 0x10, 1);
    this->suffix_style = -1;
    this->item = item;
    this->flags |= 0x45;
}

void ItemListRow::setup_stat_line(s32 src, s32 stat, s32 item) {
    this->x = 0.0f;
    this->status_icon = 0x33;
    this->category_icon = 0x2D;
    this->label = replace_owned_string((const char *)src, this->label, 8, 1);
    update_stat_line(stat);
    this->item = item;
    if (stat <= 0) {
        this->style = 0xFF909090;
        this->category_style = 0xFFAAAAAA;
        this->flags |= 0xC5;
    } else if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        this->style = 0xFF909090;
        this->category_style = 0xFFAAAAAA;
        this->flags |= 0x45;
    } else {
        this->style = -1;
        this->category_style = -1;
        this->flags |= 0x45;
    }
    this->suffix_style = (s32) this->style;
}
void ItemListRow::init_status_entry_by_flag(s32 flag, u32 src, s32 item) {
    u8 category_icon;
    if (flag) {
        category_icon = 0x14;
    } else {
        category_icon = 0x15;
    }
    init_status_entry(category_icon, src, item);
    this->x = -18.0f;
}

void ItemListRow::init_list_entry(u8 icon, s32 src, s32 item) {
    u8 status_icon_value;

    status_icon_value = icon;
    this->x = -18.0f;
    if (icon == 0x18) {
        status_icon_value = 0x16;
    }
    this->status_icon = status_icon_value;
    this->category_icon = 0x33;
    this->status_style = -1;
    this->category_style = -1;
    this->label = replace_owned_string((const char *)src, this->label, 8, 1);
    this->style = -1;
    this->suffix_style = -1;
    this->item = item;
    this->flags |= 0x145;
    if (icon == 0x18) {
        this->flags |= 0x80;
        this->style = 0xFF909090;
    }
}
void ItemListRow::init_status_entry(u8 category_icon, u32 src, s32 item) {
    this->x = -18.0f;
    this->status_icon = 0x33;
    this->category_icon = category_icon;
    this->status_style = -1;
    this->category_style = -1;
    this->label = replace_owned_string((const char *)src, this->label, 8, 1);
    this->style = -1;
    this->suffix_style = -1;
    this->item = item;
    this->flags |= 0x45;
}


void ItemListRow::set_inventory_item(TItem *item, s32 count, s32 sid) {
    s32 item_data;

    this->x = 0.0f;
    item_data = item->get_icon_index();
    select_item_icon(item_data, item->get_item_type(), item->get_item_group(), item->is_wrapped());
    this->label = replace_owned_string(item->get_name(), this->label, 8, 1);
    if (item->is_stackable() != 0) {
        update_stat_line_if_positive(count);
    }
    update_item_icon_colors(item);
    this->suffix_style = (s32) this->style;
    this->item = sid;
    this->flags |= 0x45;
}

void ItemListRow::update_from_player(TItem *item, s32 price, s32 index) {
    s32 item_data;

    this->x = 0.0f;
    item_data = item->get_icon_index();
    select_item_icon(item_data, item->get_item_type(), item->get_item_group(), item->is_wrapped());
    this->label = replace_owned_string(item->get_name(), this->label, 8, 1);
    if (TCameraCtrl::get_camera_id() <= 2) {
        text_builder_reset();
        text_builder_append_int(price);
        this->suffix = replace_owned_string(get_shared_text_buffer(), this->suffix, 0x10, 1);
    }
    update_item_icon_colors(item);
    this->item = index;
    this->flags |= 0x45;
}
void ItemListRow::init_item_row(TItem *item, s32 index) {
    s32 item_data;
    this->x = 0.0f;
    item_data = item->get_icon_index();
    select_item_icon(item_data, item->get_item_type(), item->get_item_group(), item->is_wrapped());
    this->label = replace_owned_string(item->get_name(), this->label, 8, 1);
    if (item->is_stackable() != 0) {
        s32 v = item->get_amount();
        update_stat_line_if_positive(v);
    }
    update_item_icon_colors(item);
    this->suffix_style = (s32) this->style;
    this->item = index;
    this->flags |= 0x45;
}




void ItemListRow::set_item_info(TItemData *item, s32 index, s32 count) {
    saddr item_data;

    this->x = 0.0f;
    this->status_icon = 51;
    item_data = get_item_data((uaddr)item);
    select_item_icon(item_data, item->data1.data_u8[0], item->data1.data_u8[1], TItemData::is_wrapped(item));
    forward_message((saddr)get_shared_text_buffer(), (uaddr)(void *)item);
    this->label = replace_owned_string(get_shared_text_buffer(), this->label, 8, 1);
    update_stat_line_if_positive(count);
    update_item_colors(item);
    this->suffix_style = this->style;
    this->item = index;
    this->flags = (this->flags | 0x45);
}



extern "C" {
u32 calc_text_width(char *s);
}

void ItemListRow::set_ground_item(TItemData *item, s32 index) {
    s32 item_data;

    this->x = 0.0f;
    this->status_icon = 0x33;
    item_data = get_item_data((uaddr)item);
    select_item_icon(item_data, item->data1.data_u8[0], item->data1.data_u8[1], TItemData::is_wrapped(item));
    forward_message((saddr)get_shared_text_buffer(), (uaddr)(void *)item);
    this->label = replace_owned_string(get_shared_text_buffer(), this->label, 8, 1);
    if (TCameraCtrl::get_camera_id() <= 2) {
        text_builder_reset();
        text_builder_append_int(item->data2.data_u32);
        this->suffix = replace_owned_string(get_shared_text_buffer(), this->suffix, 0x10, 1);
    }
    update_item_colors(item);
    this->item = index;
    this->flags |= 0x45;
}


void ItemListRow::init_display(s32 src, s32 item) {
    this->x = -36.0f;
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->label = replace_owned_string((const char *)src, this->label, 8, 1);
    this->style = -1;
    this->item = item;
    this->flags |= 0x45;
}

char *ItemListRow::replace_owned_string(const char *src, char *buf, s32 mask, s32 copy) {
    s32 n;
    if (buf != NULL && (this->flags & mask)) {
        this->flags &= ~mask;
        mem_free(buf);
    }
    if (src != NULL && copy != 0) {
        n = (s32)measure_string_len(src);
        buf = (char *)mem_alloc(n + 1U);
        strncpy(buf, src, n + 1);
        this->flags |= mask;
    } else {
        buf = (char *)src;
    }
    return buf;
}

void ItemListRow::calc_row_width() {
    this->width = 0.0f;
    if (this->is_flag_4_set() != 0) {
        if (this->status_icon != 0x33) {
            this->width += 36.0f;
        } else if (this->category_icon != 0x33) {
            this->width += 18.0f;
        }
        if (this->label != 0) {
            this->width += (f32)calc_text_width(this->label);
        }
        if (this->suffix != 0) {
            this->width += 9.0f;
            this->width += (f32)calc_text_width(this->suffix);
        }
    }
}

const NJS_POINT2 *get_entry_ptr(int index) {
    return &status_disp_item_icon_coord_table[(u8)index];
}


void draw_item_list_icon(WindowDrawContext *win, ItemListPosition *pos, s32 icon, s32 style, f32 depth) {
    TexturedQuad q;
    ItemListPosition *p;
    const NJS_POINT2 *entry;
    f32 scale;
    f32 offset;
    f32 edge;

    if ((u8)icon != 0x33) {
        p = pos;
        begin_screen_draw(1);
        set_texture_list(hud_texlist);
        set_draw_texture_and_color(1, style);
        entry = get_entry_ptr(icon);
        offset = 18.0f;
        scale = 0.00390625f;
        q.x0 = p->x;
        q.y0 = p->y;
        q.x1 = offset + p->x;
        q.y1 = offset + p->y;
        q.u0 = entry->x * scale;
        q.v0 = entry->y * scale;
        edge = offset + entry->x;
        q.u1 = edge * scale;
        edge = offset + entry->y;
        q.v1 = edge * scale;
        if (win->clip_and_transform_quad(&q) != 0) {
            draw_textured_quad_at_depth(&q.x0, depth);
        }
        end_screen_draw();
    }
}

typedef struct ItemListPosition ItemListPosition;
#pragma fp_contract on
void ItemListRow::render(WindowDrawContext *context) {
  WindowDrawContext *win = context;
  ItemListPosition pos;
  f32 y;
  f32 depth;
  s32 style;
  if (is_flag_4_set() != 0)
  {
    y = win->inner_y + this->y;
    if (((!((this->height + y) < win->clip_y0)) && (!((win->inner_y + this->y) > win->clip_y1))) && (win->open_tick >= 0))
    {
      pos.x = win->inner_x + this->x;
      pos.y = win->inner_y + this->y;
      depth = -1.0f / (0.14949999749660492f + win->depth);
      if (this->flags & 0x200)
      {
        draw_item_list_icon(win, &pos, this->status_icon, -1, depth);
        pos.x += 18.0f;
        draw_item_list_icon(win, &pos, this->category_icon, -1, depth);
        pos.x += 18.0f;
        draw_item_list_icon(win, &pos, (u8) this->status_style, -1, depth);
        pos.x += 18.0f;
      }
      else
      {
        set_additive_blend();
        if (this->flags & 0x100)
        {
          pos.x += 18.0f;
          draw_item_list_icon(win, &pos, this->status_icon, this->status_style, depth);
        }
        else
        {
          draw_item_list_icon(win, &pos, this->status_icon, this->status_style, depth);
          pos.x += 18.0f;
        }
        set_default_alpha_blend();
        draw_item_list_icon(win, &pos, this->category_icon, this->category_style, depth);
        pos.x += 18.0f;
      }
      if (this->flags & 0x1000)
      {
        set_text_draw_params(win, 1, 0, depth, (f32)win->clip_x1);
      }
      else
      {
        set_text_draw_params(win, 1, 1, depth, 100000.0f);
      }
      if (this->flags & 0x400)
      {
        pos.x = (0.5f * win->inner_w) + win->inner_x;
        pos.x = -((0.5f * ((f32) calc_text_width(this->label))) - pos.x);
      }
      if (this->flags & 0x800)
      {
        style = TWindowCtrl::get_pulse_color();
      }
      else
      {
        style = this->style;
      }
      if (this->flags & 0x1000)
      {
        draw_window_text((f32 *)&pos, this->label, style, 0, 100000.0f);
      }
      else
      {
        draw_window_text((f32 *)&pos, this->label, style, 1, 100000.0f);
      }
      f32 width = (f32) calc_text_width(this->suffix);
      pos.x = (win->inner_x + win->inner_w) - width;
      draw_window_text((f32 *)&pos, this->suffix, this->suffix_style, 1, 100000.0f);
    }
  }
}
void ItemListRow::update() {
    if (is_flag_4_set()) return;
}


ItemListRow::~ItemListRow() {
    u16 flags;

    if (this->suffix != 0) {
        flags = this->flags;
        if (flags & 0x10) {
            this->flags = flags & ~0x10;
            mem_free(this->suffix);
        }
    }
    if (this->label != 0) {
        flags = this->flags;
        if (flags & 8) {
            this->flags = flags & ~8;
            mem_free(this->label);
        }
    }
}

ItemListRow::ItemListRow(u8 *rec, s32 client) : TWindowLayoutRect(client) {
    this->height = 18.0f;
    this->status_icon = 51;
    this->category_icon = 51;
    this->label = 0;
    this->suffix = 0;
    this->status_style = -1;
    this->category_style = -1;
    this->style = -1;
    this->suffix_style = -1;
    this->item = 0;
}
