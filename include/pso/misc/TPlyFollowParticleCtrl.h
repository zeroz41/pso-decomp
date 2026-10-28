#ifndef PSO_MISC_TPLYFOLLOWPARTICLECTRL_H
#define PSO_MISC_TPLYFOLLOWPARTICLECTRL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TPlyFollowParticleCtrl : public TUnk_804AF8A0 {
    virtual ~TPlyFollowParticleCtrl();
    virtual void run_task();
    virtual void *get_center();
    u16 m_ac;
    u16 m_ae;
    void set_type(s16 v);
    u16 get_lifetime();
};

typedef char TPlyFollowParticleCtrl_size[sizeof(TPlyFollowParticleCtrl) == 0xB0 ? 1 : -1];

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
