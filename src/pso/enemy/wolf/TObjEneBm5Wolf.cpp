#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/math/FloatRounding.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/wolf/TObjEneBm5Wolf.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/AngleUnits.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/system/vector.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
extern "C" {
s32 approach_angle_limited(int, int, int);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
void *fn_800B8B00(void *p);
u16 get_entity_id(TObjBase *object);
extern u32 TObjEneBm5Wolf__instance_list[];
extern u32 TObjEneBm5Wolf__pack_member_list[];
BmlResource *TObjEneBm5Wolf__bml_resource;

void *bm5_wolf_decision_row[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};

CollisionBody TObjEneBm5Wolf__collider_params[3] = {
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x8003 },
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x9d03 },
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x9d03 },
};

const char *bm_ene_bm5_wolf_model_names[3] = {
    "bm5_s_kem_body.nj", "bm5_s_keml_body.nj", NULL,
};

const char *bm_ene_bm5_wolf_motion_names[15] = {
    "dams_bm5_s_kem_body.njm", "deadl_bm5_s_kem_body.njm", "deadr_bm5_s_kem_body.njm", "eat_bm5_s_kem_body.njm",
    "hoe_bm5_s_kem_body.njm", "hunt_bm5_s_kem_body.njm", "okil_bm5_s_kem_body.njm", "okir_bm5_s_kem_body.njm",
    "runb_bm5_s_kem_body.njm", "run_bm5_s_kem_body.njm", "sleep_bm5_s_kem_body.njm", "stdup_bm5_s_kem_body.njm",
    "wait_bm5_s_kem_body.njm", "walk_bm5_s_kem_body.njm", NULL,
};

BmlResourceDescriptor bm_ene_bm5_wolf_resource_descriptor = {
    "bm_ene_bm5_wolf.bml", bm_ene_bm5_wolf_model_names, bm_ene_bm5_wolf_motion_names, 2, 14,
};

TObjMotionAction wolf_action_table[19] = {
    { 1, 0, 12, 0.8f, 0x0 },
    { 1, 0, 13, 1.0f, 0x0 },
    { 1, 0, 9, 1.0f, 0x0 },
    { 1, 0, 9, 1.0f, 0x0 },
    { 3, 0, 10, 0.5f, 0x0 },
    { 3, 0, 11, 0.5f, 0x0 },
    { 3, 0, 0, 1.0f, 0x0 },
    { 2, 8, 1, 1.5f, 0x0 },
    { 3, 0, 6, 0.5f, 0x0 },
    { 2, 10, 2, 1.5f, 0x0 },
    { 3, 0, 7, 0.5f, 0x0 },
    { 3, 0, 4, 0.4f, 0x0 },
    { 3, 0, 5, 1.5f, 0x0 },
    { 3, 0, 3, 0.8f, 0x0 },
    { 3, 0, 1, 1.0f, 0x0 },
    { 3, 0, 2, 1.0f, 0x0 },
    { 2, 11, 11, 0.5f, 0x0 },
    { 3, 0, 5, 1.0f, 0x0 },
    { 3, 0, 9, 1.0f, 0x0 },
};

const char *bm5_wolf_class_name = "TObjEneBm5Wolf";

static const NpcAnimationBinding bm5_wolf_spawn_descriptor = { NULL, reinterpret_cast<TObjMotionAction *>(wolf_action_table), 0, 1, 19 };

__declspec(section ".data") u8 *TObjEneBm5Wolf__stat_params[2];
__declspec(section ".data") u8 *wolf_stat_handle_a_table[2];
__declspec(section ".data") u8 *wolf_stat_handle_b_table[2];
__declspec(section ".data") s32 lbl_80500B58[2];
s32 is_vec_xz_cross_negative(void *, void *);
f32 calc_circle_offset__14TObjEneBm5WolfFPvPvPv(TObjEneBm5Wolf *wolf, Vec *target, Vec *out);
s32 TBoss8Dragon__sub_800BB7D4(void *, int);
void draw_blob_shadow(s32 arg0);
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
s32 post_translate_matrix(void *);
s32 TObjEneBm5Wolf__spawn_timer;
s32 TObjEneBm5Wolf__data_805D5128;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
s32 vec3_add_to(void *, void *);
void TObjEneDD__sub_800BA378(s32 arg0, u8 *arg1);
s32 pack_debug_text_position(s32 arg0, s32 arg1);
s32 debug_draw_line(void *, void *, int, int);
typedef void (*State_800B73A8)(u8 *, s32);
}
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
#include <stddef.h>

#pragma defer_codegen on
extern "C" {
f32 newton_sqrtf(f32);
#pragma push
#pragma fp_contract on
s32 angle_diff_s16(s32, s32);
s32 free_collision_body_parts(void *);
s32 init_collision_body_parts(void *, void *, int);
void *__ct__14TObjCollidableFP7TObject(void *, int);
}

struct Globals_800B8A40 {
    u8 pad[0x2c];
    u8 chain0[0xc];
    u8 list0[0x8];
    u8 chain1[0xc];
    u8 list1[0x8];
};
extern "C" {
extern s32 lbl_8043B3A8[];
extern s32 lbl_8043B3B0[];
extern s32 lbl_8043B3B8[];
extern s32 lbl_8043B3C0[];
Vec lbl_80500B60;
u32 lbl_80500B6C[3];
u32 TObjEneBm5Wolf__pack_member_list[5];
u32 TObjEneBm5Wolf__instance_list[3];
void __register_global_object(void *obj, void *dtor, void *chain);
void __dl__FPv(void);
extern void *tl_04;
}

__declspec(section ".ctors") static void *const __sinit_TObjEneBm5Wolf_cpp_ref = (void *)TObjEneBm5Wolf::register_global_objects;

s32 TObjEneBm5Wolf::get_group_id() { return this->m_3dc; }

s32 actor_rand_int(saddr actor, s32 arg1) {
    return (s32) ((f32) arg1 * ((TObjChara *)actor)->random_ratio());
}

void TObjEneBm5Wolf::register_global_objects() {
    Globals_800B8A40 *g = (Globals_800B8A40 *)TObjEneBm5Wolf__stat_params;
    __register_global_object(((void *)((TObjEneBm5Wolf *)(g->list0))->reset()), (void *)__dt__14TObjEneBm5WolfFis, g->chain0);
    __register_global_object(((void *)((TObjEneBm5Wolf *)(g->list1))->reset()), (void *)__dt__14TObjEneBm5WolfFis, g->chain1);
}

TObjEneBm5WolfListNode::TObjEneBm5WolfListNode() {
    prev = NULL;
    next = NULL;
    entity_id = 0xFFFF;
}

TObjEneBm5WolfListNode::~TObjEneBm5WolfListNode() {}

void TObjEneBm5Wolf::unlink_list_node(void ***arg1, void **arg2) {
    TObjEneBm5WolfListNode *node = (TObjEneBm5WolfListNode *)this;
    TObjEneBm5WolfListNode **head = (TObjEneBm5WolfListNode **)arg1;
    TObjEneBm5WolfListNode **tail = (TObjEneBm5WolfListNode **)arg2;
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        *head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
        return;
    }
    *tail = node->prev;
}

void TObjEneBm5Wolf::push_list_node(void **arg1, void **arg2) {
    TObjEneBm5WolfListNode *node = (TObjEneBm5WolfListNode *)this;
    TObjEneBm5WolfListNode **head = (TObjEneBm5WolfListNode **)arg1;
    TObjEneBm5WolfListNode **tail = (TObjEneBm5WolfListNode **)arg2;
    if (*tail != NULL) {
        node->prev = *tail;
        (*tail)->next = node;
    } else {
        node->prev = NULL;
        *head = node;
    }
    *tail = node;
    node->next = NULL;
}

void TObjEneBm5Wolf::set_field8_from_obj(saddr arg1) {
    ((TObjEneBm5WolfListNode *)this)->entity_id = get_entity_id((TObjBase *)arg1);
}

TObjEneBm5Wolf *play_sound__14TObjEneBm5WolfFPv(TObjEneBm5WolfListNode *node) {
    return (TObjEneBm5Wolf *)find_entity_by_id(node->entity_id);
}

void*TObjEneBm5Wolf::reset() { reset_fields(); return this; }

s32 __dt__14TObjEneBm5WolfFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void TObjEneBm5Wolf::reset_fields() {
    TObjEneBm5WolfList *list = (TObjEneBm5WolfList *)this;
    list->head = NULL;
    list->tail = NULL;
}

