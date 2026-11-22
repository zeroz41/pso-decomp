#ifndef PSO_BOSS_DEROLLE_TBOSS2JOINT_H
#define PSO_BOSS_DEROLLE_TBOSS2JOINT_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/NinjaTypes.h"

// A shell segment's material in the De Rol Le body model: TBoss2DeRolLe's tables point just past a
// material chunk's head (polygon_list + 8), at its diffuse colour word.
struct TBoss2JointMaterial {
    u32 diffuse;
    u8 pad_4[0xC];
    u16 strip_head;  // the following strip chunk's [flags|type] head
};

// One of the ten shell segments TBoss2DeRolLe spawns along its body (the Barba Ray twin is TBoss7Joint).
struct TBoss2Joint : public TObjEneDD {
    enum { SHELL_BROKEN = 1 };  // joint_flags

    TBoss2Joint(TObject *parent, u16 entity_id, s32 set_index, const Vec *anchor, saddr body_material,
                saddr rim_material);
    virtual ~TBoss2Joint();
    void update_flash_color();
    virtual void run_task();
    virtual void render();
    virtual void refresh_target();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void enable_body_collision();
    virtual void break_shell();
    virtual void handle_state_0(s32 reason);
    void apply_flash_color();
    void start_pad_flash();
    void start_flash(s32 kind);
    void update_position_history();
    void init_params();

    s32 joint_flags;     // SHELL_BROKEN
    const Vec *anchor;   // run_task copies the joint's position from it (a TBoss2DeRolLe body point)
    s32 shell_hp;        // damage taken while the shell holds; break_shell runs when it reaches 0
    TBoss2JointMaterial *body_material;  // from TBoss2DeRolLe's derolle_segment_joint_node_offsets
    TBoss2JointMaterial *rim_material;   // from TBoss2DeRolLe's boss2_derolle_segment_color_targets
    u32 color;           // packed ARGB that apply_flash_color writes into the materials
    f32 unk_3a4;
    f32 flash;           // flash_color's weight, fading by 0.05 per frame
    NJS_ARGB flash_color;
};

LAYOUT_ASSERT(TBoss2Joint_size, sizeof(TBoss2Joint) == 0x3BC);

#endif
