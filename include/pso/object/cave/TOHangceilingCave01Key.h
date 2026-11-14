#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEY_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEY_H

#include "types.h"
#include "pso/unk/TUnk_804B2578.h"

class TOHangceilingCave01Key : public TUnk_804B2578 {
public:
    TOHangceilingCave01Key(TObject *parent, void *set_data);
    virtual ~TOHangceilingCave01Key();
    virtual void vfunc_79();
    virtual void vfunc_80();
};

typedef char TOHangceilingCave01Key_size[sizeof(TOHangceilingCave01Key) == 0x360 ? 1 : -1];
#endif
