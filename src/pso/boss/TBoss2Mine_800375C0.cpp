#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/TUnk_80482EC0.h"
#include "pso/boss/TUnk_80482D04.h"
#include "pso/boss/TBoss2Mine.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Mine_80038760; struct O_80038908;
extern "C" {
s32 transition_enemy_state__9TObjEneDDFs(void *, int);
s32 play_sound_effect(int, void *, int, int);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
void init_params__10TBoss2MineFlf(u8 *arg0, s32 arg1, f32 farg0);
void update_pulse_state__10TBoss2MineFv(Mine_80038760 *self);
void set_node_offsets__10TBoss2MineFv(O_80038908 *self);
void *__dt__10TBoss2MineFv(void *arg0, s16 arg1);
void* TBoss2Mine__ct(void* a0, int a1, int a2, int a3, int a4);
extern s32 lbl_80482D04[];
}

#define update_pulse_state__10TBoss2MineFv ((s32 (*)(void *))update_pulse_state__10TBoss2MineFv)

struct Vec_800375C0 { f32 x, y, z; };
struct Mine_800377E8 { u8 pad[0x404]; Vec_800375C0 vel; };

extern "C" {
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void init_launch__10TBoss2MineFPvPvii(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
s32 subtract_vector(void *, void *);
s32 vec3_add_to(void *, void *);
s32 is_alive__9TObjEneDDFv(s32);

#pragma push
#pragma fp_contract on
void TUnk_80482D04::vfunc_106(s32 arg1) {
    Vec_800375C0 v;
    f32 s;
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        ((TUnk_80482D04 *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x38C) &= ~5;
        *(s32 *)((s8 *)arg0 + 0x38C) |= 2;
        *(s32 *)((s8 *)arg0 + 0x5C) = 0;
        *(s32 *)((s8 *)arg0 + 0x3B0) = 0;
        *(s32 *)((s8 *)arg0 + 0x3C8) = 0;
        *(s32 *)((s8 *)arg0 + 0x3CC) = (s32)((6e+01f) * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + 0xF0;
        init_params__10TBoss2MineFlf(arg0, 0x1E, (0.25f));
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x38C) & 0x100) {
            *(s32 *)((s8 *)arg0 + 0x38C) &= ~0x100;
            transition_enemy_state__9TObjEneDDFs(arg0, 1);
        }
        if (*(s32 *)((s8 *)arg0 + 0x3C8) == 1) {
            transition_enemy_state__9TObjEneDDFs(arg0, 3);
        }
        break;
    case 0:
        (*(s32 *)((s8 *)arg0 + 0x3CC))--;
        if (*(s32 *)((s8 *)arg0 + 0x3CC) <= 0) {
            *(s32 *)((s8 *)arg0 + 0x3C8) = 1;
        }
        *(s32 *)((s8 *)arg0 + 0x64) += 2.56e+03f;
        ((TUnk_80482D04 *)arg0)->move_mine();
        VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x390));
        subtract_vector(&v, arg0 + 0x2FC);
        s = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        s *= (0.75f);
        if (s < (0.2f)) {
            VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)((s32)&*(Vec_800375C0 *)((s8 *)arg0 + 0x390)));
        } else {
            if (s > (4.0f)) {
                s = (4.0f);
            }
            *(f32 *)((s8 *)arg0 + 0x2FC) = v.x * s + *(f32 *)((s8 *)arg0 + 0x2FC);
            *(f32 *)((s8 *)arg0 + 0x300) = *(f32 *)((s8 *)arg0 + 0x394);
            *(f32 *)((s8 *)arg0 + 0x304) = v.z * s + *(f32 *)((s8 *)arg0 + 0x304);
        }
        ((TBoss2Mine *)arg0)->set_state_by_distance(*(s32 *)((s8 *)arg0 + 0x3CC));
        update_pulse_state__10TBoss2MineFv(arg0);
        *(f32 *)((s8 *)arg0 + 0x38) = *(f32 *)((s8 *)arg0 + 0x2FC);
        *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0x304);
        ((TUnk_80482D04 *)(arg0))->vfunc_89();
        *(f32 *)((s8 *)arg0 + 0x2FC) = *(f32 *)((s8 *)arg0 + 0x38);
        *(f32 *)((s8 *)arg0 + 0x304) = *(f32 *)((s8 *)arg0 + 0x40);
        ((TBoss2Mine *)arg0)->update_move_flag();
        break;
    case 5:
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_80482D04::vfunc_105(s32 arg1) {
    Vec_800375C0 v;
    f32 t;
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        ((TUnk_80482D04 *)(arg0))->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x38C) &= ~7;
        *(s32 *)((s8 *)arg0 + 0x3A8) = 0;
        *(s32 *)((s8 *)arg0 + 0x5C) = 0x4000;
        *(s32 *)((s8 *)arg0 + 0x64) = 0;
        *(s32 *)((s8 *)arg0 + 0x3C8) = 1;
        *(s32 *)((s8 *)arg0 + 0x3CC) = 0;
        *(f32 *)((s8 *)arg0 + 0x3DC) = (8.0f);
        *(f32 *)((s8 *)arg0 + 0x3E0) = (0.0f);
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x3C8) == 3) {
            transition_enemy_state__9TObjEneDDFs(arg0, 2);
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x3C8)) {
        case 0:
            (*(s32 *)((s8 *)arg0 + 0x3CC))++;
            if (*(s32 *)((s8 *)arg0 + 0x3CC) >= 0xF) {
                *(s32 *)((s8 *)arg0 + 0x3C8) = 1;
                play_sound_effect(0x4003A804, arg0 + 0x2FC, 0, 0);
            }
            *(f32 *)((s8 *)arg0 + 0x2FC) = *(f32 *)((s8 *)arg0 + 0x404) * *(f32 *)((s8 *)arg0 + 0x3DC) + *(f32 *)((s8 *)arg0 + 0x2FC);
            *(f32 *)((s8 *)arg0 + 0x304) = *(f32 *)((s8 *)arg0 + 0x40C) * *(f32 *)((s8 *)arg0 + 0x3DC) + *(f32 *)((s8 *)arg0 + 0x304);
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x3A8) += 0x400;
            if (*(s32 *)((s8 *)arg0 + 0x3A8) >= 0x38E3) {
                *(s32 *)((s8 *)arg0 + 0x3A8) = 0x38E3;
                *(s32 *)((s8 *)arg0 + 0x3C8) = 2;
            }
            *(f32 *)((s8 *)arg0 + 0x2FC) = *(f32 *)((s8 *)arg0 + 0x404) * *(f32 *)((s8 *)arg0 + 0x3DC) + *(f32 *)((s8 *)arg0 + 0x2FC);
            *(f32 *)((s8 *)arg0 + 0x304) = *(f32 *)((s8 *)arg0 + 0x40C) * *(f32 *)((s8 *)arg0 + 0x3DC) + *(f32 *)((s8 *)arg0 + 0x304);
            break;
        case 2:
            *(s32 *)((s8 *)arg0 + 0x5C) -= 0x600;
            if (*(s32 *)((s8 *)arg0 + 0x5C) < 0) {
                *(s32 *)((s8 *)arg0 + 0x5C) = 0;
            }
            *(s32 *)((s8 *)arg0 + 0x64) += 2.56e+03f;
            *(f32 *)((s8 *)arg0 + 0x3DC) -= (0.2f);
            if (*(f32 *)((s8 *)arg0 + 0x3DC) <= (3.0f)) {
                *(f32 *)((s8 *)arg0 + 0x3DC) = (3.0f);
            }
            ((TUnk_80482D04 *)arg0)->move_mine();
            VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x390));
            subtract_vector(&v, arg0 + 0x2FC);
            if (((TObjBoss2Tunnel *)(&v))->update_scale() <= (4.5f)) {
                *(s32 *)((s8 *)arg0 + 0x3C8) = 3;
            }
            *(f32 *)((s8 *)arg0 + 0x3E0) += (0.05f);
            if (*(f32 *)((s8 *)arg0 + 0x3E0) > (3.0f)) {
                *(f32 *)((s8 *)arg0 + 0x3E0) = (3.0f);
            }
            t = *(f32 *)((s8 *)arg0 + 0x3E0) / *(f32 *)((s8 *)arg0 + 0x3DC);
            *(f32 *)((s8 *)arg0 + 0x404) = v.x * t + *(f32 *)((s8 *)arg0 + 0x404);
            *(f32 *)((s8 *)arg0 + 0x408) = v.y * t + *(f32 *)((s8 *)arg0 + 0x408);
            *(f32 *)((s8 *)arg0 + 0x40C) = v.z * t + *(f32 *)((s8 *)arg0 + 0x40C);
            ((TObjBoss2Tunnel *)((s32)arg0 + 0x404))->update_scale();
            *(f32 *)((s8 *)arg0 + 0x2FC) = ((Mine_800377E8 *)arg0)->vel.x * *(f32 *)((s8 *)arg0 + 0x3DC) + *(f32 *)((s8 *)arg0 + 0x2FC);
            *(f32 *)((s8 *)arg0 + 0x300) = *(f32 *)((s8 *)arg0 + 0x408) * *(f32 *)((s8 *)arg0 + 0x3DC) + *(f32 *)((s8 *)arg0 + 0x300);
            *(f32 *)((s8 *)arg0 + 0x304) = *(f32 *)((s8 *)arg0 + 0x40C) * *(f32 *)((s8 *)arg0 + 0x3DC) + *(f32 *)((s8 *)arg0 + 0x304);
            break;
        }
        ((TBoss2Mine *)arg0)->update_move_flag();
        break;
    case 5:
        break;
    }
}
#pragma pop

