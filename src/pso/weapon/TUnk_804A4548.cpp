#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804A4548.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/effect/item/TItemEffFlame.h"
#include "pso/unk/text_80129D18.h"
#include "pso/unk/text_8011BE50.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

// Slides the barrel back by barrel_offset (the name s_rank_bazooka_slide_barrel was inferred).
void TUnk_804A4548::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, (-1.0f) * barrel_offset, 0.0f);
    }
}

// The recoil after a shot (the name s_rank_bazooka_recoil was inferred): the barrel
// slides back, throws a casing, then returns.
void TUnk_804A4548::update_weapon() {
    s32 ang;
    WeaponVector v;
    s32 a[3];
    if (recoil_state == 1) {
        TItemEffOrgaFlowShot::approach_value(&barrel_offset, (-0.5f), (-2.0f));
        if ((-2.0f) == barrel_offset) {
            recoil_state = 2;
            ang = owner->rotation_y + 0x4000;
            v.x = sin_table_lookup(ang);
            v.y = 0.0f;
            v.z = cos_table_lookup(ang);
            a[0] = 0x4000;
            a[1] = owner->rotation_y;
            a[2] = 0;
            TObjPlayer::launch_weapon_casing((s32)tl_05, (u32)this, 3, (u32)&v, (u32)a);
        }
    } else if (recoil_state == 2) {
        TItemEffOrgaFlowShot::approach_value(&barrel_offset, 0.2f, 0.0f);
        if (0.0f == barrel_offset) {
            recoil_state = 0;
        }
    }
}

TUnk_804A4548::TUnk_804A4548(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    barrel_offset = 0.0f;
    impact_callback = (WeaponHitCallback)spawn_flame_wall_impact;
    recoil_state = 0;
    hit_callback = (WeaponHitCallback)play_target_impact_effect;
    shot_callback = (WeaponShotCallback)create_shoot_model_with_particles;
    shot_speed = 15.0f;
}

u8 *create_s_rank_bazooka(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A4548(tl_05, (u8 *)arg0);
    }
    return NULL;
}

// Starts the recoil (the name s_rank_bazooka_marker was inferred).
void TUnk_804A4548::vfunc_62() { recoil_state = 1; }

TUnk_804A4548::~TUnk_804A4548() {}
