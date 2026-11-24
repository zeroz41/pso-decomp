#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubAreaMapDisp.h"
#include "pso/object/TObjLuker_801329B0.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowCtrl_80271DFC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/ui/window/WindowLayout.h"

#pragma readonly_strings on

extern "C" {


void TWindowSubAreaMapDisp::update_visibility() {
    if ((s32) this->m_6c != 0) {
        if (this->is_closed() != 0) {
            this->m_6c = 0;
            TWindowCtrl::clear_active_flag();
            TRaderMapCore::clear();
        }
    } else if (!(this->window_flags & 2) && (this->is_closed() == 0)) {
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
LAYOUT_ASSERT(RecoveredGlobal_80271C6C___vt__21TWindowSubAreaMapDisp_size, sizeof(RecoveredGlobal_80271C6C___vt__21TWindowSubAreaMapDisp) == 0x1C);

struct RecoveredGlobal_80271D00___vt__21TWindowSubAreaMapDisp {
    s32 value;
    u8 remaining[0x18];
};

WindowDescriptor TWindowSubAreaMapDisp__window_parameters = {
    {610.0f, 188.0f}, 50150.0f, NULL, 3,
};

extern "C" {
extern RecoveredGlobal_80271C6C___vt__21TWindowSubAreaMapDisp __vt__21TWindowSubAreaMapDisp;
}
void text_builder_reset(void);
extern "C" {
const char *TWindowSubAreaMapDisp__name = "TWindowSubAreaMapDisp";
extern s32 local_client_id;


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
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0, color);
    r.x0 = 16.0f;
    r.y0 = 346.0f;
    r.x1 = 12.0f + r.x0;
    r.y1 = 14.0f + r.y0;
    r.u0 = 0.87109375f;
    r.v0 = 0.1640625f;
    r.u1 = 0.91796875f;
    r.v1 = 0.21875f;
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)&r);
    draw_textured_quad_at_depth((f32 *)&r, scale);
    r.x0 = 484.0f;
    r.y0 = 346.0f;
    r.x1 = 12.0f + r.x0;
    r.y1 = 14.0f + r.y0;
    r.u0 = 0.9296875f;
    r.u1 = 0.9765625f;
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)&r);
    draw_textured_quad_at_depth((f32 *)&r, scale);
    r.x0 = 249.0f;
    r.y0 = 272.0f;
    r.x1 = 14.0f + r.x0;
    r.y1 = 12.0f + r.y0;
    r.u0 = 0.9375f;
    r.v0 = 0.0f;
    r.u1 = 0.9921875f;
    r.v1 = 0.046875f;
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)&r);
    draw_textured_quad_at_depth((f32 *)&r, scale);
    r.x0 = 249.0f;
    r.y0 = 4.2e+02f;
    r.x1 = 14.0f + r.x0;
    r.y1 = 12.0f + r.y0;
    r.v0 = 0.109375f;
    r.v1 = 0.15625f;
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)&r);
    draw_textured_quad_at_depth((f32 *)&r, scale);
    TWindowSubStatusDisp::get_player();
}

void TWindowSubStatusDisp__sub_80271A6C(s32 arg0, u8 *arg1) {
    NJS_POINT2 pos;
    s32 color;
    f32 scale;

    scale = (-1.0f) / (0.1794f + *(f32 *)(arg1 + 0x38));
    if (*(s32 *)(arg1 + 0x30) < 6) {
        color = ((s32)(0.16666667f * (f32)(*(s32 *)(arg1 + 0x30) * 0xFF)) << 24) | 0xFFFFFF;
    } else {
        color = -1;
    }
    set_text_draw_params(reinterpret_cast<WindowDrawContext *>(arg1), 0, 0, (f32)scale, (f32)1e+05f);
    pos.x = 487.0f + *(f32 *)(arg1 + 0x3C);
    pos.y = 41.0f + *(f32 *)(arg1 + 0x40);
    draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_message_10(0x11B)), color, 0, (f32)1e+06f);
    pos.y = 97.0f + *(f32 *)(arg1 + 0x40);
    draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_message_10(0x11C)), color, 0, (f32)1e+06f);
}

void TWindowSubAreaMapDisp::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_window_frame(context);
    heading->forward_render(context);
    if ((s32) this->m_6c != 0) {
        ((s32 (*)(void *, s32))TWindowSubStatusDisp__sub_80271A6C)(this, reinterpret_cast<saddr>(context));
        ((s32 (*)(void *, s32))fn_80271848)(this, reinterpret_cast<saddr>(context));
    }
}

void TWindowSubAreaMapDisp::run_task() {
    u8 *arg0 = (u8 *)this;
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowSubAreaMapDisp *)arg0)->update_visibility();
    ((TWindowSubAreaMapDisp *)arg0)->update_manual_scroll();
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        heading->update_subwindow();
    }
}
TWindowSubAreaMapDisp::~TWindowSubAreaMapDisp() {
    if (title != NULL) {
        mem_free(title);
        title = NULL;
    }
    if ((s32) this->m_6c != 0) {
        TWindowCtrl::clear_active_flag();
        TRaderMapCore::clear();
    }
    TWindowSubStatusDisp::destroy_status_display(reinterpret_cast<saddr>(heading), 1);
}
LAYOUT_ASSERT(RecoveredGlobal_80271D00___vt__21TWindowSubAreaMapDisp_size, sizeof(RecoveredGlobal_80271D00___vt__21TWindowSubAreaMapDisp) == 0x1C);
TWindowSubAreaMapDisp::TWindowSubAreaMapDisp() : TWindowBase((u8 *)&TWindowSubAreaMapDisp__window_parameters, (s16)((s16) local_client_id), (u8 *)(get_window_layout_position(0x59))) {
    s32 temp_r3;
    TWindowSubStatusDisp *display;
    u8 *str;

    ((TWindowSubAreaMapDisp *)this)->m_name = TWindowSubAreaMapDisp__name;
    if (get_game_play_mode() == 1) {
        text_builder_reset();
        text_builder_append((u8 *)(get_message_text(0x67)));
        append_text_space();
        append_padded_number((get_window_count_ratio_value()), (2U));
        str = (u8 *)(get_shared_text_buffer());
    } else {
        str = (u8 *)(get_floor_destination_name(get_current_floor_area()));
    }
    temp_r3 = (s32)measure_string_len((const char *)str);
    title = static_cast<char *>(mem_alloc(temp_r3 + 1));
    strncpy(title, (const char *)str, (u32)temp_r3 + 1);
    display = static_cast<TWindowSubStatusDisp *>(::operator new(0x24));
    if (display != NULL) {
        display = reinterpret_cast<TWindowSubStatusDisp *>(
            display->construct_type1_heading(reinterpret_cast<saddr>(title), client_index));
    }
    heading = display;
    this->m_6c = 0;
}

}
