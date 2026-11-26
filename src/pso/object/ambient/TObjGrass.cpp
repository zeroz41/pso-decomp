#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/HitEligibility.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include "pso/object/ambient/TObjCGrass.h"
#include "pso/system/AreaSound.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"
#include "pso/object/ambient/TObjGrassWeb.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/text_803D853C.h"

#include "pso/object/ambient/TObjGrass.h"
#include "pso/render/TObjEnemyColorFade.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixVector.h"
#include "pso/network/TProtocol.h"
#include "pso/math/ScratchVectors.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/MatrixOps.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/render_util.h"
#include "pso/network/client_id.h"
#include "pso/render/model_render_state.h"
#include "pso/object/TDeadSpot.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/ui/TLevelSelect.h"

saddr lbl_805D5140;
AttackParams **grass_bml_resource;  // the three attack parameter sets (inferred: not a BML resource)
saddr grass_combat_stats_handle;
saddr lbl_805D514C;
s32 grass_render_node_index;
BmlResource *grass_resource_bundle;
SampledMotionPoints *lbl_805D5158;
SampledMotionPoints *lbl_805D515C;

#pragma readonly_strings on

typedef struct GrassRange {
    f32 lo;
    f32 hi;
} GrassRange;

// The movement table row the enemy's movementParameters points at.
struct GrassMoveParams { f32 radius; f32 speed; s32 turn; };

struct E1C_800BF924 { u8 pad[0x1C]; };

struct E2C_800BF924 { u8 pad[0x2C]; };

extern "C" {
f32 step_toward_destination(void *, Vec, f32);
f32 enemy_move_toward(void *, s32, void *, s32, f32);
void enemy_pursue_point(void *, s32, void *, f32, f32);
}
extern "C" {
s32 select_enemy_destination(void *, Vec, int);
s32 copy_position_if_valid(void *, Vec);
s32 init_collision_body_parts(void *, void *, int);

extern const char *bm_ene_grass_model_names[2];
extern const char *bm_ene_grass_motion_names[9];
__declspec(section ".data") const char *bm_ene_grass_model_names[2] = {
    "re1_b_grass_base.nj", NULL,
};
const char *bm_ene_grass_motion_names[9] = {
    "damege_re1_b_base.njm", "die_re1_b_base.njm", "lattack_re1_b_base.njm", "mad_re1_b_base.njm",
    "rattack_re1_b_base.njm", "spit_re1_b_base.njm", "wait_re1_b_base.njm", "walk_re1_b_base.njm",
    NULL,
};
BmlResourceDescriptor bm_ene_grass_resource_descriptor = {
    "bm_ene_grass.bml", bm_ene_grass_model_names, bm_ene_grass_motion_names, 1, 8,
};
TObjMotionAction grass_grass_type_param_table[8] = {
    {1, 0, 6, 0.7f, 1},
    {1, 1, 7, 1.3f, 1},
    {2, 0, 2, 0.7f, 4},
    {2, 0, 4, 0.7f, 4},
    {2, 0, 5, 0.7f, 4},
    {2, 0, 0, 0.6f, 8},
    {3, 5, 1, 0.4f, 0x10},
    {2, 1, 3, 0.5f, 0x20},
};
void *lbl_804929E4[7] = {
    (void *)0x43c80000, (void *)0x3f400000, (void *)0x100, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *lbl_80492A00[11] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
const char *grass_class_name = "TObjGrass";
const NpcAnimationBinding grass_spawn_descriptor = {NULL, grass_grass_type_param_table, 0, 1, 8};
const Vec lbl_8043B790 = {0.0f, 0.0f, 0.0f};
const char *grass_web_class_name = "TObjGrassWeb";
#pragma fp_contract on

Vec grass_camera_vec;
Vec grass_render_vec;
Vec grass_origin_vec;
}
extern "C" {

void TObjGrass::init_from_table_entry(s32 i) {
    model = grass_resource_bundle->models[i].model;
    texlist = grass_resource_bundle->models[i].texlist;
}
void TObjGrass::clear_hit_targets() {
    s32 i;
    for (i = 0; i < 12; i++) {
        hit_targets[i] = NULL;
    }
}

TObjGrass::TObjGrass(TObject *parent, void *set_data) : TObjEnemy(parent) {
    s32 t;
    m_name = grass_class_name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_actor_gravity(this, 0, (0.0f));
    t = (saddr)grass_resource_bundle->motions;
    *(saddr *)&motion_list = t;
    scale.y = (1.3f);
    variant = 0;
    ((TObjEnemy *)this)->set_param(0xC);
    resetTimer = 0x1E;
    timer = resetTimer;
    subtype = 0;
    init_from_table_entry(variant);
    action_table = grass_grass_type_param_table;
    set_action_table(action_table);
    if ((0.0f) < parameters[1]) {
        move_mode = 2;
    } else {
        move_mode = 1;
    }
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, &((E2C_800BF924 *)lbl_80492A00)[variant], 1);
    attack_kind = 0;
    bind_enemy_combat_stats(reinterpret_cast<player_stats *>(lbl_805D5140), reinterpret_cast<AttackParams *>(grass_bml_resource[attack_kind]), reinterpret_cast<ActorParamBlock *>(grass_combat_stats_handle));
    movementParameters = &((E1C_800BF924 *)lbl_804929E4)[variant];
    referenceHp = hp;
    update_prev_position();
    copy_position();
    register_object_by_id();
    charge_distance = (0.0f);
    mode = 0;
    phase = 0;
    particle_timer = 0;
    clear_hit_targets();
    add_flags_2e4(2);
    set_actor_flags(0x04040000);
    fade.reset_obstruction_fade();
    fading_in = 1;
    savers[0] = TAttackTraceStrip::create(0xA0303030, 0xFFFF0088);
    savers[1] = TAttackTraceStrip::create(0xA0303030, 0xFFFF0088);
    view_detail = 0;
    clear_lobby_object_state();
}

TObjGrass::~TObjGrass() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (savers[i] != NULL) {
            savers[i]->queue_destruction();
            savers[i] = NULL;
        }
    }
    free_collision_body_parts(this);
}

