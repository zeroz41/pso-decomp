#ifndef PSO_WEAPON_TITEMWEAPONSRANKPUNCH_H
#define PSO_WEAPON_TITEMWEAPONSRANKPUNCH_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"
#include "pso/system/data/FlagWord.h"

class TItemWeaponSRankPunch : public TItemWeaponSRank {
public:
    TItemWeaponSRankPunch(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankPunch();
    virtual void transform_model_node();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    // Item timer callback: the ring is no longer out.
    static void clear_rico_ring_flag(TObject *object);
    FlagWord flags;                 // 1: drawing the second barrel, 2: ring out, 4: firing
    Vec shot_origins[2];   // get_joint_position(1) per barrel, launch_shot origins
};

// The weapon's hit callback (hit_callback).
void s_rank_punch_hit_effect(s32 layer, TObject *player, s32 target_id, s32 body);

void debug_weapon_attack_hook(void);
void notify_hit_target(u32 layer, uaddr player, u32 target, uaddr pos);

#endif