void TObjEneBm5Wolf::apply_to_position(void* a1) {
    TObjEneBm5WolfList *list = (TObjEneBm5WolfList *)this;
    ((TObjEneBm5Wolf *)a1)->push_list_node((void **)&list->head, (void **)&list->tail);
}

void TObjEneBm5Wolf::update(void* a1) {
    TObjEneBm5WolfList *list = (TObjEneBm5WolfList *)this;
    ((TObjEneBm5Wolf *)a1)->unlink_list_node((void ***)&list->head, (void **)&list->tail);
}

void TObjEneBm5Wolf::load_resources() {
    s32 i;

    if (TObjEneDD::check_v2_mode() != 0) {
        TObjEneBm5Wolf__bml_resource = load_enemy_bml_resource_named(&bm_ene_bm5_wolf_resource_descriptor, "bm_ene_bm5_wolf_a.bml");
    } else {
        TObjEneBm5Wolf__bml_resource = load_enemy_bml_resource(&bm_ene_bm5_wolf_resource_descriptor);
    }
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__pack_member_list)->reset_fields();
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__instance_list)->reset_fields();
    TObjEneBm5Wolf__spawn_timer = 0;
    TObjEneBm5Wolf__data_805D5128 = 0;
    lbl_80500B60.x = 0.0f;
    lbl_80500B60.y = 0.0f;
    lbl_80500B60.z = 0.0f;
    for (i = 0; i < 2; i++) {
        TObjEneBm5Wolf__stat_params[i] = (u8 *)TLobby::register_boss(lbl_8043B3A8[i]);
        wolf_stat_handle_a_table[i] = (u8 *)TLobby::dispatch_shared_handler_b(lbl_8043B3B0[i]);
        wolf_stat_handle_b_table[i] = (u8 *)TLobby::register_object(lbl_8043B3B8[i]);
        lbl_80500B58[i] = (saddr)TLobby::dispatch_shared_handler_a(lbl_8043B3C0[i]);
    }
    {
    NpcAnimationBinding sp = bm5_wolf_spawn_descriptor;
    sp.motions = reinterpret_cast<BmlMotionEntry *>(TObjEneBm5Wolf__bml_resource->motions);
    NpcModelRegistry::register_animated_chunk(9, reinterpret_cast<void *>(TObjEneBm5Wolf__bml_resource->models[1].model), reinterpret_cast<void *>(TObjEneBm5Wolf__bml_resource->models[0].m_c), &sp, TObjEneBm5Wolf__collider_params[0].radius, 0.0f);
    NpcModelRegistry::register_animated_chunk(10, reinterpret_cast<void *>(TObjEneBm5Wolf__bml_resource->models[0].model), reinterpret_cast<void *>(TObjEneBm5Wolf__bml_resource->models[0].m_c), &sp, TObjEneBm5Wolf__collider_params[0].radius, 0.0f);
    }
}

// dead-stripped: only its literals survive. The int-to-float double (.rodata 0x8043B5B8) is pooled before
// load_resources' file name, but its only live user actor_rand_int is compiled after load_resources
// (defer_codegen runs this file bottom-up). Minimal body after actor_rand_int's conversion; name inferred.
static f32 actor_rand_float(saddr actor, s32 range) {
    return (f32)range * ((TObjChara *)actor)->random_ratio();
}

void *TObjEneBm5Wolf::create(void *arg0) {
    return new TObjEneBm5Wolf((TObject *)tl_04, arg0);
}

void TObjEneBm5Wolf::release_global_805D5120() {
    if (TObjEneBm5Wolf__bml_resource != 0) {
        delete TObjEneBm5Wolf__bml_resource;
        TObjEneBm5Wolf__bml_resource = 0;
    }
}

void TObjEneBm5Wolf::apply_position_to_node_list() {
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__pack_member_list)->apply_to_position(&this->m_3c0);
}

void TObjEneBm5Wolf::update_with_default_state() {
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__pack_member_list)->update(&this->m_3c0);
}

void TObjEneBm5Wolf::apply_global_to_position() {
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__instance_list)->apply_to_position(&this->m_3cc);
}

void TObjEneBm5Wolf::update_default() {
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__instance_list)->update(&this->m_3cc);
}

TObjEneBm5Wolf *TObjEneBm5Wolf::find_pack_leader(s32 id) {
    TObjEneBm5WolfListNode *n;
    for (n = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->head; n != 0; n = n->next) {
        TObjEneBm5Wolf *w = play_sound__14TObjEneBm5WolfFPv(n);
        if (w != 0 && w->m_3dc == id) {
            return w;
        }
    }
    return 0;
}
#pragma push
#pragma bool off
TObjEneBm5Wolf::TObjEneBm5Wolf(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    s32 n;
    void *o;
    m_name = bm5_wolf_class_name;
    invoke_initialization_hook(set_data);
    select_subtype();
    init_position_vectors();
    init_model(TObjEneBm5Wolf__collider_params, 1);
    set_field_d8((saddr)((void *)wolf_action_table));
    set_field_dc((saddr)TObjEneBm5Wolf__bml_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    n = m_3d8;
    reset_hp(TObjEneBm5Wolf__stat_params[n != 0], wolf_stat_handle_a_table[n != 0], wolf_stat_handle_b_table[n != 0]);
    set_state_flag_1();
    movementParameters = bm5_wolf_decision_row;
    if (m_3d8 != 0) {
        initialize_enemy_state(8);
    } else {
        initialize_enemy_state(7);
    }
    wall_reach = 15.0f;
    enemy_init_acquire_period(0x14);
    enemy_init_validate_period(0x14);
    ((TObjEneBm5Wolf *)&m_3c0)->set_field8_from_obj((saddr)this);
    apply_position_to_node_list();
    if (m_3d8 != 0) {
        ((TObjEneBm5Wolf *)&m_3cc)->set_field8_from_obj((saddr)this);
        apply_global_to_position();
    }
    m_3e0 = 0xFFFF;
    turnOffset = 0;
    VecCopy(&m_3e8, &position);
    VecCopy(&groupAnchor, &position);
    desiredSpeed = 0.0f;
    currentSpeed = 0.0f;
    m_408 = 0;
    m_40c = 0.0f;
    o = TObject::operator new(0xAC);
    if (o != NULL) {
        o = __ct__14TObjCollidableFP7TObject(o, 0);
    }
    m_410 = (TObjCollidable *)o;
    init_collision_body_parts(m_410, &TObjEneBm5Wolf__collider_params[1], 1);
    m_414 = 0;
    m_418 = 0xFFFF;
    set_colliders_contact_low();
    roamingSubstate = 0;
    roamingTimer = 0;
    randomPhase = 0;
    m_428 = 0;
    m_42c = 0;
    m_430 = 0;
    stoppingDistance = 0.0f;
    m_438 = 0.0f;
    m_43c = 0.0f;
    m_440 = 0.0f;
    m_444.x = 0.0f;
    m_444.y = 0.0f;
    m_444.z = 0.0f;
    m_450.x = 0.0f;
    m_450.y = 0.0f;
    m_450.z = 0.0f;
    m_45c = 0.0f;
    m_460 = 0.0f;
    m_464 = 0.0f;
    nearTarget = 0;
    update_collision_center();
    update_body_colliders();
    transform_part_positions();
    mode = 0;
    dispatch_action(mode, 4);
}
#pragma pop
TObjEneBm5Wolf::~TObjEneBm5Wolf() {
    if (m_410 != NULL) {
        free_collision_body_parts(m_410);
        delete m_410;
        m_410 = NULL;
    }
    update_with_default_state();
    if (m_3d8 != 0) {
        update_default();
    }
    free_collision_body_parts(this);
}

void TObjEneBm5Wolf::run_task() {
    s16 temp_r0;
    s16 temp_r3_2;
    s32 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_state();
        return;
    }
    TObject *entity = (TObject *)find_entity_by_id((this->m_3e0));
    if (entity != NULL) {
        entity->all_parents_unqueued_for_destruction();
    }
    if (this->update_status_effects() != 4) {
        temp_r3 = this->m_414;
        if (temp_r3 != 0) {
            this->m_414 = (temp_r3 - 1);
            if (this->m_414 == 0) {
                temp_r0 = this->mode;
                if ((temp_r0 != 0x10) && (temp_r0 != 0x11)) {
                    this->transition_enemy_state(0xE);
                }
            }
        }
        this->update_action_state();
    } else {
        temp_r3_2 = this->mode;
        if (temp_r3_2 == 0) {
            this->update_action_state();
        } else if (temp_r3_2 == 1) {
            VecCopy(&this->position, &this->home_position);
            this->transition_enemy_state(7);
            this->update_action_state();
        }
    }
    this->update_collision_center();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
}

