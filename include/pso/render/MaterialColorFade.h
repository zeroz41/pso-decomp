#ifndef PSO_RENDER_MATERIALCOLORFADE_H
#define PSO_RENDER_MATERIALCOLORFADE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

class MaterialColorFade {
public:
    MaterialColorFade();
    NJS_ARGB color;
    f32 rate;
    virtual ~MaterialColorFade();
    virtual void set_rate_from_divisor(s32);
    virtual void reset_color();
    virtual void reset_obstruction_fade();
    virtual s32 decay_value_toward_floor();
    virtual s32 advance_toward_max();
    virtual void set_flags_and_apply_damage_color();
    virtual void clear_flag_and_notify();
    virtual s32 has_visible_opacity();
    void set_speed(f32 v);
    // The fade's color (callers read its alpha); defined in the Re4 Sorcerer unit.
    NJS_ARGB *get_color();
};

#include <stddef.h>
LAYOUT_ASSERT(MaterialColorFadeColorOffset, offsetof(MaterialColorFade, color) == 0);
LAYOUT_ASSERT(MaterialColorFadeRateOffset, offsetof(MaterialColorFade, rate) == 0x10);
LAYOUT_ASSERT(MaterialColorFadeSize, sizeof(MaterialColorFade) == 0x18);

#endif
