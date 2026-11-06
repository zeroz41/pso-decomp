#include "types.h"
#include "pso/weapon/TUnk_804A66D8.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B328.h"
#include "pso/unk/text_8011B620.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A66D8::emit_marker_effects() {
    u8 *counter;
    s32 i;
    if (is_mode_two_and_ready() != 0) {
        counter = (u8 *)owner + 0x7CC;
        for (i = 0; i != 2; i++) {
            increment_burst_counter(counter);
        }
        shot_callback = (WeaponShotCallback)create_shoot_model_rot_z;
        impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
        ((TObjPlayer *)this)->launch_rare_weapon_special(&gun_point, 1, 3.0f);
        ((TObjPlayer *)this)->launch_rare_weapon_special(&second_gun_point, 0, 3.0f);
    } else {
        shot_callback = (WeaponShotCallback)create_gun_shot;
        impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
        if (launch_shot((u8 *)&gun_point, 0, 0, 1) != 0) {
            launch_shot((u8 *)&second_gun_point, 0, 0, 0);
        } else {
            launch_shot((u8 *)&second_gun_point, 0, 0, 1);
        }
    }
}

void TUnk_804A66D8::reserved_53() {
    ((TObjPlayer *)this)->draw_status_icons(&gun_point, &second_gun_point);
}

TUnk_804A66D8::~TUnk_804A66D8() {}

TUnk_804A66D8::TUnk_804A66D8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(547);
}

u8 *create_twin_psychogun(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A66D8(tl_05, (u8 *)arg0);
    }
    return NULL;
}
