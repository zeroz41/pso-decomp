#ifndef PSO_EFFECT_PHOTON_TPHOTONLASER_H
#define PSO_EFFECT_PHOTON_TPHOTONLASER_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

class TParticleCtrl;

// What a photon blast passes to the laser it fires.
struct PhotonLaserParams {
    Vec pos;
    u8 pad_0C[0xC];
    Vec dir;    // unit vector, scaled by speed
    f32 range;
    f32 speed;
    f32 pad_2C;
};

// A laser that falls from the sky, spinning, with a particle emitter; it
// bursts when it drops below its owner's height.
class TPhotonLaser : public TObjChara {
public:
    static const char *class_name;
    TPhotonLaser(PhotonLaserParams *params, TObject *parent, u16 owner_id);
    virtual ~TPhotonLaser();
    virtual void run_task();
    virtual void render();
    Vec origin;
    Vec pos;
    Vec vel;
    f32 range;
    f32 pad_35C;
    u8 pad_360[0x4];
    TParticleCtrl *emitter;
    f32 timer;
    u32 angle;     // spin around the fall line, in degrees
    u16 owner_id;
    u8 pad_372[0xE];
};

LAYOUT_ASSERT(TPhotonLaser_size, sizeof(TPhotonLaser) == 0x380);
#endif
