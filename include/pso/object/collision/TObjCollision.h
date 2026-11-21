#ifndef PSO_OBJECT_COLLISION_TOBJCOLLISION_H
#define PSO_OBJECT_COLLISION_TOBJCOLLISION_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjCollision : public TObjCollidable {
    TObjCollision(TObject *parent, void *arg2);
    virtual ~TObjCollision();
    void* m_ac;
    u8 unk_B0[0x4];
    f32 m_b4;
    u8 unk_B8[0x4];
    f32 m_bc;
    u32 m_c0;
    u32 m_c4;
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
    u8 unk_C8[0x10];
};

LAYOUT_ASSERT(TObjCollision_size, sizeof(TObjCollision) == 0xD8);
#endif
