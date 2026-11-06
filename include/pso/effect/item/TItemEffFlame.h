#ifndef PSO_EFFECT_ITEM_TITEMEFFFLAME_H
#define PSO_EFFECT_ITEM_TITEMEFFFLAME_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;
struct TItemEquipBase;

// Flames flickering on the collision body of an actor a fire weapon hit; a
// timer destroys them after 30 frames.
class TItemEffFlame : public TObject {
public:
    TItemEffFlame(TObject *parent, ActorBodyHit *hit);
    virtual ~TItemEffFlame();
    virtual void run_task();

    TParticleCtrl *emitter;
    u16 target_id;
    s32 body_index;
};

typedef char TItemEffFlameSize[(sizeof(TItemEffFlame) == 0x28) ? 1 : -1];

// Weapon hit callbacks: a burst where a shot hits a wall, and flames on an
// actor's body.
extern "C" {
void spawn_flame_wall_impact(TObject *parent, TItemEquipBase *weapon, const Vec *from, Vec *hit);
void spawn_flame_effect(void *unused, ActorBodyHit *hit);
}

#endif
