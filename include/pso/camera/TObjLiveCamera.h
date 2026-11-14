#ifndef PSO_CAMERA_TOBJLIVECAMERA_H
#define PSO_CAMERA_TOBJLIVECAMERA_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjLiveCamera : public TObjBase {
    virtual ~TObjLiveCamera();
    virtual void render();
    virtual void run_task();
    static void load_static_resource();
    static void free_static_resource(); // inferred: frees what load_static_resource loads (its pair in static_resource_callback_table)
};

typedef char TObjLiveCamera_size[sizeof(TObjLiveCamera) == 0x90 ? 1 : -1];
#endif
