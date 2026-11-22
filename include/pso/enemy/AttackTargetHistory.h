#ifndef PSO_ENEMY_ATTACKTARGETHISTORY_H
#define PSO_ENEMY_ATTACKTARGETHISTORY_H

#include "types.h"

class PointerBuffer {
public:
    PointerBuffer(s32 capacity, void *empty);
    ~PointerBuffer();
    void **entries;
    void *empty;
    s32 count;
    s32 capacity;
};

class AreaAttackHistory : public PointerBuffer {
public:
    AreaAttackHistory(s32 capacity);
    ~AreaAttackHistory();
};

extern "C" {
// Sets every entry to the buffer's empty value and the count to 0 (defined in TBoss1Dragon.cpp).
void fill_value_array(PointerBuffer *buffer);
}

#endif
