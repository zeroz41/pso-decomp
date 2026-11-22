#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERIDO_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERIDO_H

#include "types.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/render/RenderFadeState.h"

struct TObjContainerIdo : public TUnk_804B97C0 {
    TObjContainerIdo(TObject *parent, void *set);
    virtual ~TObjContainerIdo();
    virtual s32 update_object_view_visibility(f32 far_depth, f32 radius);
    virtual void render();
    virtual void run_task();
    static void free_resources();
    static void load_resources();
    static void *create(void *set);
    Vec m_b4;              // a copy of the set position; nothing here reads it
    // The set position: the rail is drawn there and the lift's travel is measured from it (name inferred).
    Vec home_position;
    s32 switch_ids[4];     // the floor switches that move it: set_params[0] and the ids after it
    s32 switch_count;      // set_params[1], clamped to 1..4
    // Bits 0-3 which switches are on; 0x01000000 stop sound played, 0x02000000 lowering, 0x04000000 moving
    // this frame, 0x08000000 no dust (set_params[2]).
    u32 state;
    f32 target_distance;   // step_distance for every switch that is on
    f32 step_distance;     // scale.x / switch_count
    f32 speed;             // scale.y, distance moved per frame
    RenderFadeState fade;
};

LAYOUT_ASSERT(TObjContainerIdo_size, sizeof(TObjContainerIdo) == 0x10C);
#endif
