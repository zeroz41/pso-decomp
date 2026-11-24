#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/enemy/illgill/TObjIllGillKage.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/illgill/TObjEneIllGill.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/TLobby.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/math/ScratchVectors.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/object/base/TObjBase.h"
struct IllGillEffectRotation { s32 x, y, z; };
extern int enable_v2_features;
extern "C" {
BmlResource * illGillResource;
player_stats *TObjEneIllGill__boss_registration_id;
ActorParamBlock *TObjEneIllGill__resistance_params;
IllGillAttackBehavior * illGillAttackBehavior;
s32 illGillModelNodeIndex;
}
extern "C" {
extern const char *TObjEneIllGill_model_file_list[2];
extern const char *TObjEneIllGill_motion_name_table[11];
Vec illGillWeaponEffectPosition;
Vec illGillShadowEffectPosition;
Vec illGillChargeEffectPosition1;
Vec illGillChargeEffectPosition2;
u32 lbl_80543A90[4];
__declspec(section ".data") const char *TObjEneIllGill_model_file_list[2] = {
    "darkand_body.nj", NULL,
};
const char *TObjEneIllGill_motion_name_table[11] = {
    "wait_darkand_body.njm", "walk_darkand_body.njm", "kamae_darkand_body.njm", "tackle_darkand_body.njm",
    "lattack_darkand_body.njm", "rattack_darkand_body.njm", "damage_darkand_body.njm", "prekamae_darkand_body.njm",
    "kage_darkand_body.njm", "dead_darkand_body.njm", NULL,
};
BmlResourceDescriptor illGillResourceDescriptor = {
    "bm_ene_ill_gill.bml", TObjEneIllGill_model_file_list,
    TObjEneIllGill_motion_name_table, 1, 10
};
TObjMotionAction illGillActions[10] = {
    {1, 0, 0, 0.6f, 1},
    {1, 1, 1, 0.8f, 1},
    {2, 0, 4, 1.0f, 4},
    {2, 0, 5, 1.0f, 4},
    {2, 0, 8, 1.0f, 4},
    {2, 0, 6, 1.0f, 8},
    {3, 5, 9, 1.0f, 0x10},
    {2, 8, 7, 1.0f, 0x20},
    {3, 9, 2, 1.0f, 0x20},
    {2, 0, 3, 1.0f, 0x20},
};
IllGillMovementParameters illGillMovement = {
    400.0f, 0.9f, 0x400, {0x1e0000, 0, 1, 0}
};
CollisionBody illGillCollisionBody = {
    {0.0f, 13.200001f, 0.0f}, 7.2000003f, 0.0f, 0, 0x8003,
    {0.0f, 0.0f, 0.0f}, 0.0f
};
AttackParams *ill_gill_combat_parameter_variants[4] = {0, 0, 0, 0};
const char *TObjEneIllGill_class_name = "TObjEneIllGill";
const NpcAnimationBinding illGillAnimBinding = { NULL, illGillActions, 0, 1, 10 };
const Vec lbl_8047A328 = {0.0f, 0.0f, 0.0f};
const char *TObjIllGillKage__class_name = "TObjIllGillKage";
}

#pragma defer_codegen on
void TObjEneIllGill::load_shared_resources() {
    BmlResource *resource;
    Vec *q;

    illGillResource = new BmlResource(1, &illGillResourceDescriptor, 0, 0, NULL);
    TObjEneIllGill__boss_registration_id = TLobby::register_boss(0x26);
    ill_gill_combat_parameter_variants[0] = TLobby::dispatch_shared_handler_b(0x26);
    ill_gill_combat_parameter_variants[1] = TLobby::dispatch_shared_handler_b(0x27);
    ill_gill_combat_parameter_variants[2] = TLobby::dispatch_shared_handler_b(0x28);
    ill_gill_combat_parameter_variants[3] = TLobby::dispatch_shared_handler_b(0x29);
    TObjEneIllGill__resistance_params = TLobby::register_object(0x26);
    illGillAttackBehavior = (IllGillAttackBehavior *)TLobby::dispatch_shared_handler_a(0x26);
    illGillModelNodeIndex = 0;
    q = &illGillWeaponEffectPosition;
    q->x = q->y = q->z = 0.0f;
    q = &illGillShadowEffectPosition;
    q->x = q->y = q->z = 0.0f;
    q = &illGillChargeEffectPosition1;
    q->x = q->y = q->z = 0.0f;
    q = &illGillChargeEffectPosition2;
    q->x = q->y = q->z = 0.0f;
    {
        NpcAnimationBinding pos = illGillAnimBinding;
        resource = illGillResource;
        pos.motions = resource->motions;
        TObjNpcEnemy::register_animated_chunk((s16)0x43, resource->models->model, resource->models->texlist, &pos, illGillCollisionBody.radius, 0.0f);
    }
}

void TObjEneIllGill::free_effect() {
    delete illGillResource;
    illGillResource = NULL;
}

TObjEneIllGill::TObjEneIllGill(TObject *parent, void *setData) : TObjEnemy(parent) {
    u8 *self = (u8 *)this;
    m_name = TObjEneIllGill_class_name;
    this->set_param(0x52);
    this->apply_set_data(setData);
    this->clear_lobby_object_state();
    init_position_vectors();
    apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
    model = (void *)illGillResource->models->model;
    texlist = illGillResource->models->texlist;
    motion_list = illGillResource->motions;
    action_table = illGillActions;
    this->set_action_table(action_table);
    requested_action = 0;
    this->set_animation(requested_action);
    this->set_requested_action(requested_action);
    this->enable_motion_blend();
    scale.x = 1.2f;
    scale.y = 1.2f;
    scale.z = 1.2f;
    this->add_flags_2e4(8);
    init_collision_body_parts(this, &illGillCollisionBody, 1);
    this->update_prev_position();
    copy_position();
    register_object_by_id();
    movementParameters = &illGillMovement;
    attackType = 0;
    this->bind_enemy_combat_stats(TObjEneIllGill__boss_registration_id, ill_gill_combat_parameter_variants[attackType], TObjEneIllGill__resistance_params);
    deathTimer = 0;
    mode = 0;
    phase = 0;
    weaponSpecial = 0;
    hitFrame = 0;
    weaponEffectPosition.z = 0.0f;
    weaponEffectPosition.y = 0.0f;
    weaponEffectPosition.x = 0.0f;
    shadowEffectPosition.z = 0.0f;
    shadowEffectPosition.y = 0.0f;
    shadowEffectPosition.x = 0.0f;
    chargeEffectPosition1.z = 0.0f;
    chargeEffectPosition1.y = 0.0f;
    chargeEffectPosition1.x = 0.0f;
    chargeEffectPosition2.z = 0.0f;
    chargeEffectPosition2.y = 0.0f;
    chargeEffectPosition2.x = 0.0f;
    tertiaryEffect = 0;
    secondaryEffect = 0;
    primaryEffect = 0;
    chargeDistance = 0.0f;
    chargeFrames = 0;
    viewDetail = 0;
    fade.reset_obstruction_fade();
    fadingIn = 1;
    this->clear_charge_hits();
    if (0.0f != parameters[0]) {
        actorFlags |= 0x2000;
        target = 0;
        targetId = 0xFFFF;
        VecCopy(&move_origin, &body_center);
        VecCopy(&move_destination, &body_center);
        chargeDistance = 0.0f;
    }
}

