#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/memory.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/AreaSound.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/math/AngleUnits.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/math/FloatRounding.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/enemy/berura/TObjEneRe7BeruraPunch.h"
#include "pso/animation/MotionContext.h"
#include "pso/render/NinjaUtil.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/math/MatrixVector.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/StripBufferPair.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/object/base/TObjBase.h"

#pragma defer_codegen on
extern "C" {
extern TObjEneRe7BeruraPart TObjEneRe7Berura__detached_part_states[];
player_stats *TObjEneRe7Berura__stat_handle_table[1];
ActorParamBlock *TObjEneRe7Berura__shared_object_handles[1];
void * TObjEneRe7Berura__handler_table_a[1];
BmlResource * TObjEneRe7Berura__shared_resource;
s32 re7_berura_demo_state;
// the render flags demo_frame_callback/advance_state save while one node draws with 0x8000 cleared (name inferred)
s32 berura_node_saved_render_flags;
Vec * re7_berura_demo_camera_ptr;
s32 berura_demo_flag;
s32 re7_berura_demo_flag;
TUnk_80490470 * TObjEneRe7Berura__demo_target;
u8 * re7_berura_static_buffer;
s32 * berura_node_matrix_ptr_a;
s16 * berura_node_matrix_ptr_b;
StripBufferPair *belra_uv_animation_buffer;
s32 berura_attack_node_range_start;
s32 berura_attack_node_range_end;
GC_Mtx *TObjEneRe7Berura__node_matrix_cursor;
Vec * berura_attack_node_vec_ptr;
SampledMotionPoints * belra_trail_buffer;
extern TObjMotionAction TObjEneRe7Berura__animation_definitions[];
}




extern AttackParams *TObjEneRe7Berura__attack_stat_handles[];


extern const NpcAnimationBinding ene_re7_berura_attack_def;
// The lobby table ids load_static_resources registers: base stats
// (register_boss), resistances (register_object), lobby parameters
// (dispatch_shared_handler_a); see TObjEneDD::reset_hp. Names inferred.
const s32 berura_base_stat_ids[1] = {14};
const s32 berura_resist_stat_ids[1] = {14};
const s32 berura_lobby_param_ids[1] = {14};
// BeruraData.cpp: the attack-stat ids (dispatch_shared_handler_b) and, per
// stat set (0 normal, 1 reload_stats_from_tables), the row of each handle
// table reset_hp/reload_stats_keep_hp_tp take. Names inferred.
extern const s32 berura_attack_stat_ids[];
extern const s32 TObjEneRe7Berura__base_stat_rows[];
extern const s32 TObjEneRe7Berura__attack_stat_rows[];
extern const s32 TObjEneRe7Berura__resist_stat_rows[];
extern TObject *tl_04;


TObjEneRe7BeruraMovementParameters berura_init_params = {
    225.0f, 0.0f, 0x600, {0, 0, 0, 0},
};

