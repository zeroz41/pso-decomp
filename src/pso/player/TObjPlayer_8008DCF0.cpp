#include "pso/player/PlayerAttackParams.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEneBalClawBody.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/misc/TNowLoading.h"

struct Row_8008ED48 { u32 *p[11]; };

struct Vec_8008F910 { f32 x, y, z; };

struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct P_8008F730 { u8 pad[0x3C4]; s32 ids[5]; s16 n; };

struct Vec_8008FAD0 { f32 x, y, z; };

struct P_8008EDE8;

struct Pair_8008EDE8 { s32 a, b; };

struct TB_8008EDE8 { u8 pad0[0x18]; };

struct T_8008EDE8 : TB_8008EDE8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(P_8008EDE8 *, f32);
    virtual void m19();
    virtual void m20(P_8008EDE8 *, f32);
    virtual void m21(P_8008EDE8 *, Pair_8008EDE8 *, s32, s32, s32);
    virtual void m22();
    virtual void m23(P_8008EDE8 *, f32);
    u8 pad1C[0x2FC - 0x1C];
    Vec_8008F910 pos;
};

struct H_8008EDE8 { u8 pad[8]; void *f8; };

struct P_8008EDE8 {
    u8 pad0[0x38];
    f32 pos38[3];
    u8 pad44[0xB4 - 0x44];
    u32 fB4;
    s16 fB8;
    u8 padBA[0x2A8 - 0xBA];
    T_8008EDE8 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_8008F910 pos;
    Vec_8008F910 vel;
    u8 pad314[0x318 - 0x314];
    s32 f318;
    u8 pad31C[0x338 - 0x31C];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    H_8008EDE8 *f350;
    u8 pad354[0x37C - 0x354];
    s32 state;
    u8 pad380[0x3C0 - 0x380];
    f32 f3C0;
    u8 pad3C4[0x3DA - 0x3C4];
    s16 f3DA;
};

struct P_8008F1DC;
#define FLD(T, off) (*(T *)((u8 *)o + (off)))
struct TB_8008F1DC { u8 pad0[0x18]; };

struct T_8008F1DC : TB_8008F1DC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(P_8008F1DC *, f32);
    virtual void m19();
    virtual void m20(P_8008F1DC *, f32);
    virtual void m21();
    virtual void m22();
    virtual void m23(P_8008F1DC *, f32);
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, void *);
    u8 pad1C[0x30 - 0x1C];
    u32 flags30;
    u8 pad34[0x2FC - 0x34];
    Vec_8008F910 pos;
};

struct H_8008F1DC { u8 pad[8]; void *f8; };

struct P_8008F1DC : T_8008F1DC {
 Vec_8008F910 vel;
    u8 pad314[0x318 - 0x314];
    s32 f318;
    u8 pad31C[0x338 - 0x31C];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    H_8008F1DC *f350;
    u8 pad354[0x37C - 0x354];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
    u8 pad38C[0x3C0 - 0x38C];
    f32 f3C0;
    u8 pad3C4[0x3E4 - 0x3C4];
    u32 p3E4;
    u32 p3E8;
    u8 f3EC[0xC];
    s32 f3F8;
    s32 f3FC;
    s32 f400;
};

struct En0Base { char pad[0x14]; };

