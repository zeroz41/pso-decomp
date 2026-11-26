#ifndef PSO_ENEMY_MOJA_TOBJENEMOJA_H
#define PSO_ENEMY_MOJA_TOBJENEMOJA_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/RenderFadeState.h"

class TAttackTraceStrip;
struct BmlResource;

extern BmlResource *moja_bml_resource;

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
    TAttackTraceStrip *attack_trace;
    RenderFadeState camera_fades[4];
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
