#ifndef PSO_WEAPON_TUNK_804E70A8_H
#define PSO_WEAPON_TUNK_804E70A8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804E70A8 : public TItemWeapon {
public:
    virtual ~TUnk_804E70A8();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    TUnk_804E70A8(TObject *parent, u8 *item);
    s32 pad_1f8;   // 5 at construction, counted down by update_weapon
    s32 pad_1fc;   // 182 * sin(pad_200) once pad_1f8 is 0
    s32 pad_200;   // angle, +0xB6 per update_weapon
};

#endif
