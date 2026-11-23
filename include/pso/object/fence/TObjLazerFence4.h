#ifndef PSO_OBJECT_FENCE_TOBJLAZERFENCE4_H
#define PSO_OBJECT_FENCE_TOBJLAZERFENCE4_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_OBJECT;

struct TObjLazerFence4 : public TObjCollidable {
    TObjLazerFence4(TObject *parent, void *arg2);
    virtual ~TObjLazerFence4();
    void sub_801933C8();
    virtual s32 update_object_view_visibility(f32, f32);
    u32 m_ac;
    u8 _padB0[0x8];
    u16 m_b8;
    u16 id;
    virtual void run_task();
    void init_models();
    void draw();
    void draw_model();
    void reset_if_door_closed();
    virtual void render();
    static void *create(void *set_data);
    NJS_OBJECT *m_bc;  // drawn posed by the motion at 0xC4
    void * m_c0;
    u8 unk_C4[0x34];
};

LAYOUT_ASSERT(TObjLazerFence4_size, sizeof(TObjLazerFence4) == 0xF8);
#endif
