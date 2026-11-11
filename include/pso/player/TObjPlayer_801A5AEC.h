#ifndef PSO_PLAYER_TOBJPLAYER_801A5AEC_H
#define PSO_PLAYER_TOBJPLAYER_801A5AEC_H

#include "types.h"

void accumulate_key_bits(s32 arg0, s32 *arg1);
extern "C" {
void bind_controller_devices(void);
s8 func_801A5E54__Fv(void);
void reset_controller_input_state(void);
void update_pad_recalibration(void);
}

// --- C functions defined in TObjPlayer_801A5AEC.cpp ---
extern "C" {
void bind_controller_devices(void);
void reset_controller_input_state(void);
void update_pad_recalibration(void);
}
// --- end of C functions

#endif
