#ifndef PSO_CAMERA_TCAMERAWATCHPLAYER_H
#define PSO_CAMERA_TCAMERAWATCHPLAYER_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

// Camera mode 10: looks at player 0 from the position the camera params give.
class TCameraWatchPlayer : public TUnk_80488A28 {
public:
    TCameraWatchPlayer();
    virtual ~TCameraWatchPlayer();
    static TUnk_80488A28 *create();
    virtual void vfunc_6();
    virtual void run_task();
};
LAYOUT_ASSERT(TCameraWatchPlayer_size, sizeof(TCameraWatchPlayer) == 0x6C);

#endif
