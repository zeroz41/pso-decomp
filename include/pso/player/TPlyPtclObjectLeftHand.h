#ifndef PSO_PLAYER_TPLYPTCLOBJECTLEFTHAND_H
#define PSO_PLAYER_TPLYPTCLOBJECTLEFTHAND_H

#include "types.h"
#include "pso/effect/particle/TPlyFollowParticleCtrl.h"

struct TPlyPtclObjectLeftHand : public TPlyFollowParticleCtrl {
    TPlyPtclObjectLeftHand(TObjBase *owner);
    virtual ~TPlyPtclObjectLeftHand();
    // vtable slot 9 (TObjBase::get_center)
    virtual void *get_center();
};

extern const char *TPlyPtclObjectLeftHand__class_name;

typedef char TPlyPtclObjectLeftHand_size[sizeof(TPlyPtclObjectLeftHand) == 0xB0 ? 1 : -1];
#endif
