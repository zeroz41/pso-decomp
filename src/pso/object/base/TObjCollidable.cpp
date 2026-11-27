#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/TObjRoomId.h"
#include "pso/object/base/HitEligibility.h"
#include "pso/system/memory.h"
#include "pso/object/trap/TOTrapAncient02R.h"
#include "pso/object/base/CollisionBodySet.h"
#include "pso/map/CsnGroundQuery.h"
#include "types.h"
#include <string.h>
#include "pso/map/CsnGroundCandidates.h"
#include "pso/system/data/FlagWord.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/math/BoxCollision.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/TAttackCollider.h"
#include "pso/enemy/TObjEneBeastBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/ScratchVectors.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/base/TObjBase.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/render_util.h"
#include "pso/network/TProtocol.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TLobby.h"
#include "pso/network/UpdateObjectStateCmd.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/PlayerSlots.h"
#include "pso/quest/QuestFloorDesignation.h"
#include "pso/map/FloorPopulation.h"



#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 entity_table_count;
s32 registered_player_count;
s32 registered_enemy_count;
s32 registered_object_count;
int player_unique_pair_entry_count;

void collect_player_body_contacts(CollisionBodySet *set) {
    collect_body_contacts(set, 0, registered_player_count);
}

void collect_enemy_body_contacts(CollisionBodySet *set) {
    collect_body_contacts(set, registered_player_count, registered_enemy_count);
}

void collect_object_body_contacts(CollisionBodySet *set) {
    collect_body_contacts(set, registered_player_count + registered_enemy_count, registered_object_count);
}

#pragma push
#pragma fp_contract on
// Places the set's bodies at its position and records (in the unique pair
// table) every body of the `count` registered actors from table slot `start`
// that one of them touches.
void collect_body_contacts(CollisionBodySet *set, s32 start, s32 count) {
    CollisionBody *body;
    s32 n;
    int facing;
    f32 s;
    f32 c;
    int flags;
    s32 shape;
    TObjCollidable **entry;
    s32 i;
    TObjCollidable *actor;
    CollisionBody *other_body;
    int other_facing;
    s32 other_count;
    s32 j;
    CollisionBody *hit;

    if (set == NULL || set->colliders == NULL || set->count <= 0) {
        return;
    }
    body = set->colliders;
    n = set->count;
    facing = set->facing;
    Vec pos = set->position;
    s = sin_table_lookup(facing);
    c = cos_table_lookup(facing);
    for (; n != 0; n--, body++) {
        CollisionBox box;
        CollisionSphere sphere;
        flags = body->flags;
        shape = body->shape;
        body->center.x = body->offset.x * s + pos.x;
        body->center.y = pos.y + body->offset.y;
        body->center.z = body->offset.z * c + pos.z;
        if (body->shape == 1) {
            build_collision_box_corners(pos, facing, body, &box);
        } else {
            sphere.center.x = body->center.x;
            sphere.center.y = 0.0f;
            sphere.center.z = body->center.z;
            sphere.radius = body->radius;
        }
        entry = &entity_table[start];
        for (i = count; i != 0; i--) {
            actor = *entry++;
            if (actor != NULL && !(actor->actorFlags & 0x80000800) && actor->bodies != NULL &&
                horizontal_distance_squared(&pos, &actor->position) < 40000.0f) {
                Vec other_pos = actor->position;
                other_body = actor->bodies;
                other_facing = actor->rotation_y;
                other_count = actor->body_count;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, other_facing);
                for (j = 0; j != other_count; j++, other_body++) {
                    CollisionBox other_box;
                    Vec offset;
                    CollisionSphere other_sphere;
                    hit = NULL;
                    if (check_body_flags(flags, other_body->flags)) {
                        rotate_vector_by_current_matrix(&other_body->offset, &offset);
                        other_body->center.x = other_pos.x + offset.x;
                        other_body->center.y = other_pos.y + offset.y;
                        other_body->center.z = other_pos.z + offset.z;
                        if (other_body->shape == 1) {
                            build_collision_box_corners(other_pos, other_facing, other_body, &other_box);
                            if (shape == 1) {
                                if (test_box_overlap(box.corners, other_box.corners)) {
                                    hit = other_body;
                                }
                            } else if (test_box_sphere_contact(other_box.corners, &sphere)) {
                                hit = other_body;
                            }
                        } else {
                            other_sphere.center.x = other_body->center.x;
                            other_sphere.center.y = 0.0f;
                            other_sphere.center.z = other_body->center.z;
                            other_sphere.radius = other_body->radius;
                            if (shape == 1) {
                                if (test_box_sphere_contact(box.corners, &other_sphere)) {
                                    hit = other_body;
                                }
                            } else if (spheres_overlap(&sphere, &other_sphere)) {
                                hit = other_body;
                            }
                        }
                    }
                    if (hit != NULL) {
                        add_unique_pair_entry(actor, j);
                    }
                }
                pop_matrix();
            }
        }
    }
}

