#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTBASE_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTBASE_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

// The node indices a four-light door looks up with find_object_node to fill
// light_nodes.
struct FourLightNodeTable {
    s32 node[8];
};

struct TODoorFourLightBase : public TODoorBase {
    TODoorFourLightBase(TObject *parent, void *set_data);
    virtual ~TODoorFourLightBase();
    // The texture lists draw_node_tree binds: get_lit_textures (the door's
    // green GVM) for nodes render_lights flags 0x100000, get_unlit_textures
    // for the rest.
    virtual s32 get_unlit_textures() = 0;
    virtual s32 get_lit_textures() = 0;
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