void init_launch__10TBoss2MineFPvPvii(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 temp_r31;
    s32 var_r31;
    *(s32 *)((s8 *)arg0 + 0x38C) = (s32) (*(s32 *)((s8 *)arg0 + 0x38C) | 0x100);
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg1));
    *(s32 *)((s8 *)arg0 + 0x3F0) = arg2;
    temp_r31 = arg3 * 0x5555;
    *(s32 *)((s8 *)arg0 + 0x3F4) = arg3;
    *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) ((2e+01f) * sin_table_lookup(temp_r31));
    *(f32 *)((s8 *)arg0 + 0x3FC) = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x400) = (f32) ((2e+01f) * cos_table_lookup(temp_r31));
    if (arg3 == 0) {
        var_r31 = 0x8000;
    } else if (arg3 == 1) {
        var_r31 = 0x6800;
    } else {
        var_r31 = 0x9800;
    }
    *(f32 *)((s8 *)arg0 + 0x404) = sin_table_lookup(var_r31);
    *(f32 *)((s8 *)arg0 + 0x408) = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x40C) = cos_table_lookup(var_r31);
    *(s32 *)((s8 *)arg0 + 0x60) = var_r31;
    *(f32 *)((s8 *)arg0 + 0x390) = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x394) = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x398) = (f32) (0.0f);
    ((TUnk_80482D04 *)arg0)->move_mine();
    *(s32 *)((s8 *)arg0 + 0x5C) = 0x4000;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x2FC));
    *(s32 *)((s8 *)arg0 + 0x3A8) = 0;
    *(s16 *)((s8 *)arg0 + 0x32C) = (s16) *(s16 *)((s8 *)arg0 + 0x2B8);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & ~0xA00);
}

