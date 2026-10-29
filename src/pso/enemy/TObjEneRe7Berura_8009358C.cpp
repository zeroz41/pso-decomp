#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TUnk_80494968.h"
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEneRe7BeruraPunch.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define PADV virtual void CAT(f,__LINE__)();

struct VBase_18_a5c788 { char pad[0x18]; };
struct VObj_18_a5c788 : VBase_18_a5c788 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(void *, void *);
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual f32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *, f32);
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
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

typedef struct { u32 a : 8; u32 rest : 24; } ClrTop;
struct VBase_14_80094470 { char pad[0x14]; };

struct VSub_80094470 : VBase_14_80094470 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4();
};

struct VBase_14_664b17 { char pad[0x14]; };

struct VObj_14_664b17 : VBase_14_664b17 {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual void m4();
    virtual s32 m5();
};

struct Vec_80093C80 { f32 x, y, z; };

struct Tbl_80093C80 { u8 pad0[0xC]; s32 anim; f32 hi; f32 lo; u8 pad18[0x40]; Vec_80093C80 ofs; u8 pad64[0x0]; };

struct Obj_80093C80 { u8 pad[0x418]; s32 armf[2]; Vec_80093C80 armp[2]; void *emit[2]; };

struct SBase_80094624 { char pad[0x14]; };

struct Sub_80094624 : SBase_80094624 {
    virtual void s0();
    virtual void s1();
    virtual void s2(s32);
};

extern "C" {
f32 atan2_float(f32 y, f32 x);
s32 check_death_trigger__16TObjEneRe7BeruraFv();
s32 is_over_limit__16TObjEneRe7BeruraFv(void *);
s32 TObjEneRe7Berura__sub_8009518C(void *);
s32 advance_animation_playback();
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
extern const f64 lbl_80439EF0;
extern const f32 TObjEneRe7Berura__data_805D9724;
extern const f32 TObjEneRe7Berura__data_805D972C;
extern const f32 TObjEneRe7Berura__data_805D9740;
extern const f32 lbl_805D9760;
extern const f32 TObjEneRe7Berura__data_805D9764;
extern const f32 lbl_805D9768;
void TObjEneRe7Berura__sub_800940E8(TObjEneRe7Berura *arg0, s32 arg1);

f32 random_ratio__9TObjCharaFv(s32);
s32 get_field_3D4_shifted__16TObjEneRe7BeruraFPv(void *);
s32 enemy_validate_retained_target(u8 *arg0);
s32 play_sound_effect(s32, u32, s16, s32);
s32 push_matrix(void);
s32 pop_matrix(void);
f32 post_translate_matrix(void *);
void TObjEneDD__sub_800BA378(s32 arg0, u8 *arg1);
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
void set_matrix_identity(u8 *arg0);
s32 rotate_matrix_y(int, int);
extern u8 *belra_trail_buffer;
extern const f32 lbl_805D9744;
extern const f32 lbl_805D9748;
extern const f32 lbl_805D974C;
extern const f32 lbl_805D9750;
extern const f32 lbl_805D9754;
extern const f32 lbl_805D9758;

struct Vec3_80093888 { f32 x, y, z; };
struct Timers_80093888 { u8 pad[0x440]; s32 t[2]; };

f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
extern const f32 lbl_805D976C;
void TObjEneRe7Berura__sub_8009472C(u8 *arg0, s32 arg1);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
void *create_particle_emitter(void *, s32);
s32 launch__21TObjEneRe7BeruraPunchFll(s32, s32, void *, void *);
s32 vec3_add_to(void *, void *);
extern f32 TObjEneRe7Berura__animation_definitions[];
extern Tbl_80093C80 TObjEneRe7Berura__detached_part_states[];
extern const f32 TObjEneRe7Berura__data_805D9738;
extern const f32 lbl_805D975C;
void TObjEneRe7Berura__sub_80093C80(u8 *arg0, s32 arg1);
void TObjEneRe7Berura__sub_80094624(u8 *arg0, s32 arg1);
s32 TObjEneRe7Berura__sub_80094DB4(void *);
void update_technique_slot__10TTecRaFoieFl(s32);
extern const f32 lbl_805D973C;
}

