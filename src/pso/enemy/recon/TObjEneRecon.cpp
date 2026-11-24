#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
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
#include "pso/object/base/TObjChara.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

extern "C" {
extern TObjMotionAction TObjEneRecon__animation_entries[6];

// Breakup-model parameters TObjEneRecon::state_death hands to create_breakup_mdl.
extern const BreakUpParamRow recon_breakup_params = { 0x14, 0.05f, 1.2f, 0.9f, 0.12f, 0.55f, 0.5f };
const char *TObjEneRecon_name_ref = "TObjEneRecon";
extern const NpcAnimationBinding recon_anim_binding = { NULL, TObjEneRecon__animation_entries, 1, 1, 6 };
// Scale of the ground shadow render draws under the Recon.
extern const Vec recon_shadow_scale = { 0.8f, 1.0f, 0.8f };

player_stats *TObjEneRecon__base_params;
AttackParams *TObjEneRecon__attack_params;
ActorParamBlock *TObjEneRecon__resistance_params;
ReconParams *TObjEneRecon__behavior_params;
BmlResource *TObjEneRecon__recobox_static_instance;
TBreakUpMdlData *boss3_volopt_instance;
s32 recon_intro_stage;
Vec *recon_model_matrix_ptr;


void TObjEneRecon::render_shadows() {
  NJS_OBJECT *bml_model;
  if (TObjEneRecon__recobox_static_instance != NULL)
  {
    NJS_TEXLIST *bml_texlist;
    bml_model = get_bml_model(TObjEneRecon__recobox_static_instance, 2);
    bml_texlist = get_bml_texlist(TObjEneRecon__recobox_static_instance, 2);
    push_matrix();
    translate_matrix(0, position.x, position.y, position.z);
    rotate_matrix_zyx(0, this->rotation_x, this->rotation_y, this->rotation_z);
    scale_matrix(0, 1.5f, 1.5f, 1.5f);
    TObjFish::set_global_param(bml_texlist);
    draw_chunk_object(bml_model);
    pop_matrix();
  }
}

s32 post_translate_matrix(void *);


void TObjEneRecon::render_demo() {
    u8 *self = (u8 *)this;
    if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        ((TObjEneDD *)(self))->draw_ground_shadow(0, 0);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
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
        if (push_reflection_matrix(&floor_point) != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
            push_matrix();
            translate_matrix(0, (f32) (position.x), (f32) (hover_height), (f32) (position.z));
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
#pragma push
#pragma opt_common_subs off
void TObjEneRecon::render() {
    s32 draw_now;
    s32 view_detail;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    if (!(recon_flags & 1)) {
        if (TObjEneDD::is_main_phase_15() != 0) {
            view_detail = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
        } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
            view_detail = 1;
        } else {
            view_detail = 0;
        }
        if (view_detail != 0) {
            draw_now = 1;
            if (render_model_if_visible() == 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                if (((s16) mode == 5) && (fade.has_visible_opacity() != 0)) {
                    fade.set_flags_and_apply_damage_color();
                    if (defer_render() != 0) {
                        draw_now = 0;
                    }
                }
                if (draw_now != 0) {
                    if ((recon_flags & 2) && !(floor_flags & 0x4000)) {
                        Vec v = recon_shadow_scale;
                        draw_ground_shadow(&v, 0);
                    }
                    update_secondary_light();
                    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
                    push_matrix();
                    translate_matrix(0, (f32) (position.x), (f32) (hover_height), (f32) (position.z));
                    rotate_matrix_y(0, (int) (rotation_y));
                    TObjEneDD::clear_global_flag_400();
                    recon_intro_stage = 0;
                    recon_model_matrix_ptr = &root_node_position;
                    root_node_position.x = 0.0f;
                    root_node_position.y = 0.0f;
                    root_node_position.z = 0.0f;
                    set_chunk_model_node_callback(TObjEneRecon::advance_intro_stage);
                    TObjPlayer::toggle_particle_effect();
                    model_render_flags |= 0x01000000;
                    if (view_detail == 1) {
                        draw();
                    } else {
                        draw_motion_model();
                    }
                    model_render_flags &= 0xFEFFFFFF;
                    TParticleCtrl::end_effect_render();
                    set_chunk_model_node_callback(NULL);
                    pop_matrix();
                    update_primary_light();
                }
                if (((s16) mode == 5) && (fade.has_visible_opacity() != 0)) {
                    fade.clear_flag_and_notify();
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
        matrix_mult_vec(0, recon_model_matrix_ptr, recon_model_matrix_ptr);
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

extern s32 actor_frame_tick;
void TObjEneRecon::update_ground_probe() {
    Vec probe;
    CsnHit *hit;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy(&probe, &position);
        probe.y += 15.0f;
        hit = csnVectorUnder(&probe, ground_candidates.groups, 0x4000);
        if (hit != NULL) {
            floor_flags = hit->contact->flags;
            VecCopy(&floor_point, &hit->contact->point);
        } else {
            VecCopy(&floor_point, &position);
        }
    }
    if (floor_flags & 0x4000) {
        request_reflection_render();
    }
}

s32 TObjEneRecon::is_anim_5() {
    return (u8) (mode == 5);
}




extern "C" {

s32 TObjEneRecon::is_dead() {
    return mode == 8 || mode == 7;
}

s32 TObjEneRecon::calc_scaled_value() {
    return (s32) (30.0f * (f32) TObjEneRecon__behavior_params->bomb_seconds);
}

f32 TObjEneRecon::get_bomb_speed() {
    return TObjEneRecon__behavior_params->bomb_speed;
}
f32 TObjEneRecon::get_bomb_power() {
    return TObjEneRecon__behavior_params->bomb_power;
}
f32 TObjEneRecon::get_bomb_radius() {
    return TObjEneRecon__behavior_params->bomb_radius;
}

void TObjEneRecon::handle_message(s32 message) {
    TObjEneRecobox *box;
    switch (message) {
    case 4:
        recon_flags |= 1;
        recon_flags &= ~2;
        if ((box = (TObjEneRecobox *)find_entity_by_id(owner_id)) != NULL) {
            box->remove_child_entity((u8 *)this);
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



extern "C" {
f32 normalize_vector_xz__FP3Vec(void *, s32);

void TObjEneRecon::state_death(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 5;
        clear_intangible();
        recon_flags &= ~3;
        set_entry = 0;
        refresh_lobby_state();
        TBoss8Dragon__sub_800BB7DC(this);
        TBoss8Dragon__sub_800BB7D8(this, 0xF1, 1.0f);
        state_step = 0;
        rise_speed = 0.0f;
        velocity.x = TObjChara::velocity.x;
        velocity.z = TObjChara::velocity.z;
        move_speed = normalize_vector_xz(&velocity);
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80C), &position, 0, 0);
        break;
    case 3:
        if (state_step == 3) {
            transition_enemy_state(8);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
        case 1:
            set_flag2(velocity.x, velocity.z, move_speed);
            {
                Vec v = position;
                v.y += hover_height;
                if (project_actor_to_ground(this, &v, &ground_normal) != 0) {
                    position.y = v.y;
                }
            }
            rise_speed -= 0.1f;
            hover_height += rise_speed;
            if (hover_height < 5.0f + position.y) {
                hover_height = 5.0f + position.y;
                if (state_step == 0) {
                    state_step = 1;
                    rise_speed = 1.0f;
                    move_speed *= 0.98f;
                    if (velocity.x * velocity.x + velocity.z * velocity.z <= 0.3f) {
                        velocity.x = 0.5f * sin_table_lookup(rotation_y);
                        velocity.z = 0.5f * cos_table_lookup(rotation_y);
                    }
                } else {
                    state_step = 2;
                }
            }
            move_speed *= 0.98f;
            clamp_min_height();
            break;
        case 2:
            recon_flags |= 1;
            state_step = 3;
            spawn_particle_effect_with_flags(&position, 0x45, 0x40);
            spawn_particle_effect_with_flags(&position, 0x46, 0x40);
            play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80D), &position, 0, 0);
            TBoss3Volopt::create_breakup_mdl(boss3_volopt_instance, &recon_breakup_params,
                               texlist, &body_center, rotation_y);
            break;
        }
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneRecon::state_damage(s32 reason) {
    s32 n;
    f32 v;
    switch (reason) {
    case 4:
        requested_action = 4;
        clear_intangible();
        recon_flags &= ~1;
        recon_flags |= 2;
        set_field_378(mode);
        ((TBoss8Dragon *)this)->noop();
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003E425), &position, 0, 0);
        state_step = 0;
        break;
    case 3:
        if (motion_flags & 0x10) {
            if (is_confused() != 0) {
                acquire_target(200.0f);
            }
            n = next_mode;
            if (n == 2) {
                select_next_target();
            } else {
                transition_enemy_state(n);
            }
        }
        break;
    case 0:
        advance_animation();
        n = state_step;
        state_step = n + 1;
        velocity.x = TObjChara::velocity.x;
        velocity.z = TObjChara::velocity.z;
        v = normalize_vector_xz__FP3Vec(&velocity, n);
        set_flag2(velocity.x, velocity.z, v);
        clamp_min_height();
        TObjChara::velocity.x *= 0.5f;
        TObjChara::velocity.z *= 0.5f;
        check_collisions();
        break;
    case 5:
        clear_attack_receipts();
        break;
    }
}
#pragma pop

}

extern "C" {


void TObjEneRecon::state_fade_out(s32 reason) {
    TObjEneRecobox *box;

    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        recon_flags &= ~1;
        recon_flags |= 2;
        actorFlags |= 0x01000000;
        fade.reset_color();
        create_timed_particle_emitter(&position, 0x79, 0, 0xF);
        return;
    case 3:
        box = (TObjEneRecobox *)find_entity_by_id(owner_id);
        if (box == NULL) {
            queue_destruction();
            return;
        }
        if (box->is_anim_6() == 1) {
            transition_enemy_state(7);
            return;
        }
        if (fade.decay_value_toward_floor() != 0) {
            recon_flags |= 1;
            box->remove_tracked_target(this);
            queue_destruction();
        }
    case 5:
        return;
    case 0:
        advance_animation();
        update_velocity();
        update_body_colliders();
        clamp_min_height();
        transform_part_positions();
        spawn_trap_b();
        break;
    }
}

}





extern "C" {

void TObjEneRecon::state_orbit(s32 reason) {
    f32 r;
    f32 h;
    f32 k;
    TObjChara *t;
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        recon_flags &= ~1;
        recon_flags |= 2;
        actorFlags |= 0x01000000;
        if (mode == 4) {
            state_step = 2;
        } else {
            state_step = 0;
            orbit_angle = rotation_y + 0x8000;
            orbit_step = 0;
            bob_phase = 0;
        }
        break;
    case 3:
        if (current_target == NULL) {
            transition_enemy_state(5);
        } else if (orbit_since_strike > 0x8000 || orbit_since_strike < -0x8000) {
            select_next_target();
        } else if (orbit_since_bomb > 0x5000 || orbit_since_bomb < -0x5000) {
            retarget();
        }
        break;
    case 1:
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() != 0 || acquire_target(200.0f) != 0) {
            switch (state_step) {
            case 0:
                set_orbit_destination(orbit_angle);
                update_velocity();
                k = 0.2f * rotate_rad;
                r = ((ReconMoveParams *)movementParameters)->move_speed;
                h = 0.0f;
                if (destination_distance < k * k) {
                    if (random_ratio() > 0.5f) {
                        orbit_step = (-65536.0f * r) / (6.283184f * rotate_rad);
                    } else {
                        orbit_step = (65536.0f * r) / (6.283184f * rotate_rad);
                    }
                    state_step = 1;
                }
                break;
            case 1:
                orbit_angle += orbit_step / 2;
                orbit_since_strike += orbit_step / 2;
                orbit_since_bomb += orbit_step / 2;
                set_orbit_destination(orbit_angle);
                update_velocity();
                r = ((ReconMoveParams *)movementParameters)->move_speed;
                h = 0.0f;
                if (destination_distance < r) {
                    state_step = 2;
                }
                break;
            case 2:
                orbit_angle += orbit_step;
                orbit_since_strike += orbit_step;
                orbit_since_bomb += orbit_step;
                set_orbit_destination(orbit_angle);
                update_velocity();
                r = ((ReconMoveParams *)movementParameters)->move_speed;
                h = 10.0f * sin_table_lookup(bob_phase);
                bob_phase += 0x380;
                break;
            }
            VecCopy(&velocity, &destination_direction);
            set_flag2(velocity.x, velocity.z, r);
            hover_height = approach_value(hover_height, destination.y + h);
            clamp_min_height();
            t = current_target;
            rotation_y = 10430.38043493439 * atan2_float(t->position.x - position.x, t->position.z - position.z);
            check_collisions();
            spawn_trap_b();
        }
        break;
    }
}

void TObjEneRecon::state_bomb_attack(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        recon_flags &= ~1;
        recon_flags |= 2;
        actorFlags |= 0x01000000;
        attacking = 1;
        state_timer = 0;
        state_step = 0;
        break;
    case 3:
        if (destination_distance > 450.0f) {
            transition_enemy_state(1);
            break;
        }
        switch (state_step) {
        case 0:
            if (current_target == 0) {
                transition_enemy_state(1);
            }
            break;
        case 1:
            break;
        case 2:
            transition_enemy_state(4);
            break;
        }
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            enemy_clear_target();
        }
        switch (state_step) {
        case 0:
            enemy_copy_target_destination();
            update_velocity();
            rotation_y = approach_angle_limited(rotation_y,
                (s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)),
                0x400);
            (state_timer)++;
            if (state_timer > 0xF) {
                state_step = 1;
                requested_action = 3;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A808), &position, 0, 0);
            }
            break;
        case 1:
            if (is_passing_frame(10.0f) != 0) {
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80A), &position, 0, 0);
                TObjEneReconBomb::create(this, this, &root_node_position);
            } else if (get_flag_b4() != 0) {
                state_step = 2;
            }
            break;
        }
        break;
    case 5:
        attacking = 0;
        break;
    }
}

