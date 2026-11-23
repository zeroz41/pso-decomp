#ifndef PSO_ITEM_TOBJITEMLIGHT_H
#define PSO_ITEM_TOBJITEMLIGHT_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjItemLight : public TObjBase {
    TObjItemLight(TObject *parent, saddr set_data);
    virtual ~TObjItemLight();
    void run_task();
    u8 unk_90[0x4];
    s32 m_94;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjItemLight_size, sizeof(TObjItemLight) == 0x98);


#endif
