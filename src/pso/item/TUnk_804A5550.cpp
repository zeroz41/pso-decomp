#include "types.h"
#include "pso/item/TUnk_804A5550.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012CBC4.h"
#include "pso/unk/text_8012CC74.h"
#include "pso/item/TUnk_804A5648.h"

extern "C" {

u8 get_item_index__5TItemFv();

void TUnk_804A5550::update_weapon() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        ((TItemEquipBase *)arg0)->refresh_owner_stats();
    }
}

}

extern s32 __vt__13TUnk_804A5550[];

TUnk_804A5550::~TUnk_804A5550() {}

extern "C" {

s32 __ct__11TItemWeaponFP7TObjectPUc();

extern s32 __vt__13TUnk_804A5550[];

void *TObjPlayer::init_state(s32 arg1, void *arg2) {
    __ct__11TItemWeaponFP7TObjectPUc();
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A5550;
    if ((u8) *(u8 *)((s8 *)arg2 + 2) >= 5U) {
        set_atp(-1);
    }
    return this;
}

}


extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;

u8 *create_saber_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((TObjPlayer *)temp_r3)->init_state(tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
