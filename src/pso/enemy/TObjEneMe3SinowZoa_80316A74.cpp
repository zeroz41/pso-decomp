#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/TObjEneMe3SinowZoa_80316A74.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe1Gee.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/misc/TTecGiBarta.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct VBase_14_c5778e { char pad[0x14]; };

struct VObj_14_c5778e : VBase_14_c5778e {
    virtual void m0();
    virtual s32 m1(s32);
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct VBase_14_0b0741 { char pad[0x14]; };

struct VObj_14_0b0741 : VBase_14_0b0741 {
    virtual void m0();
    virtual s32 m1(s32);
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

struct VBase_18_803173D0 { char pad[0x18]; };

struct VObj_18_803173D0 : VBase_18_803173D0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Part_803173D0 { s32 a; s32 b; s32 c; };

struct Mdl_803173D0 { Part_803173D0 *parts; };

struct Motion_803173D0 { s32 f0; u32 nframes; };

struct MotEnt_803173D0 { s32 f0; Motion_803173D0 *motion; };

struct Anim_803173D0 { s32 f0; s32 idx; s32 f8; s32 fC; };

struct Obj_803173D0 : VObj_18_803173D0 {
    u8 pad1C[0x24 - 0x1C]; Mdl_803173D0 *mdl; u8 pad28[0x34 - 0x28]; s32 f34;
    u8 pos[0xC]; u8 pad44[0x60 - 0x44]; s32 rotY; u8 pad64[0xB8 - 0x64]; s16 fb8;
    u8 padBA[0xC0 - 0xBA]; f32 fc0; u8 padC4[0xD8 - 0xC4]; Anim_803173D0 *anims;
    MotEnt_803173D0 *motions; u8 padE0[0xF8 - 0xE0]; Motion_803173D0 *fF8;
    u8 padFC[0x326 - 0xFC]; s16 f326; u8 pad328[0x360 - 0x328]; f32 f360;
};

struct Vec_80316C3C { f32 x, y, z; };

struct VSub_80316C3C_B { u8 pad[0x14]; };

struct VSub_80316C3C : VSub_80316C3C_B {
    virtual void m0();
    virtual void m1(s32);
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct VBase_80316C3C { u8 pad[0x18]; };

struct VObj_80316C3C : VBase_80316C3C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual s32 m94();
};

struct Move_80316C3C { s32 f0; f32 speed; s32 turn; };

struct Stat_80316C3C { u8 pad[0xC]; s32 range; };

struct Def_80316C3C { u8 pad[0x24]; s32 frame; };

struct Obj_80316C3C : VObj_80316C3C {
    u8 pad1C[0x38 - 0x1C];
    Vec_80316C3C pos;
    u8 pad44[0x60 - 0x44];
    s32 rotY;
    u8 pad64[0xB8 - 0x64];
    s16 fb8;
    u8 padBA[0x2FC - 0xBA];
    Vec_80316C3C cur;
    u8 pad308[0x318 - 0x308];
    Stat_80316C3C *stat;
    u8 pad31C[0x350 - 0x31C];
    Move_80316C3C *move;
    u8 pad354[0x390 - 0x354];
    u32 hasDest;
    Vec_80316C3C dest;
    u8 pad3A0[0x3C0 - 0x3A0];
    s32 f3c0;
    u8 pad3C4[0x3C8 - 0x3C4];
    s32 kind;
    u32 flags;
    u8 pad3D0[0x414 - 0x3D0];
    VSub_80316C3C sub;
    u8 pad42C[0x434 - 0x42C];
    s32 state;
    s32 timer;
};

struct Pair_80316A74 { s32 a; s32 b; };

struct Vec_80316B20 { f32 x, y, z; };

extern "C" {
s32 play_sound_effect(s32, u32, s16, s32);
s32 pack_debug_text_position(s32, s32);
s32 sub_8031A454__18TObjEneMe3SinowZoaFv(void *);
s32 is_outside_visible_range__18TObjEneMe3SinowZoaFv(void *);
void debug_printf_at(s32 id, const char *fmt, ...);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern char lbl_80475FD4[];
extern char lbl_80475FE4[];
extern char lbl_80475FF4[];
extern char lbl_80476004[];
extern char lbl_80476010[];
extern char lbl_80476028[];
extern char lbl_80476040[];
extern char lbl_80476058[];
extern char lbl_80476070[];
extern char lbl_80476084[];
extern u32 *lbl_80542FF0[];
extern s32 model_render_flags;
extern const f32 TObjEneMe3SinowZoa__data_805DF2F0;
extern const f32 TObjEneMe3SinowZoa__data_805DF2F4;
extern const f32 lbl_805DF318;
extern const f32 TObjEneMe3SinowZoa__data_805DF31C;
s32 select_enemy_destination(void *, Vec_80316C3C, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, Vec_80316C3C);
s32 enemy_turn_toward_dest(void *, s32);
void enemy_set_heading_velocity(void *, s32, f32);
}
void print_float_padded(s32 arg0, s32 prec, f32 val);
void move_with_wall_slide(u8 *arg0);
extern "C" {
void subtract_vector(void *, void *);
s32 push_matrix_from(void *);
s32 matrix_mult_vec(int, Vec_80316C3C, void *);
void create__11TTecRaBartaFPvPvPvPv(void *, void *, void *, s32);
extern Vec_80316C3C lbl_80475FC8[];
extern Def_80316C3C *TObjEneMe3SinowZoa__kind_param_tbls[];
extern u8 identity_matrix[];
extern s32 game_difficulty_selection;
extern const f32 TObjEneMe3SinowZoa__data_805DF308;
extern const f32 TObjEneMe3SinowZoa__data_805DF30C;
extern const f32 TObjEneMe3SinowZoa__data_805DF310;
extern const f32 TObjEneMe3SinowZoa__data_805DF314;
void TObjEneMe3SinowZoa__sub_80316C3C(Obj_80316C3C *arg0, s32 arg1);
f32 random_ratio__9TObjCharaFv(void *);
f32 receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void *, int, int);
f32 receive_damage_and_transition__18TObjEneMe3SinowZoaFPviii(u8 *arg0, s32 arg1, Pair_80316A74 arg2, s32 arg3);
u16 get_entity_id(int);
u32 get_valid_target_player__10TNpcPlayerFv(int);
extern u8 sinow_zoa_collision_parts[];

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 approach_80316C3C(Obj_80316C3C *arg0) {
    copy_position_if_valid__10TObjPlayerFii(arg0, arg0->cur);
    arg0->cur.y += TObjEneMe3SinowZoa__data_805DF308;
    return enemy_turn_toward_dest(arg0, arg0->move->turn);
}
inline s32 seek_80316C3C(Obj_80316C3C *arg0, Vec_80316C3C *diff) {
    s32 angle;
    if (select_enemy_destination(arg0, arg0->dest, 1) != 0) {
        angle = approach_80316C3C(arg0);
        enemy_set_heading_velocity(arg0, arg0->rotY, arg0->move->speed);
        move_with_wall_slide((u8 *)arg0);
    } else {
        VecCopy((Vec *)diff, (const Vec *)&arg0->dest);
        subtract_vector(diff, &arg0->cur);
        angle = ((TObjEnemy *)arg0)->turn_toward_direction(arg0->move->turn, (Vec *)diff);
    }
    return angle;
}

f32 receive_damage_and_transition__18TObjEneMe3SinowZoaFPviii(u8 *actor, s32 arg1, Pair_80316A74 arg2, s32 arg3) {
    f32 temp_f31;
    temp_f31 = ((f32 (*)(void *, s32, Pair_80316A74, s32, s32, s32))receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll)(actor, arg1, arg2, arg3, -1, -1);
    if (*(s32 *)((s8 *)actor + 0x3C0) == 1 && random_ratio__9TObjCharaFv(actor) <= *(f32 *)((s8 *)actor + 0x3F0)) {
        ((TObjEneDD *)actor)->transition_enemy_state(0x12);
    } else if (*(s16 *)((s8 *)actor + 0x326) == 2) {
        ((TObjEneDD *)actor)->transition_enemy_state(6);
    }
    return temp_f31;
}

u32 check_move_collision__18TObjEneMe3SinowZoaFPvPv(u8 *arg0, void *arg1) {
    u8 *o;
    u32 r;
    u32 saved;
    Vec_80316B20 sp8;
    u8 pad[12];
    o = *(u8 **)((s8 *)arg0 + 0xA4);
    saved = *(u32 *)((s8 *)o + 0x18);
    *(u32 *)((s8 *)o + 0x18) = 0x9D01U;
    VecCopy((Vec *)&sp8, (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)arg1);
    TObjPlayer::init_all_slots();
    ((TObjEneMe3SinowZoa *)arg0)->vfunc_89();
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    if (*(u32 *)((s8 *)o + 0x18) & 0x80000) {
        if (get_valid_target_player__10TNpcPlayerFv(get_entity_id(*(s32 *)((s8 *)arg0 + 0x390))) == 0) {
            VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&sp8);
            TObjPlayer::init_all_slots();
            return 1;
        }
    }
    if ((*(u32 *)((s8 *)o + 0x18) & 0x100000) && get_valid_target_player__10TNpcPlayerFv(*(u16 *)((s8 *)arg0 + 0x1C)) == 0) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&sp8);
        TObjPlayer::init_all_slots();
        return 1;
    }
    r = (*(u32 *)((s8 *)o + 0x18) & 0x200000) != 0;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&sp8);
    TObjPlayer::init_all_slots();
    copy_collision_body((CollisionBody *)o, (const CollisionBody *)sinow_zoa_collision_parts);
    *(u32 *)((s8 *)o + 0x18) = saved;
    return r;
}

