#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/reflection.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/vector.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/gibbles/TObjEneGibbles.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/enemy/recon/TObjEneReconBomb.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"

#pragma readonly_strings on

extern "C" {
extern TObjMotionAction TObjEneRecon__animation_entries[6];

// Breakup-model parameters TObjEneRecon__sub_8031C364 hands to TBoss3Volopt::create_breakup_mdl.
extern const TBoss3VoloptBreakupParams recon_breakup_params = { 0x14, { 0.05f, 1.2f, 0.9f, 0.12f, 0.55f, 0.5f } };
const char *TObjEneRecon_name_ref = "TObjEneRecon";
extern const NpcAnimationBinding recon_anim_binding = { NULL, reinterpret_cast<TObjMotionAction *>(TObjEneRecon__animation_entries), 1, 1, 6 };
extern const Vec lbl_804760FC = { 0.8f, 1.0f, 0.8f };

saddr lbl_805D6AF0;
saddr TObjEneRecon__attack_params;
saddr TObjEneRecon__resistance_params;
f32 *TObjEneRecon__data_805D6AFC;
BmlResource *TObjEneRecon__recobox_static_instance;
TUnk_8048FA00 *boss3_volopt_instance;
s32 recon_intro_stage;
u8 *recon_model_matrix_ptr;


void TObjEneRecon::render_shadows() {
  saddr bml_model;
  if (TObjEneRecon__recobox_static_instance != NULL)
  {
    s32 temp_r30;
    bml_model = (saddr)get_bml_model((BmlResource *)TObjEneRecon__recobox_static_instance, 2);
    temp_r30 = (saddr)get_bml_texlist((BmlResource *)TObjEneRecon__recobox_static_instance, 2);
    push_matrix();
    translate_matrix(0, *((f32 *) (((s8 *) this) + 0x38)), *((f32 *) (((s8 *) this) + 0x3C)), *((f32 *) (((s8 *) this) + 0x40)));
    rotate_matrix_zyx(0, this->rotation_x, this->rotation_y, this->rotation_z);
    scale_matrix(0, 1.5f, 1.5f, 1.5f);
    TObjFish::set_global_param(temp_r30);
    draw_chunk_object((void *)bml_model);
    pop_matrix();
  }
}

s32 post_translate_matrix(void *);


void TObjEneRecon::render_demo() {
    u8 *self = (u8 *)this;
    if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        ((TObjEneDD *)(self))->draw_ground_shadow(0, 0);
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(this->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}


s32 TObjEneRecon::render_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix((Vec *)(((u8 *)this) + 0x41C)) != 0) {
            TObjFish::set_global_param((int) (this->texlist));
            push_matrix();
            translate_matrix(0, (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x38)), (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x448)), (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x40)));
            rotate_matrix_y(0, (int) (this->rotation_y));
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

}

extern "C" {
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
#pragma push
#pragma opt_common_subs off
void render__12TObjEneReconFv(u8 *ene_recon) {
    s32 var_r29;
    s32 var_r31;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRecon *)(ene_recon))->render_demo();
        return;
    }
    if (!(*(s32 *)((s8 *)ene_recon + 0x444) & 1)) {
        if (TObjEneDD::is_main_phase_15() != 0) {
            var_r31 = ((TObjEneRecon *)(ene_recon))->classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
        } else if (((TObjEneRecon *)(ene_recon))->update_object_view_visibility(400.0f, 15.0f) != 0) {
            var_r31 = 1;
        } else {
            var_r31 = 0;
        }
        if (var_r31 != 0) {
            var_r29 = 1;
            if (((TObjEneRecon *)ene_recon)->render_model_if_visible() == 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                if (((s16) ((TObjEneRecon *)ene_recon)->mode == 5) && (((TObjEneRecon *)ene_recon)->fade.has_visible_opacity() != 0)) {
                    ((TObjEneRecon *)ene_recon)->fade.set_flags_and_apply_damage_color();
                    if (((TObject *)ene_recon)->defer_render() != 0) {
                        var_r29 = 0;
                    }
                }
                if (var_r29 != 0) {
                    if ((*(s32 *)((s8 *)ene_recon + 0x444) & 2) && !(*(s32 *)((s8 *)ene_recon + 0x418) & 0x4000)) {
                        Vec v = lbl_804760FC;
                        ((TObjEneDD *)(ene_recon))->draw_ground_shadow(&v, 0);
                    }
                    ((TObjEneDD *)ene_recon)->update_secondary_light();
                    TObjFish::set_global_param((int) (((TObjEneRecon *)ene_recon)->texlist));
                    push_matrix();
                    translate_matrix(0, (f32) (*(f32 *)((s8 *)ene_recon + 0x38)), (f32) (*(f32 *)((s8 *)ene_recon + 0x448)), (f32) (*(f32 *)((s8 *)ene_recon + 0x40)));
                    rotate_matrix_y(0, (int) (((TObjEneRecon *)ene_recon)->rotation_y));
                    TObjEneDD::clear_global_flag_400();
                    recon_intro_stage = 0;
                    recon_model_matrix_ptr = ene_recon + 0x40C;
                    *(f32 *)((s8 *)ene_recon + 0x40C) = 0.0f;
                    *(f32 *)((s8 *)ene_recon + 0x410) = 0.0f;
                    *(f32 *)((s8 *)ene_recon + 0x414) = 0.0f;
                    set_chunk_model_node_callback(TObjEneRecon::advance_intro_stage);
                    TObjPlayer::toggle_particle_effect();
                    model_render_flags |= 0x01000000;
                    if (var_r31 == 1) {
                        ((TObjMotion *)ene_recon)->draw();
                    } else {
                        ((TObjEnemy *)ene_recon)->draw_motion_model();
                    }
                    model_render_flags &= 0xFEFFFFFF;
                    TParticleCtrl::end_effect_render();
                    set_chunk_model_node_callback(NULL);
                    pop_matrix();
                    ((TObjEneDD *)ene_recon)->update_primary_light();
                }
                if (((s16) ((TObjEneRecon *)ene_recon)->mode == 5) && (((TObjEneRecon *)ene_recon)->fade.has_visible_opacity() != 0)) {
                    ((TObjEneRecon *)ene_recon)->fade.clear_flag_and_notify();
                }
                model_render_flags = saved_model_render_flags;
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            }
        }
    }
}
#pragma pop


void TObjEneRecon::advance_intro_stage(NJS_OBJECT *) {
    switch ((s32) recon_intro_stage) {
    case 0:
        push_matrix();
        forward_split_screen_view_matrix();
        matrix_mult_vec(0, (Vec *)recon_model_matrix_ptr, (Vec *)recon_model_matrix_ptr);
        pop_matrix();
        break;
    case 10:
        TParticleCtrl::begin_effect_render();
        break;
    }
    recon_intro_stage += 1;
}

}

void TObjEneRecon::run_demo_task() {  }

struct Stack_8031C190 {
    s32 sp8;
    f32 spC;
};

extern s32 actor_frame_tick;
void TObjEneRecon::update_ground_probe() {
    u8 *self = (u8 *)this;
    Stack_8031C190 stack;
    u8 *temp_r3;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy((Vec *)&stack.sp8, (const Vec *)&this->position);
        stack.spC += 15.0f;
        temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (CsnGroup **)&this->m_120, 0x4000));
        if (temp_r3 != NULL) {
            *(s32 *)((s8 *)self + 0x418) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 0x18);
            VecCopy(&floor_point, (const Vec *)(*(u8 **)((s8 *)temp_r3 + 4)));
        } else {
            VecCopy(&floor_point, &position);
        }
    }
    if (*(s32 *)((s8 *)self + 0x418) & 0x4000) {
        request_reflection_render();
    }
}