TObjEneIllGill::~TObjEneIllGill() {
    free_resources();
    free_collision_body_parts(this);
}

void *TObjEneIllGill::create(void *setData) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneIllGill(parent, setData);
}

void TObjEneIllGill::run_task() {
    TObjEneIllGill *o = this;
    switch (o->mode) {
    case 0:
        update_idle();
        break;
    case 1:
        update_forward_movement();
        break;
    case 2:
        update_chase_target();
        break;
    case 3:
        update_weapon_attack();
        break;
    case 4:
        update_charge_attack();
        break;
    case 5:
        update_shadow_attack();
        break;
    case 6:
        sub_803669B0();
        break;
    case 7:
        update_damage_recovery();
        break;
    case 8:
        update_death_fall();
        break;
    case 9:
        break;
    }
    if (o->target != NULL && (((TObjChara *)o->target)->actorFlags & 0x02000800)) {
        o->actionTimer = 0;
        o->actorFlags &= ~0x200000;
        o->target = NULL;
    }
    o->update_prev_position();
    o->copy_position();
    submit_cursor_candidate(o, -1);
    o->frame_timer += 1.0f;
}

void TObjEneIllGill::render() {
    u8 *self = (u8 *)this;

    if (((s32 (*)(void *))is_split_screen)(self) != 0) {
        TCameraCtrl::get_camera_mode();
    }
    this->viewDetail = classify_actor_view_detail(250.0f, 500.0f, 40.0f);
    if (this->viewDetail != 0) {
        select_actor_lighting(this);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, this->scale.x, this->scale.y, this->scale.z);
        illGillModelNodeIndex = 0;
        set_chunk_model_node_callback(TObjEneIllGill::capture_effect_positions);
        if (this->fadingIn != 0 && TObjPlayer::check_demo_mode() == 0) {
            if (fade.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                fade.set_flags_and_apply_damage_color();
                ((TObjMotion *)self)->draw();
                fade.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else if (this->viewDetail == 1) {
            ((TObjMotion *)self)->draw();
        } else {
            ((TObjEnemy *)self)->draw_motion_model();
        }
        set_chunk_model_node_callback(NULL);
        VecCopy(&weaponEffectPosition, (const Vec *)&illGillWeaponEffectPosition);
        VecCopy(&shadowEffectPosition, (const Vec *)&illGillShadowEffectPosition);
        VecCopy(&chargeEffectPosition1, (const Vec *)&illGillChargeEffectPosition1);
        VecCopy(&chargeEffectPosition2, (const Vec *)&illGillChargeEffectPosition2);
        pop_matrix();
    }
}

#pragma push
#pragma opt_loop_invariants off
void TObjEneIllGill::refresh_target() {
    u16 best;
    s32 i;
    u8 *pl;
    u16 id;
    f32 bestDist;
    f32 d;
    u16 t;
    TObjPlayer *ent;
    if (is_actor_cadence_frame(0x1E) != 0) {
        if (fadingIn != 0) {
            targetId = 0xFFFF;
            target = 0;
            return;
        }
        if (test_actor_flags(0x10) != 0) {
            i = 0;
            best = 0xFFFF;
            Vec v = lbl_8047A328;
            bestDist = ((IllGillMovementParameters *)movementParameters)->range * ((IllGillMovementParameters *)movementParameters)->range;
            for (; i < registered_player_count + registered_enemy_count; i++) {
                pl = (u8 *)TObjPlayer::get_player_data(i);
                if (pl == NULL) break;
                if (obj_is_hit_receivable(reinterpret_cast<TObjCollidable *>(pl)) == 0) continue;
                id = reinterpret_cast<TObjBase *>(pl)->get_entity_id();
                if (id >= 0x4000) continue;
                if (id == entity_id) continue;
                if (((TObjChara *)pl)->actorFlags & 0x02000800) continue;
                VecCopy(&v, (const Vec *)(pl + offsetof(TObjChara, body_center)));
                subtract_vector(&v, &body_center);
                d = v.x * v.x + v.z * v.z;
                if (d < bestDist && check_path_obstructed(this, &((TObjChara *)pl)->body_center) == 0) {
                    best = id;
                    bestDist = d;
                }
            }
            targetId = best;
        } else {
            targetId = find_nearest_visible_player(this, NULL, ((IllGillMovementParameters *)movementParameters)->range);
        }
        t = targetId;
        if (t < 0x1000) {
            ent = get_player_by_client_id(t);
            if (ent != 0) {
                if (ent->get_floor() == get_current_floor()) {
                    target = ent;
                    clear_actor_flags(0x04040000);
                    return;
                }
            }
            target = 0;
            set_actor_flags(0x04040000);
            return;
        }
        if (t < 0x4000) {
            target = get_enemy_entity(t);
            clear_actor_flags(0x04040000);
        }
    }
}

#pragma pop
s32 TObjEneIllGill::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        switch (mode) {
        default: break;
        case 0:
            fadingIn = 0;
            phase = 0;
            requested_action = 1;
            clear_actor_flags(0x04040000);
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneIllGill::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        switch (mode) {
        default: break;
        case 0:
            fadingIn = 0;
            phase = 0;
            requested_action = 1;
            clear_actor_flags(0x04040000);
            break;
        }
        return 1;
    }
    return 0;
}