// the collision body init_enemy hands init_model (name inferred)
CollisionBody berura_collision_body = {
    {0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f,
};

const char *bm_ene_re7_berura_model_names[2] = {
    "re7_b_bell_body.nj", NULL,
};

const char *bm_ene_re7_berura_motion_names[9] = {
    "attack_re7_b_body.njm", "damege_re7_b_body.njm", "die_re7_b_body.njm", "lattack_re7_b_body.njm",
    "memai_re7_b_body.njm", "rattack_re7_b_body.njm", "wait_re7_b_body.njm", "walk_re7_b_body.njm",
    NULL,
};

BmlResourceDescriptor ene_berura_bml_descriptor = {
    "bm_ene_re7_berura.bml", bm_ene_re7_berura_model_names, bm_ene_re7_berura_motion_names, 1, 8,
};

// inferred: .sdata pointer to the "TObjEneRe7Berura" class-name string, stored in m_name by the constructor
const char *TObjEneRe7Berura__name = "TObjEneRe7Berura";

TObjMotionAction TObjEneRe7Berura__animation_definitions[8] = {
    {1, 0, 6, 0.8f, 0},
    {1, 0, 7, 0.8f, 0},
    {3, 0, 0, 0.8f, 0},
    {2, 0, 3, 0.8f, 0},
    {2, 0, 5, 0.8f, 0},
    {1, 0, 4, 0.8f, 0},
    {3, 0, 1, 0.8f, 0},
    {3, 0, 2, 0.8f, 0},
};

const NpcAnimationBinding ene_re7_berura_attack_def = { NULL, TObjEneRe7Berura__animation_definitions, 0, 1, 9 };

// the scale render hands draw_ground_shadow (name inferred)
extern const Vec berura_shadow_scale = {2.0f, 1.0f, 2.0f};

f32 lbl_805007C8[3];
AttackParams *TObjEneRe7Berura__attack_stat_handles[2];
TObjEneRe7BeruraPart TObjEneRe7Berura__detached_part_states[2];

void TObjEneRe7BeruraPart::hide() {
    first_object->evalflags |= NJD_EVAL_HIDE;
    last_object->evalflags |= NJD_EVAL_HIDE;
}

void TObjEneRe7BeruraPart::show() {
    first_object->evalflags &= ~NJD_EVAL_HIDE;
    last_object->evalflags &= ~NJD_EVAL_HIDE;
}

void TObjEneRe7Berura::load_static_resources() {
    s32 pair[4];
    Vec vecs[4];
    BmlResource *r;
    NJS_OBJECT *m;
    u8 *buf;
    s32 i;
    void *p;
    if (TObjEneDD::check_v2_mode() != 0) {
        r = load_enemy_bml_resource_named(&ene_berura_bml_descriptor, "bm_ene_re7_berura_a.bml");
    } else {
        r = load_enemy_bml_resource(&ene_berura_bml_descriptor);
    }
    TObjEneRe7Berura__shared_resource = r;
    lbl_805007C8[0] = 0.0f;
    lbl_805007C8[1] = 0.0f;
    lbl_805007C8[2] = 0.0f;
    re7_berura_demo_state = 0;
    berura_node_saved_render_flags = 0;
    re7_berura_demo_camera_ptr = 0;
    berura_demo_flag = 0;
    re7_berura_demo_flag = 0;
    TObjEneRe7Berura__demo_target = 0;
    m = r->models->model;
    buf = (u8 *)mem_alloc(0x660);
    re7_berura_static_buffer = buf;
    TObjEneRe7Berura__detached_part_states[0].node_matrices = reinterpret_cast<GC_Mtx *>(buf);
    TObjEneRe7Berura__detached_part_states[1].node_matrices = reinterpret_cast<GC_Mtx *>(buf) + 17;
    TObjEneRe7Berura__detached_part_states[0].first_node = 0x21;
    TObjEneRe7Berura__detached_part_states[0].last_node = 0x31;
    TObjEneRe7Berura__detached_part_states[1].first_node = 0x38;
    TObjEneRe7Berura__detached_part_states[1].last_node = 0x48;
    TObjEneRe7Berura__detached_part_states[0].action = 3;
    TObjEneRe7Berura__detached_part_states[0].emit_end_frame = 20.0f;
    TObjEneRe7Berura__detached_part_states[0].launch_frame = 30.0f;
    TObjEneRe7Berura__detached_part_states[1].action = 4;
    TObjEneRe7Berura__detached_part_states[1].emit_end_frame = 19.0f;
    TObjEneRe7Berura__detached_part_states[1].launch_frame = 29.0f;
    for (i = 0; i < 2; i++) {
        TObjEneRe7BeruraPart *e = &TObjEneRe7Berura__detached_part_states[i];
        AnimationMotion *ent = TObjEneRe7Berura__shared_resource->motions[TObjEneRe7Berura__animation_definitions[e->action].motion].motion;
        set_motion_packed_rotation();
        bind_motion_context((NJS_MOTION *)ent, e->launch_frame);
        TObjEneRe7Berura::capture_arm_matrices(m, e);
        clear_motion_packed_rotation();
        e->first_object = find_model_node(m, e->first_node);
        e->last_object = find_model_node(m, e->last_node);
        e->object.evalflags = NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL;
        e->object.model = e->first_object->model;
        e->object.pos[0] = 0.0f;
        e->object.pos[1] = 0.0f;
        e->object.pos[2] = 0.0f;
        e->object.ang[0] = 0;
        e->object.ang[1] = 0;
        e->object.ang[2] = 0;
        e->object.scl[0] = 1.0f;
        e->object.scl[1] = 1.0f;
        e->object.scl[2] = 1.0f;
        e->object.child = e->first_object->child;
        e->object.sibling = 0;
    }
    berura_node_matrix_ptr_a = (s32 *)(((NJS_CNK_MODEL *)find_model_node(m, 2)->model)->polygon_list + 4);
    berura_node_matrix_ptr_b = ((NJS_CNK_MODEL *)find_model_node(m, 1)->model)->polygon_list + 4;
    belra_uv_animation_buffer = new StripBufferPair(TObjEneRe7Berura__shared_resource->models->model, 2);
    SampledMotionPoints *sampled = new SampledMotionPoints(4, 14.0f, 17.0f, 0.8f);
    belra_trail_buffer = sampled;
    pair[0] = 0x2E;
    pair[1] = 0x2E;
    pair[2] = 0x45;
    pair[3] = 0x45;
    for (i = 0; i < 4; i++) {
        vecs[i].x = 0.0f;
        vecs[i].y = 0.0f;
        vecs[i].z = 0.0f;
    }
    vecs[0].x = 10.0f;
    vecs[2].x = 10.0f;
    sampled->sample((NJS_OBJECT *)TObjEneRe7Berura__shared_resource->models->model, (NJS_MOTION *)TObjEneRe7Berura__shared_resource->motions[TObjEneRe7Berura__animation_definitions[2].motion].motion, pair, vecs);
    for (i = 0; i < 1; i++) {
        TObjEneRe7Berura__stat_handle_table[i] = TLobby::register_boss(berura_base_stat_ids[i]);
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneRe7Berura__attack_stat_handles[j] = TLobby::dispatch_shared_handler_b(berura_attack_stat_ids[j]);
    }
    for (i = 0; i < 1; i++) {
        TObjEneRe7Berura__shared_object_handles[i] = TLobby::register_object(berura_resist_stat_ids[i]);
    }
    for (i = 0; i < 1; i++) {
        TObjEneRe7Berura__handler_table_a[i] = TLobby::dispatch_shared_handler_a(berura_lobby_param_ids[i]);
    }
    {
        NpcAnimationBinding atk = ene_re7_berura_attack_def;
        atk.motions = TObjEneRe7Berura__shared_resource->motions;
        TObjNpcEnemy::register_animated_chunk(0x15, TObjEneRe7Berura__shared_resource->models->model, TObjEneRe7Berura__shared_resource->models->texlist, &atk, 8.0f, 0.0f);
    }
}

void *TObjEneRe7Berura::create() {
    return new TObjEneRe7Berura(tl_04, this);
}

void TObjEneRe7Berura::destroy_children() {
    if (belra_trail_buffer != NULL) {
        delete belra_trail_buffer;
        belra_trail_buffer = NULL;
    }
    if (belra_uv_animation_buffer != NULL) {
        delete belra_uv_animation_buffer;
        belra_uv_animation_buffer = NULL;
    }
    if (re7_berura_static_buffer != NULL) {
        mem_free(re7_berura_static_buffer);
        re7_berura_static_buffer = NULL;
    }
    if (TObjEneRe7Berura__shared_resource != NULL) {
        delete TObjEneRe7Berura__shared_resource;
        TObjEneRe7Berura__shared_resource = NULL;
    }
}

TObjEneRe7Berura::TObjEneRe7Berura(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    m_name = TObjEneRe7Berura__name;
    invoke_initialization_hook(set_data);
    sub_80095328();
    init_enemy();
}

void TObjEneRe7Berura::init_enemy() {
    s32 i;
    s32 j;
    init_position_vectors();
    model = (void *)TObjEneRe7Berura__shared_resource->models->model;
    texlist = TObjEneRe7Berura__shared_resource->models->texlist;
    init_model(&berura_collision_body, 1);
    set_action_table(TObjEneRe7Berura__animation_definitions);
    set_motion_list(TObjEneRe7Berura__shared_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    reset_hp(TObjEneRe7Berura__stat_handle_table[TObjEneRe7Berura__base_stat_rows[0]],
        TObjEneRe7Berura__attack_stat_handles[TObjEneRe7Berura__attack_stat_rows[0]],
        TObjEneRe7Berura__shared_object_handles[TObjEneRe7Berura__resist_stat_rows[0]]);
    set_state_8();
    movementParameters = &berura_init_params;
    initialize_enemy_state(0x25);
    wall_reach = 10.0f;
    enemy_init_acquire_period(0x3C);
    enemy_init_validate_period(0x3C);
    status_flags = 0;
    node2_color = -1;
    node1_color = 0xFF000000;
    texture_scroll_speed = 0;
    texture_scroll = 0;
    dizzy_level = 1;
    body_fade.reset_color();
    current_arm = 1;
    punch = spawn_punch();
    arm_fade.reset_color();
    if (TObjEneDD::check_v2_mode() != 0) {
        arm_fade.set_rate_from_divisor(0xA);
    }
    for (i = 0; i < 2; i++) {
        arm_flags[i] = 0;
        VecCopy(&hand_positions[i], &position);
        hand_emitters[i] = 0;
    }
    attack_trails[0] = TAttackTraceStrip::create(0xFF00FF00, 0xA0703030);
    attack_trails[1] = TAttackTraceStrip::create(0xFF00FF00, 0xA0703030);
    for (j = 0; j < 4; j++) {
        camera_fades[j].activate_and_dispatch();
    }
    turn_limit = 0;
    turn_total = 0;
    step = 0;
    counter = 0;
    target_angle = 0;
    pad_4cc = 0;
    accum = 0.0f;
    emit_end_frame = 0.0f;
    walk_dir.x = 0.0f;
    walk_dir.y = 0.0f;
    walk_dir.z = 0.0f;
    set_intangible();
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneRe7Berura::~TObjEneRe7Berura() {
    s32 i;
    destroy_parts();
    for (i = 0; i < 2; i++) {
        if (attack_trails[i] != 0) {
            delete attack_trails[i];
            attack_trails[i] = 0;
        }
    }
    if (punch != 0) {
        punch->queue_destruction();
        punch = 0;
    }
    free_collision_body_parts(this);
}

void TObjEneRe7Berura::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    if (update_status_effects() != 4) {
        update_action_state();
        texture_scroll = texture_scroll + texture_scroll_speed;
        texture_scroll = (u8) texture_scroll;
    }
    update_collision_center();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneRe7Berura::refresh_target() {  }

void TObjEneRe7Berura::run_death_reaction() {
    if (mode != 11) {
        transition_enemy_state(11);
    }
}

void TObjEneRe7Berura::run_hit_reaction() {
    if ((status_flags & 4) || ((s32) (referenceHp - hp) < (s32) ((s16) hpmax / 5))) {
        clear_attack_receipts();
        return;
    }
    if ((s16) mode != 0xA) {
        transition_enemy_state(0xA);
    }
}

void TObjEneRe7Berura::run_miss_reaction() {  }

void TObjEneRe7Berura::update_collision_center() {
    body_center.x = position.x;
    body_center.y = 20.0f + position.y;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}

void TObjEneRe7Berura::update_body_colliders() {
    bodies->offset.y = body_center.y - position.y;
}

void TObjEneRe7Berura::sub_80095328() {  }
#pragma push
#pragma fp_contract on
s32 TObjEneRe7Berura::acquire_target_in_view() {
    Vec v;
    s32 n;
    TObjPlayer *p;
    u16 id;
    s32 i;
    f32 c;
    f32 s;
    f32 limit;
    f32 d;
    f32 best;
    best = 0.0f;
    id = 0xFFFF;
    limit = cos_table_lookup(0xAAA);
    s = sin_table_lookup(rotation_y);
    c = cos_table_lookup(rotation_y);
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p->is_alive() != 0) {
            VecCopy(&v, &p->position);
            subtract_vector(&v, &body_center);
            v.y = 0.0f;
            d = normalize_vector_xz((Vec *)(&v));
            if (d < 400.0f && d > best &&
                s * v.x + c * v.z > limit &&
                csnLookAt(&body_center, &p->body_center) == 0) {
                id = p->get_entity_id();
                best = d;
            }
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(this, id);
        return 1;
    }
    return 0;
}
#pragma pop
s32 TObjEneRe7Berura::is_arm_ready() {
    return !(arm_flags[current_arm] & 2);
}

s32 TObjEneRe7Berura::collect_node_matrices(NJS_OBJECT *obj, s32 idx) {
    Mtx34 m;
    u32 flags;
    do {
        push_matrix();
        compose_motion_node_matrix(obj);
        flags = obj->evalflags;
        if (idx == berura_attack_node_range_start) {
            berura_attack_node_vec_ptr->x = 0.0f;
            berura_attack_node_vec_ptr->y = 0.0f;
            berura_attack_node_vec_ptr->z = 0.0f;
            matrix_mult_vec(NULL, berura_attack_node_vec_ptr, berura_attack_node_vec_ptr);
            berura_attack_node_vec_ptr->y += -4.0f;
            berura_attack_node_vec_ptr->z += 20.0f;
            get_current_matrix(&m);
            push_matrix_from(identity_matrix);
            translate_matrix(0, -berura_attack_node_vec_ptr->x, -berura_attack_node_vec_ptr->y, -berura_attack_node_vec_ptr->z);
            ::concat_matrix(NULL, m);
            get_current_matrix(&m);
            pop_matrix();
            ::copy_matrix(NULL, m);
        }
        if (idx >= berura_attack_node_range_start && idx <= berura_attack_node_range_end) {
            get_current_matrix(TObjEneRe7Berura__node_matrix_cursor++);
        }
        idx++;
        if (!(flags & NJD_EVAL_BREAK)) {
            idx = TObjEneRe7Berura::collect_node_matrices(obj->child, idx);
        }
        pop_matrix();
        obj = obj->sibling;
    } while (obj != NULL);
    return idx;
}

void TObjEneRe7Berura::capture_arm_matrices(NJS_OBJECT *root, TObjEneRe7BeruraPart *e) {
    TObjEneRe7Berura__node_matrix_cursor = e->node_matrices;
    berura_attack_node_range_start = e->first_node;
    berura_attack_node_range_end = e->last_node;
    berura_attack_node_vec_ptr = &e->launch_offset;
    push_matrix_from(identity_matrix);
    collect_node_matrices(root, 0);
    pop_matrix();
}

void TObjEneRe7Berura::draw_node_tree(NJS_OBJECT *obj) {
    u32 flags;
    GC_Mtx *matrix;

    do {
        push_matrix();
        matrix = TObjEneRe7Berura__node_matrix_cursor;
        TObjEneRe7Berura__node_matrix_cursor = matrix + 1;
        ::concat_matrix(NULL, *matrix);
        flags = obj->evalflags;
        if (!(flags & NJD_EVAL_HIDE)) {
            draw_chunk_model(obj->model);
        }
        pop_matrix();
        if (!(flags & NJD_EVAL_BREAK)) {
            draw_node_tree(obj->child);
        }
        obj = obj->sibling;
    } while (obj != NULL);
}

void TObjEneRe7Berura::draw_saved_node_tree(NJS_OBJECT *obj, GC_Mtx *matrices) {
    TObjEneRe7Berura__node_matrix_cursor = matrices;
    draw_node_tree(obj);
}

void TObjEneRe7Berura::draw_arm(s32 arm) {
    TObjEneRe7BeruraPart *part;

    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(TObjEneRe7Berura__shared_resource->models->texlist));
    part = &TObjEneRe7Berura__detached_part_states[arm];
    draw_saved_node_tree(&part->object, part->node_matrices);
}

s32 TObjEneRe7Berura::get_turn_limit() {
    return this->dizzy_level << 0xF;
}

void TObjEneRe7Berura::reset_turn_total() {
    this->turn_limit = get_turn_limit();
    this->turn_total = 0;
}

s32 TObjEneRe7Berura::step_toward_target(s32 angle, s32 max_step) {
    s32 total_pos;
    s32 total_neg;
    s32 diff;
    s32 reached;

    reached = 0;
    diff = angle_diff_s16(this->rotation_y, angle);
    if (diff > max_step) {
        this->rotation_y += max_step;
        total_pos = this->turn_total;
        if (total_pos < 0) {
            this->turn_total = 0;
        } else {
            this->turn_total = total_pos + max_step;
        }
    } else if (diff < -max_step) {
        this->rotation_y -= max_step;
        total_neg = this->turn_total;
        if (total_neg > 0) {
            this->turn_total = 0;
        } else {
            this->turn_total = total_neg - max_step;
        }
    } else {
        this->rotation_y = angle;
        reached = 1;
    }
    return reached;
}

s32 TObjEneRe7Berura::is_over_limit() {
    int over;
    s32 total;
    s32 limit;

    total = this->turn_total;
    over = 0;
    limit = this->turn_limit;
    if ((total >= limit) || (total <= -limit)) {
        over = 1;
    }
    return (u8)over;
}

s32 TObjEneRe7Berura::get_dizzy_duration() {
    return dizzy_level * 0x96;
}

void TObjEneRe7Berura::clear_arm_flying() {
    arm_flags[current_arm] &= ~2;
}

void TObjEneRe7Berura::destroy_parts() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (hand_emitters[i] != 0) {
            hand_emitters[i]->queue_destruction();
            hand_emitters[i] = 0;
        }
    }
}

