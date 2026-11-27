#include "types.h"
#include "pso/weapon/TItemWeaponMechgun.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/math/MatrixReflect.h"

void TItemWeaponMechgun::transform_model_node() {
    if ((s32) this->effectJoint == get_model_node_counter()) {
        rotate_matrix_y(0, this->effectAngle);
    }
}

void TItemWeaponMechgun::emit_marker_effects() {
    if (launch_shot(&muzzle[0], 0, 0, 1) != 0) {
        launch_shot(&muzzle[1], 0, 0, 0);
    } else {
        launch_shot(&muzzle[1], 0, 0, 1);
    }
    advance_angle_wrap(&effectAngle, 0x2000);
    effectFrame = 1;
}

void TItemWeaponMechgun::update_weapon() {
    s32 effectFrame;
    if ((s32) this->effectScaleJoint != -1) {
        effectFrame = this->effectFrame;
        if (0.0f < (f32) effectFrame) {
            this->effectFrame = (s32) ((f32) effectFrame - 0.4f);
            if ((f32) this->effectFrame < 0.0f) {
                this->effectFrame = 0;
            }
        }
    }
}

void TItemWeaponMechgun::draw_held_model() {
    sample_dual_muzzles(&muzzle[0], &muzzle[1]);
}

TItemWeaponMechgun::TItemWeaponMechgun(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    this->set_weapon_flags(0x203);
    impact_callback = spawn_weapon_impact_effect;
    this->effectJoint = -1;
    this->effectAngle = 0;
    this->effectScaleJoint = -1;
    this->effectFrame = 0;
    switch ((s32) (*(u8 *)((s8 *)item + 2))) {
    case 6:
        break;
    case 5:
        this->effectJoint = 2;
        break;
    case 7:
        this->effectJoint = 2;
        break;
    }
    if ((u8) *(u8 *)((s8 *)item + 2) >= 5U) {
        set_color_node(-1);
    }
}

TItem *TItemWeaponMechgun::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMechgun(tl_05, item);
    }
    return NULL;
}

TItemWeaponMechgun::~TItemWeaponMechgun() {

}
