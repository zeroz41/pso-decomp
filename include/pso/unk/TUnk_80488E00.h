#ifndef PSO_UNK_TUNK_80488E00_H
#define PSO_UNK_TUNK_80488E00_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

// One per split-screen view; the constructor clears all four with TCameraCtrl__sub_8006E804.
struct FollowCameraSlot {
    f32 m_0[6];
    s32 m_18;
};

class TUnk_80488E00 : public TUnk_80488A28 {
public:
    TUnk_80488E00();
    virtual ~TUnk_80488E00();
    virtual void run_task();
    s32 sub_8006E7FC();
    void sub_8006DCC8();
    // Sets the two follow offsets (m_e8 and eye_offset) and hands angle to vfunc_14.
    void set_pos_target(Vec *position, Vec *target, s32 angle);
    void sub_8006CF38();
    s32 sub_8006CDD0();
    s32 is_flag_set();
    void rotate_heading_by_stick();
    void update_follow_motion_state();
    void calc_follow_position();
    void compute_follow_target();
    virtual void update_follow_flags();
    virtual void select_follow_camera_offsets();
    virtual void vfunc_14(s32);
    virtual void vfunc_9(u8 *, u8 *);
    s32 predict_obstruction();
    virtual void vfunc_10();
    virtual void vfunc_8(void *);
    virtual void vfunc_6();
    FollowCameraSlot slots[4];
    // inferred: calc_follow_position puts the camera at the actor plus this, turned by yaw
    Vec eye_offset;
    f32 m_e8;
    f32 m_ec;
    f32 m_f0;
    s32 m_f4;
    s32 m_f8;
    s32 m_fc;
    s32 m_100;
    s32 m_104;
    f32 m_108;
    s32 m_10c;
};
LAYOUT_ASSERT(TUnk_80488E00_size, sizeof(TUnk_80488E00) == 0x110);

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
