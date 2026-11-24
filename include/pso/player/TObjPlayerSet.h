#ifndef PSO_PLAYER_TOBJPLAYERSET_H
#define PSO_PLAYER_TOBJPLAYERSET_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjPlayerSet : public TObjBase {
    TObjPlayerSet(TObject *parent, void *set_data);
    virtual ~TObjPlayerSet();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjPlayerSet_size, sizeof(TObjPlayerSet) == 0x90);

// A free player set that TObjPlayer::send_respawn_position may pick, with its slot.
struct RespawnCandidate {
    RespawnCandidate();
    u16 slot;
    TObjPlayerSet *set;
};
#endif
