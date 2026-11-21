#ifndef PSO_WEAPON_TUNK_804F1320_H
#define PSO_WEAPON_TUNK_804F1320_H
#include <stddef.h>
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804F1320 : public TItemWeapon {
public:
    TUnk_804F1320(TObject *parent, u8 *item);
    virtual ~TUnk_804F1320();
    virtual void activate_effect(s32);
    void spawn_pg_effect(const Vec *origin, saddr item, f32 radius);
    virtual void emit_marker_effects();
    f32 effect_radius;
};

LAYOUT_ASSERT(TUnk_804F1320_size, sizeof(TUnk_804F1320) == 0x1FC);
LAYOUT_ASSERT(TUnk_804F1320_radius_offset, offsetof(TUnk_804F1320, effect_radius) == 0x1F8);

#endif
