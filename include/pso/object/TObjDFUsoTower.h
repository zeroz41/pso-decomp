#ifndef PSO_OBJECT_TOBJDFUSOTOWER_H
#define PSO_OBJECT_TOBJDFUSOTOWER_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjDFUsoTower : public TObjBase {
    virtual ~TObjDFUsoTower();
    u32 m_90;
    static void *create(void *arg0);
    virtual void render();
    virtual void run_task();
    u8 unk_94[0x4];
};

typedef char TObjDFUsoTower_size[sizeof(TObjDFUsoTower) == 0x98 ? 1 : -1];

extern "C" {
u8 *TObjDFUsoTower__ct(u8 *arg0, s32 _w1);
void *__dt__14TObjDFUsoTowerFv(void *arg0, s16 arg1);
}

#endif
