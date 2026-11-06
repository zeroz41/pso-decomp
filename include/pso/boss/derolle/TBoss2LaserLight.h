#ifndef PSO_BOSS_DEROLLE_TBOSS2LASERLIGHT_H
#define PSO_BOSS_DEROLLE_TBOSS2LASERLIGHT_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss2LaserLight : public TObject {
    virtual ~TBoss2LaserLight();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    void* m_28;
    u8 _pad2C[0xC];
    void* m_38;
    u8 _pad3C[0x4];
    u32 m_40;
    virtual void render();
    virtual void run_task();
};

typedef char TBoss2LaserLight_size[sizeof(TBoss2LaserLight) == 0x44 ? 1 : -1];

extern "C" {
void TBoss2LaserLight__sub_80037474(void *p);
void TBoss2LaserLight__sub_80037480(void *p);
}

// --- C functions defined in TBoss2LaserLight.cpp ---
extern "C" {
TBoss2LaserLight *TBoss2LaserLight__ct(TBoss2LaserLight *self, TObject *parent, u32 arg2);
void TBoss2LaserLight__sub_80037474(void *p);
void TBoss2LaserLight__sub_80037480(void *p);
}
// --- end of C functions

#endif
