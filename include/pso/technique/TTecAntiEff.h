#ifndef PSO_TECHNIQUE_TTECANTIEFF_H
#define PSO_TECHNIQUE_TTECANTIEFF_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// Anti's effect on the caster: starts its timed particle emitters at the
// body and at the feet, then removes itself on the next frame.
class TTecAntiEff : public TObject {
public:
    TTecAntiEff(Vec *body_pos, Vec *ground_pos, u16 owner_id, TObject *parent);
    virtual ~TTecAntiEff();
    virtual void run_task();

    u8 pad_1C[0x14];
    Vec m_body_pos;
    Vec m_ground_pos;
};
LAYOUT_ASSERT(TTecAntiEff_size, sizeof(TTecAntiEff) == 0x48);

#endif