s32 TObjEneRecon::is_anim_5() {
    return (u8) (mode == 5);
}

struct T_8031C250 { u8 pad[0x326]; s16 state; };

#define F(T, o) (*(T *)(arg0 + (o)))

struct Data_8031CF30 { u8 pad[0x1C]; s32 f1C; };

extern "C" {
f32 TObjEneRecon__sub_8031C2BC(void);
f32 TObjEneRecon__sub_8031C2C8(void);
f32 TObjEneRecon__sub_8031C2D4(void);
u8 TObjEneRecon__sub_8031C250(T_8031C250 *self);
s16 get_attack_params_atp_min(void *p);
u16 get_entity_id(void *);
f32 horizontal_distance_squared(void *, void *);
s32 TObjEneRecon__sub_8031DA90(u8 *arg0);
extern s32 lbl_805D5868;
void TObjEneRecon__sub_8031CF30(u8 *arg0, s32 reason);

u8 TObjEneRecon__sub_8031C250(T_8031C250 *self) {
    return self->state == 8 || self->state == 7;
}

s32 TObjEneRecon::calc_scaled_value() {
    return (s32) (30.0f * (f32) *(s32 *)((s8 *)TObjEneRecon__data_805D6AFC + 0x18));
}

f32 TObjEneRecon__sub_8031C2BC(void) {
    return *(f32 *)((s8 *)TObjEneRecon__data_805D6AFC + 0xC);
}
f32 TObjEneRecon__sub_8031C2C8(void) {
    return *(f32 *)((s8 *)TObjEneRecon__data_805D6AFC + 8);
}
f32 TObjEneRecon__sub_8031C2D4(void) {
    return *(f32 *)((s8 *)TObjEneRecon__data_805D6AFC + 4);
}

void TObjEneRecon::handle_message(s32 arg1) {
    uaddr temp;
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) | 1);
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) & 0xFFFFFFFD);
        if ((temp = (uaddr)find_entity_by_id(*(u16 *)((s8 *)this + 0x434))) != 0U) {
            ((TObjEneRecobox *)temp)->remove_child_entity((u8 *)this);
        }
        break;
    case 5:
    case 0:
        break;
    case 3:
        queue_destruction();
        break;
    }
}

}


#define F(T, o) (*(T *)(arg0 + (o)))

extern "C" {
f32 normalize_vector_xz__FP3Vec(void *, s32);
void TObjEneRecon__sub_8031C624(u8 *arg0, s32 reason);
s32 project_actor_to_ground(void *, void *, void *);
void TObjEneRecon__sub_8031C364(u8 *arg0, s32 reason);

void TObjEneRecon__sub_8031C364(u8 *arg0, s32 reason) {
    switch (reason) {
    case 4:
        F(s16, 0xB8) = 5;
        ((TObjEneDD *)(arg0))->clear_intangible();
        F(s32, 0x444) &= ~3;
        F(s32, 0x80) = 0;
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        TBoss8Dragon__sub_800BB7DC(arg0);
        TBoss8Dragon__sub_800BB7D8(arg0, 0xF1, 1.0f);
        F(s32, 0x3C0) = 0;
        F(f32, 0x3E0) = 0.0f;
        F(f32, 0x44C) = F(f32, 0x308);
        F(f32, 0x454) = F(f32, 0x310);
        F(f32, 0x3E4) = ((f32 (*)(void *))normalize_vector_xz__FP3Vec)(arg0 + 0x44C);
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80C), arg0 + 0x38, 0, 0);
        break;
    case 3:
        if (F(s32, 0x3C0) == 3) {
            ((TObjEneDD *)arg0)->transition_enemy_state(8);
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (F(s32, 0x3C0)) {
        case 0:
        case 1:
            ((TObjEneRecon *)arg0)->set_flag2(F(f32, 0x44C), F(f32, 0x454), F(f32, 0x3E4));
            {
                Vec v = F(Vec, 0x38);
                v.y += F(f32, 0x448);
                if (project_actor_to_ground(arg0, &v, arg0 + 0x248) != 0) {
                    F(f32, 0x3C) = v.y;
                }
            }
            F(f32, 0x3E0) -= 0.1f;
            F(f32, 0x448) += F(f32, 0x3E0);
            if (F(f32, 0x448) < 5.0f + F(f32, 0x3C)) {
                F(f32, 0x448) = 5.0f + F(f32, 0x3C);
                if (F(s32, 0x3C0) == 0) {
                    F(s32, 0x3C0) = 1;
                    F(f32, 0x3E0) = 1.0f;
                    F(f32, 0x3E4) *= 0.98f;
                    if (F(f32, 0x44C) * F(f32, 0x44C) + F(f32, 0x454) * F(f32, 0x454) <= 0.3f) {
                        F(f32, 0x44C) = 0.5f * sin_table_lookup(F(s32, 0x60));
                        F(f32, 0x454) = 0.5f * cos_table_lookup(F(s32, 0x60));
                    }
                } else {
                    F(s32, 0x3C0) = 2;
                }
            }
            F(f32, 0x3E4) *= 0.98f;
            ((TObjEneRecon *)arg0)->clamp_min_height();
            break;
        case 2:
            F(s32, 0x444) |= 1;
            F(s32, 0x3C0) = 3;
            spawn_particle_effect_with_flags((const Vec *)(arg0 + 0x38), 0x45, 0x40);
            spawn_particle_effect_with_flags((const Vec *)(arg0 + 0x38), 0x46, 0x40);
            play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80D), arg0 + 0x38, 0, 0);
            TBoss3Volopt::create_breakup_mdl((saddr)boss3_volopt_instance, (saddr)&recon_breakup_params, (s32)(F(s32, 0x24)), (saddr)(arg0 + 0x2FC), (s32)(F(s32, 0x60)));
            break;
        }
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneRecon__sub_8031C624(u8 *arg0, s32 reason) {
    s32 n;
    f32 v;
    switch (reason) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 4;
        ((TObjEneDD *)(arg0))->clear_intangible();
        *(s32 *)((s8 *)arg0 + 0x444) &= ~1;
        *(s32 *)((s8 *)arg0 + 0x444) |= 2;
        ((TObjEneDD *)arg0)->set_field_378(*(s16 *)((s8 *)arg0 + 0x326));
        ((TBoss8Dragon *)arg0)->noop();
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003E425), arg0 + 0x38, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0xB0) & 0x10) {
            if (((TObjEneRecon *)(arg0))->is_confused() != 0) {
                ((TObjEneRecon *)(arg0))->acquire_target(200.0f);
            }
            n = *(s32 *)((s8 *)arg0 + 0x378);
            if (n == 2) {
                ((TObjEneRecon *)arg0)->select_next_target();
            } else {
                ((TObjEneDD *)arg0)->transition_enemy_state(n);
            }
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        n = *(s32 *)((s8 *)arg0 + 0x3C0);
        *(s32 *)((s8 *)arg0 + 0x3C0) = n + 1;
        *(f32 *)((s8 *)arg0 + 0x44C) = *(f32 *)((s8 *)arg0 + 0x308);
        *(f32 *)((s8 *)arg0 + 0x454) = *(f32 *)((s8 *)arg0 + 0x310);
        v = normalize_vector_xz__FP3Vec(arg0 + 0x44C, n);
        ((TObjEneRecon *)arg0)->set_flag2(*(f32 *)((s8 *)arg0 + 0x44C), *(f32 *)((s8 *)arg0 + 0x454), v);
        ((TObjEneRecon *)arg0)->clamp_min_height();
        *(f32 *)((s8 *)arg0 + 0x308) *= 0.5f;
        *(f32 *)((s8 *)arg0 + 0x310) *= 0.5f;
        ((TObjEneDD *)(arg0))->check_collisions();
        break;
    case 5:
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        break;
    }
}
#pragma pop

}

