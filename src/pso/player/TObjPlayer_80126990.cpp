#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/player/TUnk_804A2B98.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 knuckle_second_hand_pass;

void TUnk_804A2B98::reserved_53() {
    s32 arg0 = (s32)this;
    if (get_item_index() == 3) {
        knuckle_second_hand_pass = 0;
        ((TItemWeapon *)arg0)->draw_weapon_model();
        knuckle_second_hand_pass = 1;
        draw_weapon_at_joint(arg0, 0x23);
    }
}

extern s32 lbl_804A2B98[];

void *TUnk_804A2B98::init_vtable_and_flags() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A2B98;
    set_weapon_flags(577);
    return this;
}

}