struct En0VObj : En0Base {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

extern Row_8008ED48 lbl_805006F8[];
extern "C" {
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 check_path_obstructed(void *, Vec_8008F910 *);
s32 fn_80090464(void *, int);
extern const f32 lbl_805D9620;
extern const f32 lbl_805D966C;
void TObjPlayer__sub_8008F910(u8 *arg0);
void queue_destruction__7TObjectFv(void *arg0);
s32 TObjPlayer__sub_800A04F0(void *);
void *find_entity_by_id(u16 id);
s32 play_sound_effect(int, void *, int, int);
extern const f32 lbl_805D964C;
extern const f32 lbl_805D9664;
extern const f32 lbl_805D9668;
s32 update_enemy_wander_move(void *, Vec_8008FAD0 *, int, f32);
s32 reset_enemy_state__10TObjPlayerFv();
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjPlayer__sub_8008FAD0(u8 *arg0);
f32 random_ratio__9TObjCharaFv(s32 arg0);
void calc_velocity_toward_destination(void *, Vec_8008F910, Vec_8008F910, f32);
s32 select_enemy_destination(void *, Vec_8008F910, s32);
void copy_position_if_valid__10TObjPlayerFii(void *, Vec_8008F910);
f32 xz_distance_squared(void *, void *);
extern Pair_8008EDE8 lbl_80439B54[];
extern const f32 lbl_805D9644;
extern const f32 lbl_805D9648;
extern const f32 lbl_805D9650;
extern const f32 lbl_805D9654;
extern const f32 lbl_805D9658;
void TObjPlayer__sub_8008EDE8(P_8008EDE8 *arg0);
s16 get_actor_hp();
s32 obj_setFlags30(void *, int);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
T_8008F1DC *find_active_entity_by_id(u16);
void check_enemy_body_collisions(void *arg0);
void send_6x2F_change_player_hp(s32 arg0, s32 arg1, s32 arg2);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *src);
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern u8 identity_matrix[];
extern const f32 lbl_805D9638;
extern const f32 lbl_805D965C;
extern const f32 lbl_805D9660;
void TObjPlayer__sub_8008F1DC(void *arg0);
s32 TObjPlayer__sub_800A0554(void *);
void TObjPlayer__sub_8008EC3C(u8 *arg0);
void TObjEneBalClawBody::update_dragon_boss_state() {

    switch (this->state) {
    case 0:
        this->actorFlags = (s32) (this->actorFlags | 0x40000);
        this->requested_action = (s16) ((((u32) this->m_388 >> 0x18U) & 1) ? 0 : 5);
        this->state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), (f32)lbl_805D9620);
        return;
    case -1:
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
        return;
    }
}

void TObjPlayer__sub_8008EC3C(u8 *enemy) {
    s32 temp_r4_2;
    s32 temp_r5;
    switch (*(s32 *)((s8 *)enemy + 0x37C)) {
    case 0:
        *(s32 *)((s8 *)enemy + 0x388) = (*(s32 *)((s8 *)enemy + 0x388) | 4);
        *(s32 *)((s8 *)enemy + 0x30) = (s32) (*(s32 *)((s8 *)enemy + 0x30) | 0x04000000);
        *(s16 *)((s8 *)enemy + 0xB8) = (*(s32 *)((s8 *)enemy + 0x388) & 0x01000000) ? 0 : 5;
        ((TBoss3Volopt *)(enemy + 0x38))->play_area_se_with_particle();
        TObjPlayer__sub_800A0554(enemy + 0x390);
        *(s32 *)((s8 *)enemy + 0x37C) = 1;
    case 1:
        ((TObjMotion *)enemy)->advance_animation();
        apply_actor_gravity((TObjEnemy *)enemy, (s32 *)(0), lbl_805D9620);
        if (((En0VObj*)(enemy + 0x390))->m5() == 1) {
            temp_r5 = *(s32 *)((s8 *)enemy + 0x388);
            temp_r4_2 = temp_r5 & ~5;
            *(s32 *)((s8 *)enemy + 0x388) = temp_r4_2;
            *(s32 *)((s8 *)enemy + 0x37C) = -1;
            ((s32 (*)(void *, s32, s32))reset_enemy_state__10TObjPlayerFv)(enemy, temp_r4_2, temp_r5);
        }
        return;
    case -1:
        *(s32 *)((s8 *)enemy + 0x388) = (s32) (*(s32 *)((s8 *)enemy + 0x388) & ~5);
        *(s32 *)((s8 *)enemy + 0x30) = (s32) (*(s32 *)((s8 *)enemy + 0x30) & 0xFBFFFFFF);
        break;
    }
}

