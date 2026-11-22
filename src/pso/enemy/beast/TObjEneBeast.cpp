#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D853C.h"

#include "pso/effect/TUnk_80494968.h"
#include "types.h"

#include "pso/player/TObjPlayer.h"


#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"


#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"

#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"


#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResourceDescriptor.h"

#include <stddef.h>
extern "C" {
void obj_clearFlags30__8TObjBaseFUl(void *, u32);
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
extern s32 model_render_flags;
}
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"

struct RecoveredGlobal_80091E08_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
struct VBase_80091EA4 { char pad[0x18]; };
struct VObj_80091EA4 : VBase_80091EA4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec *, Vec *);
};
struct Obj_80091EA4 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 state;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x3A8 - 0xC4];
    VObj_80091EA4 *effects[2];
};
struct VBase_14 { char pad[0x14]; };
struct VObj_14 : VBase_14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    u32 pad18;
};
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
    virtual s32 m9(f32, f32, f32);
};
struct Obj_8009211C : VObj_18 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    u8 f38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    Vec f2FC;
    u8 pad308[0x326 - 0x308];
    s16 f326;
    u8 pad328[0x380 - 0x328];
    f32 f380;
    u8 pad384[0x3B0 - 0x384];
    VObj_14 fades[4];
};
extern "C" {
s32 init_collision_body_parts(void *, void *, int);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
extern RecoveredGlobal_80091E08_lbl_8058D490 identity_matrix;
void set_matrix_identity(u8 *arg0);
extern void *beast_claw_trail_instance;
extern void *boss4_type3_instance;
extern s32 saved_model_render_flags;
#define play_sound_effect (*(s32 (*)(s32, s32, s32, s32))&play_sound_effect)
void TObjEneBeast::run_demo_task() {  }
void TObjEneBeast::play_group_chase_sound() {
    s32 self = (saddr)this;
    play_sound_effect(0x4003E431, self + 0x38, 0, 0);
}
void TObjEneBeast::play_death_sound() {
    s32 self = (saddr)this;
    play_sound_effect(0x4003AB2D, self + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
}
void TObjEneBeast::play_hurt_sound() {
    s32 self = (saddr)this;
    play_sound_effect(0x4003A32E, self + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}
void TObjEneBeast::play_attack_sound() {
    s32 self = (saddr)this;
    play_sound_effect(0x4003A62F, self + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}
void TObjEneBeast::play_alert_sound() {
    s32 self = (saddr)this;
    play_sound_effect(0x4003A82C, self + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
}

void TObjEneBeast::spawn_death_effect() {
    Vec stack;
    stack.x = 0.0f;
    stack.y = 1e+01f;
    stack.z = 0.5f * *(f32 *)(this->m_2b0 + 0x10);
    push_matrix_from(&identity_matrix.value);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, &stack.x, &stack.x);
    pop_matrix();
    vec3_add_to(&stack.x, (u8 *)&this->position);
    ((TObjPlayer *)(&stack.x))->spawn_effect_at_ground(0x23);
    TObjPlayer::spawn_dead_spot_type2((saddr)&stack.x, 0xF);
}

void TObjEneBeast::update_attack_trail() {
    Obj_80091EA4 *self = (Obj_80091EA4 *)this;
    Vec dir;
    Vec pos;
    Vec *entry;
    s32 idx;
    VObj_80091EA4 *eff;
    if (this->frame < 12.0f) {
        switch (this->requested_action) {
        case 3:
            entry = ((SampledMotionPoints *)(beast_claw_trail_instance))->lookup(this->frame);
            idx = 0;
            break;
        case 4:
            entry = ((SampledMotionPoints *)(boss4_type3_instance))->lookup(this->frame);
            idx = 1;
            break;
        default:
            entry = 0;
            break;
        }
        if (entry != 0) {
            push_matrix();
            set_matrix_identity(0);
            post_translate_matrix(&self->pos);
            rotate_matrix_y(0, this->rotation_y);
            matrix_mult_vec_array(NULL, entry, &pos, 2);
            pop_matrix();
            eff = self->effects[idx];
            if (eff != NULL) {
                eff->m4(&pos, &dir);
            }
        }
    }
}

void TObjEneBeast::select_subtype() {
    u8 *self = (u8 *)this;
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)self + 0x334);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)self + 0x334) = 0;
    } else if (temp_r0 > 2) {
        *(s32 *)((s8 *)self + 0x334) = 2;
    }
    switch (*(s32 *)((s8 *)self + 0x334)) {
    case 2:
        *(s32 *)((s8 *)self + 0x368) = 1;
        ((TObjEnemy *)self)->set_param(0xB);
        return;
    case 1:
        *(s32 *)((s8 *)self + 0x368) = 2;
        ((TObjEnemy *)self)->set_param(0xA);
        return;
    default:
        *(s32 *)((s8 *)self + 0x368) = 0;
        ((TObjEnemy *)self)->set_param(9);
        return;
    }
}
void TObjEneBeast::beast_update_appear() {
    u8 *self = (u8 *)this;
    switch (*(s16 *)((s8 *)self + 0x328)) {
    case 0:
    default:
        if ((s32) *(s32 *)((s8 *)self + 0x390) != 1) {
            *(s16 *)((s8 *)self + 0x328) = 2;
        } else {
            *(s16 *)((s8 *)self + 0x328) = 1;
            *(s16 *)((s8 *)self + 0xB8) = 0xB;
            ((TObjCollidable *)self)->set_indexed_flags(0, 0x0A000000);
            obj_setFlags30(self, 0x04000000);
            play_sound_effect(0x4003AB32, (saddr)(self + 0x38), 0, 0);
        }
        break;
    case 1:
        if ((u32) *(u32 *)((s8 *)self + 0xB4) != 0x20U) {
            *(s16 *)((s8 *)self + 0x328) = 2;
            *(s32 *)((s8 *)self + 0x390) = 0;
            *(s16 *)((s8 *)self + 0xB8) = 0;
            ((TObjCollidable *)self)->clear_player_status_flag(0, 0x0A000000);
            ((TObjBase *)self)->obj_clearFlags30(0x04000000);
        }
        break;
    case 2:
        *(s16 *)((s8 *)self + 0x326) = 1;
        break;
    }
    ((TObjMotion *)self)->advance_animation();
}
void TObjEneBeast::render() {
    s32 drawMode;
    saddr fade;
    s32 cam;
    s32 doDraw;

    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    drawMode = ((Obj_8009211C *)this)->m9(2e+02f, 4e+02f, 3e+01f);
    if (drawMode == 0) {
        return;
    }
    fade = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        fade = (saddr)&((Obj_8009211C *)this)->fades[cam];
        ((RenderFadeState *)fade)->update();
        fade = ((RenderFadeState *)fade)->updateFromCamera((const f32*)(&((Obj_8009211C *)this)->f2FC));
    }
    saved_model_render_flags = model_render_flags;
    select_actor_lighting((saddr)((Obj_8009211C *)this));
    TObjFish::set_global_param(((Obj_8009211C *)this)->f24);
    push_matrix();
    translate_matrix(0, 0.0f, ((Obj_8009211C *)this)->f380, 0.0f);
    post_translate_matrix(((Obj_8009211C *)this)->f38);
    rotate_matrix_y(0, ((Obj_8009211C *)this)->f60);
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(model);
    } else {
        TObjPlayer::toggle_particle_effect();
        doDraw = 1;
        if (fade != 0) {
            ((Obj_8009211C *)this)->fades[cam].m6();
            if (((TObject *)((Obj_8009211C *)this))->defer_render() != 0) {
                doDraw = 0;
            }
        }
        if (doDraw != 0) {
            if (drawMode == 1) {
                ((TObjMotion *)((Obj_8009211C *)this))->draw();
            } else {
                ((TObjEnemy *)((Obj_8009211C *)this))->draw_motion_model();
            }
        }
        TParticleCtrl::end_effect_render();
        if (fade != 0) {
            ((Obj_8009211C *)this)->fades[cam].m7();
        }
    }
    pop_matrix();
    restore_scene_lighting();
    if (((Obj_8009211C *)this)->f326 >= 10 || ((Obj_8009211C *)this)->f326 < 8) {
        Vec v;
        v.x = 1.5f;
        v.y = 1.0f;
        v.z = 2.0f;
        ((TObjEnemy *)((Obj_8009211C *)this))->draw_ground_shadow(&v, 0);
    }
}

}

