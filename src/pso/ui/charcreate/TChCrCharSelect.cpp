#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_CardSequence.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "pso/ui/charcreate/TObjCMIcon.h"
#include "pso/ui/charcreate/TChCrTagName.h"
#include "pso/ui/charcreate/TChCrTagOccHeader.h"
#include "pso/ui/charcreate/TChCrTagOccupation.h"
#include "pso/ui/charcreate/TChCrTagPlBack.h"
#include "pso/ui/charcreate/TChCrTagPlGraphic.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"
#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"


const char *TChCrCharSelect::name = "TChCrCharSelect";
s32 TChCrCharSelect::selected_char_index = -1;
s32 TChCrCharSelect::selected_slot_index = -1;
s32 TChCrCharSelect::input_mode;

const ClassGroupRange char_select_class_group_range_table[3] = {{0, 3}, {4, 7}, {8, 11}};
const vec2f char_select_icon_position = {606.0f, 52.0f};
const s32 char_select_icon_ids_mode1[2] = {0, 4};
const int char_select_class_id_table[12] = {0, 1, 2, 9, 3, 11, 4, 5, 10, 6, 7, 8};
const s32 char_select_icon_ids_mode0[1] = {4};

int get_char_select_class_id(int index) { return char_select_class_id_table[index]; }

void TChCrCharSelect::wrap_slot_index_to_range() {
    s32 min = char_select_class_group_range_table[TChCrCharSelect::selected_char_index].min;
    s32 max = char_select_class_group_range_table[TChCrCharSelect::selected_char_index].max;
    if (TChCrCharSelect::selected_slot_index < min) {
        TChCrCharSelect::selected_slot_index = max;
    } else if (TChCrCharSelect::selected_slot_index > max) {
        TChCrCharSelect::selected_slot_index = min;
    }
}
void TChCrCharSelect::clamp_slot_index_to_range() {
    s32 min = char_select_class_group_range_table[TChCrCharSelect::selected_char_index].min;
    s32 max = char_select_class_group_range_table[TChCrCharSelect::selected_char_index].max;
    if (TChCrCharSelect::selected_slot_index < min || TChCrCharSelect::selected_slot_index > max) {
        TChCrCharSelect::selected_slot_index = min;
    }
}



void TChCrCharSelect::tick_and_apply_selection() {
    s32 delay;
    CharacterAppearanceFields *character_appearance_fields;

    delay = apply_delay - 1;
    apply_delay = delay;
    if (delay <= 0) {
        character_appearance_fields = (CharacterAppearanceFields *)&TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2;
        copy_player_visual_record(character_appearance_fields, get_class_appearance_preset(get_char_select_class_id(TChCrCharSelect::selected_slot_index)));
        character_appearance_fields->section = -1;
        character_appearance_fields->name[0] = 0;
        TCharaMaking::create(tl_03, character_appearance_fields);
        queue_destruction();
    }
}

void TChCrCharSelect::handle_menu_input() {
    if (creation_direction_repeated(0x20) != 0) {
        TChCrCharSelect::selected_slot_index += 1;
        play_sound_effect(0x54100, 0, 0, 0);
    } else if (creation_direction_repeated(0x10) != 0) {
        TChCrCharSelect::selected_slot_index -= 1;
        play_sound_effect(0x54100, 0, 0, 0);
    }
    wrap_slot_index_to_range();
    if ((creation_buttons_pressed(2) != 0) || (creation_direction_repeated(0x40) != 0)) {
        play_sound_effect(0x53704, 0, 0, 0);
        TChCrCharSelect::input_mode = 0;
        return;
    }
    if (creation_buttons_pressed(4) != 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        apply_delay = 0xA;
        TChCrCharSelect::input_mode = 2;
    }
}

void TChCrCharSelect::handle_cursor_input() {
    s32 next;
    s32 previous;

    if (creation_direction_repeated(0x20) != 0) {
        next = TChCrCharSelect::selected_char_index + 1;
        TChCrCharSelect::selected_char_index = next;
        if (next >= 3) {
            TChCrCharSelect::selected_char_index = 0;
        }
        play_sound_effect(0x54100, 0, 0, 0);
    } else if (creation_direction_repeated(0x10) != 0) {
        previous = TChCrCharSelect::selected_char_index - 1;
        TChCrCharSelect::selected_char_index = previous;
        if (previous < 0) {
            TChCrCharSelect::selected_char_index = 2;
        }
        play_sound_effect(0x54100, 0, 0, 0);
    }
    if ((creation_buttons_pressed(4) != 0) || (creation_direction_repeated(0x80) != 0)) {
        play_sound_effect(0x52D01, 0, 0, 0);
        clamp_slot_index_to_range();
        TChCrCharSelect::input_mode = 1;
    }
}

void TChCrCharSelect::run_task() {
    reset_proportions();
    static void (TChCrCharSelect::*tbl[3])() = {
        &TChCrCharSelect::handle_cursor_input, &TChCrCharSelect::handle_menu_input,
        &TChCrCharSelect::tick_and_apply_selection,
    };
    (this->*tbl[TChCrCharSelect::input_mode])();
    switch (TChCrCharSelect::input_mode) {
    case 0:
        TObjCMIcon::show_only_creation_icons(1, char_select_icon_ids_mode0);
        return;
    case 1:
        TObjCMIcon::show_only_creation_icons(2, char_select_icon_ids_mode1);
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
    m_name = TChCrCharSelect::name;
    TChCrEffTag::set_eff_tag(0);
    reset_creation_input_state();
    if (TChCrCharSelect::selected_char_index == -1 || TChCrCharSelect::selected_slot_index == -1) {
        TChCrCharSelect::selected_char_index = 0;
        TChCrCharSelect::selected_slot_index = 0;
        TChCrCharSelect::input_mode = 0;
    } else {
        TChCrCharSelect::input_mode = 1;
    }
    TObjCMIcon::set_screen_position(&char_select_icon_position);
    init_widgets();
}

TChCrCharSelect *TChCrCharSelect::create(TObject *parent) {
    return new TChCrCharSelect(parent);
}

void TChCrCharSelect::init_and_create(TObject *parent) {
    TChCrCharSelect::selected_char_index = -1;
    TChCrCharSelect::selected_slot_index = -1;
    create(parent);
}