void TObjEneBm5Wolf::refresh_target() {  }

void TObjEneBm5Wolf::run_death_reaction() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0x10) && (temp_r0 != 0x11)) {
        this->transition_enemy_state(0x10);
    }
}

void TObjEneBm5Wolf::run_hit_reaction() { if (this->mode != 15) { this->transition_enemy_state(15); } }

void TObjEneBm5Wolf::run_miss_reaction() {  }

void TObjEneBm5Wolf::update_collision_center() {

    this->body_center.x = (f32) this->position.x;
    this->body_center.y = (f32) ((this->m_40c) + (10.0f + this->position.y));
    this->body_center.z = (f32) this->position.z;
    VecCopy(&this->center, &this->body_center);
}

void TObjEneBm5Wolf::update_body_colliders() {
    this->bodies->offset.y = 10.0f + this->m_40c;
}

void TObjEneBm5Wolf::select_subtype() {
    this->m_3dc = (s32) floor_to_float(this->parameters[0]);
    if (this->parameters[1] >= 1.0f) {
        this->m_3d8 = 1;
        this->model = (void *)TObjEneBm5Wolf__bml_resource->models[1].model;
        this->texlist = (saddr)TObjEneBm5Wolf__bml_resource->models[0].m_c;
        return;
    }
    this->m_3d8 = 0;
    this->model = (void *)TObjEneBm5Wolf__bml_resource->models[0].model;
    this->texlist = (saddr)TObjEneBm5Wolf__bml_resource->models[0].m_c;
}

void TObjEneBm5Wolf::advance_pose_turn(s32 target) {
    s32 d;
    d = angle_diff_s16(this->rotation_y, target);
    if (d > 0x4000) {
        d = 0x4000;
    } else if (d < -0x4000) {
        d = -0x4000;
    }
    if (this->turnOffset * d >= 0) {
        this->turnOffset = approach_angle_limited(this->turnOffset, d, 0x800);
    } else if (this->turnOffset * angle_diff_s16(this->turnOffset, d) >= 0) {
        if (this->turnOffset >= 0) {
            this->turnOffset -= 0x800;
        } else {
            this->turnOffset += 0x800;
        }
    } else {
        this->turnOffset = approach_angle_limited(this->turnOffset, d, 0x800);
    }
    this->turnOffset = (s16)this->turnOffset;
}

void TObjEneBm5Wolf::turn_pose_to_target() {
    f32 x;
    f32 z;
    x = this->position.x + 0.0f * sin_table_lookup(this->rotation_y);
    z = this->position.z + 0.0f * cos_table_lookup(this->rotation_y);
    f32 dx = this->current_target->position.x - x;
    f32 dz = this->current_target->position.z - z;
    z = atan2_float((0, dx), dz);
    advance_pose_turn((s32) (RADIANS_TO_ANGLE * z));
}

void TObjEneBm5Wolf::choose_roaming_destination() {
    Vec dir;
    f32 temp_f3;
    f32 temp_f3_2;
    CsnHit *hit;
    dir.x = this->position.x - this->groupAnchor.x;
    dir.y = 0.0f;
    dir.z = this->position.z - this->groupAnchor.z;
    normalize_vector_xz(&dir);
    rotate_xz_pair_by_angle(&dir.x, &dir.z, (s32) (32768.0f * this->random_ratio()) + 0x4000);
    temp_f3 = 120.0f * this->rand_range(0.3f, 1.0f);
    this->destination.x = (f32) ((dir.x * temp_f3) + this->groupAnchor.x);
    this->destination.z = (f32) ((dir.z * temp_f3) + this->groupAnchor.z);
    hit = csnVector(&this->body_center, &this->destination, 0x88E0U);
    if (hit != NULL) {
        dir.x = hit->contact->point.x - this->position.x;
        dir.z = hit->contact->point.z - this->position.z;
        temp_f3_2 = normalize_vector_xz(&dir) - 25.0f;
        this->destination.x = (f32) ((dir.x * temp_f3_2) + this->position.x);
        this->destination.z = (f32) ((dir.z * temp_f3_2) + this->position.z);
    }
}

void TObjEneBm5Wolf::approach_target(f32 step) {
    f32 desired;
    f32 current;

    current = this->currentSpeed;
    desired = this->desiredSpeed;
    if (current != desired) {
        if (current > desired) {
            this->currentSpeed = (f32) (current - step);
            if (this->currentSpeed < this->desiredSpeed) {
                this->currentSpeed = this->desiredSpeed;
            }
        } else {
            this->currentSpeed = (f32) (current + step);
            if (this->currentSpeed > this->desiredSpeed) {
                this->currentSpeed = this->desiredSpeed;
            }
        }
    }
}

void calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(TObjEneBm5Wolf *wolf, s32 angle, Vec *out, s32 *heading) {
    f32 c;
    f32 s;

    s = sin_table_lookup(angle);
    c = cos_table_lookup(angle);
    out->z = (f32) ((c * wolf->destination_direction.z) - (s * wolf->destination_direction.x));
    out->x = (f32) ((s * wolf->destination_direction.z) + (c * wolf->destination_direction.x));
    *heading = (s32) (RADIANS_TO_ANGLE * atan2_float(out->x, out->z));
}
#pragma pop
void TObjEneBm5Wolf::set_state_by_timer() {
    if (this->random_ratio() < 0.5f) {
        this->transition_enemy_state(8);
        return;
    }
    this->transition_enemy_state(9);
}

void TObjEneBm5Wolf::set_anim_state() {
    if (this->m_3d8 != 0) {
        this->transition_enemy_state(6);
        return;
    }
    this->transition_enemy_state(5);
}
#pragma push
#pragma fp_contract on
f32 calc_circle_offset__14TObjEneBm5WolfFPvPvPv(TObjEneBm5Wolf *wolf, Vec *target, Vec *out) {
    f32 dx;
    f32 dz;
    dz = wolf->position.z - target->z;
    dx = wolf->position.x - target->x;
    f32 distSq = dx * dx + dz * dz;
    f32 inv = 1.0f / ((f32 (*)(f32, f32))newton_sqrtf)(distSq, wolf->position.x);
    out->x = dx * inv;
    out->y = 0.0f;
    out->z = dz * inv;
    return distSq * inv;
}
#pragma pop
s32 TObjEneBm5Wolf::select_death_direction(s32 *heading) {
    Vec v;
    Vec side;
    s32 ret;
    VecCopy(&v, (const Vec *)&this->x_speed);
    v.y = 0.0f;
    if (0.0f != normalize_vector_xz(&v)) {
        *heading = (s32)(RADIANS_TO_ANGLE * atan2_float(v.x, v.z));
        side.x = sin_table_lookup(this->rotation_y);
        side.z = cos_table_lookup(this->rotation_y);
        if (is_vec_xz_cross_negative(&side, &v) != 0) {
            ret = 0;
            *heading += 0x4000;
        } else {
            ret = 1;
            *heading -= 0x4000;
        }
    } else {
        ret = 0;
        *heading = this->rotation_y;
    }
    *heading = (s16)*heading;
    return ret;
}

void TObjEneBm5Wolf::set_attack_flag() { this->m_408 |= 0x1; }

s32 TObjEneBm5Wolf::select_target() {
    if (this->m_3d8 != 0) {
        return this->select_and_apply_target(350.0f);
    }
    return this->select_and_apply_target(250.0f);
}

s32 TObjEneBm5Wolf::play_variant_sound() {
    if (this->m_3d8 != 0) {
        return this->update_linked_position(350.0f);
    }
    return this->update_linked_position(250.0f);
}
#pragma push
#pragma fp_contract on
void spawn_recoil_dust__14TObjEneBm5WolfFiPv(TObjEneBm5Wolf *wolf, Vec *dir) {
    Vec pos;
    VecCopy(&pos, &wolf->position);
    pos.x += 5.0f * dir->x;
    pos.z += 5.0f * dir->z;
    spawn_particle_effect(&pos, 0xF3);
}
#pragma pop
void TObjEneBm5Wolf::play_footsteps() {
    if ((this->is_passing_frame(7.0f) != 0) || (this->is_passing_frame(24.0f) != 0)) {
        play_sound_effect(this->remap_sound_for_area(0x3C618), &this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x1000);
    }
}