#define PAD5 PADV \
PADV \
PADV \
PADV \
PADV
struct Base_A { char pad[0x18]; };
struct V_A : Base_A {
    virtual void CAT(g,__LINE__)();
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual void m87();
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual void m94();
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual void m100(s32);
};

extern "C" void state_patrol__16TObjEneRe7BeruraFPvi(void *arg0, s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((V_A *) arg0)->m94();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 4);
        ((TObjEneDD *)arg0)->set_field_378(9);
        *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
        *(s32 *)((s8 *)arg0 + 0x4C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x60) + 0x3800);
        break;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x60) >= (s32) *(s32 *)((s8 *)arg0 + 0x4C8)) {
            ((TObjEneDD *)arg0)->transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation_playback();
        if (((TObjEneRe7BeruraPunch *)arg0)->is_patrol_active() == 0) {
            *(f32 *)((s8 *)arg0 + 0xC8) = (f32) lbl_805D973C;
        }
        temp_r4 = *(s32 *)((s8 *)arg0 + 0x60);
        *(s32 *)((s8 *)arg0 + 0x60) = (s32) (temp_r4 + 0x280);
        ((V_A *) arg0)->m100(temp_r4);
        ((V_A *) arg0)->m87();
        break;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFB);
        break;
    }

}
extern "C" {

#pragma push
#pragma opt_propagation off
void TObjEneRe7Berura::run_flash_warning_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 t;
    s32 v;
    switch (arg1) {
    case 4:
        this->requested_action = 5;
        this->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 4);
        ((TObjEneDD *)arg0)->set_field_378(4);
        *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
        this->m_4c4 = TObjEneRe7Berura__sub_80094DB4(arg0);
        *(s32 *)((s8 *)arg0 + 0x3CC) = 0;
        *(s32 *)((s8 *)arg0 + 0x4C8) = 0x300;
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x4C0) >= this->m_4c4) {
            ((TObjEneDD *)arg0)->transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation_playback();
        *(s32 *)((s8 *)arg0 + 0x4C0) = *(s32 *)((s8 *)arg0 + 0x4C0) + 1;
        t = *(s32 *)((s8 *)arg0 + 0x4C8);
        if (t > 0) {
            *(s32 *)((s8 *)arg0 + 0x4C8) = t - 0xB;
            v = (*(s32 *)((s8 *)arg0 + 0x4C8) > 0x100) ? 0x100 : *(s32 *)((s8 *)arg0 + 0x4C8);
            if (this->m_4bc > 0) {
                this->rotation_y += v;
            } else {
                this->rotation_y -= v;
            }
        }
        if ((*(s32 *)((s8 *)arg0 + 0x4C0) & 0x1F) < 0x10) {
            *(s32 *)((s8 *)arg0 + 0x3C8) = 0xFF303030;
        } else {
            *(s32 *)((s8 *)arg0 + 0x3C8) = -1;
        }
        this->vfunc_102();
        this->vfunc_89();
        ((void (*)(s32, s32, s32))update_technique_slot__10TTecRaFoieFl)(
            play_persistent_sound((s32)(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003C61E))), (s32)arg0, (u32)&this->position, 0, 0),
            0x400, 0);
        break;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFB);
        *(s32 *)((s8 *)arg0 + 0x3D4) = *(s32 *)((s8 *)arg0 + 0x3D4) + 1;
        *(s32 *)((s8 *)arg0 + 0x3C8) = -1;
        *(s32 *)((s8 *)arg0 + 0x3CC) = 0xC;
        ((TObjEneRe7Berura *)arg0)->init_fields4B8();
        break;
    }
}
#pragma pop

