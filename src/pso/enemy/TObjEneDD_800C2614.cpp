#include "types.h"
#include "pso/enemy/TObjEneDD_800BA138.h"
#include "pso/enemy/TObjEneDD_800C2614.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_800C3A60.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneRe2Flower.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_800C2628 { f32 x, y, z; };

struct Prm_800C2628 { f32 a, b, c, d, e; };

extern "C" {
s32 noop__9TObjEneDDFv(void *, s32);
s32 advance_animation_playback();
s32 play_sound_effect(s32, void *, s32, s32);
extern Prm_800C2628 enemy_dd_attack_param_block;
extern Prm_800C2628 lbl_8043BBA0;
extern f32 *const lbl_805D5170;
extern const f32 lbl_805D9FBC;
s32 objInBand__FP7GameObjf(f32);

void TObjEneRe2Flower::vfunc_105() {  }
void TObjEneDD__sub_800C2618(void* p) { *(u32*)((char*)p + 0x3c4) |= 0x2; }

extern const f32 lbl_805D9FC0;

#define F(T, off) (*(T *)(arg0 + (off)))
void TObjEneDD__sub_800C2628(u8 *arg0, s32 arg1) {
    s32 step;
    Vec_800C2628 v;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 1;
        ((TObjEneDD *)(arg0))->vfunc_96();
        ((TObjEneRe2Flower *)arg0)->clear_child_flags();
        F(u32, 0x3C4) &= ~8;
        ((TObjEneDD *)arg0)->set_field_378(8);
        if (!(F(u32, 0x3C4) & 4)) {
            F(u32, 0x3C4) |= 4;
            F(s32, 0x410) = 0;
            F(s32, 0x420) = 0;
            F(s32, 0x414) = 1;
            F(s32, 0x3D8) = 0;
            F(s32, 0x3D4) = 0;
        }
        break;
    case 1:
    case 5:
        break;
    case 3:
        if (F(s32, 0x410) > 0x1C2) {
            F(u32, 0x30) |= 0x800;
            ((TObjEneDD *)arg0)->transition_enemy_state(0xA);
            VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x38));
            v.y += lbl_805D9FBC;
            spawn_particle_effect_with_flags(&v, 0xD3, 0x40);
            {
                Prm_800C2628 prm = lbl_8043BBA0;
                prm.d = prm.b = *lbl_805D5170;
                if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0) {
                    TObjEneDD__sub_800BA5A4(arg0, &prm);
                } else {
                    TObjEneDD__sub_800BA5A4(arg0, &enemy_dd_attack_param_block);
                }
            }
            play_sound_effect(fn_800C3A60((s32)arg0, 0x4003A311), arg0 + 0x38, 0, 0);
        }
        break;
    case 0:
        advance_animation_playback();
        if (F(s32, 0x3D4) > 0) {
            F(s32, 0x3D4)--;
            if (F(s32, 0x3D4) == 0) {
                ((TObjEneDD *)arg0)->clear_attack_receipts();
            }
        }
        if (TObjEneDD::check_v2_mode() != 0) {
            F(s32, 0x410) += 0x14;
        } else {
            F(s32, 0x410) += 1;
        }
        if (F(s32, 0x410) < 0x12C) {
            step = 0x11;
            F(s32, 0x60) += 0x400;
        } else if (F(s32, 0x410) < 0x168) {
            step = 0x22;
            F(s32, 0x60) += 0x800;
        } else if (F(s32, 0x410) < 0x1B3) {
            step = 0x44;
            F(s32, 0x60) += 0x1000;
        } else {
            step = 0x44;
        }
        if (F(s32, 0x410) < 0x1B3) {
            if (F(s32, 0x414) == 0) {
                F(s32, 0x3D8) += step;
                if (F(s32, 0x3D8) > 0xFF) {
                    F(s32, 0x3D8) = 0xFF - (F(s32, 0x3D8) - 0xFF);
                    F(s32, 0x414) = 1;
                    play_sound_effect(fn_800C3A60((s32)arg0, 0x4003AD10), arg0 + 0x38, 0, 0);
                }
            } else {
                F(s32, 0x3D8) -= step;
                if (F(s32, 0x3D8) < 0) {
                    F(s32, 0x3D8) = -F(s32, 0x3D8);
                    F(s32, 0x414) = 0;
                }
            }
        } else {
            F(s32, 0x3D8) = 0xFF;
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneDD *)(arg0))->vfunc_88();
        ((s32 (*)(void *))noop__9TObjEneDDFv)(arg0);
        break;
    }
}
#undef F

void TObjEneRe2Flower::handle_event(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    switch (arg1) {
    case 4:
        this->requested_action = 6;
        this->vfunc_96();
        ((TObjEneRe2Flower *)arg0)->clear_child_flags();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFF7);
        ((TObjEneDD *)arg0)->set_field_378(3);
        *(s32 *)((s8 *)arg0 + 0x410) = 0;
        play_sound_effect(fn_800C3A60((s32)arg0, 0x4003A315), (u8 *)&this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        return;
    case 3:
        if (objInBand__FP7GameObjf(*(f32 *)((s8 *)arg0 + 0xC4) - lbl_805D9FC0) != 0) {
            ((TObjEneDD *)arg0)->transition_enemy_state(3);
        }
        this->vfunc_102();
        this->vfunc_88();
        return;
    case 0:
        advance_animation_playback();
        temp_r4 = *(s32 *)((s8 *)arg0 + 0x410);
        *(s32 *)((s8 *)arg0 + 0x410) = (temp_r4 + 1);
        noop__9TObjEneDDFv(arg0, temp_r4);
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFD);
    case 1:
        return;
    }
}

}