#pragma pop

void add_unique_pair_entry(TObjCollidable *target, s32 body) {
    ActorBodyHit *p;
    s32 i;
    if ((u32)player_unique_pair_entry_count < 0x10) {
        p = player_unique_pair_entries;
        for (i = 0; i != player_unique_pair_entry_count; i++, p++) {
            if (p->target == target && p->body == body) {
                return;
            }
        }
        p->target = target;
        p->body = body;
        player_unique_pair_entry_count++;
    }
}

void reset_global_table(void) {
    memset(player_unique_pair_entries, 0, sizeof(player_unique_pair_entries));
    player_unique_pair_entry_count = 0;
}

void TObjCollidable::clear_player_status_flag(s32 body, u32 flags) {
    CollisionBody *list = bodies;
    if (list != NULL) {
        list[body].flags &= ~flags;
    }
}

void TObjCollidable::set_indexed_flags(s32 body, s32 flags) {
    CollisionBody *list = bodies;
    if (list != NULL) {
        list[body].flags |= flags;
    }
}

s32 TObjEneBeastBase::test_elt_flag(s32 body, s32 flags) {
    CollisionBody *list = bodies;
    if (list != NULL) {
        return (u8)((flags & list[body].flags) != 0);
    }
    return (u8)0;
}

f32 TObjCollidable::get_collision_body_radius(s32 body) {
    if (bodies != NULL) {
        return bodies[body].radius;
    }
    return 0.0f;
}

TObjChara *resolve_hittable_target(u16 actor_id, s16 collider) {
    TObjCollidable *target = find_entity_by_id(actor_id);
    if (target == NULL) {
        return NULL;
    }
    if (target->all_parents_unqueued_for_destruction() == 0 || target->test_actor_flags(0x04040800) != 0) {
        return NULL;
    }
    if (static_cast<TObjEneBeastBase *>(target)->test_elt_flag(collider, 1) == 0) {
        return NULL;
    }
    if (obj_is_hit_receivable(target) == 0) {
        return NULL;
    }
    return static_cast<TObjChara *>(target);
}

void handle_6x0B_update_object_state(G_UpdateObjectState_6x0B *packet) {
    QuestObjectEntry state;
    TObjCollidable *object;
    bswap_object_state(packet);
    object = find_entity_by_id(packet->header.entity_id);
    if (object != NULL) {
        object->access_object_saved_state(&state, 1);
        state.flags = packet->flags;
        object->access_object_saved_state(&state, 0);
        object->apply_saved_state(&state.flags, 1);
    } else {
        QuestObjectEntry fallback = quest_object_entries[packet->object_index];
        fallback.flags = packet->flags;
        set_quest_object_entry(packet->object_index, &fallback);
    }
}

void TObjCollidable::send_object_state_update(void *saved_state) {
    QuestObjectEntry *source = (QuestObjectEntry *)saved_state;
    QuestObjectEntry state;
    FloorObjectSetRow *entry;
    if (source != NULL) {
        state.copy_from(source);
    } else {
        access_object_saved_state(&state, 1);
    }
    entry = (FloorObjectSetRow *)set_entry;
    if (entry != NULL) {
        G_UpdateObjectState_6x0B packet;
        packet.init();
        packet.header.entity_id = entity_id;
        packet.flags = state.flags;
        packet.object_index = entry->placement.set_index;
        packet.send();
    }
}

void clear_entity_table() {
    s32 i;
    for (i = 0; i < 0x18c; i++) {
        entity_table[i] = NULL;
    }
    entity_table_count = 0;
}

