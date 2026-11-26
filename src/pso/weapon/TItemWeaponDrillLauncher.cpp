#include "pso/effect/TEffStarLight2D.h"
#include "pso/weapon/TItemWeaponDrillLauncher.h"
#include "pso/weapon/TItemWeaponEvilCurst.h"
#include "pso/weapon/shoot/TItemShootDrillLauncher.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/item/TItemFollowStarLight.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/system/task/TObject.h"


#include "pso/weapon/TItemWeapon.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"

struct TItemEquipBase;
#include "pso/weapon/shoot/TItemShootParticle.h"

#include "pso/weapon/TItemAttacker.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/camera/TObjCamera.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"
#include "pso/weapon/SpecialProjectileWeapons.h"

saddr drill_launcher_create_shot(saddr owner, saddr pos, saddr dir, f32 life);


void TItemShootDrillLauncher::render() {
    NJS_OBJECT *render_node;
    NJS_OBJECT *object;

    if (TItemShootModel::is_owner_alive() != 0) {
        object = (NJS_OBJECT *) (this->model);
        if ((object != NULL) && ((uaddr) this->texture_list != 0U)) {
            render_node = object->child->sibling;
            render_node->evalflags = (u32) (render_node->evalflags & 0xFFFFFFFB);
            render_node->scl[0] = (f32) 10.0f;
            push_matrix();
            set_texlist(this->texture_list);
            post_translate_matrix(&this->m_pos.x);
            rotate_matrix_y(0, this->rot_y);
            rotate_matrix_x(0, this->rot_x - 0x4000);
            draw_ginja_object((this->model));
            pop_matrix();
            render_node->scl[0] = (f32) 1.0f;
        }
    }
}

void TItemShootDrillLauncher::hook() {  }

TItemShootDrillLauncher::TItemShootDrillLauncher(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {}

saddr drill_launcher_create_shot(saddr owner, saddr pos, saddr dir, f32 life) {
    TItemShootDrillLauncher *shot = NULL;
    TItemShootParticle *particle;

    if (owner != 0) {
        shot = new TItemShootDrillLauncher((void *)owner, (const Vec *)pos, (const Vec *)dir, life);
    }
    particle = (TItemShootParticle *)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (particle != NULL) {
        particle->spawn_slot_emitter(0x1BB, 0);
    }
    return (saddr)shot;
}

void TItemWeaponDrillLauncher::emit_marker_effects() {
    Vec gun_point;
    saddr burst_slot;
    s32 burst_added;
    if (projectile_visible == 1) {
        TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)drill_launcher_return_timer, 0x1E);
        projectile_visible = 0;
    }
    recoil_phase = 2;
    burst_slot = (saddr)owner + 0x7CC;
    if (get_burst_counter((void*)burst_slot) == 0) {
        burst_added = 0;
        do {
            increment_burst_counter((u8 *)burst_slot);
            burst_added += 1;
        } while (burst_added != 2);
    }
    get_gun_point(&gun_point);
    if (is_mode_two_and_ready() != 0) {
        launch_rare_weapon_special(&gun_point, 1, (f32) (1.0f));
        return;
    }
    launch_shot((u8 *)&gun_point, 0, 0, 1);
}
void TItemWeaponDrillLauncher::transform_model_node() {
    s32 player_list;
    player_list = TObjPlayer::get_player_list();
    if ((player_list > 0) && (player_list < 4)) {
        rotate_matrix_z(0, recoil_angle);
        return;
    }
    if (player_list == 4) {
        if (second_model != 0U) {
            if ((s32) projectile_visible == 1) {
                draw_ginja_object(second_model);
            }
        }
    }
}

void TItemWeaponDrillLauncher::update_weapon() {
    NJS_OBJECT *second;
    NJS_OBJECT *angled;
    projectile_spin = (projectile_spin + 0x1999);
    second = (NJS_OBJECT *)this->second_model;
    if (second != NULL) {
        angled = second->child;
        angled->evalflags = (u32) (angled->evalflags & 0xFFFFFFFD);
        angled->ang[1] = (s32) projectile_spin;
    }
    switch (recoil_phase) {
    case 1:
        recoil_angle = (s32) (recoil_angle + 0xE38);
        if ((s32) recoil_angle >= 0) {
            recoil_angle = 0;
            recoil_phase = 0;
        }
        return;
    case 2:
        recoil_angle = (s32) (recoil_angle - 0xE38);
        if ((s32) recoil_angle <= -0x31C7) {
            recoil_angle = -0x31C7;
            recoil_phase = 3;
            return;
        }
        break;
    case 3:
        recoil_phase = 1;
        return;
    }
}
TItemWeaponDrillLauncher::~TItemWeaponDrillLauncher() {

}
TItemWeaponDrillLauncher::TItemWeaponDrillLauncher(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = (WeaponShotCallback)drill_launcher_create_shot;
    shot_speed = 9.0f;
    set_weapon_flags(0x22);
    projectile_visible = 1;
    projectile_spin = 0;
    recoil_angle = 0;
}

TItem *TItemWeaponDrillLauncher::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponDrillLauncher(tl_05, item);
    }
    return NULL;
}

TItemShootDrillLauncher::~TItemShootDrillLauncher() {

}
void drill_launcher_return_timer(void *weapon) {
    if (weapon != NULL) {
        ((TItemWeaponDrillLauncher *)weapon)->projectile_visible = 1;
    }
}

void increment_burst_counter(u8 *counter) {
    *(s32 *)((s8 *)counter + 0x18) = (s32) (*(s32 *)((s8 *)counter + 0x18) + 1);
}
s32 get_burst_counter(void* p) { return *(s32*)((char*)p + 0x18); }
