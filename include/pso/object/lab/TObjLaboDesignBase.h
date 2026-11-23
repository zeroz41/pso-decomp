#ifndef PSO_OBJECT_LAB_TOBJLABODESIGNBASE_H
#define PSO_OBJECT_LAB_TOBJLABODESIGNBASE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct BmlResource;
struct TObjMapCsn;

struct TObjLaboDesignBase : public TObjCollidable {
    TObjLaboDesignBase(TObject *parent, void *set_data, s32 state);
    virtual ~TObjLaboDesignBase();
    virtual void run_task();
    virtual void render();
    virtual s32 update_object_view_visibility(f32, f32);
    void render_model();
    void draw_node_tree(NJS_OBJECT *node);
    BmlResource *model_resource;
    s32 state;
    f32 xB4;
    f32 xB8;
    TObjMapCsn *map_csn;
    // create with state 0, create_stateN with state N: the design the model
    // and collision come from.
    static void *create(void *set_data);
    static void *create_state1(void *set_data);
    static void *create_state2(void *set_data);
    static void *create_state3(void *set_data);
    static void *create_state4(void *set_data);
    static void *create_state5(void *set_data);
};

LAYOUT_ASSERT(TObjLaboDesignBase_size, sizeof(TObjLaboDesignBase) == 0xC0);
#endif
