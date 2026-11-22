#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/saver/SaverLifecycle.h"
#include "pso/effect/enemy/TEneParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/saver/TObjEneSaver.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();

#include "pso/system/vector.h"

#include "pso/render/TUnk_80490470.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/unk/TLobby.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/object/TObjControl.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/base/CollisionActorLookup.h"

struct Obj_800A6B14;


typedef struct Ent_800A715C { s32 a; void *b; } Ent_800A715C;

typedef struct Sub_800A715C { u8 pad[8]; void *f8; NJS_TEXLIST *texlist; } Sub_800A715C;

typedef struct Res_800A715C { u8 pad[0x42C]; Sub_800A715C *sub; Ent_800A715C *ents; } Res_800A715C;


struct E_800A7734 { u8 pad[8]; s32 x8; s32 xc; };

struct G_800A7734 { u8 pad[0x42c]; E_800A7734 *tbl; };

struct O_800A7734 { u8 pad[0x24]; s32 x24; u8 pad2[0xc]; s32 x34; };

extern "C" {
extern void *bm_ene_df1_saver_model_names[2];
extern void *bm_ene_df1_saver_motion_names[12];
}
// lbl_80500978: 16 bytes in the original; only its first 12 are used, as a point.
struct RecoveredGlobal_lbl_80500978 { Vec pos; u8 pad_c[4]; };
RecoveredGlobal_lbl_80500978 lbl_80500978;
extern "C" {
void *saver_boss_stat_handle;
void **player_object_ptr_array;
void *saver_object_stat_handle;
f32 *lbl_805D504C;
uaddr saver_bml_resource;
saddr lbl_805D5054;
s32 lbl_805D5058;
s32 lbl_805D505C;
saddr lbl_805D5060;
SampledMotionPoints *lbl_805D5064;
SampledMotionPoints *lbl_805D5068;
SampledMotionPoints *lbl_805D506C;
void initialize_saver_resources(void);
s32 free_collision_body_parts(void *);
void init_collision_body_parts(void *, void *, s32);
}
int initialize_enemy_photon_effect(void *p);

struct C_800A4294 { s32 x0; };

struct B_800A4294 { u8 pad[0xc]; C_800A4294 *c; };

struct A_800A4294 { u8 pad[0x8]; B_800A4294 *b; };

struct G_800A4294 { A_800A4294 *p; s32 n; u8 pad[0x8]; };

