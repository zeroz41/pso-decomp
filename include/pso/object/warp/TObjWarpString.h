#ifndef PSO_OBJECT_WARP_TOBJWARPSTRING_H
#define PSO_OBJECT_WARP_TOBJWARPSTRING_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjWarpString : public TObject {
public:
    virtual ~TObjWarpString();
    void delay_before_fade_in();
    virtual void run_task();
    virtual void render();
public:
};

#endif
