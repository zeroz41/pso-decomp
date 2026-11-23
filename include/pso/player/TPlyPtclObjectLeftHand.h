#ifndef PSO_PLAYER_TPLYPTCLOBJECTLEFTHAND_H
#define PSO_PLAYER_TPLYPTCLOBJECTLEFTHAND_H

#include "types.h"
#include "pso/effect/particle/TPlyFollowParticleCtrl.h"

struct TPlyPtclObjectLeftHand : public TPlyFollowParticleCtrl {
    TPlyPtclObjectLeftHand(TObjBase *owner);
    virtual ~TPlyPtclObjectLeftHand();
    // vtable slot 9 (TObjBase::get_center)
    virtual void *get_center();

    static const char *class_name;
};

LAYOUT_ASSERT(TPlyPtclObjectLeftHand_size, sizeof(TPlyPtclObjectLeftHand) == 0xB0);
#endif
