#ifndef PSO_OBJECT_TOBJEZBONEROTPLAYER_H
#define PSO_OBJECT_TOBJEZBONEROTPLAYER_H

#include "pso/TObjEZBoneRotBase.h"
#include "types.h"

class TObjEZBoneRotPlayer : public TObjEZBoneRotBase {
public:
    virtual ~TObjEZBoneRotPlayer();
    void start_bone_rotation_sequence(s32);
    void calc_bone_offsets_recursive(void *, s32, s32);
public:
    virtual void run_task();
    static void *create(void *arg0, void *arg1, void *arg2);
    void advance_bone_rotation();
};

extern "C" {
int render__21TObjHMS_EZRope_PlayerFv(void *p);
void *__dt__19TObjEZBoneRotPlayerFv(void *self, s16 flag);
}

#endif
