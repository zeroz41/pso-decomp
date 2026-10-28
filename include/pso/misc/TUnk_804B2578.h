#ifndef PSO_MISC_TUNK_804B2578_H
#define PSO_MISC_TUNK_804B2578_H
#include "types.h"
#include "pso/player/TObjChara.h"

class TUnk_804B2578 : public TObjChara {
public:
    virtual ~TUnk_804B2578();
    bool sub_801688C0();
    void sub_80168280(u32);
    void init_geometry();
    void sub_80168488();
    void sub_80168398();
    void sub_801682E4(s32);
    s32 sub_80168244(u32);
    void advance_wrap_offset();
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual f32 vfunc_81();
    void set_scale(f32);
    virtual void apply_knockback_from_attacker(u8 *);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_physical_attack(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual s32 select_melee_contact_body(void *, f32);
    virtual void render();
    virtual void run_task();
    u8 unk_334[0x4];
    f32 m_338;
    u8 unk_33C[0x4];
    u32 m_340;
    u8 unk_344[0x8];
    s32 m_34c;
    f32 m_350;
    u8 unk_354[0x4];
    u32 m_358;
};

#endif
