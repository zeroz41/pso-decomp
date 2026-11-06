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
typedef char TDPBShowerSize[(sizeof(TDPBShower) == 0x30) ? 1 : -1];
typedef char TDPBShowerPositionOffset[(offsetof(TDPBShower, m_position) == 0x1C) ? 1 : -1];
typedef char TDPBShowerCountdownOffset[(offsetof(TDPBShower, m_countdown) == 0x28) ? 1 : -1];
typedef char TDPBShowerEffectOffset[(offsetof(TDPBShower, m_2c) == 0x2C) ? 1 : -1];

void *create_TDPBShower(void *arg0, void *arg1);

// --- C functions defined in TDPBShower.cpp ---
void *create_TDPBShower(void *arg0, void *arg1);
// --- end of C functions

#endif
