#ifndef PSO_EFFECT_PHOTON_TDPBSHOWER_H
#define PSO_EFFECT_PHOTON_TDPBSHOWER_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

class TDPBShower : public TObject {
public:
    Vec position;       // starts 300 above the spawn point and falls 60 a frame
    s32 m_countdown;
    TParticleCtrl *particle_emitter;  // create_particle_emitter(&position, 0x134)

    TDPBShower(TObject *parent, void *position);
    virtual ~TDPBShower();
    virtual void run_task();
};

#include <stddef.h>
LAYOUT_ASSERT(TDPBShowerSize, sizeof(TDPBShower) == 0x30);
LAYOUT_ASSERT(TDPBShowerPositionOffset, offsetof(TDPBShower, position) == 0x1C);
LAYOUT_ASSERT(TDPBShowerCountdownOffset, offsetof(TDPBShower, m_countdown) == 0x28);
LAYOUT_ASSERT(TDPBShowerEffectOffset, offsetof(TDPBShower, particle_emitter) == 0x2C);

void *create_TDPBShower(void *parent, void *position);

#endif
