#ifndef PSO_EFFECT_TEFFINDIRECTSAMPLER_H
#define PSO_EFFECT_TEFFINDIRECTSAMPLER_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Task that keeps an indirect (TEV distortion) effect of one kind registered
// while it lives.
class TEffIndirectSampler : public TObject {
public:
    TEffIndirectSampler(s32 kind, s32 sampler, TObject *parent);
    virtual ~TEffIndirectSampler();
    // Sets the indirect stages up for kind (this task's kind when negative).
    void enable_indirect_tev(s32, s16 kind);
    void disable_indirect_tev();

    u8 kind;
    s8 sampler;
    u8 pad_1E[0x2];
};
LAYOUT_ASSERT(TEffIndirectSampler_size, sizeof(TEffIndirectSampler) == 0x20);

void play_indirect_effect_recipe(u8 kind, u16 sampler, s32 second_stage);
// Makes sure an indirect (TEV distortion) effect controller of this kind exists.
void request_indirect_effect(s32 kind);
// Turns the indirect stage off again (stage 1 when second_stage, else 0).
void reset_indirect_tev(s32 second_stage);

#endif
