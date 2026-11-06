#ifndef PSO_OBJECT_TOBJLAZERFENCENORM_H
#define PSO_OBJECT_TOBJLAZERFENCENORM_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLazerFenceNorm : public TObjCollidable {
    TObjLazerFenceNorm(TObject *parent, void *set_data);
    virtual ~TObjLazerFenceNorm();
    void update_closed();
    void draw_animated_beam();
    u32 scale_level;  // scale.x clamped to 0..3
    u16 switch_id;  // the floor switch that opens the fence (set_params[0])
    u8 _padB2[0x2];
    u32 m_b4;
    virtual void run_task();
    static void free_resources();
    void draw_model();
    virtual void render();
    void reset_by_door();
    f32 frame;  // the beam motion's frame
    void * m_bc;
    u8 unk_C0[0x4];
    s32 m_c4;
    u8 unk_C8[0x10];
    void select_models();
};

typedef char TObjLazerFenceNorm_size[sizeof(TObjLazerFenceNorm) == 0xD8 ? 1 : -1];

extern "C" {
void *TObjLazerFenceNorm__create(void *set_data);
}

// Loads the fence models (episode 2 areas get fe_obj_lazer2_2); undone by TObjLazerFenceNorm::free_resources.
void load_lazer_fence_norm_resources(void);

#endif
