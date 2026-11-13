#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWA_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWA_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

class TParticleCtrl;
class TUnk_80494968;

struct TObjEneMe3ShinowaParams {
    f32 m_0;
    f32 m_4;
    f32 m_8;
    f32 m_c;
    f32 m_10;
    u8 unk_14[0x4];
    s32 m_18;
    s32 m_1c;
    s32 m_20;
};

struct TObjEneMe3ShinowaMoveParams {
    f32 m_0;
    f32 m_4;
    s32 m_8;
    u8 unk_c[0x10];
};

struct TObjEneMe3Shinowa : public TObjEneDD_ST {
    virtual ~TObjEneMe3Shinowa();
    virtual s32 vfunc_104(f32);
    virtual void run_task();
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual void vfunc_105();
    virtual s32 can_hit_same_target();
    virtual void vfunc_107();
    virtual void update_player_state_default();
    virtual s32 update_effect();
    virtual void dispatch_if_active();
    virtual void vfunc_111();
    virtual void apply_effect_pair();
    virtual void action(s32);
    virtual void vfunc_114(s32);
    virtual void vfunc_115(s32);
    virtual void vfunc_116(s32);
    virtual void update_mirage();
    virtual void vfunc_118();
    void init_enemy();
    f32 get_node_world_y();
    s32 check_body_collision_at(s32, f32);
    s32 sub_800E701C();
    s32 sub_800E6FE0();
    void sub_800E6F64();
    void sub_800E6BB8(s32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u8 unk_374[0x4];
    s32 m_378;
    f32 m_37c;
    u8 unk_380[0xC];
    u16 m_38c;
    u8 unk_38E[0x2];
    TObjChara *m_390;
    Vec m_394;
    Vec m_3a0;
    f32 m_3ac;
    u8 unk_3B0[0x8];
    s32 m_3b8;
    s32 m_3bc;
    s32 m_3c0;
    u32 m_3c4;
    f32 m_3c8;
    f32 m_3cc;
    u32 m_3d0;
    s32 m_3d4;
    s32 m_3d8;
    s16 m_3dc;
    TUnk_80494968 *m_3e0;
    TUnk_80494968 *m_3e4;
    TUnk_80494938 m_3e8;
    s32 m_404;
    s32 m_408;
    s32 m_40c;
    f32 m_410;
    f32 m_414;
    Vec m_418;
    TParticleCtrl *m_424;
    TParticleCtrl *m_428;
    void copy_position_vector();
};

typedef char TObjEneMe3Shinowa_m_3e8[offsetof(TObjEneMe3Shinowa, m_3e8) == 0x3E8 ? 1 : -1];
typedef char TObjEneMe3Shinowa_size[sizeof(TObjEneMe3Shinowa) == 0x42C ? 1 : -1];

#endif