void TUnk_80482D04::move_mine() {
    u8 *arg0 = (u8 *)this;
    if (is_alive__9TObjEneDDFv(*(s32 *)((s8 *)arg0 + 0x3F0)) != 0) {
        VecCopy((Vec *)(arg0 + 0x390), (const Vec *)(*(s32 *)((s8 *)arg0 + 0x3F0) + 0x38));
        vec3_add_to(arg0 + 0x390, arg0 + 0x3F8);
        *(f32 *)((s8 *)arg0 + 0x394) += 17.0f;
    }
}

void TUnk_80482D04::vfunc_88() {
    *(f32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 4) = (f32) ((1.0f) + (*(f32 *)((s8 *)this + 0x300) - *(f32 *)((s8 *)this + 0x3C)));
}

#undef update_pulse_state__10TBoss2MineFv

void *__dt__13TUnk_80482D04Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

void *__dt__13TUnk_80482D04Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_80482D04;
        __dt__10TBoss2MineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

#define init_params__10TBoss2MineFlf ((s32 (*)(void *, int, f32))init_params__10TBoss2MineFlf)
#define calc_elapsed_scaled__9TObjEneDDFv ((f32 (*)(void *, int, int))calc_elapsed_scaled__9TObjEneDDFv)
#define play_sound_effect ((s32 (*)(int, void *, int, int, int))play_sound_effect)
#define update_pulse_state__10TBoss2MineFv ((s32 (*)(void *))update_pulse_state__10TBoss2MineFv)

struct VBase { char pad[0x18]; };

struct VObj : VBase {
#define V(n) virtual void m##n();
V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)
V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)
V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)V(58)V(59)
V(60)V(61)V(62)V(63)V(64)V(65)V(66)V(67)V(68)V(69)V(70)V(71)V(72)V(73)V(74)V(75)V(76)V(77)V(78)V(79)
V(80)V(81)V(82)V(83)V(84)V(85)V(86)V(87)V(88)V(89)V(90)V(91)V(92)V(93)V(94)V(95)
#undef V
};

struct VBase_80037EE0 { char pad[0x18]; };

struct VObj_80037EE0 : VBase_80037EE0 {
#define V(n) virtual void m##n();
V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)
V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)
V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)V(58)V(59)
V(60)V(61)V(62)V(63)V(64)V(65)V(66)V(67)V(68)V(69)V(70)V(71)V(72)V(73)V(74)V(75)V(76)V(77)V(78)V(79)
V(80)V(81)V(82)V(83)V(84)V(85)V(86)V(87)V(88)V(89)V(90)V(91)V(92)V(93)V(94)V(95)
#undef V
};

