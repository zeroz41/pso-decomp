#include "types.h"
#include "pso/player/TUnk_804A4138.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 test_action_mask__10TObjPlayerFl(void *, s32);
extern const f32 lbl_805DAE00;
extern const f32 lbl_805DAE04;
extern const f32 lbl_805DAE08;
extern const f32 lbl_805DAE0C;
extern const f32 lbl_805DAE10;
extern const f32 lbl_805DAE14;
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
        speed = ((TObjChara *)(*(void **)((s8 *)self + 0xF0)))->get_speed();
        flag = ((TObjPlayer *)(*(void **)((s8 *)self + 0xF0)))->is_flag_b0_4();
        ok = 1;
        if (test_action_mask__10TObjPlayerFl(*(void **)((s8 *)self + 0xF0), 0x20) != 0) {
            flo = lbl_805DAE00;
            lo = 0;
            fhi = lbl_805DAE04;
            hi = 0x4000;
        } else if (test_action_mask__10TObjPlayerFl(*(void **)((s8 *)self + 0xF0), 0x40) != 0) {
            flo = lbl_805DAE08;
            lo = 0x4000;
            fhi = lbl_805DAE0C;
            hi = -0x4000;
        } else if (test_action_mask__10TObjPlayerFl(*(void **)((s8 *)self + 0xF0), 0x80) != 0) {
            flo = lbl_805DAE10;
            lo = -0x4000;
            fhi = lbl_805DAE14;
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