void TObjGrass::load_resources() {
    BmlResource *p;
    if (TObjEneDD::check_v2_mode() != 0) {
        grass_resource_bundle = load_enemy_bml_resource_named(&bm_ene_grass_resource_descriptor, "bm_ene_grass_a.bml");
    } else {
        p = new BmlResource(1, &bm_ene_grass_resource_descriptor, 0, 0, NULL);
        grass_resource_bundle = p;
    }
    grass_render_node_index = 0;
    grass_origin_vec.x = grass_origin_vec.y = grass_origin_vec.z = (0.0f);
    lbl_805D5158 = new SampledMotionPoints(2, (0.0f), (2e+01f), (0.7f));
    lbl_805D515C = new SampledMotionPoints(2, (0.0f), (2e+01f), (0.7f));
    lbl_805D5158->sample_two_nodes((NJS_OBJECT *)grass_resource_bundle->models[0].model,
        (NJS_MOTION *)grass_resource_bundle->motions[grass_grass_type_param_table[2].motion].motion, 0x46, 0x48);
    lbl_805D515C->sample_two_nodes((NJS_OBJECT *)grass_resource_bundle->models[0].model,
        (NJS_MOTION *)grass_resource_bundle->motions[grass_grass_type_param_table[3].motion].motion, 0x3C, 0x3E);
    grass_bml_resource = (AttackParams **)mem_alloc(0xC);
    lbl_805D5140 = (saddr)TLobby::register_boss(0x4E);
    grass_bml_resource[0] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x51);
    grass_bml_resource[2] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x52);
    grass_bml_resource[1] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x53);
    grass_combat_stats_handle = (saddr)TLobby::register_object(0x4D);
    lbl_805D514C = (saddr)TLobby::dispatch_shared_handler_a(0x4D);
    {
        NpcAnimationBinding binding = grass_spawn_descriptor;
        binding.motions = grass_resource_bundle->motions;
        TObjNpcEnemy::register_animated_chunk(0x35, grass_resource_bundle->models[0].model,
            grass_resource_bundle->models[0].texlist, &binding, 10.0f, 0.0f);
    }
}

void TObjGrass::destroy_all() {
    if (grass_bml_resource != NULL) {
        mem_free(grass_bml_resource);
        grass_bml_resource = NULL;
    }
    if (lbl_805D515C != NULL) {
        delete lbl_805D515C;
        lbl_805D515C = NULL;
    }
    if (lbl_805D5158 != NULL) {
        delete lbl_805D5158;
        lbl_805D5158 = NULL;
    }
    if (grass_resource_bundle != NULL) {
        delete grass_resource_bundle;
        grass_resource_bundle = NULL;
    }
}

void *TObjGrass::create(void *set_data) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjGrass(parent, set_data);
}

void TObjGrass::run_task() {
    s16 mode;
    u16 client;
    TObjPlayer *player;
    TObjChara *target;
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_800BCA2C();
        return;
    }
    client = this->targetId;
    if (client < 0x1000U) {
        player = get_player_by_client_id(client);
        if (player != NULL) {
            if (player->get_floor() == get_current_floor()) {
                this->target = player;
                goto done;
            }
        }
        this->target = NULL;
    done:;
    } else if (client < 0x4000U) {
        this->target = get_enemy_entity(client);
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    mode = this->mode;
    {
        switch (this->mode) {
        case 0:
            update_ai();
            break;
        case 1:
            this->sub_800BE75C();
            break;
        case 2:
            update_chase_target();
            break;
        case 3:
            this->sub_800BDD70();
            break;
        case 4:
            this->sub_800BD4D8();
            break;
        case 5:
            update_web_attack();
            break;
        case 6:
            update();
            break;
        case 7:
            this->sub_800BCE44();
            break;
        case 8:
            update_dying();
            break;
        case 9:
            break;
        }
    }
    target = this->target;
    if ((target != NULL) && (target->actorFlags & 0x02000800)) {
        this->timer = 0;
        this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
        this->target = NULL;
    }
    this->update_prev_position();
    this->copy_position();
    submit_cursor_candidate((u8 *)this, -1);
    this->frame_timer += (1.0f);
}

