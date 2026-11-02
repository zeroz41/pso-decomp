#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012ECFC.h"
#include "pso/item/TUnk_804A6010.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012EDCC.h"

extern "C" {

s32 rotate_matrix_y(s32, s32);
}

void twinkle_star_turn_stars(void *arg0) {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x1F8));
        return;
    case 3:
        TItem::begin_effect_render();
        rotate_matrix_y(0, -*(s32 *)((s8 *)arg0 + 0x1F8));
    case 2:
        return;
    }
}

void TUnk_804A6010::update_weapon() {
    *(s32 *)&this->unk_1F8 = (s32) (*(s32 *)&this->unk_1F8 + 0xCCC);
}

extern s32 tl_05;

void TUnk_804A6010::emit_marker_effects() {
    s32 item = (s32)this;
    if (((TItemWeapon *)this)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)item, 2, 4);
    }
}

extern s32 lbl_804A6010[];

void *__dt__13TUnk_804A6010Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A6010;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A6010[];

void *TUnk_804A6010::set_state_0() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A6010;
    *(u32 *)&this->unk_1F8 = 0;
    return this;
}

}

extern "C" {
u8 * set_state_0__13TUnk_804A6010Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_state_0(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(set_state_0__13TUnk_804A6010Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
