#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/math/AngleUnits.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeEff.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/BmlResource.h"

struct NJS_OBJECT;
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/math/FloatRounding.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gibon/TObjEneBm5GibonU.h"
#include "pso/enemy/gyaranzo/TObjEneGyaranzo.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/technique/TTecFoie.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/technique/TTecMegid.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/render/TUnk_80494938.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/math/MatrixVector.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/render/render_util.h"
#include "pso/render/BlobShadow.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/enemy/wolf/TObjEneBm5Wolf.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/effect/GroundContactSound.h"
#include "pso/map/CsnQuery.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjBase.h"

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as GeeAnimationBinding).

extern "C" {
BmlResource * TObjEneBm5GibonU__model_archive;
#pragma push
TObjEneBm5GibonUMovementParameters TObjEneBm5GibonU__movement_parameters = {
    225.0f, 0.0f, 0x600, { 0, 0, 0, 0 },
};
CollisionBody gibon_collision_body_templates[4] = {
    { { 0.0f, 10.0f, 0.0f }, 8.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 16.0f, 0.0f }, 12.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *bm_ene_bm5_gibon_u_model_names[3] = {
    "gibon.nj", "gibonb_gibon.nj", NULL,
};
const char *gibon_u_animation_name_table[10] = {
    "attack_gibon.njm", "back_gibon.njm", "damage_gibon.njm", "dead_gibon.njm", "fire_gibon.njm",
    "hoe_gibon.njm", "run_gibon.njm", "wait_gibon.njm", "walk_gibon.njm", NULL,
};
BmlResourceDescriptor bm_ene_bm5_gibon_u_resource_descriptor = {
    "bm_ene_bm5_gibon_u.bml", bm_ene_bm5_gibon_u_model_names, gibon_u_animation_name_table, 2, 9,
};
const char *bm_ene_bm5_gibon_u_low_model_names[3] = {
    "lo_gibon.nj", "lo_gibonb_gibon.nj", NULL,
};
const char *gibon_u_animation_file_table[10] = {
    "attack_gibon.njm", "back_gibon.njm", "damage_gibon.njm", "dead_gibon.njm", "fire_gibon.njm",
    "hoe_gibon.njm", "run_gibon.njm", "wait_gibon.njm", "walk_gibon.njm", NULL,
};
BmlResourceDescriptor bm_ene_bm5_gibon_u_low_resource_descriptor = {
    "bm_ene_bm5_gibon_u_low.bml", bm_ene_bm5_gibon_u_low_model_names, gibon_u_animation_file_table, 2, 9,
};
TObjMotionAction gibon_u_action_table[17] = {
    { MOTION_MODE_LOOP, 0, 7, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 8, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 6, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 6, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 7, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 5, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 2, 1.0f, 0 },
    { MOTION_MODE_CHAIN, 8, 2, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 5, 1.0f, 0 },
    { MOTION_MODE_ONCE, 9, 5, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 0, 1.2f, 0 },
    { MOTION_MODE_ONCE, 0, 3, 1.3f, 0 },
    { MOTION_MODE_ONCE, 0, 1, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 4, 1.0f, 0 },
    { MOTION_MODE_CHAIN, 9, 7, 0.5f, 0 },
    { MOTION_MODE_ONCE, 0, 0, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 6, 1.0f, 0 },
};
const char *TObjEneBm5GibonU__class_name = "TObjEneBm5GibonU";
const NpcAnimationBinding TObjEneBm5GibonU__spawn_params = { NULL, gibon_u_action_table, 0, 1, 17 };
__declspec(section ".data") player_stats *TObjEneBm5GibonU__stat_params[2];
__declspec(section ".data") AttackParams *gibon_stat_handle_a_table[2];
__declspec(section ".data") ActorParamBlock *gibon_stat_handle_b_table[2];
__declspec(section ".data") u8 *gibon_param_table[2];
__declspec(section ".data") f32 lbl_80500E98[3];
__declspec(section ".data") u32 lbl_80500EA4[3];
__declspec(section ".data") u32 TObjEneBm5GibonU__pack_member_list[5];
__declspec(section ".data") u32 TObjEneBm5GibonU__instance_list[3];
}

#pragma pop
#pragma push

extern "C" {
s32 TObjEneBm5GibonU__render_node_index;
s32 TObjEneBm5GibonU__render_joint_y_rotation;
}
extern "C" {

s32 TObjEneBm5GibonU::get_clamped_level() {
    player_stats *p = stat_block;
    s32 v = 0;
    if (p != 0) {
        v = p->level;
        if (v < 0) {
            v = 0;
        } else if (game_difficulty_selection == 3) {
            if (v > 0x1d) {
                v = 0x1d;
            }
        } else if (v > 0xe) {
            v = 0xe;
        }
    }
    return v;
}

s32 TObjEneBm5GibonU::check_hit_sphere(int angle, f32 scale) {
    CollisionBody *body;
    u8 hit;
    s32 saved_rotation;
    u32 saved_flags;
    scale *= 0.5f;
    body = bodies;
    saved_rotation = rotation_y;
    saved_flags = body->flags;
    body->offset.x = 0.0f;
    body->offset.z = scale;
    body->radius = scale;
    body->half_width = 8.0f;
    body->shape = 1;
    body->flags = 0x9D01;
    rotation_y = angle;
    check_collisions();
    update_enemy_collision_flags();
    hit = (body->flags & 0x380000) != 0;
    if (is_leader == 1) {
        copy_collision_body(body, &gibon_collision_body_templates[1]);
    } else {
        copy_collision_body(body, &gibon_collision_body_templates[0]);
    }
    body->flags = saved_flags;
    rotation_y = saved_rotation;
    return hit;
}

void TObjEneBm5GibonU::get_attack_state(void *pos) { spawn_landing_effect((Vec *)pos); }

void TObjEneBm5GibonU::spawn_landing_effect(Vec *pos) {
    Vec v;
    CsnHit *hit;
    TParticleCtrl *p;
    VecCopy(&v, pos);
    v.y += 15.0f;
    hit = csnVectorUnder(&v, ground_candidates.groups, 5);
    if (hit != NULL && (hit->hit_mask & 4)) {
        p = spawn_particle_effect(&hit->contact[2].point, 0x49);
        if (p != NULL) {
            attach_particle_model(p, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            if (is_leader == 1) {
                p->set_scale(1.5f, 1.0f);
            }
        }
        p = spawn_particle_effect(&hit->contact[2].point, 0xA4);
        if (p != NULL && is_leader == 1) {
            p->set_scale(1.5f, 1.0f);
        }
        play_ground_landing_sound(&position);
        return;
    }
    play_sound_effect(remap_sound_for_area(0x3BC21), &position, 0, 0);
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::play_jump_footsteps() {
    if ((this->is_passing_frame(7.0f) != 0) || (this->is_passing_frame(28.0f) != 0)) {
        this->spawn_landing_effect(&this->position);
    }
}
#pragma pop

void TObjEneBm5GibonU::play_run_footstep() {
    if (this->is_passing_frame(10.0f) != 0) {
        this->get_attack_state(&this->position);
    }
}

void TObjEneBm5GibonU::play_walk_footsteps() {
    if ((this->is_passing_frame(12.0f) != 0) || (this->is_passing_frame(28.0f) != 0)) {
        this->get_attack_state(&this->position);
    }
}

#pragma pool_data off
void TObjEneBm5GibonU::render_debug() {
    Vec v;
    s32 idx;
    f32 frame;
    AnimationMotion *motion;
    TObjEneBm5GibonU *other;
    if (this->get_target_info() != 0) {
        debug_printf_at(pack_debug_text_position(0, 2), "GROUP:%2d", group_id);
        if (appear_mode == 1) {
            debug_printf_at(pack_debug_text_position(0, 3), "SPOT APPEAR");
        } else {
            debug_printf_at(pack_debug_text_position(0, 3), "JUMP APPEAR");
        }
        if (is_leader != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), "L/M:LEADER");
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), "L/M:MEMBER");
        }
        debug_printf_at(pack_debug_text_position(0, 4), "BACKJUMP(+0.4f)");
        debug_printf_at(pack_debug_text_position(0, 5), "RUN_FOIE(+0.3f)");
        debug_printf_at(pack_debug_text_position(0, 6), "BACK_FOIE(+0.3f)");
    }
    if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        draw_ground_shadow(0, 0);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        if (is_leader == 1) {
            scale_matrix(0, 1.5f, 1.5f, 1.5f);
        } else {
            scale_matrix(0, 2.0f, 2.0f, 2.0f);
        }
        idx = (s32)parameters[3];
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x11) {
            idx = 0x10;
        }
        motion = motion_list[action_table[idx].motion].motion;
        frame = parameters[4];
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (motion->frameCount - 1)) {
            frame = (f32)motion->frameCount;
        }
        translate_matrix(0, 0.0f, 0.0f, -10.0f);
        TObjPlayer::toggle_particle_effect();
        set_motion_packed_rotation();
        draw_model_motion(model, motion, frame);
        clear_motion_packed_rotation();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    other = TObjEneBm5GibonU::find_pack_leader(group_id);
    if (other != 0) {
        debug_draw_line(&body_center, &other->body_center, 0xFFC0C0C0, 0xFF6060FF);
        return;
    }
    VecCopy(&v, &body_center);
    v.y += 50.0f;
    debug_draw_line(&body_center, &v, 0xFFC0C0C0, 0xFF6060FF);
}
#pragma pool_data reset

