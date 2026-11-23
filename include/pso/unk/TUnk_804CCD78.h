#ifndef PSO_UNK_TUNK_804CCD78_H
#define PSO_UNK_TUNK_804CCD78_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// Zonde/Gizonde hit effect: spawns a particle effect at the struck point and
// lives for 70 frames.
class TUnk_804CCD78 : public TObject {
public:
    TUnk_804CCD78(Vec *hit_pos, Vec *source_pos, TObject *parent, s32 effect_id);
    virtual ~TUnk_804CCD78();
    virtual void run_task();

    Vec m_hit_pos;
    Vec m_source_pos;
    u8 pad_34[4];
    s32 m_timer;
    s32 m_effect_id;
};
LAYOUT_ASSERT(TUnk_804CCD78_size, sizeof(TUnk_804CCD78) == 0x40);

#endif