void TObjEneIllGill::run_idle_action() {
    switch (mode) {
    case 0:
        switch (phase) {
        case 0:
        case 1:
            break;
        default:
            phase = 2;
            if ((s32)fadingIn != 0) {
                phase = 0;
            }
            break;
        }
        break;
    default:
        mode = 0;
        if ((s32)fadingIn != 0) {
            phase = 0;
        } else {
            phase = 2;
        }
        requested_action = 1;
        free_resources();
        break;
    }
}

s32 TObjEneIllGill::project_step_to_ground(s32 angle) {
    lbl_8050BF00.y = 0.0f;
    lbl_8050BF00.x = 0.0f;
    lbl_8050BF00.z = ((IllGillMovementParameters *)movementParameters)->speed;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, angle);
    rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
    pop_matrices(1);
    vec3_add_to(&lbl_8050BF00, &position);
    return project_actor_to_ground(this, &lbl_8050BF00, 0);
}

void TObjEneIllGill::clear_charge_hits() {
    for (s32 i = 0; i < 4; i++) {
        chargeHits[i] = NULL;
    }
}

void TObjEneIllGill::move_toward_dest_with_detour() {
    TObjEneIllGill *o = this;
    s32 ang;
    VecCopy(&o->move_destination, (const Vec *)&o->home_position);
    VecCopy(&o->move_origin, (const Vec *)&o->body_center);
    VecCopy((Vec *)&o->prev_position, (const Vec *)&o->position);
    VecCopy((Vec *)&scratch_vec, (const Vec *)&o->home_position);
    subtract_vector(&scratch_vec, &o->position);
    ang = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, scratch_vec.z));
    if (o->project_step_to_ground(ang) == 1) {
        o->requested_action = 1;
        VecCopy((Vec *)&o->position, (const Vec *)&lbl_8050BF00);
        o->rotation_y = approach_angle_limited(o->rotation_y, ang, ((IllGillMovementParameters *)o->movementParameters)->turn);
    } else {
        if (fabs_float(scratch_vec.x) < fabs_float(scratch_vec.z)) {
            ang = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, 0.0f));
        } else {
            ang = (s32)(10430.38043493439 * atan2_float(0.0f, scratch_vec.z));
        }
        if (o->project_step_to_ground(ang) == 1) {
            o->requested_action = 1;
            VecCopy((Vec *)&o->position, (const Vec *)&lbl_8050BF00);
            o->rotation_y = approach_angle_limited(o->rotation_y, ang, ((IllGillMovementParameters *)o->movementParameters)->turn);
        } else {
            if (fabs_float(scratch_vec.x) < fabs_float(scratch_vec.z)) {
                ang = (s32)(10430.38043493439 * atan2_float(0.0f, scratch_vec.z));
            } else {
                ang = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, 0.0f));
            }
            if (o->project_step_to_ground(ang) == 1) {
                o->requested_action = 1;
                VecCopy((Vec *)&o->position, (const Vec *)&lbl_8050BF00);
                o->rotation_y = approach_angle_limited(o->rotation_y, ang, ((IllGillMovementParameters *)o->movementParameters)->turn);
            } else {
                o->requested_action = 0;
            }
        }
    }
    ((TObjEnemy *)o)->enemy_turn_toward_dest(((IllGillMovementParameters *)o->movementParameters)->turn);
    enemy_set_heading_velocity(((IllGillMovementParameters *)o->movementParameters)->speed, (TObjEnemy *)(o), o->rotation_y);
    (*(&o->body_center)).y += 5.0f;
    move_with_wall_slide(o);
}

void TObjEneIllGill::update_idle() {
    u8 *self = (u8 *)this;
    IllGillMovementParameters *movement;

    ((TObjMotion *)self)->advance_animation();
    switch (this->phase) {
    case 0:
        ((TObjBase *)self)->set_actor_flags(0x04040000);
        ((TUnk_80494938 *)(&this->fade))->start_fade_in();
        play_area_se_with_particle(&position);
        this->phase = 1;
        break;
    case 1:
        ((TObjBase *)self)->set_actor_flags(0x04040000);
        if (fade.advance_toward_max() == 1) {
            this->phase = 2;
            this->requested_action = 1;
            this->fadingIn = 0;
        }
        break;
    case 2:
        ((TObjBase *)self)->clear_actor_flags(0x04040000);
        this->requested_action = 1;
        if (horizontal_distance_squared(&this->position, &this->home_position) > 10000.0f) {
            move_toward_dest_with_detour();
        } else {
            this->body_center.y += 5.0f;
            movement = (IllGillMovementParameters *)movementParameters;
            ((TObjEnemy *)self)->enemy_wander_home((f32) (0.25f * movement->speed), 100.0f, 50.0f, movement->turn);
        }
        ((TObjCollidable *)self)->refresh_collision_body_centers();
        break;
    default:
        this->requested_action = 0;
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        }
        break;
    }
    minimap_render_dot(&this->position, -0x5DB4, 1, 0);
    ((TObjBase *)self)->clear_actor_flags(0x200000);
}

