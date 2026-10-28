#include "types.h"
#include "pso/enemy/TObjEneBalClawBody.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneBalClawClaw.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneBalClaw.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/object/TObjFish.h"

struct Obj_8008E098 {
    u8 pad0[0x1C];
    u16 field1C;
    u8 pad1E[0x28 - 0x1E];
    s16 field28;
    u8 pad2A[0x3C4 - 0x2A];
    s32 ids[5];
    s16 count;
};

struct Vec_8008E18C { f32 x, y, z; };

struct Obj_8008E18C {
    u8 pad0[0x38];
    Vec_8008E18C pos;
    u8 pad44[0x60 - 0x44];
    s32 field60;
};

struct Vec_8008DD14 { f32 x, y, z; };

struct Info_8008DD14 { u8 pad0[4]; f32 f4; s32 f8; };

struct Obj_8008DD14 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    Vec_8008DD14 pos38;
    u8 pad44[0x50 - 0x44];
    Vec_8008DD14 home;
    u8 pad5C[0xB8 - 0x5C];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec_8008DD14 f290;
    Vec_8008DD14 f29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_8008DD14 pos;
    Vec_8008DD14 vel;
    u8 pad314[0x350 - 0x314];
    Info_8008DD14 *info;
    u8 pad354[0x37C - 0x354];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
};

struct Obj_8008DE9C {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0xB8 - 0x34];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec_8008DD14 f290;
    Vec_8008DD14 f29C;
    Obj_8008DE9C *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_8008DD14 pos;
    Vec_8008DD14 vel;
    u8 pad314[0x350 - 0x314];
    Info_8008DD14 *info;
    u8 pad354[0x37C - 0x354];
    s32 state;
};

struct Obj_8008E098;
struct P_8008E310 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x2FC - 0xC4];
    u8 f2FC[0x32C - 0x2FC];
    s16 f32C;
    u8 pad32E[0x33C - 0x32E];
    s16 f33C;
    u8 pad33E[0x37C - 0x33E];
    s32 state;
    u8 pad380[4];
    s32 timer;
    u32 flags;
    u8 pad38C[0x3C4 - 0x38C];
    s32 ids[4];
    s32 f3D4;
    s16 count;
    u8 pad3DA[2];
    u32 emit1;
    u32 emit2;
};

struct E_8008E310 { u8 pad[0x3C0]; f32 f3C0; };

struct Obj_8008E18C;
struct VBase_18_4841bb { char pad[0x18]; };

struct VObj_18_4841bb : VBase_18_4841bb {
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
    virtual s32 m53();
};

struct Self_8008E934 { u8 pad[0x3C4]; s32 ids[4]; };

extern "C" {
int update_if_active__15TObjEneMe1GiGueFl(void*, int);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
void enter_hit_state__18TObjEneBalClawClawFs(u32, u16);
u32 find_entity_by_id(u16);
extern s32 lbl_805D586C;
extern s32 lbl_805D5870;
s32 TObjPlayer__sub_8008E098(Obj_8008E098 *self);
void vec3_add_to(Vec_8008E18C *, Vec_8008E18C *);
void matrix_mult_vec(void *, Vec_8008E18C *, Vec_8008E18C *);
void set_matrix_identity(u8 *arg0);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
extern const f32 lbl_805D9620;
extern const f32 lbl_805D962C;
extern const f32 lbl_805D9630;
void calc_slot_offset_position__10TObjPlayerFPviPvPv(Obj_8008E18C *self, s32 slot, Vec_8008E18C *out, s32 *angle_out);
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 calc_velocity_toward_destination(void *, Vec_8008DD14, Vec_8008DD14, Info_8008DD14 *, f32);
s32 check_path_obstructed(void *, void *);
f32 xz_distance_squared(void *, void *);
s32 advance_animation_playback(void *);
extern const f32 lbl_805D961C;
void TObjPlayer__sub_8008DD14(Obj_8008DD14 *self);
s32 subtract_vector(void *, void *);
extern const f32 lbl_805D9624;
extern const f32 lbl_805D9628;
s16 get_actor_hp(u8 *p);
void queue_destruction__7TObjectFv(void *arg0);
void *spawn_particle_effect(void *pos, s32 id);
void *create_particle_emitter(void *pos, s32 id);
s32 play_sound_effect(int, void *, int, int);
extern const f32 lbl_805D9634;
extern const f32 lbl_805D9638;
void TObjPlayer__sub_8008E310(P_8008E310 *arg0);
void TObjPlayer__sub_8008E254(void *arg0);
s32 TObjEneBalClawClaw__sub_8008DC90(void *);
void TObjEneBalClawClaw__sub_80090A10(u8 *arg0, u8 *arg1, s32 arg2, s16 arg3);
void *create__18TObjEneBalClawClawFPvPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5);
u8 *get_enemy_entity(u16);
extern u8 player_attack_param_table[];
void TObjPlayer__sub_8008E934(void *arg0_, s32 arg1);
struct VBase18_8008e74c_8008DCF0 { char pad[0x18]; };
struct VObj18_8008e74c_8008DCF0 : VBase18_8008e74c_8008DCF0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual s32 m9(f32, f32, f32);
};
struct VObj390_8008e74c_8008DCF0 { char pad[0x14]; };
struct VObj390V_8008e74c_8008DCF0 : VObj390_8008e74c_8008DCF0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7(); virtual s32 m8();
};