void TObjEneBm5Wolf::play_proximity_effect() {
    if (this->is_passing_frame(18.0f) != 0) {
        play_sound_effect(this->remap_sound_for_area(0x3C618), &this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x1000);
    }
}

f32 TObjEneBm5Wolf::calc_death_slide_speed(f32 speed) {
    return (28.0f) / ((this->motion_list[this->action_table[9].motion].motion->frameCount - 1) / speed);
}

int TObjEneBm5Wolf::get_flag_bit0() { return this->entity_id & 0x1; }
#pragma push
#pragma fp_contract on
s32 TObjEneBm5Wolf::calc_lunge_aim() {
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f0;
    if (is_target_unobstructed_from((TObjEneDD *)this, (TObjChara *)this->current_target) != 0) {
        this->enemy_copy_target_destination();
        this->update_velocity();
        if (((s32)get_flag_bit0()) != 0) {
            var_f0 = 7.0f;
        } else {
            var_f0 = -7.0f;
        }
        temp_f5 = this->destination_direction.z;
        temp_f4 = this->destination_direction.x;
        this->destination.x = (f32) (this->destination.x + ((2.0f * temp_f4) + (temp_f5 * var_f0)));
        this->destination.z = (f32) (this->destination.z + ((2.0f * temp_f5) - (temp_f4 * var_f0)));
        this->update_velocity();
        return (s32) (RADIANS_TO_ANGLE * atan2_float((f64) this->destination_direction.x, (f64) this->destination_direction.z));
    }
    this->destination_direction.x = sin_table_lookup(this->rotation_y);
    this->destination_direction.y = (f32) (0.0f);
    this->destination_direction.z = cos_table_lookup(this->rotation_y);
    VecCopy(&this->destination, &this->position);
    this->destination.x = (f32) ((30.0f * this->destination_direction.x) + this->destination.x);
    this->destination.z = (f32) ((30.0f * this->destination_direction.z) + this->destination.z);
    this->destination_distance = 30.0f;
    return this->rotation_y;
}
#pragma pop
void TObjEneBm5Wolf::schedule_pack_reaction(s32 delay, u16 value) {
    this->m_414 = delay;
    this->m_418 = value;
}

void TObjEneBm5Wolf::apply_mourning_zalure() {
    TObjEneBm5Wolf *target = (TObjEneBm5Wolf *)find_entity_by_id(this->m_3e0);
    if (target != 0) {
        DirectAttackPayload attack;
        attack.kind = 0xc;
        attack.power = 1.0f;
        this->receive_direct_attack(target, attack, 0, -1, -1);
    }
}

void TObjEneBm5Wolf::apply_mourning_jellen() {
    TObjEneBm5Wolf *target = (TObjEneBm5Wolf *)find_entity_by_id(this->m_3e0);
    if (target != 0) {
        DirectAttackPayload attack;
        attack.kind = 0xb;
        attack.power = 1.0f;
        this->receive_direct_attack(target, attack, 0, -1, -1);
    }
}

void TObjEneBm5Wolf::dispatch_action(u32 state, s32 event) {
    switch (state) {
    case 0:
        this->anchor_state(event);
        break;
    case 1:
        appearing_state(event);
        break;
    case 2:
        this->sleeping_state(event);
        break;
    case 3:
        ((State_800B73A8)TObjEneBm5Wolf::empty_state)((u8 *)this, event);
        break;
    case 4:
        this->alerted_state(event);
        break;
    case 5:
        this->standing_state(event);
        break;
    case 6:
        this->howling_state(event);
        break;
    case 7:
        this->roaming_state(event);
        break;
    case 8:
        this->chasing_state(event);
        break;
    case 9:
        this->flanking_state(event);
        break;
    case 10:
        this->circling_state(event);
        break;
    case 11:
        this->update_lunge(event);
        break;
    case 12:
        returning_state(event);
        break;
    case 13:
        this->repositioning_state(event);
        break;
    case 14:
        this->action(event);
        break;
    case 15:
        this->hurt_state(event);
        break;
    case 16:
        this->update_dying_state(event);
        break;
    case 17:
        this->despawn_state(event);
        break;
    }
}

void TObjEneBm5Wolf::anchor_state(s32 arg1) {
    TObjEneBm5Wolf *leader;

    switch (arg1) {
    case 4:
        this->roamingTimer = 0;
        this->set_field_378(0);
        this->set_intangible();
        this->m_408 = (s32) (this->m_408 | 2);
        return;
    case 3:
        if (this->roamingTimer > 0) {
            this->transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        leader = TObjEneBm5Wolf::find_pack_leader(this->m_3dc);
        if (leader != 0) {
            this->m_3e0 = get_entity_id(leader);
        }
        if ((this->m_3d8 != 0) || (leader == 0)) {
            VecCopy(&this->groupAnchor, (const Vec *)&this->m_3e8);
        } else {
            VecCopy(&this->groupAnchor, (const Vec *)(fn_800B8B00(leader)));
        }
        this->roamingTimer = (this->roamingTimer + 1);
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::appearing_state(s32 arg1) {
    Vec *home = &this->m_444;
    f32 t;

    switch (arg1) {
    case 4:
        this->requested_action = 0x11;
        this->set_field_378(7);
        this->set_intangible();
        this->m_408 &= ~3;
        this->m_408 |= 4;
        this->enemy_clear_target();
        this->turnOffset = 0;
        VecCopy(home, &this->position);
        this->position.x -= 100.0f * sin_table_lookup(this->rotation_y);
        this->position.z -= 100.0f * cos_table_lookup(this->rotation_y);
        this->stoppingDistance = 3.3333333f;
        this->m_40c = 0.0f;
        this->m_438 = this->position.y;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            if (select_target() != 0) {
                this->transition_enemy_state(7);
            } else {
                this->transition_enemy_state(2);
            }
        }
        break;
    case 0:
        this->advance_animation();
        if (!(this->motion_flags & 4)) {
            if (this->is_passing_frame(5.0f) != 0 ||
                this->is_passing_frame(30.0f) != 0) {
                spawn_particle_effect(&this->position, 0xF3);
            }
            if (this->is_passing_frame(6.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x3E420), &this->position, 0, 0);
            }
            if (this->is_passing_frame(24.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x4003A821), &this->position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x500);
            }
            if (this->frame <= 30.0f) {
                t = this->frame - 15.0f;
                this->m_40c = (this->m_438 + (-0.08888889f * (t * t) + 20.0f)) - this->position.y;
            } else {
                this->stoppingDistance *= 0.8f;
            }
            this->position.x += this->stoppingDistance * sin_table_lookup(this->rotation_y);
            this->position.z += this->stoppingDistance * cos_table_lookup(this->rotation_y);
        }
        this->update_ground_contact();
        this->update_body_colliders();
        break;
    case 5:
        this->m_40c = 0.0f;
        break;
    }
}
#pragma pop
void TObjEneBm5Wolf::sleeping_state(s32 arg1) {
  TObjEneBm5Wolf *entity;
  switch (arg1)
  {
    case 4:
      this->requested_action = 4;
      this->set_field_378(2);
      (this->set_intangible());
      this->enemy_clear_target();
      this->turnOffset = 0;
      this->m_408 = (s32) ((this->m_408) & 0xFFFFFFFE);
      return;
    case 3:
      if ((this->m_408) & 1)
    {
      this->transition_enemy_state(4);
      return;
      return;
    }
      if (this->current_target != 0)
    {
      this->enemy_copy_target_destination();
      set_anim_state();
      entity = (TObjEneBm5Wolf *)find_entity_by_id(this->m_3e0);
      if (entity != 0)
      {
        entity->set_attack_flag();
      }
    }
      return;
    case 0:
      play_variant_sound();
      this->advance_animation();
      (this->update_ground_contact());
      (this->update_body_colliders());
      return;
    case 5:
      this->m_408 = (s32) ((this->m_408) & 0xFFFFFFFE);
      break;
  }
}

