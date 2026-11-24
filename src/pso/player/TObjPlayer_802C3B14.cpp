#include "pso/player/PlayerState.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TObjPlayer_802C367C.h"
#include "pso/item/InventoryEntryCopy.h"
#include "types.h"
#include "pso/player/TObjPlayer_801BE778.h"
#include "pso/player/TObjPlayer_802C3B14.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {


s32 begin_action_state__10TObjPlayerFPv(u8 *player) {
    u8 class_index;

    if (player == NULL) {
        return 0;
    }
    TPlyCharData *character = (TPlyCharData *)player;
    class_index = character->m_disp_part2.char_class;
    character->m_inventory.m_num_items = 5;
    copy_entries(5, get_class_starting_inventory(class_index), character->m_inventory.get_items());
    ((TObjPlayer *)player)->set_action_state(1);
    init_new_character_stats(character);
    TObjPlayer::setup_effect_slots((s32)(*(s32 *)((s8 *)player + 0x3A4)), (saddr)(player + 0x3C0));
    init_technique_levels(*(s32 *)((s8 *)player + 0x3A4), static_cast<s8 *>(reinterpret_cast<TObjPlayer *>(player)->get_action_data()));
    character->m_inventory.m_language = current_language;
    return 1;
}

s32 TObjPlayer__sub_802C4668(s32, s32);

void TObjPlayer::begin_action_from_char_select() { TAdSinglePlyChrSelectGC::get_char_index(0xFFFF); ((int (*)(void))begin_action_state__10TObjPlayerFPv)(); }

void TObjPlayer::copy_battle_mode(u8 *player) {
    ((TObjPlayer *)player)->set_field_1ab(get_battle_mode());
}

void TObjPlayer::copy_byte_339_to_record(u8 *player) {
    ((TObjPlayer *)player)->set_field_18f(get_byte_339());
}

void TObjPlayer::copy_mag_level_to_record(u8 *player) {
    ((TObjPlayer *)player)->set_action_state(get_mag_level());
}

void TObjPlayer::apply_pending_action(saddr arg1) {
    saddr arg0 = (saddr)this;
    s32 temp = TObjPlayer__sub_801BFFA0((void *)(arg0 + 0x41C));
    if (temp != 0) {
        TObjPlayer__sub_802C4668(arg1, temp);
        ((TObjPlayer *)arg1)->set_current_time();
    }
}

}
