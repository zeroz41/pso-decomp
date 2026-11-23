#include "types.h"
#include "pso/weapon/TUnk_804A4138.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"


void TUnk_804A4138::update_idle() { rotation = 0; }
void TUnk_804A4138::vfunc_60() { if (TObjPlayer::get_player_list() == 0) { rotate_matrix_z(NULL, rotation); } }


#pragma push
#pragma fp_contract on
void TUnk_804A4138::update_attack() {
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


TUnk_804A4138::TUnk_804A4138(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    rotation = 0;
}

TItem *TObjPlayer::create_state_8012934c(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A4138(tl_05, item);
    }
    return NULL;
}

TUnk_804A4138::~TUnk_804A4138() {}
