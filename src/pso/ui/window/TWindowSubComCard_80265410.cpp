#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowAddition.h"
#include <stddef.h>
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"


#pragma readonly_strings on

extern "C" {
struct Rec_802655E4 { s32 a; s32 b; };

struct Win_802655E4 { u8 p0[0x72]; s16 f72; s16 f74; s16 f76; u8 p78[8]; Rec_802655E4 *f80; };

struct Rec_802656D8 { u32 flags; s32 b; };

struct Ent_802656D8 { u8 p0[0x24]; s32 f24; };

struct Win_802656D8 { u8 p0[0x80]; Rec_802656D8 *f80; };



struct Ent_80265C30 { u8 pad[0x8]; f32 x; u8 padc[4]; f32 w; f32 h; };


struct Ent_80265E60 { u8 pad[0x14]; f32 h; };

struct Ent_80265F60 { u8 pad[0x10]; f32 w; f32 h; };


struct Ent_80265AA4 { u32 flags; u32 x; };

struct Card_80265AA4 {
    u8 pad0[0x74];
    s16 cur;
    s16 cnt;
    u8 pad1[8];
    Ent_80265AA4 *ents;
};

struct Ent_80265C30;

s32 play_sound_effect(s32, s32, s32, s32);
void measure_message_text_width(Ent_80265C30 *e, f32 x);
void TWindowSubComCard__sub_80265500(TWindowMenu *menu);
s32 TWindowSubComCard__sub_80265660(TWindowMenu *menu, s16 row);
void TWindowSubComCard__sub_80265680(TWindowMenu *menu, s16 row);
void fn_80266378(s32 rows);

u8 * init_shop_judgment_window(void* p);
saddr create_window_menu_default(saddr pos, s32 entries);
saddr create_titled_window_menu_default(saddr pos, s32 entries, saddr title);
}
void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
saddr create_titled_window_menu(saddr position, s32 count, saddr title, s32 client_id);
const f64 lbl_8044F330 = 0.0;
// The TWindowMenu layout table (one type-3 text record; fn_80266378 sets the row count) and
// the window descriptor the TWindowMenu constructor passes to TWindowAddition.
struct MenuWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec;
};
MenuWindowLayout lbl_804D05A8 = {1, 0, {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, 0}};
WindowDescriptor lbl_804D05CC = {{0.0f, 0.0f}, 50050.0f, &lbl_804D05A8, 3};
const char *lbl_805D3960 = "TWindowMenu";
extern s32 actor_frame_tick;

void TKeyBoardControl::set_composer_flag62_bit4() {
    TWindowKeyBoardBase *keyboard = m_base;
    if (keyboard != NULL) {
        keyboard->set_flag62_bit4();
    }
}

int TWindowMenuInfomation::get_flag() { return (m_70 >> 2) & 1; }

void TWindowMenuInfomation::clear_flag_and_release2() {
    m_70 &= ~2;
    if (heading != NULL) {
        heading->set_entry_state(1);
    }
}

void TWindowSubComCardList::update_scroll_target_position() {
    NJS_POINT2 extent;
    WindowScrollBar *scroll = scroll_bar;
    if (scroll != NULL) {
        extent.x = (frame_size[0] - 4.0f) - 9.0f;
        extent.y = (f32) ((entry_count * 0x14) - 2);
        scroll->set_extent(&extent);
    }
}

void TWindowSubComCard__sub_80265500(TWindowMenu *menu) {
    NJS_POINT2 scroll_range;
    f32 max_scroll_y;
    if (menu->scroll_bar != NULL) {
        scroll_range.x = 0.0f;
        max_scroll_y = menu->frame_size[1] - 20.0f;
        scroll_range.y = max_scroll_y;
        if (menu->heading != NULL) {
            scroll_range.y = max_scroll_y - 6.0f;
        }
        menu->scroll_bar->clamp_offset(menu->scroll_offset, &scroll_range);
    }
}

void TWindowSubComCardList::sub_8026556C() {
    NJS_POINT2 extent;
    f32 extent_x;
    if (scroll_bar == NULL) {
        extent_x = this->target_size[0] - 8.0f;
        extent.y = 0.0f;
        extent.x = extent_x;
        scroll_bar = new WindowScrollBar(&extent);
        this->window_flags = (s32) (this->window_flags | 0x80);
    }
}

