#include "types.h"
#include "pso/player/TUnk_804A5150.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012C128.h"
#include "pso/item/TItem.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
void __ct__11TItemWeaponFP7TObjectPUc(void *);

void TUnk_804A5150::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)-910), (s32)((void*)-7281)); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)-910), (s32)((void*)-9102)); }

void TUnk_804A5150::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)1820), (s32)((void*)0)); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)1820), (s32)((void*)0)); }

void TUnk_804A5150::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        rotate_matrix_z(0, -this->m_1fc);
        return;
    case 2:
        rotate_matrix_z(0, this->m_1fc);
        return;
    case 3:
        rotate_matrix_x(0, *(s32 *)&this->unk_1F8);
        return;
    }
}

extern s32 holy_ray_weapon_vtable[];
extern s32 spawn_shoot_particle_attached__10TItemShootFlllf[];
extern s32 spawn_target_needle[];
extern s32 spawn_needle_wall_impact[];

void *TUnk_804A5150::init_vtable_and_handlers() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = holy_ray_weapon_vtable;
    *(s32 **)((s8 *)this + 0x1F0) = spawn_shoot_particle_attached__10TItemShootFlllf;
    (*(s32 * *)((u8 *)this + 0x1F4)) = spawn_target_needle;
    (*(s32 * *)((u8 *)this + 0x1EC)) = spawn_needle_wall_impact;
    *(u32 *)&(this->m_1fc) = 0;
    *(u32 *)((s8 *)this + 0x1F8) = 0;
    return this;
}

}

extern "C" {
u8 * init_vtable_and_handlers__13TUnk_804A5150Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_handlers_state(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_vtable_and_handlers__13TUnk_804A5150Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 holy_ray_weapon_vtable[];

void *__dt__13TUnk_804A5150Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = holy_ray_weapon_vtable;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
