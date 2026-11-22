#ifndef PSO_ENEMY_MORFOS_TOBJENEMORFOSARM_H
#define PSO_ENEMY_MORFOS_TOBJENEMORFOSARM_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEneMorfosArm : public TObjMotion {
    TObjEneMorfosArm(TObject *parent, void *owner);
    virtual ~TObjEneMorfosArm();
    uaddr m_fc;
    u16 m_100;
    static void *create(void *parent, void *owner);
    static void init_global();
    virtual void render();
    virtual void run_task();
    u8 unk_102[0x2];
};

LAYOUT_ASSERT(TObjEneMorfosArm_size, sizeof(TObjEneMorfosArm) == 0x104);

extern "C" {
void TObjEneMorfosArm__sub_8033542C(void);
}

#endif
