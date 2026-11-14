#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEYQUICK_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEYQUICK_H

#include "types.h"
#include "pso/unk/TUnk_804B2578.h"

class TOHangceilingCave01KeyQuick : public TUnk_804B2578 {
public:
    TOHangceilingCave01KeyQuick(TObject *parent, void *set_data);
    virtual ~TOHangceilingCave01KeyQuick();
    virtual void vfunc_79();
    virtual void vfunc_80();
};

typedef char TOHangceilingCave01KeyQuick_size[sizeof(TOHangceilingCave01KeyQuick) == 0x360 ? 1 : -1];
#endif
