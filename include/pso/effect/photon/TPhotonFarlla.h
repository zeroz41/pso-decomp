#ifndef PSO_EFFECT_PHOTON_TPHOTONFARLLA_H
#define PSO_EFFECT_PHOTON_TPHOTONFARLLA_H
#include "types.h"
#include "pso/unk/TUnk_804C3248.h"

class TPhotonFarlla : public TUnk_804C3248 {
public:
    virtual ~TPhotonFarlla();
    void update_all_slots();
    void sub_801AAE6C();
    virtual void render();
    virtual void run_task();
    u8 unk_158[0x24];
    u16 m_17c;
    u8 unk_17E[0x2];
    u8 * m_180;
    f32 m_184;
    u8 unk_188[0x4];
    float m_18c;
    u8 unk_190[0x4];
    s16 m_194;
    u8 unk_196[0x2];
    s32 m_198;
    u8 unk_19C[0x4];
    s32 m_1a0;
    u8 unk_1A4[0x4];
};
typedef char TPhotonFarlla_size[sizeof(TPhotonFarlla) == 0x1A8 ? 1 : -1];

extern "C" {
void *destroy__13TPhotonFarllaFPvs(void *arg0, s16 arg1);
}

#endif
