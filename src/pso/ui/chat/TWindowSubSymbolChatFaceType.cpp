#include "pso/ui/window/WindowSpritePart.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/player/LocalClientId.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/render/TextureState.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/player/LocalClientId.h"
extern const char symbol_chat_face_type_class_name_string[29] = "TWindowSubSymbolChatFaceType";




void TWindowSubSymbolChatFaceType::close_when_chat_closed() {
    if (is_open() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->result_flags = (u8) (this->result_flags | 2);
    }
}

void TWindowSubSymbolChatFaceType::confirm_selection() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->result_flags = (u8) (this->result_flags | 1);
    status_disp->set_state(2);
}




void TWindowSubSymbolChatFaceType::handle_input() {
    ControllerInputContext *input;
    input = &controller_input_state.controllers[0];
    if ((test_buttons_press_or_repeat(input, 0xF0, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0U, 0, 0);
        if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->cursor_row = (this->cursor_row - 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            this->cursor_row = (this->cursor_row + 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            this->cursor_col = (this->cursor_col + 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
            this->cursor_col = (this->cursor_col - 1);
        }
        if ((s8) this->cursor_col < 0) {
            this->cursor_col = 0U;
        }
        if ((s8) this->cursor_col >= 2) {
            this->cursor_col = 1U;
        }
        if ((s8) this->cursor_row < 0) {
            this->cursor_row = 0U;
        }
        if ((s8) this->cursor_row >= 2) {
            this->cursor_row = 1U;
        }
    }
}

void draw_selection_corners(WindowDrawContext *ctx, f32 *pos, f32 size, f32 amp) {
    TexturedQuad q;
    u32 alpha;
    f32 x;
    f32 y;
    f32 top;
    f32 left;
    f32 depth;

    if (ctx->open_tick < 0) {
        return;
    }
    if (ctx->open_tick < 6) {
        alpha = (u32)(0.16666667f * (f32)(ctx->open_tick * 255));
        alpha <<= 24;
    } else {
        alpha = 0xFF000000;
    }
    amp = (f32)(actor_frame_tick & 0xF) * amp;
    size -= 12.0f;
    depth = -1.0f / (0.26909998f + ctx->depth);
    x = ctx->inner_x + pos[0];
    y = ctx->inner_y + pos[1];
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(2, alpha | 0xFF0000 | 0xFFFF);
    left = x + amp;
    top = y + amp;
    q.x0 = left;
    q.y0 = top;
    q.x1 = 12.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.u0 = 0.87109375f;
    q.v0 = 0.0f;
    q.u1 = 0.91796875f;
    q.v1 = 0.046875f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    x = size + (x - amp);
    q.x0 = x;
    q.y0 = top;
    q.x1 = 12.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.u0 = 0.91796875f;
    q.u1 = 0.96484375f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    size = size + (y - amp);
    q.x0 = x;
    q.y0 = size;
    q.x1 = 12.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.v0 = 0.046875f;
    q.v1 = 0.09375f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    q.x0 = left;
    q.y0 = size;
    q.x1 = 12.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.u0 = 0.87109375f;
    q.u1 = 0.91796875f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    end_screen_draw();
}
void draw_face_selection(TWindowSubSymbolChatFaceType *window, WindowDrawContext *context) {
  int entry_index;
  WindowSpritePart *face;
  NJS_POINT2 corner;
  entry_index = window->get_face_index();
  face = (WindowSpritePart *)window->get_array_entry(entry_index);
  corner.x = face->x - 3.0f;
  corner.y = face->y - 3.0f;
  draw_selection_corners(context, (f32 *)&corner, 66.0f, 0.3f);
}
extern "C" {

void TWindowSubSymbolChatFaceType::update_parts_entries() {
    s32 i;
    for (i = 0; i < 4; i++) {
        WindowSpritePart *e = (WindowSpritePart *)get_array_entry(i);
        e->color = TWindowSubSymbolChatPartsSet::get_parts_color(*selection);
    }
}

void TWindowSubSymbolChatFaceType::render() {
    WindowDrawContext *context = draw_default_entry();
    update_parts_entries();
    draw_window_frame(context);
    draw_face_selection(this, context);
    status_disp->render(context);
    draw_visible_window_entries(this, &entry_list, context);
}
void TWindowSubSymbolChatFaceType::run_task() {
    TWindowSubSymbolChatFaceType *window_sub_symbol_chat_face_type = this;
    ControllerInputContext *context;
    if (!(window_sub_symbol_chat_face_type->window_flags & 2)) {
        window_sub_symbol_chat_face_type->open_tick = 0x01000000;
    }
    if (window_sub_symbol_chat_face_type->is_open() == 0) {
        window_sub_symbol_chat_face_type->handle_input();
        context = &controller_input_state.controllers[0];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            window_sub_symbol_chat_face_type->confirm_selection();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            window_sub_symbol_chat_face_type->close_when_chat_closed();
        }
    }
    if ((f32) (s32)window_sub_symbol_chat_face_type->open_tick >= 7.5f) {
        status_disp->update();
    }
    window_sub_symbol_chat_face_type->update_window();
    window_sub_symbol_chat_face_type->update_window_entry_list(&window_sub_symbol_chat_face_type->entry_list);
}

}




TWindowSubSymbolChatFaceType::~TWindowSubSymbolChatFaceType() {
    delete status_disp;
}



SymbolChatFaceTypeWindowLayout symbol_chat_face_type_layout_entries = {
    4, 1,
    {
        {6, {16.0f, 16.0f}, {60.0f, 60.0f}, 2.0f, 194.0f, 0.5f, -1, &hud_texlist, 0xA, 4},
        {6, {96.0f, 16.0f}, {60.0f, 60.0f}, 2.0f, 130.0f, 0.5f, -1, &hud_texlist, 0xA, 4},
        {6, {16.0f, 96.0f}, {60.0f, 60.0f}, 66.0f, 130.0f, 0.5f, -1, &hud_texlist, 0xA, 4},
        {6, {96.0f, 96.0f}, {60.0f, 60.0f}, 66.0f, 194.0f, 0.5f, -1, &hud_texlist, 0xA, 4},
    },
};
WindowDescriptor symbol_chat_face_type_window_layout = {
    {178.0f, 188.0f}, 50050.0f, &symbol_chat_face_type_layout_entries, 0x43,
};

const char *TWindowSubSymbolChatFaceType::class_name = symbol_chat_face_type_class_name_string;
TWindowSubSymbolChatFaceType::TWindowSubSymbolChatFaceType(const NJS_POINT2 *position, s8 *selected)
    : TWindowBase((u8 *)&symbol_chat_face_type_window_layout, 4, (u8 *)position) {
    WindowHeading *heading;
    m_name = class_name;
    result_flags = 0;
    cursor_col = 0;
    cursor_row = 0;
    selection = selected;
    heading = new WindowHeading(TWindowSubStatusDisp::get_message_10(0x33), client_index);
    status_disp = heading;
}