void TObjEneBm5GibonU::run_demo_task() {
    s32 was_leader;

    if (this->get_target_info() != 0) {
        was_leader = is_leader;
        select_subtype();
        if (was_leader != is_leader) {
            if (was_leader != 0) {
                remove_from_instance_list();
            } else {
                add_to_instance_list();
            }
        }
        update_center_position();
    }
}

void TObjEneBm5GibonU::render() {
    s32 rot[3];
    s32 cam;
    s32 vis;
    s32 fade;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_debug();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (!(status_flags & 2) && this->mode != 0x12) {
        fade = 0;
        if (is_leader != 0) {
            camera_fades[cam].update();
            fade = camera_fades[cam].updateFromCamera(&body_center.x);
        }
        if (TObjEneDD::is_main_phase_15() != 0) {
            vis = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 20.0f);
        } else if (update_object_view_visibility(400.0f, 20.0f) != 0) {
            vis = 1;
        } else {
            vis = 0;
        }
        if (vis != 0) {
            if (this->mode != 0x11) {
                direction_to_rotation_xz((u8 *)&ground_normal, &rot[0], &rot[2]);
                push_matrix();
                post_translate_matrix(&position.x);
                translate_matrix(0, 0.0f, 0.3f, 0.0f);
                rotate_matrix_z(0, rot[2]);
                rotate_matrix_x(0, rot[0]);
                rotate_matrix_y(0, this->rotation_y);
                translate_matrix(0, 0.0f, 0.0f, -3.0f);
                scale_matrix(0, 2.0f, 1.0f, 3.0f);
                rotate_matrix_x(0, -0x4000);
                draw_blob_shadow(0);
                pop_matrix();
            }
            this->update_secondary_light();
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
            push_matrix();
            if (this->mode == 1 || this->mode == 2) {
                appear_fade.set_flags_and_apply_damage_color();
            } else if (fade != 0) {
                camera_fades[cam].set_flags_and_apply_damage_color();
            }
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, this->rotation_y);
            translate_matrix(0, 0.0f, 0.0f, -10.0f);
            if (is_leader == 1) {
                scale_matrix(0, 1.5f, 1.5f, 1.5f);
            } else {
                scale_matrix(0, 2.0f, 2.0f, 2.0f);
            }
            TObjEneBm5GibonU__render_node_index = 0;
            TObjEneBm5GibonU__render_joint_y_rotation = -(turn_offset / 2);
            set_chunk_model_node_callback(TObjEneBm5GibonU::advance_anim_frame);
            TObjEneDD::clear_global_flag_400();
            TObjPlayer::toggle_particle_effect();
            if (fade != 0) {
                if (defer_render() == 0) {
                    if (vis == 1) {
                        this->draw();
                    } else {
                        this->draw_motion_model();
                    }
                }
            } else if (vis == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            set_chunk_model_node_callback(NULL);
            if (this->mode == 1 || this->mode == 2) {
                appear_fade.clear_flag_and_notify();
            } else if (fade != 0) {
                camera_fades[cam].clear_flag_and_notify();
            }
            pop_matrix();
            this->update_primary_light();
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneBm5GibonU::advance_anim_frame(NJS_OBJECT *) {
    if (((s32) TObjEneBm5GibonU__render_node_index >= 0x30) && ((s32) TObjEneBm5GibonU__render_node_index < 0x32)) {
        rotate_matrix_y(0, TObjEneBm5GibonU__render_joint_y_rotation);
    }
    TObjEneBm5GibonU__render_node_index += 1;
}

void TObjEneBm5GibonU::handle_message(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction();
        return;
    }
}

void TObjEneBm5GibonU::state_cast_technique(s32 msg) {
    Vec v;
    Vec p;
    s32 ang[3];
    s32 r;
    switch (msg) {
    case 4:
        requested_action = 0;
        set_field_378(14);
        clear_intangible();
        status_flags &= ~2;
        enemy_copy_target_destination();
        substate = 0;
        break;
    case 3:
        if (substate == 2) {
            transition_enemy_state(8);
        }
        break;
    case 0:
        update_prev_position();
        if (substate != 1) {
            if (current_target == 0) {
                transition_enemy_state(8);
            } else {
                if (select_enemy_destination(this, destination, 1) != 0) {
                    copy_position_if_valid(this, body_center);
                    r = enemy_turn_toward_dest(((TObjEneBm5GibonUMovementParameters *)movementParameters)->turn);
                    enemy_set_heading_velocity(((TObjEneBm5GibonUMovementParameters *)movementParameters)->speed, this, rotation_y);
                    move_with_wall_slide(this);
                } else {
                    VecCopy(&v, &destination);
                    subtract_vector(&v, &body_center);
                    r = turn_toward_direction(((TObjEneBm5GibonUMovementParameters *)movementParameters)->turn, &v);
                }
                if (r < 0x100) {
                    substate = 1;
                    requested_action = 13;
                } else {
                    requested_action = 1;
                }
            }
        } else {
            advance_animation();
            if (get_flag_b4() != 0) {
                substate = 2;
            }
            if (is_passing_frame(15.0f) != 0) {
                p.x = 0.0f;
                p.y = 15.0f;
                p.z = 12.0f;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, rotation_y);
                rotate_vector_by_matrix(0, &p, &p);
                pop_matrices(1);
                vec3_add_to(&p, &body_center);
                if (current_target != 0) {
                    VecCopy(&v, &destination);
                    subtract_vector(&v, &body_center);
                    r = turn_toward_direction(((TObjEneBm5GibonUMovementParameters *)movementParameters)->turn, &v);
                } else {
                    r = attack_params->get_attack_angle();
                }
                if (game_difficulty_selection == 3) {
                    switch (technique_type) {
                    case 1:
                        if (r < attack_params->get_attack_angle() / 2 && current_target != 0) {
                            TTecMegid::create((saddr)this, (saddr)&p, (saddr)&destination, (s32)(get_clamped_level()));
                        } else {
                            TTecMegid::create_ex((saddr)this, (saddr)&p, rotation_y, (s32)(get_clamped_level()));
                        }
                        play_sound_effect(0x4002A60B, &p, 0, 0);
                        break;
                    default:
                        if (r < attack_params->get_attack_angle() / 2 && current_target != 0) {
                            clear_target_cursor_list(&targets);
                            targets.count = 1;
                            targets.records[0].id = current_target->get_entity_id();
                            targets.records[0].flag = 0;
                            TTecGiZonde::create(this, &p, &targets, get_clamped_level());
                        } else {
                            void *e;
                            spawn_particle_effect(&p, 0xB9);
                            spawn_particle_effect(&p, 0xBA);
                            v.x = 0.0f;
                            v.y = 0.0f;
                            v.z = 1.0f;
                            push_matrix_from(identity_matrix);
                            rotate_matrix_y(0, rotation_y);
                            rotate_vector_by_matrix(0, &v, &v);
                            pop_matrix();
                            new TTecZondeEff(tl_07, &p, &v, 0x14000000, 20, (f32)(attack_params->get_attack_range()), 1.8f);
                        }
                        play_sound_effect(0x4002A408, &p, 0, 0);
                        break;
                    }
                } else {
                    switch (technique_type) {
                    case 1:
                        TTecGiBarta::create_ex(this, &p, rotation_y, (get_clamped_level()));
                        break;
                    default:
                        if (r < attack_params->get_attack_angle() / 2 && current_target != 0) {
                            TTecFoie::create_ex(this, &p, &current_target->body_center, get_clamped_level());
                        } else {
                            TTecFoie::create(this, &p, rotation_y, get_clamped_level());
                        }
                        break;
                    }
                    v.x = 0.0f;
                    v.y = 0.0f;
                    v.z = 0.0f;
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, rotation_y);
                    rotate_vector_by_matrix(0, &v, &v);
                    pop_matrices(1);
                    if (technique_type != 1) {
                        ang[0] = (s32)(RADIANS_TO_ANGLE * atan2_float(v.z, newton_sqrtf(v.x * v.x + v.y * v.y)));
                        ang[1] = 0;
                        ang[2] = -(s32)(RADIANS_TO_ANGLE * atan2_float(v.x, v.y));
                        spawn_directional_particle(&p, ang, 0xCC);
                    }
                }
            }
        }
        break;
    case 5:
        break;
    }
    update_collisions();
}

