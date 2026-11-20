#ifndef PSO_OBJECT_TOBJGBADVANCE_H
#define PSO_OBJECT_TOBJGBADVANCE_H

#include "types.h"
#include "pso/object/TObjMesBase.h"

struct TObjGbAdvance : public TObjMesBase {
    TObjGbAdvance(TObject *parent, ObjectSetData *placement);
    virtual ~TObjGbAdvance();
    virtual void vfunc_14();
    static void free_shared_data();
    static void load_resource_instance();
    virtual void render();
};

typedef char TObjGbAdvance_size[sizeof(TObjGbAdvance) == 0xBC ? 1 : -1];
extern "C" void *TObjGbAdvance__create(void *placement);

#endif
