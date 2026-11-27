#ifndef PSO_ENEMY_TOBJENEMYCOLORFADE_H
#define PSO_ENEMY_TOBJENEMYCOLORFADE_H
#include "types.h"
#include "pso/render/MaterialColorFade.h"

class TObjEnemyColorFade : public MaterialColorFade {
public:
    TObjEnemyColorFade();
    virtual ~TObjEnemyColorFade();
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
    void update_fade_alpha();
    void init_death_params();
    void start_fade_in();
    f32 value;
};

LAYOUT_ASSERT(FadeValueOffset, offsetof(TObjEnemyColorFade, value) == 0x18);
LAYOUT_ASSERT(FadeValueSize, sizeof(TObjEnemyColorFade) == 0x1c);

#endif
