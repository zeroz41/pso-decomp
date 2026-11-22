#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/TObjControl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
extern "C" const u8 rappy_variant_na_name[3] = "NA";
void *TObjEneLappy__model_filename_table[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_lappy_base.nj", (void *)0x0,
};
void *lbl_80492BE4[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492C10[4] = {
    (void *)"bm_ene_lappy.bml", (void *)&TObjEneLappy__model_filename_table, (void *)&lbl_80492BE4, (void *)0x2000a,
};
void *lbl_80492C20[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_lappy_base.nj", (void *)0x0,
};
void *lbl_80492C2C[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492C58[4] = {
    (void *)"bm_ene_lappy_ap.bml", (void *)&lbl_80492C20, (void *)&lbl_80492C2C, (void *)0x2000a,
};
void *lbl_80492C68[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_elappy_base.nj", (void *)0x0,
};
void *lbl_80492C74[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492CA0[4] = {
    (void *)"bm_ene_lappy_es.bml", (void *)&lbl_80492C68, (void *)&lbl_80492C74, (void *)0x2000a,
};
void *lbl_80492CB0[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_elappy_base.nj", (void *)0x0,
};
void *lbl_80492CBC[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492CE8[4] = {
    (void *)"bm_ene_lappy_ap_es.bml", (void *)&lbl_80492CB0, (void *)&lbl_80492CBC, (void *)0x2000a,
};
void *lbl_80492CF8[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_hlappy_base.nj", (void *)0x0,
};
void *TObjEneLappy__resource_name_table[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492D30[4] = {
    (void *)"bm_ene_lappy_hw.bml", (void *)&lbl_80492CF8, (void *)&TObjEneLappy__resource_name_table, (void *)0x2000a,
};
void *lbl_80492D40[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_hlappy_base.nj", (void *)0x0,
};
void *TObjEneLappy__resource_list[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492D78[4] = {
    (void *)"bm_ene_lappy_ap_hw.bml", (void *)&lbl_80492D40, (void *)&TObjEneLappy__resource_list, (void *)0x2000a,
};
void *lbl_80492D88[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_slappy_base.nj", (void *)0x0,
};
void *lbl_80492D94[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492DC0[4] = {
    (void *)"bm_ene_lappy_xs.bml", (void *)&lbl_80492D88, (void *)&lbl_80492D94, (void *)0x2000a,
};
void *lbl_80492DD0[3] = {
    (void *)"re3_b_lappy_base.nj", (void *)"re3_s_slappy_base.nj", (void *)0x0,
};
void *lbl_80492DDC[11] = {
    (void *)"attack_re3_b_base.njm", (void *)"damage_re3_b_base.njm", (void *)"die_re3_b_base.njm", (void *)"run_re3_b_base.njm",
    (void *)"tumble_re3_b_base.njm", (void *)"wait2_re3_b_base.njm", (void *)"wait_re3_b_base.njm", (void *)"wake2_re3_b_base.njm",
    (void *)"wake_re3_b_base.njm", (void *)"walk_re3_b_base.njm", (void *)0x0,
};
void *lbl_80492E08[4] = {
    (void *)"bm_ene_lappy_ap_xs.bml", (void *)&lbl_80492DD0, (void *)&lbl_80492DDC, (void *)0x2000a,
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
    (void *)"RAG-LAPPY", (void *)"AL-LAPPY", (void *)&rappy_variant_na_name,
};
void *lbl_80492EC4[14] = {
    (void *)0x43160000, (void *)0x3f097b42, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0, (void *)0x43160000,
    (void *)0x3f097b42, (void *)0x400, (void *)0x1e0000, (void *)0x0,
    (void *)0x1, (void *)0x0,
};
CollisionBody lbl_80492EFC[1] = {
    {{0.0f, 7.5f, 0.0f}, 7.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TObjEneLappy__class_name = "TObjEneLappy";


const NpcAnimationBinding lappy_resource_binding_desc = { NULL, reinterpret_cast<TObjMotionAction *>(rappy_variant_speed_table), 1, 3, 10 };

const Vec lappy_target_zero_vec = {0.0f, 0.0f, 0.0f};

extern "C" __declspec(section ".data") s32 lappy_variant_speed_ptr_table[2];
#define lappy_variant_speed_ptr_table ((f32 * *)lappy_variant_speed_ptr_table)

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

#include <stddef.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/AreaSoundRemap.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
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

struct Lappy_800C0318 { u8 pad0[0x2FC]; Vec pos; f32 vx; f32 vy; f32 vz; };


void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 play_sound_effect(s32, u32, s32, s32);
void run_death_reaction__12TObjEneLappyFv(u8 *arg0);
void run_hit_reaction__12TObjEneLappyFv(u8 *arg0);
void run_miss_reaction__12TObjEneLappyFv(void *arg0);
void run_attack_action__12TObjEneLappyFv(void *arg0);
s32 TObjEneDD__sub_800B9B24(f32);
s32 is_item_light_interaction_blocked();
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
f32 post_translate_matrix(void *);
s32 draw_chunk_object(int);
s32 lappy_variant_id;
void *rappy_bml_resource;
s32 *rappy_visibility_node;
s32 rappy_alternate_texture_list;
extern s32 model_render_flags;
void render__12TObjEneLappyFv(u8 *arg0);
void TObjPlayer__sub_800BFF54(void * _w0);
s32 minimap_render_dot(void *, int, int, int);
void run_task__12TObjEneLappyFv(u8 *arg0);
s32 check_path_obstructed(void *, void *);
s32 get_entity_id(void *);
extern s32 lbl_805D5870;
void refresh_target__12TObjEneLappyFv(u8 *arg0);
}
extern f32 identity_matrix[3][4];
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 select_enemy_destination(void *, struct Sp800C0D3C *, s32);
void run_move_action__12TObjEneLappyFv(void *arg0);
void run_idle_action__12TObjEneLappyFv(void *arg0);
s32 enemy_backstep_from_point(void *, void *, f32);
f32 update_enemy_wander_move(void *, void *, int, f32);
f32 atan2_float(f32 y, f32 x);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
s32 update_action_hold_status__12TObjEneLappyFv(s32 arg0);
s32 update_movement_status__12TObjEneLappyFv(s32 arg0);
s32 obj_setFlags30(void *, s32);

void TObjEneLappy::clear_flags_60() {
    s16 flags;

    flags = m_374;
    if (flags & 0x60) {
        m_374 = flags & ~0x60;
        project_actor_to_ground(this, &position, 0);
        obj_setFlags30(this, 0x800000);
    }
}

s32 TObjEneLappy::update_movement_status() {
    saddr self = (saddr)this;
    if (TObjChara::update_movement_status() != 0) {
        ((TObjEneLappy *)self)->clear_flags_60();
        return 1;
    }
    return 0;
}

s32 TObjEneLappy::update_action_hold_status() {
    saddr self = (saddr)this;
    if (TObjChara::update_action_hold_status() != 0) {
        ((TObjEneLappy *)self)->clear_flags_60();
        return 1;
    }
    return 0;
}

void TObjPlayer::set_flag_and_notify() {
    s16 temp_r4;

    temp_r4 = *(s16 *)((s8 *)this + 0x374);
    if (!(temp_r4 & 0x80)) {
        *(s16 *)((s8 *)this + 0x374) = (s16) (temp_r4 | 0x80);
        ((TObjEnemy *)this)->send_entity_set_flags();
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
    Vec next;
    Vec step;
    Vec probe;
    s32 angle;
    s32 dir;
    s32 tries;
    VecCopy(&prev_position, &position);
    VecCopy(&next, &body_center);
    vec3_add_to(&next, (Vec *)unk_308);
    if (is_actor_cadence_frame(0x1E) != 0) {
        if (csnVector(&body_center, &next, -1) != NULL) {
            return 0;
        }
        if (random_ratio() < 0.5f) {
            dir = -1;
        } else {
            dir = 1;
        }
        tries = 0;
        angle = 0;
loop_7:
        if (tries == 0) {
            VecCopy(&step, (Vec *)unk_308);
        } else {
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, (int)(dir * angle));
            rotate_vector_by_matrix(0, (Vec *)unk_308, &step);
            pop_matrices(1);
        }
        VecCopy(&probe, &position);
        vec3_add_to(&probe, &step);
        if (project_actor_to_ground(this, &probe, 0) == 1) {
            VecCopy(&position, &probe);
            VecCopy((Vec *)unk_308, &position);
            subtract_vector((Vec *)unk_308, &prev_position);
            return 1;
        }
        tries += 1;
        angle += 0x1000;
        if (tries >= 0xF) {
            return 0;
        }
        goto loop_7;
    }
    if (project_actor_to_ground(this, &next, 0) == 1) {
        VecCopy(&position, &next);
        VecCopy((Vec *)unk_308, &position);
        subtract_vector((Vec *)unk_308, &prev_position);
        return 1;
    }
    return 0;
}

void TObjEneLappy::play_walk_sound() {
    u8 *self = (u8 *)this;
    if (((s16) this->requested_action == 3) && ((((TObjMotion *)self)->is_passing_frame(10.0f) != 0) || (((TObjMotion *)self)->is_passing_frame(30.0f) != 0))) {
        play_sound_effect(remap_area_sound_id(0x3D20C, 5), (uaddr)(self + 0x38), 0, 0);
    }
}
void TObjPlayer__sub_800BFF54(void * _w0) {  }

void TObjEneLappy::render() {
    s32 temp_r3;
    if (obj_testFlags30(0x02000000) == 0) {
        if (this->m_374 & 1) {
            *rappy_visibility_node &= 0xFFFFFFF7;
        } else {
            *rappy_visibility_node |= 8;
        }
        temp_r3 = this->classify_actor_view_detail(150.0f, 400.0f, 10.0f);
        if (temp_r3 != 0) {
            set_speed_params(this->variant);
            TObjFish::set_global_param(this->texlist);
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            rotate_matrix_y(0, this->rotation_y);
            if (this->m_374 & 0x400) {
                scale_matrix(0, 2.0f, 1.5f, 2.0f);
                TObjEneDD__sub_800B9B24(0.6666667f);
            }
            model_render_flags &= 0xFFFFFBFF;
            set_motion_packed_rotation();
            if (is_item_light_interaction_blocked() == 1) {
                draw_chunk_object((int) (*(s32 *)((s8 *)((u8 *)this) + 0x34)));
            } else {
                model_render_flags |= 0x01000000;
                if (temp_r3 == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                model_render_flags &= 0xFEFFFFFF;
            }
            clear_motion_packed_rotation();
            if (this->m_374 & 0x400) {
                TObjEneDD::init_lights();
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(this->actorFlags & 0x800) && (obj_testFlags30(0x800000) != 0)) {
                this->TObjEnemy::draw_ground_shadow(0, 0);
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
        this->m_390 = (s32) (182.04445f * (360.0f * random_ratio()));
    }
    this->mode = 1;
    this->m_37a = 3;
    ((struct VObj_800C00F4_800BFBBC *)this)->m48();
    this->hp = 1;
    this->actorFlags = (s32) (this->actorFlags & ~0xA00);
}
void TObjEneLappy::apply_move_friction() {
    sub_800C20B0();
    advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(this, 0, 0.0f);
    }
    refresh_collision_body_centers();
    if (this->frame < (0.5f * (30.0f * this->play_speed))) {
        move_with_wall_slide((u8 *)this);
        *(f32 *)((s8 *)this + 0x308) *= 0.5f;
        this->m_310 *= 0.5f;
    }
}
void TObjEneLappy::run_death_reaction() {
    s16 temp_r3;
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    temp_r3 = this->m_374;
    if (temp_r3 & 2) {
        if (!(temp_r3 & 4)) {
            this->m_374 = (s16) (temp_r3 | 4);
            play_sound_effect((s32)(((s32)remap_area_sound_id(0x3AD13, 5))), (uaddr)(((u8 *)this) + 0x38), 0, 0);
            ((TObjPlayer *)((u8 *)this))->query_lobby_state();
            this->requested_action = 8;
        }
    } else if ((s16) this->mode != 5) {
        this->mode = 5;
        this->requested_action = 7;
        if (!(this->m_374 & 0x10)) {
            play_sound_effect((s32)(((s32)remap_area_sound_id(0x3AE10, 5))), (uaddr)(((u8 *)this) + 0x38), 0, 0);
            this->distribute_experience();
            ((TObjPlayer *)((u8 *)this))->set_flag_and_notify();
        }
        this->m_380 = 0;
    }
}

void TObjEneLappy::update_hurt() {
    u8 *arg0 = (u8 *)this;
    ((TObjMotion *)arg0)->advance_animation();
    Lappy_800C0318 *self = (Lappy_800C0318 *)arg0;
    Vec v = self->pos;
    v.x += self->vx;
    v.z += self->vz;
    if (check_path_obstructed(arg0, &v) == 0) {
        move_with_wall_slide(arg0);
    } else {
        self->vx = self->vz = 0.0f;
    }
    self->vx *= 0.5f;
    self->vz *= 0.5f;
    apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
    ((TObjPlayer *)arg0)->update_collisions();
    if (this->action_flags != 8U) {
        this->actorFlags &= ~0x200;
        this->referenceHp = this->hp;
        if (this->m_374 & 2) {
            ((TObjEneLappy *)arg0)->set_boss4_state();
            this->requested_action = 4;
        }
    }
}

void TObjEneLappy::run_hit_reaction() {
    saddr temp_r3;
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    if (this->m_374 & 2) {
        this->obj_clearFlags30(0x23F);
        return;
    }
    if ((s16) this->mode != 4) {
        this->mode = 4;
        this->requested_action = 6;
        temp_r3 = (saddr)get_player_by_client_id(this->attacker_id);
        if ((temp_r3 != 0) && !(xyz_distance_squared((Vec *)(((u8 *)this) + 0x38), (Vec *)(temp_r3 + 0x38)) < 10000.0f)) {
            this->m_374 = (s16) (this->m_374 | 2);
            ((TObjPlayer *)((u8 *)this))->set_flag_and_notify();
        }
        play_sound_effect(remap_area_sound_id(0x3B10F, 5), (uaddr)(((u8 *)this) + 0x38), 0, 0);
    }
}

void TObjEneLappy::update_invuln_timer() {
    u8 *self = (u8 *)this;
    s16 temp_r4;
    ((TObjMotion *)self)->advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity((TObjEnemy *)self, (s32 *)NULL, 0.0f);
    }
    ((TObjPlayer *)self)->update_collisions();
    temp_r4 = this->timer;
    this->timer = (temp_r4 - 1);
    if (temp_r4 < 0) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        this->timer = (s16) this->resetTimer;
        this->referenceHp = (s16) this->hp;
    }
}

void TObjEneLappy::run_miss_reaction() {
    if ((s16) this->mode != 3) {
        this->mode = 3;
        this->requested_action = 1;
        this->actorFlags = (s32) (this->actorFlags & 0xFF9FFFFF);
    }
}

void TObjEneLappy::update_attacking() {
    u8 *self = (u8 *)this;
    u8 *temp_r3;
    ((TObjMotion *)self)->advance_animation();
    switch (this->phase) {
    case 0:
        ((TObjEnemy *)self)->enemy_turn_toward_dest((saddr)((void *) *(saddr *)((s8 *)this->movementParameters + 8)));
        apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        if (((TObjMotion *)self)->is_passing_frame(11.0f) != 0) {
            enemy_set_heading_velocity(*(f32 *)((s8 *)this->movementParameters + 4), (TObjEnemy *)(self), this->rotation_y);
            this->y_speed = 0.0f;
            this->phase = 1;
        }
        break;
    case 1:
        VecCopy((Vec *)(self + 0x44), (const Vec *)(self + 0x38));
        *(f32 *)((s8 *)self + 0x38) += *(f32 *)((s8 *)self + 0x308);
        *(f32 *)((s8 *)self + 0x308) *= 0.95f;
        *(f32 *)((s8 *)self + 0x40) += this->m_310;
        this->m_310 *= 0.95f;
        apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        if (((TObjMotion *)self)->is_passing_frame(14.0f) != 0) {
            temp_r3 = this->target;
            if (temp_r3 != NULL && ((VObj_18_800C0588 *) temp_r3)->m18(self, 1.0f) != 0) {
                ((VObj_18_800C0588 *) this->target)->m20(self, 1.0f);
                ((VObj_18_800C0588 *) this->target)->m23(self, 3.0f);
            }
            play_sound_effect(remap_area_sound_id(0x3BC0D, 5), (uaddr)(self + 0x38), 0, 0);
            this->phase = 2;
            this->timer = 0x1E;
        }
        break;
    case 2:
        apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        (this->timer)--;
        if (this->timer < 0) {
            this->phase = 3;
        }
        break;
    case 3:
        VecCopy((Vec *)(self + 0x44), (const Vec *)(self + 0x38));
        *(f32 *)((s8 *)self + 0x38) += *(f32 *)((s8 *)self + 0x308);
        *(f32 *)((s8 *)self + 0x40) += this->m_310;
        apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        if (this->action_flags != 4U) {
            *(f32 *)((s8 *)self + 0x308) = this->y_speed = this->m_310 = 0.0f;
            this->actorFlags &= 0xFFDFFFFF;
            this->run_move_action();
            this->timer = 0;
        }
        break;
    }
    ((TObjPlayer *)self)->update_collisions();
}

void TObjEneLappy::run_attack_action() {
    u16 temp_r4;
    if (!(this->m_374 & 0x42) && (obj_testFlags30(0xA02) == 0) && ((s16) this->mode != 2)) {
        this->mode = 2;
        this->requested_action = 5;
        this->phase = 0;
        *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags | 0x200000);
        if ((s16) this->m_382 != (s32) (temp_r4 = this->targetId)) {
            this->m_382 = (s16) temp_r4;
            this->m_384 = 0;
        } else {
            this->m_384 = (s16) (this->m_384 + 1);
        }
        this->m_388 = 0;
    }
}
#pragma push
#pragma opt_common_subs off
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_30_offset, offsetof(RecoveredFields_800C1478_arg0, field_30) == 0x30);
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_A4_offset, offsetof(RecoveredFields_800C1478_arg0, field_A4) == 0xA4);
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_B8_offset, offsetof(RecoveredFields_800C1478_arg0, field_B8) == 0xB8);
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_2A8_offset, offsetof(RecoveredFields_800C1478_arg0, field_2A8) == 0x2A8);
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_30C_offset, offsetof(RecoveredFields_800C1478_arg0, field_30C) == 0x30C);
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_326_offset, offsetof(RecoveredFields_800C1478_arg0, field_326) == 0x326);
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_338_offset, offsetof(RecoveredFields_800C1478_arg0, field_338) == 0x338);
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_374_offset, offsetof(RecoveredFields_800C1478_arg0, field_374) == 0x374);
LAYOUT_ASSERT(RecoveredFields_800C1478_arg0_380_offset, offsetof(RecoveredFields_800C1478_arg0, field_380) == 0x380);
LAYOUT_ASSERT(RecoveredFields_800C1478_temp_r3_30_offset, offsetof(RecoveredFields_800C1478_temp_r3, field_30) == 0x30);
LAYOUT_ASSERT(RecoveredFields_800C1478_temp_r3_2_18_offset, offsetof(RecoveredFields_800C1478_temp_r3_2, field_18) == 0x18);