void TObjPlayer::set_visibility_flags_by_count(void *arg0, s32 arg1) {
    s32 i;
    s32 j;
    u32 *e;
    for (i = 0; i < arg1; i++) {
        for (j = 0; (e = lbl_805006F8[i].p[j]) != NULL; j++) {
            *e &= ~8;
        }
    }
    for (; i < 4; i++) {
        for (j = 0; (e = lbl_805006F8[i].p[j]) != NULL; j++) {
            *e |= 8;
        }
    }
}

#define RESET(p) ((s32 (*)(void *))reset_enemy_state__10TObjPlayerFv)(p)
void TObjPlayer__sub_8008EDE8(P_8008EDE8 *arg0) {
    switch (arg0->state) {
    case 0:
        if (((TObjPlayer *)arg0)->get_flag_0x388_b24() == 0) {
            RESET(arg0);
            return;
        }
        ((TObjEnemyCustom *)arg0)->find_target_in_range(lbl_805D9644);
        if (arg0->f338 != 0xFFFF) {
            arg0->fB8 = 1;
            arg0->state = 1;
            if (select_enemy_destination(arg0, arg0->pos, 1) != 0) {
                copy_position_if_valid__10TObjPlayerFii(arg0, arg0->pos);
            }
        } else {
            RESET(arg0);
        }
        break;
    case 1:
        if (arg0->target == NULL) {
            reset_enemy_state__10TObjPlayerFv();
        } else {
            arg0->vel.y = lbl_805D9620;
            calc_velocity_toward_destination(arg0, arg0->pos, arg0->target->pos, lbl_805D9648);
            {
                Vec_8008F910 n1 = arg0->pos;
                n1.x += arg0->vel.x;
                n1.z += arg0->vel.z;
                if (check_path_obstructed(arg0, &n1) == 0) {
                    move_with_wall_slide((u8 *)arg0);
                }
            }
            ((TObjEnemy *)arg0)->turn_toward_direction((s32)arg0->f350->f8, (Vec *)&arg0->vel);
            arg0->f3C0 = xz_distance_squared(&arg0->pos, &arg0->target->pos);
            if (arg0->f3C0 <= ((AttackParams *)(arg0->f318))->get_attack_range() * ((AttackParams *)(arg0->f318))->get_attack_range()) {
                arg0->fB8 = 2;
                arg0->state = 2;
                play_sound_effect(0x4003B033, arg0->pos38, 0, 0);
            }
        }
        break;
    case 2:
        if (arg0->target == NULL) {
            reset_enemy_state__10TObjPlayerFv();
        } else {
            arg0->vel.y = lbl_805D9620;
            calc_velocity_toward_destination(arg0, arg0->pos, arg0->target->pos, lbl_805D9648);
            move_with_wall_slide((u8 *)arg0);
            {
                Vec_8008F910 n2 = arg0->pos;
                n2.x += arg0->vel.x;
                n2.z += arg0->vel.z;
                if (check_path_obstructed(arg0, &n2) == 0) {
                    move_with_wall_slide((u8 *)arg0);
                }
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805D964C) != 0) {
                if (arg0->target->m18(arg0, lbl_805D9650) != 0) {
                    if (random_ratio__9TObjCharaFv((s32)arg0) <= lbl_805D9654) {
                        Pair_8008EDE8 q = lbl_80439B54[0];
                        arg0->target->m21(arg0, &q, 0, -1, -1);
                    }
                    arg0->target->m20(arg0, lbl_805D9650);
                    arg0->target->m23(arg0, lbl_805D9658);
                }
                arg0->f3DA++;
            }
            if (arg0->fB4 != 4) {
                RESET(arg0);
            }
        }
        break;
    case -1:
        break;
    }
    ((TObjMotion *)arg0)->advance_animation();
    apply_actor_gravity((TObjEnemy *)((u8 *)arg0), (s32 *)(0), lbl_805D9620);
    ((TObjPlayer *)arg0)->update_collisions();
}

