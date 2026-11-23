#ifndef PSO_UNK_TUNK_804CC0E8_H
#define PSO_UNK_TUNK_804CC0E8_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// Anti's effect on the caster: starts its timed particle emitters at the
// body and at the feet, then removes itself on the next frame.
class TUnk_804CC0E8 : public TObject {
public:
    TUnk_804CC0E8(Vec *body_pos, Vec *ground_pos, u16 owner_id, TObject *parent);
    virtual ~TUnk_804CC0E8();
    virtual void run_task();

    u8 pad_1C[0x14];
    Vec m_body_pos;
    Vec m_ground_pos;
};
LAYOUT_ASSERT(TUnk_804CC0E8_size, sizeof(TUnk_804CC0E8) == 0x48);

#endif
