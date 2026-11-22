#ifndef PSO_CAMERA_TCAMERAWATCHPLAYER_H
#define PSO_CAMERA_TCAMERAWATCHPLAYER_H
#include "types.h"
#include "pso/camera/TCameraController.h"

// Camera mode 10: looks at player 0 from the position the camera params give.
class TCameraWatchPlayer : public TCameraController {
public:
    TCameraWatchPlayer();
    virtual ~TCameraWatchPlayer();
    static TCameraController *create();
    virtual void apply_camera_params(s32 pass);
    virtual void run_task();
};
LAYOUT_ASSERT(TCameraWatchPlayer_size, sizeof(TCameraWatchPlayer) == 0x6C);

#endif