#pragma push
#pragma opt_common_subs off
#define RESET(p) ((s32 (*)(void *))reset_enemy_state__10TObjPlayerFv)(p)
#define o ((P_8008F1DC *)arg0)
void TObjPlayer__sub_8008F1DC(void *arg0) {
    switch (o->state) {
    case 0:
        if (((TObjPlayer *)o)->get_flag_0x388_b24() != 0) {
            RESET(o);
            return;
        }
        if (FLD(u16, 0x2D4) < 0x1000) {
            o->f338 = FLD(u16, 0x2D4);
            FLD(T_8008F1DC *, 0x2A8) = find_active_entity_by_id(o->f338);
            if (FLD(T_8008F1DC *, 0x2A8) != NULL && (FLD(T_8008F1DC *, 0x2A8)->flags30 & 0x04000800)) {
                o->f338 = 0xFFFF;
                FLD(T_8008F1DC *, 0x2A8) = NULL;
            }
        } else {
            ((TObjEnemyCustom *)o)->find_target_in_range(lbl_805D9644);
        }
        if (o->f338 != 0xFFFF) {
            o->f388 &= ~0x20000;
            FLD(s16, 0xB8) = 6;
            o->state = 1;
        } else {
            o->m56();
        }
        break;
    case 1:
        if (FLD(T_8008F1DC *, 0x2A8) == NULL) {
            reset_enemy_state__10TObjPlayerFv();
        } else {
            o->vel.y = lbl_805D9620;
            calc_velocity_toward_destination(o, o->pos, FLD(T_8008F1DC *, 0x2A8)->pos, lbl_805D9648);
            {
                Vec_8008F910 n1 = o->pos;
                n1.x += o->vel.x;
                n1.z += o->vel.z;
                if (check_path_obstructed(o, &n1) == 0) {
                    move_with_wall_slide((u8 *)o);
                }
            }
            ((TObjEnemy *)o)->turn_toward_direction((s32)o->f350->f8, (Vec *)&o->vel);
            o->f3C0 = xz_distance_squared(&o->pos, &FLD(T_8008F1DC *, 0x2A8)->pos);
            if (o->f3C0 <= ((AttackParams *)(o->f318))->get_attack_range() * ((AttackParams *)(o->f318))->get_attack_range()) {
                FLD(s16, 0xB8) = 7;
                o->state = 2;
                o->p3E4 = (u32)spawn_particle_effect_with_rotation(&o->pos, &o->f3F8, 0x12B, 2);
                ((TParticleCtrl *)(o->p3E4))->enable();
                o->p3E8 = (u32)spawn_particle_effect_with_rotation(&o->pos, &o->f3F8, 0x12C, 2);
                ((TParticleCtrl *)(o->p3E8))->enable();
            }
        }
        break;
    case 2:
        push_matrix_from(identity_matrix);
        post_translate_matrix(&o->pos);
        rotate_matrix_y(0, FLD(s32, 0x60));
        ((TObjEnemy *)o)->calc_joint_matrices(FLD(f32, 0xC0));
        pop_matrix();
        o->m63(8, o->f3EC);
        o->f3F8 = 0;
        o->f3FC = FLD(s32, 0x60) + 0x4000;
        o->f400 = -0x4000;
        if (FLD(f32, 0xC0) >= lbl_805D9638 && FLD(f32, 0xC0) < lbl_805D965C) {
            ((TParticleCtrl *)o->p3E4)->set_position(o->f3EC);
            ((TParticleCtrl *)(o->p3E4))->set_direction(&o->f3F8);
        } else {
            ((TParticleCtrl *)(o->p3E4))->enable();
        }
        if (FLD(f32, 0xC0) >= lbl_805D9660 && FLD(f32, 0xC0) < lbl_805D965C) {
            ((TParticleCtrl *)o->p3E8)->set_position(o->f3EC);
            ((TParticleCtrl *)(o->p3E8))->set_direction(&o->f3F8);
        } else {
            ((TParticleCtrl *)(o->p3E8))->enable();
        }
        o->vel.y = lbl_805D9620;
        calc_velocity_toward_destination(o, o->pos, FLD(T_8008F1DC *, 0x2A8)->pos, lbl_805D9648);
        {
            Vec_8008F910 n2 = o->pos;
            n2.x += o->vel.x;
            n2.z += o->vel.z;
            if (check_path_obstructed(o, &n2) == 0) {
                move_with_wall_slide((u8 *)o);
            }
        }
        ((TObjEnemy *)o)->turn_toward_direction((s32)o->f350->f8, (Vec *)&o->vel);
        if (((TObjMotion *)o)->is_passing_frame((f32)lbl_805D964C) != 0) {
            play_sound_effect(0x4003B034, (u8 *)o + 0x38, 0, 0);
            if (FLD(T_8008F1DC *, 0x2A8)->m18(o, lbl_805D9650) != 0) {
                FLD(T_8008F1DC *, 0x2A8)->m20(o, lbl_805D9650);
                FLD(T_8008F1DC *, 0x2A8)->m23(o, lbl_805D9658);
                if (!(FLD(T_8008F1DC *, 0x2A8)->flags30 & 0x800) && get_actor_hp() > 0) {
                    send_6x2F_change_player_hp(FLD(u16, 0x1C), o->f338, 1);
                }
            }
        }
        if (FLD(u32, 0xB4) != 4) {
            obj_setFlags30(o, 0x800);
        }
        break;
    case -1:
        if (o->p3E4 != 0) {
            queue_destruction__7TObjectFv((void *)o->p3E4);
            o->p3E4 = 0;
        }
        if (o->p3E8 != 0) {
            queue_destruction__7TObjectFv((void *)o->p3E8);
            o->p3E8 = 0;
        }
        o->f388 |= 0x20000;
        break;
    }
    ((TObjMotion *)o)->advance_animation();
    apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), lbl_805D9620);
    ((TObjPlayer *)o)->check_object_collisions();
    check_enemy_body_collisions(o);
}
#undef o
#pragma pop

