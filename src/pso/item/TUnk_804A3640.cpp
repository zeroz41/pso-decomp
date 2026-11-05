#include "types.h"
#include "pso/item/TUnk_804A3640.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern s32 __vt__13TUnk_804A3640[];

TUnk_804A3640::~TUnk_804A3640() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TUnk_804A3640::init_with_id_2() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A3640;
    set_weapon_flags(2);
    return this;
}

}
