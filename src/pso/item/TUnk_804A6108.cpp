#include "types.h"
#include "pso/player/TUnk_804A6108.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8012EFAC.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F004.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);
void __ct__11TItemWeaponFP7TObjectPUc(void *);

void TUnk_804A6108::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_z(0, *(s32 *)&this->unk_1F8);
        return;
    case 2:
        TItem::begin_effect_render();
        rotate_matrix_z(0, -*(s32 *)&this->unk_1F8);
        return;
    case 3:
        TItem::begin_effect_render();
        return;
    }
}
void TUnk_804A6108::update_weapon() { advance_angle_wrap((s32 *)((char*)this + 0x1f8), 3276); }

extern s32 __vt__13TUnk_804A6108[];

void *TUnk_804A6108::init_effect_state() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A6108;
    *(u32 *)&this->unk_1F8 = 0;
    return this;
}

}

extern "C" {
u8 * init_effect_state__13TUnk_804A6108Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_8012EFAC(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_effect_state__13TUnk_804A6108Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 __vt__13TUnk_804A6108[];

TUnk_804A6108::~TUnk_804A6108() {}
