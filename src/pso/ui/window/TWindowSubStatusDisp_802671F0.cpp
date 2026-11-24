#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/unk/text_801C53D4.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TUnk_804CE7E8.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_80266BD0.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowSubStatusDisp_80257BC0.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/player/PlayerSlots.h"

const char *TWindowMenuIconLine__name = "TWindowMenuIconLine";


void fn_80266BD0(s32 index, u8 *first, u8 *second, s32 player) {
    // pairs of entry codes handed to init_entry by TWindowSubShortCutList::draw_entry
    static const u8 entry_code_pairs[20][2] = {
        {0x33, 0x1C}, {0x33, 0x1E}, {0x33, 0x1F}, {0x33, 0x1D}, {0x1A, 0x1C}, {0x1A, 0x1E}, {0x1A, 0x1F},
        {0x1A, 0x1D}, {0x33, 0x20}, {0x33, 0x21}, {0x33, 0x22}, {0x33, 0x23}, {0x33, 0x24}, {0x33, 0x25},
        {0x33, 0x26}, {0x33, 0x27}, {0x33, 0x28}, {0x33, 0x29}, {0x33, 0x2A}, {0x33, 0x2B},
    };
    const u8 *entry = entry_code_pairs[index];
    *first = *entry++;
    if (*first == 0x1A && TWindowKeyBoardHard::test_card_flag_2(player) != 0) {
        *first = 0x1B;
    }
    *second = *entry;
}

extern "C" {


void TWindowSubTradeMain::update_trade_state() {
    if ((u32) this->m_80 != 0U) {
        if (((TWindowMenuIconLine *)this)->is_decided() != 0) {
            ((TWindowSubStatusDisp *)(this->m_80))->set_entry_state(2);
        } else {
            ((TWindowSubStatusDisp *)(this->m_80))->set_entry_state(1);
        }
    }
    clear_flag70_bit80();
    clear_flag();
}

void TWindowSubTradeMain::close() {
    set_visible();
    set_close_flag();
    if ((u32) this->m_80 != 0U) {
        ((TWindowSubStatusDisp *)(this->m_80))->set_entry_state(0);
    }
}

}

extern "C" {

// Puts the cursor back on the saved row, or the nearest selectable row above it.
void TWindowMenuIconLine::clamp_selection_to_valid_entry() {
    void *e;
    if (entry_count >= 0) {
        if (saved_cursor >= entry_count) {
            cursor = entry_count - 1;
            return;
        }
        e = get_array_entry(saved_cursor);
        while (((TWindowLayoutEntry *)e)->is_flag_4_set() == 0) {
            saved_cursor = saved_cursor - 1;
            e = get_array_entry(saved_cursor);
        }
        cursor = saved_cursor;
    }
}

void TWindowMenuIconLine::save_cursor_selection() {
    saved_cursor = cursor;
    saved_cursor_value = get_cursor_value();
}
void TWindowMenuIconLine::reset_list() {
    u32 i;
    this->entry_count = 0;
    this->cursor = 0;
    for (i = 0; i < (u32)this->entry_capacity; i++) {
        ((ItemListRow *)get_array_entry(i))->reset();
    }
}

}

