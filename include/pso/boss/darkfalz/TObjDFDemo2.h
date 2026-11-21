#ifndef PSO_BOSS_DARKFALZ_TOBJDFDEMO2_H
#define PSO_BOSS_DARKFALZ_TOBJDFDEMO2_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjDFDemo2 : public TObjBase {
    TObjDFDemo2(TObject *parent, void *arg2, void *arg3, void *arg4);
    virtual ~TObjDFDemo2();
    virtual void run_task();
    virtual void render();
    u8 unk_90[0x18];
    u32 m_a8;
    void* m_ac;
    u8 _padB0[0x8];
    u32 m_b8;
    u32 m_bc;
    u8 unk_C0[0x4];
};

typedef char TObjDFDemo2_size[sizeof(TObjDFDemo2) == 0xC4 ? 1 : -1];
#endif
