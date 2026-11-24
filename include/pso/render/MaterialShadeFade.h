#ifndef PSO_RENDER_MATERIALSHADEFADE_H
#define PSO_RENDER_MATERIALSHADEFADE_H
#include "types.h"
#include "pso/render/MaterialColorFade.h"

// An enemy body fade in two stages over phase 0..2: the colour offset rises from
// black to full shade over 0..1, then the alpha offset rises over 1..2.
class MaterialShadeFade : public MaterialColorFade {
public:
    MaterialShadeFade();
    virtual ~MaterialShadeFade();
    virtual void set_flags_and_apply_damage_color();
    virtual s32 decay_value_toward_floor();
    virtual void set_rate_from_divisor(s32);
    virtual void reset_color();
    virtual void reset_obstruction_fade();
    virtual s32 advance_toward_max();
    virtual s32 has_visible_opacity();
    void calc_recoil_offsets();
    // Full colour, then decays: every caller is a death state.
    void start_fade_out();
    // From clear, then rises: the appear states (Dimedian beast_update_appear).
    void start_fade_in();
    f32 phase;
};

#endif