void TObjEneMe3SinowZoa__sub_80316C3C(Obj_80316C3C *arg0, s32 arg1) {
    s32 angle;
    Vec_80316C3C diff;
    Vec_80316C3C out;
    switch (arg1) {
    case 5:
        break;
    case 4:
        arg0->fb8 = 0xA;
        ((TObjEneDD *)arg0)->set_field_378(6);
        arg0->m94();
        arg0->flags &= 0xFFEFFFF8;
        arg0->flags |= 0x10000;
        ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        arg0->state = 0;
        break;
    case 3:
        if (arg0->state == 5) {
            ((TObjEneDD *)arg0)->transition_enemy_state(6);
        }
        break;
    case 0:
        switch (arg0->state) {
        case 0:
        default:
            if (arg0->hasDest == 0) {
                ((TObjEneDD *)arg0)->transition_enemy_state(6);
                break;
            }
            angle = seek_80316C3C(arg0, &diff);
            if (angle < 0x100) {
                if (arg0->f3c0 != 0) {
                    ((TObjEneMe3SinowZoa *)(&arg0->sub))->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
                    arg0->sub.m3();
                    arg0->flags |= 0x100000;
                    arg0->flags |= 0x40000;
                    ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x08000000);
                    arg0->state = 1;
                } else {
                    arg0->state = 2;
                }
                arg0->fb8 = 8;
            } else {
                arg0->fb8 = 0xA;
            }
            break;
        case 1:
            ((TObjMotion *)arg0)->advance_animation();
            if (((TObjEneMe3SinowZoa *)(&arg0->sub))->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                arg0->state = 2;
            }
        case 2:
            ((TObjMotion *)arg0)->advance_animation();
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                arg0->timer = 0;
                arg0->state = 3;
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)TObjEneMe3SinowZoa__data_805DF314) != 0) {
                ((TObjMotion *)arg0)->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix(&arg0->pos);
                rotate_matrix_y(0, arg0->rotY);
                set_motion_packed_rotation();
                ((TObjEnemy *)arg0)->calc_joint_matrices(TObjEneMe3SinowZoa__data_805DF314);
                clear_motion_packed_rotation();
                pop_matrix();
                push_matrix_from(anim_model_matrix_array[3]);
                matrix_mult_vec(0, lbl_80475FC8[0], &out);
                pop_matrix();
                if (arg0->hasDest != 0) {
                    VecCopy((Vec *)&diff, (const Vec *)&arg0->dest);
                    subtract_vector(&diff, &arg0->cur);
                    angle = ((TObjEnemy *)arg0)->turn_toward_direction(arg0->move->turn, (Vec *)&diff);
                } else {
                    angle = arg0->stat->range;
                }
                if (angle < arg0->stat->range / 2 && arg0->hasDest != 0) {
                    if (game_difficulty_selection == 3) {
                        create__11TTecRaBartaFPvPvPvPv(arg0, &out, &arg0->pos,
                            TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[arg0->kind]->frame));
                    } else {
                        ((TTecGiBarta *)arg0)->create_ex(&out, (void *)arg0->rotY, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[arg0->kind]->frame)));
                    }
                } else if (arg0->flags & 0x100000) {
                    arg0->state = 4;
                } else {
                    arg0->state = 5;
                }
            }
            break;
        case 3:
            if (++arg0->timer >= 0x28) {
                if (arg0->flags & 0x100000) {
                    arg0->state = 4;
                } else {
                    arg0->state = 5;
                }
            }
            break;
        case 4:
            if (arg0->sub.m4() != 0) {
                arg0->state = 5;
                arg0->flags |= 0x40000;
                ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
}
#pragma pop

