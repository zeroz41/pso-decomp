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

// Starts the hair (or tail) simulation that fits the player's model, if any.
TObject *create_hair_move_sim(TObjPlayer *player);

extern "C" {
void TObjWaitEntryHairMoveSim__sub_800FE3BC(int bone);
void create_hair_effects__24TObjWaitEntryHairMoveSimFPv(TObjWaitEntryHairMoveSim *self);
int is_move_done__24TObjWaitEntryHairMoveSimFv(void);
}

#endif
