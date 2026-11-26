#include "types.h"
#include "pso/weapon/TItemWeaponSRankScythe.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"


void TItemWeaponSRankScythe::update_idle() { rotation = 0; }
void TItemWeaponSRankScythe::transform_model_node() { if (get_model_node_counter() == 0) { rotate_matrix_z(NULL, rotation); } }


#pragma push
#pragma fp_contract on
void TItemWeaponSRankScythe::update_attack() {
    s32 flag;
    s32 ok;
    s32 lo;
    s32 hi;
    f32 speed;
    f32 flo;
    f32 fhi;
    if (owner != NULL) {
        speed = owner->get_frame();
        flag = owner->is_flag_b0_4();
        ok = 1;
        if (owner->test_action_mask(0x20) != 0) {
            flo = 15.6f;
            lo = 0;
            fhi = 20.4f;
            hi = 0x4000;
        } else if (owner->test_action_mask(0x40) != 0) {
            flo = 12.0f;
            lo = 0x4000;
            fhi = 24.0f;
            hi = -0x4000;
        } else if (owner->test_action_mask(0x80) != 0) {
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
                    rotation = lo;
                } else if (flo <= speed && speed <= fhi) {
                    rotation = (s32)((speed - flo) * ((f32)(hi - lo) / (fhi - flo)) + (f32)lo);
                } else {
                    rotation = hi;
                }
            } else {
                rotation = hi;
            }
        }
    }
}
#pragma pop


TItemWeaponSRankScythe::TItemWeaponSRankScythe(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    rotation = 0;
}

TItem *TItemWeaponSRankScythe::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankScythe(tl_05, item);
    }
    return NULL;
}

TItemWeaponSRankScythe::~TItemWeaponSRankScythe() {}
