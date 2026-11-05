#include "types.h"
#include "pso/item/TUnk_804A09B0.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern s32 __vt__13TUnk_804A09B0[];

TUnk_804A09B0::~TUnk_804A09B0() {}

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

    extern unsigned char create_item_shoot_model__10TObjPlayerFiiif[];
void*TUnk_804A09B0::init_substate() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)__vt__13TUnk_804A09B0; set_weapon_flags(34); *(int*)((char*)this + 0x1f0) = (int)create_item_shoot_model__10TObjPlayerFiiif; (*(float *)((u8 *)this + 0x1E4)) = 10.0f; return this; }

}