extern "C" {

void run_task__12TObjEneReconFPvi(u8 *target, s32 reason);

void run_task__12TObjEneReconFPvi(u8 *target, s32 reason) {
    saddr entity;

    switch (reason) {
    case 4:
        ((TObjEneRecon *)target)->requested_action = 1;
        ((TObjEneRecon *)target)->clear_intangible();
        *(s32 *)((s8 *)target + 0x444) = (s32) (*(s32 *)((s8 *)target + 0x444) & 0xFFFFFFFE);
        *(s32 *)((s8 *)target + 0x444) = (s32) (*(s32 *)((s8 *)target + 0x444) | 2);
        ((TObjEneRecon *)target)->actorFlags = (s32) (((TObjEneRecon *)target)->actorFlags | 0x01000000);
        ((TObjEneRecon *)target)->fade.reset_color();
        create_timed_particle_emitter((target + 0x38), 0x79, 0, 0xF);
        return;
    case 3:
        entity = (saddr)find_entity_by_id((*(u16 *)((s8 *)target + 0x434)));
        if (entity == 0) {
            ((TObject *)target)->queue_destruction();
            return;
        }
        if (((TObjEneRecobox *)entity)->is_anim_6() == 1) {
            ((TObjEneDD *)target)->transition_enemy_state(7);
            return;
        }
        if (((TObjEneRecon *)target)->fade.decay_value_toward_floor() != 0) {
            *(s32 *)((s8 *)target + 0x444) = (s32) (*(s32 *)((s8 *)target + 0x444) | 1);
            ((TObjEneRecobox *)entity)->remove_tracked_target((TObjEneRecon *)target);
            ((TObject *)target)->queue_destruction();
        }
    case 5:
        return;
    case 0:
        ((TObjMotion *)target)->advance_animation();
        ((TObjEneDD_ST *)target)->update_velocity();
        ((TObjEneRecon *)target)->update_body_colliders();
        ((TObjEneRecon *)target)->clamp_min_height();
        ((TObjEneDD *)target)->transform_part_positions();
        ((TObjEneRecon *)target)->spawn_trap_b();
        break;
    }
}

}

#define F(T, o) (*(T *)(arg0 + (o)))


struct Obj_8031C920 { u8 pad[0x38]; f32 x, y, z; };

struct Prm_8031C920 { f32 f0; f32 f4; };

extern "C" {
void TObjEneRecon__sub_8031D380(u8 *arg0, s32 reason);
f32 atan2_float(f32 y, f32 x);
s32 approach_angle_limited(s32, s32, s32);
void TObjEneRecon__sub_8031CCFC(u8 *arg0, s32 reason);
void TObjEneRecon__sub_8031C920(u8 *arg0, s32 reason);

void TObjEneRecon__sub_8031C920(u8 *arg0, s32 reason) {
    f32 r;
    f32 h;
    f32 k;
    Obj_8031C920 *t;
    switch (reason) {
    case 4:
        F(s16, 0xB8) = 1;
        ((TObjEneRecon *)(arg0))->clear_intangible();
        F(u32, 0x444) &= ~1;
        F(u32, 0x444) |= 2;
        F(u32, 0x30) |= 0x01000000;
        if (F(s16, 0x326) == 4) {
            F(s32, 0x3C0) = 2;
        } else {
            F(s32, 0x3C0) = 0;
            F(s32, 0x3D0) = F(s32, 0x60) + 0x8000;
            F(s32, 0x3D4) = 0;
            F(s32, 0x3D8) = 0;
        }
        break;
    case 3:
        if (F(u8 *, 0x390) == NULL) {
            ((TObjEneDD *)arg0)->transition_enemy_state(5);
        } else if (F(s32, 0x46C) > 0x8000 || F(s32, 0x46C) < -0x8000) {
            ((TObjEneRecon *)arg0)->select_next_target();
        } else if (F(s32, 0x470) > 0x5000 || F(s32, 0x470) < -0x5000) {
            ((TObjEneRecon *)arg0)->retarget();
        }
        break;
    case 1:
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneEpsilon *)arg0)->update_death_check() != 0 || ((TObjEneRecon *)(arg0))->acquire_target(200.0f) != 0) {
            switch (F(s32, 0x3C0)) {
            case 0:
                ((TObjEneRecon *)arg0)->set_orbit_destination(F(s32, 0x3D0));
                ((TObjEneDD_ST *)arg0)->update_velocity();
                k = 0.2f * F(f32, 0x468);
                r = F(Prm_8031C920 *, 0x350)->f4;
                h = 0.0f;
                if (F(f32, 0x3AC) < k * k) {
                    if (((TObjChara *)arg0)->random_ratio() > 0.5f) {
                        F(s32, 0x3D4) = (-65536.0f * r) / (6.283184f * F(f32, 0x468));
                    } else {
                        F(s32, 0x3D4) = (65536.0f * r) / (6.283184f * F(f32, 0x468));
                    }
                    F(s32, 0x3C0) = 1;
                }
                break;
            case 1:
                F(s32, 0x3D0) += F(s32, 0x3D4) / 2;
                F(s32, 0x46C) += F(s32, 0x3D4) / 2;
                F(s32, 0x470) += F(s32, 0x3D4) / 2;
                ((TObjEneRecon *)arg0)->set_orbit_destination(F(s32, 0x3D0));
                ((TObjEneDD_ST *)arg0)->update_velocity();
                r = F(Prm_8031C920 *, 0x350)->f4;
                h = 0.0f;
                if (F(f32, 0x3AC) < r) {
                    F(s32, 0x3C0) = 2;
                }
                break;
            case 2:
                F(s32, 0x3D0) += F(s32, 0x3D4);
                F(s32, 0x46C) += F(s32, 0x3D4);
                F(s32, 0x470) += F(s32, 0x3D4);
                ((TObjEneRecon *)arg0)->set_orbit_destination(F(s32, 0x3D0));
                ((TObjEneDD_ST *)arg0)->update_velocity();
                r = F(Prm_8031C920 *, 0x350)->f4;
                h = 10.0f * sin_table_lookup(F(s32, 0x3D8));
                F(s32, 0x3D8) += 0x380;
                break;
            }
            VecCopy((Vec *)(arg0 + 0x44C), (const Vec *)(arg0 + 0x3A0));
            ((TObjEneRecon *)arg0)->set_flag2(F(f32, 0x44C), F(f32, 0x454), r);
            F(f32, 0x448) = ((TObjEneRecon *)arg0)->approach_value(F(f32, 0x448), F(f32, 0x398) + h);
            ((TObjEneRecon *)arg0)->clamp_min_height();
            t = F(Obj_8031C920 *, 0x390);
            F(s32, 0x60) = 10430.38043493439 * atan2_float(t->x - F(f32, 0x38), t->z - F(f32, 0x40));
            ((TObjEneRecon *)(arg0))->check_collisions();
            ((TObjEneRecon *)arg0)->spawn_trap_b();
        }
        break;
    }
}

