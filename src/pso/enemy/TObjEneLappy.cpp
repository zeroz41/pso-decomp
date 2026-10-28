#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/enemy/TObjEneRe2Flower.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneLappy.h"
extern "C" void test_flag_256__12TObjEneLappyFv();
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TLobby.h"
extern "C" __declspec(section ".data") s32 lappy_variant_speed_ptr_table[2];
#define lappy_variant_speed_ptr_table ((f32 * *)lappy_variant_speed_ptr_table)
extern "C" void * rappy_variant_speed_table[40];

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define VA virtual void CAT(f,__LINE__)();
struct Base_800C00F4_800BFBBC { char pad[0x18]; };

struct VObj_800C00F4_800BFBBC : Base_800C00F4_800BFBBC {
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
    virtual void m48();
};

struct VBase_18_ca64a0 { char pad[0x18]; };

struct VObj_18_ca64a0 : VBase_18_ca64a0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

#include <stddef.h>
struct VPad18 { char pad[0x18]; };

struct VCls18 : VPad18 {
    virtual s32 vm0();
    virtual s32 vm1();
    virtual s32 vm2();
    virtual s32 vm3();
    virtual s32 vm4();
    virtual s32 vm5();
    virtual s32 vm6();
    virtual s32 vm7();
    virtual s32 vm8();
    virtual s32 vm9();
    virtual s32 vm10();
    virtual s32 vm11();
    virtual s32 vm12();
    virtual s32 vm13();
    virtual s32 vm14();
    virtual s32 vm15();
    virtual s32 vm16();
    virtual s32 vm17(s32, s16);
};

struct RecoveredFields_800C1478_arg0 {
    u8 unknown_0[0x30];
    s32 field_30;
    u8 unknown_34[0x70];
    void * field_A4;
    u8 unknown_A8[0x10];
    s16 field_B8;
    u8 unknown_BA[0x1EE];
    void * field_2A8;
    u8 unknown_2AC[0x60];
    f32 field_30C;
    u8 unknown_310[0x16];
    s16 field_326;
    u8 unknown_328[0x10];
    u16 field_338;
    u8 unknown_33A[0x3A];
    s16 field_374;
    u8 unknown_376[0xA];
    s16 field_380;
};

struct RecoveredFields_800C1478_temp_r3 {
    u8 unknown_0[0x30];
    s32 field_30;
};

struct RecoveredFields_800C1478_temp_r3_2 {
    u8 unknown_0[0x18];
    s32 field_18;
};

struct Sub_800BFCD4 { u8 pad[0xc]; f32 fc; };

struct Obj_800BFCD4 { u8 pad[0xa4]; Sub_800BFCD4 *fa4; u8 pad2[0x368 - 0xa8]; s32 f368; };

struct G_800BFCD4 { u8 pad[0x68]; f32 f68; u8 pad2[0x1c]; f32 f88; };

struct Vec_800C1224 { f32 x, y, z; };

struct VBase_18_800C0588 { char pad[0x18]; };

struct VObj_18_800C0588 : VBase_18_800C0588 {
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
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
    virtual s32 m57();
};

struct Sp800C0D3C { s32 a; s32 b; s32 c; };

struct Vec_800C1144 { f32 x, y, z; };

struct Position_800C08A0 { f32 x, y, z; };

struct VBase_18_800C0E30 { char pad[0x18]; };
struct VObj_18_800C0E30 : VBase_18_800C0E30 {
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
    virtual s32 m17(int);
};

struct Vec_800C0E30 { s32 x, y, z; };

struct Vec_800C0318 { f32 x, y, z; };

struct Lappy_800C0318 { u8 pad0[0x2FC]; Vec_800C0318 pos; f32 vx; f32 vy; f32 vz; };

extern const f32 lbl_805D9F24;
extern const f32 lbl_805D9F28;
extern const f32 lbl_805D9F2C;
extern const f32 lbl_805D9F30;
extern const f32 lbl_805D9F34;
extern const f32 lbl_805D9F38;
extern const f32 lbl_805D9F3C;
extern const f32 lbl_805D9F40;
extern const f32 lbl_805D9F44;
extern const f32 lbl_805D9F48;
extern const f32 lbl_805D9F4C;
extern const f32 lbl_805D9F50;
extern const f32 lbl_805D9F54;
extern const f32 lbl_805D9F58;
extern const f32 lbl_805D9F5C;
extern const f32 lbl_805D9F60;
extern const f32 lbl_805D9F64;
extern const f32 lbl_805D9F68;
extern const f32 lbl_805D9F6C;
extern const f32 lbl_805D9F70;
extern const f32 lbl_805D9F74;
extern const f32 lbl_805D9F78;
extern const f32 lbl_805D9F7C;
extern const f32 lbl_805D9F80;
extern const f32 lbl_805D9F84;
extern const f32 lbl_805D9F88;
extern const f32 lbl_805D9F8C;
extern const f32 lbl_805D9F90;
extern const f32 lbl_805D9F94;
extern const f32 lbl_805D9F98;
extern const f32 lbl_805D9F9C;

extern "C" {
s32 remap_area_sound_id(s32, s32);
f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 apply_actor_gravity(void *, s32, f32);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
void sub_800C20B0__12TObjEneLappyFv(void *arg0);
#define sub_800C20B0__12TObjEneLappyFv (*(s32 (*)())&sub_800C20B0__12TObjEneLappyFv)
s32 play_sound_effect(s32, u32, s32, s32);
void vfunc_63__12TObjEneLappyFv(u8 *arg0);
void *get_player_by_client_id(s32 i);
void vfunc_62__12TObjEneLappyFv(u8 *arg0);
void vfunc_61__12TObjEneLappyFv(void *arg0);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, s32);
void vfunc_60__12TObjEneLappyFv(void *arg0);
s32 TObjEneDD__sub_800B9B24(f32);
void set_speed_params__12TObjEneLappyFl(void *arg0, s32 arg1);
#define set_speed_params__12TObjEneLappyFl (*(s32 (*)(void *, int))&set_speed_params__12TObjEneLappyFl)
s32 toggle_particle_effect__10TObjPlayerFv();
s32 is_item_light_interaction_blocked();
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 render_world_model__9TObjEnemyFv(void *);
s32 draw__10TObjMotionFv(void *);
s32 end_effect_render__13TParticleCtrlFv();
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
f32 post_translate_matrix(void *);
s32 set_global_param__8TObjFishFl(int);
s32 draw_chunk_object(int);
extern s32 *rappy_visibility_node;
extern s32 model_render_flags;
void render__12TObjEneLappyFv(u8 *arg0);
u16 find_nearest_visible_player(void *, int, f32);
void TObjPlayer__sub_800BFF54(void * _w0);
void sub_800C20C0__12TObjEneLappyFv(void *arg0);
#define sub_800C20C0__12TObjEneLappyFv (*(s32 (*)())&sub_800C20C0__12TObjEneLappyFv)
u8 *find_active_entity_by_id(u16);
s32 submit_cursor_candidate(void *, int);
s32 minimap_render_dot(void *, int, int, int);
void run_task__12TObjEneLappyFv(u8 *arg0);
s32 advance_animation_playback(void *);
void apply_variant_speeds__12TObjEneLappyFv(Obj_800BFCD4 *self);
s32 check_path_obstructed(void *, void *);
int get_player_data__10TObjPlayerFi(int a0);
s32 obj_getField1c(void *);
s32 subtract_vector(void *, void *);
extern s32 lappy_target_zero_vec[];
extern s32 lbl_805D586C;
extern s32 lbl_805D5870;
void vfunc_28__12TObjEneLappyFv(u8 *arg0);
u32 csnVector(void *, void *, s32);
s32 project_actor_to_ground(void *, void *, s32);
s32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(s32, void *, void *);
s32 push_matrix_from(void *);
s32 pop_matrices(s32);
extern f32 identity_matrix[3][4];
s32 enemy_set_heading_velocity(void *, int, f32);
s32 enemy_turn_toward_dest(void *, void *);
s32 select_enemy_destination(void *, struct Sp800C0D3C *, s32);
void vfunc_59__12TObjEneLappyFv(void *arg0);
void vfunc_58__12TObjEneLappyFv(void *arg0);
s32 enemy_backstep_from_point(void *, void *, f32);
s32 enemy_wander_home__9TObjEnemyFlfff(void *, int, f32, f32, f32);
f32 update_enemy_wander_move(void *, void *, int, f32);
f64 atan2_float(f32, f32);
s32 queue_destruction__7TObjectFv(void *);
s32 spawn_particle_effect(void *, int);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, int);
s32 angle_difference_abs(int, int);
s32 lerp_angle_half__10TObjPlayerFUsUs(int, int);
s32 play_persistent_sound(s32, void *, void *, int, int);
extern const f64 lbl_8043BA18;
s32 update_action_hold_status__12TObjEneLappyFv(s32 arg0);
s32 update_movement_status__12TObjEneLappyFv(s32 arg0);
s32 update_movement_status__13TUnk_804806E8Fv();
s32 update_action_hold_status__13TUnk_804806E8Fv();
s32 obj_setFlags30(void *, s32);
s32 send_entity_set_flags__9TObjEnemyFv();

void TObjEneLappy::clear_flags_60() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r4;

    temp_r4 = *(s16 *)((s8 *)arg0 + 0x374);
    if (temp_r4 & 0x60) {
        *(s16 *)((s8 *)arg0 + 0x374) = (s16) (temp_r4 & 0xFFFFFF9F);
        project_actor_to_ground(arg0, arg0 + 0x38, 0);
        obj_setFlags30(arg0, 0x800000);
    }
}

s32 TObjEneLappy::update_movement_status() {
    s32 arg0 = (s32)this;
    if (update_movement_status__13TUnk_804806E8Fv() != 0) {
        ((TObjEneLappy *)arg0)->clear_flags_60();
        return 1;
    }
    return 0;
}

s32 TObjEneLappy::update_action_hold_status() {
    s32 arg0 = (s32)this;
    if (update_action_hold_status__13TUnk_804806E8Fv() != 0) {
        ((TObjEneLappy *)arg0)->clear_flags_60();
        return 1;
    }
    return 0;
}

void TObjPlayer::set_flag_and_notify() {
    s16 temp_r4;

    temp_r4 = *(s16 *)((s8 *)this + 0x374);
    if (!(temp_r4 & 0x80)) {
        *(s16 *)((s8 *)this + 0x374) = (s16) (temp_r4 | 0x80);
        send_entity_set_flags__9TObjEnemyFv();
    }
}

