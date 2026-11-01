#include "types.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubStatusDisp_802671F0.h"
#include "pso/unk/text_801C53D4.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TUnk_804CE7E8.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TShopJudgmentItemWindow.h"
#include "pso/misc/TWindowSubMag.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

struct Stack_80266EB8 {
    f32 sp8;
    f32 spC;
};
struct Vec2_80266E34 { f32 x, y; };
struct List_80266E34 {
    u8 pad0[0x48]; f32 window_height; u8 pad1[0x72 - 0x4C]; s16 count; u8 pad2[0x84 - 0x74]; void *scrollbar;
};
struct RecoveredGlobal_80267704_lbl_804D0604 {
    s32 value;
    u8 remaining[0x10];
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
struct V_80267F9C { f32 x; f32 y; };
struct RecoveredGlobal_80268048_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
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

struct Pt_80267714
{
  f32 x;
  f32 y;
};

extern "C" {
s32 *get_shared_text_buffer(void);
u32 calc_text_width();
u8 get_font_char_advance();
u16 map_char_to_font_code(u16 c);
void TWindowSubStatusDisp__sub_80228F5C(s32);
void text_builder_append(u8 *str);
void set_text_draw_params(s32 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
void draw_window_tab(void *, void *, s32, f32);
extern const f32 lbl_805DD180;
extern const f32 lbl_805DD19C;
extern const f32 lbl_805DD1A0;
extern const f32 lbl_805DD1A4;
extern const f32 lbl_805DD1A8;
extern const f32 lbl_805DD1AC;
extern const f32 lbl_805DD1B0;
extern const f32 lbl_805DD1B4;
extern const f32 lbl_805DD1B8;
extern const f32 lbl_805DD1BC;
extern char lbl_805DD1C0[2];
void draw_item_list_capacity(void *arg0, Win_80267714 *arg1, s32 arg2, s32 arg3);
s32 get_array_entry__11TWindowBaseFi(void *, s16);
extern const f32 lbl_805DD184;
extern const f32 lbl_805DD188;
extern const f32 lbl_805DD18C;
extern const f32 lbl_805DD190;
extern const f32 lbl_805DD194;
extern const f32 lbl_805DD1C4;
extern const f32 lbl_805DD1C8;
extern const f32 lbl_805DD1CC;
extern const f32 lbl_805DD1D0;
extern s32 lbl_805D3968;
extern RecoveredGlobal_80267704_lbl_804D0604 lbl_804D0604;
extern s32 lbl_804D05F8[];
extern RecoveredGlobal_80268048_lbl_8050E208 controller_input_state;
extern s32 lbl_804D0618[];

s32 clamp_list_scroll_offset(int, void *, void *);
s32 get_cursor_pos__14TWindowSubItemFv();
s32 init_entry__20TWindowSubStatusDispFScScUcUll(s32, u8, u8, int, s32, s32);
void fn_80266BD0(s32 index, u8 *first, u8 *second, s32 player);
void TWindowSubStatusDisp__sub_80258A28(u8 *arg0, s32 arg1, s32 arg2);
void *get_player_by_client_id(s32 i);
s8 clamp_char_at__10TObjPlayerFl(s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);
s32 finalize_state__20TWindowSubStatusDispFv(s32);
s32 is_flag80_set__20TWindowSubStatusDispFv(s32);
s32 advance_state__20TWindowSubStatusDispFv();
s32 init_status_entry__20TWindowSubStatusDispFPvcUii(void*, s32, s32, s32);
u32 reset_selection__20TWindowSubStatusDispFv(int, void *);
u32 construct_type1_heading__20TWindowSubStatusDispFll(u32, s32, s16);
s32 is_decided__19TWindowMenuIconLineFv(void *);
s32 is_flag_4_set__20TWindowSubStatusDispFv();
}
void text_builder_reset();
s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width);
void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);
extern "C" {
u8 *fn_802683F4(void *, s32, s32, s16);
u8 *__nw__7TObjectFUl(s32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
s32 is_player_input_active(s32 param_1);
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, s32);
s32 draw_window_scrollbar(s32, s32, void *);
void __dl__7TObjectFPv(void *);
void destroy_window__15TWindowAdditionFs(void *, int);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);