void TObjEneRe7Berura__sub_80093888(u8 *actor, s32 arg1) {
    Vec3_80093888 sp2C;
    Vec3_80093888 sp20;
    Vec3_80093888 sp14;
    Vec3_80093888 sp8;
    s32 i;
    s32 entry;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)actor + 0xB8) = 1;
        ((TObjEneDD *)(actor))->vfunc_96();
        *(s32 *)((s8 *)actor + 0x3C0) = (s32) (*(s32 *)((s8 *)actor + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)actor)->set_field_378(6);
        *(s32 *)((s8 *)actor + 0x4C0) = 0;
        *(s32 *)((s8 *)actor + 0x4C4) = 0;
        *(s32 *)((s8 *)actor + 0x4C8) = 0;
        *(s32 *)((s8 *)actor + 0x4CC) = get_field_3D4_shifted__16TObjEneRe7BeruraFPv(actor);
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)actor + 0x4C0) != 0) {
        case 5:
            return;
        }
        if (((s32 (*)(void *))check_death_trigger__16TObjEneRe7BeruraFv)(actor) == 0) {
            if ((void *) *(u8 **)((s8 *)actor + 0x390) == NULL) {
                ((TObjEneDD *)actor)->transition_enemy_state(8);
            } else if (*(f32 *)((s8 *)actor + 0x3AC) >= TObjEneRe7Berura__data_805D9740) {
                ((TObjEneDD *)actor)->transition_enemy_state(4);
            } else if (is_over_limit__16TObjEneRe7BeruraFv(actor) != 0) {
                ((TObjEneDD *)actor)->transition_enemy_state(7);
            }
        }
        break;
    case 0:
        advance_animation_playback();
        switch (*(s32 *)((s8 *)actor + 0x4C0)) {
        case 0:
            if (enemy_validate_retained_target(actor) != 0) {
                ((TObjEneDD_ST *)actor)->enemy_copy_target_destination();
                ((TObjEneDD *)actor)->update_velocity();
                if (((TObjEneRe7Berura *)actor)->step_toward_target((s32) (lbl_80439EF0 * atan2_float(*(f32 *)((s8 *)actor + 0x3A0), *(f32 *)((s8 *)actor + 0x3A8))), 0x100) != 0) {
                    *(s32 *)((s8 *)actor + 0x4C0) = 1;
                    *(s16 *)((s8 *)actor + 0xB8) = 2;
                    ((TObjEneRe7Berura *)actor)->init_fields4B8();
                    for (i = 0; i < 2; i++) {
                        ((TUnk_80494968 *)(((Timers_80093888 *)actor)->t[i]))->clear_segments();
                    }
                }
                ((TObjEneRe7Berura *)actor)->play_band_sound();
            }
            break;
        case 1:
            if (((TObjMotion *)actor)->is_passing_frame((f32)lbl_805D9744) != 0) {
                play_sound_effect(((TObjEnemy *)(actor))->remap_sound_for_area((s32)(0x4003AD22)), (u32) (actor + 0x38), 0, 0);
            }
            if ((((TObjMotion *)actor)->is_passing_frame((f32)lbl_805D9748) != 0) && (((TObjEneDD_ST *)actor)->enemy_check_target_valid() != 0)) {
                if (((VObj_18_a5c788 *)((u8 *)(*(u8 **)((s8 *)actor + 0x390))))->m18(actor, lbl_805D974C) != 0) {
                    if (((VObj_18_a5c788 *)((u8 *)(*(u8 **)((s8 *)actor + 0x390))))->m20(actor, lbl_805D974C) > TObjEneRe7Berura__data_805D972C) {
                        if (TObjEneDD::check_v2_mode() != 0) {
                            if (random_ratio__9TObjCharaFv((s32) actor) <= lbl_805D9750) {
                                TObjEneDD__sub_800BA378((s32)actor, (*(u8 **)((s8 *)actor + 0x390)));
                            }
                        } else if (random_ratio__9TObjCharaFv((s32) actor) <= lbl_805D9754) {
                            TObjEneDD__sub_800BA378((s32)actor, (*(u8 **)((s8 *)actor + 0x390)));
                        }
                    }
                    ((VObj_18_a5c788 *)((u8 *)(*(u8 **)((s8 *)actor + 0x390))))->m23(actor, lbl_805D9758);
                }
            }
            entry = TObjPlayer::lookup_entry_by_value(belra_trail_buffer, *(f32 *)((s8 *)actor + 0xC0));
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(actor + 0x38);
                rotate_matrix_y(0, (int) (*(s32 *)((s8 *)actor + 0x60)));
                mult_vec_array__10TObjPlayerFUll(0, entry, (void *) (&sp8), 4);
                pop_matrix();
                ((VObj_18_a5c788 *)((u8 *)(*(u8 **)((s8 *)actor + 0x440))))->m4(&sp8, &sp14);
                ((VObj_18_a5c788 *)((u8 *)(*(u8 **)((s8 *)actor + 0x444))))->m4(&sp20, &sp2C);
            }
            if (((TObjEneDD *)actor)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)actor + 0x4C0) = 2;
                *(s32 *)((s8 *)actor + 0x4C4) = 0;
                *(s16 *)((s8 *)actor + 0xB8) = 0;
            }
            break;
        case 2:
            *(s32 *)((s8 *)actor + 0x4C4) = (s32) (*(s32 *)((s8 *)actor + 0x4C4) + 1);
            if ((s32) *(s32 *)((s8 *)actor + 0x4C4) >= 0x32) {
                *(s32 *)((s8 *)actor + 0x4C0) = 0;
                *(s16 *)((s8 *)actor + 0xB8) = 1;
            }
            break;
        }
        ((TObjEneDD *)(actor))->vfunc_102();
        ((TObjEneDD *)(actor))->vfunc_89();
        break;
    }
}
}

