#ifndef PSO_MISC_TCONTAINERANCIENT01R_H
#define PSO_MISC_TCONTAINERANCIENT01R_H

#include "types.h"
#include "pso/player/TObjChara.h"

struct TContainerAncient01R : public TObjChara {
    virtual ~TContainerAncient01R();
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    void open_container();
    void check_open_trigger();
    void update_spawning();
    s32 sub_8018A688();
    void reset_hp();
    virtual void vfunc_6(s16 *, s32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual s32 try_start_action(s32, s32);
    virtual void apply_knockback_from_attacker(u8 *);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void render();
    virtual void run_task();
    static void init_table_entries();
    u8 unk_334[0x4];
    s16 m_338;
    u8 unk_33A[0x2];
    f32 m_33c;
    u8 unk_340[0x4];
    f32 m_344;
    u8 unk_348[0x18];
    s32 m_360;
    u8 unk_364[0x4];
    f32 m_368;
    u8 unk_36C[0x4];
    u32 m_370;
};

typedef char TContainerAncient01R_size[sizeof(TContainerAncient01R) == 0x374 ? 1 : -1];
#endif
