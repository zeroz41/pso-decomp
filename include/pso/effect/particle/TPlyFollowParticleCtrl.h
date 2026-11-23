#ifndef PSO_EFFECT_PARTICLE_TPLYFOLLOWPARTICLECTRL_H
#define PSO_EFFECT_PARTICLE_TPLYFOLLOWPARTICLECTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TPlyFollowParticleCtrl : public TObjCollidable {
    // owner: the actor it follows (its id goes to owner_id, its center is the
    // starting position).
    TPlyFollowParticleCtrl(TObjBase *owner);
    virtual ~TPlyFollowParticleCtrl();
    virtual void run_task();
    virtual void *get_center();
    u16 owner_id; // entity id of the actor followed, looked up as a player client id
    u16 pad_AE;
    void set_type(u16 type);
    u16 get_owner_id();

    static const char *class_name;
};

LAYOUT_ASSERT(TPlyFollowParticleCtrl_size, sizeof(TPlyFollowParticleCtrl) == 0xB0);

extern "C" {
void TPlyFollowParticleCtrl__sub_8030A694(void);
s32 __dt__22TPlyFollowParticleCtrlFis(s32 arg0, s16 arg1);
}

// --- C functions defined in TPlyFollowParticleCtrl.cpp ---
extern "C" {
void TPlyFollowParticleCtrl__sub_8030A694(void);
}
// --- end of C functions

#endif
