#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/charcreate/TChCrCharSelect_802937D4.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "pso/ui/charcreate/TObjCMIcon_80299488.h"
#include "pso/ui/charcreate/TObjCMIcon.h"
#include "pso/ui/charcreate/TChCrTagName.h"
#include "pso/ui/charcreate/TChCrTagOccHeader.h"
#include "pso/ui/charcreate/TChCrTagOccupation.h"
#include "pso/ui/charcreate/TChCrTagPlBack.h"
#include "pso/ui/charcreate/TChCrTagPlGraphic.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"
#include "pso/unk/text_802993F0.h"
#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct Range_802937E8 { s32 min; s32 max; };

const char *TChCrCharSelect__name = "TChCrCharSelect";
s32 TChCrCharSelect__selected_char_index = -1;
s32 TChCrCharSelect__selected_slot_index = -1;
s32 TChCrCharSelect__input_mode;

const Range_802937E8 char_select_class_group_range_table[3] = {{0, 3}, {4, 7}, {8, 11}};
const vec2f lbl_80464E88 = {606.0f, 52.0f};
const s32 lbl_80464E90[2] = {0, 4};
const int char_select_class_id_table[12] = {0, 1, 2, 9, 3, 11, 4, 5, 10, 6, 7, 8};
const s32 lbl_805DD9D8[1] = {4};

int get_char_select_class_id(int a0) {  return char_select_class_id_table[a0]; }

void TChCrCharSelect::wrap_slot_index_to_range() {
    s32 min = char_select_class_group_range_table[TChCrCharSelect__selected_char_index].min;
    s32 max = char_select_class_group_range_table[TChCrCharSelect__selected_char_index].max;
    if (TChCrCharSelect__selected_slot_index < min) {
        TChCrCharSelect__selected_slot_index = max;
    } else if (TChCrCharSelect__selected_slot_index > max) {
        TChCrCharSelect__selected_slot_index = min;
    }
}
void TChCrCharSelect::clamp_slot_index_to_range() {
    s32 min = char_select_class_group_range_table[TChCrCharSelect__selected_char_index].min;
    s32 max = char_select_class_group_range_table[TChCrCharSelect__selected_char_index].max;
    if (TChCrCharSelect__selected_slot_index < min || TChCrCharSelect__selected_slot_index > max) {
        TChCrCharSelect__selected_slot_index = min;
    }
}

CharacterAppearanceFields *get_class_appearance_preset(s32 arg0);
extern "C" {
s32 copy_player_visual_record(void *, void *);
}

extern saddr tl_03;

void TChCrCharSelect::tick_and_apply_selection() {
    s32 temp_r0;
    CharacterAppearanceFields *character_appearance_fields;

    temp_r0 = apply_delay - 1;
    apply_delay = temp_r0;
    if (temp_r0 <= 0) {
        character_appearance_fields = (CharacterAppearanceFields *)&TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2;
        copy_player_visual_record(character_appearance_fields, get_class_appearance_preset(get_char_select_class_id(TChCrCharSelect__selected_slot_index)));
        character_appearance_fields->section = -1;
        character_appearance_fields->name[0] = 0;
        TCharaMaking::create((void *)tl_03, character_appearance_fields);
        queue_destruction();
    }
}

extern "C" {



void TChCrCharSelect::handle_menu_input() {
    if (creation_direction_repeated(0x20) != 0) {
        TChCrCharSelect__selected_slot_index += 1;
        play_sound_effect(0x54100, 0, 0, 0);
    } else if (creation_direction_repeated(0x10) != 0) {
        TChCrCharSelect__selected_slot_index -= 1;
        play_sound_effect(0x54100, 0, 0, 0);
    }
    wrap_slot_index_to_range();
    if ((creation_buttons_pressed(2) != 0) || (creation_direction_repeated(0x40) != 0)) {
        play_sound_effect(0x53704, 0, 0, 0);
        TChCrCharSelect__input_mode = 0;
        return;
    }
    if (creation_buttons_pressed(4) != 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        apply_delay = 0xA;
        TChCrCharSelect__input_mode = 2;
    }
}


void TChCrCharSelect::handle_cursor_input() {
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
        clamp_slot_index_to_range();
        TChCrCharSelect__input_mode = 1;
    }
}

}


void TChCrCharSelect::run_task() {
    reset_proportions();
    static void (TChCrCharSelect::*tbl[3])() = {
        &TChCrCharSelect::handle_cursor_input, &TChCrCharSelect::handle_menu_input,
        &TChCrCharSelect::tick_and_apply_selection,
    };
    (this->*tbl[TChCrCharSelect__input_mode])();
    switch (TChCrCharSelect__input_mode) {
    case 0:
        TObjCMIcon__sub_802994C8(1, lbl_805DD9D8);
        return;
    case 1:
        TObjCMIcon__sub_802994C8(2, lbl_80464E90);
        return;
    case 2:
    default:
        TObjCMIcon::reset_icon_flags();
        return;
    }
}

void TChCrCharSelect::init_widgets() { TChCrTagOccupation::create_all(); TChCrTagName::create_all(); create_all_ch_cr_tag_headers(); TChCrTagPlBack::create_default(); TChCrTagPlGraphic::create_matching_tags(); TChCrTagInformation::create_default(); }

TChCrCharSelect::~TChCrCharSelect() {}


TChCrCharSelect::TChCrCharSelect(TObject *parent) : TObject(parent) {
    m_name = TChCrCharSelect__name;
    TChCrEffTag::set_eff_tag(0);
    fn_802993F0();
    if (TChCrCharSelect__selected_char_index == -1 || TChCrCharSelect__selected_slot_index == -1) {
        TChCrCharSelect__selected_char_index = 0;
        TChCrCharSelect__selected_slot_index = 0;
        TChCrCharSelect__input_mode = 0;
    } else {
        TChCrCharSelect__input_mode = 1;
    }
    fn_8029945C(&lbl_80464E88);
    init_widgets();
}
