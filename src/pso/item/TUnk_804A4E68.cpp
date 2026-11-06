#include "types.h"
#include "pso/item/TUnk_804A4E68.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/TMainTask.h"

void TUnk_804A4E68::vfunc_60() {
    if (TObjPlayer::get_player_list() == 0) {
        rotate_matrix_z(NULL, rotation_z);
    }
}

void TUnk_804A4E68::update_idle() {
    rotation_z = 0;
}

extern "C" {
s32 test_action_mask__10TObjPlayerFl(void *, s32);
#pragma push
#pragma fp_contract on
void TUnk_804A4E68::update_attack() {
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
        if (test_action_mask__10TObjPlayerFl(this->owner, 0x20) != 0) {
            flo = 15.6f;
            lo = 0;
            fhi = 20.4f;
            hi = 0x4000;
        } else if (test_action_mask__10TObjPlayerFl(this->owner, 0x40) != 0) {
            flo = 12.0f;
            lo = 0x4000;
            fhi = 24.0f;
            hi = -0x4000;
        } else if (test_action_mask__10TObjPlayerFl(this->owner, 0x80) != 0) {
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

}

TUnk_804A4E68::~TUnk_804A4E68() {}

TUnk_804A4E68::TUnk_804A4E68(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_z = 0;
}

u8 *TObjPlayer::create_vtable_clear_field1f8(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A4E68(tl_05, item);
    }
    return NULL;
}
