#ifndef PSO_PLAYER_PLAYERACTIONPROVIDER_H
#define PSO_PLAYER_PLAYERACTIONPROVIDER_H
#include "types.h"

struct BmlMotionEntry;

struct TObjMotionAction;

// Body types are 0-5 and weapon motion types 0-18.
int is_valid_motion_type(u32 motion_type);
int is_valid_body_type(u32 body_type);

// The body type and weapon motion type a provider's motion set was loaded for.
class PlayerMotionKey {
public:
    PlayerMotionKey();
    ~PlayerMotionKey();
    int matches(s32 body_type, s32 motion_type);
    s32 get_motion_type();
    s32 get_body_type();
    void set_motion_type(s32 motion_type);
    s32 body_type;
    s32 motion_type;
};

// Base of the player action providers (GamePlayerActionProvider,
// LobbyPlayerActionProvider) that TObjPlayer::init_action_provider creates;
// allocated from obj_heap.
class PlayerActionProvider {
public:
    PlayerMotionKey key;
    PlayerActionProvider();
    static void *operator new(size_t size);
    static void operator delete(void *p);
    virtual u8 *get_cell_address(s32, s32);
    virtual ~PlayerActionProvider();
    virtual u8 *get_motion_buffer();
    virtual int load_motions(s32 set);
    virtual int load_motion_set(s32 set, s32 body_type, s32 motion_type);
    virtual const TObjMotionAction *get_motion_actions(s32 body_type, s32 motion_type);
    virtual const s32 *get_motion_files(s32 body_type, s32 motion_type);
    virtual int get_motion_file(s32 body_type, s32 motion_type, s32 slot);
    virtual int is_male();
    virtual int is_male(s32 body_type);
    virtual int is_female();
    virtual int is_female(s32 body_type);
    virtual void mark_attack_motions();
    // Action numbers: indexes into the provider's motion action table, or -1 when
    // the provider has no such action. The slow walk plays while the move speed is
    // slowed (PlayerMoveSpeed flag 8); the lock-on idle while a lock-on target is held.
    virtual int get_slow_walk_action();
    virtual int get_technique_action();
    virtual int get_attack1_action();
    virtual int get_attack2_action();
    virtual int get_attack3_action();
    virtual int get_lock_on_idle_action();
    virtual int get_use_item_action();
    virtual int get_walk_action();
    virtual int get_idle_action();
    virtual int get_knockdown_action();
    virtual int get_stand_up_action();
    virtual int get_hurt_action();
    virtual int get_death_action();
    virtual int get_interact_action();
    virtual int get_photon_blast_action();
    virtual int get_run_action();
    // Lobby gestures TObjPlayer::select_idle_action plays for a key held on the
    // keyboard (F1-F4, M and 5 use the knockdown, hurt, interact, use-item, death
    // and lock-on idle slots). The chair sits are U and I, or a held pad button
    // with a second press.
    virtual int get_key_f5_action();
    virtual int get_key_f6_action();
    virtual int get_key_f7_action();
    virtual int get_key_f8_action();
    virtual int get_key_f9_action();
    virtual int get_key_f10_action();
    virtual int get_key_f11_action();
    virtual int get_key_f12_action();
    virtual int get_key_6_action();
    virtual int get_key_7_action();
    virtual int get_key_8_action();
    virtual int get_key_9_action();
    virtual int get_key_0_action();
    virtual int get_key_h_action();
    virtual int get_key_b_action();
    virtual int get_key_o_action();
    virtual int get_key_n_action();
    virtual int get_key_q_action();
    virtual int get_key_j_action();
    virtual int get_key_r_action();
    virtual int get_key_k_action();
    virtual int get_key_w_action();
    virtual int get_key_s_action();
    virtual int get_key_t_action();
    virtual int get_key_c_action();
    virtual int get_key_d_action();
    virtual int get_key_f_action();
    virtual int get_key_g_action();
    virtual int get_key_y_action();
    virtual int get_key_p_action();
    virtual int get_key_a_action();
    virtual int get_key_e_action();
    virtual int get_key_z_action();
    virtual int get_key_x_action();
    virtual int get_key_v_action();
    virtual int get_key_l_action();
    virtual int get_chair_sit_action();
    virtual int get_alt_chair_sit_action();
    virtual int get_key_1_action();
    virtual int get_key_2_action();
    virtual int get_key_3_action();
    virtual int get_key_4_action();
    virtual int vfunc_73();
    virtual int vfunc_74();
    virtual int get_motion_count();
    virtual BmlMotionEntry *get_current_motion_list(); // Motion list used when the player changes lobby animation state.
    virtual BmlMotionEntry *get_motion_list(s32 body_type);
    s32 load_motion(s32 set, s32 index, s32 size, s32 aram_addr);
    s32 load_action_motion_pairs(s32 set, s32 body_type, s32 motion_type);
    void set_motion_type(s32 motion_type);
    int matches_motion_key(s32 body_type, s32 motion_type);
};

extern const char *player_motion_data_filename_ptr;

// player_action_provider_selector picks the class TObjPlayer::init_action_provider
// creates: 1 = GamePlayerActionProvider, 0 = LobbyPlayerActionProvider. Each scene's
// load hook selects one and allocates its motion buffer (the lobby hook selects the
// game provider when its allocation fails); the release hook frees it and selects 0.
// New-game setup also selects the game provider (select_game_player_actions).
extern int player_action_provider_selector;
int get_player_action_provider_selector();
void set_player_action_provider_selector(int selector);
void select_game_player_actions();
s32 get_player_action_motion_count();
void alloc_game_action_motion_buffer();
void free_game_action_motion_buffer();
void init_game_player_actions();
void release_game_player_actions();
u8 *alloc_lobby_action_motion_buffer();
void free_lobby_action_motion_buffer();
void init_lobby_player_actions();
void release_lobby_player_actions();

#endif
