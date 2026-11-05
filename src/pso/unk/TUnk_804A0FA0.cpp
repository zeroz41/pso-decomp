#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80122388.h"
#include "pso/item/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804A0FA0.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/unk/text_801224D4.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"

struct Self_801223E0 { u8 pad[0x1f8]; f32 f1f8; };

extern "C" {
u8 * guld_milla_ct(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void scale_matrix(s32, f32, f32, f32);

void vfunc_60__13TUnk_804A0FA0Fv(Self_801223E0 *self);
}
u8 *create_guld_milla(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x210));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(guld_milla_ct(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

void TUnk_804A0FA0::vfunc_60() {
    if (((TItem *)((Self_801223E0 *)this))->get_item_index() == 5) {
        s32 n = TObjPlayer::get_player_list();
        switch (n) {
        case 3:
        case 4:
            scale_matrix(0, 1.0f, ((Self_801223E0 *)this)->f1f8, ((Self_801223E0 *)this)->f1f8);
            break;
        }
    }
}

extern "C" {

u8 get_item_index__5TItemFv();

void TUnk_804A0FA0::update_idle() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)0.2f, (f32)0.0f);
    }
}

void TUnk_804A0FA0::update_attack() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)0.5f, (f32)1.0f);
    }
}

}

extern "C" {
u8 *__nw__5TItemFUl(s32);
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
}
extern s32 __vt__13TUnk_804A0FA0[];

u8 *construct_dagger_weapon(u8 *player, u8 *arg1, u8 *arg2) {
    u8 temp_r0;
    __ct__11TItemWeaponFP7TObjectPUc(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = __vt__13TUnk_804A0FA0;
    ((TItemWeapon *)player)->set_weapon_flags(0x600);
    *(f32 *)((s8 *)player + 0x1F8) = (f32) 1.0f;
    temp_r0 = *(u8 *)((s8 *)arg2 + 2);
    if ((temp_r0 >= 5U) && (temp_r0 != 7)) {
        ((TObjPlayer *)player)->set_atp(-1);
    }
    return player;
}

u8 *create_dagger_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_dagger_weapon((u8 *)temp_r3, (u8 *)tl_05, (u8 *)arg0));
        }
        return var_r0;
    }
    return NULL;
}

TUnk_804A0FA0::~TUnk_804A0FA0() {}
