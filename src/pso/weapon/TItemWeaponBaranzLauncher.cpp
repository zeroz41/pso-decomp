#include "types.h"
#include "pso/player/TObjPlayer_80126460.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/system/task/TObject.h"
#include "pso/weapon/TUnk_804A2A58.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80126740.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"

u32 baranz_launcher_create_shot(void *player, s32 pos, s32 dir, f32 life) {
    uaddr model_shot;
    uaddr particle_shot;
    NJS_OBJECT *model;

    model_shot = TObjPlayer::create_shoot_model((uaddr)player, pos, dir, life);
    particle_shot = (uaddr)TObjPlayer::spawn_shoot_particle((saddr)player, pos, dir, life);
    if ((model_shot != 0U) && (particle_shot != 0U)) {
        model = ((TItemWeapon *)player)->second_model;
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
void TUnk_804A2A58::vfunc_60() { if (TObjPlayer::get_player_list() == 1) { rotate_matrix_y(NULL, rotation_y); } }


void TUnk_804A2A58::emit_marker_effects() {
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


void TUnk_804A2A58::update_weapon() {
    if (spin_speed > 0) {
        spin_speed -= 0x888;
        rotation_y -= 0x888;
    }
}

TUnk_804A2A58::~TUnk_804A2A58() {

}


TUnk_804A2A58::TUnk_804A2A58(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    shot_callback = (WeaponShotCallback)baranz_launcher_create_shot;
    spin_speed = 0;
    rotation_y = 0;
    shot_speed = 7.0f;
}

// ---- pso/unk/text_80126740


TItem *create_baranz_launcher(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2A58(tl_05, item);
    }
    return NULL;
}