#undef clear_attack_flag__14TObjEneBalClawFv
#undef TObjEneBalClawClaw__sub_80090824
#undef rotate_matrix_y
#undef pop_matrix
#undef sub_80090798__18TObjEneBalClawClawFv
#undef update_drop__18TObjEneBalClawClawFPv
#undef update_move_to_target__18TObjEneBalClawClawFPv
#undef update_follow_parent__18TObjEneBalClawClawFPv
#undef sub_80090D3C__18TObjEneBalClawClawFv
#undef TObjEneBalClawClaw__sub_80090ECC
#undef TObjEneBalClawClaw__sub_80091134
#undef TObjEneBalClawClaw__sub_80091200
#undef update_chase__18TObjEneBalClawClawFPv
#undef push_matrix
#undef post_translate_matrix
#undef obj_clearFlags30__8TObjBaseFUl
#undef obj_setFlags30
#undef play_sound_effect
#undef translate_matrix
#undef update_if_active__15TObjEnemyCustomFl
#undef TObjEneBalClawClaw__sub_800914A4
#undef find_active_entity_by_id
#undef reset_active_state__18TObjEneBalClawClawFPv


#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/enemy/saver/TObjEneSaver.h"


#include "pso/system/task/TObject_80019A50.h"


struct Ent_8009241C { u8 pad0[0xC]; f32 radius; u8 pad10[0x2C - 0x10]; };
struct Ids_8009241C { s16 id[3]; };


