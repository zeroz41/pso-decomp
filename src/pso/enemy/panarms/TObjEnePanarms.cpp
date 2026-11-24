#include "pso/enemy/EnemyPlacement.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnePanBARA.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "dolphin/mtx.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecJelin.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecZarua.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"

#include "pso/object/base/TObjChara.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/map/CsnQuery.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/model_render_state.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"

// The technique levels of TLobby::dispatch_shared_handler_a(0x33) (clamped to 0..14 by the callers).
struct PanBARATechniqueLevels {
    u8 pad_0[0x18];
    s32 resta_level;  // TTecResta::create (update_heal)
    s32 jelin_level;  // TTecJelin::create (attack_target_player)
    s32 zalure_level; // TTecZarua::create_instance (attack_target_player)
};

/* A half's one collision sphere (init_collision_body_parts in the constructor). */
CollisionBody panbara_collision_body[1] = {
    { { 0.0f, 16.5f, 0.0f }, 7.5f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

/* The two halves' motions, picked by the half's index through panbara_motion_params_by_half. */
TObjMotionAction panbara_pal_motion_params[10] = {
    { MOTION_MODE_LOOP, 0, 24, 0.8f, 0 },
    { MOTION_MODE_LOOP, 0, 27, 0.7f, 0 },
    { MOTION_MODE_LOOP, 0, 21, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 0, 0.8f, 0 },
    { MOTION_MODE_ONCE, 0, 20, 0.8f, 0 },
    { MOTION_MODE_ONCE, 0, 10, 1.3f, 0 },
    { MOTION_MODE_ONCE, 0, 13, 0.7f, 0 },
    { MOTION_MODE_ONCE, 0, 16, 0.7f, 0 },
    { MOTION_MODE_ONCE, 0, 18, 0.7f, 0 },
    { MOTION_MODE_ONCE, 0, 6, 0.6f, 0 },
};

TObjMotionAction panbara_par_motion_params[10] = {
    { MOTION_MODE_LOOP, 0, 25, 0.8f, 0 },
    { MOTION_MODE_LOOP, 0, 28, 0.7f, 0 },
    { MOTION_MODE_LOOP, 0, 22, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 1, 0.8f, 0 },
    { 0, 0, 0, 0.0f, 0 },
    { MOTION_MODE_ONCE, 0, 11, 1.3f, 0 },
    { MOTION_MODE_ONCE, 0, 14, 0.7f, 0 },
    { MOTION_MODE_ONCE, 0, 17, 0.7f, 0 },
    { MOTION_MODE_ONCE, 0, 19, 0.7f, 0 },
    { MOTION_MODE_ONCE, 0, 7, 0.6f, 0 },
};

// The TU's .rodata, in this order (the functions that read each table come in the same order in this last-to-first
// source); every table is indexed by the half (half_index) unless noted.
extern const char TObjEnePanBARA__class_name[] = "TObjEnePanBARA";
const char *TObjEnePanBARA__name = TObjEnePanBARA__class_name;

// The half's bml model/texlist index (ctor).
const s32 panbara_model_index_by_half[2] = {1, 2};

const Vec panarms_part_offset_table[2] = {{14.851f, 0.0f, -5.1765f}, {-14.1604f, 0.0f, -5.2659f}};

const s32 panbara_part_rotation_table[2] = {-26578, 26578};

const Vec panarms_parent_offset_table[2] = {{17.3438f, 0.0f, 5.6544f}, {-17.3438f, 0.0f, 5.6544f}};

const s32 panbara_parent_rotation_table[2] = {-10558, 10558};

const f32 panbara_target_range[2] = {100.0f, 80.0f};

// attack_target_player copies these (not indexed).
const DirectAttackPayload panbara_melee_attack_payload[1] = {{0, 0.0f}};

const DirectAttackPayload panbara_fallback_attack_payload[1] = {{0, 0.0f}};

const f32 panbara_max_move_speed[2] = {0.6f, 0.3f};

const s32 panbara_retreat_angle_offset[2] = {0x800, -0x800};

// spawn_npc_pair's NPC descriptors (local initialisers; their templates end the TU's .rodata). spawn_npc_pair fills
// in the bml's motion table before TLobby::spawn_npc_enemy.

typedef void (TObjEnePanBARA::*PanBARAStateFn)();

struct PanBARAState {
    PanBARAStateFn enter;
    PanBARAStateFn update;
};

extern "C" void __sinit_TObjEnePanarms_cpp();
__declspec(section ".ctors") static void *const panarms_global_initializer = (void *)__sinit_TObjEnePanarms_cpp;
// Indexed by the half's state: set_state runs enter, run_task runs update.
extern PanBARAState TObjEnePanarms__state_fn_table[17];

void ModelNodePositionCapture::clear() { set_chunk_model_node_callback(0); }

s32 TObjEnePanBARA::is_chasing_or_attacking() {
    return state == 9 || state == 11;
}

int TObjEnePanBARA::find_nearest_enemy_with_flag_alt_target(Vec *direction, f32 range) {
    s32 target_id;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    target_id = find_nearest_hittable_enemy(this, direction, range);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return static_cast<u16>(target_id);
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::set_random_action_timer(int minimum, int range) {
    action_timer = (s32)((f32)range * random_ratio() + (f32)minimum);
}
#pragma pop

s32 TObjEnePanBARA::is_below_half_hp() {
    u8 result = 0;
    if (half_index == 0 && partner->is_dying() == 0 && heal_called == 0 && hp <= split_hp / 2) {
        result = 1;
    }
    return result;
}

s32 TObjEnePanBARA::has_reached_partner() {
    return (u8)(state == 0xE);
}

s32 TObjEnePanBARA::is_moving_to_partner() {
    return (u8)(state == 0xD);
}

s32 TObjEnePanBARA::check_can_attack() {
    u8 result = 0;
    if (partner_death_seen == 0 && partner->is_dying() != 0) {
        result = 1;
    }
    return result;
}

s32 TObjEnePanBARA::is_phase_12() {
    return (u8)(state == 0xC);
}

void TObjMotion::clear_motion_flags(s32 flags) {
    motion_flags &= ~flags;
}

void __sinit_TObjEnePanarms_cpp() {
    TObjEnePanarms__state_fn_table[0].enter = &TObjEnePanBARA::reset_state;
    TObjEnePanarms__state_fn_table[0].update = &TObjEnePanBARA::snap_to_parent_position;
    TObjEnePanarms__state_fn_table[1].enter = &TObjEnePanBARA::init_split;
    TObjEnePanarms__state_fn_table[1].update = &TObjEnePanBARA::handle_split_flag;
    TObjEnePanarms__state_fn_table[2].enter = &TObjEnePanBARA::start_action;
    TObjEnePanarms__state_fn_table[2].update = &TObjEnePanBARA::update_wait;
    TObjEnePanarms__state_fn_table[3].enter = &TObjEnePanBARA::init_state_1;
    TObjEnePanarms__state_fn_table[3].update = &TObjEnePanBARA::update_move_to_target;
    TObjEnePanarms__state_fn_table[4].enter = &TObjEnePanBARA::init_state_16;
    TObjEnePanarms__state_fn_table[4].update = &TObjEnePanBARA::update_slide_in;
    TObjEnePanarms__state_fn_table[5].enter = &TObjEnePanBARA::restore_from_linked_object;
    TObjEnePanarms__state_fn_table[5].update = &TObjEnePanBARA::update_hit_state;
    TObjEnePanarms__state_fn_table[6].enter = &TObjEnePanBARA::enter_damage;
    TObjEnePanarms__state_fn_table[6].update = &TObjEnePanBARA::apply_effect_if_flagged;
    TObjEnePanarms__state_fn_table[7].enter = &TObjEnePanBARA::enter_dead;
    TObjEnePanarms__state_fn_table[7].update = &TObjEnePanBARA::update_dead;
    TObjEnePanarms__state_fn_table[8].enter = &TObjEnePanBARA::enter_vanished;
    TObjEnePanarms__state_fn_table[8].update = &TObjEnePanBARA::update_vanished;
    TObjEnePanarms__state_fn_table[9].enter = &TObjEnePanBARA::init_state_2;
    TObjEnePanarms__state_fn_table[9].update = &TObjEnePanBARA::update_chase_target;
    TObjEnePanarms__state_fn_table[10].enter = &TObjEnePanBARA::init_action;
    TObjEnePanarms__state_fn_table[10].update = &TObjEnePanBARA::update_retreat;
    TObjEnePanarms__state_fn_table[11].enter = &TObjEnePanBARA::init_attack_state2;
    TObjEnePanarms__state_fn_table[11].update = &TObjEnePanBARA::update_attack;
    TObjEnePanarms__state_fn_table[12].enter = &TObjEnePanBARA::enter_call_partner;
    TObjEnePanarms__state_fn_table[12].update = &TObjEnePanBARA::update_call_partner;
    TObjEnePanarms__state_fn_table[13].enter = &TObjEnePanBARA::start_phase2_timer150;
    TObjEnePanarms__state_fn_table[13].update = &TObjEnePanBARA::update_move_to_partner;
    TObjEnePanarms__state_fn_table[14].enter = &TObjEnePanBARA::start_phase3_timer12;
    TObjEnePanarms__state_fn_table[14].update = &TObjEnePanBARA::update_move_timer;
    TObjEnePanarms__state_fn_table[15].enter = &TObjEnePanBARA::init_open_state;
    TObjEnePanarms__state_fn_table[15].update = &TObjEnePanBARA::update_heal;
    TObjEnePanarms__state_fn_table[16].enter = &TObjEnePanBARA::init_attack_state;
    TObjEnePanarms__state_fn_table[16].update = &TObjEnePanBARA::update_action_timer;
}

PanBARAState TObjEnePanarms__state_fn_table[17] = {};

ModelNodePositionEntry panbara_capture_nodes[2] = {
    { 3 },
    { -1 },
};

TObjMotionAction *panbara_motion_params_by_half[2] = { panbara_pal_motion_params, panbara_par_motion_params };

s32 panarms_turn_delta_table[2] = { 0x4000, -0x4000 };

TObjEnePanBARA *TObjEnePanarms::create_bara(EnemyPlacement *setData, s32 index) {
    return new TObjEnePanBARA(new TObjControl(tl_04), setData, index);
}

struct PanBARAParams {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

// The 12-byte record TObjEnemy::exchange_object_state fills (mode 1) or stores (mode 0).
struct PanBARAObjectState {
    u32 unk_0;
    u16 unk_4;
    s16 unk_6;
    u8 unk_8[4];
};

TObjEnePanBARA::TObjEnePanBARA(TObject *parent, EnemyPlacement *setData, s32 index) : TObjEnemy(parent) {
    s32 i;

    m_name = TObjEnePanBARA__name;
    add_flags_2e4(2);
    apply_set_data(setData);
    // Same statements as TObjEnemy::clear_lobby_object_state (0x800F5D80); the original expands them here.
    PanBARAObjectState objectState;
    if (this->exchange_object_state(&objectState, 1) != 0) {
        objectState.unk_0 = 0;
        objectState.unk_6 = 0;
        this->exchange_object_state(&objectState, 0);
    }
    half_index = index;
    texlist = get_bml_texlist((BmlResource *)TObjEnePanarms__entry_params_resource, panbara_model_index_by_half[half_index]);
    model = (void *)get_bml_model((BmlResource *)TObjEnePanarms__entry_params_resource, panbara_model_index_by_half[half_index]);
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    collision_body_parts = init_collision_body_parts(this, panbara_collision_body, 1);
    set_action_table(panbara_motion_params_by_half[half_index]);
    set_motion_list(TObjEnePanarms__entry_params_resource->motions);
    set_animation(0);
    set_requested_action(0);
    VecCopy(&body_center, &position);
    velocity.x = velocity.y = velocity.z = 0.0f;
    target = NULL;
    switch (half_index) {
    case 0:
        bind_enemy_combat_stats(TLobby::register_boss(50), TLobby::dispatch_shared_handler_b(50),
                                TLobby::register_object(50));
        break;
    case 1:
        bind_enemy_combat_stats(TLobby::register_boss(51), TLobby::dispatch_shared_handler_b(51),
                                TLobby::register_object(51));
        break;
    default:
        return;
    }
    referenceHp = hp;
    register_by_id();
    movementParameters = NULL;
    if (half_index == 0) {
        set_param(23);
    } else {
        set_param(22);
    }
    node_capture = ModelNodePositionCapture::create(panbara_capture_nodes, &draw_callback_position);
    if (node_capture == NULL) {
        return;
    }
    move_speed = 0.0f;
    partner_death_seen = 0;
    if (half_index == 0) {
        pad_460 = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(50))->unk_0;
        attack_power = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(50))->unk_4;
    } else {
        pad_460 = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(51))->unk_0;
        jelin_chance = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(51))->unk_4;
        if (jelin_chance < 0.0f) {
            jelin_chance = 0.0f;
        } else if (jelin_chance > 1.0f) {
            jelin_chance = 1.0f;
        }
        zalure_chance = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(51))->unk_8;
        if (zalure_chance < 0.0f) {
            zalure_chance = 0.0f;
        } else if (zalure_chance > 1.0f) {
            zalure_chance = 1.0f;
        }
        if (jelin_chance + zalure_chance > 1.0f) {
            zalure_chance = 1.0f - jelin_chance;
        }
    }
    VecCopy(&shadow_position, &position);
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    state = 0;
    prev_state = 0;
    set_state(0);
}