void TObjEneLappy::update_moving() {
    u8 *self = (u8 *)this;
    Vec probe;
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
    ((TObjMotion *)self)->advance_animation();
    if ((*(s32 *)&this->actorFlags & 0x1000) && !(this->m_374 & 2)) {
        temp_r6 = this->target;
        if (temp_r6 != NULL) {
            Vec target1 = *(Vec *)(temp_r6 + 0x2FC);
            enemy_backstep_from_point(self, &target1.x, (f32) (*(f32 *)((s8 *)((u8 *)(*(u8 * *)&this->movementParameters)) + 4)));
            turn_toward_direction(*(s32 *)((u8 *)movementParameters + 8), (Vec *)unk_308);
            apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
            ((TObjPlayer *)self)->update_collisions();
            return;
        }
    }
    temp_r3 = this->action_flags;
    if (temp_r3 == 1U) {
        switch (*(s16 *)&this->m_37a) {
        case 0:
            temp_r7 = this->target;
            if (temp_r7 != NULL) {
                Vec target2 = *(Vec *)(temp_r7 + 0x2FC);
                temp_f31 = update_enemy_wander_move(self, &target2.x, 1, (f32) (*(f32 *)((s8 *)((u8 *)(*(u8 * *)&this->movementParameters)) + 4)));
                if ((((TObjCollidable *)self)->obj_testFlags30(2) == 0) && (temp_f31 < 10000.0f)) {
                    *(s16 *)&this->m_37a = 1;
                    *(s32 *)((s8 *)self + 0x398) = 0;
                    ((TObjChara *)self)->random_ratio();
                    this->m_39c = 0.0f;
                }
                temp_r3_2 = (u8 *)(*(u8 * *)&this->movementParameters);
                if (*(f32 *)((s8 *)temp_r3_2 + 0) * *(f32 *)((s8 *)temp_r3_2 + 0) < temp_f31 || temp_f31 < *(f32 *)((s8 *)temp_r3_2 + 4) * *(f32 *)((s8 *)temp_r3_2 + 4)) {
                    this->target = NULL;
                }
            } else {
                temp_r4 = (u8 *)(*(u8 * *)&this->movementParameters);
                ((TObjEnemy *)(self))->enemy_wander_home(*(f32 *)((s8 *)temp_r4 + 4), 100.0f, 50.0f, *(s32 *)((s8 *)temp_r4 + 8));
            }
            turn_toward_direction(*(s32 *)((u8 *)movementParameters + 8), (Vec *)unk_308);
            play_walk_sound();
            goto block_48;
        case 1:
            temp_r7_2 = this->target;
            if (temp_r7_2 != NULL) {
                Vec target3 = *(Vec *)(temp_r7_2 + 0x2FC);
                temp_f1 = update_enemy_wander_move(self, &target3.x, 1, (f32) (*(f32 *)((s8 *)((u8 *)(*(u8 * *)&this->movementParameters)) + 4)));
                if (temp_f1 > 22500.0f) {
                    *(s16 *)&this->m_37a = 0;
                }
                turn_toward_direction(*(s32 *)((u8 *)movementParameters + 8), (Vec *)unk_308);
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
            this->rotation_y = lerp_angle_half(this->rotation_y, this->m_390);
            if ((u32) this->action_flags == 1U) {
                *(s32 *)&this->actorFlags = (*(s32 *)&this->actorFlags & 0xFBFFFFFF);
                *(s16 *)&this->m_37a = 4;
                play_sound_effect(remap_area_sound_id(0x3AF12, 5), (uaddr)(self + 0x38), 0, 0);
            }
            if (((TObjMotion *)self)->is_passing_frame(30.0f) != 0) {
                play_sound_effect(remap_area_sound_id(0x3AA11, 5), (uaddr)(self + 0x38), 0, 0);
            }
            goto block_48;
        case 4:
            if (temp_r3 == 1U) {
                enemy_set_heading_velocity((f32) (3.5f * *(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4)), (TObjEnemy *)(self), this->rotation_y);
                *(s16 *)&this->unk_394 = (s16) (*(s16 *)&this->unk_394 + 1);
                if (((f32) *(s16 *)&this->unk_394 > 15.0f) && (find_nearest_visible_player(reinterpret_cast<TObjChara *>(self), &probe, 300.0f) != 0xFFFFU) && (angle_difference_abs(this->rotation_y, (int) ((s32) (10430.38043493439 * atan2_float(probe.x, probe.z)))) < 0xAAA)) {
                    if (((TObjChara *)self)->random_ratio() >= 0.5f) {
                        var_r4 = -0x4000;
                    } else {
                        var_r4 = 0x4000;
                    }
                    this->rotation_y = (s32) (this->rotation_y + var_r4);
                    *(s16 *)&this->unk_394 = 0;
                }
                if (((TObjEneLappy *)self)->advance_flee_step() == 0) {
                    ((TObject *)self)->queue_destruction();
                    return;
                }
                if (--*(s16 *)&this->m_396 < 0) {
                    spawn_particle_effect(&this->position, 0xF3);
                    *(s16 *)&this->m_396 = 2;
                }
                play_persistent_sound((s32)(((TObjEnemy *)(self))->remap_sound_for_area(0x3AF12)), (saddr)self, (uaddr)&this->position, (s32)(0), (s32)(0));
                goto block_47;
            }
block_47:
            apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
            ((TObjCollidable *)self)->refresh_collision_body_centers();
            return;
        }
    }
block_48:
        apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        ((TObjPlayer *)self)->update_collisions();
}

void TObjEneLappy::run_move_action() {
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
                        this->requested_action = 3;
                        break;
                    case 1:
                        this->requested_action = 2;
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
        temp_r3 = this->bodies;
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
            range = 10.0f;
        } else {
            range = 100.0f;
        }
        if (xz_distance_squared((Vec *)(arg0 + 0x38), (Vec *)(arg0 + 0x50)) > range * range) {
            *(u8 *)((s8 *)arg0 + 0x378) = 2;
            ((TObjPlayer *)arg0)->requested_action = 3;
        } else if ((s8) *(u8 *)((s8 *)arg0 + 0x378) != (s8) ((TObjPlayer *)arg0)->m_379) {
            *(u8 *)((s8 *)arg0 + 0x378) = ((TObjPlayer *)arg0)->m_379;
            ((TObjPlayer *)arg0)->phase = 0;
        }
    }
    switch ((s8) *(u8 *)((s8 *)arg0 + 0x378)) {
    case 0:
        switch (((TObjPlayer *)arg0)->phase) {
        case 0:
            *(s16 *)((s8 *)arg0 + 0x37E) = (s16) (45.0f * (1.0f + ((TObjChara *)arg0)->random_ratio()));
            ((TObjPlayer *)arg0)->phase = ((TObjPlayer *)arg0)->requested_action = 1;
        case 1:
            (*(s16 *)((s8 *)arg0 + 0x37E))--;
            if (*(s16 *)((s8 *)arg0 + 0x37E) < 0) {
                play_sound_effect(remap_area_sound_id(0x3B20B, 5), (uaddr)(arg0 + 0x38), 0, 0);
                ((TObjPlayer *)arg0)->phase = 2;
            }
            break;
        case 2:
            *(f32 *)((s8 *)arg0 + 0x38C) = 30.0f;
            ((TObjPlayer *)arg0)->phase = ((TObjPlayer *)arg0)->requested_action = 3;
        case 3:
            ((TObjEnemy *)(arg0))->enemy_wander_home(*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4), 100.0f, 100.0f, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8));
            *(f32 *)((s8 *)arg0 + 0x38C) -= *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4);
            if (*(f32 *)((s8 *)arg0 + 0x38C) < 0.0f) {
                ((TObjPlayer *)arg0)->phase = 0;
            }
            break;
        }
        ((TObjMotion *)arg0)->advance_animation();
        break;
    case 1:
        ((TObjPlayer *)arg0)->requested_action = 0;
        ((TObjMotion *)arg0)->advance_animation();
        (*(s16 *)((s8 *)arg0 + 0x37E))--;
        if (*(s16 *)((s8 *)arg0 + 0x37E) < 0) {
            play_sound_effect(remap_area_sound_id(0x3B20B, 5), (uaddr)(arg0 + 0x38), 0, 0);
            *(s16 *)((s8 *)arg0 + 0x37E) = (s16) (30.0f * (6.0f * (1.0f + ((TObjChara *)arg0)->random_ratio())));
        }
        break;
    case 2: {
        ((TObjMotion *)arg0)->advance_animation();
        Vec_800C0E30 v = *(Vec_800C0E30 *)((s8 *)arg0 + 0x50);
        update_enemy_wander_move(arg0, &v, 7, *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4));
        ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((u8 *)((TObjEnemy *)arg0)->movementParameters + 8), (Vec *)((u8 *)arg0 + 0x308));
        break;
    }
    }
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    if (!(((TObjPlayer *)arg0)->actorFlags & 0x800000)) {
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
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

void TObjEneLappy::run_idle_action() {
    s16 flags;
    flags = this->m_374;
    if (!(flags & 2) && !(this->actorFlags & 0xA00)) {
        if (flags & 0x20) {
            this->m_374 = flags & ~0x20;
            this->obj_clearFlags30(0x02000000);
            Vec v = *(Vec *)((s8 *)this + 0x38);
            if (project_actor_to_ground(this, &v, 0) == 1) {
                *(f32 *)((s8 *)this + 0x3C) = 300.0f + v.y;
            }
        }
        if (this->mode != 0) {
            this->mode = 0;
            this->phase = 0;
            switch ((s8) this->m_378) {
            case 0:
                this->requested_action = 3;
                break;
            case 1:
                this->requested_action = 0;
                break;
            }
        }
    }
}

void TObjEneLappy::refresh_target() {
    s32 best_id;
    s32 i;
    s32 id;
    TObjPlayer *p;
    f32 best;
    f32 d;
    if (is_actor_cadence_frame(0x1E) != 0) {
        if (actorFlags & 0x1000) {
            if ((m_2b4 -= 1.0f) < 0.0f) {
                targetId = 0xFFFFU;
                m_2b4 = 0.0f;
            } else {
                targetId = find_nearest_visible_player(this, NULL, *(f32 *)movementParameters);
            }
        } else if (obj_testFlags30(0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec v = lappy_target_zero_vec;
            best = *(f32 *)movementParameters * *(f32 *)movementParameters;
            for (; i < registered_player_count + lbl_805D5870; i++) {
                p = TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                id = get_entity_id(p);
                if ((u16)id < 0x4000 && (u16)id != entity_id && !(p->actorFlags & 0x800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy(&v, &p->body_center);
                    subtract_vector(&v, &body_center);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(this, &p->body_center) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            targetId = best_id;
        } else {
            targetId = find_nearest_visible_player(this, NULL, *(f32 *)movementParameters);
        }
    }
    if (m_384 > 3 && m_382 == targetId) {
        s32 j;
        TObjPlayer *q;
        for (j = 0; j < registered_player_count; j++) {
            q = TObjPlayer::get_player_data(j);
            if (q != NULL && m_382 != (u16) get_entity_id(q) && !(q->actorFlags & 0x800)) {
                if (xz_distance_squared(&q->body_center, &body_center) < 2500.0f) {
                    targetId = j;
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
    sub_800C20C0();
    if (TObjPlayer::check_demo_mode() == 1) {
        apply_variant_speeds();
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
    if ((obj_testFlags30(0x06000000) == 0) && !(((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 & 4)) {
        submit_cursor_candidate(((u8 *)this), -1);
    }
    minimap_render_dot(((u8 *)this) + 0x38, -0x5DB4, 1, 0);
    if (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 & 0x40) {
        ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_30C = (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_30C > -6.0f) ? ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_30C : -6.0f;
        if (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_30 & 0x800000) {
            ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 = (s16) (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 & 0xFFFFFFBF);
            if (TLobby::get_instance() == 1) {
                play_sound_effect(0x3AB44, (uaddr)(((u8 *)this) + 0x38), 0, 0);
            } else {
                play_sound_effect(0x4003AB33, (uaddr)(((u8 *)this) + 0x38), 0, 0);
            }
            temp_r3_2 = (unsigned char *) (((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_A4);
            ((RecoveredFields_800C1478_temp_r3_2 *)temp_r3_2)->field_18 = (s32) (((RecoveredFields_800C1478_temp_r3_2 *)temp_r3_2)->field_18 | 1);
        }
    }
    if ((obj_testFlags30(0x800) != 0) && !(((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_374 & 2)) {
        temp_r5 = ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_380;
        ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_380 = (temp_r5 + 1);
        if ((((VCls18 *)(((u8 *)this)))->vm17(0x1E, temp_r5) != 0) && (((u16)find_nearest_visible_player(this, NULL, 120.0f) == 0xFFFFU) || ((s16) ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_380 >= 0x384))) {
            ((TObjEneLappy *)((u8 *)this))->set_boss4_state();
            ((RecoveredFields_800C1478_arg0 *)((u8 *)this))->field_B8 = 9;
        }
    }
}
#pragma pop


#undef lappy_variant_speed_ptr_table

}

extern void *tl_04;

void *TObjEneLappy::create(void *set) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneLappy(control, set);
}

#define render__12TObjEneLappyFv (*(void (*)())&render__12TObjEneLappyFv)
#define scale_matrix (*(void (*)(int, f32, f32, f32))&scale_matrix)
#define draw_chunk_object (*(s32 (*)(int))&draw_chunk_object)
#define post_translate_matrix (*(s32 (*)(void *))&post_translate_matrix)
#define pop_matrix (*(s32 (*)())&pop_matrix)
#define push_matrix (*(s32 (*)())&push_matrix)
#define rotate_matrix_y (*(s32 (*)(int, int))&rotate_matrix_y)

#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

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

extern "C" {
__declspec(section ".data") saddr lappy_boss_stats_handles[2];
__declspec(section ".data") saddr lappy_boss_stats_ptrs_b[2];
__declspec(section ".data") saddr lappy_object_handles[2];
__declspec(section ".data") s32 lappy_variant_speed_ptr_table[2];

s32 release_texture_list(void*);
}
u8 *load_gvm_texture_file(saddr name);
extern s32 game_difficulty_selection;
extern s32 TLobby__event_theme_id;

void TLobby::cleanup_handles() {
    if (TLobby::get_instance() == 0) {
        if ((u32) (*(u32 *)&rappy_alternate_texture_list) != 0U) {
            release_texture_list((void*)(*(uaddr *)&rappy_alternate_texture_list));
            TAdSinglePlyChrSelectGC::safe_free((*(u32 *)&rappy_alternate_texture_list));
            (*(u32 *)&rappy_alternate_texture_list) = 0U;
        }
    } else {
        (*(u32 *)&rappy_alternate_texture_list) = 0U;
    }
    if ((u32) (*(u32 *)&rappy_bml_resource) != 0U) {
        delete (BmlResource *)(*(uaddr *)&rappy_bml_resource);
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
                p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492E08, 0, 0, NULL);
                (*(u32 *)&rappy_bml_resource) = p;
            } else {
                p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492DC0, 0, 0, NULL);
                (*(u32 *)&rappy_bml_resource) = p;
            }
            break;
        case 4:
            lappy_variant_id = 2;
            if (rare) {
                p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492CE8, 0, 0, NULL);
                (*(u32 *)&rappy_bml_resource) = p;
            } else {
                p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492CA0, 0, 0, NULL);
                (*(u32 *)&rappy_bml_resource) = p;
            }
            break;
        case 5:
            lappy_variant_id = 3;
            if (rare) {
                p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492D78, 0, 0, NULL);
                (*(u32 *)&rappy_bml_resource) = p;
            } else {
                p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492D30, 0, 0, NULL);
                (*(u32 *)&rappy_bml_resource) = p;
            }
            break;
        default:
            lappy_variant_id = 0;
            if (rare) {
                p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492C58, 0, 0, NULL);
                (*(u32 *)&rappy_bml_resource) = p;
            } else {
                p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492C10, 0, 0, NULL);
                (*(u32 *)&rappy_bml_resource) = p;
            }
            break;
        }
    } else {
        lappy_variant_id = 0;
        if (rare) {
            p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492C58, 0, 0, NULL);
            (*(u32 *)&rappy_bml_resource) = p;
        } else {
            p = (saddr)new BmlResource(1, (BmlResourceDescriptor *)lbl_80492C10, 0, 0, NULL);
            (*(u32 *)&rappy_bml_resource) = p;
        }
    }
    if (TLobby::get_instance() == 0) {
        if (rare) {
            (*(u32 *)&rappy_alternate_texture_list) = (uaddr)load_gvm_texture_file((saddr)re3_b_lappy_base_niji_gvm);
        } else {
            (*(u32 *)&rappy_alternate_texture_list) = (uaddr)load_gvm_texture_file((saddr)re3_b_lappy_base_ao_gvm);
        }
    } else {
        (*(u32 *)&rappy_alternate_texture_list) = *(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 0x1C);
    }
    (*(s32 *)&rappy_visibility_node) = (s32)find_model_node((*(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 8)), 0x12);
    for (i = 0; i < 2; i++) {
        lappy_boss_stats_handles[i] = (saddr)TLobby::register_boss(i + 0x18);
        lappy_boss_stats_ptrs_b[i] = (saddr)TLobby::dispatch_shared_handler_b(i + 0x18);
        lappy_object_handles[i] = (saddr)TLobby::register_object(i + 0x18);
        lappy_variant_speed_ptr_table[i] = (saddr)TLobby::dispatch_shared_handler_a(i + 0x18);
    }
    {
        u8 *res = RES_800C17B8;
        NpcAnimationBinding d = lappy_resource_binding_desc;
        d.motions = reinterpret_cast<BmlMotionEntry *>(*(s32 *)(res + 0x430));
        NpcModelRegistry::register_animated_chunk(5, reinterpret_cast<void *>(*(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 8)),
                                        reinterpret_cast<void *>(*(saddr *)(*(u8 **)(RES_800C17B8 + 0x42C) + 0xC)), &d, 10.0f, 0.0f);
        if (TLobby::get_instance() == 0) {
            NpcModelRegistry::register_animated_chunk(6, reinterpret_cast<void *>(*(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 8)), reinterpret_cast<void *>((*(uaddr *)&rappy_alternate_texture_list)), &d,
                                            10.0f, 0.0f);
        } else {
            NpcModelRegistry::register_animated_chunk(6, reinterpret_cast<void *>(*(s32 *)(*(u8 **)(RES_800C17B8 + 0x42C) + 0x18)),
                                            reinterpret_cast<void *>(*(saddr *)(*(u8 **)(RES_800C17B8 + 0x42C) + 0x1C)), &d, 10.0f, 0.0f);
        }
    }
}

__declspec(section ".rodata") const char re3_b_lappy_base_niji_gvm[] = "re3_b_lappy_base_niji.gvm";
__declspec(section ".rodata") const char re3_b_lappy_base_ao_gvm[] = "re3_b_lappy_base_ao.gvm";

#undef RES_800C17B8

TObjEneLappy::~TObjEneLappy() {
    free_collision_body_parts(this);
}

#pragma defer_codegen on

void TObjEneLappy::sub_800C20C0() {
    this->m_374 = (s16) (this->m_374 | 1);
}

void TObjEneLappy::sub_800C20B0() {
    this->m_374 = (s16) (this->m_374 & 0xFFFFFFFE);
}

void TObjEneLappy::set_speed_params(s32 variant) {
    s32 var_r0;
    s32 var_r0_2;

    if (TLobby::get_instance() == 0) {
        *(s32 *)((s8 *)this + 0x34) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)rappy_bml_resource + 0x42C)) + 8);
    } else {
        if (variant == 0) {
            var_r0 = *(s32 *)((s8 *)(*(void **)((s8 *)rappy_bml_resource + 0x42C)) + 8);
        } else {
            var_r0 = *(s32 *)((s8 *)(*(void **)((s8 *)rappy_bml_resource + 0x42C)) + 0x18);
        }
        *(s32 *)((s8 *)this + 0x34) = var_r0;
    }
    if (variant == 0) {
        var_r0_2 = *(s32 *)((s8 *)(*(void **)((s8 *)rappy_bml_resource + 0x42C)) + 0xC);
    } else {
        var_r0_2 = rappy_alternate_texture_list;
    }
    this->texlist = var_r0_2;
}

