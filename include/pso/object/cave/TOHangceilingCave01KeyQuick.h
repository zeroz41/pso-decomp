#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEYQUICK_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEYQUICK_H

#include "types.h"
#include "pso/unk/TUnk_804B2578.h"

struct TOHangceilingCave01KeyQuick : public TUnk_804B2578 {
    virtual ~TOHangceilingCave01KeyQuick();
    virtual void vfunc_80();
    virtual void vfunc_79();
    u8 unk_35C[0x4];
    void *destroy_hanging_object(s16 arg1);
    u8 *init_base(s32 arg1, s32 arg2);
};

typedef char TOHangceilingCave01KeyQuick_size[sizeof(TOHangceilingCave01KeyQuick) == 0x360 ? 1 : -1];
#endif