extern "C" {
u32 calc_text_width();
u8 get_font_char_advance();
u16 map_char_to_font_code(u16 c);
s32 lbl_804D05F8[3] = {1, 0, 8};
WindowDescriptor lbl_804D0604 = {
    {0.0f, 0.0f}, 50050.0f, lbl_804D05F8, 3,
};

void fn_80266BD0(s32 index, u8 *first, u8 *second, s32 player);
s32 play_sound_effect(s32, s32, s32, s32);
s32 is_flag80_set__20TWindowSubStatusDispFv(s32);
}
void text_builder_reset();
s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width);
extern "C" {

void TShopJudgmentItemWindow__sub_80267F9C(const NJS_POINT2 *size, s32 count);

saddr TWindowMenuIconLine::get_cursor_value() {
    return ((ItemListRow *)get_array_entry(cursor))->get_item();
}

void TWindowMenuIconLine::calc_content_extent() {
    NJS_POINT2 extent;

    if (scroll_bar != NULL) {
        extent.x = frame_size[0] - 8.0f;
        if (scroll_bar != NULL) {
            extent.x -= 5.0f;
        }
        extent.y = (f32) (entry_count * 20 - 2);
        scroll_bar->set_extent(&extent);
    }
}

void TWindowMenuIconLine::clamp_scroll_offset() {
    NJS_POINT2 range;
    if (scroll_bar != NULL) {
        range.x = 0.0f;
        range.y = frame_size[1] - 20.0f;
        if (status_display != NULL) {
            range.y -= 6.0f;
        }
        scroll_bar->clamp_offset(scroll_offset, &range);
    }
}

void TWindowMenuIconLine::advance_line(s32 message) {
    int index;
    index = entry_count;
    if (index < entry_capacity) {
        ((ItemListRow *)get_array_entry(index))->setup_entry_msg_d1(message);
        entry_count++;
    }
}

void TWindowMenuIconLine::advance_status_disp_entry(s32 message) {
    int index;
    index = entry_count;
    if (index < entry_capacity) {
        ((ItemListRow *)get_array_entry(index))->setup_entry_msg_d0(message);
        entry_count++;
    }
}

void TWindowMenuIconLine::add_list_entry(s32 message) {
    int index;
    index = entry_count;
    if (index < entry_capacity) {
        ((ItemListRow *)(get_array_entry(index)))->init_no_item_entry(message);
        entry_count++;
    }
}

void TWindowSubShortCutList::draw_entry(s32 index, s32 status_style, s32 arg3, s32 item) {
    u8 status_icon;
    u8 category_icon;

    if ((s16) this->entry_count < (s16) this->entry_capacity) {
        fn_80266BD0(index, &status_icon, &category_icon, this->client_index);
        ((ItemListRow *)get_array_entry(this->entry_count))->init_entry(status_icon, category_icon, status_style, arg3, item);
        this->entry_count = (this->entry_count + 1);
    }
}

void TWindowMenuIconLine::push_status_disp_entry(s32 count, s32 id) {
    if (entry_count < entry_capacity) {
        TWindowSubStatusDisp__sub_80258A28((ItemListRow *)get_array_entry(entry_count), count, id);
        entry_count++;
    }
}

void TWindowMenuIconLine::add_battle_stat_entry(s32 stat, s32 item, s32 gray_out) {
    s32 value;
    ItemListRow *row;
    uaddr player;

    if (entry_count < entry_capacity) {
        player = (uaddr)get_player_by_client_id(client_index);
        if (player != 0U) {
            if (stat == 4) {
                value = fn_801C5404((s32 *)(player + 0x7C8));
            } else {
                value = (s8)((TObjPlayer *)(player + 0x7C4))->clamp_char_at(stat);
            }
            if (value > 0) {
                row = (ItemListRow *)get_array_entry(entry_count);
                row->setup_stat_line(get_localized_text_entry(0x10, stat + 0x13), value, item);
                if ((gray_out != 0) && ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0))) {
                    row->flags |= 0x80;
                }
                entry_count++;
            }
        }
    }
}