void TObjEneRecon::state_attack(s32 reason) {
    s32 i;
    TObjPlayer *p;
    f32 d;
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        recon_flags &= ~1;
        recon_flags |= 2;
        actorFlags &= ~0x01000000;
        state_timer = 0;
        state_step = 0;
        hit_window = 0;
        attacking = 1;
        break;
    case 3:
        if (destination_distance > 450.0f) {
            transition_enemy_state(1);
            break;
        }
        switch (state_step) {
        case 0:
        case 1:
            if (current_target == 0) {
                transition_enemy_state(1);
            }
            break;
        case 2:
            break;
        case 3:
            transition_enemy_state(4);
            break;
        }
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            enemy_clear_target();
        }
        switch (state_step) {
        case 0:
            if (current_target != 0) {
                advance_field398();
            }
            update_velocity();
            velocity.x = sin_table_lookup(rotation_y);
            velocity.z = cos_table_lookup(rotation_y);
            update_collide_flag();
            hover_height = approach_value(hover_height, destination.y);
            clamp_min_height();
            if (is_in_strike_range() != 0) {
                requested_action = 1;
                state_step = 1;
            }
            break;
        case 1:
            state_timer++;
            if (state_timer >= TObjEneRecon__behavior_params->strike_delay) {
                state_timer = 0;
                state_step = 2;
                requested_action = 2;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A808), &position, 0, 0);
            }
            update_flag_0x444();
            break;
        case 2:
            if (is_passing_frame(3.0f) != 0 || is_passing_frame((f32)(4.0f)) != 0) {
                spawn_particle_effect(&body_center, 0x218);
            }
            if (is_passing_frame(7.0f) != 0) {
                hit_window = 1;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A809), &position, 0, 0);
            } else if (is_passing_frame(31.0f) != 0) {
                hit_window = 0;
            }
            if (hit_window == 1) {
                for (i = 0; i < lbl_805D5868; i++) {
                    p = TObjPlayer::get_player_data(i);
                    if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && p != NULL && p->get_entity_id() < 0x1000 && p->has_flag_0x800() == 0) {
                        d = horizontal_distance_squared(&p->body_center, &root_node_position);
                        if (d <= attack_params->get_damage_radius() * attack_params->get_damage_radius()) {
                            DirectAttackPayload attack;
                            attack.kind = 0;
                            attack.power = (f32)get_attack_params_atp_min(attack_params);
                            p->receive_direct_attack(this, attack, NULL, -1, -1);
                            p->apply_knockback_from_attacker((u8 *)this, 7.0f);
                        }
                    }
                }
            }
            if (get_flag_b4() != 0) {
                state_step = 3;
            }
            update_flag_0x444();
            break;
        }
        check_collisions();
        spawn_trap_a();
        break;
    case 5:
        attacking = 0;
        break;
    }
}