extern "C" {
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(s32, f32, f32, f32);
void*TUnk_80482D04::create(int a1, int a2, int a3) { TBoss2Mine__ct(this, a1, a2, a3, 1); *(int*)((char*)this + 0x18) = (int)lbl_80482D04; *(int*)((char*)this + 0x3f0) = 0; *(int*)((char*)this + 0x3f4) = 0; *(float*)((char*)this + 0x3f8) = (0.0f); *(float*)((char*)this + 0x3fc) = (0.0f); *(float*)((char*)this + 0x400) = (0.0f); *(float*)((char*)this + 0x404) = (0.0f); *(float*)((char*)this + 0x408) = (0.0f); *(float*)((char*)this + 0x40c) = (0.0f); return this; }
#pragma push
#pragma fp_contract on
void TUnk_80482EC0::vfunc_106(s32 arg1) {
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r7;
    switch (arg1) {
    case 4:
        ((VObj *) ((u8 *)this))->m94();
        *(s32 *)((s8 *)((u8 *)this) + 0x38C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x38C) & ~5);
        temp_r5 = *(s32 *)((s8 *)((u8 *)this) + 0x38C) | 2;
        *(s32 *)((s8 *)((u8 *)this) + 0x38C) = temp_r5;
        *(s32 *)((s8 *)((u8 *)this) + 0x5C) = 0x8000;
        *(s32 *)((s8 *)((u8 *)this) + 0x3B0) = 0;
        *(s32 *)((s8 *)((u8 *)this) + 0x3C8) = 0;
        temp_r7 = (s32) ((3e+01f) * calc_elapsed_scaled__9TObjEneDDFv(this, 0x8000, temp_r5));
        *(s32 *)((s8 *)((u8 *)this) + 0x3CC) = (temp_r7 + 0xB4);
        play_sound_effect(0x4003A804, (void *) (((u8 *)this) + 0x2FC), 0, 0, temp_r7);
        init_params__10TBoss2MineFlf(this, 0x1E, (f32) ((0.25f)));
        return;
    case 3:
        temp_r4 = *(s32 *)((s8 *)((u8 *)this) + 0x38C);
        if (temp_r4 & 0x100) {
            *(s32 *)((s8 *)((u8 *)this) + 0x38C) = (s32) (temp_r4 & 0xFFFFFEFF);
            transition_enemy_state__9TObjEneDDFs(this, 1);
        }
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x3C8) == 2) {
            transition_enemy_state__9TObjEneDDFs(this, 3);
        }
        break;
    case 5:
        break;
    case 0:
        switch (*(s32 *)((s8 *)((u8 *)this) + 0x3C8)) {
        case 0:
            *(s32 *)((s8 *)((u8 *)this) + 0x3A8) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3A8) + 0x280);
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x3A8) >= 0x38E3) {
                *(s32 *)((s8 *)((u8 *)this) + 0x3A8) = 0x38E3;
                *(s32 *)((s8 *)((u8 *)this) + 0x3C8) = 1;
                return;
            }
            break;
        case 1:
            *(s32 *)((s8 *)((u8 *)this) + 0x3CC) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3CC) - 1);
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x3CC) <= 0) {
                *(s32 *)((s8 *)((u8 *)this) + 0x3C8) = 2;
            }
            this->set_state_by_distance((int) (*(s32 *)((s8 *)((u8 *)this) + 0x3CC)));
            update_pulse_state__10TBoss2MineFv(this);
            break;
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_80482EC0::vfunc_105(s32 arg1) {
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_r3;
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        ((VObj_80037EE0 *)arg0)->m93();
        *(s32 *)((s8 *)arg0 + 0x38C) = (s32) (*(s32 *)((s8 *)arg0 + 0x38C) & 0xFFFFFFF8);
        VecCopy((Vec *)(arg0 + 0x39C), (const Vec *)(arg0 + 0x390));
        subtract_vector(arg0 + 0x39C, arg0 + 0x2FC);
        *(f32 *)((s8 *)arg0 + 0x3DC) = ((TObjBoss2Tunnel *)(arg0 + 0x39C))->clamp_velocity();
        temp_r3 = (s32) ((10430.38043493439) * atan2_float(*(f32 *)((s8 *)arg0 + 0x39C), *(f32 *)((s8 *)arg0 + 0x3A4)));
        *(s32 *)((s8 *)arg0 + 0x60) = temp_r3;
        *(s32 *)((s8 *)arg0 + 0x5C) = 0x4000;
        temp_f2 = *(f32 *)((s8 *)arg0 + 0x300);
        temp_f1 = newton_sqrtf(temp_r3, ((2.0f) * (temp_f2 - *(f32 *)((s8 *)arg0 + 0x394))) / (0.2f), temp_f2, (2.0f));
        *(f32 *)((s8 *)arg0 + 0x3E4) = (1e+01f) * temp_f1;
        *(f32 *)((s8 *)arg0 + 0x3EC) = (f32) (1e+01f);
        *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 0.0f;
        *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
        *(f32 *)((s8 *)arg0 + 0x3E0) = (f32) *(f32 *)((s8 *)arg0 + 0x3DC);
        break;
    case 3:
        if (*(f32 *)((s8 *)arg0 + 0x300) < *(f32 *)((s8 *)arg0 + 0x394)) {
            *(f32 *)((s8 *)arg0 + 0x300) = *(f32 *)((s8 *)arg0 + 0x394);
            transition_enemy_state__9TObjEneDDFs(arg0, 2);
        }
        break;
    case 5:
        break;
    case 0:
        *(f32 *)((s8 *)arg0 + 0x2FC) = (f32) ((*(f32 *)((s8 *)arg0 + 0x39C) * *(f32 *)((s8 *)arg0 + 0x3EC)) + *(f32 *)((s8 *)arg0 + 0x2FC));
        *(f32 *)((s8 *)arg0 + 0x304) = (f32) ((*(f32 *)((s8 *)arg0 + 0x3A4) * *(f32 *)((s8 *)arg0 + 0x3EC)) + *(f32 *)((s8 *)arg0 + 0x304));
        *(f32 *)((s8 *)arg0 + 0x3E0) = (f32) (*(f32 *)((s8 *)arg0 + 0x3E0) - *(f32 *)((s8 *)arg0 + 0x3EC));
        if (*(f32 *)((s8 *)arg0 + 0x3E0) < *(f32 *)((s8 *)arg0 + 0x3E4)) {
            *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3E8) - (0.2f));
            *(f32 *)((s8 *)arg0 + 0x300) = (f32) (*(f32 *)((s8 *)arg0 + 0x300) + *(f32 *)((s8 *)arg0 + 0x3E8));
            if ((s32) *(s32 *)((s8 *)arg0 + 0x5C) >= 0x8000) {
                *(s32 *)((s8 *)arg0 + 0x5C) = 0x8000;
            } else {
                *(s32 *)((s8 *)arg0 + 0x3D8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3D8) + 0x300);
                *(s32 *)((s8 *)arg0 + 0x5C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3D8) + 0x4000);
            }
        } else {
            *(s32 *)((s8 *)arg0 + 0x5C) = 0x4000;
        }
        ((TBoss2Mine *)arg0)->update_move_flag();
        break;
    }
}
#pragma pop

void TBoss2Mine::set_launch_position_velocity(u8 *arg1, u8 *arg2) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x38C) = (s32) (*(s32 *)((s8 *)arg0 + 0x38C) | 0x100);
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)arg1);
    VecCopy((Vec *)(arg0 + 0x390), (const Vec *)arg2);
    *(f32 *)((s8 *)arg0 + 0x394) += 1.0f;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x2FC));
    *(s32 *)((s8 *)arg0 + 0x3A8) = 0;
    *(s16 *)((s8 *)arg0 + 0x32C) = (s16) *(s16 *)((s8 *)arg0 + 0x2B8);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & ~0xA00);
}

}

#undef init_params__10TBoss2MineFlf
#undef calc_elapsed_scaled__9TObjEneDDFv
#undef play_sound_effect
#undef update_pulse_state__10TBoss2MineFv
#define play_sound_effect ((s32 (*)(s32, u32, s16, s32))play_sound_effect)
#define TBoss2Mine__ct ((void *(*)(void *, s32, s16, s16, s32))TBoss2Mine__ct)
#define set_node_offsets__10TBoss2MineFv ((void (*)(void *))set_node_offsets__10TBoss2MineFv)

struct Base_8003843C_80038140 { char pad[0x18]; };
struct VObj_8003843C_80038140 : Base_8003843C_80038140 {
#define V(n) virtual void m##n();
    V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)
    V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)
    V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)
    V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)
    V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)
    V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)V(58)V(59)
    V(60)V(61)V(62)V(63)V(64)V(65)V(66)V(67)V(68)V(69)
    V(70)V(71)V(72)V(73)V(74)V(75)V(76)V(77)V(78)V(79)
    V(80)V(81)V(82)V(83)V(84)V(85)V(86)V(87)V(88)V(89)
    V(90)V(91)V(92)V(93)
