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
#include "pso/unk/text_803DA798.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/HeadingEntry.h"

#pragma readonly_strings on



void TWindowSubAreaMapDisp::update_visibility() {
    if (this->manual_scroll != 0) {
        if (this->is_closed() != 0) {
            this->manual_scroll = 0;
            TWindowCtrl::clear_active_flag();
            TRaderMapCore::clear();
        }
    } else if (!(this->window_flags & 2) && (this->is_closed() == 0)) {
        this->manual_scroll = 1;
        TRaderMapCore::open_free_map_view();
        TRaderMapCore::show_radar();
        TWindowCtrl::set_flag_bit0();
        {
            f32 c = 0.0f;
            this->pan_x_speed = c;
            this->pan_y_speed = c;
            this->zoom_speed = c;
        }
    }
}


WindowDescriptor TWindowSubAreaMapDisp::window_parameters = {
    {610.0f, 188.0f}, 50150.0f, NULL, 3,
};

const char *TWindowSubAreaMapDisp::class_name = "TWindowSubAreaMapDisp";



void TWindowSubAreaMapDisp::draw_pan_arrows(WindowDrawContext *context) {
    TexturedQuad r;
    s32 color;
    f32 scale;

    scale = (-1.0f) / (0.1794f + context->depth);
    if (context->open_tick < 6) {
        color = ((s32)(0.16666667f * (f32)(context->open_tick * 0xFF)) << 24) | 0xFFFFFF;
    } else {
        color = -1;
    }
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(0, color);
    r.x0 = 16.0f;
    r.y0 = 346.0f;
    r.x1 = 12.0f + r.x0;
    r.y1 = 14.0f + r.y0;
    r.u0 = 0.87109375f;
    r.v0 = 0.1640625f;
    r.u1 = 0.91796875f;
    r.v1 = 0.21875f;
    context->transform_quad(&r);
    draw_textured_quad_at_depth(&r.x0, scale);
    r.x0 = 484.0f;
    r.y0 = 346.0f;
    r.x1 = 12.0f + r.x0;
    r.y1 = 14.0f + r.y0;
    r.u0 = 0.9296875f;
    r.u1 = 0.9765625f;
    context->transform_quad(&r);
    draw_textured_quad_at_depth(&r.x0, scale);
    r.x0 = 249.0f;
    r.y0 = 272.0f;
    r.x1 = 14.0f + r.x0;
    r.y1 = 12.0f + r.y0;
    r.u0 = 0.9375f;
    r.v0 = 0.0f;
    r.u1 = 0.9921875f;
    r.v1 = 0.046875f;
    context->transform_quad(&r);
    draw_textured_quad_at_depth(&r.x0, scale);
    r.x0 = 249.0f;
    r.y0 = 4.2e+02f;
    r.x1 = 14.0f + r.x0;
    r.y1 = 12.0f + r.y0;
    r.v0 = 0.109375f;
    r.v1 = 0.15625f;
    context->transform_quad(&r);
    draw_textured_quad_at_depth(&r.x0, scale);
    end_screen_draw();
}

void TWindowSubAreaMapDisp::draw_zoom_button_hints(WindowDrawContext *context) {
    NJS_POINT2 pos;
    s32 color;
    f32 scale;

    scale = (-1.0f) / (0.1794f + context->depth);
    if (context->open_tick < 6) {
        color = ((s32)(0.16666667f * (f32)(context->open_tick * 0xFF)) << 24) | 0xFFFFFF;
    } else {
        color = -1;
    }
    set_text_draw_params(context, 0, 0, scale, (f32)1e+05f);
    pos.x = 487.0f + context->clip_x0;
    pos.y = 41.0f + context->clip_y0;
    draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_message_10(0x11B)), color, 0, (f32)1e+06f);
    pos.y = 97.0f + context->clip_y0;
    draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_message_10(0x11C)), color, 0, (f32)1e+06f);
}

void TWindowSubAreaMapDisp::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_window_frame(context);
    heading->render(context);
    if (this->manual_scroll != 0) {
        draw_zoom_button_hints(context);
        draw_pan_arrows(context);
    }
}

void TWindowSubAreaMapDisp::run_task() {
    update_window();
    this->update_visibility();
    this->update_manual_scroll();
    if ((f32)this->open_tick >= 7.5f) {
        heading->update();
    }
}
TWindowSubAreaMapDisp::~TWindowSubAreaMapDisp() {
    if (title != NULL) {
        mem_free(title);
        title = NULL;
    }
    if (this->manual_scroll != 0) {
        TWindowCtrl::clear_active_flag();
        TRaderMapCore::clear();
    }
    delete heading;
}
TWindowSubAreaMapDisp::TWindowSubAreaMapDisp() : TWindowBase((u8 *)&TWindowSubAreaMapDisp::window_parameters, (s16)((s16) local_client_id), (u8 *)(get_window_layout_position(0x59))) {
    s32 title_len;
    WindowHeading *display;
    u8 *str;

    this->m_name = TWindowSubAreaMapDisp::class_name;
    if (get_game_play_mode() == 1) {
        text_builder_reset();
        text_builder_append((const char *)(get_message_text(0x67)));
        append_text_space();
        append_padded_number((get_window_count_ratio_value()), (2U));
        str = (u8 *)get_shared_text_buffer();
    } else {
        str = (u8 *)(get_floor_destination_name(get_current_floor_area()));
    }
    title_len = (s32)measure_string_len((const char *)str);
    title = static_cast<char *>(mem_alloc(title_len + 1));
    strncpy(title, (const char *)str, (u32)title_len + 1);
    display = new WindowHeading(reinterpret_cast<saddr>(title), client_index);
    heading = display;
    this->manual_scroll = 0;
}