void TObjEneLappy::apply_variant_speeds() {
    Obj_800BFCD4 *self = (Obj_800BFCD4 *)this;
    f32 *p;
    if (self->f368 >= 2) {
        return;
    }
    self->fa4->fc = lappy_variant_speed_ptr_table[self->f368][0];
    p = lappy_variant_speed_ptr_table[self->f368];
    (*(G_800BFCD4 *)&rappy_variant_speed_table).f68 = p[1];
    (*(G_800BFCD4 *)&rappy_variant_speed_table).f88 = p[2];
}

s32 TObjEneLappy::advance_flee_step() {
    TObjEneLappy *arg0 = this;
    LappyVec sp20;
    LappyVec sp14;
    LappyVec sp8;
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;
    VecCopy((Vec *)((LappyVec *)&arg0->m_44), (const Vec *)&arg0->position);
    VecCopy((Vec *)&sp20, (const Vec *)((LappyVec *)&arg0->m_2fc));
    vec3_add_to(&sp20, (LappyVec *)&arg0->unk_308);
    if (arg0->is_actor_cadence_frame(0x1E) != 0) {
        if (csnVector((LappyVec *)&arg0->m_2fc, &sp20, -1) != 0U) {
            return 0;
        }
        if (calc_boss4_scale__10TObjPlayerFi(arg0) < lbl_805D9F24) {
            var_r30 = -1;
        } else {
            var_r30 = 1;
        }
        var_r29 = 0;
        var_r31 = 0;
loop_7:
        if (var_r29 == 0) {
            VecCopy((Vec *)&sp14, (const Vec *)((LappyVec *)&arg0->unk_308));
        } else {
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, (int)(var_r30 * var_r31));
            rotate_vector_by_matrix(0, (LappyVec *)&arg0->unk_308, &sp14);
            pop_matrices(1);
        }
        VecCopy((Vec *)&sp8, (const Vec *)&arg0->position);
        vec3_add_to(&sp8, &sp14);
        if (((s32)project_actor_to_ground(arg0, &sp8, 0)) == 1) {
            VecCopy((Vec *)&arg0->position, (const Vec *)&sp8);
            VecCopy((Vec *)((LappyVec *)&arg0->unk_308), (const Vec *)&arg0->position);
            subtract_vector((LappyVec *)&arg0->unk_308, (LappyVec *)&arg0->m_44);
            return 1;
        }
        var_r29 += 1;
        var_r31 += 0x1000;
        if (var_r29 >= 0xF) {
            return 0;
        }
        goto loop_7;
    }
    if (((s32)project_actor_to_ground(arg0, &sp20, 0)) == 1) {
        VecCopy((Vec *)((LappyVec *)&arg0->position), (const Vec *)&sp20);
        VecCopy((Vec *)((LappyVec *)&arg0->unk_308), (const Vec *)((LappyVec *)&arg0->position));
        subtract_vector((LappyVec *)&arg0->unk_308, (LappyVec *)&arg0->m_44);
        return 1;
    }
    return 0;
}

void TObjEneLappy::play_walk_sound() {
    u8 *arg0 = (u8 *)this;
    if (((s16) this->m_b8 == 3) && ((objInBand((GameObj *)arg0, (f32)lbl_805D9F28) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D9F2C)) != 0))) {
        play_sound_effect(remap_area_sound_id(0x3D20C, 5), (u32)(arg0 + 0x38), 0, 0);
    }
}
void TObjPlayer__sub_800BFF54(void * _w0) {  }

void TObjEneLappy::render() {
    s32 temp_r3;
    if (obj_testFlags30__13TUnk_804AF8A0FUl(this, 0x02000000) == 0) {
        if (this->m_374 & 1) {
            *rappy_visibility_node &= 0xFFFFFFF7;
        } else {
            *rappy_visibility_node |= 8;
        }
        temp_r3 = ((VObj_18_ca64a0 *)(this))->m9(lbl_805D9F30, lbl_805D9F34, lbl_805D9F28);
        if (temp_r3 != 0) {
            set_speed_params__12TObjEneLappyFl(this, this->variant);
            set_global_param__8TObjFishFl(this->texture_id);
            select_actor_lighting(this);
            toggle_particle_effect__10TObjPlayerFv();
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            rotate_matrix_y(0, this->rotation_y);
            if (this->m_374 & 0x400) {
                scale_matrix(0, lbl_805D9F38, lbl_805D9F3C, lbl_805D9F38);
                TObjEneDD__sub_800B9B24(lbl_805D9F40);
            }
            model_render_flags &= 0xFFFFFBFF;
            TObjPlayer::set_global_flag();
            if (is_item_light_interaction_blocked() == 1) {
                draw_chunk_object((int) (*(s32 *)((s8 *)((u8 *)this) + 0x34)));
            } else {
                model_render_flags |= 0x01000000;
                if (temp_r3 == 1) {
                    draw__10TObjMotionFv(this);
                } else {
                    render_world_model__9TObjEnemyFv(this);
                }
                model_render_flags &= 0xFEFFFFFF;
            }
            TObjPlayer::clear_global_state();
            if (this->m_374 & 0x400) {
                TObjEneDD::init_lights();
            }
            pop_matrix();
            restore_scene_lighting();
            end_effect_render__13TParticleCtrlFv();
            if (!(this->actorFlags & 0x800) && (obj_testFlags30__13TUnk_804AF8A0FUl(this, 0x800000) != 0)) {
                this->render_with_position_override(0, 0);
            }
        }
    }
}

void TObjEneLappy::set_boss4_state() {
    s16 temp_r4;
    temp_r4 = this->m_374;
    if (!(temp_r4 & 2)) {
        this->m_374 = (temp_r4 | 2);
        *(s16 *)((s8 *)this + 0x394) = 0;
        this->m_390 = (s32) (lbl_805D9F44 * (lbl_805D9F48 * calc_boss4_scale__10TObjPlayerFi(this)));
    }
    this->mode = 1;
    this->m_37a = 3;
    ((struct VObj_800C00F4_800BFBBC *)this)->m48();
    this->hp = 1;
    this->actorFlags = (s32) (this->actorFlags & ~0xA00);
}
s32 TObjEneLappy::apply_move_friction() {
    sub_800C20B0__12TObjEneLappyFv();
    advance_animation_playback(this);
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(this, 0, lbl_805D9F4C);
    }
    refresh_collision_body_centers();
    if (this->m_c0 < (lbl_805D9F24 * (lbl_805D9F2C * this->m_c8))) {
        move_with_wall_slide((u8 *)this);
        *(f32 *)((s8 *)this + 0x308) = (f32) (*(f32 *)((s8 *)this + 0x308) * lbl_805D9F24);
        this->m_310 = (f32) (this->m_310 * lbl_805D9F24);
    }
}
void TObjEneLappy::vfunc_63() {
    s16 temp_r3;
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    temp_r3 = this->m_374;
    if (temp_r3 & 2) {
        if (!(temp_r3 & 4)) {
            this->m_374 = (s16) (temp_r3 | 4);
            play_sound_effect((s32)(((s32)remap_area_sound_id(0x3AD13, 5))), (u32)(((u8 *)this) + 0x38), 0, 0);
            ((TObjPlayer *)((u8 *)this))->query_lobby_state();
            this->m_b8 = 8;
        }
    } else if ((s16) this->mode != 5) {
        this->mode = 5;
        this->m_b8 = 7;
        if (!(this->m_374 & 0x10)) {
            play_sound_effect((s32)(((s32)remap_area_sound_id(0x3AE10, 5))), (u32)(((u8 *)this) + 0x38), 0, 0);
            this->distribute_experience();
            ((TObjPlayer *)((u8 *)this))->set_flag_and_notify();
        }
        this->m_380 = 0;
    }
}

void TObjEneLappy::update_hurt() {
    u8 *arg0 = (u8 *)this;
    advance_animation_playback(arg0);
    Lappy_800C0318 *self = (Lappy_800C0318 *)arg0;
    Vec_800C0318 v = self->pos;
    v.x += self->vx;
    v.z += self->vz;
    if (check_path_obstructed(arg0, &v) == 0) {
        move_with_wall_slide(arg0);
    } else {
        self->vx = self->vz = lbl_805D9F4C;
    }
    self->vx *= lbl_805D9F24;
    self->vz *= lbl_805D9F24;
    apply_actor_gravity(arg0, 0, lbl_805D9F4C);
    ((TObjPlayer *)arg0)->update_collisions();
    if (this->m_b4 != 8U) {
        this->actorFlags &= ~0x200;
        this->referenceHp = this->hp;
        if (this->m_374 & 2) {
            ((TObjEneLappy *)arg0)->set_boss4_state();
            this->m_b8 = 4;
        }
    }
}

void TObjEneLappy::vfunc_62() {
    s32 temp_r3;
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    if (this->m_374 & 2) {
        this->obj_clearFlags30(0x23F);
        return;
    }
    if ((s16) this->mode != 4) {
        this->mode = 4;
        this->m_b8 = 6;
        temp_r3 = (s32)get_player_by_client_id(this->m_2d4);
        if ((temp_r3 != 0) && !(xyz_distance_squared((Vec *)(((u8 *)this) + 0x38), (Vec *)(temp_r3 + 0x38)) < lbl_805D9F50)) {
            this->m_374 = (s16) (this->m_374 | 2);
            ((TObjPlayer *)((u8 *)this))->set_flag_and_notify();
        }
        play_sound_effect((s32)((void*)((s32)remap_area_sound_id(0x3B10F, 5))), (u32)(((u8 *)this) + 0x38), 0, 0);
    }
}

void TObjEneLappy::update_invuln_timer() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r4;
    advance_animation_playback(arg0);
    if (!(*(s32 *)&this->actorFlags & 0x800000)) {
        apply_actor_gravity(arg0, NULL, lbl_805D9F4C);
    }
    ((TObjPlayer *)arg0)->update_collisions();
    temp_r4 = *(s16 *)&this->timer;
    *(s16 *)&this->timer = (temp_r4 - 1);
    if (temp_r4 < 0) {
        *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags & 0xFFFFFEFF);
        *(s16 *)&this->timer = (s16) *(s16 *)&this->resetTimer;
        this->referenceHp = (s16) this->hp;
    }
}

void TObjEneLappy::vfunc_61() {
    if ((s16) this->mode != 3) {
        this->mode = 3;
        this->m_b8 = 1;
        this->actorFlags = (s32) (this->actorFlags & 0xFF9FFFFF);
    }
}