void TWindowSubComCardList::reset_entries() {
    s32 i;
    Rec_802655E4 *r;
    void *e;
    ((Win_802655E4 *)this)->f72 = 0;
    ((Win_802655E4 *)this)->f74 = 0;
    r = ((Win_802655E4 *)this)->f80;
    for (i = 0; i < ((Win_802655E4 *)this)->f76; i++, r++) {
        e = ((void *)get_array_entry(i));
        TWindowDuelResult::set_default_status(e, 0);
        measure_message_text_width_default(e);
        r->a = 0;
        r->b = 0;
    }
}

s32 TWindowSubComCard__sub_80265660(TWindowMenu *menu, s16 row) {
    if (menu->rows[row].flags & 0x10) return 0;
    return 1;
}

void TWindowSubComCard__sub_80265680(TWindowMenu *menu, s16 row) {
    WindowTextEntry *entry = static_cast<WindowTextEntry *>(menu->get_array_entry(row));
    TWindowMenuRow *state = &menu->rows[row];
    entry->color = 0xFF909090;
    state->flags |= 0x10;
}

void TWindowSubComCard::set_entry_value_clear_flag(s32 idx, s32 val) {
    Win_802656D8 *w = (Win_802656D8 *)this;
    Ent_802656D8 *e = (Ent_802656D8 *)((TWindowBase *)w)->get_array_entry((s16)idx);
    Rec_802656D8 *r = w->f80;
    e->f24 = val;
    r[(s16)idx].flags &= ~0x10;
}

void *TWindowMenu::get_selected_entry() {
    s16 row;
    row = selected_row;
    if (row < 0) {
        return 0;
    }
    if (row >= row_count) {
        return 0;
    }
    return get_array_entry(row);
}

void TWindowMenu::set_active_flag() {
    if (!(this->m_70 & 8) && (is_decided() == 0)) {
        if (!(this->m_70 & 0x400)) {
            play_sound_effect(0x52F16, 0, 0, 0);
        }
        this->m_70 = (u16) (this->m_70 | 4);
    }
}

void TWindowMenu::confirm_selection() {
    u8 *arg0 = (u8 *)this;
    s32 row_flags;
    u8 *window_sub_status_disp;
    if (((int)((TWindowMenu *)arg0)->is_decided()) == 0) {
        row_flags = rows[selected_row].flags;
        if (row_flags & 0x10) {
            if (!(row_flags & 0x20)) {
                play_sound_effect(0x53F06, 0, 0, 0);
            }
        } else {
            if (!(row_flags & 0x20)) {
                play_sound_effect(0x52D01, 0, 0, 0);
            }
            this->m_70 = (u16) (this->m_70 | 2);
            window_sub_status_disp = (u8 *)this->heading;
            if (window_sub_status_disp != NULL) {
                ((TWindowSubStatusDisp *)window_sub_status_disp)->set_entry_state(2);
            }
        }
    }
}

