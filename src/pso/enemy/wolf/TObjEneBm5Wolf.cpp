#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/math/FloatRounding.h"
#include "pso/npc/TObjNpcEnemy.h"
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
#include "pso/object/ambient/TObjCGrass.h"
#include "pso/render/BlobShadow.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjBase.h"
extern "C" {
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

static const NpcAnimationBinding bm5_wolf_spawn_descriptor = { NULL, wolf_action_table, 0, 1, 19 };

__declspec(section ".data") player_stats *TObjEneBm5Wolf__stat_params[2];
__declspec(section ".data") AttackParams *wolf_stat_handle_a_table[2];
__declspec(section ".data") ActorParamBlock *wolf_stat_handle_b_table[2];
__declspec(section ".data") s32 wolf_param_table[2];
s32 TObjEneBm5Wolf__render_node_index;
s32 TObjEneBm5Wolf__render_joint_y_rotation;
}
#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"

#pragma defer_codegen on
#pragma push
#pragma fp_contract on

struct Globals_800B8A40 {
    u8 pad[0x2c];
    u8 chain0[0xc];
    TObjEneBm5WolfList list0;
    u8 chain1[0xc];
    TObjEneBm5WolfList list1;
};
extern "C" {
Vec lbl_80500B60;
u32 lbl_80500B6C[3];
u32 TObjEneBm5Wolf__pack_member_list[5];
u32 TObjEneBm5Wolf__instance_list[3];
void __register_global_object(void *obj, void *dtor, void *chain);
void __dt__18TObjEneBm5WolfListFv();
}

__declspec(section ".ctors") static void *const __sinit_TObjEneBm5Wolf_cpp_ref = (void *)TObjEneBm5Wolf::register_global_objects;

s32 TObjEneBm5Wolf::get_group_id() { return this->group_id; }

s32 actor_rand_int(saddr actor, s32 range) {
    return (s32) ((f32) range * ((TObjChara *)actor)->random_ratio());
}

void TObjEneBm5Wolf::register_global_objects() {
    Globals_800B8A40 *g = (Globals_800B8A40 *)TObjEneBm5Wolf__stat_params;
    __register_global_object(g->list0.reset(), (void *)__dt__18TObjEneBm5WolfListFv, g->chain0);
    __register_global_object(g->list1.reset(), (void *)__dt__18TObjEneBm5WolfListFv, g->chain1);
}

TObjEneBm5WolfNode::TObjEneBm5WolfNode() {
    prev = NULL;
    next = NULL;
    entity_id = 0xFFFF;
}

TObjEneBm5WolfNode::~TObjEneBm5WolfNode() {}

void TObjEneBm5WolfNode::unlink_from(TObjEneBm5WolfNode **head, TObjEneBm5WolfNode **tail) {
    if (prev != NULL) {
        prev->next = next;
    } else {
        *head = next;
    }
    if (next != NULL) {
        next->prev = prev;
        return;
    }
    *tail = prev;
}

void TObjEneBm5WolfNode::append_to(TObjEneBm5WolfNode **head, TObjEneBm5WolfNode **tail) {
    if (*tail != NULL) {
        prev = *tail;
        (*tail)->next = this;
    } else {
        prev = NULL;
        *head = this;
    }
    *tail = this;
    next = NULL;
}

void TObjEneBm5WolfNode::set_owner(TObjEneBm5Wolf *owner) {
    entity_id = owner->get_entity_id();
}

TObjEneBm5Wolf *TObjEneBm5WolfNode::get_owner() {
    return (TObjEneBm5Wolf *)find_entity_by_id(entity_id);
}

TObjEneBm5WolfList *TObjEneBm5WolfList::reset() { clear(); return this; }

TObjEneBm5WolfList::~TObjEneBm5WolfList() {}

void TObjEneBm5WolfList::clear() {
    head = NULL;
    tail = NULL;
}

void TObjEneBm5WolfList::append(TObjEneBm5WolfNode *node) {
    node->append_to(&head, &tail);
}

void TObjEneBm5WolfList::remove(TObjEneBm5WolfNode *node) {
    node->unlink_from(&head, &tail);
}

void TObjEneBm5Wolf::load_resources() {
    s32 i;

    if (TObjEneDD::check_v2_mode() != 0) {
        TObjEneBm5Wolf__bml_resource = load_enemy_bml_resource_named(&bm_ene_bm5_wolf_resource_descriptor, "bm_ene_bm5_wolf_a.bml");
    } else {
        TObjEneBm5Wolf__bml_resource = load_enemy_bml_resource(&bm_ene_bm5_wolf_resource_descriptor);
    }
    ((TObjEneBm5WolfList *)TObjEneBm5Wolf__pack_member_list)->clear();
    ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->clear();
    TObjEneBm5Wolf__render_node_index = 0;
    TObjEneBm5Wolf__render_joint_y_rotation = 0;
    lbl_80500B60.x = 0.0f;
    lbl_80500B60.y = 0.0f;
    lbl_80500B60.z = 0.0f;
    for (i = 0; i < 2; i++) {
        TObjEneBm5Wolf__stat_params[i] = TLobby::register_boss(wolf_base_stat_ids[i]);
        wolf_stat_handle_a_table[i] = TLobby::dispatch_shared_handler_b(wolf_attack_stat_ids[i]);
        wolf_stat_handle_b_table[i] = TLobby::register_object(wolf_resist_stat_ids[i]);
        wolf_param_table[i] = (saddr)TLobby::dispatch_shared_handler_a(wolf_param_ids[i]);
    }
    {
    NpcAnimationBinding sp = bm5_wolf_spawn_descriptor;
    sp.motions = TObjEneBm5Wolf__bml_resource->motions;
    TObjNpcEnemy::register_animated_chunk(9, TObjEneBm5Wolf__bml_resource->models[1].model, TObjEneBm5Wolf__bml_resource->models[0].texlist, &sp, TObjEneBm5Wolf__collider_params[0].radius, 0.0f);
    TObjNpcEnemy::register_animated_chunk(10, TObjEneBm5Wolf__bml_resource->models[0].model, TObjEneBm5Wolf__bml_resource->models[0].texlist, &sp, TObjEneBm5Wolf__collider_params[0].radius, 0.0f);
    }
}

