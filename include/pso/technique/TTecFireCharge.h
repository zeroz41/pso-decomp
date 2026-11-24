#ifndef PSO_TECHNIQUE_TTECFIRECHARGE_H
#define PSO_TECHNIQUE_TTECFIRECHARGE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct TObjPlayer;

// The fire technique charge effect (inferred from its particles and run_task):
// it follows the caster m_actor and lives while the charge flag 0x80 is set, up to
// 180 frames.

class TTecFireCharge : public TObject {
public:
    TTecFireCharge(TObjPlayer *actor, TObject *parent);
    virtual ~TTecFireCharge();
    virtual void run_task();
    TObjPlayer *m_actor;
    Vec m_position;
    s32 m_age;
    s32 m_sound_handle;
};
LAYOUT_ASSERT(TTecFireCharge_size, sizeof(TTecFireCharge) == 0x34);

#endif