void TObjEneRecon__sub_8031CCFC(u8 *arg0, s32 reason) {
    switch (reason) {
    case 4:
        ((TObjEneEpsilon *)arg0)->requested_action = 1;
        ((TObjEneDD_ST *)arg0)->clear_intangible();
        *(u32 *)((s8 *)arg0 + 0x444) &= ~1;
        *(u32 *)((s8 *)arg0 + 0x444) |= 2;
        ((TObjEneEpsilon *)arg0)->actorFlags |= 0x01000000;
        *(s32 *)((s8 *)arg0 + 0x474) = 1;
        *(s32 *)((s8 *)arg0 + 0x3C4) = 0;
        *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
        break;
    case 3:
        if (*(f32 *)((s8 *)arg0 + 0x3AC) > 450.0f) {
            ((TObjEneDD *)arg0)->transition_enemy_state(1);
            break;
        }
        switch (*(s32 *)((s8 *)arg0 + 0x3C0)) {
        case 0:
            if (((TObjEneEpsilon *)arg0)->current_target == 0) {
                ((TObjEneDD *)arg0)->transition_enemy_state(1);
            }
            break;
        case 1:
            break;
        case 2:
            ((TObjEneDD *)arg0)->transition_enemy_state(4);
            break;
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneEpsilon *)arg0)->update_death_check() == 0) {
            ((TObjEneDD_ST *)(arg0))->enemy_clear_target();
        }
        switch (*(s32 *)((s8 *)arg0 + 0x3C0)) {
        case 0:
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD_ST *)arg0)->update_velocity();
            ((TObjEneEpsilon *)arg0)->rotation_y = approach_angle_limited(((TObjEneEpsilon *)arg0)->rotation_y,
                (s32)(10430.38043493439 * atan2_float(((TObjEneEpsilon *)arg0)->destination_direction.x, ((TObjEneEpsilon *)arg0)->destination_direction.z)),
                0x400);
            (*(s32 *)((s8 *)arg0 + 0x3C4))++;
            if (*(s32 *)((s8 *)arg0 + 0x3C4) > 0xF) {
                *(s32 *)((s8 *)arg0 + 0x3C0) = 1;
                ((TObjEneEpsilon *)arg0)->requested_action = 3;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A808), arg0 + 0x38, 0, 0);
            }
            break;
        case 1:
            if (((TObjMotion *)arg0)->is_passing_frame(10.0f) != 0) {
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80A), arg0 + 0x38, 0, 0);
                TObjEneReconBomb::create(arg0, arg0, arg0 + 0x40C);
            } else if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x3C0) = 2;
            }
            break;
        }
        break;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x474) = 0;
        break;
    }
}

void TObjEneRecon__sub_8031CF30(u8 *arg0, s32 reason) {
    s32 i;
    u8 *p;
    f32 d;
    switch (reason) {
    case 4:
        F(s16, 0xB8) = 1;
        ((TObjEneDD_ST *)arg0)->clear_intangible();
        F(u32, 0x444) &= ~1;
        F(u32, 0x444) |= 2;
        F(u32, 0x30) &= ~0x01000000;
        F(s32, 0x3C4) = 0;
        F(s32, 0x3C0) = 0;
        F(s32, 0x3C8) = 0;
        F(s32, 0x474) = 1;
        break;
    case 3:
        if (F(f32, 0x3AC) > 450.0f) {
            ((TObjEneDD *)arg0)->transition_enemy_state(1);
            break;
        }
        switch (F(s32, 0x3C0)) {
        case 0:
        case 1:
            if (F(u32, 0x390) == 0) {
                ((TObjEneDD *)arg0)->transition_enemy_state(1);
            }
            break;
        case 2:
            break;
        case 3:
            ((TObjEneDD *)arg0)->transition_enemy_state(4);
            break;
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneEpsilon *)arg0)->update_death_check() == 0) {
            ((TObjEneDD_ST *)(arg0))->enemy_clear_target();
        }
        switch (F(s32, 0x3C0)) {
        case 0:
            if (F(u32, 0x390) != 0) {
                ((TObjEneRecon *)arg0)->advance_field398();
            }
            ((TObjEneDD_ST *)arg0)->update_velocity();
            F(f32, 0x44C) = sin_table_lookup(F(s32, 0x60));
            F(f32, 0x454) = cos_table_lookup(F(s32, 0x60));
            ((TObjEneRecon *)arg0)->update_collide_flag();
            F(f32, 0x448) = ((TObjEneRecon *)arg0)->approach_value(F(f32, 0x448), F(f32, 0x398));
            ((TObjEneRecon *)arg0)->clamp_min_height();
            if (TObjEneRecon__sub_8031DA90(arg0) != 0) {
                F(s16, 0xB8) = 1;
                F(s32, 0x3C0) = 1;
            }
            break;
        case 1:
            F(s32, 0x3C4)++;
            if (F(s32, 0x3C4) >= ((Data_8031CF30 *)TObjEneRecon__data_805D6AFC)->f1C) {
                F(s32, 0x3C4) = 0;
                F(s32, 0x3C0) = 2;
                F(s16, 0xB8) = 2;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A808), arg0 + 0x38, 0, 0);
            }
            ((TObjEneRecon *)arg0)->update_flag_0x444();
            break;
        case 2:
            if (((TObjMotion *)arg0)->is_passing_frame(3.0f) != 0 || ((TObjMotion *)arg0)->is_passing_frame((f32)(4.0f)) != 0) {
                spawn_particle_effect((const Vec *)(arg0 + 0x2FC), 0x218);
            }
            if (((TObjMotion *)arg0)->is_passing_frame(7.0f) != 0) {
                F(s32, 0x3C8) = 1;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A809), arg0 + 0x38, 0, 0);
            } else if (((TObjMotion *)arg0)->is_passing_frame(31.0f) != 0) {
                F(s32, 0x3C8) = 0;
            }
            if (F(s32, 0x3C8) == 1) {
                for (i = 0; i < lbl_805D5868; i++) {
                    p = (u8 *)TObjPlayer::get_player_data(i);
                    if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && p != NULL && get_entity_id(p) < 0x1000 && ((TObjChara *)p)->has_flag_0x800() == 0) {
                        d = horizontal_distance_squared(p + 0x2FC, arg0 + 0x40C);
                        if (d <= F(AttackParams *, 0x318)->get_damage_radius() * F(AttackParams *, 0x318)->get_damage_radius()) {
                            DirectAttackPayload attack;
                            attack.kind = 0;
                            attack.power = (f32)get_attack_params_atp_min(F(AttackParams *, 0x318));
                            ((TObjChara *)p)->receive_direct_attack(arg0, attack, NULL, -1, -1);
                            ((TObjChara *)p)->apply_knockback_from_attacker(arg0, 7.0f);
                        }
                    }
                }
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s32, 0x3C0) = 3;
            }
            ((TObjEneRecon *)arg0)->update_flag_0x444();
            break;
        }
        ((TObjEneDD_ST *)arg0)->check_collisions();
        ((TObjEneRecon *)arg0)->spawn_trap_a();
        break;
    case 5:
        F(s32, 0x474) = 0;
        break;
    }
}