void TObjEneMe3SinowZoa__sub_803170F0(u8 *ene_dd, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd + 0xB8) = 0xB;
        ((TObjEneDD *)ene_dd)->set_field_378(6);
        ((TObjEneDD *)(ene_dd))->vfunc_96();
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) & 0xFFEFFFFD);
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) | 5);
        ((VObj_14_0b0741 *)(ene_dd + (1044)))->m1(0x1E);
        *(s32 *)((s8 *)ene_dd + 0x3C0) = 0;
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) | 0x40000);
        ((TObjCollidable *)ene_dd)->clear_player_status_flag(0, 0x08000000U);
        *(s32 *)((s8 *)ene_dd + 0x434) = 0;
        break;
    case 3:
        if (((s32) *(s32 *)((s8 *)ene_dd + 0x434) == 1) && (((VObj_14_0b0741 *)(ene_dd + (1044)))->m5() != 0)) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(6);
            *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) & ~5);
            break;
        }
    case 5:
        break;
    case 0:
        ((TObjMotion *)ene_dd)->advance_animation();
        if (((TObjEneDD *)ene_dd)->get_flag_b4() != 0) {
            *(s32 *)((s8 *)ene_dd + 0x434) = 1;
        }
        ((TObjEneDD *)(ene_dd))->vfunc_102();
        ((TObjEneDD *)(ene_dd))->vfunc_89();
        break;
    }
}

