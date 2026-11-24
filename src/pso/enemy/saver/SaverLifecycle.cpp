#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/saver/SaverLifecycle.h"
#include "pso/effect/enemy/TEneParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/effect/enemy/TeneFakeTecThunderEff.h"
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
#include "pso/render/render_util.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_800A7764.h"

#include "pso/render/TUnk_80490470.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/unk/TLobby.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjControl.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/model_render_state.h"
#include "pso/object/base/TObjBase.h"
#include "pso/technique/TechniqueRingwaveList.h"
#include "pso/render/GinjaMaterialState.h"

extern "C" {
void calc_velocity_toward_destination(TObjChara *chara, Vec from, Vec to, f32 speed);
s32 select_enemy_destination(TObjChara *chara, Vec dest, s32 flags);
f32 enemy_move_toward(TObjEnemy *enemy, s32 turn_speed, Vec dest, s32 flags, f32 *params, f32 speed);
s32 copy_position_if_valid(TObjChara *chara, Vec pos);
}

extern "C" {
extern const char *bm_ene_df1_saver_model_names[2];
extern const char *bm_ene_df1_saver_motion_names[12];
}
// Where render's node callback last placed the particle node (node 0x1A), in world space. 16 bytes in the
// original; only the first 12 are used, as a point.
struct SaverNodePoint { Vec pos; u8 pad_c[4]; };
SaverNodePoint saver_particle_node_position;
extern "C" {
player_stats *saver_boss_stat_handle;
AttackParams **player_object_ptr_array;
ActorParamBlock *saver_object_stat_handle;
f32 *saver_ai_params;  // [0] attack motion speed, [1] attack recovery frames, [2] walk speed, [3] walk motion speed
BmlResource *saver_bml_resource;
s16 *saver_scroll_polygons;  // polygon list whose uvs run_task scrolls once a frame
s32 saver_scroll_tick;
s32 saver_render_node_index;
s32 saver_render_rotation_x;
SampledMotionPoints *saver_attack_trail_points;
SampledMotionPoints *saver_jump_trail_points;
SampledMotionPoints *saver_nail_trail_points;
}


