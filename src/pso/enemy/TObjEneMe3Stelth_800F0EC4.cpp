#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/misc/TTecGiFoie.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/player/TObjPlayer.h"

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

struct VBase14_800F1440 { char pad[0x14]; };

struct VSub_800F1440 : VBase14_800F1440 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual s32 s4();
};

struct Quad_800F1440 { s32 a, b, c, d; };

struct Vec_800F1098 { f32 x, y, z; };

struct IVec_800F1098 { s32 a, b, c; };

struct Spd_800F1098 { s32 a; f32 speed; s32 turn; };

struct Tbl_800F1098 { u8 pad[0x24]; s32 lvl; };

struct Obj_800F0EC4 { u8 pad0[0x326]; s16 f326; u8 pad328[0x3C0 - 0x328]; s32 f3C0; u8 pad3C4[0x3E0 - 0x3C4]; f32 f3E0; };

struct Pair_800F0EC4 { s32 a; s32 b; };

struct VBase_18_800F0F84 { char pad[0x18]; };

struct VObj_18_800F0F84 : VBase_18_800F0F84 {
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
};

struct Vec_800F0F84 { f32 x, y, z; };

struct Ent_800F0F84 { u8 pad0[0x18]; u32 f18; };

extern "C" {
s32 is_split_screen();
s32 play_sound_effect(int, void *, int, int);
extern const Quad_800F1440 me3_stelth_offset_vec;
extern const f32 lbl_805DA828;
extern const f32 lbl_805DA82C;
void TObjEneMe3Stelth__sub_800F1440(u8 *arg0, s32 arg1);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
s32 select_enemy_destination(void *, Vec_800F1098 *, int);
s32 copy_position_if_valid__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 enemy_turn_toward_dest(void *, s32);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, int);
void subtract_vector(void *, void *);
s32 push_matrix_from(void *);
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern IVec_800F1098 lbl_8043D680;
extern Tbl_800F1098 *TObjEneMe3Stelth__behavior_params_by_variant[];
extern u8 identity_matrix[];
extern s32 game_difficulty_selection;
extern const f32 TObjEneMe3Stelth__data_805DA820;
extern const f32 TObjEneMe3Stelth__data_805DA824;
void TObjEneMe3Stelth__sub_800F1098(u8 *arg0, s32 arg1);
f32 random_ratio__9TObjCharaFv(s32 arg0);
s32 receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void *, void *, void *, void *, s32, s32);
u16 get_entity_id(void *);
void handle_direct_attack__16TObjEneMe3StelthFPvPviPv(Obj_800F0EC4 *arg0, void *arg1, Pair_800F0EC4 arg2, void *arg3);
u32 get_valid_target_player__10TNpcPlayerFv(int);
extern u8 TObjEneMe3Stelth__collision_body_template[];
s32 TObjEneMe3Stelth__sub_800F0F84(u8 *arg0, Vec_800F0F84 *arg1);
#define F(T, o) (*(T *)(arg0 + (o)))
#define VO ((VObj_18 *)(arg0))

#define F(T, o) (*(T *)(arg0 + (o)))

void handle_direct_attack__16TObjEneMe3StelthFPvPviPv(Obj_800F0EC4 *actor, void *arg1, Pair_800F0EC4 arg2, void *arg3) {
    if (actor->f3C0 == 1 && get_entity_id(arg1) < 0x1000 && random_ratio__9TObjCharaFv((s32)actor) <= actor->f3E0) {
        ((TObjEneDD *)actor)->transition_enemy_state(0x12);
    } else if (actor->f326 == 2) {
        ((TObjEneDD *)actor)->transition_enemy_state(6);
    }
    ((s32 (*)(void *, void *, Pair_800F0EC4, void *, s32, s32))receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll)(actor, arg1, arg2, arg3, -1, -1);
}

s32 TObjEneMe3Stelth__sub_800F0F84(u8 *arg0, Vec_800F0F84 *arg1) {
    Ent_800F0F84 *ent;
    s32 result;
    u32 saved;
    Vec_800F0F84 sp;
    u8 unused[12];
    ent = *(Ent_800F0F84 **)(arg0 + 0xA4);
    saved = ent->f18;
    ent->f18 = 0x9D01;
    VecCopy((Vec *)&sp, (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)arg1);
    TObjPlayer::init_all_slots();
    ((VObj_18_800F0F84 *)arg0)->m87();
    if ((ent->f18 & 0x80000) && get_valid_target_player__10TNpcPlayerFv(get_entity_id((void *)(*(s32 *)((s8 *)arg0 + 0x390)))) == 0) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&sp);
        TObjPlayer::init_all_slots();
        return 1;
    }
    if ((ent->f18 & 0x100000) && get_valid_target_player__10TNpcPlayerFv(*(u16 *)((s8 *)arg0 + 0x1C)) == 0) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&sp);
        TObjPlayer::init_all_slots();
        return 1;
    }
    result = (ent->f18 & 0x200000) != 0;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&sp);
    TObjPlayer::init_all_slots();
    copy_collision_body((CollisionBody *)ent, (const CollisionBody *)TObjEneMe3Stelth__collision_body_template);
    ent->f18 = saved;
    return result;
}

