#ifndef PSO_UNK_TUNK_804C3248_H
#define PSO_UNK_TUNK_804C3248_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// One attachment effect of a photon blast summon; the summon holds a counted array of them.
struct PhotonBlastAttachment {
    void *obj;
    Vec pos;
    s32 joint;  // the model joint whose position it follows, or < 0 to follow the summon
    s32 angles[3];
};

// The attachments publish_photon_blast_joint_origins moves onto their joints
// while the summon's model is drawn.
struct PhotonBlastJointList {
    PhotonBlastAttachment *list;
    s32 count;
};

class TUnk_804C3248 : public TObjMotion {
public:
    TUnk_804C3248();
    virtual ~TUnk_804C3248();
    void spawn_photon_blast_attachment_effects(s32);
    virtual void enter_scene();
    virtual void update_if_active();
    void setup_photon_blast_camera();
    void update_state();
    void free_photon();
    void update_photon_blast_attachments();
    void set_photon_blast_joint_callback();
    void begin_photon_summon_camera(s8);
    // Eases the camera position and target towards their goals by fixed steps.
    // The caller passes 1.0 for speed; the steps do not use it.
    void update_camera_pose(f32 speed);
    // 0 while update_camera_pose eases the camera in; 1 once
    // begin_photon_summon_camera has started the summon's camera script.
    s32 camera_state;
    u32 attachment_count;
    // setup_photon_blast_camera places these behind the local player.
    Vec camera_target;
    Vec camera_position;
    Vec camera_target_goal;
    Vec camera_position_goal;
    s32 m_134;
    u8 unk_138[0x4];
    f32 m_13c;
    u8 unk_140[0x4];
    f32 m_144;
    PhotonBlastAttachment *attachments;
    u8 unk_14C[0x4];
    f32 m_150;
    u8 unk_154[0x4];
};

#include <stddef.h>
LAYOUT_ASSERT(TUnk_804C3248_camera_state, offsetof(TUnk_804C3248, camera_state) == 0xFC);
LAYOUT_ASSERT(TUnk_804C3248_camera_target, offsetof(TUnk_804C3248, camera_target) == 0x104);
LAYOUT_ASSERT(TUnk_804C3248_camera_position_goal, offsetof(TUnk_804C3248, camera_position_goal) == 0x128);
LAYOUT_ASSERT(TUnk_804C3248_attachments, offsetof(TUnk_804C3248, attachments) == 0x148);

#endif
