#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponSoulEater.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TItemTimerEventHpDrain.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecMegid.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponSoulEater::update_idle() {
    rotation_z = 0;
}

void TItemWeaponSoulEater::transform_model_node() {
    if (get_model_node_counter() == 0) {
        rotate_matrix_z(NULL, rotation_z);
    }
}

#pragma push
#pragma fp_contract on
void TItemWeaponSoulEater::update_attack() {
    s32 flag;
    s32 ok;
    s32 lo;
    s32 hi;
    f32 frame;
    f32 flo;
    f32 fhi;

    if (owner != NULL) {
        frame = owner->get_frame();
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
                if (frame < flo) {
                    rotation_z = lo;
                } else if (flo <= frame && frame <= fhi) {
                    rotation_z = (s32)((frame - flo) * ((f32)(hi - lo) / (fhi - flo)) + (f32)lo);
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

void TItemWeaponSoulEater::on_equipped() {
    if (effect_objects != NULL) {
        if (get_item_index() == 0) {
            new TItemTimerEventHpDrain(effect_objects, get_owner_client(), 0x96);
        } else {
            new TItemTimerEventHpDrain(effect_objects, get_owner_client(), 0x5A);
        }
    }
}

void TItemWeaponSoulEater::emit_marker_effects() {
    Vec pos;

    if (get_item_index() == 1) {
        TItemEffCane::create(tl_05, this, 2, 0x101);
        if (is_mode_two_and_ready() != 0) {
            if (get_joint_position(2, &pos) != 0) {
                TTecMegid::create_ex(owner, &pos, owner->rotation.y, 0);
                ((TItemWeapon *)this)->drain_owner_hp_fraction(0.07f);
            }
        } else {
            ((TItemWeapon *)this)->update_active_game_effect();
        }
    }
}

TItemWeaponSoulEater::TItemWeaponSoulEater(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_z = 0;
    if (get_item_index() == 1) {
        set_weapon_flags(0x22);
    }
}

TItem *TItemWeaponSoulEater::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSoulEater(tl_05, item);
    }
    return NULL;
}

TItemWeaponSoulEater::~TItemWeaponSoulEater() {}