s32 post_translate_matrix(void *);
s32 rotate_matrix_x(s32, s32);
void draw_chunk_object(void *child);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 defer_render__7TObjectFv(void *);

int TObjPlayer::reset_enemy_state() { return update_if_active__15TObjEneMe1GiGueFl(this, 0); }

extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D963C;
extern const f32 lbl_805D9640;

void TObjPlayer__sub_8008DD14(Obj_8008DD14 *self) {
    s16 mode;
    switch (self->state) {
    case 0:
        self->f30 &= 0xFFFBFEFF;
        mode = 6;
        if (self->f388 & 0x01000000) {
            mode = 1;
        }
        self->fB8 = mode;
        self->state = 1;
        VecCopy((Vec *)&self->f29C, (const Vec *)&self->home);
        break;
    case 1: {
        self->vel.y = lbl_805D9620;
        VecCopy((Vec *)&self->f290, (const Vec *)&self->pos);
        calc_velocity_toward_destination(self, self->f290, self->f29C, self->info, self->info->f4);
        ((TObjPlayer *)self)->update_angle(self->info->f8, &self->vel);
        Vec_8008DD14 v = self->pos;
        v.x += self->vel.x;
        v.z += self->vel.z;
        if (check_path_obstructed(self, &v) == 0) {
            move_with_wall_slide((u8 *)self);
        }
        if (xz_distance_squared(&self->pos38, &self->home) < lbl_805D961C) {
            ((TObjPlayer *)self)->reset_enemy_state();
        }
        advance_animation_playback(self);
        apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), lbl_805D9620);
        break;
    }
    case -1:
        break;
    }
}

void TObjPlayer::update_move_to_target() {
    Obj_8008DE9C *self = (Obj_8008DE9C *)this;
    switch (self->state) {
    case -1:
        break;
    case 0: {
        self->f30 &= ~0x100;
        self->fB8 = ((TObjPlayer *)self)->get_flag_0x388_b24() != 0 ? 1 : 6;
        Vec_8008DD14 d = self->pos;
        subtract_vector(&d, &self->target->pos);
        ((TObjEnemyCustom *)self)->pick_open_direction((f32 *)&d, (f32)lbl_805D9624, (f32)lbl_805D9628);
        self->state = 1;
        break;
    }
    case 1: {
        if (self->target == NULL) {
            reset_enemy_state();
            break;
        }
        if (this->is_actor_cadence_frame(0x5A) != 0) {
            Vec_8008DD14 d2 = self->pos;
            subtract_vector(&d2, &self->target->pos);
            ((TObjEnemyCustom *)self)->pick_open_direction((f32 *)&d2, (f32)lbl_805D9624, (f32)lbl_805D9628);
        }
        VecCopy((Vec *)&self->f290, (const Vec *)&self->pos);
        calc_velocity_toward_destination(self, self->f290, self->f29C, self->info, self->info->f4);
        ((TObjPlayer *)self)->update_angle(self->info->f8, &self->vel);
        Vec_8008DD14 v = self->pos;
        v.x += self->vel.x;
        v.z += self->vel.z;
        if (check_path_obstructed(self, &v) == 0) {
            move_with_wall_slide((u8 *)self);
        }
        advance_animation_playback(self);
        apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), lbl_805D9620);
        ((TObjPlayer *)self)->update_collisions();
        break;
    }
    }
}

s32 TObjPlayer__sub_8008E098(Obj_8008E098 *self) {
    s32 i;
    Obj_8008E098 *p;
    s32 j;
    self->count = 0;
    for (i = lbl_805D586C; i < lbl_805D586C + lbl_805D5870; i++) {
        p = (Obj_8008E098 *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && ((TWindowLockOn *)p)->get_target_id() == 0x26 &&
            self->field28 == p->field28 && ((TObjEneBalClawClaw *)p)->check_active() != 0) {
            self->ids[self->count++] = get_entity_id(p);
            if (self->count >= 4) {
                break;
            }
        }
    }
    for (j = 0; j < self->count; j++) {
        enter_hit_state__18TObjEneBalClawClawFs(find_entity_by_id(self->ids[j]), self->field1C);
    }
    return self->count;
}

