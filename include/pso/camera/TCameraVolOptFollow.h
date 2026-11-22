#ifndef PSO_CAMERA_TCAMERAVOLOPTFOLLOW_H
#define PSO_CAMERA_TCAMERAVOLOPTFOLLOW_H
#include "types.h"
#include "pso/camera/TCameraFollow.h"

// Camera mode 12, the Vol Opt fight: while Vol Opt has a camera focus the camera
// stands behind the followed player, looking past it at the focus. Within 100
// units of the focus it locks the target and eye offsets from the player instead.
class TCameraVolOptFollow : public TCameraFollow {
public:
    TCameraVolOptFollow();
    virtual ~TCameraVolOptFollow();
    static TCameraController *create();
    virtual void run_task();
    virtual void update_follow_settings();
    void update_target_follow();
    s32 pad_110;
    s32 follow_state;  // 0 tracking the focus, 1 holding the offsets below
    Vec locked_target_offset; // target minus the player's position when the lock began
    Vec locked_eye_offset;    // position minus the player's position when the lock began
};
LAYOUT_ASSERT(TCameraVolOptFollow_size, sizeof(TCameraVolOptFollow) == 0x130);

#endif
