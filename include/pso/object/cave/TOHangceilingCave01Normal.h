#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01NORMAL_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01NORMAL_H

#include "types.h"
#include "pso/unk/TOHangceilingCaveBase.h"

class TOHangceilingCave01Normal : public TOHangceilingCaveBase {
public:
    TOHangceilingCave01Normal(TObject *parent, void *set_data);
    virtual ~TOHangceilingCave01Normal();
    virtual void begin_wait();
    virtual void update_state();
};

LAYOUT_ASSERT(TOHangceilingCave01Normal_size, sizeof(TOHangceilingCave01Normal) == 0x360);
#endif
