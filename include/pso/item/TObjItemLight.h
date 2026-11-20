#ifndef PSO_ITEM_TOBJITEMLIGHT_H
#define PSO_ITEM_TOBJITEMLIGHT_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjItemLight : public TObjBase {
    TObjItemLight(TObject *parent, s32 arg2);
    virtual ~TObjItemLight();
    void run_task();
    u8 unk_90[0x4];
    s32 m_94;
};

typedef char TObjItemLight_size[sizeof(TObjItemLight) == 0x98 ? 1 : -1];

extern "C" {
void *__dt__13TObjItemLightFv(void *arg0, s16 arg1);
}

#endif
