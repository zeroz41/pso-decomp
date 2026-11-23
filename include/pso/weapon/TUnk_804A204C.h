#ifndef PSO_WEAPON_TUNK_804A204C_H
#define PSO_WEAPON_TUNK_804A204C_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A204C : public TItemWeapon {
public:
    TUnk_804A204C(TObject *parent, u8 *item);
    virtual ~TUnk_804A204C();
    virtual void on_equipped();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    static TItem *create(u8 *item);

    u32 pad_1f8;
    s32 swing_direction;  // 1 while swing_angle climbs to 0x2000, 0 while it falls to -0x2000
    s32 swing_angle;      // the model's swing about y, drawn by vfunc_60
    s32 floor_area;       // floor update_weapon last spawned its star light on
};
LAYOUT_ASSERT(TUnk_804A204C_size, sizeof(TUnk_804A204C) == 0x208);

#endif
