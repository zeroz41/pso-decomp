#include "types.h"
#include "pso/ui/window/Scroll_8026D790.h"
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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"

// inferred: name from the string the .sdata pointer holds
const char *TWindowMenuIconLine__name = "TWindowMenuIconLine";


void fn_80266BD0(s32 index, u8 *first, u8 *second, s32 player) {
    // inferred: pairs of entry codes handed to init_entry by TWindowSubShortCutList::draw_entry
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

struct Win_80266CF8 { u8 p0[0x72]; s16 f72; s16 f74; u8 p76[2]; s16 f78; };

extern "C" {

void TShopArmorListWindow::clamp_selection_to_valid_entry() {
    Win_80266CF8 *w = (Win_80266CF8 *)this;
    void *e;
    if (w->f72 >= 0) {
        if (w->f78 >= w->f72) {
            w->f74 = w->f72 - 1;
            return;
        }
        e = (void *)((TWindowBase *)w)->get_array_entry(w->f78);
        while (((TWindowSubStatusDisp *)e)->is_flag_4_set() == 0) {
            w->f78 = w->f78 - 1;
            e = (void *)((TWindowBase *)w)->get_array_entry(w->f78);
        }
        w->f74 = w->f78;
    }
}

void TShopArmorListWindow::save_cursor_selection() {
    this->m_78 = (s16) this->m_74;
    this->m_7c = ((TWindowMenuIconLine *)this)->get_cursor_value();
}
void TWindowMenuIconLine::reset_list() {
    u32 i;
    this->entry_count = 0;
    this->cursor = 0;
    for (i = 0; i < (u32)this->entry_capacity; i++) {
        TWindowSubStatusDisp::reset((void *)get_array_entry(i));
    }
}

}

struct Stack_80266EB8 {
    f32 sp8;
    f32 spC;
};
struct List_80266E34 {
    u8 pad0[0x48]; f32 window_height; u8 pad1[0x72 - 0x4C]; s16 count; u8 pad2[0x84 - 0x74]; void *scrollbar;
};
struct Stack_80267B18 {
    f32 sp8;
    f32 spC;
};
struct Win_80267AA8 { u8 p0[0x74]; s16 f74; s16 f76; };
struct Stack_80267D14 {
    f32 sp8;
    f32 spC;
};

struct Win_80267714
{
  f32 x;
  f32 y;
  u8 pad8[0x30 - 8];
  s32 i30;
  u8 pad34[4];
  f32 f38;
};

extern "C" {
u32 calc_text_width();
u8 get_font_char_advance();
u16 map_char_to_font_code(u16 c);
void draw_window_tab(void *, void *, s32, f32);
void draw_item_list_capacity(void *arg0, Win_80267714 *arg1, s32 arg2, s32 arg3);
s32 lbl_804D05F8[3] = {1, 0, 8};
WindowDescriptor lbl_804D0604 = {
    {0.0f, 0.0f}, 50050.0f, lbl_804D05F8, 3,
};

s32 clamp_list_scroll_offset(int, void *, void *);
s32 get_cursor_pos__14TWindowSubItemFv();
s32 init_entry__20TWindowSubStatusDispFScScUcUll(s32, u8, u8, int, s32, s32);
void fn_80266BD0(s32 index, u8 *first, u8 *second, s32 player);
void *get_player_by_client_id(s32 i);
s32 play_sound_effect(s32, s32, s32, s32);
s32 finalize_state__20TWindowSubStatusDispFv(s32);
s32 is_flag80_set__20TWindowSubStatusDispFv(s32);
}
void text_builder_reset();
s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width);
extern "C" {
s32 draw_window_scrollbar(s32, s32, void *);

void TShopJudgmentItemWindow__sub_80267F9C(NJS_POINT2 v, s32 x);

saddr TWindowMenuIconLine::get_cursor_value() {
    get_array_entry(this->cursor);
    return get_cursor_pos__14TWindowSubItemFv();
}

void TWindowMenuIconLine::calc_content_extent() {
    struct List_80266E34 *s = (struct List_80266E34 *)this;
    NJS_POINT2 v;

    if (s->scrollbar != NULL) {
        v.x = s->window_height - 8.0f;
        if (s->scrollbar != NULL) {
            v.x -= 5.0f;
        }
        v.y = (f32) (s->count * 20 - 2);
        ((Scroll_8026D790 *)(s->scrollbar))->copy_position(&v);
    }
}

void TWindowSubStatusDisp::clamp_scroll_offset() {
    u8 *arg0 = (u8 *)this;
    Stack_80266EB8 stack;
    f32 temp_f1;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x84) != 0U) {
        stack.sp8 = 0.0f;
        temp_f1 = this->frame_size[1] - 20.0f;
        stack.spC = temp_f1;
        if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
            stack.spC = temp_f1 - 6.0f;
        }
        clamp_list_scroll_offset((int) (*(u32 *)((s8 *)arg0 + 0x84)), (u8 *)&this->m_68, &stack.sp8);
    }
}

