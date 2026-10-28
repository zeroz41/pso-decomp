#include "types.h"
#include "pso/item/TUnk_804A09B0.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

    extern unsigned char create_item_shoot_model__10TObjPlayerFiiif[];
    extern unsigned char lbl_804A09B0[];
    extern const float lbl_805DACB8;
void*TUnk_804A09B0::init_substate() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804A09B0; set_weapon_flags(34); *(int*)((char*)this + 0x1f0) = (int)create_item_shoot_model__10TObjPlayerFiiif; (*(float *)((u8 *)this + 0x1E4)) = lbl_805DACB8; return this; }

}
