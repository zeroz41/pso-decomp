#ifndef PSO_PLAYER_TMIRRORPAIRPARTICLE_H
#define PSO_PLAYER_TMIRRORPAIRPARTICLE_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

class TParticleCtrl;

// The pair of particles spawn_mirror_pair (a weapon special) sends spiralling in on the hit
// position. Field names are inferred from the constructor, run_task and the destructor.
class TMirrorPairParticle : public TObject {
public:
    TMirrorPairParticle(TObject *parent, Vec *pos, s32 start_angle);
    virtual ~TMirrorPairParticle();
    void update_inward_orbit_point();
    virtual void render();
    virtual void run_task();
    Vec center;              // inferred: the point it circles, 5 units off the hit position
    Vec origin;              // inferred: the hit position as given
    Vec point;               // inferred: where the particle sits this frame
    f32 radius;              // inferred: 40, shrinking by 4 a frame
    s32 angle;               // the angle update_inward_orbit_point looks up
    s32 frames_left;         // inferred: 10 frames, then it queues its own destruction
    TParticleCtrl *particle; // the particle it moves, released by the destructor
};
LAYOUT_ASSERT(TMirrorPairParticle_size, sizeof(TMirrorPairParticle) == 0x50);

#endif
