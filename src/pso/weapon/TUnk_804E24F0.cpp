#include "pso/math/ClampedStep.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/weapon/TUnk_804E24F0.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
void get_weapon_color__11TItemWeaponFPv(void *, void *);
}

void TUnk_804E24F0::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, muzzle_offset, 0.0f);
    }
}

void TUnk_804E24F0::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    u8 sp8[16];
    desc->flags |= 0x11C;
    get_weapon_color__11TItemWeaponFPv(sp8, this);
    copy_argb(&desc->color, (NJS_ARGB *)sp8);
    desc->model = second_model;
    desc->hits = 4;
    desc->scale = 2.0f;
    desc->wall_effect = (void *)TObjPlayer::forward_item_effect_callback;
}

void TUnk_804E24F0::emit_marker_effects() {
    Vec position;

    get_gun_point(&position);
    spawn_particle_effect(&position, 9);
    spawn_light_task();
    fire_shot_at_target(&position, 0, 0);
}

void TUnk_804E24F0::update_idle() {
    ::approach_value(&muzzle_offset, 0.5f, 4.0f);
}

void TUnk_804E24F0::update_attack() {
    ::approach_value(&muzzle_offset, -1.0f, 0.0f);
}

TUnk_804E24F0::TUnk_804E24F0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    muzzle_offset = 0.0f;
}

TItem *TUnk_804E24F0::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804E24F0(tl_05, item);
    }
    return NULL;
}

TUnk_804E24F0::~TUnk_804E24F0() {}
