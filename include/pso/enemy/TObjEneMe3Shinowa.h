#ifndef PSO_ENEMY_TOBJENEME3SHINOWA_H
#define PSO_ENEMY_TOBJENEME3SHINOWA_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneMe3Shinowa : public TObjEneDD_ST {
    virtual ~TObjEneMe3Shinowa();
    virtual void run_task();
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual void vfunc_105();
    virtual u8 can_hit_same_target();
    virtual void vfunc_107();
    virtual void update_player_state_default();
    virtual s32 update_effect();
    virtual void dispatch_if_active();
    virtual void vfunc_111();
    virtual void apply_effect_pair();
    virtual void action(s32);
    virtual void vfunc_114(s32);
    virtual void vfunc_115();
    virtual void vfunc_116(s32);
    virtual void update_mirage();
    virtual void vfunc_118();
    void init_enemy();
    f32 get_node_world_y();
    u8 check_body_collision_at(s32, f32);
    s32 sub_800E701C();
    s32 sub_800E6FE0();
    void sub_800E6F64();
    void sub_800E6BB8(s32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u32 m_374;
    u8 unk_378[0x14];
    u16 m_38c;
    u8 unk_38E[0x2];
    u32 m_390;
    u8 unk_394[0x8];
    u32 m_39c;
    u32 m_3a0;
    u8 unk_3A4[0x4];
    u32 m_3c4;
    u8 unk_3C8[0x4];
    void* m_3cc;
    u8 unk_3D0[0x18];
    void* m_3e8;
    u8 _padBeforeFade[0x10];
    u32 m_3fc;
    u8 _padBeforeFadeTail[0x4];
    MaterialOpacityFade fade;
    void copy_position_vector();
};

typedef char TObjEneMe3Shinowa_m_3fc_offset[offsetof(TObjEneMe3Shinowa, m_3fc) == 0x3E0 ? 1 : -1];

typedef char TObjEneMe3ShinowaFadeOffset[offsetof(TObjEneMe3Shinowa, fade) == 0x3E8 ? 1 : -1];

#endif
