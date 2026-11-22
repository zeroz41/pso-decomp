#ifndef PSO_OBJECT_TOBJWAITENTRYHAIRMOVESIM_H
#define PSO_OBJECT_TOBJWAITENTRYHAIRMOVESIM_H

#include "types.h"

class TObjPlayer;

extern "C" {
void TObjWaitEntryHairMoveSim__sub_800FE3BC(int _w0);
s32 fn_800FE73C(TObjPlayer *player);
void *__ct__24TObjWaitEntryHairMoveSimFv(void *arg0, void *player);
void create_hair_effects__24TObjWaitEntryHairMoveSimFPv(void *arg0);
int is_move_done__24TObjWaitEntryHairMoveSimFv(void);
}

#endif
