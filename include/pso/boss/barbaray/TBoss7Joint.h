#ifndef PSO_BOSS_BARBARAY_TBOSS7JOINT_H
#define PSO_BOSS_BARBARAY_TBOSS7JOINT_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/base/TObjMotion.h"

struct TBoss7DeRolLeC;

struct TBoss7Joint : public TObjEneDD {
    TBoss7Joint(TObject *parent, u16 id, s16 set_index, Vec *position, s32 index);
    virtual ~TBoss7Joint();
    void init_boss_stats();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void run_hit_reaction();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    virtual void run_miss_reaction();
    virtual void run_death_reaction();
    virtual void refresh_target();
    virtual void update_body_colliders();
    virtual void enable_body_collision();
    CollisionBody collision_body;
    s32 index;              // constructor argument: the joint's place along the body
    u32 part_flags;         // bit 0: the shell is broken and hits reach the boss
    Vec *source_position;   // constructor argument: run_task copies it into position
    s32 shell_hp;           // init_params sets it from TBoss7Joint_get_shell_max_hp()
    void store_position();
    void run_task();
    s32 init_params();
    static TBoss7DeRolLeC *get_state();
    int is_part_active();
};

LAYOUT_ASSERT(TBoss7Joint_collision_body, offsetof(TBoss7Joint, collision_body) == 0x38C);
LAYOUT_ASSERT(TBoss7Joint_size, sizeof(TBoss7Joint) == 0x3C8);

#endif