void TObjEneBm5Wolf::alerted_state(s32 arg1) {
  s32 new_var;
  switch (arg1)
  {
    case 4:
      this->requested_action = 4;
      this->set_field_378(4);
      (this->set_intangible());
      new_var = (s32) (((s32) (60.0f * this->random_ratio())) + 0xA);
      this->roamingSubstate = new_var;
      return;
    case 3:
      if ((this->roamingSubstate) <= 0)
    {
      set_anim_state();
    }
    case 5:
      return;
      return;
    case 0:
      this->roamingSubstate = (s32) ((this->roamingSubstate) - 1);
      play_variant_sound();
      this->advance_animation();
      (this->update_ground_contact());
      (this->update_body_colliders());
      break;
  }
}

void TObjEneBm5Wolf::standing_state(s32 arg1) {
  switch (arg1)
  {
    case 4:
      this->requested_action = 5;
      this->set_field_378(7);
      (this->set_intangible());
      this->roamingSubstate = 0;
      return;
    case 3:
      if ((this->roamingSubstate) > 0x3C)
    {
      this->transition_enemy_state(7);
    }
    case 5:
      return;
    case 0:
      this->roamingSubstate = (s32) ((this->roamingSubstate) + 1);
      this->advance_animation();
      this->is_passing_frame(7.0f);
      if (enemy_validate_retained_target(this) != 0)
    {
      this->enemy_copy_target_destination();
      this->update_velocity();
      turn_pose_to_target();
    }
    else
    {
      play_variant_sound();
    }
      (this->update_ground_contact());
      (this->update_body_colliders());
      break;
  }
  return;
}