s32 TObjCollidable::unregister_object_by_id() {
    s32 mid;
    s32 lo;
    s32 hi;
    s32 count;
    u16 id;
    lo = 0;
    id = entity_id;
    count = entity_table_count;
    hi = count - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (entity_table[mid]->entity_id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if (entity_table[lo] == this) {
        memcpy(&entity_table[lo], &entity_table[lo + 1], (count - (lo + 1)) * 4);
        entity_table_count--;
        u16 kind = get_entity_id();
        if (kind < 0x1000) {
            registered_player_count--;
        } else if (kind < 0x4000) {
            registered_enemy_count--;
        } else {
            registered_object_count--;
        }
        entity_table[entity_table_count] = NULL;
        return (u16)id;
    }
    return (u16)0xFFFF;
}

void TObjCollidable::register_object_by_id() {
    get_or_assign_entity_id(0);
    register_entity_by_id(this);
}

u16 register_entity_by_id(TObjCollidable *actor) {
    u16 id;
    s32 lo;
    s32 mid;
    s32 hi;
    u16 kind;

    id = actor->entity_id;
    if (id == 0xFFFF) {
        return id;
    }
    hi = entity_table_count - 1;
    if (hi > -1 && id < entity_table[hi]->entity_id) {
        lo = 0;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (entity_table[mid]->entity_id < id) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (id == entity_table[lo]->entity_id) {
            return id;
        }
        memcpy(&entity_table[lo + 1], &entity_table[lo], (entity_table_count - lo) * 4);
    } else {
        lo = entity_table_count;
    }
    entity_table[lo] = actor;
    entity_table_count++;
    kind = actor->get_entity_id();
    if (kind < 0x1000) {
        registered_player_count++;
    } else if (kind < 0x4000) {
        registered_enemy_count++;
    } else {
        registered_object_count++;
    }
    return id;
}

TObjCollidable *find_entity_by_id(u16 id) {
    s32 lo;
    s32 mid;
    s32 hi;
    TObjCollidable *entity;
    if (id == 0xffff) {
        return NULL;
    }
    if (id < 12) {
        return get_player_by_client_id(id);
    }
    lo = 0;
    hi = entity_table_count - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (entity_table[mid]->entity_id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    entity = entity_table[lo];
    if (entity != NULL && entity->entity_id == id) {
        return entity;
    }
    return NULL;
}

void TObjCollidable::collision_update_stub() {}

void clear_battle_param_slots() {
    int i;
    for (i = 0; i < 16; i++) {
        set_battle_param_slot(i, 0);
    }
}

s32 find_or_alloc_battle_param_slot(uaddr actor) {
    s32 slot;
    u32 battle_param;

    for (slot = 0;;) {
        battle_param = TObjPlayer::get_battle_param(slot);
        if (battle_param == actor) {
            return slot;
        }
        if (battle_param == 0U) {
            return set_battle_param_slot(slot, actor);
        }
        slot += 1;
        if (slot >= 0x10) {
            return -1;
        }
    }
}

int set_battle_param_slot(int slot, int actor) {
    player_battle_param_table[slot] = actor;
    return slot;
}

void TObjCollidable::refresh_collision_body_centers() {
    Vec center;
    s32 n;
    s32 i;
    if (this != NULL && bodies != NULL && all_parents_unqueued_for_destruction() != 0) {
        n = body_count;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, rotation_y);
        for (i = 0; i < n; i++) {
            VecCopy(&center, &bodies[i].offset);
            rotate_vector_by_current_matrix(&center, &center);
            vec3_add_to(&center, &position);
            VecCopy(&bodies[i].center, &center);
        }
        pop_matrix();
    }
}

s32 build_collision_box_corners(Vec origin, s32 facing, CollisionBody *body, CollisionBox *out) {
    Vec pos;
    CollisionBox box;
    s32 i;
    f32 y, nx, nz, ny, x, z;
    VecCopy(&pos, &body->center);
    y = 50.0f;
    pos.y = 0.0f;
    ny = -y;
    x = body->half_width;
    z = body->radius;
    nx = -x;
    nz = -z;
    box.corners[0].x = nx;
    box.corners[0].y = y;
    box.corners[0].z = z;
    box.corners[1].x = nx;
    box.corners[1].y = y;
    box.corners[1].z = nz;
    box.corners[2].x = x;
    box.corners[2].y = y;
    box.corners[2].z = nz;
    box.corners[3].x = x;
    box.corners[3].y = y;
    box.corners[3].z = z;
    box.corners[4].x = nx;
    box.corners[4].y = ny;
    box.corners[4].z = z;
    box.corners[5].x = nx;
    box.corners[5].y = ny;
    box.corners[5].z = nz;
    box.corners[6].x = x;
    box.corners[6].y = ny;
    box.corners[6].z = nz;
    box.corners[7].x = x;
    box.corners[7].y = ny;
    box.corners[7].z = z;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, facing);
    for (i = 0; i < 8; i++) {
        rotate_vector_by_current_matrix(&box.corners[i], &box.corners[i]);
        vec3_add_to(&box.corners[i], &pos);
    }
    pop_matrix();
    if (out != NULL) {
        copy_collision_box(out, &box);
        return 1;
    }
    return 0;
}