#undef V
    virtual void m94();
};

struct VBase_18_444bc5
{
  char pad[0x18];
};

struct VObj_18_444bc5 : VBase_18_444bc5 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
};

struct ByteBlock_10
{
  u8 bytes[0x10];
};

struct ByteBlock_14
{
  u8 bytes[0x14];
};

struct RecoveredGlobal_800384C8_lbl_80435AB0
{
  s32 value;
  u8 remaining[0x10];
};

struct Vec_80038200 { f32 x, y, z; };

struct Col_80038200 { s32 a; f32 r, g, b; };

struct Base_80038200 { char pad[0x18]; };

struct Mine_80038200 : Base_80038200 {
#define V(n) virtual void m##n();
    V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)
#undef V
    virtual s32 m8(f32, f32);
#define V(n) virtual void m##n();
    V(9)V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)
    V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)
    V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)
    V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)
    V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)V(58)V(59)
    V(60)V(61)V(62)V(63)V(64)V(65)V(66)V(67)V(68)V(69)
    V(70)V(71)V(72)V(73)V(74)V(75)V(76)V(77)V(78)V(79)
    V(80)V(81)V(82)V(83)V(84)V(85)V(86)V(87)V(88)V(89)
    V(90)V(91)V(92)V(93)V(94)V(95)V(96)V(97)V(98)V(99)
    V(100)V(101)V(102)V(103)V(104)V(105)V(106)V(107)
#undef V
    virtual void m108();
    u8 pad1C[0x24 - 0x1C];
    void *f24;
    u8 pad28[0x34 - 0x28];
    void *model;
    Vec_80038200 pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 pad68[0x300 - 0x68];
    f32 f300;
    u8 pad304[0x326 - 0x304];
    s16 f326;
    u8 pad328[0x38C - 0x328];
    u32 flags;
    u8 pad390[0x3AC - 0x390];
    f32 f3AC;
    u32 f3B0;
};

extern "C" {
f32 TBoss2DeRolLe__sub_80034CEC(void);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
void TObjEneDD__sub_800BA5A4(void *p, void *a1);
extern RecoveredGlobal_800384C8_lbl_80435AB0 boss2_mine_collision_desc;
void scale_matrix(s32, f32, f32, f32);
void rotate_matrix_y(s32, s32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void rotate_matrix_x(s32, s32);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
void draw_chunk_object(void *);
extern Vec_80038200 lbl_80435AD0;
extern Col_80038200 boss2_mine_render_color;
extern void *lbl_805D28BC;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void *TBoss2Mine__sub_800381B8(void *arg0, s32 arg1, s16 arg2, s16 arg3);

void TUnk_80482EC0::vfunc_88() {
    *(f32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 4) = (f32) ((5.0f) + (*(f32 *)((s8 *)this + 0x300) - *(f32 *)((s8 *)this + 0x3C)));
}

extern s32 lbl_80482EC0[];

void *TBoss2Mine::deleting_dtor(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_80482EC0;
        __dt__10TBoss2MineFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TBoss2Mine__sub_800381B8(void *arg0, s32 arg1, s16 arg2, s16 arg3) {
    TBoss2Mine__ct(arg0, arg1, arg2, arg3, 0);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_80482EC0;
    return arg0;
}

void TBoss2Mine::vfunc_110() {  }
void TBoss2Mine::vfunc_109() {  }

void TBoss2Mine::render() {
    Mine_80038200 *self = (Mine_80038200 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        self->m108();
        return;
    }
    if (self->flags & 1) {
        return;
    }
    if (self->m8((4e+02f), (2e+01f)) == 0) {
        return;
    }
    if (self->flags & 2) {
        Vec_80038200 v = lbl_80435AD0;
        ((TObjEnemy *)self)->render_with_position_override((u8 *)&v, 0);
    }
    TObjFish::set_global_param((s32)self->f24);
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    TObjPlayer::toggle_particle_effect();
    set_node_offsets__10TBoss2MineFv(self);
    push_matrix();
    post_translate_matrix(&self->pos);
    translate_matrix(0, (0.0f), self->f300 - self->pos.y, (0.0f));
    rotate_matrix_y(0, self->f60);
    rotate_matrix_x(0, self->f5C);
    rotate_matrix_y(0, self->f64);
    translate_matrix(0, (0.0f), (-1e+01f), (0.0f));
    if (self->flags & 4) {
        model_render_flags |= 0x20;
        Col_80038200 c = boss2_mine_render_color;
        f32 f = -(f32)(self->f3B0 >> 16) / (255.0f);
        c.b = f;
        c.g = f;
        c.r = -f;
        set_constant_material((const NJS_ARGB *)(((f32 *)&c)));
        draw_chunk_object(self->model);
    } else {
        draw_chunk_object(self->model);
    }
    pop_matrix();
    if (self->f326 == 3) {
        push_matrix();
        f32 s = (0.5f) * self->f3AC;
        post_translate_matrix(&self->pos);
        scale_matrix(0, s, (3.0f), s);
        draw_chunk_object(lbl_805D28BC);
        pop_matrix();
    }
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
}

void TBoss2Mine::vfunc_108(s32 arg1) {
    switch (arg1) {
    case 4:
        ((VObj_8003843C_80038140 *)this)->m94();
        *(s32 *)((s8 *)this + 0x38C) = (s32) (*(s32 *)((s8 *)this + 0x38C) & 0xFFFFFFF8);
        return;
    case 3:
        transition_enemy_state__9TObjEneDDFs(this, 0);
        return;
    case 5:
        *(s32 *)((s8 *)this + 0x30) = (s32) (*(s32 *)((s8 *)this + 0x30) & 0xFFFFF7FF);
        *(s16 *)((s8 *)this + 0x32C) = (s16) *(s16 *)((s8 *)this + 0x2B8);
    case 0:
        return;
    }
}

typedef struct CopyStack_800384C8 CopyStack_800384C8;
typedef struct ByteBlock_10 ByteBlock_10;
typedef struct ByteBlock_14 ByteBlock_14;
typedef struct RecoveredGlobal_800384C8_lbl_80435AB0 RecoveredGlobal_800384C8_lbl_80435AB0;
typedef struct VBase_18_444bc5 VBase_18_444bc5;
typedef struct VObj_18_444bc5 VObj_18_444bc5;
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
typedef char RecoveredGlobal_800384C8_lbl_80435AB0_size[((sizeof(RecoveredGlobal_800384C8_lbl_80435AB0)) == 0x14) ? (1) : (-1)];
void TBoss2Mine::vfunc_107(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  struct CopyStack_800384C8
  {
    u8 bytes[0x14];
  };
  CopyStack_800384C8 copy_storage_800384C8;
  switch (arg1)
  {
    case 4:
      (this->vfunc_96());
      *((s32 *) (((s8 *) arg0) + 0x38C)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x38C))) & 0xFFFFFFF8);
      *((s32 *) (((s8 *) arg0) + 0x3B0)) = 0;
      *((s32 *) (((s8 *) arg0) + 0x3C8)) = 0;
      *((s32 *) (((s8 *) arg0) + 0x3CC)) = 0;
      create_timed_particle_emitter((void *)((*((s32 *) (((s8 *) arg0) + 0xA4))) + 0x1C), 0x16A, 0, 6);
      return;
    case 3:
      if (((s32) (*((s32 *) (((s8 *) arg0) + 0x3CC)))) == 2)
    {
      transition_enemy_state__9TObjEneDDFs(arg0, 0);
    }
    case 5:
      return;
      return;
    case 0:
      *((s32 *) (((s8 *) arg0) + 0x3C8)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x3C8))) + 1);
      if (((s32) (*((s32 *) (((s8 *) arg0) + 0x3C8)))) > 0x1E)
    {
      *((ByteBlock_14 *) (((s32)(copy_storage_800384C8.bytes - 0x4)) + 4)) = *((const ByteBlock_14 *) (((s32) (((u8 *)&boss2_mine_collision_desc.value) - 4)) + 4));
      *((f32 *)(copy_storage_800384C8.bytes + 0x4)) = TBoss2DeRolLe__sub_80034CEC();
      TObjEneDD__sub_800BA5A4(arg0, copy_storage_800384C8.bytes);
      spawn_particle_effect_with_flags((void *)((*((s32 *) (((s8 *) arg0) + 0xA4))) + 0x1C), 0x16B, 0x40);
      *((s32 *) (((s8 *) arg0) + 0x3CC)) = 2;
      play_sound_effect(0x4003AD05, (u32)(arg0 + 0x2FC), 0, 0);
    }
      break;
  }
}

