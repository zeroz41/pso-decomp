#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
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
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/math/FloatRounding.h"
#include "pso/effect/TUnk_80494968.h"
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

#pragma defer_codegen on
extern "C" {
s32 rotate_matrix_y(int, int);
void post_translate_matrix(void *);
void draw_model_motion(void *model, void *motion, f32 frame);
void TObjEneRe7Berura__sub_80093470(TObjEneRe7Berura *self, s32 mode);
void TObjEneRe7BeruraPunch__sub_800962F4(TObjEneRe7BeruraPunch *p);
void TObjPlayer__sub_800A04F0(void *);
void fn_80095DD0(TObjEneRe7BeruraPart *);
void fn_80095DF4(TObjEneRe7BeruraPart *);
s32 scroll_strip_uvs(s32, int, int);
extern const Vec lbl_80439EC4;
extern TObjEneRe7BeruraPart TObjEneRe7Berura__detached_part_states[];
u8 * TObjEneRe7Berura__stat_handle_table[1];
u8 * TObjEneRe7Berura__shared_object_handles[1];
void * TObjEneRe7Berura__handler_table_a[1];
BmlResource * TObjEneRe7Berura__shared_resource;
s32 re7_berura_demo_state;
s32 lbl_805D4F6C;
Vec * re7_berura_demo_camera_ptr;
s32 berura_demo_flag;
s32 re7_berura_demo_flag;
TUnk_80490470 * TObjEneRe7Berura__demo_target;
u8 * re7_berura_static_buffer;
s32 * berura_node_matrix_ptr_a;
s16 * berura_node_matrix_ptr_b;
uaddr belra_uv_animation_buffer;
s32 berura_attack_node_range_start;
s32 berura_attack_node_range_end;
u8 * TObjEneRe7Berura__node_matrix_cursor;
Vec * berura_attack_node_vec_ptr;
SampledMotionPoints * belra_trail_buffer;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
f32 atan2_float(f32 y, f32 x);
s32 TObjEneRe7Berura__sub_8009518C(TObjEneRe7Berura *);
void TObjEneRe7Berura__sub_800940E8(TObjEneRe7Berura *self, s32 reason);
s32 matrix_mult_vec_array(int, int, void *, int);
void set_matrix_identity(u8 *arg0);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
void TObjEneRe7Berura__sub_8009472C(TObjEneRe7Berura *self, s32 reason);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 angle);
s32 launch__21TObjEneRe7BeruraPunchFll(TObjEneRe7BeruraPunch *, s32, Vec *, f32 *);
s32 vec3_add_to(void *, void *);
extern TObjMotionAction TObjEneRe7Berura__animation_definitions[];
void TObjEneRe7Berura__sub_80093C80(TObjEneRe7Berura *self, s32 reason);
void TObjEneRe7Berura__sub_80094624(TObjEneRe7Berura *self, s32 reason);
s32 TObjEneRe7Berura__sub_80094DB4(TObjEneRe7Berura *);
}


struct Mtx_8009503C { f32 m[3][4]; };
extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *);
void TObjEneRe7Berura__sub_80093888(TObjEneRe7Berura *actor, s32 reason);


void TObjEneRe7Berura__sub_80094C68(TObjEneRe7Berura *self);
void TObjEneRe7Berura__sub_80094D98(TObjEneRe7Berura *self);
void draw_node_tree__16TObjEneRe7BeruraFPv(NJS_OBJECT *obj);


s32 TObjPlayer__sub_800A0554(void *);




s32 angle_diff_s16(s32);
void free_collision_body_parts(void *);
}


void compose_motion_node_matrix(void *arg0);
extern "C" {
s32 matrix_mult_vec(int, void *, void *);
void copy_matrix__10TObjPlayerFUlUl(int, void *);
s32 concat_matrix__10TObjPlayerFUlUl(s32, void *);
}

void *destroy_buffer_pair(void *arg0, s16 arg1);
void get_current_matrix(void *);
void draw_chunk_model(void *arg0);
extern u8 *TObjEneRe7Berura__data_805007D4[];


extern const NpcAnimationBinding ene_re7_berura_attack_def;
extern s32 identity_matrix[];
const s32 lbl_805D9718[1] = {14};
const s32 lbl_805D971C[1] = {14};
const s32 lbl_805D9720[1] = {14};
extern const s32 lbl_80439DA0[];
extern const s32 TObjEneRe7Berura__data_80439DA8[];
extern const s32 TObjEneRe7Berura__data_80439DB0[];
extern const s32 TObjEneRe7Berura__data_80439DB8[];
extern TObject *tl_04;


TObjEneRe7BeruraMovementParameters berura_init_params = {
    225.0f, 0.0f, 0x600, {0, 0, 0, 0},
};

