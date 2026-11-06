#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEY_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEY_H

#include "types.h"
#include "pso/unk/TUnk_804B2578.h"

struct TOHangceilingCave01Key : public TUnk_804B2578 {
    virtual ~TOHangceilingCave01Key();
    virtual void vfunc_80();
    virtual void vfunc_79();
    u8 unk_35C[0x4];
};

typedef char TOHangceilingCave01Key_size[sizeof(TOHangceilingCave01Key) == 0x360 ? 1 : -1];
#endif