void TObjEneBm5Wolf::howling_state(s32 arg1) {
    TObjEneBm5WolfListNode *p;
    TObjEneBm5Wolf *r;
    switch (arg1) {
    case 4:
        this->requested_action = 0x10;
        set_field_378(7);
        this->set_intangible();
        this->roamingSubstate = 0;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(7);
        }
        break;
    case 5:
        break;
    case 0:
        (this->roamingSubstate)++;
        advance_animation();
        if (this->requested_action == 0x10) {
            is_passing_frame(7.0f);
        } else if (this->requested_action == 0xB && is_passing_frame(9.0f) != 0) {
            play_sound_effect(this->remap_sound_for_area(0x3A819), &this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (this->roamingSubstate == 0x3C) {
            for (p = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->head; p != NULL; p = p->next) {
                r = play_sound__14TObjEneBm5WolfFPv(p);
                if (this->m_3dc == ((TObjEneBm5Wolf *)r)->get_group_id()) {
                    r->set_attack_flag();
                }
            }
        }
        if (enemy_validate_retained_target(this) != 0) {
            if (this->requested_action == 0x10) {
                this->turn_pose_to_target();
            } else {
                this->turnOffset = 0;
            }
        } else {
            play_variant_sound();
        }
        this->update_ground_contact();
        this->update_body_colliders();
        break;
    }
}

void TObjEneBm5Wolf::empty_state() {  }
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::roaming_state(int event) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f31;
    f32 temp_f3;
    f32 square;
    s32 temp_r30;
    TObjChara *temp_r3;
    switch (event) {
    case 4:
        this->requested_action = 1;
        set_field_378(7);
        this->clear_intangible();
        this->roamingTimer = 0;
        this->roamingSubstate = 0;
        this->randomPhase = actor_rand_int((saddr)this, 0x14);
        this->nearTarget = 0;
        temp_r30 = (s32) (65536.0f * this->random_ratio());
        temp_f31 = 120.0f * this->random_ratio();
        this->destination.x = (f32) ((temp_f31 * sin_table_lookup(temp_r30)) + this->groupAnchor.x);
        this->destination.z = (f32) ((temp_f31 * cos_table_lookup(temp_r30)) + this->groupAnchor.z);
        this->desiredSpeed = (f32) ((0.7f * this->random_ratio()) + 0.3f);
        this->currentSpeed = (f32) (0.0f);
        this->stoppingDistance = (f32) (2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
        this->update_velocity();
        return;
    case 3:
        if (this->nearTarget != 0) {
            set_state_by_timer();
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (play_variant_sound() != 0) {
            temp_r3 = this->current_target;
            temp_f3 = temp_r3->position.x - this->position.x;
            temp_f1 = temp_r3->position.z - this->position.z;
            square = temp_f3 * temp_f3;
            square = (temp_f1 * temp_f1) + square;
            if (square < 22500.0f) {
                this->nearTarget = 1;
            }
            turn_pose_to_target();
        } else {
            advance_pose_turn(this->rotation_y);
        }
        switch (this->roamingSubstate) {
        case 0:
            play_footsteps();
            this->update_velocity();
            approach_target(0.05f);
            this->roamingTimer = (this->roamingTimer + 1);
            if ((this->destination_distance < this->stoppingDistance) || (this->roamingTimer > 0x64)) {
                this->roamingSubstate = 1;
                this->desiredSpeed = (f32) (0.0f);
            } else if (((s32)has_move_failures(0x14)) != 0) {
                this->roamingTimer = 0;
                choose_roaming_destination();
                this->desiredSpeed = this->rand_range(0.3f, 1.0f);
                this->stoppingDistance = (f32) (2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
            }
            this->play_speed = (f32) (1.1f * this->currentSpeed);
            temp_f1_2 = this->currentSpeed;
            enemy_turn_and_move_on_ground((u8 *)this, (s32)(512.0f * temp_f1_2), (f32)temp_f1_2);
            break;
        case 1:
            play_footsteps();
            this->update_velocity();
            approach_target(0.020000001f);
            if (this->currentSpeed <= 0.1f) {
                this->roamingSubstate = 2;
                this->roamingTimer = (s32) this->rand_range(240.0f, 360.0f);
                this->requested_action = 0;
            }
            this->play_speed = (f32) (1.1f * this->currentSpeed);
            temp_f1_3 = this->currentSpeed;
            enemy_turn_and_move_on_ground((u8 *)this, (s32)(512.0f * temp_f1_3), (f32)temp_f1_3);
            break;
        case 2:
            this->requested_action = 0;
            this->roamingTimer = (this->roamingTimer - 1);
            if (this->roamingTimer <= 0) {
                choose_roaming_destination();
                this->desiredSpeed = this->rand_range(0.3f, 1.0f);
                this->currentSpeed = (f32) (0.0f);
                this->stoppingDistance = (f32) (2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
                this->roamingSubstate = 0;
                this->requested_action = 1;
            }
            this->update_ground_contact();
            break;
        }
        this->check_collisions();
        break;
    }
}
#pragma pop
void TObjEneBm5Wolf::chasing_state(s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    switch (arg1) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(8);
        this->clear_intangible();
        this->desiredSpeed = (f32) (1.6f);
        this->roamingSubstate = 0;
        break;
    case 3:
        if ((uaddr) this->current_target == 0U) {
            this->transition_enemy_state(7);
            break;
        }
        if (this->has_move_failures(0xA) != 0) {
            this->transition_enemy_state(9);
            break;
        }
        if ((this->roamingSubstate == 0) && (this->is_passing_frame(this->frame_count - 1.0f) != 0) && (this->destination_distance < 90.0f)) {
            this->transition_enemy_state(0xA);
            break;
        }
    case 5:
    case 1:
        break;
    case 0:
        this->advance_animation();
        if (this->is_passing_frame(5.0f) != 0) {
            spawn_particle_effect(&this->position, 0xF3);
        }
        if ((s16) this->requested_action == 2) {
            play_proximity_effect();
        }
        if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            if (this->frame >= 15.0f) {
                this->currentSpeed *= 0.9f;
                this->play_speed = (f32) (0.8f * this->currentSpeed);
                temp_f1 = this->currentSpeed;
                enemy_turn_and_move_on_ground((u8 *)this, (768.0f * temp_f1), temp_f1);
            } else {
                approach_target(0.1f);
                this->play_speed = (f32) (0.8f * this->currentSpeed);
                temp_f1_2 = this->currentSpeed;
                enemy_turn_and_move_on_ground((u8 *)this, (768.0f * temp_f1_2), temp_f1_2);
            }
            turn_pose_to_target();
            this->check_collisions();
        }
        break;
    }
}

void TObjEneBm5Wolf::flanking_state(s32 arg1) {
    s32 *ang = &this->m_42c;
    Vec *dst = &this->m_444;
    Vec *src = &this->m_450;
    switch (arg1) {
    case 4:
        this->requested_action = 3;
        set_field_378(9);
        this->clear_intangible();
        this->desiredSpeed = 2.0f;
        this->roamingSubstate = 0;
        this->roamingTimer = 0;
        calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, 0x1C71, src, ang);
        VecCopy(dst, src);
        this->m_430 = *ang;
        break;
    case 3:
        if (this->current_target == 0U) {
            this->transition_enemy_state(7);
        } else if (is_passing_frame(this->frame_count - 1.0f) != 0 && this->destination_distance < 90.0f) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)((u8 *)this))->update_death_check() != 0) {
            if (is_passing_frame(5.0f) != 0) {
                spawn_particle_effect(&this->position, 0xF3);
            }
            this->play_proximity_effect();
            if (is_passing_frame(15.0f) != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                if (this->roamingTimer == 0) {
                    this->roamingTimer = 1;
                    calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, -0x1C71, src, ang);
                } else {
                    this->roamingTimer = 0;
                    calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, 0x1C71, src, ang);
                }
            }
            if (is_passing_frame(this->frame_count - 1.0f) != 0) {
                VecCopy(dst, src);
                this->m_430 = *ang;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_430, 0x800);
            this->rotation_y = (s16)this->rotation_y;
            if (this->frame >= 15.0f) {
                this->currentSpeed *= 0.9f;
                this->play_speed = 0.5f * this->currentSpeed;
                this->move_with_wall_slide_on_ground(dst->x, dst->z, this->currentSpeed);
            } else {
                approach_target(1.0f);
                this->play_speed = 0.5f * this->currentSpeed;
                this->move_with_wall_slide_on_ground(dst->x, dst->z, this->currentSpeed);
            }
            this->turn_pose_to_target();
            this->check_collisions();
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::circling_state(s32 arg1) {
    Vec *b;
    Vec *a;
    f32 vx;
    f32 vz;
    a = &this->m_444;
    b = &this->m_450;
    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(10);
        this->clear_intangible();
        this->desiredSpeed = 0.7f;
        this->roamingSubstate = 0;
        this->roamingTimer = 0;
        this->randomPhase = 0;
        this->m_428 = 0;
        this->m_42c = 0;
        this->stoppingDistance = 0.0f;
        this->m_438 = 0.0f;
        a->x = 0.0f;
        a->y = 0.0f;
        a->z = 0.0f;
        b->x = 0.0f;
        b->y = 0.0f;
        b->z = 0.0f;
        this->set_active();
        break;
    case 3:
        if (this->current_target == NULL) {
            this->transition_enemy_state(7);
            break;
        }
        if (this->roamingSubstate > 450) {
            this->roamingSubstate = 0;
            if (this->random_ratio() < 0.5f) {
                this->transition_enemy_state(11);
            }
        } else if (this->roamingSubstate > 45) {
            f32 dz = this->position.z - this->current_target->position.z;
            f32 dx = this->position.x - this->current_target->position.x;
            f32 d = dx * dx + dz * dz;
            if (d >= 10000.0f) {
                set_state_by_timer();
            } else if (d < 900.0f) {
                this->transition_enemy_state(11);
            } else {
                f32 c;
                vx = sin_table_lookup(this->current_target->rotation_y);
                c = cos_table_lookup(this->current_target->rotation_y);
                vz = vx * b->x + c * b->z;
                if (vz < cos_table_lookup(0x6AAA)) {
                    this->transition_enemy_state(11);
                }
            }
        }
        break;
    case 0:
        this->advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
            if (this->randomPhase == 0) {
                Vec fwd;
                Vec to;
                this->randomPhase = 1;
                VecCopy(a, &this->current_target->position);
                this->stoppingDistance = calc_circle_offset__14TObjEneBm5WolfFPvPvPv(this, a, b);
                this->m_438 = this->rand_range(50.0f, 80.0f);
                fwd.x = sin_table_lookup(this->rotation_y);
                fwd.y = 0.0f;
                fwd.z = cos_table_lookup(this->rotation_y);
                to.x = this->current_target->position.x - this->position.x;
                to.y = 0.0f;
                to.z = this->current_target->position.z - this->position.z;
                if (is_vec_xz_cross_negative(&fwd, &to) != 0) {
                    this->m_42c = -1;
                } else {
                    this->m_42c = 1;
                }
            }
            this->roamingSubstate++;
            play_footsteps();
            if (this->m_428 > 0) {
                this->m_428--;
                if (this->m_42c > 0) {
                    this->stoppingDistance -= 0.5f;
                } else {
                    this->stoppingDistance += 0.5f;
                }
            } else {
                f32 cur = this->stoppingDistance;
                f32 tgt = this->m_438;
                f32 diff = cur - tgt;
                if (diff > 0.2f) {
                    this->stoppingDistance = cur - 0.2f;
                } else if (diff < -0.2f) {
                    this->stoppingDistance += 0.2f;
                } else {
                    this->stoppingDistance = tgt;
                }
            }
            switch (this->randomPhase) {
            case 1: {
                this->desiredSpeed = 0.7f;
                approach_target(0.12f);
                calc_circle_offset__14TObjEneBm5WolfFPvPvPv(this, a, b);
                if (this->m_42c >= 0) {
                    vx = b->z;
                    vz = -b->x;
                } else {
                    vz = b->x;
                    vx = -b->z;
                }
                if (this->has_move_failures(1) != 0) {
                    this->set_active();
                } else {
                    this->clear_field_388();
                }
                this->move_with_wall_slide_on_ground(vx, vz, this->currentSpeed);
                if (this->has_move_failures(10) != 0) {
                    this->roamingTimer = 0;
                    this->randomPhase = 2;
                }
                break;
            }
            case 2: {
                s32 ang;
                f32 sx;
                f32 cz;
                this->desiredSpeed = 0.5f;
                approach_target(0.12f);
                this->roamingTimer++;
                if (this->roamingTimer >= 40) {
                    ang = this->rotation_y;
                } else {
                    ang = this->rotation_y + (this->m_42c << 11);
                }
                sx = sin_table_lookup(ang);
                cz = cos_table_lookup(ang);
                if (this->has_move_failures(2) != 0) {
                    this->roamingTimer = 0;
                    this->set_active();
                } else {
                    this->clear_field_388();
                }
                this->move_with_wall_slide_on_ground(sx, cz, this->currentSpeed);
                if (this->roamingTimer >= 80) {
                    this->randomPhase = 0;
                }
                break;
            }
            }
            this->rotation_y = approach_angle_limited(this->rotation_y,
                (s32)(RADIANS_TO_ANGLE * atan2_float(this->position.x - this->prev_position.x, this->position.z - this->prev_position.z)),
                0x200);
            this->rotation_y = (s16)this->rotation_y;
            this->play_speed = 1.1f * this->currentSpeed;
            this->turn_pose_to_target();
            this->check_collisions();
            if (this->bodies->flags & 0x380000) {
                this->m_428 = 20;
            }
        }
        break;
    case 5:
        this->clear_field_388();
        break;
    }
}

