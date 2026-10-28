#ifndef PSO_OBJECT_TOBJCOLLISION_H
#define PSO_OBJECT_TOBJCOLLISION_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjCollision : public TObjCollidable {
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

typedef char TObjCollision_size[sizeof(TObjCollision) == 0xD8 ? 1 : -1];
#endif