TObjEnePanBARA::~TObjEnePanBARA() {
    free_collision_body_parts(this);
    collision_body_parts = NULL;
    ModelNodePositionCapture::destroy(node_capture);
}

void TObjEnePanBARA::run_task() {
    PanBARAStateFn fn;
    Vec a;
    f32 s;

    if (state != 0 && TObjPlayer::check_demo_mode() != 0) {
        set_state(0);
    }
    partner_delta.x = partner->position.x - position.x;
    partner_delta.y = 0.0f;
    partner_delta.z = partner->position.z - position.z;
    partner_angle = 10430.38043493439 * atan2_float(partner_delta.x, partner_delta.z);
    partner_distance = vector_length(&partner_delta);
    frame_count++;
    fn = TObjEnePanarms__state_fn_table[state].update;
    if (fn == 0) {
        return;
    }
    (this->*fn)();
    if (visible != 0) {
        actorFlags &= ~0x02000000;
    } else {
        actorFlags |= 0x02000000;
    }
    update_prev_position();
    if (state == 0) {
        return;
    }
    if (visible != 0) {
        if (state != 7) {
            submit_cursor_candidate(this, -1);
        }
        advance_animation();
        switch (state) {
        case 7:
            break;
        case 1:
            s = frame / 35.0f;
            calc_part_position(&a, NULL);
            subtract_vector(&a, &body_center);
            a.x *= s;
            a.z *= s;
            vec3_add_to(&a, &body_center);
            minimap_render_dot(&a, -0x5DB4, 1, 0);
            break;
        case 5:
            {
            s = frame / 45.0f;
            Vec b = body_center;
            subtract_vector(&b, &rejoin_position);
            b.x *= s;
            b.z *= s;
            vec3_add_to(&b, &rejoin_position);
            minimap_render_dot(&b, -0x5DB4, 1, 0);
            }
            break;
        default:
            minimap_render_dot(&body_center, -0x5DB4, 1, 0);
            break;
        }
    }
    if (collision_enabled == 0) {
        collision_body_parts->flags &= ~1;
    }
}