void TObjEneBm5Wolf::update_lunge(s32 arg1) {
    f32 temp_f2;
    f32 temp_f3;
    switch (arg1) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->m_408 = (s32) (this->m_408 & 0xFFFFFFFD);
        this->m_408 = (this->m_408 | 4);
        this->roamingSubstate = 0;
        this->roamingTimer = 0;
        this->m_42c = calc_lunge_aim();
        this->m_430 = 0;
        if (this->destination_distance > 40.0f) {
            this->destination_distance = 40.0f;
        }
        temp_f3 = this->destination_distance / 13.333333f;
        this->desiredSpeed = temp_f3;
        this->currentSpeed = temp_f3;
        this->nearTarget = 0;
        this->m_40c = (f32) (0.0f);
        this->stoppingDistance = (f32) this->position.y;
        this->m_43c = (f32) (20.0f);
        this->m_438 = -0.08888889f;
        return;
    case 3:
        if (this->roamingSubstate == 2) {
            this->transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (this->roamingSubstate) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                if (this->nearTarget != 0) {
                    this->roamingSubstate = 2;
                } else {
                    this->roamingSubstate = 1;
                    this->roamingTimer = 0;
                }
            }
            if (this->is_passing_frame(5.0f) != 0) {
                spawn_particle_effect(&this->position, 0xF3);
            }
            if (this->is_passing_frame(6.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x3E420), &this->position, 0, 0);
            }
            if (this->is_passing_frame(24.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area(0x4003A821), &this->position, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x500);
            }
            if (this->is_passing_frame((f32) (20.0f)) != 0) {
                this->nearTarget = 0;
                if (enemy_validate_retained_target(this) != 0) {
                    if (this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                        this->current_target->receive_physical_attack(this, 1.0f);
                        this->current_target->apply_knockback_from_attacker((u8 *)this, 7.0f);
                        this->nearTarget = 1;
                        if ((TObjEneDD::check_v2_mode() != 0) && (this->random_ratio() <= 0.1f)) {
                            if (this->m_3d8 != 0) {
                                TObjEneDD__sub_800BA378((saddr)this, (u8 *)this->current_target);
                            } else {
                                TObjEneDD::send_damage_message((saddr)this, (u8 *)this->current_target);
                            }
                        }
                    }
                }
            }
            approach_target((f32) (0.1f));
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0x1000);
            this->rotation_y = (s32) (s16) this->rotation_y;
            advance_pose_turn(this->rotation_y);
            if (this->frame <= 30.0f) {
                this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->currentSpeed);
                temp_f2 = this->frame - 15.0f;
                this->m_40c = (f32) ((this->stoppingDistance + ((this->m_438 * (temp_f2 * temp_f2)) + 20.0f)) - this->position.y);
            } else {
                if (this->nearTarget == 0) {
                    this->currentSpeed *= 0.8f;
                    this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->currentSpeed);
                }
                this->m_40c = (f32) (0.0f);
            }
            break;
        case 1:
            this->advance_animation();
            this->roamingTimer = (this->roamingTimer + 1);
            if (this->roamingTimer >= 0xA) {
                this->roamingSubstate = 2;
            }
            advance_pose_turn(this->rotation_y);
            if (this->nearTarget == 0) {
                this->currentSpeed *= 0.8f;
                this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->currentSpeed);
            }
            break;
        }
        this->check_collisions();
        return;
    case 5:
        this->m_40c = (f32) (0.0f);
        break;
    }
}

void TObjEneBm5Wolf::returning_state(s32 arg1) {
    Vec *home = &this->m_450;
    f32 lim = this->stoppingDistance;
    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(0xC);
        this->clear_intangible();
        this->desiredSpeed = 1.6f;
        this->roamingSubstate = 0;
        VecCopy(home, &this->position);
        TObjBoss2Tunnel::calc_scaled_value(0x200, 1.6f);
        this->m_430 = this->rotation_y;
        if (this->enemy_has_live_target() != 0) {
            Vec a;
            Vec d;
            TObjChara *t;
            a.x = sin_table_lookup(this->rotation_y);
            a.z = cos_table_lookup(this->rotation_y);
            t = this->current_target;
            d.x = t->position.x - this->position.x;
            d.z = t->position.z - this->position.z;
            if (is_vec_xz_cross_negative(&a, &d) != 0) {
                this->m_42c = 0x5000;
            } else {
                this->m_42c = -0x5000;
            }
        } else if (this->random_ratio() < 0.5f) {
            this->m_42c = 0x5000;
        } else {
            this->m_42c = -0x5000;
        }
        this->m_42c = this->m_42c + this->m_430;
        break;
    case 3:
        if (this->current_target == NULL || this->roamingSubstate > 0x96) {
            this->transition_enemy_state(7);
        } else if (this->destination_distance < lim) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        this->roamingSubstate++;
        this->advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
            play_footsteps();
            this->m_42c = approach_angle_limited(this->m_42c, this->m_430, 0x100);
            this->destination.x = 90.0f * sin_table_lookup(this->m_42c) + home->x;
            this->destination.z = 90.0f * cos_table_lookup(this->m_42c) + home->z;
            this->update_velocity();
            approach_target(0.2f);
            this->play_speed = 1.1f * this->currentSpeed;
            enemy_turn_and_move_on_ground((u8 *)this, 0x500, this->currentSpeed);
            this->turn_pose_to_target();
            this->check_collisions();
        }
        break;
    }
}
#pragma pop
void TObjEneBm5Wolf::repositioning_state(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->roamingSubstate = 0;
        this->m_42c = 0;
        this->roamingTimer = 0;
        return;
    case 3:
        if (this->roamingSubstate == 2) {
            if (this->current_target != 0U) {
                this->transition_enemy_state(0xA);
            } else {
                this->transition_enemy_state(7);
            }
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (this->roamingSubstate) {
        case 0: {
            f32 dx;
            f32 dz;
            this->m_42c = ((this->roamingTimer >> 1) << 0xC) + 0x1800;
            if (this->roamingTimer & 1) {
                this->m_42c = -this->m_42c;
            }
            if (get_flag_bit0() == 0) {
                this->m_42c = -this->m_42c;
            }
            this->m_42c += this->rotation_y;
            (this->roamingTimer)++;
            if (this->roamingTimer > 8) {
                this->roamingSubstate = 2;
            }
            dx = 16.0f * sin_table_lookup(this->m_42c);
            dz = 16.0f * cos_table_lookup(this->m_42c);
            this->m_410->position.x = this->position.x + dx;
            this->m_410->position.y = this->position.y;
            this->m_410->position.z = this->position.z + dz;
            ((TObjPlayer *)(this->m_410))->update_collisions();
            if (!(this->m_410->bodies->flags & 0x380000)) {
                dx *= 2.0f;
                dz *= 2.0f;
                if (this->enemy_probe_wall_ahead(dx, dz, 1.0f) == NULL) {
                    Vec v;
                    VecCopy(&v, &this->body_center);
                    v.x += dx;
                    v.z += dz;
                    if (csnVectorUnder(&v, (CsnGroup **)&this->m_120, 0x15) != NULL) {
                        this->roamingSubstate = 1;
                        this->requested_action = 0x12;
                        this->destination_direction.x = sin_table_lookup(this->m_42c);
                        this->destination_direction.y = 0.0f;
                        this->destination_direction.z = cos_table_lookup(this->m_42c);
                    }
                }
            }
            break;
        }
        case 1:
            if (this->get_flag_b4() != 0) {
                select_target();
                this->roamingSubstate = 2;
            }
            play_proximity_effect();
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, 1.8f);
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0xF00);
            advance_pose_turn(this->m_42c);
            this->check_collisions();
            break;
        }
        break;
    }
}

void TObjEneBm5Wolf::action(s32 arg1) {
    switch (arg1) {
    case 4:
        this->clear_intangible();
        this->set_field_378(7);
        this->requested_action = 0xB;
        this->roamingSubstate = 0;
        TObjEneBm5Wolf::find_pack_leader(this->m_3dc);
        return;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(7);
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        advance_pose_turn(this->rotation_y);
        if (this->is_passing_frame(10.0f) != 0) {
            play_sound_effect(this->remap_sound_for_area(0x3AA1A), &this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x100);
        }
        this->roamingSubstate = (this->roamingSubstate + 1);
        if (this->roamingSubstate == 0x1E) {
            apply_mourning_zalure();
        } else if (this->roamingSubstate == 0x28) {
            apply_mourning_jellen();
        }
        this->check_collisions();
        break;
    }
}

