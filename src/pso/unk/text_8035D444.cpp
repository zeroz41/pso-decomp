#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/unk/text_8035D444.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_8035D49C.h"

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

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
u8 *fn_8035D49C(u8 *player, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = ruby_bullet_weapon_vtable;
    ((TItemWeapon *)player)->set_weapon_flags(0x8000);
    return player;
}
}

u8 *alloc_and_init_obj_effect(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(fn_8035D49C((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
