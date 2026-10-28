#ifndef PSO_OBJECT_TOBJLIVECAMERA_H
#define PSO_OBJECT_TOBJLIVECAMERA_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLiveCamera : public TObjBase {
    virtual ~TObjLiveCamera();
    virtual void render();
    virtual void run_task();
    static void load_static_resource();
};

typedef char TObjLiveCamera_size[sizeof(TObjLiveCamera) == 0x90 ? 1 : -1];
#endif
