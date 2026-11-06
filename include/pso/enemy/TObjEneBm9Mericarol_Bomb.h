#ifndef PSO_ENEMY_TOBJENEBM9MERICAROL_BOMB_H
#define PSO_ENEMY_TOBJENEBM9MERICAROL_BOMB_H
#include "types.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/TParticleCtrl.h"

class TObjEneBm9Mericarol;

class TObjEneBm9Mericarol_Bomb : public TUnk_804928CC {
public:
    TObjEneBm9Mericarol_Bomb(TObjEneBm9Mericarol *owner, Vec *pos, Vec *target, f32 farg0, f32 farg1, s32 arg4);
    virtual ~TObjEneBm9Mericarol_Bomb();
    virtual void render();
    virtual void run_task();
    virtual s32 area_attack_deliver_direct(void *recoil, s32 arg2, void *object, f32 range);
    u8 unk_B0[0x4];
    f32 m_b4;
    f32 unk_B8;
    f32 m_bc;
    u8 unk_C0[0x4];
    f32 m_c4;
    u8 unk_C8[0x4];
    f32 m_cc;
    u8 unk_D0[0x4];
    f32 m_d4;
    u8 unk_D8[0x4];
    f32 m_dc;
    u8 unk_E0[0x4];
    f32 m_e4;
    u8 unk_E8[0x4];
    s32 m_ec;
    u8 unk_F0[0x4];
    f32 m_f4;
    f32 m_f8;
    u8 unk_FC[0x4];
    s32 m_100;
    u8 unk_104[0x4];
    s32 m_108;
    u8 unk_10C[0x4];
    TParticleCtrl *m_110;
    TParticleCtrl *unk_114;
};
typedef char TObjEneBm9Mericarol_Bomb_size[sizeof(TObjEneBm9Mericarol_Bomb) == 0x118 ? 1 : -1];

#endif
