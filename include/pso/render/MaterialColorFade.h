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
};

#include <stddef.h>
typedef char MaterialColorFadeColorOffset[offsetof(MaterialColorFade, color) == 0 ? 1 : -1];
typedef char MaterialColorFadeRateOffset[offsetof(MaterialColorFade, rate) == 0x10 ? 1 : -1];
typedef char MaterialColorFadeSize[sizeof(MaterialColorFade) == 0x18 ? 1 : -1];

#endif