extern "C" {
void free_collision_body_parts(void *);

extern void *tl_04;

}
const char *beast_model_name_table[4] = {
    "re8_b_beast_wola_body.nj", "re8_b_rdbeast_wola_body.nj", "re8_b_srdbeast_wola_body.nj", NULL,
};
const char *beast_motion_name_table[13] = {
    "appear_bm1_s_wala_body.njm", "atackl_bm1_s_wala_body.njm", "atackr_bm1_s_wala_body.njm", "damage_bm1_s_wala_body.njm",
    "deadb_bm1_s_wala_body.njm", "dead_bm1_s_wala_body.njm", "leader_bm1_s_wala_body.njm", "mihari_bm1_s_wala_body.njm",
    "run_bm1_s_wala_body.njm", "stund_bm1_s_wala_body.njm", "wakeup_bm1_s_wala_body.njm", "walk_bm1_s_wala_body.njm",
    NULL,
};
BmlResourceDescriptor beast_resource_descriptor = {
    "bm_ene_re8_b_beast.bml", beast_model_name_table, beast_motion_name_table, 3, 12,
};
// inferred: stored to the object's name field by the constructor
const char *beast_class_name = "TObjEneBeast";
extern const char beast_a_bml_filename[25];
void *beast_action_table[48] = {
    (void *)0x10000, (void *)0x9, (void *)0x3f19999a, (void *)0x1,
    (void *)0x20000, (void *)0x7, (void *)0x3f19999a, (void *)0x20,
    (void *)0x10002, (void *)0xb, (void *)0x3f000000, (void *)0x1,
    (void *)0x20000, (void *)0x1, (void *)0x3f266666, (void *)0x4,
    (void *)0x20000, (void *)0x2, (void *)0x3f59999a, (void *)0x4,
    (void *)0x10000, (void *)0x8, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0x3, (void *)0x3fc00000, (void *)0x8,
    (void *)0x20000, (void *)0xa, (void *)0x3f4ccccd, (void *)0x20,
    (void *)0x30000, (void *)0x5, (void *)0x3f19999a, (void *)0x10,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x10,
    (void *)0x20000, (void *)0x6, (void *)0x3f19999a, (void *)0x20,
    (void *)0x20000, (void *)0x0, (void *)0x3f000000, (void *)0x20,
};
void *beast_movement_params[21] = {
    (void *)0x43610000, (void *)0x3ecccccd, (void *)0x400, (void *)0x0,
    (void *)0x1e0000, (void *)0x1, (void *)0x0, (void *)0x437a0000,
    (void *)0x3f0ccccd, (void *)0x400, (void *)0x0, (void *)0x1e0000,
    (void *)0x1, (void *)0x0, (void *)0x43960000, (void *)0x3f333333,
    (void *)0x400, (void *)0x0, (void *)0x1e0000, (void *)0x1,
    (void *)0x0,
};
void *beast_collision_body_table[33] = {
    (void *)0x0, (void *)0x41480000, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41480000, (void *)0x0, (void *)0x40e00000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x41000000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};

