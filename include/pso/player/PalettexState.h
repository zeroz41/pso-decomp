#ifndef PSO_PLAYER_PALETTEXSTATE_H
#define PSO_PLAYER_PALETTEXSTATE_H

#include "types.h"
#include "pso/system/data/FlagWord.h"

// The palette state of one client: its flags and the quest label run_palettex_callback starts.
struct PalettexState {
    FlagWord flags;
    s32 callback_label;

    PalettexState();
    ~PalettexState();
    void run_callback();
    s32 get_callback_label();
    void set_callback_label(s32 label);
    s32 is_enabled();
    void disable();
    void enable();
    s32 is_activated();
    void restore();
    void activate();
    void reset();
};

LAYOUT_ASSERT(PalettexStateSize, sizeof(PalettexState) == 8);

#endif
