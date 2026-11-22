#ifndef PSO_CAMERA_TCAMERAFIXED_H
#define PSO_CAMERA_TCAMERAFIXED_H
#include "types.h"
#include "pso/camera/TCameraController.h"

// Camera mode 9: holds the pose scenes and conversations hand over through
// set_active_camera_pose and the camera parameters.
class TCameraFixed : public TCameraController {
public:
    TCameraFixed();
    virtual ~TCameraFixed();
    static TCameraController *create();
    virtual void apply_camera_params(s32 pass);
    virtual void run_task();
};
LAYOUT_ASSERT(TCameraFixed_size, sizeof(TCameraFixed) == 0x6C);

#endif