void TObjEneBm5GibonU::backjump_state(s32 msg) {
    s32 offs[3];
    switch (msg) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(0xE);
        this->clear_intangible();
        this->status_flags &= ~2;
        this->substate = 0;
        this->base_heading = 0;
        offs[0] = (s32)(3.0f * this->random_ratio()) - 1;
        offs[1] = (s32)(2.0f * this->random_ratio()) - 1;
        if (offs[1] <= offs[0]) {
            offs[1]++;
        }
        this->destination_direction.x = 0.0f;
        this->destination_direction.y = 0.0f;
        this->destination_direction.z = 0.0f;
        offs[2] = -(offs[0] + offs[1]);
        this->destination_distance = 0.0f;
        if (this->update_target() != 0) {
            s32 d;
            int ang;
            s32 i;
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->target_heading = (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
            for (i = 0; i < 3; i++) {
                d = offs[i] * 0x1FFF;
                ang = this->target_heading + 0x10000 + d - 0x8000;
                if (this->check_hit_sphere(ang, 160.0f) == 0) {
                    f32 dx = 2.0f * (60.0f * sin_table_lookup(ang));
                    f32 dz = 2.0f * (60.0f * cos_table_lookup(ang));
                    if (((TObjEneDD *)this)->enemy_probe_wall_ahead(dx, dz, 1.0f) == NULL) {
                        Vec v;
                        VecCopy(&v, (const Vec *)&this->body_center);
                        v.x += dx;
                        v.z += dz;
                        if (csnVectorUnder(&v, this->ground_candidates.groups, 0x15) != 0) {
                            this->destination_direction.x = sin_table_lookup(ang);
                            this->destination_direction.y = 0.0f;
                            this->destination_direction.z = cos_table_lookup(ang);
                            this->destination_distance = 60.0f;
                            this->target_heading += d / 2;
                            break;
                        }
                    }
                }
            }
        }
        this->current_speed = this->desired_speed = this->destination_distance / 33.0f;
        this->substate = 0;
        this->set_invulnerable();
        break;
    case 3:
        if (this->substate == 1) {
            if (this->random_ratio() < this->back_foie_chance) {
                this->transition_enemy_state(0x14);
            } else {
                this->transition_enemy_state(8);
            }
        }
        break;
    case 0:
        switch (this->substate) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->substate = 1;
            }
            play_jump_footsteps();
            if (this->is_passing_frame(8.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x3B22A), &this->position, 0, 0);
            }
            if (this->is_passing_frame(33.0f) != 0) {
                this->clear_invulnerable();
                TObjPlayer::init_all_slots();
                this->check_object_collisions();
                if (this->attack_collider->bodies->flags & 0x80000) {
                    s32 i;
                    for (i = 0; i < 16; i++) {
                        TObjPlayer *p = (TObjPlayer *)TObjPlayer::get_battle_param(i);
                        if (p == 0) {
                            break;
                        }
                        if (obj_is_hit_receivable(p) != 0 && p->select_melee_contact_body(this, 1.0f) != 0) {
                            p->apply_knockback_from_attacker((u8 *)this, 1.0f);
                            p->receive_physical_attack(this, 1.0f);
                        }
                    }
                }
            }
            this->approach_target(0.1f);
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_heading, 0x1000);
            this->rotation_y = (s16)this->rotation_y;
            this->turn_toward_angle(this->rotation_y);
            if (this->frame <= 33.0f) {
                this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->current_speed);
            }
            break;
        }
        this->check_collisions();
        this->update_enemy_collision_flags();
        break;
    case 5:
        this->play_sound_variant();
        this->clear_invulnerable();
        break;
    }
}

void TObjEneBm5GibonU::update_dying_state(s32 msg) {
    Vec spot;
    Vec dir;
    f32 k;
    TObjEneBm5GibonUNode *n;
    TObjEneBm5GibonU *o;
    switch (msg) {
    case 4:
        this->clear_intangible();
        this->refresh_and_send_entity_flags();
        play_sound_effect(this->remap_sound_for_area(0x3A826), &this->position, 0, 0);
        this->requested_action = 0xB;
        TBoss8Dragon__sub_800BB7D4(this, 0xF1);
        this->substate = 0;
        this->stopping_distance = this->calc_anim_speed(this->action_table[7].speed);
        this->sink_depth = 0.0f;
        this->wall_reach = 0.0f;
        if (this->is_leader != 0) {
            k = 50.0f;
            for (n = ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__pack_member_list)->head; n != NULL; n = n->next) {
                o = n->get_owner();
                if (o != NULL && o->group_id == this->group_id) {
                    o->schedule_pack_reaction((s32)(k * this->random_ratio()) + 0x14, this->attacker_id);
                }
            }
        }
        this->set_active();
        return;
    case 3:
        if (this->substate == 2) {
            this->transition_enemy_state(0x12);
        }
    case 1:
        return;
    case 0:
        switch (this->substate) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->substate = 1;
                spot.x = 0.0f;
                spot.y = 0.0f;
                spot.z = -10.0f;
                rotate_xz_pair_by_angle(&spot.x, &spot.z, this->rotation_y);
                vec3_add_to(&spot, &this->position);
                if (this->is_leader == 1) {
                    spawn_dead_spot_scale15(&spot, 0x32);
                } else {
                    TObjPlayer::spawn_dead_spot_type2(&spot, 0x32);
                }
                spawn_effect_at_ground(&spot, 0x46);
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_heading, 0x300);
            this->rotation_y = (s16)this->rotation_y;
            if (this->wall_reach < 28.0f) {
                this->wall_reach += this->stopping_distance;
            }
            VecCopy(&dir, (const Vec *)&this->velocity.x);
            {
                f32 v = normalize_vector_xz(&dir);
                this->move_clamped_on_ground(dir.x, dir.z, v);
            }
            if (this->is_passing_frame(26.0f) != 0) {
                spawn_recoil_dust(&dir);
            }
            this->velocity.x *= 0.8f;
            this->velocity.z *= 0.8f;
            this->turn_toward_angle(this->rotation_y);
            this->update_body_colliders();
            break;
        case 1:
            this->position.y -= 0.1f;
            this->sink_depth += 0.1f;
            if (this->sink_depth > 20.0f) {
                this->substate = 2;
            }
            break;
        }
        break;
    case 5:
        this->clear_field_388();
        return;
    }
}

void TObjEneBm5GibonU::hurt_state(s32 msg) {
    Vec dir;
    switch (msg) {
    case 4:
        this->clear_intangible();
        TBoss8Dragon__sub_800BB7D4(this, 0xF1);
        this->state_timer = 0;
        this->target_heading = 0;
        this->requested_action = 6;
        this->substate = 0;
        if (this->referenceHp - this->hp < 0x14) {
            play_sound_effect(this->remap_sound_for_area(0x3A824), &this->position, 0, 0);
        }
        this->set_active();
        break;
    case 3:
        if (this->motion_flags & 0x10) {
            switch (this->next_mode) {
            case 12:
                this->transition_enemy_state(0xE);
                break;
            case 3:
                this->transition_enemy_state(8);
                break;
            default:
                this->transition_enemy_state(this->next_mode);
                break;
            }
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&dir, (const Vec *)&this->velocity.x);
        {
            f32 v = normalize_vector_xz(&dir);
            this->move_with_wall_slide_on_ground(dir.x, dir.z, v);
        }
        if (this->substate == 0) {
            this->velocity.x *= 0.5f;
            this->velocity.z *= 0.5f;
        } else {
            this->velocity.x *= 0.9f;
            this->velocity.z *= 0.9f;
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_heading, 0x300);
            this->rotation_y = (s16) this->rotation_y;
            if (this->is_passing_frame(26.0f) != 0) {
                spawn_recoil_dust(&dir);
            }
        }
        this->check_collisions();
        this->update_enemy_collision_flags();
        break;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

void TObjEneBm5GibonU::action(s32 msg) {

    switch (msg) {
    case 4:
        this->clear_intangible();
        this->set_field_378(8);
        this->requested_action = 9;
        this->substate = 0;
        TObjEneBm5GibonU::find_pack_leader(this->group_id);
        return;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(8);
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        this->turn_toward_angle(this->rotation_y);
        if (this->is_passing_frame(10.0f) != 0) {
            play_sound_effect(this->remap_sound_for_area(0x3AA22), &this->position, 0, 0);
        }
        this->substate++;
        if (this->substate == 0x1E) {
            this->damage_linked_entity_type10();
        } else if (this->substate == 0x28) {
            this->damage_linked_entity();
        }
        this->check_collisions();
        this->update_enemy_collision_flags();
        break;
    }
}

void TObjEneBm5GibonU::repositioning_state(s32 msg) {
    Vec v;
    f32 dx;
    f32 dz;
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xE);
        this->clear_intangible();
        this->substate = 0;
        this->target_heading = 0;
        this->state_timer = 0;
        break;
    case 3:
        if (this->substate == 2) {
            if (this->current_target != NULL) {
                this->transition_enemy_state(0xB);
            } else {
                this->transition_enemy_state(8);
            }
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (this->substate) {
        case 0:
            this->target_heading = ((this->state_timer >> 1) << 0xC) + 0x1800;
            if (this->state_timer & 1) {
                this->target_heading = -this->target_heading;
            }
            if (this->is_active() == 0) {
                this->target_heading = -this->target_heading;
            }
            this->target_heading += this->rotation_y;
            (this->state_timer)++;
            if (this->state_timer > 8) {
                this->substate = 2;
            }
            dx = 16.0f * sin_table_lookup(this->target_heading);
            dz = 16.0f * cos_table_lookup(this->target_heading);
            this->attack_collider->position.x = this->position.x + dx;
            this->attack_collider->position.y = this->position.y;
            this->attack_collider->position.z = this->position.z + dz;
            this->attack_collider->update_collisions();
            if (!(this->attack_collider->bodies->flags & 0x380000)) {
                dx *= 2.0f;
                dz *= 2.0f;
                if (((TObjEneDD *)this)->enemy_probe_wall_ahead(dx, dz, 1.0f) == NULL) {
                    VecCopy(&v, &this->body_center);
                    v.x += dx;
                    v.z += dz;
                    if (csnVectorUnder(&v, this->ground_candidates.groups, 0x15) != NULL) {
                        this->substate = 1;
                        this->requested_action = 0x10;
                        this->destination_direction.x = sin_table_lookup(this->target_heading);
                        this->destination_direction.y = 0.0f;
                        this->destination_direction.z = cos_table_lookup(this->target_heading);
                    }
                }
            }
            break;
        case 1:
            if (this->get_flag_b4() != 0) {
                this->update_target();
                this->substate = 2;
            }
            play_run_footstep();
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, 1.8f);
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_heading, 0xF00);
            this->turn_toward_angle(this->target_heading);
            this->check_collisions();
            this->update_enemy_collision_flags();
            break;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::returning_state(s32 msg) {
    Vec dir;
    Vec diff;
    Vec *home = &this->work_vector;
    f32 range = this->stopping_distance;
    u8 *tgt;
    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->desired_speed = 1.6f;
        this->substate = 0;
        VecCopy(home, &this->position);
        TObjBoss2Tunnel::calc_scaled_value(0x200, 1.6f);
        this->base_heading = this->rotation_y;
        if (this->enemy_has_live_target() != 0) {
            dir.x = sin_table_lookup(this->rotation_y);
            dir.z = cos_table_lookup(this->rotation_y);
            tgt = (u8 *)this->current_target;
            diff.x = ((TObjEneBm5GibonU *)tgt)->position.x - this->position.x;
            diff.z = ((TObjEneBm5GibonU *)tgt)->position.z - this->position.z;
            if (is_vec_xz_cross_negative(&dir, &diff) != 0) {
                this->target_heading = 0x5000;
            } else {
                this->target_heading = -0x5000;
            }
        } else if (this->random_ratio() < 0.5f) {
            this->target_heading = 0x5000;
        } else {
            this->target_heading = -0x5000;
        }
        this->target_heading += this->base_heading;
        return;
    case 3:
        if (this->current_target == NULL || this->substate > 0x96) {
            this->transition_enemy_state(8);
            return;
        }
        if (this->destination_distance < range) {
            this->transition_enemy_state(0xB);
        }
    case 5:
        return;
    case 0:
        (this->substate)++;
        this->advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
            play_walk_footsteps();
            this->target_heading = approach_angle_limited(this->target_heading, this->base_heading, 0x100);
            this->destination.x = 90.0f * sin_table_lookup(this->target_heading) + home->x;
            this->destination.z = 90.0f * cos_table_lookup(this->target_heading) + home->z;
            this->update_velocity();
            this->approach_target(0.2f);
            this->play_speed = 1.05f * this->current_speed;
            enemy_turn_and_move_on_ground(this, 0x500, this->current_speed);
            this->face_target();
            this->check_collisions();
            this->update_enemy_collision_flags();
        }
        break;
    }
}
#pragma pop

