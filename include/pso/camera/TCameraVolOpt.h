#ifndef PSO_CAMERA_TCAMERAVOLOPT_H
#define PSO_CAMERA_TCAMERAVOLOPT_H

#include "types.h"
#include "pso/camera/TCameraController.h"

// Camera mode 11, the Vol Opt fight: looks at TBoss3Volopt::get_camera_focus
// from 30 units behind player 0.
class TCameraVolOpt : public TCameraController {
public:
    TCameraVolOpt();
    virtual ~TCameraVolOpt();
    virtual void run_task();
    static TCameraController *create();
};

LAYOUT_ASSERT(TCameraVolOpt_size, sizeof(TCameraVolOpt) == 0x6C);

#endif