CollisionBox *copy_collision_box(CollisionBox *dst, const CollisionBox *src) {
    *dst = *src;
    return dst;
}

s32 test_collider_sphere_overlap_xz(Vec, const CollisionBody *body, CollisionSphere *out) {
    CollisionSphere sphere;
    VecCopy(&sphere.center, &body->center);
    static_cast<volatile CollisionSphere &>(sphere).center.y = 0.0f;
    sphere.radius = static_cast<const volatile CollisionBody *>(body)->radius;
    if (out != NULL) {
        copy_collision_sphere(out, &sphere);
        return 1;
    }
    return 0;
}

void copy_collision_sphere(CollisionSphere *dst, CollisionSphere *src) {
    *dst = *src;
}

s32 resolve_actor_sphere_contact(TObjCollidable *actor, TObjCollidable *, CollisionBody *contact) {
    Vec displacement;
    f32 tangent_scale;
    s32 turn;
    u16 angle;
    if (horizontal_distance_squared(&actor->position, &actor->prev_position) < 9.9999994e-11f) {
        return 0;
    }
    VecCopy(&displacement, &contact->center);
    subtract_vector(&displacement, &actor->prev_position);
    angle = angle_diff_s16((10430.38043493439 * atan2_float(displacement.x, displacement.z)), actor->rotation_y);
    if ((s32)angle < 0x4000) {
        tangent_scale = 0.25f;
        turn = 0x4000;
    } else {
        turn = 0xC000;
        if ((s32)angle < 0xC000) {
            return 0;
        }
        tangent_scale = 0.25f;
    }
    if (actor->entity_id >= 0x1000U) {
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, turn);
        rotate_vector_by_current_matrix(&displacement, &displacement);
        pop_matrix();
        if (1e-5f < ((displacement.x * displacement.x) + (displacement.z * displacement.z))) {
            displacement.y = 0.0f;
            normalize_vector(&displacement);
            displacement.x = (displacement.x * tangent_scale);
            displacement.z *= tangent_scale;
            vec3_add_to(&displacement, &actor->prev_position);
            if (project_actor_to_ground(actor, &displacement, NULL) != 0) {
                VecCopy(&actor->position, &displacement);
                return 1;
            }
        }
    }
    if (project_actor_to_ground(actor, &actor->prev_position, NULL) != 0) {
        VecCopy(&actor->position, &actor->prev_position);
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
// Turns the step v by yaw and moves the actor there when the ground under
// that point is found.
#define TRY_STEP(yaw)                                                  \
    push_matrix_from(identity_matrix);                                 \
    rotate_matrix_y(0, (yaw));                                         \
    rotate_vector_by_current_matrix(&v, &v);                           \
    pop_matrix();                                                      \
    vec3_add_to(&v, &actor->position);                                 \
    if (project_actor_to_ground(actor, &v, NULL) != 0) {               \
        VecCopy(&actor->position, &v);                                 \
        moved = 1;                                                     \
    }
s32 resolve_player_box_contact(TObjCollidable *actor, TObjCollidable *other, CollisionBody *contact) {
    Vec radial;
    Vec v;
    s32 moved;
    if (other == NULL || contact == NULL) {
        return 0;
    }
    VecCopy(&radial, &actor->prev_position);
    subtract_vector(&radial, &contact->center);
    if (enable_v2_features != 0 && actor->entity_id < 0x1000) {
        f32 hw = contact->half_width;
        f32 hd = contact->radius;
        f32 xl;
        f32 zl;
        f32 xx;
        f32 zz;
        f32 dx;
        f32 dz;
        moved = 0;
        xl = hw * hw + actor->get_collision_body_radius(0);
        zl = hd * hd + actor->get_collision_body_radius(0);
        VecCopy(&scratch_vec, &radial);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, -other->rotation_y);
        rotate_vector_by_current_matrix(&scratch_vec, &scratch_vec);
        pop_matrix();
        xx = scratch_vec.x * scratch_vec.x;
        zz = scratch_vec.z * scratch_vec.z;
        dx = xl - xx;
        dz = zl - zz;
        if (xx + zz < 1e-5f) {
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.1f;
            TRY_STEP(actor->rotation_y);
        } else if (contact->flags & 0x20000000) {
            v.x = v.y = v.z = 0.0f;
            if (hd < hw) {
                if (0.0f < scratch_vec.z) {
                    v.z = 0.1f;
                } else {
                    v.z = -0.1f;
                }
            } else {
                if (0.0f < scratch_vec.x) {
                    v.x = 0.1f;
                } else {
                    v.x = -0.1f;
                }
            }
            TRY_STEP(other->rotation_y);
        } else if (dx < dz) {
            v.x = scratch_vec.x < 0.0f ? -0.1f : 0.1f;
            v.z = v.y = 0.0f;
            TRY_STEP(other->rotation_y);
            v.x = 0.0f;
            v.y = 0.0f;
            if (scratch_vec.z < 0.0f) {
                v.z = -0.010000001f;
            } else {
                v.z = 0.010000001f;
            }
            TRY_STEP(other->rotation_y);
        } else {
            v.x = 0.0f;
            v.y = 0.0f;
            if (scratch_vec.z < 0.0f) {
                v.z = -0.1f;
            } else {
                v.z = 0.1f;
            }
            TRY_STEP(other->rotation_y);
            v.x = scratch_vec.x < 0.0f ? -0.010000001f : 0.010000001f;
            v.z = v.y = 0.0f;
            TRY_STEP(other->rotation_y);
        }
        if (moved != 0) {
            return moved;
        }
    }
    if (angle_difference_abs((s32)(10430.38043493439 * atan2_float(radial.x, radial.z)), actor->rotation_y) < 0x3000) {
        return 0;
    }
    if (project_actor_to_ground(actor, &actor->prev_position, NULL) != 0) {
        VecCopy(&actor->position, &actor->prev_position);
        return 1;
    }
    return 1;
}
#undef TRY_STEP
#pragma pop

