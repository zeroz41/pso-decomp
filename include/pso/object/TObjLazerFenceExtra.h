#ifndef PSO_OBJECT_TOBJLAZERFENCEEXTRA_H
#define PSO_OBJECT_TOBJLAZERFENCEEXTRA_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLazerFenceExtra : public TObjCollidable {
    virtual ~TObjLazerFenceExtra();
    void update_wait_switch();
    void render_lazer_fence_model();
    void draw_lazer_fence_extra_model();
    void init_models();
    void render();
    void run_task();
    u8 unk_AC[0x8];
    s32 m_b4;
    u8 unk_B8[0x4];
    u32 m_d8;
    u8 unk_C0[0x4];
    s32 m_c4;
    u8 unk_C8[0x14];
};

typedef char TObjLazerFenceExtra_size[sizeof(TObjLazerFenceExtra) == 0xDC ? 1 : -1];
#endif
