#include "types.h"
#include "pso/player/TObjPlayer_801BE778.h"
#include "pso/player/TObjPlayer_801BFED4.h"
#include "pso/player/TObjPlayer_802C3B14.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 get_class_starting_inventory(u8);
s32 init_technique_levels(s32, saddr);
s32 init_new_character_stats(void *);
s32 copy_entries(s32, saddr, saddr);

s32 begin_action_state__10TObjPlayerFPv(u8 *player) {
    s32 temp_r31;
    u8 temp_r30;

    if (player == NULL) {
        return 0;
    }
    temp_r30 = *(u8 *)((s8 *)player + 0x3A1);
    *(s8 *)((s8 *)player + 0) = 5;
    copy_entries(5, get_class_starting_inventory(temp_r30), (saddr)((TObjPlayer *)player)->get_ptr_4());
    ((TObjPlayer *)player)->set_action_state(1);
    init_new_character_stats(player);
    TObjPlayer::setup_effect_slots((s32)(*(s32 *)((s8 *)player + 0x3A4)), (saddr)(player + 0x3C0));
    init_technique_levels(*(s32 *)((s8 *)player + 0x3A4), (saddr)((TObjPlayer *)player)->get_action_data());
    *(s8 *)((s8 *)player + 3) = (s8) current_language;
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