void TBoss2Mine::vfunc_106(s32) {  }
void TBoss2Mine::vfunc_105(s32) {  }

}

#undef play_sound_effect
#undef TBoss2Mine__ct
#undef set_node_offsets__10TBoss2MineFv
#define transition_enemy_state__9TObjEneDDFs ((int (*)(void *, void *))transition_enemy_state__9TObjEneDDFs)

#define VM(n) virtual void m##n();
struct Base_800386A4_80038610 { char pad[0x18]; };
struct VObj_800386A4_80038610 : Base_800386A4_80038610 {
    VM(0) VM(1) VM(2) VM(3) VM(4) VM(5) VM(6) VM(7) VM(8) VM(9)
    VM(10) VM(11) VM(12) VM(13) VM(14) VM(15) VM(16) VM(17) VM(18) VM(19)
    VM(20) VM(21) VM(22) VM(23) VM(24) VM(25) VM(26) VM(27) VM(28) VM(29)
    VM(30) VM(31) VM(32) VM(33) VM(34) VM(35) VM(36) VM(37) VM(38) VM(39)
    VM(40) VM(41) VM(42) VM(43) VM(44) VM(45) VM(46) VM(47) VM(48) VM(49)
    VM(50) VM(51) VM(52) VM(53) VM(54) VM(55) VM(56) VM(57) VM(58) VM(59)
    VM(60) VM(61) VM(62) VM(63) VM(64) VM(65) VM(66) VM(67) VM(68) VM(69)
    VM(70) VM(71) VM(72) VM(73) VM(74) VM(75) VM(76) VM(77) VM(78) VM(79)
    VM(80) VM(81) VM(82) VM(83) VM(84) VM(85) VM(86) VM(87) VM(88) VM(89)
    VM(90) VM(91) VM(92) VM(93) VM(94) VM(95) VM(96) VM(97) VM(98) VM(99)
    VM(100) VM(101)
    virtual void m102(s32);
    virtual void m103(s32);
    virtual void m104(s32);
    virtual void m105(s32);
    virtual void m106(s32);
};

struct N_80038908 { u8 pad[0x14]; s32 f14; u8 pad2[0x30 - 0x18]; N_80038908 *next; };

struct M_80038908 { u8 pad[0x2c]; N_80038908 *first; };

struct O_80038908 { u8 pad[0x34]; M_80038908 *m; u8 pad2[0x3a8 - 0x38]; s32 f3a8; };

typedef struct Mine_80038760 {
    u8 pad0[0x38C];
    s32 flags;
    u8 pad390[0x3B0 - 0x390];
    s32 angle;
    f32 scale;
    f32 speed;
    s32 timer;
    s32 wait;
    s32 state;
} Mine_80038760;

extern "C" {

struct Base_80038948_80038610 {
    char pad[0x18];
};
struct VObj_80038948_80038610 : Base_80038948_80038610 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual u32 m102();
};

