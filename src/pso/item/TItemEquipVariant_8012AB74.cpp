#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012AB74.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern s32 lavis_cannon_weapon_vtable[];

void *__dt__13TUnk_804A4A88Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lavis_cannon_weapon_vtable;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