void TObjEneRecon::state_search(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        recon_flags &= ~1;
        recon_flags |= 2;
        actorFlags |= 0x01000000;
        return;
    case 3:
        if (acquire_counter >= 0x96) {
            transition_enemy_state(5);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() != 0 || acquire_target(200.0f) != 0) {
            transition_enemy_state(4);
        } else {
            acquire_counter++;
        }
        sync_height();
        update_velocity();
        rotation_y = (u16)(rotation_y + 0x400);
        check_collisions();
        spawn_trap_b();
        break;
    }
}

void TObjEneRecon::state_launch(s32 reason) {
    f32 dx;
    f32 dz;
    f32 speed_sq;
    f32 dy;
    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_intangible();
        recon_flags &= ~1;
        recon_flags |= 2;
        actorFlags |= 0x01000000;
        state_step = 0;
        this->rotation_y = 10430.38043493439 * atan2_float(spawn_direction.x, spawn_direction.z);
        enemy_clear_target();
        break;
    case 3:
        if (state_step == 2) {
            transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        dx = spawn_direction.x;
        dz = spawn_direction.z;
        speed_sq = dx * dx + dz * dz;
        move_with_wall_slide_on_ground(dx, dz, speed_sq);
        switch (state_step) {
        case 0:
            hover_height += spawn_direction.y;
            if (hover_height == offset_max) {
                state_step = 1;
            } else {
                spawn_direction.x *= 0.95f;
                spawn_direction.z *= 0.95f;
                if (hover_height > offset_max) {
                    dy = spawn_direction.y;
                    if (dy > -0.3f) {
                        spawn_direction.y = dy - 0.1f;
                        if (spawn_direction.y < -0.3f) {
                            spawn_direction.y = -0.3f;
                        }
                    } else {
                        spawn_direction.y *= 0.9f;
                        if (spawn_direction.y > -0.3f) {
                            spawn_direction.y = -0.3f;
                        }
                    }
                    if (hover_height + spawn_direction.y < offset_max) {
                        spawn_direction.y = offset_max - hover_height;
                    }
                } else {
                    if (spawn_direction.y < 0.3f) {
                        spawn_direction.y += 0.1f;
                        if (spawn_direction.y > 0.3f) {
                            spawn_direction.y = 0.3f;
                        }
                    } else {
                        spawn_direction.y *= 0.9f;
                        if (spawn_direction.y < 0.3f) {
                            spawn_direction.y = 0.3f;
                        }
                    }
                    if (hover_height + spawn_direction.y > offset_max) {
                        spawn_direction.y = offset_max - hover_height;
                    }
                }
            }
            break;
        case 1:
            if (speed_sq <= 0.010000001f) {
                state_step = 2;
            } else {
                spawn_direction.x *= 0.95f;
                spawn_direction.z *= 0.95f;
            }
            break;
        }
        update_flag_0x444();
        prev_position.x = body_center.x;
        prev_position.z = body_center.z;
        clamp_min_height();
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
    play_persistent_sound(TObjEneRecobox::remap_area_sound_id(0x4003AD07), this, &position, 0, 0);
}

void TObjEneRecon::spawn_trap_b() {
    play_persistent_sound(TObjEneRecobox::remap_area_sound_id(0x4003B206), this, &position, 0, 0);
}

u16 TObjEneRecon::get_attack_target_id() {
    if (attacking != 0) {
        return target_id;
    }
    return 0xFFFFU;
}

}

