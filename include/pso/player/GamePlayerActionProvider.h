#ifndef PSO_PLAYER_GAMEPLAYERACTIONPROVIDER_H
#define PSO_PLAYER_GAMEPLAYERACTIONPROVIDER_H
#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/player/PlayerActionProvider.h"

class GamePlayerActionProvider : public PlayerActionProvider {
public:
    BmlMotionEntry motions[16];
    GamePlayerActionProvider();
    virtual s32 get_cell_address(s32, s32);
    virtual ~GamePlayerActionProvider();
    virtual int load_motions(s32 set);
    virtual int load_motion_set(s32 set, s32 body_type, s32 motion_type);
    virtual const TObjMotionAction *get_motion_actions(s32 body_type, s32 motion_type);
    virtual const s32 *get_motion_files(s32 body_type, s32 motion_type);
    virtual int get_motion_file(s32 body_type, s32 motion_type, s32 slot);
    virtual int get_attack3_action();
    virtual int get_attack2_action();
    virtual int get_technique_action();
    virtual int get_slow_walk_action();
    virtual void mark_attack_motions();
    virtual int get_motion_count();
    virtual int get_run_action();
    virtual int get_photon_blast_action();
    virtual int get_interact_action();
    virtual int get_death_action();
    virtual int get_hurt_action();
    virtual int get_stand_up_action();
    virtual int get_knockdown_action();
    virtual int get_idle_action();
    virtual int get_walk_action();
    virtual int get_use_item_action();
    virtual int get_lock_on_idle_action();
    virtual int get_attack1_action();
    virtual int get_motion_buffer();
    virtual BmlMotionEntry *get_motion_list(s32 body_type);
    virtual BmlMotionEntry *get_current_motion_list();
};
LAYOUT_ASSERT(GamePlayerActionProvider_size, sizeof(GamePlayerActionProvider) == 0x8C);

#endif
