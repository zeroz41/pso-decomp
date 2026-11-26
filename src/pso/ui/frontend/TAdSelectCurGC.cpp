#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803DA798.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/frontend/TAdSelectCurGC_802AED98.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/network/TLobby.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/render/GinjaTexture.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TAdSelectCurGC::draw_quads() {
    u32 i;
    for (i = 0; i < entry_count; i++) {
        begin_screen_draw(1);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(menu_selection_cursor_texture_list));
        set_draw_texture_and_color(0, (static_cast<u32>(entry_alpha[i]) << 24) | 0xFFFFFF);
        draw_textured_quad_at_depth(&quads[i].x0, draw_depth);
        draw_textured_quad_at_depth(&quads[i + 16].x0, draw_depth);
        draw_textured_quad_at_depth(&quads[i + 32].x0, draw_depth);
        end_screen_draw();
    }
}

void TAdSelectCurGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); draw_quads(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

void TAdSelectCurGC::update_texture_rectangles(s32 frame) {
    s32 i;
    for (i = 0; i < static_cast<s32>(entry_count); i++) {
        switch (confirmation_result()) {
        case 0:
            quads[i].u0 = 0.0625f;
            quads[i].v0 = 0.875f;
            quads[i].u1 = 0.125f;
            quads[i].v1 = 0.9453125f;
            (quads + 16)[i].u0 = 0.0f;
            (quads + 16)[i].v0 = 0.875f;
            (quads + 16)[i].u1 = 0.0625f;
            (quads + 16)[i].v1 = 0.9453125f;
            (quads + 32)[i].u0 = 0.125f;
            (quads + 32)[i].v0 = 0.875f;
            (quads + 32)[i].u1 = 0.1875f;
            (quads + 32)[i].v1 = 0.9453125f;
            break;
        case 1:
            quads[i].u0 = 0.25390625f;
            quads[i].v0 = 0.875f;
            quads[i].u1 = 0.31640625f;
            quads[i].v1 = 0.9453125f;
            (quads + 16)[i].u0 = 0.19140625f;
            (quads + 16)[i].v0 = 0.875f;
            (quads + 16)[i].u1 = 0.25390625f;
            (quads + 16)[i].v1 = 0.9453125f;
            (quads + 32)[i].u0 = 0.31640625f;
            (quads + 32)[i].v0 = 0.875f;
            (quads + 32)[i].u1 = 0.37890625f;
            (quads + 32)[i].v1 = 0.9453125f;
            break;
        }
    }
}

void TAdSelectCurGC::reset_entries() {
    s32 i;
    selected_index = 0;
    entry_count = 0;
    confirmation = 0;
    frame = -1;
    pending_command = 0;
    for (i = 0; i < 16; i++) {
        entry_alpha[i] = 0;
    }
}

static const f32 cursor_end_cap_width = 16.0f;
static const f32 cursor_end_caps_width = 32.0f;

void TAdSelectCurGC::append_entry(const void *position) {
    if (entry_count < 16) {
        copy_vec2(&entry_positions[entry_count], const_cast<void *>(position));
        quads[entry_count].x0 = cursor_end_cap_width + entry_positions[entry_count].x;
        quads[entry_count].y0 = entry_positions[entry_count].y;
        quads[entry_count].x1 = quads[entry_count].x0 + (cursor_size.x - cursor_end_caps_width);
        quads[entry_count].y1 = quads[entry_count].y0 + cursor_size.y;
        (quads + 16)[entry_count].x0 = entry_positions[entry_count].x;
        (quads + 16)[entry_count].y0 = entry_positions[entry_count].y;
        (quads + 16)[entry_count].x1 = cursor_end_cap_width + (quads + 16)[entry_count].x0;
        (quads + 16)[entry_count].y1 = (quads + 16)[entry_count].y0 + cursor_size.y;
        (quads + 32)[entry_count].x0 = entry_positions[entry_count].x + (cursor_size.x - cursor_end_cap_width);
        (quads + 32)[entry_count].y0 = entry_positions[entry_count].y;
        (quads + 32)[entry_count].x1 = cursor_end_cap_width + (quads + 32)[entry_count].x0;
        (quads + 32)[entry_count].y1 = (quads + 32)[entry_count].y0 + cursor_size.y;
        entry_count++;
    }
}



/* The two one-texture lists load_select_cursor_texture picks from by language
   (f256_ad for Japanese, f256_ad_eng otherwise) and keeps in menu_selection_cursor_texture_list */
NJS_TEXNAME select_cursor_eng_texture_entry = {"f256_ad_eng", 0, NULL};
NJS_TEXLIST select_cursor_eng_texture_list = {&select_cursor_eng_texture_entry, 1};
NJS_TEXNAME select_cursor_texture_entry = {"f256_ad", 0, NULL};
NJS_TEXLIST select_cursor_texture_list = {&select_cursor_texture_entry, 1};
/* inferred: TObject name the constructor stores */
const char *TAdSelectCurGC::name = "TAdSelectCurGC";
NJS_TEXLIST *menu_selection_cursor_texture_list;

extern "C" {
extern const s32 current_language;
void copy_vec2__FPvPv(NJS_POINT2 *target, const NJS_POINT2 *source);
}

void TAdSelectCurGC::run_task() {
    s32 ok;
    u32 i;
    update_texture_rectangles(frame++);
    if (navigation_locked == 0 && confirmation == 0 && (s32)entry_count != 0) {
        if (wait_directions_released != 0) {
            u8 t = 0;
            if (test_previous_buttons_remapped(&controller_input_state.controllers[0], 0x10) == 0 &&
                test_previous_buttons_remapped(&controller_input_state.controllers[0], 0x20) == 0) {
                t = 1;
            }
            ok = t;
        } else {
            ok = 1;
        }
        if (ok != 0) {
            if (TAdMultiPlyChrSelectGC::dispatch_draw_command(&controller_input_state.controllers[0], 0x10, 6, 1) != 0 ||
                test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0) {
                play_sound_effect(0x54100, 0, 0, 0);
                selected_index--;
            }
            if (TAdMultiPlyChrSelectGC::dispatch_draw_command(&controller_input_state.controllers[0], 0x20, 6, 1) != 0 ||
                test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0) {
                play_sound_effect(0x54100, 0, 0, 0);
                selected_index++;
            }
        }
        if (selected_index > (s32)(entry_count - 1)) {
            selected_index = 0;
        }
        if (selected_index < 0) {
            selected_index = entry_count - 1;
        }
        if (confirmation_disabled == 0 &&
            (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 4) != 0 ||
             test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            play_sound_effect(0x52D01, 0, 0, 0);
            confirmation = 1;
        }
    }
    for (i = 0; i < entry_count; i++) {
        entry_alpha[i] -= 25;
        if (entry_alpha[i] < 0) {
            entry_alpha[i] = 0;
        }
    }
    entry_alpha[selected_index] = 0xFF;
    switch (pending_command) {
    case 0:
        break;
    case 1:
        confirmation = 0;
        pending_command = 0;
        break;
    case 2:
        confirmation = 1;
        pending_command = 0;
        break;
    case 3:
        navigation_locked = 0;
        pending_command = 0;
        break;
    case 4:
        navigation_locked = 1;
        pending_command = 0;
        break;
    }
}

TAdSelectCurGC::~TAdSelectCurGC() {}
TAdSelectCurGC::TAdSelectCurGC(TObject *parent, const NJS_POINT2 *position, const NJS_POINT2 *size)
    : TObject(parent) {
    s32 i;
    m_name = TAdSelectCurGC::name;
    copy_vec2__FPvPv(&entry_positions[0], position);
    copy_vec2__FPvPv(&cursor_size, size);
    selected_index = 0;
    entry_count = 0;
    confirmation = 0;
    frame = -1;
    navigation_locked = 0;
    wait_directions_released = 0;
    confirmation_disabled = 0;
    pending_command = 0;
    set_draw_depth(0.5555556f);
    for (i = 0; i < 16; i++) {
        entry_alpha[i] = 0;
    }
}

void free_select_cursor_texture() {
    if (menu_selection_cursor_texture_list != NULL) {
        release_texture_list(menu_selection_cursor_texture_list);
        menu_selection_cursor_texture_list = NULL;
    }
}

void load_select_cursor_texture() {
    TLobby::update_menu_cursor();
    const char *names[5] = {"f256_ad", "f256_ad_eng", "f256_ad_eng", "f256_ad_eng", "f256_ad_eng"};
    NJS_TEXLIST *lists[5] = {
        &select_cursor_texture_list, &select_cursor_eng_texture_list, &select_cursor_eng_texture_list,
        &select_cursor_eng_texture_list, &select_cursor_eng_texture_list,
    };
    NJS_TEXLIST *list = lists[current_language];
    menu_selection_cursor_texture_list = list;
    load_streamed_prs_texture(names[current_language], list);
}

void TAdSelectCurGC::set_draw_depth(f32 depth) { draw_depth = depth; }
