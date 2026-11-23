#ifndef PSO_EFFECT_TEFFCLITICAL_H
#define PSO_EFFECT_TEFFCLITICAL_H

#include "types.h"
#include "pso/effect/TEffect.h"

// The ring and particle burst of a critical hit.
class TEffClitical : public TEffect {
public:
    TEffClitical(Vec *pos);
    virtual ~TEffClitical();
    virtual void run_task();
    virtual void render();
    static void create(Vec *pos);

    static f32 alpha_approach_step;
    static const char *class_name;

    s32 frame;  // frame of the ring texture, 0..6
    s32 phase;  // 0 until the burst particles are spawned
};

LAYOUT_ASSERT(TEffCliticalSize, sizeof(TEffClitical) == 0x78);

void init_texture_copy_rect(TextureFrameSlot *slot, NJS_TEXLIST *texlist, NJS_TEXLIST *frames, s32 slot_index,
                            s32 frame);
void approach_position_if_far(Vec *from, Vec *to, f32 rate);

#endif
