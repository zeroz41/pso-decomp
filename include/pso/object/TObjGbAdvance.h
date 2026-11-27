#ifndef PSO_OBJECT_TOBJGBADVANCE_H
#define PSO_OBJECT_TOBJGBADVANCE_H

#include "types.h"
#include "pso/object/TObjMesBase.h"

struct TObjGbAdvance : public TObjMesBase {
    TObjGbAdvance(TObject *parent, ObjectSetData *placement);
    virtual ~TObjGbAdvance();
    virtual void update_idle();
    static void free_shared_data();
    static void load_resource_instance();
    virtual void render();
    static void *create(ObjectSetData *set_data);
    static BmlResource *resource;  // the shared model archive
};

LAYOUT_ASSERT(TObjGbAdvance_size, sizeof(TObjGbAdvance) == 0xBC);

#endif
