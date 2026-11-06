#ifndef PSO_EFFECT_PHOTON_TPHOTONGOLLA_H
#define PSO_EFFECT_PHOTON_TPHOTONGOLLA_H
#include "types.h"
#include "pso/unk/TUnk_804C3248.h"

class TPhotonGolla : public TUnk_804C3248 {
public:
    virtual ~TPhotonGolla();
    void sub_801AB688();
    virtual void render();
    virtual void run_task();
    u8 unk_158[0x4];
    float m_15c;
    u8 unk_160[0x4];
    float m_164;
    u8 unk_168[0x34];
    s32 m_19c;
    u8 unk_1A0[0x4];
    u8 * m_1a4;
    u8 unk_1A8[0x10];
    s16 m_1b8;
    u8 unk_1BA[0x2];
    s32 m_1bc;
    u8 unk_1C0[0x4];
    s32 m_1c4;
    u8 unk_1C8[0x4];
public:
    static s32 spawn_concentrate(void *arg0);
    static void collect_hit_targets(void *arg0);
};
typedef char TPhotonGolla_size[sizeof(TPhotonGolla) == 0x1CC ? 1 : -1];

extern "C" {
void *destroy__12TPhotonGollaFPvs(void *arg0, s16 arg1);
}

#endif
