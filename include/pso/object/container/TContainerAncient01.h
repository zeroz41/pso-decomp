#ifndef PSO_OBJECT_CONTAINER_TCONTAINERANCIENT01_H
#define PSO_OBJECT_CONTAINER_TCONTAINERANCIENT01_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjChara.h"

struct BmlResource;

struct TContainerAncient01 : public TObjChara {
    TContainerAncient01(TObject *parent, void *set_data);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual ~TContainerAncient01();
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual s32 select_melee_contact_body(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    void open_container();
    void update_spawning();
    void update_blast();  // name inferred: the open blast (sounds, effects, attack_nearby_players) until active_limit
    virtual void apply_saved_state(s16 *, s32);
    virtual s32 try_start_action(void *, s32, f32);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    u8 unk_334[0x4];
    f32 wait_limit;      // frames it waits for a player before it opens anyway (300 + scale.x - 1)
    f32 active_limit;    // frames the open blast runs (210 + scale.y - 1)
    f32 range;
    Vec lower_effect_position;
    Vec upper_effect_position;
    s32 opened;          // 1 once it has opened
    Vec open_scale;
    void spawn_effect(const Vec *position, s32 effect_id);
    void reset_state();
    void update_wait_for_player();
    void init_state_vectors();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void release_static_resource();
    static void load_resources();
    static s32 is_global_state_in_table();
    u32 effect_rate;     // set param 2 + 4; the blast spawns an effect every 30 / effect_rate frames
    static int get_table_entry(int a0);
    // Hits every player on this floor within range (squared, xz) with a kind 0xF
    // direct attack of power 100. Name inferred.
    void attack_nearby_players(f32 range);
    // The archive load_resources loaded; TContainerAncient01R shares it.
    static BmlResource *get_bml_resource();
};

LAYOUT_ASSERT(TContainerAncient01_size, sizeof(TContainerAncient01) == 0x370);
LAYOUT_ASSERT(TContainerAncient01LowerEffectOffset, offsetof(TContainerAncient01, lower_effect_position) == 0x344);
LAYOUT_ASSERT(TContainerAncient01UpperEffectOffset, offsetof(TContainerAncient01, upper_effect_position) == 0x350);
LAYOUT_ASSERT(TContainerAncient01OpenScaleOffset, offsetof(TContainerAncient01, open_scale) == 0x360);
#endif
