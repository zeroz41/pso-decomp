#ifndef PSO_TLOGO_H
#define PSO_TLOGO_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TLogo : public TObject {
public:
    virtual ~TLogo();
    virtual void render();
    virtual void run_task();
public:
    static void free_held_object();
    static void request_exit();
    static s32 check_progressive_ready();
};

#endif
