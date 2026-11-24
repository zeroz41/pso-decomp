#include "pso/system/SoundEffect.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/frontend/TAdSelectCurGC_802AED98.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "types.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"

#include "pso/unk/TLobby.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/vector.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

/* inferred: the two one-texture lists apply_menu_cursor_selection picks from by language
   (f256_ad for Japanese, f256_ad_eng otherwise) and keeps in menu_selection_cursor_texture_list */
NJS_TEXNAME select_cursor_eng_texture_entry = {"f256_ad_eng", 0, NULL};
NJS_TEXLIST select_cursor_eng_texture_list = {&select_cursor_eng_texture_entry, 1};
NJS_TEXNAME select_cursor_texture_entry = {"f256_ad", 0, NULL};
NJS_TEXLIST select_cursor_texture_list = {&select_cursor_texture_entry, 1};
/* inferred: TObject name the constructor stores */
const char *TAdSelectCurGC__name = "TAdSelectCurGC";
NJS_TEXLIST *menu_selection_cursor_texture_list;

extern "C" {
extern const s32 current_language;
void copy_vec2__FPvPv(NJS_POINT2 *target, const NJS_POINT2 *source);

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
            if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)(&controller_input_state.controllers[0]), 0x10, 6, 1) != 0 ||
                test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0) {
                play_sound_effect(0x54100, 0, 0, 0);
                selected_index--;
            }
            if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)(&controller_input_state.controllers[0]), 0x20, 6, 1) != 0 ||
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
    m_name = TAdSelectCurGC__name;
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

void TLobby__sub_802AF198(void) {
    if (menu_selection_cursor_texture_list != NULL) {
        release_texture_list(menu_selection_cursor_texture_list);
        menu_selection_cursor_texture_list = NULL;
    }
}

void TLobby::apply_menu_cursor_selection() {
    TLobby::update_menu_cursor();
    const char *names[5] = {"f256_ad", "f256_ad_eng", "f256_ad_eng", "f256_ad_eng", "f256_ad_eng"};
    NJS_TEXLIST *lists[5] = {
        &select_cursor_texture_list, &select_cursor_eng_texture_list, &select_cursor_eng_texture_list,
        &select_cursor_eng_texture_list, &select_cursor_eng_texture_list,
    };
    NJS_TEXLIST *list = lists[current_language];
    menu_selection_cursor_texture_list = list;
    load_streamed_prs_texture((saddr)names[current_language], (saddr)list);
}

void TAdSelectCurGC::set_draw_depth(f32 depth) { draw_depth = depth; }


}
