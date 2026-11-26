#include "types.h"
#include "pso/ui/frontend/TAdMcSelectMcGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"
#include "pso/ui/frontend/TAdMcCheckGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer_8023E480.h"

NJS_TEXNAME mc_select_memorycard_texname = { "f256_memorycard", 0, NULL };
__declspec(section ".data") NJS_TEXLIST mc_select_memorycard_texture_list = { &mc_select_memorycard_texname, 1 };
const char *TAdMcSelectMcGC::class_name = "TAdMcSelectMcGC";
NJS_TEXLIST *TAdMcSelectMcGC::texture_list_ptr;

void TAdMcSelectMcGC::draw_status_window() {
    begin_screen_draw(1);
    set_texture_list(TAdMcSelectMcGC::texture_list_ptr);
    set_draw_texture_and_color(0, (alpha << 0x18) | 0xFF0000 | 0xFFFF);
    draw_textured_quad_at_depth(&quads[0].x0, 0.8f);
    end_screen_draw();
}

void TAdMcSelectMcGC::render() {
    if (render_direct == 1) {
        if (TMainTask::get_render_pass() == 1) {
            return;
        }
    } else {
        if (defer_render() != 0) {
            return;
        }
        set_depth_buffer_settings_2();
    }
    set_additive_blend();
    draw_status_window();
    set_default_alpha_blend();
    if (render_direct == 0) {
        restore_saved_depth_alpha_state();
    }
}

#pragma push
#pragma fp_contract on
void TAdMcSelectMcGC::run_task() {
    s32 i;
    TAdMcCheckGC *slot_cursor;
    TAdMcSelectCursorGC *cursor;
    for (i = 0; i < 8; i++) {
        quads[i].x0 = 286.0f * (f32)slot + 51.0f;
        quads[i].y0 = 116.0f;
        quads[i].x1 = 256.0f + quads[i].x0;
        quads[i].y1 = 256.0f + quads[i].y0;
    }
    cursor = TAdMcSelectGC::get_mc_count();
    if (cursor != NULL && slot == cursor->sub_8032AAC4()) {
        alpha >>= 1;
    }
    slot_cursor = TAdMcSelectCursorGC::get_cursor_type(slot);
    if (slot_cursor != NULL && slot_cursor->get_check_step() == 0) {
        fade_step = 0;
    }
    switch (fade_step) {
    case 0:
        if (slot_cursor != NULL && slot_cursor->get_check_step() > 0) {
            fade_step = 1;
        }
        alpha = 0;
        break;
    case 1:
        if (slot_cursor != NULL && slot_cursor->get_check_step() > 3) {
            fade_step = 2;
        }
        alpha = 0;
        break;
    case 2:
        if (slot_cursor != NULL && slot_cursor->get_check_step() > 4) {
            fade_step = 3;
        }
        alpha = 0;
        break;
    case 3:
        alpha = 0xFF;
        break;
    }
}
#pragma pop

TAdMcSelectMcGC::~TAdMcSelectMcGC() {}

TAdMcSelectMcGC::TAdMcSelectMcGC(TObject *parent, s32 slot) : TObject(parent) {
    s32 i;
    m_name = TAdMcSelectMcGC::class_name;
    pad_130 = 0;
    fade_step = 0;
    pad_128 = 0;
    this->slot = slot;
    alpha = 0xFF;
    render_direct = 1;
    for (i = 0; i < 8; i++) {
        quads[i].u0 = 0.0f;
        quads[i].v0 = 0.0f;
        quads[i].u1 = 1.0f;
        quads[i].v1 = 1.0f;
    }
}

void TAdMcSelectMcGC::release_selected_entry() {
    if (TAdMcSelectMcGC::texture_list_ptr != NULL && TAdMcSelectMcGC::texture_list_ptr->textures->texture != NULL) {
        release_texture_list(TAdMcSelectMcGC::texture_list_ptr);
    }
}

void TAdMcSelectMcGC::init_memorycard() {
    TAdMcSelectMcGC::texture_list_ptr = &mc_select_memorycard_texture_list;
    load_streamed_prs_texture("f256_memorycard", &mc_select_memorycard_texture_list);
}

s32 TAdMcSelectCursorGC::sub_8032AAC4() { return selected_slot; }
