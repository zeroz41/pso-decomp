#ifndef PSO_OBJECT_TOBJEZBONEROTPLAYER_H
#define PSO_OBJECT_TOBJEZBONEROTPLAYER_H

#include "pso/object/TObjEZBoneRotBase.h"
#include "types.h"

class TObjPlayer;

class TObjEZBoneRotPlayer : public TObjEZBoneRotBase {
public:
    TObjEZBoneRotPlayer(TObject *parent, u8 *root, void *desc);
    virtual ~TObjEZBoneRotPlayer();
    void start_bone_rotation_sequence(s32);
    void calc_bone_offsets_recursive(NJS_OBJECT *bone, s32 angle, s32 amplitude);
public:
    virtual void run_task();
    static void *create(void *parent, void *root, void *desc);
    void advance_bone_rotation();

    TObjPlayer *player;   // the player whose motion drives the swing
    s32 last_rotation_y;  // its rotation_y last frame
};

LAYOUT_ASSERT(TObjEZBoneRotPlayer_size, sizeof(TObjEZBoneRotPlayer) == 0xA0);

extern "C" {
int render__21TObjHMS_EZRope_PlayerFv(void *p);
}

#endif