void *TObjEneBeast::create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneBeast(control, set_data);
}

uaddr ene_beast_boss_id_buffer;
uaddr TObjEneBeast__boss4_rock_handler_ids;
uaddr boss4_rock_pool;
uaddr boss4_rock_shared_handler_ids;
BmlResource *ene_beast_bml_resource;
void *beast_claw_trail_instance;
void *boss4_type3_instance;

void free_boss4_rock_pool(void) {
    if ((u32) ene_beast_boss_id_buffer != 0U) {
        mem_free((void*)ene_beast_boss_id_buffer);
        ene_beast_boss_id_buffer = 0U;
    }
    if ((u32) TObjEneBeast__boss4_rock_handler_ids != 0U) {
        mem_free((void*)TObjEneBeast__boss4_rock_handler_ids);
        TObjEneBeast__boss4_rock_handler_ids = 0U;
    }
    if ((u32) boss4_rock_pool != 0U) {
        mem_free((void*)boss4_rock_pool);
        boss4_rock_pool = 0U;
    }
    if ((u32) boss4_rock_shared_handler_ids != 0U) {
        mem_free((void*)boss4_rock_shared_handler_ids);
        boss4_rock_shared_handler_ids = 0U;
    }
    if ((uaddr) boss4_type3_instance != 0U) {
        delete (SampledMotionPoints *)boss4_type3_instance;
        boss4_type3_instance = 0U;
    }
    if ((uaddr) beast_claw_trail_instance != 0U) {
        delete (SampledMotionPoints *)beast_claw_trail_instance;
        beast_claw_trail_instance = 0U;
    }
    if (ene_beast_bml_resource != NULL) {
        delete ene_beast_bml_resource;
        ene_beast_bml_resource = NULL;
    }
}

