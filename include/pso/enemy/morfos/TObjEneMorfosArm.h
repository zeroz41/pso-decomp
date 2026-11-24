#ifndef PSO_ENEMY_MORFOS_TOBJENEMORFOSARM_H
#define PSO_ENEMY_MORFOS_TOBJENEMORFOSARM_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEneMorfos;

struct TObjEneMorfosArm : public TObjMotion {
    TObjEneMorfosArm(TObject *parent, TObjEneMorfos *owner);
    virtual ~TObjEneMorfosArm();
    TObjEneMorfos *morfos;  // the owner it follows (get_arm_point, get_rotation_y)
    u16 morfos_id;          // the owner's entity id
    static TObjEneMorfosArm *create(TObject *parent, TObjEneMorfos *owner);
    static void init_global();
    static void free_global();  // empty; unload_static_data's counterpart of init_global
    virtual void render();
    virtual void run_task();
    u8 unk_102[0x2];
};

LAYOUT_ASSERT(TObjEneMorfosArm_owner, offsetof(TObjEneMorfosArm, morfos) == 0xFC);
LAYOUT_ASSERT(TObjEneMorfosArm_size, sizeof(TObjEneMorfosArm) == 0x104);

#endif