void TObjEnePanBARA::render() {
    s32 render_flags;
    s32 camera_mode;
    RenderFadeState *fade;
    s32 draw_now;
    if (update_object_view_visibility(500.0f, 20.0f) == 0 || visible == 0) {
        shadow_position.x = shadow_position.y = shadow_position.z = 0.0f;
        return;
    }
    camera_mode = 0;
    if (is_split_screen() != 0) {
        camera_mode = TCameraCtrl::get_camera_mode();
    }
    TObjPlayer::toggle_particle_effect();
    render_flags = model_render_flags;
    saved_model_render_flags = render_flags;
    model_render_flags = render_flags | 0x01000000 | 1;
    fade = &fades[camera_mode];
    fade->update();
    if (fade->updateFromCamera(&body_center.x) != 0) {
        fade->set_flags_and_apply_damage_color();
        draw_now = 1;
        if (defer_render() != 0) {
            draw_now = 0;
        }
        if (draw_now != 0) {
            draw();
        }
        fade->clear_flag_and_notify();
    } else {
        this->draw();
    }
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    this->update_linked_effect();
}

void TObjEnePanBARA::draw() { push_matrix(); post_translate_matrix(&position.x); rotate_matrix_y(NULL, rotation_y); TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist)); node_capture->install(); TObjMotion::draw(); node_capture->clear(); pop_matrix(); }