extern A_800A4294 lbl_804CC8C8;
extern G_800A4294 player_effect_task_list;
extern int TObjPlayer__effect_count;
extern "C" {
void TObjPlayer__sub_800A4294(void);
s32 TObjPlayer__sub_800A7774(void *, void *);
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 TObjPlayer__sub_800A04F0(void *);
struct VDisp_800a42c4_800A4288 { char pad[0x18]; virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(void *, void *); };

void TObjPlayer__sub_800A42C0(void);
s32 post_translate_matrix(void *);
void check_enemy_body_collisions(void *arg0);
s32 submit_cursor_candidate(void *, int);
s32 matrix_mult_vec_array(int, int, void *, int);
s32 minimap_render_dot(void *, int, int, int);

extern "C" {
__declspec(section ".data") void *bm_ene_df1_saver_model_names[2] = {
    (void *)"df1_s_kil_body.nj", (void *)0x0,
};
void *bm_ene_df1_saver_motion_names[12] = {
    (void *)"aseri_df1_s_kil_body.njm", (void *)"atack_df1_s_kil_body.njm", (void *)"damage_df1_s_kil_body.njm", (void *)"deadb_df1_s_kil_body.njm",
    (void *)"dead_df1_s_kil_body.njm", (void *)"defdam_df1_s_kil_body.njm", (void *)"defence_df1_s_kil_body.njm", (void *)"jump_df1_s_kil_body.njm",
    (void *)"nail_df1_s_kil_body.njm", (void *)"wait_df1_s_kil_body.njm", (void *)"walk_df1_s_kil_body.njm", (void *)0x0,
};
void *bm_ene_df1_saver_resource_descriptor[4] = {
    (void *)"bm_ene_df1_saver.bml", (void *)&bm_ene_df1_saver_model_names, (void *)&bm_ene_df1_saver_motion_names, (void *)0x1000b,
};
TObjMotionAction saver_action_table[11] = {
    {1, 0, 9, 1.0f, 1},
    {1, 0, 10, 1.0f, 1},
    {2, 0, 1, 1.0f, 4},
    {2, 0, 8, 1.0f, 4},
    {2, 0, 7, 0.7f, 4},
    {1, 0, 6, 0.8f, 0x20},
    {2, 7, 5, 1.0f, 8},
    {2, 0, 0, 0.8f, 0x20},
    {2, 0, 2, 1.0f, 8},
    {3, 0, 4, 1.0f, 0x10},
    {3, 0, 3, 1.0f, 0x10},
};

const char *TObjEneSaver__class_name = "TObjEneSaver";
const NpcAnimationBinding saver_init_binding_desc = { NULL, reinterpret_cast<TObjMotionAction *>(saver_action_table), 0, 1, 11 };
const Vec lbl_8043A8A4 = {0.0f, 0.0f, 0.0f};
const Vec lbl_8043A8B0 = {0.0f, 0.0f, 0.0f};
const Vec lbl_8043A8BC = {0.0f, 0.0f, 0.0f};
void *lbl_80490B28[7] = {
    (void *)0x437a0000, (void *)0x3fa00000, (void *)0x400, (void *)0x0,
    (void *)0x64, (void *)0x0, (void *)0x0,
};
void *saver_collision_body_part_table[11] = {
    (void *)0x0, (void *)0x41480000, (void *)0x0, (void *)0x40c00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
}

void TObjPlayer::reset_effect_count() { TObjPlayer__effect_count = 0; }

void TObjPlayer__sub_800A4294(void) {
    player_effect_task_list.p = &lbl_804CC8C8;
    player_effect_task_list.n = 0x10;
    (*(s32 *)&TObjPlayer__effect_count) = player_effect_task_list.p->b->c->x0;
}

void TObjPlayer__sub_800A42C0(void) {  }

void TObjEneSaver::apply_lookup_entry_effect() {
    struct { s32 a, b, c; s32 d, e, f, g, h; } sp8;
    s32 entry;
    u8 *temp_r3_2;

    entry = (saddr)lbl_805D5064->lookup((f32)this->frame);
    if (entry != 0) {
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(&this->position);
        rotate_matrix_y(0, this->rotation_y);
        matrix_mult_vec_array(0, entry, &sp8, 2);
        pop_matrix();
        temp_r3_2 = (u8 *)attack_traces[0];
        if (temp_r3_2 != NULL) {
            ((struct VDisp_800a42c4_800A4288 *) temp_r3_2)->m4(&sp8, &sp8.d);
        }
    }
}

void TObjEneSaver::sub_800A435C() {
    switch (particle_type) {
    case 0x0:
        if (particle_ctrl != NULL) {
            particle_ctrl->free_particle_ctrl();
        }
        break;
    default:
        calc_move_state();
    case 0x107:
    case 0x10E:
        if (!(state_flags & 4)) {
            if (particle_ctrl != NULL) {
                particle_ctrl->free_particle_ctrl();
            }
        } else if ((s32)particle_type_b != (s32)particle_type) {
            if (particle_ctrl != NULL) {
                particle_ctrl->set_param(particle_type);
            }
            particle_type_b = particle_type;
        }
        break;
    }
    if (particle_ctrl != NULL) {
        TObjPlayer__sub_800A7774(particle_ctrl, &particle_position);
    }
}

void TObjEneSaver::calc_move_state() {
    if (guard_hp_max == guard_hp) {
        particle_type = 0x101;
        return;
    }
    if (0.5f * guard_hp_max < guard_hp) {
        particle_type = 0x102;
        return;
    }
    if (guard_hp > 0) {
        particle_type = 0x103;
        return;
    }
    particle_type = 0;
}

void TObjEneSaver::update_collapse_and_destroy() {
    advance_animation();
    switch (phase) {
    case 0:
        phase = 1;
        fn_800D911C(&position);
        TObjPlayer__sub_800A04F0(&body_fade);
        apply_actor_gravity(this, NULL, 0.0f);
        play_sound_effect(remap_sound_for_area(0x4003B207), &position, 0, 0);
        return;
    case 1:
        step_angle_clamped(this, 0);
        move_with_wall_slide((u8 *)this);
        velocity.x *= 0.5f;
        velocity.z *= 0.5f;
        if (body_fade.decay_value_toward_floor() == 1) {
            TObjPlayer::apply_effect_variant_a((saddr)&position, 0);
            phase = 2;
        }
        return;
    case 2:
        queue_destruction();
        break;
    }
}

void TObjEneSaver::run_death_reaction() {
    if (mode != 0xA) {
        mode = 0xA;
        phase = 0;
        if (random_ratio() < 0.5f) {
            requested_action = 9;
        } else {
            requested_action = 0xA;
        }
        bodies->flags &= ~1;
        ((TObjPlayer *)this)->refresh_lobby_state();
        send_entity_set_flags();
    }
}

void TObjEneSaver::update_entry_motion() {
    advance_animation();
    step_angle_clamped(this, 0);
    switch (phase) {
    case 0:
        phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case 1:
        velocity.z = 0.0f;
        velocity.x = 0.0f;
        apply_actor_gravity(this, NULL, 0.0f);
        if (action_flags != 8) {
            phase = 2;
        }
        break;
    case 2:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        actorFlags &= ~0x600;
        bodies->flags &= ~0x04000000;
        referenceHp = hp;
        break;
    }
    check_object_collisions();
    check_enemy_body_collisions(this);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
    actorFlags &= ~0x200000;
}
}




extern "C" {
f32 atan2_float(f32 y, f32 x);
s32 angle_difference_abs(s32, s32);
void *get_player_by_client_id(s32 i);
s32 subtract_vector(void *, void *);

void TObjEneSaver::update_knockback_state() {

    advance_animation();
    step_angle_clamped(this, 0);
    switch (phase) {
    case 0:
        phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case 1:
        move_with_wall_slide((u8 *)this);
        velocity.x *= 0.5f;
        velocity.z *= 0.5f;
        if (action_flags != 8) {
            requested_action = 7;
            phase = 2;
        }
        break;
    case 2:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        if (action_flags != 0x20) {
            if (guard_hp <= 0) {
                state_flags |= 8;
            }
            actorFlags &= ~0x600;
            referenceHp = hp;
        }
        break;
    }
    check_object_collisions();
    check_enemy_body_collisions(this);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
    actorFlags &= ~0x200000;
}
void TObjEneSaver::run_hit_reaction() {
    Vec v;
    TObjChara *attacker;
    s32 d;
    if (mode >= 10 || mode < 8) {
        attacker = (TObjChara *)get_player_by_client_id(attacker_id);
        if (attacker != NULL) {
            VecCopy(&v, &attacker->body_center);
            subtract_vector(&v, &body_center);
            d = angle_difference_abs(rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
        } else {
            d = 0;
        }
        if (d < 0x2AAA) {
            mode = 8;
            requested_action = 6;
        } else {
            mode = 9;
            requested_action = 8;
        }
        phase = 0;
    }
    bodies->flags |= 1;
    actorFlags &= ~0x06240000;
}

}





struct VBase18_800A4D9C { char pad[0x18]; };

struct VObj18_800A4D9C : VBase18_800A4D9C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(void *, void *);
};



extern "C" {
s32 TObjPlayer__sub_800A0554(void *);
f32 calc_distance_to_client__10TObjPlayerFlUsUl(void *, u16, void *);

f32 calc_xz_distance_sq(saddr arg0, uaddr arg1, void *arg2);

s32 enemy_move_toward(void *, s32, Vec *, int, f32 *, f32);
s32 select_enemy_destination(void *, Vec *, int);
s32 copy_position_if_valid(s32 arg0, s32 arg1);
#define turn_toward_target__12TObjEneSaverFv ((s32 (*)(void*))(turn_toward_target__12TObjEneSaverFv))
f32 horizontal_distance_squared(int, void *);

}
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 calc_velocity_toward_destination(void *, Vec, Vec, f32);
s32 get_current_floor();
f32 newton_sqrtf(f32);

void TObjPlayer__sub_800A54B4(u8 *arg0);
s32 check_path_obstructed(void *, void *);
u16 get_entity_id(void *);
void TObjPlayer__sub_800A5960(void *arg0);

s16 TObjPlayer__sub_800A776C(void *p);

#pragma push
#pragma fp_contract on
void TObjPlayer__sub_800A49B4(TObjEneSaver *self) {
    self->advance_animation();
    step_angle_clamped(self, 0);
    if (!(self->actorFlags & 0x800000)) {
        apply_actor_gravity(self, (s32 *)0, 0.0f);
    }
    switch (self->phase) {
    case 0:
        self->phase = 1;
        apply_actor_gravity(self, (s32 *)0, 0.0f);
        if (self->last_attacker != NULL) {
            s32 bonus;
            s32 atp;
            atp = self->last_attacker->get_actor_attack_params_atp_min();
            bonus = self->last_attacker->get_field_2c8();
            self->guard_hp -= 0.2f * (bonus + atp + TObjPlayer__sub_800A776C(self->last_attacker) - self->m_2ce);
            if (self->guard_hp <= 0) {
                self->guard_hp = 0;
                self->state_flags |= 8;
            }
        }
        self->actorFlags |= 0x04000000;
        play_sound_effect(((TObjEnemy *)(self))->remap_sound_for_area(0x4003AD05), &self->position, 0, 0);
        break;
    case 1:
        if (((TObjMotion *)self)->is_passing_frame(5.0f) != 0) {
            self->particle_type = 0x107;
        }
        if (((TObjMotion *)self)->is_passing_frame(28.0f) != 0) {
            self->actorFlags &= 0xFBFFFEFF;
            self->state_flags &= ~0x20;
            if (self->test_flag_256() != 0) {
                self->phase = 0;
                self->frame = 0.0f;
            } else {
                self->phase = 2;
            }
            self->calc_move_state();
        }
        break;
    case 2:
    default:
        self->actorFlags &= 0xFBFFFEFF;
        self->state_flags &= ~0x20;
        break;
    }
    ((TObjPlayer *)self)->check_object_collisions();
    check_enemy_body_collisions(self);
    minimap_render_dot(&self->position, -0x5DB4, 1, 0);
    self->actorFlags &= ~0x200000;
}
#pragma pop

void TObjEneSaver::run_miss_reaction() {
    if (mode != 7) {
        mode = 7;
        phase = 0;
        requested_action = 5;
    }
    bodies->flags |= 1;
    actorFlags &= ~0x06640000;
}


int TObjEneSaver::test_flag_256() {
    Vec v;
    TObjPlayer *p;
    s32 i;
    if (state_flags & 0x20) {
        return 1;
    }
    if ((state_flags & 4) && guard_hp > 0) {
        for (i = 0; i < registered_player_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == NULL || (p->actorFlags & 0x800)) {
                continue;
            }
            if (!(calc_distance_to_client__10TObjPlayerFlUsUl(this, i, &v) < 900.0f)) {
                continue;
            }
            if (angle_difference_abs(rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z))) >= 0x2AAA) {
                continue;
            }
            if (p->test_action_mask(0xE0) == 0) {
                continue;
            }
            VecCopy(&v, &body_center);
            subtract_vector(&v, &p->body_center);
            if (angle_difference_abs(p->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z))) < 0x2AAA) {
                last_attacker = p;
                state_flags |= 0x20;
                return 1;
            }
        }
    }
    return 0;
}

