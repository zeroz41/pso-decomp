#include "types.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/system/task/TObject.h"
#include "pso/weapon/TItemWeaponBaranzLauncher.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"

u32 baranz_launcher_create_shot(TItemWeapon *player, s32 pos, s32 dir, f32 life) {
    uaddr model_shot;
    uaddr particle_shot;
    NJS_OBJECT *model;

    model_shot = TObjPlayer::create_shoot_model((uaddr)player, pos, dir, life);
    particle_shot = (uaddr)TObjPlayer::spawn_shoot_particle((saddr)player, pos, dir, life);
    if ((model_shot != 0U) && (particle_shot != 0U)) {
        model = player->second_model;
        if (model != NULL) {
            model->evalflags &= ~NJD_EVAL_UNIT_ANG;
            model->ang[0] = 0x4000;
        }
        ((TItemShootParticle *)particle_shot)->spawn_slot_emitter(0x1BB, 0);
        ((TObject *)particle_shot)->set_parent((TObject *)model_shot);
    }
    return model_shot;
}

// Baranz Launcher (inferred)
void TItemWeaponBaranzLauncher::transform_model_node() { if (TObjPlayer::get_player_list() == 1) { rotate_matrix_y(NULL, rotation_y); } }


void TItemWeaponBaranzLauncher::emit_marker_effects() {
    Vec pos;
    spin_speed += 0x2AAA;
    if (is_model_shown() != 0) {
        get_joint_position(2, &pos);
        launch_shot((u8 *)&pos, 0, 0x4FA, 1);
        get_joint_position(3, &pos);
        launch_shot((u8 *)&pos, 1, 0xE38, 1);
        get_joint_position(4, &pos);
        launch_shot((u8 *)&pos, 2, -0x4FA, 1);
        get_joint_position(5, &pos);
        launch_shot((u8 *)&pos, 3, -0xE38, 1);
    }
}


void TItemWeaponBaranzLauncher::update_weapon() {
    if (spin_speed > 0) {
        spin_speed -= 0x888;
        rotation_y -= 0x888;
    }
}

TItemWeaponBaranzLauncher::~TItemWeaponBaranzLauncher() {

}


TItemWeaponBaranzLauncher::TItemWeaponBaranzLauncher(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    shot_callback = (WeaponShotCallback)baranz_launcher_create_shot;
    spin_speed = 0;
    rotation_y = 0;
    shot_speed = 7.0f;
}

// ---- pso/unk/text_80126740


TItem *TItemWeaponBaranzLauncher::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponBaranzLauncher(tl_05, item);
    }
    return NULL;
}
