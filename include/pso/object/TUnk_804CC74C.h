#ifndef PSO_OBJECT_TUNK_804CC74C_H
#define PSO_OBJECT_TUNK_804CC74C_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TObjPlayer;

// The dark technique charge: spawns its three particles every 10 frames at
// the caster m_actor while the charge flag 0x80 is set, up to 180 frames.
class TUnk_804CC74C : public TObject {
public:
    TUnk_804CC74C(TObjPlayer *actor, TObject *parent);
    virtual ~TUnk_804CC74C();
    virtual void run_task();
    TObjPlayer *m_actor;
    Vec m_position;
    s32 m_age;
    s32 m_sound_handle;
};
LAYOUT_ASSERT(TUnk_804CC74C_size, sizeof(TUnk_804CC74C) == 0x34);

#endif
