#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMOF_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMOF_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjDFDemoF : public TObjBase {
    TObjDFDemoF(TObject *parent);
    virtual ~TObjDFDemoF();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_13() = 0;
    u32 m_90;
    static void *create(void *arg0);
    u8 unk_94[0x24];
    f32 m_b8;
};

LAYOUT_ASSERT(TObjDFDemoF_size, sizeof(TObjDFDemoF) == 0xBC);
#endif
