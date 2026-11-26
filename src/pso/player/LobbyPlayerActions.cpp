// LobbyPlayerActionProvider's lobby gender queries, action numbers and loaded
// motion set flags.
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/LobbyPlayerActionProvider.h"

int LobbyPlayerActionProvider::is_male(s32 body_type) { return get_gender(body_type) == 0; }
int LobbyPlayerActionProvider::is_male() { return get_gender() == 0; }

int LobbyPlayerActionProvider::is_female(s32 body_type) { return get_gender(body_type) == 1; }
int LobbyPlayerActionProvider::is_female() { return get_gender() == 1; }

u8 *LobbyPlayerActionProvider::get_motion_buffer() { return lobby_action_motion_buffer; }

int LobbyPlayerActionProvider::get_knockdown_action() { return 0x6; }
int LobbyPlayerActionProvider::get_hurt_action() { return 0x7; }
int LobbyPlayerActionProvider::get_interact_action() { return 0x8; }
int LobbyPlayerActionProvider::get_use_item_action() { return 0x9; }
int LobbyPlayerActionProvider::get_key_f5_action() { return 0xA; }
int LobbyPlayerActionProvider::get_key_f6_action() { return 0xB; }
int LobbyPlayerActionProvider::get_key_f7_action() { return 0xC; }
int LobbyPlayerActionProvider::get_key_f8_action() { return 0xD; }
int LobbyPlayerActionProvider::get_key_f9_action() { return 0xE; }
int LobbyPlayerActionProvider::get_key_f10_action() { return 0xF; }
int LobbyPlayerActionProvider::get_key_f11_action() { return 0x10; }
int LobbyPlayerActionProvider::get_key_f12_action() { return 0x11; }
int LobbyPlayerActionProvider::get_lock_on_idle_action() { return 0x13; }
int LobbyPlayerActionProvider::get_key_6_action() { return 0x14; }
int LobbyPlayerActionProvider::get_key_7_action() { return 0x15; }
int LobbyPlayerActionProvider::get_key_8_action() { return 0x16; }
int LobbyPlayerActionProvider::get_key_9_action() { return 0x17; }
int LobbyPlayerActionProvider::get_key_0_action() { return 0x18; }
int LobbyPlayerActionProvider::get_death_action() { return 0x12; }
int LobbyPlayerActionProvider::get_key_h_action() { return 0x19; }
int LobbyPlayerActionProvider::get_key_b_action() { return 0x1A; }
int LobbyPlayerActionProvider::get_key_o_action() { return 0x1B; }
int LobbyPlayerActionProvider::get_key_n_action() { return 0x1C; }
int LobbyPlayerActionProvider::get_key_q_action() { return 0x1D; }
int LobbyPlayerActionProvider::get_key_j_action() { return 0x1E; }
int LobbyPlayerActionProvider::get_key_r_action() { return 0x1F; }
int LobbyPlayerActionProvider::get_key_k_action() { return 0x20; }
int LobbyPlayerActionProvider::get_key_w_action() { return 0x21; }
int LobbyPlayerActionProvider::get_key_s_action() { return 0x22; }
int LobbyPlayerActionProvider::get_key_t_action() { return 0x23; }
int LobbyPlayerActionProvider::get_key_c_action() { return 0x24; }
int LobbyPlayerActionProvider::get_key_d_action() { return 0x25; }
int LobbyPlayerActionProvider::get_key_f_action() { return 0x26; }
int LobbyPlayerActionProvider::get_key_g_action() { return 0x27; }
int LobbyPlayerActionProvider::get_key_y_action() { return 0x28; }
int LobbyPlayerActionProvider::get_key_p_action() { return 0x29; }
int LobbyPlayerActionProvider::get_key_a_action() { return 0x2A; }
int LobbyPlayerActionProvider::get_key_e_action() { return 0x2B; }
int LobbyPlayerActionProvider::get_key_z_action() { return 0x2C; }
int LobbyPlayerActionProvider::get_key_x_action() { return 0x2D; }
int LobbyPlayerActionProvider::get_key_v_action() { return 0x2E; }
int LobbyPlayerActionProvider::get_key_l_action() { return 0x2F; }
int LobbyPlayerActionProvider::get_chair_sit_action() { return 0x30; }
int LobbyPlayerActionProvider::get_alt_chair_sit_action() { return 0x31; }
int LobbyPlayerActionProvider::get_key_1_action() { return 0x32; }
int LobbyPlayerActionProvider::get_key_2_action() { return 0x33; }
int LobbyPlayerActionProvider::get_key_3_action() { return 0x34; }
int LobbyPlayerActionProvider::get_key_4_action() { return 0x35; }
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