void TWindowCheckBox::advance_all_entries(s32 arg1) {
    s32 i;
    get_array_entry(this->cursor);
    if (((s32 (*)(void))is_flag80_set__20TWindowSubStatusDispFv)() == 0) {
        if (arg1 != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
        for (i = 0; i < this->entry_capacity; i++) {
            ((ItemListRow *)get_array_entry(i))->advance_state();
        }
        ((ItemListRow *)get_array_entry(this->cursor))->finalize_state();
    }
}

void TWindowSubStatusDisp::refresh_selected_entry(s32 arg1) {
    TWindowSubStatusDisp *entry;

    entry = static_cast<TWindowSubStatusDisp *>(get_array_entry(*(s16 *)((s8 *)this + 0x74)));
    if (entry->is_flag80_set() == 0) {
        if (arg1 != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
        ((ItemListRow *)entry)->finalize_state();
    }
}

void TWindowMenuIconLine::add_status_entry(s8 flags, s32 src, s32 item) {
    u8 category_icon;
    s16 index = entry_count;

    if (index < entry_capacity) {
        if (flags & 8) {
            category_icon = 0xD;
        } else if (flags & 4) {
            category_icon = 0xF;
        } else {
            category_icon = 0x33;
        }
        ItemListRow *row = static_cast<ItemListRow *>(get_array_entry(index));
        row->init_status_entry(category_icon, src, item);
        row->x = -18.0f;
        if (flags & 2) {
            row->status_icon = 0xE;
            row->flags |= 0x100;
        }
        ++entry_count;
    }
}

void TWindowSubStatusDisp::append_entry(s32 flag, s32 arg2, s32 item, s32 arg4, s32 arg5) {
    ItemListRow *row;
    s32 i;
    f32 k;
    ItemListRow *other;

    if (*(s16 *)(((u8 *)this) + 0x72) < *(s16 *)(((u8 *)this) + 0x76)) {
        row = (ItemListRow *)get_array_entry(*(s16 *)(((u8 *)this) + 0x72));
        row->init_status_entry_by_flag(flag, arg2, item);
        if (arg4 != 0) {
            row->flags |= 0x400;
        }
        if (arg5 != 0) {
            k = 40.0f;
            i = 0;
            row->flags |= 0x1000;
            while (i < *(s16 *)(((u8 *)this) + 0x76)) {
                other = (ItemListRow *)get_array_entry(i);
                other->y = k * (f32)i++;
            }
        }
        (*(s16 *)(((u8 *)this) + 0x72))++;
    }
}

void TWindowMenuIconLine::add_inventory_item(TItem *item, s32 count, s32 id) {
    int index;
    if (item != NULL) {
        index = entry_count;
        if (index < entry_capacity) {
            ((ItemListRow *)(get_array_entry(index)))->set_inventory_item(item, count, id);
            entry_count++;
        }
    }
}

void TWindowMenuIconLine::add_item(TItem *item, s32 price, s32 index) {
    int row;
    if (item != NULL) {
        row = entry_count;
        if (row < entry_capacity) {
            ((ItemListRow *)get_array_entry(row))->update_from_player(item, price, index);
            entry_count++;
        }
    }
}

void TWindowMenuIconLine::add_list_entry(TItem *item, s32 index) {
    int row;
    if (item != NULL) {
        row = entry_count;
        if (row < entry_capacity) {
            ((ItemListRow *)get_array_entry(row))->init_item_row(item, index);
            entry_count = entry_count + 1;
        }
    }
}

void TWindowMenuIconLine::add_item_info_entry(TItemData *item, s32 index, s32 count) {
    if (item != NULL) {
        if (entry_count < entry_capacity) {
            ((ItemListRow *)get_array_entry(entry_count))->set_item_info(item, index, count);
            entry_count++;
        }
    }
}

void TWindowMenuIconLine::add_ground_item(TItemData *item, s32 index) {
    if (item != NULL) {
        if (entry_count < entry_capacity) {
            ((ItemListRow *)get_array_entry(entry_count))->set_ground_item(item, index);
            entry_count++;
        }
    }
}

void TLobby::add_status_disp_entry(s32 src, s32 arg2) {
    TWindowMenuIconLine *list = (TWindowMenuIconLine *)this;
    if (list->entry_count < list->entry_capacity) {
        ItemListRow *entry = (ItemListRow *)list->get_array_entry(list->entry_count);
        entry->init_display(src, arg2);
        list->entry_count++;
    }
}

void TAdVIConfigGC__sub_80267704(s32 arg0) {
    lbl_804D0604.flags = arg0;
}

#pragma fp_contract on
void draw_item_list_capacity(void *, WindowDrawContext *context, s32 current_items, s32 capacity) {
  u8 new_var;
  NJS_POINT2 pt;
  if (context->open_tick >= 0)
  {
    pt.x = (166.0f + context->x) - 8.0f;
    pt.y = context->y - 13.0f;
    draw_window_tab(context, &pt.x, 0, -60.0f);
    pt.x += 50.0f;
    pt.y += 4.0f;
    set_text_draw_params(context, 0, 0, (f32)(-1.0f / (0.1794f + context->depth)), (f32)100000.0f);
    text_builder_reset();
    text_builder_append_int(current_items);
    get_shared_text_buffer();
    pt.x -= (f32) calc_text_width();
    map_char_to_font_code(0x2F);
    new_var = get_font_char_advance();
    pt.x -= 0.5f * new_var;
    text_builder_append((u8 *)"/");
    text_builder_append_int(capacity);
    draw_window_text((f32 *)&pt, (const char *)(get_shared_text_buffer()), -1, 0, (f32)100000.0f);
  }
}

void TWindowMenuIconLine::set_flag4() {
    if (!(this->state_flags & 8) && (is_decided() == 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state_flags = (u16) (this->state_flags | 4);
    }
}

void TWindowMenuIconLine::handle_open() {
    saddr entry;
    entry = reinterpret_cast<saddr>(get_array_entry(this->cursor));
    if ((((TWindowLayoutEntry *)entry)->is_flag_4_set() == 0) || (((TWindowSubStatusDisp *)entry)->is_flag80_set() != 0)) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    if (!(this->state_flags & 0x100)) {
        play_sound_effect(0x52D01, 0, 0, 0);
    }
    this->state_flags = (u16) (this->state_flags | 2);
    if (this->status_display != NULL) {
        ((TWindowSubStatusDisp *)(this->status_display))->set_entry_state(2);
    }
}

void TWindowMenuIconLine::move_cursor_next() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = this->cursor;
loop_1:
    var_r31 += 1;
    if (var_r31 >= (s16) this->entry_capacity) {
        if (!(this->state_flags & 1)) {
            var_r31 = 0;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) this->cursor) {
            if (sub_80266B18(var_r31) != 0) {
                this->cursor = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}

void TWindowMenuIconLine::move_cursor() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = this->cursor;
loop_1:
    var_r31 -= 1;
    if (var_r31 < 0) {
        if (!(this->state_flags & 1)) {
            var_r31 = this->entry_capacity - 1;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) this->cursor) {
            if (sub_80266B18(var_r31) != 0) {
                this->cursor = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}

void TWindowMenuIconLine::set_cursor_index(s16 index) {
    if (index >= 0) {
        if (index >= entry_capacity) {
            return;
        }
        while (sub_80266B18(index) == 0) {
            if (index > 0) {
                index -= 1;
                continue;
            }
            break;
        }
        cursor = index;
    }
}

void TWindowMenuIconLine::create_menu_scroll_bar() {
    NJS_POINT2 size;
    if (this->scroll_bar == NULL) {
        size.x = this->target_size[0] - 8.0f;
        size.y = 0.0f;
        this->scroll_bar = new WindowScrollBar(&size);
        this->window_flags |= 0x80;
    }
}

void TWindowMenuIconLine::ensure_status_display(s32 title) {
    uaddr var_r0;

    if ((uaddr) this->status_display == 0U) {
        var_r0 = (saddr)::operator new(0x24);
        if (var_r0 != 0U) {
            var_r0 = (uaddr)((TWindowSubStatusDisp *)var_r0)->construct_type1_heading(title, this->client_index);
        }
        *(u32 *)&this->status_display = var_r0;
        (this->window_flags) = (s32) ((this->window_flags) | 0x40);
    }
}

void TWindowMenuIconLine::start_scroll(f32 height) {
    u16 flags = state_flags;
    if (flags & 0x20) {
        state_flags = flags & ~0x20;
        target_size[1] = height;
        tween_ticks = 3;
    }
}

void TWindowSubStatusDisp::init_scroll_pos() {
    u16 temp_r4;
    void *temp;

    temp_r4 = *(u16 *)((s8 *)this + 0x70);
    if (!(temp_r4 & 0x20)) {
        *(u16 *)((s8 *)this + 0x70) = (u16) (temp_r4 | 0x20);
        temp = (u16 *)this->get_array_entry((s16)((*(s16 *)((s8 *)this + 0x74))));
        this->target_size[1] = (f32) (20.0f + *(f32 *)((s8 *)temp + 0x14));
        if (this->window_flags & 0x40) {
            this->target_size[1] += 6.0f;
        }
        this->tween_ticks = 3;
    }
}

#pragma push
#pragma fp_contract on
void TWindowMenuIconLine::center_list_selection() {
    f32 target;

    if ((this->scroll_bar != 0U) && (this->tween_ticks == 0U)) {
        f32 t = (*(f32 *)&this->frame_size[1] - 16.0f) - 10.0f;
        target = 9.0f + (f32) (this->cursor * 0x14);
        target -= 0.5f * t;
        scroll_offset[1] += target - scroll_offset[1];
    }
}
#pragma pop

void TWindowMenuIconLine::clamp_item_list_scroll() {
    NJS_POINT2 range;
    if (this->scroll_bar != NULL) {
        range.x = 0.0f;
        range.y = this->frame_size[1] - 20.0f;
        if (this->status_display != NULL) {
            range.y -= 6.0f;
        }
        scroll_bar->clamp_offset(scroll_offset, &range);
    }
}

#pragma fp_contract on
void TWindowMenuIconLine::update_scroll_offset() {
  s8 *new_var;
  f32 var_f4;
  u32 n;
  if ((this->state_flags) & 0x20)
  {
    new_var = ((s8 *) ((u16 *)get_array_entry(this->cursor))) + 0xC;
    var_f4 = *((f32 *) new_var);
  }
  else
  {
    var_f4 = 0.0f;
  }
  n = this->tween_ticks;
  if (n == 0)
  {
    this->scroll_offset[1] = var_f4;
  }
  else
  {
    var_f4 += 0.5f * ((this->target_size[1]) - (this->frame_size[1]));
    this->scroll_offset[1] += (var_f4 - (this->scroll_offset[1])) / ((f32) n);
  }
}

void TWindowMenuIconLine::draw_selected_list_entry(WindowDrawContext *context) {
    u16 *entry;

    if (!(this->state_flags & 0x80)) {
        entry = (u16 *)this->get_array_entry((s16)(this->cursor));
        if (*entry & 1) {
            draw_selection_bar(context, (u8 *)entry, ((TWindowMenuIconLine *)this)->is_decided());
        }
    }
}

#define self ((u8 *)this)
void TWindowMenuIconLine::init(u32 arg1, s32 arg2) {
    u32 i;
    u8 *e;
    *(const char **)self = TWindowMenuIconLine__name;
    *(s16 *)(self + 0x20) = arg2;
    *(s16 *)(self + 0x72) = 0;
    *(s16 *)(self + 0x74) = 0;
    *(u16 *)(self + 0x76) = arg1;
    *(s16 *)(self + 0x78) = 0;
    *(s32 *)(self + 0x7C) = 0;
    *(s16 *)(self + 0x70) = 0;
    *(s32 *)(self + 0x80) = 0;
    *(s32 *)(self + 0x84) = 0;
    for (i = 0; i < arg1; i++) {
        e = (u8 *)((TWindowBase *)self)->get_array_entry(i);
        *(f32 *)(e + 0xC) = (f32)(i * 0x14);
    }
}
#undef self

TWindowMenuIconLine *fn_80267F38(saddr parent, saddr position, uaddr count, s16 client) {
    ((s32 (*)(void *, void *))TShopJudgmentItemWindow__sub_80267F9C)((void *)position, (void *)count);
    return new TWindowMenuIconLine((u8 *)parent, count, client);
}

void TShopJudgmentItemWindow__sub_80267F9C(const NJS_POINT2 *size, s32 count) {
    lbl_804D0604.pad_00[0] = size->x;
    lbl_804D0604.pad_00[1] = size->y;
    lbl_804D05F8[1] = count;
}

void TWindowMenuIconLine::render() {
    WindowDrawContext *draw_context;

    draw_context = get_draw_context();
    draw_window_frame(draw_context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24),
        draw_context);
    this->draw_selected_list_entry(draw_context);
    if (this->status_display != 0) {
        ((TWindowSubStatusDisp *)this->status_display)->forward_render(draw_context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, draw_context, scroll_offset);
    }
}

void TWindowMenuIconLine::run_task() {
    s32 temp_r31;
    uaddr temp_r3;
    WindowScrollBar *temp_r3_2;
    ControllerInputContext *input;
    ControllerInputContext *temp_r29_2;
    ControllerInputContext *context;
    temp_r31 = is_player_input_active(((s32) this->client_index));
    if ((this->get_flag() == 0) && (((TWindowMenuIconLine *)this)->is_decided() == 0) && (this->sub_80244994() != 0)) {
        if (this->state_flags & 0x10) {
            input = &controller_input_state.controllers[temp_r31];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        } else {
            temp_r29_2 = &controller_input_state.controllers[temp_r31];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        }
        context = &controller_input_state.controllers[temp_r31];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            this->handle_open();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->set_flag4();
        }
    }
    if ((f32) this->open_tick >= 7.5f) {
        temp_r3 = *(u32 *)((s8 *)((u8 *)this) + 0x80);
        if (temp_r3 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
        }
        temp_r3_2 = scroll_bar;
        if (temp_r3_2 != NULL) {
            temp_r3_2->increment_counter();
        }
    }
    ((TWindowDD *)((u8 *)this))->initialize_subwindow();
    this->update_scroll_offset();
    this->step_window_tween();
    this->center_list_selection();
    this->clamp_item_list_scroll();
    this->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24));
}

TWindowMenuIconLine::~TWindowMenuIconLine() {
    TWindowSubStatusDisp::destroy_allocation((saddr)this->scroll_bar, (s16)1);
    TWindowSubStatusDisp::destroy_status_display((saddr)this->status_display, (s16)1);
}
}

// The descriptor-taking form; the window layout comes from the caller.
TWindowMenuIconLine::TWindowMenuIconLine(u8 *parent, u32 count, s16 client, u8 *descriptor)
    : TWindowAddition(descriptor, client, parent) {
    init(count, client);
}

// The default form: the list window descriptor of this unit.
TWindowMenuIconLine::TWindowMenuIconLine(u8 *parent, u32 count, s16 client)
    : TWindowAddition((u8 *)&lbl_804D0604, client, parent) {
    init(count, client);
}
