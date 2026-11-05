#include "types.h"
#include "pso/item/TUnk_804A2868.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEffFlame.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProShield.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"

struct Obj_80125FB8 { u8 pad[0x1f8]; s32 a; };

struct Out_80125FB8 { u8 pad0[0x10]; s32 f10; u8 pad1[0x74 - 0x14]; void *f74; s32 f78; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
extern s32 lbl_804A2868[];
void TObjPlayer__sub_80125FB8(Obj_80125FB8 *self, Out_80125FB8 *o);


void TObjPlayer__sub_80125FB8(Obj_80125FB8 *self, Out_80125FB8 *o) {
    o->f78 = 0x1bb;
    o->f74 = (void *)spawn_flame_effect;
    o->f10 = self->a;
}

u8 *TObjPlayer__sub_80125FD8(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A2868;
    ((TItemWeapon *)arg0)->set_weapon_flags(0x8000);
    *(f32 *)((s8 *)arg0 + 0x1E4) = 5.0f;
    if (((TItem *)arg0)->get_item_index() == 1) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 0xA;
    } else {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 1;
    }
    return arg0;
}

u8 *TObjPlayer__sub_80126054(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_80125FD8((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}

}


void *__dt__13TUnk_804A2868Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A2868;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
