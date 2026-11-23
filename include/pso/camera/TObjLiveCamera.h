#ifndef PSO_CAMERA_TOBJLIVECAMERA_H
#define PSO_CAMERA_TOBJLIVECAMERA_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// The live camera set object of the Gol Dragon floor. It does nothing itself;
// its static resource is the arena monitors' model file.
class TObjLiveCamera : public TObjBase {
public:
    TObjLiveCamera(TObject *parent, void *set_data);
    virtual ~TObjLiveCamera();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void load_static_resource();
    static void free_static_resource(); // frees what load_static_resource loads (its pair in static_resource_callback_table)
};

LAYOUT_ASSERT(TObjLiveCamera_size, sizeof(TObjLiveCamera) == 0x90);
#endif
