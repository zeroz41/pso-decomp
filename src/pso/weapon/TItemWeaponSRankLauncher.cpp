#include "pso/math/ClampedStep.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponSRankLauncher.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffLandHit.h"

extern "C" {
void get_weapon_color__11TItemWeaponFPv(void *, void *);
}

void TItemWeaponSRankLauncher::transform_model_node() {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, muzzle_offset, 0.0f);
    }
}

void TItemWeaponSRankLauncher::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    u8 color[16];
    desc->flags |= 0x39C;
    get_weapon_color__11TItemWeaponFPv(color, this);
    copy_argb(&desc->color, (NJS_ARGB *)color);
    desc->model = second_model;
    desc->hits = 4;
    desc->scale = 2.0f;
    desc->wall_effect = (void *)spawn_wall_hit_particles;
}

void TItemWeaponSRankLauncher::emit_marker_effects() {
    Vec position;

    get_gun_point(&position);
    spawn_particle_effect(&position, 9);
    spawn_light_task();
    fire_shot_at_target(&position, 0, 0);
}

void TItemWeaponSRankLauncher::update_idle() {
    ::approach_value(&muzzle_offset, 0.5f, 4.0f);
}

void TItemWeaponSRankLauncher::update_attack() {
    ::approach_value(&muzzle_offset, -1.0f, 0.0f);
}


TItemWeaponSRankLauncher::TItemWeaponSRankLauncher(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    set_weapon_flags(2);
    muzzle_offset = 0.0f;
}
TItem *TItemWeaponSRankLauncher::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankLauncher(tl_05, item);
    }
    return NULL;
}


TItemWeaponSRankLauncher::~TItemWeaponSRankLauncher() {}