s32 respond_to_body_contact(TObjCollidable *actor, TObjCollidable *other, CollisionBody *contact) {
    if (other != NULL && contact != NULL) {
        switch (contact->shape) {
        case 0:
            return resolve_actor_sphere_contact(actor, other, contact);
        default:
            return resolve_player_box_contact(actor, other, contact);
        }
    }
    return 0;
}

s32 check_body_flag_pair(s32 flags, s32 other_flags) {
    if (((flags & 0x2000) && (other_flags & 0x100)) || ((flags & 0x100) && (other_flags & 0x2000))) {
        return 1;
    }
    if (((flags & 0x4000) && (other_flags & 0x200)) || ((flags & 0x200) && (other_flags & 0x4000))) {
        return 1;
    }
    if (((flags & 0x8000) && (other_flags & 0x400)) || ((flags & 0x400) && (other_flags & 0x8000))) {
        return 1;
    }
    if (((flags & 0x10000) && (other_flags & 0x800)) || ((flags & 0x800) && (other_flags & 0x10000))) {
        return 1;
    }
    if (((flags & 0x40000) && (other_flags & 0x1000)) || ((flags & 0x1000) && (other_flags & 0x40000))) {
        return 1;
    }
    return 0;
}

s32 check_body_flags(s32 flags, s32 other_flags) {
    s32 shared;

    shared = flags & other_flags;
    if (!(shared & 1)) {
        return 0;
    }
    if (!(shared & 6)) {
        return 0;
    }
    if (((flags & 8) && (other_flags & 0x2000)) || ((other_flags & 8) && (flags & 0x2000))) {
        return 0;
    }
    if (((flags & 0x10) && (other_flags & 0x4000)) || ((other_flags & 0x10) && (flags & 0x4000))) {
        return 0;
    }
    if (((flags & 0x20) && (other_flags & 0x8000)) || ((other_flags & 0x20) && (flags & 0x8000))) {
        return 0;
    }
    if (((flags & 0x40) && (other_flags & 0x10000)) || ((other_flags & 0x40) && (flags & 0x10000))) {
        return 0;
    }
    if (((flags & 0x80) && (other_flags & 0x40000)) || ((other_flags & 0x80) && (flags & 0x40000))) {
        return 0;
    }
    return 1;
}