void TObjEneBm5GibonU::update_lunge(s32 msg) {
    f32 speed;
    s32 flags;
    switch (msg) {
    case 4:
        this->requested_action = 0xA;
        this->set_field_378(0xE);
        this->clear_intangible();
        flags = this->status_flags & 0xFFFFFFFD;
        this->status_flags = flags;
        this->substate = 0;
        this->state_timer = 0;
        this->target_heading = calc_lunge_aim(flags);
        this->base_heading = 0;
        {
            f32 lim = 40.0f;
            if (this->destination_distance > lim) {
                this->destination_distance = lim;
            }
        }
        speed = this->destination_distance / 14.666667f;
        this->desired_speed = speed;
        this->current_speed = speed;
        this->near_target = 0;
        return;
    case 3:
        if ((s32) this->substate == 1) {
            this->transition_enemy_state(0xE);
        }
        break;
    case 5:
        break;
    case 0:
        switch (this->substate) {
        case 0:
            (this->advance_animation());
            if (this->get_flag_b4() != 0) {
                this->substate = 1;
            }
            play_jump_footsteps();
            if (this->is_passing_frame(8.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x3A828), &this->position, 0, 0);
            }
            if (this->is_passing_frame(22.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x3A529), &this->position, 0, 0);
            }
            if (this->is_passing_frame(22.0f) != 0) {
                this->near_target = 0;
                if (enemy_validate_retained_target(this) != 0) {
                    if (this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                        this->current_target->receive_physical_attack(this, 1.0f);
                        this->current_target->apply_knockback_from_attacker((u8 *)this, 7.0f);
                        this->near_target = 1;
                        if ((TObjEneDD::check_v2_mode() != 0) && (this->random_ratio() <= 0.1f)) {
                            if ((s32) this->is_leader != 0) {
                                TObjEneDD__sub_800BA378(this, this->current_target);
                            } else {
                                TObjEneDD::send_damage_message(this, this->current_target);
                            }
                        }
                    }
                }
            }
            this->approach_target(0.1f);
            this->rotation_y = approach_angle_limited((s32)(this->rotation_y), (s32)(this->target_heading), 0x1000);
            this->rotation_y = (s32) (s16) this->rotation_y;
            this->turn_toward_angle(this->rotation_y);
            if (this->frame <= 28.0f) {
                this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->current_speed);
            } else if ((s32) this->near_target == 0) {
                this->current_speed *= 0.8f;
                this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->current_speed);
            }
            break;
        }
        this->check_collisions();
        this->update_enemy_collision_flags();
        break;
    }
}
extern "C" {
#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::run_idle_state(s32 msg) {
  s32 ang;
  Vec *a = &((TObjEneBm5GibonU *)this)->work_point;
  Vec *b = &work_vector;
  f32 fx;
  f32 fz;
  switch (msg)
  {
    case 4:
      requested_action = 1;
      set_field_378(0xB);
      clear_intangible();
      desired_speed = 0.7f;
      substate = 0;
      state_timer = 0;
      random_phase = 0 & 0xFFFF;
      circle_shift_timer = 0;
      target_heading = 0;
      stopping_distance = 0.0f;
      circle_radius = 0.0f;
      a->x = 0.0f;
      a->y = 0.0f;
      a->z = 0.0f;
      b->x = 0.0f;
      b->y = 0.0f;
      b->z = 0.0f;
      set_active();
      break;

    case 3:
      if (current_target == 0)
    {
      transition_enemy_state(8);
      break;
    }
      if (substate > 0x1C2)
    {
      substate = 0;
      if (random_ratio() < 0.5f)
      {
        if (random_ratio() < backjump_chance)
        {
          transition_enemy_state(0x13);
        }
        else
        {
          transition_enemy_state(0xC);
        }
      }
    }
    else
      if (substate > 0x2D)
    {
      f32 dz = position.z - current_target->position.z;
      f32 dx = position.x - current_target->position.x;
      f32 d = (dx * dx) + (dz * dz);
      if (d >= 10000.0f)
      {
        select_attack_by_range();
      }
      else
        if (d < 900.0f)
      {
        if (random_ratio() < backjump_chance)
        {
          transition_enemy_state(0x13);
        }
        else
        {
          transition_enemy_state(0xC);
        }
      }
      else
      {
        fx = sin_table_lookup(current_target->rotation_y);
        fz = cos_table_lookup(current_target->rotation_y);
        fz = (fx * b->x) + (fz * b->z);
        if (fz < cos_table_lookup(0x6AAA))
        {
          if (random_ratio() < backjump_chance)
          {
            transition_enemy_state(0x13);
          }
          else
          {
            transition_enemy_state(0xC);
          }
        }
      }
    }
      break;

    case 0:
      advance_animation();
      if (((TObjEneEpsilon *)this)->update_death_check() != 0)
    {
      if (random_phase == 0)
      {
        Vec fwd;
        Vec to;
        random_phase = 1;
        VecCopy(a, &current_target->position);
        stopping_distance = calc_xz_direction_to(a, b);
        circle_radius = rand_range(50.0f, 80.0f);
        fwd.x = sin_table_lookup(rotation_y);
        fwd.y = 0.0f;
        fwd.z = cos_table_lookup(rotation_y);
        to.x = current_target->position.x - position.x;
        to.y = 0.0f;
        to.z = current_target->position.z - position.z;
        if (is_vec_xz_cross_negative(&fwd, &to) != 0)
        {
          target_heading = -1;
        }
        else
        {
          target_heading = 1;
        }
      }
      substate++;
      play_walk_footsteps();
      if (circle_shift_timer > 0)
      {
        circle_shift_timer--;
        if (target_heading > 0)
        {
          stopping_distance -= 0.5f;
        }
        else
        {
          stopping_distance += 0.5f;
        }
      }
      else
      {
        f32 cur = stopping_distance;
        f32 tgt = circle_radius;
        f32 diff = cur - tgt;
        if (diff > 0.2f)
        {
          stopping_distance = cur - 0.2f;
        }
        else
          if (diff < -0.2f)
        {
          stopping_distance += 0.2f;
        }
        else
        {
          stopping_distance = tgt;
        }
      }
      switch (random_phase)
      {
        case 1:
        {
          desired_speed = 0.7f;
          approach_target(0.12f);
          calc_xz_direction_to(&((TObjEneBm5GibonU *)this)->work_point, b);
          if (target_heading >= 0)
          {
            fx = b->z;
            fz = -b->x;
          }
          else
          {
            fz = b->x;
            fx = -b->z;
          }
          if (has_move_failures(1) != 0)
          {
            set_active();
          }
          else
          {
            clear_field_388();
          }
          move_with_wall_slide_on_ground(fx, fz, current_speed);
          if (has_move_failures(10) != 0)
          {
            state_timer = 0;
            random_phase = 2;
          }
          break;
        }

        case 2:
        {
          desired_speed = 0.5f;
          approach_target(0.12f);
          state_timer++;
          if (state_timer >= 0x28)
          {
            ang = rotation_y;
          }
          else
          {
            ang = rotation_y + (target_heading << 11);
          }
          fz = sin_table_lookup(ang);
          fx = cos_table_lookup(ang);
          if (has_move_failures(2) != 0)
          {
            state_timer = 0;
            set_active();
          }
          else
          {
            clear_field_388();
          }
          move_with_wall_slide_on_ground(fz, fx, current_speed);
          if (state_timer >= 0x50)
          {
            random_phase = 0;
          }
          break;
        }

      }

      rotation_y = approach_angle_limited(rotation_y, (s32) (RADIANS_TO_ANGLE * atan2_float(position.x - prev_position.x, position.z - prev_position.z)), 0x200);
      rotation_y = (s16) rotation_y;
      play_speed = 1.05f * current_speed;
      face_target();
      check_collisions();
      update_enemy_collision_flags();
      if (bodies->flags & 0x380000)
      {
        circle_shift_timer = 0x14;
      }
    }
      break;

    case 5:
      clear_field_388();
      break;

  }

}
#pragma pop
}
void TObjEneBm5GibonU::flanking_state(s32 msg) {
    s32 *rot = &this->target_heading;
    Vec *vel = &this->work_point;
    Vec *dir = &this->work_vector;
    f32 t;
    switch (msg) {
    case 4:
        this->requested_action = 3;
        this->set_field_378(0xA);
        this->clear_intangible();
        this->desired_speed = 2.0f;
        this->substate = 0;
        this->state_timer = 0;
        calc_rotated_vector(0x1C71, dir, rot);
        VecCopy(vel, dir);
        this->base_heading = *rot;
        return;
    case 3:
        if (this->current_target == NULL) {
            this->transition_enemy_state(8);
            return;
        }
        if (this->substate == 1) {
            this->transition_enemy_state(0x14);
            return;
        }
        if (this->is_passing_frame(this->frame_count - 1.0001f) != 0 &&
            this->destination_distance < 90.0f) {
            this->transition_enemy_state(0xB);
        }
    case 5:
    case 1:
        return;
    case 0:
        this->advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            return;
        }
        if (this->is_passing_frame(13.0f) != 0) {
            this->spawn_landing_effect(&this->position);
        }
        play_run_footstep();
        if (this->is_passing_frame(10.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            if (this->state_timer == 0) {
                this->state_timer = 1;
                calc_rotated_vector(-0x1C71, dir, rot);
            } else {
                this->state_timer = 0;
                calc_rotated_vector(0x1C71, dir, rot);
            }
        }
        if (this->is_passing_frame(this->frame_count - 1.0001f) != 0) {
            VecCopy(vel, dir);
            this->base_heading = *rot;
        }
        this->rotation_y = approach_angle_limited(this->rotation_y, this->base_heading, 0x800);
        this->rotation_y = (s16)this->rotation_y;
        if (this->is_passing_frame(18.0f) != 0) {
            this->current_speed = 6.0f;
        }
        t = this->frame;
        if (t >= 10.0f && t <= 18.0f) {
            this->move_with_wall_slide_on_ground(vel->x, vel->z, 1.0f);
        } else {
            this->current_speed *= 0.9f;
            this->move_with_wall_slide_on_ground(vel->x, vel->z, this->current_speed);
        }
        this->run_distance += this->current_speed;
        if (this->run_distance >= 50.0f) {
            this->run_distance -= 50.0f;
            if (this->random_ratio() < this->run_foie_chance) {
                this->substate = 1;
            }
        }
        this->face_target();
        this->check_collisions();
        this->update_enemy_collision_flags();
        break;
    }
}