void calc_slot_offset_position__10TObjPlayerFPviPvPv(Obj_8008E18C *self, s32 slot, Vec_8008E18C *out, s32 *angle_out) {
    s32 angle;
    push_matrix();
    angle = (s32)(lbl_805D962C * (f32)(slot * 0x5A + 0x2D));
    *angle_out = self->field60 + angle;
    out->x = lbl_805D9620;
    out->y = lbl_805D9620;
    out->z = lbl_805D9630;
    set_matrix_identity(0);
    rotate_matrix_y(0, angle);
    matrix_mult_vec(0, out, out);
    vec3_add_to(out, &self->pos);
    pop_matrix();
}

void TObjPlayer__sub_8008E254(void *arg0_) {
    switch (((TObjPlayer *)arg0_)->m_37c) {
    case -1:
        break;
    case 0:
        if (((TObjPlayer *)arg0_)->get_flag_0x388_b24() == 0) {
            ((TObjPlayer *)arg0_)->reset_enemy_state();
            return;
        }
        *(s32 *)((s8 *)arg0_ + 0x3D4) = 0;
        TObjPlayer__sub_8008E934(arg0_, 0);
        *(s16 *)((s8 *)arg0_ + 0x33C) = 0x1E;
        ((TObjPlayer *)arg0_)->m_37c = 1;
        return;
    case 1:
        advance_animation_playback(arg0_);
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0_), (s32 *)(0), lbl_805D9620);
        (*(s16 *)((s8 *)arg0_ + 0x33C))--;
        if (*(s16 *)((s8 *)arg0_ + 0x33C) <= 0) {
            ((TObjPlayer *)arg0_)->reset_enemy_state();
        }
        return;
    }
}

void TObjPlayer__sub_8008E310(P_8008E310 *arg0_) {
    s32 all;
    s32 cnt;
    E_8008E310 *e;
    f32 lim;
    switch (arg0_->state) {
    case 0:
        if (((TObjPlayer *)arg0_)->get_flag_0x388_b24() != 0) {
            ((TObjPlayer *)arg0_)->reset_enemy_state();
            return;
        }
        arg0_->f3D4 = 0;
        if (TObjPlayer__sub_8008E098((Obj_8008E098 *)arg0_) == 0) {
            ((TObjPlayer *)arg0_)->reset_enemy_state();
            return;
        }
        arg0_->flags |= 1;
        arg0_->flags &= ~0x04020000;
        arg0_->timer = 0x258;
        arg0_->state = 1;
        arg0_->fB8 = 5;
        arg0_->emit1 = (u32)create_particle_emitter(arg0_->f2FC, 0x128);
        break;
    case 1:
        ((TNowLoading *)(arg0_->emit1))->copy_pos(arg0_->f2FC);
        advance_animation_playback(arg0_);
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0_), (s32 *)(0), lbl_805D9620);
        all = 1;
        cnt = 0;
        lim = lbl_805D9634;
        for (s32 i = 0; i < arg0_->count; i++) {
            e = (E_8008E310 *)find_entity_by_id(arg0_->ids[i]);
            if (e != NULL) {
                cnt++;
                if (e->f3C0 > lim) {
                    all = 0;
                }
            } else {
                arg0_->ids[i] = 0xFFFF;
            }
        }
        if (--arg0_->timer <= 0 || cnt == 0) {
            arg0_->flags &= ~1;
            ((TObjPlayer *)arg0_)->reset_enemy_state();
            return;
        }
        if (all == 1) {
            for (s32 i = 0; i < arg0_->count; i++) {
                E_8008E310 *e2 = (E_8008E310 *)find_entity_by_id(arg0_->ids[i]);
                if (e2 != NULL) {
                    ((TObjEneBalClawClaw *)e2)->set_claw_flags();
                    arg0_->f32C += get_actor_hp((u8 *)e2);
                }
            }
            arg0_->emit2 = (u32)create_particle_emitter(arg0_->f2FC, 0x12A);
            ((TParticleCtrl *)(arg0_->emit2))->enable();
            arg0_->fB8 = 0xB;
            arg0_->flags |= 0x04000000;
            arg0_->state = 2;
        }
        break;
    case 2:
        ((TNowLoading *)(arg0_->emit1))->copy_pos(arg0_->f2FC);
        advance_animation_playback(arg0_);
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0_), (s32 *)(0), lbl_805D9620);
        if (arg0_->fC0 < lbl_805D9638) {
            ((TParticleCtrl *)(arg0_->emit2))->enable();
        } else {
            ((TParticleCtrl *)(arg0_->emit2))->clear_active_flag();
            ((TNowLoading *)(arg0_->emit2))->copy_pos(arg0_->f2FC);
        }
        if (arg0_->fB8 != 0xB) {
            queue_destruction__7TObjectFv((void *)arg0_->emit1);
            arg0_->emit1 = 0;
            spawn_particle_effect(arg0_->f2FC, 0x129);
            TObjPlayer__sub_8008E934(arg0_, 1);
            advance_animation_playback(arg0_);
            arg0_->flags &= ~0x04000000;
            arg0_->f33C = 0x1E;
            arg0_->state = 3;
            play_sound_effect(0x4003AD30, arg0_->pos, 0, 0);
        }
        break;
    case 3:
        ((TNowLoading *)(arg0_->emit2))->copy_pos(arg0_->f2FC);
        advance_animation_playback(arg0_);
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0_), (s32 *)(0), lbl_805D9620);
        if (--arg0_->f33C <= 0) {
            arg0_->flags &= ~1;
            ((TObjPlayer *)arg0_)->reset_enemy_state();
        }
        break;
    case -1:
        if (arg0_->flags & 0x04000000) {
            TObjPlayer__sub_8008E934(arg0_, 1);
            advance_animation_playback(arg0_);
        }
        if (((TObjPlayer *)arg0_)->get_flag_0x388_b24() == 0) {
            for (s32 i = 0; i < arg0_->count; i++) {
                e = (E_8008E310 *)find_entity_by_id(arg0_->ids[i]);
                if (e != NULL) {
                    ((TObjEneBalClawClaw *)e)->clear_flag();
                }
            }
        }
        arg0_->flags |= 0x20000;
        if (arg0_->emit1 != 0) {
            queue_destruction__7TObjectFv((void *)arg0_->emit1);
            arg0_->emit1 = 0;
        }
        if (arg0_->emit2 != 0) {
            queue_destruction__7TObjectFv((void *)arg0_->emit2);
            arg0_->emit2 = 0;
        }
        break;
    }
}

