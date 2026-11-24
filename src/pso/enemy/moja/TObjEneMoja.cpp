#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeEff.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/memory.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/gibbles/TObjEneGibbles.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/technique/TTecFoie.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecMegid.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D853C.h"

#include "pso/object/base/TObjChara.h"


#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/TObjControl.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"

#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/math/ScratchVectors.h"
#include "pso/network/client_id.h"
#include "pso/render/model_render_state.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/player/TPlyDispData.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
extern "C" {
void TObjPlayer__sub_800ACA0C(void *);
}
extern "C" {
f32 enemy_pursue_point(void *, s32, Vec *, void *, f32, f32);
s32 select_enemy_destination(void *, Vec *, int);
s32 copy_position_if_valid(saddr chara, saddr pos);
void calc_velocity_toward_destination(TObjChara *chara, Vec from, Vec to, f32 speed);
s32 minimap_render_dot(void *, int, int, int, f32);
}

// The Moja's models and motions, and the archive that holds them; the second
// set is the one Ultimate loads.
const char *moja_model_names[] = {
    "bm2c_s_moj_body.nj",
    "bm2f_s_moj_body.nj",
    "bm2w_s_moj_body.nj",
    NULL
};
const char *moja_motion_names[] = {
    "cstand_bm2c_s_moj_body.njm",
    "cwalk_bm2c_s_moj_body.njm",
    "damage_bm2f_s_moj_body.njm",
    "deadb_bm2f_s_moj_body.njm",
    "dead_bm2f_s_moj_body.njm",
    "giva_bm2f_s_moj_body.njm",
    "hoe_bm2f_s_moj_body.njm",
    "jump_bm2f_s_moj_body.njm",
    "punch_bm2f_s_moj_body.njm",
    "stand_bm2f_s_moj_body.njm",
    "walk_bm2f_s_moj_body.njm",
    NULL
};
BmlResourceDescriptor moja_bml_descriptor = { "bm_ene_bm2_moja.bml", moja_model_names, moja_motion_names, 3, 11 };
const char *moja_ultimate_model_names[] = {
    "bm2c_s_moj_body.nj",
    "bm2f_s_moj_body.nj",
    "bm2w_s_moj_body.nj",
    NULL
};
const char *moja_ultimate_motion_names[] = {
    "cstand_bm2c_s_moj_body.njm",
    "cwalk_bm2c_s_moj_body.njm",
    "damage_bm2f_s_moj_body.njm",
    "deadb_bm2f_s_moj_body.njm",
    "dead_bm2f_s_moj_body.njm",
    "giva_bm2f_s_moj_body.njm",
    "hoe_bm2f_s_moj_body.njm",
    "jump_bm2f_s_moj_body.njm",
    "punch_bm2f_s_moj_body.njm",
    "stand_bm2f_s_moj_body.njm",
    "walk_bm2f_s_moj_body.njm",
    NULL
};
BmlResourceDescriptor moja_ultimate_bml_descriptor = { "bm_ene_bm2_moja_a.bml", moja_ultimate_model_names, moja_ultimate_motion_names, 3, 11 };

// The Moja's actions (TObjMotion::action_table).
TObjMotionAction moja_motion_actions[9] = {
    { 1, 0, 9, 0.5f, 0x1 },
    { 2, 2, 6, 0.7f, 0x20 },
    { 1, 0, 10, 0.6f, 0x1 },
    { 2, 0, 8, 0.7f, 0x4 },
    { 2, 0, 5, 0.4f, 0x4 },
    { 2, 0, 7, 0.5f, 0x4 },
    { 2, 0, 2, 0.8f, 0x8 },
    { 3, 7, 4, 0.7f, 0x10 },
    { 3, 7, 3, 0.7f, 0x10 }
};
MojaMovementParameters moja_movement_params[2] = {
    { 250.0f, 0.75f, 0x400, { 0x1E0000, 0, 0, 0 } },
    { 250.0f, 0.75f, 0x400, { 0, 0x1E0000, 0, 0 } }
};
CollisionBody moja_collision_body = { { 0.0f, 20.0f, 0.0f }, 12.5f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f };

const char *TObjEneMoja__name = "TObjEneMoja";

// What load_resources sets up and free_resources releases: the combat stat
// blocks of the two variants, the archive and the punch's sampled trail.
player_stats **moja_boss_stats_handles;
AttackParams **moja_attack_params;
ActorParamBlock **moja_object_handles;
BattleMovementParams **moja_behavior_params;
BmlResource *moja_bml_resource;
SampledMotionPoints *moja_punch_points;

// The collision flags the Moja gets back when it can be hit again.
static const s32 moja_hittable_body_flags = 0x8001;

