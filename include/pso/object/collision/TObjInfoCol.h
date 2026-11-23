#ifndef PSO_OBJECT_COLLISION_TOBJINFOCOL_H
#define PSO_OBJECT_COLLISION_TOBJINFOCOL_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/object/base/TObjMotion.h"

class TObjInfoCol : public TObjCollidable {
public:
    TObjInfoCol(saddr, saddr);
    virtual ~TObjInfoCol();
    f32 interaction_radius;

    s32 is_target_in_range(f32 radius_squared);
    void run_task();
    void bswap_6x78();
    static void *create(void *set_data);
};

#include <stddef.h>
LAYOUT_ASSERT(TObjInfoColRadiusOffset, offsetof(TObjInfoCol, interaction_radius) == 0xAC);

LAYOUT_ASSERT(TObjInfoCol_size, sizeof(TObjInfoCol) == 0xB0);

extern "C" {
void *__dt__11TObjInfoColFv(void *arg0, s16 arg1);
}

#endif
