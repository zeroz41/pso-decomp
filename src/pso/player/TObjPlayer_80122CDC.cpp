#include "types.h"
#include "pso/player/TUnk_804A1478.h"
#include "pso/player/TObjPlayer.h"
#include "pso/items/TItemWeapon.h"

extern "C" {

u8 get_item_index__5TItemFv();
void TItemWeapon__ct(void *);

extern s32 tl_05;

void TUnk_804A1478::emit_marker_effects() {
    s32 item = (s32)this;
    if ((get_item_index__5TItemFv() < 4U) && (((TItemWeapon *)item)->get_attack_stage() == 0)) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)item, 1, 2);
    }
}

extern s32 lbl_804A1478[];

void *TUnk_804A1478::set_vtable_804A1478() {
    TItemWeapon__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A1478;
    return this;
}

}