void TObjEneLappy::update_attacking() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    advance_animation_playback(arg0);
    switch (this->phase) {
    case 0:
        enemy_turn_toward_dest(arg0, (void *) *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8));
        apply_actor_gravity(arg0, 0, lbl_805D9F4C);
        if (objInBand((GameObj *)arg0, (f32)lbl_805D9F54) != 0) {
            enemy_set_heading_velocity(arg0, this->rotation_y, *(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4));
            *(f32 *)((s8 *)arg0 + 0x30C) = lbl_805D9F4C;
            this->phase = 1;
        }
        break;
    case 1:
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
        *(f32 *)((s8 *)arg0 + 0x38) += *(f32 *)((s8 *)arg0 + 0x308);
        *(f32 *)((s8 *)arg0 + 0x308) *= lbl_805D9F58;
        *(f32 *)((s8 *)arg0 + 0x40) += this->m_310;
        this->m_310 *= lbl_805D9F58;
        apply_actor_gravity(arg0, 0, lbl_805D9F4C);
        if (objInBand((GameObj *)arg0, (f32)lbl_805D9F5C) != 0) {
            temp_r3 = this->target;
            if (temp_r3 != NULL && ((VObj_18_800C0588 *) temp_r3)->m18(arg0, lbl_805D9F60) != 0) {
                ((VObj_18_800C0588 *) this->target)->m20(arg0, lbl_805D9F60);
                ((VObj_18_800C0588 *) this->target)->m23(arg0, lbl_805D9F64);
            }
            play_sound_effect(remap_area_sound_id(0x3BC0D, 5), (u32)(arg0 + 0x38), 0, 0);
            this->phase = 2;
            *(s16 *)&this->timer = 0x1E;
        }
        break;
    case 2:
        apply_actor_gravity(arg0, 0, lbl_805D9F4C);
        (*(s16 *)&this->timer)--;
        if (*(s16 *)&this->timer < 0) {
            this->phase = 3;
        }
        break;
    case 3:
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
        *(f32 *)((s8 *)arg0 + 0x38) += *(f32 *)((s8 *)arg0 + 0x308);
        *(f32 *)((s8 *)arg0 + 0x40) += this->m_310;
        apply_actor_gravity(arg0, 0, lbl_805D9F4C);
        if (this->m_b4 != 4U) {
            *(f32 *)((s8 *)arg0 + 0x308) = *(f32 *)((s8 *)arg0 + 0x30C) = this->m_310 = lbl_805D9F4C;
            *(s32 *)&this->actorFlags &= 0xFFDFFFFF;
            this->vfunc_59();
            *(s16 *)&this->timer = 0;
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
}

void TObjEneLappy::vfunc_60() {
    u16 temp_r4;
    if (!(this->m_374 & 0x42) && (obj_testFlags30__13TUnk_804AF8A0FUl(this, 0xA02) == 0) && ((s16) this->mode != 2)) {
        this->mode = 2;
        this->m_b8 = 5;
        this->phase = 0;
        *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags | 0x200000);
        if ((s16) *(s16 *)&this->m_382 != (s32) (temp_r4 = this->targetId)) {
            *(s16 *)&this->m_382 = (s16) temp_r4;
            *(s16 *)&this->m_384 = 0;
        } else {
            *(s16 *)&this->m_384 = (s16) (*(s16 *)&this->m_384 + 1);
        }
        this->m_388 = 0;
    }
}
#pragma push
#pragma opt_common_subs off
typedef char RecoveredFields_800C1478_arg0_30_offset[offsetof(RecoveredFields_800C1478_arg0, field_30) == 0x30 ? 1 : -1];
typedef char RecoveredFields_800C1478_arg0_A4_offset[offsetof(RecoveredFields_800C1478_arg0, field_A4) == 0xA4 ? 1 : -1];
typedef char RecoveredFields_800C1478_arg0_B8_offset[offsetof(RecoveredFields_800C1478_arg0, field_B8) == 0xB8 ? 1 : -1];
typedef char RecoveredFields_800C1478_arg0_2A8_offset[offsetof(RecoveredFields_800C1478_arg0, field_2A8) == 0x2A8 ? 1 : -1];
typedef char RecoveredFields_800C1478_arg0_30C_offset[offsetof(RecoveredFields_800C1478_arg0, field_30C) == 0x30C ? 1 : -1];
typedef char RecoveredFields_800C1478_arg0_326_offset[offsetof(RecoveredFields_800C1478_arg0, field_326) == 0x326 ? 1 : -1];
typedef char RecoveredFields_800C1478_arg0_338_offset[offsetof(RecoveredFields_800C1478_arg0, field_338) == 0x338 ? 1 : -1];
typedef char RecoveredFields_800C1478_arg0_374_offset[offsetof(RecoveredFields_800C1478_arg0, field_374) == 0x374 ? 1 : -1];
typedef char RecoveredFields_800C1478_arg0_380_offset[offsetof(RecoveredFields_800C1478_arg0, field_380) == 0x380 ? 1 : -1];
typedef char RecoveredFields_800C1478_temp_r3_30_offset[offsetof(RecoveredFields_800C1478_temp_r3, field_30) == 0x30 ? 1 : -1];
typedef char RecoveredFields_800C1478_temp_r3_2_18_offset[offsetof(RecoveredFields_800C1478_temp_r3_2, field_18) == 0x18 ? 1 : -1];

void TObjEneLappy::update_moving() {
    u8 *arg0 = (u8 *)this;
    Position_800C08A0 probe;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f31;
    s16 temp_r3_4;
    s32 var_r4;
    u32 temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r4;
    u8 *temp_r6;
    u8 *temp_r7;
    u8 *temp_r7_2;
    advance_animation_playback(arg0);
    if ((*(s32 *)&this->actorFlags & 0x1000) && !(this->m_374 & 2)) {
        temp_r6 = this->target;
        if (temp_r6 != NULL) {
            Position_800C08A0 target1 = *(Position_800C08A0 *)(temp_r6 + 0x2FC);
            enemy_backstep_from_point(arg0, &target1.x, (f32) (*(f32 *)((s8 *)((u8 *)(*(u8 * *)&this->movementParameters)) + 4)));
            ((TObjPlayer *)arg0)->update_angle((s32)((void *) (*(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8))), (u8 *)&this->unk_308);
            apply_actor_gravity(arg0, 0, lbl_805D9F4C);
            ((TObjPlayer *)arg0)->update_collisions();
            return;
        }
    }
    temp_r3 = this->m_b4;
    if (temp_r3 == 1U) {
        switch (*(s16 *)&this->m_37a) {
        case 0:
            temp_r7 = this->target;
            if (temp_r7 != NULL) {
                Position_800C08A0 target2 = *(Position_800C08A0 *)(temp_r7 + 0x2FC);
                temp_f31 = update_enemy_wander_move(arg0, &target2.x, 1, (f32) (*(f32 *)((s8 *)((u8 *)(*(u8 * *)&this->movementParameters)) + 4)));
                if ((obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 2) == 0) && (temp_f31 < lbl_805D9F50)) {
                    *(s16 *)&this->m_37a = 1;
                    *(s32 *)((s8 *)arg0 + 0x398) = 0;
                    calc_boss4_scale__10TObjPlayerFi(arg0);
                    this->m_39c = (f32) lbl_805D9F4C;
                }
                temp_r3_2 = (u8 *)(*(u8 * *)&this->movementParameters);
                if (*(f32 *)((s8 *)temp_r3_2 + 0) * *(f32 *)((s8 *)temp_r3_2 + 0) < temp_f31 || temp_f31 < *(f32 *)((s8 *)temp_r3_2 + 4) * *(f32 *)((s8 *)temp_r3_2 + 4)) {
                    this->target = NULL;
                }
            } else {
                temp_r4 = (u8 *)(*(u8 * *)&this->movementParameters);
                ((s32 (*)(void *, f32, f32, f32, int))enemy_wander_home__9TObjEnemyFlfff)(arg0, *(f32 *)((s8 *)temp_r4 + 4), lbl_805D9F68, lbl_805D9F6C, *(s32 *)((s8 *)temp_r4 + 8));
            }
            ((TObjPlayer *)arg0)->update_angle((s32)((void *) (*(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8))), (u8 *)&this->unk_308);
            play_walk_sound();
            goto block_48;
        case 1:
            temp_r7_2 = this->target;
            if (temp_r7_2 != NULL) {
                Position_800C08A0 target3 = *(Position_800C08A0 *)(temp_r7_2 + 0x2FC);
                temp_f1 = update_enemy_wander_move(arg0, &target3.x, 1, (f32) (*(f32 *)((s8 *)((u8 *)(*(u8 * *)&this->movementParameters)) + 4)));
                if (temp_f1 > lbl_805D9F70) {
                    *(s16 *)&this->m_37a = 0;
                }
                ((TObjPlayer *)arg0)->update_angle((s32)((void *) (*(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8))), (u8 *)&this->unk_308);
                temp_r3_3 = (u8 *)(*(u8 * *)&this->movementParameters);
                if (*(f32 *)((s8 *)temp_r3_3 + 0) * *(f32 *)((s8 *)temp_r3_3 + 0) < temp_f1 || temp_f1 < *(f32 *)((s8 *)temp_r3_3 + 4) * *(f32 *)((s8 *)temp_r3_3 + 4)) {
                    this->target = NULL;
                }
            } else {
                *(s16 *)&this->m_37a = 0;
            }
            play_walk_sound();
            goto block_48;
        case 2:
            break;
        case 3:
            this->rotation_y = lerp_angle_half__10TObjPlayerFUsUs(this->rotation_y, this->m_390);
            if ((u32) this->m_b4 == 1U) {
                *(s32 *)&this->actorFlags = (*(s32 *)&this->actorFlags & 0xFBFFFFFF);
                *(s16 *)&this->m_37a = 4;
                play_sound_effect(remap_area_sound_id(0x3AF12, 5), (u32)(arg0 + 0x38), 0, 0);
            }
            if (objInBand((GameObj *)(arg0), lbl_805D9F2C) != 0) {
                play_sound_effect(remap_area_sound_id(0x3AA11, 5), (u32)(arg0 + 0x38), 0, 0);
            }
            goto block_48;
        case 4:
            if (temp_r3 == 1U) {
                enemy_set_heading_velocity(arg0, this->rotation_y, (f32) (lbl_805D9F74 * *(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4)));
                *(s16 *)&this->unk_394 = (s16) (*(s16 *)&this->unk_394 + 1);
                if (((f32) *(s16 *)&this->unk_394 > lbl_805D9F78) && (((u16 (*)(void *, void *, f32))find_nearest_visible_player)(arg0, &probe.x, lbl_805D9F7C) != 0xFFFFU) && (angle_difference_abs(this->rotation_y, (int) ((s32) (lbl_8043BA18 * atan2_float(probe.x, probe.z)))) < 0xAAA)) {
                    if (calc_boss4_scale__10TObjPlayerFi(arg0) >= lbl_805D9F24) {
                        var_r4 = -0x4000;
                    } else {
                        var_r4 = 0x4000;
                    }
                    this->rotation_y = (s32) (this->rotation_y + var_r4);
                    *(s16 *)&this->unk_394 = 0;
                }
                if (((TObjEneLappy *)arg0)->advance_flee_step() == 0) {
                    queue_destruction__7TObjectFv(arg0);
                    return;
                }
                if (--*(s16 *)&this->m_396 < 0) {
                    spawn_particle_effect((u8 *)&this->position, 0xF3);
                    *(s16 *)&this->m_396 = 2;
                }
                play_persistent_sound(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x3AF12), arg0, (u8 *)&this->position, 0, 0);
                goto block_47;
            }
block_47:
            apply_actor_gravity(arg0, 0, lbl_805D9F4C);
            ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
            return;
        }
    }
