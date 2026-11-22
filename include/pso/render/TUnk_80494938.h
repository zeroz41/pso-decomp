#ifndef PSO_RENDER_TUNK_80494938_H
#define PSO_RENDER_TUNK_80494938_H
#include "types.h"
#include "pso/render/MaterialColorFade.h"

class TUnk_80494938 : public MaterialColorFade {
public:
    TUnk_80494938();
    virtual ~TUnk_80494938();
    virtual void set_rate_from_divisor(s32);
    virtual void reset_color();
    virtual void reset_obstruction_fade();
    virtual s32 decay_value_toward_floor();
    virtual s32 advance_toward_max();
    virtual void set_flags_and_apply_damage_color();
    virtual s32 has_visible_opacity();
    // value strictly between hidden (0) and opaque (2).
    s32 has_partial_opacity();
    s32 advance_timer(f32 limit);
    void copy_color(NJS_ARGB *src);
    void set_rate(f32 new_rate);
    void sub_800D741C();
    void init_death_params();
    void start_fade_in();
    f32 value;
};

// Unrecovered enclosing constructors call the native constructor by its ABI symbol.
extern "C" void *__ct__13TUnk_80494938Fv(void *);

LAYOUT_ASSERT(FadeValueOffset, offsetof(TUnk_80494938, value) == 0x18);
LAYOUT_ASSERT(FadeValueSize, sizeof(TUnk_80494938) == 0x1c);

#endif