void TObjGrass::render() {
    if (actorFlags & 0x02000000) {
        return;
    }
    view_detail = classify_actor_view_detail((2.5e+02f), (5e+02f), (4e+01f));
    if (view_detail == 0) {
        return;
    }
    select_actor_lighting(this);
    TObjFish::set_global_param(texlist);
    push_matrix();
    translate_matrix(0, (0.0f), parameters[2], (0.0f));
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, rotation_y);
    scale_matrix(0, (1.3f), scale.y, (1.3f));
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(model);
    } else {
        toggle_particle_effect();
        grass_render_node_index = 0;
        set_chunk_model_node_callback(TObjGrass::update_camera_vec_by_stage);
        if (fading_in == 1) {
            if (fade.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                fade.set_flags_and_apply_damage_color();
                if (defer_render() == 0) {
                    draw();
                }
                fade.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else {
            model_render_flags |= 0x01000000;
            if (view_detail == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            model_render_flags &= 0xFEFFFFFF;
        }
        TParticleCtrl::end_effect_render();
    }
    set_chunk_model_node_callback(NULL);
    pop_matrix();
    restore_scene_lighting();
    VecCopy(&camera_vec, &grass_camera_vec);
    VecCopy(&render_vec, &grass_render_vec);
    VecCopy(&origin_vec, &grass_origin_vec);
    switch (mode) {
    case 0:
    case 1:
    case 8:
    case 9:
        break;
    default: {
        Vec v;
        v.x = (1.0f);
        v.y = (1.0f);
        v.z = (4.0f);
        draw_ground_shadow(&v, 0);
        break;
    }
    }
}

void TObjGrass::refresh_target() {
    u16 best_id;
    s32 i;
    u16 id;
    TObjPlayer *p;
    f32 best;
    f32 d;
    TObjPlayer *q;
    u16 tid;
    if (this->is_actor_cadence_frame(0x1E) != 0) {
        if (this->fading_in == 1) {
            this->targetId = 0xFFFFU;
            this->target = NULL;
            return;
        }
        if (this->test_actor_flags(0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec v = lbl_8043B790;
            best = *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0) * *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0);
            for (; i < registered_player_count + registered_enemy_count; i++) {
                p = TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                id = p->get_entity_id();
                if (id < 0x4000 && id != this->entity_id && !(p->actorFlags & 0x02000800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy(&v, &p->body_center);
                    subtract_vector(&v, &this->body_center);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(this, &p->body_center) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            this->targetId = best_id;
        } else {
            this->targetId = find_nearest_visible_player(this, NULL, *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0));
        }
        tid = this->targetId;
        if (tid < 0x1000U) {
            q = get_player_by_client_id(tid);
            if (q != NULL) {
                if (q->get_floor() == get_current_floor()) {
                    this->target = q;
                    this->clear_actor_flags(0x04040000);
                    return;
                }
            }
            this->target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            this->target = get_enemy_entity(tid);
            this->clear_actor_flags(0x04040000);
        }
    }
}

s32 TObjGrass::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        switch (this->mode) {
        case 0:
            this->fading_in = 0;
            this->phase = 2;
            this->requested_action = 1;
            clear_actor_flags((u32)(0x04040000));
        }
        return 1;
    }
    return 0;
}

s32 TObjGrass::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        switch (this->mode) {
        case 0:
            this->fading_in = 0;
            this->phase = 2;
            this->requested_action = 1;
            clear_actor_flags((u32)(0x04040000));
        }
        return 1;
    }
    return 0;
}

void TObjGrass::run_idle_action() {
    switch (this->mode) {
    case 0:
        switch (this->phase) {
        case 0:
        case 1:
            break;
        default:
            this->phase = 2;
        case 2:
            if (this->fading_in != 0) {
                this->phase = 0;
            }
            break;
        }
        break;
    default:
        this->mode = 0;
        if (this->fading_in != 0) {
            this->phase = 0;
        } else {
            this->phase = 2;
        }
        this->requested_action = 1;
        break;
    }
}

