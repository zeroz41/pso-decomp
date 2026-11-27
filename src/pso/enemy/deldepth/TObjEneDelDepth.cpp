#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/animation/ActorAnimationState.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/map/CsnQuery.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/object/TObjControl.h"
#include "pso/render/reflection.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/deldepth/TObjEneDelDepthBomb.h"
#include "pso/enemy/deldepth/TObjEneDelDepth.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/network/TLobby.h"
#include "pso/technique/TTecBarta.h"
#include "pso/technique/TTecMegid.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/ProjectedStripDraw.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/PlayerCommands.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/DebugFont.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixStack.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/system/task/TMainTask.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/BlobShadow.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/TDeadSpot.h"
#include "pso/render/model_render_state.h"
#include "pso/enemy/BattleParamTables.h"


DelDepthParameters *TObjEneDelDepth::tune_params;
BmlResource *TObjEneDelDepth::shared_resource;

static const char *deldepth_model_names[] = {
    "swim_body.nj", "swim_disc.nj", "swim_kirai.nj", NULL,
};
static const char *TObjEneDelDepth_motion_file_list[] = {
    "changea_swim_disc.njm", "changeb_swim_disc.njm", "damage_swim_disc.njm", "dead_swim_disc.njm",
    "move_swim_disc.njm", "attack_swim_body.njm", "attack2_swim_body.njm", "changea_swim_body.njm",
    "changeb_swim_body.njm", "damage_swim_body.njm", "dead_swim_body.njm", "wait_swim_body.njm",
    NULL,
};
static BmlResourceDescriptor deldepth_bml_descriptor = {
    "bm_ene_del_depth.bml", deldepth_model_names, TObjEneDelDepth_motion_file_list, 3, 12
};
static const char *deldepth_low_model_names[] = {
    "lo_swim_body.nj", "swim_disc.nj", "swim_kirai.nj", NULL,
};
static const char *TObjEneDelDepth_motion_names[] = {
    "changea_swim_disc.njm", "changeb_swim_disc.njm", "damage_swim_disc.njm", "dead_swim_disc.njm",
    "move_swim_disc.njm", "attack_swim_body.njm", "attack2_swim_body.njm", "changea_swim_body.njm",
    "changeb_swim_body.njm", "damage_swim_body.njm", "dead_swim_body.njm", "wait_swim_body.njm",
    NULL,
};
static BmlResourceDescriptor deldepth_low_bml_descriptor = {
    "bm_ene_del_depth_low.bml", deldepth_low_model_names, TObjEneDelDepth_motion_names, 3, 12
};
static CollisionBody TObjEneDelDepth_collision_body_parts[] = {
    {{0.0f, 15.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f}
};
static TObjMotionAction deldepth_motion_actions[] = {
    {1, 0, 11, 0.5f, 0},
    {2, 0, 5, 0.8f, 0},
    {3, 0, 6, 0.8f, 0},
    {3, 0, 11, 0.5f, 0},
    {3, 0, 9, 0.8f, 0},
    {3, 0, 10, 0.7f, 0}
};
static TObjMotionAction deldepth_motion_actions_b[] = {{1, 0, 0xB, 0.5f, 0}};

const char *del_depth_name = "TObjEneDelDepth";
// drawScale end points of the surfacing progress (0 = flat on the floor, 1 = full size).
static const Vec flat_scale = {2.5f, 0.0f, 2.5f};
static const Vec full_scale = {1.0f, 1.0f, 1.0f};

TObjEneDelDepth::ActionPair deldepth_actions[] = {
    { &TObjEneDelDepth::init_params, &TObjEneDelDepth::try_relocate_on_timer },
    { &TObjEneDelDepth::init_draw_params, &TObjEneDelDepth::update_surface },
    { &TObjEneDelDepth::init_draw_mode_and_motion, &TObjEneDelDepth::update_scale_pulse },
    { &TObjEneDelDepth::start_move_toward_player, &TObjEneDelDepth::update_movement },
    { &TObjEneDelDepth::enter_state8, &TObjEneDelDepth::update_state },
    { &TObjEneDelDepth::enter_appear_state, &TObjEneDelDepth::try_enter_appear },
    { &TObjEneDelDepth::enter_look_around, &TObjEneDelDepth::update_look_around },
    { &TObjEneDelDepth::init_depth, &TObjEneDelDepth::update_spin_search },
    { &TObjEneDelDepth::setup_depth_draw, &TObjEneDelDepth::move_toward_target },
    { &TObjEneDelDepth::enter_attack_cast, &TObjEneDelDepth::update_attack_cast },
    { &TObjEneDelDepth::init_draw_state, &TObjEneDelDepth::update_bomb_drop },
    { &TObjEneDelDepth::init_state, &TObjEneDelDepth::update_state_flag },
    { &TObjEneDelDepth::start_attack_motion, &TObjEneDelDepth::update_ai_state },
    { &TObjEneDelDepth::init_move, &TObjEneDelDepth::update_death_fade },
    { &TObjEneDelDepth::enter_fall_to_ground, &TObjEneDelDepth::update_fall_to_ground },
};


void TObjEneDelDepth::setup_draw_material(f32 opacity, f32 red, f32 green, f32 blue) {
    NJS_ARGB color;
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x8820;
    set_chunk_material_override_pair(0xFF00, 0x800);
    set_chunk_blend(0x2100);
    color.r = red;
    color.g = green;
    color.a = -1.0f + opacity;
    color.b = blue;
    set_constant_material(&color);
}

void TObjEneDelDepth::setup_draw_material_default(f32 opacity) {
    TObjEneDelDepth::setup_draw_material(opacity, 0.0f, 0.0f, 0.0f);
}

void TObjEneDelDepth::reset_globals() {
    model_render_flags &= 0xFFFF77DF;
    set_chunk_material_override_pair(0xFF00, 0);
    set_chunk_blend(0x2500);
    set_chunk_blend(0x2500);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}

void *TObjEneDelDepth::create(void *setData) {
    return new TObjEneDelDepth(new TObjControl((TObject *)tl_04), setData);
}

void TObjEneDelDepth::load_assets() {

    if (is_split_screen() != 0) {
        BmlResource *p = new BmlResource(1, &deldepth_low_bml_descriptor, 0, 0, NULL);
        shared_resource = p;
    } else {
        BmlResource *p = new BmlResource(1, &deldepth_bml_descriptor, 0, 0, NULL);
        shared_resource = p;
    }

    {
        NpcAnimationBinding info = { NULL, deldepth_motion_actions, 0, 0, 6 };
        info.motions = shared_resource->motions;
        TObjNpcEnemy::register_animated_chunk((s16)0x47, shared_resource->models[0].model, shared_resource->models[0].texlist, &info, TObjEneDelDepth_collision_body_parts[0].radius, 0.0f);
    }
    {
        NpcAnimationBinding info = { NULL, deldepth_motion_actions_b, 0, 0, 1 };
        info.motions = shared_resource->motions;
        TObjNpcEnemy::register_animated_chunk((s16)0x48, shared_resource->models[1].model, shared_resource->models[1].texlist, &info, TObjEneDelDepth_collision_body_parts[0].radius, 0.0f);
    }
    tune_params = (DelDepthParameters *)dispatch_shared_handler_a(0x30);
}

void TObjEneDelDepth::free_shared_data() {
    if (shared_resource != NULL) {
        delete shared_resource;
        shared_resource = NULL;
    }
}

TObjEneDelDepth::TObjEneDelDepth(TObject *parent, void *setData) : TObjEnemy(parent) {
    m_name = del_depth_name;
    add_flags_2e4(8);
    apply_set_data(setData);
    update_target_depth();
    init();
    project_actor_to_ground(this, &position, 0);
    set_action_state(0);
}

void TObjEneDelDepth::init() {
    this->texlist = get_bml_texlist(shared_resource = TObjEneDelDepth::get_data(), 0);
    this->model = get_bml_model(shared_resource, 0);
    VecCopy(&this->prev_position, (const Vec *)(VecCopy(&this->home_position, (const Vec *)(VecCopy(&this->center, &this->position)))));
    this->collisionBody = init_collision_body_parts(this, TObjEneDelDepth_collision_body_parts, 1);
    this->set_action_table(deldepth_motion_actions);
    this->set_motion_list(shared_resource->motions);
    this->set_animation(0);
    this->set_requested_action(0);
    VecCopy((Vec *)((u8 *)&this->body_center), &this->position);
    this->velocity.z = 0.0f;
    this->velocity.y = 0.0f;
    velocity.x = 0.0f;
    this->target = 0;
    this->bind_enemy_combat_stats(register_boss(0x30), dispatch_shared_handler_b(0x30), register_object(0x30));
    this->referenceHp = (s16) this->hp;
    register_by_id();
    this->movementParameters = 0;
    this->set_param(0x47);
    this->motionController = (new DelDepthMotion(this));
    this->targetPlayer = 0xFFFF;
    this->groundFlags = 0;
    VecCopy(&this->groundPoint, &this->position);
    this->clear_lobby_object_state();
}

#pragma push
#pragma opt_common_subs off
void TObjEneDelDepth::update_target_depth() {
    this->bombSpeed = (f32) (0.6f + this->parameters[0]);
    if (this->bombSpeed < 0.0f) {
        this->bombSpeed = 0.0f;
    }
}
#pragma pop

TObjEneDelDepth::~TObjEneDelDepth() {
    free_collision_body_parts(this);
    collisionBody = NULL;
    delete motionController;
    motionController = 0;
}

void TObjEneDelDepth::run_task() {
    TObjEneDelDepth::Action fn;
    if (TObjPlayer::check_demo_mode() != 0) {
        update_target_depth();
        return;
    }
    this->set_body_flag();
    fn = deldepth_actions[action].update;
    (void)(fn != NULL);
    (this->*fn)();
    this->update_prev_position();
    this->update_collisions();
    if (this->targetable != 0) {
        submit_cursor_candidate(this, -1);
    }
    motionController->update_animation_frame();
    this->clear_body_flag_if_untargetable();
    if (this->action != 0xD) {
        minimap_render_dot(&this->body_center, -0x5DB4, 1, 0);
    }
    update_ground_check();
}

void TObjEneDelDepth::render() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_in_demo();
        return;
    }
    if (this->opacity <= 0.0f) {
        return;
    }
    if (this->update_object_view_visibility(500.0f, 20.0f) == 0) {
        return;
    }
    if (draw_if_visible() != 0) {
        return;
    }
    if (this->opacity < 1.0f) {
        setup_draw_material_default(this->opacity);
    }
    toggle_particle_effect();
    push_matrix();
    Vec v = this->position;
    v.y += this->drawOffsetY;
    post_translate_matrix(&v.x);
    rotate_matrix_y(0, this->rotation_y);
    scale_matrix_vec3(0, (u8 *)&this->drawScale);
    this->motionController->draw_model_part();
    pop_matrix();
    TParticleCtrl::end_effect_render();
    if (this->opacity < 1.0f) {
        TObjEneDelDepth::reset_globals();
    }
    if (!(this->groundFlags & 0x4000)) {
        Vec s = {2.0f, 2.0f, 2.0f};
        this->draw_ground_shadow(&s, 0);
    }
}

