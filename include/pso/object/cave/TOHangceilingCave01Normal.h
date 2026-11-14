#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01NORMAL_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01NORMAL_H

#include "types.h"
#include "pso/unk/TUnk_804B2578.h"

class TOHangceilingCave01Normal : public TUnk_804B2578 {
public:
    TOHangceilingCave01Normal(TObject *parent, void *set_data);
    virtual ~TOHangceilingCave01Normal();
    virtual void vfunc_79();
    virtual void vfunc_80();
};

typedef char TOHangceilingCave01Normal_size[sizeof(TOHangceilingCave01Normal) == 0x360 ? 1 : -1];
#endif