void TObjEneIllGill::update_forward_movement() {
    u8 *player = (u8 *)this;
    Vec v;
    f32 d;
    f32 a;
    f32 b;
    IllGillMovementParameters *movement;
    this->requested_action = 0;
    ((TObjMotion *)player)->advance_animation();
    ((TObjBase *)player)->set_actor_flags(0x04040000);
    v.y = 0.0f;
    v.x = 0.0f;
    v.z = 1.0f;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrices(1);
    vec3_add_to(&v, &home_position);
    this->body_center.y += 5.0f;
    d = step_toward_destination(this, v, 2.0f * ((IllGillMovementParameters *)movementParameters)->speed);
    movement = (IllGillMovementParameters *)movementParameters;
    a = movement->range * movement->range;
    b = movement->speed * movement->speed;
    if (a < d || d < b) {
        this->target = 0;
    }
    apply_actor_gravity((TObjEnemy *)player, (s32 *)(0), 0.0f);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::run_move_action() {
    TObjEneIllGill *enemy = this;
    if (enemy->mode >= 3 || enemy->mode < 1) {
        enemy->requested_action = 1;
        enemy->mode = 2;
        enemy->phase = 0;
        enemy->clear_actor_flags((int)(0x04040000U));
        enemy->free_resources();
    }
}

void TObjEneIllGill::update_chase_target() {
    u8 *self = (u8 *)this;
    f32 r;
    s32 id;
    f32 d;
    s32 a;
    f32 t;
    ((TObjBase *)self)->clear_actor_flags(0x04040000);
    r = ((IllGillMovementParameters *)movementParameters)->speed;
    id = ((IllGillMovementParameters *)movementParameters)->turn;
    ((TObjMotion *)self)->advance_animation();
    if (this->target != NULL) {
        switch (this->phase) {
        default:
        case 1:
            this->phase = 0;
        case 0: {
            Vec dir;
            this->body_center.y += 5.0f;
            d = enemy_move_toward(this, id, ((TObjChara *)target)->body_center, 0, 0.125f * r);
            VecCopy(&dir, (const Vec *)((u8 *)&((TObjChara *)target)->body_center));
            subtract_vector(&dir, &body_center);
            a = angle_difference_abs(this->rotation_y,
                                     (s32)(10430.38043493439 * atan2_float(dir.x, dir.z)));
            if (a < this->attack_params->get_attack_angle()) {
                this->phase = 2;
            }
            break;
        }
        case 2: {
            this->body_center.y += 5.0f;
            enemy_pursue_point(this, id, ((TObjChara *)target)->body_center, r, 40.0f);
            d = horizontal_distance_squared(&move_destination, &body_center);
            t = r + this->bodies->radius;
            if (d < t * t) {
                if (this->targetId == 0xFFFF) {
                    this->target = NULL;
                } else {
                    this->phase = 0;
                }
            }
            break;
        }
        }
        t = ((IllGillMovementParameters *)movementParameters)->range;
        if (t * t < d) {
            this->target = NULL;
        }
        if (((TObjMotion *)self)->is_passing_frame(0.0f) != 0) {
            play_sound_effect(0x4003A34D, &position, 0, 0);
        }
        if (((TObjMotion *)self)->is_passing_frame(15.0f) != 0) {
            play_sound_effect(0x4003A34D, &position, 0, 0);
        }
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

s32 TObjEneIllGill::is_target_in_attack_range() {
    Vec v;
    f32 dist;
    s32 ang;
    f32 rad;
    u16 id;
    TObjChara *pl;

    if (this->target != NULL && this->attack_params != NULL && !(this->target->actorFlags & 0x02000800)) {
        if (test_actor_flags(0x2000) != 0) {
            this->attackType = 3;
            bind_enemy_combat_stats(NULL, ill_gill_combat_parameter_variants[this->attackType], NULL);
            return 1;
        }
        dist = calc_xz_distance_sq(this, this->target, &v);
        ang = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
        pl = this->target;
        if (pl->bodies != NULL) {
            rad = pl->bodies->radius - 1.0;
        } else {
            rad = 10.0f;
        }
        id = reinterpret_cast<TObjBase *>(pl)->get_entity_id();
        if (id < 0x1000) {
            s32 i;
            pl = this->target;
            if (((TObjPlayer *)pl)->check_player_flag1() == 1 || (enable_v2_features == 1 && pl->test_actor_flags(0x20) != 0)) {
                this->attack_params = ill_gill_combat_parameter_variants[0];
                if (dist <= (rad + this->attack_params->get_attack_range()) * (rad + this->attack_params->get_attack_range()) &&
                    ang <= this->attack_params->get_attack_angle()) {
                    this->attackType = 0;
                    bind_enemy_combat_stats(NULL, ill_gill_combat_parameter_variants[this->attackType], NULL);
                    return 1;
                }
                return 0;
            }
            for (i = 0; i < 4; i++) {
                f32 r2;
                s32 m;
                this->attack_params = ill_gill_combat_parameter_variants[i];
                r2 = (rad + this->attack_params->get_attack_range()) * (rad + this->attack_params->get_attack_range());
                m = this->attack_params->get_attack_angle();
                if (dist <= r2 && ang <= m) {
                    this->attackType = i;
                    bind_enemy_combat_stats(NULL, ill_gill_combat_parameter_variants[this->attackType], NULL);
                    return 1;
                }
            }
        } else if (id < 0x4000) {
            this->attack_params = ill_gill_combat_parameter_variants[0];
            if (dist <= (rad + this->attack_params->get_attack_range()) * (rad + this->attack_params->get_attack_range()) &&
                ang <= this->attack_params->get_attack_angle()) {
                this->attackType = 0;
                bind_enemy_combat_stats(NULL, ill_gill_combat_parameter_variants[this->attackType], NULL);
                return 1;
            }
        }
    }
    return 0;
}

void TObjEneIllGill::run_attack_action() {
    TObjEneIllGill *o = this;
    switch (o->attackType) {
    default:
        o->attackType = 0;
    case 0:
    case 1:
        o->mode = 3;
        o->phase = 0;
        o->requested_action = 1;
        break;
    case 2:
        o->mode = 5;
        o->phase = 0;
        o->requested_action = 1;
        break;
    case 3:
        o->mode = 4;
        o->phase = 0;
        o->requested_action = 7;
        o->chargeDistance = 0.0f;
        o->clear_charge_hits();
        break;
    }
    o->actorFlags |= 0x200000;
    o->actorFlags &= ~0x40000;
}

void TObjEneIllGill::update_weapon_attack() {
    u8 *actor = (u8 *)this;
    f32 special_param;
    f32 damage;
    s32 angle_left;
    u16 target_id;
    TParticleCtrl *primary;
    TParticleCtrl *secondary;
    TParticleCtrl *tertiary;
    TObjPlayer *player;
    TObjChara *hit_target;
    TObjChara *chase_target;
    target_id = this->targetId;
    if (target_id < 0x1000U) {
        player = get_player_by_client_id(target_id);
        if ((player != NULL) && (player->get_floor() == get_current_floor())) {
            this->target = player;
        } else {
            this->target = NULL;
        }
    } else if (target_id < 0x4000U) {
        this->target = get_enemy_entity(target_id);
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    ((TObjBase *)actor)->clear_actor_flags(0x04040000);
    {
        play_speed = illGillAttackBehavior->animationSpeed * action_table[requested_action].speed;
    }
    ((TObjMotion *)actor)->advance_animation();
    switch (this->phase) {
    default:
        this->phase = 0;
    case 0:
        chase_target = this->target;
        if (chase_target == NULL) {
            this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
            this->actionTimer = 0;
        } else {
            Vec v = chase_target->body_center;
            subtract_vector(&v, &body_center);
            angle_left = ((TObjEnemy *)actor)->turn_toward_direction((((IllGillMovementParameters *)movementParameters)->turn), &v);
            apply_actor_gravity((TObjEnemy *)actor, (s32 *)(0), 0.0f);
            if (angle_left < this->attack_params->get_attack_angle()) {
                this->phase = 2;
                special_param = this->parameters[1];
                if (0.0f == special_param) {
                    if (random_ratio() > 0.35f) {
                        if (random_ratio() > 0.5f) {
                            this->weaponSpecial = 1;
                        } else {
                            this->weaponSpecial = 2;
                        }
                    } else {
                        this->weaponSpecial = 3;
                    }
                } else {
                    this->weaponSpecial = (s32) special_param;
                }
                switch (this->weaponSpecial) {
                case 1:
                    this->requested_action = 2;
                    if (this->primaryEffect == 0U) {
                        this->primaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1E);
                    }
                    if (this->secondaryEffect == 0U) {
                        this->secondaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1F);
                    }
                    this->hitFrame = 0x1E;
                    this->tertiaryEffect = NULL;
                    play_sound_effect(0x4003A352, &position, 0, 0);
                    break;
                case 2:
                    this->requested_action = 2;
                    if (this->primaryEffect == 0U) {
                        this->primaryEffect = create_particle_emitter((&weaponEffectPosition), 0xA1);
                    }
                    if (this->secondaryEffect == 0U) {
                        this->secondaryEffect = create_particle_emitter((&weaponEffectPosition), 0x188);
                    }
                    this->hitFrame = 0x1E;
                    this->tertiaryEffect = NULL;
                    play_sound_effect(0x4003A352, &position, 0, 0);
                    break;
                case 3:
                default:
                    this->requested_action = 3;
                    if (this->primaryEffect == 0U) {
                        this->primaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1C4);
                    }
                    if (this->secondaryEffect == 0U) {
                        this->secondaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1C5);
                    }
                    if (this->tertiaryEffect == 0U) {
                        this->tertiaryEffect = create_particle_emitter((&weaponEffectPosition), 0x1C8);
                    }
                    this->hitFrame = 0x23;
                    play_sound_effect(0x4003A352, &position, 0, 0);
                    break;
                }
            }
        }
        break;
    case 2:
        apply_actor_gravity((TObjEnemy *)actor, (s32 *)(0), 0.0f);
        if (((TObjMotion *)actor)->is_passing_frame(5.0f) != 0) {
            play_sound_effect(0x4003A353, &position, 0, 0);
        }
        if (((TObjMotion *)actor)->is_passing_frame((f32)((f32) this->hitFrame)) != 0) {
            this->hitFrame = 0;
            hit_target = this->target;
            if ((hit_target != NULL) && (hit_target->select_melee_contact_body(actor, 1.0f) != 0)) {
                switch (this->weaponSpecial) {
                case 1:
                    ((TObjPlayer *)actor)->set_model_id(7);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) illGillAttackBehavior->specialParameter));
                    ((TObjChara *)(this->target))->receive_weapon_special_attack(actor, 0);
                    play_sound_effect(0x40039E54, &position, 0, 0);
                    break;
                case 2:
                    ((TObjPlayer *)actor)->set_model_id(0xA);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) illGillAttackBehavior->specialParameter));
                    ((TObjChara *)(this->target))->receive_weapon_special_attack(actor, 0);
                    play_sound_effect(0x40039E54, &position, 0, 0);
                    break;
                case 3:
                    ((TObjPlayer *)actor)->set_model_id(0xB);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) illGillAttackBehavior->thirdSpecialParameter));
                    if (((TObjChara *)(this->target))->receive_weapon_special_attack(actor, 0) <= 0.0f) {
                        ((TObjChara *)(this->target))->receive_physical_attack(actor, 1.0f);
                    }
                    play_sound_effect(0x40039E55, &position, 0, 0);
                    break;
                default:
                    damage = ((TObjChara *)(this->target))->receive_physical_attack(actor, 1.0f);
                    play_sound_effect(0x40039E54, &position, 0, 0);
                    ((TObjChara *)(this->target))->apply_knockback_from_attacker(actor, damage);
                    break;
                }
            }
        }
        primary = this->primaryEffect;
        if ((primary != 0U) && (((TObject *)primary)->all_parents_unqueued_for_destruction() != 0)) {
            ((TParticleCtrl *)this->primaryEffect)->set_position(&weaponEffectPosition);
        }
        secondary = this->secondaryEffect;
        if ((secondary != 0U) && (((TObject *)secondary)->all_parents_unqueued_for_destruction() != 0)) {
            ((TParticleCtrl *)this->secondaryEffect)->set_position(&weaponEffectPosition);
        }
        tertiary = this->tertiaryEffect;
        if ((tertiary != 0U) && (((TObject *)tertiary)->all_parents_unqueued_for_destruction() != 0)) {
            ((TParticleCtrl *)this->tertiaryEffect)->set_position(&weaponEffectPosition);
        }
        if ((u32) this->action_flags != 4U) {
            this->phase = 3;
            this->requested_action = 0;
            this->actionTimer = 0x1E;
            this->free_resources();
        }
        break;
    case 3:
        apply_actor_gravity((TObjEnemy *)actor, (s32 *)(0), 0.0f);
        this->actionTimer = (this->actionTimer - 1);
        if ((s32) this->actionTimer < 0) {
            this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
            this->actionTimer = 0;
        }
        break;
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::free_resources() {
    if (this->primaryEffect != 0U) {
        TParticleCtrl::release((void *)this->primaryEffect);
        this->primaryEffect = NULL;
    }
    if (this->secondaryEffect != 0U) {
        TParticleCtrl::release((void *)this->secondaryEffect);
        this->secondaryEffect = NULL;
    }
    if (this->tertiaryEffect != 0U) {
        TParticleCtrl::release((void *)this->tertiaryEffect);
        this->tertiaryEffect = NULL;
    }
}

