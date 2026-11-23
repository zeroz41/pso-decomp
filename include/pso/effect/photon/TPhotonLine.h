#ifndef PSO_EFFECT_PHOTON_TPHOTONLINE_H
#define PSO_EFFECT_PHOTON_TPHOTONLINE_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

// What a photon blast passes to the line it fires.
struct PhotonLineParams {
    Vec pos;
    Vec dir;    // unit vector, scaled by speed
    f32 speed;
    f32 power;  // scale of the photon blast hit it deals
};

// A wave that sweeps along the ground and hits each player it crosses once
// (at most nine); it ends when a wall blocks its path.
class TPhotonLine : public TObjChara {
public:
    TPhotonLine(PhotonLineParams *params, TObject *parent, u16 owner_id);
    virtual ~TPhotonLine();
    virtual void run_task();
    virtual void render();
    Vec vel;
    u8 pad_340[0x4];
    f32 power;
    u8 pad_348[0x8];
    TObjCollidable *owner;
    u16 hit_ids[10];  // entity ids already hit
    u16 hit_count;
    u8 pad_36A[0xE];
};

LAYOUT_ASSERT(TPhotonLine_size, sizeof(TPhotonLine) == 0x378);
#endif
