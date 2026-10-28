#ifndef PSO_MISC_TOMINEDISP_H
#define PSO_MISC_TOMINEDISP_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TOMineDisp : public TObjBase {
    virtual ~TOMineDisp();
    virtual void render();
    virtual void run_task();
    u32 m_90;
    u8 unk_94[0x4];
    f32 m_98;
    u8 unk_9C[0x4];
    f32 m_a0;
    u32 m_a4;
    u16 m_a8;
    u8 unk_AA[0x2];
};

typedef char TOMineDisp_size[sizeof(TOMineDisp) == 0xAC ? 1 : -1];
#endif
