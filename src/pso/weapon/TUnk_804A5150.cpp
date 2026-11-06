#include "types.h"
#include "pso/weapon/TUnk_804A5150.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012C128.h"
#include "pso/item/TItem.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/effect/item/TItemEffNeedle.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);

void TUnk_804A5150::update_idle() { TObjPlayer::add_angle_clamped(&rotation_x, (s32)((void*)-910), (s32)((void*)-7281)); TObjPlayer::add_angle_clamped(&rotation_z, (s32)((void*)-910), (s32)((void*)-9102)); }

void TUnk_804A5150::update_attack() { TObjPlayer::add_angle_clamped(&rotation_x, (s32)((void*)1820), (s32)((void*)0)); TObjPlayer::add_angle_clamped(&rotation_z, (s32)((void*)1820), (s32)((void*)0)); }

void TUnk_804A5150::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        rotate_matrix_z(0, -rotation_z);
        return;
    case 2:
        rotate_matrix_z(0, rotation_z);
        return;
    case 3:
        rotate_matrix_x(0, rotation_x);
        return;
    }
}
}

TUnk_804A5150::TUnk_804A5150(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = (WeaponShotCallback)TItemShoot::spawn_shoot_particle_attached;
    hit_callback = (WeaponHitCallback)spawn_target_needle;
    impact_callback = (WeaponHitCallback)spawn_needle_wall_impact;
    rotation_z = 0;
    rotation_x = 0;
}

extern "C" {
u8 *TObjPlayer::create_handlers_state(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A5150(tl_05, arg0);
    }
    return NULL;
}

}


TUnk_804A5150::~TUnk_804A5150() {}