void TObjEneSaver::sub_800A4D9C() {
    u8 m50[0xC];
    u8 m44[0xC];
    Vec d;
    u8 *p;
    s32 e;
    u16 id;
    id = targetId;
    if (id < 0x1000) {
        p = (u8 *)get_player_by_client_id(id);
        if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            target = p;
        } else {
            target = NULL;
        }
    } else if (id < 0x4000) {
        target = get_enemy_entity(id);
    } else {
        targetId = 0xFFFF;
        target = NULL;
    }
    actorFlags |= 0x06000000;
    bodies->flags &= ~1;
    advance_animation();
    step_angle_clamped(this, 0);
    switch (phase) {
    case 0:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        if (is_passing_frame(11.0f) != 0) {
            u8 *t = target;
            if (t == NULL) {
                goto fail;
            }
            {
                Vec dest = ((TObjChara *)t)->body_center;
                if (select_enemy_destination(this, &dest, 1) == 0) {
                    goto fail;
                }
            }
            phase = 1;
            {
                Vec pos = body_center;
                copy_position_if_valid((saddr)this, (saddr)&pos);
            }
            VecCopy(&d, &move_destination);
            subtract_vector(&d, &body_center);
            {
                f32 dist = newton_sqrtf(d.x * d.x + d.z * d.z);
                dist -= 15.0f;
                calc_velocity_toward_destination(this, move_origin, move_destination, 0.058333334f * dist);
            }
            play_sound_effect(remap_sound_for_area(0x4003AD03), &position, 0, 0);
            goto done;
        fail:
            phase = 2;
        done:
            spawn_particle_effect(&position, 0xF3);
        }
        break;
    case 1:
        move_with_wall_slide((u8 *)this);
        if (11.0f <= frame && frame <= 27.0f) {
            if ((e = (saddr)lbl_805D5068->lookup(frame)) != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&position);
                rotate_matrix_y(0, rotation_y);
                matrix_mult_vec_array(0, e, m44, 2);
                pop_matrix();
                if (attack_traces[1] != NULL) {
                    ((VObj18_800A4D9C *)attack_traces[1])->m4(m44, m50);
                }
            }
        }
        if (is_passing_frame(23.0f) != 0) {
            check_object_collisions();
            check_enemy_body_collisions(this);
            phase = 2;
            TObjPlayer__sub_800A5960(this);
            spawn_particle_effect(&position, 0xF3);
            play_sound_effect(remap_sound_for_area(0x4003AD04), &position, 0, 0);
            state_flags &= ~0x10;
        }
        break;
    case 2:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        if (action_flags != 4) {
            enemy_set_heading_velocity(0.0f, this, rotation_y);
            actorFlags &= ~0x06200000;
            bodies->flags |= 1;
        }
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

struct VBase_800A5154 { char pad[0x18]; };
struct VTgt_800A5154 : VBase_800A5154 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual f32 m20(void *, f32);
    virtual void m21(); virtual void m22();
    virtual void m23(void *);
};
struct VCb_800A5154 : VBase_800A5154 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(void *, void *);
};
struct Anim_800A5154 { u8 pad[0x18]; u32 flags; };

struct Pl_800A5154 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x38 - 0x34];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Anim_800A5154 *anim;
    u8 padA8[0xB4 - 0xA8];
    u32 fB4;
    u8 padB8[0xC0 - 0xB8];
    f32 fC0;
    u8 padC4[0x2A8 - 0xC4];
    VTgt_800A5154 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    u8 snd[0x328 - 0x2FC];
    s16 phase;
    u8 pad32A[0x338 - 0x32A];
    u16 target_id;
    u8 pad33A[0x374 - 0x33A];
    u32 f374;
    u8 pad378[0x37E - 0x378];
    s16 count;
    s32 f380;
    u8 pad384[0x388 - 0x384];
    s16 f388;
    s16 f38A;
    u8 pad38C[0x3C8 - 0x38C];
    VCb_800A5154 *cb;
};

#define o ((Pl_800A5154 *)arg0)
void TObjPlayer__sub_800A5154(void *arg0) {
    Vec w;
    Vec v;
    u16 id;

    id = o->target_id;
    if (id < 0x1000) {
        u8 *p = (u8 *)get_player_by_client_id(id);
        if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            o->target = (VTgt_800A5154 *)p;
        } else {
            o->target = NULL;
        }
    } else if (id < 0x4000) {
        o->target = (VTgt_800A5154 *)get_enemy_entity(id);
    } else {
        o->target_id = 0xFFFF;
        o->target = NULL;
    }
    o->anim->flags |= 1;
    o->flags &= 0xF9FBFFFF;
    ((TObjMotion *)o)->advance_animation();
    step_angle_clamped(o, 0);
    switch (o->phase) {
    case 0:
        o->phase = 1;
        apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), 0.0f);
        play_sound_effect(((TObjEnemy *)(o))->remap_sound_for_area(0x4003AD02), &o->pos, 0, 0);
        break;
    case 1:
        if (!(o->flags & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), 0.0f);
        }
        if (((TObjMotion *)o)->is_passing_frame((f32)7.0f) != 0) {
            if (o->target != NULL && o->target->m18(o, 1.0f) != 0) {
                f32 d = o->target->m20(o, 1.0f);
                o->target->m23(o);
                o->f388 = o->f388 + d;
                o->f380 = 0x10E;
                if (o->f38A < o->f388) {
                    o->f388 = o->f38A;
                }
                play_sound_effect(((TObjEnemy *)(o))->remap_sound_for_area(0x4003B241), o->snd, 0, 0);
            }
        }
        if (0.0f <= o->fC0 && o->fC0 <= 7.0f) {
            s32 entry = (saddr)lbl_805D506C->lookup(o->fC0);
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&o->pos);
                rotate_matrix_y(0, o->angle);
                matrix_mult_vec_array(0, entry, &v, 2);
                pop_matrix();
                if (o->cb != NULL) {
                    o->cb->m4(&v, &w);
                }
            }
        }
        if (o->fB4 != 4) {
            o->phase = 2;
            o->count++;
        }
        break;
    case 2:
        ((TObjEneSaver *)o)->calc_move_state();
        if (o->count >= 2) {
            o->count = 0;
            o->f374 &= ~8;
        }
        o->flags &= ~0x200000;
        break;
    }
    ((TObjPlayer *)o)->check_object_collisions();
    check_enemy_body_collisions(o);
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
    submit_cursor_candidate(o, -1);
}
#undef o


