#include "types.h"
#include "pso/item/TUnk_804A4E68.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 imperial_pick_weapon_vtable[];

void *TUnk_804A4E68::init_vtable_and_clear_field1f8() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = imperial_pick_weapon_vtable;
    *(u32 *)&this->unk_1F8 = 0;
    return this;
}

}