// The file is compiled -inline off,deferred, which emits the functions in the
// reverse of the order they are written in.
TObjEneMoja::TObjEneMoja(TObject *parent, void *setData) : TObjEnemy(parent) {
    m_name = TObjEneMoja__name;
    apply_set_data(setData);
    init_position_vectors();
    mode = 0;
    phase = 0;
    techniqueChance = 0.3f + parameters[1];
    if (techniqueChance < 0.0f) {
        techniqueChance = 0.0f;
    } else if (1.0f < techniqueChance) {
        techniqueChance = 1.0f;
    }
    jumpChance = 0.6f + parameters[2];
    if (jumpChance < 0.0f) {
        jumpChance = 0.0f;
    } else if (1.0f < jumpChance) {
        jumpChance = 1.0f;
    }
    clamp_stat_354();
    select_rare_variant();
    subtype = 1;
    action_table = moja_motion_actions;
    set_action_table(action_table);
    motion_list = moja_bml_resource->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, &moja_collision_body, 1);
    attack = 0;
    bind_enemy_combat_stats(moja_boss_stats_handles[variant], moja_attack_params[attack + variant * 3],
        moja_object_handles[variant]);
    movementParameters = &moja_movement_params[variant];
    referenceHp = hp;
    update_prev_position();
    copy_position();
    register_object_by_id();
    resetTimer = 0;
    timer = resetTimer;
    unused_37C = 0;
    attackSequence = -1;
    roar = 1;
    add_flags_2e4(1);
    actorFlags |= 0x40000;
    sinkOffset = 0.0f;
    unknown_398 = TAttackTraceStrip::create(0xFF303030, 0x0A303030);
    for (s32 i = 0; i < 4; i++) {
        unknown_39C[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}

TObjEneMoja::~TObjEneMoja() {
    if (unknown_398 != NULL) {
        unknown_398->queue_destruction();
        unknown_398 = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneMoja::load_resources() {
    switch (game_difficulty_selection) {
    case 3: {
        void *memory = new BmlResource(1, &moja_ultimate_bml_descriptor, 0, 0, NULL);
        moja_bml_resource = (BmlResource *)memory;
        break;
    }
    default: {
        void *memory = new BmlResource(1, &moja_bml_descriptor, 0, 0, NULL);
        moja_bml_resource = (BmlResource *)memory;
        break;
    }
    }
    SampledMotionPoints *points = new SampledMotionPoints(2, 9.0f, 16.0f, 0.7f);
    moja_punch_points = points;
    Vec first;
    Vec second;
    first.x = first.y = first.z = 0.0f;
    second.x = -20.0f;
    second.y = 0.0f;
    second.z = 0.0f;
    points->sample_node_offsets(moja_bml_resource->models[1].model,
        (NJS_MOTION *)moja_bml_resource->motions[moja_motion_actions[3].motion].motion, 38, &first, &second);
    moja_boss_stats_handles = static_cast<player_stats **>(mem_alloc(2 * sizeof(*moja_boss_stats_handles)));
    moja_attack_params = static_cast<AttackParams **>(mem_alloc(6 * sizeof(*moja_attack_params)));
    moja_object_handles = static_cast<ActorParamBlock **>(mem_alloc(2 * sizeof(*moja_object_handles)));
    moja_behavior_params = static_cast<BattleMovementParams **>(mem_alloc(2 * sizeof(*moja_behavior_params)));
    moja_boss_stats_handles[0] = TLobby::register_boss(0x49);
    moja_boss_stats_handles[1] = TLobby::register_boss(0x4A);
    moja_attack_params[0] = TLobby::dispatch_shared_handler_b(0x48);
    moja_attack_params[1] = TLobby::dispatch_shared_handler_b(0x49);
    moja_attack_params[2] = TLobby::dispatch_shared_handler_b(0x4A);
    moja_attack_params[3] = TLobby::dispatch_shared_handler_b(0x4B);
    moja_attack_params[4] = TLobby::dispatch_shared_handler_b(0x4C);
    moja_attack_params[5] = TLobby::dispatch_shared_handler_b(0x4D);
    moja_object_handles[0] = TLobby::register_object(0x48);
    moja_object_handles[1] = TLobby::register_object(0x49);
    moja_behavior_params[0] = TLobby::dispatch_shared_handler_a(0x48);
    moja_behavior_params[1] = TLobby::dispatch_shared_handler_a(0x49);
    s16 ids[3] = { 0x32, 0x33, 0x34 };
    NpcAnimationBinding binding = { moja_bml_resource->motions, moja_motion_actions, 0, 2, 9 };
    for (s32 i = 0; i < 3; i++) {
        TObjNpcEnemy::register_animated_chunk(ids[i], moja_bml_resource->models[i].model, moja_bml_resource->models[i].texlist,
            &binding, moja_collision_body.radius, 0.0f);
    }
}

void TObjEneMoja::free_resources() {
    if (moja_boss_stats_handles != NULL) {
        mem_free(moja_boss_stats_handles);
        moja_boss_stats_handles = NULL;
    }
    if (moja_attack_params != NULL) {
        mem_free(moja_attack_params);
        moja_attack_params = NULL;
    }
    if (moja_object_handles != NULL) {
        mem_free(moja_object_handles);
        moja_object_handles = NULL;
    }
    if (moja_behavior_params != NULL) {
        mem_free(moja_behavior_params);
        moja_behavior_params = NULL;
    }
    if (moja_punch_points != NULL) {
        delete moja_punch_points;
        moja_punch_points = NULL;
    }
    if (moja_bml_resource != NULL) {
        delete moja_bml_resource;
        moja_bml_resource = NULL;
    }
}

void *TObjEneMoja::create(void *setData) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneMoja(parent, setData);
}

void TObjEneMoja::run_task() {
    u16 id;
    TObjPlayer *player;
    TObjChara *t;
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjPlayer__sub_800ACA0C(this);
        return;
    }
    id = this->targetId;
    if (id < 0x1000U) {
        player = get_player_by_client_id(id);
        if (player != NULL) {
            if (player->get_floor() == get_current_floor()) {
                this->target = player;
                goto done;
            }
        }
        this->target = NULL;
    done:;
    } else if (id < 0x4000U) {
        this->target = get_enemy_entity(id);
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    {
        switch (this->mode) {
        case 0:
            update_idle_state();
            break;
        case 1:
            update_appearance_jump();
            break;
        case 2:
            update_appearance_drop();
            break;
        case 3:
            update_approach_state();
            break;
        case 4:
            update_punch_attack();
            break;
        case 5:
            update_technique_state();
            break;
        case 6:
            update_attack_jump();
            break;
        case 7:
            update_invincibility();
            break;
        case 8:
            update_ground_effect();
            break;
        case 9:
            update_death_state();
            break;
        }
    }
    update_prev_position();
    copy_position();
    submit_cursor_candidate(this, -1);
    t = this->target;
    if ((t != NULL) && (((TObjChara *)t)->actorFlags & 0x02000800)) {
        this->attackSequence = -1;
        (this->timer) = 0;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
        this->target = NULL;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0, this->frame_timer++);
}

void TObjEneMoja::render() {
    Vec pos;
    RenderFadeState *fade;
    s32 cam;
    s32 vis;
    s32 draw;
    s32 id;
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    vis = this->classify_actor_view_detail(250.0f, 500.0f, 30.0f);
    if (vis == 0) {
        return;
    }
    select_actor_lighting(this);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    id = model_render_flags;
    fade = &unknown_39C[cam];
    saved_model_render_flags = id;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags = id | 1;
    fade->update();
    draw = 1;
    if (fade->updateFromCamera((const f32 *)&position) == 1) {
        fade->set_flags_and_apply_damage_color();
        if (defer_render() != 0) {
            draw = 0;
        } else {
            model_render_flags &= ~1;
        }
    }
    if (draw != 0) {
        set_motion_packed_rotation();
        push_matrix();
        translate_matrix(0, 0.0f, sinkOffset, 0.0f);
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(model);
        } else {
            TObjPlayer::toggle_particle_effect();
            if (vis == 1) {
                this->draw();
            } else {
                draw_motion_model();
            }
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
        clear_motion_packed_rotation();
    }
    model_render_flags &= ~1;
    if (fade->updateFromCamera((const f32 *)&position) == 1) {
        fade->clear_flag_and_notify();
    }
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
    restore_scene_lighting();
    switch (mode) {
    case 0:
    case 1:
    case 9:
        break;
    default:
        pos.x = 2.0f;
        pos.y = 1.0f;
        pos.z = 2.0f;
        draw_ground_shadow(&pos, 0);
        break;
    }
}

// TObjChara's slot 28. Picks the nearest player or enemy it can reach as the
// target (inferred purpose; the slot has no evidenced name).
void TObjEneMoja::refresh_target() {
    u16 best_id;
    s32 i;
    u16 id;
    TObjPlayer *p;
    f32 best;
    f32 d;
    TObjPlayer *q;
    u16 tid;
    if (appearance != 1 && ((mode != 0 && target == NULL) || is_actor_cadence_frame(0x1E) != 0)) {
        if (test_actor_flags(0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec v = { 0.0f, 0.0f, 0.0f };
            best = ((MojaMovementParameters *)movementParameters)->target_range * ((MojaMovementParameters *)movementParameters)->target_range;
            for (; i < registered_player_count + registered_enemy_count; i++) {
                p = TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                id = p->get_entity_id();
                if (id < 0x4000 && id != entity_id && !(p->actorFlags & 0x02000800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy(&v, &p->body_center);
                    subtract_vector(&v, &body_center);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(this, &p->body_center) != 1 && csnVector(&body_center, &p->body_center, -1) == NULL) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            targetId = best_id;
        } else {
            targetId = find_nearest_visible_player(this, NULL, ((MojaMovementParameters *)movementParameters)->target_range);
        }
        tid = targetId;
        if (tid < 0x1000U) {
            q = get_player_by_client_id(tid);
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
            return;
        }
        targetId = 0xFFFFU;
        target = NULL;
    }
}

s32 TObjEneMoja::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
            this->mode = 0;
            this->phase = 0;
            this->roar = 1;
            this->attackSequence = -1;
            (this->timer) = 0;
            this->appearance = 0;
            this->requested_action = 2;
            clear_actor_flags(0x06040000);
            bodies->flags |= 1;
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneMoja::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
            this->mode = 0;
            this->phase = 0;
            this->roar = 1;
            this->attackSequence = -1;
            (this->timer) = 0;
            this->appearance = 0;
            this->requested_action = 2;
            clear_actor_flags(0x06040000);
            bodies->flags |= 1;
            break;
        }
        return 1;
    }
    return 0;
}

void TObjEneMoja::run_idle_action() {
    s32 m;

    m = mode;
    if ((m >= 3) || (m < 0)) {
        phase = 0;
        roar = 1;
        (this->actorFlags) = (s32) ((this->actorFlags) | 0x40000);
    }
    switch (appearance) {
    case 0:
        mode = 0;
        this->requested_action = 2;
        return;
    case 1:
        mode = 1;
        this->requested_action = 5;
        return;
    default:
        mode = 0;
        this->requested_action = 0;
        return;
    }
}

void TObjEneMoja::update_idle_state() {
    switch (phase) {
    case 0:
    default: {
        Vec dest = home_position;
        if (select_enemy_destination(this, &dest, 7) != 0) {
            Vec cur = body_center;
            copy_position_if_valid((saddr)this, (saddr)&cur);
        }
        switch (appearance) {
        case 0:
            phase = 1;
            break;
        }
        break;
    }
    case 1:
        advance_animation();
        enemy_wander_home(((MojaMovementParameters *)movementParameters)->move_speed, 100.0f, 100.0f,
            ((MojaMovementParameters *)movementParameters)->turn_speed);
        break;
    }
    refresh_collision_body_centers();
    clear_actor_flags(0x200000);
}

void TObjEneMoja::update_appearance_jump() {
    Vec off;
    Vec tmp;
    Vec delta;
    f32 ticks;
    f32 dist;
    TObjPlayer *p;
    s32 i;
    actorFlags |= 0x06000000;
    bodies->flags &= ~1;
    advance_animation();
    switch (phase) {
    case 0:
    default:
        off.x = 0.0f;
        off.y = -500.0f;
        off.z = 200.0f;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, rotation_y);
        rotate_vector_by_matrix(0, &off, &off);
        pop_matrices(1);
        VecCopy((Vec *)&tmp, &home_position);
        subtract_vector(&tmp, &off);
        VecCopy(&position, (const Vec *)&tmp);
        if (is_passing_frame(8.0f) == 0) {
            return;
        }
        VecCopy(&move_destination, &home_position);
        VecCopy(&move_origin, &position);
        VecCopy((Vec *)&delta, &move_destination);
        subtract_vector(&delta, &position);
        rotation_y = (s32)(10430.38043493439 * atan2_float(delta.x, delta.z));
        jumpSpeed = newton_sqrtf(delta.x * delta.x + delta.z * delta.z);
        ticks = 12.0f / play_speed;
        jumpSpeed = jumpSpeed / ticks;
        calc_velocity_toward_destination(this, move_origin, move_destination, jumpSpeed);
        velocity.y = delta.y / ticks;
        phase = 1;
        break;
    case 1:
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z;
        if (is_passing_frame(20.0f) == 0) {
            return;
        }
        phase = 2;
        for (i = 0; i < lbl_805D5868; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == NULL) {
                break;
            }
            if ((u16)p->get_entity_id() >= 0x1000) {
                break;
            }
            if (obj_is_hit_receivable(p) != 0) {
                dist = horizontal_distance_squared(&p->body_center, &body_center);
                if (dist <= 2500.0f) {
                    DirectAttackPayload hit;
                    hit.kind = 0;
                    hit.power = 25.0f;
                    f32 damage = p->receive_direct_attack(this, hit, 0, -1, -1);
                    p->apply_knockback_from_attacker((u8 *)this, damage);
                }
                if (dist <= 10000.0f && !is_split_screen() && local_client_id == (u16)p->get_entity_id()) {
                    TCameraCtrl::set_shake_preset(0);
                }
            }
        }
        spawn_particle_effect(&position, 0xCB);
        spawn_particle_effect(&position, 0xF0);
        play_sound_effect(remap_sound_for_area(0x3AD03), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        break;
    case 2:
        apply_actor_gravity(this, 0, 0.0f);
        if (action_flags != 4) {
            actorFlags &= 0xF9DFFFFF;
            bodies->flags |= 1;
            attackSequence = -1;
            timer = 0;
            appearance = 0;
        }
        break;
    }
}

void TObjEneMoja::update_appearance_drop() {
    f32 ticks;
    f32 dist;
    TObjPlayer *p;
    s32 i;
    actorFlags |= 0x06000000;
    bodies->flags &= ~1;
    advance_animation();
    switch (phase) {
    case 0:
    default:
        VecCopy((Vec *)&scratch_vec, &home_position);
        subtract_vector(&scratch_vec, &position);
        rotation_y = approach_angle_limited(rotation_y,
            (s32)(10430.38043493439 * atan2_float(scratch_vec.x, scratch_vec.z)),
            ((MojaMovementParameters *)movementParameters)->turn_speed);
        if (rotation_y >= ((MojaMovementParameters *)movementParameters)->turn_speed) {
            return;
        }
        requested_action = 5;
        if (is_passing_frame(8.0f) == 0) {
            return;
        }
        VecCopy(&move_destination, &home_position);
        VecCopy(&move_origin, &position);
        jumpSpeed = newton_sqrtf(scratch_vec.x * scratch_vec.x + scratch_vec.z * scratch_vec.z);
        ticks = 12.0f / play_speed;
        jumpSpeed = jumpSpeed / ticks;
        calc_velocity_toward_destination(this, move_origin, move_destination, jumpSpeed);
        velocity.y = scratch_vec.y / ticks;
        phase = 1;
        break;
    case 1:
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z;
        if (is_passing_frame(20.0f) == 0) {
            return;
        }
        phase = 2;
        for (i = 0; i < lbl_805D5868; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == NULL) {
                break;
            }
            if ((u16)p->get_entity_id() >= 0x1000) {
                break;
            }
            if (obj_is_hit_receivable(p) != 0) {
                dist = horizontal_distance_squared(&p->body_center, &body_center);
                if (dist <= 2500.0f) {
                    DirectAttackPayload hit;
                    hit.kind = 0;
                    hit.power = 25.0f;
                    f32 damage = p->receive_direct_attack(this, hit, 0, -1, -1);
                    p->apply_knockback_from_attacker((u8 *)this, damage);
                }
                if (dist <= 10000.0f && !is_split_screen() && local_client_id == (u16)p->get_entity_id()) {
                    TCameraCtrl::set_shake_preset(0);
                }
            }
        }
        spawn_particle_effect(&position, 0xCB);
        spawn_particle_effect(&position, 0xF0);
        play_sound_effect(remap_sound_for_area(0x3AD03), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        break;
    case 2:
        apply_actor_gravity(this, 0, 0.0f);
        if (action_flags != 4) {
            actorFlags &= 0xF9DFFFFF;
            bodies->flags |= 1;
            attackSequence = -1;
            timer = 0;
            appearance = 0;
        }
        break;
    }
}

void TObjEneMoja::run_move_action() {
    if ((s16) mode != 3) {
        mode = 3;
        switch ((s32) roar) {
        case 1:
            phase = 0;
            this->requested_action = 1;
            break;
        default:
            phase = 0;
            this->requested_action = 2;
            break;
        }
        attackSequence = -1;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xF9FBFFFF);
        bodies->flags |= 1;
        appearance = 0;
    }
}

