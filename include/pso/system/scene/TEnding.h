#ifndef PSO_SYSTEM_SCENE_TENDING_H
#define PSO_SYSTEM_SCENE_TENDING_H

#include "pso/system/task/TObject.h"

class TAdRicoRingCtrl;

// Frames since the ending started.
extern u32 ending_frame_counter;
// Set while the ending scene runs.
extern s32 ending_scene_active;

class TEnding : public TObject {
public:
    TEnding();
    virtual ~TEnding();
    virtual void run_task();
    virtual void render();

    s32 phase;
    u8 unresolved_20[4];
    s32 timing_rate;
    s32 elapsed_ticks;
    u8 unresolved_2c[0x6E0];
    TAdRicoRingCtrl *ring_controller;
public:
    static void set_flag_and_advance();
    static void start_ending_scene();
};

#include <stddef.h>
LAYOUT_ASSERT(TEndingSize, sizeof(TEnding) == 0x710);
LAYOUT_ASSERT(TEndingPhase, offsetof(TEnding, phase) == 0x1C);
LAYOUT_ASSERT(TEndingRate, offsetof(TEnding, timing_rate) == 0x24);
LAYOUT_ASSERT(TEndingTicks, offsetof(TEnding, elapsed_ticks) == 0x28);
LAYOUT_ASSERT(TEndingRing, offsetof(TEnding, ring_controller) == 0x70C);

extern "C" {
void TEnding__sub_8008C9F8(void);
}

// --- C functions defined in TEnding.cpp ---
extern "C" {
void TEnding__sub_8008C9F8(void);
}
// --- end of C functions

#endif
