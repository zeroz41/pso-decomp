#ifndef PSO_EFFECT_PHOTON_TPHOTONLINE_H
#define PSO_EFFECT_PHOTON_TPHOTONLINE_H

#include "types.h"
#include "pso/object/base/TObjChara.h"
#include <stddef.h>

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
    static const char *class_name;
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

LAYOUT_ASSERT(PhotonLineParamsSize, sizeof(PhotonLineParams) == 0x20);
LAYOUT_ASSERT(TPhotonLine_size, sizeof(TPhotonLine) == 0x378);
LAYOUT_ASSERT(PhotonLineVelocityOffset, offsetof(TPhotonLine, vel) == 0x334);
LAYOUT_ASSERT(PhotonLineScaleOffset, offsetof(TPhotonLine, power) == 0x344);
LAYOUT_ASSERT(PhotonLineOwnerOffset, offsetof(TPhotonLine, owner) == 0x350);
LAYOUT_ASSERT(PhotonLineHitIdsOffset, offsetof(TPhotonLine, hit_ids) == 0x354);
LAYOUT_ASSERT(PhotonLineHitCountOffset, offsetof(TPhotonLine, hit_count) == 0x368);
#endif