void TObjPlayer::run_death_sequence() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    u8 *p;
    switch (this->m_37c) {
    case 0:
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        *(s32 *)((s8 *)arg0 + 0x388) &= ~0x20000;
        if (((TObjPlayer *)arg0)->get_flag_0x388_b24() != 0) {
            this->requested_action = 4;
            this->m_37c = 1;
            for (i = 0; i < ((P_8008F730 *)arg0)->n; i++) {
                p = (u8 *)find_entity_by_id(((P_8008F730 *)arg0)->ids[i]);
                if (p != NULL) {
                    ((TObjEnemy *)p)->send_entity_set_flags();
                    queue_destruction__7TObjectFv(p);
                }
            }
        } else {
            this->requested_action = 9;
            *(f32 *)((s8 *)arg0 + 0x30C) = *(f32 *)((s8 *)arg0 + 0x3B4) / lbl_805D9664;
            this->m_37c = 2;
        }
        play_sound_effect(0x4003AD37, (u8 *)&this->position, 0, 0);
        break;
    case 1:
        ((TObjMotion *)arg0)->advance_animation();
        if (this->frame >= lbl_805D9668) {
            this->m_37c = 3;
        }
        break;
    case 2:
        ((TObjMotion *)arg0)->advance_animation();
        if (this->frame >= lbl_805D964C) {
            *(f32 *)((s8 *)arg0 + 0x3B4) -= *(f32 *)((s8 *)arg0 + 0x30C);
            if (*(f32 *)((s8 *)arg0 + 0x3B4) <= 0.0f) {
                *(f32 *)((s8 *)arg0 + 0x3B4) = 0.0f;
                this->m_37c = 3;
            }
        }
        break;
    case 3:
        TObjPlayer__sub_800A04F0((u8 *)&this->unk_390);
        fn_800D911C((Vec *)(arg0 + 0x2FC));
        *(s32 *)((s8 *)arg0 + 0x388) |= 4;
        this->m_37c = 4;
    case 4:
        ((TObjMotion *)arg0)->advance_animation();
        if (((VObj_14_c1c33b *)(arg0 + 0x390))->m4() == 1) {
            TObjPlayer::apply_effect_variant_a((s32)(arg0 + 0x38), 0);
            ((TObjEnemy *)arg0)->send_entity_set_flags();
            queue_destruction__7TObjectFv(arg0);
        }
        break;
    }
}

