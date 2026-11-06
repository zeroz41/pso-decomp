#include "types.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TUnk_804A69C0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TUnk_804A69DC.h"
#include "pso/TItemAttacker.h"
#include "pso/map/FloorArea.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemShootModel_dtor.h"
#include "pso/player/TObjPlayer_80130778.h"
#include "pso/item/TUnk_804A6AD8.h"
#include "pso/TMainTask.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 is_owner_alive__15TItemShootModelFv();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *);

void TUnk_804A69C0::render() {
    u8 *arg0 = (u8 *)this;
    if ((is_owner_alive__15TItemShootModelFv() != 0) && ((u32) this->m_58 != 0U) && ((u32) this->m_5C != 0U)) {
        push_matrix();
        set_texlist(*(u32 *)&this->m_5C);
        post_translate_matrix(arg0 + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28);
        draw_ginja_object(this->m_58);
        pop_matrix();
    }
}

void TUnk_804A69C0::hook() {
    this->m_28 = (this->m_28 + 0xCCC);
}

extern s32 __vt__13TUnk_804A69C0[];

void *TUnk_804A69C0::init_shoot_model() {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A69C0;
    this->m_28 = 0;
    return this;
}

}

extern "C" {
s32 get_current_floor();
s32 update_technique_slot__10TTecRaFoieFl(int, int, int);
s32 play_sound_effect(int, int, int, int);
s32 init_shoot_model__13TUnk_804A69C0Fv(int, void *, void *, void *, f32);
s32 __nw__7TObjectFUl(int);
s32 create_shoot_model__10TObjPlayerFiiif(s32 arg0, s32 arg1, s32 arg2, f32 farg0);
void TObjPlayer__sub_801307D0(void *arg0);

s32 create_shoot_model__10TObjPlayerFiiif(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    s32 temp_r3;
    s32 var_r0;
    s32 var_r3;
    var_r3 = 0;
    if (arg0 != 0) {
        temp_r3 = __nw__7TObjectFUl(0x6C);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = init_shoot_model__13TUnk_804A69C0Fv((int)temp_r3, (void *)arg0, (void *)arg1, (void *)arg2, (f32)farg0);
        }
        var_r3 = var_r0;
    }
    return var_r3;
}

}

void TUnk_804A69DC::activate_effect(s32) {
    if (owner != NULL && is_current_area_item_enabled() != 0) {
        if (get_current_floor() == owner->get_floor() && get_mode() == 2) {
            update_technique_slot__10TTecRaFoieFl(play_sound_effect(0x4001AA05, (int)&owner->position, 0, 0), 0x300, 0);
            launch_shot((u8 *)&gun_point, 0, 0, 1);
        }
    }
}

void TUnk_804A69DC::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        get_gun_point(&gun_point);
        if (spin_speed > 0x1999) {
            send_activate_effect(0);
            TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)TObjPlayer__sub_801307D0, 0x1E);
            charge_ready = 0;
            return;
        }
        for_each_target_in_range(324.0f);
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

void TUnk_804A69DC::vfunc_60() {
    if (TObjPlayer::get_player_list() == 3) {
        rotate_matrix_x(0, rotation);
    }
}

void TUnk_804A69DC::reserved_53() {
    s32 *temp_r31;

    if ((u32) *(u32 *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1] != 0U) {
        temp_r31 = *(s32 **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)*(void **)&(*(s16 *)((u8 *)this + 0xF4)) + 0x2C)) + 0x30)) + 0x30);
        if (charge_ready == 0) {
            *temp_r31 |= 0x10;
        }
        draw_weapon_model();
        update_trail_slot(0);
        if (charge_ready == 0) {
            *temp_r31 &= 0xFFFFFFEF;
        }
    }
}

void TUnk_804A69DC::update_idle() {
    s32 speed;

    speed = spin_speed;
    if (speed > 0xCCC) {
        spin_speed = speed - 0xB6;
    }
}

void TUnk_804A69DC::update_attack() {
    s32 speed;

    attack_frames++;
    if (!(attack_frames & 3)) {
        speed = spin_speed;
        if (speed < 0x3333) {
            spin_speed = speed + 0xB6;
        }
    }
}

void TUnk_804A69DC::update_weapon() {
    advance_angle_wrap(&rotation, spin_speed);
}

TUnk_804A69DC::~TUnk_804A69DC() {}

TUnk_804A69DC::TUnk_804A69DC(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(35);
    shot_callback = (WeaponShotCallback)create_shoot_model__10TObjPlayerFiiif;
    rotation = 0;
    spin_speed = 3276;
    attack_frames = 0;
    charge_ready = 1;
}

u8 *TObjPlayer::create_state_35_alt(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A69DC(tl_05, (u8 *)arg0);
    }
    return NULL;
}

TUnk_804A69C0::~TUnk_804A69C0() {

}


void TObjPlayer__sub_801307D0(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x204) = 1;
    }
}

