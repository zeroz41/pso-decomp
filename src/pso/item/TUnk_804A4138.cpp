#include "types.h"
#include "pso/player/TUnk_804A4138.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

#include "pso/system/MatrixOps.h"
#include "pso/TMainTask.h"

void TUnk_804A4138::update_idle() { rotation = 0; }
void TUnk_804A4138::vfunc_60() { if (TObjPlayer::get_player_list() == 0) { rotate_matrix_z(NULL, rotation); } }

extern "C" {
s32 test_action_mask__10TObjPlayerFl(void *, s32);
#pragma push
#pragma fp_contract on
void TUnk_804A4138::update_attack() {
    u8 *self = (u8 *)this;
    s32 flag;
    s32 ok;
    s32 lo;
    s32 hi;
    f32 speed;
    f32 flo;
    f32 fhi;
    if (*(void **)((s8 *)self + 0xF0) != NULL) {
        speed = ((TObjChara *)(*(void **)((s8 *)self + 0xF0)))->get_frame();
        flag = ((TObjPlayer *)(*(void **)((s8 *)self + 0xF0)))->is_flag_b0_4();
        ok = 1;
        if (test_action_mask__10TObjPlayerFl(*(void **)((s8 *)self + 0xF0), 0x20) != 0) {
            flo = 15.6f;
            lo = 0;
            fhi = 20.4f;
            hi = 0x4000;
        } else if (test_action_mask__10TObjPlayerFl(*(void **)((s8 *)self + 0xF0), 0x40) != 0) {
            flo = 12.0f;
            lo = 0x4000;
            fhi = 24.0f;
            hi = -0x4000;
        } else if (test_action_mask__10TObjPlayerFl(*(void **)((s8 *)self + 0xF0), 0x80) != 0) {
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
                    *(s32 *)((s8 *)self + 0x1FC) = lo;
                } else if (flo <= speed && speed <= fhi) {
                    *(s32 *)((s8 *)self + 0x1FC) = (s32)((speed - flo) * ((f32)(hi - lo) / (fhi - flo)) + (f32)lo);
                } else {
                    *(s32 *)((s8 *)self + 0x1FC) = hi;
                }
            } else {
                *(s32 *)((s8 *)self + 0x1FC) = hi;
            }
        }
    }
}
#pragma pop

}

TUnk_804A4138::TUnk_804A4138(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    rotation = 0;
}

u8 *TObjPlayer::create_state_8012934c(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A4138(tl_05, arg0);
    }
    return NULL;
}

TUnk_804A4138::~TUnk_804A4138() {}
