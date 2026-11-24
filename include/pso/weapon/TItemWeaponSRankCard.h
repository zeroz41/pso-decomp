#ifndef PSO_WEAPON_TITEMWEAPONSRANKCARD_H
#define PSO_WEAPON_TITEMWEAPONSRANKCARD_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

// Weapon group 0xA7: the S-rank cards. On the third step of a combo they throw
// three cards in a fan and the held model is drawn three times.
class TItemWeaponSRankCard : public TUnk_804A4948 {
public:
    TItemWeaponSRankCard(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    virtual ~TItemWeaponSRankCard();
    virtual void transform_model_node();
    virtual void update_weapon();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    // The cane effect at the throw, on the first step of a combo only.
    void create_cane_if_ready(Vec *pos);

    u32 fan_flags; // bit 0 while the attack stage is 2: draw the two extra cards
};

#endif