#pragma push
#pragma opt_common_subs off
void TObjGrass::update_ai() {
    advance_animation();
    switch (phase) {
    case 0:
        set_actor_flags(0x04040000);
        fade.start_fade_in();
        play_area_sound_effect(&position);
        phase = 1;
        break;
    case 1:
        set_actor_flags(0x04040000);
        if (fade.advance_toward_max() == 1) {
            phase = 2;
            requested_action = 1;
            fading_in = 0;
        }
        break;
    default:
        phase = 2;
    case 2:
        clear_actor_flags(0x04040000);
        switch (move_mode) {
        case 1:
            requested_action = 1;
            if ((1e+04f) < horizontal_distance_squared(&position, &home_position)) {
                Vec *d;
                Vec *v;
                s32 ang;
                VecCopy(&move_destination, &home_position);
                VecCopy(&move_origin, &body_center);
                VecCopy(&prev_position, &position);
                VecCopy(&scratch_vec, &home_position);
                subtract_vector(&scratch_vec, &position);
                d = &scratch_vec;
                ang = (s32)((10430.38043493439) * atan2_float(d->x, d->z));
                v = &scratch_vec2;
                v->x = v->y = (0.0f);
                v->z = ((GrassMoveParams *)movementParameters)->speed;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &scratch_vec2, &scratch_vec2);
                pop_matrices(1);
                vec3_add_to(&scratch_vec2, &position);
                if (project_actor_to_ground(this, &scratch_vec2, NULL) == 1) {
                    requested_action = 1;
                    VecCopy(&position, &scratch_vec2);
                    rotation_y = approach_angle_limited(rotation_y, ang, ((GrassMoveParams *)movementParameters)->turn);
                } else {
                    f32 r = fabs_float(d->z);
                    if (fabs_float(scratch_vec.x) < r) {
                        ang = (s32)((10430.38043493439) * atan2_float(scratch_vec.x, (0.0f)));
                    } else {
                        ang = (s32)((10430.38043493439) * atan2_float((0.0f), d->z));
                    }
                    v->y = (0.0f);
                    scratch_vec2.x = (0.0f);
                    v->z = ((GrassMoveParams *)movementParameters)->speed;
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, ang);
                    rotate_vector_by_matrix(0, &scratch_vec2, &scratch_vec2);
                    pop_matrices(1);
                    vec3_add_to(&scratch_vec2, &position);
                    if (project_actor_to_ground(this, &scratch_vec2, NULL) == 1) {
                        requested_action = 1;
                        VecCopy(&position, &scratch_vec2);
                        rotation_y = approach_angle_limited(rotation_y, ang, ((GrassMoveParams *)movementParameters)->turn);
                    } else {
                        s32 ang2;
                        r = fabs_float(d->z);
                        if (fabs_float(scratch_vec.x) < r) {
                            ang2 = (s32)((10430.38043493439) * atan2_float((0.0f), d->z));
                        } else {
                            ang2 = (s32)((10430.38043493439) * atan2_float(scratch_vec.x, (0.0f)));
                        }
                        v->y = (0.0f);
                        scratch_vec2.x = (0.0f);
                        v->z = ((GrassMoveParams *)movementParameters)->speed;
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, ang2);
                        rotate_vector_by_matrix(0, &scratch_vec2, &scratch_vec2);
                        pop_matrices(1);
                        vec3_add_to(&scratch_vec2, &position);
                        if (project_actor_to_ground(this, &scratch_vec2, NULL) == 1) {
                            requested_action = 1;
                            VecCopy(&position, &scratch_vec2);
                            rotation_y = approach_angle_limited(rotation_y, ang2, ((GrassMoveParams *)movementParameters)->turn);
                        } else {
                            requested_action = 1;
                        }
                    }
                }
                enemy_turn_toward_dest(((GrassMoveParams *)movementParameters)->turn);
                enemy_set_heading_velocity(((GrassMoveParams *)movementParameters)->speed, this, rotation_y);
                move_with_wall_slide(this);
            } else {
                enemy_wander_home((0.25f) * ((GrassMoveParams *)movementParameters)->speed, (1e+02f), (5e+01f), ((GrassMoveParams *)movementParameters)->turn);
            }
            refresh_collision_body_centers();
            break;
        default:
            requested_action = 0;
            if (!(actorFlags & 0x800000)) {
                apply_actor_gravity(this, (s32 *)(0), (0.0f));
            }
            break;
        }
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    clear_actor_flags(0x200000);
}
#pragma pop

void TObjGrass::run_move_action() {
    s16 mode;

    mode = this->mode;
    if ((mode >= 3) || (mode < 1)) {
        this->requested_action = 1;
        if ((s16) this->move_mode == 2) {
            this->mode = 1;
        } else {
            this->mode = 2;
        }
        this->phase = 0;
        clear_actor_flags((u32)(0x04040000));
    }
}

