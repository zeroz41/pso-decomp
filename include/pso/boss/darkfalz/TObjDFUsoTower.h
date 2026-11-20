#ifndef PSO_BOSS_DARKFALZ_TOBJDFUSOTOWER_H
#define PSO_BOSS_DARKFALZ_TOBJDFUSOTOWER_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjDFUsoTower : public TObjBase {
    TObjDFUsoTower(saddr _w1);
    virtual ~TObjDFUsoTower();
    u32 m_90;
    static void *create(void *arg0);
    virtual void render();
    virtual void run_task();
    u8 unk_94[0x4];
    void sub_8004D9A0(s32 v);
};

LAYOUT_ASSERT(TObjDFUsoTower_size, sizeof(TObjDFUsoTower) == 0x98);

#endif