void TBoss2Mine__vt102(void *arg0, s32 arg1);
void TBoss2Mine__vt85(void *arg0, s32 arg1, s32 arg2);

void TBoss2Mine__vt102(void *boss2_mine, s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        ((TBoss2Mine *)boss2_mine)->vfunc_95();
        *(s32 *)((s8 *)boss2_mine + 0x38C) = (s32) (*(s32 *)((s8 *)boss2_mine + 0x38C) | 1);
        *(s32 *)((s8 *)boss2_mine + 0x38C) = (s32) (*(s32 *)((s8 *)boss2_mine + 0x38C) & 0xFFFFFFF9);
        return;
    case 3:
        temp_r4 = *(s32 *)((s8 *)boss2_mine + 0x38C);
        if (temp_r4 & 0x100) {
            *(s32 *)((s8 *)boss2_mine + 0x38C) = (s32) (temp_r4 & 0xFFFFFEFF);
            transition_enemy_state__9TObjEneDDFs((void*)((s32)boss2_mine), (void*)(1));
        }
    case 5:
    case 0:
        return;
    }
}

void TBoss2Mine__vt85(void *arg0, s32 arg1, s32 arg2) {
    VObj_800386A4_80038610 *o = (VObj_800386A4_80038610 *)arg0;
    switch (arg1) {
    case 0:
        o->m102(arg2);
        return;
    case 1:
        o->m103(arg2);
        return;
    case 2:
        o->m104(arg2);
        return;
    case 3:
        o->m105(arg2);
        return;
    case 4:
        o->m106(arg2);
        return;
    }
}

void TBoss2Mine::update_pulse_state() {
    ((Mine_80038760 *)this)->timer++;
    switch (((Mine_80038760 *)this)->state) {
    case 2:
        if (((Mine_80038760 *)this)->timer >= ((Mine_80038760 *)this)->wait) {
            ((Mine_80038760 *)this)->timer = 0;
            ((Mine_80038760 *)this)->scale = (0.0f);
            ((Mine_80038760 *)this)->state = 0;
        } else {
            ((Mine_80038760 *)this)->flags &= ~4;
            break;
        }
    case 0: {
        ((Mine_80038760 *)this)->scale += ((Mine_80038760 *)this)->speed;
        if (((Mine_80038760 *)this)->scale >= 1.0f) {
            ((Mine_80038760 *)this)->scale = 1.0f;
            ((Mine_80038760 *)this)->state = 1;
        }
        ((Mine_80038760 *)this)->angle = (s32)((255.0f) * ((Mine_80038760 *)this)->scale) << 16;
        ((Mine_80038760 *)this)->flags |= 4;
        break;
    }
    case 1: {
        ((Mine_80038760 *)this)->scale -= ((Mine_80038760 *)this)->speed;
        if (((Mine_80038760 *)this)->scale <= 0.0f) {
            ((Mine_80038760 *)this)->scale = 0.0f;
            ((Mine_80038760 *)this)->timer = 0;
            ((Mine_80038760 *)this)->state = 2;
        }
        ((Mine_80038760 *)this)->angle = (s32)((255.0f) * ((Mine_80038760 *)this)->scale) << 16;
        ((Mine_80038760 *)this)->flags |= 4;
        break;
    }
    case 3:
        break;
    }
}

void TBoss2Mine::set_state_by_distance(s32 arg1) {
    if (arg1 < 0x5A) {
        f32 temp = (0.5f);
        *(s32 *)((s8 *)this + 0x3C0) = 3;
        *(f32 *)((s8 *)this + 0x3B8) = temp;
        return;
    }
    if (arg1 < 0x96) {
        *(s32 *)((s8 *)this + 0x3C0) = 5;
        return;
    }
    if (arg1 < 0x12C) {
        *(s32 *)((s8 *)this + 0x3C0) = 0xA;
        return;
    }
    *(s32 *)((s8 *)this + 0x3C0) = 0x1E;
}

void TBoss2Mine::init_params(s32 arg1, f32 farg0) {
    *(f32 *)((s8 *)((u8 *)this) + 0x3B8) = farg0;
    *(s32 *)((s8 *)((u8 *)this) + 0x3C0) = arg1;
    *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x3B4) = (f32) (0.0f);
    *(s32 *)((s8 *)((u8 *)this) + 0x3BC) = 0;
}

void TBoss2Mine::set_node_offsets() {
    N_80038908 *n = ((O_80038908 *)this)->m->first;
    s32 i;
    s32 v = -((O_80038908 *)this)->f3a8;
    for (i = 0; i < 4; i++) {
        n->f14 = v;
        n = n->next;
    }
    v = ((O_80038908 *)this)->f3a8;
    for (i = 0; i < 4; i++) {
        n->f14 = v;
        n = n->next;
    }
}

void TBoss2Mine::update_move_flag() {
    struct VObj_80038948_80038610 *obj = (struct VObj_80038948_80038610 *) this;
    *(f32 *)((s8 *)this + 0x38) = (f32) *(f32 *)((s8 *)this + 0x2FC);
    *(f32 *)((s8 *)this + 0x40) = (f32) *(f32 *)((s8 *)this + 0x304);
    if (obj->m102() == 0U) {
        *(s32 *)((s8 *)this + 0x38C) = (s32) (*(s32 *)((s8 *)this + 0x38C) & 0xFFFFFFFD);
        return;
    }
    *(s32 *)((s8 *)this + 0x38C) = (s32) (*(s32 *)((s8 *)this + 0x38C) | 2);
}

void TBoss2Mine::save_position() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }
void TBoss2Mine::vfunc_61() {  }

}