block_48:
        apply_actor_gravity(arg0, 0, lbl_805D9F4C);
        ((TObjPlayer *)arg0)->update_collisions();
}

void TObjEneLappy::vfunc_59() {
    s32 temp_r6;
    void *temp_r3;
    void *temp_r7;
    if (!(this->m_374 & 0x42) && !(this->actorFlags & 0xA00)) {
        if ((s16) this->mode != 1) {
            temp_r7 = this->target;
            if (temp_r7 != NULL) {
                struct Sp800C0D3C sp8 = *(struct Sp800C0D3C *)((s8 *)temp_r7 + 0x2FC);
                if (select_enemy_destination(this, &sp8, 1) == 1) {
                    switch ((s8)this->m_378) {
                    case 0:
                        this->m_b8 = 3;
                        break;
                    case 1:
                        this->m_b8 = 2;
                        break;
                    }
                    this->m_37a = 0;
                    this->m_380 = 0;
                    this->m_378 = 0U;
                    this->mode = 1;
                    this->actorFlags = (s32) (this->actorFlags & 0xFFDBFFFF);
                }
            }
        }
        temp_r3 = this->m_a4;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
    }
}

#pragma push
#pragma opt_common_subs on
#define arg0 ((u8 *)ov)
void TObjEneLappy::update_idle_state(void *ov) {
    f32 range;

    if (((VObj_18_800C0E30 *) arg0)->m17(0x1E) != 0) {
        if ((s8) ((TObjPlayer *)arg0)->m_379 != 0) {
            range = lbl_805D9F28;
        } else {
            range = lbl_805D9F68;
        }
        if (xz_distance_squared((Vec *)(arg0 + 0x38), (Vec *)(arg0 + 0x50)) > range * range) {
            *(u8 *)((s8 *)arg0 + 0x378) = 2;
            ((TObjPlayer *)arg0)->m_b8 = 3;
        } else if ((s8) *(u8 *)((s8 *)arg0 + 0x378) != (s8) ((TObjPlayer *)arg0)->m_379) {
            *(u8 *)((s8 *)arg0 + 0x378) = ((TObjPlayer *)arg0)->m_379;
            ((TObjPlayer *)arg0)->phase = 0;
        }
    }
    switch ((s8) *(u8 *)((s8 *)arg0 + 0x378)) {
    case 0:
        switch (((TObjPlayer *)arg0)->phase) {
        case 0:
            *(s16 *)((s8 *)arg0 + 0x37E) = (s16) (lbl_805D9F80 * (lbl_805D9F60 + calc_boss4_scale__10TObjPlayerFi(arg0)));
            ((TObjPlayer *)arg0)->phase = ((TObjPlayer *)arg0)->m_b8 = 1;
        case 1:
            (*(s16 *)((s8 *)arg0 + 0x37E))--;
            if (*(s16 *)((s8 *)arg0 + 0x37E) < 0) {
                play_sound_effect(remap_area_sound_id(0x3B20B, 5), (u32)(arg0 + 0x38), 0, 0);
                ((TObjPlayer *)arg0)->phase = 2;
            }
            break;
        case 2:
            *(f32 *)((s8 *)arg0 + 0x38C) = lbl_805D9F2C;
            ((TObjPlayer *)arg0)->phase = ((TObjPlayer *)arg0)->m_b8 = 3;
        case 3:
            ((s32 (*)(f32, void *, int, f32, f32)) enemy_wander_home__9TObjEnemyFlfff)(*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4), arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8), lbl_805D9F68, lbl_805D9F68);
            *(f32 *)((s8 *)arg0 + 0x38C) -= *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4);
            if (*(f32 *)((s8 *)arg0 + 0x38C) < lbl_805D9F4C) {
                ((TObjPlayer *)arg0)->phase = 0;
            }
            break;
        }
        advance_animation_playback(arg0);
        break;
    case 1:
        ((TObjPlayer *)arg0)->m_b8 = 0;
        advance_animation_playback(arg0);
        (*(s16 *)((s8 *)arg0 + 0x37E))--;
        if (*(s16 *)((s8 *)arg0 + 0x37E) < 0) {
            play_sound_effect(remap_area_sound_id(0x3B20B, 5), (u32)(arg0 + 0x38), 0, 0);
            *(s16 *)((s8 *)arg0 + 0x37E) = (s16) (lbl_805D9F2C * (lbl_805D9F84 * (lbl_805D9F60 + calc_boss4_scale__10TObjPlayerFi(arg0))));
        }
        break;
    case 2: {
        advance_animation_playback(arg0);
        Vec_800C0E30 v = *(Vec_800C0E30 *)((s8 *)arg0 + 0x50);
        update_enemy_wander_move(arg0, &v, 7, *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4));
        ((TObjPlayer *)arg0)->update_angle((s32)((void *) *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8)), arg0 + 0x308);
        break;
    }
    }
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    if (!(((TObjPlayer *)arg0)->actorFlags & 0x800000)) {
        apply_actor_gravity(arg0, 0, lbl_805D9F4C);
    }
    if (((TObjPlayer *)arg0)->actorFlags & 0x40000) {
        if ((*(s16 *)((s8 *)arg0 + 0x33C))-- < 0) {
            ((TObjPlayer *)arg0)->actorFlags &= ~0x40000;
            *(s16 *)((s8 *)arg0 + 0x33C) = *(s16 *)((s8 *)arg0 + 0x33A);
        }
    }
}
#undef arg0
#pragma pop

void TObjEneLappy::vfunc_58() {
    s16 flags;
    flags = this->m_374;
    if (!(flags & 2) && !(this->actorFlags & 0xA00)) {
        if (flags & 0x20) {
            this->m_374 = flags & ~0x20;
            this->obj_clearFlags30(0x02000000);
            Vec_800C1144 v = *(Vec_800C1144 *)((s8 *)this + 0x38);
            if (project_actor_to_ground(this, &v, 0) == 1) {
                *(f32 *)((s8 *)this + 0x3C) = lbl_805D9F7C + v.y;
            }
        }
        if (this->mode != 0) {
            this->mode = 0;
            this->phase = 0;
            switch ((s8) this->m_378) {
            case 0:
                this->m_b8 = 3;
                break;
            case 1:
                this->m_b8 = 0;
                break;
            }
        }
    }
}