void TObjGrass::sub_800BE75C() {
    Vec v;
    f32 d;
    f32 lo2;
    f32 hi2;
    set_actor_flags(0x04040000);
    advance_animation();
    v.y = (0.0f);
    v.x = (0.0f);
    v.z = parameters[1];
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, rotation_y);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrices(1);
    vec3_add_to(&v, &home_position);
    d = step_toward_destination(this, v, (2.0f) * ((GrassRange *)movementParameters)->hi);
    lo2 = ((GrassRange *)movementParameters)->lo * ((GrassRange *)movementParameters)->lo;
    hi2 = ((GrassRange *)movementParameters)->hi * ((GrassRange *)movementParameters)->hi;
    if (lo2 < d || d < hi2) {
        target = NULL;
        move_mode = 0;
    }
    apply_actor_gravity(this, (s32 *)(0), (0.0f));
    play_persistent_sound(remap_sound_for_area(0x4003A801), this, &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjGrass::update_chase_target() {
    f32 speed;
    f32 dist;
    s32 turn;
    GrassMoveParams *prm;
    clear_actor_flags(0x04040000);
    prm = (GrassMoveParams *)movementParameters;
    speed = prm->speed;
    turn = prm->turn;
    if (actorFlags & 0x2000) {
        speed *= (2.0f);
        play_speed = (2.0f) * action_table[requested_action].speed;
        { f32 ft = (f32)turn; ft *= (2.0f); turn = (s32)ft; }
        play_persistent_sound(remap_sound_for_area(0x4003A300), this, &position, 0, 0);
    } else {
        play_persistent_sound(remap_sound_for_area(0x4003A801), this, &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
    }
    advance_animation();
    if (target != NULL) {
        switch (phase) {
        default:
            phase = 0;
        case 0: {
            Vec v;
            Vec t = target->body_center;
            dist = enemy_move_toward(this, turn, &t, 0, (0.125f) * speed);
            VecCopy(&v, &target->body_center);
            subtract_vector(&v, &body_center);
            turn = angle_difference_abs(rotation_y, (s32)((10430.38043493439) * atan2_float(v.x, v.z)));
            if (turn < attack_params->get_attack_angle()) {
                phase = 1;
            }
            break;
        }
        case 1: {
            Vec t = target->body_center;
            f32 r;
            enemy_pursue_point(this, turn, &t, speed, (4e+01f));
            dist = horizontal_distance_squared(&move_destination, &body_center);
            r = speed + bodies->radius;
            if (dist < r * r) {
                if (targetId == 0xFFFF) {
                    target = NULL;
                } else {
                    phase = 0;
                }
            }
            break;
        }
        }
        if (((GrassMoveParams *)movementParameters)->radius * ((GrassMoveParams *)movementParameters)->radius < dist) {
            target = NULL;
        }
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

#define TBL grass_bml_resource
#define T318 attack_params
#define IN_RANGE() (dist <= (r + T318->get_attack_range()) * (r + T318->get_attack_range()) && ang <= T318->get_attack_angle())
#define BIND(n) attack_kind = (n); bind_enemy_combat_stats(NULL, TBL[attack_kind], NULL); return 1;

s32 TObjGrass::is_target_in_attack_range() {
    f32 dist;
    TObjChara *t;
    s32 ang;
    f32 r;
    TObjChara *tgt;
    s32 i;
    u16 kind;
    Vec v;

    tgt = this->target;
    if (tgt != NULL && T318 != NULL && !(tgt->actorFlags & 0x02000800)) {
    if (test_actor_flags(0x2000) != 0) {
        BIND(2)
    }
    dist = calc_xz_distance_sq(this, target, &v);
    ang = angle_difference_abs(this->rotation_y, (s32)((10430.38043493439) * atan2_float(v.x, v.z)));
    t = this->target;
    if (t->bodies != NULL) {
        r = t->bodies->radius;
    } else {
        r = (1e+01f);
    }
    kind = ((TObjBase *)(t))->get_entity_id();
    if (kind < 0x1000) {
        t = this->target;
        if (((TObjPlayer *)t)->check_player_flag1() == 1 || (enable_v2_features == 1 && t->test_actor_flags(0x20) != 0)) {
            T318 = TBL[0];
            if (IN_RANGE()) {
                BIND(0)
            }
            return 0;
        }
        for (i = 0; i < 2; i++) {
            T318 = TBL[i];
            if (IN_RANGE()) {
                BIND(i)
            }
        }
    } else if (kind < 0x4000) {
        T318 = TBL[0];
        if (IN_RANGE()) {
            BIND(0)
        }
    }
    }
    return 0;
}

#undef BIND
#undef IN_RANGE
#undef T318
#undef TBL

void TObjGrass::run_attack_action() {

    switch (this->attack_kind) {
    default:
        this->attack_kind = 0;
    case 0:
        this->mode = 3;
        break;
    case 1:
        this->mode = 5;
        break;
    case 2:
        this->mode = 4;
        this->charge_distance = (f32) (0.0f);
        clear_hit_targets();
        break;
    }
    this->phase = 0;
    this->requested_action = 1;
    this->actorFlags = (s32) (this->actorFlags | 0x200000);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}

void TObjGrass::sub_800BDD70() {
    Vec sp20;
    Vec dst;
    Vec to_target;
    s32 ang;
    Vec *ent;
    s32 idx;
    clear_actor_flags(0x04040000);
    advance_animation();
    switch (this->phase) {
    default:
        this->phase = 0;
    case 0:
        if (this->target == NULL) {
            this->actorFlags &= ~0x200000;
            this->timer = 0;
        } else {
            VecCopy(&to_target, &this->target->body_center);
            subtract_vector(&to_target, &this->body_center);
            ang = turn_toward_direction(((GrassMoveParams *)this->movementParameters)->turn, &to_target);
            apply_actor_gravity(this, (s32 *)(0), (0.0f));
            if (ang < this->attack_params->get_attack_angle()) {
                this->phase = 1;
                if ((0.5f) < random_ratio()) {
                    this->requested_action = 2;
                } else {
                    this->requested_action = 3;
                }
            }
        }
        break;
    case 1:
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        if (is_passing_frame((f32)(14.0f)) != 0) {
            if (this->target != NULL && this->target->select_melee_contact_body(this, (1.0f)) != 0) {
                f32 damage = this->target->receive_physical_attack(this, (1.0f));
                this->target->apply_knockback_from_attacker((u8 *)this, damage);
            }
            switch (get_current_floor_area()) {
            case AREA_CAVE1:
            case AREA_CAVE2:
            case AREA_CAVE3:
                play_sound_effect(0x4003A60D, &this->position, 0, 0);
                break;
            case AREA_BATTLE1:
            case AREA_BATTLE2:
                if (enable_v2_features == 1) {
                    play_sound_effect(0x30022, &this->position, 0, 0);
                }
                break;
            case AREA_PIONEER2_EP2:
                break;
            case AREA_VR_TEMPLE_ALPHA:
            case AREA_VR_TEMPLE_BETA:
                play_sound_effect(0x3A316, &this->position, 0, 0);
                break;
            }
        }
        if (this->frame < (2e+01f)) {
            switch (this->requested_action) {
            case 2:
                ent = lbl_805D5158->lookup(this->frame);
                idx = 0;
                break;
            case 3:
                ent = lbl_805D515C->lookup(this->frame);
                idx = 1;
                break;
            default:
                ent = NULL;
                break;
            }
            if (ent != NULL) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&this->position.x);
                rotate_matrix_y(0, this->rotation_y);
                scale_matrix(0, (1.3f), (1.3f), (1.3f));
                matrix_mult_vec_array(NULL, ent, &dst, 2);
                pop_matrix();
                if (this->savers[idx] != NULL) {
                    this->savers[idx]->add_segment(&dst, &sp20);
                }
            }
        }
        if (this->action_flags != 4U) {
            this->phase = 2;
            this->requested_action = 0;
            this->timer = 0xF;
        }
        break;
    case 2:
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        (this->timer)--;
        if (this->timer < 0) {
            this->actorFlags &= ~0x200000;
            this->timer = 0;
        }
        break;
    }
    update_collisions();
    play_persistent_sound(remap_sound_for_area(0x4003A801), this, &this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot(&this->position, -0x5DB4, 1, 0);
}

#pragma push
#pragma opt_common_subs off
void TObjGrass::sub_800BD4D8() {
    if (this->targetId < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(this->targetId);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            this->target = p;
        } else {
            this->target = NULL;
        }
    } else {
        this->targetId = 0xFFFF;
        this->target = NULL;
    }
    this->clear_actor_flags(0x40000);
    if (this->target == NULL) {
        this->targetId = 0xFFFF;
        this->clear_actor_flags(0x4202000);
        this->timer = 0;
        return;
    }
    switch (this->phase) {
    default:
        this->phase = 0;
    case 0:
        this->clear_actor_flags(0x4000000);
        this->clear_player_status_flag(0, 0x80);
        play_persistent_sound(this->remap_sound_for_area(0x4003A801), this, &this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        this->play_speed = (2.0f) * this->action_table[this->requested_action].speed;
        this->advance_animation();
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        if (this->target != NULL) {
            Vec v;
            s32 d;
            VecCopy(&v, &this->target->body_center);
            subtract_vector(&v, &this->body_center);
            d = this->turn_toward_direction((s32)((2.0f) * (f32)((GrassMoveParams *)this->movementParameters)->turn), &v);
            if (d < this->attack_params->get_attack_angle()) {
                s32 ang = (s32)((10430.38043493439) * atan2_float(v.x, v.z));
                this->charge_distance = (3e+01f) + (newton_sqrtf(TObjPlayer::calc_distance_to_client(this, this->targetId, NULL)) + this->get_collision_body_radius(0));
                if (this->charge_distance < (1e+02f)) {
                    this->charge_distance = (1e+02f);
                }
                v.z = (0.0f);
                v.x = (0.0f);
                v.z = this->charge_distance;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, &this->body_center);
                if (select_enemy_destination(this, v, 1) != 0 || select_enemy_destination(this, this->target->body_center, 1) != 0) {
                    this->phase = 3;
                    this->requested_action = 7;
                    this->set_actor_flags(0x4000000);
                    this->set_indexed_flags(0, 0x80);
                    copy_position_if_valid(this, this->body_center);
                    play_sound_effect(this->remap_sound_for_area(0x4003A806), &this->position, 0, 0);
                    TObjPlayer::play_effect_if_v2(-0x200);
                } else {
                    if (this->targetId == 0xFFFF) {
                        this->target = NULL;
                    } else {
                        this->phase = 2;
                        this->requested_action = 0;
                        this->timer = 0x5A;
                    }
                    clear_hit_targets();
                }
            }
        }
        break;
    case 3:
        this->set_actor_flags(0x4000000);
        this->set_indexed_flags(0, 0x80);
        this->advance_animation();
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        if (this->action_flags != 0x20) {
            this->phase = 1;
            this->requested_action = 1;
            this->clear_actor_flags(0x4000000);
            this->clear_player_status_flag(0, 0x80);
        }
        break;
    case 1: {
        s32 k;
        s32 i;
        this->clear_actor_flags(0x4000000);
        this->clear_player_status_flag(0, 0x80);
        this->play_speed = (2.0f) * this->action_table[this->requested_action].speed;
        this->advance_animation();
        for (i = 0; i < 12; i++) {
            k = i * 4 + 0x3D4;
            if (this->hit_targets[i] == NULL) {
                TObjChara *p = TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                if ((u16)p->get_entity_id() >= 0x1000) {
                    break;
                }
                if (obj_is_hit_receivable(p) != 0 && this->find_actor_body_contact(p, (f32)((1e+04f))) != 0 &&
                    p->select_melee_contact_body(this, (1.0f)) != 0) {
                    f32 dmg = p->receive_physical_attack(this, (1.0f));
                    p->set_actor_flags(0x400);
                    p->apply_knockback_from_attacker((u8 *)this, (2.0f) * dmg);
                    if (is_split_screen() == 0 && local_client_id == (u16)p->get_entity_id()) {
                        TCameraCtrl::set_shake_preset(1);
                    }
                    *(TObjChara **)((u8 *)this + k) = p;
                }
            }
        }
        if (this->target != NULL) {
            GrassMoveParams *prm = (GrassMoveParams *)this->movementParameters;
            f32 spd = (2.0f) * prm->speed;
            f32 d2;
            f32 t;
            if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                spd *= (2.0f);
            }
            this->enemy_turn_toward_dest((s32)((2.0f) * (f32)prm->turn));
            enemy_set_heading_velocity(spd, this, this->rotation_y);
            move_with_wall_slide(this);
            d2 = horizontal_distance_squared(&this->move_destination, &this->body_center);
            if (this->targetId == 0xFFFF) {
                this->lost_target_frames++;
            }
            t = spd + this->bodies->radius;
            if (d2 < t * t || ((GrassMoveParams *)this->movementParameters)->radius * ((GrassMoveParams *)this->movementParameters)->radius < d2 || (1.5e+02f) < (f32)this->lost_target_frames) {
                if (this->targetId == 0xFFFF) {
                    this->target = NULL;
                } else {
                    this->phase = 2;
                    this->requested_action = 0;
                    this->timer = 0x5A;
                }
                clear_hit_targets();
                this->lost_target_frames = 0;
            }
        }
        play_persistent_sound(this->remap_sound_for_area(0x4003A300), this, &this->position, 0, 0);
        if (this->view_detail != 0) {
            Vec w;
            s32 ang[3];
            w.y = (0.0f);
            w.x = (0.0f);
            w.z = (4.0f);
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, this->rotation_y);
            rotate_vector_by_matrix(0, &w, &w);
            pop_matrix();
            vec3_add_to(&this->camera_vec, &w);
            ang[0] = -(s32)((10430.38043493439) * atan2_float(this->velocity.z, newton_sqrtf(this->velocity.x * this->velocity.x)));
            ang[1] = 0;
            ang[2] = (s32)((10430.38043493439) * atan2_float(this->velocity.x, (0.0f)));
            spawn_directional_particle(&this->camera_vec, ang, 0x150);
        }
        break;
    }
    case 2:
        this->clear_actor_flags(0x4000000);
        this->clear_player_status_flag(0, 0x80);
        this->play_speed = (2.0f) * this->action_table[this->requested_action].speed;
        this->advance_animation();
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        this->timer--;
        if (this->timer < 0) {
            this->clear_actor_flags(0x200000);
            this->timer = 0;
            this->targetId = 0xFFFF;
            this->target = NULL;
        }
        break;
    }
    this->refresh_collision_body_centers();
    minimap_render_dot(&this->position, -0x5DB4, 1, 0);
}
#pragma pop

