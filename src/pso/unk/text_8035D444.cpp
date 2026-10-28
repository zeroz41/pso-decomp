#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/unk/text_8035D444.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern s32 ruby_bullet_weapon_vtable[];

void *__dt__13TUnk_804F1EC8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = ruby_bullet_weapon_vtable;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
