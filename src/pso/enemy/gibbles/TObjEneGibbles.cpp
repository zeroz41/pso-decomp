#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/map/CsnQuery.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/effect/GroundContactSound.h"
#include "pso/player/PlayerAttackParams.h"
struct NJS_OBJECT;
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/TObjControl.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gibbles/TObjEneGibbles.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/vector.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/player/PlayerSlots.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/camera/TCameraCtrl_8006A03C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_800A7764.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/network/client_id.h"

#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"

__declspec(section ".data") const char *TObjEneGibbles__model_filenames[2] = {
    "gibb_body.nj", NULL,
};
const char *TObjEneGibbles__motion_names_and_resource_descriptor[11] = {
    "attack_gibb_body.njm", "damage_gibb_body.njm", "dead_gibb_body.njm", "guard_gibb_body.njm",
    "jump_gibb_body.njm", "kamae_gibb_body.njm", "landing_gibb_body.njm", "punch_gibb_body.njm",
    "wait_gibb_body.njm", "walk_gibb_body.njm", NULL,
};
BmlResourceDescriptor lbl_804E285C = {
    "bm_ene_gibbles.bml", TObjEneGibbles__model_filenames, TObjEneGibbles__motion_names_and_resource_descriptor, 1, 10,
};
__declspec(section ".data") const char *lbl_804E286C[2] = {
    "lo_gibb_body.nj", NULL,
};
const char *gibbles_motion_name_table[11] = {
    "attack_gibb_body.njm", "damage_gibb_body.njm", "dead_gibb_body.njm", "guard_gibb_body.njm",
    "jump_gibb_body.njm", "kamae_gibb_body.njm", "landing_gibb_body.njm", "punch_gibb_body.njm",
    "wait_gibb_body.njm", "walk_gibb_body.njm", NULL,
};
BmlResourceDescriptor lbl_804E28A0 = {
    "bm_ene_gibbles_low.bml", lbl_804E286C, gibbles_motion_name_table, 1, 10,
};
// actions/action_count hold gibbles_action_table and its 10 entries (same layout as GeeAnimationBinding)
TObjMotionAction gibbles_action_table[10] = {
    {1, 0, 8, 0.3f, 1},
    {1, 0, 9, 0.5f, 1},
    {2, 0, 0, 0.7f, 4},
    {2, 0, 7, 0.6f, 4},
    {1, 0, 5, 0.3f, 4},
    {2, 6, 4, 0.7f, 4},
    {1, 0, 6, 0.7f, 4},
    {1, 0, 3, 0.8f, 0x20},
    {2, 0, 1, 0.8f, 8},
    {3, 0, 2, 0.7f, 0x10},
};
const char *TObjEneGibbles__class_name = "TObjEneGibbles";
const NpcAnimationBinding gibbles_resource_binding_desc = { NULL, gibbles_action_table, 0, 1, 10 };
const Vec lbl_80472768 = {0.0f, 0.0f, 0.0f};
const Vec lbl_80472774 = {0.0f, 0.0f, 0.0f};
const Vec gibbles_joint_zero_vec = {0.0f, 0.0f, 0.0f};
GibblesMoveParams lbl_804E2950 = {
    250.0f, 1.25f, 0x400, {0, 0x64, 0, 0},
};
CollisionBody lbl_804E296C[3] = {
    { { 0.0f, 15.0f, 0.0f }, 15.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 30.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
saddr gibbles_boss_stat_handle;
AttackParams **gibbles_combat_stat_entries;
saddr gibbles_combat_stats_handle;
GibblesAiParams *TObjEneGibbles__ai_parameters;
BmlResource *TObjEneGibbles__resource_bundle;
s32 TObjEneGibbles__render_node_index;
s32 TObjEneGibbles__render_rotation_x;

// The file is compiled -inline off,deferred, which emits the functions in the
// reverse of the order they are written in.
void TObjEneGibbles::select_model_record(s32 i) {
    model = TObjEneGibbles__resource_bundle->models[i].model;
    texlist = (saddr)TObjEneGibbles__resource_bundle->models[i].m_c;
}

void *TObjEneGibbles::get_center() { return &body_center; }

TObjEneGibbles::TObjEneGibbles(TObject *parent, void *setData) : TObjEnemy(parent) {
    s32 i;
    m_name = TObjEneGibbles__class_name;
    apply_set_data(setData);
    init_position_vectors();
    scale.x = scale.y = scale.z = 1.0f;
    init_params();
    mode = 0;
    phase = 0;
    variant = 0;
    set_param(0x3D);
    subtype = 0;
    select_model_record(variant);
    action_table = gibbles_action_table;
    set_field_d8((saddr)action_table);
    motion_list = TObjEneGibbles__resource_bundle->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    init_collision_body_parts(this, lbl_804E296C, 1);
    attack_kind = 0;
    combo_count = 0;
    movementParameters = &lbl_804E2950;
    bind_enemy_combat_stats((u8 *)gibbles_boss_stat_handle, (u8 *)gibbles_combat_stat_entries[attack_kind], (u8 *)gibbles_combat_stats_handle);
    referenceHp = hp;
    update_position();
    update_shadow_height();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    initialize_enemy_photon_effect(this);
    status_flags = 1;
    guarded_player = NULL;
    head_angle = 0;
    add_flags_2e4(0x11);
    actorFlags |= 0x06040000;
    armor_state = 0x101;
    reported_armor_state = 0x101;
    attack_colliders[0] = new TObjCollidable(NULL);
    init_collision_body_parts(attack_colliders[0], &lbl_804E296C[1], 1);
    attack_colliders[1] = new TObjCollidable(NULL);
    init_collision_body_parts(attack_colliders[1], &lbl_804E296C[2], 1);
    fade.reset_obstruction_fade();
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}

TObjEneGibbles::~TObjEneGibbles() {
    if (attack_colliders[0] != NULL) {
        free_collision_body_parts(attack_colliders[0]);
        delete attack_colliders[0];
        attack_colliders[0] = NULL;
    }
    if (attack_colliders[1] != NULL) {
        free_collision_body_parts(attack_colliders[1]);
        delete attack_colliders[1];
        attack_colliders[1] = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneGibbles::load_resources() {
    BmlResource *p;
    if (is_split_screen() != 0) {
        p = new BmlResource(1, &lbl_804E28A0, 0, 0, NULL);
        TObjEneGibbles__resource_bundle = p;
    } else {
        p = new BmlResource(1, &lbl_804E285C, 0, 0, NULL);
        TObjEneGibbles__resource_bundle = p;
    }
    TObjEneGibbles__render_node_index = 0;
    TObjEneGibbles__render_rotation_x = 0;
    gibbles_combat_stat_entries = (AttackParams **)mem_alloc(0xC);
    gibbles_boss_stat_handle = (saddr)TLobby::register_boss(0x3D);
    gibbles_combat_stat_entries[0] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x3D);
    gibbles_combat_stat_entries[2] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x3E);
    gibbles_combat_stat_entries[1] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x3F);
    gibbles_combat_stats_handle = (saddr)TLobby::register_object(0x3D);
    TObjEneGibbles__ai_parameters = (GibblesAiParams *)TLobby::dispatch_shared_handler_a(0x3D);
    NpcAnimationBinding s = gibbles_resource_binding_desc;
    s.motions = TObjEneGibbles__resource_bundle->motions;
    NpcModelRegistry::register_animated_chunk(0x44, TObjEneGibbles__resource_bundle->models->model, TObjEneGibbles__resource_bundle->models->m_c, &s, lbl_804E296C[0].radius, 0.0f);
}

void TObjEneGibbles::free_static() {
    if (gibbles_combat_stat_entries != NULL) {
        mem_free(gibbles_combat_stat_entries);
        gibbles_combat_stat_entries = NULL;
    }
    if (TObjEneGibbles__resource_bundle != NULL) {
        delete TObjEneGibbles__resource_bundle;
        TObjEneGibbles__resource_bundle = NULL;
    }
}

void *TObjEneGibbles::create(void *setData) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneGibbles(parent, setData);
}

