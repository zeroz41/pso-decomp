#include "types.h"
#include "pso/weapon/TItemWeaponImperialPick.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"


void TItemWeaponImperialPick::transform_model_node() {
    if (TObjPlayer::get_player_list() == 0) {
        rotate_matrix_z(NULL, rotation_z);
    }
}

void TItemWeaponImperialPick::update_idle() {
    rotation_z = 0;
}


#pragma push
#pragma fp_contract on
void TItemWeaponImperialPick::update_attack() {
    s32 flag;
    s32 ok;
    s32 lo;
    s32 hi;
    f32 speed;
    f32 flo;
    f32 fhi;
    if (this->owner != NULL) {
        speed = ((TObjChara *)(this->owner))->get_frame();
        flag = ((TObjPlayer *)(this->owner))->is_flag_b0_4();
        ok = 1;
        if (this->owner->test_action_mask(0x20) != 0) {
            flo = 15.6f;
            lo = 0;
            fhi = 20.4f;
            hi = 0x4000;
        } else if (this->owner->test_action_mask(0x40) != 0) {
            flo = 12.0f;
            lo = 0x4000;
            fhi = 24.0f;
            hi = -0x4000;
        } else if (this->owner->test_action_mask(0x80) != 0) {
            flo = 14.4f;
            lo = -0x4000;
            fhi = 20.0f;
            hi = 0x2000;
        } else {
            ok = 0;
        }
        if (ok == 1) {
            if (flag == 0) {
                if (speed < flo) {
                    rotation_z = lo;
                } else if (flo <= speed && speed <= fhi) {
                    rotation_z = (s32)((speed - flo) * ((f32)(hi - lo) / (fhi - flo)) + (f32)lo);
                } else {
                    rotation_z = hi;
                }
            } else {
                rotation_z = hi;
            }
        }
    }
}
#pragma pop


TItemWeaponImperialPick::~TItemWeaponImperialPick() {}

TItemWeaponImperialPick::TItemWeaponImperialPick(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_z = 0;
}

TItem *TItemWeaponImperialPick::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponImperialPick(tl_05, item);
    }
    return NULL;
}
