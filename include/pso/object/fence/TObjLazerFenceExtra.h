#ifndef PSO_OBJECT_FENCE_TOBJLAZERFENCEEXTRA_H
#define PSO_OBJECT_FENCE_TOBJLAZERFENCEEXTRA_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct AnimationMotion;
struct NJS_OBJECT;

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
    NJS_OBJECT *base_model;  // the fence size's "_moto" model, drawn without motion
    NJS_OBJECT *beam_model;  // the model beam_motion animates
    AnimationMotion *beam_motion;
    void *beam_part_models[4];  // models of the beam's child nodes, retextured for scale_level
    s32 size_valid;  // 1 when set_params[2] is a valid fence size (0 or 1); 0 hides it
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjLazerFenceExtra_size, sizeof(TObjLazerFenceExtra) == 0xDC);

#endif
