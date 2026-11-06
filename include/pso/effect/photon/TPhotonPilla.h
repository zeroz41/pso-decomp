#ifndef PSO_EFFECT_PHOTON_TPHOTONPILLA_H
#define PSO_EFFECT_PHOTON_TPHOTONPILLA_H
#include "types.h"
#include "pso/unk/TUnk_804C3248.h"

class TPhotonPilla : public TUnk_804C3248 {
public:
    virtual ~TPhotonPilla();
    void spawn_laser();
    void apply_photon_blast_effects();
    void sub_801ADC7C();
    virtual void render();
    virtual void run_task();
    u8 unk_158[0x24];
    u16 m_17c;
    u8 unk_17E[0x2];
    float m_180;
    u8 unk_184[0x4];
    float m_188;
    u8 unk_18C[0x4];
    u8 * m_190;
    u8 unk_194[0x4];
    s16 m_198;
    u8 unk_19A[0x2];
    s32 m_19c;
    u8 unk_1A0[0x4];
    s32 m_1a4;
    u8 unk_1A8[0x4];
};
typedef char TPhotonPilla_size[sizeof(TPhotonPilla) == 0x1AC ? 1 : -1];

extern "C" {
void *destroy__12TPhotonPillaFPvs(void *arg0, s16 arg1);
}

#endif