int TObjEneLappy::test_flag_256() { return 0; }

#define CLAMP_800C1C4C(x, lo, hi) ((x) < (lo) ? (lo) : ((x) < (hi) ? (x) : (hi)))

TObjEneLappy::TObjEneLappy(TObject *parent, void *set_data) : TObjEnemy(parent) {
    Set_800C1C4C *set = (Set_800C1C4C *)set_data;
    s32 i;
    f32 scale;

    m_name = TObjEneLappy__class_name;
    apply_set_data(set);
    motion_list = ((BmlResource *)rappy_bml_resource)->motions;
    VecCopy(&position, (const Vec *)set->pos);
    copy_xyz(&rotation_x, set->rot);
    for (i = 0; i < 5; i++) {
        parameters[i] = set->params[i];
    }
    variant = set->f3c != 0 ? 1 : 0;
    if (random_ratio() < 0.002f) {
        variant = 1;
        if (TLobby::get_instance() == 1) {
            (*(s32 *)&rappy_visibility_node) = (s32)find_model_node(*(u32 *)(*(u8 **)((u8 *)rappy_bml_resource + 0x42C) + 0x18), 0x12);
        }
    }
    if (variant == 0) {
        set_param(5);
    } else if (TLobby::get_instance() == 1) {
        switch (lappy_variant_id) {
        case 1:
            set_param(0x4F);
            break;
        case 2:
            set_param(0x51);
            break;
        case 3:
            set_param(0x50);
            break;
        default:
            set_param(0x33);
            break;
        }
    } else {
        set_param(6);
    }
    state36C = set->f3e;
    resetTimer = 0xF;
    timer = resetTimer;
    VecCopy(&prev_position, &position);
    VecCopy(&home_position, &position);
    VecCopy((Vec *)&m_290, &position);
    VecCopy((Vec *)&m_29c, &position);
    m_374 = 0;
    m_396 = 0;
    m_382 = -1;
    m_384 = 0;
    m_380 = 0;
    m_378 = CLAMP_800C1C4C((s16)parameters[0], 0, 1);
    m_37a = 0;
    movementParameters = lbl_80492EC4;
    init_collision_body_parts(this, lbl_80492EFC, 1);
    if (set->fa > 0) {
        m_374 |= 0x60;
        m_378 = 1;
        actorFlags &= ~0x800000;
        bodies->flags &= ~1;
    }
    bind_enemy_combat_stats((u8 *)(lappy_boss_stats_handles[variant]), (u8 *)(lappy_boss_stats_ptrs_b[variant]), (u8 *)(lappy_object_handles[variant]));
    apply_variant_speeds();
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    register_object_by_id();
    scale = 6.0f * (1.0f + random_ratio());
    m_37e = 30.0f * scale;
    add_flags_2e4(1);
    actorFlags |= 0x40000;
    action_table = (TObjMotionAction *)rappy_variant_speed_table;
    set_field_d8((saddr)action_table);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    m_379 = m_378;
    if (TObjEneDD::check_v2_mode() != 0 && random_ratio() < 0.033333335f) {
        m_374 |= 0x400;
    }
    clear_lobby_object_state();
}



#undef rotate_matrix_y
#undef push_matrix
#undef pop_matrix
#undef post_translate_matrix
#undef draw_chunk_object
#undef scale_matrix
#undef render__12TObjEneLappyFv