void TObjPlayer::update_me1_gigue_state() {
    update_if_active__15TObjEneMe1GiGueFl(this, (int)(get_flag_0x388_b24() ? 9 : 2));
}

void TObjEneBalClawBody::render() {
    s32 var_r30;
    s32 temp_r3;
    s32 var_r29;
    u8 *arg0 = (u8 *)this;

    if (!(((TObjEneBalClawBody *)arg0)->actorFlags & 0x02000000)) {
        saved_model_render_flags = model_render_flags;
        temp_r3 = ((VObj18_8008e74c_8008DCF0*)arg0)->m9(lbl_805D963C, lbl_805D9640, lbl_805D9628);
        if (temp_r3 != 0) {
            var_r30 = 1;
            TObjFish::set_global_param(((TObjEneBalClawBody *)arg0)->texture_id);
            select_actor_lighting((s32)arg0);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                TObjPlayer::set_visibility_flags_by_count(arg0, 4);
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_x(0, *(s32 *)((s8 *)arg0 + 0x5C));
                rotate_matrix_y(0, ((TObjEneBalClawBody *)arg0)->rotation_y);
                draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
            } else {
                TObjPlayer::set_visibility_flags_by_count(arg0, ((TObjEneBalClawBody *)arg0)->m_3d8);
                translate_matrix(0, lbl_805D9620, ((TObjEneBalClawBody *)arg0)->m_3b4 + *(f32 *)((s8 *)arg0 + 0x3BC), lbl_805D9620);
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_x(0, *(s32 *)((s8 *)arg0 + 0x5C));
                rotate_matrix_y(0, ((TObjEneBalClawBody *)arg0)->rotation_y);
                if (((TObjEneBalClawBody *)arg0)->m_388 & 4) {
                    if (((VObj390V_8008e74c_8008DCF0*)(arg0 + 0x390))->m8() != 0) {
                        ((VObj390V_8008e74c_8008DCF0*)(arg0 + 0x390))->m6();
                        var_r29 = 1;
                        if (defer_render__7TObjectFv(arg0) != 0) {
                            var_r29 = 0;
                        }
                        if (var_r29 != 0) {
                            if (temp_r3 == 1) {
                                ((TObjMotion *)arg0)->draw();
                            } else {
                                ((TObjEnemy *)arg0)->render_world_model();
                            }
                        }
                        ((VObj390V_8008e74c_8008DCF0*)(arg0 + 0x390))->m7();
                    } else {
                        var_r30 = 0;
                    }
                } else if (temp_r3 == 1) {
                    ((TObjMotion *)arg0)->draw();
                } else {
                    ((TObjEnemy *)arg0)->render_world_model();
                }
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            model_render_flags = saved_model_render_flags;
            ((TObjEneBalClaw *)arg0)->render_scaled(var_r30);
        }
    }
}
#pragma push
#pragma opt_propagation off
#define arg0 ((u8 *)arg0_)
void TObjPlayer__sub_8008E934(void *arg0_, s32 arg1) {
    Vec_8008E18C a;
    Vec_8008E18C b;
    s32 angA;
    s32 angB;
    s32 i;
    s32 id;
    s32 id2;
    s32 n;
    s32 k;
    u8 *ent;
    s32 j;
    if (arg1 == 1) {
        *(u32 *)((s8 *)arg0 + 0x388) |= 0x01000000;
        ((TObjEnemy *)arg0)->set_param(0x28);
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((TObjEneBalClawClaw *)arg0)->sub_80090418(1);
        *(s16 *)((s8 *)arg0 + 0x3DA) = 0;
        ((VObj_18_4841bb *)(arg0))->m53();
    } else {
        *(u32 *)((s8 *)arg0 + 0x388) &= ~0x01000000;
        ((TObjEnemy *)arg0)->set_param(0x27);
        *(s16 *)((s8 *)arg0 + 0xB8) = 5;
        ((TObjEneBalClawClaw *)arg0)->sub_80090418(0);
        ((VObj_18_4841bb *)(arg0))->m53();
        if (!(*(u32 *)((s8 *)arg0 + 0x388) & 0x40000)) {
            *(s16 *)((s8 *)arg0 + 0x32C) = *(s16 *)((s8 *)arg0 + 0x32C) / (*(s16 *)((s8 *)arg0 + 0x3D8) + 1);
            if (*(s16 *)((s8 *)arg0 + 0x32C) <= 0) {
                *(s16 *)((s8 *)arg0 + 0x32C) = 1;
            }
            *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
            if (*(u32 *)((s8 *)arg0 + 0x80) != 0) {
                *(u32 *)((s8 *)arg0 + 0x388) |= 0x40000;
                for (i = 0; i < 4; i++) {
                    id = *(u16 *)((s8 *)arg0 + 0x1C) + i;
                    id2 = *(s16 *)((s8 *)arg0 + 0x2C) + i;
                    id++;
                    id2++;
                    calc_slot_offset_position__10TObjPlayerFPviPvPv((Obj_8008E18C *)arg0, i, &a, &angA);
                    ((void *(*)(void *, u16, void *, void *, void *, void *))create__18TObjEneBalClawClawFPvPvPvPvPv)(arg0, id, (void *)id2, &a, (void *)angA, (void *)*(s16 *)((s8 *)arg0 + 0x32C));
                }
            }
        } else {
            n = 0;
            for (k = 0; k < *(s16 *)((s8 *)arg0 + 0x3D8); k++) {
                ent = get_enemy_entity(((Self_8008E934 *)arg0)->ids[k]);
                if (ent != NULL) {
                    calc_slot_offset_position__10TObjPlayerFPviPvPv((Obj_8008E18C *)arg0, k, &b, &angB);
                    TObjEneBalClawClaw__sub_80090A10(ent, (u8 *)&b, angB, *(s16 *)((s8 *)arg0 + 0x32C));
                    n++;
                }
            }
            if (n > 0) {
                *(s16 *)((s8 *)arg0 + 0x32C) = *(s16 *)((s8 *)arg0 + 0x32C) / (n + 1);
                for (j = 0; j < *(s16 *)((s8 *)arg0 + 0x3D8); j++) {
                    if ((ent = get_enemy_entity(((Self_8008E934 *)arg0)->ids[j])) != NULL) {
                        ((TObjPlayer *)ent)->set_hp_clamped(*(s16 *)((s8 *)arg0 + 0x32C));
                    }
                }
            }
        }
        *(s16 *)((s8 *)arg0 + 0x3D8) = 0;
    }
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    *(u8 **)((s8 *)arg0 + 0x350) = player_attack_param_table + arg1 * 0x1C;
    TObjEneBalClawClaw__sub_8008DC90(arg0);
    *(s32 *)((s8 *)arg0 + 0x368) = arg1;
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
}
}
#undef arg0
#pragma pop
