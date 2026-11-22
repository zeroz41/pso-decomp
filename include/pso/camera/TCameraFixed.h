#ifndef PSO_CAMERA_TCAMERAFIXED_H
#define PSO_CAMERA_TCAMERAFIXED_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

// Camera mode 9: holds the pose scenes and conversations hand over through
// set_active_camera_pose and the camera parameters.
class TCameraFixed : public TUnk_80488A28 {
public:
    TCameraFixed();
    virtual ~TCameraFixed();
    static TUnk_80488A28 *create();
    virtual void vfunc_6();
    virtual void run_task();
};
LAYOUT_ASSERT(TCameraFixed_size, sizeof(TCameraFixed) == 0x6C);

#endif
