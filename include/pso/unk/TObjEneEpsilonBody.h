#ifndef PSO_UNK_TOBJENEEPSILONBODY_H
#define PSO_UNK_TOBJENEEPSILONBODY_H
#include "types.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TUnk_80494938.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

class TObjEneEpsilonBody : public TObjEneEpsilon {
public:
    TObjEneEpsilonBody(TObject *parent, void *set_data);
    virtual ~TObjEneEpsilonBody();
    virtual f32 receive_weapon_special_attack(void *, void *);
    void init_params();
    void update_guard_flag();
    void sub_80361D4C(s32);
    void sub_803606A0(s32);
    void render_body_effect();
    void set_guard_state();
    void set_guard_part_colors(NJS_ARGB *color);
    s16 get_table_value_by_index();
    s16 sub_8035F8A8();
    virtual void run_task();
    virtual void render();
    virtual f32 receive_physical_attack(void *, f32);
    virtual void vfunc_28();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    TObject *m_430;
    TObject *m_434;
    s32 m_438; // 0x438
    u8 unk_43C[0x2];
    s16 m_43e; // 0x43E
    s32 m_440;
    s32 m_444; // 0x444
    s32 m_448;
    u8 unk_44C[0x4];
    s32 m_450; // 0x450
    s32 m_454;
    f32 m_458; // 0x458
    u8 unk_45C[0x4];
    s32 guard_rotation_y[4];  // per guard: the rotation_y it was spawned with
    Vec guard_position[4];    // per guard: the position it was spawned at
    NJS_ARGB m_4a0;
    u8 unk_4B0[0x10];
    TUnk_80494938 m_4c0;
    u16 guard_ids[4];  // entity ids of the four TObjEneEpsilonGuard it spawns
    s32 m_4e4; // 0x4E4
    s32 m_4e8;
    s32 m_4ec;
    s32 m_4f0;
    s32 m_4f4;
    f32 m_4f8; // 0x4F8
    f32 m_4fc;
    f32 m_500;
    f32 m_504;
    f32 m_508;
    f32 m_50c;
    f32 m_510;
};
typedef char TObjEneEpsilonBody_size[sizeof(TObjEneEpsilonBody) == 0x514 ? 1 : -1];

#endif
