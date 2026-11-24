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
    virtual s32 get_cell_address(s32, s32);
    virtual ~PlayerActionProvider();
    virtual int get_motion_buffer();
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
    virtual int vfunc_15();
    virtual int get_technique_action();
    virtual int get_attack1_action();
    virtual int get_attack2_action();
    virtual int get_attack3_action();
    virtual int vfunc_20();
    virtual int get_use_item_action();
    virtual int vfunc_22();
    virtual int vfunc_23();
    virtual int get_knockdown_action();
    virtual int vfunc_25();
    virtual int get_hurt_action();
    virtual int get_death_action();
    virtual int get_interact_action();
    virtual int get_photon_blast_action();
    virtual int get_run_action();
    virtual int vfunc_31();
    virtual int vfunc_32();
    virtual int vfunc_33();
    virtual int vfunc_34();
    virtual int vfunc_35();
    virtual int vfunc_36();
    virtual int vfunc_37();
    virtual int vfunc_38();
    virtual int vfunc_39();
    virtual int vfunc_40();
    virtual int vfunc_41();
    virtual int vfunc_42();
    virtual int vfunc_43();
    virtual int vfunc_44();
    virtual int vfunc_45();
    virtual int vfunc_46();
    virtual int vfunc_47();
    virtual int vfunc_48();
    virtual int vfunc_49();
    virtual int vfunc_50();
    virtual int vfunc_51();
    virtual int vfunc_52();
    virtual int vfunc_53();
    virtual int vfunc_54();
    virtual int vfunc_55();
    virtual int vfunc_56();
    virtual int vfunc_57();
    virtual int vfunc_58();
    virtual int vfunc_59();
    virtual int vfunc_60();
    virtual int vfunc_61();
    virtual int vfunc_62();
    virtual int vfunc_63();
    virtual int vfunc_64();
    virtual int vfunc_65();
    virtual int vfunc_66();
    virtual int vfunc_67();
    virtual int vfunc_68();
    virtual int vfunc_69();
    virtual int vfunc_70();
    virtual int vfunc_71();
    virtual int vfunc_72();
    virtual int vfunc_73();
    virtual int vfunc_74();
    virtual int get_motion_count();
    virtual BmlMotionEntry *vfunc_76(); // Motion list used when the player changes lobby animation state.
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
s32 alloc_lobby_action_motion_buffer();
void free_lobby_action_motion_buffer();
void init_lobby_player_actions();
void release_lobby_player_actions();

#endif