void TObjEneRe7Berura::reload_stats_from_tables() {
    this->reload_stats_keep_hp_tp(TObjEneRe7Berura__stat_handle_table[TObjEneRe7Berura__base_stat_rows[1]], TObjEneRe7Berura__attack_stat_handles[TObjEneRe7Berura__attack_stat_rows[1]], TObjEneRe7Berura__shared_object_handles[TObjEneRe7Berura__resist_stat_rows[1]]);
}

void TObjEneRe7Berura::reload_base_stats() {
    reload_stats_keep_hp_tp(TObjEneRe7Berura__stat_handle_table[TObjEneRe7Berura__base_stat_rows[0]], TObjEneRe7Berura__attack_stat_handles[TObjEneRe7Berura__attack_stat_rows[0]], TObjEneRe7Berura__shared_object_handles[TObjEneRe7Berura__resist_stat_rows[0]]);
}

void TObjEneRe7Berura::play_band_sound() {
    if ((is_passing_frame(4.0f) != 0) || (is_passing_frame(20.0f) != 0)) {
        play_sound_effect(remap_sound_for_area(0x4003BC1F), &position, 0, 0);
    }
}

s32 TObjEneRe7Berura::check_death_trigger() {
    if (is_confused() != 0) {
        transition_enemy_state((s16)9);
        return 1;
    }
    return 0;
}

