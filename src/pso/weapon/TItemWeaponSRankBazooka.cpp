#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponSRankBazooka.h"
#include "pso/effect/item/TItemEffFlame.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

// Slides the barrel back by barrel_offset (the name s_rank_bazooka_slide_barrel was inferred).
void TItemWeaponSRankBazooka::transform_model_node() {
    if (get_model_node_counter() == 1) {
        translate_matrix(0, 0.0f, (-1.0f) * barrel_offset, 0.0f);
    }
}

// The recoil after a shot (the name s_rank_bazooka_recoil was inferred): the barrel
// slides back, throws a casing, then returns.
void TItemWeaponSRankBazooka::update_weapon() {
    s32 ang;
    Vec v;
    s32 a[3];
    if (recoil_state == 1) {
        ::approach_value(&barrel_offset, (-0.5f), (-2.0f));
        if ((-2.0f) == barrel_offset) {
            recoil_state = 2;
            ang = owner->rotation_y + 0x4000;
            v.x = sin_table_lookup(ang);
            v.y = 0.0f;
            v.z = cos_table_lookup(ang);
            a[0] = 0x4000;
            a[1] = owner->rotation_y;
            a[2] = 0;
            TObjPlayer::launch_weapon_casing(tl_05, this, 3, &v, a);
        }
    } else if (recoil_state == 2) {
        ::approach_value(&barrel_offset, 0.2f, 0.0f);
        if (0.0f == barrel_offset) {
            recoil_state = 0;
        }
    }
}

TItemWeaponSRankBazooka::TItemWeaponSRankBazooka(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    barrel_offset = 0.0f;
    impact_callback = (WeaponHitCallback)spawn_flame_wall_impact;
    recoil_state = 0;
    hit_callback = (WeaponHitCallback)play_target_impact_effect;
    shot_callback = create_shoot_model_with_particles;
    shot_speed = 15.0f;
}

TItem *TItemWeaponSRankBazooka::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankBazooka(tl_05, item);
    }
    return NULL;
}

// Starts the recoil (the name s_rank_bazooka_marker was inferred).
void TItemWeaponSRankBazooka::start_attack_effect() { recoil_state = 1; }

TItemWeaponSRankBazooka::~TItemWeaponSRankBazooka() {}
