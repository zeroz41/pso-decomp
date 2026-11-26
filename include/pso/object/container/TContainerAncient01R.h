#ifndef PSO_OBJECT_CONTAINER_TCONTAINERANCIENT01R_H
#define PSO_OBJECT_CONTAINER_TCONTAINERANCIENT01R_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjChara.h"

struct TContainerAncient01R : public TObjChara {
    TContainerAncient01R(TObject *parent, void *set_data);
    virtual s32 roll_physical_accuracy(TObjChara *, s32, f32);
    virtual f32 receive_weapon_special_attack(TObjChara *, CollisionBody *);
    virtual ~TContainerAncient01R();
    virtual s32 select_melee_contact_body(TObjChara *, f32);
    virtual int calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float);
    virtual f32 receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    void open_container();
    void check_open_trigger();
    void update_spawning();
    void update_blast();
    void reset_state();
    virtual void apply_saved_state(s16 *, s32);
    virtual s32 try_start_action(TObjChara *, s32, f32);
    virtual void apply_knockback_from_attacker(TObjBase *, f32);
    virtual void render();
    virtual void run_task();
    static void init_table_entries();
    u8 pad_334[0x4];
    s16 hit_count; // hits taken: it opens when hp runs out
    u8 pad_33A[0x2];
    f32 wait_limit;
    f32 active_limit;
    f32 range;
    Vec lower_effect_position;
    Vec upper_effect_position;
    void init_positions();
    void trigger_spawn(const Vec *position, s32 effect_id);
    s32 opened;
    Vec open_scale;
    u32 spawns_per_second; // set param 2 + 4: the open blast spawns every 30 / this frames
    static void *create(void *set_data);
    // Forgets the archive it shares with TContainerAncient01 (which frees it).
    static void free_resources();
    void attack_nearby_players(f32 range);
};

LAYOUT_ASSERT(TContainerAncient01R_size, sizeof(TContainerAncient01R) == 0x374);
LAYOUT_ASSERT(TContainerAncient01RLowerEffectOffset, offsetof(TContainerAncient01R, lower_effect_position) == 0x348);
LAYOUT_ASSERT(TContainerAncient01RUpperEffectOffset, offsetof(TContainerAncient01R, upper_effect_position) == 0x354);
LAYOUT_ASSERT(TContainerAncient01ROpenScaleOffset, offsetof(TContainerAncient01R, open_scale) == 0x364);
#endif