void TObjEneLappy::vfunc_28() {
    s32 best_id;
    s32 i;
    s32 id;
    u8 *p;
    f32 best;
    f32 d;
    u8 *arg0 = (u8 *)this;
    if (((TObjEneLappy *)(arg0))->is_actor_cadence_frame(0x1E) != 0) {
        if (*(s32 *)((s8 *)arg0 + 0x30) & 0x1000) {
            if ((*(f32 *)((s8 *)arg0 + 0x2B4) -= lbl_805D9F60) < lbl_805D9F4C) {
                *(u16 *)((s8 *)arg0 + 0x338) = 0xFFFFU;
                *(f32 *)((s8 *)arg0 + 0x2B4) = lbl_805D9F4C;
            } else {
                *(u16 *)((s8 *)arg0 + 0x338) = find_nearest_visible_player(arg0, 0, *(f32 *)((s8 *)(*(f32 **)((s8 *)arg0 + 0x350)) + 0));
            }
        } else if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec_800C1224 v = *(Vec_800C1224 *)lappy_target_zero_vec;
            best = *(f32 *)((s8 *)(*(f32 **)((s8 *)arg0 + 0x350)) + 0) * *(f32 *)((s8 *)(*(f32 **)((s8 *)arg0 + 0x350)) + 0);
            for (; i < lbl_805D586C + lbl_805D5870; i++) {
                p = (u8 *)get_player_data__10TObjPlayerFi(i);
                if (p == NULL) {
                    break;
                }
                id = obj_getField1c(p);
                if ((u16)id < 0x4000 && (u16)id != *(u16 *)((s8 *)arg0 + 0x1C) && !(*(s32 *)((s8 *)p + 0x30) & 0x800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy((Vec *)&v, (const Vec *)(p + 0x2FC));
                    subtract_vector(&v, arg0 + 0x2FC);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(arg0, p + 0x2FC) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            *(u16 *)((s8 *)arg0 + 0x338) = best_id;
        } else {
            *(u16 *)((s8 *)arg0 + 0x338) = find_nearest_visible_player(arg0, 0, *(f32 *)((s8 *)(*(f32 **)((s8 *)arg0 + 0x350)) + 0));
        }
    }
    if (*(s16 *)((s8 *)arg0 + 0x384) > 3 && *(s16 *)((s8 *)arg0 + 0x382) == *(u16 *)((s8 *)arg0 + 0x338)) {
        s32 j;
        u8 *q;
        for (j = 0; j < lbl_805D586C; j++) {
            q = (u8 *)get_player_data__10TObjPlayerFi(j);
            if (q != NULL && *(s16 *)((s8 *)arg0 + 0x382) != (u16) obj_getField1c(q) && !(*(s32 *)((s8 *)q + 0x30) & 0x800)) {
                if (xz_distance_squared((Vec *)(q + 0x2FC), (Vec *)(arg0 + 0x2FC)) < lbl_805D9F88) {
                    *(u16 *)((s8 *)arg0 + 0x338) = j;
                }
                break;
            }
        }
    }
}

void TObjEneLappy::run_task() {
    f32 var_f1;
    s16 temp_r5;
    u8 *temp_r3;
    u8 *temp_r3_2;
    sub_800C20C0__12TObjEneLappyFv();
    if (TObjPlayer::check_demo_mode() == 1) {
        apply_variant_speeds__12TObjEneLappyFv((Obj_800BFCD4 *)(this));
        TObjPlayer__sub_800BFF54(this);
        return;
    }
    ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_2A8 = find_active_entity_by_id(((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_338);
    temp_r3 = (unsigned char *) (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_2A8);
    if ((temp_r3 != NULL) && (((RecoveredFields_800C1478_temp_r3 *)temp_r3)->field_30 & 0x800)) {
        ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_2A8 = NULL;
        ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_338 = 0xFFFFU;
    }
    switch (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_326) {
    case 0:
        TObjEneLappy::update_idle_state(this);
        break;
    case 1:
        this->update_moving();
        break;
    case 2:
        this->update_attacking();
        break;
    case 3:
        this->update_invuln_timer();
        break;
    case 4:
        this->update_hurt();
        break;
    case 5:
        this->apply_move_friction();
        break;
    }
    ((TObjEnemy *)((u8 *)this))->update_prev_position();
    VecCopy((Vec *)(((u8 *)this) + 0x74), (const Vec *)(((u8 *)this) + 0x2FC));
    if ((obj_testFlags30__13TUnk_804AF8A0FUl(((u8 *)this), 0x06000000) == 0) && !(((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 & 4)) {
        submit_cursor_candidate(((u8 *)this), -1);
    }
    minimap_render_dot(((u8 *)this) + 0x38, -0x5DB4, 1, 0);
    if (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 & 0x40) {
        ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_30C = (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_30C > lbl_805D9F8C) ? ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_30C : lbl_805D9F8C;
        if (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_30 & 0x800000) {
            ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 = (s16) (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 & 0xFFFFFFBF);
            if (TLobby::get_instance() == 1) {
                play_sound_effect(0x3AB44, (u32)(((u8 *)this) + 0x38), 0, 0);
            } else {
                play_sound_effect(0x4003AB33, (u32)(((u8 *)this) + 0x38), 0, 0);
            }
            temp_r3_2 = (unsigned char *) (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_A4);
            ((RecoveredFields_800C1478_temp_r3_2 *)temp_r3_2)->field_18 = (s32) (((RecoveredFields_800C1478_temp_r3_2 *)temp_r3_2)->field_18 | 1);
        }
    }
    if ((obj_testFlags30__13TUnk_804AF8A0FUl(((u8 *)this), 0x800) != 0) && !(((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 & 2)) {
        temp_r5 = ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_380;
        ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_380 = (temp_r5 + 1);
        if ((((VCls18 *)(((u8 *)this)))->vm17(0x1E, temp_r5) != 0) && (((u16)find_nearest_visible_player(((u8 *)this), 0, lbl_805D9F90) == 0xFFFFU) || ((s16) ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_380 >= 0x384))) {
            ((TObjEneLappy *)((u8 *)this))->set_boss4_state();
            ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_B8 = 9;
        }
    }
}
#pragma pop

#undef sub_800C20B0__12TObjEneLappyFv
#undef set_speed_params__12TObjEneLappyFl
#undef sub_800C20C0__12TObjEneLappyFv

#undef lappy_variant_speed_ptr_table

void *TObjControl__ct(void *, void *);
struct Set_800C1C4C;
u8 * TObjEneLappy__ct(u8 *self, s32 arg1, Set_800C1C4C *set);
#define TObjEneLappy__ct (*(void * (*)(void *, void *, void *))&TObjEneLappy__ct)
void *__nw__7TObjectFUl(int);

extern void *tl_04;

void *TObjEneLappy::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3A4);
    if (o2 != NULL) {
        o2 = TObjEneLappy__ct(o2, o, arg0);
    }
    return o2;
}
}

#undef TObjEneLappy__ct

#define render__12TObjEneLappyFv (*(void (*)())&render__12TObjEneLappyFv)
#define apply_variant_speeds__12TObjEneLappyFv (*(s32 (*)(void *))&apply_variant_speeds__12TObjEneLappyFv)
#define render_world_model__9TObjEnemyFv (*(void (*)(void *))&render_world_model__9TObjEnemyFv)
#define draw__10TObjMotionFv (*(void (*)(void *))&draw__10TObjMotionFv)
#define scale_matrix (*(void (*)(int, f32, f32, f32))&scale_matrix)
#define draw_chunk_object (*(s32 (*)(int))&draw_chunk_object)
#define set_global_param__8TObjFishFl (*(s32 (*)(void *))&set_global_param__8TObjFishFl)
#define post_translate_matrix (*(s32 (*)(void *))&post_translate_matrix)
#define pop_matrix (*(s32 (*)())&pop_matrix)
#define push_matrix (*(s32 (*)())&push_matrix)
#define rotate_matrix_y (*(s32 (*)(int, int))&rotate_matrix_y)
#define end_effect_render__13TParticleCtrlFv (*(s32 (*)())&end_effect_render__13TParticleCtrlFv)
#define toggle_particle_effect__10TObjPlayerFv (*(s32 (*)())&toggle_particle_effect__10TObjPlayerFv)

#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe2Flower.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Set_800C1C4C {
    u8 pad0[0xA];
    s16 fa;
    u8 padC[0x10 - 0xC];
    f32 pos[3];
    f32 rot[3];
    f32 params[5];
    s16 f3c;
    s16 f3e;
};
struct Lappy_800C1C4C { u8 pad[0x354]; f32 params[5]; };

typedef struct Vec_800C20D0 {
    f32 x, y, z;
} Vec_800C20D0;

typedef struct Mat_800C20D0 {
    u8 pad0[0x8];
    s32 f8;
    u8 padC[0x14 - 0xC];
    s32 f14;
    u8 pad18[0x20 - 0x18];
    s32 f20;
    u8 pad24[0x2C - 0x24];
    s32 f2C;
} Mat_800C20D0;

typedef struct Model_800C20D0 {
    Mat_800C20D0 *mat;
} Model_800C20D0;

struct VBase_800C20D0 {
    char pad0[0x18];
};

struct VObj_800C20D0 : VBase_800C20D0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Obj_800C20D0 : VObj_800C20D0 {
    u8 pad1C[0x24 - 0x1C];
    Model_800C20D0 *model;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    Vec_800C20D0 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
};

typedef struct Vec_800C220C { f32 x, y, z; } Vec_800C220C;

typedef struct Mat_800C220C {
    u8 pad0[0x8];
    s32 f8;
    u8 padC[0x14 - 0xC];
    s32 f14;
    u8 pad18[0x20 - 0x18];
    s32 f20;
    u8 pad24[0x2C - 0x24];
    s32 f2C;
} Mat_800C220C;

typedef struct Model_800C220C { Mat_800C220C *mat; } Model_800C220C;

struct SBase_800C220C { char pad0[0x14]; };

struct Sub_800C220C : SBase_800C220C {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual void m6(); virtual void m7(); virtual s32 m8();
};

struct VBase_800C220C { char pad0[0x18]; };

struct VObj_800C220C : VBase_800C220C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void m104();
};

struct Obj_800C220C : VObj_800C220C {
    u8 pad1C[0x24 - 0x1C];
    Model_800C220C *model;
    u8 pad28[0x38 - 0x28];
    Vec_800C220C pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0x326 - 0x64];
    s16 f326;
    u8 pad328[0x3C0 - 0x328];
    s32 f3C0;
    u32 f3C4;
    f32 f3C8;
    u8 pad3CC[0x3D8 - 0x3CC];
    s32 f3D8;
    f32 f3DC;
    f32 f3E0;
    f32 f3E4;
    f32 f3E8;
    f32 f3EC;
    f32 f3F0;
    Sub_800C220C sub;
};

extern "C" {
s32 update_player_state__9TObjEneDDFv(void *, void *, int);
s32 sub_800C3B8C__16TObjEneRe2FlowerFv(void *);
}
void restore_default_scene(void);
void set_scene_override(u8 scene);
extern Vec_800C20D0 lbl_8043BBC0[];
extern "C" {
s32 is_main_phase_15__9TObjEneDDFv(void);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 defer_render__7TObjectFv(void *);
extern Vec_800C220C lbl_8043BBB4[];
extern s32 saved_model_render_flags;
extern s32 lbl_805D5178;
extern s32 lbl_805D517C;
extern f32 *lbl_805D5180;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 lbl_805D9FAC;
extern const f32 lbl_805D9FB0;
extern const f32 lbl_805D9FB4;
extern const f32 lbl_805D9FB8;
void TObjPlayer__sub_800C220C(Obj_800C220C *o);
void *__dt__12TObjEneLappyFv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);

s32 add_flags_2e4__13TUnk_804806E8FUl(void *, int, f32, f32);
s32 __ct__9TObjEnemyFP7TObject(void *, s32, void *);
s32 init_collision_body_parts(void *, void *, int);

extern s32 lbl_805D2A40;
extern s32 lappy_variant_id;
extern void *rappy_bml_resource;

extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void vfunc_73__13TUnk_804806E8Fv();
extern "C" void consume_timer_field__13TUnk_804806E8Fl();
extern "C" void vfunc_67__13TUnk_804806E8Ff();
extern "C" void vfunc_66__13TUnk_804806E8Fv();
extern "C" void get_anim_node_position__13TUnk_804806E8FlP3Vec();
extern "C" void apply_slow_status__13TUnk_804806E8Fv();
extern "C" void update_shock_clock__13TUnk_804806E8Fv();
extern "C" void vfunc_43__13TUnk_804806E8Fv();
extern "C" void vfunc_18__13TUnk_804806E8FPUc();
extern "C" void vfunc_13__13TUnk_804AF8A0Fl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__13TUnk_804806E8Fl();
extern "C" void apply_action_hold_status__13TUnk_804806E8Ff();
extern "C" void apply_anti_technique__13TUnk_804806E8Fl();
extern "C" void apply_attack_stat_status__13TUnk_804806E8FPv();
extern "C" void apply_confusion_status__13TUnk_804806E8Fv();
extern "C" void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
extern "C" void apply_movement_ailment__13TUnk_804806E8Fl();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_paralysis__13TUnk_804806E8Fv();
extern "C" void apply_poison_status__13TUnk_804806E8Fv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__13TUnk_804806E8Fv();
extern "C" void apply_switch_attack__13TUnk_804806E8Fv();
extern "C" void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void clear_all_status_effects__13TUnk_804806E8Fv();
extern "C" void clear_harmful_statuses__13TUnk_804806E8Fv();
extern "C" void cure_paralysis__13TUnk_804806E8Fv();
extern "C" void cure_poison_ailment__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
extern "C" void vfunc_78__13TUnk_804806E8Fl();
extern "C" void vfunc_77__13TUnk_804806E8Fv();
extern "C" void vfunc_76__13TUnk_804806E8Fv();
extern "C" void vfunc_75__13TUnk_804806E8Ff();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void vfunc_9__13TUnk_804806E8Fv();
extern "C" void get_actor_level_index__13TUnk_804806E8Fv();
extern "C" void vfunc_12__9TObjEnemyFv();
extern "C" void get_pos__13TUnk_804806E8Fl();
extern "C" void is_actor_cadence_frame__13TUnk_804806E8Fl();
extern "C" void is_target_in_attack_range__13TUnk_804806E8Fv();
extern "C" u8 lbl_8043B7D8[];
extern "C" u8 lbl_8043B7EC[];
extern "C" u8 lbl_8043B800[];
extern "C" u8 lbl_8043B818[];
extern "C" u8 lbl_8043B830[];
extern "C" u8 lbl_8043B844[];
extern "C" u8 lbl_8043B858[];
extern "C" u8 lbl_8043B870[];
extern "C" u8 lbl_8043B888[];
extern "C" u8 lbl_8043B89C[];
extern "C" u8 lbl_8043B8B4[];
extern "C" u8 lbl_8043B8C8[];
extern "C" u8 lbl_8043B8DC[];
extern "C" u8 lbl_8043B8F0[];
extern "C" u8 lbl_8043B904[];
extern "C" u8 lbl_8043B91C[];
extern "C" u8 lbl_8043B930[];
extern "C" u8 lbl_8043B948[];
extern "C" u8 lbl_8043B960[];
extern "C" u8 lbl_8043B974[];
extern "C" u8 lbl_8043B98C[];
extern "C" u8 lbl_8043B9A4[];
extern "C" u8 lbl_8043B9B8[];
extern "C" u8 lbl_8043B9D0[];
extern "C" u8 lbl_8043B9DC[];
extern "C" const u8 rappy_variant_na_name[3] = "NA";
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
extern void *TObjEneLappy__model_filename_table[3];
extern void *lbl_80492BE4[11];
extern void *lbl_80492C20[3];
extern void *lbl_80492C2C[11];
extern void *lbl_80492C68[3];
extern void *lbl_80492C74[11];
extern void *lbl_80492CB0[3];
extern void *lbl_80492CBC[11];
extern void *lbl_80492CF8[3];
extern void *TObjEneLappy__resource_name_table[11];
extern void *lbl_80492D40[3];
extern void *TObjEneLappy__resource_list[11];
extern void *lbl_80492D88[3];
extern void *lbl_80492D94[11];
extern void *lbl_80492DD0[3];
extern void *lbl_80492DDC[11];
void *TObjEneLappy__model_filename_table[3] = {
    (void *)&lbl_8043B7D8, (void *)&lbl_8043B7EC, (void *)0x0,
};
void *lbl_80492BE4[11] = {
    (void *)&lbl_8043B800, (void *)&lbl_8043B818, (void *)&lbl_8043B830, (void *)&lbl_8043B844,
    (void *)&lbl_8043B858, (void *)&lbl_8043B870, (void *)&lbl_8043B888, (void *)&lbl_8043B89C,
    (void *)&lbl_8043B8B4, (void *)&lbl_8043B8C8, (void *)0x0,
};
void *lbl_80492C10[4] = {
    (void *)&lbl_8043B8DC, (void *)&TObjEneLappy__model_filename_table, (void *)&lbl_80492BE4, (void *)0x2000a,
};
void *lbl_80492C20[3] = {
    (void *)&lbl_8043B7D8, (void *)&lbl_8043B7EC, (void *)0x0,
};
void *lbl_80492C2C[11] = {
    (void *)&lbl_8043B800, (void *)&lbl_8043B818, (void *)&lbl_8043B830, (void *)&lbl_8043B844,
    (void *)&lbl_8043B858, (void *)&lbl_8043B870, (void *)&lbl_8043B888, (void *)&lbl_8043B89C,
    (void *)&lbl_8043B8B4, (void *)&lbl_8043B8C8, (void *)0x0,
};
void *lbl_80492C58[4] = {
    (void *)&lbl_8043B8F0, (void *)&lbl_80492C20, (void *)&lbl_80492C2C, (void *)0x2000a,
};
void *lbl_80492C68[3] = {
    (void *)&lbl_8043B7D8, (void *)&lbl_8043B904, (void *)0x0,
};
void *lbl_80492C74[11] = {
    (void *)&lbl_8043B800, (void *)&lbl_8043B818, (void *)&lbl_8043B830, (void *)&lbl_8043B844,
    (void *)&lbl_8043B858, (void *)&lbl_8043B870, (void *)&lbl_8043B888, (void *)&lbl_8043B89C,
    (void *)&lbl_8043B8B4, (void *)&lbl_8043B8C8, (void *)0x0,
};
void *lbl_80492CA0[4] = {
    (void *)&lbl_8043B91C, (void *)&lbl_80492C68, (void *)&lbl_80492C74, (void *)0x2000a,
};
void *lbl_80492CB0[3] = {
    (void *)&lbl_8043B7D8, (void *)&lbl_8043B904, (void *)0x0,
};
void *lbl_80492CBC[11] = {
    (void *)&lbl_8043B800, (void *)&lbl_8043B818, (void *)&lbl_8043B830, (void *)&lbl_8043B844,
    (void *)&lbl_8043B858, (void *)&lbl_8043B870, (void *)&lbl_8043B888, (void *)&lbl_8043B89C,
    (void *)&lbl_8043B8B4, (void *)&lbl_8043B8C8, (void *)0x0,
};
void *lbl_80492CE8[4] = {
    (void *)&lbl_8043B930, (void *)&lbl_80492CB0, (void *)&lbl_80492CBC, (void *)0x2000a,
};
void *lbl_80492CF8[3] = {
    (void *)&lbl_8043B7D8, (void *)&lbl_8043B948, (void *)0x0,
};
void *TObjEneLappy__resource_name_table[11] = {
    (void *)&lbl_8043B800, (void *)&lbl_8043B818, (void *)&lbl_8043B830, (void *)&lbl_8043B844,
    (void *)&lbl_8043B858, (void *)&lbl_8043B870, (void *)&lbl_8043B888, (void *)&lbl_8043B89C,
    (void *)&lbl_8043B8B4, (void *)&lbl_8043B8C8, (void *)0x0,
};
void *lbl_80492D30[4] = {
    (void *)&lbl_8043B960, (void *)&lbl_80492CF8, (void *)&TObjEneLappy__resource_name_table, (void *)0x2000a,
};
void *lbl_80492D40[3] = {
    (void *)&lbl_8043B7D8, (void *)&lbl_8043B948, (void *)0x0,
};
void *TObjEneLappy__resource_list[11] = {
    (void *)&lbl_8043B800, (void *)&lbl_8043B818, (void *)&lbl_8043B830, (void *)&lbl_8043B844,
    (void *)&lbl_8043B858, (void *)&lbl_8043B870, (void *)&lbl_8043B888, (void *)&lbl_8043B89C,
    (void *)&lbl_8043B8B4, (void *)&lbl_8043B8C8, (void *)0x0,
};
void *lbl_80492D78[4] = {
    (void *)&lbl_8043B974, (void *)&lbl_80492D40, (void *)&TObjEneLappy__resource_list, (void *)0x2000a,
};
void *lbl_80492D88[3] = {
    (void *)&lbl_8043B7D8, (void *)&lbl_8043B98C, (void *)0x0,
};
void *lbl_80492D94[11] = {
    (void *)&lbl_8043B800, (void *)&lbl_8043B818, (void *)&lbl_8043B830, (void *)&lbl_8043B844,
    (void *)&lbl_8043B858, (void *)&lbl_8043B870, (void *)&lbl_8043B888, (void *)&lbl_8043B89C,
    (void *)&lbl_8043B8B4, (void *)&lbl_8043B8C8, (void *)0x0,
};
void *lbl_80492DC0[4] = {
    (void *)&lbl_8043B9A4, (void *)&lbl_80492D88, (void *)&lbl_80492D94, (void *)0x2000a,
};
void *lbl_80492DD0[3] = {
    (void *)&lbl_8043B7D8, (void *)&lbl_8043B98C, (void *)0x0,
};
void *lbl_80492DDC[11] = {
    (void *)&lbl_8043B800, (void *)&lbl_8043B818, (void *)&lbl_8043B830, (void *)&lbl_8043B844,
    (void *)&lbl_8043B858, (void *)&lbl_8043B870, (void *)&lbl_8043B888, (void *)&lbl_8043B89C,
    (void *)&lbl_8043B8B4, (void *)&lbl_8043B8C8, (void *)0x0,
};
void *lbl_80492E08[4] = {
    (void *)&lbl_8043B9B8, (void *)&lbl_80492DD0, (void *)&lbl_80492DDC, (void *)0x2000a,
};
void *rappy_variant_speed_table[40] = {
    (void *)0x10000, (void *)0x6, (void *)0x3f666666, (void *)0x0,
    (void *)0x10001, (void *)0x5, (void *)0x3f333333, (void *)0x0,
    (void *)0x20003, (void *)0x8, (void *)0x3f333333, (void *)0x0,
    (void *)0x10003, (void *)0x9, (void *)0x3fe66666, (void *)0x1,
    (void *)0x10004, (void *)0x3, (void *)0x3f99999a, (void *)0x1,
    (void *)0x20001, (void *)0x0, (void *)0x3f800000, (void *)0x4,
    (void *)0x20001, (void *)0x1, (void *)0x3f800000, (void *)0x8,
    (void *)0x30006, (void *)0x2, (void *)0x3f19999a, (void *)0x10,
    (void *)0x20004, (void *)0x4, (void *)0x3f666666, (void *)0x1,
    (void *)0x20004, (void *)0x7, (void *)0x3f000000, (void *)0x0,
};
void *lbl_80492EB8[3] = {
    (void *)&lbl_8043B9D0, (void *)&lbl_8043B9DC, (void *)&rappy_variant_na_name,
};
void *lbl_80492EC4[14] = {
    (void *)0x43160000, (void *)0x3f097b42, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0, (void *)0x43160000,
    (void *)0x3f097b42, (void *)0x400, (void *)0x1e0000, (void *)0x0,
    (void *)0x1, (void *)0x0,
};
void *lbl_80492EFC[11] = {
    (void *)0x0, (void *)0x40f00000, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_80492F28[84] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__12TObjEneLappyFv, (void *)&run_task__12TObjEneLappyFv,
    (void *)&render__12TObjEneLappyFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&vfunc_12__9TObjEnemyFv, (void *)&vfunc_13__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__12TObjEneLappyFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__12TObjEneLappyFv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__12TObjEneLappyFv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__12TObjEneLappyFv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__12TObjEneLappyFv, (void *)&vfunc_59__12TObjEneLappyFv,
    (void *)&vfunc_60__12TObjEneLappyFv, (void *)&vfunc_61__12TObjEneLappyFv, (void *)&vfunc_62__12TObjEneLappyFv, (void *)&vfunc_63__12TObjEneLappyFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEnemyFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)0x0,
};

__declspec(section ".data") s32 lappy_boss_stats_handles[2];
__declspec(section ".data") s32 lappy_boss_stats_ptrs_b[2];
__declspec(section ".data") s32 lappy_object_handles[2];
__declspec(section ".data") s32 lappy_variant_speed_ptr_table[2];
#define lbl_80492F28 ((s32 *)lbl_80492F28)

typedef struct Desc_800C17B8 {
    s32 a;
    void *b;
    s32 c;
    s32 d;
} Desc_800C17B8;

void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
s32 get_main_phase();
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
void spawn_npc_enemy__6TLobbyFslllff(int, int, int, void *, f32, f32);
extern u8 lbl_8043BA28[];
extern u8 lbl_8043BA44[];
extern const Desc_800C17B8 lappy_resource_binding_desc;
extern s32 game_difficulty_selection;
extern s32 TLobby__event_theme_id;
extern s32 rappy_alternate_texture_list;

void TLobby::cleanup_handles() {
    if (TLobby::get_instance() == 0) {
        if ((u32) (*(u32 *)&rappy_alternate_texture_list) != 0U) {
            release_texture_list((void*)(*(u32 *)&rappy_alternate_texture_list));
            TAdSinglePlyChrSelectGC::safe_free((*(u32 *)&rappy_alternate_texture_list));
            (*(u32 *)&rappy_alternate_texture_list) = 0U;
        }
    } else {
        (*(u32 *)&rappy_alternate_texture_list) = 0U;
    }
    if ((u32) (*(u32 *)&rappy_bml_resource) != 0U) {
        TLobby__sub_8001FE7C((void*)(*(u32 *)&rappy_bml_resource), 1);
        (*(u32 *)&rappy_bml_resource) = 0U;
    }
}

#define RES_800C17B8 ((u8 *)rappy_bml_resource)

void TObjEneLappy::load_resources() {
    int rare;
    s32 p;
    s32 i;

    rare = game_difficulty_selection == 3;
    if (get_main_phase() == 0xF) {
        switch (TLobby__event_theme_id) {
        case 1:
            lappy_variant_id = 1;
            if (rare) {
                p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
                if (p != 0) {
                    p = load_resource_from_descriptor(p, 1, lbl_80492E08, 0, 0, 0);
                }
                (*(u32 *)&rappy_bml_resource) = p;
            } else {
                p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
                if (p != 0) {
                    p = load_resource_from_descriptor(p, 1, lbl_80492DC0, 0, 0, 0);
                }
                (*(u32 *)&rappy_bml_resource) = p;
            }
            break;
        case 4:
            lappy_variant_id = 2;
            if (rare) {
                p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
                if (p != 0) {
                    p = load_resource_from_descriptor(p, 1, lbl_80492CE8, 0, 0, 0);
                }
                (*(u32 *)&rappy_bml_resource) = p;
            } else {
                p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
                if (p != 0) {
                    p = load_resource_from_descriptor(p, 1, lbl_80492CA0, 0, 0, 0);
                }
                (*(u32 *)&rappy_bml_resource) = p;
            }
            break;
        case 5:
            lappy_variant_id = 3;
            if (rare) {
                p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
                if (p != 0) {
                    p = load_resource_from_descriptor(p, 1, lbl_80492D78, 0, 0, 0);
                }
                (*(u32 *)&rappy_bml_resource) = p;
            } else {
                p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
                if (p != 0) {
                    p = load_resource_from_descriptor(p, 1, lbl_80492D30, 0, 0, 0);
                }
                (*(u32 *)&rappy_bml_resource) = p;
            }
            break;
        default:
            lappy_variant_id = 0;
            if (rare) {
                p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
                if (p != 0) {
                    p = load_resource_from_descriptor(p, 1, lbl_80492C58, 0, 0, 0);
                }
                (*(u32 *)&rappy_bml_resource) = p;
            } else {
                p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
                if (p != 0) {
                    p = load_resource_from_descriptor(p, 1, lbl_80492C10, 0, 0, 0);
                }
                (*(u32 *)&rappy_bml_resource) = p;
            }
            break;
        }
    } else {
        lappy_variant_id = 0;
        if (rare) {
            p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
            if (p != 0) {
                p = load_resource_from_descriptor(p, 1, lbl_80492C58, 0, 0, 0);
            }
            (*(u32 *)&rappy_bml_resource) = p;
        } else {
            p = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
            if (p != 0) {
                p = load_resource_from_descriptor(p, 1, lbl_80492C10, 0, 0, 0);
            }
            (*(u32 *)&rappy_bml_resource) = p;
        }
    }
    if (TLobby::get_instance() == 0) {
        if (rare) {
            (*(u32 *)&rappy_alternate_texture_list) = (u32)load_gvm_texture_file((s32)lbl_8043BA28);
        } else {
            (*(u32 *)&rappy_alternate_texture_list) = (u32)load_gvm_texture_file((s32)lbl_8043BA44);
        }
    } else {
        (*(u32 *)&rappy_alternate_texture_list) = *(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 0x1C);
    }
    (*(s32 *)&rappy_visibility_node) = (s32)find_model_node((*(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 8)), 0x12);
    for (i = 0; i < 2; i++) {
        lappy_boss_stats_handles[i] = register_boss__6TLobbyFl(i + 0x18);
        lappy_boss_stats_ptrs_b[i] = dispatch_shared_handler_b__6TLobbyFl(i + 0x18);
        lappy_object_handles[i] = register_object__6TLobbyFl(i + 0x18);
        lappy_variant_speed_ptr_table[i] = dispatch_shared_handler_a__6TLobbyFl(i + 0x18);
    }
    {
        u8 *res = RES_800C17B8;
        Desc_800C17B8 d = lappy_resource_binding_desc;
        d.a = *(s32 *)(res + 0x430);
        spawn_npc_enemy__6TLobbyFslllff(5, *(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 8),
                                        *(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 0xC), &d, lbl_805D9F28, lbl_805D9F4C);
        if (TLobby::get_instance() == 0) {
            spawn_npc_enemy__6TLobbyFslllff(6, *(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 8), (*(u32 *)&rappy_alternate_texture_list), &d,
                                            lbl_805D9F28, lbl_805D9F4C);
        } else {
            spawn_npc_enemy__6TLobbyFslllff(6, *(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 0x18),
                                            *(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 0x1C), &d, lbl_805D9F28, lbl_805D9F4C);
        }
    }
}

#undef RES_800C17B8

void *__dt__12TObjEneLappyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_80492F28;
        free_collision_body_parts(arg0);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define CLAMP_800C1C4C(x, lo, hi) ((x) < (lo) ? (lo) : ((x) < (hi) ? (x) : (hi)))

u8 *TObjEneLappy__ct(u8 *self, s32 arg1, Set_800C1C4C *set) {
    s32 i;
    f32 scale;

    __ct__9TObjEnemyFP7TObject(self, arg1, set);
    *(void **)(self + 0x18) = (u8 *)lbl_80492F28;
    *(s32 *)(self + 0) = lbl_805D2A40;
    ((TObjEneLappy *)self)->apply_set_data(set);
    *(s32 *)(self + 0xDC) = *(s32 *)((u8 *)rappy_bml_resource + 0x430);
    VecCopy((Vec *)(self + 0x38), (const Vec *)set->pos);
    ((TObjPlayer *)(self + 0x5C))->copy_xyz(set->rot);
    for (i = 0; i < 5; i++) {
        ((Lappy_800C1C4C *)self)->params[i] = set->params[i];
    }
    *(s32 *)(self + 0x368) = set->f3c != 0 ? 1 : 0;
    if (calc_boss4_scale__10TObjPlayerFi(self) < lbl_805D9F94) {
        *(s32 *)(self + 0x368) = 1;
        if (TLobby::get_instance() == 1) {
            (*(s32 *)&rappy_visibility_node) = (s32)find_model_node(*(u32 *)(*(u8 **)((u8 *)rappy_bml_resource + 0x42C) + 0x18), 0x12);
        }
    }
    if (*(s32 *)(self + 0x368) == 0) {
        ((TObjEnemy *)self)->set_param(5);
    } else if (TLobby::get_instance() == 1) {
        switch (lappy_variant_id) {
        case 1:
            ((TObjEnemy *)self)->set_param(0x4F);
            break;
        case 2:
            ((TObjEnemy *)self)->set_param(0x51);
            break;
        case 3:
            ((TObjEnemy *)self)->set_param(0x50);
            break;
        default:
            ((TObjEnemy *)self)->set_param(0x33);
            break;
        }
    } else {
        ((TObjEnemy *)self)->set_param(6);
    }
    *(s32 *)(self + 0x36C) = set->f3e;
    *(s16 *)(self + 0x33A) = 0xF;
    *(s16 *)(self + 0x33C) = *(s16 *)(self + 0x33A);
    VecCopy((Vec *)(self + 0x44), (const Vec *)(self + 0x38));
    VecCopy((Vec *)(self + 0x50), (const Vec *)(self + 0x38));
    VecCopy((Vec *)(self + 0x290), (const Vec *)(self + 0x38));
    VecCopy((Vec *)(self + 0x29C), (const Vec *)(self + 0x38));
    *(s16 *)(self + 0x374) = 0;
    *(s16 *)(self + 0x396) = 0;
    *(s16 *)(self + 0x382) = -1;
    *(s16 *)(self + 0x384) = 0;
    *(s16 *)(self + 0x380) = 0;
    *(u8 *)(self + 0x378) = CLAMP_800C1C4C((s16)*(f32 *)(self + 0x354), 0, 1);
    *(s16 *)(self + 0x37A) = 0;
    *(void **)(self + 0x350) = (u8 *)lbl_80492EC4;
    init_collision_body_parts(self, (u8 *)lbl_80492EFC, 1);
    if (set->fa > 0) {
        *(s16 *)(self + 0x374) |= 0x60;
        *(u8 *)(self + 0x378) = 1;
        *(u32 *)(self + 0x30) &= ~0x800000;
        *(u32 *)(*(u8 **)(self + 0xA4) + 0x18) &= ~1;
    }
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)(lappy_boss_stats_handles[*(s32 *)(self + 0x368)]), (u8 *)(lappy_boss_stats_ptrs_b[*(s32 *)(self + 0x368)]), (u8 *)(lappy_object_handles[*(s32 *)(self + 0x368)]));
    apply_variant_speeds__12TObjEneLappyFv(self);
    *(s16 *)(self + 0x32C) = *(s16 *)(self + 0x2B8);
    *(s16 *)(self + 0x32E) = *(s16 *)(self + 0x2BA);
    *(s16 *)(self + 0x33E) = *(s16 *)(self + 0x32C);
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    ((TObjPlayer *)self)->reset_photon_effect();
    scale = lbl_805D9F84 * (lbl_805D9F60 + calc_boss4_scale__10TObjPlayerFi(self));
    *(s16 *)(self + 0x37E) = lbl_805D9F2C * scale;
    add_flags_2e4__13TUnk_804806E8FUl(self, 1, scale, lbl_805D9F84);
    *(u32 *)(self + 0x30) |= 0x40000;
    *(void **)(self + 0xD8) = (u8 *)rappy_variant_speed_table;
    ((TObjMotion *)self)->set_field_d8((s32)(*(void **)(self + 0xD8)));
    *(s16 *)(self + 0xB8) = 0;
    ((TObjMotion *)self)->set_animation(*(s16 *)(self + 0xB8));
    ((TObjMotion *)self)->set_field_b8(*(s16 *)(self + 0xB8));
    *(u8 *)(self + 0x379) = *(u8 *)(self + 0x378);
    if (TObjEneDD::check_v2_mode() != 0 && calc_boss4_scale__10TObjPlayerFi(self) < lbl_805D9F98) {
        *(s16 *)(self + 0x374) |= 0x400;
    }
    ((TObjEneLappy *)self)->clear_lobby_object_state();
    return self;
}

