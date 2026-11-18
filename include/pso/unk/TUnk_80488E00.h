#ifndef PSO_UNK_TUNK_80488E00_H
#define PSO_UNK_TUNK_80488E00_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

class TUnk_80488E00 : public TUnk_80488A28 {
public:
    virtual ~TUnk_80488E00();
    s32 sub_8006E7FC();
    void sub_8006DCC8();
    void sub_8006CF38();
    s32 sub_8006CDD0();
    virtual void update_follow_flags();
    virtual void select_follow_camera_offsets();
    virtual void vfunc_14(s32);
    virtual void vfunc_9(u8 *, u8 *);
    s32 predict_obstruction();
    virtual void vfunc_10();
    virtual void vfunc_8(void *);
    virtual void vfunc_6();
    u8 unk_6C[0x7C];
    f32 m_e8;
    u8 unk_EC[0x4];
    f32 m_f0;
    u8 unk_F4[0x8];
    s32 m_fc;
    u8 unk_100[0xC];
    s32 m_10c;
};
typedef char TUnk_80488E00_size[sizeof(TUnk_80488E00) == 0x110 ? 1 : -1];

// Fallback follow-camera pose per floor area (Pioneer 2 Ep1, Lobby, Pioneer 2 Ep2), applied by
// vfunc_10 when there is no local player; one row per camera.
struct FollowCameraInitPose {
    Vec pos;
    Vec target;
    s32 projection_angle; // 0x3555 = 75 degrees
    f32 near_clip;        // inferred: TCameraCtrl::set_clamped_offsets clamps both to [-65535, -1]
    f32 far_clip;
};
extern FollowCameraInitPose *follow_camera_init_pose_table[4];

#endif
