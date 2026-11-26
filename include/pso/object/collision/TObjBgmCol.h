#ifndef PSO_OBJECT_COLLISION_TOBJBGMCOL_H
#define PSO_OBJECT_COLLISION_TOBJBGMCOL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjBgmCol : public TObjBase {
    TObjBgmCol(TObject *parent, void *set_data);
    virtual ~TObjBgmCol();
    u32 outside;  // 1 while the local player is outside the zone
    u8 unk_94[0x4];
    f32 radius;
    s32 category;
    s32 check();
    virtual void run_task();
    s32 is_within_distance(f32 distance_sq);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjBgmCol_size, sizeof(TObjBgmCol) == 0xA0);
#endif
