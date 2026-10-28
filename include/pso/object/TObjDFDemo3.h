#ifndef PSO_OBJECT_TOBJDFDEMO3_H
#define PSO_OBJECT_TOBJDFDEMO3_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjDFDemo3 : public TObjBase {
    virtual ~TObjDFDemo3();
    virtual void render();
    virtual void run_task();
    u32 m_90;
    u32 m_94;
    u32 m_98;
    u32 m_9c;
    u32 m_a0;
    u32 m_a4;
    u32 m_a8;
    u32 m_ac;
    u32 m_b0;
    u8 _padB4[0x4];
    u32 m_b8;
    void* m_bc;
    static void *create(void *arg0, void *arg1, void *arg2);
    u8 unk_C0[0x8];
};

typedef char TObjDFDemo3_size[sizeof(TObjDFDemo3) == 0xC8 ? 1 : -1];
#endif
