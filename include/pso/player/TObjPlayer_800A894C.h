#ifndef PSO_PLAYER_TOBJPLAYER_800A894C_H
#define PSO_PLAYER_TOBJPLAYER_800A894C_H

#include "types.h"

class TObjEneDubchik;

// --- C functions defined in TObjEneDubchik.cpp ---
// The state handlers TObjEneDubchik's run_synced_state_handler picks by mode.
extern "C" {
void dubchik_start_dying(TObjEneDubchik *dubchik);
void TObjPlayer__sub_800A8C4C(TObjEneDubchik *dubchik);
void TObjPlayer__sub_800A8E04(TObjEneDubchik *dubchik);
void TObjPlayer__sub_800A8FB4(TObjEneDubchik *dubchik);
void TObjPlayer__sub_800A93E4(TObjEneDubchik *dubchik);
void TObjPlayer__sub_800A9C38(TObjEneDubchik *dubchik);
void TObjPlayer__sub_800A9E9C(TObjEneDubchik *dubchik);
void TObjPlayer__sub_800AA330(TObjEneDubchik *dubchik);
void TObjPlayer__sub_800AA82C(void);
}
// --- end of C functions

#endif
