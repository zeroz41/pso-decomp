#ifndef PSO_CAMERA_TCAMERACTRL_800687BC_H
#define PSO_CAMERA_TCAMERACTRL_800687BC_H

#include "types.h"
#include "pso/camera/CameraViewParams.h"

struct TCameraCtrl;
extern "C" {
void TCameraCtrl__sub_800687C8(void);
void TCameraCtrl__sub_800689E8(void);
bool TCameraCtrl__sub_800689F4(void);
f32 TCameraCtrl__sub_80068A04(void);
s32 TCameraCtrl__sub_80069304(void);
s32 activate_camera_mode(s32 arg0);
void quad_80068B34(s32 i);
s32 restore_player_cameras(void);
void set_active_camera_pose(u8 *arg0, u8 *arg1);
void set_active_camera_pose_from_params(u8 *arg0);
void transform_to_view__11TCameraCtrlFii(s32 arg0, s32 arg1);
void viewport_80068B34(void);
}

#endif
