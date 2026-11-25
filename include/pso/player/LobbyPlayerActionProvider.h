#ifndef PSO_PLAYER_LOBBYPLAYERACTIONPROVIDER_H
#define PSO_PLAYER_LOBBYPLAYERACTIONPROVIDER_H
#include "types.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/system/data/FlagWord.h"

class LobbyPlayerActionProvider : public PlayerActionProvider {
public:
    LobbyPlayerActionProvider();
    virtual u8 *get_cell_address(s32, s32);
    virtual ~LobbyPlayerActionProvider();
    virtual const s32 *get_motion_files(s32 body_type, s32 motion_type);
    virtual int get_motion_file(s32 body_type, s32 motion_type, s32 slot);
    virtual int is_female();
    virtual int is_female(s32 body_type);
    virtual int is_male(s32 body_type);
    virtual int load_motions(s32 set);
    virtual int load_motion_set(s32 set, s32 body_type, s32 motion_type);
    virtual BmlMotionEntry *get_current_motion_list();
    virtual int get_motion_count();
    virtual int get_key_4_action();
    virtual int get_key_3_action();
    virtual int get_key_2_action();
    virtual int get_key_1_action();
    virtual int get_alt_chair_sit_action();
    virtual int get_chair_sit_action();
    virtual int get_key_l_action();
    virtual int get_key_v_action();
    virtual int get_key_x_action();
    virtual int get_key_z_action();
    virtual int get_key_e_action();
    virtual int get_key_a_action();
    virtual int get_key_p_action();
    virtual int get_key_y_action();
    virtual int get_key_g_action();
    virtual int get_key_f_action();
    virtual int get_key_d_action();
    virtual int get_key_c_action();
    virtual int get_key_t_action();
    virtual int get_key_s_action();
    virtual int get_key_w_action();
    virtual int get_key_k_action();
    virtual int get_key_r_action();
    virtual int get_key_j_action();
    virtual int get_key_q_action();
    virtual int get_key_n_action();
    virtual int get_key_o_action();
    virtual int get_key_b_action();
    virtual int get_key_h_action();
    virtual int get_death_action();
    virtual int get_key_0_action();
    virtual int get_key_9_action();
    virtual int get_key_8_action();
    virtual int get_key_7_action();
    virtual int get_key_6_action();
    virtual int get_lock_on_idle_action();
    virtual int get_key_f12_action();
    virtual int get_key_f11_action();
    virtual int get_key_f10_action();
    virtual int get_key_f9_action();
    virtual int get_key_f8_action();
    virtual int get_key_f7_action();
    virtual int get_key_f6_action();
    virtual int get_key_f5_action();
    virtual int get_use_item_action();
    virtual int get_interact_action();
    virtual int get_hurt_action();
    virtual int get_knockdown_action();
    virtual u8 *get_motion_buffer();
    virtual int is_male();
    virtual const TObjMotionAction *get_motion_actions(s32 body_type, s32 motion_type);
    virtual int get_idle_action();
    virtual int get_walk_action();
    virtual int get_run_action();
    virtual BmlMotionEntry *get_motion_list(s32 body_type);

    // The lobby uses two motion sets: 0 for male bodies, 1 for female ones.
    int get_gender(s32 body_type);
    int get_gender();
    static void set_female_motions_loaded();
    static s32 female_motions_loaded();
    static void set_male_motions_loaded();
    static s32 male_motions_loaded();
    static void clear_loaded_motions();
};
// The lobby motion buffer: 0x38 motions of 0x4000 bytes for each of the two sets.
extern u8 *lobby_action_motion_buffer;
// Bit 1 once the male motion set is loaded, bit 2 once the female one is.
extern FlagWord lobby_loaded_motion_sets;

LAYOUT_ASSERT(LobbyPlayerActionProvider_size, sizeof(LobbyPlayerActionProvider) == 0xC);

#endif
