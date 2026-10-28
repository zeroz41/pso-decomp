#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/unk/TUnk_804A2C90.h"
#include "pso/item/TItem.h"
#include "pso/player/TUnk_804A2D88.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 get_item_index__5TItemFv();
void TItemWeapon__ct(void *);

void TUnk_804A2C90::update_weapon() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 6) {
        ((TItemEquipBase *)arg0)->refresh_owner_stats();
    }
}

extern s32 lbl_804A2D88[];
extern s32 spawn_weapon_impact_effect[];

void *TUnk_804A2D88::init_with_update_handler() {
    TItemWeapon__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A2D88;
    (*(s32 * *)((u8 *)this + 0x1EC)) = spawn_weapon_impact_effect;
    return this;
}

}