void TWindowSubShortMail::advance_line(s32 arg1) {
    int index;
    index = *(s16 *)((s8 *)this + 0x72);
    if (index < (s16) *(s16 *)((s8 *)this + 0x76)) {
        ((TWindowSubStatusDisp *)(reinterpret_cast<TWindowBase *>(this)->get_array_entry(index)))->setup_entry_msg_d1(arg1);
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}

void advance_status_disp_entry(TWindowBase *window_base, s32 arg1) {
    int index;
    index = *(s16 *)((s8 *)window_base + 0x72);
    if (index < (s16) *(s16 *)((s8 *)window_base + 0x76)) {
        ((TWindowSubStatusDisp *)(window_base->get_array_entry(index)))->setup_entry_msg_d0(arg1);
        *(s16 *)((s8 *)window_base + 0x72) = (s16) (*(s16 *)((s8 *)window_base + 0x72) + 1);
    }
}

void TWindowSubStatusDisp::add_list_entry(s32 arg1) {
    int index;
    index = *(s16 *)((s8 *)this + 0x72);
    if (index < (s16) *(s16 *)((s8 *)this + 0x76)) {
        ((TWindowSubStatusDisp *)(get_array_entry(index)))->init_no_item_entry(arg1);
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}

void TWindowSubShortCutList::draw_entry(s32 index, u8 arg2, s32 arg3, s32 arg4) {
    u8 sp9;
    u8 sp8;

    if ((s16) this->entry_count < (s16) this->entry_capacity) {
        fn_80266BD0(index, &sp9, &sp8, this->client_index);
        init_entry__20TWindowSubStatusDispFScScUcUll(reinterpret_cast<saddr>(get_array_entry(this->entry_count)), sp9, sp8, arg2, arg3, arg4);
        this->entry_count = (this->entry_count + 1);
    }
}

void push_status_disp_entry(void *arg0, s32 count, s32 id) {
    TWindowMenuIconLine *list = (TWindowMenuIconLine *)arg0;
    if (list->entry_count < list->entry_capacity) {
        TWindowSubStatusDisp__sub_80258A28((u8 *)list->get_array_entry(list->entry_count), count, id);
        list->entry_count++;
    }
}

void add_battle_stat_entry(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;
    u16 *temp_r30;
    uaddr player;

    if ((s16) *(s16 *)((s8 *)arg0 + 0x72) < (s16) *(s16 *)((s8 *)arg0 + 0x76)) {
        player = (uaddr)get_player_by_client_id(*(s16 *)((s8 *)arg0 + 0x20));
        if (player != 0U) {
            if (arg1 == 4) {
                var_r31 = fn_801C5404((s32 *)(player + 0x7C8));
            } else {
                var_r31 = (s8)((TObjPlayer *)(player + 0x7C4))->clamp_char_at(arg1);
            }
            if (var_r31 > 0) {
                temp_r30 = (u16 *)((TWindowBase *)arg0)->get_array_entry((s16)(*(s16 *)((s8 *)arg0 + 0x72)));
                ((TWindowSubStatusDisp *)temp_r30)->setup_stat_line(get_localized_text_entry(0x10, arg1 + 0x13), var_r31, arg2);
                if ((arg3 != 0) && ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0))) {
                    *temp_r30 |= 0x80;
                }
                *(s16 *)((s8 *)arg0 + 0x72) = (s16) (*(s16 *)((s8 *)arg0 + 0x72) + 1);
            }
        }
    }
}

