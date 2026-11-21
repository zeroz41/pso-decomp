#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TUnk_804A6CC8.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A6CC8::vfunc_60() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        post_translate_matrix(&slide.x);
        return;
    case 2:
        scale_current_matrix(&scale.x);
        return;
    }
}

void TUnk_804A6CC8::update_idle() {
    if (shown == 1) {
        shown = !shown;
        scale.x = scale.y = scale.z = 1e-05f;
    }
}

void TUnk_804A6CC8::update_attack() {
    if (shown == 0) {
        shown = !shown;
        scale.x = scale.y = scale.z = 1.0f;
    }
}

void TUnk_804A6CC8::update_weapon() {
    WeaponVector dir;
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

void TUnk_804A6CC8::emit_marker_effects() {
    Vec muzzle;

    slide_state = 2;
    get_gun_point(&muzzle);
    spawn_particle_effect(&muzzle, 9);
}

TUnk_804A6CC8::~TUnk_804A6CC8() {}

TUnk_804A6CC8::TUnk_804A6CC8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = NULL;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    shot_speed = 20.0f;
    shown = 0;
    scale.x = scale.y = scale.z = 1e-05f;
    slide_state = 0;
    slide.x = slide.y = slide.z = 0.0f;
}

TItem *create_yasminkov_2000h(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A6CC8(tl_05, item);
    }
    return NULL;
}
