#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType_80283A70.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80283954.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
extern "C" {
extern const char TWindowSubSymbolChatFaceType__class_name_string[29] = "TWindowSubSymbolChatFaceType";
}

extern "C" {



void TWindowSubSymbolChatFaceType::close_when_chat_closed() {
    if (is_open() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 2);
    }
}

void TWindowSubSymbolChatFaceType::confirm_selection() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
    m_68->set_entry_state(2);
}

}

struct Stack_80283F38
{
  f32 sp8;
  f32 spC;
};

struct Ctx_80283C84 {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[0x30 - 0x18];
    s32 fade;
    u8 pad34[0x38 - 0x34];
    f32 depth;
};

struct Quad_80283C84 { f32 x, y, x2, y2, u, v, u2, v2; };


struct Ent_80283FA8 { u8 pad[0x2c]; s32 parts_entry; };

extern "C" {

void TWindowSubSymbolChatFaceType__sub_80283C84(Ctx_80283C84 *, f32 *, f32, f32);
extern s32 actor_frame_tick;

typedef struct Stack_80283F38 Stack_80283F38;

void TWindowSubSymbolChatFaceType::handle_input() {
    ControllerInputContext *input;
    input = &controller_input_state.controllers[0];
    if ((test_buttons_press_or_repeat(input, 0xF0, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0U, 0, 0);
        if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->m_62 = (this->m_62 - 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            this->m_62 = (this->m_62 + 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        if ((s8) this->m_61 < 0) {
            this->m_61 = 0U;
        }
        if ((s8) this->m_61 >= 2) {
            this->m_61 = 1U;
        }
        if ((s8) this->m_62 < 0) {
            this->m_62 = 0U;
        }
        if ((s8) this->m_62 >= 2) {
            this->m_62 = 1U;
        }
    }
}

void TWindowSubSymbolChatFaceType__sub_80283C84(Ctx_80283C84 *ctx, f32 *pos, f32 size, f32 amp) {
    Quad_80283C84 q;
    u32 alpha;
    f32 x;
    f32 y;
    f32 top;
    f32 left;
    f32 depth;

    if (ctx->fade < 0) {
        return;
    }
    if (ctx->fade < 6) {
        alpha = (u32)(0.16666667f * (f32)(ctx->fade * 255));
        alpha <<= 24;
    } else {
        alpha = 0xFF000000;
    }
    amp = (f32)(actor_frame_tick & 0xF) * amp;
    size -= 12.0f;
    depth = -1.0f / (0.26909998f + ctx->depth);
    x = ctx->x + pos[0];
    y = ctx->y + pos[1];
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(2, alpha | 0xFF0000 | 0xFFFF);
    left = x + amp;
    top = y + amp;
    q.x = left;
    q.y = top;
    q.x2 = 12.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = 0.87109375f;
    q.v = 0.0f;
    q.u2 = 0.91796875f;
    q.v2 = 0.046875f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    x = size + (x - amp);
    q.x = x;
    q.y = top;
    q.x2 = 12.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = 0.91796875f;
    q.u2 = 0.96484375f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    size = size + (y - amp);
    q.x = x;
    q.y = size;
    q.x2 = 12.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.v = 0.046875f;
    q.v2 = 0.09375f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    q.x = left;
    q.y = size;
    q.x2 = 12.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = 0.87109375f;
    q.u2 = 0.91796875f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    TWindowSubStatusDisp::get_player();
}

void TWindowSubSymbolChatFaceType__sub_80283F38(u8 *window_base, u8 *ctx) {
  int new_var;
  u8 *temp_r3;
  Stack_80283F38 stack;
  new_var = fn_802839A4(window_base);
  temp_r3 = (u8 *) ((TWindowBase *)window_base)->get_array_entry(new_var);
  stack.sp8 = (*((f32 *) (((s8 *) temp_r3) + 8))) - 3.0f;
  stack.spC = (*((f32 *) (((s8 *) temp_r3) + 0xC))) - 3.0f;
  TWindowSubSymbolChatFaceType__sub_80283C84((Ctx_80283C84 *)ctx, &stack.sp8, 66.0f, 0.3f);
}

void TWindowSubSymbolChatFaceType::update_parts_entries() {
    s32 i;
    for (i = 0; i < 4; i++) {
        Ent_80283FA8 *e = (Ent_80283FA8 *)get_array_entry(i);
        e->parts_entry = TWindowSubSymbolChatPartsSet::get_parts_entry(*m_64);
    }
}

void TWindowSubSymbolChatFaceType::render() {
    saddr context = reinterpret_cast<saddr>(draw_default_entry());
    update_parts_entries();
    draw_window_frame((void *)context);
    TWindowSubSymbolChatFaceType__sub_80283F38((u8 *)this, (u8 *)context);
    m_68->forward_render(reinterpret_cast<void *>(context));
    draw_visible_window_entries(this, &entry_list, reinterpret_cast<WindowDrawContext *>(context));
}
void TWindowSubSymbolChatFaceType::run_task() {
    TWindowSubSymbolChatFaceType *window_sub_symbol_chat_face_type = this;
    ControllerInputContext *context;
    if (!(*(s32 *)&window_sub_symbol_chat_face_type->window_flags & 2)) {
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
        m_68->update_subwindow();
    }
    ((TWindowDD *)window_sub_symbol_chat_face_type)->initialize_subwindow();
    window_sub_symbol_chat_face_type->update_window_entry_list(&window_sub_symbol_chat_face_type->entry_list);
}

}

extern "C" {



TWindowSubSymbolChatFaceType::~TWindowSubSymbolChatFaceType() {
    TWindowSubStatusDisp::destroy_status_display((s32)m_68, 1);
}

}


// inferred: symbol_chat_face_type_layout_entries, the layout table
// symbol_chat_face_type_window_layout points at (a 2x2 grid of face-type sprites).
struct SymbolChatFaceTypeWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec[4];
};
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

extern "C" {
const char *TWindowSubSymbolChatFaceType__name = TWindowSubSymbolChatFaceType__class_name_string;
TWindowSubSymbolChatFaceType::TWindowSubSymbolChatFaceType(void *position, s8 *selection)
    : TWindowBase((u8 *)&symbol_chat_face_type_window_layout, 4, (u8 *)position) {
    TWindowSubStatusDisp *heading;
    m_name = TWindowSubSymbolChatFaceType__name;
    m_60 = 0;
    m_61 = 0;
    m_62 = 0;
    m_64 = selection;
    heading = static_cast<TWindowSubStatusDisp *>(::operator new(0x24));
    if (heading != NULL) {
        heading = (TWindowSubStatusDisp *)heading->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x33), client_index);
    }
    m_68 = heading;
}

}
