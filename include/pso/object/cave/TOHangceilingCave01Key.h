#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEY_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01KEY_H

#include "types.h"
#include "pso/object/cave/TOHangceilingCaveBase.h"

class TOHangceilingCave01Key : public TOHangceilingCaveBase {
public:
    TOHangceilingCave01Key(TObject *parent, ObjectSetData *set_data);
    virtual ~TOHangceilingCave01Key();
    virtual void begin_wait();
    virtual void update_state();
};

LAYOUT_ASSERT(TOHangceilingCave01Key_size, sizeof(TOHangceilingCave01Key) == 0x360);
#endif
