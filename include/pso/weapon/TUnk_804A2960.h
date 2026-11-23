#ifndef PSO_WEAPON_TUNK_804A2960_H
#define PSO_WEAPON_TUNK_804A2960_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The frozen shooter weapon class, made by frozen_shooter_create.
class TUnk_804A2960 : public TItemWeapon {
public:
    TUnk_804A2960(TObject *parent, u8 *item);
    virtual ~TUnk_804A2960();
    virtual void emit_marker_effects();
    virtual void on_equipped();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);

    s32 unk_1f8;     // 10 for item index 1, else 1; the descriptor's +0x10
    s32 skip_freeze; // set by the item index 1 shot: the descriptor gets no frozen_shooter_freeze_hit
    s32 unk_200;     // 0x1F5 for item index 1, else 0x95; the descriptor's +0x78
};

TItem *frozen_shooter_create(u8 *item);


#endif
