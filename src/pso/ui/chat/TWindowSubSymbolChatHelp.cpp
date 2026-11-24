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

struct Quad_8028429C { f32 x, y, x2, y2, u0, v0, u1, v1; };

struct Win_8028429C { u8 pad[0x10]; f32 x; f32 y; u8 pad2[0x38 - 0x18]; f32 scale; };


struct UV_802844C8 { f32 u, v; };

struct Quad_802844C8 { f32 x, y, x2, y2, u0, v0, u1, v1; };

struct Win_802844C8 { u8 pad[0x10]; f32 x; f32 y; u8 pad2[0x38 - 0x18]; f32 scale; };


struct UV_802845EC { f32 u, v; };

struct Quad_802845EC { f32 x, y, x2, y2, u0, v0, u1, v1; };

struct Win_802845EC { u8 pad[0x10]; f32 x; f32 y; u8 pad2[0x38 - 0x18]; f32 scale; };

const char *TWindowSubSymbolChatHelp__name = "TWindowSubSymbolChatHelp";
const UV_802845EC symbol_chat_help_icon_uv_table[6] = {
    {216.0f, 54.0f}, {216.0f, 70.0f}, {216.0f, 86.0f},
    {216.0f, 102.0f}, {216.0f, 118.0f}, {216.0f, 134.0f},
};
const UV_802844C8 symbol_chat_help_entry_uv_table[7] = {
    {0.0f, 0.0f}, {0.0f, 16.0f}, {0.0f, 32.0f}, {0.0f, 48.0f},
    {0.0f, 64.0f}, {0.0f, 80.0f}, {0.0f, 96.0f},
};

WindowDescriptor symbol_chat_help_window_layout = {
    {242.0f, 116.0f}, 50050.0f, NULL, 3,
};

extern "C" {
int TWindowSubSymbolChatHelp__sub_80247EE8(int);
void draw_help_icon__24TWindowSubSymbolChatHelpFiPvii(s32 arg0, Win_802845EC *arg1, s32 arg2, s32 arg3);


#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatHelp::draw_color_palette(void *arg1) {
    Quad_8028429C q;
    f32 scale;
    s32 i;
    s32 t;
    scale = (-1.0f) / ((0.1794f) + ((Win_8028429C *)arg1)->scale);
    q.u0 = (0.9375f);
    q.v0 = (0.15234375f);
    q.u1 = (0.9921875f);
    q.v1 = (0.20703125f);
    for (i = 0; i < 8; i++) {
        if (m_60 & 2) {
            t = TWindowSubSymbolChatPartsSet::get_parts_entry(i);
        } else {
            t = TWindowSubSymbolChatHelp__sub_80247EE8(i);
        }
        set_constant_material_color(t);
        q.x = (112.0f + ((Win_8028429C *)arg1)->x) + 12.0f * (f32)i;
        q.y = 50.0f + ((Win_8028429C *)arg1)->y;
        q.x2 = 14.0f + q.x;
        q.y2 = 14.0f + q.y;
        ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)&q);
        draw_textured_quad_at_depth((f32 *)&q, scale);
    }
    if (m_60 & 2) {
        set_constant_material_color(-1);
    } else {
        set_constant_material_color(0xFF808080);
    }
    q.x = 12.0f * (f32)*m_64 + (112.0f + ((Win_8028429C *)arg1)->x);
    q.y = 50.0f + ((Win_8028429C *)arg1)->y;
    q.x2 = 14.0f + q.x;
    q.y2 = 14.0f + q.y;
    q.u0 = (0.87109375f);
    q.v0 = (0.15234375f);
    q.u1 = (0.92578125f);
    q.v1 = (0.20703125f);
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatHelp::draw_help_entry(void *arg1, s32 arg2, s32 arg3) {
    Quad_802844C8 q;
    const UV_802844C8 *uv;
    f32 scale;
    s32 idx;
    idx = arg2;
    if (arg2 == 2 && *m_68 == 1) {
        idx = 6;
    }
    uv = &symbol_chat_help_entry_uv_table[idx];
    scale = (-1.0f) / ((0.1794f) + ((Win_802844C8 *)arg1)->scale);
    set_constant_material_color(arg3);
    q.x = (16.0f) + ((Win_802844C8 *)arg1)->x;
    q.y = (16.0f) * (f32)arg2 + ((Win_802844C8 *)arg1)->y;
    q.x2 = 231.0f + q.x;
    q.y2 = (16.0f) + q.y;
    q.u0 = uv->u / 256.0f;
    q.v0 = uv->v / 256.0f;
    q.u1 = (231.0f + uv->u) / 256.0f;
    q.v1 = ((16.0f) + uv->v) / 256.0f;
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
}
#pragma pop