extern "C" {
__declspec(section ".data") const char *bm_ene_df1_saver_model_names[2] = {
    "df1_s_kil_body.nj", NULL,
};
const char *bm_ene_df1_saver_motion_names[12] = {
    "aseri_df1_s_kil_body.njm", "atack_df1_s_kil_body.njm", "damage_df1_s_kil_body.njm", "deadb_df1_s_kil_body.njm",
    "dead_df1_s_kil_body.njm", "defdam_df1_s_kil_body.njm", "defence_df1_s_kil_body.njm", "jump_df1_s_kil_body.njm",
    "nail_df1_s_kil_body.njm", "wait_df1_s_kil_body.njm", "walk_df1_s_kil_body.njm", NULL,
};
BmlResourceDescriptor bm_ene_df1_saver_resource_descriptor = {
    "bm_ene_df1_saver.bml",
    bm_ene_df1_saver_model_names, bm_ene_df1_saver_motion_names, 1, 11,
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
const NpcAnimationBinding saver_init_binding_desc = { NULL, saver_action_table, 0, 1, 11 };
const Vec lbl_8043A8A4 = {0.0f, 0.0f, 0.0f};
const Vec lbl_8043A8B0 = {0.0f, 0.0f, 0.0f};
const Vec lbl_8043A8BC = {0.0f, 0.0f, 0.0f};
SaverMoveParams saver_move_params = {
    250.0f, 1.25f, 0x400, {0, 0x64, 0, 0},
};
CollisionBody saver_collision_body_part_table[1] = {
    {{0.0f, 12.5f, 0.0f}, 6.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
}

void TObjPlayer::reset_effect_count() { fake_tec_texture = 0; }

void init_fake_tec_texlist() {
    fake_tec_texlist.textures = technique_ringwave_texnames;
    fake_tec_texlist.nbTexture = 0x10;
    fake_tec_texture = fake_tec_texlist.textures->texture->surface->id;
}

void TObjEneSaver::run_demo_task() {}

void TObjEneSaver::apply_lookup_entry_effect() {
    Vec edge[2];
    Vec *entry;

    entry = saver_attack_trail_points->lookup((f32)this->frame);
    if (entry != 0) {
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, this->rotation_y);
        matrix_mult_vec_array(NULL, entry, edge, 2);
        pop_matrix();
        if (attack_traces[0] != NULL) {
            attack_traces[0]->add_segment(&edge[0], &edge[1]);
        }
    }
}

void TObjEneSaver::update_particle_effect() {
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
        body_fade.start_fade_out();
        apply_actor_gravity(this, NULL, 0.0f);
        play_sound_effect(remap_sound_for_area(0x4003B207), &position, 0, 0);
        return;
    case 1:
        step_angle_clamped(0);
        move_with_wall_slide(this);
        velocity.x *= 0.5f;
        velocity.z *= 0.5f;
        if (body_fade.decay_value_toward_floor() == 1) {
            TObjPlayer::apply_effect_variant_a(&position, 0);
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
        refresh_lobby_state();
        send_entity_set_flags();
    }
}

void TObjEneSaver::update_entry_motion() {
    advance_animation();
    step_angle_clamped(0);
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

void TObjEneSaver::update_knockback_state() {

    advance_animation();
    step_angle_clamped(0);
    switch (phase) {
    case 0:
        phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case 1:
        move_with_wall_slide(this);
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

#pragma push
#pragma fp_contract on
// Mode 7: guard (action 5, motion 6 "defence").
void TObjEneSaver::state_defence() {
    advance_animation();
    step_angle_clamped(0);
    if (!(actorFlags & 0x800000)) {
        apply_actor_gravity(this, NULL, 0.0f);
    }
    switch (phase) {
    case 0:
        phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        if (last_attacker != NULL) {
            s32 bonus;
            s32 atp;
            atp = last_attacker->get_actor_attack_params_atp_min();
            bonus = last_attacker->get_atp();
            guard_hp -= 0.2f * (bonus + atp + last_attacker->get_atp_range() - dfp);
            if (guard_hp <= 0) {
                guard_hp = 0;
                state_flags |= 8;
            }
        }
        actorFlags |= 0x04000000;
        play_sound_effect(remap_sound_for_area(0x4003AD05), &position, 0, 0);
        break;
    case 1:
        if (is_passing_frame(5.0f) != 0) {
            particle_type = 0x107;
        }
        if (is_passing_frame(28.0f) != 0) {
            actorFlags &= 0xFBFFFEFF;
            state_flags &= ~0x20;
            if (test_flag_256() != 0) {
                phase = 0;
                frame = 0.0f;
            } else {
                phase = 2;
            }
            calc_move_state();
        }
        break;
    case 2:
    default:
        actorFlags &= 0xFBFFFEFF;
        state_flags &= ~0x20;
        break;
    }
    check_object_collisions();
    check_enemy_body_collisions(this);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    actorFlags &= ~0x200000;
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
            if (!(TObjPlayer::calc_distance_to_client(this, i, &v) < 900.0f)) {
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

void TObjEneSaver::state_jump_attack() {
    Vec edge[2];
    Vec d;
    TObjPlayer *p;
    Vec *e;
    u16 id;
    id = targetId;
    if (id < 0x1000) {
        p = get_player_by_client_id(id);
        if (p != NULL && p->get_floor() == get_current_floor()) {
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
    step_angle_clamped(0);
    switch (phase) {
    case 0:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        if (is_passing_frame(11.0f) != 0) {
            TObjChara *t = target;
            if (t == NULL) {
                goto fail;
            }
            if (select_enemy_destination(this, ((TObjChara *)t)->body_center, 1) == 0) {
                goto fail;
            }
            phase = 1;
            copy_position_if_valid(this, body_center);
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
        move_with_wall_slide(this);
        if (11.0f <= frame && frame <= 27.0f) {
            if ((e = saver_jump_trail_points->lookup(frame)) != NULL) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&position.x);
                rotate_matrix_y(0, rotation_y);
                matrix_mult_vec_array(NULL, e, edge, 2);
                pop_matrix();
                if (attack_traces[1] != NULL) {
                    attack_traces[1]->add_segment(&edge[0], &edge[1]);
                }
            }
        }
        if (is_passing_frame(23.0f) != 0) {
            check_object_collisions();
            check_enemy_body_collisions(this);
            phase = 2;
            damage_targets_in_reach();
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

// Mode 5: the "nail" attack (action 3, motion 8); the damage it deals refills guard_hp.
void TObjEneSaver::state_nail() {
    Vec w;
    Vec v;
    u16 id;

    id = targetId;
    if (id < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(id);
        if (p != NULL && p->get_floor() == get_current_floor()) {
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
    bodies->flags |= 1;
    actorFlags &= 0xF9FBFFFF;
    advance_animation();
    step_angle_clamped(0);
    switch (phase) {
    case 0:
        phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        play_sound_effect(remap_sound_for_area(0x4003AD02), &position, 0, 0);
        break;
    case 1:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        if (is_passing_frame(7.0f) != 0) {
            if (target != NULL && target->select_melee_contact_body(this, 1.0f) != 0) {
                f32 damage = target->receive_physical_attack(this, 1.0f);
                target->apply_knockback_from_attacker((u8 *)this, damage);
                guard_hp = guard_hp + damage;
                particle_type = 0x10E;
                if (guard_hp_max < guard_hp) {
                    guard_hp = guard_hp_max;
                }
                play_sound_effect(remap_sound_for_area(0x4003B241), &body_center, 0, 0);
            }
        }
        if (0.0f <= frame && frame <= 7.0f) {
            Vec *entry = saver_nail_trail_points->lookup(frame);
            if (entry != NULL) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&position.x);
                rotate_matrix_y(0, rotation_y);
                matrix_mult_vec_array(NULL, entry, &v, 2);
                pop_matrix();
                if (attack_traces[2] != NULL) {
                    attack_traces[2]->add_segment(&v, &w);
                }
            }
        }
        if (action_flags != 4) {
            phase = 2;
            step_counter++;
        }
        break;
    case 2:
        calc_move_state();
        if (step_counter >= 2) {
            step_counter = 0;
            state_flags &= ~8;
        }
        actorFlags &= ~0x200000;
        break;
    }
    check_object_collisions();
    check_enemy_body_collisions(this);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}


#pragma defer_codegen on

void TObjEneSaver::select_model_record(s32 i) {
    model = saver_bml_resource->models[i].model;
    texlist = saver_bml_resource->models[i].texlist;
}

void *TObjEneSaver::get_center() { return &body_center; }

TObjEneSaver::TObjEneSaver(TObject *parent, void *set_data) : TObjEnemy(parent) {
    s16 guard;
    m_name = TObjEneSaver__class_name;
    apply_set_data(set_data);
    init_position_vectors();
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
    select_model_record(variant);
    action_table = saver_action_table;
    set_action_table(action_table);
    motion_list = saver_bml_resource->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, saver_collision_body_part_table, 1);
    attack_index = 0;
    step_counter = 0;
    bind_enemy_combat_stats(saver_boss_stat_handle, player_object_ptr_array[attack_index], saver_object_stat_handle);
    movementParameters = &saver_move_params;
    referenceHp = hp;
    update_prev_position();
    copy_position();
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
    attack_traces[0] = TAttackTraceStrip::create(0xA0303030, 0xFFFF0088);
    attack_traces[1] = TAttackTraceStrip::create(0xA0303030, 0xFFFF0088);
    attack_traces[2] = TAttackTraceStrip::create(0xA0303030, 0xFF303030);
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
    BmlResource *r;
    r = new BmlResource(1, &bm_ene_df1_saver_resource_descriptor, 0, 0, NULL);
    saver_bml_resource = r;
    NJS_OBJECT *scroll_node = r->models[0].model->child->sibling;
    saver_scroll_polygons = static_cast<NJS_CNK_MODEL *>(scroll_node->model)->polygon_list;
    saver_scroll_tick = 0;
    saver_render_node_index = 0;
    saver_render_rotation_x = 0;
    saver_particle_node_position.pos.z = 0.0f;
    saver_particle_node_position.pos.y = 0.0f;
    saver_particle_node_position.pos.x = 0.0f;
    saver_attack_trail_points = new SampledMotionPoints(2, 15.0f, 60.0f, 1.0f);
    saver_jump_trail_points = new SampledMotionPoints(2, 11.0f, 27.0f, 1.0f);
    saver_nail_trail_points = new SampledMotionPoints(2, 0.0f, 7.0f, 1.0f);
    saver_attack_trail_points->sample_two_nodes(saver_bml_resource->models[0].model, (NJS_MOTION *)(saver_bml_resource->motions[saver_action_table[2].motion].motion), 0x20, 0x21);
    saver_jump_trail_points->sample_two_nodes(saver_bml_resource->models[0].model, (NJS_MOTION *)(saver_bml_resource->motions[saver_action_table[4].motion].motion), 0x20, 0x21);
    pos.x = pos.y = pos.z = 0.0f;
    dir.x = (-10.0f);
    dir.y = dir.z = 0.0f;
    saver_nail_trail_points->sample_node_offsets(saver_bml_resource->models[0].model, (NJS_MOTION *)(saver_bml_resource->motions[saver_action_table[3].motion].motion), 0x19, &pos, &dir);
    player_object_ptr_array = static_cast<AttackParams **>(mem_alloc(3 * sizeof(*player_object_ptr_array)));
    saver_boss_stat_handle = TLobby::register_boss(0x52);
    player_object_ptr_array[0] = TLobby::dispatch_shared_handler_b(0x57);
    player_object_ptr_array[2] = TLobby::dispatch_shared_handler_b(0x58);
    player_object_ptr_array[1] = TLobby::dispatch_shared_handler_b(0x59);
    saver_object_stat_handle = TLobby::register_object(0x51);
    saver_ai_params = (f32 *)TLobby::dispatch_shared_handler_a(0x51);
    NpcAnimationBinding init = saver_init_binding_desc;
    init.motions = saver_bml_resource->motions;
    TObjNpcEnemy::register_animated_chunk((s16)0x1A, saver_bml_resource->models[0].model, saver_bml_resource->models[0].texlist, &init, saver_collision_body_part_table[0].radius, (f32)0.0f);
}

void TObjEneSaver::free_resources() {
    if (player_object_ptr_array != NULL) {
        mem_free(player_object_ptr_array);
        player_object_ptr_array = NULL;
    }
    if (saver_attack_trail_points != NULL) {
        delete saver_attack_trail_points;
        saver_attack_trail_points = NULL;
    }
    if (saver_jump_trail_points != NULL) {
        delete saver_jump_trail_points;
        saver_jump_trail_points = NULL;
    }
    if (saver_nail_trail_points != NULL) {
        delete saver_nail_trail_points;
        saver_nail_trail_points = NULL;
    }
    if (saver_bml_resource != NULL) {
        delete saver_bml_resource;
        saver_bml_resource = NULL;
    }
}

void *create_ene_saver(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjEneSaver(control, set_data);
}

void TObjEneSaver::run_task() {
    if (saver_scroll_tick != actor_frame_tick) {
        saver_scroll_tick = actor_frame_tick;
        TObjPlayer__sub_8023DEE0(saver_scroll_polygons, 0xE, 0, 0);
    }
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
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
            state_appear();
            break;
        case 3:
            update_move_toward_target();
            break;
        case 4:
            state_attack();
            break;
        case 5:
            state_nail();
            break;
        case 6:
            state_jump_attack();
            break;
        case 7:
            state_defence();
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
            state_disappear();
            break;
        }
    }
    if (target != NULL && (target->actorFlags & 0x02000800)) {
        step_counter = 0;
        actorFlags &= ~0x200000;
        state_flags &= 0xFFFF0000;
        state_flags |= 0x40;
        target = NULL;
    }
    update_prev_position();
    copy_position();
    update_particle_effect();
    frame_timer += 1.0f;
}

void TObjEneSaver::render() {
    s32 v;
    v = classify_actor_view_detail(300.0f, 600.0f, 30.0f);
    if (v != 0) {
        select_actor_lighting(this);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix_from(NULL);
        translate_matrix_vec3(0, (u8 *)&position);
        rotate_matrix_y(0, rotation_y);
        saver_render_node_index = 0;
        saver_render_rotation_x = facing_angle;
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
        VecCopy(&particle_position, &saver_particle_node_position.pos);
        pop_matrix();
        restore_scene_lighting();
        if (!(state_flags & 1)) {
            draw_ground_shadow(0, 0);
        }
    } else {
        push_matrix_from(identity_matrix);
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        set_motion_packed_rotation();
        calc_joint_matrices(frame);
        clear_motion_packed_rotation();
        pop_matrix();
        push_matrix_from(anim_model_matrix_array[26]);
        {
            Vec t = lbl_8043A8A4;
            matrix_mult_vec(NULL, &t, &particle_position);
        }
        pop_matrix();
    }
}

void TObjPlayer::step_cutscene_frame(NJS_OBJECT *) {
    if (saver_render_node_index == 0x15) {
        rotate_matrix_x(NULL, saver_render_rotation_x);
    }
    if (saver_render_node_index == 0x1A) {
        saver_particle_node_position.pos.x = 0.0f;
        saver_particle_node_position.pos.y = 0.0f;
        saver_particle_node_position.pos.z = 0.0f;
        transform_vec_by_camera(&ninja_camera, &saver_particle_node_position.pos, &saver_particle_node_position.pos);
    }
    saver_render_node_index += 1;
}

void TObjEneSaver::step_angle_clamped(s32 angle) {
    s32 target_rot;

    target_rot = angle;
    if (target_rot < -0x238E) {
        target_rot = -0x238E;
    } else if (target_rot > 0x238E) {
        target_rot = 0x238E;
    }
    facing_angle = lerp_angle_half(facing_angle, target_rot);
}

void TObjEneSaver::turn_toward_target() {
    Vec d;
    VecCopy(&d, &target->body_center);
    subtract_vector(&d, &body_center);
    step_angle_clamped(angle_diff_s16(rotation_y, (s32)(10430.38043493439 * atan2_float(d.x, d.z))));
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
    if (test_actor_flags(0x10) != 0) {
        u16 best_id;
        s32 i;
        TObjPlayer *p;
        u16 id;
        f32 best;
        f32 d;
        u16 tid;
        i = 0;
        best_id = 0xFFFF;
        Vec v = lbl_8043A8B0;
        best = ((SaverMoveParams *)movementParameters)->radius * ((SaverMoveParams *)movementParameters)->radius;
        for (; i < registered_player_count + registered_enemy_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p != NULL && p != (TObjChara *)this) {
                id = p->get_entity_id();
                if (id < 0x4000 && id != entity_id && !(p->actorFlags & 0x02000800)) {
                    VecCopy(&v, &p->body_center);
                    subtract_vector(&v, &body_center);
                    d = v.x * v.x + v.z * v.z;
                    if (d < best && check_path_obstructed(this, &p->body_center) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
        }
        targetId = best_id;
        tid = targetId;
        if (tid < 0x1000U) {
            TObjPlayer *q = get_player_by_client_id(tid);
            if (q != NULL) {
                if (q->get_floor() == get_current_floor()) {
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
        u16 best_id2;
        u16 best_id;
        TObjPlayer *p;
        TObjPlayer *best_p2;
        TObjPlayer *best_p;
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
        best = ((SaverMoveParams *)movementParameters)->radius * ((SaverMoveParams *)movementParameters)->radius;
        best2 = best;
        for (; i < registered_player_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == NULL) continue;
            if (p->get_entity_id() >= 0x1000) continue;
            if (p->get_floor() != get_current_floor()) continue;
            if (p->actorFlags & 0x02000800) continue;
            VecCopy(&v, &p->body_center);
            subtract_vector(&v, &body_center);
            d = v.x * v.x + v.z * v.z;
            if ((p->class_flags & parameter_mask) && d < best &&
                check_path_obstructed(this, &p->body_center) != 1) {
                best_id = p->get_entity_id();
                best = d;
                best_p = p;
            }
            if (d < best2 && check_path_obstructed(this, &p->body_center) != 1) {
                best_id2 = p->get_entity_id();
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
    if (TObjChara::update_action_hold_status() != 0) {
        switch (mode) {
        case 0:
        case 1:
        case 2:
        case 0xB:
            if (body_fade.advance_toward_max() == 1) {
                state_flags &= ~0x43;
                state_flags |= 4;
                mode = 3;
                phase = 0;
                requested_action = 1;
                clear_actor_flags(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneSaver::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        switch (mode) {
        case 0:
        case 1:
        case 2:
        case 0xB:
            if (body_fade.advance_toward_max() == 1) {
                state_flags &= ~0x43;
                state_flags |= 4;
                mode = 3;
                phase = 0;
                requested_action = 1;
                clear_actor_flags(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

void TObjEneSaver::run_idle_action() {
    switch (mode) {
    case 0:
        if (body_fade.has_visible_opacity() != 0) {
            mode = 0xB;
            phase = 0;
            requested_action = 0;
            clear_actor_flags(0x200000);
            set_actor_flags(0x06040000);
            state_flags &= 0xFFFF0000;
            state_flags |= 0x40;
            bodies->flags &= ~1;
        }
        return;
    case 11:
        if (!(state_flags & 0x40)) {
            mode = 0;
            return;
        }
        break;
    default:
        mode = 0xB;
        phase = 0;
        requested_action = 0;
        clear_actor_flags(0x200000);
        set_actor_flags(0x06040000);
        state_flags &= 0xFFFF0000;
        state_flags |= 0x40;
        break;
    }
}

void TObjEneSaver::init_render_flags() {
    set_position_from(&home_position);
    refresh_collision_body_centers();
    actorFlags &= ~0x200000;
    actorFlags |= 0x06040000;
    bodies->flags &= ~1;
}

void TObjEneSaver::state_disappear() {
    actorFlags &= ~0x200000;
    actorFlags |= 0x06040000;
    state_flags &= ~7;
    bodies->flags &= ~1;
    advance_animation();
    switch (phase) {
    case 0:
    default:
        if (30.0f < (f32)step_counter++) {
            phase = 1;
            scale.z = 1.0f;
            scale.y = 1.0f;
            scale.x = 1.0f;
            step_counter = 0;
            body_fade.start_fade_out();
            apply_actor_gravity(this, NULL, 0.0f);
            play_area_variant_sound(&position);
        }
        break;
    case 1:
        scale.x -= 0.1f;
        if (scale.x < 1e-5f) {
            scale.x = 0.0f;
        }
        scale.y += 0.1f;
        scale.z = scale.x;
        if (body_fade.decay_value_toward_floor() == 1) {
            phase = 2;
        }
        break;
    case 2:
        set_position_from(&home_position);
        update_prev_position();
        scale.z = 1.0f;
        scale.y = 1.0f;
        scale.x = 1.0f;
        state_flags &= 0xFFFF0000;
        state_flags |= 1;
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneSaver::run_move_action() {
    switch (mode) {
    default:
        if (state_flags & 4) {
            mode = 3;
            phase = 0;
            requested_action = 1;
            actorFlags &= 0xF9FBFFFF;
        } else if (state_flags & 1) {
            mode = 1;
            phase = 0;
            actorFlags |= 0x06040000;
        }
        bodies->flags |= 1;
        return;
    case 1:
        if (state_flags & 2) {
            mode = 2;
            phase = 0;
            actorFlags |= 0x06040000;
        }
        return;
    case 2:
        if (state_flags & 4) {
            mode = 3;
            phase = 0;
            requested_action = 1;
            actorFlags &= 0xF9FBFFFF;
            return;
        }
        break;
    case 3:
        if (state_flags & 3) {
            mode = 1;
            phase = 0;
            actorFlags |= 0x06040000;
            state_flags &= 0xFFFF0000;
            state_flags |= 1;
            bodies->flags |= 1;
            return;
        }
        break;
    }
}


void TObjEneSaver::advance_motion_state() {

    actorFlags &= ~0x200000;
    actorFlags |= 0x06040000;
    bodies->flags &= ~1;
    switch (phase) {
    case 0:
        phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        return;
    case 1:
        if (horizontal_distance_squared(&target->body_center, &body_center) < 40000.0f) {
            phase = 2;
        }
        return;
    case 2:
        state_flags &= 0xFFFF0000;
        state_flags |= 2;
        break;
    }
}

void TObjEneSaver::state_appear() {
    actorFlags &= ~0x200000;
    actorFlags |= 0x06040000;
    bodies->flags &= ~1;
    advance_animation();
    switch (phase) {
    case 0:
        phase = 1;
        play_area_se_with_particle(&position);
        body_fade.start_fade_in();
        apply_actor_gravity(this, NULL, 0.0f);
        play_area_variant_sound(&position);
        break;
    case 1:
        if (body_fade.advance_toward_max() == 1) {
            phase = 2;
        }
        break;
    case 2:
        state_flags &= 0xFFFF0000;
        state_flags |= 4;
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneSaver::update_move_toward_target() {
    f32 reach;
    f32 dist;
    TObjChara *t;
    bodies->flags |= 1;
    actorFlags &= 0xF9DBFFFF;
    t = target;
    if (t != NULL) {
        switch (phase) {
        case 0: {
            if (select_enemy_destination(this, t->body_center, 1) != 0) {
                set_override_speed(saver_ai_params[3]);
                phase = 1;
                copy_position_if_valid(this, body_center);
                apply_actor_gravity(this, NULL, 0.0f);
            }
            break;
        }
        case 1: {
            enemy_move_toward(this, ((SaverMoveParams *)movementParameters)->turn_speed, t->body_center, 0, saver_ai_params, saver_ai_params[2]);
            dist = horizontal_distance_squared(&move_destination, &position);
            if (dist < 22500.0f) {
                state_flags &= ~0x10;
            } else {
                state_flags |= 0x10;
            }
            reach = ((SaverMoveParams *)movementParameters)->speed + bodies->radius;
            if (dist < (reach * reach)) {
                phase = 2;
            }
            break;
        }
        case 2:
            state_flags &= ~0x10;
            phase = 0;
            break;
        }
        advance_animation();
        turn_toward_target();
        check_object_collisions();
        check_enemy_body_collisions(this);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
        submit_cursor_candidate(this, -1);
    }
}

s32 TObjEneSaver::is_target_in_attack_range() {
    Vec v;
    f32 radius;
    f32 r;
    f32 dist;
    s32 ang;
    s32 flags;
    TObjChara *tgt;
    CollisionBody *body;
    if (mode >= 3) {
        tgt = target;
        if (tgt != NULL && attack_params != NULL && !(tgt->actorFlags & 0x02000800)) {
            dist = calc_xz_distance_sq(this, tgt, &v);
            ang = angle_difference_abs(rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
            body = target->bodies;
            if (body != NULL) {
                radius = body->radius;
            } else {
                radius = 10.0f;
            }
            flags = state_flags;
            if (flags & 8) {
                attack_index = 2;
                if (dist <= (radius + player_object_ptr_array[attack_index]->get_attack_range()) * (radius + player_object_ptr_array[attack_index]->get_attack_range()) && ang <= player_object_ptr_array[attack_index]->get_attack_angle()) {
                    return 1;
                }
            } else if (flags & 0x10) {
                attack_index = 1;
                r = 150.0f + radius;
                if (dist <= r * r && ang <= 0xAAA) {
                    return 1;
                }
            } else {
                attack_index = 0;
                if (dist <= (radius + player_object_ptr_array[attack_index]->get_attack_range()) * (radius + player_object_ptr_array[attack_index]->get_attack_range()) && ang <= player_object_ptr_array[attack_index]->get_attack_angle()) {
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
        VecCopy(&v, &target->body_center);
        subtract_vector(&v, &body_center);
        f32 a = atan2_float(v.x, v.z);
        mode = 4;
        if ((s32)(10430.38043493439 * a) < 0x10) {
            phase = 1;
            requested_action = 2;
            set_override_speed(*saver_ai_params);
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
    bind_enemy_combat_stats(NULL, player_object_ptr_array[attack_index], NULL);
    bodies->flags |= 1;
    actorFlags &= 0xF9FBFFFF;
    actorFlags |= 0x200000;
}

// Hits every player (and, when 0x10 is set in actorFlags, every enemy) the blades reach.
void TObjEneSaver::damage_targets_in_reach() {
    s32 n;
    s32 limit;
    s32 i;
    TObjChara *p;
    if (test_actor_flags(0x10) != 0) {
        limit = 0x4000;
        n = registered_player_count + registered_enemy_count;
    } else {
        n = registered_player_count;
        limit = 0x1000;
    }
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && p != this &&
            p->get_entity_id() < limit && !(p->actorFlags & 0x02000800) &&
            p->select_melee_contact_body(this, 1.0f) != 0) {
            f32 damage = p->receive_physical_attack(this, 1.0f);
            p->apply_knockback_from_attacker((u8 *)this, damage);
        }
    }
}

// Mode 4: the walk-in slash combo (actions 1/2, motion 1 "atack").
void TObjEneSaver::state_attack() {
    bodies->flags |= 1;
    actorFlags &= 0xF9FBFFFF;
    if (targetId < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(targetId);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            target = p;
        } else {
            target = NULL;
        }
    } else if (targetId < 0x4000) {
        target = get_enemy_entity(targetId);
    } else {
        targetId = 0xFFFF;
        target = NULL;
    }
    switch (phase) {
    case 0:
        if (target == NULL) {
            phase = 0;
            actorFlags &= ~0x200000;
            resetTimer = 0;
        } else {
            Vec d;
            s32 a;
            VecCopy(&d, &target->body_center);
            subtract_vector(&d, &body_center);
            a = turn_toward_direction(((SaverMoveParams *)movementParameters)->turn_speed, &d);
            if (!(actorFlags & 0x800000)) {
                apply_actor_gravity(this, NULL, 0.0f);
            }
            if (a < 0x10) {
                phase = 1;
                requested_action = 2;
                set_override_speed(saver_ai_params[0]);
                if (check_path_obstructed(this, &target->body_center) == 1) {
                    velocity.x = velocity.y = velocity.z = 0.0f;
                } else {
                    calc_velocity_toward_destination(this, body_center, target->body_center, ((SaverMoveParams *)movementParameters)->speed);
                }
            }
        }
        break;
    case 1:
        requested_action = 2;
        if (is_passing_frame(12.0f) != 0) {
            phase = 2;
            play_sound_effect(remap_sound_for_area(0x4003A801), &position, 0, 0);
        }
        break;
    case 2:
        requested_action = 2;
        if (is_passing_frame(16.0f) != 0) {
            damage_targets_in_reach();
        }
        if (15.0f <= frame && frame <= 20.0f) {
            apply_lookup_entry_effect();
        }
        if (is_passing_frame(21.0f) != 0) {
            phase = 3;
        }
        break;
    case 3:
        requested_action = 2;
        move_with_wall_slide(this);
        if (is_passing_frame(32.0f) != 0) {
            phase = 4;
            play_sound_effect(remap_sound_for_area(0x4003A801), &position, 0, 0);
        }
        break;
    case 4:
        requested_action = 2;
        if (is_passing_frame(37.0f) != 0) {
            damage_targets_in_reach();
        }
        if (32.0f <= frame && frame <= 40.0f) {
            apply_lookup_entry_effect();
        }
        if (is_passing_frame(42.0f) != 0) {
            phase = 5;
        }
        break;
    case 5:
        requested_action = 2;
        move_with_wall_slide(this);
        if (is_passing_frame(52.0f) != 0) {
            phase = 6;
            play_sound_effect(remap_sound_for_area(0x4003A801), &position, 0, 0);
        }
        break;
    case 6:
        requested_action = 2;
        if (is_passing_frame(54.0f) != 0) {
            damage_targets_in_reach();
        }
        if (52.0f <= frame && frame <= 60.0f) {
            apply_lookup_entry_effect();
        }
        if (action_flags != 4) {
            phase = 7;
            resetTimer = saver_ai_params[1];
        }
        break;
    case 7:
        if (--resetTimer < 0) {
            phase = 0;
            actorFlags &= ~0x200000;
            resetTimer = 0;
        }
        break;
    }
    advance_animation();
    step_angle_clamped(0);
    check_object_collisions();
    check_enemy_body_collisions(this);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}
