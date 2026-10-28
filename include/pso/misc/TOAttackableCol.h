#ifndef PSO_MISC_TOATTACKABLECOL_H
#define PSO_MISC_TOATTACKABLECOL_H

#include "types.h"
#include "pso/player/TObjChara.h"

struct TOAttackableCol : public TObjChara {
    virtual ~TOAttackableCol();
    virtual void vfunc_6(s16 *, s32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual s32 try_start_action(s32, s32);
    virtual void apply_knockback_from_attacker(u8 *);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual s32 select_melee_contact_body(void *, f32);
    u8 unk_334[0x4];
    f32 m_338;
    u32 m_33c;
    void init_params();
    int send_state_change(u16 state);
    int handle_6x91_update_state();
    f32 apply_hit(s32 arg1);
    void release();
    void check_door_trigger();
    virtual void run_task();
    virtual void render();
    static void *create(void *arg0);
    void bswap_state();
    void broadcast_state();
    u8 unk_340[0x4];
    s32 m_344;
    u8 unk_348[0x4];
    s32 m_34c;
};

typedef char TOAttackableCol_size[sizeof(TOAttackableCol) == 0x350 ? 1 : -1];
extern "C" {
u8 *TOAttackableCol__ct(u8 *arg0, s32 arg1);
void TOAttackableCol__sub_80157310(void *_w0);
void TOAttackableCol__sub_80157C20(void *p, s32 v);
s32 TOAttackableCol__sub_80157C28(void *p);
void *__dt__15TOAttackableColFv(void *arg0, s16 arg1);
void *fn_80157CA8(void *arg0);
}

#endif