void TObjPlayer__sub_8008F910(u8 *arg0) {
    s32 var_r30;
    s32 var_r3;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case -1:
        break;
    case 0:
        *(s32 *)((s8 *)arg0 + 0x30) &= ~0x200000;
        *(s16 *)((s8 *)arg0 + 0xB8) = ((TObjPlayer *)arg0)->get_flag_0x388_b24() != 0 ? 3 : 8;
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
    case 1: {
        ((TObjMotion *)arg0)->advance_animation();
        *(f32 *)((s8 *)arg0 + 0x30C) = lbl_805D9620;
        Vec_8008F910 v = *(Vec_8008F910 *)((s8 *)arg0 + 0x2FC);
        v.x += *(f32 *)((s8 *)arg0 + 0x308);
        v.z += *(f32 *)((s8 *)arg0 + 0x310);
        if (check_path_obstructed(arg0, &v) == 0) {
            move_with_wall_slide(arg0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x308) = *(f32 *)((s8 *)arg0 + 0x310) = lbl_805D9620;
        }
        *(f32 *)((s8 *)arg0 + 0x308) *= lbl_805D966C;
        *(f32 *)((s8 *)arg0 + 0x310) *= lbl_805D966C;
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9620);
        ((TObjPlayer *)arg0)->update_collisions();
        if (*(u32 *)((s8 *)arg0 + 0xB4) != 8U) {
            var_r30 = 0;
            *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
            *(s32 *)((s8 *)arg0 + 0x30) &= ~0x200;
            *(s32 *)((s8 *)arg0 + 0x388) &= ~1;
            if (((TObjPlayer *)arg0)->get_flag_0x388_b24() == 0) {
                var_r3 = fn_80090464(arg0, 0);
                if (var_r3 <= 0) {
                    var_r3 = 0xA;
                }
                if (*(s16 *)((s8 *)arg0 + 0x32C) <= (*(s16 *)((s8 *)arg0 + 0x2B8) * var_r3) / 100) {
                    if (!(*(s32 *)((s8 *)arg0 + 0x388) & 0x02000000)) {
                        *(u16 *)((s8 *)arg0 + 0x338) = *(u16 *)((s8 *)arg0 + 0x2D4);
                        *(s32 *)((s8 *)arg0 + 0x388) |= 0x02000000;
                    }
                    var_r30 = 2;
                }
            }
            ((TObjEneMe1GiGue *)arg0)->update_if_active(var_r30);
        }
        break;
    }
    }
}
void TObjPlayer__sub_8008FAD0(u8 *arg0) {
    s16 v;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x30) &= 0xFBFFFEFF;
        ((TObjEnemyCustom *)arg0)->sub_8004292C();
        v = 6;
        if (*(s32 *)((s8 *)arg0 + 0x388) & 0x01000000) {
            v = 1;
        }
        *(s16 *)((s8 *)arg0 + 0xB8) = v;
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
        }
        break;
    case 1:
        if (*(void **)((s8 *)arg0 + 0x2A8) == NULL) {
            reset_enemy_state__10TObjPlayerFv();
            break;
        }
        play_persistent_sound(0x4003B235, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
        *(f32 *)((s8 *)arg0 + 0x30C) = lbl_805D9620;
        {
            Vec_8008FAD0 pos = *(Vec_8008FAD0 *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC);
            update_enemy_wander_move(arg0, &pos, 1, *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4));
        }
        ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((u8 *)((TObjEnemy *)arg0)->movementParameters + 8), (Vec *)((u8 *)arg0 + 0x308));
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9620);
        ((TObjPlayer *)arg0)->update_collisions();
        break;
    case -1:
        break;
    }
}
}
