#ifndef PSO_OBJECT_TOBJHMS_EZROPE_PLAYER_H
#define PSO_OBJECT_TOBJHMS_EZROPE_PLAYER_H
#include "types.h"
#include "pso/object/TObjEZRopeBase.h"

// One rope of the hair: hung at pos on the owner's bone, twisted by twist_offset from the owner's
// facing and drawn with segment. The list ends at a negative bone.
struct TObjHMSRopeSpec {
    s8 bone;
    s32 twist_offset;
    Vec pos;
    TObjEZRopeSegment *segment;
};

// A collision sphere carried by the owner's bone; the list ends at a negative bone.
struct TObjHMSColliderSpec {
    s8 bone;
    f32 radius;
    Vec center;
};

class TObjHMS_EZRope_Player : public TObjEZRopeBase {
public:
    TObjHMS_EZRope_Player(TObject *parent, TObjHMSRopeSpec *ropes, TObjHMSColliderSpec *colliders);
    virtual ~TObjHMS_EZRope_Player();
    virtual void run_task();
    virtual void render();
    void draw_rope();
    TObject *owner;
    TObjHMSRopeSpec *rope_specs;
    TObjHMSColliderSpec *collider_specs;
    TObjEZRopeSegment *segment_buffer;
    TObjEZRopeEnd *end_buffer;
    TObjEZRopeCollider *collider_buffer;
};
LAYOUT_ASSERT(TObjHMS_EZRope_Player_size, sizeof(TObjHMS_EZRope_Player) == 0x48);

void copy_ezrope_collider(TObjEZRopeCollider *dst, TObjEZRopeCollider *src);
void copy_ezrope_end(TObjEZRopeEnd *dst, TObjEZRopeEnd *src);
void copy_ezrope_segment(TObjEZRopeSegment *dst, TObjEZRopeSegment *src);

// The pull the player-attached ropes and bone chains settle under each frame.
extern Vec ez_bone_rot_player_chain_gravity;

#endif
