#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01NORMAL_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01NORMAL_H

#include "types.h"
#include "pso/unk/TUnk_804B2578.h"

struct TOHangceilingCave01Normal : public TUnk_804B2578 {
    virtual ~TOHangceilingCave01Normal();
    virtual void vfunc_80();
    virtual void vfunc_79();
    u8 unk_35C[0x4];
};

typedef char TOHangceilingCave01Normal_size[sizeof(TOHangceilingCave01Normal) == 0x360 ? 1 : -1];
#endif