void TObjEneGibbles::init_params() {
    s16 armor_points;

    armor_points = (s16)(100.0f + parameters[0]);
    armor = armor_points;
    armor_max = armor_points;
    preferred_class = (s32)parameters[1];
    if (preferred_class < 0) {
        preferred_class = 0;
    } else if (preferred_class > 8) {
        preferred_class = 8;
    }
    target_class_mask = 0;
    target_class_mask |= 1 << preferred_class;
    jump_attack_chance = parameters[2];
    hit_jump_chance = parameters[3];
}

void TObjEneGibbles::run_task() {
    TObjChara *chased;
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_802D7E3C();
        return;
    }
    {
        switch (this->mode) {
        case 0:
            this->init_state();
            break;
        case 1:
            this->update_spawn_state();
            break;
        case 2:
            this->update_death_sequence();
            break;
        case 3:
            this->state_chase_target();
            break;
        case 4:
            state_attack();
            break;
        case 5:
            state_punch();
            break;
        case 6:
            this->state_jump_attack();
            break;
        case 7:
            state_guard();
            break;
        case 8:
            this->update_action_state();
            break;
        case 9:
            this->state_dead();
            break;
        case 10:
            this->state_appear();
            break;
        case 11:
            this->update_wander();
            break;
        }
    }
    chased = (TObjChara *)target;
    if (chased != NULL && (chased->actorFlags & 0x02000800)) {
        combo_count = 0;
        actorFlags &= 0xFFDFFFFF;
        status_flags &= 0xFFFF0000;
        target = NULL;
    }
    this->update_position();
    this->update_shadow_height();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    this->sync_state();
    this->m_2b4 += 1.0f;
}