void TObjEneRecon__sub_8031D380(u8 *arg0, s32 reason) {
  s32 temp_r4;
  switch (reason)
  {
    case 4:
      *((s16 *) (((s8 *) arg0) + 0xB8)) = 1;
      (((TObjEneRecon *)(arg0))->clear_intangible());
      *((s32 *) (((s8 *) arg0) + 0x444)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x444))) & 0xFFFFFFFE);
      *((s32 *) (((s8 *) arg0) + 0x444)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x444))) | 2);
      *((s32 *) (((s8 *) arg0) + 0x30)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x30))) | 0x01000000);
      return;
    case 3:
      if (((s32) (*((s32 *) (((s8 *) arg0) + 0x3B0)))) >= 0x96)
    {
      ((TObjEneDD *)arg0)->transition_enemy_state(5);
    }
    case 5:
      return;
    case 0:
      ((TObjMotion *)arg0)->advance_animation();
      if ((((TObjEneEpsilon *)arg0)->update_death_check() != 0) || ((((TObjEneRecon *)(arg0))->acquire_target((200.0f))) != 0))
    {
      ((TObjEneDD *)arg0)->transition_enemy_state(4);
    }
    else
    {
      *((s32 *) (((s8 *) arg0) + 0x3B0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x3B0))) + 1);
    }
      ((TObjEneRecon *)arg0)->sync_height();
      ((TObjEneDD_ST *)arg0)->update_velocity();
      temp_r4 = *((s32 *) (((s8 *) arg0) + 0x60));
      *((s32 *) (((s8 *) arg0) + 0x60)) = (s32) ((u16)(temp_r4 + 0x400));
      (((TObjEneRecon *)(arg0))->check_collisions());
      ((TObjEneRecon *)arg0)->spawn_trap_b();
      break;
  }
  return;
}
void TObjEneRecon::sub_8031D4B0(s32 reason) {
    u8 *self = (u8 *)this;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_5;
    f32 temp_f31;
    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_intangible();
        *(s32 *)((s8 *)self + 0x444) = (s32) (*(s32 *)((s8 *)self + 0x444) & 0xFFFFFFFE);
        *(s32 *)((s8 *)self + 0x444) = (s32) (*(s32 *)((s8 *)self + 0x444) | 2);
        *(s32 *)((s8 *)self + 0x30) = (*(s32 *)((s8 *)self + 0x30) | 0x01000000);
        *(s32 *)((s8 *)self + 0x3C0) = 0;
        this->rotation_y = (s32) (10430.38043493439 * atan2_float((f32) (*(f32 *)((s8 *)self + 0x428)), (f32) (*(f32 *)((s8 *)self + 0x430))));
        ((TObjEneDD_ST *)(self))->enemy_clear_target();
        break;
    case 3:
        if ((s32) *(s32 *)((s8 *)self + 0x3C0) == 2) {
            ((TObjEneDD *)self)->transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)self)->advance_animation();
        temp_f1 = *(f32 *)((s8 *)self + 0x428);
        temp_f2 = *(f32 *)((s8 *)self + 0x430);
        temp_f31 = (temp_f1 * temp_f1) + (temp_f2 * temp_f2);
        ((TObjEneDD *)self)->move_with_wall_slide_on_ground(temp_f1, temp_f2, temp_f31);
        switch (*(s32 *)((s8 *)self + 0x3C0)) {
        case 0:
            *(f32 *)((s8 *)self + 0x448) = (f32) (*(f32 *)((s8 *)self + 0x448) + *(f32 *)((s8 *)self + 0x42C));
            if (*(f32 *)((s8 *)self + 0x448) == *(f32 *)((s8 *)self + 0x460)) {
                *(s32 *)((s8 *)self + 0x3C0) = 1;
            } else {
                *(f32 *)((s8 *)self + 0x428) *= 0.95f;
                *(f32 *)((s8 *)self + 0x430) *= 0.95f;
                if (*(f32 *)((s8 *)self + 0x448) > *(f32 *)((s8 *)self + 0x460)) {
                    temp_f2_2 = *(f32 *)((s8 *)self + 0x42C);
                    if (temp_f2_2 > -0.3f) {
                        *(f32 *)((s8 *)self + 0x42C) = (f32) (temp_f2_2 - 0.1f);
                        if (*(f32 *)((s8 *)self + 0x42C) < -0.3f) {
                            *(f32 *)((s8 *)self + 0x42C) = -0.3f;
                        }
                    } else {
                        *(f32 *)((s8 *)self + 0x42C) *= 0.9f;
                        if (*(f32 *)((s8 *)self + 0x42C) > -0.3f) {
                            *(f32 *)((s8 *)self + 0x42C) = -0.3f;
                        }
                    }
                    temp_f1_2 = *(f32 *)((s8 *)self + 0x448);
                    temp_f2_3 = *(f32 *)((s8 *)self + 0x460);
                    if ((temp_f1_2 + *(f32 *)((s8 *)self + 0x42C)) < temp_f2_3) {
                        *(f32 *)((s8 *)self + 0x42C) = (f32) (temp_f2_3 - temp_f1_2);
                    }
                } else {
                    if ((*(f32 *)((s8 *)self + 0x42C)) < 0.3f) {
                        *(f32 *)((s8 *)self + 0x42C) += 0.1f;
                        if (*(f32 *)((s8 *)self + 0x42C) > 0.3f) {
                            *(f32 *)((s8 *)self + 0x42C) = 0.3f;
                        }
                    } else {
                        *(f32 *)((s8 *)self + 0x42C) *= 0.9f;
                        if (*(f32 *)((s8 *)self + 0x42C) < 0.3f) {
                            *(f32 *)((s8 *)self + 0x42C) = 0.3f;
                        }
                    }
                    temp_f1_3 = *(f32 *)((s8 *)self + 0x448);
                    temp_f2_5 = *(f32 *)((s8 *)self + 0x460);
                    if ((temp_f1_3 + *(f32 *)((s8 *)self + 0x42C)) > temp_f2_5) {
                        *(f32 *)((s8 *)self + 0x42C) = (f32) (temp_f2_5 - temp_f1_3);
                    }
                }
            }
            break;
        case 1:
            if (temp_f31 <= 0.010000001f) {
                *(s32 *)((s8 *)self + 0x3C0) = 2;
            } else {
                *(f32 *)((s8 *)self + 0x428) *= 0.95f;
                *(f32 *)((s8 *)self + 0x430) *= 0.95f;
            }
            break;
        }
        ((TObjEneRecon *)self)->update_flag_0x444();
        *(f32 *)((s8 *)self + 0x44) = (f32) *(f32 *)((s8 *)self + 0x2FC);
        *(f32 *)((s8 *)self + 0x4C) = (f32) *(f32 *)((s8 *)self + 0x304);
        ((TObjEneRecon *)self)->clamp_min_height();
        this->update_body_colliders();
        break;
    }
}

s32 TObjEneRecon::acquire_target(f32 range) {
    if (this->is_confused() != 0) {
        return ((TObjEneDD_ST *)this)->select_and_apply_target(range);
    }
    return select_nearest_target(range);
}

void TObjEneRecon::spawn_trap_a() {
    s32 arg0 = (saddr)this;
    play_persistent_sound((TObjEneRecobox::remap_area_sound_id(0x4003AD07)), (arg0), (arg0 + 0x38), 0, 0);
}

void TObjEneRecon::spawn_trap_b() {
    s32 arg0 = (saddr)this;
    play_persistent_sound((TObjEneRecobox::remap_area_sound_id(0x4003B206)), (arg0), (arg0 + 0x38), 0, 0);
}

u16 TObjEneRecon::sub_8031D878() {
    if (*(s32 *)((s8 *)this + 0x474) != 0) {
        return target_id;
    }
    return 0xFFFFU;
}

}