void TObjEneBm5Wolf::hurt_state(s32 arg1) {
    switch (arg1) {
    case 4:
        this->clear_intangible();
        TBoss8Dragon__sub_800BB7D4(this, 0xF1);
        this->roamingTimer = 0;
        this->m_42c = 0;
        this->requested_action = 6;
        this->roamingSubstate = 0;
        if (this->referenceHp - this->hp < 0x14) {
            play_sound_effect(this->remap_sound_for_area(0x3AB1B), &this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x500);
        }
        this->set_active();
        break;
    case 3:
        if ((this->motion_flags) & 0x10) {
            switch (this->next_mode) {
            case 11:
                this->transition_enemy_state(0xD);
                break;
            case 2:
                this->transition_enemy_state(7);
                break;
            default:
                this->transition_enemy_state(this->next_mode);
                break;
            }
        }
        break;
    case 0: {
        Vec v;
        this->advance_animation();
        VecCopy(&v, (const Vec *)&this->x_speed);
        {
        f32 c = normalize_vector_xz(&v);
        this->move_with_wall_slide_on_ground(v.x, v.z, c);
        }
        if (this->roamingSubstate == 0) {
            this->x_speed *= 0.5f;
            this->m_310 *= 0.5f;
        } else {
            this->x_speed *= 0.9f;
            this->m_310 *= 0.9f;
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0x300);
            this->rotation_y = (s16) this->rotation_y;
            if (this->is_passing_frame(22.0f) != 0) {
                spawn_recoil_dust__14TObjEneBm5WolfFiPv(this, &v);
            }
        }
        this->check_collisions();
        break;
    }
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

void TObjEneBm5Wolf::update_dying_state(s32 arg1) {
    s32 *tgt;
    TObjEneBm5WolfListNode *n;
    TObjEneBm5Wolf *e;
    f32 k;
    Vec pos;
    Vec vel;
    f32 c;
    tgt = &this->m_42c;
    switch (arg1) {
    case 4:
        this->clear_intangible();
        this->refresh_and_send_entity_flags();
        play_sound_effect(this->remap_sound_for_area(0x3AD1D), &this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        if (select_death_direction(tgt) == 0) {
            this->requested_action = 0xF;
        } else {
            this->requested_action = 0xE;
        }
        TBoss8Dragon__sub_800BB7D4(this, 0xF1);
        this->roamingSubstate = 0;
        this->stoppingDistance = calc_death_slide_speed(this->action_table[9].speed);
        this->wall_reach = this->m_43c = 0.0f;
        if (this->m_3d8 != 0) {
            k = 50.0f;
            for (n = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__pack_member_list)->head; n != NULL; n = n->next) {
                e = play_sound__14TObjEneBm5WolfFPv(n);
                if (e != NULL && e->m_3dc == this->m_3dc) {
                    ((TObjEneBm5Wolf *)e)->schedule_pack_reaction((s32)(k * this->random_ratio()) + 0x14, this->attacker_id);
                }
            }
        }
        this->set_active();
        break;
    case 3:
        if (this->roamingSubstate == 2) {
            this->transition_enemy_state(0x11);
        }
        break;
    case 1:
        break;
    case 0:
        switch (this->roamingSubstate) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->roamingSubstate = 1;
                pos.y = 0.0f;
                if (this->requested_action == 0xE) {
                    pos.x = 12.0f;
                    pos.z = -10.0f;
                } else {
                    pos.x = -12.0f;
                    pos.z = -10.0f;
                }
                rotate_xz_pair_by_angle(&pos.x, &pos.z, this->rotation_y);
                vec3_add_to(&pos, &this->position);
                TObjPlayer::spawn_dead_spot_type2((saddr)&pos, 0x32);
                ((TObjPlayer *)(&pos))->spawn_effect_at_ground(0x46);
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, *tgt, 0x300);
            this->rotation_y = (s16)this->rotation_y;
            if (this->wall_reach < 28.0f) {
                this->wall_reach = this->wall_reach + this->stoppingDistance;
            }
            VecCopy(&vel, (const Vec *)&this->x_speed);
            c = normalize_vector_xz(&vel);
            this->move_clamped_on_ground(vel.x, vel.z, c);
            if (this->is_passing_frame(22.0f) != 0) {
                spawn_recoil_dust__14TObjEneBm5WolfFiPv(this, &vel);
            }
            this->x_speed *= 0.8f;
            this->m_310 *= 0.8f;
            advance_pose_turn(this->rotation_y);
            this->update_body_colliders();
            break;
        case 1:
            this->position.y -= 0.1f;
            this->m_43c += 0.1f;
            if (this->m_43c > 20.0f) {
                this->roamingSubstate = 2;
            }
            break;
        }
        break;
    case 5:
        this->clear_field_388();
        break;
    }
}

void TObjEneBm5Wolf::despawn_state(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction();
        break;
    }
}

void TObjEneBm5Wolf::advance_spawn_timer(NJS_OBJECT *) {
    if (((s32) TObjEneBm5Wolf__spawn_timer >= 0x16) && ((s32) TObjEneBm5Wolf__spawn_timer < 0x18)) {
        rotate_matrix_y(0, TObjEneBm5Wolf__data_805D5128);
    }
    TObjEneBm5Wolf__spawn_timer += 1;
}

void TObjEneBm5Wolf::render() {
    s32 rot[3];
    s32 var_r31;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_debug();
        return;
    }
    if (!(this->m_408 & 2) && ((s16) this->mode != 0x11)) {
        if (TObjEneDD::is_main_phase_15() != 0) {
            var_r31 = this->classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 20.0f);
        } else if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
            var_r31 = 1;
        } else {
            var_r31 = 0;
        }
        if (var_r31 != 0) {
            if ((s16) this->mode != 0x10) {
                direction_to_rotation_xz((u8 *)&this->ground_normal, &rot[0], &rot[2]);
                push_matrix();
                post_translate_matrix(&this->position);
                translate_matrix(0, 0.0f, 0.3f, 0.0f);
                rotate_matrix_z(0, rot[2]);
                rotate_matrix_x(0, rot[0]);
                rotate_matrix_y(0, this->rotation_y);
                translate_matrix(0, 0.0f, 0.0f, -10.0f);
                scale_matrix(0, 1.2f, 1.0f, 3.0f);
                rotate_matrix_x(0, -0x4000);
                draw_blob_shadow(0);
                pop_matrix();
            }
            this->update_secondary_light();
            TObjFish::set_global_param(this->texlist);
            push_matrix();
            post_translate_matrix(&this->position);
            rotate_matrix_y(0, this->rotation_y);
            translate_matrix(0, 0.0f, 0.0f, -10.0f);
            if (this->m_408 & 4) {
                translate_matrix(0, 0.0f, this->m_40c, 0.0f);
            }
            TObjEneBm5Wolf__spawn_timer = 0;
            TObjEneBm5Wolf__data_805D5128 = -(this->turnOffset / 2);
            set_chunk_model_node_callback(TObjEneBm5Wolf::advance_spawn_timer);
            TObjEneDD::clear_global_flag_400();
            TObjPlayer::toggle_particle_effect();
            if (var_r31 == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            set_chunk_model_node_callback(NULL);
            pop_matrix();
            this->update_primary_light();
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneBm5Wolf::update_state() {
    s32 old_subtype;

    if (this->get_target_info() != 0) {
        old_subtype = this->m_3d8;
        this->select_subtype();
        if (old_subtype != this->m_3d8) {
            if (old_subtype != 0) {
                this->update_default();
            } else {
                this->apply_global_to_position();
            }
        }
        this->update_collision_center();
    }
}
#pragma push
#pragma opt_common_subs off
#pragma pool_data off
void TObjEneBm5Wolf::render_debug() {
    f32 frame;
    s32 idx;
    u32 n;
    AnimationMotion *motion;
    TObjEneBm5Wolf *leader;

    if (this->get_target_info() != 0) {
        debug_printf_at(pack_debug_text_position(0, 0), "GROUP:%2d", this->m_3dc);
        if (this->m_3d8 != 0) {
            debug_printf_at(pack_debug_text_position(0, 1), "L/M:LEADER");
        } else {
            debug_printf_at(pack_debug_text_position(0, 1), "L/M:MEMBER");
        }
    }
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        this->draw_ground_shadow(0, 0);
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix(&this->position);
        rotate_matrix_y(0, this->rotation_y);
        idx = (s32) this->parameters[3];
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x13) {
            idx = 0x12;
        }
        motion = this->motion_list[this->action_table[idx].motion].motion;
        frame = this->parameters[4];
        if (frame < 0.0f) {
            frame = 0.0f;
        } else {
            n = motion->frameCount;
            if (frame > (n - 1)) {
                frame = (f32) n;
            }
        }
        translate_matrix(0, 0.0f, 0.0f, -10.0f);
        TObjPlayer::toggle_particle_effect();
        set_motion_packed_rotation();
        draw_model_motion(this->model, motion, frame);
        clear_motion_packed_rotation();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    leader = TObjEneBm5Wolf::find_pack_leader(this->m_3dc);
    if (leader != 0) {
        debug_draw_line(&this->body_center, &leader->body_center, 0xFFC0C0C0, 0xFF6060FF);
        return;
    }
    {
    Vec v;
    VecCopy(&v, &this->body_center);
    v.y += 50.0f;
    debug_draw_line(&this->body_center, &v, 0xFFC0C0C0, 0xFF6060FF);
    }
}
#pragma pop
void TObjEneBm3FlyNest::render_shadows() {  }
