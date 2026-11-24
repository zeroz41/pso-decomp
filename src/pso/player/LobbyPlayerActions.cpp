// LobbyPlayerActionProvider's lobby gender queries, action numbers and loaded
// motion set flags.
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/LobbyPlayerActionProvider.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

int LobbyPlayerActionProvider::is_male(s32 body_type) { return get_gender(body_type) == 0; }
int LobbyPlayerActionProvider::is_male() { return get_gender() == 0; }

int LobbyPlayerActionProvider::is_female(s32 body_type) { return get_gender(body_type) == 1; }
int LobbyPlayerActionProvider::is_female() { return get_gender() == 1; }

int LobbyPlayerActionProvider::get_motion_buffer() { return lobby_action_motion_buffer; }

int LobbyPlayerActionProvider::get_knockdown_action() { return 0x6; }
int LobbyPlayerActionProvider::get_hurt_action() { return 0x7; }
int LobbyPlayerActionProvider::get_interact_action() { return 0x8; }
int LobbyPlayerActionProvider::get_use_item_action() { return 0x9; }
int LobbyPlayerActionProvider::vfunc_31() { return 0xA; }
int LobbyPlayerActionProvider::vfunc_32() { return 0xB; }
int LobbyPlayerActionProvider::vfunc_33() { return 0xC; }
int LobbyPlayerActionProvider::vfunc_34() { return 0xD; }
int LobbyPlayerActionProvider::vfunc_35() { return 0xE; }
int LobbyPlayerActionProvider::vfunc_36() { return 0xF; }
int LobbyPlayerActionProvider::vfunc_37() { return 0x10; }
int LobbyPlayerActionProvider::vfunc_38() { return 0x11; }
int LobbyPlayerActionProvider::vfunc_20() { return 0x13; }
int LobbyPlayerActionProvider::vfunc_39() { return 0x14; }
int LobbyPlayerActionProvider::vfunc_40() { return 0x15; }
int LobbyPlayerActionProvider::vfunc_41() { return 0x16; }
int LobbyPlayerActionProvider::vfunc_42() { return 0x17; }
int LobbyPlayerActionProvider::vfunc_43() { return 0x18; }
int LobbyPlayerActionProvider::get_death_action() { return 0x12; }
int LobbyPlayerActionProvider::vfunc_44() { return 0x19; }
int LobbyPlayerActionProvider::vfunc_45() { return 0x1A; }
int LobbyPlayerActionProvider::vfunc_46() { return 0x1B; }
int LobbyPlayerActionProvider::vfunc_47() { return 0x1C; }
int LobbyPlayerActionProvider::vfunc_48() { return 0x1D; }
int LobbyPlayerActionProvider::vfunc_49() { return 0x1E; }
int LobbyPlayerActionProvider::vfunc_50() { return 0x1F; }
int LobbyPlayerActionProvider::vfunc_51() { return 0x20; }
int LobbyPlayerActionProvider::vfunc_52() { return 0x21; }
int LobbyPlayerActionProvider::vfunc_53() { return 0x22; }
int LobbyPlayerActionProvider::vfunc_54() { return 0x23; }
int LobbyPlayerActionProvider::vfunc_55() { return 0x24; }
int LobbyPlayerActionProvider::vfunc_56() { return 0x25; }
int LobbyPlayerActionProvider::vfunc_57() { return 0x26; }
int LobbyPlayerActionProvider::vfunc_58() { return 0x27; }
int LobbyPlayerActionProvider::vfunc_59() { return 0x28; }
int LobbyPlayerActionProvider::vfunc_60() { return 0x29; }
int LobbyPlayerActionProvider::vfunc_61() { return 0x2A; }
int LobbyPlayerActionProvider::vfunc_62() { return 0x2B; }
int LobbyPlayerActionProvider::vfunc_63() { return 0x2C; }
int LobbyPlayerActionProvider::vfunc_64() { return 0x2D; }
int LobbyPlayerActionProvider::vfunc_65() { return 0x2E; }
int LobbyPlayerActionProvider::vfunc_66() { return 0x2F; }
int LobbyPlayerActionProvider::vfunc_67() { return 0x30; }
int LobbyPlayerActionProvider::vfunc_68() { return 0x31; }
int LobbyPlayerActionProvider::vfunc_69() { return 0x32; }
int LobbyPlayerActionProvider::vfunc_70() { return 0x33; }
int LobbyPlayerActionProvider::vfunc_71() { return 0x34; }
int LobbyPlayerActionProvider::vfunc_72() { return 0x35; }
int LobbyPlayerActionProvider::get_motion_count() { return 0x38; }

void LobbyPlayerActionProvider::set_female_motions_loaded() {
    lobby_loaded_motion_sets.set(2);
}

s32 LobbyPlayerActionProvider::female_motions_loaded() {
    return test_flags_any(&lobby_loaded_motion_sets.bits, 2);
}

void LobbyPlayerActionProvider::set_male_motions_loaded() {
    lobby_loaded_motion_sets.set(1);
}

s32 LobbyPlayerActionProvider::male_motions_loaded() {
    return test_flags_any(&lobby_loaded_motion_sets.bits, 1);
}

void LobbyPlayerActionProvider::clear_loaded_motions() {
    lobby_loaded_motion_sets.reset();
}
