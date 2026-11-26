#ifndef PSO_OBJECT_COLLISION_TOATTACKABLECOL_H
#define PSO_OBJECT_COLLISION_TOATTACKABLECOL_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

struct TOAttackableCol : public TObjChara {
    TOAttackableCol(saddr);
    virtual ~TOAttackableCol();
    virtual void apply_saved_state(s16 *, s32);
    virtual s32 roll_physical_accuracy(TObjChara *, s32, f32);
    virtual s32 try_start_action(TObjChara *, s32, f32);
    virtual void apply_knockback_from_attacker(TObjBase *, f32);
    virtual f32 receive_weapon_special_attack(TObjChara *, CollisionBody *);
    virtual f32 receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual int calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float);
    virtual s32 select_melee_contact_body(TObjChara *, f32);
    u8 unk_334[0x4];
    f32 m_338;
    u32 hits_left;  // hits it can still take; 0 once destroyed
    void init_params();
    void send_state_change(u16 state);
    void handle_6x91_update_state();
    f32 apply_hit(saddr player);
    void release();
    void check_door_trigger();
    void sub_80157310();
    void set_hits_left(s32 v);
    s32 get_hits_left();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    s32 script_kind;  // set_params[1]: 100-999 picks the mission script manager, else the area's
    s32 label;
    s32 done_switch;  // floor switch set when it is destroyed, -1 for none (only used while label is 0)
    s32 required_switch;  // floor switch that must be set before it can be hit, -1 for none
};

LAYOUT_ASSERT(TOAttackableCol_size, sizeof(TOAttackableCol) == 0x350);
struct G_UpdateAttackableColState_6x91;
G_UpdateAttackableColState_6x91 *init_6x91_subcommand(G_UpdateAttackableColState_6x91 *msg);

#endif
