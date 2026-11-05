#include "types.h"
#include "pso/player/TUnk_804A4138.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80129308.h"
#include "pso/item/TItemEquipVariant_801293A4.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"

#include "pso/system/MatrixOps.h"

void TUnk_804A4138::update_idle() { *(s32*)((char*)this + 0x1fc) = 0; }
void TUnk_804A4138::vfunc_60() { if (TObjPlayer::get_player_list() == 0) { rotate_matrix_z(NULL, *(s32 *)((u8 *)this + 0x1FC)); } }

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

extern "C" {

void construct_srank_weapon(void *);

extern s32 lbl_804A4138[];

void *TObjPlayer__sub_80129308(void *weapon, s32 parent, void *item) {
    construct_srank_weapon(weapon);
    *(s32 **)((s8 *)weapon + 0x18) = lbl_804A4138;
    *(u32 *)((s8 *)weapon + 0x1FC) = 0;
    return weapon;
}

}

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_state_8012934c(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_80129308(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 lbl_804A4138[];

void *__dt__13TUnk_804A4138Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A4138;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
