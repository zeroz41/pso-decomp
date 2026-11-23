#ifndef PSO_OBJECT_TOBJWAITENTRYHAIRMOVESIM_H
#define PSO_OBJECT_TOBJWAITENTRYHAIRMOVESIM_H

#include "types.h"

#include "pso/system/task/TObject.h"

class TObjPlayer;

class TObjWaitEntryHairMoveSim : public TObject {
public:
    TObjWaitEntryHairMoveSim(TObjPlayer *player);
    virtual ~TObjWaitEntryHairMoveSim();
    virtual void run_task();

    TObjPlayer *player;
};
LAYOUT_ASSERT(TObjWaitEntryHairMoveSimSize, sizeof(TObjWaitEntryHairMoveSim) == 0x20);

extern "C" {
void TObjWaitEntryHairMoveSim__sub_800FE3BC(int bone);
TObject *fn_800FE73C(TObjPlayer *player);
void create_hair_effects__24TObjWaitEntryHairMoveSimFPv(TObjWaitEntryHairMoveSim *self);
int is_move_done__24TObjWaitEntryHairMoveSimFv(void);
}

#endif