void TShopJudgmentItemWindow__sub_80267F9C(V_80267F9C v, s32 x);

extern "C" {
extern const f32 lbl_805DD188 = 0.0f;
extern const f32 lbl_805DD18C = 20.0f;
extern const f32 lbl_805DD190 = 6.0f;
extern const f32 lbl_805DD194 = -18.0f;
extern const f32 lbl_805DD198 = 40.0f;
extern const f32 lbl_805DD19C = 166.0f;
extern const f32 lbl_805DD1A0 = 13.0f;
extern const f32 lbl_805DD1A4 = -60.0f;
extern const f32 lbl_805DD1A8 = 50.0f;
extern const f32 lbl_805DD1AC = 4.0f;
extern const f32 lbl_805DD1B0 = -1.0f;
extern const f32 lbl_805DD1B4 = 0.1794f;
extern const f32 lbl_805DD1B8 = 100000.0f;
extern const f32 lbl_805DD1BC = 0.5f;
}

s32 TWindowMenuIconLine::get_cursor_value() {
    get_array_entry__11TWindowBaseFi(this, *(s16 *)&this->cursor);
    return get_cursor_pos__14TWindowSubItemFv();
}

void TWindowMenuIconLine::calc_content_extent() {
    struct List_80266E34 *s = (struct List_80266E34 *)this;
    struct Vec2_80266E34 v;

    if (s->scrollbar != NULL) {
        v.x = s->window_height - lbl_805DD180;
        if (s->scrollbar != NULL) {
            v.x -= lbl_805DD184;
        }
        v.y = (f32) (s->count * 20 - 2);
        ((TWindowMenu *)(s->scrollbar))->copy_position(&v);
    }
}

void TWindowSubStatusDisp::clamp_scroll_offset() {
    u8 *arg0 = (u8 *)this;
    Stack_80266EB8 stack;
    f32 temp_f1;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x84) != 0U) {
        stack.sp8 = (*(const f32 *)&lbl_805DD188);
        temp_f1 = this->m_4c - (*(const f32 *)&lbl_805DD18C);
        stack.spC = temp_f1;
        if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
            stack.spC = temp_f1 - (*(const f32 *)&lbl_805DD190);
        }
        clamp_list_scroll_offset((int) (*(u32 *)((s8 *)arg0 + 0x84)), (u8 *)&this->m_68, &stack.sp8);
    }
}

void TWindowSubShortMail::advance_line(s32 arg1) {
    s16 temp_r4;
    temp_r4 = (s16) *(s16 *)((s8 *)this + 0x72);
    if (temp_r4 < (s16) *(s16 *)((s8 *)this + 0x76)) {
        ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(this, temp_r4)))->setup_entry_msg_d1(arg1);
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}

void advance_status_disp_entry(void *arg0, s32 arg1) {
    s16 temp_r4;
    temp_r4 = (s16) *(s16 *)((s8 *)arg0 + 0x72);
    if (temp_r4 < (s16) *(s16 *)((s8 *)arg0 + 0x76)) {
        ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(arg0, temp_r4)))->setup_entry_msg_d0(arg1);
        *(s16 *)((s8 *)arg0 + 0x72) = (s16) (*(s16 *)((s8 *)arg0 + 0x72) + 1);
    }
}

void TWindowSubStatusDisp::add_list_entry(s32 arg1) {
    s16 temp_r4;
    temp_r4 = (s16) *(s16 *)((s8 *)this + 0x72);
    if (temp_r4 < (s16) *(s16 *)((s8 *)this + 0x76)) {
        ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(this, temp_r4)))->init_no_item_entry(arg1);
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}

void TWindowSubShortCutList::draw_entry(s32 index, u8 arg2, s32 arg3, s32 arg4) {
    u8 sp9;
    u8 sp8;

    if ((s16) this->entry_count < (s16) this->entry_capacity) {
        fn_80266BD0(index, &sp9, &sp8, this->m_20);
        init_entry__20TWindowSubStatusDispFScScUcUll(get_array_entry__11TWindowBaseFi(this, this->entry_count), sp9, sp8, arg2, arg3, arg4);
        this->entry_count = (this->entry_count + 1);
    }
}