void TObjEneMoja::update_approach_state() {
    BattleMovementParams *params;
    TObjChara *t;
    switch (phase) {
    case 0:
        apply_actor_gravity(this, 0, 0.0f);
        if (is_passing_frame(0.0f) != 0) {
            play_sound_effect(remap_sound_for_area(0x3AD0A), &position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (action_flags != 0x20U) {
            set_override_speed(moja_behavior_params[variant]->values.floats[3]);
            requested_action = 2;
            {
            Vec v = target->body_center;
            if (select_enemy_destination(this, &v, 1) != 0) {
                Vec v2 = body_center;
                copy_position_if_valid((saddr)this, (saddr)&v2);
            }
            }
            phase = 1;
            roar = 0;
            timer = 0x96;
        }
        break;
    case 1:
    default:
        t = target;
        if (t != NULL) {
            Vec v3 = t->body_center;
            params = moja_behavior_params[variant];
            if (((MojaMovementParameters *)movementParameters)->target_range * ((MojaMovementParameters *)movementParameters)->target_range < enemy_pursue_point(this, ((MojaMovementParameters *)movementParameters)->turn_speed, &v3, params, params->values.floats[2], 30.0f)) {
                target = NULL;
            }
            if (horizontal_distance_squared(&move_destination, &position) < (((MojaMovementParameters *)movementParameters)->move_speed + bodies->radius) * (((MojaMovementParameters *)movementParameters)->move_speed + bodies->radius)
                || --timer < 0) {
                attackSequence = 0;
            }
        }
        if (is_passing_frame(4.0f) != 0 || is_passing_frame(19.0f) != 0) {
            play_sound_effect(remap_sound_for_area(0x3A801), &position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
        }
        break;
    }
    advance_animation();
    update_collisions();
}

s32 TObjEneMoja::is_target_in_attack_range() {
    s32 angd;
    s32 lim;
    s32 i;
    f32 sq;
    f32 dist;
    f32 radius;
    TObjChara *t;
    CollisionBody *c;
    Vec d;
    if (this->mode > 1 && (t = this->target) != NULL &&
        this->attack_params != NULL && !(t->actorFlags & 0x02000800)) {
        dist = calc_xz_distance_sq(this, t, &d);
        angd = angle_difference_abs(this->rotation_y,
                                    (s32)(10430.38043493439 * atan2_float(d.x, d.z)));
        c = this->target->bodies;
        if (c != NULL) {
            radius = c->radius;
        } else {
            radius = 10.0f;
        }
        for (i = 0; i < 3; i++) {
            this->attack_params = moja_attack_params[i + (this->variant) * 3];
            sq = (radius + this->attack_params->get_attack_range()) *
                 (radius + this->attack_params->get_attack_range());
            lim = this->attack_params->get_attack_angle();
            if (dist <= sq && angd <= lim) {
                this->attack = i;
                switch (this->attack) {
                case 0:
                    if (this->attackSequence == -1) {
                        this->attackSequence = 0;
                    }
                    return 1;
                case 1:
                    if (this->attackSequence != -1 && !(this->techniqueChance < 0.00001f)) {
                        if (random_ratio() < this->techniqueChance) {
                            return 1;
                        }
                        this->attackSequence = -1;
                        {
                            Vec v = body_center;
                            select_enemy_destination(this, &v, 1);
                        }
                        {
                            Vec v2 = body_center;
                            ((s32 (*)(TObjEneMoja *, Vec *))copy_position_if_valid)(this, &v2);
                        }
                    }
                    break;
                case 2:
                    if (this->attackSequence != -1) {
                        if (22500.0f < dist && random_ratio() < this->jumpChance) {
                            return 1;
                        }
                        this->attackSequence = -1;
                        {
                            Vec v = body_center;
                            select_enemy_destination(this, &v, 1);
                        }
                        {
                            Vec v2 = body_center;
                            ((s32 (*)(TObjEneMoja *, Vec *))copy_position_if_valid)(this, &v2);
                        }
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

void TObjEneMoja::run_attack_action() {
    switch (attack) {
    case 2:
        mode = 6;
        requested_action = 5;
        break;
    case 1:
        mode = 5;
        requested_action = 2;
        break;
    case 0:
    default:
        mode = 4;
        requested_action = 3;
        break;
    }
    phase = 0;
    actorFlags |= 0x200000;
    actorFlags &= 0xF9FBFFFF;
    bodies->flags |= 1;
    appearance = 0;
}

void TObjEneMoja::update_punch_attack() {
    Vec trail[2];
    s32 t;
    s32 n;
    s32 i;
    TObjChara *p;
    TAttackTraceStrip *trace;
    Vec *e;
    switch (phase) {
    case 0:
        set_override_speed(moja_behavior_params[variant]->values.floats[0]);
        phase = 1;
    case 1:
        advance_animation();
        if (is_passing_frame(9.0f) != 0) {
            play_sound_effect(remap_sound_for_area(0x3AD04), &position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x300);
        }
        if (is_passing_frame(12.0f) != 0) {
            t = test_actor_flags(0x10);
            n = registered_player_count;
            if (t != 0) {
                n += registered_enemy_count;
            }
            for (i = 0; i < n; i++) {
                p = TObjPlayer::get_player_data(i);
                if (p == NULL || p == this) {
                    break;
                }
                if ((obj_is_hit_receivable(p) != 0) && !(p->actorFlags & 0x02000800) && (p->select_melee_contact_body(this, 1.0f) != 0)) {
                    f32 damage = p->receive_physical_attack(this, 1.0f);
                    p->apply_knockback_from_attacker((u8 *)this, damage);
                    if (0.5f < random_ratio()) {
                        roar = 1;
                    }
                }
            }
        }
        if ((9.0f <= frame) && (frame <= 16.0f)) {
            e = moja_punch_points->lookup(frame);
            if (e != NULL) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&position.x);
                rotate_matrix_y(0, rotation_y);
                matrix_mult_vec_array(NULL, e, trail, 2);
                pop_matrix();
                trace = unknown_398;
                if (trace != NULL) {
                    trace->add_segment(&trail[0], &trail[1]);
                }
            }
        }
        if (action_flags != 4U) {
            attackSequence += 1;
            phase = 2;
            switch (roar) {
            case 1:
                requested_action = 1;
                timer = 0;
                break;
            default:
                requested_action = 0;
                timer = (s16)moja_behavior_params[variant]->values.floats[1];
                break;
            }
        }
        break;
    case 2:
        advance_animation();
        if ((is_passing_frame(0.0f) != 0) && (roar == 1)) {
            play_sound_effect(remap_sound_for_area(0x3AD0A), &position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (action_flags != 0x20U) {
            if ((f32)--timer < 0.0f) {
                timer = 0;
                phase = 1;
                roar = 0;
                targetId = 0xFFFF;
                target = NULL;
                if (attackSequence >= 3) {
                    attackSequence = -1;
                }
                actorFlags &= 0xFFDFFFFF;
            }
        }
        break;
    }
    apply_actor_gravity(this, 0, 0.0f);
    update_collisions();
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TObjEneMoja::update_technique_state() {
    Vec dir;
    Vec pos;
    MojaParticleAngles ang;
    s32 ang2;
    void *obj;
    TObjPlayer *p;
    s32 a;
    u16 id;
    id = targetId;
    if (id < 0x1000) {
        p = get_player_by_client_id(id);
        if (p != NULL && p->get_floor() == get_current_floor() &&
            get_room() == p->get_room()) {
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
    advance_animation();
    switch (phase) {
    case 0:
    default:
        if (target == NULL) {
            phase = 2;
            attackSequence = -1;
            actorFlags &= 0xFFDFFFFF;
        } else {
            Vec dest = target->body_center;
            if (select_enemy_destination(this, &dest, 1) != 0) {
                Vec cur = body_center;
                copy_position_if_valid((saddr)this, (saddr)&cur);
                a = enemy_turn_toward_dest(((MojaMovementParameters *)movementParameters)->turn_speed);
                enemy_set_heading_velocity(((MojaMovementParameters *)movementParameters)->move_speed, this, rotation_y);
                move_with_wall_slide(this);
            } else {
                VecCopy((Vec *)&dir, (const Vec *)&target->body_center);
                subtract_vector(&dir, &body_center);
                a = turn_toward_direction(((MojaMovementParameters *)movementParameters)->turn_speed, (Vec *)&dir);
            }
            if (a < 0x100) {
                phase = 1;
                requested_action = 4;
            } else {
                requested_action = 2;
            }
        }
        break;
    case 1:
        if (is_passing_frame(22.0f) != 0) {
            pos.x = 0.0f;
            pos.y = 3.0f;
            pos.z = 17.0f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, rotation_y);
            rotate_vector_by_matrix(0, &pos, &pos);
            pop_matrices(1);
            vec3_add_to(&pos, &body_center);
            if (target != NULL) {
                VecCopy((Vec *)&dir, (const Vec *)&target->body_center);
                subtract_vector(&dir, &body_center);
                ang2 = turn_toward_direction(((MojaMovementParameters *)movementParameters)->turn_speed, (Vec *)&dir);
            } else {
                ang2 = attack_params->get_attack_angle();
            }
            if (game_difficulty_selection == 3) {
                switch (variant) {
                case 1:
                    if (ang2 < attack_params->get_attack_angle() / 2 && target != NULL) {
                        TTecMegid::create((saddr)this, (saddr)&pos, (saddr)&target->body_center, calc_technique_level());
                    } else {
                        TTecMegid::create_ex((saddr)this, (saddr)&pos, rotation_y, calc_technique_level());
                    }
                    play_sound_effect(0x4002A60B, &pos, 0, 0);
                    break;
                default:
                    spawn_particle_effect(&pos, 0xB9);
                    spawn_particle_effect(&pos, 0xBA);
                    if (ang2 < attack_params->get_attack_angle() / 2) {
                        if (normalize_vector_safe(&dir) < 0.00001f) {
                            dir.y = dir.x = 0.0f;
                            dir.z = 1.0f;
                            push_matrix_from(identity_matrix);
                            rotate_matrix_y(0, rotation_y);
                            rotate_vector_by_matrix(0, &dir, &dir);
                            pop_matrix();
                        }
                        if (target != NULL) {
                            DirectAttackPayload hit;
                            hit.kind = 3;
                            hit.power = 20.0f * (f32) calc_technique_level() + 240.0f;
                            target->receive_direct_attack(this, hit, 0, -1, -1);
                        }
                    } else {
                        dir.y = dir.x = 0.0f;
                        dir.z = 1.0f;
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, rotation_y);
                        rotate_vector_by_matrix(0, &dir, &dir);
                        pop_matrix();
                    }
                    new TTecZondeEff(tl_07, &pos, &dir, 0x14000000, 20, (f32)(attack_params->get_attack_range()), 1.8f);
                    play_sound_effect(0x4002A408, &pos, 0, 0);
                    break;
                }
            } else {
                switch (variant) {
                case 1:
                    TTecGiBarta::create_ex(this, &pos, rotation_y, calc_technique_level());
                    break;
                default:
                    if (ang2 < attack_params->get_attack_angle() / 2 && target != NULL) {
                        TTecFoie::create_ex(this, &pos, &target->body_center, calc_technique_level());
                    } else {
                        TTecFoie::create(this, &pos, rotation_y, calc_technique_level());
                    }
                    break;
                }
                dir.y = dir.x = 0.0f;
                dir.z = 1.0f;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, rotation_y);
                rotate_vector_by_matrix(0, &dir, &dir);
                pop_matrices(1);
                {
                    f32 xx = dir.x * dir.x;
                    f32 yy = dir.y * dir.y;
                    ang.x = (s32) (10430.38043493439 * atan2_float(dir.z, newton_sqrtf(xx + yy)));
                }
                ang.y = 0;
                ang.z = -(s32) (10430.38043493439 * atan2_float(dir.x, dir.y));
                spawn_directional_particle(&pos, &ang, 0xCC);
                play_sound_effect(remap_sound_for_area(0x3E405), &pos, 0, 0);
            }
        }
        if (action_flags != 4) {
            phase = 2;
            timer = 30;
        }
        break;
    case 2:
        attackSequence++;
        if (attackSequence >= 2) {
            attackSequence = -1;
            actorFlags &= 0xFFDFFFFF;
        } else {
            phase = 0;
            timer = 0;
        }
        break;
    }
    apply_actor_gravity(this, (s32 *)(0), 0.0f);
    update_collisions();
}
#pragma pop

void TObjEneMoja::update_attack_jump() {
    Vec delta;
    TObjPlayer *p;
    s32 i;
    f32 d;

    actorFlags |= 0x06000000;
    bodies->flags &= ~1;
    advance_animation();
    switch (phase) {
    case 0:
    default:
        apply_actor_gravity(this, 0, 0.0f);
        if (is_passing_frame(8.0f) != 0) {
            if (target != NULL) {
                Vec dest = target->body_center;
                if (select_enemy_destination(this, &dest, 1) != 0) {
                    Vec pos = body_center;
                    copy_position_if_valid((saddr)this, (saddr)&pos);
                    VecCopy(&delta, &move_destination);
                    subtract_vector(&delta, &body_center);
                    jumpSpeed = -20.0f + newton_sqrtf(delta.x * delta.x + delta.z * delta.z);
                    jumpSpeed = jumpSpeed / (12.0f / play_speed);
                    phase = 1;
                } else {
                    phase = 2;
                }
            } else {
                phase = 2;
            }
            spawn_particle_effect(&position, 0xF3);
            play_sound_effect(remap_sound_for_area(0x3A802), &position, 0, 0);
        }
        break;
    case 1:
        calc_velocity_toward_destination(this, move_origin, move_destination, jumpSpeed);
        move_with_wall_slide(this);
        if (is_passing_frame(20.0f) != 0) {
            phase = 2;
            for (i = 0; i < lbl_805D5868; i++) {
                p = TObjPlayer::get_player_data(i);
                if (p == NULL || (u16)p->get_entity_id() >= 0x1000) {
                    break;
                }
                if (obj_is_hit_receivable(p) != 0) {
                    d = horizontal_distance_squared(&p->body_center, &body_center);
                    if (d <= attack_params->get_damage_radius() * attack_params->get_damage_radius()) {
                        DirectAttackPayload hit;
                        hit.kind = 0;
                        hit.power = get_attack_params_atp_min(attack_params);
                        f32 damage = p->receive_direct_attack(this, hit, 0, -1, -1);
                        p->apply_knockback_from_attacker((u8 *)this, damage);
                    }
                    if (d <= 10000.0f && is_split_screen() == 0 && local_client_id == (u16)p->get_entity_id()) {
                        TCameraCtrl::set_shake_preset(0);
                    }
                }
            }
            spawn_particle_effect(&position, 0xCB);
            spawn_particle_effect(&position, 0xF0);
            play_sound_effect(remap_sound_for_area(0x3AD03), &position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x300);
        }
        break;
    case 2:
        apply_actor_gravity(this, 0, 0.0f);
        if (action_flags != 4) {
            actorFlags &= ~0x06200000;
            bodies->flags |= 1;
            attackSequence = -1;
            timer = 0;
        }
        break;
    }
}

void TObjEneMoja::run_miss_reaction() {

    switch (mode) {
    case 4:
        (this->actorFlags) &= 0xFFFFFEFF;
        ((this->bodies))->flags |= moja_hittable_body_flags;
        referenceHp = (s16) hp;
        roar = 0;
        break;
    default:
        mode = 7;
        (this->timer) = 0xF;
    case 7:
        this->requested_action = 0;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFF9BFFFF);
        break;
    }
    appearance = 0;
}

void TObjEneMoja::update_invincibility() {
    s16 t;

    advance_animation();
    if (!(actorFlags & 0x800000)) {
        apply_actor_gravity(this, 0, 0.0f);
    }
    update_collisions();
    t = timer;
    timer = t - 1;
    if (t < 0) {
        actorFlags &= 0xFFFFFEFF;
        bodies->flags |= moja_hittable_body_flags;
        timer = resetTimer;
        referenceHp = hp;
    }
}

void TObjEneMoja::run_hit_reaction() {
    switch (mode) {
    case 4:
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xF9FFF9FF);
        bodies->flags &= 0xFBFFFFFF;
        referenceHp = (s16) hp;
        roar = 0;
        break;
    default:
        mode = 8;
    case 8:
        this->requested_action = 6;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDBFFFF);
        break;
    }
    appearance = 0;
}

void TObjEneMoja::update_ground_effect() {
    advance_animation();
    if (is_passing_frame(0.0f) != 0) {
        play_sound_effect(remap_sound_for_area(0x3A807), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
    }
    velocity.z = 0.0f;
    velocity.x = 0.0f;
    apply_actor_gravity(this, 0, 0.0f);
    update_collisions();
    if (action_flags != 8U) {
        actorFlags &= 0xFBFFF9FF;
        bodies->flags &= 0xFBFFFFFF;
        referenceHp = hp;
        roar = 0;
    }
}

void TObjEneMoja::run_death_reaction() {
    if ((s16) this->mode != 9) {
        this->mode = 9;
        this->requested_action = 7;
        bodies->flags &= 0xFFFF7FFE;
        spawn_particle_effect(&body_center, 0xF1);
        refresh_lobby_state();
        send_entity_set_flags();
        this->appearance = 0;
    }
}

void TObjEneMoja::update_death_state() {
    Vec v;

    advance_animation();
    if (is_passing_frame(0.0f) != 0) {
        play_sound_effect(remap_sound_for_area(0x3A809), &position, 0, 0);
    }
    if (is_passing_frame(27.0f) != 0) {
        v.x = 0.0f;
        v.y = 10.0f;
        v.z = 0.5f * this->stat_block->proportions;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, this->rotation_y);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        vec3_add_to(&v, &position);
        play_sound_effect(remap_sound_for_area(0x3AD03), &v, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        spawn_particle_effect(&v, 0xF0);
        spawn_dead_spot_scale15(&v, 0x14);
        spawn_effect_at_ground(&v, 0x32);
    }
    if (this->frame < 0.5f * (30.0f * this->play_speed)) {
        move_with_wall_slide(this);
        velocity.x *= 0.5f;
        this->velocity.z *= 0.5f;
    } else if (!((this->actorFlags) & 0x800000)) {
        apply_actor_gravity(this, 0, 0.0f);
    }
    this->sinkOffset -= 0.1f;
    if (this->sinkOffset < -20.0f) {
        queue_destruction();
    }
}

void TObjEneMoja::select_rare_variant() {
    s32 v;
    v = variant;
    if (v >= 1) {
        variant = 1;
        set_param(2);
        bindModel(2);
        return;
    }
    if (v <= 0) {
        if (random_ratio() < 0.002f) {
            variant = 1;
            set_param(2);
            bindModel(2);
            return;
        }
        variant = 0;
        set_param(1);
        bindModel(1);
    }
}

void TObjEneMoja::clamp_stat_354() {
    f32 lo = 0.0f;
    if (parameters[0] < lo) {
        parameters[0] = lo;
    } else if (1.0f < parameters[0]) {
        parameters[0] = 1.0f;
    }
    appearance = (s32)parameters[0];
}