void TObjEneBm5GibonU::chasing_state(s32 msg) {
    f32 frame;
    f32 speed;
    switch (msg) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(9);
        this->clear_intangible();
        this->desired_speed = 1.6f;
        this->substate = 0;
        return;
    case 3:
        if (this->current_target == NULL) {
            this->transition_enemy_state(8);
        } else if (this->has_move_failures(0xA) != 0) {
            this->transition_enemy_state(0xA);
        } else if ((s32) this->substate == 1) {
            this->transition_enemy_state(0x14);
        } else if ((this->is_passing_frame((f32) (this->frame_count - 1.0001f)) != 0) && (this->destination_distance < 90.0f)) {
            this->transition_enemy_state(0xB);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        this->advance_animation();
        if (this->is_passing_frame(13.0f) != 0) {
            this->spawn_landing_effect(&this->position);
        }
        if ((s16) this->requested_action == 2) {
            play_run_footstep();
        }
        if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            if (this->is_passing_frame(18.0f) != 0) {
                this->current_speed = 4.0f;
            }
            frame = this->frame;
            if ((frame >= 10.0f) && (frame <= 18.0f)) {
                enemy_turn_and_move_on_ground(this, (768.0f * this->current_speed), 1.0f);
            } else {
                this->current_speed *= 0.9f;
                speed = this->current_speed;
                enemy_turn_and_move_on_ground(this, (768.0f * speed), speed);
            }
            this->run_distance += this->current_speed;
            if (this->run_distance >= 50.0f) {
                this->run_distance -= 50.0f;
                if (this->random_ratio() < this->run_foie_chance) {
                    this->substate = 1;
                }
            }
            this->face_target();
            this->check_collisions();
            this->update_enemy_collision_flags();
        }
        break;
    }
}
}
extern "C" {

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::roaming_state(s32 msg) {
    s32 angle;
    f32 radius;
    TObjChara *target;
    f32 dx;
    f32 dz;

    switch (msg) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(8);
        this->clear_intangible();
        this->state_timer = 0;
        this->substate = 0;
        this->random_phase = actor_rand_int((saddr)this, 0x14);
        this->near_target = 0;
        angle = (s32)(65536.0f * this->random_ratio());
        radius = 120.0f * this->random_ratio();
        this->destination.x = radius * sin_table_lookup(angle) + this->group_anchor.x;
        this->destination.z = radius * cos_table_lookup(angle) + this->group_anchor.z;
        this->desired_speed = 0.7f * this->random_ratio() + 0.3f;
        this->current_speed = 0.0f;
        this->stopping_distance = 2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desired_speed);
        this->update_velocity();
        break;
    case 3:
        if (this->near_target != 0) {
            this->select_attack_by_range();
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        if (this->play_sound_variant() != 0) {
            f32 dist;
            target = this->current_target;
            dx = target->position.x - this->position.x;
            dz = target->position.z - this->position.z;
            dist = dx * dx;
            dist += dz * dz;
            if (dist < 22500.0f) {
                this->near_target = 1;
            }
            this->face_target();
        } else {
            this->turn_toward_angle(this->rotation_y);
        }
        switch (this->substate) {
        case 0:
            play_walk_footsteps();
            this->update_velocity();
            this->approach_target(0.05f);
            this->state_timer += 1;
            if (this->destination_distance < this->stopping_distance || this->state_timer > 100) {
                this->substate = 1;
                this->desired_speed = 0.0f;
            } else if (this->has_move_failures(0x14) != 0) {
                this->state_timer = 0;
                this->pick_wander_destination();
                this->desired_speed = this->rand_range(0.3f, 1.0f);
                this->stopping_distance = 2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desired_speed);
            }
            this->play_speed = 1.05f * this->current_speed;
            enemy_turn_and_move_on_ground(this, 512.0f * this->current_speed, this->current_speed);
            break;
        case 1:
            play_walk_footsteps();
            this->update_velocity();
            this->approach_target(0.020000001f);
            if (this->current_speed <= 0.1f) {
                this->substate = 2;
                this->state_timer = this->rand_range(240.0f, 360.0f);
                this->requested_action = 0;
            }
            this->play_speed = 1.05f * this->current_speed;
            enemy_turn_and_move_on_ground(this, 512.0f * this->current_speed, this->current_speed);
            break;
        case 2:
            this->requested_action = 0;
            this->state_timer -= 1;
            if (this->state_timer <= 0) {
                this->pick_wander_destination();
                this->desired_speed = this->rand_range(0.3f, 1.0f);
                this->current_speed = 0.0f;
                this->stopping_distance = 2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desired_speed);
                this->substate = 0;
                this->requested_action = 1;
            }
            this->update_ground_contact();
            break;
        }
        this->check_collisions();
        this->update_enemy_collision_flags();
        break;
    }
}
#pragma pop

void TObjEneBm5GibonU::empty_state(s32) {  }