void push_status_disp_entry(void *arg0, s32 arg1, s32 arg2) {
    if ((s16) *(s16 *)((s8 *)arg0 + 0x72) < (s16) *(s16 *)((s8 *)arg0 + 0x76)) {
        TWindowSubStatusDisp__sub_80258A28((u8 *)(((s32 (*)(void *))get_array_entry__11TWindowBaseFi)(arg0)), arg1, arg2);
        *(s16 *)((s8 *)arg0 + 0x72) = (s16) (*(s16 *)((s8 *)arg0 + 0x72) + 1);
    }
}

void add_battle_stat_entry(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;
    u16 *temp_r30;
    u32 player;

    if ((s16) *(s16 *)((s8 *)arg0 + 0x72) < (s16) *(s16 *)((s8 *)arg0 + 0x76)) {
        player = (u32)get_player_by_client_id(*(s16 *)((s8 *)arg0 + 0x20));
        if (player != 0U) {
            if (arg1 == 4) {
                var_r31 = fn_801C5404((s32 *)(player + 0x7C8));
            } else {
                var_r31 = clamp_char_at__10TObjPlayerFl(player + 0x7C4, arg1);
            }
            if (var_r31 > 0) {
                temp_r30 = ((u16 *(*)(void *, s16))get_array_entry__11TWindowBaseFi)(arg0, *(s16 *)((s8 *)arg0 + 0x72));
                ((TWindowSubStatusDisp *)temp_r30)->setup_stat_line(get_localized_text_entry(0x10, arg1 + 0x13), var_r31, arg2);
                if ((arg3 != 0) && ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0))) {
                    *temp_r30 |= 0x80;
                }
                *(s16 *)((s8 *)arg0 + 0x72) = (s16) (*(s16 *)((s8 *)arg0 + 0x72) + 1);
            }
        }
    }
}

