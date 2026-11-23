#ifndef PSO_OBJECT_COLLISION_TOBJFOGCOLLISION_H
#define PSO_OBJECT_COLLISION_TOBJFOGCOLLISION_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjFogCollision : public TObjBase {
    TObjFogCollision(TObject *parent, void *set);
    virtual ~TObjFogCollision();
    virtual void vfunc_13(s32);
    virtual void vfunc_14();
    virtual void draw_volume();
    virtual void render();
    u32 m_90;
    u32 m_94;
    virtual void run_task();
    s32 check_collision(u16 client);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjFogCollision_size, sizeof(TObjFogCollision) == 0x98);
#endif
