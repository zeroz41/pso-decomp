#ifndef PSO_TECHNIQUE_TTECICECHARGE_H
#define PSO_TECHNIQUE_TTECICECHARGE_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

struct TObjPlayer;

// A technique's charge effect around its caster (create_technique_charge_light
// builds it for kinds 3-5): ice particles every 10 frames and a looping sound,
// until the caster stops charging or 180 frames pass.
class TTecIceCharge : public TObject {
public:
    TTecIceCharge(TObjPlayer *actor, TObject *parent);
    virtual ~TTecIceCharge();
    virtual void run_task();

    TObjPlayer *m_actor;
    Vec m_position;     // the caster's body centre when created
    s32 m_age;          // frames since created
    s32 m_sound_handle; // play_sound_effect's result, stopped by the dtor
};
LAYOUT_ASSERT(TTecIceCharge_size, sizeof(TTecIceCharge) == 0x34);

#endif
