#include "types.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TUnk_804D0658.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Stack_80268A6C {
    f32 sp8;
    f32 spC;
};

extern "C" {
s32 clamp_list_scroll_offset(int, void *, void *);
extern const f32 lbl_805DD1D8;
extern const f32 lbl_805DD1DC;
extern const f32 lbl_805DD1E0;
u32 construct_type1_heading__20TWindowSubStatusDispFll(u32, s32, s16);
s32 TWindowSubComCard__sub_8026906C(void);
s32 play_sound_effect(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0, s32 a3 = 0);
s32 is_open__13TUnk_804D0658Fv();
s32 get_array_entry__13TUnk_804CE018Fi(void * a0 = 0, s16 a1 = 0);

void TUnk_804D0658::request_close() {
    if (!(this->m_70 & 8) && (is_open__13TUnk_804D0658Fv() == 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_70 = (u16) (this->m_70 | 4);
    }
}
void TUnk_804D0658::draw() {
    get_array_entry__13TUnk_804CE018Fi(this, this->m_74);
    if (TWindowSubComCard__sub_8026906C() == 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        this->m_70 = (u16) (this->m_70 | 2);
        if ((u32) this->m_78 != 0U) {
            ((TWindowSubStatusDisp *)(this->m_78))->set_entry_state(2);
        }
    }
}
void TUnk_804D0658::move_next_choice() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = this->m_74;
loop_1:
    var_r31 += 1;
    if (var_r31 >= (s16) *(s16 *)&this->unk_76) {
        if (!(this->m_70 & 1)) {
            var_r31 = 0;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) this->m_74) {
            if (sub_80266B18(var_r31) != 0) {
                this->m_74 = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}
void TUnk_804D0658::move_cursor_prev() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = this->m_74;
loop_1:
    var_r31 -= 1;
    if (var_r31 < 0) {
        if (!(this->m_70 & 1)) {
            var_r31 = *(s16 *)&this->unk_76 - 1;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) this->m_74) {
            if (sub_80266B18(var_r31) != 0) {
                this->m_74 = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}
void create_sub_window__20TWindowChoiceSettingFPvi(void *arg0, s32 arg1) {
    u32 var_r0;

    if ((u32) *(u32 *)((s8 *)arg0 + 0x78) == 0U) {
        var_r0 = (int)::operator new(0x24);
        if (var_r0 != 0U) {
            var_r0 = construct_type1_heading__20TWindowSubStatusDispFll(var_r0, arg1, *(s16 *)((s8 *)arg0 + 0x20));
        }
        *(u32 *)((s8 *)arg0 + 0x78) = var_r0;
        *(s32 *)((s8 *)arg0 + 0x2C) = (s32) (*(s32 *)((s8 *)arg0 + 0x2C) | 0x40);
    }
}
}
struct W_802689EC { u8 pad[0x4C]; f32 f4c; u32 f50; u8 pad54[0x6C - 0x54]; f32 f6c; u8 pad70[4]; s16 f74; u8 pad76[0x7C - 0x76]; u32 f7c; };
extern const f32 lbl_805DD1E4;
extern const f32 lbl_805DD1E8;
extern const f32 lbl_805DD1EC;
extern const f32 lbl_805DD1F0;
#pragma push
#pragma fp_contract on

void TUnk_804D0658::update_scroll_offset() {
    W_802689EC *w = (W_802689EC *)this;
    f32 v;
    if (w->f7c != 0 && w->f50 == 0) {
        v = lbl_805DD1E4 + (f32)(w->f74 * 20);
        v -= lbl_805DD1E8 * ((w->f4c - lbl_805DD1EC) - lbl_805DD1F0);
        w->f6c += v - w->f6c;
    }
}
#pragma pop

void TUnk_804D0658::clamp_scroll() {
    u8 *arg0 = (u8 *)this;
    Stack_80268A6C stack;
    f32 temp_f1;
    if ((u32) *(u32 *)&this->unk_7C != 0U) {
        stack.sp8 = lbl_805DD1D8;
        temp_f1 = this->m_4c - lbl_805DD1DC;
        stack.spC = temp_f1;
        if ((u32) this->m_78 != 0U) {
            stack.spC = temp_f1 - lbl_805DD1E0;
        }
        clamp_list_scroll_offset((int) (*(u32 *)&this->unk_7C), arg0 + 0x68, &stack.sp8);
    }
}

void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);

void TUnk_804D0658::draw_setting(s32 window_key_board_soft) {
    u16 *temp_r3;

    temp_r3 = ((u16 * (*)(void *, s16))get_array_entry__13TUnk_804CE018Fi)(this, this->m_74);
    if (*temp_r3 & 1) {
        draw_selection_bar((u8 *)window_key_board_soft, (u8 *)temp_r3, ((s32 (*)(void *))is_open__13TUnk_804D0658Fv)(this));
    }
}

extern s32 lbl_805D3970;
extern const f32 lbl_805DD1F4;

void TWindowMenuInfomation__ct(u8 *lobby, u32 arg1) {
    u32 i;
    u8 *e;
    *(s32 *)lobby = lbl_805D3970;
    *(s16 *)(lobby + 0x72) = 0;
    *(s16 *)(lobby + 0x74) = 0;
    *(u16 *)(lobby + 0x76) = arg1;
    *(s16 *)(lobby + 0x70) = 0;
    *(s32 *)(lobby + 0x78) = 0;
    *(s32 *)(lobby + 0x7C) = 0;
    for (i = 0; i < arg1; i++) {
        e = ((u8 *(*)(void *, u32))get_array_entry__13TUnk_804CE018Fi)(lobby, i);
        *(f32 *)(e + 0xC) = (f32)(i * 0x14);
    }
    ((TLobby *)lobby)->set_field_1c(lbl_805DD1F4);
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct V_80268C5C { f32 x; f32 y; };

extern V_80268C5C choice_setting_popup_window_descriptor[];
extern s32 lbl_804D0638[];
extern "C" {
void fn_80268C5C(V_80268C5C v, s32 x);
s32 __nw__7TObjectFUl(s32);
s32 fn_80269004(s32, s32, s32);
s32 get_window_layout_position(s32);
}
extern s32 lbl_8044F3A0[];
extern s32 lbl_8044F3B8[];
s32 create_information_counter_window(s32 arg0) {
    s32 var_r31;

    ((s32 (*)(s32 *, s32))fn_80268C5C)(lbl_8044F3A0, arg0);
    var_r31 = __nw__7TObjectFUl(0x80);
    if (var_r31 != 0) {
        var_r31 = fn_80269004(var_r31, get_window_layout_position(0xAE), arg0);
    }
    ((s32 (*)(s32, s32 *))create_sub_window__20TWindowChoiceSettingFPvi)(var_r31, lbl_8044F3B8);
    return var_r31;
}

void fn_80268C5C(V_80268C5C v, s32 x) {
    choice_setting_popup_window_descriptor[0] = v;
    lbl_804D0638[1] = x;
}

struct RecoveredGlobal_80268D08_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern RecoveredGlobal_80268D08_lbl_8050E208 controller_input_state;
extern const f32 lbl_805DD1F8;
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, s32);
s32 draw_window_scrollbar(s32, s32, void *);
void __dl__7TObjectFPv(void *);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);

void TWindowSubStatusDisp__sub_80268C80(u8 *arg0) {
    s32 temp_r3;

    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TUnk_804CE018 *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    ((TUnk_804D0658 *)arg0)->draw_setting(temp_r3);
    if ((u32) ((TUnk_804D0658 *)arg0)->m_78 != 0U) {
        forward_render__20TWindowSubStatusDispFv(((TUnk_804D0658 *)arg0)->m_78, temp_r3);
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x7C) != 0U) {
        draw_window_scrollbar(*(u32 *)((s8 *)arg0 + 0x7C), temp_r3, arg0 + 0x68);
    }
}