void TWindowMenu::select_next_item() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = selected_row;
loop_1:
    var_r31 += 1;
    if (var_r31 >= row_count) {
        if (!(this->m_70 & 1)) {
            var_r31 = 0;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != selected_row) {
            if (sub_80266B18(var_r31) != 0) {
                selected_row = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}

void TWindowMenu::move_cursor_prev() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = selected_row;
loop_1:
    var_r31 -= 1;
    if (var_r31 < 0) {
        if (!(this->m_70 & 1)) {
            var_r31 = row_count - 1;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != selected_row) {
            if (sub_80266B18(var_r31) != 0) {
                selected_row = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowMenu::update_target_y() {
    f32 v;
    f32 t;
    f32 base;
    if (scroll_bar != 0 && this->tween_ticks == 0) {
        v = 9.0f + (f32)(this->selected_row * 0x14);
        v -= 0.5f * (this->frame_size[1] - 20.0f);
        if (heading != NULL) {
            v -= 3.0f;
        }
        t = this->scroll_offset[1];
        this->scroll_offset[1] = t + (v - t);
    }
}
#pragma pop

void TWindowMenu::clamp_menu_choice_scroll() {
    NJS_POINT2 scroll_range;
    f32 max_scroll_y;
    if (scroll_bar != NULL) {
        scroll_range.x = 0.0f;
        max_scroll_y = this->frame_size[1] - 20.0f;
        scroll_range.y = max_scroll_y;
        if (this->heading != 0) {
            scroll_range.y = max_scroll_y - 6.0f;
        }
        this->scroll_bar->clamp_offset(scroll_offset, &scroll_range);
    }
}

void TWindowMenu::advance_past_disabled_menu_rows() {
    u16 *e;
    s16 t;
    if (((Card_80265AA4 *)this)->cur < ((Card_80265AA4 *)this)->cnt) {
        e = ((u16 *)((TWindowBase *)((Card_80265AA4 *)this))->get_array_entry((s32)(((Card_80265AA4 *)this)->cur)));
        while (((u32)((TWindowSubComCard *)e)->get_field_20()) != 0 && (*e & 0x10)) {
            t = ((Card_80265AA4 *)this)->cur + 1;
            ((Card_80265AA4 *)this)->cur = t;
            if (t >= ((Card_80265AA4 *)this)->cnt) {
                break;
            }
            e = ((u16 *)((TWindowBase *)((Card_80265AA4 *)this))->get_array_entry((s32)(((Card_80265AA4 *)this)->cur)));
            if (((Card_80265AA4 *)this)->ents[((Card_80265AA4 *)this)->cur].flags & 2) {
                ((Card_80265AA4 *)this)->ents[((Card_80265AA4 *)this)->cur].flags &= ~2;
                *e &= ~8;
            }
        }
    }
}

#pragma fp_contract on
void TWindowMenu::update_scroll_value() {
    u8 *arg0 = (u8 *)this;
  u8 *new_var2;
  f32 v;
  u32 *new_var;
  u32 n;
  new_var = &this->tween_ticks;
  if ((*((u16 *)(arg0 + 0x70))) & 0x20)
  {
    v = *((f32 *) (static_cast<u8 *>(reinterpret_cast<TWindowMenu *>(arg0)->get_selected_entry()) + 0xC));
  }
  else
  {
    v = 0.0f;
    new_var = &this->tween_ticks;
  }
  n = *new_var;
  if (n == 0)
  {
    this->scroll_offset[1] = v;
    return;
  }
  v += 0.5f * ((this->target_size[1]) - (this->frame_size[1]));
  new_var2 = (u8 *)&this->scroll_offset[1];
  *((f32 *) new_var2) += (v - (this->scroll_offset[1])) / ((f32) n);
}

s32 TWindowMenu::get_selected_value() {
    return rows[selected_row].value;
}

void TWindowSubComCardList::set_selected_index(s16 index) {
    if ((index >= 0) && (index < row_count)) {
        selected_row = index;
    }
}

#pragma push
#pragma fp_contract on
void align_menu_entry_positions(TWindowMenu *self) {
    f32 left = self->target_size[0] - 8.0f;
    f32 right = 0.5f * self->target_size[0] - 4.0f;
    u32 i;
    for (i = 0; i < self->row_count; i++) {
        Ent_80265C30 *e = (Ent_80265C30 *)self->get_array_entry(i);
        if (((TWindowSubComCard *)e)->get_field_20() != 0) {
            measure_message_text_width(e, left);
            if (e->h > 18.0f) {
                e->x = 0.0f;
            } else {
                e->x = right - 0.5f * e->w;
            }
        }
    }
}
#pragma pop

void TWindowSubComCard::calc_layout_height(f32 width) {
    f32 h;
    u32 i;
    Ent_80265C30 *e;
    h = 0.0f;
    for (i = 0; i < *(s16 *)(((u8 *)this) + 0x76); i++) {
        e = (Ent_80265C30 *)((TWindowBase *)this)->get_array_entry(i);
        if (((TWindowSubComCard *)e)->get_field_20() != 0 && !(e->h <= lbl_8044F330)) {
            measure_message_text_width(e, width);
            h += 2.0f + e->h;
        }
    }
    h -= 2.0f;
    if (this->m_2c & 0x40) {
        h += 6.0f;
    }
    this->width = width;
    *(f32 *)(((u8 *)this) + 0x3C) = 20.0f + h;
    *(f32 *)(((u8 *)this) + 0x7C) = h;
    ((TWindowBase *)((u8 *)this))->save_position();
}

void TWindowSubComCardList::set_scroll_target(f32 width, f32 farg1) {
    update_layout_height(width);
    if (this->target_size[1] > farg1) {
        sub_8026556C();
    }
    this->target_size[1] = farg1;
    layout_height = (f32) (farg1 - 20.0f);
    save_position();
    update_scroll_target_position();
}

void TWindowMenu::update_layout_height(f32 x) {
    f32 sum = 0.0f;
    u32 i;
    for (i = 0; i < row_count; i++) {
        Ent_80265E60 *e = ((Ent_80265E60 *)this->TWindowBase::get_array_entry(i));
        if (reinterpret_cast<TWindowSubComCard *>(e)->get_field_20() != 0) {
            if (!(e->h <= lbl_8044F330)) {
                sum += 2.0f + e->h;
            }
        }
    }
    sum -= 2.0f;
    if (window_flags & 0x40) {
        sum += 6.0f;
    }
    target_size[0] = x;
    target_size[1] = 20.0f + sum;
    layout_height = sum;
    save_position();
}

void TWindowMenu::calc_window_size() {
    f32 width = 0.0f;
    f32 row_gap = 2.0f;
    f32 sum = width;
    f64 minimum_entry_height = lbl_8044F330;
    u32 i;
    for (i = 0; i < row_count; i++) {
        Ent_80265F60 *e = static_cast<Ent_80265F60 *>(get_array_entry(i));
        if (reinterpret_cast<TWindowSubComCard *>(e)->get_field_20() != 0) {
            if (e->w > width) {
                width = e->w;
            }
            if (!(e->h <= minimum_entry_height)) {
                sum += row_gap + e->h;
            }
        }
    }
    sum -= 2.0f;
    layout_height = sum;
    if (window_flags & 0x40) {
        sum += 6.0f;
    }
    target_size[0] = 8.0f + width;
    target_size[1] = 20.0f + sum;
    save_position();
}

void TWindowMenu::layout_entries() {
    f32 gap;
    f64 zero;
    f32 y;
    u32 i;
    u8 *e;
    f32 h;
    y = 0.0f;
    gap = 2.0f;
    zero = lbl_8044F330;
    for (i = 0; i < row_count; i++) {
        e = (u8 *)get_array_entry(i);
        if (((TWindowSubComCard *)e)->get_field_20() != 0) {
            *(f32 *)(e + 0xC) = y;
            h = *(f32 *)(e + 0x14);
            if (!(h <= zero)) {
                y += gap + h;
            }
        }
    }
}

void TWindowMenu::clear_transition_flag() {
    u16 flags = m_70;
    if (flags & 0x20) {
        m_70 = flags & ~0x20;
        target_size[1] = 20.0f + layout_height;
        tween_ticks = 3;
    }
}

void TWindowMenu::open() {
    u16 open_flags;
    WindowTextEntry *selected_entry;

    open_flags = m_70;
    if (!(open_flags & 0x20)) {
        m_70 = (u16) (open_flags | 0x20);
        selected_entry = static_cast<WindowTextEntry *>(get_selected_entry());
        target_size[1] = 20.0f + selected_entry->height;
        if (window_flags & 0x40) {
            target_size[1] += 6.0f;
        }
        tween_ticks = 3;
    }
}

void add_gray_text_entry(TWindowMenu *list, const char *text, s32 kind, s32 id) {
    list->add_text_entry((saddr)text, kind | 0x10, id, 0xFF909090);
}

s32 TWindowMenu::add_text_entry(saddr text, s32 flags, s32 id, s32 color) {
    s16 row_index;
    WindowTextEntry *entry;
    TWindowMenuRow *row;

    if (entry_count >= row_count) {
        return 0;
    }
    entry = static_cast<WindowTextEntry *>(get_array_entry(entry_count));
    row_index = entry_count;
    row = &rows[row_index];
    entry->y = (f32)(row_index * 0x14);
    entry->color = color;
    if (flags & 1) {
        set_text_entry_string((u8 *)entry, text, 0x20);
    } else {
        set_text_entry_string((u8 *)entry, text, 0);
    }
    if (flags & 4) {
        entry->flags |= 1;
    }
    if (flags & 8) {
        entry->flags |= 0x40;
    }
    if (flags & 0x40) {
        entry->flags |= 0x200;
    }
    if (flags & 2) {
        if (entry_count == row_cursor) {
            flags &= ~2;
        } else {
            entry->flags |= 8;
        }
    }
    if (m_70 & 0x100) {
        ((TWindowHelpItem *)entry)->reset_float_field();
    }
    measure_message_text_width_default(entry);
    row->flags = flags;
    row->value = id;
    entry_count++;
    return 1;
}

s32 TWindowMenu::add_text_entry(saddr text, s32 flags, s32 id) {
    return add_text_entry(text, flags, id, -1);
}

void fn_80266378(s32 rows) {
    lbl_804D05A8.rows = rows;
}

TWindowMenu *create_yes_no_window(const NJS_POINT2 *position, s32 id, const char *yes_text, const char *no_text) {
  TWindowMenu *window_menu = create_window_menu((saddr)position, 2, id);
  if (yes_text == NULL)
  {
    window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5B)), 6, 0);
  }
  else
  {
    window_menu->add_text_entry((saddr)yes_text, 6, 0);
  }
  if (no_text == NULL)
  {
    window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5C)), 6, 1);
  }
  else
  {
    window_menu->add_text_entry((saddr)no_text, 6, 1);
  }
  window_menu->calc_window_size();
  if (window_menu->frame_size[0] < 104.0f)
  {
    window_menu->update_layout_height(104.0f);
  }
  align_menu_entry_positions(window_menu);
  window_menu->set_ready_flag();
  window_menu->set_depth(50030.0f);
  return window_menu;
}

