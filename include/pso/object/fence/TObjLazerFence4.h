#ifndef PSO_OBJECT_FENCE_TOBJLAZERFENCE4_H
#define PSO_OBJECT_FENCE_TOBJLAZERFENCE4_H

#include "types.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_OBJECT;

struct TObjLazerFence4 : public TObjCollidable {
    TObjLazerFence4(TObject *parent, void *set_data);
    virtual ~TObjLazerFence4();
    void wait_for_switch();
    virtual s32 update_object_view_visibility(f32, f32);
    u32 state;            // 0 closed (beam drawn, blocking), 1 open (switch set)
    f32 animation_frame;  // the beam motion's frame
    u8 _padB4[0x4];
    u16 color_slot;       // beam colour, from scale.x (0-3)
    u16 id;               // set_params[0]: the floor switch that opens it
    virtual void run_task();
    void init_models();
    void draw();
    void draw_model();
    void reset_if_door_closed();
    virtual void render();
    static void *create(void *set_data);
    NJS_OBJECT *beam_model;  // drawn posed by motion
    NJS_OBJECT *post_model;  // the posts, drawn alone when open
    NJS_MOTION *motion;
    void *beam_nodes[12];    // the beam model's pieces, recoloured by color_slot
};

LAYOUT_ASSERT(TObjLazerFence4_size, sizeof(TObjLazerFence4) == 0xF8);
#endif
