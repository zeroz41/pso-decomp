#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/weapon/TItemWeaponYasminkov2000H.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponYasminkov7000V.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"


// Yasminkov 7000V (inferred)
void TItemWeaponYasminkov7000V::transform_model_node() { if (TObjPlayer::get_player_list() == 1) { post_translate_matrix(&this->model_offset.x); } }

#pragma push
#pragma opt_common_subs off

void TItemWeaponYasminkov7000V::update_weapon() {
    f32 casing_velocity[3];
    s32 casing_angles[3];
    s32 angle;
    switch (this->state) {
    case 1:
        this->model_offset.y = (f32) (this->model_offset.y - 0.90000004f);
        if (this->model_offset.y <= 0.0f) {
            this->model_offset.y = 0.0f;
            this->state = 0;
            break;
        }
        break;
    case 2:
        this->model_offset.y += 0.90000004f;
        if (2.7f <= this->model_offset.y) {
            this->model_offset.y = 2.7f;
            this->state = 3;
            break;
        }
        break;
    case 3:
        this->state = 1;
        angle = this->owner->rotation_y - 0x4000;
        casing_velocity[0] = sin_table_lookup(angle);
        casing_velocity[1] = 1.0f;
        casing_velocity[2] = cos_table_lookup(angle);
        casing_angles[0] = 0x4000;
        casing_angles[1] = this->owner->rotation_y;
        casing_angles[2] = 0;
        TObjPlayer::launch_weapon_casing((saddr)tl_05, (uaddr) this, 2, (uaddr) &casing_velocity[0], (uaddr) &casing_angles[0]);
        break;
    }
}
#pragma pop

void TItemWeaponYasminkov7000V::emit_marker_effects() {
    Vec muzzle;
    this->state = 2;
    get_gun_point(&muzzle);
    spawn_particle_effect(&muzzle, 9);
}

TItemWeaponYasminkov7000V::~TItemWeaponYasminkov7000V() {

}

TItemWeaponYasminkov7000V::TItemWeaponYasminkov7000V(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = NULL;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    shot_speed = 20.0f;
    state = 0;
    model_offset.z = 0.0f;
    model_offset.y = 0.0f;
    model_offset.x = 0.0f;
}

TItem *TItemWeaponYasminkov7000V::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponYasminkov7000V(tl_05, item);
    }
    return NULL;
}
