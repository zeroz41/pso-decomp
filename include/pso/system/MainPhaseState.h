#ifndef PSO_SYSTEM_MAINPHASESTATE_H
#define PSO_SYSTEM_MAINPHASESTATE_H

#include "types.h"

struct MainPhaseState {
    s32 cur;
    s32 next;
    s32 unk8;
    s32 unkC;
    s32 result;
    s32 prev;
};

extern "C" MainPhaseState main_phase_state;

#endif