int TObjEneLappy::test_flag_256() { return 0; }

void TObjEneLappy::set_speed_params(s32 arg1) {
    s32 var_r0;
    s32 var_r0_2;

    if (TLobby::get_instance() == 0) {
        *(s32 *)((s8 *)this + 0x34) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)rappy_bml_resource + 0x42C)) + 8);
    } else {
        if (arg1 == 0) {
            var_r0 = *(s32 *)((s8 *)(*(void **)((s8 *)rappy_bml_resource + 0x42C)) + 8);
        } else {
            var_r0 = *(s32 *)((s8 *)(*(void **)((s8 *)rappy_bml_resource + 0x42C)) + 0x18);
        }
        *(s32 *)((s8 *)this + 0x34) = var_r0;
    }
    if (arg1 == 0) {
        var_r0_2 = *(s32 *)((s8 *)(*(void **)((s8 *)rappy_bml_resource + 0x42C)) + 0xC);
    } else {
        var_r0_2 = rappy_alternate_texture_list;
    }
    this->texture_id = var_r0_2;
}

void TObjEneLappy::sub_800C20B0() {
    this->m_374 = (s16) (this->m_374 & 0xFFFFFFFE);
}

void TObjEneLappy::sub_800C20C0() {
    this->m_374 = (s16) (this->m_374 | 1);
}
extern "C" {
__declspec(section ".sdata2") extern const f32 lbl_805D9F24 = 0.5f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F28 = 10.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F2C = 30.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F30 = 150.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F34 = 400.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F38 = 2.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F3C = 1.5f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F40 = 0.66666668653488159f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F44 = 182.04444885253906f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F48 = 360.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F4C = 0.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F50 = 10000.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F54 = 11.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F58 = 0.94999998807907104f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F5C = 14.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F60 = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F64 = 3.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F68 = 100.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F6C = 50.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F70 = 22500.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F74 = 3.5f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F78 = 15.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F7C = 300.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F80 = 45.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F84 = 6.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F88 = 2500.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F8C = -6.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F90 = 120.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F94 = 0.0020000000949949026f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F98 = 0.033333335071802139f;
__declspec(section ".sdata2") extern const f32 lbl_805D9F9C = 0.0f;
}

