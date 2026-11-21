#ifndef PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXMOVE_H
#define PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXMOVE_H

#include "pso/system/task/TObject.h"
#include <stddef.h>
#include "types.h"

class TObjOnlineEndingHexMove : public TObject {
public:
    virtual ~TObjOnlineEndingHexMove();
    virtual void run_task();

    s32 timer;
};

typedef char EndingHexMoveSize[sizeof(TObjOnlineEndingHexMove) == 0x20 ? 1 : -1];

#endif
