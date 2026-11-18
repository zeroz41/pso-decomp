#ifndef PSO_OBJECT_LAB_TOBJLABODESIGNBASE_H
#define PSO_OBJECT_LAB_TOBJLABODESIGNBASE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjLaboDesignBase : public TObjCollidable {
    virtual ~TObjLaboDesignBase();
    virtual void run_task();
    virtual void render();
    virtual s32 update_object_view_visibility(f32, f32);
    void *create_instance(void *);
    void *alloc_and_construct(void *);
    void render(void *);
    u8 unk_AC[0x4];
    s32 state;
    f32 xB4;
    f32 xB8;
    void *map_csn;
};

typedef char TObjLaboDesignBase_size[sizeof(TObjLaboDesignBase) == 0xC0 ? 1 : -1];
#endif
