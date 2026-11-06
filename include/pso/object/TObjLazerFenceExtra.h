#ifndef PSO_OBJECT_TOBJLAZERFENCEEXTRA_H
#define PSO_OBJECT_TOBJLAZERFENCEEXTRA_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLazerFenceExtra : public TObjCollidable {
    TObjLazerFenceExtra(TObject *parent, void *set_data);
    virtual ~TObjLazerFenceExtra();
    void update_wait_switch();
    void reset_by_door();
    void render_lazer_fence_model();
    void draw_lazer_fence_extra_model();
    void init_models();
    void render();
    void run_task();
    s32 scale_level;  // scale.x clamped to 0..3
    s16 switch_id;  // the floor switch that opens the fence (set_params[0])
    u8 _padB2[0x2];
    s32 m_b4;
    f32 frame;  // the beam motion's frame
    u32 m_bc;
    u8 unk_C0[0x4];
    s32 m_c4;
    u8 unk_C8[0x10];
    s32 size_valid;  // 1 when set_params[2] is a valid fence size (0 or 1); 0 hides it
};

typedef char TObjLazerFenceExtra_size[sizeof(TObjLazerFenceExtra) == 0xDC ? 1 : -1];

extern "C" {
void *TObjLazerFenceExtra__create(void *set_data);
}
#endif