typedef struct Self_800A5960 Self_800A5960;
}

struct VBase800A64E8_800a64e8_800A4288 { char pad[0x14]; };
struct VObj800A64E8_800a64e8_800A4288 : VBase800A64E8_800a64e8_800A4288 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
};

struct Tgt_800A6B14 { u8 pad[0x2fc]; Vec pos; };

struct Obj_800A6B14 {
    u8 pad[0x60]; s32 angle;
    u8 pad2[0x2a8 - 0x64]; Tgt_800A6B14 *target;
    u8 pad3[0x2fc - 0x2ac]; Vec pos;
};




extern "C" {
s32 rotate_matrix_x(int, void *);
extern f32 lbl_804FF5E8[];
s32 angle_diff_s16(s32, s32);
#define TObjPlayer__sub_800A42C0 ((s32 (*)(void*))(TObjPlayer__sub_800A42C0))
void TObjPlayer__sub_800A49B4(TObjEneSaver *self);
extern s32 actor_frame_tick;

s32 matrix_mult_vec(int, Vec *, void *);
extern u8 identity_matrix[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

#define get_entity_id ((s32 (*)(void*))(get_entity_id))
void * create_ene_saver(void *arg0);
s32 lerp_angle_half__Fll(s32, s32);
s32 obj_setFlags30(void *, int);

struct VBase62D4 { char pad[0x14]; };
struct VObj62D4 : VBase62D4 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
};


extern void *tl_04;

#define saver_collision_body_part_table ((f32 *)saver_collision_body_part_table)
#define RES ((Res_800A715C *)saver_bml_resource)

}

#pragma defer_codegen on

extern "C" {

void TObjEneSaver::sub_800A7734(s32 i) {
    ((O_800A7734 *)this)->x34 = (*(G_800A7734 * *)&saver_bml_resource)->tbl[i].x8;
    ((O_800A7734 *)this)->x24 = (*(G_800A7734 * *)&saver_bml_resource)->tbl[i].xc;
}

void *TObjEneSaver::get_center() { return (char*)this + 0x2fc; }

TObjEneSaver::TObjEneSaver(TObject *parent, void *set_data) : TObjEnemy(parent) {
    s16 guard;
    m_name = TObjEneSaver__class_name;
    apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    scale.z = 1.0f;
    scale.y = 1.0f;
    scale.x = 1.0f;
    guard = (s16)(100.0f + parameters[0]);
    guard_hp = guard;
    guard_hp_max = guard;
    if (parameters[1] < 0.0f) {
        parameters[1] = 0.0f;
    } else if (8.0f < parameters[1]) {
        parameters[1] = 8.0f;
    }
    parameter_mask = 0;
    parameter_mask |= 1 << (s32)parameters[1];
    mode = 0;
    phase = 0;
    variant = 0;
    set_param(0x1E);
    subtype = 0;
    sub_800A7734(variant);
    action_table = saver_action_table;
    set_field_d8((saddr)action_table);
    motion_list = ((BmlResource *)saver_bml_resource)->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    init_collision_body_parts(this, (u8 *)saver_collision_body_part_table, 1);
    attack_index = 0;
    step_counter = 0;
    bind_enemy_combat_stats((u8 *)saver_boss_stat_handle, (u8 *)(player_object_ptr_array[attack_index]), (u8 *)saver_object_stat_handle);
    movementParameters = (u8*)lbl_80490B28;
    referenceHp = hp;
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    initialize_enemy_photon_effect(this);
    state_flags = 1;
    last_attacker = NULL;
    VecCopy(&particle_position, &body_center);
    facing_angle = 0;
    add_flags_2e4(8);
    actorFlags |= 0x06040000;
    particle_type = 0x101;
    particle_type_b = 0x101;
    particle_ctrl = new TEneParticleCtrl(this, particle_type);
    attack_traces[0] = TUnk_80494968::create(0xA0303030, 0xFFFF0088);
    attack_traces[1] = TUnk_80494968::create(0xA0303030, 0xFFFF0088);
    attack_traces[2] = TUnk_80494968::create(0xA0303030, 0xFF303030);
    clear_lobby_object_state();
}

TObjEneSaver::~TObjEneSaver() {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (attack_traces[i] != NULL) {
            attack_traces[i]->queue_destruction();
            attack_traces[i] = NULL;
        }
    }
    free_collision_body_parts(this);
}

void initialize_saver_resources(void) {
    Vec pos;
    Vec dir;
    void *r;
    r = new BmlResource(1, (BmlResourceDescriptor *)bm_ene_df1_saver_resource_descriptor, 0, 0, NULL);
    saver_bml_resource = (uaddr)r;
    lbl_805D5054 = *(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)((u8 *)((Res_800A715C *)r)->sub) + 8)) + 0x2C)) + 0x30)) + 4)) + 4);
    lbl_805D5058 = 0;
    lbl_805D505C = 0;
    lbl_805D5060 = 0;
    lbl_80500978.pos.z = 0.0f;
    lbl_80500978.pos.y = 0.0f;
    lbl_80500978.pos.x = 0.0f;
    lbl_805D5064 = new SampledMotionPoints(2, 15.0f, 60.0f, 1.0f);
    lbl_805D5068 = new SampledMotionPoints(2, 11.0f, 27.0f, 1.0f);
    lbl_805D506C = new SampledMotionPoints(2, 0.0f, 7.0f, 1.0f);
    lbl_805D5064->sample_two_nodes((NJS_OBJECT *)RES->sub->f8, (NJS_MOTION *)(RES->ents[saver_action_table[2].motion].b), 0x20, 0x21);
    lbl_805D5068->sample_two_nodes((NJS_OBJECT *)RES->sub->f8, (NJS_MOTION *)(RES->ents[saver_action_table[4].motion].b), 0x20, 0x21);
    pos.x = pos.y = pos.z = 0.0f;
    dir.x = (-10.0f);
    dir.y = dir.z = 0.0f;
    lbl_805D506C->sample_node_offsets((NJS_OBJECT *)RES->sub->f8, (NJS_MOTION *)(RES->ents[saver_action_table[3].motion].b), 0x19, (const Vec *)&pos, (const Vec *)&dir);
    player_object_ptr_array = (void **)mem_alloc(0xC);
    saver_boss_stat_handle = TLobby::register_boss(0x52);
    player_object_ptr_array[0] = TLobby::dispatch_shared_handler_b(0x57);
    player_object_ptr_array[2] = TLobby::dispatch_shared_handler_b(0x58);
    player_object_ptr_array[1] = TLobby::dispatch_shared_handler_b(0x59);
    saver_object_stat_handle = TLobby::register_object(0x51);
    lbl_805D504C = (f32 *)TLobby::dispatch_shared_handler_a(0x51);
    NpcAnimationBinding init = saver_init_binding_desc;
    init.motions = reinterpret_cast<BmlMotionEntry *>(RES->ents);
    NpcModelRegistry::register_animated_chunk((s16)0x1A, reinterpret_cast<void *>(RES->sub->f8), reinterpret_cast<void *>(RES->sub->texlist), &init, (f32)saver_collision_body_part_table[3], (f32)0.0f);
}