#define F(t, o) (*(t *)(arg0 + (o)))
#define EMIT_(i) (((Obj_80093C80 *)arg0)->emit[i])
#define ARMF ((s32 *)(arg0 + 0x418))
#define ARMP (((Obj_80093C80 *)arg0)->armp)
#define SUB ((VObj_14_664b17 *)(arg0 + 0x3FC))
void TObjEneRe7Berura__sub_80093C80(u8 *arg0, s32 arg1) {
    Vec_80093C80 v;
    Tbl_80093C80 *t;
    s32 ok;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)(arg0))->vfunc_96();
        F(s32, 0x3C0) &= ~3;
        F(s32, 0x3C0) |= 4;
        ((TObjEneDD *)arg0)->set_field_378(5);
        t = &TObjEneRe7Berura__detached_part_states[F(s32, 0x3F4)];
        F(s16, 0xB8) = t->anim;
        F(f32, 0x4D0) = t->lo;
        F(f32, 0x4D4) = t->hi;
        F(s32, 0x4C0) = 0;
        for (s32 i = 0; i < 2; i++) {
            EMIT_(i) = 0;
        }
        if (TObjEneDD::check_v2_mode() != 0) {
            TObjEneRe7Berura__animation_definitions[0x48 / 4] = lbl_805D975C;
            TObjEneRe7Berura__animation_definitions[0x38 / 4] = lbl_805D975C;
        } else {
            TObjEneRe7Berura__animation_definitions[0x48 / 4] = TObjEneRe7Berura__data_805D9738;
            TObjEneRe7Berura__animation_definitions[0x38 / 4] = TObjEneRe7Berura__data_805D9738;
        }
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003BC20)), (u32)(arg0 + 0x38), 0, 0);
        TObjPlayer::play_effect_if_v2(-0x100);
        break;
    case 3:
        if (F(s32, 0x4C0) == 3 && check_death_trigger__16TObjEneRe7BeruraFv() == 0) {
            ((TObjEneDD *)arg0)->transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation_playback();
        switch (F(s32, 0x4C0)) {
        case 0:
            ok = 1;
            for (s32 i = 0; i < 2; i++) {
                if (EMIT_(i) == 0) {
                    EMIT_(i) = create_particle_emitter(arg0 + 0x2FC, 0xDC);
                    if (EMIT_(i) != 0) {
                        ((TParticleCtrl *)(EMIT_(i)))->enable();
                    } else {
                        for (s32 j = 0; j < i; j++) {
                            ((TParticleCtrl *)(EMIT_(j)))->enable();
                        }
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok != 0) {
                if (F(f32, 0xC0) < F(f32, 0x4D4) && F(f32, 0xC0) >= F(f32, 0x4D0)) {
                    for (s32 i = 0; i < 2; i++) {
                        ((TParticleCtrl *)(EMIT_(i)))->enable();
                    }
                } else {
                    for (s32 i = 0; i < 2; i++) {
                        ((TParticleCtrl *)EMIT_(i))->set_position(&ARMP[i]);
                    }
                }
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)(F(f32, 0x4D0))) != 0) {
                ARMF[F(s32, 0x3F4)] |= 3;
                SUB->m3();
                VecCopy((Vec *)&v, (const Vec *)&TObjEneRe7Berura__detached_part_states[F(s32, 0x3F4)].ofs);
                rotate_xz_pair_by_angle(&v.x, &v.z, F(s32, 0x60));
                vec3_add_to(&v, arg0 + 0x38);
                launch__21TObjEneRe7BeruraPunchFll(F(s32, 0x3F8), F(s32, 0x3F4), &v, arg0 + 0x394);
                F(s32, 0x4C0) = 1;
                ((TObjEneRe7Berura *)arg0)->destroy_parts();
                play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A321)), (u32)(arg0 + 0x38), 0, 0);
                TObjPlayer::play_effect_if_v2(-0x100);
            }
            break;
        case 1:
            if (!(ARMF[F(s32, 0x3F4)] & 2)) {
                F(s32, 0x4C0) = 2;
                ARMF[F(s32, 0x3F4)] |= 4;
                ARMF[F(s32, 0x3F4)] &= ~1;
            }
            break;
        case 2:
            if (SUB->m5() != 0) {
                ARMF[F(s32, 0x3F4)] &= ~4;
                if (F(s32, 0x3F4) == 0) {
                    F(s32, 0x3F4) = 1;
                } else {
                    F(s32, 0x3F4) = 0;
                }
                F(s32, 0x4C0) = 3;
            }
            break;
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneDD *)(arg0))->vfunc_89();
        break;
    case 5:
        SUB->m2();
        ARMF[F(s32, 0x3F4)] &= ~7;
        ((TObjEneRe7Berura *)arg0)->destroy_parts();
        break;
    }
}

