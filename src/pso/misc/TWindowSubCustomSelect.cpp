#include "types.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowHelpItem_80243408.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowSubCustomSelect.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct Stack_80277638 {
    f32 sp8;
    f32 spC;
};

struct RecoveredGlobal_80277928_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80277408_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Ent_80277AEC { u16 id; u8 pad[0xA]; };

struct Pos_80277AEC { f32 x; f32 y; };

struct Sub_80277AEC { u8 pad[0x34]; s32 flags; };

struct Big_80277AEC { u8 pad[0x85C]; Sub_80277AEC sub; };

struct Stack_80277368
{
  f32 sp8;
  f32 spC;
};

struct Ent_802776D0 { u16 id; u16 sub; };

extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_window_scrollbar(int, int, void *);
s32 forward_render__20TWindowSubStatusDispFv(int, int);
void draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif(void *, void *, s32, f32);
extern const f32 TWindowSubCustomSelect__data_805DD5B0;
extern const f32 lbl_805DD5C4;
extern const f32 lbl_805DD5C8;
extern const f32 lbl_805DD5CC;
extern const f32 lbl_805DD5D0;
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern RecoveredGlobal_80277928_lbl_8050E208 controller_input_state;
extern const f32 lbl_805DD5E4;
s32 play_sound_effect(s32, s32, s32, s32);
s32 apply_choice__20TWindowChoiceSettingFllll(void *, int, int, int);
s32 get_message_10__20TWindowSubStatusDispFl(int);
void *get_player_by_client_id(s32 i);
s32 construct_with_parent__15TWindowAdditionFPv(void *, void *, s16, s32);
s32 get_window_layout_position(int);
void *reset_selection__20TWindowSubStatusDispFv(void *, Pos_80277AEC *);
extern u8 custom_select_organic_action_table[];
extern u8 custom_select_android_action_table[];
extern u8 TWindowSubCustomSelect__window_settings[];
extern s32 __vt__22TWindowSubCustomSelect[];
extern s32 TWindowSubCustomSelect__class_name;
extern const f32 lbl_805DD5E8;
extern const f32 lbl_805DD5EC;
s32 clamp_list_scroll_offset(void *, void *, void *);
extern const f32 lbl_805DD5A8;
extern const f32 lbl_805DD5AC;
extern const f32 lbl_805DD5B4;
extern const f32 lbl_805DD5B8;
extern const f32 lbl_805DD5BC;
extern const f32 lbl_805DD5C0;
s32 can_use_palette_action__10TObjPlayerFPvUcUc(s32, u8, u8);
u8 *get_array_entry__11TWindowBaseFi(void *, s32);
s32 draw_action_palette_icon(void *, u16, u16);
s32 draw_visible_window_entries(void *, void *, void *);
extern const f32 lbl_805DD5D4;
extern const f32 lbl_805DD5D8;
extern const f32 lbl_805DD5DC;
extern const f32 lbl_805DD5E0;
void __dl__7TObjectFPv(void *);

void TWindowSubCustomSelect::handle_cancel() {
    if (is_active() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_73 = (u8) (this->m_73 | 2);
    }
}

void TWindowSubCustomSelect::handle_decide() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_73 = (u8) (this->m_73 | 1);
    ((TWindowSubStatusDisp *)(this->m_7c))->set_entry_state(2);
}

typedef char RecoveredGlobal_80277408_lbl_8050E208_size[sizeof(RecoveredGlobal_80277408_lbl_8050E208) == 0x1B0 ? 1 : -1];

typedef struct Stack_80277368 Stack_80277368;
#pragma fp_contract on
s32 TWindowSubCustomSelect::update_list_scroll() {
  u8 *arg0 = (u8 *) this;
  Stack_80277368 stack;
  u8 *new_var;
  f32 *new_var3;
  f32 tgt;
  float new_var2;
  new_var2 = (TWindowSubCustomSelect__data_805DD5B0 * ((f32) ((s8)this->m_71))) + lbl_805DD5AC;
  tgt = lbl_805DD5A8 + new_var2;
  tgt -= lbl_805DD5B4;
  new_var3 = (f32 *) (((s8 *) arg0) + 0x6C);
  *new_var3 = (*new_var3) + (tgt - (*((f32 *) (((s8 *) arg0) + 0x6C))));
  stack.sp8 = lbl_805DD5B8;
  stack.spC = ((this->m_4c) - lbl_805DD5BC) - lbl_805DD5C0;
  clamp_list_scroll_offset(*((u8 **) (((s8 *) arg0) + 0x80)), (new_var = arg0) + 0x68, &stack.sp8);
}