void TWindowCheckBox::advance_all_entries(s32 arg1) {
    s32 i;
    get_array_entry(*(s16 *)(((u8 *)this) + 0x74));
    if (((s32 (*)(void))is_flag80_set__20TWindowSubStatusDispFv)() == 0) {
        if (arg1 != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
        for (i = 0; i < this->entry_capacity; i++) {
            ((TWindowSubStatusDisp *)get_array_entry(i))->advance_state();
        }
        get_array_entry(*(s16 *)(((u8 *)this) + 0x74));
        ((s32 (*)(void))finalize_state__20TWindowSubStatusDispFv)();
    }
}

void TWindowSubStatusDisp::refresh_selected_entry(s32 arg1) {
    TWindowSubStatusDisp *entry;

    entry = static_cast<TWindowSubStatusDisp *>(get_array_entry(*(s16 *)((s8 *)this + 0x74)));
    if (entry->is_flag80_set() == 0) {
        if (arg1 != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
        entry->finalize_state();
    }
}

void TWindowSubStatusDisp::add_status_entry(s8 arg1, s32 src, s32 arg3) {
    s8 var_r29;
    s16 temp_r5;
    void *window_sub_status_disp;

    temp_r5 = *(s16 *)((s8 *)this + 0x72);
    if (temp_r5 < (s16) *(s16 *)((s8 *)this + 0x76)) {
        if (arg1 & 8) {
            var_r29 = 0xD;
        } else if (arg1 & 4) {
            var_r29 = 0xF;
        } else {
            var_r29 = 0x33;
        }
        window_sub_status_disp = (void *)this->get_array_entry((s16)temp_r5);
        init_status_entry__20TWindowSubStatusDispFPvcUii((u8 *)window_sub_status_disp, var_r29, src, arg3);
        *(f32 *)((s8 *)window_sub_status_disp + 8) = (f32) -18.0f;
        if (arg1 & 2) {
            reinterpret_cast<ItemListRow *>(window_sub_status_disp)->status_icon = 0xE;
            *(u16 *)((s8 *)window_sub_status_disp + 0) = (u16) (*(u16 *)((s8 *)window_sub_status_disp + 0) | 0x100);
        }
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}

void init_status_entry_by_flag__20TWindowSubStatusDispFl(void *, s32, s32, s32);
void TWindowSubStatusDisp::append_entry(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u16 *e;
    s32 i;
    f32 k;
    u8 *p;

    if (*(s16 *)(((u8 *)this) + 0x72) < *(s16 *)(((u8 *)this) + 0x76)) {
        e = (u16 *)get_array_entry(*(s16 *)(((u8 *)this) + 0x72));
        init_status_entry_by_flag__20TWindowSubStatusDispFl(e, arg1, arg2, arg3);
        if (arg4 != 0) {
            *e |= 0x400;
        }
        if (arg5 != 0) {
            k = 40.0f;
            i = 0;
            *e |= 0x1000;
            while (i < *(s16 *)(((u8 *)this) + 0x76)) {
                p = (u8 *)get_array_entry(i);
                *(f32 *)(p + 0xC) = k * (f32)i++;
            }
        }
        (*(s16 *)(((u8 *)this) + 0x72))++;
    }
}

void TWindowSubStatusDisp::add_inventory_item(saddr item, s32 count, s32 sid) {
    int index;
    if (item != 0) {
        index = *(s16 *)((s8 *)this + 0x72);
        if (index < (s16) *(s16 *)((s8 *)this + 0x76)) {
            ((TWindowSubStatusDisp *)(get_array_entry(index)))->set_inventory_item((void *)item, (s32)count, (s32)sid);
            *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
        }
    }
}

void TShopEquipmentSellWindow::add_item(saddr item, s32 arg2, s32 arg3) {
    int index;
    if (item != 0) {
        index = this->m_72;
        if (index < (s16) this->m_76) {
            ((TWindowSubStatusDisp *)(reinterpret_cast<TWindowBase *>(this)->get_array_entry(index)))->update_from_player((void *)item, (s32)arg2, (s32)arg3);
            this->m_72 = (this->m_72 + 1);
        }
    }
}

void TShopJudgmentItemWindow::add_list_entry(saddr arg1, s32 arg2) {
    int index;
    if (arg1 != 0) {
        index = this->m_72;
        if (index < (s16) this->m_76) {
            ((TWindowSubStatusDisp *)(reinterpret_cast<TWindowBase *>(this)->get_array_entry(index)))->init_item_row((void *)arg1, (s32)arg2);
            this->m_72 = (this->m_72 + 1);
        }
    }
}

void TWindowSubStatusDisp::add_item_info_entry(saddr arg1, s32 arg2, saddr count) {
    int index;
    if (arg1 != 0) {
        index = *(s16 *)((s8 *)this + 0x72);
        if (index < (s16) *(s16 *)((s8 *)this + 0x76)) {
            ((TWindowSubStatusDisp *)(get_array_entry(index)))->set_item_info((void*)arg1, (int)arg2, (void*)count);
            *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
        }
    }
}

void TWindowSubStatusDisp::add_ground_item(saddr arg1, s32 arg2) {
    int index;
    if (arg1 != 0) {
        index = *(s16 *)((s8 *)this + 0x72);
        if (index < (s16) *(s16 *)((s8 *)this + 0x76)) {
            ((TWindowSubStatusDisp *)(get_array_entry(index)))->set_ground_item((void *)arg1, (s32)arg2);
            *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
        }
    }
}

void TLobby::add_status_disp_entry(s32 src, s32 arg2) {
    TWindowMenuIconLine *list = (TWindowMenuIconLine *)this;
    if (list->entry_count < list->entry_capacity) {
        TWindowSubStatusDisp *entry = (TWindowSubStatusDisp *)list->get_array_entry(list->entry_count);
        entry->init_display(src, arg2);
        list->entry_count++;
    }
}

void TAdVIConfigGC__sub_80267704(s32 arg0) {
    lbl_804D0604.flags = arg0;
}

typedef struct Win_80267714 Win_80267714;
#pragma fp_contract on
void draw_item_list_capacity(void *arg0, Win_80267714 *arg1, s32 arg2, s32 arg3) {
  u8 new_var;
  NJS_POINT2 pt;
  if (arg1->i30 >= 0)
  {
    pt.x = (166.0f + arg1->x) - 8.0f;
    pt.y = arg1->y - 13.0f;
    draw_window_tab(arg1, &pt, 0, -60.0f);
    pt.x += 50.0f;
    pt.y += 4.0f;
    set_text_draw_params(reinterpret_cast<WindowDrawContext *>(arg1), 0, 0, (f32)(-1.0f / (0.1794f + arg1->f38)), (f32)100000.0f);
    text_builder_reset();
    text_builder_append_int(arg2);
    get_shared_text_buffer();
    pt.x -= (f32) calc_text_width();
    map_char_to_font_code(0x2F);
    new_var = get_font_char_advance();
    pt.x -= 0.5f * new_var;
    text_builder_append((u8 *)"/");
    text_builder_append_int(arg3);
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
    if ((((TWindowSubStatusDisp *)entry)->is_flag_4_set() == 0) || (((TWindowSubStatusDisp *)entry)->is_flag80_set() != 0)) {
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

void TWindowSubShortCutList::set_cursor_index(s16 v) {
    if (v >= 0) {
        if (v >= ((Win_80267AA8 *)this)->f76) {
            return;
        }
        while (sub_80266B18(v) == 0) {
            if (v > 0) {
                v -= 1;
                continue;
            }
            break;
        }
        ((Win_80267AA8 *)this)->f74 = v;
    }
}

void TWindowMenuIconLine::create_menu_scroll_bar() {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80267B18, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80267B18, spC) == 0x4);
    Stack_80267B18 stack;
    f32 temp_f1;
    u32 temp_r3;
    if ((uaddr) this->scroll_bar == 0U) {
        temp_f1 = this->target_size[0] - 8.0f;
        stack.spC = 0.0f;
        stack.sp8 = temp_f1;
        *(u32 *)&this->scroll_bar = reinterpret_cast<uaddr>(new Scroll_8026D790(&stack.sp8));
        this->window_flags = (s32) (this->window_flags | 0x80);
    }
}

void TWindowMenuIconLine::ensure_status_display(s32 arg1) {
    uaddr var_r0;

    if ((uaddr) this->status_display == 0U) {
        var_r0 = (saddr)::operator new(0x24);
        if (var_r0 != 0U) {
            var_r0 = (uaddr)((TWindowSubStatusDisp *)var_r0)->construct_type1_heading(arg1, this->client_index);
        }
        *(u32 *)&this->status_display = var_r0;
        (this->window_flags) = (s32) ((this->window_flags) | 0x40);
    }
}

void TWindowSubMag::start_scroll(f32 farg0) {
    u16 temp_r4;

    temp_r4 = *(u16 *)((s8 *)this + 0x70);
    if (temp_r4 & 0x20) {
        *(u16 *)((s8 *)this + 0x70) = (u16) (temp_r4 & 0xFFFFFFDF);
        *(f32 *)&this->card = farg0;
        *(s32 *)((s8 *)this + 0x50) = 3;
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
        *(s32 *)((s8 *)this + 0x50) = 3;
    }
}

#pragma push
#pragma fp_contract on
void TWindowMenuIconLine::center_list_selection() {
    f32 target;

    if ((this->scroll_bar != 0U) && (*(u32 *)((s8 *)((u8 *)this) + 0x50) == 0U)) {
        f32 t = (*(f32 *)&this->frame_size[1] - 16.0f) - 10.0f;
        target = 9.0f + (f32) (this->cursor * 0x14);
        target -= 0.5f * t;
        scroll_offset[1] += target - scroll_offset[1];
    }
}
#pragma pop

void TWindowMenuIconLine::clamp_item_list_scroll() {
    Stack_80267D14 stack;
    f32 temp_f1;
    if ((uaddr) this->scroll_bar != 0U) {
        stack.sp8 = 0.0f;
        temp_f1 = *(f32 *)&this->frame_size[1] - 20.0f;
        stack.spC = temp_f1;
        if ((uaddr) this->status_display != 0U) {
            stack.spC = temp_f1 - 6.0f;
        }
        clamp_list_scroll_offset((saddr)this->scroll_bar, (void *) (((u8 *)this) + 0x68), &stack.sp8);
    }
}

#pragma fp_contract on
void TWindowMenuIconLine::update_scroll_offset() {
  s8 *new_var;
  f32 var_f4;
  u32 n;
  if ((this->state_flags) & 0x20)
  {
    new_var = ((s8 *) ((u16 *)get_array_entry(*((s16 *) (((s8 *) this) + 0x74))))) + 0xC;
    var_f4 = *((f32 *) new_var);
  }
  else
  {
    var_f4 = 0.0f;
  }
  n = *((u32 *) (((s8 *) this) + 0x50));
  if (n == 0)
  {
    *((f32 *) (((s8 *) this) + 0x6C)) = var_f4;
  }
  else
  {
    var_f4 += 0.5f * ((*((f32 *) (((s8 *) this) + 0x3C))) - (*((f32 *) (((s8 *) this) + 0x4C))));
    *((f32 *) (((s8 *) this) + 0x6C)) += (var_f4 - (*((f32 *) (((s8 *) this) + 0x6C)))) / ((f32) n);
  }
}

void TWindowMenuIconLine::draw_selected_list_entry(saddr window_key_board_soft) {
    u16 *entry;

    if (!(this->state_flags & 0x80)) {
        entry = (u16 *)this->get_array_entry((s16)(this->cursor));
        if (*entry & 1) {
            draw_selection_bar(reinterpret_cast<WindowDrawContext *>(window_key_board_soft), (u8 *)entry, ((TWindowMenuIconLine *)this)->is_decided());
        }
    }
}

#define self ((u8 *)this)
void TWindowMenuIconLine::vfunc_6(u32 arg1, s32 arg2) {
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

void TShopJudgmentItemWindow__sub_80267F9C(NJS_POINT2 v, s32 x) {
    lbl_804D0604.pad_00[0] = v.x;
    lbl_804D0604.pad_00[1] = v.y;
    lbl_804D05F8[1] = x;
}

void TWindowMenuIconLine::render() {
    saddr draw_context;

    draw_context = reinterpret_cast<saddr>(get_draw_context());
    draw_window_frame((void *)draw_context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24),
        reinterpret_cast<WindowDrawContext *>(draw_context));
    this->draw_selected_list_entry(draw_context);
    if (this->status_display != 0) {
        ((TWindowSubStatusDisp *)this->status_display)->forward_render((void *)(draw_context));
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x84) != 0U) {
        draw_window_scrollbar(*(u32 *)((s8 *)((u8 *)this) + 0x84), draw_context, ((u8 *)this) + 0x68);
    }
}

void TWindowMenuIconLine::run_task() {
    s32 temp_r31;
    uaddr temp_r3;
    uaddr temp_r3_2;
    u8 *input;
    u8 *temp_r29_2;
    u8 *context;
    temp_r31 = is_player_input_active(((s32) this->client_index));
    if ((this->get_flag() == 0) && (((TWindowMenuIconLine *)this)->is_decided() == 0) && (this->sub_80244994() != 0)) {
        if (this->state_flags & 0x10) {
            input = (u8 *)&controller_input_state + (temp_r31 * 0x50) + 0x20;
            if ((test_buttons_press_or_repeat((saddr)input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((test_buttons_press_or_repeat((saddr)input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        } else {
            temp_r29_2 = (u8 *)&controller_input_state + (temp_r31 * 0x50) + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        }
        context = (u8 *)&controller_input_state + (temp_r31 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            this->handle_open();
        }
        if ((TWindowShortListCtrl__check_controller_button(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->set_flag4();
        }
    }
    if ((f32) this->open_tick >= 7.5f) {
        temp_r3 = *(u32 *)((s8 *)((u8 *)this) + 0x80);
        if (temp_r3 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
        }
        temp_r3_2 = *(u32 *)((s8 *)((u8 *)this) + 0x84);
        if (temp_r3_2 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3_2)->increment_counter();
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
    TWindowSubStatusDisp::destroy_allocation((saddr)(*(void **)((s8 *)this + 0x84)), (s16)1);
    TWindowSubStatusDisp::destroy_status_display((saddr)(*(void **)((s8 *)this + 0x80)), (s16)1);
}
}

// The descriptor-taking form; the window layout comes from the caller.
TWindowMenuIconLine::TWindowMenuIconLine(u8 *parent, u32 count, s16 client, u8 *descriptor)
    : TWindowAddition(descriptor, client, parent) {
    vfunc_6(count, client);
}

// The default form: the list window descriptor of this unit.
TWindowMenuIconLine::TWindowMenuIconLine(u8 *parent, u32 count, s16 client)
    : TWindowAddition((u8 *)&lbl_804D0604, client, parent) {
    vfunc_6(count, client);
}
