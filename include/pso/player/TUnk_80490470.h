#ifndef PSO_PLAYER_TUNK_80490470_H
#define PSO_PLAYER_TUNK_80490470_H
#include "types.h"
#include "pso/player/TUnk_80494AE0.h"

class TUnk_80490470 : public TUnk_80494AE0 {
public:
    virtual ~TUnk_80490470();
    virtual void set_flags_and_apply_damage_color();
    virtual s32 decay_value_toward_floor();
    virtual void set_rate_from_divisor(s32);
    virtual void vfunc_4();
    virtual void reset_obstruction_fade();
    virtual s32 advance_toward_max();
    virtual s32 has_visible_opacity();
    void*init_vtable_and_field18();
    void calc_recoil_offsets();
    u8 unk_18[0x4];
};

#endif
