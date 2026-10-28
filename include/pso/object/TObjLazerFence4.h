#ifndef PSO_OBJECT_TOBJLAZERFENCE4_H
#define PSO_OBJECT_TOBJLAZERFENCE4_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLazerFence4 : public TObjCollidable {
    virtual ~TObjLazerFence4();
    void sub_801933C8();
    virtual s32 update_object_view_visibility(f32, f32);
    u32 m_ac;
    u8 _padB0[0x8];
    u16 m_b8;
    u16 m_ba;
    virtual void run_task();
    void init_models();
    void draw();
    void draw_model();
    void reset_if_door_closed();
    virtual void render();
    void *create();
    u8 unk_BC[0x4];
    void * m_c0;
    u8 unk_C4[0x34];
};

typedef char TObjLazerFence4_size[sizeof(TObjLazerFence4) == 0xF8 ? 1 : -1];
#endif
