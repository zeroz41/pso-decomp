#include "pso/player/PlayerState.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyCharDataNewCharacter.h"
#include "pso/item/InventoryEntryCopy.h"
#include "types.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

s32 TObjPlayer::begin_action_state(TPlyCharData *character) {
    u8 class_index;

    if (character == NULL) {
        return 0;
    }
    class_index = character->m_disp_part2.char_class;
    character->m_inventory.m_num_items = 5;
    copy_entries(5, get_class_starting_inventory(class_index), character->m_inventory.get_items());
    character->set_mag_level(1);
    init_new_character_stats(character);
    setup_effect_slots(character->m_disp_part2.v1_flags, &character->m_config.m_smth);
    init_technique_levels(character->m_disp_part2.v1_flags, character->get_technique_levels());
    character->m_inventory.m_language = current_language;
    return 1;
}

void TObjPlayer::begin_action_from_char_select() { begin_action_state(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)); }

void TObjPlayer::copy_battle_mode(TPlyCharData *record) {
    record->set_battle_mode(get_battle_mode());
}

void TObjPlayer::copy_byte_339_to_record(TPlyCharData *record) {
    record->set_field_18f(get_byte_339());
}

void TObjPlayer::copy_mag_level_to_record(TPlyCharData *record) {
    record->set_mag_level(get_mag_level());
}

void TObjPlayer::apply_pending_action(TPlyCharData *record) {
    s32 action = pending_actions.get_bits();
    if (action != 0) {
        record->set_pending_action(action);
        record->stamp_save_time();
    }
}