void TObjEneRe7Berura::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_message_transition(reason);
        return;
    case 1:
        state_attack(reason);
        return;
    case 3:
        update_emerge_state(reason);
        return;
    case 2:
        update_hidden_state(reason);
        return;
    case 8:
        handle_state(reason);
        return;
    case 4:
        update_walk_state(reason);
        return;
    case 5:
        update_punch_state(reason);
        return;
    case 6:
        update_melee_state(reason);
        return;
    case 7:
        run_flash_warning_state(reason);
        return;
    case 9:
        state_patrol(reason);
        return;
    case 10:
        update_damage_state(reason);
        return;
    case 11:
        update_death_state(reason);
    default:
        return;
    }
}

void TObjEneRe7Berura::handle_message_transition(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        transition_enemy_state((s16)1);
        break;
    }
}

void TObjEneRe7Berura::state_attack(s32 reason) {
    s32 flags;

    switch (reason) {
    case 4:
        requested_action = 0;
        set_intangible();
        flags = status_flags;
        status_flags = flags & ~5;
        status_flags = status_flags | 2;
        this->set_field_378(3);
        body_fade.start_fade_in();
        play_area_se_with_particle(&position);
        reset_turn_total();
        return;
    case 3:
        if (body_fade.advance_toward_max() != 0) {
            transition_enemy_state((s16)3);
        }
        return;
    case 0:
        update_ground_contact();
        update_body_colliders();
        return;
    case 5:
        status_flags &= ~2;
        break;
    }
}