void TWindowSubCustomSelect::handle_grid_navigation() {
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r3_3;
    u8 temp_r4;
    u8 temp_r5;
    u8 *window_choice_setting;
    window_choice_setting = (u8 *)&(*(RecoveredGlobal_80277408_lbl_8050E208 *)&controller_input_state).value + (is_player_input_active(((s32) this->m_20)) * 0x50) + 0x20;
    if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0xF0, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_80277408_lbl_8050E208 *)&controller_input_state).value + 0x160), 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, (s32)(0U), 0, 0);
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x10, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_80277408_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x10, 6, 1) != 0)) {
            this->m_71 = (this->m_71 - 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x20, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_80277408_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x20, 6, 1) != 0)) {
            this->m_71 = (this->m_71 + 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x80, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_80277408_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x80, 6, 1) != 0)) {
            this->m_70 = (this->m_70 + 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x40, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&(*(RecoveredGlobal_80277408_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x40, 6, 1) != 0)) {
            this->m_70 = (this->m_70 - 1);
        }
        temp_r3 = this->m_70;
        if ((s8) temp_r3 < 0) {
            this->m_70 = (temp_r3 + 3);
        }
        temp_r3_2 = this->m_70;
        if ((s8) temp_r3_2 >= 3) {
            this->m_70 = (temp_r3_2 - 3);
        }
        temp_r3_3 = this->m_71;
        if ((s8) temp_r3_3 < 0) {
            this->m_71 = (u8) (temp_r3_3 + this->m_72);
        }
        temp_r4 = this->m_71;
        temp_r5 = this->m_72;
        if ((s8) temp_r4 >= (s8) temp_r5) {
            this->m_71 = (u8) (temp_r4 - temp_r5);
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubCustomSelect::draw_cursor(u8 *window_sub_custom_equip) {
    Stack_80277638 stack;
    stack.sp8 = (lbl_805DD5C8 * (f32) (s8) this->m_70) + lbl_805DD5C4;
    stack.spC = (TWindowSubCustomSelect__data_805DD5B0 * (f32) (s8) this->m_71) + lbl_805DD5CC;
    draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif(window_sub_custom_equip, &stack.sp8, this->m_74, lbl_805DD5D0);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
void TWindowSubCustomSelect::draw_palette_cells(int ctx) {
    u32 i;
    s32 p;
    Ent_802776D0 *e;
    s16 id;
    s16 sub;
    u8 *w1;
    u8 *w0;
    u8 *w2;
    f32 y;
    f32 fx;
    f32 fy;
    p = ((s32)get_player_by_client_id((this->m_20)));
    if (p == 0) {
        return;
    }
    e = *(Ent_802776D0 * *)&this->m_78;
    for (i = 0; e->id != 8; i++, e++) {
        if (e->id == 0) {
            continue;
        }
        fx = lbl_805DD5C8 * (f32)(i % 3);
        fy = TWindowSubCustomSelect__data_805DD5B0 * (f32)(i / 3);
        y = *(f32 *)((s8 *)ctx + 0x14) + fy;
        if (lbl_805DD5D4 + (lbl_805DD5D8 + y) < *(f32 *)((s8 *)ctx + 0x40) || lbl_805DD5D8 + y > *(f32 *)((s8 *)ctx + 0x48)) {
            continue;
        }
        w1 = get_array_entry__11TWindowBaseFi(this, 1);
        w0 = get_array_entry__11TWindowBaseFi(this, 0);
        w2 = get_array_entry__11TWindowBaseFi(this, 2);
        *(f32 *)((s8 *)w1 + 8) = lbl_805DD5DC + fx;
        *(f32 *)((s8 *)w1 + 0xC) = lbl_805DD5BC + fy;
        *(f32 *)((s8 *)w0 + 8) = lbl_805DD5E0 + fx;
        *(f32 *)((s8 *)w0 + 0xC) = lbl_805DD5D8 + fy;
        id = e->id;
        sub = e->sub;
        if (can_use_palette_action__10TObjPlayerFPvUcUc(p, id, sub) != 0) {
            *(s32 *)((s8 *)w1 + 0x2C) = -1;
        } else {
            *(s32 *)((s8 *)w1 + 0x2C) = 0xFF404040;
        }
        draw_action_palette_icon(w1, id, sub);
        update_palette_item_count_label((TWindowHelpItem *)w2, (u8 *)w1, (u16)id, (u16)sub, (s32)this->m_20);
        draw_visible_window_entries(this, &*(u8 *)((s8 *)this + 0x24), (void *)ctx);
    }
}
#pragma pop

void render__22TWindowSubCustomSelectFv(TWindowSubCustomSelect *window_sub_custom_select) {
    s32 temp_r3;
    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)window_sub_custom_select)->draw_window_frame((void *)temp_r3);
    window_sub_custom_select->draw_palette_cells(temp_r3);
    window_sub_custom_select->draw_cursor((u8 *)temp_r3);
    forward_render__20TWindowSubStatusDispFv(window_sub_custom_select->m_7c, temp_r3);
    draw_window_scrollbar(window_sub_custom_select->m_80, temp_r3, (u8 *)window_sub_custom_select + 0x68);
}

typedef char RecoveredGlobal_80277928_lbl_8050E208_size[sizeof(RecoveredGlobal_80277928_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubCustomSelect::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    u8 *temp_r30_2;
    temp_r30 = is_player_input_active(((s32) this->m_20));
    if (!(*(s32 *)&this->m_2c & 2)) {
        *(s32 *)&this->m_5c = 0x01000000;
    }
    if (((TWindowSubCustomSelect *)arg0)->is_active() == 0) {
        handle_grid_navigation();
        temp_r30_2 = (u8 *)&controller_input_state.value + (temp_r30 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r30_2, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
            handle_decide();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r30_2, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
            handle_cancel();
        }
    }
    update_list_scroll();
    if ((f32) *(s32 *)&this->m_5c >= lbl_805DD5E4) {
        ((TWindowSubStatusDisp *)(*(s32 *)&this->m_7c))->update_subwindow();
        ((TWindowSubStatusDisp *)(*(s32 *)&this->m_80))->increment_counter();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
    *(s32 *)&this->m_74 = (s32) (*(s32 *)&this->m_74 + 1);
}

void *__dt__22TWindowSubCustomSelectFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TWindowSubCustomSelect;
        TWindowSubStatusDisp::destroy_allocation((s32)(*(void **)((s8 *)arg0 + 0x80)), (s16)1);
        TWindowSubStatusDisp::destroy_status_display((s32)(*(void **)((s8 *)arg0 + 0x7C)), (s16)1);
        ((TWindowAddition *)arg0)->destroy_window(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
#pragma fp_contract on
u8 *TWindowSubCustomSelect__ct(TWindowSubCustomSelect *window_sub_custom_select, s32 arg1) {
    Pos_80277AEC pos;
    Big_80277AEC *p;
    Sub_80277AEC *q;
    Ent_80277AEC *e;
    void *o;
    construct_with_parent__15TWindowAdditionFPv(window_sub_custom_select, TWindowSubCustomSelect__window_settings, arg1, get_window_layout_position(0x10));
    *(s32 **)((s8 *)window_sub_custom_select + 0x18) = __vt__22TWindowSubCustomSelect;
    *(s32 *)((s8 *)window_sub_custom_select + 0) = TWindowSubCustomSelect__class_name;
    window_sub_custom_select->m_20 = arg1;
    p = (Big_80277AEC *)get_player_by_client_id(window_sub_custom_select->m_20);
    if (p == NULL) {
        return (u8 *)window_sub_custom_select;
    }
    q = &p->sub;
    if (q == NULL) {
        return (u8 *)window_sub_custom_select;
    }
    if (q->flags & 0x10) {
        *(u8 **)((s8 *)window_sub_custom_select + 0x78) = custom_select_android_action_table;
    } else {
        *(u8 **)((s8 *)window_sub_custom_select + 0x78) = custom_select_organic_action_table;
    }
    window_sub_custom_select->m_73 = 0;
    window_sub_custom_select->m_70 = 0;
    window_sub_custom_select->m_71 = 0;
    window_sub_custom_select->m_74 = 0;
    e = *(Ent_80277AEC **)((s8 *)window_sub_custom_select + 0x78);
    window_sub_custom_select->m_72 = 0;
    while (e->id != 8) {
        e++;
        (window_sub_custom_select->m_72)++;
    }
    o = ::operator new(0x24);
    if (o != NULL) {
        o = ((TWindowSubStatusDisp *)o)->construct_type1_heading(get_message_10__20TWindowSubStatusDispFl(0x22), window_sub_custom_select->m_20);
    }
    *(void **)((s8 *)window_sub_custom_select + 0x7C) = o;
    pos.x = lbl_805DD5E8;
    pos.y = TWindowSubCustomSelect__data_805DD5B0 * (f32)(s8)window_sub_custom_select->m_72 + lbl_805DD5EC;
    o = ::operator new(0xC);
    if (o != NULL) {
        o = reset_selection__20TWindowSubStatusDispFv(o, &pos);
    }
    *(void **)((s8 *)window_sub_custom_select + 0x80) = o;
    return (u8 *)window_sub_custom_select;
}
#pragma pop

}