struct Recon_8031D898 {
    u8 pad0[0x38C];
    u16 target;
    u8 pad38E[0x434 - 0x38E];
    u16 owner;
    u8 pad436[0x470 - 0x436];
    s32 f470;
    s32 f474;
};

struct Recon_8031D994 {
    u8 pad0[0x38C];
    u16 target;
    u8 pad38E[0x434 - 0x38E];
    u16 owner;
    u8 pad436[0x46C - 0x436];
    s32 f46C;
    s32 f470;
    s32 f474;
};

extern "C" {
f32 fabs_float(f32);

void TObjEneRecon::retarget() {
    TargetCandidate hits[5];
    void *p;
    s32 n;
    u16 id;
    s32 i;
    p = find_entity_by_id(((Recon_8031D898 *)this)->owner);
    if (p == 0) {
        queue_destruction();
        return;
    }
    if (((TObjEneRecobox *)p)->is_below_child_limit(((Recon_8031D898 *)this)->target) != 0) {
        ((Recon_8031D898 *)this)->f470 = 0;
        transition_enemy_state(3);
        return;
    }
    n = collect_enemy_target_candidates(this, hits, 10000.0f);
    for (i = 0; i < n; i++) {
        id = hits[i].id;
        if (id != ((Recon_8031D898 *)this)->target && ((TObjEneRecobox *)p)->is_below_child_limit(id) != 0) {
            ((Recon_8031D898 *)this)->f470 = 0;
            enemy_set_target_id(this, id);
            transition_enemy_state(3);
            return;
        }
    }
    transition_enemy_state(4);
    ((Recon_8031D898 *)this)->f474 = 0;
}

void TObjEneRecon::select_next_target() {
    TargetCandidate hits[5];
    void *p;
    s32 n;
    u16 id;
    s32 i;
    p = find_entity_by_id(((Recon_8031D994 *)this)->owner);
    if (p == 0) {
        queue_destruction();
        return;
    }
    if (((TObjEneRecobox *)p)->is_below_child_limit(((Recon_8031D994 *)this)->target) != 0) {
        ((Recon_8031D994 *)this)->f46C = 0;
        transition_enemy_state(2);
        return;
    }
    n = collect_enemy_target_candidates(this, hits, 10000.0f);
    for (i = 0; i < n; i++) {
        id = hits[i].id;
        if (id != ((Recon_8031D994 *)this)->target && ((TObjEneRecobox *)p)->is_below_child_limit(id) != 0) {
            ((Recon_8031D994 *)this)->f46C = 0;
            enemy_set_target_id(this, id);
            transition_enemy_state(2);
            return;
        }
    }
    transition_enemy_state(4);
    ((Recon_8031D994 *)this)->f474 = 0;
}

s32 TObjEneRecon__sub_8031DA90(u8 *arg0) {
    f32 temp_f31;
    if ((*(f32 *)((s8 *)arg0 + 0x3AC) < (5.0f + ((AttackParams *)TObjEneRecon__attack_params)->get_attack_range())) && (fabs_float((f32) (*(f32 *)((s8 *)arg0 + 0x448) - *(f32 *)((s8 *)arg0 + 0x398))) < 1.0f)) {
        temp_f31 = vec3_dot((Vec *)(arg0 + 0x44C), (Vec *)(arg0 + 0x3A0));
        
        if (temp_f31 >= cos_table_lookup(((AttackParams *)(*(saddr *)((s8 *)arg0 + 0x318)))->get_attack_angle())) {
            return 1;
        }
    }
    return 0;
}

f32 TObjEneRecon::approach_value(f32 farg0, f32 farg1) {
    f32 temp_f31;
    f32 var_f1;

    temp_f31 = farg1 - farg0;
    if (fabs_float(temp_f31) < 0.2f) {
        return farg1;
    }
    var_f1 = 0.1f;
    var_f1 = temp_f31 * var_f1;
    if (var_f1 > 1.5f) {
        var_f1 = 1.5f;
    } else if (var_f1 < -1.5f) {
        var_f1 = -1.5f;
    }
    return farg0 + var_f1;
}

}


void TObjEneRecon::update_body_colliders() {
    u8 *self = (u8 *)this;
    f32 d;
    u8 *t = *(u8 **)((s8 *)self + 0x390);
    if (t != NULL && this->mode == 2) {
        *(f32 *)((s8 *)self + 0x3C) = *(f32 *)((s8 *)t + 0x3C);
    } else {
        Vec v = *(Vec *)(self + 0x38);
        v.y += *(f32 *)((s8 *)self + 0x448);
        if (project_actor_to_ground(self, &v, self + 0x248) != 0) {
            *(f32 *)((s8 *)self + 0x3C) = v.y;
        }
    }
    d = *(f32 *)((s8 *)self + 0x448) - *(f32 *)((s8 *)self + 0x3C);
    if (d >= 30.0f) {
        this->set_colliders_contact_high();
    } else {
        this->set_colliders_contact_low();
    }
    *(f32 *)((s8 *)(*(u8 **)((s8 *)self + 0xA4)) + 4) = d;
}


void TObjEneRecon::check_collisions() {
    update_body_colliders();
    TObjEneDD::check_collisions();
    this->clamp_min_height();
}


#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TObjEneRecon::clamp_min_height() {
    u8 *self = (u8 *)this;
  f32 new_var;
  f32 temp_f2;
  new_var = *((f32 *) (((s8 *) self) + 0x448));
  temp_f2 = *((f32 *) (((s8 *) self) + 0x3C));
  if ((new_var - temp_f2) < 5.0f)
  {
    *((f32 *) (((s8 *) self) + 0x448)) = (f32) (5.0f + temp_f2);
  }
  *((f32 *) (((s8 *) self) + 0x300)) = (f32) (*((f32 *) (((s8 *) self) + 0x448)));
}
#pragma pop

extern "C" {

s32 VecCopy__FP3VecPC3Vec(void *, void *, void *);

void TObjEneRecon::update_position_from_offsets() {
    u8 *self = (u8 *)this;
    *(f32 *)((s8 *)self + 0x2FC) = (f32) *(f32 *)((s8 *)self + 0x38);
    *(f32 *)((s8 *)self + 0x304) = (f32) *(f32 *)((s8 *)self + 0x40);
    VecCopy__FP3VecPC3Vec(self + 0x74, self + 0x2FC, self);
}

}


extern "C" {


void TObjEneRecon::update_collide_flag() {
    void *temp_r5;

    temp_r5 = this->movementParameters;
    if (TObjEneEpsilon__sub_800B92F8(this, *(s32 *)((s8 *)temp_r5 + 8), *TObjEneRecon__data_805D6AFC) != 0) {
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) | 2);
        return;
    }
    *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) & 0xFFFFFFFD);
}

void TObjEneRecon::set_flag2(f32 x, f32 z, f32 r) {
    if (this->move_with_wall_slide_commit(x, z, r) != 0U) {
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) | 2);
        return;
    }
    *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) & 0xFFFFFFFD);
}

void TObjEneRecon::update_flag_0x444() {
    if (update_ground_contact() != 0U) {
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) | 2);
        return;
    }
    *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) & 0xFFFFFFFD);
}

void enemy_copy_target_destination__12TObjEneDD_STFv(void *);