void TObjEneSaver::free_resources() {
    if (player_object_ptr_array != NULL) {
        mem_free(player_object_ptr_array);
        player_object_ptr_array = NULL;
    }
    if (lbl_805D5064 != NULL) {
        delete lbl_805D5064;
        lbl_805D5064 = NULL;
    }
    if (lbl_805D5068 != NULL) {
        delete lbl_805D5068;
        lbl_805D5068 = NULL;
    }
    if (lbl_805D506C != NULL) {
        delete lbl_805D506C;
        lbl_805D506C = NULL;
    }
    if ((u32) saver_bml_resource != 0U) {
        delete (BmlResource *)saver_bml_resource;
        saver_bml_resource = 0U;
    }
}

void *create_ene_saver(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneSaver(control, set_data);
}

void TObjEneSaver::run_task() {
    if (lbl_805D5058 != actor_frame_tick) {
        lbl_805D5058 = actor_frame_tick;
        TObjPlayer__sub_8023DEE0((s16 *)lbl_805D5054, 0xE, 0, 0);
    }
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjPlayer__sub_800A42C0(this);
        return;
    }
    {
        switch (mode) {
        case 0:
            init_render_flags();
            break;
        case 1:
            advance_motion_state();
            break;
        case 2:
            sub_800A5FA8();
            break;
        case 3:
            update_move_toward_target();
            break;
        case 4:
            TObjPlayer__sub_800A54B4((((u8 *)this)));
            break;
        case 5:
            TObjPlayer__sub_800A5154((this));
            break;
        case 6:
            sub_800A4D9C();
            break;
        case 7:
            TObjPlayer__sub_800A49B4(this);
            break;
        case 8:
            update_knockback_state();
            break;
        case 9:
            update_entry_motion();
            break;
        case 10:
            update_collapse_and_destroy();
            break;
        case 11:
            sub_800A62D4();
            break;
        }
    }
    if (target != NULL && (((TObjChara *)target)->actorFlags & 0x02000800)) {
        step_counter = 0;
        actorFlags &= ~0x200000;
        state_flags &= 0xFFFF0000;
        state_flags |= 0x40;
        target = NULL;
    }
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    sub_800A435C();
    m_2b4 += 1.0f;
}