CollisionBody lbl_8048F66C = {
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

const NpcAnimationBinding ene_re7_berura_attack_def = { NULL, reinterpret_cast<TObjMotionAction *>(TObjEneRe7Berura__animation_definitions), 0, 1, 9 };

const Vec lbl_80439EC4 = {2.0f, 1.0f, 2.0f};

f32 lbl_805007C8[3];
u8 *TObjEneRe7Berura__data_805007D4[2];
TObjEneRe7BeruraPart TObjEneRe7Berura__detached_part_states[2];

void fn_80095DF4(TObjEneRe7BeruraPart *part) {
    part->first_object->evalflags |= NJD_EVAL_HIDE;
    part->last_object->evalflags |= NJD_EVAL_HIDE;
}

void fn_80095DD0(TObjEneRe7BeruraPart *part) {
    part->first_object->evalflags &= ~NJD_EVAL_HIDE;
    part->last_object->evalflags &= ~NJD_EVAL_HIDE;
}

void TObjEneRe7Berura::load_static_resources() {
    s32 pair[4];
    Vec vecs[4];
    BmlResource *r;
    uaddr m;
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
    lbl_805D4F6C = 0;
    re7_berura_demo_camera_ptr = 0;
    berura_demo_flag = 0;
    re7_berura_demo_flag = 0;
    TObjEneRe7Berura__demo_target = 0;
    m = (uaddr)r->models->model;
    buf = (u8 *)mem_alloc(0x660);
    re7_berura_static_buffer = buf;
    TObjEneRe7Berura__detached_part_states[0].node_matrices = buf;
    TObjEneRe7Berura__detached_part_states[1].node_matrices = buf + 0x330;
    TObjEneRe7Berura__detached_part_states[0].first_node = 0x21;
    TObjEneRe7Berura__detached_part_states[0].last_node = 0x31;
    TObjEneRe7Berura__detached_part_states[1].first_node = 0x38;
    TObjEneRe7Berura__detached_part_states[1].last_node = 0x48;
    TObjEneRe7Berura__detached_part_states[0].action = 3;
    TObjEneRe7Berura__detached_part_states[0].m_10 = 20.0f;
    TObjEneRe7Berura__detached_part_states[0].m_14 = 30.0f;
    TObjEneRe7Berura__detached_part_states[1].action = 4;
    TObjEneRe7Berura__detached_part_states[1].m_10 = 19.0f;
    TObjEneRe7Berura__detached_part_states[1].m_14 = 29.0f;
    for (i = 0; i < 2; i++) {
        TObjEneRe7BeruraPart *e = &TObjEneRe7Berura__detached_part_states[i];
        AnimationMotion *ent = TObjEneRe7Berura__shared_resource->motions[TObjEneRe7Berura__animation_definitions[e->action].motion].motion;
        set_motion_packed_rotation();
        bind_motion_context((NJS_MOTION *)ent, e->m_14);
        TObjEneRe7Berura::apply_attack_params((NJS_OBJECT *)m, e);
        clear_motion_packed_rotation();
        e->first_object = (NJS_OBJECT *)find_model_node(m, e->first_node);
        e->last_object = (NJS_OBJECT *)find_model_node(m, e->last_node);
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
    berura_node_matrix_ptr_a = (s32 *)(((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(m, 2))->model)->polygon_list + 4);
    berura_node_matrix_ptr_b = ((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(m, 1))->model)->polygon_list + 4;
    p = ::operator new(0x14);
    if (p != NULL) {
        p = ((TLobby *)p)->alloc_tables((saddr)TObjEneRe7Berura__shared_resource->models->model, 2);
    }
    belra_uv_animation_buffer = (uaddr)p;
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
        TObjEneRe7Berura__stat_handle_table[i] = (u8 *)TLobby::register_boss(lbl_805D9718[i]);
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneRe7Berura__data_805007D4[j] = (u8 *)TLobby::dispatch_shared_handler_b(lbl_80439DA0[j]);
    }
    for (i = 0; i < 1; i++) {
        TObjEneRe7Berura__shared_object_handles[i] = (u8 *)TLobby::register_object(lbl_805D971C[i]);
    }
    for (i = 0; i < 1; i++) {
        TObjEneRe7Berura__handler_table_a[i] = TLobby::dispatch_shared_handler_a(lbl_805D9720[i]);
    }
    {
        NpcAnimationBinding atk = ene_re7_berura_attack_def;
        atk.motions = reinterpret_cast<BmlMotionEntry *>(TObjEneRe7Berura__shared_resource->motions);
        NpcModelRegistry::register_animated_chunk(0x15, reinterpret_cast<void *>(TObjEneRe7Berura__shared_resource->models->model), reinterpret_cast<void *>(TObjEneRe7Berura__shared_resource->models->m_c), &atk, 8.0f, 0.0f);
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
    if ((u32) belra_uv_animation_buffer != 0U) {
        destroy_buffer_pair((void *)belra_uv_animation_buffer, 1);
        belra_uv_animation_buffer = 0U;
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
    texlist = (saddr)TObjEneRe7Berura__shared_resource->models->m_c;
    init_model(&lbl_8048F66C, 1);
    set_field_d8((saddr)TObjEneRe7Berura__animation_definitions);
    set_field_dc((saddr)TObjEneRe7Berura__shared_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp(TObjEneRe7Berura__stat_handle_table[TObjEneRe7Berura__data_80439DA8[0]],
        TObjEneRe7Berura__data_805007D4[TObjEneRe7Berura__data_80439DB0[0]],
        TObjEneRe7Berura__shared_object_handles[TObjEneRe7Berura__data_80439DB8[0]]);
    set_state_8();
    movementParameters = &berura_init_params;
    initialize_enemy_state(0x25);
    wall_reach = 10.0f;
    enemy_init_acquire_period(0x3C);
    enemy_init_validate_period(0x3C);
    m_3c0 = 0;
    m_3c4 = -1;
    m_3c8 = 0xFF000000;
    m_3cc = 0;
    m_3d0 = 0;
    m_3d4 = 1;
    m_3d8.reset_color();
    m_3f4 = 1;
    m_3f8 = (TObjEneRe7BeruraPunch *)spawn_punch(this);
    m_3fc.reset_color();
    if (TObjEneDD::check_v2_mode() != 0) {
        m_3fc.set_rate_from_divisor(0xA);
    }
    for (i = 0; i < 2; i++) {
        m_418[i] = 0;
        VecCopy__FP3VecPC3Vec(&m_420[i], &position);
        m_438[i] = 0;
    }
    m_440[0] = TUnk_80494968::create(0xFF00FF00, 0xA0703030);
    m_440[1] = TUnk_80494968::create(0xFF00FF00, 0xA0703030);
    for (j = 0; j < 4; j++) {
        m_448[j].activate_and_dispatch();
    }
    m_4b8 = 0;
    m_4bc = 0;
    m_4c0 = 0;
    m_4c4 = 0;
    m_4c8 = 0;
    m_4cc = 0;
    m_4d0 = 0.0f;
    m_4d4 = 0.0f;
    m_4d8 = 0.0f;
    m_4dc = 0.0f;
    m_4e0 = 0.0f;
    set_intangible();
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneRe7Berura::~TObjEneRe7Berura() {
    s32 i;
    destroy_parts();
    for (i = 0; i < 2; i++) {
        if (m_440[i] != 0) {
            delete m_440[i];
            m_440[i] = 0;
        }
    }
    if (m_3f8 != 0) {
        m_3f8->queue_destruction();
        m_3f8 = 0;
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
        m_3d0 = m_3d0 + m_3cc;
        m_3d0 = (u8) m_3d0;
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
    if ((m_3c0 & 4) || ((s32) (referenceHp - hp) < (s32) ((s16) hpmax / 5))) {
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
    VecCopy__FP3VecPC3Vec(&center, &body_center);
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
            VecCopy__FP3VecPC3Vec(&v, &p->position);
            subtract_vector(&v, &body_center);
            v.y = 0.0f;
            d = normalize_vector_xz((Vec *)(&v));
            if (d < 400.0f && d > best &&
                s * v.x + c * v.z > limit &&
                csnLookAt(&body_center, &p->body_center) == 0) {
                id = get_entity_id(p);
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
s32 TObjEneRe7Berura__sub_8009518C(TObjEneRe7Berura *self) {
    return !(self->m_418[self->m_3f4] & 2);
}

s32 TObjEneRe7Berura::collect_node_matrices(void *obj, int idx) {
    Mtx_8009503C m;
    u32 flags;
    do {
        push_matrix();
        compose_motion_node_matrix(obj);
        flags = ((NJS_OBJECT *)obj)->evalflags;
        if (idx == berura_attack_node_range_start) {
            berura_attack_node_vec_ptr->x = 0.0f;
            berura_attack_node_vec_ptr->y = 0.0f;
            berura_attack_node_vec_ptr->z = 0.0f;
            matrix_mult_vec(0, berura_attack_node_vec_ptr, berura_attack_node_vec_ptr);
            berura_attack_node_vec_ptr->y += -4.0f;
            berura_attack_node_vec_ptr->z += 20.0f;
            get_current_matrix(&m);
            push_matrix_from(identity_matrix);
            translate_matrix(0, -berura_attack_node_vec_ptr->x, -berura_attack_node_vec_ptr->y, -berura_attack_node_vec_ptr->z);
            concat_matrix__10TObjPlayerFUlUl(0, &m);
            get_current_matrix(&m);
            pop_matrix();
            copy_matrix__10TObjPlayerFUlUl(0, &m);
        }
        if (idx >= berura_attack_node_range_start && idx <= berura_attack_node_range_end) {
            u8 *p = TObjEneRe7Berura__node_matrix_cursor;
            TObjEneRe7Berura__node_matrix_cursor = p + sizeof(Mtx_8009503C);
            get_current_matrix(p);
        }
        idx++;
        if (!(flags & NJD_EVAL_BREAK)) {
            idx = TObjEneRe7Berura::collect_node_matrices(((NJS_OBJECT *)obj)->child, idx);
        }
        pop_matrix();
        obj = ((NJS_OBJECT *)obj)->sibling;
    } while (obj != NULL);
    return idx;
}

void TObjEneRe7Berura::apply_attack_params(NJS_OBJECT *root, void *part) {
    TObjEneRe7BeruraPart *e = (TObjEneRe7BeruraPart *)part;
    TObjEneRe7Berura__node_matrix_cursor = e->node_matrices;
    berura_attack_node_range_start = e->first_node;
    berura_attack_node_range_end = e->last_node;
    berura_attack_node_vec_ptr = &e->m_58;
    push_matrix_from(identity_matrix);
    collect_node_matrices(root, 0);
    pop_matrix();
}

void draw_node_tree__16TObjEneRe7BeruraFPv(NJS_OBJECT *obj) {
    u32 flags;
    u8 *matrix;

    do {
        push_matrix();
        matrix = TObjEneRe7Berura__node_matrix_cursor;
        TObjEneRe7Berura__node_matrix_cursor = matrix + sizeof(Mtx_8009503C);
        concat_matrix__10TObjPlayerFUlUl(0, matrix);
        flags = obj->evalflags;
        if (!(flags & NJD_EVAL_HIDE)) {
            draw_chunk_model(obj->model);
        }
        pop_matrix();
        if (!(flags & NJD_EVAL_BREAK)) {
            draw_node_tree__16TObjEneRe7BeruraFPv(obj->child);
        }
        obj = obj->sibling;
    } while (obj != NULL);
}

void TObjEneRe7Berura::set_data_and_draw_node_tree(u8 *matrices) {
    TObjEneRe7Berura__node_matrix_cursor = matrices;
    draw_node_tree__16TObjEneRe7BeruraFPv(((NJS_OBJECT *)this));
}

void TObjEneRe7Berura::init_part(s32 arg0) {
    TObjEneRe7BeruraPart *part;

    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(TObjEneRe7Berura__shared_resource->models->m_c));
    part = &TObjEneRe7Berura__detached_part_states[arg0];
    ((TObjEneRe7Berura *)(&part->object))->set_data_and_draw_node_tree(part->node_matrices);
}

s32 TObjEneRe7Berura::get_field_3D4_shifted() {
    return this->m_3d4 << 0xF;
}

void TObjEneRe7Berura::init_fields4B8() {
    this->m_4b8 = get_field_3D4_shifted();
    this->m_4bc = 0;
}

s32 TObjEneRe7Berura::step_toward_target(s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3;
    s32 var_r31;

    var_r31 = 0;
    temp_r3 = angle_diff_s16(this->rotation_y);
    if (temp_r3 > arg2) {
        this->rotation_y = (s32) (this->rotation_y + arg2);
        temp_r0 = this->m_4bc;
        if (temp_r0 < 0) {
            this->m_4bc = 0;
        } else {
            this->m_4bc = (s32) (temp_r0 + arg2);
        }
    } else if (temp_r3 < (s32) -arg2) {
        this->rotation_y = (s32) (this->rotation_y - arg2);
        temp_r0_2 = this->m_4bc;
        if (temp_r0_2 > 0) {
            this->m_4bc = 0;
        } else {
            this->m_4bc = (s32) (temp_r0_2 - arg2);
        }
    } else {
        this->rotation_y = arg1;
        var_r31 = 1;
    }
    return var_r31;
}

s32 TObjEneRe7Berura::is_over_limit() {
    int var_r4;
    s32 temp_r5;
    s32 temp_r0;

    temp_r5 = this->m_4bc;
    var_r4 = 0;
    temp_r0 = this->m_4b8;
    if ((temp_r5 >= temp_r0) || (temp_r5 <= (s32) -temp_r0)) {
        var_r4 = 1;
    }
    return (u8)((u8) var_r4);
}

s32 TObjEneRe7Berura__sub_80094DB4(TObjEneRe7Berura *self) {
    return self->m_3d4 * 0x96;
}

void TObjEneRe7Berura__sub_80094D98(TObjEneRe7Berura *self) {
    self->m_418[self->m_3f4] &= ~2;
}

void TObjEneRe7Berura::destroy_parts() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (m_438[i] != 0) {
            m_438[i]->queue_destruction();
            m_438[i] = 0;
        }
    }
}

void TObjEneRe7Berura::reload_stats_from_tables() {
    this->reload_stats_keep_hp_tp((u8 *)(((void * *)TObjEneRe7Berura__stat_handle_table)[TObjEneRe7Berura__data_80439DA8[1]]), (u8 *)(((void * *)TObjEneRe7Berura__data_805007D4)[TObjEneRe7Berura__data_80439DB0[1]]), (u8 *)(((void * *)TObjEneRe7Berura__shared_object_handles)[TObjEneRe7Berura__data_80439DB8[1]]));
}

void TObjEneRe7Berura__sub_80094C68(TObjEneRe7Berura *self) {
    ((TObjEneDD *)self)->reload_stats_keep_hp_tp((u8 *)(((void * *)TObjEneRe7Berura__stat_handle_table)[TObjEneRe7Berura__data_80439DA8[0]]), (u8 *)(((void * *)TObjEneRe7Berura__data_805007D4)[TObjEneRe7Berura__data_80439DB0[0]]), (u8 *)(((void * *)TObjEneRe7Berura__shared_object_handles)[TObjEneRe7Berura__data_80439DB8[0]]));
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
        TObjEneRe7Berura__sub_8009472C(this, reason);
        return;
    case 2:
        TObjEneRe7Berura__sub_80094624(this, reason);
        return;
    case 8:
        handle_state(reason);
        return;
    case 4:
        TObjEneRe7Berura__sub_800940E8(this, reason);
        return;
    case 5:
        TObjEneRe7Berura__sub_80093C80(this, reason);
        return;
    case 6:
        TObjEneRe7Berura__sub_80093888(this, reason);
        return;
    case 7:
        run_flash_warning_state(reason);
        return;
    case 9:
        TObjEneRe7Berura::state_patrol(this, reason);
        return;
    case 10:
        TObjEneRe7Berura__sub_80093470(this, reason);
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

void TObjEneRe7Berura::state_attack(s32 arg1) {
    s32 temp_r5;

    switch (arg1) {
    case 4:
        requested_action = 0;
        set_intangible();
        temp_r5 = m_3c0;
        m_3c0 = temp_r5 & ~5;
        m_3c0 = m_3c0 | 2;
        this->set_field_378(3);
        TObjPlayer__sub_800A0554(&m_3d8);
        play_area_se_with_particle(&position);
        init_fields4B8();
        return;
    case 3:
        if (m_3d8.advance_toward_max() != 0) {
            transition_enemy_state((s16)3);
        }
        return;
    case 0:
        update_ground_contact();
        update_body_colliders();
        return;
    case 5:
        m_3c0 &= ~2;
        break;
    }
}

void TObjEneRe7Berura__sub_8009472C(TObjEneRe7Berura *self, s32 reason) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r4;
    s32 var_r4_2;
    switch (reason) {
    case 4:
        self->requested_action = 0;
        self->set_intangible();
        self->m_3c0 &= ~7;
        self->set_field_378(4);
        self->m_3c4 = 0xFFFFFFU;
        self->m_3c8 = 0xFF000000;
        self->m_3cc = 0;
        self->m_4c0 = 0;
        self->m_4d0 = 0.0f;
        self->m_4c4 = 0;
        break;
    case 3:
        if (((self->m_4c4 & 7) == 7) && (self->check_death_trigger() == 0)) {
            self->transition_enemy_state(4);
        }
        break;
    case 0:
        switch (self->m_4c0) {
        case 0:
            if (self->update_linked_position(400.0f) != 0) {
                self->m_4c0 = 1;
                self->enemy_copy_target_destination();
                self->update_velocity();
            }
            break;
        case 1:
            temp_r3 = self->m_4c4;
            if (!(temp_r3 & 1)) {
                var_r4 = self->m_3c4 >> 0x18U;
                var_r4 += 0x20;
                if (var_r4 >= 0xFF) {
                    self->m_4c4 = temp_r3 | 1;
                    var_r4 = 0xFF;
                }
                self->m_3c4 = (var_r4 << 24) | (self->m_3c4 & 0xFFFFFF);
            }
            if (!(self->m_4c4 & 2)) {
                self->m_4d0 += 0.5f;
                self->m_3cc = floor_to_float(self->m_4d0);
                if (self->m_3cc >= 0xC) {
                    self->m_4c4 = self->m_4c4 | 2;
                    self->m_3cc = 0xC;
                }
            }
            temp_r3_2 = self->m_4c4;
            if (!(temp_r3_2 & 4)) {
                var_r4_2 = self->m_3c8 & 0xFF;
                var_r4_2 += 0x20;
                if (var_r4_2 >= 0xFF) {
                    self->m_4c4 = temp_r3_2 | 4;
                    var_r4_2 = 0xFF;
                }
                self->m_3c8 = var_r4_2 | ((var_r4_2 << 0x10) | 0xFF000000 | (var_r4_2 << 8));
            }
            play_persistent_sound(self->remap_sound_for_area(0x4003C61E), (saddr)self, (uaddr)&self->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x100);
            break;
        }
        self->update_ground_contact();
        self->check_collisions();
        break;
    case 5:
        self->m_3c4 = -1;
        self->m_3cc = 0xC;
        self->clear_intangible();
        break;
    }
}

void TObjEneRe7Berura__sub_80094624(TObjEneRe7Berura *self, s32 reason) {
    switch (reason) {
    case 4:
        self->requested_action = 0;
        self->set_intangible();
        self->m_3c0 &= ~6;
        self->m_3c0 |= 1;
        self->set_field_378(2);
        VecCopy(&self->position, &self->home_position);
        VecCopy(&self->prev_position, &self->position);
        VecCopy(&self->body_center, &self->position);
        self->m_3c4 = -1;
        self->m_3c8 = 0xFF000000;
        self->m_3d4 = 1;
        self->m_3d8.reset_color();
        self->m_3f4 = 1;
        self->init_fields4B8();
        return;
    case 3:
        if (self->update_linked_position(400.0f) != 0) {
            self->transition_enemy_state(1);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneRe7Berura::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0;
        set_intangible();
        m_3c0 &= ~7;
        set_field_378(8);
        m_4c0 = 0;
        m_4c4 = 0;
        return;
    case 3:
        if (check_death_trigger() == 0) {
            if (m_4c0 == 2) {
                transition_enemy_state(4);
            } else if (m_4c0 == 3) {
                transition_enemy_state(2);
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        switch (m_4c0) {
        case 0:
            if (update_linked_position(400.0f) != 0) {
                enemy_copy_target_destination();
                update_velocity();
                m_4c0 = 2;
            } else {
                m_4c4 = m_4c4 + 1;
                if (m_4c4 > 0x3C) {
                    m_4c4 = 0;
                    m_4c0 = 1;
                    m_3d8.reset_color();
                    m_3c0 |= 2;
                }
            }
            break;
        case 1:
            if (m_3d8.decay_value_toward_floor() != 0) {
                m_4c0 = 3;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    }
}

void TObjEneRe7Berura__sub_800940E8(TObjEneRe7Berura *self, s32 reason) {
    switch (reason) {
    case 4:
        self->requested_action = 1;
        self->clear_intangible();
        self->m_3c0 &= ~7;
        self->set_field_378(4);
        self->m_4c0 = 0;
        self->m_4c8 = 0;
        self->m_4c4 = 0;
        self->m_4d0 = 0.0f;
        self->m_4d8 = 0.0f;
        self->m_4dc = 0.0f;
        self->m_4e0 = 0.0f;
        return;
    case 3:
        if (self->check_death_trigger() == 0) {
            if (self->current_target == NULL) {
                self->transition_enemy_state(8);
            } else if (self->destination_distance <= 30.0f) {
                self->transition_enemy_state(6);
            } else if (self->m_4c4 == 3) {
                self->transition_enemy_state(5);
            } else if (((TObjEneRe7Berura *)self)->is_over_limit() != 0) {
                self->transition_enemy_state(7);
            }
        }
        break;
    case 5:
        break;
    case 0:
        self->advance_animation();
        self->play_band_sound();
        if (self->update_linked_position(400.0f) != 0) {
            self->enemy_copy_target_destination();
            self->update_velocity();
        }
        switch (self->m_4c4) {
        case 0:
            if (self->enemy_has_live_target() != 0) {
                self->m_4c8 = (s32) (u16) (s32) (RADIANS_TO_ANGLE * atan2_float(self->destination_direction.x, self->destination_direction.z));
            } else {
                self->m_4c8 = self->rotation_y;
            }
            self->m_4c4 = 1;
        case 1:
            if (self->step_toward_target(self->m_4c8, 0x100) != 0) {
                self->m_4c4 = 2;
                self->m_4d8 = sin_table_lookup(self->rotation_y);
                self->m_4e0 = cos_table_lookup(self->rotation_y);
                self->init_fields4B8();
            }
            self->update_ground_contact();
            break;
        case 2:
            if (TObjEneDD::check_v2_mode() != 0) {
                if (self->acquire_target_in_view() != 0) {
                    self->enemy_copy_target_destination();
                    self->update_velocity();
                    self->m_4c4 = 3;
                } else {
                    if (self->enemy_has_live_target() != 0) {
                        self->m_4c8 = (s32) (u16) (s32) (RADIANS_TO_ANGLE * atan2_float(self->destination_direction.x, self->destination_direction.z));
                    } else {
                        self->m_4c8 = self->rotation_y;
                    }
                    self->step_toward_target(self->m_4c8, 0x100);
                }
            } else {
                self->m_4d0 += 0.28f;
                if (self->m_4d0 >= 20.0f) {
                    self->m_4d0 = 0.0f;
                    self->m_4c0 = self->m_4c0 + 1;
                    if ((self->m_4c0 >= 2) && (self->destination_distance > 80.0f) && (TObjEneRe7Berura__sub_8009518C(self) != 0) && (self->acquire_target_in_view() != 0)) {
                        self->m_4c0 = 0;
                        self->enemy_copy_target_destination();
                        self->update_velocity();
                        self->m_4c4 = 3;
                    } else {
                        self->m_4c4 = 0;
                    }
                }
                self->move_clamped_on_ground(self->m_4d8, self->m_4e0, 0.28f);
            }
            break;
        }
        self->check_collisions();
        break;
    }
}

void TObjEneRe7Berura__sub_80093C80(TObjEneRe7Berura *self, s32 reason) {
    Vec v;
    TObjEneRe7BeruraPart *t;
    s32 ok;
    switch (reason) {
    case 4:
        self->clear_intangible();
        self->m_3c0 &= ~3;
        self->m_3c0 |= 4;
        self->set_field_378(5);
        t = &TObjEneRe7Berura__detached_part_states[self->m_3f4];
        self->requested_action = t->action;
        self->m_4d0 = t->m_14;
        self->m_4d4 = t->m_10;
        self->m_4c0 = 0;
        for (s32 i = 0; i < 2; i++) {
            self->m_438[i] = 0;
        }
        if (TObjEneDD::check_v2_mode() != 0) {
            TObjEneRe7Berura__animation_definitions[4].speed = 2.0f;
            TObjEneRe7Berura__animation_definitions[3].speed = 2.0f;
        } else {
            TObjEneRe7Berura__animation_definitions[4].speed = 0.8f;
            TObjEneRe7Berura__animation_definitions[3].speed = 0.8f;
        }
        play_sound_effect(self->remap_sound_for_area(0x4003BC20), &self->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x100);
        break;
    case 3:
        if (self->m_4c0 == 3 && self->check_death_trigger() == 0) {
            self->transition_enemy_state(4);
        }
        break;
    case 0:
        self->advance_animation();
        switch (self->m_4c0) {
        case 0:
            ok = 1;
            for (s32 i = 0; i < 2; i++) {
                if (self->m_438[i] == 0) {
                    self->m_438[i] = create_particle_emitter(&self->body_center, 0xDC);
                    if (self->m_438[i] != 0) {
                        self->m_438[i]->enable();
                    } else {
                        for (s32 j = 0; j < i; j++) {
                            self->m_438[j]->enable();
                        }
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok != 0) {
                if (self->frame < self->m_4d4 && self->frame >= self->m_4d0) {
                    for (s32 i = 0; i < 2; i++) {
                        self->m_438[i]->enable();
                    }
                } else {
                    for (s32 i = 0; i < 2; i++) {
                        self->m_438[i]->set_position(&self->m_420[i]);
                    }
                }
            }
            if (self->is_passing_frame(self->m_4d0) != 0) {
                self->m_418[self->m_3f4] |= 3;
                self->m_3fc.reset_obstruction_fade();
                VecCopy(&v, &TObjEneRe7Berura__detached_part_states[self->m_3f4].m_58);
                rotate_xz_pair_by_angle(&v.x, &v.z, self->rotation_y);
                vec3_add_to(&v, &self->position);
                launch__21TObjEneRe7BeruraPunchFll(self->m_3f8, self->m_3f4, &v, &self->destination.x);
                self->m_4c0 = 1;
                self->destroy_parts();
                play_sound_effect(self->remap_sound_for_area(0x4003A321), &self->position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x100);
            }
            break;
        case 1:
            if (!(self->m_418[self->m_3f4] & 2)) {
                self->m_4c0 = 2;
                self->m_418[self->m_3f4] |= 4;
                self->m_418[self->m_3f4] &= ~1;
            }
            break;
        case 2:
            if (self->m_3fc.advance_toward_max() != 0) {
                self->m_418[self->m_3f4] &= ~4;
                if (self->m_3f4 == 0) {
                    self->m_3f4 = 1;
                } else {
                    self->m_3f4 = 0;
                }
                self->m_4c0 = 3;
            }
            break;
        }
        self->update_ground_contact();
        self->check_collisions();
        break;
    case 5:
        self->m_3fc.reset_color();
        self->m_418[self->m_3f4] &= ~7;
        self->destroy_parts();
        break;
    }
}

void TObjEneRe7Berura__sub_80093888(TObjEneRe7Berura *actor, s32 reason) {
    Vec sp2C;
    Vec sp20;
    Vec sp14;
    Vec sp8;
    s32 i;
    s32 entry;

    switch (reason) {
    case 4:
        actor->requested_action = 1;
        actor->clear_intangible();
        actor->m_3c0 &= ~7;
        actor->set_field_378(6);
        actor->m_4c0 = 0;
        actor->m_4c4 = 0;
        actor->m_4c8 = 0;
        actor->m_4cc = ((TObjEneRe7Berura *)actor)->get_field_3D4_shifted();
        return;
    case 3:
        if (actor->m_4c0 != 0) {
        case 5:
            return;
        }
        if (actor->check_death_trigger() == 0) {
            if (actor->current_target == NULL) {
                actor->transition_enemy_state(8);
            } else if (actor->destination_distance >= 30.0f) {
                actor->transition_enemy_state(4);
            } else if (((TObjEneRe7Berura *)actor)->is_over_limit() != 0) {
                actor->transition_enemy_state(7);
            }
        }
        break;
    case 0:
        actor->advance_animation();
        switch (actor->m_4c0) {
        case 0:
            if (enemy_validate_retained_target(actor) != 0) {
                actor->enemy_copy_target_destination();
                actor->update_velocity();
                if (actor->step_toward_target((s32) (RADIANS_TO_ANGLE * atan2_float(actor->destination_direction.x, actor->destination_direction.z)), 0x100) != 0) {
                    actor->m_4c0 = 1;
                    actor->requested_action = 2;
                    actor->init_fields4B8();
                    for (i = 0; i < 2; i++) {
                        actor->m_440[i]->clear_segments();
                    }
                }
                actor->play_band_sound();
            }
            break;
        case 1:
            if (actor->is_passing_frame(12.0f) != 0) {
                play_sound_effect(actor->remap_sound_for_area(0x4003AD22), &actor->position, 0, 0);
            }
            if ((actor->is_passing_frame(16.0f) != 0) && (actor->enemy_check_target_valid() != 0)) {
                if (actor->current_target->select_melee_contact_body(actor, 1.0f) != 0) {
                    if (actor->current_target->receive_physical_attack(actor, 1.0f) > 0.0f) {
                        if (TObjEneDD::check_v2_mode() != 0) {
                            if (actor->random_ratio() <= 0.1f) {
                                TObjEneDD__sub_800BA378(actor, actor->current_target);
                            }
                        } else if (actor->random_ratio() <= 0.3333f) {
                            TObjEneDD__sub_800BA378(actor, actor->current_target);
                        }
                    }
                    actor->current_target->apply_knockback_from_attacker((u8 *)actor, 5.0f);
                }
            }
            entry = (saddr)belra_trail_buffer->lookup(actor->frame);
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&actor->position);
                rotate_matrix_y(0, actor->rotation_y);
                matrix_mult_vec_array(0, entry, &sp8, 4);
                pop_matrix();
                actor->m_440[0]->vfunc_6(&sp8, &sp14);
                actor->m_440[1]->vfunc_6(&sp20, &sp2C);
            }
            if (actor->get_flag_b4() != 0) {
                actor->m_4c0 = 2;
                actor->m_4c4 = 0;
                actor->requested_action = 0;
            }
            break;
        case 2:
            actor->m_4c4 = actor->m_4c4 + 1;
            if (actor->m_4c4 >= 0x32) {
                actor->m_4c0 = 0;
                actor->requested_action = 1;
            }
            break;
        }
        actor->update_ground_contact();
        actor->check_collisions();
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
        m_3c0 &= ~3;
        m_3c0 |= 4;
        set_field_378(4);
        m_4c0 = 0;
        m_4c4 = TObjEneRe7Berura__sub_80094DB4(this);
        m_3cc = 0;
        m_4c8 = 0x300;
        break;
    case 3:
        if (m_4c0 >= m_4c4) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        m_4c0 = m_4c0 + 1;
        t = m_4c8;
        if (t > 0) {
            m_4c8 = t - 0xB;
            v = (m_4c8 > 0x100) ? 0x100 : m_4c8;
            if (m_4bc > 0) {
                rotation_y += v;
            } else {
                rotation_y -= v;
            }
        }
        if ((m_4c0 & 0x1F) < 0x10) {
            m_3c8 = 0xFF303030;
        } else {
            m_3c8 = -1;
        }
        update_ground_contact();
        check_collisions();
        set_sound_pitch_request(
            play_persistent_sound(remap_sound_for_area(0x4003C61E), (saddr)this, (uaddr)&position, 0, 0),
            0x400, 0);
        break;
    case 5:
        m_3c0 &= ~4;
        m_3d4 = m_3d4 + 1;
        m_3c8 = -1;
        m_3cc = 0xC;
        init_fields4B8();
        break;
    }
}

#pragma pop
void TObjEneRe7Berura::state_patrol(void *arg0, int msg) {
    TObjEneRe7Berura *self = (TObjEneRe7Berura *)arg0;

    switch (msg) {
    case 4:
        self->requested_action = 1;
        self->clear_intangible();
        self->m_3c0 = self->m_3c0 & ~3;
        self->m_3c0 = self->m_3c0 | 4;
        self->set_field_378(9);
        self->m_4c0 = 0;
        self->m_4c8 = self->rotation_y + 0x3800;
        break;
    case 3:
        if (self->rotation_y >= self->m_4c8) {
            self->transition_enemy_state(5);
        }
        break;
    case 0:
        self->advance_animation();
        if (((TObjEneRe7BeruraPunch *)self)->is_patrol_active() == 0) {
            self->play_speed = 1.6f;
        }
        self->rotation_y = self->rotation_y + 0x280;
        self->update_ground_contact();
        self->check_collisions();
        break;
    case 5:
        self->m_3c0 = self->m_3c0 & ~4;
        break;
    }

}

void TObjEneRe7Berura__sub_80093470(TObjEneRe7Berura *self, s32 mode) {
    Vec v;
    f32 speed;
    switch (mode) {
    case 4:
        self->requested_action = 6;
        self->clear_intangible();
        self->m_3c0 &= ~7;
        self->advance_animation();
        play_sound_effect(self->remap_sound_for_area(0x4003A826), &self->position, 0, 0);
        self->set_active();
        break;
    case 3:
        if (self->get_flag_b4() != 0) {
            ((TObjEneDD *)self)->transition_enemy_state(self->next_mode);
        }
        break;
    case 0:
        self->advance_animation();
        VecCopy(&v, (Vec *)&self->x_speed);
        speed = normalize_vector_xz(&v);
        self->move_clamped_on_ground(v.x, v.z, speed);
        self->x_speed *= 0.8f;
        self->m_310 *= 0.8f;
        break;
    case 5:
        self->clear_attack_receipts();
        self->clear_field_388();
        break;
    }
}

void TObjEneRe7Berura::update_death_state(s32 mode) {
    switch (mode) {
    case 4:
        requested_action = 7;
        clear_intangible();
        m_3c0 &= ~7;
        advance_animation();
        refresh_and_send_entity_flags();
        TObjEneRe7BeruraPunch__sub_800962F4(m_3f8);
        m_4d0 = m_3cc;
        m_4c4 = 0;
        m_4c0 = 0;
        fn_800D911C(&body_center);
        TObjPlayer__sub_800A04F0(&m_3d8);
        m_3c0 |= 2;
        play_sound_effect(remap_sound_for_area(0x4003AD25), &position, 0, 0);
        break;
    case 0:
        switch (m_4c4) {
        case 0: {
            advance_animation();
            if (m_3d8.decay_value_toward_floor() != 0) {
                m_4c4 = 4;
                m_3c0 |= 1;
                TObjPlayer::apply_effect_variant_b((saddr)&position, 0);
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
        lbl_805D4F6C = model_render_flags;
        model_render_flags &= 0xFFFF7FFF;
        break;
    case 0x3:
        model_render_flags = lbl_805D4F6C;
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
        lbl_805D4F6C = model_render_flags;
        model_render_flags &= 0xFFFF7FFF;
        break;
    case 26:
        model_render_flags = lbl_805D4F6C;
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
    if (m_3c0 & 1) {
        visible = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        visible = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        visible = 1;
    } else {
        visible = 0;
    }
    if (visible != 0) {
        if (mode != 0xB) {
            Vec v = lbl_80439EC4;
            draw_ground_shadow(&v, 0);
        }
        update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        model_render_flags &= ~0x810;
        TObjPlayer::toggle_particle_effect();
        for (i = 0; i < 2; i++) {
            if (m_418[i] & 1) {
                fn_80095DF4(&TObjEneRe7Berura__detached_part_states[i]);
            }
        }
        *berura_node_matrix_ptr_a = m_3c4;
        berura_node_matrix_ptr_b[0] = m_3c8;
        berura_node_matrix_ptr_b[1] = m_3c8 >> 16;
        scroll_strip_uvs(belra_uv_animation_buffer, (s16)m_3d0, 0);
        fade = &m_448[cam];
        fade->update();
        cam = fade->updateFromCamera(&body_center.x);
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(texlist));
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        if (mode == 5) {
            re7_berura_demo_state = 0;
            lbl_805D4F6C = 0;
            re7_berura_demo_camera_ptr = m_420;
            m_420[0].x = 15.0f;
            m_420[0].y = 0.0f;
            m_420[0].z = 10.0f;
            m_420[1].x = 15.0f;
            m_420[1].y = 0.0f;
            m_420[1].z = -10.0f;
            berura_demo_flag = (m_418[0] >> 2) & 1;
            re7_berura_demo_flag = (m_418[1] >> 2) & 1;
            TObjEneRe7Berura__demo_target = &m_3fc;
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
            lbl_805D4F6C = 0;
            if (m_3c0 & 2) {
                if (m_3d8.has_visible_opacity() != 0) {
                    m_3d8.set_flags_and_apply_damage_color();
                    f2 = 1;
                    if (defer_render() != 0) {
                        f2 = 0;
                    }
                    if (f2 != 0) {
                        set_chunk_model_node_callback(TObjEneRe7Berura::advance_state);
                        draw();
                        set_chunk_model_node_callback(0);
                    }
                    m_3d8.clear_flag_and_notify();
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
            if (m_418[l3] & 1) {
                fn_80095DD0(&TObjEneRe7Berura__detached_part_states[l3]);
            }
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        return;
    }
    if (mode == 5) {
        for (l4 = 0; l4 < 2; l4++) {
            VecCopy(&m_420[l4], &position);
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
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(texlist));
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
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