s32 TObjEneDelDepth::draw_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix((Vec *)(&this->groundPoint)) != 0) {
            push_matrix();
            Vec v = this->position;
            v.y += this->drawOffsetY;
            post_translate_matrix(&v.x);
            rotate_matrix_y(0, this->rotation_y);
            scale_matrix_vec3(0, (u8 *)&this->drawScale);
            this->motionController->draw_model_part();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

void TObjEneDelDepth::render_in_demo() {  }

void TObjEneDelDepth::set_action_state(s32 i) {
    TObjEneDelDepth::Action fn;
    action = i;
    fn = deldepth_actions[action].enter;
    (void)(fn != NULL);
    (this->*fn)();
}

void TObjEneDelDepth::set_depth_offset(s32 minimum, s32 range) {
    timer = minimum + (s32)((f32)range * random_ratio());
}

#pragma push
#pragma fp_contract on
s32 TObjEneDelDepth::adjust_height_to_ground() {
    Vec v = this->position;
    v.x = 15.0f * cos_table_lookup(this->rotation_y) + v.x;
    v.y += 5.0f;
    v.x = 15.0f * sin_table_lookup(this->rotation_y) + v.x;
    if (project_actor_to_ground(this, &v, 0) != 0) {
        this->position.y += 0.5f * (v.y - this->position.y);
        return 1;
    }
    return 0;
}
#pragma pop

void TObjEneDelDepth::set_draw_mode(s32 mode) {
    collisionBody->flags &= 0xF5FFF297;
    switch (mode) {
    case 0:
        collisionBody->flags |= 0x0A000000 | 0x528;
        targetable = 0;
        return;
    case 1:
        collisionBody->flags |= 0x0A000000 | 0x28;
        targetable = 0;
        return;
    case 2:
        targetable = 1;
        return;
    case 3:
        static const s32 flags = 0x500;
        collisionBody->flags |= flags;
        targetable = 1;
        return;
    }
}

void TObjEneDelDepth::set_body_flag() {
    this->collisionBody->flags |= 1;
}

void TObjEneDelDepth::clear_body_flag_if_untargetable() {
    if (this->targetable == 0) {
        this->collisionBody->flags &= ~1;
    }
}

void TObjEneDelDepth::run_death_reaction() { if (this->action != 13) { set_action_state(13); } }

void TObjEneDelDepth::run_hit_reaction() {
    if (this->action != 0xC) {
        this->actorFlags &= ~0x200;
        this->set_action_state(0xC);
    }
}

void TObjEneDelDepth::run_miss_reaction() {
    if (this->action != 0xB) {
        this->actorFlags &= ~0x100;
        this->set_action_state(0xB);
    }
}

void TObjEneDelDepth::set_default_depth_offset() { set_depth_offset(15, 15); }

void TObjEneDelDepth::init_params() {
    this->adjust_height_to_ground();
    this->drawOffsetY = -2.5f;
    this->drawScale.z = 0.0f;
    this->drawScale.y = 0.0f;
    this->drawScale.x = 0.0f;
    this->opacity = 0.0f;
    this->relocationAttempts = 0;
    this->motionController->set_motion(6);
    this->set_draw_mode(0);
    this->actorFlags = (this->actorFlags | 0x4040000);
    set_default_depth_offset();
}

void TObjEneDelDepth::try_relocate_on_timer() {
    if (--this->timer <= 0) {
        if (find_nearest_visible_player(this, NULL, 200.0f) == 0xFFFF) {
            if (++this->relocationAttempts >= 5) {
                this->position.x = (f32) this->home_position.x;
                this->position.z = (f32) this->home_position.z;
                this->relocationAttempts = 5;
            }
            set_default_depth_offset();
            return;
        }
        play_area_se_with_particle(&this->position);
        this->set_action_state(1);
    }
}

void TObjEneDelDepth::init_draw_params() {
    this->set_draw_mode(0);
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
    this->progress = 0.0f;
    this->drawOffsetY = -2.5f;
}

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::update_surface() {
    this->drawOffsetY = -2.5f * (1.0f - this->progress);
    this->drawScale.x = this->progress * (full_scale.x - flat_scale.x) + flat_scale.x;
    this->drawScale.y = this->progress * (full_scale.y - flat_scale.y) + flat_scale.y;
    this->drawScale.z = this->progress * (full_scale.z - flat_scale.z) + flat_scale.z;
    f32 fade = 1.0f;
    if (this->progress > 0.8f) {
        fade = (1.0f - this->progress) / 0.19999999f;
    }
    f32 wobble = fade * (0.1f * sin_table_lookup(this->timer << 12));
    this->drawScale.x *= 1.0f + wobble;
    this->drawScale.z *= 1.0f - wobble;
    this->timer++;
    if (this->progress >= 0.5f) {
        this->opacity = 1.0f;
    } else {
        this->opacity = 2.0f * this->progress;
    }
    if ((this->progress += 0.033333335f) > 1.0f) {
        if (find_nearest_visible_player(this, NULL, 200.0f) != 0xFFFF) {
            this->set_action_state(3);
            play_sound_effect(0x4003A822, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
        } else {
            this->set_action_state(2);
        }
    }
}
#pragma pop

void TObjEneDelDepth::init_draw_mode_and_motion() {
    this->progress = 1.0f;
    this->drawOffsetY = 0.0f;
    this->set_draw_mode(0);
    this->motionController->set_motion(0x6);
}

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::update_scale_pulse() {
    this->drawOffsetY = -2.5f * (1.0f - this->progress);
    this->drawScale.x = this->progress * (full_scale.x - flat_scale.x) + flat_scale.x;
    this->drawScale.y = this->progress * (full_scale.y - flat_scale.y) + flat_scale.y;
    this->drawScale.z = this->progress * (full_scale.z - flat_scale.z) + flat_scale.z;
    f32 fade = 1.0f;
    if (this->progress > 0.8f) {
        fade = (1.0f - this->progress) / 0.19999999f;
    }
    f32 wobble = fade * (0.15f * sin_table_lookup(this->timer << 10));
    this->drawScale.x *= 1.0f + wobble;
    this->drawScale.z *= 1.0f - wobble;
    this->timer++;
    if (this->progress >= 0.5f) {
        this->opacity = 1.0f;
    } else {
        this->opacity = 2.0f * this->progress;
    }
    if ((this->progress += -0.011111111f) < 0.0f) {
        this->set_action_state(0);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::start_move_toward_player() {
    s32 angle;
    this->movementSpeed = 0.0f;
    if (find_nearest_visible_player(this, &direction, 200.0f) == 0xFFFF) {
        this->set_action_state(2);
        return;
    }
    angle = (s32) (1048575.0f * random_ratio());
    this->direction.x += 15.0f * sin_table_lookup(angle);
    this->direction.z += 15.0f * cos_table_lookup(angle);
    if (vector_length(&this->direction) <= 0.01f) {
        this->set_action_state(2);
        return;
    }
    normalize_vector(&this->direction);
    this->progress = ((30.0f * random_ratio()) + 70.0f);
    this->opacity = 1.0f;
    this->motionController->set_motion(7);
    this->set_draw_mode(3);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::update_movement() {
    Vec p;
    Vec n;
    s32 i;
    TObjChara *pl;
    s32 k;
    s32 ang;
    s32 rot;
    if ((actor_frame_tick % 5) == 0) {
        clear_battle_param_slots();
        this->check_object_collisions();
        for (i = 0; i < 16; i++) {
            pl = TObjPlayer::get_battle_param(i);
            if (pl == 0) {
                break;
            }
            if (obj_is_hit_receivable(pl) != 0 && is_player_entity_id(pl->get_entity_id()) != 0) {
                pl->select_melee_contact_body(this, 1.0f);
                pl->receive_physical_attack(this, 1.0f);
                pl->apply_knockback_from_attacker(this, 5.0f);
            }
        }
    }
    if (this->progress > 0.0f) {
        this->angle += 0xC00;
        f32 t = sin_table_lookup(this->angle);
        f32 u = 0.5f * (0.5f + t);
        u = tune_params->accel * u;
        if ((this->movementSpeed += u) > tune_params->maxSpeed) {
            this->movementSpeed = tune_params->maxSpeed;
        }
    } else {
        if ((this->movementSpeed -= tune_params->accel) < 0.0f) {
            this->movementSpeed = 0.0f;
        }
    }
    this->progress -= fabs_float(this->movementSpeed);
    VecCopy((Vec *)&this->prev_position, (const Vec *)&this->position);
    for (k = 1; k < 15; k++) {
        f32 s;
        f32 c;
        f32 d;
        this->position.x += this->movementSpeed * this->direction.x;
        this->position.z += this->movementSpeed * this->direction.z;
        VecCopy(&p, (const Vec *)&this->position);
        VecCopy(&n, (const Vec *)&this->direction);
        normalize_vector(&n);
        d = 1.3f * TObjEneDelDepth_collision_body_parts[0].radius;
        p.x += d * n.x;
        p.z += d * n.z;
        if (this->adjust_height_to_ground() != 0) {
            CsnHit *hit;
            ang = 0;
            hit = csnVector(&this->prev_position, &p, 0x88E0);
            if (hit != 0) {
                Vec w;
                VecCopy(&p, (const Vec *)&this->position);
                w.x = hit->contact->normal.z;
                w.z = -hit->contact->normal.x;
                normalize_vector_xz((&w));
                if (n.x * w.x + n.z * w.z >= 0.0f) {
                    n.x = w.x;
                    n.z = w.z;
                } else {
                    n.x = -w.x;
                    n.z = -w.z;
                }
                d = 1.2f * TObjEneDelDepth_collision_body_parts[0].radius;
                p.x += d * n.x;
                p.z += d * n.z;
                this->angle = (s32)(10430.38043493439 * atan2_float(n.x, n.z));
                if (csnVector(&this->prev_position, &p, 0x88E0) == 0) {
                    ang = 1;
                }
            } else {
                ang = 1;
            }
            if (ang == 1) {
                CsnHit *u;
                p.y += 10.0f;
                u = csnVectorUnder(&p, this->ground_candidates.groups, 0x16EF);
                if (u != 0 && (u->contact->flags & 0xE0) == 0) {
                    break;
                }
            }
        }
        rot = k << 12;
        if (k & 1) {
            rot *= -1;
        }
        s = sin_table_lookup(rot);
        c = cos_table_lookup(rot);
        this->direction.x = c * this->direction.x - s * this->direction.z;
        this->direction.y = 0.0f;
        this->direction.z = s * this->direction.x + c * this->direction.z;
        normalize_vector(&this->direction);
        this->rotation_y = (s32)(10430.38043493439 * atan2_float(this->direction.x, this->direction.z));
        VecCopy((Vec *)&this->position, (const Vec *)&this->prev_position);
    }
    if (this->progress <= 0.0f && 0.0f == this->movementSpeed) {
        Vec q;
        if (find_nearest_visible_player(this, &q, 50.0f) != 0xFFFF && vector_length(&q) > 15.0f) {
            this->set_action_state(4);
        } else {
            this->set_action_state(3);
            play_sound_effect(0x4003A822, &this->position, 0, 0);
        }
    }
}
#pragma pop

void TObjEneDelDepth::enter_state8() {
    this->actorFlags = (s32) (this->actorFlags | 0x04000000);
    this->attackTimer = 8;
    this->motionController->set_motion(0xA);
    play_sound_effect(0x4003A820, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
    this->set_draw_mode(1);
}

void TObjEneDelDepth::update_state() {
    if (this->motionController->is_state_complete() == 1) {
        this->actorFlags = (s32) (this->actorFlags & 0xFBFFFFFF);
        if (get_flag_bit4() != 0) {
            set_action_state(7);
            return;
        }
        set_action_state(6);
    }
}

void TObjEneDelDepth::enter_appear_state() {
    this->actorFlags = (s32) (this->actorFlags | 0x04000000);
    this->attackTimer = 0x14;
    play_sound_effect(0x4003A820, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
    this->motionController->set_motion(0xB);
    this->set_draw_mode(1);
}

void TObjEneDelDepth::try_enter_appear() {
    if (this->motionController->is_state_complete() == 1) {
        this->actorFlags = (s32) (this->actorFlags | 0x04000000);
        this->set_action_state(3);
        play_sound_effect(0x4003A822, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
    }
}

void TObjEneDelDepth::enter_look_around() {
    targetPlayer = 0xFFFF;
    angle = ((s32)(4.0f * random_ratio()) + 4) << 16;
    timer = 0x7FFFFFFF;
    turnSpeed = tune_params->turnSpeed;
    if (random_ratio() > 0.5f) {
        turnSpeed *= -1;
    }
    motionController->set_motion(0);
    set_draw_mode(2);
}

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::update_look_around() {
    Vec v;
    Vec w;
    f32 f;
    s32 lim;
    u16 id;
    f = sin_table_lookup(this->angle);
    if (f < 0.0f) {
        f = 0.0f;
    }
    this->rotation_y = (s32)(f * (f32)this->turnSpeed + (f32)this->rotation_y);
    if (this->targetPlayer == 0xFFFF) {
        id = find_nearest_visible_player(this, &v, 162.5f);
        if (id != 0xFFFF && angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z))) < 0x1C71) {
            this->angle = 0;
            this->targetPlayer = id;
        }
    }
    this->angle -= 0x600;
    if (this->angle <= 0) {
        u32 n = ((NJS_MOTION *)get_bml_motion(shared_resource, 0xB))->nbFrame;
        lim = (s32)((f32)n / 0.5f);
        this->angle = 0;
        if (this->targetPlayer != 0xFFFF) {
            w.x = 1.0f;
    w.z = w.y = 0.0f;
            TObjPlayer::calc_distance_to_client(this, this->targetPlayer, &w);
            this->rotation_y = approach_angle_limited(this->rotation_y, (s32)(10430.38043493439 * atan2_float(w.x, w.z)), 0x280);
        }
        if (this->timer > lim) {
            this->motionController->set_motion(0);
            this->timer = lim;
        } else if (--this->timer <= 0) {
            if (this->targetPlayer == 0xFFFF) {
                this->set_action_state(5);
            } else {
                this->set_action_state(8);
            }
        }
    }
}
#pragma pop

void TObjEneDelDepth::init_depth() {
    this->set_depth_offset(0x1E, 0x1E);
    this->turnSpeed = 0x888;
    if (random_ratio() > 0.5f) {
        this->turnSpeed = this->turnSpeed * 0xFFFFFFFF;
    }
    this->motionController->set_motion(0);
    this->set_draw_mode(2);
}

void TObjEneDelDepth::update_spin_search() {
    Vec sp;
    s32 r = 0;
    s32 t;
    this->rotation_y = this->rotation_y + this->turnSpeed;
    if (this->find_nearest_enemy_with_flag(&sp, 500.0f) != 0xFFFF) {
        t = (s32) (10430.38043493439 * atan2_float(sp.x, sp.z));
        if (angle_difference_abs(this->rotation_y, t) < 0x444) {
            this->rotation_y = t;
            r = 1;
        }
    }
    this->timer = this->timer - 1;
    if (r != 0 || this->timer < 0) {
        this->set_action_state(9);
    }
}

void TObjEneDelDepth::setup_depth_draw() { this->set_depth_offset(30, 30); this->motionController->set_motion(0); this->set_draw_mode(2); }

void TObjEneDelDepth::move_toward_target() {
    Vec v;
    s32 ang;
    s32 id;
    v.x = 1.0f;
    v.z = v.y = 0.0f;
    id = this->targetPlayer;
    if (id != 0xFFFF) {
        TObjPlayer::calc_distance_to_client(this, static_cast<u16>(id), &v);
    }
    ang = (s32)(10430.38043493439 * atan2_float(v.x, v.z));
    this->rotation_y = approach_angle_limited(this->rotation_y, ang, 0x200);
    if (angle_difference_abs(this->rotation_y, ang) < 0x200) {
        this->timer = 0;
    }
    VecCopy(&this->prev_position, &this->position);
    if (vector_length(&v) <= 0.01f) {
        v.x = 1.0f;
    v.z = v.y = 0.0f;
    } else {
        normalize_vector(&v);
    }
    v.x *= 0.2f;
    v.y *= 0.2f;
    v.z *= 0.2f;
    vec3_add_to(&this->position, &v);
    if (project_actor_to_ground(this, &this->position, 0) == 0 || csnLookAt(&prev_position, &position) != 0) {
        VecCopy(&this->position, &this->prev_position);
    }
    if (--this->timer <= 0) {
        if (vector_length(&v) > 50.0f || random_ratio() < 0.45f) {
            this->set_action_state(9);
        } else {
            this->set_action_state(0xA);
        }
    }
}

void TObjEneDelDepth::init_draw_state() { this->timer = 30; this->attackTimer = 8; this->motionController->set_motion(2); this->set_draw_mode(2); }

void TObjEneDelDepth::update_bomb_drop() {
    Vec out;
    this->attackTimer--;
    if (this->attackTimer <= 0 && this->attackTimer == 0) {
        set_motion_packed_rotation();
        push_matrix_from(identity_matrix);
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        this->calc_joint_matrices(8.0f);
        pop_matrix();
        push_matrix_from(anim_model_matrix_array[23]);
        {
        Vec v = {0.0f, 0.0f, 0.0f};
        matrix_mult_vec(0, &v, &out);
        }
        pop_matrix();
        clear_motion_packed_rotation();
        play_sound_effect(0x4003A81D, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
        TObjEneDelDepthBomb::create(this, this, &out, tune_params->techniqueLevel);
    }
    if (--this->timer <= 0) {
        if (get_flag_bit4() != 0) {
            this->set_action_state(7);
            return;
        }
        this->set_action_state(5);
    }
}

void TObjEneDelDepth::enter_attack_cast() {
    timer = 30;
    attackTimer = 12;
    motionController->set_motion(1);
    set_draw_mode(2);
}

void TObjEneDelDepth::update_attack_cast() {
    this->attackTimer--;
    if (this->attackTimer <= 0 && this->attackTimer == 0) {
        if ((s32) game_difficulty_selection == 3) {
            TTecMegid::create_ex(this, &this->position, this->rotation_y, tune_params->techniqueLevel);
        } else {
            TTecBarta::create_ex(this, &this->position, this->rotation_y, tune_params->techniqueLevel);
        }
    }
    if (--this->timer <= 0) {
        if (get_flag_bit4() != 0) {
            this->set_action_state(7);
            return;
        }
        this->set_action_state(5);
    }
}

void TObjEneDelDepth::init_state() {
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
    this->drawScale.z = 1.0f;
    this->drawScale.y = 1.0f;
    this->drawScale.x = 1.0f;
    this->attackTimer = 0;
    this->motionController->set_motion(3);
    this->set_draw_mode(2);
}

void TObjEneDelDepth::update_state_flag() {
    if (this->motion_flags & 0x10) {
        if (get_flag_bit4() != 0) {
            set_action_state(7);
            return;
        }
        set_action_state(6);
    }
}

void TObjEneDelDepth::start_attack_motion() {
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
    this->drawScale.z = 1.0f;
    this->drawScale.y = 1.0f;
    this->drawScale.x = 1.0f;
    play_sound_effect(0x4003A321, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
    if (this->motionController->get_type() < 6) {
        this->motionController->set_motion(4);
    } else {
        this->timer = 0x10;
        this->motionController->set_motion(8);
    }
    this->set_draw_mode(0);
}

void TObjEneDelDepth::update_ai_state() {
    Vec direction;
    s32 timer;

    if (this->motionController->get_type() < 6) {
        if (this->motion_flags & 0x10) {
            this->set_action_state(5);
        }
    } else {
        timer = this->timer - 1;
        this->timer = timer;
        if (timer <= 0) {
            if (((find_nearest_visible_player(this, &direction, 50.0f)) != 0xFFFF) && (vector_length(&direction) > 15.0f)) {
                this->set_action_state(4);
                return;
            }
            this->set_action_state(3);
            play_sound_effect(0x4003A822, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
        }
    }
}

void TObjEneDelDepth::init_move() {
    this->drawScale.z = 1.0f;
    this->drawScale.y = 1.0f;
    this->drawScale.x = 1.0f;
    refresh_lobby_state();
    this->actionPhase = 0;
    if (this->motionController->get_type() < 6) {
        this->timer = 0x22;
        this->motionController->set_motion(5);
    } else {
        this->timer = 0x20;
        this->motionController->set_motion(9);
    }
    this->set_draw_mode(0);
}

#pragma push
#pragma opt_common_subs off
void TObjEneDelDepth::update_death_fade() {
    EnemyStateRecord record;
    switch (this->actionPhase) {
    case 0:
        if (--this->timer <= 0) {
            this->actionPhase = 1;
            play_sound_effect(0x4003A321, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
            this->timer = 5;
        }
        break;
    case 1:
        if ((this->opacity += -0.2f) < 0.0f) {
            this->opacity = 0.0f;
        }
        if (--this->timer <= 0) {
            this->actionPhase = 2;
        }
        break;
    case 2:
    default:
        record.flags = 0x800;
        this->send_6x0A_enemy_state(&record);
        this->exchange_object_state(&record, 0);
        apply_enemy_state(&record.flags);
        this->send_entity_set_flags();
        TDeadSpot::spawn_kind0_scale7_5(&position, 0);
        this->queue_destruction();
        break;
    }
}

#pragma pop
void TObjEneDelDepth::enter_fall_to_ground() {
    drawOffsetY = -2.5f;
    drawScale.z = 0.0f;
    drawScale.y = 0.0f;
    drawScale.x = 0.0f;
    opacity = 0.0f;
    motionController->set_motion(6);
    set_draw_mode(0);
}

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::update_fall_to_ground() {
    s32 done;
    s32 tries;
    Vec a;
    Vec b;
    Vec c;
    f32 s;
    f32 co;
    f32 k;

    done = 0;
    k = 5.0f;
    tries = 4;
    this->fallVelocity.y += -0.075f;
    do {
        VecCopy(&a, (const Vec *)&this->position);
        vec3_add_to(&a, &this->fallVelocity);
        VecCopy(&b, &a);
        b.y += k + fabs_float(this->fallVelocity.y);
        if (project_actor_to_ground(this, &b, 0) != 0) {
            VecCopy((Vec *)&this->position, &a);
            if (!(this->position.y > b.y)) {
                this->position.y = b.y;
                done = 1;
            }
            break;
        }
        s = sin_table_lookup(0x4000);
        co = cos_table_lookup(0x4000);
        tries--;
        this->fallVelocity.x = co * this->fallVelocity.x + s * this->fallVelocity.z;
        this->fallVelocity.z = -s * this->fallVelocity.x + co * this->fallVelocity.z;
    } while (tries > 0);
    if (tries == 0) {
        this->fallVelocity.x = this->fallVelocity.z = 0.0f;
        VecCopy(&c, (const Vec *)&this->position);
        c.y += 5.0f + fabs_float(this->fallVelocity.y);
        if (project_actor_to_ground(this, &c, 0) != 0) {
            if (!(this->position.y > c.y)) {
                this->position.y = c.y;
                done = 1;
            }
        } else {
            done = 1;
        }
    }
    if (done != 0) {
        this->adjust_height_to_ground();
        this->set_action_state(1);
    }
}
#pragma pop

void TObjEneDelDepth::update_ground_check() {
    Vec point;
    CsnHit *hit;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy(&point, &position);
        point.y += 15.0f;
        hit = csnVectorUnder(&point, ground_candidates.groups, 0x4000);
        if (hit != NULL) {
            groundFlags = hit->contact->flags;
            VecCopy(&groundPoint, &hit->contact->point);
        } else {
            VecCopy(&groundPoint, &position);
        }
    }
    if (groundFlags & 0x4000) {
        request_reflection_render();
    }
}

const char *del_depth_bomb_name = "TObjEneDelDepthBomb";

TObjEneDelDepthBomb::TObjEneDelDepthBomb(TObjEneDelDepth *parent, TObjChara *attacker, const Vec *origin, s32 level) : TObjChara(parent) {
    m_name = del_depth_bomb_name;
    source = attacker;
    rotation_y = ((TObjEneDelDepth *)m_up)->rotation_y;
    VecCopy(&position, origin);
    f32 sine = sin_table_lookup(rotation_y);
    f32 cosine = cos_table_lookup(rotation_y);
    speed = ((TObjEneDelDepth *)m_up)->get_bomb_speed();
    velocity.x = speed * sine;
    velocity.y = 0.0f;
    velocity.z = speed * cosine;
    techniqueLevel = level;
    distance = 0.0f;
    age = 0;
}

TObjEneDelDepthBomb::~TObjEneDelDepthBomb() {}

TObjEneDelDepthBomb *TObjEneDelDepthBomb::create(TObjEneDelDepth *parent, TObjChara *source, const Vec *position, s32 level) {
    return new TObjEneDelDepthBomb(parent, source, position, level);
}

void TObjEneDelDepthBomb::run_task() {
    s32 done = 0;
    f32 travelled;
    velocity.y += -0.05f;
    vec3_add_to(&position, &velocity);
    if (++age > 0x14F) {
        done = 1;
    }
    Vec ground = position;
    ground.y += 5.0f;
    if (project_actor_to_ground(this, &ground, &ground_normal) != 0) {
        groundHeight = ground.y;
        if (position.y <= groundHeight) {
            done = 1;
        }
    } else {
        done = 1;
    }
    if (render_check_stub() != 0) {
        done = 1;
    }
    travelled = distance + speed;
    distance = travelled;
    if (travelled >= 200.0f) {
        done = 1;
    }
    if (done != 0) {
        Vec impact;
        VecCopy(&impact, &position);
        impact.y += 5.0f;
        TTecRaBarta::create(source, &position, &impact, techniqueLevel);
        this->queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TObjEneDelDepthBomb::render() {
    Vec shadowScale;
    s32 rotationX;
    s32 rotationZ;
    BmlResource *data = TObjEneDelDepth::get_data();
    if (data == 0) {
        this->queue_destruction();
        return;
    }
    NJS_OBJECT *model = get_bml_model(data, 2);
    NJS_TEXLIST *texture = get_bml_texlist(data, 2);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_zyx(0, rotation_x, rotation_y, rotation_z);
    set_texture_list(texture);
    draw_chunk_object(model);
    pop_matrix();
    push_matrix();
    translate_matrix(0, position.x, 0.1f + groundHeight, position.z);
    direction_to_rotation_xz((u8 *)&ground_normal, &rotationX, &rotationZ);
    rotate_matrix_z(0, rotationZ);
    rotate_matrix_x(0, rotationX + 0x4000);
    f32 height = position.y - groundHeight;
    if (height > 40.0f) {
        height = 40.0f;
    } else if (height < 0.0f) {
        height = 0.0f;
    }
    f32 fade;
    shadowScale.x = shadowScale.y = 0.65f * (fade = 1.0f - height / 40.0f) + 0.1f;
    shadowScale.z = 1.0f;
    scale_current_matrix(&shadowScale.x);
    draw_blob_shadow(0);
    pop_matrix();
}
#pragma pop

s32 TObjEneDelDepthBomb::render_check_stub() { return 0; }
