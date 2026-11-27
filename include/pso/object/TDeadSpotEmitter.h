#ifndef PSO_OBJECT_TDEADSPOTEMITTER_H
#define PSO_OBJECT_TDEADSPOTEMITTER_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

class TDeadSpotEmitter : public TObject {
public:
    TDeadSpotEmitter(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius);
    virtual ~TDeadSpotEmitter();
    virtual void run_task();
    virtual void place_emitter();
    Vec position;
    f32 radius;
    s32 timer;     // frames since the last emitter move (name inferred)
    s32 interval;  // frames between moves: 2, TDeadSpotGroundEmitter 8 (name inferred)
    TParticleCtrl *emitter;
};
LAYOUT_ASSERT(TDeadSpotEmitter_size, sizeof(TDeadSpotEmitter) == 0x38);

#endif