// dead-stripped: only its literals survive. The int-to-float double (.rodata 0x8043B5B8) is pooled before
// load_resources' file name, but its only live user actor_rand_int is compiled after load_resources
// (defer_codegen runs this file bottom-up). Minimal body after actor_rand_int's conversion; name inferred.
static f32 actor_rand_float(saddr actor, s32 range) {
    return (f32)range * ((TObjChara *)actor)->random_ratio();
}

void *TObjEneBm5Wolf::create(void *set_data) {
    return new TObjEneBm5Wolf(tl_04, set_data);
}

void TObjEneBm5Wolf::release_global_805D5120() {
    if (TObjEneBm5Wolf__bml_resource != 0) {
        delete TObjEneBm5Wolf__bml_resource;
        TObjEneBm5Wolf__bml_resource = 0;
    }
}

void TObjEneBm5Wolf::add_to_pack_member_list() {
    ((TObjEneBm5WolfList *)TObjEneBm5Wolf__pack_member_list)->append(&this->pack_node);
}

void TObjEneBm5Wolf::remove_from_pack_member_list() {
    ((TObjEneBm5WolfList *)TObjEneBm5Wolf__pack_member_list)->remove(&this->pack_node);
}

void TObjEneBm5Wolf::add_to_instance_list() {
    ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->append(&this->instance_node);
}

void TObjEneBm5Wolf::remove_from_instance_list() {
    ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->remove(&this->instance_node);
}

