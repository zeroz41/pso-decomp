#ifndef PSO_UNK_TUNK_804CCD0C_H
#define PSO_UNK_TUNK_804CCD0C_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct TObjPlayer;

// The lightning technique charge effect (inferred from its particles and run_task):
// it follows the caster m_actor and lives while the charge flag 0x80 is set, up to
// 180 frames.

class TUnk_804CCD0C : public TObject {
public:
    TUnk_804CCD0C(TObjPlayer *actor, TObject *parent);
    virtual ~TUnk_804CCD0C();
    virtual void run_task();
    TObjPlayer *m_actor;
    Vec m_position;
    s32 m_age;
    s32 m_sound_handle;
};
LAYOUT_ASSERT(TUnk_804CCD0C_size, sizeof(TUnk_804CCD0C) == 0x34);

#endif
