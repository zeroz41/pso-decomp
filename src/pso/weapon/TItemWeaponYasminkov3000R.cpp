#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeaponYasminkov3000R.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponYasminkov3000R::transform_model_node() {
    if (get_model_node_counter() == 1) {
        post_translate_matrix(&slide.x);
    }
}

void TItemWeaponYasminkov3000R::emit_marker_effects() {
    WeaponVector dir;
    s32 angle[3];
    WeaponVector muzzle;
    s32 a;

    slide_state = 2;
    a = owner->rotation_y - 0x4000;
    dir.x = sin_table_lookup(a);
    dir.y = 1.0f;
    dir.z = cos_table_lookup(a);
    angle[0] = 0x4000;
    angle[1] = owner->rotation_y;
    angle[2] = 0;
    TObjPlayer::launch_weapon_casing((saddr)tl_05, (uaddr)this, 3, (uaddr)&dir, (uaddr)angle);
    get_joint_position(2, &muzzle);
    spawn_particle_effect((const Vec *)&muzzle, 9);
}

void TItemWeaponYasminkov3000R::update_weapon() {
    switch (slide_state) {
    case 1:
        if (0.0f < slide.z) {
            slide.z -= 0.5f;
            if (slide.z <= 0.0f) {
                slide.z = 0.0f;
                slide_state = 0;
            }
        }
        break;
    case 2:
        if (slide.z < 1.4f) {
            slide.z += 0.5f;
            if (1.4f <= slide.z) {
                slide.z = 1.4f;
                slide_state = 3;
            }
        }
        break;
    case 3:
        slide_state = 1;
        break;
    }
}

TItemWeaponYasminkov3000R::~TItemWeaponYasminkov3000R() {}

TItemWeaponYasminkov3000R::TItemWeaponYasminkov3000R(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = NULL;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    shot_speed = 20.0f;
    slide.x = slide.y = slide.z = 0.0f;
    slide_state = 0;
}

TItem *TItemWeaponYasminkov3000R::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponYasminkov3000R(tl_05, item);
    }
    return NULL;
}
