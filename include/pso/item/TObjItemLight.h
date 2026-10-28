#ifndef PSO_ITEM_TOBJITEMLIGHT_H
#define PSO_ITEM_TOBJITEMLIGHT_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjItemLight : public TObjBase {
    virtual ~TObjItemLight();
    void run_task();
    u8 unk_90[0x4];
    s32 m_94;
};

typedef char TObjItemLight_size[sizeof(TObjItemLight) == 0x98 ? 1 : -1];

extern "C" {
u8 *TObjItemLight__ct(TObjItemLight *arg0, s32 arg1, s32 arg2);
void *__dt__13TObjItemLightFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjItemLight.cpp ---
extern "C" {
u8 *TObjItemLight__ct(TObjItemLight *item_light, s32 arg1, s32 arg2);
void *__dt__13TObjItemLightFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
