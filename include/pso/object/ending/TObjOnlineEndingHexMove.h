#ifndef PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXMOVE_H
#define PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXMOVE_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjOnlineEndingHexMove : public TObject {
public:
    virtual ~TObjOnlineEndingHexMove();
    virtual void run_task();
};

#endif
