#ifndef PSO_WEAPON_TITEMWEAPONEVILCURST_H
#define PSO_WEAPON_TITEMWEAPONEVILCURST_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponEvilCurst : public TItemWeapon {
public:
    TItemWeaponEvilCurst(TObject *parent, u8 *item);
    virtual ~TItemWeaponEvilCurst();
    virtual void on_equipped();
    virtual void transform_model_node();
    virtual void draw_held_model();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    static TItem *create(u8 *item);

    u32 pad_1f8;
    s32 swing_direction;  // 1 while swing_angle climbs to 0x2000, 0 while it falls to -0x2000
    s32 swing_angle;      // the model's swing about y, drawn by transform_model_node
    s32 floor_area;       // floor update_weapon last spawned its star light on
};
LAYOUT_ASSERT(TItemWeaponEvilCurst_size, sizeof(TItemWeaponEvilCurst) == 0x208);

#endif