extern "C" {

void TObjEneRecon::retarget() {
    TargetCandidate hits[5];
    void *p;
    s32 n;
    u16 id;
    s32 i;
    p = find_entity_by_id(owner_id);
    if (p == 0) {
        queue_destruction();
        return;
    }
    if (((TObjEneRecobox *)p)->is_below_child_limit(target_id) != 0) {
        orbit_since_bomb = 0;
        transition_enemy_state(3);
        return;
    }
    n = collect_enemy_target_candidates(this, hits, 10000.0f);
    for (i = 0; i < n; i++) {
        id = hits[i].id;
        if (id != target_id && ((TObjEneRecobox *)p)->is_below_child_limit(id) != 0) {
            orbit_since_bomb = 0;
            enemy_set_target_id(this, id);
            transition_enemy_state(3);
            return;
        }
    }
    transition_enemy_state(4);
    attacking = 0;
}

void TObjEneRecon::select_next_target() {
    TargetCandidate hits[5];
    void *p;
    s32 n;
    u16 id;
    s32 i;
    p = find_entity_by_id(owner_id);
    if (p == 0) {
        queue_destruction();
        return;
    }
    if (((TObjEneRecobox *)p)->is_below_child_limit(target_id) != 0) {
        orbit_since_strike = 0;
        transition_enemy_state(2);
        return;
    }
    n = collect_enemy_target_candidates(this, hits, 10000.0f);
    for (i = 0; i < n; i++) {
        id = hits[i].id;
        if (id != target_id && ((TObjEneRecobox *)p)->is_below_child_limit(id) != 0) {
            orbit_since_strike = 0;
            enemy_set_target_id(this, id);
            transition_enemy_state(2);
            return;
        }
    }
    transition_enemy_state(4);
    attacking = 0;
}

s32 TObjEneRecon::is_in_strike_range() {
    f32 facing;
    if ((destination_distance < (5.0f + TObjEneRecon__attack_params->get_attack_range())) && (fabs_float((f32) (hover_height - destination.y)) < 1.0f)) {
        facing = vec3_dot(&velocity, &destination_direction);
        if (facing >= cos_table_lookup(attack_params->get_attack_angle())) {
            return 1;
        }
    }
    return 0;
}

f32 TObjEneRecon::approach_value(f32 current, f32 target) {
    f32 diff;
    f32 step;

    diff = target - current;
    if (fabs_float(diff) < 0.2f) {
        return target;
    }
    step = 0.1f;
    step = diff * step;
    if (step > 1.5f) {
        step = 1.5f;
    } else if (step < -1.5f) {
        step = -1.5f;
    }
    return current + step;
}

}