void TObjEneBm5GibonU::howling_state(s32 msg) {
    TObjEneBm5GibonUNode *n;
    TObjEneBm5GibonU *o;
    switch (msg) {
    case 4:
        this->requested_action = 0xE;
        this->set_field_378(8);
        this->set_intangible();
        this->substate = 0;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(8);
        }
        break;
    case 5:
        break;
    case 0:
        (this->substate)++;
        this->advance_animation();
        if (this->is_passing_frame(20.0f) != 0) {
            play_sound_effect(this->remap_sound_for_area(0x3A523), &this->position, 0, 0);
        }
        if (this->substate == 0x3C) {
            for (n = ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__instance_list)->head; n != NULL; n = n->next) {
                o = n->get_owner();
                if (this->group_id == o->get_group_id()) {
                    o->set_flag();
                }
            }
        }
        if (enemy_validate_retained_target(this) != 0) {
            if (this->requested_action == 0xE) {
                this->face_target();
            } else {
                this->turn_offset = 0;
            }
        } else {
            this->play_sound_variant();
        }
        this->update_ground_contact();
        this->update_body_colliders();
        break;
    }
}

void TObjEneBm5GibonU::standing_state(s32 msg) {
  switch (msg)
  {
    case 4:
      this->requested_action = 5;
      this->set_field_378(8);
      (this->set_intangible());
      this->substate = 0;
      return;
    case 3:
      if ((this->substate) > 0x3C)
    {
      this->transition_enemy_state(8);
    }
    case 5:
      return;
      return;
    case 0:
      this->substate = (s32) ((this->substate) + 1);
      this->advance_animation();
      if (this->is_passing_frame(20.0f) != 0)
    {
      play_sound_effect(this->remap_sound_for_area(0x3A523), &this->position, 0, 0);
    }
      if (enemy_validate_retained_target(this) != 0)
    {
      this->enemy_copy_target_destination();
      this->update_velocity();
      this->face_target();
    }
    else
    {
      this->play_sound_variant();
    }
      (this->update_ground_contact());
      (this->update_body_colliders());
      break;
  }
}

void TObjEneBm5GibonU::alerted_state(s32 msg) {
  switch (msg)
  {
    case 4:
      *((s16 *) (((s8 *) this) - -0xB8)) = 4;
      this->set_field_378(5);
      (this->set_intangible());
      this->substate = (s32) (((s32) (60.0f * this->random_ratio())) + 0xA);
      return;
      return;
      this->substate = (s32) (((s32) (60.0f * this->random_ratio())) + 0xA);
    case 3:
      if ((this->substate) <= 0)
    {
      this->set_anim_by_state();
    }
    case 5:
      return;
    case 0:
      this->substate = (s32) ((this->substate) - 1);
      this->play_sound_variant();
      this->advance_animation();
      (this->update_ground_contact());
      (this->update_body_colliders());
      break;
  }
}

void TObjEneBm5GibonU::sleeping_state(s32 msg) {
  u8 *entity;
  switch (msg)
  {
    case 4:
      this->requested_action = 4;
      this->set_field_378(3);
      (this->clear_intangible());
      ((TObjEneDD_ST *)(this))->enemy_clear_target();
      this->turn_offset = 0;
      this->status_flags = (s32) ((this->status_flags) & 0xFFFFFFFE);
      return;
    case 3:
      if ((this->status_flags) & 1)
    {
      this->transition_enemy_state(5);
      return;
    }
      if ((this->current_target) != 0U)
    {
      this->enemy_copy_target_destination();
      this->set_anim_by_state();
      entity = (u8 *) find_entity_by_id(this->leader_id);
      if (entity != 0)
      {
        ((TObjEneBm5GibonU *)entity)->set_flag();
      }
    }
      return;
    case 0:
      this->play_sound_variant();
      this->advance_animation();
      (this->update_ground_contact());
      (this->update_body_colliders());
      return;
      return;
    case 5:
      this->status_flags = (s32) ((this->status_flags) & 0xFFFFFFFE);
      break;
  }
}

void TObjEneBm5GibonU::spot_appearing_state(s32 msg) {
    Vec *home = &this->work_point;
    switch (msg) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(8);
        this->set_intangible();
        this->status_flags &= ~3;
        ((TObjEneDD_ST *)(this))->enemy_clear_target();
        this->turn_offset = 0;
        VecCopy(home, &this->position);
        this->appear_fade.start_fade_in();
        play_area_sound_effect(&this->position);
        break;
    case 3:
        if (this->appear_fade.advance_toward_max() != 0) {
            if (this->update_target() != 0) {
                this->transition_enemy_state(8);
            } else {
                this->transition_enemy_state(3);
            }
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        this->update_ground_contact();
        this->update_body_colliders();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::appearing_state(s32 msg) {
    Vec *home = &this->work_point;
    switch (msg) {
    case 4:
        this->requested_action = 0xF;
        this->set_field_378(8);
        this->set_intangible();
        this->status_flags = (s32) (this->status_flags & 0xFFFFFFFC);
        ((TObjEneDD_ST *)(this))->enemy_clear_target();
        this->turn_offset = 0;
        VecCopy(home, &this->position);
        this->position.x -= 100.0f * sin_table_lookup(this->rotation_y);
        this->position.z -= 100.0f * cos_table_lookup(this->rotation_y);
        this->stopping_distance = 3.5714285f;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            if (this->update_target() != 0) {
                this->transition_enemy_state(8);
            } else {
                this->transition_enemy_state(3);
            }
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        if (!(this->motion_flags & 4)) {
            play_jump_footsteps();
            if (this->is_passing_frame(8.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x3A828), &this->position, 0, 0);
            }
            if (this->is_passing_frame(22.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x3A529), &this->position, 0, 0);
            }
            if (this->frame > 28.0f) {
                this->stopping_distance *= 0.8f;
            }
            this->position.x += this->stopping_distance * sin_table_lookup(this->rotation_y);
            this->position.z += this->stopping_distance * cos_table_lookup(this->rotation_y);
        }
        this->update_ground_contact();
        this->update_body_colliders();
        break;
    }
}
#pragma pop

void TObjEneBm5GibonU::handle_state(s32 msg) {
  TObjEneBm5GibonU *other;
  switch (msg)
  {
    case 4:
      state_timer = 0;
      set_field_378(0);
      set_intangible();
      status_flags |= 2;
      return;
    case 3:
      if (state_timer > 0)
    {
      if (appear_mode < 1)
      {
        transition_enemy_state(1);
        return;
      }
      transition_enemy_state(2);
    }
    case 5:
      return;
    case 0:
      other = TObjEneBm5GibonU::find_pack_leader(group_id);
      if (other)
    {
      leader_id = other->get_entity_id();
    }
      if (is_leader != 0 || other == NULL)
    {
      VecCopy(&group_anchor, &spawn_position);
    }
    else
    {
      VecCopy(&group_anchor, other->get_spawn_position());
    }
      state_timer++;
      break;
  }
}

}

#pragma pop

// The Gibbon's static data from TObjEneBm5GibonU__stat_params on: the parameter tables, then
// the two lists, each after the destructor-chain record __register_global_object fills in.
struct TObjEneBm5GibonUStaticData {
    u8 tables[0x2c];
    u8 node_list_chain[0xc];
    TObjEneBm5GibonUList node_list;
    u8 enemy_list_chain[0xc];
    TObjEneBm5GibonUList enemy_list;
};

extern "C" {
void __register_global_object(void *obj, void *dtor, void *chain);
void __dt__20TObjEneBm5GibonUListFv();
}

#pragma defer_codegen on

Vec *TObjEneBm5GibonU::get_spawn_position() { return &this->spawn_position; }

s32 TObjEneBm5GibonU::get_group_id() { return this->group_id; }

#pragma push
#pragma opt_propagation off
void TObjEneBm5GibonU::register_global_objects() {
    TObjEneBm5GibonUStaticData *data = (TObjEneBm5GibonUStaticData *)TObjEneBm5GibonU__stat_params;
    __register_global_object(data->node_list.reset(), (void *)__dt__20TObjEneBm5GibonUListFv, data->node_list_chain);
    __register_global_object(data->enemy_list.reset(), (void *)__dt__20TObjEneBm5GibonUListFv, data->enemy_list_chain);
}
#pragma pop

TObjEneBm5GibonUNode::TObjEneBm5GibonUNode() {
    prev = NULL;
    next = NULL;
    entity_id = 0xFFFF;
}

TObjEneBm5GibonUNode::~TObjEneBm5GibonUNode() {}

void TObjEneBm5GibonUNode::unlink_from(TObjEneBm5GibonUNode **head, TObjEneBm5GibonUNode **tail) {
    if (prev != NULL) {
        prev->next = next;
    } else {
        *head = next;
    }
    if (next != NULL) {
        next->prev = prev;
        return;
    }
    *tail = prev;
}

void TObjEneBm5GibonUNode::append_to(TObjEneBm5GibonUNode **head, TObjEneBm5GibonUNode **tail) {
    TObjEneBm5GibonUNode *last = *tail;
    if (last != NULL) {
        prev = last;
        (*tail)->next = this;
    } else {
        prev = NULL;
        *head = this;
    }
    *tail = this;
    next = NULL;
}

void TObjEneBm5GibonUNode::set_owner(TObjEneBm5GibonU *owner) {
    entity_id = owner->get_entity_id();
}