void TObjEneGibbles::render() {
    Vec v;
    s32 fade;
    s32 vis;
    s32 cam;
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (get_current_floor_area() == AREA_TOWER) {
        vis = this->classify_actor_view_detail(600.0f, 600.0f, 30.0f);
    } else {
        vis = this->classify_actor_view_detail(300.0f, 600.0f, 30.0f);
    }
    if (vis != 0) {
        this->fades[cam].update();
        fade = this->fades[cam].updateFromCamera(&body_center.x);
        select_actor_lighting(this);
        TObjFish::set_global_param(this->texlist);
        push_matrix_from(NULL);
        VecCopy(&v, &position);
        switch (this->mode) {
        case 2:
        case 6:
        case 10:
            v.y += this->jump_height;
            break;
        }
        translate_matrix_vec3(NULL, (u8 *)&v);
        rotate_matrix_y(NULL, this->rotation_y);
        scale_matrix_vec3(NULL, (u8 *)&scale);
        TObjEneGibbles__render_node_index = 0;
        TObjEneGibbles__render_rotation_x = this->head_angle;
        set_chunk_model_node_callback(gibbles_render_node_callback);
        TObjPlayer::toggle_particle_effect();
        switch (this->mode) {
        case 0:
            break;
        case 1:
        case 2:
        case 10:
            if (this->fade.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                model_render_flags |= 1;
                this->fade.set_flags_and_apply_damage_color();
                if (defer_render() == 0) {
                    ((TObjMotion *)this)->draw();
                }
                this->fade.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
            break;
        default:
            if (fade != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                this->fades[cam].set_flags_and_apply_damage_color();
                if (defer_render() == 0) {
                    if (vis == 1) {
                        ((TObjMotion *)this)->draw();
                    } else {
                        ((TObjEnemy *)this)->draw_motion_model();
                    }
                }
                this->fades[cam].clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            } else if (vis == 1) {
                ((TObjMotion *)this)->draw();
            } else {
                ((TObjEnemy *)this)->draw_motion_model();
            }
            break;
        }
        TParticleCtrl::end_effect_render();
        set_chunk_model_node_callback(NULL);
        pop_matrix();
        restore_scene_lighting();
        if (!(this->status_flags & 1)) {
            ((TObjEnemy *)this)->draw_ground_shadow(0, 0);
        }
    } else {
        this->update_position();
    }
}

void gibbles_render_node_callback(NJS_OBJECT *) {
    if ((s32) TObjEneGibbles__render_node_index == 0x18) {
        rotate_matrix_x(NULL, TObjEneGibbles__render_rotation_x);
    }
    TObjEneGibbles__render_node_index += 1;
}

void TObjEneGibbles::clamp_angle(s32 angle) {
    if (angle < -0x238E) {
        angle = -0x238E;
    } else if (angle > 0x238E) {
        angle = 0x238E;
    }
    this->head_angle = lerp_angle_half(this->head_angle, angle);
}

void TObjEneGibbles::turn_toward_target() {
    Vec d;
    VecCopy(&d, &((TObjChara *)target)->body_center);
    subtract_vector(&d, &body_center);
    clamp_angle(angle_diff_s16(rotation_y, (s32)(10430.38043493439 * atan2_float(d.x, d.z))));
}

void TObjEneGibbles::refresh_target() {
    if (status_flags & 0x40) {
        targetId = 0xFFFF;
        target = NULL;
        return;
    }
    if (is_actor_cadence_frame(0x1E) == 0) {
        return;
    }
    if (obj_testFlags30(0x10) != 0) {
        s32 best_id;
        s32 i;
        TObjPlayer *p;
        s32 id;
        f32 best;
        f32 d;
        u16 tid;
        i = 0;
        best_id = 0xFFFF;
        Vec v = lbl_80472768;
        best = ((GibblesMoveParams *)movementParameters)->radius * ((GibblesMoveParams *)movementParameters)->radius;
        for (; i < registered_player_count + registered_enemy_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && p != (TObjChara *)this) {
                id = ((s32 (*)(void *))get_entity_id)(p);
                if ((u16)id < 0x4000 && (u16)id != entity_id && !(p->actorFlags & 0x02000800)) {
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
                    target = (u8 *)q;
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
        s32 best_id2;
        s32 best_id;
        TObjPlayer *p;
        TObjPlayer *best_p2;
        TObjPlayer *best_p;
        s32 i;
        f32 best2;
        f32 best;
        f32 d;
        Vec v = lbl_80472774;
        best_id = 0xFFFF;
        best_p2 = NULL;
        best_id2 = best_id;
        best_p = NULL;
        i = 0;
        best = ((GibblesMoveParams *)movementParameters)->radius * ((GibblesMoveParams *)movementParameters)->radius;
        best2 = best;
        for (; i < registered_player_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == NULL) continue;
            if ((u16)((s32 (*)(void *))get_entity_id)(p) >= 0x1000) continue;
            if (p->get_floor() != get_current_floor()) continue;
            if (p->actorFlags & 0x02000800) continue;
            VecCopy(&v, &p->body_center);
            subtract_vector(&v, &body_center);
            d = v.x * v.x + v.z * v.z;
            if ((p->class_flags & target_class_mask) && d < best &&
                check_path_obstructed(this, &p->body_center) != 1) {
                best_id = ((s32 (*)(void *))get_entity_id)(p);
                best = d;
                best_p = p;
            }
            if (d < best2 && check_path_obstructed(this, &p->body_center) != 1) {
                best_id2 = ((s32 (*)(void *))get_entity_id)(p);
                best2 = d;
                best_p2 = p;
            }
        }
        if (best2 < 900.0f && best_p2 != NULL) {
            targetId = best_id2;
            target = (u8 *)best_p2;
            return;
        }
        if (best_p != NULL) {
            targetId = best_id;
            target = (u8 *)best_p;
            return;
        }
        if (best_p2 != NULL) {
            targetId = best_id2;
            target = (u8 *)best_p2;
            return;
        }
        targetId = 0xFFFF;
        target = NULL;
    }
}

s32 TObjEneGibbles::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xa:
            if (fade.advance_toward_max() == 1) {
                this->status_flags &= ~0x143;
                this->status_flags |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneGibbles::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xa:
            if (fade.advance_toward_max() == 1) {
                this->status_flags &= ~0x143;
                this->status_flags |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

void TObjEneGibbles::run_idle_action() {
    switch (this->mode) {
    case 0:
        if (fade.has_visible_opacity() != 0) {
            this->mode = 0xA;
            this->phase = 0;
            this->requested_action = 0;
            obj_clearFlags30(0x200000);
            obj_setFlags30(this, 0x06040000);
            this->status_flags &= 0xFFFF0000;
            this->bodies->flags &= 0xFFFFFFFE;
        }
    case 6:
    case 11:
        return;
    case 10:
        if (!(this->status_flags & 0x40)) {
            this->mode = 0;
            return;
        }
        break;
    default:
        this->phase = 0;
        this->mode = 0xB;
        this->requested_action = 1;
        this->actorFlags &= 0xF99BFFFF;
        break;
    }
}

void TObjEneGibbles::init_state() {
    set_position_from(&home_position);
    refresh_collision_body_centers();
    this->actorFlags &= 0xFFDFFFFF;
    this->actorFlags |= 0x06040000;
    this->bodies->flags &= 0xFFFFFFFE;
}

void TObjEneGibbles::update_wander() {
    advance_animation();
    if (target != NULL) {
        mode = 3;
        phase = 0;
        obj_clearFlags30(0x06240000);
        status_flags &= 0xFFFF0000;
        status_flags |= 4;
        bodies->flags |= 1;
    } else {
        status_flags &= 0xFFFFFFFB;
    }
    enemy_wander_home(((GibblesMoveParams *)movementParameters)->speed, 100.0f, 100.0f, ((GibblesMoveParams *)movementParameters)->turn_speed);
    refresh_collision_body_centers();
    check_object_collisions();
    check_enemy_body_collisions(this);
    update_enemy_collision_flags();
    obj_clearFlags30(0x200000);
    play_ground_contact_sound();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

void TObjEneGibbles::state_appear() {
    this->actorFlags &= 0xFFDFFFFF;
    this->actorFlags |= 0x06040000;
    this->status_flags &= ~0x107;
    this->bodies->flags &= 0xFFFFFFFE;
    advance_animation();
    switch (this->phase) {
    default:
    case 0:
        this->phase = 1;
        this->requested_action = 5;
        this->jump_height = 0.0f;
        this->jump_speed = 16.483517f;
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case 1:
        if (is_passing_frame(8.0f) != 0) {
            this->phase = 2;
            spawn_ground_contact_effect();
            play_sound_effect(this->resolve_sound_id(0x3A82F), &position, 0, 0);
            this->fade.reset_color();
        }
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case 2:
        if (this->fade.decay_value_toward_floor() == 1) {
            this->phase = 3;
        } else {
            this->jump_height = this->jump_height + this->jump_speed;
            this->jump_speed = this->jump_speed - 1.0989012f;
        }
        break;
    case 3:
        this->set_position_from(&home_position);
        this->update_prev_position();
        this->scale.z = 1.0f;
        this->scale.y = 1.0f;
        this->scale.x = 1.0f;
        this->status_flags &= 0xFFFF0000;
        this->status_flags |= 1;
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneGibbles::run_move_action() {
    switch (this->mode) {
    default:
        if (this->status_flags & 4) {
            this->mode = 3;
            this->phase = 0;
            this->requested_action = 1;
            this->actorFlags &= 0xF9FBFFFF;
        } else if (this->status_flags & 1) {
            this->mode = 1;
            this->phase = 0;
            this->actorFlags |= 0x06040000;
        }
        this->bodies->flags |= 1;
        return;
    case 1:
        if (this->status_flags & 2) {
            this->mode = 2;
            this->phase = 0;
            this->actorFlags |= 0x06040000;
        }
        return;
    case 2:
        if (this->status_flags & 4) {
            this->mode = 3;
            this->phase = 0;
            this->requested_action = 1;
            this->actorFlags &= 0xF9FBFFFF;
            return;
        }
        break;
    case 3:
        if (this->status_flags & 3) {
            this->mode = 1;
            this->phase = 0;
            this->actorFlags |= 0x06040000;
            this->status_flags &= 0xFFFF0000;
            this->status_flags |= 1;
            this->bodies->flags |= 1;
            return;
        }
        break;
    }
}

void TObjEneGibbles::update_spawn_state() {
    this->actorFlags &= 0xFFDFFFFF;
    this->actorFlags |= 0x06040000;
    this->bodies->flags &= 0xFFFFFFFE;
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        return;
    case 1:
        if (horizontal_distance_squared(&((TObjChara *)target)->body_center, &body_center) < 40000.0f) {
            this->phase = 3;
        }
    case 2:
        return;
    case 3:
        this->status_flags &= 0xFFFF0000;
        this->status_flags |= 2;
        break;
    }
}

void TObjEneGibbles::update_death_sequence() {
    this->actorFlags &= 0xFFDFFFFF;
    this->actorFlags |= 0x06040000;
    this->bodies->flags &= 0xFFFFFFFE;
    advance_animation();
    switch (this->phase) {
    case 2:
        break;
    case 0:
        this->phase = 1;
        this->requested_action = 5;
        fade.start_fade_in();
        this->jump_height = 100.00001f;
        this->jump_speed = 1.0989012f;
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case 1:
        if (fade.advance_toward_max() != 0) {
            this->jump_height = this->jump_height - this->jump_speed;
            this->jump_speed += 1.0989012f;
        } else {
            this->frame = 22.0f;
        }
        if (is_passing_frame((this->frame_count - 1.0f) - this->play_speed) != 0) {
            this->jump_height = 0.0f;
            this->jump_speed = 0.0f;
            switch (landing_damage_players()) {
            case 0:
                TObjEneGibbles__sub_800D8988(&position);
                break;
            default:
            case 1:
                play_sound_effect(resolve_sound_id(0x3AD32), &position, 0, 0);
                break;
            }
            shake_camera_in_room();
            this->phase = 3;
        }
        break;
    case 3:
        if (is_passing_frame((this->frame_count - 1.0f) - this->play_speed) != 0) {
            this->status_flags &= 0xFFFF0000;
            this->status_flags |= 4;
        }
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneGibbles::state_chase_target() {
    f32 d;
    s32 ok;
    this->bodies->flags |= 1;
    this->actorFlags &= 0xF9DBFFFF;
    if (this->target == NULL) {
        return;
    }
    switch (this->phase) {
    case 2:
        break;
    case 0:
        if (select_enemy_destination(this, ((TObjChara *)target)->body_center, 7) != 0) {
            this->phase = 1;
            copy_position_if_valid(this, body_center);
            apply_actor_gravity(this, NULL, 0.0f);
            this->state_timer = 0.0f;
        } else {
            this->phase = 0;
            this->mode = 0xB;
            this->requested_action = 1;
            this->actorFlags &= 0xF99BFFFF;
        }
        break;
    case 1:
        {
            f32 speed = TObjEneGibbles__ai_parameters->walk_speed;
            this->state_timer += speed;
            enemy_move_toward(this, ((GibblesMoveParams *)movementParameters)->turn_speed, ((TObjChara *)target)->body_center, 0, speed);
        }
        d = horizontal_distance_squared(&move_destination, &position);
        ok = select_enemy_destination(this, ((TObjChara *)target)->body_center, 1);
        if (d >= 22500.0f && ok != 0) {
            this->status_flags |= 0x10;
        } else if (this->state_timer >= 50.0f) {
            this->state_timer = 0.0f;
            if (random_ratio() < this->jump_attack_chance && ok != 0) {
                this->status_flags |= 0x10;
            } else {
                this->status_flags &= ~0x10;
            }
        } else {
            this->status_flags &= ~0x10;
        }
        {
            f32 r = ((GibblesMoveParams *)movementParameters)->speed + this->bodies->radius;
            if (d < r * r) {
                this->phase = 3;
            }
        }
        break;
    case 3:
        this->status_flags &= ~0x10;
        this->phase = 0;
        break;
    }
    play_ground_contact_sound();
    advance_animation();
    turn_toward_target();
    this->check_object_collisions();
    check_enemy_body_collisions(this);
    this->update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

s32 TObjEneGibbles::is_target_in_attack_range() {
    Vec v;
    f32 rad;
    f32 dist;
    s32 ang;
    TObjChara *obj;
    CollisionBody *body;
    if (this->mode >= 3) {
        obj = (TObjChara *)this->target;
        if (obj != NULL && this->attack_params != NULL && !(obj->actorFlags & 0x02000800)) {
            dist = calc_xz_distance_sq(this, obj, &v);
            ang = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
            body = ((TObjChara *)this->target)->bodies;
            if (body != NULL) {
                rad = body->radius;
            } else {
                rad = 10.0f;
            }
            if (this->status_flags & 8) {
                this->attack_kind = 2;
                if (dist <= (rad + gibbles_combat_stat_entries[attack_kind]->get_attack_range()) * (rad + gibbles_combat_stat_entries[attack_kind]->get_attack_range()) && ang <= gibbles_combat_stat_entries[attack_kind]->get_attack_angle()) {
                    return 1;
                }
            } else if (this->status_flags & 0x10) {
                this->attack_kind = 1;
                if (dist <= (150.0f + rad) * (150.0f + rad) && ang <= 0xAAA) {
                    return 1;
                }
            } else {
                this->attack_kind = 0;
                if (dist <= (rad + gibbles_combat_stat_entries[attack_kind]->get_attack_range()) * (rad + gibbles_combat_stat_entries[attack_kind]->get_attack_range()) && ang <= gibbles_combat_stat_entries[attack_kind]->get_attack_angle()) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void TObjEneGibbles::run_attack_action() {
    Vec v;
    switch (this->attack_kind) {
    case 0:
    default: {
        VecCopy(&v, &((TObjChara *)this->target)->body_center);
        subtract_vector(&v, &this->body_center);
        f64 t = atan2_float(v.x, v.z);
        this->mode = 4;
        if ((s32) (10430.38043493439 * t) < 0x10) {
            this->phase = 1;
            this->requested_action = 2;
        } else {
            this->phase = 0;
            this->requested_action = 1;
        }
        break;
    }
    case 2:
        this->mode = 5;
        this->phase = 0;
        this->requested_action = 3;
        break;
    case 1:
        this->mode = 6;
        this->phase = 0;
        this->requested_action = 4;
        this->status_flags &= 0xFFFFFF7F;
        break;
    }
    bind_enemy_combat_stats(NULL, (u8 *)gibbles_combat_stat_entries[this->attack_kind], NULL);
    this->bodies->flags |= 1;
    this->actorFlags &= 0xF9FBFFFF;
    this->actorFlags |= 0x200000;
}

void TObjEneGibbles::slam_damage_players(s32 node) {
    Vec v;
    DirectAttackPayload a;
    f32 d;
    s32 i;
    TObjPlayer *p;

    if (node == 0x35) {
        render_and_get_joint_pos(&v, 0x35);
    } else if (node == 0x1F) {
        render_and_get_joint_pos(&v, 0x1F);
    } else {
        return;
    }
    v.y += 20.0f;
    if (csnVecterUnder(&v, 0x16EF) != 0) {
        if (spawn_ground_impact_effects(&v, 2.0f) == 0) {
            v.y += 5.0f;
            spawn_particle_effect(&v, 0x64);
        }
        for (i = 0; i < lbl_805D5868; i++) {
            p = TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && get_entity_id(p) < 0x1000) {
                d = horizontal_distance_squared(&p->body_center, &v);
                if (d <= gibbles_combat_stat_entries[0]->get_damage_radius() * gibbles_combat_stat_entries[0]->get_damage_radius()) {
                    a.kind = 0;
                    a.power = get_attack_params_atp_min(gibbles_combat_stat_entries[0]);
                    p->apply_knockback_from_attacker((u8 *)this, p->receive_direct_attack(this, a, NULL, -1, -1));
                }
            }
        }
    }
}

#pragma push
#pragma opt_loop_invariants off
s32 TObjEneGibbles::landing_damage_players() {
    s32 i;
    TObjPlayer *pl;

    for (i = 0; i < lbl_805D5868; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((uaddr)pl) != 0 && get_entity_id(pl) < 0x1000U) {
            f32 dist = horizontal_distance_squared(&pl->body_center, &position);
            if (dist <= gibbles_combat_stat_entries[1]->get_damage_radius() * gibbles_combat_stat_entries[1]->get_damage_radius()) {
                DirectAttackPayload attack;
                attack.kind = 0;
                attack.power = get_attack_params_atp_min(gibbles_combat_stat_entries[1]);
                f32 res = pl->receive_direct_attack(this, attack, NULL, -1, -1);
                pl->apply_knockback_from_attacker((u8 *)this, res);
                if (res > 0.0f) {
                    obj_setFlags30(pl, 0x600);
                }
            }
        }
    }
    return spawn_ground_contact_effect();
}

extern "C" s32 TObjEneGibbles__sub_802D9824(void *self, s32 arg, f32 scale) {
    TObjEneGibbles *g;
    s32 done = 0;
    TObjCollidable **p;
    s32 i;

    if (actor_frame_tick % 5) {
        return 0;
    }
    ((TObjEneGibbles *)self)->render_and_get_joint_pos(&((TObjEneGibbles *)self)->attack_colliders[0]->position, 0x35);
    TObjPlayer::init_all_slots();
    p = ((TObjEneGibbles *)self)->attack_colliders;
    (*p)->check_object_collisions();
    if ((*p)->bodies->flags & 0x80000) {
        for (i = 0; i < 16; i++) {
            TObjChara *obj = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (!obj) {
                break;
            }
            if (!obj_is_hit_receivable((u8 *)obj)) {
                continue;
            }
            g = (TObjEneGibbles *)self;
            if (obj->select_melee_contact_body(g, 1.0f) == 0) {
                continue;
            }
            if (scale <= 0.0f) {
                scale = obj->receive_physical_attack(g, 1.0f);
            } else {
                DirectAttackPayload h;
                h.kind = 0;
                h.power = scale;
                scale = obj->receive_direct_attack(g, h, 0, -1, -1);
            }
            obj->apply_knockback_from_attacker((u8 *)g, scale);
            if (arg == 1 && scale > 0.0f) {
                obj_setFlags30(obj, 0x600);
                g->armor = (s16)(g->armor + scale);
                g->armor_state = 0x10e;
            }
            done = 1;
        }
    }
    return done;
}

extern "C" s32 TObjEneGibbles__sub_802D9644(void *self, s32 arg, f32 scale) {
    TObjEneGibbles *g;
    s32 done = 0;
    TObjCollidable **p;
    s32 i;

    if (actor_frame_tick % 5) {
        return 0;
    }
    ((TObjEneGibbles *)self)->render_and_get_joint_pos(&((TObjEneGibbles *)self)->attack_colliders[0]->position, 0x1f);
    TObjPlayer::init_all_slots();
    p = ((TObjEneGibbles *)self)->attack_colliders;
    (*p)->check_object_collisions();
    if ((*p)->bodies->flags & 0x80000) {
        for (i = 0; i < 16; i++) {
            TObjChara *obj = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (!obj) {
                break;
            }
            if (!obj_is_hit_receivable((u8 *)obj)) {
                continue;
            }
            g = (TObjEneGibbles *)self;
            if (obj->select_melee_contact_body(g, 1.0f) == 0) {
                continue;
            }
            if (scale <= 0.0f) {
                scale = obj->receive_physical_attack(g, 1.0f);
            } else {
                DirectAttackPayload h;
                h.kind = 0;
                h.power = scale;
                scale = obj->receive_direct_attack(g, h, 0, -1, -1);
            }
            obj->apply_knockback_from_attacker((u8 *)g, scale);
            if (arg == 1 && scale > 0.0f) {
                obj_setFlags30(obj, 0x600);
                g->armor = (s16)(g->armor + scale);
                g->armor_state = 0x10e;
            }
            done = 1;
        }
    }
    return done;
}

void TObjEneGibbles::state_attack() {
    bodies->flags |= 1;
    actorFlags &= 0xF9FBFFFF;
    u16 id = targetId;
    if (id < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(id);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            target = (u8 *)p;
        } else {
            target = NULL;
        }
    } else if (id < 0x4000) {
        target = get_enemy_entity(id);
    } else {
        targetId = 0xFFFF;
        target = NULL;
    }
    switch (phase) {
    case 0:
        if (target == NULL) {
            phase = 0;
            actorFlags &= 0xFFDFFFFF;
            resetTimer = 0;
        } else {
            Vec d;
            s32 diff;
            VecCopy(&d, &((TObjChara *)target)->body_center);
            subtract_vector(&d, &body_center);
            diff = turn_toward_direction(((GibblesMoveParams *)movementParameters)->turn_speed, &d);
            if (!(actorFlags & 0x800000)) {
                apply_actor_gravity(this, NULL, 0.0f);
            }
            if (diff < 0x10) {
                status_flags |= 0x100;
                phase = 1;
                requested_action = 2;
                if (check_path_obstructed(this, &((TObjChara *)target)->body_center) == 1) {
                    velocity.x = velocity.y = velocity.z = 0.0f;
                } else {
                    calc_velocity_toward_destination(this, body_center, ((TObjChara *)target)->body_center, ((GibblesMoveParams *)movementParameters)->speed);
                }
            }
        }
        break;
    case 1:
        requested_action = 2;
        if (is_passing_frame(5.0f) != 0) {
            phase = 2;
            play_sound_effect(resolve_sound_id(0x3AD34), &position, 0, 0);
        }
        break;
    case 2:
        requested_action = 2;
        if (is_passing_frame(8.0f) != 0) {
            slam_damage_players(0x1F);
        } else {
            TObjEneGibbles__sub_802D9644(this, 0, 0.0f);
        }
        if (13.0f <= frame && frame <= 19.0f) {
            sub_802D8034();
        }
        if (is_passing_frame(15.0f) != 0) {
            phase = 3;
        }
        break;
    case 3:
        requested_action = 2;
        move_with_wall_slide((u8 *)this);
        if (is_passing_frame(19.0f) != 0) {
            phase = 4;
            play_sound_effect(resolve_sound_id(0x3AD34), &position, 0, 0);
        }
        break;
    case 4:
        requested_action = 2;
        if (is_passing_frame(23.0f) != 0) {
            slam_damage_players(0x35);
        } else {
            TObjEneGibbles__sub_802D9824(this, 0, 0.0f);
        }
        if (24.0f <= frame && frame <= 34.0f) {
            sub_802D8034();
        }
        if (is_passing_frame(31.0f) != 0) {
            phase = 5;
        }
        break;
    case 5:
        requested_action = 2;
        move_with_wall_slide((u8 *)this);
        if (is_passing_frame(38.0f) != 0) {
            phase = 6;
            play_sound_effect(resolve_sound_id(0x3AD34), &position, 0, 0);
        }
        break;
    case 6:
        requested_action = 2;
        if (is_passing_frame(40.0f) != 0) {
            slam_damage_players(0x1F);
        } else {
            TObjEneGibbles__sub_802D9644(this, 0, 0.0f);
        }
        if (43.0f <= frame && frame <= 54.0f) {
            sub_802D8034();
        }
        if (is_passing_frame((frame_count - 1.0f) - play_speed) != 0) {
            requested_action = 0;
            phase = 7;
            resetTimer = (s16)TObjEneGibbles__ai_parameters->attack_recovery;
        }
        break;
    case 7:
        if (--resetTimer < 0) {
            requested_action = 1;
            phase = 0;
            actorFlags &= 0xFFDFFFFF;
            resetTimer = 0;
            status_flags &= ~0x100;
        }
        break;
    }
    play_distance_sound();
    advance_animation();
    clamp_angle(0);
    check_object_collisions();
    check_enemy_body_collisions(this);
    update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

void TObjEneGibbles::state_punch() {
    TObjPlayer *p;
    u16 id;
    id = targetId;
    if (id < 0x1000) {
        p = get_player_by_client_id(id);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            target = (u8 *)p;
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
    play_ground_contact_sound();
    advance_animation();
    clamp_angle(0);
    switch (phase) {
    case 0:
        phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        status_flags |= 0x100;
        play_sound_effect(resolve_sound_id(0x3AD2E), &position, 0, 0);
        break;
    case 1:
    case 2:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        if (is_passing_frame(10.0f) != 0) {
            play_sound_effect(resolve_sound_id(0x3A82D), &body_center, 0, 0);
        }
        if (is_passing_frame(24.0f) != 0) {
            phase = 2;
        }
        if (phase == 1) {
            TObjEneGibbles__sub_802D9644(this, 1, get_attack_params_atp_min(gibbles_combat_stat_entries[2]));
        }
        if (action_flags != 4) {
            phase = 3;
            combo_count++;
        }
        break;
    case 3:
        update_move_state();
        if (combo_count >= 2) {
            combo_count = 0;
            status_flags &= ~0x108;
        }
        actorFlags &= 0xFFDFFFFF;
        break;
    }
    check_object_collisions();
    check_enemy_body_collisions(this);
    update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}
void TObjEneGibbles::state_jump_attack() {
    if (targetId < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(targetId);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            target = (u8 *)p;
        } else {
            target = NULL;
        }
    } else if (targetId < 0x4000) {
        target = get_enemy_entity(targetId);
    } else {
        targetId = 0xFFFF;
        target = NULL;
    }
    advance_animation();
    clamp_angle(0);
    switch (phase) {
    case 2:
        break;
    case 0:
        jump_height = 0.0f;
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        wait_timer = 0;
        if (status_flags & 0x80) {
            wait_frames = TObjEneGibbles__ai_parameters->wait_frames;
            set_min_clamped_entry_value(6, TObjEneGibbles__ai_parameters->landing_speed);
        } else {
            wait_frames = TObjEneGibbles__ai_parameters->wait_frames;
            set_min_clamped_entry_value(6, TObjEneGibbles__ai_parameters->landing_speed);
        }
        phase = 4;
        actorFlags &= 0xF9FFFFFF;
        status_flags &= ~0x80;
        status_flags |= 0x100;
        break;
    case 4:
        wait_timer++;
        if (wait_timer >= wait_frames) {
            if (target != NULL) {
                Vec v;
                if (select_enemy_destination(this, ((TObjChara *)target)->body_center, 1) != 0) {
                    f32 dist;
                    phase = 1;
                    copy_position_if_valid(this, body_center);
                    VecCopy(&v, &move_destination);
                    subtract_vector(&v, &body_center);
                    dist = newton_sqrtf(v.x * v.x + v.z * v.z);
                    dist -= 15.0f;
                    calc_velocity_toward_destination(this, move_origin, move_destination, 0.026923077f * dist);
                    play_sound_effect(resolve_sound_id(0x3A82F), &position, 0, 0);
                    jump_speed = 12.5f;
                    requested_action = 5;
                    actorFlags |= 0x06000000;
                    bodies->flags &= ~1;
                    goto done;
                }
            }
            enemy_set_heading_velocity(0.0f, this, rotation_y);
            status_flags &= ~0x100;
            mode = 3;
            phase = 0;
            requested_action = 1;
            actorFlags &= 0xF9FBFFFF;
        done:
            spawn_ground_contact_effect();
        }
        submit_cursor_candidate(this, -1);
        break;
    case 1:
        if (frame >= 8.0f) {
            move_with_wall_slide((u8 *)this);
            jump_height += jump_speed;
            if (frame >= 25.0f) {
                jump_speed -= 1.0989012f;
            } else {
                jump_speed -= 0.5f;
            }
        }
        if (is_passing_frame(frame_count - 1.0f - play_speed) != 0) {
            phase = 3;
            jump_height = 0.0f;
            switch (landing_damage_players()) {
            case 0:
                TObjEneGibbles__sub_800D8988(&position);
                break;
            case 1:
            default:
                play_sound_effect(resolve_sound_id(0x3AD32), &position, 0, 0);
                break;
            }
            actorFlags &= 0xF9FFFFFF;
            bodies->flags |= 1;
            status_flags &= ~0x10;
            requested_action = 6;
            shake_camera_in_room();
        }
        break;
    case 3:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        if (is_passing_frame(frame_count - 1.0f - play_speed) != 0) {
            actorFlags &= ~0x200000;
            enemy_set_heading_velocity(0.0f, this, rotation_y);
            status_flags &= ~0x100;
            mode = 3;
            phase = 0;
            requested_action = 1;
            actorFlags &= 0xF9FBFFFF;
        }
        submit_cursor_candidate(this, -1);
        break;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

#pragma pop
int TObjEneGibbles::test_flag_256() {
    Vec v;
    TObjPlayer *pl;
    s32 i;
    s32 flags;
    flags = this->status_flags;
    if (flags & 0x20) {
        return 1;
    }
    if ((flags & 4) && this->mode != 6 && this->armor > 0) {
        for (i = 0; i < registered_player_count; i++) {
            pl = TObjPlayer::get_player_data(i);
            if (pl != NULL && !(pl->actorFlags & 0x800)
                && TObjPlayer::calc_distance_to_client((saddr)this, i, &v) < 900.0f
                && angle_difference_abs(this->rotation_y, (s32) (10430.38043493439 * atan2_float(v.x, v.z))) < 0x2AAA
                && pl->test_action_mask(0xE0) != 0) {
                VecCopy(&v, &body_center);
                subtract_vector(&v, &pl->body_center);
                if (angle_difference_abs(pl->rotation_y, (s32) (10430.38043493439 * atan2_float(v.x, v.z))) < 0x2AAA) {
                    this->guarded_player = pl;
                    this->status_flags |= 0x20;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void TObjEneGibbles::run_miss_reaction() {
    if (this->mode != 7 && this->mode != 6) {
        this->mode = 7;
        this->phase = 0;
        this->requested_action = 7;
    }
    this->bodies->flags |= 1;
    this->actorFlags &= 0xF99BFFFF;
}

#pragma push
#pragma fp_contract on
void TObjEneGibbles::state_guard() {
    this->advance_animation();
    this->clamp_angle(0);
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(this, NULL, 0.0f);
    }
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        if (this->guarded_player != NULL) {
            this->armor = (s16)((f32)this->armor - 0.2f * (f32)(this->guarded_player->get_atp() + this->guarded_player->get_actor_attack_params_atp_min() + this->guarded_player->get_atp_range() - this->dfp));
            if (this->armor <= 0) {
                this->armor = 0;
                this->status_flags |= 8;
            }
        }
        this->actorFlags |= 0x04000000;
        play_sound_effect(this->resolve_sound_id(0x3A330), &position, 0, 0);
        break;
    case 1:
        if (this->is_passing_frame(5.0f) != 0) {
            this->armor_state = 0x107;
        }
        if (this->is_passing_frame(12.0f) != 0) {
            this->actorFlags &= 0xFBFFFEFF;
            this->status_flags &= ~0x20;
            if (this->test_flag_256() != 0) {
                this->phase = 0;
                this->frame = 0.0f;
            } else {
                this->phase = 3;
            }
            this->update_move_state();
        }
        break;
    case 3:
    default:
        this->actorFlags &= 0xFBFFFEFF;
        this->status_flags &= ~0x20;
        break;
    }
    check_object_collisions();
    check_enemy_body_collisions(this);
    update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    this->actorFlags &= 0xFFDFFFFF;
}

#pragma pop
void TObjEneGibbles::run_hit_reaction() {
    if (this->mode != 8) {
        if (this->status_flags & 0x100) {
            s32 i;
            this->referenceHp = this->hp;
            this->actorFlags &= ~0x200;
            this->hit_flags = 0;
            for (i = 0; i < this->body_count; i++) {
                bodies[i].flags &= ~0x04000000;
            }
        } else {
            Vec v;
            TObjPlayer *pl = get_player_by_client_id(this->attacker_id);
            if (pl != NULL) {
                VecCopy(&v, &pl->body_center);
                subtract_vector(&v, &body_center);
                angle_difference_abs(this->rotation_y, (s32) (10430.38043493439 * atan2_float(v.x, v.z)));
            }
            this->mode = 8;
            this->requested_action = 8;
            this->phase = 0;
            this->actorFlags &= 0xF9DBFFFF;
        }
    }
    bodies->flags |= 1;
}

void TObjEneGibbles::update_action_state() {
    advance_animation();
    clamp_angle(0);
    switch (this->phase) {
    case 2:
        break;
    case 0:
        this->phase = 1;
        apply_actor_gravity(this, NULL, 0.0f);
        play_sound_effect(resolve_sound_id(0x3AD34), &position, 0, 0);
        break;
    case 1:
        this->velocity.z = 0.0f;
        this->velocity.x = 0.0f;
        apply_actor_gravity(this, NULL, 0.0f);
        if ((u32) this->action_flags != 8U) {
            this->phase = 3;
        }
        break;
    case 3:
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        this->actorFlags &= 0xFFFFF9FF;
        this->bodies->flags &= 0xFBFFFFFF;
        this->referenceHp = (s16) this->hp;
        if (random_ratio() < this->hit_jump_chance) {
            this->mode = 6;
            this->phase = 0;
            this->requested_action = 4;
            this->status_flags |= 0x90;
        }
        break;
    }
    check_object_collisions();
    check_enemy_body_collisions(this);
    update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
    this->actorFlags &= 0xFFDFFFFF;
}

void TObjEneGibbles::run_death_reaction() {
    if (this->mode != 9) {
        this->mode = 9;
        this->phase = 0;
        this->requested_action = 9;
        this->bodies->flags &= 0xFFFFFFFE;
        refresh_lobby_state();
        send_entity_set_flags();
    }
}

void TObjEneGibbles::state_dead() {
    Vec point;
    switch (this->phase) {
    case 0:
        this->phase = 1;
        this->state_timer = 0.0f;
        apply_actor_gravity(this, NULL, 0.0f);
        play_sound_effect(this->resolve_sound_id(0x3A333), &position, 0, 0);
        return;
    case 1:
        advance_animation();
        if (this->motion_flags & 0x10) {
            this->phase = 4;
            point.x = 0.0f;
            point.y = 0.0f;
            point.z = -10.0f;
            rotate_xz_pair_by_angle(&point.x, &point.z, this->rotation_y);
            vec3_add_to(&point, &position);
            TObjPlayer__sub_800D93C4((saddr)&point, 0xA);
            spawn_effect_at_ground(&point, 0x46);
        }
    case 2:
        return;
    case 4:
        this->position.y -= 0.1f;
        this->state_timer += 0.1f;
        if (this->state_timer > 25.0f) {
            this->phase = 3;
            return;
        }
        break;
    case 3:
        queue_destruction();
        break;
    }
}

void TObjEneGibbles::update_move_state() {
    if (this->armor_max == this->armor) {
        this->armor_state = 0x101;
        return;
    }
    if ((0.5f * (f32) this->armor_max) < (f32) this->armor) {
        this->armor_state = 0x102;
        return;
    }
    if (this->armor > 0) {
        this->armor_state = 0x103;
        return;
    }
    this->armor_state = 0;
}

void TObjEneGibbles::sync_state() {
    switch (this->armor_state) {
    case 0x0:
        break;
    default:
        update_move_state();
    case 0x107:
    case 0x10E:
        if (this->status_flags & 4) {
            if (this->reported_armor_state != this->armor_state) {
                this->reported_armor_state = this->armor_state;
            }
        }
        break;
    }
}

void TObjEneGibbles::sub_802D8034() {}

u32 TObjEneGibbles::resolve_sound_id(u32 sound_id) {
    s32 area;
    u32 id;
    area = get_current_floor_area();
    if (sound_id == 0x3A83D) {
        id = 0x4003A321;
        if (area != AREA_TOWER) {
            id = sound_id;
        }
    } else if (sound_id == 0x3A83E) {
        id = 0x4003A322;
        if (area != AREA_TOWER) {
            id = sound_id;
        }
    } else if (sound_id == 0x3A83F) {
        id = 0x4003A323;
        if (area != AREA_TOWER) {
            id = sound_id;
        }
    } else {
        id = this->remap_sound_for_area(sound_id);
    }
    return id;
}

void TObjEneGibbles::render_and_get_joint_pos(Vec *out, s32 node) {
    set_motion_packed_rotation();
    push_matrix_from(identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    scale_matrix_vec3(NULL, (u8 *)&scale);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[node]);
    Vec origin = gibbles_joint_zero_vec;
    matrix_mult_vec(NULL, &origin, out);
    pop_matrix();
    clear_motion_packed_rotation();
}
void TObjEneGibbles::update_position() {
    VecCopy(&this->body_center, &this->position);
    this->body_center.y += 15.0f;
    switch (this->mode) {
    case 2:
    case 6:
    case 0xA:
        this->body_center.y += this->jump_height;
        break;
    }
}

void TObjEneGibbles::update_shadow_height() {
    this->bodies->offset.y = this->body_center.y - this->position.y;
}

void TObjEneGibbles::sub_802D7E3C() {}

void TObjEneGibbles::play_ground_contact_sound() {
    if (is_passing_frame(7.0f) != 0 || is_passing_frame(20.0f) != 0) {
        if (spawn_ground_impact_effects(&position, 3.0f) != 0) {
            TObjEneGibbles__sub_800D8988(&position);
            return;
        }
        play_sound_effect(resolve_sound_id(0x3A82B), &position, 0, 0);
    }
}

void TObjEneGibbles::play_distance_sound() {
    if (is_passing_frame(8.0f) != 0) {
        if (spawn_ground_impact_effects(&position, 3.0f) != 0) {
            TObjEneGibbles__sub_800D8988(&position);
            return;
        }
        play_sound_effect(resolve_sound_id(0x3A83D), &position, 0, 0);
        return;
    }
    if (is_passing_frame(23.0f) != 0) {
        if (spawn_ground_impact_effects(&position, 3.0f) != 0) {
            TObjEneGibbles__sub_800D8988(&position);
            return;
        }
        play_sound_effect(resolve_sound_id(0x3A83E), &position, 0, 0);
        return;
    }
    if (is_passing_frame(40.0f) != 0) {
        if (spawn_ground_impact_effects(&position, 3.0f) != 0) {
            TObjEneGibbles__sub_800D8988(&position);
            return;
        }
        play_sound_effect(resolve_sound_id(0x3A83F), &position, 0, 0);
    }
}

s32 TObjEneGibbles::spawn_ground_contact_effect() {
    Vec point;
    VecCopy(&point, &position);
    point.y += 15.0f;
    CsnHit *hit = csnVectorUnder(&point, (CsnGroup **)&m_120, 0x15);
    if (hit != NULL) {
        if (hit->hit_mask & 4) {
            spawn_ground_impact_effects(&position, 3.0f);
            return 0;
        }
        spawn_particle_effect(&position, 0x20E);
        return 1;
    }
    return 2;
}

s32 TObjEneGibbles::spawn_ground_impact_effects(const Vec *pos, f32 scale) {
    Vec point;
    if (scale <= 0.0f) {
        return 0;
    }
    VecCopy(&point, pos);
    point.y += 15.0f;
    CsnHit *hit = csnVectorUnder(&point, (CsnGroup **)&m_120, 5);
    if (hit != NULL && (hit->hit_mask & 4) != 0) {
        TParticleCtrl *spray = (TParticleCtrl *)spawn_particle_effect(&hit->contact[2].point, 0x49);
        if (spray != NULL) {
            attach_particle_model((u8 *)spray, TParticleCtrl::get_particle_model(2),
                                  TParticleCtrl::get_instance(), 0, 1, 1.0f);
            spray->set_scale(scale, 1.0f);
        }
        TParticleCtrl *ripple = (TParticleCtrl *)spawn_particle_effect(&hit->contact[2].point, 0xA4);
        if (ripple != NULL) {
            ripple->set_scale(scale, 1.5f);
        }
        return 1;
    }
    return 0;
}

void TObjEneGibbles::shake_camera_in_room() {
    s16 t;
    s16 u;
    TObjPlayer *r;
    if ((get_main_phase() == 0xF || is_split_screen() == 0) && (r = get_player_by_client_id(local_client_id)) != 0) {
        t = (s32)((TObjBase *)r)->get_room();
        u = (s32)get_room();
        if (u == t) {
            start_camera_shake(0x1E, 0.1f);
        }
    }
}
void TObjEneGibbles::set_min_clamped_entry_value(s32 action, f32 speed) {
    if (speed < 0.1f) {
        speed = 0.1f;
    }
    gibbles_action_table[action].speed = speed;
}