void TObjEneRe2Flower::vfunc_106() {
    s32 save8;
    s32 save14;
    if (((Obj_800C20D0 *)this)->m8(400.0f, 25.0f) == 0) {
        return;
    }
    Vec_800C20D0 v = lbl_8043BBC0[0];
    update_player_state__9TObjEneDDFv(((Obj_800C20D0 *)this), &v, 0);
    if (((TObjEneRe2Flower *)((Obj_800C20D0 *)this))->get_flag_11() == 0 && sub_800C3B8C__16TObjEneRe2FlowerFv(((Obj_800C20D0 *)this)) != 0) {
        save8 = ((Obj_800C20D0 *)this)->model->mat->f8;
        save14 = ((Obj_800C20D0 *)this)->model->mat->f14;
        ((Obj_800C20D0 *)this)->model->mat->f8 = ((Obj_800C20D0 *)this)->model->mat->f20;
        ((Obj_800C20D0 *)this)->model->mat->f14 = ((Obj_800C20D0 *)this)->model->mat->f2C;
    }
    set_global_param__8TObjFishFl(((Obj_800C20D0 *)this)->model);
    push_matrix();
    post_translate_matrix(&((Obj_800C20D0 *)this)->pos);
    rotate_matrix_y(0, ((Obj_800C20D0 *)this)->f60);
    TObjEneDD::clear_global_flag_400();
    toggle_particle_effect__10TObjPlayerFv();
    set_scene_override(0);
    draw_chunk_object(((Obj_800C20D0 *)this)->f34);
    restore_default_scene();
    end_effect_render__13TParticleCtrlFv();
    pop_matrix();
    if (((TObjEneRe2Flower *)((Obj_800C20D0 *)this))->get_flag_11() == 0 && sub_800C3B8C__16TObjEneRe2FlowerFv(((Obj_800C20D0 *)this)) != 0) {
        ((Obj_800C20D0 *)this)->model->mat->f8 = save8;
        ((Obj_800C20D0 *)this)->model->mat->f14 = save14;
    }
}
void TObjPlayer__sub_800C220C(Obj_800C220C *o) {
    s32 visible;
    s32 save8;
    s32 save14;
    if (TObjPlayer::check_demo_mode() != 0) {
        o->m104();
        return;
    }
    if (o->f326 == 11) {
        return;
    }
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        if (((TObjEneRe2Flower *)o)->get_flag_11() != 0) {
            visible = o->m9(600.0f, 600.0f, 25.0f);
        } else {
            visible = o->m9(lbl_805D9E88, lbl_805D9E84, 25.0f);
        }
    } else if (o->m8(400.0f, 25.0f) != 0) {
        visible = 1;
    } else {
        visible = 0;
    }
    if (visible != 0) {
        if (o->f326 != 10) {
            Vec_800C220C v = lbl_8043BBB4[0];
            update_player_state__9TObjEneDDFv(o, &v, 0);
        }
        ((TObjEneDD *)o)->update_secondary_light();
        if (((TObjEneRe2Flower *)o)->get_flag_11() == 0 && sub_800C3B8C__16TObjEneRe2FlowerFv(o) != 0) {
            save8 = o->model->mat->f8;
            save14 = o->model->mat->f14;
            o->model->mat->f8 = o->model->mat->f20;
            o->model->mat->f14 = o->model->mat->f2C;
        }
        set_global_param__8TObjFishFl(o->model);
        push_matrix();
        post_translate_matrix(&o->pos);
        rotate_matrix_y(0, o->f3C0);
        saved_model_render_flags = model_render_flags;
        set_scene_override(0);
        TObjEneDD::clear_global_flag_400();
        translate_matrix(0, lbl_805D9FAC, o->f3C8, lbl_805D9FAC);
        lbl_805D517C = o->f60 - o->f3C0;
        lbl_805D5180 = &o->f3DC;
        o->f3DC = lbl_805D9FAC;
        o->f3E0 = lbl_805D9FB0;
        o->f3E4 = lbl_805D9FAC;
        o->f3E8 = lbl_805D9FAC;
        o->f3EC = lbl_805D9FB4;
        o->f3F0 = lbl_805D9FAC;
        scale_matrix(0, lbl_805D9FB8, lbl_805D9FB8, lbl_805D9FB8);
        TObjEneRe7Berura::set_global_state((s32)((void *)TObjPlayer::update_effect_sequence));
        if (o->f326 == 8) {
            s32 c = (o->f3D8 & 0xFF) << 16;
            lbl_805D5178 = -1;
            toggle_particle_effect__10TObjPlayerFv();
            ((TObjEneDD_ST *)o)->draw_with_alt_model(c);
            end_effect_render__13TParticleCtrlFv();
        } else {
            lbl_805D5178 = 0;
            toggle_particle_effect__10TObjPlayerFv();
            if (o->f3C4 & 8) {
                if (o->sub.m8() != 0) {
                    o->sub.m6();
                    if (defer_render__7TObjectFv(o) == 0) {
                        draw__10TObjMotionFv(o);
                    }
                    o->sub.m7();
                }
            } else if (visible == 1) {
                draw__10TObjMotionFv(o);
            } else {
                render_world_model__9TObjEnemyFv(o);
            }
            end_effect_render__13TParticleCtrlFv();
        }
        TObjEneRe7Berura::set_global_state(0);
        restore_default_scene();
        model_render_flags = saved_model_render_flags;
        pop_matrix();
        ((TObjEneDD *)o)->update_primary_light();
        if (((TObjEneRe2Flower *)o)->get_flag_11() == 0 && sub_800C3B8C__16TObjEneRe2FlowerFv(o) != 0) {
            o->model->mat->f8 = save8;
            o->model->mat->f14 = save14;
        }
        return;
    }
    o->f3DC = o->pos.x;
    o->f3E0 = lbl_805D9FB0 + o->pos.y;
    o->f3E4 = o->pos.z;
    o->f3E8 = o->pos.x;
    o->f3EC = lbl_805D9FB4 + o->pos.y;
    o->f3F0 = o->pos.z;
}
}

#undef toggle_particle_effect__10TObjPlayerFv
#undef end_effect_render__13TParticleCtrlFv
#undef rotate_matrix_y
#undef push_matrix
#undef pop_matrix
#undef post_translate_matrix
#undef set_global_param__8TObjFishFl
#undef draw_chunk_object
#undef scale_matrix
#undef draw__10TObjMotionFv
#undef render_world_model__9TObjEnemyFv
#undef apply_variant_speeds__12TObjEneLappyFv
#undef render__12TObjEneLappyFv
