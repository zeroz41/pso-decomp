#ifndef PSO_OBJECT_TOBJGBADVANCE_H
#define PSO_OBJECT_TOBJGBADVANCE_H

#include "types.h"
#include "pso/object/TObjMesBase.h"

struct TObjGbAdvance : public TObjMesBase {
    virtual ~TObjGbAdvance();
    virtual void vfunc_14();
    static void free_shared_data();
    static void load_resource_instance();
    virtual void render();
};

LAYOUT_ASSERT(TObjGbAdvance_size, sizeof(TObjGbAdvance) == 0xBC);
#endif