void TObjEneSaver::render() {
    s32 v;
    v = classify_actor_view_detail(300.0f, 600.0f, 30.0f);
    if (v != 0) {
        select_actor_lighting(this);
        TObjFish::set_global_param(texlist);
        push_matrix_from(NULL);
        translate_matrix_vec3(0, (u8 *)&position);
        rotate_matrix_y(0, rotation_y);
        lbl_805D505C = 0;
        lbl_805D5060 = facing_angle;
        set_chunk_model_node_callback(TObjPlayer::step_cutscene_frame);
        TObjPlayer::toggle_particle_effect();
        switch (mode) {
        case 11:
            if (phase == 1) {
                scale_matrix_vec3(0, (u8 *)&scale);
            }
        case 1:
        case 2:
            if (body_fade.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                body_fade.set_flags_and_apply_damage_color();
                v = 1;
                model_render_flags |= 1;
                if (defer_render() != 0) {
                    v = 0;
                }
                if (v != 0) {
                    draw();
                }
                model_render_flags &= ~1;
                body_fade.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
            break;
        case 0:
            break;
        default:
            if (v == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            break;
        }
        TParticleCtrl::end_effect_render();
        set_chunk_model_node_callback(NULL);
        VecCopy(&particle_position, &lbl_80500978.pos);
        pop_matrix();
        restore_scene_lighting();
        if (!(state_flags & 1)) {
            draw_ground_shadow(0, 0);
        }
    } else {
        push_matrix_from(identity_matrix);
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        set_motion_packed_rotation();
        calc_joint_matrices(frame);
        clear_motion_packed_rotation();
        pop_matrix();
        push_matrix_from(anim_model_matrix_array[26]);
        {
            Vec t = lbl_8043A8A4;
            matrix_mult_vec(0, &t, &particle_position);
        }
        pop_matrix();
    }
}

void TObjPlayer::step_cutscene_frame(NJS_OBJECT *) {
    if (lbl_805D505C == 0x15) {
        rotate_matrix_x(0, (void *)lbl_805D5060);
    }
    if (lbl_805D505C == 0x1A) {
        lbl_80500978.pos.x = 0.0f;
        lbl_80500978.pos.y = 0.0f;
        lbl_80500978.pos.z = 0.0f;
        TObjBoss2Tunnel::transform_vec_by_camera((saddr)&lbl_804FF5E8, (saddr)&lbl_80500978.pos, (saddr)&lbl_80500978.pos);
    }
    lbl_805D505C += 1;
}

void step_angle_clamped(void *self, s32 arg1) {
    s32 target_rot;

    target_rot = arg1;
    if (target_rot < -0x238E) {
        target_rot = -0x238E;
    } else if (target_rot > 0x238E) {
        target_rot = 0x238E;
    }
    *(s32 *)((s8 *)self + 0x39C) = lerp_angle_half__Fll(*(s32 *)((s8 *)self + 0x39C), target_rot);
}

void TObjEneSaver::turn_toward_target() {
    Vec d;
    VecCopy((Vec *)&d, (const Vec *)&((Obj_800A6B14 *)this)->target->pos);
    subtract_vector(&d, &((Obj_800A6B14 *)this)->pos);
    step_angle_clamped(this, angle_diff_s16(((Obj_800A6B14 *)this)->angle, (s32)(10430.38043493439 * atan2_float(d.x, d.z))));
}

void TObjEneSaver::refresh_target() {
    if (state_flags & 0x40) {
        targetId = 0xFFFF;
        target = NULL;
        return;
    }
    if (is_actor_cadence_frame(0x1E) == 0) {
        return;
    }
    if (obj_testFlags30(0x10) != 0) {
        s32 best_id;
        s32 i;
        u8 *p;
        s32 id;
        f32 best;
        f32 d;
        u16 tid;
        i = 0;
        best_id = 0xFFFF;
        Vec v = lbl_8043A8B0;
        best = *(f32 *)movementParameters * *(f32 *)movementParameters;
        for (; i < registered_player_count + registered_enemy_count; i++) {
            p = (u8 *)TObjPlayer::get_player_data(i);
            if (p != NULL && p != (u8 *)this) {
                id = get_entity_id(p);
                if ((u16)id < 0x4000 && (u16)id != entity_id && !(((TObjMotion *)p)->actorFlags & 0x02000800)) {
                    VecCopy((Vec *)&v, (const Vec *)((Vec *)(p + 0x2FC)));
                    subtract_vector(&v, &body_center);
                    d = v.x * v.x + v.z * v.z;
                    if (d < best && check_path_obstructed(this, p + 0x2FC) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
        }
        targetId = best_id;
        tid = targetId;
        if (tid < 0x1000U) {
            u8 *q = (u8 *)get_player_by_client_id(tid);
            if (q != NULL) {
                if (((TObjPlayer *)q)->get_floor() == get_current_floor()) {
                    target = q;
                    return;
                }
            }
            target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            target = get_enemy_entity(tid);
        }
        return;
    }
    {
        s32 best_id2;
        s32 best_id;
        u8 *p;
        u8 *best_p2;
        u8 *best_p;
        s32 i;
        f32 best2;
        f32 best;
        f32 d;
        Vec v = lbl_8043A8BC;
        best_id = 0xFFFF;
        best_p2 = NULL;
        best_id2 = best_id;
        best_p = NULL;
        i = 0;
        best = *(f32 *)movementParameters * *(f32 *)movementParameters;
        best2 = best;
        for (; i < registered_player_count; i++) {
            p = (u8 *)TObjPlayer::get_player_data(i);
            if (p == NULL) continue;
            if ((u16)get_entity_id(p) >= 0x1000) continue;
            if (((TObjPlayer *)p)->get_floor() != get_current_floor()) continue;
            if (((TObjMotion *)p)->actorFlags & 0x02000800) continue;
            VecCopy((Vec *)&v, (const Vec *)((Vec *)(p + 0x2FC)));
            subtract_vector(&v, &body_center);
            d = v.x * v.x + v.z * v.z;
            if ((((TObjPlayer *)p)->class_flags & parameter_mask) && d < best &&
                check_path_obstructed(this, p + 0x2FC) != 1) {
                best_id = get_entity_id(p);
                best = d;
                best_p = p;
            }
            if (d < best2 && check_path_obstructed(this, p + 0x2FC) != 1) {
                best_id2 = get_entity_id(p);
                best2 = d;
                best_p2 = p;
            }
        }
        if (best2 < 900.0f && best_p2 != NULL) {
            targetId = best_id2;
            target = best_p2;
            return;
        }
        if (best_p != NULL) {
            targetId = best_id;
            target = best_p;
            return;
        }
        if (best_p2 != NULL) {
            targetId = best_id2;
            target = best_p2;
            return;
        }
        targetId = 0xFFFF;
        target = NULL;
    }
}

s32 TObjEneSaver::update_action_hold_status() {
    u8 *self = (u8 *)this;
    if (TObjChara::update_action_hold_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xB:
            if (body_fade.advance_toward_max() == 1) {
                this->state_flags &= ~0x43;
                this->state_flags |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                ((TObjBase *)self)->obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneSaver::update_movement_status() {
    u8 *self = (u8 *)this;
    if (TObjChara::update_movement_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xB:
            if (body_fade.advance_toward_max() == 1) {
                this->state_flags &= ~0x43;
                this->state_flags |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                ((TObjBase *)self)->obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

void TObjEneSaver::run_idle_action() {
    u8 *self = (u8 *)this;
    u8 *temp_r3;

    switch (this->mode) {
    case 0:
        if (((VObj800A64E8_800a64e8_800A4288 *)(self + 0x3A4))->m8() != 0) {
            this->mode = 0xB;
            this->phase = 0;
            this->requested_action = 0;
            ((TObjBase *)self)->obj_clearFlags30(0x200000);
            obj_setFlags30(self, 0x06040000);
            this->state_flags = (s32) (this->state_flags & 0xFFFF0000);
            this->state_flags = (s32) (this->state_flags | 0x40);
            temp_r3 = (unsigned char *) (this->bodies);
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
        }
        return;
    case 11:
        if (!(this->state_flags & 0x40)) {
            this->mode = 0;
            return;
        }
        break;
    default:
        this->mode = 0xB;
        this->phase = 0;
        this->requested_action = 0;
        ((TObjBase *)self)->obj_clearFlags30(0x200000);
        obj_setFlags30(self, 0x06040000);
        this->state_flags = (s32) (this->state_flags & 0xFFFF0000);
        this->state_flags = (s32) (this->state_flags | 0x40);
        break;
    }
}

void TObjEneSaver::init_render_flags() {
    u8 *self = (u8 *)this;
    u8 *temp_r3;

    ((TObjBase *)self)->set_position_from((u8 *)&this->home_position);
    ((TObjCollidable *)self)->refresh_collision_body_centers();
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) & 0xFFDFFFFF);
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) | 0x06040000);
    temp_r3 = (unsigned char *) (this->bodies);
    *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
}

void TObjEneSaver::sub_800A62D4() {
    s16 temp_r4_2;

    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    this->actorFlags = (s32) (this->actorFlags | 0x06040000);
    this->state_flags = (s32) (this->state_flags & 0xFFFFFFF8);
    *(s32 *)((s8 *)this->bodies + 0x18) = (s32) (*(s32 *)((s8 *)this->bodies + 0x18) & 0xFFFFFFFE);
    this->advance_animation();
    switch (this->phase) {
    case 0:
    default:
        temp_r4_2 = *(s16 *)((s8 *)((u8 *)this) + 0x37E);
        *(s16 *)((s8 *)((u8 *)this) + 0x37E) = (temp_r4_2 + 1);
        if (30.0f < (f32) temp_r4_2) {
            this->phase = 1;
            this->scale.z = (f32) 1.0f;
            this->scale.y = (f32) 1.0f;
            this->scale.x = (f32) 1.0f;
            *(s16 *)((s8 *)((u8 *)this) + 0x37E) = 0;
            TObjPlayer__sub_800A04F0((void *) (((u8 *)this) + 0x3A4));
            apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
            play_area_variant_sound((Vec *)((u8 *)this + 0x38));
        }
        break;
    case 1:
        this->scale.x = (f32) (this->scale.x - 0.1f);
        if (this->scale.x < 1e-5f) {
            this->scale.x = (f32) 0.0f;
        }
        this->scale.y += 0.1f;
        this->scale.z = (f32) this->scale.x;
        if (((VObj62D4 *) (((u8 *)this) + 0x3A4))->m4() == 1) {
            this->phase = 2;
        }
        break;
    case 2:
        this->set_position_from((void *) (((u8 *)this) + 0x50));
        this->update_prev_position();
        this->scale.z = (f32) 1.0f;
        this->scale.y = (f32) 1.0f;
        this->scale.x = (f32) 1.0f;
        this->state_flags = (s32) (this->state_flags & 0xFFFF0000);
        this->state_flags = (s32) (this->state_flags | 1);
        break;
    }
    minimap_render_dot((void *) (((u8 *)this) + 0x38), -0x5DB4, 1, 0);
}

void TObjEneSaver::run_move_action() {
    s32 temp_r4;
    void *temp_r3;
    void *temp_r3_2;

    switch (this->mode) {
    default:
        temp_r4 = this->state_flags;
        if (temp_r4 & 4) {
            this->mode = 3;
            this->phase = 0;
            this->requested_action = 1;
            this->actorFlags = (s32) (this->actorFlags & 0xF9FBFFFF);
        } else if (temp_r4 & 1) {
            this->mode = 1;
            this->phase = 0;
            this->actorFlags = (s32) (this->actorFlags | 0x06040000);
        }
        temp_r3 = this->bodies;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
        return;
    case 1:
        if (this->state_flags & 2) {
            this->mode = 2;
            this->phase = 0;
            this->actorFlags = (s32) (this->actorFlags | 0x06040000);
        }
        return;
    case 2:
        if (this->state_flags & 4) {
            this->mode = 3;
            this->phase = 0;
            this->requested_action = 1;
            this->actorFlags = (s32) (this->actorFlags & 0xF9FBFFFF);
            return;
        }
        break;
    case 3:
        if (this->state_flags & 3) {
            this->mode = 1;
            this->phase = 0;
            this->actorFlags = (s32) (this->actorFlags | 0x06040000);
            this->state_flags = (s32) (this->state_flags & 0xFFFF0000);
            this->state_flags = (s32) (this->state_flags | 1);
            temp_r3_2 = this->bodies;
            *(s32 *)((s8 *)temp_r3_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_2 + 0x18) | 1);
            return;
        }
        break;
    }
}

}

#undef TObjPlayer__sub_800A42C0
#undef get_entity_id

void TObjEneSaver::advance_motion_state() {

    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    this->actorFlags = (s32) (this->actorFlags | 0x06040000);
    *(s32 *)((s8 *)this->bodies + 0x18) = (s32) (*(s32 *)((s8 *)this->bodies + 0x18) & 0xFFFFFFFE);
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
        return;
    case 1:
        if (horizontal_distance_squared((saddr)(this->target + 0x2FC), (void *) (((u8 *)this) + 0x2FC)) < 40000.0f) {
            this->phase = 2;
        }
        return;
    case 2:
        this->state_flags = (s32) (this->state_flags & 0xFFFF0000);
        this->state_flags = (s32) (this->state_flags | 2);
        break;
    }
}

void TObjEneSaver::sub_800A5FA8() {
    u8 *temp_r4;
    u8 *self = (u8 *)this;
    ((TObjEneSaver *)self)->actorFlags = (s32) (((TObjEneSaver *)self)->actorFlags & 0xFFDFFFFF);
    ((TObjEneSaver *)self)->actorFlags = (s32) (((TObjEneSaver *)self)->actorFlags | 0x06040000);
    temp_r4 = (unsigned char *) (((TObjEneSaver *)self)->bodies);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    ((TObjMotion *)self)->advance_animation();
    switch (((TObjEneSaver *)self)->phase) {
    case 0:
        ((TObjEneSaver *)self)->phase = 1;
        play_area_se_with_particle((Vec *)(self + 0x38));
        TObjPlayer__sub_800A0554((u8 *)&this->body_fade);
        apply_actor_gravity((TObjEnemy *)(self), (s32 *)(0), 0.0f);
        play_area_variant_sound((Vec *)(self + 0x38));
        break;
    case 1:
        if (body_fade.advance_toward_max() == 1) {
            ((TObjEneSaver *)self)->phase = 2;
        }
        break;
    case 2:
        *(s32 *)((s8 *)self + 0x374) = (s32) (*(s32 *)((s8 *)self + 0x374) & 0xFFFF0000);
        *(s32 *)((s8 *)self + 0x374) = (s32) (*(s32 *)((s8 *)self + 0x374) | 4);
        break;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

void TObjEneSaver::update_move_toward_target() {
    f32 temp_f0;
    f32 temp_f1;
    u8 *temp_r8;
    *(s32 *)((s8 *)this->bodies + 0x18) |= 1;
    this->actorFlags &= 0xF9DBFFFF;
    temp_r8 = this->target;
    if (temp_r8 != NULL) {
        switch (this->phase) {
        case 0: {
            Vec v = *(Vec *)(temp_r8 + 0x2FC);
            if (select_enemy_destination(this, &v, 1) != 0) {
                sub_800A7798(lbl_805D504C[3]);
                this->phase = 1;
                {
                Vec v2 = *(Vec *)(((u8 *)this) + 0x2FC);
                copy_position_if_valid((saddr)this, (saddr)&v2);
                }
                apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
            }
            break;
        }
        case 1: {
            Vec v3 = *(Vec *)(temp_r8 + 0x2FC);
            enemy_move_toward(this, *(s32 *)((s8 *)this->movementParameters + 8), &v3, 0, lbl_805D504C, lbl_805D504C[2]);
            temp_f1 = horizontal_distance_squared((saddr) (((u8 *)this) + 0x29C), (void *) (((u8 *)this) + 0x38));
            if (temp_f1 < 22500.0f) {
                this->state_flags &= ~0x10;
            } else {
                this->state_flags |= 0x10;
            }
            temp_f0 = *(f32 *)((s8 *)this->movementParameters + 4) + *(f32 *)((s8 *)this->bodies + 0xC);
            if (temp_f1 < (temp_f0 * temp_f0)) {
                this->phase = 2;
            }
            break;
        }
        case 2:
            this->state_flags &= ~0x10;
            this->phase = 0;
            break;
        }
        advance_animation();
        turn_toward_target();
        this->check_object_collisions();
        check_enemy_body_collisions((this));
        minimap_render_dot((void *) (((u8 *)this) + 0x38), -0x5DB4, 1, 0);
        submit_cursor_candidate(this, -1);
    }
}

s32 TObjEneSaver::is_target_in_attack_range() {
    u8 *self = (u8 *)this;
    Vec v;
    f32 var_f29;
    f32 r;
    f32 dist;
    s32 ang;
    s32 flags;
    u8 *tgt;
    u8 *p;
    if (this->mode >= 3) {
        tgt = this->target;
        if (tgt != NULL && this->m_318 != 0U && !(*(s32 *)((s8 *)tgt + 0x30) & 0x02000800)) {
            dist = calc_xz_distance_sq((saddr)self, (uaddr)tgt, (void *)&v);
            ang = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
            p = *(u8 **)(this->target + 0xA4);
            if (p != NULL) {
                var_f29 = *(f32 *)((s8 *)p + 0xC);
            } else {
                var_f29 = 10.0f;
            }
            flags = this->state_flags;
            if (flags & 8) {
                *(s16 *)((s8 *)self + 0x37C) = 2;
                if (dist <= (var_f29 + ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_range()) * (var_f29 + ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_range()) && ang <= ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_angle()) {
                    return 1;
                }
            } else if (flags & 0x10) {
                *(s16 *)((s8 *)self + 0x37C) = 1;
                r = 150.0f + var_f29;
                if (dist <= r * r && ang <= 0xAAA) {
                    return 1;
                }
            } else {
                *(s16 *)((s8 *)self + 0x37C) = 0;
                if (dist <= (var_f29 + ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_range()) * (var_f29 + ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_range()) && ang <= ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_angle()) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void TObjEneSaver::run_attack_action() {
    Vec v;
    switch (attack_index) {
    case 0:
    default: {
        VecCopy(&v, &((TObjChara *)target)->body_center);
        subtract_vector(&v, &body_center);
        f32 a = atan2_float(v.x, v.z);
        mode = 4;
        if ((s32)(10430.38043493439 * a) < 0x10) {
            phase = 1;
            requested_action = 2;
            sub_800A7798(*lbl_805D504C);
        } else {
            phase = 0;
            requested_action = 1;
        }
        break;
    }
    case 2:
        mode = 5;
        phase = 0;
        requested_action = 3;
        break;
    case 1:
        mode = 6;
        phase = 0;
        requested_action = 4;
        break;
    }
    bind_enemy_combat_stats(NULL, (u8 *)player_object_ptr_array[attack_index], NULL);
    bodies->flags |= 1;
    actorFlags &= 0xF9FBFFFF;
    actorFlags |= 0x200000;
}

void TObjPlayer__sub_800A5960(void *arg0) {
    s32 n;
    s32 limit;
    s32 i;
    TObjChara *p;
    TObjEneSaver *self = (TObjEneSaver *)arg0;
    if (self->obj_testFlags30(0x10) != 0) {
        limit = 0x4000;
        n = registered_player_count + registered_enemy_count;
    } else {
        n = registered_player_count;
        limit = 0x1000;
    }
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && p != self &&
            get_entity_id(p) < limit && !(p->actorFlags & 0x02000800) &&
            p->select_melee_contact_body(self, 1.0f) != 0) {
            f32 damage = p->receive_physical_attack(self, 1.0f);
            p->apply_knockback_from_attacker((u8 *)self, damage);
        }
    }
}

#define F(t, o) (*(t *)(arg0 + (o)))

void TObjPlayer__sub_800A54B4(u8 *arg0) {
    *(s32 *)((s8 *)(F(u8 *, 0xA4)) + 0x18) |= 1;
    F(s32, 0x30) &= 0xF9FBFFFF;
    if (F(u16, 0x338) < 0x1000) {
        u8 *p = (u8 *)get_player_by_client_id(F(u16, 0x338));
        if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            F(u8 *, 0x2A8) = p;
        } else {
            F(u8 *, 0x2A8) = NULL;
        }
    } else if (F(u16, 0x338) < 0x4000) {
        F(u8 *, 0x2A8) = get_enemy_entity(F(u16, 0x338));
    } else {
        F(u16, 0x338) = 0xFFFF;
        F(u8 *, 0x2A8) = NULL;
    }
    switch (F(s16, 0x328)) {
    case 0:
        if (F(u8 *, 0x2A8) == NULL) {
            F(s16, 0x328) = 0;
            F(s32, 0x30) &= ~0x200000;
            F(s16, 0x33A) = 0;
        } else {
            Vec d;
            s32 a;
            VecCopy((Vec *)&d, (const Vec *)(F(u8 *, 0x2A8) + 0x2FC));
            subtract_vector(&d, arg0 + 0x2FC);
            a = ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((s8 *)(F(u8 *, 0x350)) + 8), (Vec *)&d);
            if (!(F(s32, 0x30) & 0x800000)) {
                apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
            }
            if (a < 0x10) {
                F(s16, 0x328) = 1;
                F(s16, 0xB8) = 2;
                ((TObjMotion *)arg0)->sub_800A7798(lbl_805D504C[0]);
                if (check_path_obstructed(arg0, F(u8 *, 0x2A8) + 0x2FC) == 1) {
                    F(f32, 0x308) = F(f32, 0x30C) = F(f32, 0x310) = 0.0f;
                } else {
                    calc_velocity_toward_destination(arg0, *(Vec *)(arg0 + 0x2FC), *(Vec *)(F(u8 *, 0x2A8) + 0x2FC), *(f32 *)((s8 *)(F(u8 *, 0x350)) + 4));
                }
            }
        }
        break;
    case 1:
        F(s16, 0xB8) = 2;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)12.0f) != 0) {
            F(s16, 0x328) = 2;
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0 + 0x38, 0, 0);
        }
        break;
    case 2:
        F(s16, 0xB8) = 2;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)16.0f) != 0) {
            TObjPlayer__sub_800A5960(arg0);
        }
        if (15.0f <= F(f32, 0xC0) && F(f32, 0xC0) <= 20.0f) {
            ((TObjEneSaver *)arg0)->apply_lookup_entry_effect();
        }
        if (((TObjMotion *)arg0)->is_passing_frame((f32)21.0f) != 0) {
            F(s16, 0x328) = 3;
        }
        break;
    case 3:
        F(s16, 0xB8) = 2;
        move_with_wall_slide(arg0);
        if (((TObjMotion *)arg0)->is_passing_frame((f32)32.0f) != 0) {
            F(s16, 0x328) = 4;
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0 + 0x38, 0, 0);
        }
        break;
    case 4:
        F(s16, 0xB8) = 2;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)37.0f) != 0) {
            TObjPlayer__sub_800A5960(arg0);
        }
        if (32.0f <= F(f32, 0xC0) && F(f32, 0xC0) <= 40.0f) {
            ((TObjEneSaver *)arg0)->apply_lookup_entry_effect();
        }
        if (((TObjMotion *)arg0)->is_passing_frame((f32)42.0f) != 0) {
            F(s16, 0x328) = 5;
        }
        break;
    case 5:
        F(s16, 0xB8) = 2;
        move_with_wall_slide(arg0);
        if (((TObjMotion *)arg0)->is_passing_frame((f32)52.0f) != 0) {
            F(s16, 0x328) = 6;
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0 + 0x38, 0, 0);
        }
        break;
    case 6:
        F(s16, 0xB8) = 2;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)54.0f) != 0) {
            TObjPlayer__sub_800A5960(arg0);
        }
        if (52.0f <= F(f32, 0xC0) && F(f32, 0xC0) <= 60.0f) {
            ((TObjEneSaver *)arg0)->apply_lookup_entry_effect();
        }
        if (F(u32, 0xB4) != 4) {
            F(s16, 0x328) = 7;
            F(s16, 0x33A) = lbl_805D504C[1];
        }
        break;
    case 7:
        if (--F(s16, 0x33A) < 0) {
            F(s16, 0x328) = 0;
            F(s32, 0x30) &= ~0x200000;
            F(s16, 0x33A) = 0;
        }
        break;
    }
    ((TObjMotion *)arg0)->advance_animation();
    step_angle_clamped(arg0, 0);
    ((TObjPlayer *)arg0)->check_object_collisions();
    check_enemy_body_collisions(arg0);
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
    submit_cursor_candidate(arg0, -1);
}

#undef F

