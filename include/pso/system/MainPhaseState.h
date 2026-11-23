#ifndef PSO_SYSTEM_MAINPHASESTATE_H
#define PSO_SYSTEM_MAINPHASESTATE_H

#include "types.h"

struct MainPhaseState {
    s32 cur;
    s32 next;
    s32 queued_main_phase;
    s32 fallback;
    s32 result;
    s32 prev;
};

extern "C" MainPhaseState main_phase_state;

#endif
