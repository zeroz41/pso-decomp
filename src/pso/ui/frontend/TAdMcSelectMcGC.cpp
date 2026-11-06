#include "types.h"
#include "pso/ui/frontend/TAdMcSelectMcGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC_8032A610.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer_8023E480.h"

GinjaTextureEntry lbl_804ED9C0 = { "f256_memorycard", 0, NULL };
__declspec(section ".data") GinjaTextureList mc_select_memorycard_texture_list = { &lbl_804ED9C0, 1 };
const char *TAdMcSelectMcGC__class_name = "TAdMcSelectMcGC";
GinjaTextureList *TAdMcSelectMcGC__texture_list_ptr;

void TAdMcSelectMcGC::draw_status_window() {
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)TAdMcSelectMcGC__texture_list_ptr);
    set_draw_texture_and_color(0, (pad_120 << 0x18) | 0xFF0000 | 0xFFFF);
    draw_textured_quad_at_depth(&quads[0].x0, 0.8f);
    TWindowSubStatusDisp::get_player();
}

void TAdMcSelectMcGC::render() {
    if (pad_1c == 1) {
        if (TMainTask::get_render_pass() == 1) {
            return;
        }
        goto block_5;
    }
    if (defer_render() == 0) {
        set_depth_buffer_settings_2();
block_5:
        set_additive_blend();
        draw_status_window();
        set_default_alpha_blend();
        if (pad_1c == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

#pragma push
#pragma fp_contract on
void TAdMcSelectMcGC::run_task() {
    s32 i;
    void *slot_cursor;
    TAdMcSelectCursorGC *cursor;
    for (i = 0; i < 8; i++) {
        quads[i].x0 = 286.0f * (f32)pad_12c + 51.0f;
        quads[i].y0 = 116.0f;
        quads[i].x1 = 256.0f + quads[i].x0;
        quads[i].y1 = 256.0f + quads[i].y0;
    }
    cursor = TAdMcSelectGC::get_mc_count();
    if (cursor != NULL && pad_12c == cursor->sub_8032AAC4()) {
        pad_120 >>= 1;
    }
    slot_cursor = (void *)TAdMcSelectCursorGC::get_cursor_type(pad_12c);
    if (slot_cursor != NULL && TAdMcSelectCursorGC__sub_8032A6D8(slot_cursor) == 0) {
        pad_124 = 0;
    }
    switch (pad_124) {
    case 0:
        if (slot_cursor != NULL && TAdMcSelectCursorGC__sub_8032A6D8(slot_cursor) > 0) {
            pad_124 = 1;
        }
        pad_120 = 0;
        break;
    case 1:
        if (slot_cursor != NULL && TAdMcSelectCursorGC__sub_8032A6D8(slot_cursor) > 3) {
            pad_124 = 2;
        }
        pad_120 = 0;
        break;
    case 2:
        if (slot_cursor != NULL && TAdMcSelectCursorGC__sub_8032A6D8(slot_cursor) > 4) {
            pad_124 = 3;
        }
        pad_120 = 0;
        break;
    case 3:
        pad_120 = 0xFF;
        break;
    }
}
#pragma pop

TAdMcSelectMcGC::~TAdMcSelectMcGC() {}

TAdMcSelectMcGC::TAdMcSelectMcGC(TObject *parent, s32 slot) : TObject(parent) {
    s32 i;
    m_name = TAdMcSelectMcGC__class_name;
    pad_130 = 0;
    pad_124 = 0;
    pad_128 = 0;
    pad_12c = slot;
    pad_120 = 0xFF;
    pad_1c = 1;
    for (i = 0; i < 8; i++) {
        quads[i].u0 = 0.0f;
        quads[i].v0 = 0.0f;
        quads[i].u1 = 1.0f;
        quads[i].v1 = 1.0f;
    }
}

void TAdMcSelectMcGC::release_selected_entry() {
    if (TAdMcSelectMcGC__texture_list_ptr != NULL && TAdMcSelectMcGC__texture_list_ptr->entries->texture != NULL) {
        release_texture_list(TAdMcSelectMcGC__texture_list_ptr);
    }
}

void TAdMcSelectMcGC::init_memorycard() {
    TAdMcSelectMcGC__texture_list_ptr = &mc_select_memorycard_texture_list;
    TLobby__sub_8023E4B4((s32)"f256_memorycard", (s32)&mc_select_memorycard_texture_list);
}

s32 TAdMcSelectCursorGC::sub_8032AAC4() { return m_20; }
