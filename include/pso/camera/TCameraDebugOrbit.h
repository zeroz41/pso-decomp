#ifndef PSO_CAMERA_TCAMERADEBUGORBIT_H
#define PSO_CAMERA_TCAMERADEBUGORBIT_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

// Camera mode 4: orbits its target, turned by the second controller's stick;
// its buttons 0x20000 and 0x10000 move it out and in.
class TCameraDebugOrbit : public TUnk_80488A28 {
public:
    TCameraDebugOrbit();
    virtual ~TCameraDebugOrbit();
    static TUnk_80488A28 *create();
    virtual void run_task();
    f32 distance; // from the target, 10 to 300
};
LAYOUT_ASSERT(TCameraDebugOrbit_size, sizeof(TCameraDebugOrbit) == 0x70);

#endif
