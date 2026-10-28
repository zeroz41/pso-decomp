#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern "C" {


extern s32 __vt__11TItemWeapon[];

void *__dt__11TItemWeaponFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TItemWeapon;
        __dt__14TItemEquipBaseFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}
