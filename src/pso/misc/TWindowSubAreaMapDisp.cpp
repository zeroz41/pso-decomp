#include "types.h"
#include "pso/misc/TWindowSubAreaMapDisp.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TLobby_8001D6A0.h"
#include "pso/misc/TWindowCtrl_80271DFC.h"
#include "pso/misc/TWindowSubStatusDisp_80228CC0.h"
#include "pso/misc/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/CurrentArea.h"

extern "C" {

s32 sub_80246948__13TUnk_804CE018Fv();

void TWindowSubAreaMapDisp::update_visibility() {
    if ((s32) this->m_6c != 0) {
        if (sub_80246948__13TUnk_804CE018Fv() != 0) {
            this->m_6c = 0;
            TWindowCtrl::clear_active_flag();
            TRaderMapCore::clear();
        }
    } else if (!(this->m_2c & 2) && (sub_80246948__13TUnk_804CE018Fv() == 0)) {
        this->m_6c = 1;
        TRaderMapCore::open_free_map_view();
        TRaderMapCore::show_radar();
        TWindowCtrl::set_flag_bit0();
        {
            f32 c = 0.0f;
            *(f32 *)&this->unk_60 = c;
            this->m_64 = c;
            *(f32 *)&this->unk_68 = c;
        }
    }
}

}

struct RecoveredGlobal_80271C6C___vt__21TWindowSubAreaMapDisp { s32 value; u8 remaining[0x18]; };
typedef char RecoveredGlobal_80271C6C___vt__21TWindowSubAreaMapDisp_size[sizeof(RecoveredGlobal_80271C6C___vt__21TWindowSubAreaMapDisp) == 0x1C ? 1 : -1];

struct RecoveredGlobal_80271D00_lbl_804D0FC0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80271D00___vt__21TWindowSubAreaMapDisp {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
void mem_free(void *p);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_80271C6C___vt__21TWindowSubAreaMapDisp __vt__21TWindowSubAreaMapDisp;
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32 arg0);
u8 *get_floor_destination_name(s32);
void *mem_alloc(u32 size);
s32 measure_string_len__20TWindowSubStatusDispFv(int);
void text_builder_append(u8 *str);
}
void text_builder_reset(void);
extern "C" {
s32 get_window_layout_position(int);
s32 construct_type1_heading__20TWindowSubStatusDispFll(int, int, int);
s32 get_game_play_mode();
s32 strncpy(int, int, void *);
extern RecoveredGlobal_80271D00_lbl_804D0FC0 TWindowSubAreaMapDisp__window_parameters;
extern s32 TWindowSubAreaMapDisp__name;
extern s32 local_client_id;
void apply_context_transform_to_rect(void *, void *);
extern s32 lbl_805D63F0;

struct Vec2_80271A6C {
    f32 x;
    f32 y;
};

s32 draw_default_entry__9TWindowDDFl();
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);

struct Rect_80271848 { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

void fn_80271848(s32 arg0, u8 *arg1) {
    Rect_80271848 r;
    s32 color;
    f32 scale;

    scale = (-1.0f) / (0.1794f + *(f32 *)(arg1 + 0x38));
    if (*(s32 *)(arg1 + 0x30) < 6) {
        color = ((s32)(0.16666667f * (f32)(*(s32 *)(arg1 + 0x30) * 0xFF)) << 24) | 0xFFFFFF;
    } else {
        color = -1;
    }
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0, color);
    r.x0 = 16.0f;
    r.y0 = 346.0f;
    r.x1 = 12.0f + r.x0;
    r.y1 = 14.0f + r.y0;
    r.u0 = 0.87109375f;
    r.v0 = 0.1640625f;
    r.u1 = 0.91796875f;
    r.v1 = 0.21875f;
    apply_context_transform_to_rect(arg1, &r);
    draw_textured_quad_at_depth((f32 *)&r, scale);
    r.x0 = 484.0f;
    r.y0 = 346.0f;
    r.x1 = 12.0f + r.x0;
    r.y1 = 14.0f + r.y0;
    r.u0 = 0.9296875f;
    r.u1 = 0.9765625f;
    apply_context_transform_to_rect(arg1, &r);
    draw_textured_quad_at_depth((f32 *)&r, scale);
    r.x0 = 249.0f;
    r.y0 = 272.0f;
    r.x1 = 14.0f + r.x0;
    r.y1 = 12.0f + r.y0;
    r.u0 = 0.9375f;
    r.v0 = 0.0f;
    r.u1 = 0.9921875f;
    r.v1 = 0.046875f;
    apply_context_transform_to_rect(arg1, &r);
    draw_textured_quad_at_depth((f32 *)&r, scale);
    r.x0 = 249.0f;
    r.y0 = 4.2e+02f;
    r.x1 = 14.0f + r.x0;
    r.y1 = 12.0f + r.y0;
    r.v0 = 0.109375f;
    r.v1 = 0.15625f;
    apply_context_transform_to_rect(arg1, &r);
    draw_textured_quad_at_depth((f32 *)&r, scale);
    TWindowSubStatusDisp::get_player();
}