void TObjEnePanBARA::update_linked_effect() {
    Vec ground_normal;
    s32 tilt_x;
    s32 tilt_z;

    VecCopy(&shadow_position, &draw_callback_position);
    if (project_actor_to_ground(this, &shadow_position, &ground_normal) != 0) {
        push_matrix();
        shadow_position.y += 0.2f;
        post_translate_matrix(&shadow_position.x);
        direction_to_rotation_xz((u8 *)&ground_normal, &tilt_x, &tilt_z);
        rotate_matrix_z(NULL, tilt_z);
        rotate_matrix_y(NULL, rotation_y);
        rotate_matrix_x(NULL, tilt_x + 0x4000);
        scale_matrix(NULL, 2.0f, 2.0f, 1.0f);
        if (state != 7 && state != 8) {
            draw_blob_shadow(0);
        }
        pop_matrix();
    }
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::run_death_reaction() {
    s32 st = this->state;
    switch (st) {
    case 7:
    case 8:
        return;
    default:
        if (st == 0) {
            this->rotation_y = this->body->rotation_y + panarms_turn_delta_table[this->half_index];
            VecCopy(&this->position, &this->body->position);
            this->position.x += 10.0f * sin_table_lookup(this->rotation_y);
            this->position.z += 10.0f * cos_table_lookup(this->rotation_y);
            VecCopy(&this->body_center, &this->position);
        }
        set_state(7);
        break;
    }
}
#pragma pop

void TObjEnePanBARA::run_hit_reaction() {
    switch (state) {
    case 0:
    case 1:
    case 5:
    case 6:
        break;
    default:
        actorFlags &= ~0x200;
        set_state(6);
        break;
    }
}

void TObjEnePanBARA::run_miss_reaction() { this->actorFlags &= 0xfffffeff; }

void TObjEnePanBARA::start_split() {
    VecCopy(&position, &body->position);
    rotation_y = body->rotation_y;
    set_state(1);
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::init_state() {
    update_offset_from_parent();
    set_state(3);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::do_action_2() { set_state(2); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::start_merge() { set_state(5); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::reset_split() {
    if (state != 0) {
        set_state(0);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::die_with_body() {
    run_death_reaction();
}
#pragma pop

void TObjEnePanBARA::set_state(s32 next) {
    PanBARAStateFn enter;
    s32 *current = &state;
    if (prev_state != state) {
        prev_state = *current;
    }
    state = next;
    if (state < 0 || state >= 17) {
        return;
    }
    enter = TObjEnePanarms__state_fn_table[state].enter;
    if (enter) {
        (this->*enter)();
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::set_links(TObjEnePanarms *body, TObjEnePanBARA *partner) {
    this->body = body;
    this->partner = partner;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on
void TObjEnePanBARA::calc_part_position(Vec *pos, s32 *rotation) {
    f32 x;
    f32 z;
    f32 s;
    f32 c;

    x = panarms_part_offset_table[this->half_index].x;
    z = panarms_part_offset_table[this->half_index].z;
    s = sin_table_lookup(this->body->rotation_y);
    c = cos_table_lookup(this->body->rotation_y);
    VecCopy(pos, &this->body->position);
    pos->x += x * c + z * s;
    pos->z += -x * s + z * c;
    if (rotation != NULL) {
        *rotation = this->body->rotation_y - panbara_part_rotation_table[this->half_index];
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::calc_default_part_position() {
    calc_part_position(&position, &rotation_y);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on
void TObjEnePanBARA::update_offset_from_parent() {
    f32 x;
    f32 z;
    f32 s;
    f32 c;
    x = panarms_parent_offset_table[this->half_index].x;
    z = panarms_parent_offset_table[this->half_index].z;
    s = sin_table_lookup(this->body->rotation_y);
    c = cos_table_lookup(this->body->rotation_y);
    VecCopy(&this->rejoin_position, &this->body->position);
    this->rejoin_position.x += x * c + z * s;
    this->rejoin_position.z += -x * s + z * c;
    this->rejoin_rotation = this->body->rotation_y;
    this->rejoin_rotation += panbara_parent_rotation_table[this->half_index];
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on
s32 TObjEnePanBARA::try_move_with_detour(Vec *delta) {
    Vec dir = *delta;
    Vec t;
    Vec p;
    s32 i;
    s32 ang;
    f32 s;
    f32 c;
    f32 nx;
    dir.y = 0.0f;
    if (0.0f == vector_length(&dir)) {
        return 0;
    }
    VecCopy(&t, &position);
    vec3_add_to(&t, delta);
    if (horizontal_distance_squared(&t, &home_position) > 250000.0f) {
        return 0;
    }
    for (i = 1; i < 16; i++) {
        VecCopy(&p, &position);
        vec3_add_to(&p, &dir);
        p.y += 10.0f;
        if (project_actor_to_ground(this, &p, 0) != 0 && csnLookAt(&position, &p) == NULL) {
            VecCopy(&prev_position, &position);
            VecCopy(&position, &p);
            update_collisions();
            return 1;
        }
        ang = i << 12;
        if (i & 1) {
            ang *= -1;
        }
        s = sin_table_lookup(ang);
        c = cos_table_lookup(ang);
        nx = c * dir.x - s * dir.z;
        dir.x = nx;
        dir.z = s * nx + c * dir.z;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 TObjEnePanBARA::find_target_in_front() {
    Vec direction;
    s32 ret;

    if (get_state_flag() != 0) {
        ret = partner->is_chasing_or_attacking() == 0
            && (target_id = find_nearest_enemy_with_flag_alt_target(&direction, panbara_target_range[half_index])) != 0xffff
            && angle_difference_abs(rotation_y, (s32)(10430.38043493439 * atan2_float(direction.x, direction.z))) < 0x400;
        return (u8)ret;
    } else {
        ret = partner->is_chasing_or_attacking() == 0
            && (target_id = find_nearest_visible_player(this, &direction, panbara_target_range[half_index])) != 0xffff
            && angle_difference_abs(rotation_y, (s32)(10430.38043493439 * atan2_float(direction.x, direction.z))) < 0x400;
        return (u8)ret;
    }
}

#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::attack_target_player(s32 id) {
    TObjChara *player;
    f32 roll;
    s32 level;
    player = get_player_by_client_id(id);
    if (player != NULL) {
        if (this->half_index == 0) {
            DirectAttackPayload attack = panbara_melee_attack_payload[0];
            attack.power = this->attack_power;
            player->receive_direct_attack(this, attack, NULL, -1, -1);
            return;
        }
        roll = random_ratio();
        if (roll <= jelin_chance) {
            level = ((PanBARATechniqueLevels *)TLobby::dispatch_shared_handler_a(0x33))->jelin_level;
            if (level < 0 || level > 0xE) {
                level = 0;
            }
            TTecJelin::create((saddr)this, (saddr)&body_center, (saddr)&player->body_center, level);
            return;
        }
        if (roll <= jelin_chance + zalure_chance) {
            level = ((PanBARATechniqueLevels *)TLobby::dispatch_shared_handler_a(0x33))->zalure_level;
            if (level < 0 || level > 0xE) {
                level = 0;
            }
            TTecZarua::create_instance((saddr)this, &body_center, &player->body_center, level);
            return;
        }
        player->receive_direct_attack(this, panbara_fallback_attack_payload[0], NULL, -1, -1);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::spawn_periodic_particle() {
    Vec point;
    if (!(frame_count & 7)) {
        VecCopy(&point, &shadow_position);
        point.y += 5.0f;
        spawn_particle_effect(&point, 0xF3);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::reset_state() {
    collision_body_parts->flags &= ~1;
    move_speed = 0.0f;
    visible = 0;
    collision_enabled = 0;
}
#pragma pop

void TObjEnePanBARA::snap_to_parent_position() {
    VecCopy(&position, &body->position);
    position.x += 1000.0f;
    position.y += 1000.0f;
    VecCopy(&body_center, &position);
}

void TObjEnePanBARA::init_split() {
    collision_body_parts->flags &= ~1;
    this->visible = 1;
    this->collision_enabled = 0;
    this->hp = (s16) ((this->body->hp + 1) / 2);
    this->split_hp = (s32) this->hp;
    this->heal_called = 0;
    clear_motion_flags(0x10);
    this->motion_flags |= 1;
    set_requested_action(9);
}

void TObjEnePanBARA::handle_split_flag() {
    if (this->motion_flags & 0x10) {
        calc_default_part_position();
        set_state(2);
    }
}

void TObjEnePanBARA::start_action() {
    this->set_random_action_timer(0xF, 0x3C);
    collision_body_parts->flags |= 1;
    this->collision_enabled = 1;
    if (this->prev_state == 1) {
        this->motion_flags |= 1;
    } else {
        this->motion_flags &= ~1;
    }
    set_requested_action(0);
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::update_wait() {
    Vec v;
    Vec a;
    f32 scale;
    s32 idx;
    f32 max;
    s32 angle;
    s32 ok;
    TObjPlayer *p;
    TObjCollidable *e;

    if (--this->action_timer > 0) {
        return;
    }
    if (this->action_timer == 0) {
        this->motion_flags &= ~1;
        this->set_requested_action(1);
    }
    if (this->half_index == 1 && partner->is_phase_12() != 0) {
        if (partner_distance < 27.5f) {
            set_state(0xA);
            return;
        }
        set_state(0xD);
        return;
    }
    idx = find_nearest_visible_player(this, &v, 500.0f);
    ok = 0;
    if (idx != 0xFFFF) {
        angle = (s32)(10430.38043493439 * atan2_float(v.x, v.z));
        if (angle_difference_abs(this->rotation_y, angle) < 0x208) {
            ok = 1;
        }
    }
    if (ok != 0) {
        this->rotation_y = approach_angle_limited(this->rotation_y, angle, 0x208);
        scale = 75.0f;
        p = get_player_by_client_id(idx);
        if (p != NULL) {
            if (this->half_index == 1) {
                scale *= -1.0f;
            }
            VecCopy(&a, &p->position);
            a.x += scale * cos_table_lookup(this->rotation_y);
            a.z -= scale * sin_table_lookup(this->rotation_y);
            subtract_vector(&a, &position);
            a.y = 0.0f;
            if (vector_length(&a) <= 0.01f) {
                a.x = a.z = 0.0f;
            } else {
                normalize_vector(&a);
            }
        }
    } else {
        if (this->half_index == 0) {
            this->rotation_y -= 0x208;
        } else {
            this->rotation_y += 0x208;
        }
        a.x = sin_table_lookup(this->rotation_y);
        a.z = cos_table_lookup(this->rotation_y);
        a.y = 0.0f;
    }
    max = panbara_max_move_speed[this->half_index];
    if ((this->move_speed += 0.025f) > max) {
        move_speed = max;
    }
    a.x *= move_speed;
    a.z *= move_speed;
    try_move_with_detour(&a);
    if (is_below_half_hp() != 0) {
        set_state(0xC);
        return;
    }
    if (check_can_attack() != 0) {
        set_state(0x10);
        return;
    }
    if (find_target_in_front() != 0) {
        e = find_entity_by_id(this->target_id);
        if (e != NULL && horizontal_distance_squared(&e->position, &position) < 756.25f) {
            set_state(0xA);
            return;
        }
        set_state(9);
    }
}
#pragma pop

void TObjEnePanBARA::init_state_1() {
    collision_body_parts->flags |= 1;
    this->motion_flags &= ~1;
    set_requested_action(1);
}

void TObjEnePanBARA::update_move_to_target() {
    Vec step;
    f32 dist;
    if (check_can_attack() != 0) {
        set_state(0x10);
        return;
    }
    if (this->partner->is_dying() != 0) {
        set_state(2);
        return;
    }
    VecCopy(&step, &this->rejoin_position);
    subtract_vector(&step, &this->position);
    step.y = 0.0f;
    dist = vector_length(&step);
    if (dist <= 0.01f) {
        step.x = 1.0f;
        step.z = 0.0f;
    } else {
        normalize_vector(&step);
    }
    if (collision_body_parts->flags & 0x01C00000) {
        f32 t = step.x;
        step.x = step.z;
        step.z = -t;
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (10430.38043493439 * atan2_float(step.x, step.z)), 0x208);
    if (dist > 15.0f) {
        if ((this->move_speed += 0.025f) > 0.6f) {
            this->move_speed = 0.6f;
        }
    } else {
        if ((this->move_speed -= 0.025f) < 0.3f) {
            this->move_speed = 0.3f;
        }
    }
    step.x *= this->move_speed;
    step.z *= this->move_speed;
    try_move_with_detour(&step);
    if (horizontal_distance_squared(&this->rejoin_position, &this->position) < 56.25f) {
        set_state(4);
    }
}

void TObjEnePanBARA::init_state_16() {
    collision_body_parts->flags |= 1;
    this->action_timer = 0x16;
    this->motion_flags &= ~1;
    set_requested_action(1);
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::update_slide_in() {
    Vec step;
    f32 fraction;
    s32 frames_left;
    if (check_can_attack() != 0) {
        set_state(0x10);
        return;
    }
    if (this->partner->is_dying() != 0) {
        set_state(2);
        return;
    }
    frames_left = this->action_timer - 5;
    if (frames_left > 0) {
        fraction = 1.0f / (f32) frames_left;
        VecCopy(&step, &rejoin_position);
        subtract_vector(&step, &position);
        step.x *= fraction;
        step.y *= fraction;
        step.z *= fraction;
        vec3_add_to(&position, &step);
        this->rotation_y = (s32) ((fraction * (f32) angle_diff_s16(this->rotation_y, this->rejoin_rotation)) + (f32) this->rotation_y);
    } else if (frames_left == 0) {
        set_requested_action(0);
    }
    this->action_timer--;
}
#pragma pop

void TObjEnePanBARA::restore_from_linked_object() {
    collision_body_parts->flags &= ~1;
    VecCopy(&this->position, &this->body->position);
    this->rotation_y = this->body->rotation_y;
    this->motion_flags |= 1;
    set_requested_action(8);
}

void TObjEnePanBARA::update_hit_state() {
    if (this->partner->is_dying() != 0) {
        set_state(2);
        return;
    }
    if (this->motion_flags & 0x10) {
        set_state(0);
    }
}

void TObjEnePanBARA::enter_damage() {
    visible = 1;
    collision_enabled = 1;
    static s32 panarms_sound_effect_pair[2] = { remap_sound_for_area(0x4003BC34), remap_sound_for_area(0x4003BC33) };
    play_sound_effect(panarms_sound_effect_pair[half_index], &position, 0, 0);
    motion_flags &= ~1;
    set_requested_action(5);
}

void TObjEnePanBARA::apply_effect_if_flagged() {
    if (this->motion_flags & 0x10) {
        set_state(this->prev_state);
    }
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::enter_dead() {
    Vec v;
    s32 motion;
    this->visible = 1;
    this->collision_enabled = 0;
    refresh_lobby_state();
    motion = 7;
    this->motion_flags &= ~1;
    if (find_nearest_visible_player(this, &v, 500.0f) != 0xFFFF) {
        if (v.x * sin_table_lookup(this->rotation_y) + v.z * cos_table_lookup(this->rotation_y) < 0.0f) {
            motion = 6;
        }
    }
    set_requested_action(motion);
    static s32 TObjEnePanarms__sound_ids[2] = { remap_sound_for_area(0x4003B836), remap_sound_for_area(0x4003BB35) };
    play_sound_effect(TObjEnePanarms__sound_ids[this->half_index], &position, 0, 0);
    this->action_timer = 0xA4;
}
#pragma pop

void TObjEnePanBARA::update_dead() {
    Vec v;
    f32 f;
    this->action_timer--;
    static f32 panarms_particle_frame_window = panbara_pal_motion_params[6].speed;
    f = this->frame;
    if (f >= 24.0f && f < 24.0f + panarms_particle_frame_window) {
        VecCopy(&v, &shadow_position);
        v.y += 5.0f;
        spawn_particle_effect(&v, 0xF3);
    }
    if (this->action_timer <= 0x78) {
        if (this->action_timer == 0x78) {
            spawn_ground_effect(&shadow_position, 0x78);
            TObjPlayer::spawn_dead_spot_default(&shadow_position, 6);
        }
        this->position.y += -0.15625f;
        if ((s32) this->action_timer < 0) {
            set_state(8);
        }
    }
}

void TObjEnePanBARA::enter_vanished() {
    collision_body_parts->flags &= ~1;
    visible = 0;
    collision_enabled = 0;
}

void TObjEnePanBARA::update_vanished() {  }

void TObjEnePanBARA::init_state_2() {
    collision_body_parts->flags |= 1;
    this->visible = 1;
    this->collision_enabled = 1;
    this->action_timer = 0x5A;
    this->motion_flags &= ~1;
    set_requested_action(2);
}

void TObjEnePanBARA::update_chase_target() {
    Vec step;
    TObjCollidable *p;

    p = find_entity_by_id((u16) this->target_id);
    if (p == NULL || (p->actorFlags & 0x02000800)) {
        set_state(2);
        return;
    }
    this->action_timer--;
    VecCopy(&step, &p->position);
    subtract_vector(&step, &this->position);
    step.y = 0.0f;
    if (vector_length(&step) <= 0.01f) {
        step.x = 1.0f;
        step.z = 0.0f;
    } else {
        normalize_vector(&step);
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (10430.38043493439 * atan2_float(step.x, step.z)), 0x101);
    if (this->action_timer > 0) {
        if ((this->move_speed += 0.075f) > 1.25f) {
            this->move_speed = 1.25f;
        }
    } else {
        if ((this->move_speed -= 0.075f) < 0.0f) {
            this->move_speed = 0.0f;
        }
    }
    step.x *= this->move_speed;
    step.z *= this->move_speed;
    try_move_with_detour(&step);
    if (0.0f == this->move_speed) {
        set_state(0xA);
        return;
    }
    if (horizontal_distance_squared(&p->position, &this->position) < 625.0f) {
        set_state(0xB);
        return;
    }
    if (is_below_half_hp() != 0) {
        set_state(0xC);
        return;
    }
    if (check_can_attack() != 0) {
        set_state(0x10);
        return;
    }
    spawn_periodic_particle();
}

void TObjEnePanBARA::init_action() {
    collision_body_parts->flags |= 1;
    this->set_random_action_timer(0xF, 0x1E);
    this->visible = 1;
    this->collision_enabled = 1;
    this->move_speed = 0.0f;
    this->motion_flags &= ~1;
    set_requested_action(2);
}

void TObjEnePanBARA::update_retreat() {
    Vec v;

    if (--this->action_timer > 0) {
        if ((this->move_speed += -0.075f) < -1.0f) {
            this->move_speed = -1.0f;
        }
    } else {
        if ((this->move_speed += 0.025f) >= 0.0f) {
            this->move_speed = 0.0f;
            set_state(2);
            return;
        }
    }
    v.x = this->move_speed * sin_table_lookup(this->rotation_y);
    v.z = this->move_speed * cos_table_lookup(this->rotation_y);
    v.y = 0.0f;
    try_move_with_detour(&v);
    if (is_below_half_hp() != 0) {
        set_state(0xC);
        return;
    }
    if (check_can_attack() != 0) {
        set_state(0x10);
        return;
    }
    this->spawn_periodic_particle();
}

void TObjEnePanBARA::init_attack_state2() {
    collision_body_parts->flags |= 1;
    this->visible = 1;
    this->collision_enabled = 1;
    this->move_speed = 0.0f;
    this->action_timer = 12;
    this->motion_flags &= ~1;
    set_requested_action(3);
}

void TObjEnePanBARA::update_attack() {
    TObjCollidable *entity;

    entity = find_entity_by_id((u16) this->target_id);
    if (entity == NULL || (entity->actorFlags & 0x02000800)) {
        set_state(2);
        return;
    }
    if (--this->action_timer == 0) {
        attack_target_player(this->target_id);
        play_sound_effect(remap_sound_for_area(0x4003B72F), &this->position, 0, 0);
    }
    if (this->frame < 5.0f) {
        this->rotation_y = approach_angle_limited(this->rotation_y, panbara_retreat_angle_offset[this->half_index] + (s32) (10430.38043493439 * atan2_float(entity->position.x - this->position.x, entity->position.z - this->position.z)), 0x200);
    }
    if (this->motion_flags & 0x10) {
        set_state(0xA);
    }
}

void TObjEnePanBARA::enter_call_partner() {
    if (this->half_index != 1) {
        collision_body_parts->flags |= 1;
        this->visible = 1;
        this->collision_enabled = 1;
        this->move_speed = 0.0f;
        this->action_timer = 0x96;
        this->heal_called = 1;
        play_sound_effect(this->remap_sound_for_area(0x4003BC2D), &this->position, 0, 0);
        this->motion_flags &= ~1;
        this->set_requested_action(2);
    }
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::update_call_partner() {
    if (partner->has_reached_partner() != 0) {
        set_state(0xF);
        return;
    }
    if (check_can_attack() != 0) {
        set_state(0x10);
        return;
    }
    if ((--this->action_timer < 0 && partner->is_moving_to_partner() == 0) || this->partner->is_dying() != 0) {
        set_state(2);
        return;
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (int) ((s32) ((6144.0f * sin_table_lookup((int) (this->action_timer << 0xC))) + (f32) this->partner_angle)), 0x1111);
    if (!(this->action_timer & 0x3F)) {
        play_sound_effect(this->remap_sound_for_area(0x4003BC2D), &this->position, 0, 0);
    }
    this->spawn_periodic_particle();
}
#pragma pop

void TObjEnePanBARA::start_phase2_timer150() {
    if (this->half_index != 0) {
        collision_body_parts->flags |= 1;
        this->visible = 1;
        this->collision_enabled = 1;
        this->move_speed = 0.0f;
        this->action_timer = 0x96;
        this->motion_flags &= ~1;
        set_requested_action(2);
    }
}

void TObjEnePanBARA::update_move_to_partner() {
    Vec v;
    if (check_can_attack() != 0) {
        set_state(0x10);
        return;
    }
    if (--this->action_timer < 0 || partner->is_phase_12() == 0) {
        set_state(2);
        return;
    }
    VecCopy(&v, &partner_delta);
    if (vector_length(&v) <= 0.01f) {
        v.x = 1.0f;
        v.z = 0.0f;
    } else {
        normalize_vector(&v);
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)), 0x888);
    if (this->action_timer < 0x87) {
        if ((this->move_speed += 0.075f) > 1.25f) {
            this->move_speed = 1.25f;
        }
        v.x *= this->move_speed;
        v.z *= this->move_speed;
        try_move_with_detour(&v);
    }
    if (partner_distance < 25.0f) {
        set_state(0xE);
        return;
    }
    this->spawn_periodic_particle();
}

void TObjEnePanBARA::start_phase3_timer12() {
    if (this->half_index != 0) {
        collision_body_parts->flags |= 1;
        this->visible = 1;
        this->collision_enabled = 1;
        this->move_speed = 0.0f;
        this->action_timer = 0xC;
        this->motion_flags &= ~1;
        set_requested_action(3);
    }
}

void TObjEnePanBARA::update_move_timer() {
    if (this->partner->is_dying() != 0 || (this->motion_flags & 0x10)) {
        set_state(0xA);
        return;
    }
    if (--this->action_timer == 0) {
        play_sound_effect(remap_sound_for_area(0x4003B72F), &this->position, 0, 0);
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, this->partner_angle - 0x800, 0x200);
}

void TObjEnePanBARA::init_open_state() {
    if (this->half_index != 1) {
        collision_body_parts->flags |= 1;
        this->visible = 1;
        this->collision_enabled = 1;
        this->move_speed = 0.0f;
        this->action_timer = 6;
        this->motion_flags &= ~1;
        set_requested_action(0);
    }
}

void TObjEnePanBARA::update_heal() {
    s32 level;
    if (--this->action_timer == 0) {
        set_requested_action(4);
    }
    if (-15.0f == (f32) this->action_timer) {
        level = ((PanBARATechniqueLevels *)TLobby::dispatch_shared_handler_a(0x33))->resta_level;
        if (level < 0 || level > 0xE) {
            level = 0;
        }
        TTecResta::create(this, &position, level);
        play_sound_effect(this->remap_sound_for_area(0x4003BC31), &position, 0, 0);
    }
    if (this->motion_flags & 0x10) {
        set_state(2);
    }
}

void TObjEnePanBARA::init_attack_state() {
    collision_body_parts->flags |= 1;
    this->visible = 1;
    this->collision_enabled = 1;
    this->move_speed = 0.0f;
    this->action_timer = 0x3C;
    this->partner_death_seen = 1;
    if (angle_difference_abs(this->rotation_y, this->partner_angle) < 0x2000) {
        if (angle_diff_s16(this->rotation_y, this->partner_angle) >= 0) {
            this->rotation_y = (this->partner_angle - 0x2000);
        } else {
            this->rotation_y = (this->partner_angle + 0x2000);
        }
    }
    this->motion_flags &= ~1;
    set_requested_action(2);
}

void TObjEnePanBARA::update_action_timer() {
    s32 prev_rotation;

    if (--this->action_timer < 0) {
        set_state(2);
        return;
    }
    prev_rotation = this->rotation_y;
    this->rotation_y = approach_angle_limited(this->rotation_y, this->partner_angle, 0x888);
    if (angle_difference_abs(prev_rotation, this->rotation_y) == 0) {
        set_requested_action(0);
    }
}

void TObjEnePanarms::spawn_npc_pair() {
    NpcAnimationBinding binding_a = { NULL, panbara_pal_motion_params, 0, 1, 10 };
    BmlMotionEntry *motions = TObjEnePanarms__entry_params_resource->motions;
    binding_a.motions = motions;
    NpcAnimationBinding binding_b = { NULL, panbara_par_motion_params, 0, 1, 10 };
    binding_b.motions = motions;
    BmlModelEntry *models = TObjEnePanarms__entry_params_resource->models;
    TObjNpcEnemy::register_animated_chunk(0x24, models[1].model, models[1].texlist, &binding_a, 7.5f, 0.0f);
    models = TObjEnePanarms__entry_params_resource->models;
    TObjNpcEnemy::register_animated_chunk(0x25, models[2].model, models[2].texlist, &binding_b, 7.5f, 0.0f);
}

int TObjEnePanarms::find_nearest_enemy_with_flag(Vec *direction, f32 range) {
    s32 target_id;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    target_id = find_nearest_hittable_enemy(this, direction, range);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return static_cast<u16>(target_id);
}