#pragma push
#pragma opt_propagation off
void TObjEneBeast::load_resources() {
    u8 *p;
    s32 i;

    if (TObjEneDD::check_v2_mode() != 0) {
        ene_beast_bml_resource = load_enemy_bml_resource_named(&beast_resource_descriptor, (const char *)beast_a_bml_filename);
        ((Ent_8009241C *)beast_collision_body_table)[0].radius = 1e+01f;
        ((Ent_8009241C *)beast_collision_body_table)[1].radius = 1e+01f;
        ((Ent_8009241C *)beast_collision_body_table)[2].radius = 9.0f;
    } else {
        p = (u8 *)new BmlResource(1, &beast_resource_descriptor, 0, 0, NULL);
        ene_beast_bml_resource = (BmlResource *)p;
        ((Ent_8009241C *)beast_collision_body_table)[0].radius = 7.0f;
        ((Ent_8009241C *)beast_collision_body_table)[1].radius = 7.0f;
        ((Ent_8009241C *)beast_collision_body_table)[2].radius = 8.0f;
    }
    p = (u8 *)new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    beast_claw_trail_instance = (void *)p;
    p = (u8 *)new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    boss4_type3_instance = (void *)p;
    ((SampledMotionPoints *)beast_claw_trail_instance)->sample_two_nodes(ene_beast_bml_resource->models->model, (NJS_MOTION *)ene_beast_bml_resource->motions[((s32 *)beast_action_table)[13]].motion, 5, 8);
    ((SampledMotionPoints *)boss4_type3_instance)->sample_two_nodes(ene_beast_bml_resource->models->model, (NJS_MOTION *)ene_beast_bml_resource->motions[((s32 *)beast_action_table)[17]].motion, 10, 13);
    ene_beast_boss_id_buffer = (uaddr)mem_alloc(0xC);
    TObjEneBeast__boss4_rock_handler_ids = (uaddr)mem_alloc(0xC);
    boss4_rock_pool = (uaddr)mem_alloc(0xC);
    boss4_rock_shared_handler_ids = (uaddr)mem_alloc(0xC);
    ((s32 *)ene_beast_boss_id_buffer)[0] = (saddr)TLobby::register_boss(0x4B);
    ((s32 *)ene_beast_boss_id_buffer)[1] = (saddr)TLobby::register_boss(0x4C);
    ((s32 *)ene_beast_boss_id_buffer)[2] = (saddr)TLobby::register_boss(0x4D);
    ((s32 *)TObjEneBeast__boss4_rock_handler_ids)[0] = (saddr)TLobby::dispatch_shared_handler_b(0x4E);
    ((s32 *)TObjEneBeast__boss4_rock_handler_ids)[1] = (saddr)TLobby::dispatch_shared_handler_b(0x4F);
    ((s32 *)TObjEneBeast__boss4_rock_handler_ids)[2] = (saddr)TLobby::dispatch_shared_handler_b(0x50);
    ((s32 *)boss4_rock_pool)[0] = (saddr)TLobby::register_object(0x4A);
    ((s32 *)boss4_rock_pool)[1] = (saddr)TLobby::register_object(0x4B);
    ((s32 *)boss4_rock_pool)[2] = (saddr)TLobby::register_object(0x4C);
    ((s32 *)boss4_rock_shared_handler_ids)[0] = (saddr)TLobby::dispatch_shared_handler_a(0x4A);
    ((s32 *)boss4_rock_shared_handler_ids)[1] = (saddr)TLobby::dispatch_shared_handler_a(0x4B);
    ((s32 *)boss4_rock_shared_handler_ids)[2] = (saddr)TLobby::dispatch_shared_handler_a(0x4C);
    {
        Ids_8009241C ids = {{2, 3, 4}};
        NpcAnimationBinding q = { NULL, reinterpret_cast<TObjMotionAction *>(beast_action_table), 0, 2, 12 };
        q.motions = ene_beast_bml_resource->motions;
        for (i = 0; i < 3; i++) {
            NpcModelRegistry::register_animated_chunk(ids.id[i], reinterpret_cast<void *>(ene_beast_bml_resource->models[i].model),
                                            reinterpret_cast<void *>(ene_beast_bml_resource->models[i].m_c), &q,
                                            ((Ent_8009241C *)beast_collision_body_table)[i].radius, 0.0f);
        }
    }
}

#pragma pop
extern "C" {
// Archive loaded instead of beast_resource_descriptor's when TObjEneDD::check_v2_mode() is set. Defined after
// load_resources (it follows that function's initialisers and is not pooled there); the declaration above it would
// otherwise send it to .data.
}
__declspec(section ".rodata") const char beast_a_bml_filename[25] = "bm_ene_re8_b_beast_a.bml"; // inferred: from the string