void TObjEneIllGill::run_miss_reaction() { clear_actor_flags(256); }

void TObjEneIllGill::sub_803669B0() {
    u8 *player = (u8 *)this;
    ((TObjBase *)player)->clear_actor_flags((int)(0x04040000U));
    ((TObjMotion *)player)->advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity((TObjEnemy *)player, (s32 *)(0), (f32) (0.0f));
    }
    update_collisions();
    if (actionTimer-- < 0) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        this->actionTimer = (s32) this->resetTimer;
        this->referenceHp = (s16) this->hp;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::run_hit_reaction() {
    if (requested_action == 2 || requested_action == 3) {
        this->referenceHp = (s16) this->hp;
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
        this->hit_flags = 0;
        bodies->flags = (s32) (bodies->flags & 0xFBFFFFFF);
        return;
    }
    if ((s16) this->mode != 7) {
        this->mode = 7;
        this->requested_action = 5;
        this->free_resources();
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
}

void TObjEneIllGill::update_damage_recovery() {
    u8 *self = (u8 *)this;
    ((TObjBase *)self)->clear_actor_flags(0x04040000);
    ((TObjMotion *)self)->advance_animation();
    this->velocity.z = 0.0f;
    this->velocity.x = 0.0f;
    apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
    update_collisions();
    if (((TObjMotion *)self)->is_passing_frame(30.0f) != 0) {
        play_sound_effect(0x4003A350, &position, 0, 0);
    }
    if (this->action_flags != 8) {
        this->actorFlags &= ~0x600;
        this->bodies->flags &= ~0x04000000;
        if ((f32)this->hp < 0.25f * (f32)this->hpmax) {
            this->actorFlags |= 0x2000;
            this->target = 0;
            this->targetId = 0xFFFF;
            VecCopy(&this->move_origin, (const Vec *)(&body_center));
            VecCopy(&move_destination, (const Vec *)(&body_center));
            this->chargeDistance = 0.0f;
        }
        this->referenceHp = this->hp;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneIllGill::run_death_reaction() {
    u8 *self = (u8 *)this;
    if ((s16) this->mode != 8) {
        this->mode = 8;
        this->phase = 0;
        this->requested_action = 6;
        bodies->flags = (s32) (bodies->flags & 0xFFFF7FFE);
        this->free_resources();
        spawn_particle_effect(&body_center, 0xF2);
        refresh_lobby_state();
        ((TObjEnemy *)self)->send_entity_set_flags();
    }
}

void TObjEneIllGill::update_death_fall() {
    u8 *self = (u8 *)this;
  ((TObjBase *)self)->set_actor_flags(0x04040000);
  ((TObjMotion *)self)->advance_animation();
  switch (this->phase)
  {
    default:
      this->phase = 0;
    case 0:
      apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
      if (((TObjMotion *)self)->is_passing_frame((f32)(10.0f)) != 0)
    {
      play_sound_effect(0x4003A351, &position, 0, 0);
      this->phase = 2;
    }
      return;
    return;
    case 2:
      this->body_center.y += 5.0f;
      move_with_wall_slide(this);
      velocity.x *= 0.5f;
      this->velocity.z *= 0.5f;
      if (((TObjMotion *)self)->is_passing_frame((f32)(30.0f)) != 0)
    {
      this->phase = 3;
      spawn_particle_effect(&position, 0xF0);
      return;
    }
      break;
    case 3:
      if (((TObjMotion *)self)->is_passing_frame((f32)(52.0f)) != 0)
    {
      play_sound_effect(0x4003A358, &position, 0, 0);
      TObjPlayer::apply_effect_variant_b(&position, 0xA);
      fn_800D911C(&position);
      this->phase = 4;
      this->deathTimer = 0xA;
      return;
    }
      break;
    case 4:
      if (--deathTimer < 0)
    {
      queue_destruction();
    }
      break;
  }
}

void TObjEneIllGill::capture_effect_positions(NJS_OBJECT *) {
    Vec *v;
    switch (illGillModelNodeIndex) {
    case 50:
        v = &illGillWeaponEffectPosition;
        v->x = 0.0f;
        v->y = 0.0f;
        v->z = 0.0f;
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    case 44:
        v = &illGillShadowEffectPosition;
        v->x = 0.0f;
        v->y = 0.0f;
        v->z = 0.0f;
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    case 40:
        v = &illGillChargeEffectPosition1;
        v->x = 0.0f;
        v->y = 0.0f;
        v->z = 0.0f;
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    case 27:
        v = &illGillChargeEffectPosition2;
        v->x = 0.0f;
        v->y = 0.0f;
        v->z = 0.0f;
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    }
    illGillModelNodeIndex++;
}

void TObjEneIllGill::update_shadow_attack() {
    u8 *arg0_ = (u8 *)this;
    TObjPlayer *pl;
    s32 a;
    u8 *enemy = (u8 *)arg0_;
    if (this->targetId < 0x1000U) {
        pl = get_player_by_client_id(this->targetId);
        if (pl != NULL && pl->get_floor() == get_current_floor()) {
            this->target = pl;
        } else {
            this->target = NULL;
        }
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    ((TObjBase *)enemy)->clear_actor_flags(0x04040000);
    ((TObjMotion *)enemy)->advance_animation();
    switch (this->phase) {
    case 0:
        if (this->target == NULL) {
            this->actorFlags &= ~0x00200000;
            this->actionTimer = 0;
        } else {
            Vec v;
            VecCopy(&v, (const Vec *)((u8 *)&((TObjChara *)target)->body_center));
            subtract_vector(&v, &body_center);
            a = ((TObjEnemy *)enemy)->turn_toward_direction(((IllGillMovementParameters *)movementParameters)->turn, &v);
            apply_actor_gravity((TObjEnemy *)enemy, (s32 *)(0), 0.0f);
            if (a < ((AttackParams *)(ill_gill_combat_parameter_variants[2]))->get_attack_angle()) {
                this->phase = 1;
                this->requested_action = 4;
                this->actionTimer = 0;
            }
        }
        break;
    case 1:
        if (((TObjMotion *)enemy)->is_passing_frame(10.0f) != 0) {
            this->phase = 2;
            this->requested_action = 4;
            this->actionTimer = 0;
            {
                Vec d = *(Vec *)((u8 *)&((TObjChara *)target)->body_center);
                IllGillEffectRotation ang;
                subtract_vector(&d, &shadowEffectPosition);
                ang.x = (s32)(10430.38043493439 * atan2_float(d.z, newton_sqrtf(d.x * d.x + d.y * d.y)));
                ang.y = 0;
                ang.z = -(s32)(10430.38043493439 * atan2_float(d.x, d.y));
                if (this->primaryEffect == 0U) {
                    this->primaryEffect = (TParticleCtrl *)spawn_continuous_particle_with_direction(&shadowEffectPosition, &ang, 0x224);
                }
                spawn_directional_particle(&shadowEffectPosition, &ang, 0x223);
            }
        }
        break;
    case 2:
        play_persistent_sound(0x4003A356, enemy, &position, 0, 0);
        apply_actor_gravity((TObjEnemy *)enemy, (s32 *)(0), 0.0f);
        if (this->target != NULL) {
            Vec w;
            VecCopy(&w, (const Vec *)((u8 *)&((TObjChara *)target)->body_center));
            subtract_vector(&w, &body_center);
            a = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(w.x, w.z)));
            if (a < ((AttackParams *)(ill_gill_combat_parameter_variants[2]))->get_attack_angle()) {
                VecCopy(&w, (const Vec *)((u8 *)&((TObjChara *)target)->position));
                subtract_vector(&w, &shadowEffectPosition);
                atan2_float(w.z, newton_sqrtf(w.x * w.x + w.y * w.y));
                atan2_float(w.x, w.y);
                if (this->action_flags != 4 && ((TObjCollidable *)target)->test_actor_flags(0x04000000) == 0) {
                    void *m = (void *)new TObjIllGillKage((saddr)tl_05, (uaddr)this->target);
                }
            } else {
                this->action_flags &= ~4;
            }
        } else {
            this->action_flags &= ~4;
        }
        if (this->action_flags != 4) {
            this->phase = 4;
            this->requested_action = 0;
            this->actionTimer = 10;
        }
        break;
    case 4:
        apply_actor_gravity((TObjEnemy *)enemy, (s32 *)(0), 0.0f);
        this->actionTimer = this->actionTimer - 1;
        if (this->actionTimer < 0) {
            this->actorFlags &= ~0x00200000;
            this->actionTimer = 0;
            this->free_resources();
        }
        break;
    }
    ((TObjCollidable *)enemy)->update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

#pragma push
#pragma opt_common_subs off
void TObjEneIllGill::update_charge_attack() {
    TObjEneIllGill *o = this;
    if (o->targetId < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(o->targetId);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            o->target = p;
        } else {
            o->target = NULL;
        }
    } else {
        o->targetId = 0xFFFF;
        o->target = NULL;
    }
    o->clear_actor_flags(0x40000);
    if (o->target == NULL) {
        o->targetId = 0xFFFF;
        o->clear_actor_flags(0x4202000);
        o->actionTimer = 0;
        return;
    }
    switch (o->phase) {
    default:
        o->phase = 0;
    case 0:
        o->clear_actor_flags(0x4000000);
        o->clear_player_status_flag(0, 0x80);
        {
            o->play_speed = 2.0f * o->action_table[o->requested_action].speed;
        }
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity(o, 0, 0.0f);
        if (o->target != NULL) {
            Vec v = o->target->body_center;
            s32 d;
            subtract_vector(&v, &o->body_center);
            d = o->turn_toward_direction((s32)(2.0f * (f32)((IllGillMovementParameters *)o->movementParameters)->turn), &v);
            if (d < o->attack_params->get_attack_angle()) {
                s32 ang = (s32)(10430.38043493439 * atan2_float(v.x, v.z));
                o->chargeDistance = 30.0f + (newton_sqrtf(TObjPlayer::calc_distance_to_client(o, o->targetId, NULL)) + ((TObjCollidable *)o)->get_collision_body_radius(0));
                if (o->chargeDistance < 100.0f) {
                    o->chargeDistance = 100.0f;
                }
                v.z = 0.0f;
                v.x = 0.0f;
                v.z = o->chargeDistance;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, &o->body_center);
                if (select_enemy_destination(o, v, 1) != 0 || select_enemy_destination(o, o->target->body_center, 1) != 0) {
                    o->phase = 1;
                    o->requested_action = 8;
                    o->set_actor_flags(0x4000000);
                    o->set_indexed_flags(0, 0x80);
                    copy_position_if_valid(o, o->body_center);
                    o->actionTimer = 10;
                    play_sound_effect(0x4003A34E, &o->position, 0, 0);
                } else {
                    if (o->targetId == 0xFFFF) {
                        o->target = NULL;
                    } else {
                        o->phase = 4;
                        o->requested_action = 9;
                        o->actionTimer = illGillAttackBehavior->recoveryFrames;
                    }
                    o->clear_charge_hits();
                }
            }
        }
        break;
    case 1: {
        o->set_actor_flags(0x4000000);
        o->set_indexed_flags(0, 0x80);
        {
            Vec v = o->target->body_center;
            s32 d;
            subtract_vector(&v, &o->body_center);
            d = o->turn_toward_direction((s32)(2.0f * (f32)((IllGillMovementParameters *)o->movementParameters)->turn), &v);
            if (d < o->attack_params->get_attack_angle()) {
                s32 ang = (s32)(10430.38043493439 * atan2_float(v.x, v.z));
                o->chargeDistance = 30.0f + (newton_sqrtf(TObjPlayer::calc_distance_to_client(o, o->targetId, NULL)) + ((TObjCollidable *)o)->get_collision_body_radius(0));
                if (o->chargeDistance < 100.0f) {
                    o->chargeDistance = 100.0f;
                }
                v.z = 0.0f;
                v.x = 0.0f;
                v.z = o->chargeDistance;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, &o->body_center);
                if (select_enemy_destination(o, v, 1) == 0 && select_enemy_destination(o, o->target->body_center, 1) == 0) {
                    if (o->targetId == 0xFFFF) {
                        o->target = NULL;
                    } else {
                        o->phase = 4;
                        o->requested_action = 9;
                        o->actionTimer = illGillAttackBehavior->recoveryFrames;
                    }
                    o->clear_charge_hits();
                }
            }
        }
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity(o, 0, 0.0f);
        o->actionTimer--;
        if (o->actionTimer < 0) {
            o->phase = 2;
            o->requested_action = 9;
            o->clear_actor_flags(0x4000000);
            o->clear_player_status_flag(0, 0x80);
            if (o->primaryEffect == 0) {
                o->primaryEffect = create_particle_emitter(&o->chargeEffectPosition1, 0x222);
            }
            if (o->secondaryEffect == 0) {
                o->secondaryEffect = create_particle_emitter(&o->chargeEffectPosition2, 0x222);
            }
        }
        break;
    }
    case 2: {
        TObjChara **hit;
        TObjChara *p;
        s32 i;
        o->clear_actor_flags(0x4000000);
        o->clear_player_status_flag(0, 0x80);
        {
            o->play_speed = o->action_table[o->requested_action].speed;
        }
        ((TObjMotion *)o)->advance_animation();
        for (i = 0; i < 4; i++) {

            hit = &o->chargeHits[i];
            if (*hit == NULL) {
                p = (TObjChara *)TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                if (p->get_entity_id() >= 0x1000) {
                    break;
                }
                if (o->find_actor_body_contact(reinterpret_cast<TObjCollidable *>(p), 10000.0f) != 0 &&
                    p->select_melee_contact_body(o, 1.0f) != 0) {
                    f32 dmg = p->receive_physical_attack(o, 1.0f);
                    p->set_actor_flags(0x400);
                    p->apply_knockback_from_attacker((u8 *)o, 2.0f * dmg);
                    *hit = p;
                    if (is_split_screen() == 0 && local_client_id == p->get_entity_id()) {
                        TCameraCtrl::set_shake_preset(1);
                    }
                }
            }
        }
        if (o->target != NULL) {
            IllGillMovementParameters *prm = ((IllGillMovementParameters *)o->movementParameters);
            f32 spd = 4.5f * prm->speed;
            f32 d2;
            f32 t;
            s32 c;
            if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                spd *= 2.0f;
            }
            ((TObjEnemy *)o)->enemy_turn_toward_dest((s32)(4.5f * (f32)prm->turn));
            enemy_set_heading_velocity(spd, (TObjEnemy *)(o), o->rotation_y);
            move_with_wall_slide(o);
            d2 = horizontal_distance_squared(&o->move_destination, &o->body_center);
            t = spd + o->bodies->radius;
            if (d2 < t * t || ((IllGillMovementParameters *)o->movementParameters)->range * ((IllGillMovementParameters *)o->movementParameters)->range < d2 || 120.0f < (f32)(c = o->chargeFrames)) {
                if (o->targetId == 0xFFFF) {
                    o->target = NULL;
                } else {
                    o->phase = 4;
                    o->requested_action = 9;
                    o->actionTimer = illGillAttackBehavior->recoveryFrames;
                    o->free_resources();
                }
                o->clear_charge_hits();
                o->chargeFrames = 0;
            } else {
                o->chargeFrames = c + 1;
            }
        }
        play_persistent_sound(0x4003A34F, o, &o->position, 0, 0);
        if (o->primaryEffect != 0 && ((TObject *)(o->primaryEffect))->all_parents_unqueued_for_destruction() != 0) {
            ((TParticleCtrl *)o->primaryEffect)->set_position(&o->chargeEffectPosition1);
        }
        if (o->secondaryEffect != 0 && ((TObject *)(o->primaryEffect))->all_parents_unqueued_for_destruction() != 0) {
            ((TParticleCtrl *)o->secondaryEffect)->set_position(&o->chargeEffectPosition2);
        }
        break;
    }
    case 4:
        o->clear_actor_flags(0x4000000);
        o->clear_player_status_flag(0, 0x80);
        {
            o->play_speed = 2.0f * o->action_table[o->requested_action].speed;
        }
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity(o, 0, 0.0f);
        o->actionTimer--;
        if (o->actionTimer < 0) {
            o->clear_actor_flags(0x200000);
            o->actionTimer = 0;
            o->targetId = 0xFFFF;
            o->target = NULL;
        }
        break;
    }
    o->refresh_collision_body_centers();
    minimap_render_dot(&o->position, -0x5DB4, 1, 0);
}

