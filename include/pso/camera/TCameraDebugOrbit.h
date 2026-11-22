#ifndef PSO_CAMERA_TCAMERADEBUGORBIT_H
#define PSO_CAMERA_TCAMERADEBUGORBIT_H
#include "types.h"
#include "pso/camera/TCameraController.h"

// Camera mode 4: orbits its target, turned by the second controller's stick;
// its buttons 0x20000 and 0x10000 move it out and in.
class TCameraDebugOrbit : public TCameraController {
public:
    TCameraDebugOrbit();
    virtual ~TCameraDebugOrbit();
    static TCameraController *create();
    virtual void run_task();
    f32 distance; // from the target, 10 to 300
};
LAYOUT_ASSERT(TCameraDebugOrbit_size, sizeof(TCameraDebugOrbit) == 0x70);

#endif
