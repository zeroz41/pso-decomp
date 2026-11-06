#ifndef PSO_PLAYER_TPLYPTCLOBJECTRIGHTHAND_H
#define PSO_PLAYER_TPLYPTCLOBJECTRIGHTHAND_H

#include "types.h"
#include "pso/effect/particle/TPlyFollowParticleCtrl.h"

struct TPlyPtclObjectRightHand : public TPlyFollowParticleCtrl {
    TPlyPtclObjectRightHand(TObjBase *owner);
    virtual ~TPlyPtclObjectRightHand();
    // vtable slot 9 (TObjBase::get_center)
    virtual void *get_center();
};

extern const char *TPlyPtclObjectRightHand__class_name;

typedef char TPlyPtclObjectRightHand_size[sizeof(TPlyPtclObjectRightHand) == 0xB0 ? 1 : -1];


#endif