s32 test_player_overlap_with_players(TObjCollidable *, TObjCollidable *source, Vec *pos, CollisionBody *out) {
    CollisionBodySet a;
    CollisionBodySet b;
    s32 i;
    TObjCollidable *other;
    CollisionBody *hit;

    if (source != NULL && source->bodies != NULL) {
        a.colliders = source->bodies;
        a.count = source->body_count;
        VecCopy(&a.position, pos);
        a.facing = source->rotation_y;
        for (i = registered_player_count; i < entity_table_count; i++) {
            other = TObjPlayer::get_player_data(i);
            if (other != NULL && other != source && other->test_actor_flags(0x80000800) == 0 && other->bodies != NULL &&
                horizontal_distance_squared(&source->position, &other->position) < 10000.0f) {
                b.colliders = other->bodies;
                b.count = other->body_count;
                VecCopy(&b.position, &other->position);
                b.facing = other->rotation_y;
                hit = refresh_actor_body_spheres(a, b);
                if (hit != NULL) {
                    if (out != NULL) {
                        copy_collision_body(out, hit);
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 test_player_body_overlap_at(TObjMapWarp *, TObjCollidable *player, const Vec *pos) {
    CollisionBodySet source;
    CollisionBodySet destination;
    s32 i;
    TObjCollidable *other;
    CollisionBody *body;

    if (player != NULL && (body = player->bodies) != NULL) {
        source.colliders = body;
        source.count = player->body_count;
        VecCopy(&source.position, pos);
        source.facing = player->rotation_y;
        for (i = 0; i < entity_table_count; i++) {
            other = TObjPlayer::get_player_data(i);
            if (other != NULL && other != player && (body = other->bodies) != NULL) {
                destination.colliders = body;
                destination.count = other->body_count;
                VecCopy(&destination.position, &other->position);
                destination.facing = other->rotation_y;
                if (refresh_actor_body_spheres(source, destination) != NULL) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

CollisionBody *refresh_actor_body_spheres(CollisionBodySet source_set, CollisionBodySet destination_set) {
    CollisionBox boxAA, boxBB, boxAB, boxBA;
    Vec worldA, worldB, offsetA, offsetB;
    CollisionSphere sphereAB, sphereBA, sphereAA, sphereBB;
    CollisionBody *source;
    CollisionBody *destination;
    s32 facingA, facingB, countA, countB;
    s32 flags;
    s32 i, j;
    countA = source_set.count;
    countB = destination_set.count;
    for (i = 0; i < countA; ++i) {
        source = &source_set.colliders[i];
        flags = source->flags;
        VecCopy(&worldA, &source_set.position);
        VecCopy(&offsetA, &source->offset);
        facingA = source_set.facing;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, facingA);
        rotate_vector_by_current_matrix(&offsetA, &offsetA);
        pop_matrix();
        vec3_add_to(&worldA, &offsetA);
        VecCopy(&source->center, &worldA);
        VecCopy(&worldA, &source_set.position);
        for (j = 0; j < countB; ++j) {
            destination = &destination_set.colliders[j];
            if (check_body_flags(flags, destination->flags)) {
                VecCopy(&worldB, &destination_set.position);
                VecCopy(&offsetB, &destination->offset);
                facingB = destination_set.facing;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, facingB);
                rotate_vector_by_current_matrix(&offsetB, &offsetB);
                pop_matrix();
                vec3_add_to(&worldB, &offsetB);
                VecCopy(&destination->center, &worldB);
                VecCopy(&worldB, &destination_set.position);
                switch (source->shape) {
                case 1:
                    switch (destination->shape) {
                    case 1:
                        build_collision_box_corners(worldA, facingA, source, &boxAA);
                        build_collision_box_corners(worldB, facingB, destination, &boxBB);
                        if (test_box_overlap(boxAA.corners, boxBB.corners)) return destination;
                        break;
                    case 0: default:
                        build_collision_box_corners(worldA, facingA, source, &boxAB);
                        test_collider_sphere_overlap_xz(worldB, destination, &sphereAB);
                        if (test_box_sphere_contact(boxAB.corners, &sphereAB)) return destination;
                        break;
                    }
                    break;
                case 0: default:
                    switch (destination->shape) {
                    case 1:
                        test_collider_sphere_overlap_xz(worldA, source, &sphereBA);
                        build_collision_box_corners(worldB, facingB, destination, &boxBA);
                        if (test_box_sphere_contact(boxBA.corners, &sphereBA)) return destination;
                        break;
                    case 0: default:
                        test_collider_sphere_overlap_xz(worldA, source, &sphereAA);
                        test_collider_sphere_overlap_xz(worldB, destination, &sphereBB);
                        if (spheres_overlap(&sphereAA, &sphereBB)) return destination;
                        break;
                    }
                    break;
                }
            }
        }
    }
    return NULL;
}

CollisionBody *TObjCollidable::find_actor_body_contact(TObjCollidable *target, f32 limit) {
    CollisionBodySet source, destination;
    CollisionBody *result;
    if (target != this && target != NULL && !(actorFlags & 0x800) && !(target->actorFlags & 0x80000800)) {
        if (limit < horizontal_distance_squared(&position, &target->position)) {
            return NULL;
        }
        CollisionBody *data = bodies;
        if (data != NULL && target->bodies != NULL) {
            source.colliders = data;
            source.count = body_count;
            VecCopy(&source.position, &position);
            source.facing = rotation_y;
            destination.colliders = target->bodies;
            destination.count = target->body_count;
            VecCopy(&destination.position, &target->position);
            destination.facing = target->rotation_y;
            result = refresh_actor_body_spheres(source, destination);
            if (result != NULL) {
                find_or_alloc_battle_param_slot(reinterpret_cast<uaddr>(target));
                return result;
            }
        }
    }
    return NULL;
}

void TObjCollidable::mark_enemy_body_contacts() {
    TObjCollidable *actor;
    s32 i;
    CollisionBody *body = bodies;
    if (body != NULL) {
        body->flags = body->flags & 0xFFEFFFFF;
        for (i = 0; i < entity_table_count; i++) {
            actor = entity_table[i];
            if (actor == NULL) {
                break;
            }
            u16 kind = actor->get_entity_id();
            if (kind >= 0x1000U && kind < 0x4000U && check_actor_body_contact(actor, 100.0f) != 0U) {
                bodies->flags = bodies->flags | 0x100000;
            }
        }
    }
}

void TAttackCollider::update_body_contact_flag(f32 range) {
    CollisionBody *body = bodies;
    if (body) {
        body->flags &= ~0x80000;
        for (s32 i = 0; i < registered_player_count; i++) {
            TObjCollidable *actor = entity_table[i];
            if (actor && check_actor_body_contact(actor, range)) {
                bodies->flags |= 0x80000;
            }
        }
    }
}

u32 TObjCollidable::check_actor_body_contact(TObjCollidable *target, f32 range) {
    CollisionBodySet a;
    CollisionBodySet b;
    CollisionBody *hit;

    if (target != this && target != NULL && !(actorFlags & 0x800) && !(target->actorFlags & 0x80000800)) {
        if (range * range < horizontal_distance_squared(&position, &target->position)) {
            return 0;
        }
        if (bodies != NULL && target->bodies != NULL) {
            a.colliders = bodies;
            a.count = body_count;
            VecCopy(&a.position, &position);
            a.facing = rotation_y;
            b.colliders = target->bodies;
            b.count = target->body_count;
            VecCopy(&b.position, &target->position);
            b.facing = target->rotation_y;
            hit = refresh_actor_body_spheres(a, b);
            if (hit != NULL) {
                find_or_alloc_battle_param_slot((uaddr)target);
                hit->flags |= 0x04000000;
                return (uaddr)hit;
            }
        }
    }
    return 0;
}

void TObjCollidable::update_enemy_collision_flags() {
    TObjPlayer *player;
    s32 j;
    CollisionBody *contact;
    CollisionBody *body = bodies;
    if (body != NULL) {
        body->flags = body->flags & 0xFEDFFFFF;
        for (j = registered_player_count + registered_enemy_count; j < entity_table_count; j++) {
            player = TObjPlayer::get_player_data(j);
            if (player != NULL) {
                contact = find_actor_body_contact(player, 10000.0f);
                if (contact != NULL && check_body_flag_pair(bodies->flags, contact->flags) == 0 &&
                    respond_to_body_contact(this, player, contact) != 0) {
                    bodies->flags = bodies->flags | 0x01200000;
                }
            }
        }
    }
}

void check_enemy_body_collisions(TObjCollidable *actor) {
    TObjPlayer *other;
    s32 i;
    CollisionBody *contact;
    if (actor->bodies != NULL) {
        actor->bodies->flags &= ~0x900000;
        for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
            other = TObjPlayer::get_player_data(i);
            if (other != NULL) {
                if (actor->room == other->room || actor->entity_id < 0x1000) {
                    contact = actor->find_actor_body_contact(other, 10000.0f);
                    if (contact != NULL) {
                        actor->bodies->flags |= 0x100000;
                        if (check_body_flag_pair(actor->bodies->flags, contact->flags) == 0 &&
                            respond_to_body_contact(actor, other, contact) != 0) {
                            actor->bodies->flags |= 0x800000;
                        }
                    }
                }
            }
        }
    }
}

void TObjCollidable::check_object_collisions() {
    TObjPlayer *player;
    s32 j;
    CollisionBody *contact;
    CollisionBody *body = bodies;
    if (body != NULL) {
        body->flags = body->flags & 0xFFB7FFFF;
        for (j = 0; j < registered_player_count; j++) {
            player = TObjPlayer::get_player_data(j);
            if (player != NULL && player->entity_id < 0x1000U) {
                contact = find_actor_body_contact(player, 10000.0f);
                if (contact != NULL) {
                    bodies->flags = bodies->flags | 0x80000;
                    if (check_body_flag_pair(bodies->flags, contact->flags) == 0 &&
                        respond_to_body_contact(this, player, contact) != 0) {
                        bodies->flags = bodies->flags | 0x400000;
                    }
                }
            }
        }
        if (!(bodies->flags & 0x480000)) {
            refresh_collision_body_centers();
        }
    }
}

void TObjCollidable::update_collisions() {
    check_object_collisions();
    check_enemy_body_collisions(this);
}

void TObjCollidable::clear_collision_bodies() {
    body_flags = NULL;
    bodies = NULL;
}

void *TObjCollidable::set_collision_body(CollisionBody *body) {
    body_count = 1;
    bodies = body;
    body_flags = &own_body_flags;
    refresh_collision_body_centers();
    return bodies;
}

void free_collision_body_parts(TObjCollidable *actor) {
    FlagWord *flags = actor->body_flags;
    if (flags != NULL) {
        if (flags != NULL) {
            mem_free((u8 *)flags - 0x10);
        }
        actor->body_flags = NULL;
    }
    if (actor->bodies != NULL) {
        mem_free(actor->bodies);
        actor->bodies = NULL;
    }
}

CollisionBody *init_collision_body_parts(TObjCollidable *actor, const CollisionBody *bodies, s32 count) {
    s32 n;
    s32 i;
    if (actor->bodies == NULL) {
        actor->body_count = count;
        actor->bodies = (CollisionBody *)mem_alloc(actor->body_count * sizeof(CollisionBody));
        for (i = 0; i < actor->body_count; i++) {
            copy_collision_body(&actor->bodies[i], bodies++);
        }
        actor->refresh_collision_body_centers();
    }
    if (actor->body_flags == NULL) {
        n = actor->body_count;
        actor->body_flags = new FlagWord[n];
    }
    return actor->bodies;
}

s32 project_actor_to_ground(TObjCollidable *actor, Vec *pos, Vec *normal) {
    Vec origin;
    CsnHit *hit;
    u16 room_kind;
    CsnGroundCandidates *cache;
    s32 mask;
    VecCopy(&origin, pos);
    origin.y += 10.0f;
    room_kind = get_entity_id_kind(actor->entity_id);
    mask = 0x15;
    if (room_kind == 0) {
        mask = 0x55;
    }
    cache = actor->ground_cache;
    if (cache != NULL) {
        hit = csnVectorUnder(&origin, cache->groups, mask);
    } else {
        hit = csnVecterUnder(&origin, mask);
    }
    if (hit == NULL) {
        return 0;
    }
    VecCopy(pos, &hit->contact->point);
    if (normal != NULL) {
        VecCopy(normal, &hit->contact->normal);
    }
    return 1;
}

void TObjCollidable::reset_motion_fields() {
    if (ground_cache != NULL) {
        ground_cache->clear();
    }
}

void clear_entity_tables(void) {
    clear_entity_table();
    clear_battle_param_slots();
}

void init_entity_tables() {
    entity_table_count = 0;
    registered_player_count = 0;
    registered_enemy_count = 0;
    registered_object_count = 0;
    clear_entity_table();
    clear_battle_param_slots();
}

TObjCollidable::~TObjCollidable() {
    body_count = 0;
    bodies = NULL;
}

TObjCollidable::TObjCollidable(TObject *parent) : TObjBase(parent) {
    ground_cache = NULL;
    body_count = 0;
    bodies = NULL;
    interactor = 0xFFFF;
    body_flags = NULL;
    clear_hit_receive_state();
}

void TObjCollidable::clear_hit_receive_state() { hit_receive_state = 0; }

CursorAction::CursorAction() { kind = CURSOR_ACTION_NONE; }

s32 TObjCollidable::access_object_saved_state(void *saved_state, s16 load) {
    s16 index;
    FloorObjectSetRow *entry = (FloorObjectSetRow *)set_entry;
    if (entry == NULL) {
        return 0;
    }
    index = entry->placement.set_index;
    if (index < 0 || index > 0xB9F) {
        return 0;
    }
    if (load == 0) {
        quest_object_entries[index].copy_from((QuestObjectEntry *)saved_state);
    }
    if (load == 1) {
        ((QuestObjectEntry *)saved_state)->copy_from(&quest_object_entries[index]);
    }
    return 1;
}

TObjCollidable *entity_table[0x18C];
saddr player_battle_param_table[0x10];
ActorBodyHit player_unique_pair_entries[0x10];
