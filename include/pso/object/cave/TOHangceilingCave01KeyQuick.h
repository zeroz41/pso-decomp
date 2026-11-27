#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEYQUICK_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEYQUICK_H

#include "types.h"
#include "pso/object/cave/TOHangceilingCaveBase.h"

class TOHangceilingCave01KeyQuick : public TOHangceilingCaveBase {
public:
    TOHangceilingCave01KeyQuick(TObject *parent, ObjectSetData *set_data);
    virtual ~TOHangceilingCave01KeyQuick();
    virtual void begin_wait();
    virtual void update_state();
};

LAYOUT_ASSERT(TOHangceilingCave01KeyQuick_size, sizeof(TOHangceilingCave01KeyQuick) == 0x360);
#endif