void TObjEneRe7Berura__sub_800940E8(TObjEneRe7Berura *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        arg0->requested_action = 1;
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)arg0)->set_field_378(4);
        *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
        *(s32 *)((s8 *)arg0 + 0x4C8) = 0;
        arg0->m_4c4 = 0;
        arg0->m_4d0 = (f32) TObjEneRe7Berura__data_805D972C;
        arg0->m_4d8 = (f32) TObjEneRe7Berura__data_805D972C;
        *(f32 *)((s8 *)arg0 + 0x4DC) = (f32) TObjEneRe7Berura__data_805D972C;
        arg0->m_4e0 = (f32) TObjEneRe7Berura__data_805D972C;
        return;
    case 3:
        if (check_death_trigger__16TObjEneRe7BeruraFv() == 0) {
            if ((u32) arg0->m_390 == 0U) {
                ((TObjEneDD *)arg0)->transition_enemy_state(8);
            } else if (*(f32 *)((s8 *)arg0 + 0x3AC) <= TObjEneRe7Berura__data_805D9740) {
                ((TObjEneDD *)arg0)->transition_enemy_state(6);
            } else if ((s32) arg0->m_4c4 == 3) {
                ((TObjEneDD *)arg0)->transition_enemy_state(5);
            } else if (is_over_limit__16TObjEneRe7BeruraFv(arg0) != 0) {
                ((TObjEneDD *)arg0)->transition_enemy_state(7);
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback();
        arg0->play_band_sound();
        if (((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneRe7Berura__data_805D9724) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
        }
        switch (arg0->m_4c4) {
        case 0:
            if (((TObjEneDD_ST *)arg0)->enemy_has_live_target() != 0) {
                *(s32 *)((s8 *)arg0 + 0x4C8) = (s32) (u16) (s32) (lbl_80439EF0 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))));
            } else {
                *(s32 *)((s8 *)arg0 + 0x4C8) = (s32) arg0->rotation_y;
            }
            arg0->m_4c4 = 1;
        case 1:
            if (arg0->step_toward_target((int) (*(s32 *)((s8 *)arg0 + 0x4C8)), 0x100) != 0) {
                arg0->m_4c4 = 2;
                arg0->m_4d8 = sin_table_lookup((int) (arg0->rotation_y));
                arg0->m_4e0 = cos_table_lookup((int) (arg0->rotation_y));
                arg0->init_fields4B8();
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            break;
        case 2:
            if (TObjEneDD::check_v2_mode() != 0) {
                if (arg0->acquire_target_in_view() != 0) {
                    ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                    ((TObjEneDD *)arg0)->update_velocity();
                    arg0->m_4c4 = 3;
                } else {
                    if (((TObjEneDD_ST *)arg0)->enemy_has_live_target() != 0) {
                        *(s32 *)((s8 *)arg0 + 0x4C8) = (s32) (u16) (s32) (lbl_80439EF0 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))));
                    } else {
                        *(s32 *)((s8 *)arg0 + 0x4C8) = (s32) arg0->rotation_y;
                    }
                    arg0->step_toward_target((int) (*(s32 *)((s8 *)arg0 + 0x4C8)), 0x100);
                }
            } else {
                arg0->m_4d0 = (f32) (arg0->m_4d0 + lbl_805D9760);
                if (arg0->m_4d0 >= TObjEneRe7Berura__data_805D9764) {
                    arg0->m_4d0 = (f32) TObjEneRe7Berura__data_805D972C;
                    *(s32 *)((s8 *)arg0 + 0x4C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x4C0) + 1);
                    if (((s32) *(s32 *)((s8 *)arg0 + 0x4C0) >= 2) && (*(f32 *)((s8 *)arg0 + 0x3AC) > lbl_805D9768) && (TObjEneRe7Berura__sub_8009518C(arg0) != 0) && (arg0->acquire_target_in_view() != 0)) {
                        *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
                        ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                        ((TObjEneDD *)arg0)->update_velocity();
                        arg0->m_4c4 = 3;
                    } else {
                        arg0->m_4c4 = 0;
                    }
                }
                ((TObjEneDD *)arg0)->move_clamped_on_ground((f32) (arg0->m_4d8), (f32) (arg0->m_4e0), lbl_805D9760);
            }
            break;
        }
        ((TObjEneDD *)(arg0))->vfunc_89();
        break;
    }
}

