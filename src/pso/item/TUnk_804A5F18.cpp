#include "types.h"
#include "pso/player/TObjPlayer_8012EAA8.h"
#include "pso/player/TUnk_804A5F18.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecDeband.h"
#include "pso/misc/TTecSifta.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012ECA4.h"
#include "pso/item/TItem.h"

extern "C" {

int rotate_matrix_x(void*, void*);
void __ct__11TItemWeaponFP7TObjectPUc(void *);
int get_player_list__10TObjPlayerFv(void*);

void TObjPlayer::cast_shifta_deband() {
    s32 temp_r3;
    s32 temp_r3_2;

    if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
        if (get_tp() == 0) {
            temp_r3 = *(s32 *)&this->blend.frame[1];
            TTecDeband::create(temp_r3, temp_r3 + 0x38, 2);
        } else {
            temp_r3_2 = *(s32 *)&this->blend.frame[1];
            TTecSifta::create((void *)temp_r3_2, (void *)(temp_r3_2 + 0x38), (void *)2);
        }
        ((TItemWeapon *)this)->roll_technique();
        return;
    }
    update_active_game_effect();
}
void TUnk_804A5F18::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), 1820, 10922); }
void TUnk_804A5F18::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), -1820, 0); }
}
void s_red_blade_equip_rolls(void* p) { ((TItemWeapon *)p)->roll_technique(); ((TItemWeapon *)p)->roll_technique(); }
void s_red_blade_turn_node(void* p) { if (get_player_list__10TObjPlayerFv(p) == 1) { rotate_matrix_x((void*)0, *(void**)((char*)p + 0x1f8)); } }

extern s32 lbl_804A5F18[];

void *TObjPlayer::init_variant_a() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A5F18;
    *(u32 *)&this->unk_1F8 = 10922;
    ((TItemWeapon *)this)->set_weapon_flags(1570);
    set_effect_state(2);
    return this;
}

extern "C" {
u8 * init_variant_a__10TObjPlayerFv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_state_variant_a(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_variant_a__10TObjPlayerFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 lbl_804A5F18[];

void *__dt__13TUnk_804A5F18Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A5F18;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
