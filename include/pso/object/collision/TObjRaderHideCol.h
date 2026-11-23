#ifndef PSO_OBJECT_COLLISION_TOBJRADERHIDECOL_H
#define PSO_OBJECT_COLLISION_TOBJRADERHIDECOL_H

#include <stddef.h>
#include "pso/object/base/TObjMotion.h"

struct TObjRaderHideCol : public TObjBase {
    TObjRaderHideCol(TObject *parent, void *set_data);
    virtual ~TObjRaderHideCol();
    virtual void render();
    virtual void run_task();

    f32 hide_radius;
    u32 radar_hidden;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjRaderHideCol_radius_offset, offsetof(TObjRaderHideCol, hide_radius) == 0x90);
LAYOUT_ASSERT(TObjRaderHideCol_hidden_offset, offsetof(TObjRaderHideCol, radar_hidden) == 0x94);
LAYOUT_ASSERT(TObjRaderHideCol_size, sizeof(TObjRaderHideCol) == 0x98);

#endif