u8 * init_shop_judgment_window(void* p) { return (u8 *)create_yes_no_window((const NJS_POINT2 *)p, 4, NULL, NULL); }

TWindowMenu *create_window_menu(saddr position, s32 count, s32 client_id) {
    fn_80266378(count);
    return new TWindowMenu(count, client_id, position);
}

saddr create_window_menu_default(saddr pos, s32 entries) {
    return reinterpret_cast<saddr>(create_window_menu(pos, entries, 4));
}

saddr create_titled_window_menu(saddr position, s32 count, saddr title, s32 client_id) {
    saddr menu;
    saddr heading_window;
    saddr var_r0;
    menu = reinterpret_cast<saddr>(create_window_menu(position, count, client_id));
    heading_window = (saddr)::operator new(0x24);
    var_r0 = heading_window;
    if (var_r0 != 0) {
        var_r0 = (saddr)((TWindowSubStatusDisp *)heading_window)->construct_type1_heading(title, client_id);
    }
    reinterpret_cast<TWindowMenu *>(menu)->heading = reinterpret_cast<TWindowSubStatusDisp *>(var_r0);
    *(s32 *)((s8 *)menu + 0x2C) = (s32) (*(s32 *)((s8 *)menu + 0x2C) | 0x40);
    return menu;
}