void TObjGrass::update_web_attack() {
    Vec v;
    Vec v2;
    s32 ang[3];
    if (targetId < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(targetId);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            target = p;
        } else {
            target = NULL;
        }
    } else {
        targetId = 0xFFFF;
        target = NULL;
    }
    clear_actor_flags(0x4040000);
    advance_animation();
    switch (phase) {
    case 0:
        if (target == NULL) {
            actorFlags &= ~0x200000;
            timer = 0;
        } else {
            s32 d;
            VecCopy(&v, &target->body_center);
            subtract_vector(&v, &body_center);
            d = turn_toward_direction(((GrassMoveParams *)movementParameters)->turn, &v);
            apply_actor_gravity(this, (s32 *)(0), (0.0f));
            if (d < grass_bml_resource[1]->get_attack_angle()) {
                phase = 1;
                requested_action = 4;
                timer = 0;
            }
        }
        break;
    case 1:
        play_persistent_sound(remap_sound_for_area(0x40039E07), this, &position, 0, 0);
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        if (target != NULL) {
            s32 d;
            VecCopy(&v2, &target->body_center);
            subtract_vector(&v2, &body_center);
            d = angle_difference_abs(rotation_y, (s32)((10430.38043493439) * atan2_float(v2.x, v2.z)));
            if (d < grass_bml_resource[1]->get_attack_angle()) {
                VecCopy(&v2, &target->position);
                subtract_vector(&v2, &render_vec);
                ang[0] = (s32)((10430.38043493439) * atan2_float(v2.z, newton_sqrtf(v2.x * v2.x + v2.y * v2.y)));
                ang[1] = 0;
                ang[2] = -(s32)((10430.38043493439) * atan2_float(v2.x, v2.y));
                spawn_directional_particle(&this->render_vec, ang, 0xCA);
                if (this->action_flags != 4 && this->target->test_actor_flags(0x4000000) == 0) {
                    if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                        target->apply_movement_ailment(0);
                    } else {
                        new TObjGrassWeb(tl_05, target);
                    }
                }
            } else {
                this->action_flags &= ~4;
            }
        } else {
            this->action_flags &= ~4;
        }
        if (this->action_flags != 4) {
            this->phase = 2;
            this->requested_action = 1;
            this->timer = 0xF;
        }
        break;
    case 2:
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        timer--;
        if (timer < 0) {
            actorFlags &= ~0x200000;
            timer = 0;
        }
        break;
    }
    update_collisions();
    play_persistent_sound(remap_sound_for_area(0x4003A801), this, &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjGrass::run_miss_reaction() {
    if ((s16) this->mode != 6) {
        this->mode = 6;
        this->requested_action = 0;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFF9BFFFF);
}

void TObjGrass::update() {
    s16 timer;

    this->clear_actor_flags((u32)(0x04040000));
    this->advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
    }
    update_collisions();
    play_persistent_sound(this->remap_sound_for_area(0x4003A801), (u8 *)this, &this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    timer = this->timer;
    this->timer = (timer - 1);
    if (timer < 0) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        this->timer = (s16) this->resetTimer;
        this->referenceHp = (s16) this->hp;
    }
    minimap_render_dot(&this->position, -0x5DB4, 1, 0);
}