void TObjEneRe7Berura::handle_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        this->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)arg0)->set_field_378(8);
        *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
        this->m_4c4 = 0;
        return;
    case 3:
        if (check_death_trigger__16TObjEneRe7BeruraFv() == 0) {
            if (*(s32 *)((s8 *)arg0 + 0x4C0) == 2) {
                ((TObjEneDD *)arg0)->transition_enemy_state(4);
            } else if (*(s32 *)((s8 *)arg0 + 0x4C0) == 3) {
                ((TObjEneDD *)arg0)->transition_enemy_state(2);
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback();
        switch (*(s32 *)((s8 *)arg0 + 0x4C0)) {
        case 0:
            if (((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneRe7Berura__data_805D9724) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
                *(s32 *)((s8 *)arg0 + 0x4C0) = 2;
            } else {
                this->m_4c4 = (s32) (this->m_4c4 + 1);
                if ((s32) this->m_4c4 > 0x3C) {
                    this->m_4c4 = 0;
                    *(s32 *)((s8 *)arg0 + 0x4C0) = 1;
                    ((VSub_80094470 *)(arg0 + 0x3D8))->v2();
                    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 2);
                }
            }
            break;
        case 1:
            if (((VSub_80094470 *)(arg0 + 0x3D8))->v4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x4C0) = 3;
            }
            break;
        }
        this->vfunc_102();
        this->vfunc_89();
        break;
    }
}

