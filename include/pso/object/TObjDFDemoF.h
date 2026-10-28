#ifndef PSO_OBJECT_TOBJDFDEMOF_H
#define PSO_OBJECT_TOBJDFDEMOF_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjDFDemoF : public TObjBase {
    virtual ~TObjDFDemoF();
    virtual void render();
    virtual void run_task();
    u32 m_90;
    static void *create(void *arg0);
    u8 unk_94[0x24];
    f32 m_b8;
};

typedef char TObjDFDemoF_size[sizeof(TObjDFDemoF) == 0xBC ? 1 : -1];
#endif
