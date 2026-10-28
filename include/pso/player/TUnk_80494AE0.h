#ifndef PSO_PLAYER_TUNK_80494AE0_H
#define PSO_PLAYER_TUNK_80494AE0_H
#include "types.h"

class TUnk_80494AE0 {
public:
    u8 unk_0[0x4];
    float m_4;
    u8 unk_8[0x4];
    float m_c;
    u8 unk_10[0x4];
    virtual ~TUnk_80494AE0();
    virtual void set_rate_from_divisor(s32);
    virtual void vfunc_4();
    virtual void reset_obstruction_fade();
    virtual s32 decay_value_toward_floor();
    virtual s32 advance_toward_max();
    virtual void set_flags_and_apply_damage_color();
    virtual void clear_flag_and_notify();
    virtual s32 has_visible_opacity();
};

#endif