saddr create_titled_window_menu_default(saddr pos, s32 entries, saddr title) {
    return create_titled_window_menu(pos, entries, title, 4);
}

void TWindowMenu::draw_selected_bar(WindowDrawContext *context) {
    s16 selected_row;
    u16 *entry;
    if (!(actor_frame_tick & 0x10)) {
        selected_row = *(s16 *)&this->unk_7A;
        if (selected_row >= 0) {
            entry = (u16 *)(((saddr)get_array_entry((s32) selected_row)));
            if (*entry & 1) {
                draw_selection_bar(context, (u8 *)entry, 1);
            }
        }
    }
}

void TWindowMenu::render_selected_entry(WindowDrawContext *context) {
    u16 *entry;

    entry = (u16 *)this->get_array_entry(selected_row);
    if (*entry & 1) {
        draw_selection_bar(context, (u8 *)entry, is_decided());
    }
}

void TWindowMenu::render() {
    WindowDrawContext *ctx;

    ctx = this->get_draw_context();
    draw_window_frame(ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        ctx);
    if (!(this->m_70 & 0x80)) {
        this->render_selected_entry(ctx);
        this->draw_selected_bar(ctx);
    }
    if (this->heading != 0) {
        this->heading->forward_render(ctx);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, ctx, scroll_offset);
    }
}

