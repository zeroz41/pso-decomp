#ifndef PSO_OBJECT_TOBJEZBONEROTPLAYER_H
#define PSO_OBJECT_TOBJEZBONEROTPLAYER_H

#include "pso/object/TObjEZBoneRotBase.h"
#include "types.h"

class TObjEZBoneRotPlayer : public TObjEZBoneRotBase {
public:
    TObjEZBoneRotPlayer(TObject *parent, u8 *root, void *desc);
    virtual ~TObjEZBoneRotPlayer();
    void start_bone_rotation_sequence(s32);
    void calc_bone_offsets_recursive(void *, s32, s32);
public:
    virtual void run_task();
    static void *create(void *parent, void *root, void *desc);
    void advance_bone_rotation();
};

extern "C" {
int render__21TObjHMS_EZRope_PlayerFv(void *p);
}

#endif