#pragma push
#pragma fp_contract on
void TObjEneRecon::set_orbit_destination(s32 arg1) {
    enemy_copy_target_destination();
    *(f32 *)((s8 *)((u8 *)this) + 0x394) = (f32) ((*(f32 *)((s8 *)((u8 *)this) + 0x468) * sin_table_lookup(arg1)) + *(f32 *)((s8 *)((u8 *)this) + 0x394));
    *(f32 *)((s8 *)((u8 *)this) + 0x398) = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x460);
    *(f32 *)((s8 *)((u8 *)this) + 0x39C) = (f32) ((*(f32 *)((s8 *)((u8 *)this) + 0x468) * cos_table_lookup(arg1)) + *(f32 *)((s8 *)((u8 *)this) + 0x39C));
}
#pragma pop

void TObjEneRecon::advance_field398() {
    ((s32 (*)())enemy_copy_target_destination__12TObjEneDD_STFv)();
    *(f32 *)((s8 *)this + 0x398) = (f32) (*(f32 *)((s8 *)this + 0x398) + *(f32 *)((s8 *)this + 0x464));
}
void TObjEneRecon::sync_height() {
    ((s32 (*)())enemy_copy_target_destination__12TObjEneDD_STFv)();
    *(f32 *)((s8 *)this + 0x398) = (f32) *(f32 *)((s8 *)this + 0x460);
}
void TObjEneRecon::run_miss_reaction() {  }
void TObjEneRecon::run_hit_reaction() { if (this->mode != 6) { transition_enemy_state(6); } }

void TObjEneRecon::run_death_reaction() {
    u8 *self = (u8 *)this;
    s16 temp_r0;
    temp_r0 = this->mode;
    if ((temp_r0 != 7) && (temp_r0 != 8)) {
        ((TObjEneDD *)self)->transition_enemy_state(7);
    }
}

void TObjEneRecon::refresh_target() {  }

void *TObjEneRecon__ai_parameters[7] = {
    (void *)0x43610000, (void *)0x3f6d097b, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
CollisionBody TObjEneRecon__collision_body_template = {
    {0.0f, 0.0f, 0.0f}, 5.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f
};
TObjMotionAction TObjEneRecon__animation_entries[6] = {
    { 1, 0, 8, 0.7f, 0 },
    { 1, 1, 9, 0.7f, 0 },
    { 3, 2, 4, 0.8f, 0 },
    { 3, 3, 5, 0.7f, 0 },
    { 3, 4, 6, 0.6f, 0 },
    { 1, 5, 7, 0.7f, 0 },
};
}

#pragma defer_codegen on
f32 TObjEneRecon::get_field_4d0() { return this->m_4d0; }
f32 TObjEneRecon::get_field_4d4() { return *(f32*)((char*)this + 0x4d4); }

struct RecoveredFields_8031E708_temp_r5
{
  u8 unknown_0[0x8];
  s32 field_8;
  NJS_TEXLIST *texlist;
};

extern "C" {
typedef struct RecoveredFields_8031E708_temp_r5 RecoveredFields_8031E708_temp_r5;
void TObjEneRecon::load_resources() {
  u8 *temp_r5;
  TObjEneRecon__recobox_static_instance = TObjEneRecobox::get_bml_resource();
  boss3_volopt_instance = new TUnk_8048FA00((long)(saddr)TObjEneRecon__recobox_static_instance->models->model);
  recon_intro_stage = 0;
  recon_model_matrix_ptr = 0;
  lbl_805D6AF0 = (saddr)TLobby::register_boss(0x42);
  TObjEneRecon__attack_params = (saddr)TLobby::dispatch_shared_handler_b(0x42);
  TObjEneRecon__resistance_params = (saddr)TLobby::register_object(0x42);
  TObjEneRecon__data_805D6AFC = (f32 *)TLobby::dispatch_shared_handler_a(0x42);
  TObjEneReconBomb::load_resources();
  NpcAnimationBinding binding = recon_anim_binding;
  binding.motions = reinterpret_cast<BmlMotionEntry *>(TObjEneRecon__recobox_static_instance->motions);
  temp_r5 = (u8 *)TObjEneRecon__recobox_static_instance->models;
  NpcModelRegistry::register_animated_chunk((s16)(0xC), reinterpret_cast<void *>(((int) ((RecoveredFields_8031E708_temp_r5 *) temp_r5)->field_8)), reinterpret_cast<void *>(((RecoveredFields_8031E708_temp_r5 *) temp_r5)->texlist), &binding, TObjEneRecon__collision_body_template.radius, (f32)(15.0f));
}


TObjEneRecon *TObjEneRecon::create(TObjEneRecobox *owner, u16 id, s32 index, Vec *pos, Vec *dir) {
    return new TObjEneRecon(tl_04, owner, id, index, pos, dir);
}

}

void TObjEneRecon::release_static_instance() {
    TObjEneReconBomb::release_resources();
    if (boss3_volopt_instance != 0) {
        delete boss3_volopt_instance;
        boss3_volopt_instance = 0;
    }
}

TObjEneRecon::TObjEneRecon(TObject *parent, TObjEneRecobox *owner, u16 id, s32 index, Vec *pos, Vec *dir) : TObjEneDD_ST(parent) {
    m_name = TObjEneRecon_name_ref;
    owner_id = get_entity_id(owner);
    init_common_from((u8 *)owner);
    entity_id = id;
    set_index = index;
    VecCopy(&position, pos);
    VecCopy(&owner_position, &owner->position);
    VecCopy(&spawn_direction, dir);
    init_state();
    offset_max += ((TObjEneRecon *)owner)->get_field_4d0();
    rotate_rad += ((TObjEneRecon *)owner)->get_field_4d4();
    set_entry = 0;
}

