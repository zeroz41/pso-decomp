#ifndef PSO_TECHNIQUE_TTECSUPPORTCHARGE_H
#define PSO_TECHNIQUE_TTECSUPPORTCHARGE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct TObjPlayer;

// Support technique charge effect: follows the casting player and spawns particles
// until the charge ends.
class TTecSupportCharge : public TObject {
public:
    TTecSupportCharge(TObjPlayer *actor, TObject *parent);
    virtual ~TTecSupportCharge();
    virtual void run_task();
    TObjPlayer *actor;
    Vec position;
    s32 age;
    s32 sound;
};
LAYOUT_ASSERT(TTecSupportCharge_size, sizeof(TTecSupportCharge) == 0x34);

#endif
