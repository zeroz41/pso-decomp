#ifndef PSO_OBJECT_JUNGLE_TOROCKJUNGLEL01_H
#define PSO_OBJECT_JUNGLE_TOROCKJUNGLEL01_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockJungleL01 : public TORockCave {
    virtual ~TORockJungleL01();
    virtual void vfunc_15();
    virtual void vfunc_14();
    virtual void run_task();
    void* m_b4;
    u8 unk_B8[0x18];
    s32 m_d0;
    u32 m_d4;
    void *destroy(s16 arg1);
};

typedef char TORockJungleL01_size[sizeof(TORockJungleL01) == 0xD8 ? 1 : -1];

extern "C" {
void *TORockJungleL01__create(void *arg0);
}

#endif
