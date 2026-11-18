#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType_80283A70.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80283954.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"
extern "C" { extern const char TWindowSubSymbolChatFaceType__class_name_string[29] = "TWindowSubSymbolChatFaceType"; }

extern "C" {

s32 play_sound_effect(int, int, int, int);
s32 is_open__28TWindowSubSymbolChatFaceTypeFv();

void TWindowSubSymbolChatFaceType::close_when_chat_closed() {
    if (is_open__28TWindowSubSymbolChatFaceTypeFv() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 2);
    }
}

void TWindowSubSymbolChatFaceType::confirm_selection() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
    ((TWindowSubStatusDisp *)(this->m_68))->set_entry_state(2);
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

struct Win_80283FA8 { u8 pad[0x64]; s8 *f64; };

struct Ent_80283FA8 { u8 pad[0x2c]; s32 f2c; };

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
s32 forward_render__20TWindowSubStatusDispFv(int, int);
void TWindowSubSymbolChatFaceType__sub_80283C84(Ctx_80283C84 *, f32 *, f32, f32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
void begin_screen_draw(s32);
void set_draw_texture_and_color(s32, s32);
void apply_context_transform_to_rect(Ctx_80283C84 *, Quad_80283C84 *);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
extern s32 actor_frame_tick;
extern s32 lbl_805D63F0;

typedef struct Stack_80283F38 Stack_80283F38;

void TWindowSubSymbolChatFaceType::handle_input() {
    u8 *input;
    input = (u8 *)&controller_input_state + 0x20;
    if ((TWindowChoiceSetting::apply_choice((s32)input, 0xF0, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0U, 0, 0);
        if ((TWindowChoiceSetting::apply_choice((s32)input, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
            this->m_62 = (this->m_62 - 1);
        }
        if ((TWindowChoiceSetting::apply_choice((s32)input, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
            this->m_62 = (this->m_62 + 1);
        }
        if ((TWindowChoiceSetting::apply_choice((s32)input, 0x80, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0x80, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        if ((TWindowChoiceSetting::apply_choice((s32)input, 0x40, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0x40, 6, 1) != 0)) {
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
    TObjFish::set_global_param(lbl_805D63F0);
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
    apply_context_transform_to_rect(ctx, &q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    x = size + (x - amp);
    q.x = x;
    q.y = top;
    q.x2 = 12.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = 0.91796875f;
    q.u2 = 0.96484375f;
    apply_context_transform_to_rect(ctx, &q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    size = size + (y - amp);
    q.x = x;
    q.y = size;
    q.x2 = 12.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.v = 0.046875f;
    q.v2 = 0.09375f;
    apply_context_transform_to_rect(ctx, &q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    q.x = left;
    q.y = size;
    q.x2 = 12.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = 0.87109375f;
    q.u2 = 0.91796875f;
    apply_context_transform_to_rect(ctx, &q);
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
        e->f2c = TWindowSubSymbolChatPartsSet::get_parts_entry(*((Win_80283FA8 *)this)->f64);
    }
}

void render__28TWindowSubSymbolChatFaceTypeFv(u8 *arg0) {
    s32 temp_r31;
    temp_r31 = draw_default_entry__9TWindowDDFl();
    ((TWindowSubSymbolChatFaceType *)arg0)->update_parts_entries();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r31);
    TWindowSubSymbolChatFaceType__sub_80283F38((u8 *)arg0, (u8 *)temp_r31);
    forward_render__20TWindowSubStatusDispFv((int) (((TWindowSubSymbolChatFaceType *)arg0)->m_68), temp_r31);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r31);
}
void run_task__28TWindowSubSymbolChatFaceTypeFv(TWindowSubSymbolChatFaceType *window_sub_symbol_chat_face_type) {
    u8 *context;
    if (!(*(s32 *)&window_sub_symbol_chat_face_type->m_2c & 2)) {
        *(s32 *)&window_sub_symbol_chat_face_type->m_5c = 0x01000000;
    }
    if (window_sub_symbol_chat_face_type->is_open() == 0) {
        window_sub_symbol_chat_face_type->handle_input();
        context = (u8 *)&controller_input_state + 0x20;
        if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state + 0x160), 4) != 0)) {
            window_sub_symbol_chat_face_type->confirm_selection();
        }
        if ((TWindowShortListCtrl__check_controller_button(context, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state + 0x160), 2) != 0)) {
            window_sub_symbol_chat_face_type->close_when_chat_closed();
        }
    }
    if ((f32) *(s32 *)&window_sub_symbol_chat_face_type->m_5c >= 7.5f) {
        ((TWindowSubStatusDisp *)(*(s32 *)&window_sub_symbol_chat_face_type->m_68))->update_subwindow();
    }
    ((TWindowDD *)window_sub_symbol_chat_face_type)->initialize_subwindow();
    ((TWindowBase *)window_sub_symbol_chat_face_type)->update_window_entry_list((u8 *)window_sub_symbol_chat_face_type + 0x24);
}

}

extern "C" {

extern s32 __vt__28TWindowSubSymbolChatFaceType[];

TWindowSubSymbolChatFaceType::~TWindowSubSymbolChatFaceType() {
    TWindowSubStatusDisp::destroy_status_display((s32)(*(void **)((s8 *)this + 0x68)), (s16)1);
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
        {6, {16.0f, 16.0f}, {60.0f, 60.0f}, 2.0f, 194.0f, 0.5f, -1, &lbl_805D63F0, 0xA, 4},
        {6, {96.0f, 16.0f}, {60.0f, 60.0f}, 2.0f, 130.0f, 0.5f, -1, &lbl_805D63F0, 0xA, 4},
        {6, {16.0f, 96.0f}, {60.0f, 60.0f}, 66.0f, 130.0f, 0.5f, -1, &lbl_805D63F0, 0xA, 4},
        {6, {96.0f, 96.0f}, {60.0f, 60.0f}, 66.0f, 194.0f, 0.5f, -1, &lbl_805D63F0, 0xA, 4},
    },
};
WindowDescriptor symbol_chat_face_type_window_layout = {
    {178.0f, 188.0f}, 50050.0f, &symbol_chat_face_type_layout_entries, 0x43,
};

extern "C" {
s32 construct_type1_heading__20TWindowSubStatusDispFll(s32, s32, s32);
s32 get_message_10__20TWindowSubStatusDispFl(int);
const char *TWindowSubSymbolChatFaceType__name = TWindowSubSymbolChatFaceType__class_name_string;
u8 *TWindowSubSymbolChatFaceType__ct(TWindowSubSymbolChatFaceType *window_sub_symbol_chat_face_type, s32 arg1, s32 arg2) {
    s32 var_r31;
    __ct__11TWindowBaseFPUcsPUc(window_sub_symbol_chat_face_type, (u8 *)&symbol_chat_face_type_window_layout, (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)window_sub_symbol_chat_face_type + 0x18) = __vt__28TWindowSubSymbolChatFaceType;
    *(s32 *)((s8 *)window_sub_symbol_chat_face_type + 0) = (s32) TWindowSubSymbolChatFaceType__name;
    window_sub_symbol_chat_face_type->m_60 = 0;
    window_sub_symbol_chat_face_type->m_61 = 0;
    window_sub_symbol_chat_face_type->m_62 = 0;
    window_sub_symbol_chat_face_type->m_64 = arg2;
    var_r31 = (int)::operator new(0x24);
    if (var_r31 != 0) {
        var_r31 = construct_type1_heading__20TWindowSubStatusDispFll(var_r31, get_message_10__20TWindowSubStatusDispFl(0x33), (s32) window_sub_symbol_chat_face_type->m_20);
    }
    window_sub_symbol_chat_face_type->m_68 = var_r31;
    return (u8 *)window_sub_symbol_chat_face_type;
}

}
