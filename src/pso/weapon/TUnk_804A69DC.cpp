#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/weapon/shoot/TUnk_804A69C0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/weapon/TUnk_804A69DC.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/map/FloorArea.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A6AD8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"

extern "C" s32 post_translate_matrix(void *);

void TUnk_804A69C0::render() {
    u8 *arg0 = (u8 *)this;
    if ((TItemShootModel::is_owner_alive() != 0) && ((uaddr) this->model != 0U) && ((uaddr) this->texture_list != 0U)) {
        push_matrix();
        set_texlist(this->texture_list);
        post_translate_matrix(arg0 + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

void TUnk_804A69C0::hook() {
    this->m_28 = (this->m_28 + 0xCCC);
}

TUnk_804A69C0::TUnk_804A69C0(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    m_28 = 0;
}

saddr create_shoot_model(saddr owner, saddr pos, saddr dir, f32 life) {
    TUnk_804A69C0 *shot = NULL;
    if (owner != 0) {
        shot = new TUnk_804A69C0((void *)owner, (const Vec *)pos, (const Vec *)dir, life);
    }
    return (saddr)shot;
}

void TUnk_804A69DC::activate_effect(s32) {
    if (owner != NULL && is_current_area_item_enabled() != 0) {
        if (get_current_floor() == owner->get_floor() && get_mode() == 2) {
            set_sound_pitch_request(play_sound_effect(0x4001AA05, &owner->position, 0, 0), 0x300, 0);
            launch_shot((u8 *)&gun_point, 0, 0, 1);
        }
    }
}

void TUnk_804A69DC::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        get_gun_point(&gun_point);
        if (spin_speed > 0x1999) {
            send_activate_effect(0);
            TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)charge_ready_timer, 0x1E);
            charge_ready = 0;
            return;
        }
        for_each_target_in_range(324.0f);
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
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
    shot_callback = (WeaponShotCallback)create_shoot_model;
    rotation = 0;
    spin_speed = 3276;
    attack_frames = 0;
    charge_ready = 1;
}

TItem *TObjPlayer::create_state_35_alt(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A69DC(tl_05, item);
    }
    return NULL;
}

TUnk_804A69C0::~TUnk_804A69C0() {

}


void charge_ready_timer(void *weapon) {
    if (weapon != NULL) {
        ((TUnk_804A69DC *)weapon)->charge_ready = 1;
    }
}

