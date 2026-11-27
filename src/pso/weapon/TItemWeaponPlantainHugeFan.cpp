#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponPlantainHugeFan.h"
#include "pso/weapon/shoot/TItemShootPlantainHugeFan.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"

void TItemShootPlantainHugeFan::render() {
    if ((is_owner_alive() != 0) && ((uaddr)model != 0U) && ((uaddr)texture_list != 0U)) {
        push_matrix();
        TParticleCtrl::begin_effect_render();
        set_texlist(texture_list);
        post_translate_matrix(&m_pos.x);
        rotate_matrix_by_node_angles(&rot.x, 1);
        draw_ginja_object(model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TItemShootPlantainHugeFan::hook() {
    rot.z = rot.z + 0x3333;
}

TItemShootPlantainHugeFan::TItemShootPlantainHugeFan(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    rot.z = 0;
}

TItemShoot *TObjPlayer::create_item_shoot_model(TItemWeapon *weapon, const Vec *origin, const Vec *end, f32 frames) {
    TItemShootPlantainHugeFan *model = NULL;
    if (weapon != NULL) {
        model = new TItemShootPlantainHugeFan(weapon, origin, end, frames);
    }
    return model;
}

void TItemWeaponPlantainHugeFan::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)this)->launch_rare_weapon_special(NULL, 1, 1.0f);
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

TItemWeaponPlantainHugeFan::~TItemWeaponPlantainHugeFan() {}

TItemWeaponPlantainHugeFan::TItemWeaponPlantainHugeFan(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    shot_callback = TObjPlayer::create_item_shoot_model;
    shot_speed = 10.0f;
}

TItem *TItemWeaponPlantainHugeFan::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponPlantainHugeFan(tl_05, item);
    }
    return NULL;
}

TItemShootPlantainHugeFan::~TItemShootPlantainHugeFan() {}