void TObjEneMe3Stelth__sub_800F1098(u8 *arg0, s32 arg1) {
    Vec_800F1098 d;
    Vec_800F1098 out;
    IVec_800F1098 c;
    s32 r;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0xA;
        ((TObjEneDD *)arg0)->set_field_378(6);
        ((TObjEneDD *)(arg0))->vfunc_96();
        F(s32, 0x3CC) &= 0xFFFFFFF8;
        F(s32, 0x3CC) |= 0x10000;
        ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        F(s32, 0x424) = 0;
        break;
    case 3:
        if (F(s32, 0x424) == 3) {
            ((TObjEneDD *)arg0)->transition_enemy_state(6);
        }
        break;
    case 0:
        ((TObjEnemy *)arg0)->update_prev_position();
        switch (F(s32, 0x424)) {
        case 0:
        default:
            if (F(u32, 0x390) == 0) {
                ((TObjEneDD *)arg0)->transition_enemy_state(6);
                break;
            }
            {
                Vec_800F1098 dest = F(Vec_800F1098, 0x394);
                if (select_enemy_destination(arg0, &dest, 1) != 0) {
                    Vec_800F1098 pos = F(Vec_800F1098, 0x2FC);
                    copy_position_if_valid__10TObjPlayerFii((s32)arg0, (s32)&pos);
                    F(f32, 0x300) += TObjEneMe3Stelth__data_805DA820;
                    r = enemy_turn_toward_dest(arg0, F(Spd_800F1098 *, 0x350)->turn);
                    enemy_set_heading_velocity(F(Spd_800F1098 *, 0x350)->speed, (TObjEnemy *)arg0, F(s32, 0x60));
                    move_with_wall_slide(arg0);
                } else {
                    VecCopy((Vec *)&d, (const Vec *)(arg0 + 0x394));
                    subtract_vector(&d, arg0 + 0x2FC);
                    r = ((TObjEnemy *)arg0)->turn_toward_direction(F(Spd_800F1098 *, 0x350)->turn, (Vec *)&d);
                }
            }
            if (r < 0x100) {
                F(s32, 0x424) = 1;
                F(s16, 0xB8) = 8;
            } else {
                F(s16, 0xB8) = 0xA;
            }
            break;
        case 1:
            ((TObjMotion *)arg0)->advance_animation();
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s32, 0x428) = 0;
                F(s32, 0x424) = 2;
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)TObjEneMe3Stelth__data_805DA824) != 0) {
                ((TObjMotion *)arg0)->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix(arg0 + 0x38);
                rotate_matrix_y(0, F(s32, 0x60));
                set_motion_packed_rotation();
                ((TObjEnemy *)arg0)->calc_joint_matrices(TObjEneMe3Stelth__data_805DA824);
                clear_motion_packed_rotation();
                pop_matrix();
                push_matrix_from(anim_model_matrix_array[3]);
                c.a = lbl_8043D680.a;
                c.b = lbl_8043D680.b;
                c.c = lbl_8043D680.c;
                matrix_mult_vec(0, &c, &out);
                pop_matrix();
                if (F(u32, 0x390) != 0) {
                    VecCopy((Vec *)&d, (const Vec *)(arg0 + 0x394));
                    subtract_vector(&d, arg0 + 0x2FC);
                    r = ((TObjEnemy *)arg0)->turn_toward_direction(F(Spd_800F1098 *, 0x350)->turn, (Vec *)&d);
                } else {
                    r = F(s32 *, 0x318)[3];
                }
                if (r < F(s32 *, 0x318)[3] / 2 && F(u32, 0x390) != 0) {
                    if (game_difficulty_selection == 3) {
                        ((TTecRaFoie *)arg0)->create(&out, arg0 + 0x394, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[F(s32, 0x3C8)]->lvl)));
                    } else {
                        TTecGiFoie::create((void *)arg0, &out, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[F(s32, 0x3C8)]->lvl)));
                    }
                } else {
                    F(s32, 0x424) = 3;
                }
            }
            break;
        case 2:
            if (++F(s32, 0x428) >= 0x3C) {
                F(s32, 0x424) = 3;
            }
            break;
        }
        break;
    case 5:
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
}

void TObjEneMe3Stelth__sub_800F1440(u8 *arg0, s32 arg1) {
    Quad_800F1440 q;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0xB;
        ((TObjEneDD *)arg0)->set_field_378(6);
        VO->m94();
        F(s32, 0x3CC) &= 0xFFFFFFF1;
        F(s32, 0x3CC) |= 1;
        F(s32, 0x3CC) |= 0x40000;
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x08000000);
        F(s32, 0x424) = 0;
        play_sound_effect(0x3B23B, arg0 + 0x38, 0, 0);
        break;
    case 3:
        if (F(s32, 0x424) == 3) {
            ((TObjEneDD *)arg0)->transition_enemy_state(6);
            F(s32, 0x3CC) &= ~1;
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            F(s32, 0x424) = 3;
        } else if (is_split_screen() != 0) {
            switch (F(s32, 0x424)) {
            case 0:
                if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DA828) != 0) {
                    F(s32, 0x3CC) |= 8;
                    q.a = me3_stelth_offset_vec.a;
                    q.b = me3_stelth_offset_vec.b;
                    q.c = me3_stelth_offset_vec.c;
                    q.d = me3_stelth_offset_vec.d;
                    ((TObjEneMe3SinowZoa *)(arg0 + 0x404))->copy_position_vector(&q);
                    F(s32, 0x424) = 1;
                }
                break;
            case 1:
                if (((VSub_800F1440 *)(arg0 + 0x404))->s4() != 0) {
                    F(s32, 0x3CC) &= ~8;
                    F(s32, 0x3C0) = 0;
                    F(s32, 0x424) = 2;
                }
                break;
            }
        } else if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DA828) != 0) {
            F(s32, 0x3CC) |= 8;
        } else if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DA82C) != 0) {
            F(s32, 0x3CC) &= ~8;
            F(s32, 0x3C0) = 0;
        }
        VO->m100();
        VO->m87();
        break;
    case 5:
        F(s32, 0x3CC) &= ~8;
        F(s32, 0x3C0) = 0;
        break;
    }
}
}