#pragma defer_codegen on
#define F(o, T, off) (*(T *)(o + (off)))
struct Rec2C_800927DC { u8 b[0x2C]; };
struct Rec1C_800927DC { u8 b[0x1C]; };

#define self ((u8 *)this)

TObjEneBeast::TObjEneBeast(TObject *parent, void *set_data) : TUnk_80493450(parent) {
    s32 i;

    F(self, const char *, 0) = beast_class_name;
    apply_set_data(set_data);
    ((TObjPlayer *)self)->init_position_vectors();
    F(self, s32, 0x334) = F(self, s32, 0x368);
    ((TObjEneBeast *)self)->select_subtype();
    ((TObjEneBeast *)self)->select_model_record(F(self, s32, 0x368));
    F(self, u8 *, 0xD8) = (u8 *)beast_action_table;
    ((TObjMotion *)self)->set_field_d8((saddr)(F(self, u8 *, 0xD8)));
    F(self, BmlMotionEntry *, 0xDC) = ene_beast_bml_resource->motions;
    F(self, s16, 0xB8) = 0;
    ((TObjMotion *)self)->set_animation(F(self, s16, 0xB8));
    ((TObjMotion *)self)->set_field_b8(F(self, s16, 0xB8));
    init_collision_body_parts(self, &((Rec2C_800927DC *)beast_collision_body_table)[F(self, s32, 0x334)], 1);
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)(((uaddr *)ene_beast_boss_id_buffer)[F(self, s32, 0x334)]), (u8 *)(((uaddr *)TObjEneBeast__boss4_rock_handler_ids)[F(self, s32, 0x334)]), (u8 *)(((uaddr *)boss4_rock_pool)[F(self, s32, 0x334)]));
    F(self, void *, 0x350) = &((Rec1C_800927DC *)beast_movement_params)[F(self, s32, 0x334)];
    F(self, s16, 0x33E) = F(self, s16, 0x32C);
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    ((TObjPlayer *)self)->register_object_by_id();
    F(self, s32, 0x2AC) = (s32)(182.04445f * (3.6e+02f * ((TObjChara *)self)->random_ratio()));
    F(self, s16, 0x33A) = 0xF;
    F(self, s16, 0x33C) = F(self, s16, 0x33A);
    F(self, s16, 0x328) = 0;
    F(self, s16, 0x374) = 0;
    F(self, s16, 0x376) = 0;
    F(self, s32, 0x378) = 0;
    F(self, s32, 0x37C) = 0;
    ((TObjChara *)self)->add_flags_2e4(1);
    obj_setFlags30(self, 0x40000);
    F(self, f32, 0x380) = 0.0f;
    m_3a8[0] = (TObject *)TUnk_80494968::create((u32)0xA0303030, (u32)0xFF303030);
    m_3a8[1] = (TObject *)TUnk_80494968::create((u32)0xA0303030, (u32)0xFF303030);
    F(self, f32, 0x398) = ((f32 **)boss4_rock_shared_handler_ids)[F(self, s32, 0x334)][0];
    F(self, f32, 0x3A0) = ((f32 **)boss4_rock_shared_handler_ids)[F(self, s32, 0x334)][1];
    F(self, f32, 0x39C) = ((f32 **)boss4_rock_shared_handler_ids)[F(self, s32, 0x334)][2];
    F(self, f32, 0x3A4) = ((f32 **)boss4_rock_shared_handler_ids)[F(self, s32, 0x334)][3];
    F(self, s32, 0x390) = 1;
    for (i = 0; i < 4; i++) {
        m_3b0[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}
#undef self
#undef F

TObjEneBeast::~TObjEneBeast() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (m_3a8[i] != NULL) {
            m_3a8[i]->queue_destruction();
            m_3a8[i] = NULL;
        }
    }
    unlink_enemy_group_relations();
    free_collision_body_parts(this);
}
