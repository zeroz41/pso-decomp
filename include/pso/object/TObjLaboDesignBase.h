#ifndef PSO_OBJECT_TOBJLABODESIGNBASE_H
#define PSO_OBJECT_TOBJLABODESIGNBASE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLaboDesignBase : public TObjCollidable {
    virtual ~TObjLaboDesignBase();
    void *create_instance(void *);
    void *alloc_and_construct(void *);
    void render();
    void run_task();
    u8 unk_AC[0x14];
};

typedef char TObjLaboDesignBase_size[sizeof(TObjLaboDesignBase) == 0xC0 ? 1 : -1];
#endif
