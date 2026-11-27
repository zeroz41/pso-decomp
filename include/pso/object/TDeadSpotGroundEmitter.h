#ifndef PSO_OBJECT_TDEADSPOTGROUNDEMITTER_H
#define PSO_OBJECT_TDEADSPOTGROUNDEMITTER_H
#include "types.h"
#include "pso/object/TDeadSpotEmitter.h"

class TDeadSpotGroundEmitter : public TDeadSpotEmitter {
public:
    TDeadSpotGroundEmitter(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius);
    virtual ~TDeadSpotGroundEmitter();
    virtual void place_emitter();
};
LAYOUT_ASSERT(TDeadSpotGroundEmitter_size, sizeof(TDeadSpotGroundEmitter) == 0x38);

#endif
