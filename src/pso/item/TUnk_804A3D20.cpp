#include "types.h"
#include "pso/player/TUnk_804A3D20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_801286D0.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"

extern "C" {

void construct_srank_weapon(void *);

extern s32 lbl_804A3D20[];
extern s32 spawn_weapon_impact_effect[];

void *TUnk_804A3D20::setup_shoot_model_callback() {
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3D20;
    (*(s32 * *)((u8 *)this + 0x1EC)) = spawn_weapon_impact_effect;
    return this;
}

}

extern "C" {
u8 * setup_shoot_model_callback__13TUnk_804A3D20Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_shoot_model_callback(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(setup_shoot_model_callback__13TUnk_804A3D20Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 lbl_804A3D20[];

void *__dt__13TUnk_804A3D20Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3D20;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