void TObjGrass::run_hit_reaction() {
    if ((s16) this->mode != 7) {
        this->mode = 7;
        this->requested_action = 5;
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
}

void TObjGrass::sub_800BCE44() {
  CollisionBody *bodies;
  clear_actor_flags((u32)(0x04040000));
  advance_animation();
  this->velocity.z = (f32) (0.0f);
  this->velocity.x = (f32) (0.0f);
  apply_actor_gravity(this, (s32 *)(0), (f32) (0.0f));
  update_collisions();
  if (is_passing_frame((f32) (0.0f)) != 0)
  {
    play_sound_effect(remap_sound_for_area(0x4003A603), &this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
  }
  if ((this->action_flags) != 8U)
  {
    this->actorFlags = (s32) ((this->actorFlags) & 0xFFFFF9FF);
    bodies = this->bodies;
    bodies->flags &= 0xFBFFFFFF;
    if ((this->hp) < ((this->hpmax) * (this->parameters[0])))
    {
      this->actorFlags = (s32) ((this->actorFlags) | 0x2000);
      this->target = NULL;
      this->targetId = (float) 0xFFFF;
      VecCopy(&this->move_origin, &this->body_center);
      VecCopy(&this->move_destination, &this->body_center);
      this->charge_distance = (f32) (0.0f);
    }
    this->referenceHp = this->hp;
  }
  play_persistent_sound(remap_sound_for_area(0x4003A801), this, &this->position, 0, 0);
  TObjPlayer::play_effect_if_v2(-0x200);
  minimap_render_dot(&this->position, -0x5DB4, 1, 0);
}

void TObjGrass::run_death_reaction() {
    if (this->mode != 8) {
        this->mode = 8;
        this->phase = 0;
        this->requested_action = 6;
        this->bodies->flags &= 0xFFFF7FFE;
        spawn_particle_effect(&this->body_center, 0xF2);
        refresh_lobby_state();
        this->send_entity_set_flags();
    }
}

void TObjGrass::update_camera_vec_by_stage(NJS_OBJECT *) {
    Vec *v;

    switch (grass_render_node_index) {
    case 0x31:
        v = &grass_camera_vec;
        grass_camera_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    case 0x32:
        break;
    case 0x34:
        break;
    case 0x35:
        v = &grass_render_vec;
        grass_render_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    case 0x3F:
        break;
    case 0x49:
        break;
    case 0xC:
        v = &grass_origin_vec;
        grass_origin_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    }
    grass_render_node_index++;
}

#pragma push
#pragma opt_common_subs off
void TObjGrass::update_dying() {
    set_actor_flags(0x04040000);
    advance_animation();
    switch (phase) {
    default:
        phase = 0;
    case 0:
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        if (is_passing_frame((f32)(0.0f)) != 0) {
            play_sound_effect(remap_sound_for_area(0x4003A804), &position, 0, 0);
            phase = 1;
        }
        break;
    case 1:
        move_with_wall_slide(this);
        velocity.x *= (0.5f);
        velocity.z *= (0.5f);
        if (is_passing_frame((f32)(23.0f)) != 0) {
            phase = 2;
            spawn_particle_effect(&position, 0xF0);
        }
        break;
    case 2:
        if (is_passing_frame((f32)(32.0f)) != 0) {
            Vec v;
            v.y = (0.0f);
            v.x = (0.0f);
            v.z = (-15.0f);
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, rotation_y);
            rotate_vector_by_matrix(0, &v, &v);
            pop_matrices(1);
            vec3_add_to(&v, &position);
            switch (get_current_floor_area()) {
            case AREA_CAVE1:
            case AREA_CAVE2:
            case AREA_CAVE3: {
                new TObjCGrass(v, (s32)((12.0f) + parameters[3]), 0xF0);
                break;
            }
            }
            play_sound_effect(remap_sound_for_area(0x4003AB0A), &position, 0, 0);
            TDeadSpot::spawn_kind1_scale15(&position, 0xA);
            spawn_ground_effect(&position, 0x1E);
        }
        scale.y -= 0.01f;
        if (scale.y < 0.0f) {
            scale.y = 0.0f;
        }
        parameters[2] -= (0.01f);
        if (parameters[2] < (-5.0f)) {
            actorFlags |= 0x02000000;
            parameters[2] = (-5.0f);
            queue_destruction();
        }
        break;
    }
    if (frame < (32.0f)) {
        particle_timer++;
        if (particle_timer == 4) {
            particle_timer = 0;
            spawn_particle_effect(&origin_vec, 0xF2);
        }
    }
}
#pragma pop

void TObjGrass::sub_800BCA2C() {  }

TObjGrassWeb::TObjGrassWeb(TObject *parent, TObjCollidable *target) : TObjBase(parent) {
    if (target != NULL) {
        m_name = grass_web_class_name;
        VecCopy(&position, &target->position);
        state = 0;
        target_id = target->get_entity_id();
        set_params[0] = 0xB4;
    } else {
        TObject::queue_destruction();
    }
}

TObjGrassWeb::~TObjGrassWeb() {
}

void TObjGrassWeb::render() {  }

void TObjGrassWeb::run_task() {
    switch (this->state) {
    case 0:
        apply_to_player();
        return;
    case 1:
        update_hold();
        return;
    default:
        queue_destruction();
        return;
    }
}

void TObjGrassWeb::apply_to_player() {
    TObjPlayer *player;

    this->state = 1;
    player = get_player_by_client_id(this->target_id);
    if ((player != NULL) && (player->is_locally_controlled() != 0) && (player->all_parents_unqueued_for_destruction() != 0) && (player->test_actor_flags(0x800) == 0)) {
        TObjPlayer::play_effect(player, this->set_params[0], 1);
    }
}

void TObjGrassWeb::update_hold() {
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_persistent_sound(0x4003A809, this, &position, 0, 0);
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        if (enable_v2_features == 1) {
            play_persistent_sound(0x3051E, this, &position, 0, 0);
        }
        break;
    case AREA_PIONEER2_EP2:
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_persistent_sound(0x3A81D, this, &position, 0, 0);
        break;
    }
    if (set_params[0]-- < 0) {
        state = 2;
    }
}
}

void TObjGrassWeb::queue_destruction() { TObject::queue_destruction(); }
