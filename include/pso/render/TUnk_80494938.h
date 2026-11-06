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
    void sub_800D741C();
    void start_fade_in();
    f32 value;
};

// Unrecovered enclosing constructors call the native constructor by its ABI symbol.
extern "C" void *__ct__13TUnk_80494938Fv(void *);

typedef char FadeValueOffset[offsetof(TUnk_80494938, value) == 0x18 ? 1 : -1];
typedef char FadeValueSize[sizeof(TUnk_80494938) == 0x1c ? 1 : -1];

#endif