#pragma push
#pragma fp_contract on
void draw_help_icon__24TWindowSubSymbolChatHelpFiPvii(s32 arg0, Win_802845EC *arg1, s32 arg2, s32 arg3) {
    Quad_802845EC q;
    const UV_802845EC *uv;
    f32 scale;
    uv = &symbol_chat_help_icon_uv_table[arg2];
    scale = (-1.0f) / ((0.1794f) + arg1->scale);
    set_constant_material_color(arg3);
    q.x = arg1->x;
    q.y = (16.0f) * (f32)arg2 + arg1->y;
    q.x2 = (16.0f) + q.x;
    q.y2 = (16.0f) + q.y;
    q.u0 = uv->u / 256.0f;
    q.v0 = uv->v / 256.0f;
    q.u1 = ((16.0f) + uv->u) / 256.0f;
    q.v1 = ((16.0f) + uv->v) / 256.0f;
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
}
#pragma pop

void TWindowSubSymbolChatHelp::draw_help_entries(void *arg1) {
    if ((s32) *(s32 *)((s8 *)arg1 + 0x30) >= 0) {
        begin_screen_draw(1);
        TObjFish::set_global_param(hud_texlist);
        set_draw_texture_and_color(2, -1);
        draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 0, -1);
        draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 1, -1);
        if (this->m_60 & 1) {
            draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 2, -1);
        } else {
            draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 2, (s32)(0xFF808080));
        }
        if (this->m_60 & 2) {
            draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 3, -1);
        } else {
            draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 3, (s32)(0xFF808080));
        }
        if (this->m_60 & 4) {
            draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 4, -1);
            draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 5, -1);
        } else {
            draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 4, (s32)(0xFF808080));
            draw_help_icon__24TWindowSubSymbolChatHelpFiPvii((saddr)this, (Win_802845EC *)(arg1), 5, (s32)(0xFF808080));
        }
        draw_color_palette((Win_8028429C *)(arg1));
        TWindowSubStatusDisp::get_player();
        begin_screen_draw(1);
        TWindowSubStatusDisp::begin_render();
        set_draw_texture_and_color(1, -1);
        draw_help_entry((Win_802844C8 *)(arg1), 0, -1);
        draw_help_entry((Win_802844C8 *)(arg1), 1, -1);
        if (this->m_60 & 1) {
            draw_help_entry((Win_802844C8 *)(arg1), 2, -1);
        } else {
            draw_help_entry((Win_802844C8 *)(arg1), 2, (s32)(0xFF808080));
        }
        if (this->m_60 & 2) {
            draw_help_entry((Win_802844C8 *)(arg1), 3, -1);
        } else {
            draw_help_entry((Win_802844C8 *)(arg1), 3, (s32)(0xFF808080));
        }
        if (this->m_60 & 4) {
            draw_help_entry((Win_802844C8 *)(arg1), 4, -1);
            draw_help_entry((Win_802844C8 *)(arg1), 5, -1);
        } else {
            draw_help_entry((Win_802844C8 *)(arg1), 4, (s32)(0xFF808080));
            draw_help_entry((Win_802844C8 *)(arg1), 5, (s32)(0xFF808080));
        }
        TWindowSubStatusDisp::get_player();
    }
}

void TWindowSubSymbolChatHelp::handle_toggle_input() {
    s32 *temp_r3;
    s32 *temp_r3_2;
    void *context;

    if (this->m_60 & 4) {
        context = &controller_input_state.controllers[0];
        if (test_pressed_buttons_packed(context, 0x10000) != 0) {
            temp_r3 = m_6c;
            if ((s32) *temp_r3 != 0) {
                *temp_r3 = 0;
            } else {
                *temp_r3 = 1;
            }
        }
        if (test_pressed_buttons_packed(context, 0x20000) != 0) {
            temp_r3_2 = m_70;
            if ((s32) *temp_r3_2 != 0) {
                *temp_r3_2 = 0;
                return;
            }
            *temp_r3_2 = 1;
        }
    }
}

void TWindowSubSymbolChatHelp::handle_page_input() {
    if ((m_60 & 2) && test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x200) != 0) {
        ++*m_64;
        s8 *selection = m_64;
        if (*selection >= 8) {
            *selection -= 8;
        }
    }
}

void TWindowSubSymbolChatHelp::render() {
    saddr arg0 = (saddr)this;
    saddr temp_r3;
    temp_r3 = reinterpret_cast<saddr>(draw_default_entry());
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_help_entries((void *)temp_r3);
}

void TWindowSubSymbolChatHelp::run_task() { handle_page_input(); handle_toggle_input(); ((TWindowDD *)this)->initialize_subwindow(); }

TWindowSubSymbolChatHelp::~TWindowSubSymbolChatHelp() {}
TWindowSubSymbolChatHelp::TWindowSubSymbolChatHelp(s8 *selection, s32 *mode)
    : TWindowBase((u8 *)&symbol_chat_help_window_layout, 4, reinterpret_cast<u8 *>(const_cast<NJS_POINT2 *>(get_window_layout_position(0x7E)))) {
    m_name = TWindowSubSymbolChatHelp__name;
    m_60 = 0;
    m_64 = selection;
    m_68 = mode;
    m_6c = NULL;
    m_70 = NULL;
}

}