#undef transition_enemy_state__9TObjEneDDFs
#define transition_enemy_state__9TObjEneDDFs ((int (*)(void *, void *))transition_enemy_state__9TObjEneDDFs)

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual s32 m81();
    virtual void m82();
    virtual void m83();
    virtual s32 m84();
    virtual s32 m85(s16, s32);
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual s32 m107();
};

void TBoss2Mine::vfunc_62() { clear_attack_receipts(); }

void TBoss2Mine::vfunc_63() { if (*(short*)((char*)this + 0x326) != 4) { transition_enemy_state__9TObjEneDDFs(this, (void*)4); } }
void TBoss2Mine::vfunc_28() {  }
void TBoss2Mine::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_109();
        return;
    }
    this->vfunc_83();
    if (((VObj_18 *)(arg0))->m84() == 0) {
        ((VObj_18 *)(arg0))->m85(*(s16 *)((s8 *)arg0 + 0x326), 3);
    }
    ((VObj_18 *)(arg0))->m85(*(s16 *)((s8 *)arg0 + 0x326), 0);
    ((TObjEneDD *)arg0)->sub_800BBA0C();
    if (!(*(s32 *)((s8 *)arg0 + 0x38C) & 1)) {
        save_position();
        this->vfunc_88();
        ((TBoss8Dragon *)arg0)->set_player_state_default();
        this->vfunc_100();
    }
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
}

#undef transition_enemy_state__9TObjEneDDFs

struct VBase_18_72b3e0 { char pad[0x18]; };

struct VObj_18_72b3e0 : VBase_18_72b3e0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual s32 m85(s16, s32);
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
};

typedef struct Rec_80038BA0 { u8 d[0x1C]; } Rec_80038BA0;

typedef struct Tbl_80038BA0 {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    Rec_80038BA0 d[2];
    u8 model[0x10];
} Tbl_80038BA0;

extern "C" {
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 init_model__9TObjEneDDFv(void *, void *, int, int);
extern u8 *lbl_805D4BA4;
void init__10TBoss2MineFPvi(u8 *arg0, s32 arg1);
void *__dt__9TObjEneDDFv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);

extern s32 __vt__10TBoss2Mine[];

void *__dt__10TBoss2MineFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TBoss2Mine;
        free_collision_body_parts(arg0);
        __dt__9TObjEneDDFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
__declspec(section ".data") void *boss2_mine_params[2] = {
    (void *)0x11, (void *)0x11,
};
__declspec(section ".data") void *lbl_80482C90[2] = {
    (void *)0xf, (void *)0xf,
};
__declspec(section ".data") void *lbl_80482C98[2] = {
    (void *)0x11, (void *)0x11,
};
void *lbl_80482CA0[14] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x43610000,
    (void *)0x0, (void *)0x600, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *lbl_80482CD8[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40a00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void init__10TBoss2MineFPvi(u8 *boss2_mine, s32 arg1) {
    s32 temp_r29;
    s32 temp_r30;
    u8 *temp_r6;
    ((TObjEneDD *)boss2_mine)->init_position_vectors();
    *(s32 *)((s8 *)boss2_mine + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D4BA4 + 0x42C)) + 0x38);
    temp_r6 = *(u8 **)((s8 *)lbl_805D4BA4 + 0x42C);
    *(s32 *)((s8 *)boss2_mine + 0x24) = *(s32 *)((s8 *)temp_r6 + 0x2C);
    init_model__9TObjEneDDFv(boss2_mine, (u8 *)lbl_80482CD8, 1, (int)temp_r6);
    reset_hp__9TObjEneDDFv(boss2_mine, register_boss__6TLobbyFl(((s32 *)boss2_mine_params)[arg1]),
                            dispatch_shared_handler_b__6TLobbyFl(((s32 *)lbl_80482C90)[arg1]),
                            register_object__6TLobbyFl(((s32 *)lbl_80482C98)[arg1]));
    ((TObjEneDD *)boss2_mine)->check_state_flag_2();
    *(Rec_80038BA0 **)((s8 *)boss2_mine + 0x350) = &((Rec_80038BA0 *)lbl_80482CA0)[arg1];
    *(f32 *)((s8 *)boss2_mine + 0x37C) = (3.0f);
    ((TBoss2Mine *)(boss2_mine))->vfunc_95();
    *(s32 *)((s8 *)boss2_mine + 0x38C) = 0;
    *(f32 *)((s8 *)boss2_mine + 0x390) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x394) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x398) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x39C) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x3A0) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x3A4) = (0.0f);
    *(s32 *)((s8 *)boss2_mine + 0x3A8) = 0;
    *(f32 *)((s8 *)boss2_mine + 0x3AC) = (0.0f);
    *(s32 *)((s8 *)boss2_mine + 0x3B0) = 0;
    *(f32 *)((s8 *)boss2_mine + 0x3B4) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x3B8) = (0.0f);
    *(s32 *)((s8 *)boss2_mine + 0x3BC) = 0;
    *(s32 *)((s8 *)boss2_mine + 0x3C0) = 0;
    *(s32 *)((s8 *)boss2_mine + 0x3C4) = 2;
    *(s32 *)((s8 *)boss2_mine + 0x3C8) = 0;
    *(s32 *)((s8 *)boss2_mine + 0x3CC) = 0;
    *(s32 *)((s8 *)boss2_mine + 0x3D0) = 0;
    *(s32 *)((s8 *)boss2_mine + 0x3D8) = 0;
    *(f32 *)((s8 *)boss2_mine + 0x3DC) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x3E0) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x3E4) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x3E8) = (0.0f);
    *(f32 *)((s8 *)boss2_mine + 0x3EC) = (0.0f);
    *(s16 *)((s8 *)boss2_mine + 0x326) = 0;
    ((VObj_18_72b3e0 *)(boss2_mine))->m85(*(s16 *)((s8 *)boss2_mine + 0x326), 4);
}

}
