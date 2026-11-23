#ifndef PSO_EFFECT_PHOTON_TPHOTONCONCENTRATE_H
#define PSO_EFFECT_PHOTON_TPHOTONCONCENTRATE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;
class TObjChara;

// What the spawner fills in for one concentrating photon.
struct PhotonConcentrateParams {
    Vec origin;
    Vec target;
    Vec direction;  // unit vector, scaled by speed
    f32 range;      // destroyed once this far from the origin
    f32 speed;
    f32 pad_2C;
    TObjChara *target_object;  // the enemy the spawner aimed at
    u32 angle;      // roll of its spiral around the path, in degrees
};

// A photon that flies from origin to target on a spiral, carrying a particle
// emitter; it bursts when it reaches the target.
class TPhotonConcentrate : public TObjCollidable {
public:
    static const char *class_name;
    TPhotonConcentrate(PhotonConcentrateParams *params, TObject *parent, u16 owner_id);
    virtual ~TPhotonConcentrate();
    virtual void render();
    virtual void run_task();
    Vec origin;
    Vec pos;
    Vec vel;
    Vec target;
    f32 dist;       // to the target
    f32 total;      // from the origin to the target
    f32 range;
    f32 pad_E8;
    u32 angle;
    TObjChara *target_object;
    u8 pad_F4[0x4];
    TParticleCtrl *emitter;
    TObjCollidable *owner;  // its spiral turns with the owner's y rotation
    u8 pad_100[0xC];
};

LAYOUT_ASSERT(TPhotonConcentrate_size, sizeof(TPhotonConcentrate) == 0x10C);

#endif
