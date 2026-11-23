#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTBASE_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTBASE_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

struct TODoorFourLightBase : public TODoorBase {
    TODoorFourLightBase(TObject *parent, void *set_data);
    virtual ~TODoorFourLightBase();
    // Texture lists the derived doors return for draw_node_tree: vfunc_22 for nodes flagged 0x100000
    // (light lit by render_lights), vfunc_21 otherwise (inferred: lit/unlit light textures).
    virtual s32 vfunc_21() = 0;
    virtual s32 vfunc_22() = 0;
    virtual s32 init_door_switch_binding();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    virtual void render();
    NJS_OBJECT *model;
    // The four lights' nodes, then their second faces (render_lights).
    NJS_OBJECT *light_nodes[8];
    s32 light_count; // set_params[1], clamped to 0..4

    void clamp_light_index();
    void render_lights();
    void draw_node_tree(u8 *arg1);
};

LAYOUT_ASSERT(TODoorFourLightBase_size, sizeof(TODoorFourLightBase) == 0xFC);
#endif