void TObjEneRe7Berura::update_emerge_state(s32 reason) {
    s32 fade_bits;
    s32 fade_bits_2;
    s32 alpha;
    s32 grey;
    switch (reason) {
    case 4:
        requested_action = 0;
        set_intangible();
        status_flags &= ~7;
        set_field_378(4);
        node2_color = 0xFFFFFFU;
        node1_color = 0xFF000000;
        texture_scroll_speed = 0;
        step = 0;
        accum = 0.0f;
        counter = 0;
        break;
    case 3:
        if (((counter & 7) == 7) && (check_death_trigger() == 0)) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        switch (step) {
        case 0:
            if (update_linked_position(400.0f) != 0) {
                step = 1;
                enemy_copy_target_destination();
                update_velocity();
            }
            break;
        case 1:
            fade_bits = counter;
            if (!(fade_bits & 1)) {
                alpha = node2_color >> 0x18U;
                alpha += 0x20;
                if (alpha >= 0xFF) {
                    counter = fade_bits | 1;
                    alpha = 0xFF;
                }
                node2_color = (alpha << 24) | (node2_color & 0xFFFFFF);
            }
            if (!(counter & 2)) {
                accum += 0.5f;
                texture_scroll_speed = floor_to_float(accum);
                if (texture_scroll_speed >= 0xC) {
                    counter = counter | 2;
                    texture_scroll_speed = 0xC;
                }
            }
            fade_bits_2 = counter;
            if (!(fade_bits_2 & 4)) {
                grey = node1_color & 0xFF;
                grey += 0x20;
                if (grey >= 0xFF) {
                    counter = fade_bits_2 | 4;
                    grey = 0xFF;
                }
                node1_color = grey | ((grey << 0x10) | 0xFF000000 | (grey << 8));
            }
            play_persistent_sound(remap_sound_for_area(0x4003C61E), this, &position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x100);
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    case 5:
        node2_color = -1;
        texture_scroll_speed = 0xC;
        clear_intangible();
        break;
    }
}

void TObjEneRe7Berura::update_hidden_state(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 0;
        set_intangible();
        status_flags &= ~6;
        status_flags |= 1;
        set_field_378(2);
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &position);
        VecCopy(&body_center, &position);
        node2_color = -1;
        node1_color = 0xFF000000;
        dizzy_level = 1;
        body_fade.reset_color();
        current_arm = 1;
        reset_turn_total();
        return;
    case 3:
        if (update_linked_position(400.0f) != 0) {
            transition_enemy_state(1);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneRe7Berura::handle_state(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 0;
        set_intangible();
        status_flags &= ~7;
        set_field_378(8);
        step = 0;
        counter = 0;
        return;
    case 3:
        if (check_death_trigger() == 0) {
            if (step == 2) {
                transition_enemy_state(4);
            } else if (step == 3) {
                transition_enemy_state(2);
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        switch (step) {
        case 0:
            if (update_linked_position(400.0f) != 0) {
                enemy_copy_target_destination();
                update_velocity();
                step = 2;
            } else {
                counter = counter + 1;
                if (counter > 0x3C) {
                    counter = 0;
                    step = 1;
                    body_fade.reset_color();
                    status_flags |= 2;
                }
            }
            break;
        case 1:
            if (body_fade.decay_value_toward_floor() != 0) {
                step = 3;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    }
}

void TObjEneRe7Berura::update_walk_state(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        status_flags &= ~7;
        set_field_378(4);
        step = 0;
        target_angle = 0;
        counter = 0;
        accum = 0.0f;
        walk_dir.x = 0.0f;
        walk_dir.y = 0.0f;
        walk_dir.z = 0.0f;
        return;
    case 3:
        if (check_death_trigger() == 0) {
            if (current_target == NULL) {
                transition_enemy_state(8);
            } else if (destination_distance <= 30.0f) {
                transition_enemy_state(6);
            } else if (counter == 3) {
                transition_enemy_state(5);
            } else if (is_over_limit() != 0) {
                transition_enemy_state(7);
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        play_band_sound();
        if (update_linked_position(400.0f) != 0) {
            enemy_copy_target_destination();
            update_velocity();
        }
        switch (counter) {
        case 0:
            if (enemy_has_live_target() != 0) {
                target_angle = (s32) (u16) (s32) (RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
            } else {
                target_angle = rotation_y;
            }
            counter = 1;
        case 1:
            if (step_toward_target(target_angle, 0x100) != 0) {
                counter = 2;
                walk_dir.x = sin_table_lookup(rotation_y);
                walk_dir.z = cos_table_lookup(rotation_y);
                reset_turn_total();
            }
            update_ground_contact();
            break;
        case 2:
            if (TObjEneDD::check_v2_mode() != 0) {
                if (acquire_target_in_view() != 0) {
                    enemy_copy_target_destination();
                    update_velocity();
                    counter = 3;
                } else {
                    if (enemy_has_live_target() != 0) {
                        target_angle = (s32) (u16) (s32) (RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
                    } else {
                        target_angle = rotation_y;
                    }
                    step_toward_target(target_angle, 0x100);
                }
            } else {
                accum += 0.28f;
                if (accum >= 20.0f) {
                    accum = 0.0f;
                    step = step + 1;
                    if ((step >= 2) && (destination_distance > 80.0f) && (is_arm_ready() != 0) && (acquire_target_in_view() != 0)) {
                        step = 0;
                        enemy_copy_target_destination();
                        update_velocity();
                        counter = 3;
                    } else {
                        counter = 0;
                    }
                }
                move_clamped_on_ground(walk_dir.x, walk_dir.z, 0.28f);
            }
            break;
        }
        check_collisions();
        break;
    }
}

void TObjEneRe7Berura::update_punch_state(s32 reason) {
    Vec v;
    TObjEneRe7BeruraPart *t;
    s32 ok;
    switch (reason) {
    case 4:
        clear_intangible();
        status_flags &= ~3;
        status_flags |= 4;
        set_field_378(5);
        t = &TObjEneRe7Berura__detached_part_states[current_arm];
        requested_action = t->action;
        accum = t->launch_frame;
        emit_end_frame = t->emit_end_frame;
        step = 0;
        for (s32 i = 0; i < 2; i++) {
            hand_emitters[i] = 0;
        }
        if (TObjEneDD::check_v2_mode() != 0) {
            TObjEneRe7Berura__animation_definitions[4].speed = 2.0f;
            TObjEneRe7Berura__animation_definitions[3].speed = 2.0f;
        } else {
            TObjEneRe7Berura__animation_definitions[4].speed = 0.8f;
            TObjEneRe7Berura__animation_definitions[3].speed = 0.8f;
        }
        play_sound_effect(remap_sound_for_area(0x4003BC20), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x100);
        break;
    case 3:
        if (step == 3 && check_death_trigger() == 0) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        switch (step) {
        case 0:
            ok = 1;
            for (s32 i = 0; i < 2; i++) {
                if (hand_emitters[i] == 0) {
                    hand_emitters[i] = create_particle_emitter(&body_center, 0xDC);
                    if (hand_emitters[i] != 0) {
                        hand_emitters[i]->enable();
                    } else {
                        for (s32 j = 0; j < i; j++) {
                            hand_emitters[j]->enable();
                        }
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok != 0) {
                if (frame < emit_end_frame && frame >= accum) {
                    for (s32 i = 0; i < 2; i++) {
                        hand_emitters[i]->enable();
                    }
                } else {
                    for (s32 i = 0; i < 2; i++) {
                        hand_emitters[i]->set_position(&hand_positions[i]);
                    }
                }
            }
            if (is_passing_frame(accum) != 0) {
                arm_flags[current_arm] |= 3;
                arm_fade.reset_obstruction_fade();
                VecCopy(&v, &TObjEneRe7Berura__detached_part_states[current_arm].launch_offset);
                rotate_xz_pair_by_angle(&v.x, &v.z, rotation_y);
                vec3_add_to(&v, &position);
                punch->launch(current_arm, &v, &destination);
                step = 1;
                destroy_parts();
                play_sound_effect(remap_sound_for_area(0x4003A321), &position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x100);
            }
            break;
        case 1:
            if (!(arm_flags[current_arm] & 2)) {
                step = 2;
                arm_flags[current_arm] |= 4;
                arm_flags[current_arm] &= ~1;
            }
            break;
        case 2:
            if (arm_fade.advance_toward_max() != 0) {
                arm_flags[current_arm] &= ~4;
                if (current_arm == 0) {
                    current_arm = 1;
                } else {
                    current_arm = 0;
                }
                step = 3;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    case 5:
        arm_fade.reset_color();
        arm_flags[current_arm] &= ~7;
        destroy_parts();
        break;
    }
}

void TObjEneRe7Berura::update_melee_state(s32 reason) {
    Vec trail_points[4];
    s32 i;
    Vec *entry;

    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        status_flags &= ~7;
        set_field_378(6);
        step = 0;
        counter = 0;
        target_angle = 0;
        pad_4cc = get_turn_limit();
        return;
    case 3:
        if (step != 0) {
        case 5:
            return;
        }
        if (check_death_trigger() == 0) {
            if (current_target == NULL) {
                transition_enemy_state(8);
            } else if (destination_distance >= 30.0f) {
                transition_enemy_state(4);
            } else if (is_over_limit() != 0) {
                transition_enemy_state(7);
            }
        }
        break;
    case 0:
        advance_animation();
        switch (step) {
        case 0:
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
                if (step_toward_target((s32) (RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z)), 0x100) != 0) {
                    step = 1;
                    requested_action = 2;
                    reset_turn_total();
                    for (i = 0; i < 2; i++) {
                        attack_trails[i]->clear_segments();
                    }
                }
                play_band_sound();
            }
            break;
        case 1:
            if (is_passing_frame(12.0f) != 0) {
                play_sound_effect(remap_sound_for_area(0x4003AD22), &position, 0, 0);
            }
            if ((is_passing_frame(16.0f) != 0) && (enemy_check_target_valid() != 0)) {
                if (current_target->select_melee_contact_body(this, 1.0f) != 0) {
                    if (current_target->receive_physical_attack(this, 1.0f) > 0.0f) {
                        if (TObjEneDD::check_v2_mode() != 0) {
                            if (random_ratio() <= 0.1f) {
                                TObjEneDD__sub_800BA378(this, current_target);
                            }
                        } else if (random_ratio() <= 0.3333f) {
                            TObjEneDD__sub_800BA378(this, current_target);
                        }
                    }
                    current_target->apply_knockback_from_attacker((u8 *)this, 5.0f);
                }
            }
            entry = belra_trail_buffer->lookup(frame);
            if (entry != NULL) {
                push_matrix();
                set_matrix_identity(NULL);
                post_translate_matrix(&position.x);
                rotate_matrix_y(NULL, rotation_y);
                matrix_mult_vec_array(NULL, entry, trail_points, 4);
                pop_matrix();
                attack_trails[0]->add_segment(&trail_points[0], &trail_points[1]);
                attack_trails[1]->add_segment(&trail_points[2], &trail_points[3]);
            }
            if (get_flag_b4() != 0) {
                step = 2;
                counter = 0;
                requested_action = 0;
            }
            break;
        case 2:
            counter = counter + 1;
            if (counter >= 0x32) {
                step = 0;
                requested_action = 1;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    }
}
#pragma push
#pragma opt_propagation off
void TObjEneRe7Berura::run_flash_warning_state(s32 reason) {
    s32 t;
    s32 v;
    switch (reason) {
    case 4:
        requested_action = 5;
        clear_intangible();
        status_flags &= ~3;
        status_flags |= 4;
        set_field_378(4);
        step = 0;
        counter = get_dizzy_duration();
        texture_scroll_speed = 0;
        target_angle = 0x300;
        break;
    case 3:
        if (step >= counter) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        step = step + 1;
        t = target_angle;
        if (t > 0) {
            target_angle = t - 0xB;
            v = (target_angle > 0x100) ? 0x100 : target_angle;
            if (turn_total > 0) {
                rotation_y += v;
            } else {
                rotation_y -= v;
            }
        }
        if ((step & 0x1F) < 0x10) {
            node1_color = 0xFF303030;
        } else {
            node1_color = -1;
        }
        update_ground_contact();
        check_collisions();
        set_sound_pitch_request(
            play_persistent_sound(remap_sound_for_area(0x4003C61E), this, &position, 0, 0),
            0x400, 0);
        break;
    case 5:
        status_flags &= ~4;
        dizzy_level = dizzy_level + 1;
        node1_color = -1;
        texture_scroll_speed = 0xC;
        reset_turn_total();
        break;
    }
}

#pragma pop
void TObjEneRe7Berura::state_patrol(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 1;
        clear_intangible();
        status_flags = status_flags & ~3;
        status_flags = status_flags | 4;
        set_field_378(9);
        step = 0;
        target_angle = rotation_y + 0x3800;
        break;
    case 3:
        if (rotation_y >= target_angle) {
            transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        if (is_motion_blending() == 0) {
            play_speed = 1.6f;
        }
        rotation_y = rotation_y + 0x280;
        update_ground_contact();
        check_collisions();
        break;
    case 5:
        status_flags = status_flags & ~4;
        break;
    }

}

void TObjEneRe7Berura::update_damage_state(s32 reason) {
    Vec v;
    f32 speed;
    switch (reason) {
    case 4:
        requested_action = 6;
        clear_intangible();
        status_flags &= ~7;
        advance_animation();
        play_sound_effect(remap_sound_for_area(0x4003A826), &position, 0, 0);
        set_active();
        break;
    case 3:
        if (get_flag_b4() != 0) {
            transition_enemy_state(next_mode);
        }
        break;
    case 0:
        advance_animation();
        VecCopy(&v, &velocity);
        speed = normalize_vector_xz(&v);
        move_clamped_on_ground(v.x, v.z, speed);
        velocity.x *= 0.8f;
        velocity.z *= 0.8f;
        break;
    case 5:
        clear_attack_receipts();
        clear_field_388();
        break;
    }
}

void TObjEneRe7Berura::update_death_state(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 7;
        clear_intangible();
        status_flags &= ~7;
        advance_animation();
        refresh_and_send_entity_flags();
        punch->deactivate();
        accum = texture_scroll_speed;
        counter = 0;
        step = 0;
        fn_800D911C(&body_center);
        body_fade.start_fade_out();
        status_flags |= 2;
        play_sound_effect(remap_sound_for_area(0x4003AD25), &position, 0, 0);
        break;
    case 0:
        switch (counter) {
        case 0: {
            advance_animation();
            if (body_fade.decay_value_toward_floor() != 0) {
                counter = 4;
                status_flags |= 1;
                TObjPlayer::apply_effect_variant_b(&position, 0);
                queue_destruction();
            }
        }
            break;
        }
        break;
    case 3:
        break;
    case 5:
        break;
    }
}

void TObjEneRe7Berura::demo_frame_callback(NJS_OBJECT *) {
    switch (re7_berura_demo_state) {
    case 0x2:
        berura_node_saved_render_flags = model_render_flags;
        model_render_flags &= 0xFFFF7FFF;
        break;
    case 0x3:
        model_render_flags = berura_node_saved_render_flags;
        break;
    case 0x4C:
    case 0x50:
        forward_transform_to_view(re7_berura_demo_camera_ptr, re7_berura_demo_camera_ptr);
        re7_berura_demo_camera_ptr++;
        break;
    case 0x21:
        if (berura_demo_flag != 0) {
            TObjEneRe7Berura__demo_target->set_flags_and_apply_damage_color();
        }
        break;
    case 0x38:
        if (re7_berura_demo_flag != 0) {
            TObjEneRe7Berura__demo_target->set_flags_and_apply_damage_color();
        }
        break;
    case 0x32:
        if (berura_demo_flag != 0) {
            TObjEneRe7Berura__demo_target->clear_flag_and_notify();
        }
        break;
    case 0x49:
        if (re7_berura_demo_flag != 0) {
            TObjEneRe7Berura__demo_target->clear_flag_and_notify();
        }
        break;
    }
    re7_berura_demo_state += 1;
}

void TObjEneRe7Berura::advance_state(NJS_OBJECT *) {
    switch (re7_berura_demo_state) {
    case 25:
        berura_node_saved_render_flags = model_render_flags;
        model_render_flags &= 0xFFFF7FFF;
        break;
    case 26:
        model_render_flags = berura_node_saved_render_flags;
        break;
    }
    re7_berura_demo_state += 1;
}

void TObjEneRe7Berura::render() {
    RenderFadeState *fade;
    s32 visible;
    s32 cam;
    s32 i;
    s32 f1;
    s32 f2;
    s32 l3;
    s32 l4;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (status_flags & 1) {
        visible = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        visible = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        visible = 1;
    } else {
        visible = 0;
    }
    if (visible != 0) {
        if (mode != 0xB) {
            Vec v = berura_shadow_scale;
            draw_ground_shadow(&v, 0);
        }
        update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        model_render_flags &= ~0x810;
        TObjPlayer::toggle_particle_effect();
        for (i = 0; i < 2; i++) {
            if (arm_flags[i] & 1) {
                TObjEneRe7Berura__detached_part_states[i].hide();
            }
        }
        *berura_node_matrix_ptr_a = node2_color;
        berura_node_matrix_ptr_b[0] = node1_color;
        berura_node_matrix_ptr_b[1] = node1_color >> 16;
        belra_uv_animation_buffer->scroll_uvs(texture_scroll, 0);
        fade = &camera_fades[cam];
        fade->update();
        cam = fade->updateFromCamera(&body_center.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (mode == 5) {
            re7_berura_demo_state = 0;
            berura_node_saved_render_flags = 0;
            re7_berura_demo_camera_ptr = hand_positions;
            hand_positions[0].x = 15.0f;
            hand_positions[0].y = 0.0f;
            hand_positions[0].z = 10.0f;
            hand_positions[1].x = 15.0f;
            hand_positions[1].y = 0.0f;
            hand_positions[1].z = -10.0f;
            berura_demo_flag = (arm_flags[0] >> 2) & 1;
            re7_berura_demo_flag = (arm_flags[1] >> 2) & 1;
            TObjEneRe7Berura__demo_target = &arm_fade;
            if (cam != 0) {
                re7_berura_demo_flag = 0;
                berura_demo_flag = 0;
                fade->set_flags_and_apply_damage_color();
                f1 = 1;
                if (defer_render() != 0) {
                    f1 = 0;
                }
                if (f1 != 0) {
                    set_chunk_model_node_callback(TObjEneRe7Berura::demo_frame_callback);
                    draw();
                    set_chunk_model_node_callback(0);
                }
                fade->clear_flag_and_notify();
            } else {
                set_chunk_model_node_callback(TObjEneRe7Berura::demo_frame_callback);
                if (visible == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                set_chunk_model_node_callback(0);
            }
        } else {
            re7_berura_demo_state = 0;
            berura_node_saved_render_flags = 0;
            if (status_flags & 2) {
                if (body_fade.has_visible_opacity() != 0) {
                    body_fade.set_flags_and_apply_damage_color();
                    f2 = 1;
                    if (defer_render() != 0) {
                        f2 = 0;
                    }
                    if (f2 != 0) {
                        set_chunk_model_node_callback(TObjEneRe7Berura::advance_state);
                        draw();
                        set_chunk_model_node_callback(0);
                    }
                    body_fade.clear_flag_and_notify();
                }
            } else if (cam != 0) {
                fade->set_flags_and_apply_damage_color();
                set_chunk_model_node_callback(TObjEneRe7Berura::advance_state);
                draw();
                set_chunk_model_node_callback(0);
                fade->clear_flag_and_notify();
            } else if (visible == 1) {
                draw();
            } else {
                draw_motion_model();
            }
        }
        pop_matrix();
        update_primary_light();
        for (l3 = 0; l3 < 2; l3++) {
            if (arm_flags[l3] & 1) {
                TObjEneRe7Berura__detached_part_states[l3].show();
            }
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        return;
    }
    if (mode == 5) {
        for (l4 = 0; l4 < 2; l4++) {
            VecCopy(&hand_positions[l4], &position);
        }
    }
}

void TObjEneRe7Berura::run_demo_task() { if (get_target_info() != 0) { sub_80095328(); } }

void TObjEneRe7Berura::render_demo() {
    s32 idx;
    AnimationMotion *mot;
    f32 frame;

    get_target_info();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        if (mode != 0xB) {
            Vec v = { 2.0f, 1.0f, 2.0f };
            draw_ground_shadow(&v, 0);
        }
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        idx = (s32)parameters[0];
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 8) {
            idx = 7;
        }
        mot = motion_list[action_table[idx].motion].motion;
        frame = parameters[1];
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (mot->frameCount - 1)) {
            frame = (f32)mot->frameCount;
        }
        set_motion_packed_rotation();
        draw_model_motion(model, mot, frame);
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
