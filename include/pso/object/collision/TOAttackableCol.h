#ifndef PSO_OBJECT_COLLISION_TOATTACKABLECOL_H
#define PSO_OBJECT_COLLISION_TOATTACKABLECOL_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

struct TOAttackableCol : public TObjChara {
    TOAttackableCol(saddr);
    virtual ~TOAttackableCol();
    virtual void vfunc_6(s16 *, s32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual s32 try_start_action(s32, s32);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual s32 select_melee_contact_body(void *, f32);
    u8 unk_334[0x4];
    f32 m_338;
    u32 m_33c;
    void init_params();
    void send_state_change(u16 state);
    void handle_6x91_update_state();
    f32 apply_hit(saddr player);
    void release();
    void check_door_trigger();
    virtual void run_task();
    virtual void render();
    static void *create(void *arg0);
    void bswap_state();
    void broadcast_state();
    u8 unk_340[0x4];
    s32 label;
    u8 unk_348[0x4];
    s32 m_34c;
};

LAYOUT_ASSERT(TOAttackableCol_size, sizeof(TOAttackableCol) == 0x350);
extern "C" {
void TOAttackableCol__sub_80157310(void *_w0);
void TOAttackableCol__sub_80157C20(void *p, s32 v);
s32 TOAttackableCol__sub_80157C28(void *p);
void *__dt__15TOAttackableColFv(void *arg0, s16 arg1);
void *init_6x91_subcommand(void *barrier_energy01);
}

#endif