extern s32 choice_setting_popup_vtable[];

typedef char RecoveredGlobal_80268D08_lbl_8050E208_size[sizeof(RecoveredGlobal_80268D08_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubStatusDisp::handle_choice_input() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r3;
    u32 temp_r3_2;
    u8 *input;
    u8 *temp_r30_2;
    u8 *temp_r30_3;
    if ((((TUnk_804D0658 *)arg0)->is_selected() == 0) && (((s32 (*)(void *))is_open__13TUnk_804D0658Fv)(arg0) == 0)) {
        if (*(u16 *)((s8 *)arg0 + 0x70) & 0x10) {
            input = (u8 *)&controller_input_state.value + 0x20;
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_cursor_prev();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_next_choice();
            }
        } else {
            temp_r30_2 = (u8 *)&controller_input_state.value + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r30_2, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r30_2, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_next_choice();
            }
        }
        temp_r30_3 = (u8 *)&controller_input_state.value + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r30_3, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
            ((TUnk_804D0658 *)arg0)->draw();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r30_3, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
            ((TUnk_804D0658 *)arg0)->request_close();
        }
    }
    if ((f32) *(s32 *)&this->m_5c >= lbl_805DD1F8) {
        temp_r3 = *(u32 *)((s8 *)arg0 + 0x78);
        if (temp_r3 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
        }
        temp_r3_2 = *(u32 *)((s8 *)arg0 + 0x7C);
        if (temp_r3_2 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3_2)->increment_counter();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TUnk_804CDFE8 *)arg0)->step_window_tween();
    ((TUnk_804D0658 *)arg0)->update_scroll_offset();
    ((TUnk_804D0658 *)arg0)->clamp_scroll();
    ((TUnk_804CE018 *)arg0)->update_window_entry_list((u8 *)&this->m_24);
}

void *TUnk_804D0658::destroy_children(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = choice_setting_popup_vtable;
        TWindowSubStatusDisp::destroy_allocation((s32)(*(void * *)&this->unk_7C), (s16)1);
        TWindowSubStatusDisp::destroy_status_display((s32)(*(void * *)&this->m_78), (s16)1);
        destroy_window(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}
