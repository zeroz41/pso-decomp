#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_801283B8.h"
#include "pso/player/TUnk_804A3B20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80128440.h"
#include "pso/item/TItemEquipVariant_80128498.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"

extern "C" {

void construct_srank_weapon(void *);

void srank_marker_noop(void) {  }

extern s32 tl_05;

void TUnk_804A3B20::vfunc_62() {
    s32 arg0 = (s32)this;
    if (((TItemWeapon *)arg0)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)arg0, 1, 2);
    }
}

extern s32 lbl_804A3B20[];

void *TUnk_804A3B20::init_state_vtable() {
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3B20;
    return this;
}

}

extern "C" {
u8 * init_state_vtable__13TUnk_804A3B20Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
u8 *TObjPlayer__sub_80128440(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_state_vtable__13TUnk_804A3B20Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 lbl_804A3B20[];

void *__dt__13TUnk_804A3B20Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3B20;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
