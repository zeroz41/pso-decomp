#ifndef PSO_EFFECT_PHOTON_TDPBSHOWER_H
#define PSO_EFFECT_PHOTON_TDPBSHOWER_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TDPBShower : public TObject {
public:
 f32 m_position[3];
 s32 m_countdown;
 void* m_2c;

    virtual ~TDPBShower();
    virtual void run_task();
};

#include <stddef.h>
LAYOUT_ASSERT(TDPBShowerSize, sizeof(TDPBShower) == 0x30);
LAYOUT_ASSERT(TDPBShowerPositionOffset, offsetof(TDPBShower, m_position) == 0x1C);
LAYOUT_ASSERT(TDPBShowerCountdownOffset, offsetof(TDPBShower, m_countdown) == 0x28);
LAYOUT_ASSERT(TDPBShowerEffectOffset, offsetof(TDPBShower, m_2c) == 0x2C);

void *create_TDPBShower(void *arg0, void *arg1);

// --- C functions defined in TBoss6DPB.cpp ---
void *create_TDPBShower(void *arg0, void *arg1);
// --- end of C functions

#endif
