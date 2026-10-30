#ifndef PSO_MISC_MATERIALOPACITYFADE_H
#define PSO_MISC_MATERIALOPACITYFADE_H

#include "pso/misc/MaterialColorFade.h"

class MaterialOpacityFade : public MaterialColorFade {
public:
    MaterialOpacityFade();
    virtual ~MaterialOpacityFade();
    virtual void set_rate_from_divisor(s32);
    virtual void reset_color();
    virtual void reset_obstruction_fade();
    virtual s32 decay_value_toward_floor();
    virtual s32 advance_toward_max();
    virtual void set_flags_and_apply_damage_color();
    virtual s32 has_visible_opacity();
    s32 has_partial_opacity();
    s32 advance_to(f32 target);
    void update_alpha();
    void set_color(const NJS_ARGB *source);
    void set_rate(f32 value);
    void start_fade_out();
    void start_fade_in();
    f32 opacity;
};

// Legacy enclosing constructor bodies still invoke this constructor by its ABI symbol.
extern "C" void *__ct__19MaterialOpacityFadeFv(void *);

typedef char MaterialOpacityFadeOffset[offsetof(MaterialOpacityFade, opacity) == 0x18 ? 1 : -1];
typedef char MaterialOpacityFadeSize[sizeof(MaterialOpacityFade) == 0x1c ? 1 : -1];

#endif
