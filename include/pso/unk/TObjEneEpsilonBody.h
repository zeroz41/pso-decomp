#ifndef PSO_UNK_TOBJENEEPSILONBODY_H
#define PSO_UNK_TOBJENEEPSILONBODY_H
#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneEpsilon.h"

class TObjEneEpsilonBody : public TObjEneEpsilon {
public:
    virtual ~TObjEneEpsilonBody();
    virtual f32 receive_weapon_special_attack(void *, void *);
    void init_params();
    void update_guard_flag();
    void sub_80361D4C(s32);
    void sub_803606A0(s32);
    void render_body_effect();
    void set_guard_state(s32);
    s16 get_table_value_by_index();
    s16 sub_8035F8A8();
    virtual void run_task();
    virtual void render();
    virtual f32 receive_physical_attack(void *, f32);
    virtual void vfunc_28();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    virtual void vfunc_88();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    u8 unk_3A8[0x90];
    s32 m_438; // 0x438
    u8 unk_43C[0x2];
    s16 m_43e; // 0x43E
    u8 unk_440[0x4];
    s32 m_444; // 0x444
    u8 unk_448[0x8];
    s32 m_450; // 0x450
    u8 unk_454[0x4];
    f32 m_458; // 0x458

    u8 _padBeforeFade[0x64];
    MaterialOpacityFade fade;
    u8 _padAfterFade[0x8];
    s32 m_4e4; // 0x4E4
    u8 unk_4E8[0x10];
    f32 m_4f8; // 0x4F8
    u8 unk_4FC[0x18];
};

typedef char TObjEneEpsilonBodyFadeOffset[offsetof(TObjEneEpsilonBody, fade) == 0x4C0 ? 1 : -1];
typedef char TObjEneEpsilonBody_size[sizeof(TObjEneEpsilonBody) == 0x514 ? 1 : -1];

#endif
