#include "pso/ui/charcreate/CreationInput.h"
#include "types.h"
#include "pso/ui/charcreate/TChCrCharSelect_802938E4.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

extern "C" {

s32 wrap_slot_index_to_range__15TChCrCharSelectFv(void *);
s32 clamp_slot_index_to_range__15TChCrCharSelectFv(s32);
s32 play_sound_effect(s32, s32, s32, s32);

extern s32 TChCrCharSelect__selected_slot_index;
extern s32 TChCrCharSelect__input_mode;

void TChCrCharSelect::handle_menu_input() {
    if (creation_direction_repeated(0x20) != 0) {
        TChCrCharSelect__selected_slot_index += 1;
        play_sound_effect(0x54100, 0, 0, 0);
    } else if (creation_direction_repeated(0x10) != 0) {
        TChCrCharSelect__selected_slot_index -= 1;
        play_sound_effect(0x54100, 0, 0, 0);
    }
    wrap_slot_index_to_range__15TChCrCharSelectFv(this);
    if ((creation_buttons_pressed(2) != 0) || (creation_direction_repeated(0x40) != 0)) {
        play_sound_effect(0x53704, 0, 0, 0);
        TChCrCharSelect__input_mode = 0;
        return;
    }
    if (creation_buttons_pressed(4) != 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        *(s32 *)((s8 *)this + 0x1C) = 0xA;
        TChCrCharSelect__input_mode = 2;
    }
}

extern s32 TChCrCharSelect__selected_char_index;

void handle_cursor_input__15TChCrCharSelectFv(s32 arg0) {
    s32 temp_r0;
    s32 temp_r0_2;

    if (creation_direction_repeated(0x20) != 0) {
        temp_r0 = TChCrCharSelect__selected_char_index + 1;
        TChCrCharSelect__selected_char_index = temp_r0;
        if (temp_r0 >= 3) {
            TChCrCharSelect__selected_char_index = 0;
        }
        play_sound_effect(0x54100, 0, 0, 0);
    } else if (creation_direction_repeated(0x10) != 0) {
        temp_r0_2 = TChCrCharSelect__selected_char_index - 1;
        TChCrCharSelect__selected_char_index = temp_r0_2;
        if (temp_r0_2 < 0) {
            TChCrCharSelect__selected_char_index = 2;
        }
        play_sound_effect(0x54100, 0, 0, 0);
    }
    if ((creation_buttons_pressed(4) != 0) || (creation_direction_repeated(0x80) != 0)) {
        play_sound_effect(0x52D01, 0, 0, 0);
        clamp_slot_index_to_range__15TChCrCharSelectFv(arg0);
        TChCrCharSelect__input_mode = 1;
    }
}

}
