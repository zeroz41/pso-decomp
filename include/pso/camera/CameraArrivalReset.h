#ifndef PSO_CAMERA_ARRIVAL_RESET_H
#define PSO_CAMERA_ARRIVAL_RESET_H
#include "pso/camera/FollowCameraController.h"
struct ArrivalCameraPose {
    u8 prefix[0x30];
    s32 heading;
    u8 unknown34[8];
    FollowVector position;
    FollowVector target;
};
struct ArrivalCameraActor {
    u8 prefix[0x38];
    FollowVector position;
    u8 unknown44[0x1C];
    s32 heading;
};
LAYOUT_ASSERT(ArrivalPoseHeading, offsetof(ArrivalCameraPose,heading)==0x30);
LAYOUT_ASSERT(ArrivalPosePosition, offsetof(ArrivalCameraPose,position)==0x3C);
LAYOUT_ASSERT(ArrivalPoseTarget, offsetof(ArrivalCameraPose,target)==0x48);
LAYOUT_ASSERT(ArrivalActorHeading, offsetof(ArrivalCameraActor,heading)==0x60);
extern "C" void vfunc_8__13TUnk_80488E00FPv(ArrivalCameraPose *, const ArrivalCameraActor *);
#endif