void TObjEneRecon::update_body_colliders() {
    f32 d;
    TObjChara *t = current_target;
    if (t != NULL && this->mode == 2) {
        position.y = t->position.y;
    } else {
        Vec v = position;
        v.y += hover_height;
        if (project_actor_to_ground(this, &v, &ground_normal) != 0) {
            position.y = v.y;
        }
    }
    d = hover_height - position.y;
    if (d >= 30.0f) {
        this->set_colliders_contact_high();
    } else {
        this->set_colliders_contact_low();
    }
    bodies->offset.y = d;
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
    f32 height = hover_height;
    f32 ground = position.y;
    if (height - ground < 5.0f) {
        hover_height = 5.0f + ground;
    }
    body_center.y = hover_height;
}
#pragma pop

extern "C" {

void TObjEneRecon::update_position_from_offsets() {
    body_center.x = position.x;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}

}


extern "C" {


void TObjEneRecon::update_collide_flag() {
    if (TObjEneEpsilon__sub_800B92F8(this, ((ReconMoveParams *)movementParameters)->turn_speed, TObjEneRecon__behavior_params->collide_distance) != 0) {
        recon_flags |= 2;
        return;
    }
    recon_flags &= ~2;
}

void TObjEneRecon::set_flag2(f32 x, f32 z, f32 r) {
    if (this->move_with_wall_slide_commit(x, z, r) != 0U) {
        recon_flags |= 2;
        return;
    }
    recon_flags &= ~2;
}

void TObjEneRecon::update_flag_0x444() {
    if (update_ground_contact() != 0U) {
        recon_flags |= 2;
        return;
    }
    recon_flags &= ~2;
}

#pragma push
#pragma fp_contract on
void TObjEneRecon::set_orbit_destination(s32 angle) {
    enemy_copy_target_destination();
    destination.x = rotate_rad * sin_table_lookup(angle) + destination.x;
    destination.y = offset_max;
    destination.z = rotate_rad * cos_table_lookup(angle) + destination.z;
}
#pragma pop

void TObjEneRecon::advance_field398() {
    enemy_copy_target_destination();
    destination.y = destination.y + strike_height;
}
void TObjEneRecon::sync_height() {
    enemy_copy_target_destination();
    destination.y = offset_max;
}
void TObjEneRecon::run_miss_reaction() {  }
void TObjEneRecon::run_hit_reaction() { if (this->mode != 6) { transition_enemy_state(6); } }

void TObjEneRecon::run_death_reaction() {
    if (mode != 7 && mode != 8) {
        transition_enemy_state(7);
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
f32 TObjEneRecobox::get_recon_offset_max() { return recon_offset_max; }
f32 TObjEneRecobox::get_recon_rotate_rad() { return recon_rotate_rad; }

extern "C" {
void TObjEneRecon::load_resources() {
  TObjEneRecon__recobox_static_instance = TObjEneRecobox::get_bml_resource();
  boss3_volopt_instance = new TBreakUpMdlData(TObjEneRecon__recobox_static_instance->models->model);
  recon_intro_stage = 0;
  recon_model_matrix_ptr = 0;
  TObjEneRecon__base_params = TLobby::register_boss(0x42);
  TObjEneRecon__attack_params = TLobby::dispatch_shared_handler_b(0x42);
  TObjEneRecon__resistance_params = TLobby::register_object(0x42);
  TObjEneRecon__behavior_params = (ReconParams *)TLobby::dispatch_shared_handler_a(0x42);
  TObjEneReconBomb::load_resources();
  NpcAnimationBinding binding = recon_anim_binding;
  binding.motions = TObjEneRecon__recobox_static_instance->motions;
  TObjNpcEnemy::register_animated_chunk(0xC, TObjEneRecon__recobox_static_instance->models[0].model, TObjEneRecon__recobox_static_instance->models[0].texlist, &binding, TObjEneRecon__collision_body_template.radius, 15.0f);
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
    owner_id = owner->get_entity_id();
    init_common_from(owner);
    entity_id = id;
    set_index = index;
    VecCopy(&position, pos);
    VecCopy(&owner_position, &owner->position);
    VecCopy(&spawn_direction, dir);
    init_state();
    offset_max += owner->get_recon_offset_max();
    rotate_rad += owner->get_recon_rotate_rad();
    set_entry = 0;
}

extern "C" {


#pragma push
#pragma fp_contract on
void TObjEneRecon::init_state() {
    init_position_vectors();
    model = TObjEneRecon__recobox_static_instance->models->model;
    texlist = TObjEneRecon__recobox_static_instance->models->texlist;
    init_model(&TObjEneRecon__collision_body_template, 1);
    set_action_table(TObjEneRecon__animation_entries);
    set_motion_list(TObjEneRecon__recobox_static_instance->motions);
    this->requested_action = 0;
    set_animation((this->requested_action));
    set_requested_action((int) (this->requested_action));
    reset_hp(TObjEneRecon__base_params, TObjEneRecon__attack_params, TObjEneRecon__resistance_params);
    set_state_flag_4();
    movementParameters = (void *) TObjEneRecon__ai_parameters;
    initialize_enemy_state(0x44);
    wall_reach = 5.0f;
    enemy_init_acquire_period(0xA);
    enemy_init_validate_period(0xA);
    set_active();
    actorFlags = (actorFlags | 0x01000000);
    recon_flags = 2;
    hover_height = (position.y);
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    pad_458 = 0.0f;
    pad_45C = 0;
    offset_max = (f32) ((2.0f * calc_elapsed_scaled()) + 45.0f);
    strike_height = (f32) ((2.0f * calc_elapsed_scaled()) + 15.0f);
    rotate_rad = (f32) ((5.0f * calc_elapsed_scaled()) + 50.0f);
    attacking = 0;
    emitter = NULL;
    emitter_side = 0;
    floor_flags = 0;
    VecCopy(&floor_point, &position);
    fade.reset_color();
    orbit_since_strike = 0;
    orbit_since_bomb = 0;
    VecCopy(&root_node_position, &position);
    state_step = 0;
    state_timer = 0;
    hit_window = 0;
    pad_3CC = 0;
    orbit_angle = 0;
    orbit_step = 0;
    bob_phase = 0;
    pad_3DC = 0;
    rise_speed = 0.0f;
    move_speed = 0.0f;
    pad_3E8[0] = 0.0f;
    pad_3E8[1] = 0.0f;
    pad_3E8[2] = 0.0f;
    pad_3E8[3] = 0.0f;
    pad_3E8[4] = 0.0f;
    pad_3E8[5] = 0.0f;
    pad_3E8[6] = 0.0f;
    pad_3E8[7] = 0.0f;
    pad_3E8[8] = 0.0f;
    this->mode = 0;
    this->dispatch_action(this->mode, 4);
}

}
#pragma pop
TObjEneRecon::~TObjEneRecon() {
    this->send_entity_set_flags();
    free_collision_body_parts(this);
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}


void TObjEneRecon::run_task() {
    f32 dz;
    f32 dx;
    f32 side;
    s16 m;
    TObjEneRecobox *owner;
    TParticleCtrl *e;
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    owner = (TObjEneRecobox *)find_entity_by_id(owner_id);
    if (owner == NULL || owner->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
        return;
    }
    m = mode;
    if (m != 8 && m != 7 && owner->is_anim_6() == 1) {
        hit_flags = (s32)(hit_flags | 4);
        ((TObjPlayer *)this)->set_hp_clamped(0);
        set_actor_flags(0xA00U);
        sync_enemy_state(0);
    }
    if (update_status_effects() != 4) {
        update_action_state();
        e = emitter;
        if (e == NULL) {
            emitter = create_particle_emitter(&body_center, 0x217);
            if (emitter != NULL) {
                emitter->enable();
            }
        } else {
            m = mode;
            if (m == 8 || m == 7) {
                e->enable();
            } else {
                if (emitter_side == 0) {
                    side = 3.0f;
                    emitter_side = 1;
                } else {
                    side = -3.0f;
                    emitter_side = 0;
                }
                if (TObjEneDD::check_v2_mode() != 0) {
                    side *= 3.0f;
                }
                dx = side * cos_table_lookup(rotation_y);
                dz = side * -sin_table_lookup(rotation_y);
                emitter->position.x = body_center.x + dx;
                emitter->position.y = -1.5f + body_center.y;
                emitter->position.z = body_center.z + dz;
            }
        }
    } else {
        e = emitter;
        if (e != NULL) {
            e->enable();
        }
    }
    update_position_from_offsets();
    submit_default_cursor_candidate();
    render_minimap_dot();
    update_ground_probe();
}

void TObjEneRecon::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        state_launch(reason);
        return;
    case 1:
        state_search(reason);
        return;
    case 2:
        state_attack(reason);
        return;
    case 3:
        state_bomb_attack(reason);
        return;
    case 4:
        state_orbit(reason);
        return;
    case 6:
        state_damage(reason);
        return;
    case 7:
        state_death(reason);
        return;
    case 5:
        state_fade_out(reason);
        return;
    case 8:
        handle_message(reason);
    default:
        return;
    }
}