extern "C" {

void obj_setFlags30(void *, u32);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void run_task__12TObjEneReconFv(TObjEneRecon *ene_recon);


#pragma push
#pragma fp_contract on
void TObjEneRecon::init_state() {
    u8 *self = (u8 *)this;
    u8 *temp_r6;

    ((TObjEneDD *)self)->init_position_vectors();
    *(s32 *)((s8 *)self + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecon__recobox_static_instance + 0x42C)) + 8);
    temp_r6 = (u8 *)(*(u8 **)((s8 *)TObjEneRecon__recobox_static_instance + 0x42C));
    this->texlist = (s32) *(s32 *)((s8 *)temp_r6 + 0xC);
    ((TObjEneDD *)self)->init_model((CollisionBody *)&TObjEneRecon__collision_body_template, 1);
    ((TObjMotion *)self)->set_field_d8((saddr)TObjEneRecon__animation_entries);
    ((TObjMotion *)self)->set_field_dc((int) (*(s32 *)((s8 *)TObjEneRecon__recobox_static_instance + 0x430)));
    this->requested_action = 0;
    ((TObjMotion *)self)->set_animation((this->requested_action));
    ((TObjMotion *)self)->set_field_b8((int) (this->requested_action));
    ((TObjEneDD *)self)->reset_hp((u8 *)lbl_805D6AF0, (u8 *)TObjEneRecon__attack_params, (u8 *)TObjEneRecon__resistance_params);
    ((TObjEneDD *)self)->set_state_flag_4();
    *(void **)((s8 *)self + 0x350) = (void *) TObjEneRecon__ai_parameters;
    ((TObjEneDD *)self)->initialize_enemy_state(0x44);
    *(f32 *)((s8 *)self + 0x37C) = 5.0f;
    ((TObjEneDD_ST *)self)->enemy_init_acquire_period(0xA);
    ((TObjEneDD_ST *)self)->enemy_init_validate_period(0xA);
    ((TObjEneDD_ST *)self)->set_active();
    *(s32 *)((s8 *)self + 0x30) = (*(s32 *)((s8 *)self + 0x30) | 0x01000000);
    *(s32 *)((s8 *)self + 0x444) = 2;
    *(f32 *)((s8 *)self + 0x448) = (*(f32 *)((s8 *)self + 0x3C));
    *(f32 *)((s8 *)self + 0x44C) = 0.0f;
    *(f32 *)((s8 *)self + 0x450) = 0.0f;
    *(f32 *)((s8 *)self + 0x454) = 0.0f;
    *(f32 *)((s8 *)self + 0x458) = 0.0f;
    *(s32 *)((s8 *)self + 0x45C) = 0;
    *(f32 *)((s8 *)self + 0x460) = (f32) ((2.0f * ((TObjEneDD *)self)->calc_elapsed_scaled()) + 45.0f);
    *(f32 *)((s8 *)self + 0x464) = (f32) ((2.0f * ((TObjEneDD *)self)->calc_elapsed_scaled()) + 15.0f);
    *(f32 *)((s8 *)self + 0x468) = (f32) ((5.0f * ((TObjEneDD *)self)->calc_elapsed_scaled()) + 50.0f);
    *(s32 *)((s8 *)self + 0x474) = 0;
    *(s32 *)((s8 *)self + 0x478) = 0;
    *(s32 *)((s8 *)self + 0x47C) = 0;
    *(s32 *)((s8 *)self + 0x418) = 0;
    VecCopy((Vec *)(self + 0x41C), (const Vec *)(self + 0x38));
    ((TObjEneRecon *)self)->fade.reset_color();
    *(s32 *)((s8 *)self + 0x46C) = 0;
    *(s32 *)((s8 *)self + 0x470) = 0;
    VecCopy((Vec *)(self + 0x40C), (const Vec *)(self + 0x38));
    *(s32 *)((s8 *)self + 0x3C0) = 0;
    *(s32 *)((s8 *)self + 0x3C4) = 0;
    *(s32 *)((s8 *)self + 0x3C8) = 0;
    *(s32 *)((s8 *)self + 0x3CC) = 0;
    *(s32 *)((s8 *)self + 0x3D0) = 0;
    *(s32 *)((s8 *)self + 0x3D4) = 0;
    *(s32 *)((s8 *)self + 0x3D8) = 0;
    *(s32 *)((s8 *)self + 0x3DC) = 0;
    *(f32 *)((s8 *)self + 0x3E0) = 0.0f;
    *(f32 *)((s8 *)self + 0x3E4) = 0.0f;
    *(f32 *)((s8 *)self + 0x3E8) = 0.0f;
    *(f32 *)((s8 *)self + 0x3EC) = 0.0f;
    *(f32 *)((s8 *)self + 0x3F0) = 0.0f;
    *(f32 *)((s8 *)self + 0x3F4) = 0.0f;
    *(f32 *)((s8 *)self + 0x3F8) = 0.0f;
    *(f32 *)((s8 *)self + 0x3FC) = 0.0f;
    *(f32 *)((s8 *)self + 0x400) = 0.0f;
    *(f32 *)((s8 *)self + 0x404) = 0.0f;
    *(f32 *)((s8 *)self + 0x408) = 0.0f;
    this->mode = 0;
    this->dispatch_action(this->mode, 4);
}

}
#pragma pop
TObjEneRecon::~TObjEneRecon() {
    this->send_entity_set_flags();
    free_collision_body_parts(this);
    if (m_478 != NULL) {
        m_478->queue_destruction();
        m_478 = NULL;
    }
}


void run_task__12TObjEneReconFv(TObjEneRecon *ene_recon) {
    f32 temp_f2;
    f32 temp_f31;
    f32 var_f30;
    s16 temp_r0;
    s16 temp_r0_2;
    saddr entity;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRecon *)(ene_recon))->run_demo_task();
        return;
    }
    entity = (saddr)find_entity_by_id((*(u16 *)((s8 *)ene_recon + 0x434)));
    if ((entity == 0) || (((TObject *)entity)->all_parents_unqueued_for_destruction() == 0)) {
        ene_recon->queue_destruction();
        return;
    }
    temp_r0 = ene_recon->mode;
    if ((temp_r0 != 8) && (temp_r0 != 7) && (((TObjEneRecobox *)entity)->is_anim_6() == 1)) {
        ene_recon->m_2dc = (s32) (ene_recon->m_2dc | 4);
        ((TObjPlayer *)ene_recon)->set_hp_clamped(0);
        obj_setFlags30(ene_recon, 0xA00U);
        ((TObjEneRecon *)(ene_recon))->vfunc_74(0);
    }
    if (((TObjEneRecon *)(ene_recon))->update_status_effects() != 4) {
        ((TObjEneRecon *)(ene_recon))->update_action_state();
        temp_r3_2 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
        if (temp_r3_2 == NULL) {
            *(u8 **)((s8 *)ene_recon + 0x478) = (u8 *)create_particle_emitter((u8 *)ene_recon + 0x2FC, 0x217);
            temp_r3_3 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
            if (temp_r3_3 != NULL) {
                ((TParticleCtrl *)temp_r3_3)->enable();
            }
        } else {
            temp_r0_2 = ene_recon->mode;
            if ((temp_r0_2 == 8) || (temp_r0_2 == 7)) {
                ((TParticleCtrl *)temp_r3_2)->enable();
            } else {
                if ((s32) *(s32 *)((s8 *)ene_recon + 0x47C) == 0) {
                    var_f30 = 3.0f;
                    *(s32 *)((s8 *)ene_recon + 0x47C) = 1;
                } else {
                    var_f30 = -3.0f;
                    *(s32 *)((s8 *)ene_recon + 0x47C) = 0;
                }
                if (TObjEneDD::check_v2_mode() != 0) {
                    var_f30 *= 3.0f;
                }
                temp_f31 = var_f30 * cos_table_lookup(ene_recon->rotation_y);
                temp_f2 = var_f30 * -sin_table_lookup(ene_recon->rotation_y);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x60) = (f32) (ene_recon->body_center.x + temp_f31);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x64) = (f32) (-1.5f + ene_recon->body_center.y);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x68) = (f32) (ene_recon->body_center.z + temp_f2);
            }
        }
    } else {
        temp_r3_4 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
        if (temp_r3_4 != NULL) {
            ((TParticleCtrl *)temp_r3_4)->enable();
        }
    }
    ene_recon->update_position_from_offsets();
    ((TObjEnemy *)ene_recon)->submit_default_cursor_candidate();
    ((TObjEneRecon *)(ene_recon))->render_minimap_dot();
    ene_recon->update_ground_probe();
}

void TObjEneRecon::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        sub_8031D4B0(reason);
        return;
    case 1:
        TObjEneRecon__sub_8031D380((u8 *)this, reason);
        return;
    case 2:
        TObjEneRecon__sub_8031CF30((u8 *)this, reason);
        return;
    case 3:
        TObjEneRecon__sub_8031CCFC((u8 *)this, reason);
        return;
    case 4:
        TObjEneRecon__sub_8031C920((u8 *)this, reason);
        return;
    case 6:
        TObjEneRecon__sub_8031C624((u8 *)this, reason);
        return;
    case 7:
        TObjEneRecon__sub_8031C364((u8 *)this, reason);
        return;
    case 5:
        run_task__12TObjEneReconFPvi((u8 *)this, reason);
        return;
    case 8:
        handle_message(reason);
    default:
        return;
    }
}