void TWindowSubStatusDisp__sub_80271A6C(s32 arg0, u8 *arg1) {
    Vec2_80271A6C pos;
    s32 color;
    f32 scale;

    scale = (-1.0f) / (0.1794f + *(f32 *)(arg1 + 0x38));
    if (*(s32 *)(arg1 + 0x30) < 6) {
        color = ((s32)(0.16666667f * (f32)(*(s32 *)(arg1 + 0x30) * 0xFF)) << 24) | 0xFFFFFF;
    } else {
        color = -1;
    }
    set_text_draw_params((s32)arg1, 0, 0, (f32)scale, (f32)1e+05f);
    pos.x = 487.0f + *(f32 *)(arg1 + 0x3C);
    pos.y = 41.0f + *(f32 *)(arg1 + 0x40);
    draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_message_10(0x11B)), color, 0, (f32)1e+06f);
    pos.y = 97.0f + *(f32 *)(arg1 + 0x40);
    draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_message_10(0x11C)), color, 0, (f32)1e+06f);
}

void TWindowSubAreaMapDisp::render() {
    s32 temp_r3;

    temp_r3 = draw_default_entry__9TWindowDDFl();
    draw_window_frame((void *)temp_r3);
    forward_render__20TWindowSubStatusDispFv(this->m_70, temp_r3);
    if ((s32) this->m_6c != 0) {
        ((s32 (*)(void *, s32))TWindowSubStatusDisp__sub_80271A6C)(this, temp_r3);
        ((s32 (*)(void *, s32))fn_80271848)(this, temp_r3);
    }
}

void TWindowSubAreaMapDisp::run_task() {
    u8 *arg0 = (u8 *)this;
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowSubAreaMapDisp *)arg0)->update_visibility();
    ((TWindowSubAreaMapDisp *)arg0)->update_manual_scroll();
    if ((f32) *(s32 *)&this->m_5c >= 7.5f) {
        ((TWindowSubStatusDisp *)(*(u8 * *)&this->m_70))->update_subwindow();
    }
}
u8 *__dt__21TWindowSubAreaMapDispFv(TWindowSubAreaMapDisp *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__21TWindowSubAreaMapDisp.value;
        if ((u32) arg0->m_74 != 0U) {
            mem_free(*(void **)((s8 *)arg0 + 0x74));
            arg0->m_74 = 0U;
        }
        if ((s32) arg0->m_6c != 0) {
            TWindowCtrl::clear_active_flag();
            TRaderMapCore::clear();
        }
        TWindowSubStatusDisp::destroy_status_display(arg0->m_70, 1);
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return (u8 *)arg0;
}
typedef char RecoveredGlobal_80271D00_lbl_804D0FC0_size[sizeof(RecoveredGlobal_80271D00_lbl_804D0FC0) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80271D00___vt__21TWindowSubAreaMapDisp_size[sizeof(RecoveredGlobal_80271D00___vt__21TWindowSubAreaMapDisp) == 0x1C ? 1 : -1];
u8 *TWindowSubAreaMapDisp__ct(TWindowSubAreaMapDisp *window_sub_area_map_disp) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    u8 *var_r30;
    ((TWindowDD *)window_sub_area_map_disp)->construct_base((u8 *)&TWindowSubAreaMapDisp__window_parameters.value, (s16)((void *) ((s16) local_client_id)), (u8 *)(get_window_layout_position(0x59)));
    *(s32 **)((s8 *)window_sub_area_map_disp + 0x18) = &(*(RecoveredGlobal_80271D00___vt__21TWindowSubAreaMapDisp *)&__vt__21TWindowSubAreaMapDisp).value;
    *(s32 *)((s8 *)window_sub_area_map_disp + 0) = (s32) TWindowSubAreaMapDisp__name;
    if (get_game_play_mode() == 1) {
        text_builder_reset();
        text_builder_append((u8 *)(TQuestVmDownLoadServer__sub_8006EF6C(0x67)));
        append_text_space();
        append_padded_number((get_window_count_ratio_value()), (2U));
        var_r30 = (u8 *)(get_shared_text_buffer());
    } else {
        var_r30 = (u8 *)(get_floor_destination_name(get_current_area()));
    }
    temp_r3 = measure_string_len__20TWindowSubStatusDispFv((int)var_r30);
    window_sub_area_map_disp->m_74 = (s32)mem_alloc((temp_r3 + 1));
    strncpy((int)window_sub_area_map_disp->m_74, (int)var_r30, (void *)(temp_r3 + 1));
    temp_r3_2 = (int)::operator new(0x24);
    var_r0 = temp_r3_2;
    if (var_r0 != 0) {
        var_r0 = construct_type1_heading__20TWindowSubStatusDispFll(temp_r3_2, window_sub_area_map_disp->m_74, (int) ((s32) window_sub_area_map_disp->m_20));
    }
    window_sub_area_map_disp->m_70 = var_r0;
    window_sub_area_map_disp->m_6c = 0;
    return (u8 *)window_sub_area_map_disp;
}
}