void TUnk_804CE7E8::advance_all_entries(s32 arg1) {
    s32 i;
    ((s32 (*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, *(s16 *)(((u8 *)this) + 0x74));
    if (((s32 (*)(void))is_flag80_set__20TWindowSubStatusDispFv)() == 0) {
        if (arg1 != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
        for (i = 0; i < this->entry_capacity; i++) {
            ((s32 (*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, i);
            advance_state__20TWindowSubStatusDispFv();
        }
        ((s32 (*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, *(s16 *)(((u8 *)this) + 0x74));
        ((s32 (*)(void))finalize_state__20TWindowSubStatusDispFv)();
    }
}

void TWindowSubStatusDisp::refresh_selected_entry(s32 arg1) {
    s32 temp_r31;

    temp_r31 = get_array_entry__11TWindowBaseFi(this, *(s16 *)((s8 *)this + 0x74));
    if (((s32 (*)(void))is_flag80_set__20TWindowSubStatusDispFv)() == 0) {
        if (arg1 != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
        finalize_state__20TWindowSubStatusDispFv(temp_r31);
    }
}

void TWindowSubStatusDisp::add_status_entry(s8 arg1, s32 src, s32 arg3) {
    s32 var_r29;
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
        window_sub_status_disp = ((void *(*)(void *, s16))get_array_entry__11TWindowBaseFi)(this, temp_r5);
        init_status_entry__20TWindowSubStatusDispFPvcUii(window_sub_status_disp, var_r29, src, arg3);
        *(f32 *)((s8 *)window_sub_status_disp + 8) = (f32) (*(const f32 *)&lbl_805DD194);
        if (arg1 & 2) {
            *(s8 *)&((TWindowSubStatusDisp *)window_sub_status_disp)->unk_1C = 0xE;
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
        e = (u16 *)((void *(*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, *(s16 *)(((u8 *)this) + 0x72));
        init_status_entry_by_flag__20TWindowSubStatusDispFl(e, arg1, arg2, arg3);
        if (arg4 != 0) {
            *e |= 0x400;
        }
        if (arg5 != 0) {
            k = (*(const f32 *)&lbl_805DD198);
            i = 0;
            *e |= 0x1000;
            while (i < *(s16 *)(((u8 *)this) + 0x76)) {
                p = (u8 *)((void *(*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, i);
                *(f32 *)(p + 0xC) = k * (f32)i++;
            }
        }
        (*(s16 *)(((u8 *)this) + 0x72))++;
    }
}

void TWindowSubStatusDisp::add_inventory_item(s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_r4;
    if (arg1 != 0) {
        temp_r4 = (s16) *(s16 *)((s8 *)this + 0x72);
        if (temp_r4 < (s16) *(s16 *)((s8 *)this + 0x76)) {
            ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(this, temp_r4)))->set_inventory_item((void *)arg1, (s32)arg2, (s32)arg3);
            *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
        }
    }
}

void TShopEquipmentSellWindow::add_item(s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_r4;
    if (arg1 != 0) {
        temp_r4 = (s16) this->m_72;
        if (temp_r4 < (s16) this->m_76) {
            ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(this, temp_r4)))->update_from_player((void *)arg1, (s32)arg2, (s32)arg3);
            this->m_72 = (this->m_72 + 1);
        }
    }
}

void TShopJudgmentItemWindow::add_list_entry(s32 arg1, s32 arg2) {
    s16 temp_r4;
    if (arg1 != 0) {
        temp_r4 = (s16) this->m_72;
        if (temp_r4 < (s16) this->m_76) {
            ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(this, temp_r4)))->init_item_row((void *)arg1, (s32)arg2);
            this->m_72 = (this->m_72 + 1);
        }
    }
}

void TWindowSubStatusDisp::add_item_info_entry(s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_r4;
    if (arg1 != 0) {
        temp_r4 = (s16) *(s16 *)((s8 *)this + 0x72);
        if (temp_r4 < (s16) *(s16 *)((s8 *)this + 0x76)) {
            ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(this, temp_r4)))->set_item_info((void*)arg1, (int)arg2, (void*)arg3);
            *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
        }
    }
}

void TWindowSubStatusDisp::add_ground_item(s32 arg1, s32 arg2) {
    s16 temp_r4;
    if (arg1 != 0) {
        temp_r4 = (s16) *(s16 *)((s8 *)this + 0x72);
        if (temp_r4 < (s16) *(s16 *)((s8 *)this + 0x76)) {
            ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(this, temp_r4)))->set_ground_item((void *)arg1, (s32)arg2);
            *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
        }
    }
}

void TLobby::add_status_disp_entry(s32 arg1, s32 arg2) {
    if ((s16) *(s16 *)((s8 *)this + 0x72) < (s16) *(s16 *)((s8 *)this + 0x76)) {
        ((TWindowSubStatusDisp *)(((s32 (*)(void *))get_array_entry__11TWindowBaseFi)(this)))->init_display(arg1, arg2);
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}

typedef char RecoveredGlobal_80267704_lbl_804D0604_size[sizeof(RecoveredGlobal_80267704_lbl_804D0604) == 0x14 ? 1 : -1];
void TAdVIConfigGC__sub_80267704(s32 arg0) {
    *(s32 *)((s8 *)&lbl_804D0604.value + 0x10) = arg0;
}

typedef struct Pt_80267714 Pt_80267714;
typedef struct Win_80267714 Win_80267714;
#pragma fp_contract on
void draw_item_list_capacity(void *arg0, Win_80267714 *arg1, s32 arg2, s32 arg3) {
  u8 new_var;
  Pt_80267714 pt;
  if (arg1->i30 >= 0)
  {
    pt.x = ((*(const f32 *)&lbl_805DD19C) + arg1->x) - lbl_805DD180;
    pt.y = arg1->y - (*(const f32 *)&lbl_805DD1A0);
    draw_window_tab(arg1, &pt, 0, (*(const f32 *)&lbl_805DD1A4));
    pt.x += (*(const f32 *)&lbl_805DD1A8);
    pt.y += (*(const f32 *)&lbl_805DD1AC);
    set_text_draw_params((s32)arg1, 0, 0, (f32)((*(const f32 *)&lbl_805DD1B0) / ((*(const f32 *)&lbl_805DD1B4) + arg1->f38)), (f32)(*(const f32 *)&lbl_805DD1B8));
    text_builder_reset();
    TWindowSubStatusDisp__sub_80228F5C(arg2);
    get_shared_text_buffer();
    pt.x -= (f32) calc_text_width();
    map_char_to_font_code(0x2F);
    new_var = get_font_char_advance();
    pt.x -= (*(const f32 *)&lbl_805DD1BC) * new_var;
    text_builder_append((u8 *)lbl_805DD1C0);
    TWindowSubStatusDisp__sub_80228F5C(arg3);
    draw_window_text((f32 *)&pt, (const char *)(get_shared_text_buffer()), -1, 0, (f32)(*(const f32 *)&lbl_805DD1B8));
  }
}

void TWindowMenuIconLine::set_flag4() {
    if (!(this->state_flags & 8) && (((s32 (*)(void))is_decided__19TWindowMenuIconLineFv)() == 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state_flags = (u16) (this->state_flags | 4);
    }
}

void TWindowMenuIconLine::handle_open() {
    s32 temp_r31;
    temp_r31 = get_array_entry__11TWindowBaseFi(this, *(s16 *)&this->cursor);
    if ((is_flag_4_set__20TWindowSubStatusDispFv() == 0) || (is_flag80_set__20TWindowSubStatusDispFv(temp_r31) != 0)) {
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
    var_r31 = *(s16 *)&this->cursor;
loop_1:
    var_r31 += 1;
    if (var_r31 >= (s16) this->entry_capacity) {
        if (!(this->state_flags & 1)) {
            var_r31 = 0;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) *(s16 *)&this->cursor) {
            if (sub_80266B18(var_r31) != 0) {
                *(s16 *)&this->cursor = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}

void TWindowMenuIconLine::move_cursor() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = *(s16 *)&this->cursor;
loop_1:
    var_r31 -= 1;
    if (var_r31 < 0) {
        if (!(this->state_flags & 1)) {
            var_r31 = this->entry_capacity - 1;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) *(s16 *)&this->cursor) {
            if (sub_80266B18(var_r31) != 0) {
                *(s16 *)&this->cursor = var_r31;
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
    typedef char sp8_offset[(offsetof(Stack_80267B18, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80267B18, spC) == 0x4) ? 1 : -1];
    Stack_80267B18 stack;
    f32 temp_f1;
    u32 temp_r3;
    u32 var_r0;
    if ((u32) *(u32 *)&this->unk_84 == 0U) {
        temp_f1 = this->m_38 - lbl_805DD180;
        stack.spC = (*(const f32 *)&lbl_805DD188);
        stack.sp8 = temp_f1;
        temp_r3 = (int)::operator new(0xC);
        var_r0 = temp_r3;
        if (var_r0 != 0U) {
            var_r0 = reset_selection__20TWindowSubStatusDispFv(temp_r3, &stack.sp8);
        }
        *(u32 *)&this->unk_84 = var_r0;
        this->m_2c = (s32) (this->m_2c | 0x80);
    }
}

void TWindowMenuIconLine::ensure_status_display(s32 arg1) {
    u32 var_r0;

    if ((u32) this->status_display == 0U) {
        var_r0 = (int)::operator new(0x24);
        if (var_r0 != 0U) {
            var_r0 = construct_type1_heading__20TWindowSubStatusDispFll(var_r0, arg1, this->m_20);
        }
        *(u32 *)&this->status_display = var_r0;
        (this->m_2c) = (s32) ((this->m_2c) | 0x40);
    }
}

void TWindowSubMag::start_scroll(f32 farg0) {
    u16 temp_r4;

    temp_r4 = *(u16 *)((s8 *)this + 0x70);
    if (temp_r4 & 0x20) {
        *(u16 *)((s8 *)this + 0x70) = (u16) (temp_r4 & 0xFFFFFFDF);
        *(f32 *)&this->m_3c = farg0;
        *(s32 *)((s8 *)this + 0x50) = 3;
    }
}

void TWindowSubStatusDisp::init_scroll_pos() {
    u16 temp_r4;
    void *temp;

    temp_r4 = *(u16 *)((s8 *)this + 0x70);
    if (!(temp_r4 & 0x20)) {
        *(u16 *)((s8 *)this + 0x70) = (u16) (temp_r4 | 0x20);
        temp = ((u16 *(*)(void *, s16))get_array_entry__11TWindowBaseFi)(this, (s16)(*(s16 *)((s8 *)this + 0x74)));
        this->m_3c = (f32) ((*(const f32 *)&lbl_805DD18C) + *(f32 *)((s8 *)temp + 0x14));
        if (this->m_2c & 0x40) {
            this->m_3c = (f32) (this->m_3c + (*(const f32 *)&lbl_805DD190));
        }
        *(s32 *)((s8 *)this + 0x50) = 3;
    }
}

#pragma push
#pragma fp_contract on
void TWindowMenuIconLine::center_list_selection() {
    f32 target;

    if ((*(u32 *)&this->unk_84 != 0U) && (*(u32 *)((s8 *)((u8 *)this) + 0x50) == 0U)) {
        f32 t = (*(f32 *)&this->m_4c - lbl_805DD1C8) - lbl_805DD1CC;
        target = lbl_805DD1C4 + (f32) (*(s16 *)&this->cursor * 0x14);
        target -= (*(const f32 *)&lbl_805DD1BC) * t;
        *(f32 *)&this->unk_6C += target - *(f32 *)&this->unk_6C;
    }
}
#pragma pop

void TWindowMenuIconLine::clamp_item_list_scroll() {
    Stack_80267D14 stack;
    f32 temp_f1;
    if ((u32) *(u32 *)&this->unk_84 != 0U) {
        stack.sp8 = (*(const f32 *)&lbl_805DD188);
        temp_f1 = *(f32 *)&this->m_4c - (*(const f32 *)&(*(const f32 *)&lbl_805DD18C));
        stack.spC = temp_f1;
        if ((u32) *(u32 *)&this->status_display != 0U) {
            stack.spC = temp_f1 - (*(const f32 *)&(*(const f32 *)&lbl_805DD190));
        }
        clamp_list_scroll_offset((int) (*(u32 *)&this->unk_84), (void *) (((u8 *)this) + 0x68), &stack.sp8);
    }
}

#pragma fp_contract on
void TWindowMenuIconLine::update_scroll_offset() {
  s8 *new_var;
  f32 var_f4;
  u32 n;
  if ((this->state_flags) & 0x20)
  {
    new_var = ((s8 *) ((u16 *)get_array_entry__11TWindowBaseFi(this, *((s16 *) (((s8 *) this) + 0x74))))) + 0xC;
    var_f4 = *((f32 *) new_var);
  }
  else
  {
    var_f4 = (*(const f32 *)&lbl_805DD188);
  }
  n = *((u32 *) (((s8 *) this) + 0x50));
  if (n == 0)
  {
    *((f32 *) (((s8 *) this) + 0x6C)) = var_f4;
  }
  else
  {
    var_f4 += (*(const f32 *)&lbl_805DD1BC) * ((*((f32 *) (((s8 *) this) + 0x3C))) - (*((f32 *) (((s8 *) this) + 0x4C))));
    *((f32 *) (((s8 *) this) + 0x6C)) += (var_f4 - (*((f32 *) (((s8 *) this) + 0x6C)))) / ((f32) n);
  }
}

void TWindowMenuIconLine::draw_selected_list_entry(s32 window_key_board_soft) {
    u16 *temp_r3;

    if (!(this->state_flags & 0x80)) {
        temp_r3 = ((u16 *(*)(void *, s16))get_array_entry__11TWindowBaseFi)(this, (s16)(*(s16 *)&this->cursor));
        if (*temp_r3 & 1) {
            draw_selection_bar((u8 *)window_key_board_soft, (u8 *)temp_r3, is_decided__19TWindowMenuIconLineFv(this));
        }
    }
}

void TWindowMenuIconLine__ct(u8 *arg0, u32 arg1, s32 arg2) {
    u32 i;
    u8 *e;
    *(s32 *)arg0 = lbl_805D3968;
    *(s16 *)(arg0 + 0x20) = arg2;
    *(s16 *)(arg0 + 0x72) = 0;
    *(s16 *)(arg0 + 0x74) = 0;
    *(u16 *)(arg0 + 0x76) = arg1;
    *(s16 *)(arg0 + 0x78) = 0;
    *(s32 *)(arg0 + 0x7C) = 0;
    *(s16 *)(arg0 + 0x70) = 0;
    *(s32 *)(arg0 + 0x80) = 0;
    *(s32 *)(arg0 + 0x84) = 0;
    for (i = 0; i < arg1; i++) {
        e = ((u8 *(*)(void *, u32))get_array_entry__11TWindowBaseFi)(arg0, i);
        *(f32 *)(e + 0xC) = (f32)(i * 0x14);
    }
}

u8 *fn_80267F38(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    u8 *temp_r3;
    u8 *var_r0;
    ((s32 (*)(void *, void *))TShopJudgmentItemWindow__sub_80267F9C)((void *)arg1, (void *)arg2);
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x88));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(fn_802683F4(temp_r3, arg0, arg2, arg3));
    }
    return var_r0;
}

void TShopJudgmentItemWindow__sub_80267F9C(V_80267F9C v, s32 x) {
    ((V_80267F9C *)&lbl_804D0604)[0].x = v.x;
    ((V_80267F9C *)&lbl_804D0604)[0].y = v.y;
    lbl_804D05F8[1] = x;
}

void TWindowMenuIconLine::render() {
    s32 temp_r3;

    temp_r3 = get_draw_context__11TWindowBaseFPv();
    draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(this, ((u8 *)this) + 0x24, temp_r3);
    this->draw_selected_list_entry(temp_r3);
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x80) != 0U) {
        forward_render__20TWindowSubStatusDispFv(*(u32 *)((s8 *)((u8 *)this) + 0x80), temp_r3);
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x84) != 0U) {
        draw_window_scrollbar(*(u32 *)((s8 *)((u8 *)this) + 0x84), temp_r3, ((u8 *)this) + 0x68);
    }
}

typedef char RecoveredGlobal_80268048_lbl_8050E208_size[sizeof(RecoveredGlobal_80268048_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowMenuIconLine::run_task() {
    s32 temp_r31;
    u32 temp_r3;
    u32 temp_r3_2;
    u8 *input;
    u8 *temp_r29_2;
    u8 *temp_r29_3;
    temp_r31 = is_player_input_active(((s32) this->m_20));
    if ((this->get_flag() == 0) && (is_decided__19TWindowMenuIconLineFv(this) == 0) && (this->sub_80244994() != 0)) {
        if (this->state_flags & 0x10) {
            input = (u8 *)&controller_input_state.value + (temp_r31 * 0x50) + 0x20;
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        } else {
            temp_r29_2 = (u8 *)&controller_input_state.value + (temp_r31 * 0x50) + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        }
        temp_r29_3 = (u8 *)&controller_input_state.value + (temp_r31 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r29_3, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
            this->handle_open();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r29_3, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
            this->set_flag4();
        }
    }
    if ((f32) this->m_5c >= lbl_805DD1D0) {
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
    this->update_window_entry_list(((u8 *)this) + 0x24);
}

void *TWindowSubStatusDisp::destroy_item_list_resources(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804D0618;
        TWindowSubStatusDisp::destroy_allocation((s32)(*(void **)((s8 *)this + 0x84)), (s16)1);
        TWindowSubStatusDisp::destroy_status_display((s32)(*(void **)((s8 *)this + 0x80)), (s16)1);
        destroy_window__15TWindowAdditionFs(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
}
