#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeaponYasminkov2000H.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponYasminkov2000H::transform_model_node() {
    switch (get_model_node_counter()) {
    case 1:
        post_translate_matrix(&slide.x);
        return;
    case 2:
        scale_current_matrix(&scale.x);
        return;
    }
}

void TItemWeaponYasminkov2000H::update_idle() {
    if (shown == 1) {
        shown = !shown;
        scale.x = scale.y = scale.z = 1e-05f;
    }
}

void TItemWeaponYasminkov2000H::update_attack() {
    if (shown == 0) {
        shown = !shown;
        scale.x = scale.y = scale.z = 1.0f;
    }
}

void TItemWeaponYasminkov2000H::update_weapon() {
    Vec dir;
    s32 angle[3];
    s32 a;

    switch (slide_state) {
    case 1:
        slide.y -= 0.46666667f;
        if (slide.y <= 0.0f) {
            slide.y = 0.0f;
            slide_state = 0;
        }
        break;
    case 2:
        slide.y += 0.46666667f;
        if (1.4f <= slide.y) {
            slide.y = 1.4f;
            slide_state = 3;
        }
        break;
    case 3:
        slide_state = 1;
        a = owner->rotation_y - 0x4000;
        dir.x = sin_table_lookup(a);
        dir.y = 1.0f;
        dir.z = cos_table_lookup(a);
        angle[0] = 0x4000;
        angle[1] = owner->rotation_y;
        angle[2] = 0;
        TObjPlayer::launch_weapon_casing((saddr)tl_05, (uaddr)this, 3, (uaddr)&dir, (uaddr)angle);
        break;
    }
}

void TItemWeaponYasminkov2000H::emit_marker_effects() {
    Vec muzzle;

    slide_state = 2;
    get_gun_point(&muzzle);
    spawn_particle_effect(&muzzle, 9);
}

TItemWeaponYasminkov2000H::~TItemWeaponYasminkov2000H() {}

TItemWeaponYasminkov2000H::TItemWeaponYasminkov2000H(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = NULL;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    shot_speed = 20.0f;
    shown = 0;
    scale.x = scale.y = scale.z = 1e-05f;
    slide_state = 0;
    slide.x = slide.y = slide.z = 0.0f;
}

TItem *TItemWeaponYasminkov2000H::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponYasminkov2000H(tl_05, item);
    }
    return NULL;
}
