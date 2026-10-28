#include "types.h"
#include "pso/item/TUnk_804A3738.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A3738[];

void *TUnk_804A3738::init_vtable_804A3738() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3738;
    return this;
}

}
