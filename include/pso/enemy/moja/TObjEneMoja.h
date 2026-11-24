#ifndef PSO_ENEMY_MOJA_TOBJENEMOJA_H
#define PSO_ENEMY_MOJA_TOBJENEMOJA_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/RenderFadeState.h"

class TAttackTraceStrip;
struct BmlResource;

extern BmlResource *moja_bml_resource;

struct MojaBattleStat {
    u8 unknown_00[0x18];
    s32 techniqueLevel;
};
// One per variant (TObjEnemy::variant); TObjEnemy::movementParameters points
// at the Moja's.
struct MojaMovementParameters {
    f32 target_range;  // find_nearest_visible_player's radius; a farther target is dropped
    f32 move_speed;    // wander and chase speed
    s32 turn_speed;    // turn_toward_direction's max step
    u32 unknown_0C[4];
};
// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as
// DelDepthAnimationBinding).
struct MojaAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};
struct MojaParticleAngles {
    s32 x, y, z;
};
struct TObjEneMoja : public TObjEnemy {
    TObjEneMoja(TObject *parent, void *setData);
    virtual ~TObjEneMoja();
    void clamp_stat_354();
    static void load_resources();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual s32 is_target_in_attack_range();
    virtual void run_attack_action();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void refresh_target();
    void render();
    void bindModel(int index);
    s32 appearance;
    f32 jumpSpeed;
    s32 unused_37C;
    s32 attack;
    s32 attackSequence;
    s32 roar;
    f32 sinkOffset;
    f32 techniqueChance;
    f32 jumpChance;
    TAttackTraceStrip *unknown_398;
    RenderFadeState unknown_39C[4];
    static void *create(void *setData);
    static void free_resources();
    s32 calc_technique_level();
    void select_rare_variant();
    void update_death_state();
    void update_technique_state();
    void update_punch_attack();
    void update_invincibility();
    void update_ground_effect();
    void update_approach_state();
    void update_idle_state();
    void update_appearance_jump();
    void update_appearance_drop();
    void update_attack_jump();
    void run_task();
};
LAYOUT_ASSERT(MojaSize, sizeof(TObjEneMoja)==0x40C);

// The Moja model archive, shared with the town NPC TObjNpcMoja.
extern BmlResource *moja_bml_resource;

#include <stddef.h>
#define MOJA_OFFSET(field, offset) LAYOUT_ASSERT(MojaOffset_##field, offsetof(TObjEneMoja, field)==offset)
MOJA_OFFSET(appearance,0x374);
MOJA_OFFSET(attackSequence,0x384);
MOJA_OFFSET(roar,0x388);
#undef MOJA_OFFSET
#endif
