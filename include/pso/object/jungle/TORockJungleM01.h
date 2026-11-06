#ifndef PSO_OBJECT_JUNGLE_TOROCKJUNGLEM01_H
#define PSO_OBJECT_JUNGLE_TOROCKJUNGLEM01_H

#include "types.h"
#include "pso/object/cave/TORockCaveBrakable.h"

struct TORockJungleM01 : public TORockCaveBrakable {
    virtual ~TORockJungleM01();
    virtual void vfunc_16();
    virtual void vfunc_15();
    virtual void vfunc_14();
    virtual void vfunc_18();
    void* m_bc;
    u8 _padC0[0x10];
    u32 m_d0;
    u8 _padD4[0x4];
    u32 m_d8;
    u32 m_dc;
    virtual void run_task();
    static void *create(void *arg0);
};

typedef char TORockJungleM01_size[sizeof(TORockJungleM01) == 0xE0 ? 1 : -1];

extern "C" {
u8 *TORockJungleM01__ct(u8 *arg0, s32 arg1);
}

#endif
