#ifndef PSO_BOSS_BARBARAY_TBOSS7PHOTONBULLET_H
#define PSO_BOSS_BARBARAY_TBOSS7PHOTONBULLET_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

struct TBoss7PhotonBullet : public TUnk_804928CC {
    virtual ~TBoss7PhotonBullet();
    void render();
    void run_task();
    void* m_cc;
    u8 _padD0[0x8];
    void* m_d8;
    u8 _padDC[0x8];
    u32 m_e4;
    u32 m_e8;
    u8 _padEC[0x4];
    u32 m_f0;
    u32 m_f4;
    u8 unk_DC[0x1C];
    static f32 get_target_pos_y();
    void emit_hit_effect(void *arg1);
};

typedef char TBoss7PhotonBullet_size[sizeof(TBoss7PhotonBullet) == 0xF8 ? 1 : -1];
#endif
