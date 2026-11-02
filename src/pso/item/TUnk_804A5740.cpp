#include "types.h"
#include "pso/player/TObjPlayer_8012CE9C.h"
#include "pso/player/TUnk_804A5740.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8012CF84.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012CFDC.h"
#include "pso/item/TItem.h"

extern "C" {

int rotate_matrix_x(void*, void*);
void __ct__11TItemWeaponFP7TObjectPUc(void *);
int get_player_list__10TObjPlayerFv(void*);

void TUnk_804A5740::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), 1820, 10922); }
void TUnk_804A5740::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), -1820, 0); }
void TUnk_804A5740::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) > 0) { rotate_matrix_x((void*)0, *(void* *)&this->unk_1F8); } }

extern s32 lbl_804A5740[];

void *TUnk_804A5740::init_state_1f8() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A5740;
    *(u32 *)&this->unk_1F8 = 10922;
    set_weapon_flags(1536);
    return this;
}

}

extern "C" {
u8 * init_state_1f8__13TUnk_804A5740Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_8012CF84(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_state_1f8__13TUnk_804A5740Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 lbl_804A5740[];

void *__dt__13TUnk_804A5740Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A5740;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