void TObjEneRe7Berura__sub_80094624(u8 *ene_re7_berura, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_re7_berura + 0xB8) = 0;
        ((TObjEneDD *)ene_re7_berura)->vfunc_95();
        *(s32 *)((s8 *)ene_re7_berura + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_re7_berura + 0x3C0) & 0xFFFFFFF9);
        *(s32 *)((s8 *)ene_re7_berura + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_re7_berura + 0x3C0) | 1);
        ((TObjEneDD *)ene_re7_berura)->set_field_378(2);
        VecCopy((Vec *)(ene_re7_berura + 0x38), (const Vec *)(ene_re7_berura + 0x50));
        VecCopy((Vec *)(ene_re7_berura + 0x44), (const Vec *)(ene_re7_berura + 0x38));
        VecCopy((Vec *)(ene_re7_berura + 0x2FC), (const Vec *)(ene_re7_berura + 0x38));
        *(s32 *)((s8 *)ene_re7_berura + 0x3C4) = -1;
        s32 c = *(s32 *)((s8 *)ene_re7_berura + 0x3C8) = 0xFF000000;
        *(s32 *)((s8 *)ene_re7_berura + 0x3D4) = 1;
        ((Sub_80094624 *)(ene_re7_berura + 0x3D8))->s2(c);
        *(s32 *)((s8 *)ene_re7_berura + 0x3F4) = 1;
        ((TObjEneRe7Berura *)ene_re7_berura)->init_fields4B8();
        return;
    case 3:
        if (((TObjEneDD_ST *)ene_re7_berura)->update_linked_position(TObjEneRe7Berura__data_805D9724) != 0) {
            ((TObjEneDD *)ene_re7_berura)->transition_enemy_state(1);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneRe7Berura__sub_8009472C(u8 *arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r4;
    s32 var_r4_2;
    u32 m1;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((TObjEneDD *)arg0)->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)arg0)->set_field_378(4);
        *(u32 *)((s8 *)arg0 + 0x3C4) = 0xFFFFFFU;
        *(s32 *)((s8 *)arg0 + 0x3C8) = 0xFF000000;
        *(s32 *)((s8 *)arg0 + 0x3CC) = 0;
        *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
        *(f32 *)((s8 *)arg0 + 0x4D0) = (f32) TObjEneRe7Berura__data_805D972C;
        *(s32 *)((s8 *)arg0 + 0x4C4) = 0;
        break;
    case 3:
        if (((s32) (*(s32 *)((s8 *)arg0 + 0x4C4) & 7) == 7) && (check_death_trigger__16TObjEneRe7BeruraFv() == 0)) {
            ((TObjEneDD *)arg0)->transition_enemy_state(4);
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x4C0)) {
        case 0:
            if (((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneRe7Berura__data_805D9724) != 0) {
                *(s32 *)((s8 *)arg0 + 0x4C0) = 1;
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
            }
            break;
        case 1:
            temp_r3 = *(s32 *)((s8 *)arg0 + 0x4C4);
            if (!(temp_r3 & 1)) {
                var_r4 = (u32) *(u32 *)((s8 *)arg0 + 0x3C4) >> 0x18U;
                var_r4 += 0x20;
                if (var_r4 >= 0xFF) {
                    *(s32 *)((s8 *)arg0 + 0x4C4) = (s32) (temp_r3 | 1);
                    var_r4 = 0xFF;
                }
                *(u32 *)((s8 *)arg0 + 0x3C4) = (var_r4 << 24) | (*(u32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFF);
            }
            if (!(*(s32 *)((s8 *)arg0 + 0x4C4) & 2)) {
                *(f32 *)((s8 *)arg0 + 0x4D0) = (f32) (*(f32 *)((s8 *)arg0 + 0x4D0) + lbl_805D976C);
                *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) get_random_float__21TObjEneMe3ShinowaRealFv(*(f32 *)((s8 *)arg0 + 0x4D0));
                if ((s32) *(s32 *)((s8 *)arg0 + 0x3CC) >= 0xC) {
                    *(s32 *)((s8 *)arg0 + 0x4C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x4C4) | 2);
                    *(s32 *)((s8 *)arg0 + 0x3CC) = 0xC;
                }
            }
            temp_r3_2 = *(s32 *)((s8 *)arg0 + 0x4C4);
            if (!(temp_r3_2 & 4)) {
                var_r4_2 = *(u32 *)((s8 *)arg0 + 0x3C8) & 0xFF;
                var_r4_2 += 0x20;
                if (var_r4_2 >= 0xFF) {
                    *(s32 *)((s8 *)arg0 + 0x4C4) = (s32) (temp_r3_2 | 4);
                    var_r4_2 = 0xFF;
                }
                *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (var_r4_2 | ((var_r4_2 << 0x10) | 0xFF000000 | (var_r4_2 << 8)));
            }
            play_persistent_sound((s32)(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003C61E))), (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
            TObjPlayer::play_effect_if_v2(-0x100);
            break;
        }
        ((TObjEneDD *)arg0)->vfunc_102();
        ((TObjEneDD *)arg0)->vfunc_89();
        break;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C4) = -1;
        *(s32 *)((s8 *)arg0 + 0x3CC) = 0xC;
        ((TObjEneDD *)arg0)->vfunc_96();
        break;
    }
}
