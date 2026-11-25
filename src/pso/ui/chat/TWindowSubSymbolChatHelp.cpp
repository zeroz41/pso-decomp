#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/chat/TWindowSubSymbolChatHelp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/WindowLayout.h"


struct HelpEntryUv { f32 u, v; };


struct HelpIconUv { f32 u, v; };

const char *window_sub_symbol_chat_help_name = "TWindowSubSymbolChatHelp";
const HelpIconUv symbol_chat_help_icon_uv_table[6] = {
    {216.0f, 54.0f}, {216.0f, 70.0f}, {216.0f, 86.0f},
    {216.0f, 102.0f}, {216.0f, 118.0f}, {216.0f, 134.0f},
};
const HelpEntryUv symbol_chat_help_entry_uv_table[7] = {
    {0.0f, 0.0f}, {0.0f, 16.0f}, {0.0f, 32.0f}, {0.0f, 48.0f},
    {0.0f, 64.0f}, {0.0f, 80.0f}, {0.0f, 96.0f},
};

WindowDescriptor symbol_chat_help_window_layout = {
    {242.0f, 116.0f}, 50050.0f, NULL, 3,
};

extern "C" {
int TWindowSubSymbolChatHelp__sub_80247EE8(int);


#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatHelp::draw_color_palette(void *context) {
    TexturedQuad q;
    f32 scale;
    s32 i;
    s32 t;
    scale = (-1.0f) / ((0.1794f) + ((WindowDrawContext *)context)->depth);
    q.u0 = (0.9375f);
    q.v0 = (0.15234375f);
    q.u1 = (0.9921875f);
    q.v1 = (0.20703125f);
    for (i = 0; i < 8; i++) {
        if (feature_flags & 2) {
            t = TWindowSubSymbolChatPartsSet::get_parts_entry(i);
        } else {
            t = TWindowSubSymbolChatHelp__sub_80247EE8(i);
        }
        set_constant_material_color(t);
        q.x0 = (112.0f + ((WindowDrawContext *)context)->inner_x) + 12.0f * (f32)i;
        q.y0 = 50.0f + ((WindowDrawContext *)context)->inner_y;
        q.x1 = 14.0f + q.x0;
        q.y1 = 14.0f + q.y0;
        ((WindowDrawContext *)context)->transform_quad((TexturedQuad *)&q);
        draw_textured_quad_at_depth((f32 *)&q, scale);
    }
    if (feature_flags & 2) {
        set_constant_material_color(-1);
    } else {
        set_constant_material_color(0xFF808080);
    }
    q.x0 = 12.0f * (f32)*color_selection + (112.0f + ((WindowDrawContext *)context)->inner_x);
    q.y0 = 50.0f + ((WindowDrawContext *)context)->inner_y;
    q.x1 = 14.0f + q.x0;
    q.y1 = 14.0f + q.y0;
    q.u0 = (0.87109375f);
    q.v0 = (0.15234375f);
    q.u1 = (0.92578125f);
    q.v1 = (0.20703125f);
    ((WindowDrawContext *)context)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatHelp::draw_help_entry(void *context, s32 row, s32 color) {
    TexturedQuad q;
    const HelpEntryUv *uv;
    f32 scale;
    s32 idx;
    idx = row;
    if (row == 2 && *mirror_mode == 1) {
        idx = 6;
    }
    uv = &symbol_chat_help_entry_uv_table[idx];
    scale = (-1.0f) / ((0.1794f) + ((WindowDrawContext *)context)->depth);
    set_constant_material_color(color);
    q.x0 = (16.0f) + ((WindowDrawContext *)context)->inner_x;
    q.y0 = (16.0f) * (f32)row + ((WindowDrawContext *)context)->inner_y;
    q.x1 = 231.0f + q.x0;
    q.y1 = (16.0f) + q.y0;
    q.u0 = uv->u / 256.0f;
    q.v0 = uv->v / 256.0f;
    q.u1 = (231.0f + uv->u) / 256.0f;
    q.v1 = ((16.0f) + uv->v) / 256.0f;
    ((WindowDrawContext *)context)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatHelp::draw_help_icon(WindowDrawContext *context, s32 row, s32 color) {
    TexturedQuad q;
    const HelpIconUv *uv;
    f32 scale;
    uv = &symbol_chat_help_icon_uv_table[row];
    scale = (-1.0f) / ((0.1794f) + context->depth);
    set_constant_material_color(color);
    q.x0 = context->inner_x;
    q.y0 = (16.0f) * (f32)row + context->inner_y;
    q.x1 = (16.0f) + q.x0;
    q.y1 = (16.0f) + q.y0;
    q.u0 = uv->u / 256.0f;
    q.v0 = uv->v / 256.0f;
    q.u1 = ((16.0f) + uv->u) / 256.0f;
    q.v1 = ((16.0f) + uv->v) / 256.0f;
    ((WindowDrawContext *)context)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
}
#pragma pop

void TWindowSubSymbolChatHelp::draw_help_entries(void *context) {
    if ((s32) *(s32 *)((s8 *)context + 0x30) >= 0) {
        begin_screen_draw(1);
        TObjFish::set_global_param(hud_texlist);
        set_draw_texture_and_color(2, -1);
        draw_help_icon((WindowDrawContext *)(context), 0, -1);
        draw_help_icon((WindowDrawContext *)(context), 1, -1);
        if (this->feature_flags & 1) {
            draw_help_icon((WindowDrawContext *)(context), 2, -1);
        } else {
            draw_help_icon((WindowDrawContext *)(context), 2, (s32)(0xFF808080));
        }
        if (this->feature_flags & 2) {
            draw_help_icon((WindowDrawContext *)(context), 3, -1);
        } else {
            draw_help_icon((WindowDrawContext *)(context), 3, (s32)(0xFF808080));
        }
        if (this->feature_flags & 4) {
            draw_help_icon((WindowDrawContext *)(context), 4, -1);
            draw_help_icon((WindowDrawContext *)(context), 5, -1);
        } else {
            draw_help_icon((WindowDrawContext *)(context), 4, (s32)(0xFF808080));
            draw_help_icon((WindowDrawContext *)(context), 5, (s32)(0xFF808080));
        }
        draw_color_palette((WindowDrawContext *)(context));
        TWindowSubStatusDisp::get_player();
        begin_screen_draw(1);
        TWindowSubStatusDisp::begin_render();
        set_draw_texture_and_color(1, -1);
        draw_help_entry((WindowDrawContext *)(context), 0, -1);
        draw_help_entry((WindowDrawContext *)(context), 1, -1);
        if (this->feature_flags & 1) {
            draw_help_entry((WindowDrawContext *)(context), 2, -1);
        } else {
            draw_help_entry((WindowDrawContext *)(context), 2, (s32)(0xFF808080));
        }
        if (this->feature_flags & 2) {
            draw_help_entry((WindowDrawContext *)(context), 3, -1);
        } else {
            draw_help_entry((WindowDrawContext *)(context), 3, (s32)(0xFF808080));
        }
        if (this->feature_flags & 4) {
            draw_help_entry((WindowDrawContext *)(context), 4, -1);
            draw_help_entry((WindowDrawContext *)(context), 5, -1);
        } else {
            draw_help_entry((WindowDrawContext *)(context), 4, (s32)(0xFF808080));
            draw_help_entry((WindowDrawContext *)(context), 5, (s32)(0xFF808080));
        }
        TWindowSubStatusDisp::get_player();
    }
}

void TWindowSubSymbolChatHelp::handle_toggle_input() {
    s32 *first_flag;
    s32 *second_flag;
    void *context;

    if (this->feature_flags & 4) {
        context = &controller_input_state.controllers[0];
        if (test_pressed_buttons_packed(context, 0x10000) != 0) {
            first_flag = flip_u;
            if ((s32) *first_flag != 0) {
                *first_flag = 0;
            } else {
                *first_flag = 1;
            }
        }
        if (test_pressed_buttons_packed(context, 0x20000) != 0) {
            second_flag = flip_v;
            if ((s32) *second_flag != 0) {
                *second_flag = 0;
                return;
            }
            *second_flag = 1;
        }
    }
}

void TWindowSubSymbolChatHelp::handle_page_input() {
    if ((feature_flags & 2) && test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x200) != 0) {
        ++*color_selection;
        s8 *selection = color_selection;
        if (*selection >= 8) {
            *selection -= 8;
        }
    }
}

void TWindowSubSymbolChatHelp::render() {
    saddr self_addr = (saddr)this;
    saddr entry;
    entry = reinterpret_cast<saddr>(draw_default_entry());
    ((TWindowBase *)self_addr)->draw_window_frame((void *)entry);
    draw_help_entries((void *)entry);
}

void TWindowSubSymbolChatHelp::run_task() { handle_page_input(); handle_toggle_input(); update_window(); }

TWindowSubSymbolChatHelp::~TWindowSubSymbolChatHelp() {}
TWindowSubSymbolChatHelp::TWindowSubSymbolChatHelp(s8 *selection, s32 *mode)
    : TWindowBase((u8 *)&symbol_chat_help_window_layout, 4, reinterpret_cast<u8 *>(const_cast<NJS_POINT2 *>(get_window_layout_position(0x7E)))) {
    m_name = window_sub_symbol_chat_help_name;
    feature_flags = 0;
    color_selection = selection;
    mirror_mode = mode;
    flip_u = NULL;
    flip_v = NULL;
}

}