void TObjEneMe3SinowZoa__sub_80317254(u8 *ene_dd, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd + 0xB8) = 0xC;
        ((TObjEneDD *)ene_dd)->set_field_378(6);
        ((TObjEneDD *)(ene_dd))->vfunc_96();
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) & 0xFFEFFFFD);
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) | 5);
        ((VObj_14_c5778e *)(ene_dd + (1044)))->m1(0x1E);
        play_sound_effect(0x4003AD2F, (u32)(ene_dd + 0x38), 0, 0);
        *(s32 *)((s8 *)ene_dd + 0x434) = 0;
        break;
    case 3:
        if (((s32) *(s32 *)((s8 *)ene_dd + 0x434) == 1) && (((VObj_14_c5778e *)(ene_dd + (1044)))->m4() != 0)) {
            *(s32 *)((s8 *)ene_dd + 0x3C0) = 1;
            ((TObjEneDD *)ene_dd)->transition_enemy_state(6);
            *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) & ~5);
            *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) | 0x40000);
            ((TObjCollidable *)ene_dd)->set_indexed_flags(0, 0x08000000);
            break;
        }
    case 5:
        break;
    case 0:
        ((TObjMotion *)ene_dd)->advance_animation();
        if (((TObjEneDD *)ene_dd)->get_flag_b4() != 0) {
            *(s32 *)((s8 *)ene_dd + 0x434) = 1;
        }
        ((TObjEneDD *)(ene_dd))->vfunc_102();
        ((TObjEneDD *)(ene_dd))->vfunc_89();
        break;
    }
}
void TObjEneMe3SinowZoa::vfunc_115() {
    Obj_803173D0 *arg0 = (Obj_803173D0 *)this;
    s32 save[3];
    s32 flag;
    Motion_803173D0 *motion;
    f32 frame;
    if (((TObjEneDD *)arg0)->get_target_info() != 0) {
        if (((TObjEneMe3SinowZoa *)arg0)->sub_8031A4D0() != 0) {
            debug_printf_at(pack_debug_text_position(0, 2), lbl_80475FD4);
        } else {
            debug_printf_at(pack_debug_text_position(0, 2), lbl_80475FE4);
        }
        if (is_outside_visible_range__18TObjEneMe3SinowZoaFv(arg0) != 0) {
            debug_printf_at(pack_debug_text_position(0xF, 2), lbl_80475FF4);
        } else {
            debug_printf_at(pack_debug_text_position(0xF, 2), lbl_80476004);
        }
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 4), lbl_80476010);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 3), lbl_80476028);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 6), lbl_80476040);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 5), lbl_80476058);
        if (sub_8031A454__18TObjEneMe3SinowZoaFv(arg0) != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), lbl_80476070);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), lbl_80476084);
        }
    }
    flag = sub_8031A454__18TObjEneMe3SinowZoaFv(arg0);
    if (arg0->m8(lbl_805DF318, TObjEneMe3SinowZoa__data_805DF2F0) != 0) {
        TObjFish::set_global_param((s32)arg0->mdl);
        TObjPlayer::toggle_particle_effect();
        if (flag != 0) {
            Part_803173D0 *parts = arg0->mdl->parts;
            s32 i;
            for (i = 0; i < 3; i++) {
                save[i] = parts[i].c;
            }
            for (i = 0; i < 3; i++) {
                parts[i].c = parts[i + 3].c;
            }
        }
        push_matrix();
        post_translate_matrix(arg0->pos);
        rotate_matrix_y(0, arg0->rotY);
        scale_matrix(0, TObjEneMe3SinowZoa__data_805DF2F4, TObjEneMe3SinowZoa__data_805DF2F4, TObjEneMe3SinowZoa__data_805DF2F4);
        {
            s32 i;
            for (i = 0; i < 3; i++) {
                if (lbl_80542FF0[i] != NULL) {
                    *lbl_80542FF0[i] = 0xB000FFB0;
                }
            }
        }
        if (arg0->f326 == 0) {
            s32 idx = arg0->fb8;
            if (idx < 0) {
                idx = 0;
            } else if (idx >= 0xD) {
                idx = 0xC;
            }
            motion = arg0->motions[arg0->anims[idx].idx].motion;
            frame = arg0->f360;
            if (frame < TObjEneMe3SinowZoa__data_805DF31C) {
                frame = TObjEneMe3SinowZoa__data_805DF31C;
            } else if (frame > (motion->nframes - 1)) {
                frame = (motion->nframes - 1);
            }
            set_motion_packed_rotation();
            draw_model_motion((void *)arg0->f34, motion, frame);
            clear_motion_packed_rotation();
            arg0->fF8 = motion;
            arg0->fc0 = frame;
            frame = ((TObjEneMe3SinowZoa *)arg0)->get_node_height();
            print_float_padded(pack_debug_text_position(0, 7), 5, frame);
        } else {
            model_render_flags &= ~0x400;
        }
        pop_matrix();
        if (flag != 0) {
            s32 i;
            Part_803173D0 *parts = arg0->mdl->parts;
            for (i = 0; i < 3; i++) {
                parts[i].c = save[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}
}