void TWindowMenu::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 player_idx;
    ControllerInputContext *input;
    ControllerInputContext *temp_r29_2;
    ControllerInputContext *context;

    ((TWindowMenu *)this)->layout_entries();
    if (!(*(s32 *)&this->window_flags & 2)) {
        *(s32 *)&this->open_tick = 0x01000000;
    }
    if ((((TWindowMenu *)arg0)->sub_80266BB8() == 0) && (((TWindowMenu *)arg0)->is_decided() == 0) && ((s32) *(s32 *)&this->open_tick > 2) && (is_window_display_enabled() != 0) && (((TWindowBase *)arg0)->sub_80244994() != 0)) {
        player_idx = is_player_input_active((this->client_index));
        if (this->m_70 & 0x10) {
            input = &controller_input_state.controllers[player_idx];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (is_locked(0x10) != 0)) {
                move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (is_locked(0x20) != 0)) {
                select_next_item();
            }
        } else {
            temp_r29_2 = &controller_input_state.controllers[player_idx];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x10, 6, 1) != 0) || (is_locked(0x10) != 0)) {
                move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x20, 6, 1) != 0) || (is_locked(0x20) != 0)) {
                select_next_item();
            }
        }
        context = &controller_input_state.controllers[player_idx];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (((TWindowMenu *)arg0)->test_menu_flag(4) != 0)) {
            confirm_selection();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (((TWindowMenu *)arg0)->test_menu_flag(2) != 0)) {
            set_active_flag();
        }
    }
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        if (this->heading != 0) {
            this->heading->update_subwindow();
        }
        if (scroll_bar != NULL) {
            scroll_bar->increment_counter();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowMenu *)arg0)->update_scroll_value();
    ((TWindowAddition *)arg0)->step_window_tween();
    ((TWindowMenu *)arg0)->update_target_y();
    ((TWindowMenu *)arg0)->clamp_menu_choice_scroll();
    ((TWindowMenu *)arg0)->advance_past_disabled_menu_rows();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowMenu::~TWindowMenu() {
    TWindowSubStatusDisp::destroy_allocation((saddr)scroll_bar, (s16)1);
    TWindowSubStatusDisp::destroy_status_display((saddr)heading, (s16)1);
    mem_free(rows);
}

TWindowMenu::TWindowMenu(u32 count, s32 client, saddr parent) : TWindowAddition((u8 *)&lbl_804D05CC, (s16)client, (u8 *)parent) {
    #define window_menu ((u8 *)this)
    u32 i;
    u8 *p;
    *(const char **)window_menu = lbl_805D3960;
    *(s16 *)(window_menu + 0x72) = 0;
    *(s16 *)(window_menu + 0x74) = 0;
    *(u16 *)(window_menu + 0x76) = count;
    *(s16 *)(window_menu + 0x78) = 0;
    *(s16 *)(window_menu + 0x70) = 0;
    *(s16 *)(window_menu + 0x20) = client;
    ((TWindowMenu *)window_menu)->reset_selection();
    *(u8 **)(window_menu + 0x80) = (u8 *)mem_alloc(count * 8);
    p = *(u8 **)(window_menu + 0x80);
    for (i = 0; i < count; i++) {
        *(s32 *)p = 0;
        *(s32 *)(p + 4) = 0;
        p += 8;
    }
    *(s32 *)(window_menu + 0x88) = 0;
    *(s32 *)(window_menu + 0x84) = 0;
    #undef window_menu
}

#pragma push
#pragma scheduling off
void WindowScrollBar::set_extent(const NJS_POINT2 *size) {
    extent.x = size->x;
    extent.y = size->y;
}
#pragma pop

s32 TWindowAddition::sub_80266B18(s32 index) {
    return *(u16 *)((s8 *)(*(u16 **)((s8 *)(*(saddr *)((s8 *)((u8 *)this) + 0x28) + (index * 4)) + 0)) + 0) & 1;
}

s32 TWindowMenu::test_menu_flag(s32 buttons) {
    if (this->m_70 & 0x200) {
        return 0U;
    }
    return test_controller_flag_4c_color(&controller_input_state.keyboard, buttons);
}

s32 TWindowMenu::is_locked(s32 buttons) {
    if (this->m_70 & 0x200) {
        return 0;
    }
    return test_buttons_press_or_repeat(&controller_input_state.keyboard, (s32)buttons, 6, 1);
}

int TWindowMenu::sub_80266BB8() { return (this->m_70 >> 6) & 0x1; }