TObjEneBm5Wolf *TObjEneBm5Wolf::find_pack_leader(s32 id) {
    TObjEneBm5WolfNode *n;
    for (n = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->head; n != 0; n = n->next) {
        TObjEneBm5Wolf *w = n->get_owner();
        if (w != 0 && w->group_id == id) {
            return w;
        }
    }
    return 0;
}
#pragma push
#pragma bool off
TObjEneBm5Wolf::TObjEneBm5Wolf(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    s32 n;
    m_name = bm5_wolf_class_name;
    invoke_initialization_hook(set_data);
    select_subtype();
    init_position_vectors();
    init_model(TObjEneBm5Wolf__collider_params, 1);
    set_action_table(wolf_action_table);
    set_motion_list(TObjEneBm5Wolf__bml_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    n = is_leader;
    reset_hp(TObjEneBm5Wolf__stat_params[n != 0], wolf_stat_handle_a_table[n != 0], wolf_stat_handle_b_table[n != 0]);
    set_state_flag_1();
    movementParameters = bm5_wolf_decision_row;
    if (is_leader != 0) {
        initialize_enemy_state(8);
    } else {
        initialize_enemy_state(7);
    }
    wall_reach = 15.0f;
    enemy_init_acquire_period(0x14);
    enemy_init_validate_period(0x14);
    pack_node.set_owner(this);
    add_to_pack_member_list();
    if (is_leader != 0) {
        instance_node.set_owner(this);
        add_to_instance_list();
    }
    leader_id = 0xFFFF;
    turn_offset = 0;
    VecCopy(&spawn_position, &position);
    VecCopy(&group_anchor, &position);
    desired_speed = 0.0f;
    current_speed = 0.0f;
    status_flags = 0;
    jump_height = 0.0f;
    attack_collider = new TObjCollidable(NULL);
    init_collision_body_parts(attack_collider, &TObjEneBm5Wolf__collider_params[1], 1);
    reaction_delay = 0;
    reaction_attacker_id = 0xFFFF;
    set_colliders_contact_low();
    substate = 0;
    state_timer = 0;
    random_phase = 0;
    circle_shift_timer = 0;
    target_heading = 0;
    base_heading = 0;
    stopping_distance = 0.0f;
    circle_radius = 0.0f;
    sink_depth = 0.0f;
    pad_440 = 0.0f;
    work_point.x = 0.0f;
    work_point.y = 0.0f;
    work_point.z = 0.0f;
    work_vector.x = 0.0f;
    work_vector.y = 0.0f;
    work_vector.z = 0.0f;
    pad_45c = 0.0f;
    pad_460 = 0.0f;
    pad_464 = 0.0f;
    near_target = 0;
    update_collision_center();
    update_body_colliders();
    transform_part_positions();
    mode = 0;
    dispatch_action(mode, 4);
}
#pragma pop
TObjEneBm5Wolf::~TObjEneBm5Wolf() {
    if (attack_collider != NULL) {
        free_collision_body_parts(attack_collider);
        delete attack_collider;
        attack_collider = NULL;
    }
    remove_from_pack_member_list();
    if (is_leader != 0) {
        remove_from_instance_list();
    }
    free_collision_body_parts(this);
}

void TObjEneBm5Wolf::run_task() {
    s16 cur_mode;
    s16 idle_mode;
    s32 delay;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_state();
        return;
    }
    TObject *entity = (TObject *)find_entity_by_id((this->leader_id));
    if (entity != NULL) {
        entity->all_parents_unqueued_for_destruction();
    }
    if (this->update_status_effects() != 4) {
        delay = this->reaction_delay;
        if (delay != 0) {
            this->reaction_delay = (delay - 1);
            if (this->reaction_delay == 0) {
                cur_mode = this->mode;
                if ((cur_mode != 0x10) && (cur_mode != 0x11)) {
                    this->transition_enemy_state(0xE);
                }
            }
        }
        this->update_action_state();
    } else {
        idle_mode = this->mode;
        if (idle_mode == 0) {
            this->update_action_state();
        } else if (idle_mode == 1) {
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
    s16 cur_mode;

    cur_mode = this->mode;
    if ((cur_mode != 0x10) && (cur_mode != 0x11)) {
        this->transition_enemy_state(0x10);
    }
}

void TObjEneBm5Wolf::run_hit_reaction() { if (this->mode != 15) { this->transition_enemy_state(15); } }

void TObjEneBm5Wolf::run_miss_reaction() {  }

void TObjEneBm5Wolf::update_collision_center() {

    this->body_center.x = (f32) this->position.x;
    this->body_center.y = (f32) ((this->jump_height) + (10.0f + this->position.y));
    this->body_center.z = (f32) this->position.z;
    VecCopy(&this->center, &this->body_center);
}

void TObjEneBm5Wolf::update_body_colliders() {
    this->bodies->offset.y = 10.0f + this->jump_height;
}

void TObjEneBm5Wolf::select_subtype() {
    this->group_id = (s32) floor_to_float(this->parameters[0]);
    if (this->parameters[1] >= 1.0f) {
        this->is_leader = 1;
        this->model = (void *)TObjEneBm5Wolf__bml_resource->models[1].model;
        this->texlist = TObjEneBm5Wolf__bml_resource->models[0].texlist;
        return;
    }
    this->is_leader = 0;
    this->model = (void *)TObjEneBm5Wolf__bml_resource->models[0].model;
    this->texlist = TObjEneBm5Wolf__bml_resource->models[0].texlist;
}

void TObjEneBm5Wolf::advance_pose_turn(s32 target) {
    s32 d;
    d = angle_diff_s16(this->rotation_y, target);
    if (d > 0x4000) {
        d = 0x4000;
    } else if (d < -0x4000) {
        d = -0x4000;
    }
    if (this->turn_offset * d >= 0) {
        this->turn_offset = approach_angle_limited(this->turn_offset, d, 0x800);
    } else if (this->turn_offset * angle_diff_s16(this->turn_offset, d) >= 0) {
        if (this->turn_offset >= 0) {
            this->turn_offset -= 0x800;
        } else {
            this->turn_offset += 0x800;
        }
    } else {
        this->turn_offset = approach_angle_limited(this->turn_offset, d, 0x800);
    }
    this->turn_offset = (s16)this->turn_offset;
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
    f32 radius;
    f32 wall_distance;
    CsnHit *hit;
    dir.x = this->position.x - this->group_anchor.x;
    dir.y = 0.0f;
    dir.z = this->position.z - this->group_anchor.z;
    normalize_vector_xz(&dir);
    rotate_xz_pair_by_angle(&dir.x, &dir.z, (s32) (32768.0f * this->random_ratio()) + 0x4000);
    radius = 120.0f * this->rand_range(0.3f, 1.0f);
    this->destination.x = (f32) ((dir.x * radius) + this->group_anchor.x);
    this->destination.z = (f32) ((dir.z * radius) + this->group_anchor.z);
    hit = csnVector(&this->body_center, &this->destination, 0x88E0U);
    if (hit != NULL) {
        dir.x = hit->contact->point.x - this->position.x;
        dir.z = hit->contact->point.z - this->position.z;
        wall_distance = normalize_vector_xz(&dir) - 25.0f;
        this->destination.x = (f32) ((dir.x * wall_distance) + this->position.x);
        this->destination.z = (f32) ((dir.z * wall_distance) + this->position.z);
    }
}

void TObjEneBm5Wolf::approach_target(f32 step) {
    f32 desired;
    f32 current;

    current = this->current_speed;
    desired = this->desired_speed;
    if (current != desired) {
        if (current > desired) {
            this->current_speed = (f32) (current - step);
            if (this->current_speed < this->desired_speed) {
                this->current_speed = this->desired_speed;
            }
        } else {
            this->current_speed = (f32) (current + step);
            if (this->current_speed > this->desired_speed) {
                this->current_speed = this->desired_speed;
            }
        }
    }
}

void TObjEneBm5Wolf::calc_rotated_vector(s32 angle, Vec *out, s32 *heading) {
    f32 c;
    f32 s;

    s = sin_table_lookup(angle);
    c = cos_table_lookup(angle);
    out->z = (f32) ((c * destination_direction.z) - (s * destination_direction.x));
    out->x = (f32) ((s * destination_direction.z) + (c * destination_direction.x));
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
    if (this->is_leader != 0) {
        this->transition_enemy_state(6);
        return;
    }
    this->transition_enemy_state(5);
}
#pragma push
#pragma fp_contract on
f32 TObjEneBm5Wolf::calc_circle_offset(Vec *target, Vec *out) {
    f32 dx;
    f32 dz;
    dz = position.z - target->z;
    dx = position.x - target->x;
    f32 distSq = dx * dx + dz * dz;
    f32 inv = 1.0f / ((f32 (*)(f32, f32))newton_sqrtf)(distSq, position.x);
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
    VecCopy(&v, (const Vec *)&this->velocity.x);
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

void TObjEneBm5Wolf::set_attack_flag() { this->status_flags |= 0x1; }

s32 TObjEneBm5Wolf::select_target() {
    if (this->is_leader != 0) {
        return this->select_and_apply_target(350.0f);
    }
    return this->select_and_apply_target(250.0f);
}

s32 TObjEneBm5Wolf::play_variant_sound() {
    if (this->is_leader != 0) {
        return this->update_linked_position(350.0f);
    }
    return this->update_linked_position(250.0f);
}
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::spawn_recoil_dust(Vec *dir) {
    Vec pos;
    VecCopy(&pos, &position);
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
    f32 dir_x;
    f32 dir_z;
    f32 side_offset;
    if (is_target_unobstructed_from((TObjEneDD *)this, (TObjChara *)this->current_target) != 0) {
        this->enemy_copy_target_destination();
        this->update_velocity();
        if (((s32)get_flag_bit0()) != 0) {
            side_offset = 7.0f;
        } else {
            side_offset = -7.0f;
        }
        dir_z = this->destination_direction.z;
        dir_x = this->destination_direction.x;
        this->destination.x = (f32) (this->destination.x + ((2.0f * dir_x) + (dir_z * side_offset)));
        this->destination.z = (f32) (this->destination.z + ((2.0f * dir_z) - (dir_x * side_offset)));
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
void TObjEneBm5Wolf::schedule_pack_reaction(s32 delay, u16 attacker_id) {
    this->reaction_delay = delay;
    this->reaction_attacker_id = attacker_id;
}

void TObjEneBm5Wolf::apply_mourning_zalure() {
    TObjEneBm5Wolf *target = (TObjEneBm5Wolf *)find_entity_by_id(this->leader_id);
    if (target != 0) {
        DirectAttackPayload attack;
        attack.kind = 0xc;
        attack.power = 1.0f;
        this->receive_direct_attack(target, attack, 0, -1, -1);
    }
}

void TObjEneBm5Wolf::apply_mourning_jellen() {
    TObjEneBm5Wolf *target = (TObjEneBm5Wolf *)find_entity_by_id(this->leader_id);
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
        this->empty_state(event);
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

void TObjEneBm5Wolf::anchor_state(s32 event) {
    TObjEneBm5Wolf *leader;

    switch (event) {
    case 4:
        this->state_timer = 0;
        this->set_field_378(0);
        this->set_intangible();
        this->status_flags = (s32) (this->status_flags | 2);
        return;
    case 3:
        if (this->state_timer > 0) {
            this->transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        leader = TObjEneBm5Wolf::find_pack_leader(this->group_id);
        if (leader != 0) {
            this->leader_id = leader->get_entity_id();
        }
        if ((this->is_leader != 0) || (leader == 0)) {
            VecCopy(&this->group_anchor, (const Vec *)&this->spawn_position);
        } else {
            VecCopy(&this->group_anchor, leader->get_spawn_position());
        }
        this->state_timer = (this->state_timer + 1);
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::appearing_state(s32 event) {
    Vec *home = &this->work_point;
    f32 t;

    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->set_field_378(7);
        this->set_intangible();
        this->status_flags &= ~3;
        this->status_flags |= 4;
        this->enemy_clear_target();
        this->turn_offset = 0;
        VecCopy(home, &this->position);
        this->position.x -= 100.0f * sin_table_lookup(this->rotation_y);
        this->position.z -= 100.0f * cos_table_lookup(this->rotation_y);
        this->stopping_distance = 3.3333333f;
        this->jump_height = 0.0f;
        this->circle_radius = this->position.y;
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
                this->jump_height = (this->circle_radius + (-0.08888889f * (t * t) + 20.0f)) - this->position.y;
            } else {
                this->stopping_distance *= 0.8f;
            }
            this->position.x += this->stopping_distance * sin_table_lookup(this->rotation_y);
            this->position.z += this->stopping_distance * cos_table_lookup(this->rotation_y);
        }
        this->update_ground_contact();
        this->update_body_colliders();
        break;
    case 5:
        this->jump_height = 0.0f;
        break;
    }
}
#pragma pop
void TObjEneBm5Wolf::sleeping_state(s32 event) {
  TObjEneBm5Wolf *entity;
  switch (event)
  {
    case 4:
      this->requested_action = 4;
      this->set_field_378(2);
      (this->set_intangible());
      this->enemy_clear_target();
      this->turn_offset = 0;
      this->status_flags = (s32) ((this->status_flags) & 0xFFFFFFFE);
      return;
    case 3:
      if ((this->status_flags) & 1)
    {
      this->transition_enemy_state(4);
      return;
      return;
    }
      if (this->current_target != 0)
    {
      this->enemy_copy_target_destination();
      set_anim_state();
      entity = (TObjEneBm5Wolf *)find_entity_by_id(this->leader_id);
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
      this->status_flags = (s32) ((this->status_flags) & 0xFFFFFFFE);
      break;
  }
}

void TObjEneBm5Wolf::alerted_state(s32 event) {
  s32 new_var;
  switch (event)
  {
    case 4:
      this->requested_action = 4;
      this->set_field_378(4);
      (this->set_intangible());
      new_var = (s32) (((s32) (60.0f * this->random_ratio())) + 0xA);
      this->substate = new_var;
      return;
    case 3:
      if ((this->substate) <= 0)
    {
      set_anim_state();
    }
    case 5:
      return;
      return;
    case 0:
      this->substate = (s32) ((this->substate) - 1);
      play_variant_sound();
      this->advance_animation();
      (this->update_ground_contact());
      (this->update_body_colliders());
      break;
  }
}

void TObjEneBm5Wolf::standing_state(s32 event) {
  switch (event)
  {
    case 4:
      this->requested_action = 5;
      this->set_field_378(7);
      (this->set_intangible());
      this->substate = 0;
      return;
    case 3:
      if ((this->substate) > 0x3C)
    {
      this->transition_enemy_state(7);
    }
    case 5:
      return;
    case 0:
      this->substate = (s32) ((this->substate) + 1);
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

void TObjEneBm5Wolf::howling_state(s32 event) {
    TObjEneBm5WolfNode *p;
    TObjEneBm5Wolf *r;
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        set_field_378(7);
        this->set_intangible();
        this->substate = 0;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(7);
        }
        break;
    case 5:
        break;
    case 0:
        (this->substate)++;
        advance_animation();
        if (this->requested_action == 0x10) {
            is_passing_frame(7.0f);
        } else if (this->requested_action == 0xB && is_passing_frame(9.0f) != 0) {
            play_sound_effect(this->remap_sound_for_area(0x3A819), &this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (this->substate == 0x3C) {
            for (p = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__instance_list)->head; p != NULL; p = p->next) {
                r = p->get_owner();
                if (this->group_id == ((TObjEneBm5Wolf *)r)->get_group_id()) {
                    r->set_attack_flag();
                }
            }
        }
        if (enemy_validate_retained_target(this) != 0) {
            if (this->requested_action == 0x10) {
                this->turn_pose_to_target();
            } else {
                this->turn_offset = 0;
            }
        } else {
            play_variant_sound();
        }
        this->update_ground_contact();
        this->update_body_colliders();
        break;
    }
}

void TObjEneBm5Wolf::empty_state(s32 event) {}
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::roaming_state(int event) {
    f32 dz;
    f32 walk_speed;
    f32 stop_speed;
    f32 radius;
    f32 dx;
    f32 square;
    s32 angle;
    TObjChara *target;
    switch (event) {
    case 4:
        this->requested_action = 1;
        set_field_378(7);
        this->clear_intangible();
        this->state_timer = 0;
        this->substate = 0;
        this->random_phase = actor_rand_int((saddr)this, 0x14);
        this->near_target = 0;
        angle = (s32) (65536.0f * this->random_ratio());
        radius = 120.0f * this->random_ratio();
        this->destination.x = (f32) ((radius * sin_table_lookup(angle)) + this->group_anchor.x);
        this->destination.z = (f32) ((radius * cos_table_lookup(angle)) + this->group_anchor.z);
        this->desired_speed = (f32) ((0.7f * this->random_ratio()) + 0.3f);
        this->current_speed = (f32) (0.0f);
        this->stopping_distance = (f32) (2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desired_speed));
        this->update_velocity();
        return;
    case 3:
        if (this->near_target != 0) {
            set_state_by_timer();
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (play_variant_sound() != 0) {
            target = this->current_target;
            dx = target->position.x - this->position.x;
            dz = target->position.z - this->position.z;
            square = dx * dx;
            square = (dz * dz) + square;
            if (square < 22500.0f) {
                this->near_target = 1;
            }
            turn_pose_to_target();
        } else {
            advance_pose_turn(this->rotation_y);
        }
        switch (this->substate) {
        case 0:
            play_footsteps();
            this->update_velocity();
            approach_target(0.05f);
            this->state_timer = (this->state_timer + 1);
            if ((this->destination_distance < this->stopping_distance) || (this->state_timer > 0x64)) {
                this->substate = 1;
                this->desired_speed = (f32) (0.0f);
            } else if (((s32)has_move_failures(0x14)) != 0) {
                this->state_timer = 0;
                choose_roaming_destination();
                this->desired_speed = this->rand_range(0.3f, 1.0f);
                this->stopping_distance = (f32) (2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desired_speed));
            }
            this->play_speed = (f32) (1.1f * this->current_speed);
            walk_speed = this->current_speed;
            enemy_turn_and_move_on_ground(this, (s32)(512.0f * walk_speed), (f32)walk_speed);
            break;
        case 1:
            play_footsteps();
            this->update_velocity();
            approach_target(0.020000001f);
            if (this->current_speed <= 0.1f) {
                this->substate = 2;
                this->state_timer = (s32) this->rand_range(240.0f, 360.0f);
                this->requested_action = 0;
            }
            this->play_speed = (f32) (1.1f * this->current_speed);
            stop_speed = this->current_speed;
            enemy_turn_and_move_on_ground(this, (s32)(512.0f * stop_speed), (f32)stop_speed);
            break;
        case 2:
            this->requested_action = 0;
            this->state_timer = (this->state_timer - 1);
            if (this->state_timer <= 0) {
                choose_roaming_destination();
                this->desired_speed = this->rand_range(0.3f, 1.0f);
                this->current_speed = (f32) (0.0f);
                this->stopping_distance = (f32) (2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desired_speed));
                this->substate = 0;
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
void TObjEneBm5Wolf::chasing_state(s32 event) {
    f32 slowed_speed;
    f32 speed;
    switch (event) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(8);
        this->clear_intangible();
        this->desired_speed = (f32) (1.6f);
        this->substate = 0;
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
        if ((this->substate == 0) && (this->is_passing_frame(this->frame_count - 1.0f) != 0) && (this->destination_distance < 90.0f)) {
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
                this->current_speed *= 0.9f;
                this->play_speed = (f32) (0.8f * this->current_speed);
                slowed_speed = this->current_speed;
                enemy_turn_and_move_on_ground(this, (768.0f * slowed_speed), slowed_speed);
            } else {
                approach_target(0.1f);
                this->play_speed = (f32) (0.8f * this->current_speed);
                speed = this->current_speed;
                enemy_turn_and_move_on_ground(this, (768.0f * speed), speed);
            }
            turn_pose_to_target();
            this->check_collisions();
        }
        break;
    }
}

void TObjEneBm5Wolf::flanking_state(s32 event) {
    s32 *ang = &this->target_heading;
    Vec *dst = &this->work_point;
    Vec *src = &this->work_vector;
    switch (event) {
    case 4:
        this->requested_action = 3;
        set_field_378(9);
        this->clear_intangible();
        this->desired_speed = 2.0f;
        this->substate = 0;
        this->state_timer = 0;
        calc_rotated_vector(0x1C71, src, ang);
        VecCopy(dst, src);
        this->base_heading = *ang;
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
                if (this->state_timer == 0) {
                    this->state_timer = 1;
                    calc_rotated_vector(-0x1C71, src, ang);
                } else {
                    this->state_timer = 0;
                    calc_rotated_vector(0x1C71, src, ang);
                }
            }
            if (is_passing_frame(this->frame_count - 1.0f) != 0) {
                VecCopy(dst, src);
                this->base_heading = *ang;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, this->base_heading, 0x800);
            this->rotation_y = (s16)this->rotation_y;
            if (this->frame >= 15.0f) {
                this->current_speed *= 0.9f;
                this->play_speed = 0.5f * this->current_speed;
                this->move_with_wall_slide_on_ground(dst->x, dst->z, this->current_speed);
            } else {
                approach_target(1.0f);
                this->play_speed = 0.5f * this->current_speed;
                this->move_with_wall_slide_on_ground(dst->x, dst->z, this->current_speed);
            }
            this->turn_pose_to_target();
            this->check_collisions();
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::circling_state(s32 event) {
    Vec *b;
    Vec *a;
    f32 vx;
    f32 vz;
    a = &this->work_point;
    b = &this->work_vector;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(10);
        this->clear_intangible();
        this->desired_speed = 0.7f;
        this->substate = 0;
        this->state_timer = 0;
        this->random_phase = 0;
        this->circle_shift_timer = 0;
        this->target_heading = 0;
        this->stopping_distance = 0.0f;
        this->circle_radius = 0.0f;
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
        if (this->substate > 450) {
            this->substate = 0;
            if (this->random_ratio() < 0.5f) {
                this->transition_enemy_state(11);
            }
        } else if (this->substate > 45) {
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
            if (this->random_phase == 0) {
                Vec fwd;
                Vec to;
                this->random_phase = 1;
                VecCopy(a, &this->current_target->position);
                this->stopping_distance = calc_circle_offset(a, b);
                this->circle_radius = this->rand_range(50.0f, 80.0f);
                fwd.x = sin_table_lookup(this->rotation_y);
                fwd.y = 0.0f;
                fwd.z = cos_table_lookup(this->rotation_y);
                to.x = this->current_target->position.x - this->position.x;
                to.y = 0.0f;
                to.z = this->current_target->position.z - this->position.z;
                if (is_vec_xz_cross_negative(&fwd, &to) != 0) {
                    this->target_heading = -1;
                } else {
                    this->target_heading = 1;
                }
            }
            this->substate++;
            play_footsteps();
            if (this->circle_shift_timer > 0) {
                this->circle_shift_timer--;
                if (this->target_heading > 0) {
                    this->stopping_distance -= 0.5f;
                } else {
                    this->stopping_distance += 0.5f;
                }
            } else {
                f32 cur = this->stopping_distance;
                f32 tgt = this->circle_radius;
                f32 diff = cur - tgt;
                if (diff > 0.2f) {
                    this->stopping_distance = cur - 0.2f;
                } else if (diff < -0.2f) {
                    this->stopping_distance += 0.2f;
                } else {
                    this->stopping_distance = tgt;
                }
            }
            switch (this->random_phase) {
            case 1: {
                this->desired_speed = 0.7f;
                approach_target(0.12f);
                calc_circle_offset(a, b);
                if (this->target_heading >= 0) {
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
                this->move_with_wall_slide_on_ground(vx, vz, this->current_speed);
                if (this->has_move_failures(10) != 0) {
                    this->state_timer = 0;
                    this->random_phase = 2;
                }
                break;
            }
            case 2: {
                s32 ang;
                f32 sx;
                f32 cz;
                this->desired_speed = 0.5f;
                approach_target(0.12f);
                this->state_timer++;
                if (this->state_timer >= 40) {
                    ang = this->rotation_y;
                } else {
                    ang = this->rotation_y + (this->target_heading << 11);
                }
                sx = sin_table_lookup(ang);
                cz = cos_table_lookup(ang);
                if (this->has_move_failures(2) != 0) {
                    this->state_timer = 0;
                    this->set_active();
                } else {
                    this->clear_field_388();
                }
                this->move_with_wall_slide_on_ground(sx, cz, this->current_speed);
                if (this->state_timer >= 80) {
                    this->random_phase = 0;
                }
                break;
            }
            }
            this->rotation_y = approach_angle_limited(this->rotation_y,
                (s32)(RADIANS_TO_ANGLE * atan2_float(this->position.x - this->prev_position.x, this->position.z - this->prev_position.z)),
                0x200);
            this->rotation_y = (s16)this->rotation_y;
            this->play_speed = 1.1f * this->current_speed;
            this->turn_pose_to_target();
            this->check_collisions();
            if (this->bodies->flags & 0x380000) {
                this->circle_shift_timer = 20;
            }
        }
        break;
    case 5:
        this->clear_field_388();
        break;
    }
}

void TObjEneBm5Wolf::update_lunge(s32 event) {
    f32 t;
    f32 lunge_speed;
    switch (event) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->status_flags = (s32) (this->status_flags & 0xFFFFFFFD);
        this->status_flags = (this->status_flags | 4);
        this->substate = 0;
        this->state_timer = 0;
        this->target_heading = calc_lunge_aim();
        this->base_heading = 0;
        if (this->destination_distance > 40.0f) {
            this->destination_distance = 40.0f;
        }
        lunge_speed = this->destination_distance / 13.333333f;
        this->desired_speed = lunge_speed;
        this->current_speed = lunge_speed;
        this->near_target = 0;
        this->jump_height = (f32) (0.0f);
        this->stopping_distance = (f32) this->position.y;
        this->sink_depth = (f32) (20.0f);
        this->circle_radius = -0.08888889f;
        return;
    case 3:
        if (this->substate == 2) {
            this->transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (this->substate) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                if (this->near_target != 0) {
                    this->substate = 2;
                } else {
                    this->substate = 1;
                    this->state_timer = 0;
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
                this->near_target = 0;
                if (enemy_validate_retained_target(this) != 0) {
                    if (this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                        this->current_target->receive_physical_attack(this, 1.0f);
                        this->current_target->apply_knockback_from_attacker((u8 *)this, 7.0f);
                        this->near_target = 1;
                        if ((TObjEneDD::check_v2_mode() != 0) && (this->random_ratio() <= 0.1f)) {
                            if (this->is_leader != 0) {
                                TObjEneDD__sub_800BA378(this, this->current_target);
                            } else {
                                TObjEneDD::send_damage_message(this, this->current_target);
                            }
                        }
                    }
                }
            }
            approach_target((f32) (0.1f));
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_heading, 0x1000);
            this->rotation_y = (s32) (s16) this->rotation_y;
            advance_pose_turn(this->rotation_y);
            if (this->frame <= 30.0f) {
                this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->current_speed);
                t = this->frame - 15.0f;
                this->jump_height = (f32) ((this->stopping_distance + ((this->circle_radius * (t * t)) + 20.0f)) - this->position.y);
            } else {
                if (this->near_target == 0) {
                    this->current_speed *= 0.8f;
                    this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->current_speed);
                }
                this->jump_height = (f32) (0.0f);
            }
            break;
        case 1:
            this->advance_animation();
            this->state_timer = (this->state_timer + 1);
            if (this->state_timer >= 0xA) {
                this->substate = 2;
            }
            advance_pose_turn(this->rotation_y);
            if (this->near_target == 0) {
                this->current_speed *= 0.8f;
                this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->current_speed);
            }
            break;
        }
        this->check_collisions();
        return;
    case 5:
        this->jump_height = (f32) (0.0f);
        break;
    }
}

void TObjEneBm5Wolf::returning_state(s32 event) {
    Vec *home = &this->work_vector;
    f32 lim = this->stopping_distance;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(0xC);
        this->clear_intangible();
        this->desired_speed = 1.6f;
        this->substate = 0;
        VecCopy(home, &this->position);
        TObjBoss2Tunnel::calc_scaled_value(0x200, 1.6f);
        this->base_heading = this->rotation_y;
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
                this->target_heading = 0x5000;
            } else {
                this->target_heading = -0x5000;
            }
        } else if (this->random_ratio() < 0.5f) {
            this->target_heading = 0x5000;
        } else {
            this->target_heading = -0x5000;
        }
        this->target_heading = this->target_heading + this->base_heading;
        break;
    case 3:
        if (this->current_target == NULL || this->substate > 0x96) {
            this->transition_enemy_state(7);
        } else if (this->destination_distance < lim) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        this->substate++;
        this->advance_animation();
        if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
            play_footsteps();
            this->target_heading = approach_angle_limited(this->target_heading, this->base_heading, 0x100);
            this->destination.x = 90.0f * sin_table_lookup(this->target_heading) + home->x;
            this->destination.z = 90.0f * cos_table_lookup(this->target_heading) + home->z;
            this->update_velocity();
            approach_target(0.2f);
            this->play_speed = 1.1f * this->current_speed;
            enemy_turn_and_move_on_ground(this, 0x500, this->current_speed);
            this->turn_pose_to_target();
            this->check_collisions();
        }
        break;
    }
}
#pragma pop
void TObjEneBm5Wolf::repositioning_state(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->substate = 0;
        this->target_heading = 0;
        this->state_timer = 0;
        return;
    case 3:
        if (this->substate == 2) {
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
        switch (this->substate) {
        case 0: {
            f32 dx;
            f32 dz;
            this->target_heading = ((this->state_timer >> 1) << 0xC) + 0x1800;
            if (this->state_timer & 1) {
                this->target_heading = -this->target_heading;
            }
            if (get_flag_bit0() == 0) {
                this->target_heading = -this->target_heading;
            }
            this->target_heading += this->rotation_y;
            (this->state_timer)++;
            if (this->state_timer > 8) {
                this->substate = 2;
            }
            dx = 16.0f * sin_table_lookup(this->target_heading);
            dz = 16.0f * cos_table_lookup(this->target_heading);
            this->attack_collider->position.x = this->position.x + dx;
            this->attack_collider->position.y = this->position.y;
            this->attack_collider->position.z = this->position.z + dz;
            this->attack_collider->update_collisions();
            if (!(this->attack_collider->bodies->flags & 0x380000)) {
                dx *= 2.0f;
                dz *= 2.0f;
                if (this->enemy_probe_wall_ahead(dx, dz, 1.0f) == NULL) {
                    Vec v;
                    VecCopy(&v, &this->body_center);
                    v.x += dx;
                    v.z += dz;
                    if (csnVectorUnder(&v, this->ground_candidates.groups, 0x15) != NULL) {
                        this->substate = 1;
                        this->requested_action = 0x12;
                        this->destination_direction.x = sin_table_lookup(this->target_heading);
                        this->destination_direction.y = 0.0f;
                        this->destination_direction.z = cos_table_lookup(this->target_heading);
                    }
                }
            }
            break;
        }
        case 1:
            if (this->get_flag_b4() != 0) {
                select_target();
                this->substate = 2;
            }
            play_proximity_effect();
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, 1.8f);
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_heading, 0xF00);
            advance_pose_turn(this->target_heading);
            this->check_collisions();
            break;
        }
        break;
    }
}

