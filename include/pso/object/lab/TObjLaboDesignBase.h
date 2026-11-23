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
    void *create_instance(void *);
    void *alloc_and_construct(void *);
    void render_model();
    void draw_node_tree(NJS_OBJECT *node);
    BmlResource *model_resource;
    s32 state;
    f32 xB4;
    f32 xB8;
    TObjMapCsn *map_csn;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjLaboDesignBase_size, sizeof(TObjLaboDesignBase) == 0xC0);
#endif
