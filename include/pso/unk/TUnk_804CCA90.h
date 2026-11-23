#ifndef PSO_UNK_TUNK_804CCA90_H
#define PSO_UNK_TUNK_804CCA90_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// Plays a sound effect at a point once a delay in frames has run out, then
// destroys itself (spawned by Anti, Resta and Reverser).
class TUnk_804CCA90 : public TObject {
public:
    TUnk_804CCA90(Vec *pos, s16 delay, s32 sound_id, TObject *parent);
    virtual ~TUnk_804CCA90();
    virtual void run_task();

    s16 m_delay;
    s16 m_timer;
    s32 m_sound_id;
    Vec m_pos;
};
LAYOUT_ASSERT(TUnk_804CCA90_size, sizeof(TUnk_804CCA90) == 0x30);

#endif
