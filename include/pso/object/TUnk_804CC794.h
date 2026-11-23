#ifndef PSO_OBJECT_TUNK_804CC794_H
#define PSO_OBJECT_TUNK_804CC794_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct TObjPlayer;

// The fire technique charge effect (inferred from its particles and run_task):
// it follows the caster m_actor and lives while the charge flag 0x80 is set, up to
// 180 frames.

class TUnk_804CC794 : public TObject {
public:
    TUnk_804CC794(TObjPlayer *actor, TObject *parent);
    virtual ~TUnk_804CC794();
    virtual void run_task();
    TObjPlayer *m_actor;
    Vec m_position;
    s32 m_age;
    s32 m_sound_handle;
};
LAYOUT_ASSERT(TUnk_804CC794_size, sizeof(TUnk_804CC794) == 0x34);

#endif
