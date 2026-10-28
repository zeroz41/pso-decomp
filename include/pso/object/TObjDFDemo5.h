#ifndef PSO_OBJECT_TOBJDFDEMO5_H
#define PSO_OBJECT_TOBJDFDEMO5_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjDFDemo5 : public TObjBase {
    virtual ~TObjDFDemo5();
    virtual void run_task();
    void update_particle_emitters();
    u8 unk_90[0x4];
    u32 m_94;
    u8 unk_98[0x30];
    u32 m_c8;
    u32 m_cc;
    u32 m_d0;
    void* m_d4;
    u8 _padD8[0x8];
    u32 m_e0;
    u32 m_e4;
    u8 _padE8[0x4];
    u32 m_ec;
    void* m_f0;
    u8 _padF4[0x14];
    u32 m_108;
    void* m_10c;
    static void *create(void *arg0, void *arg1, void *arg2);
    u8 unk_110[0x8];
};

typedef char TObjDFDemo5_size[sizeof(TObjDFDemo5) == 0x118 ? 1 : -1];
#endif