TObjEneBm5GibonU *TObjEneBm5GibonUNode::get_owner() {
    return (TObjEneBm5GibonU *)find_entity_by_id(entity_id);
}

TObjEneBm5GibonUList *TObjEneBm5GibonUList::reset() {
    clear();
    return this;
}

TObjEneBm5GibonUList::~TObjEneBm5GibonUList() {}

void TObjEneBm5GibonUList::clear() {
    head = NULL;
    tail = NULL;
}

void TObjEneBm5GibonUList::append(TObjEneBm5GibonUNode *node) {
    node->append_to(&head, &tail);
}

void TObjEneBm5GibonUList::remove(TObjEneBm5GibonUNode *node) {
    node->unlink_from(&head, &tail);
}

void TObjEneBm5GibonU::load_resources() {
    s32 i;
    BmlResource *m;
    f32 *v;
    if (is_split_screen() != 0) {
        m = load_enemy_bml_resource(&bm_ene_bm5_gibon_u_low_resource_descriptor);
    } else {
        m = load_enemy_bml_resource(&bm_ene_bm5_gibon_u_resource_descriptor);
    }
    TObjEneBm5GibonU__model_archive = m;
    ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__pack_member_list)->clear();
    ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__instance_list)->clear();
    TObjEneBm5GibonU__render_node_index = 0;
    TObjEneBm5GibonU__render_joint_y_rotation = 0;
    v = lbl_80500E98;
    lbl_80500E98[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    for (i = 0; i < 2; i++) {
        TObjEneBm5GibonU__stat_params[i] = TLobby::register_boss(gibon_base_stat_ids[i]);
        gibon_stat_handle_a_table[i] = TLobby::dispatch_shared_handler_b(gibon_attack_stat_ids[i]);
        gibon_stat_handle_b_table[i] = TLobby::register_object(gibon_resist_stat_ids[i]);
        gibon_param_table[i] = (u8 *)TLobby::dispatch_shared_handler_a(gibon_param_ids[i]);
    }
    NpcAnimationBinding sp = TObjEneBm5GibonU__spawn_params;
    m = TObjEneBm5GibonU__model_archive;
    sp.motions = m->motions;
    TObjNpcEnemy::register_animated_chunk(0xE, m->models[0].model, m->models[0].texlist, &sp, gibon_collision_body_templates[0].radius, 0.0f);
    TObjNpcEnemy::register_animated_chunk(0xF, TObjEneBm5GibonU__model_archive->models[1].model, TObjEneBm5GibonU__model_archive->models[1].texlist, &sp, gibon_collision_body_templates[1].radius, 0.0f);
}

void *TObjEneBm5GibonU::create(void *set_data) {
    return new TObjEneBm5GibonU(tl_04, set_data);
}

void TObjEneBm5GibonU::release_static_resource() {
    if (TObjEneBm5GibonU__model_archive != NULL) {
        delete TObjEneBm5GibonU__model_archive;
        TObjEneBm5GibonU__model_archive = NULL;
    }
}

void TObjEneBm5GibonU::add_to_pack_member_list() {
    ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__pack_member_list)->append(&pack_node);
}

void TObjEneBm5GibonU::remove_from_pack_member_list() {
    ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__pack_member_list)->remove(&pack_node);
}

void TObjEneBm5GibonU::add_to_instance_list() {
    ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__instance_list)->append(&instance_node);
}

void TObjEneBm5GibonU::remove_from_instance_list() {
    ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__instance_list)->remove(&instance_node);
}

TObjEneBm5GibonU *TObjEneBm5GibonU::find_pack_leader(s32 id) {
    TObjEneBm5GibonUNode *n;
    for (n = ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__instance_list)->head; n != 0; n = n->next) {
        TObjEneBm5GibonU *e = n->get_owner();
        if (e != 0 && e->group_id == id) {
            return e;
        }
    }
    return 0;
}

TObjEneBm5GibonU::TObjEneBm5GibonU(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    s32 i;
    s32 b;
    this->m_name = TObjEneBm5GibonU__class_name;
    this->invoke_initialization_hook(set_data);
    this->select_subtype();
    this->init_position_vectors();
    if (this->is_leader == 1) {
        this->init_model(&gibon_collision_body_templates[1], 1);
    } else {
        this->init_model(&gibon_collision_body_templates[0], 1);
    }
    this->set_action_table(gibon_u_action_table);
    this->set_motion_list(TObjEneBm5GibonU__model_archive->motions);
    this->requested_action = 0;
    this->set_animation(this->requested_action);
    this->set_requested_action(this->requested_action);
    b = this->is_leader ? 1 : 0;
    this->reset_hp(TObjEneBm5GibonU__stat_params[b], gibon_stat_handle_a_table[b], gibon_stat_handle_b_table[b]);
    this->set_state_flag_1();
    this->movementParameters = &TObjEneBm5GibonU__movement_parameters;
    if (this->is_leader != 0) {
        this->initialize_enemy_state(0x3C);
    } else {
        this->initialize_enemy_state(0x3B);
    }
    this->wall_reach = 15.0f;
    this->enemy_init_acquire_period(0x14);
    this->enemy_init_validate_period(0x14);
    pack_node.set_owner(this);
    this->add_to_pack_member_list();
    if (this->is_leader != 0) {
        instance_node.set_owner(this);
        this->add_to_instance_list();
    }
    this->leader_id = 0xFFFF;
    this->turn_offset = 0;
    VecCopy(&this->spawn_position, &this->position);
    VecCopy(&this->group_anchor, &this->position);
    this->desired_speed = 0.0f;
    this->current_speed = 0.0f;
    this->status_flags = 0;
    this->attack_collider = new TObjCollidable(NULL);
    init_collision_body_parts(this->attack_collider, &gibon_collision_body_templates[2], 1);
    this->reaction_delay = 0;
    this->reaction_attacker_id = 0xFFFF;
    this->set_colliders_contact_low();
    this->substate = 0;
    this->state_timer = 0;
    this->random_phase = 0;
    this->circle_shift_timer = 0;
    this->target_heading = 0;
    this->base_heading = 0;
    this->stopping_distance = 0.0f;
    this->circle_radius = 0.0f;
    this->sink_depth = 0.0f;
    this->pad_53c = 0.0f;
    this->work_point.x = 0.0f;
    this->work_point.y = 0.0f;
    this->work_point.z = 0.0f;
    this->work_vector.x = 0.0f;
    this->work_vector.y = 0.0f;
    this->work_vector.z = 0.0f;
    this->pad_558 = 0.0f;
    this->pad_55c = 0.0f;
    this->pad_560 = 0.0f;
    this->near_target = 0;
    this->update_center_position();
    this->update_body_colliders();
    this->transform_part_positions();
    this->mode = 0;
    this->dispatch_action(this->mode, 4);
    for (i = 0; i < 4; i++) {
        this->camera_fades[i].activate_and_dispatch();
    }
}

TObjEneBm5GibonU::~TObjEneBm5GibonU() {
    if (attack_collider != NULL) {
        free_collision_body_parts(attack_collider);
        delete attack_collider;
        attack_collider = NULL;
    }
    remove_from_pack_member_list();
    if (is_leader != 0) {
        remove_from_instance_list();
    }
    free_collision_body_parts(this);
}

void TObjEneBm5GibonU::run_task() {
    TObject *partner;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    partner = (TObject *)find_entity_by_id(leader_id);
    if (partner != NULL) {
        partner->all_parents_unqueued_for_destruction();
    }
    if (this->update_status_effects() != 4) {
        if (this->reaction_delay != 0) {
            this->reaction_delay = (this->reaction_delay - 1);
            if ((s32) this->reaction_delay == 0) {
                if ((this->mode != 0x11) && (this->mode != 0x12)) {
                    transition_enemy_state(0xF);
                }
            }
        }
        this->update_action_state();
    } else {
        if (this->mode == 0) {
            this->update_action_state();
        } else if (this->mode == 1) {
            VecCopy(&position, &home_position);
            transition_enemy_state(8);
            this->update_action_state();
        }
    }
    update_center_position();
    submit_default_cursor_candidate();
    this->render_minimap_dot();
}

void TObjEneBm5GibonU::refresh_target() {  }

void TObjEneBm5GibonU::run_death_reaction() {
    if ((this->mode != 0x11) && (this->mode != 0x12)) {
        transition_enemy_state(0x11);
    }
}

void TObjEneBm5GibonU::run_hit_reaction() { if (this->mode != 16) { transition_enemy_state(16); } }

void TObjEneBm5GibonU::run_miss_reaction() {  }

void TObjEneBm5GibonU::update_center_position() {
    body_center.x = position.x;
    body_center.y = 10.0f + position.y;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}

void TObjEneBm5GibonU::update_body_colliders() {
    this->bodies->offset.y = 10.0f;
}