void TObjEneBm5Wolf::action(s32 event) {
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_field_378(7);
        this->requested_action = 0xB;
        this->substate = 0;
        TObjEneBm5Wolf::find_pack_leader(this->group_id);
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
        this->substate = (this->substate + 1);
        if (this->substate == 0x1E) {
            apply_mourning_zalure();
        } else if (this->substate == 0x28) {
            apply_mourning_jellen();
        }
        this->check_collisions();
        break;
    }
}

void TObjEneBm5Wolf::hurt_state(s32 event) {
    switch (event) {
    case 4:
        this->clear_intangible();
        TBoss8Dragon__sub_800BB7D4(this, 0xF1);
        this->state_timer = 0;
        this->target_heading = 0;
        this->requested_action = 6;
        this->substate = 0;
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
        VecCopy(&v, (const Vec *)&this->velocity.x);
        {
        f32 c = normalize_vector_xz(&v);
        this->move_with_wall_slide_on_ground(v.x, v.z, c);
        }
        if (this->substate == 0) {
            this->velocity.x *= 0.5f;
            this->velocity.z *= 0.5f;
        } else {
            this->velocity.x *= 0.9f;
            this->velocity.z *= 0.9f;
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_heading, 0x300);
            this->rotation_y = (s16) this->rotation_y;
            if (this->is_passing_frame(22.0f) != 0) {
                spawn_recoil_dust(&v);
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

void TObjEneBm5Wolf::update_dying_state(s32 event) {
    s32 *tgt;
    TObjEneBm5WolfNode *n;
    TObjEneBm5Wolf *e;
    f32 k;
    Vec pos;
    Vec vel;
    f32 c;
    tgt = &this->target_heading;
    switch (event) {
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
        this->substate = 0;
        this->stopping_distance = calc_death_slide_speed(this->action_table[9].speed);
        this->wall_reach = this->sink_depth = 0.0f;
        if (this->is_leader != 0) {
            k = 50.0f;
            for (n = ((TObjEneBm5WolfList *)TObjEneBm5Wolf__pack_member_list)->head; n != NULL; n = n->next) {
                e = n->get_owner();
                if (e != NULL && e->group_id == this->group_id) {
                    ((TObjEneBm5Wolf *)e)->schedule_pack_reaction((s32)(k * this->random_ratio()) + 0x14, this->attacker_id);
                }
            }
        }
        this->set_active();
        break;
    case 3:
        if (this->substate == 2) {
            this->transition_enemy_state(0x11);
        }
        break;
    case 1:
        break;
    case 0:
        switch (this->substate) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->substate = 1;
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
                TObjPlayer::spawn_dead_spot_type2(&pos, 0x32);
                spawn_effect_at_ground(&pos, 0x46);
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, *tgt, 0x300);
            this->rotation_y = (s16)this->rotation_y;
            if (this->wall_reach < 28.0f) {
                this->wall_reach = this->wall_reach + this->stopping_distance;
            }
            VecCopy(&vel, (const Vec *)&this->velocity.x);
            c = normalize_vector_xz(&vel);
            this->move_clamped_on_ground(vel.x, vel.z, c);
            if (this->is_passing_frame(22.0f) != 0) {
                spawn_recoil_dust(&vel);
            }
            this->velocity.x *= 0.8f;
            this->velocity.z *= 0.8f;
            advance_pose_turn(this->rotation_y);
            this->update_body_colliders();
            break;
        case 1:
            this->position.y -= 0.1f;
            this->sink_depth += 0.1f;
            if (this->sink_depth > 20.0f) {
                this->substate = 2;
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
    if (((s32) TObjEneBm5Wolf__render_node_index >= 0x16) && ((s32) TObjEneBm5Wolf__render_node_index < 0x18)) {
        rotate_matrix_y(0, TObjEneBm5Wolf__render_joint_y_rotation);
    }
    TObjEneBm5Wolf__render_node_index += 1;
}

void TObjEneBm5Wolf::render() {
    s32 rot[3];
    s32 detail;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_debug();
        return;
    }
    if (!(this->status_flags & 2) && ((s16) this->mode != 0x11)) {
        if (TObjEneDD::is_main_phase_15() != 0) {
            detail = this->classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 20.0f);
        } else if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
            detail = 1;
        } else {
            detail = 0;
        }
        if (detail != 0) {
            if ((s16) this->mode != 0x10) {
                direction_to_rotation_xz((u8 *)&this->ground_normal, &rot[0], &rot[2]);
                push_matrix();
                post_translate_matrix(&this->position.x);
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
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation_y);
            translate_matrix(0, 0.0f, 0.0f, -10.0f);
            if (this->status_flags & 4) {
                translate_matrix(0, 0.0f, this->jump_height, 0.0f);
            }
            TObjEneBm5Wolf__render_node_index = 0;
            TObjEneBm5Wolf__render_joint_y_rotation = -(this->turn_offset / 2);
            set_chunk_model_node_callback(TObjEneBm5Wolf::advance_spawn_timer);
            TObjEneDD::clear_global_flag_400();
            TObjPlayer::toggle_particle_effect();
            if (detail == 1) {
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
        old_subtype = this->is_leader;
        this->select_subtype();
        if (old_subtype != this->is_leader) {
            if (old_subtype != 0) {
                this->remove_from_instance_list();
            } else {
                this->add_to_instance_list();
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
        debug_printf_at(pack_debug_text_position(0, 0), "GROUP:%2d", this->group_id);
        if (this->is_leader != 0) {
            debug_printf_at(pack_debug_text_position(0, 1), "L/M:LEADER");
        } else {
            debug_printf_at(pack_debug_text_position(0, 1), "L/M:MEMBER");
        }
    }
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        this->draw_ground_shadow(0, 0);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        post_translate_matrix(&this->position.x);
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
    leader = TObjEneBm5Wolf::find_pack_leader(this->group_id);
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
