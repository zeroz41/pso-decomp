#include "types.h"
#include "pso/player/TUnk_804A4A88.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8012AB1C.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012AB74.h"
#include "pso/item/TItem.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);
int __ct__11TItemWeaponFP7TObjectPUc(void);


void TUnk_804A4A88::emit_marker_effects() {
    s32 arg0 = (s32)this;
    if (is_mode_two_and_ready() != 0) {
        ((TObjPlayer *)arg0)->drain_owner_hp_fraction(0.05f);
        ((TObjPlayer *)arg0)->launch_rare_weapon_special(0, 1, 1.0f);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

void TUnk_804A4A88::vfunc_60() {
    if (TObjPlayer::get_player_list() == 2) {
        rotate_matrix_z(0, *(s32 *)&this->unk_1F8);
        advance_angle_wrap((s32 *)&this->unk_1F8, 0x1999);
    }
}

    extern unsigned char create_lavis_shot[];
    extern s32 __vt__13TUnk_804A4A88[];
void*TUnk_804A4A88::init_state_object() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)__vt__13TUnk_804A4A88; set_weapon_flags(34); *(int*)((char*)this + 0x1f0) = (int)create_lavis_shot; (*(float *)((u8 *)this + 0x1E4)) = 10.0f; *(int *)&this->unk_1F8 = 0; return this; }

}

extern "C" {
u8 * init_state_object__13TUnk_804A4A88Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_8012AB1C(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_state_object__13TUnk_804A4A88Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}


TUnk_804A4A88::~TUnk_804A4A88() {}