void TObjEneBm5GibonU::select_subtype() {
    group_id = (s32)floor_to_float(parameters[0]);
    if (parameters[1] >= 1.0f) {
        appear_mode = 0;
    } else {
        appear_mode = 1;
    }
    if (variant >= 1) {
        is_leader = 1;
        technique_type = 1;
        model = (void *)TObjEneBm5GibonU__model_archive->models[1].model;
        texlist = TObjEneBm5GibonU__model_archive->models[1].texlist;
    } else {
        is_leader = 0;
        technique_type = 0;
        model = (void *)TObjEneBm5GibonU__model_archive->models[0].model;
        texlist = TObjEneBm5GibonU__model_archive->models[0].texlist;
    }
    backjump_chance = 0.4f + parameters[2];
    run_foie_chance = 0.3f + parameters[3];
    back_foie_chance = 0.3f + parameters[4];
}

void TObjEneBm5GibonU::turn_toward_angle(s32 angle) {
    s32 d;
    d = angle_diff_s16(this->rotation_y, angle);
    if (d > 0x3000) {
        d = 0x3000;
    } else if (d < -0x3000) {
        d = -0x3000;
    }
    if (this->turn_offset * d >= 0) {
        this->turn_offset = approach_angle_limited(this->turn_offset, d, 0x400);
    } else if (this->turn_offset * angle_diff_s16(this->turn_offset, d) >= 0) {
        if (this->turn_offset >= 0) {
            this->turn_offset -= 0x400;
        } else {
            this->turn_offset += 0x400;
        }
    } else {
        this->turn_offset = approach_angle_limited(this->turn_offset, d, 0x400);
    }
    this->turn_offset = (s16)this->turn_offset;
}

void TObjEneBm5GibonU::face_target() {
    Vec off;
    Vec q;
    off.x = sin_table_lookup(rotation_y) * 0.0f;
    q.x = position.x + off.x;
    off.z = cos_table_lookup(rotation_y) * 0.0f;
    q.z = position.z + off.z;
    q.x = current_target->position.x - q.x;
    q.z = current_target->position.z - q.z;
    turn_toward_angle((s32)(RADIANS_TO_ANGLE * atan2_float(q.x, q.z)));
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::pick_wander_destination() {
    Vec v;
    f32 d;
    CsnHit *hit;
    v.x = this->position.x - this->group_anchor.x;
    v.y = 0.0f;
    v.z = this->position.z - this->group_anchor.z;
    normalize_vector_xz(&v);
    rotate_xz_pair_by_angle(&v.x, &v.z, (s32)(32768.0f * this->random_ratio()) + 0x4000);
    d = 120.0f * this->rand_range(0.3f, 1.0f);
    this->destination.x = v.x * d + this->group_anchor.x;
    this->destination.z = v.z * d + this->group_anchor.z;
    hit = csnVector(&this->body_center, &this->destination, 0x88E0);
    if (hit != NULL) {
        v.x = hit->contact->point.x - this->position.x;
        v.z = hit->contact->point.z - this->position.z;
        d = normalize_vector_xz(&v) - 25.0f;
        this->destination.x = v.x * d + this->position.x;
        this->destination.z = v.z * d + this->position.z;
    }
}
#pragma pop

void TObjEneBm5GibonU::approach_target(f32 step) {
    f32 target;
    f32 speed;

    speed = current_speed;
    target = desired_speed;
    if (speed != target) {
        if (speed > target) {
            current_speed = speed - step;
            if (current_speed < desired_speed) {
                current_speed = desired_speed;
            }
        } else {
            current_speed = speed + step;
            if (current_speed > desired_speed) {
                current_speed = desired_speed;
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::calc_rotated_vector(s32 angle, Vec *out, s32 *rotation) {
    f32 c;
    f32 s;

    s = sin_table_lookup(angle);
    c = cos_table_lookup(angle);
    out->z = c * this->destination_direction.z - s * this->destination_direction.x;
    out->x = s * this->destination_direction.z + c * this->destination_direction.x;
    *rotation = (s32)(RADIANS_TO_ANGLE * atan2_float(out->x, out->z));
}
#pragma pop

void TObjEneBm5GibonU::select_attack_by_range() {
    run_distance = 0.0f;
    if (random_ratio() < 0.5f) {
        transition_enemy_state(9);
        return;
    }
    transition_enemy_state(0xA);
}

void TObjEneBm5GibonU::set_anim_by_state() {
    if ((s32) is_leader != 0) {
        transition_enemy_state(7);
        return;
    }
    transition_enemy_state(6);
}

#pragma push
#pragma fp_contract on
f32 TObjEneBm5GibonU::calc_xz_direction_to(Vec *target, Vec *dir) {
    f32 dx;
    f32 dz;
    dx = this->position.x - target->x;
    dz = this->position.z - target->z;
    f32 d = dx * dx + dz * dz;
    f32 inv = 1.0f / newton_sqrtf(d);
    dir->x = dx * inv;
    dir->y = 0.0f;
    dir->z = dz * inv;
    return d * inv;
}
#pragma pop

void TObjEneBm5GibonU::set_flag() { status_flags |= 0x1; }

s32 TObjEneBm5GibonU::update_target() {
    if (this->is_leader != 0) {
        return this->select_and_apply_target(350.0f);
    }
    return this->select_and_apply_target(250.0f);
}

s32 TObjEneBm5GibonU::play_sound_variant() {
    if ((s32) is_leader != 0) {
        return this->update_linked_position(350.0f);
    }
    return this->update_linked_position(250.0f);
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::spawn_recoil_dust(Vec *dir) {
    Vec v;
    VecCopy(&v, &this->position);
    v.x = 5.0f * dir->x + v.x;
    v.z = 5.0f * dir->z + v.z;
    this->spawn_landing_effect(&v);
}
#pragma pop

f32 TObjEneBm5GibonU::calc_anim_speed(f32 speed) {
    return 28.0f / ((this->motion_list[this->action_table[7].motion].motion->frameCount - 1) / speed);
}

int TObjEneBm5GibonU::is_active() { return this->entity_id & 0x1; }

#pragma push
#pragma fp_contract on
s32 TObjEneBm5GibonU::calc_lunge_aim(int) {
    f32 dir_x;
    f32 dir_z;
    f32 side;
    if (is_target_unobstructed_from((TObjEneDD *)this, (TObjChara *)this->current_target) != 0) {
        this->enemy_copy_target_destination();
        this->update_velocity();
        if (this->is_active() != 0) {
            side = 7.0f;
        } else {
            side = -7.0f;
        }
        dir_z = this->destination_direction.z;
        dir_x = this->destination_direction.x;
        this->destination.x = (f32) (this->destination.x + ((2.0f * dir_x) + (dir_z * side)));
        this->destination.z = (f32) (this->destination.z + ((2.0f * dir_z) - (dir_x * side)));
        this->update_velocity();
        return (s32) (RADIANS_TO_ANGLE * atan2_float((f64) this->destination_direction.x, (f64) this->destination_direction.z));
    }
    this->destination_direction.x = sin_table_lookup(this->rotation_y);
    this->destination_direction.y = (f32) 0.0f;
    this->destination_direction.z = cos_table_lookup(this->rotation_y);
    VecCopy(&this->destination, &this->position);
    this->destination.x = (f32) ((30.0f * this->destination_direction.x) + this->destination.x);
    this->destination.z = (f32) ((30.0f * this->destination_direction.z) + this->destination.z);
    this->destination_distance = 30.0f;
    return this->rotation_y;
}
#pragma pop

void TObjEneBm5GibonU::schedule_pack_reaction(s32 timer, u16 id) {
    this->reaction_delay = timer;
    this->reaction_attacker_id = id;
}

void TObjEneBm5GibonU::damage_linked_entity_type10() {
    u8 *r = (u8 *)find_entity_by_id(leader_id);
    if (r != 0) {
        DirectAttackPayload d;
        d.kind = 10;
        d.power = 1.5f;
        receive_direct_attack(r, d, 0, -1, -1);
    }
}

void TObjEneBm5GibonU::damage_linked_entity() {
    u8 *r = (u8 *)find_entity_by_id(leader_id);
    if (r != 0) {
        DirectAttackPayload d;
        d.kind = 9;
        d.power = 1.5f;
        receive_direct_attack(r, d, 0, -1, -1);
    }
}

void TObjEneBm5GibonU::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        this->handle_state(reason);
        break;
    case 1:
        appearing_state(reason);
        break;
    case 2:
        spot_appearing_state(reason);
        break;
    case 3:
        sleeping_state(reason);
        break;
    case 4:
        empty_state(reason);
        break;
    case 5:
        alerted_state(reason);
        break;
    case 6:
        standing_state(reason);
        break;
    case 7:
        howling_state(reason);
        break;
    case 8:
        roaming_state(reason);
        break;
    case 9:
        chasing_state(reason);
        break;
    case 10:
        flanking_state(reason);
        break;
    case 11:
        this->run_idle_state(reason);
        break;
    case 12:
        update_lunge(reason);
        break;
    case 13:
        returning_state(reason);
        break;
    case 14:
        repositioning_state(reason);
        break;
    case 15:
        action(reason);
        break;
    case 16:
        hurt_state(reason);
        break;
    case 17:
        update_dying_state(reason);
        break;
    case 18:
        this->handle_message(reason);
        break;
    case 19:
        backjump_state(reason);
        break;
    case 20:
        this->state_cast_technique(reason);
        break;
    }
}

__declspec(section ".ctors") static void *const __sinit_TObjEneBm5GibonU_cpp_ref = (void *)TObjEneBm5GibonU::register_global_objects;