#pragma pop
TObjIllGillKage::TObjIllGillKage(saddr parent, uaddr target) : TObjBase((TObject *)parent) {
    m_name = TObjIllGillKage__class_name;
    if (target != 0U) {
        VecCopy(&position, &((TObjBase *)target)->position);
        this->target_id = ((TObjBase *)target)->get_entity_id();
        this->timer = 0xB4;
        this->state = 0;
    } else {
        this->target_id = 0xFFFFU;
        ((TObject *)this)->queue_destruction();
    }
}

TObjIllGillKage::~TObjIllGillKage() {}

void TObjIllGillKage::render() {  }

void TObjIllGillKage::run_task() {
    switch (this->state) {
    case 0:
        this->attack_target();
        return;
    case 1:
        tick_persistent_sound();
        return;
    default:
        this->queue_destruction();
        return;
    }
}

void TObjIllGillKage::attack_target() {
    TObjPlayer *player;

    this->state = 1;
    player = get_player_by_client_id(this->target_id);
    if ((player != NULL) && (TObjPlayer::is_locally_controlled(player) != 0) && (player->all_parents_unqueued_for_destruction() != 0) && (player->test_actor_flags(0x800) == 0)) {
        TObjPlayer::play_effect(player, this->timer, 3);
    }
}

void TObjIllGillKage::tick_persistent_sound() {
    play_persistent_sound(0x4003A357, this, &position, 0, 0);
    if (timer-- < 0) {
        this->state = 2;
    }
}

void TObjIllGillKage::queue_destruction() { TObject::queue_destruction(); }
