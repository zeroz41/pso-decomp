#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A0AC4.h"

extern s32 lbl_804A0AC4[];

void *__dt__13TUnk_804A0AC4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A0AC4;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

    extern unsigned char create_item_shoot_model__10TObjPlayerFiiif[];
    extern const float lbl_805DACC4;
void*TUnk_804A0AC4::init_state_34() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804A0AC4; set_weapon_flags(34); *(int*)((char*)this + 0x1f0) = (int)create_item_shoot_model__10TObjPlayerFiiif; (*(float *)((u8 *)this + 0x1E4)) = lbl_805DACC4; return this; }

}
