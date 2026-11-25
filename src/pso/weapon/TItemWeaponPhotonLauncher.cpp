#include "pso/math/ClampedStep.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/weapon/TItemWeaponPhotonLauncher.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffLandHit.h"

extern "C" {
void get_weapon_color__11TItemWeaponFPv(void *, void *);
}

void TItemWeaponPhotonLauncher::transform_model_node() {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, muzzle_offset, 0.0f);
    }
}

void TItemWeaponPhotonLauncher::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    u8 sp8[16];
    desc->flags |= 0x11C;
    get_weapon_color__11TItemWeaponFPv(sp8, this);
    copy_argb(&desc->color, (NJS_ARGB *)sp8);
    desc->model = second_model;
    desc->hits = 4;
    desc->scale = 2.0f;
    desc->wall_effect = (void *)spawn_wall_hit_particles;
}

void TItemWeaponPhotonLauncher::emit_marker_effects() {
    Vec position;

    get_gun_point(&position);
    spawn_particle_effect(&position, 9);
    spawn_light_task();
    fire_shot_at_target(&position, 0, 0);
}

void TItemWeaponPhotonLauncher::update_idle() {
    ::approach_value(&muzzle_offset, 0.5f, 4.0f);
}

void TItemWeaponPhotonLauncher::update_attack() {
    ::approach_value(&muzzle_offset, -1.0f, 0.0f);
}

TItemWeaponPhotonLauncher::TItemWeaponPhotonLauncher(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    muzzle_offset = 0.0f;
}

TItem *TItemWeaponPhotonLauncher::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponPhotonLauncher(tl_05, item);
    }
    return NULL;
}

TItemWeaponPhotonLauncher::~TItemWeaponPhotonLauncher() {}
