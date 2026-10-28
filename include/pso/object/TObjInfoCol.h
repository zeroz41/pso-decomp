#ifndef PSO_OBJECT_TOBJINFOCOL_H
#define PSO_OBJECT_TOBJINFOCOL_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/object/TObjMotion.h"

class TObjInfoCol : public TObjCollidable {
public:
    virtual ~TObjInfoCol();
    f32 interaction_radius;

    s32 is_target_in_range(f32 radius_squared);
    void run_task();
    void bswap_6x78();
};

#include <stddef.h>
typedef char TObjInfoColRadiusOffset[
    offsetof(TObjInfoCol, interaction_radius) == 0xAC ? 1 : -1];

typedef char TObjInfoCol_size[sizeof(TObjInfoCol) == 0xB0 ? 1 : -1];

extern "C" {
u8 *TObjInfoCol__ct(u8 *info_col, s32 arg1, s32 arg2);
void *__dt__11TObjInfoColFv(void *arg0, s16 arg1);
}

#endif
