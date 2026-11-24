#ifndef PSO_PLAYER_LOBBYPLAYERACTIONPROVIDER_H
#define PSO_PLAYER_LOBBYPLAYERACTIONPROVIDER_H
#include "types.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/system/data/FlagWord.h"

class LobbyPlayerActionProvider : public PlayerActionProvider {
public:
    LobbyPlayerActionProvider();
    virtual s32 get_cell_address(s32, s32);
    virtual ~LobbyPlayerActionProvider();
    virtual const s32 *get_motion_files(s32 body_type, s32 motion_type);
    virtual int get_motion_file(s32 body_type, s32 motion_type, s32 slot);
    virtual int is_female();
    virtual int is_female(s32 body_type);
    virtual int is_male(s32 body_type);
    virtual int load_motions(s32 set);
    virtual int load_motion_set(s32 set, s32 body_type, s32 motion_type);
    virtual BmlMotionEntry *vfunc_76();
    virtual int get_motion_count();
    virtual int vfunc_72();
    virtual int vfunc_71();
    virtual int vfunc_70();
    virtual int vfunc_69();
    virtual int vfunc_68();
    virtual int vfunc_67();
    virtual int vfunc_66();
    virtual int vfunc_65();
    virtual int vfunc_64();
    virtual int vfunc_63();
    virtual int vfunc_62();
    virtual int vfunc_61();
    virtual int vfunc_60();
    virtual int vfunc_59();
    virtual int vfunc_58();
    virtual int vfunc_57();
    virtual int vfunc_56();
    virtual int vfunc_55();
    virtual int vfunc_54();
    virtual int vfunc_53();
    virtual int vfunc_52();
    virtual int vfunc_51();
    virtual int vfunc_50();
    virtual int vfunc_49();
    virtual int vfunc_48();
    virtual int vfunc_47();
    virtual int vfunc_46();
    virtual int vfunc_45();
    virtual int vfunc_44();
    virtual int get_death_action();
    virtual int vfunc_43();
    virtual int vfunc_42();
    virtual int vfunc_41();
    virtual int vfunc_40();
    virtual int vfunc_39();
    virtual int vfunc_20();
    virtual int vfunc_38();
    virtual int vfunc_37();
    virtual int vfunc_36();
    virtual int vfunc_35();
    virtual int vfunc_34();
    virtual int vfunc_33();
    virtual int vfunc_32();
    virtual int vfunc_31();
    virtual int get_use_item_action();
    virtual int get_interact_action();
    virtual int get_hurt_action();
    virtual int get_knockdown_action();
    virtual int get_motion_buffer();
    virtual int is_male();
    virtual const TObjMotionAction *get_motion_actions(s32 body_type, s32 motion_type);
    virtual int vfunc_23();
    virtual int vfunc_22();
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
extern s32 lobby_action_motion_buffer;
// Bit 1 once the male motion set is loaded, bit 2 once the female one is.
extern FlagWord lobby_loaded_motion_sets;

LAYOUT_ASSERT(LobbyPlayerActionProvider_size, sizeof(LobbyPlayerActionProvider) == 0xC);

#endif
