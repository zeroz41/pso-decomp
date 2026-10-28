#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/player/TUnk_804A2B98.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 get_item_index__5TItemFv();
void TItemWeapon__ct(void *);
void set_status_flags__10TObjPlayerFUl(void *, int);

extern s32 knuckle_second_hand_pass;

void TUnk_804A2B98::reserved_53() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 3) {
        knuckle_second_hand_pass = 0;
        ((TItemWeapon *)arg0)->draw_weapon_model();
        knuckle_second_hand_pass = 1;
        draw_weapon_at_joint(arg0, 0x23);
    }
}

extern s32 lbl_804A2B98[];

void *TUnk_804A2B98::init_vtable_and_flags() {
    TItemWeapon__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A2B98;
    set_status_flags__10TObjPlayerFUl(this, 577);
    return this;
}

}
