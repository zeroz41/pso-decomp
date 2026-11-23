#ifndef PSO_WEAPON_TUNK_804A5930_H
#define PSO_WEAPON_TUNK_804A5930_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Sealed J-Sword weapon class (old names
// TObjPlayer::update_weapon_kill_count, sealed_j_sword_start_timers,
// TObjPlayer__sub_8012D620): counts the owner's kills into the item's kill
// counter and becomes the unsealed sword (item code 00 32 00) on use once
// it reaches 23000. Made by sealed_j_sword_create.
class TUnk_804A5930 : public TItemWeapon {
public:
    virtual void use();
    virtual void update_weapon();
    virtual void on_equipped();
    virtual ~TUnk_804A5930();
    TUnk_804A5930(TObject *parent, u8 *item);

    s16 kill_count_seen; // 0x1F8: owner kill count already counted (inferred name)
};

TItem *sealed_j_sword_create(u8 *item);


#endif
