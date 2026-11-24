#include "pso/object/base/HitEligibility.h"
#include "pso/system/memory.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/trap/TOTrapAncient02R.h"
#include "pso/object/base/CollisionBodySet.h"
#include "pso/map/CsnGroundQuery.h"
#include "types.h"
#include <string.h>
#include "pso/map/CsnGroundCandidates.h"
#include "pso/system/data/FlagWord.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer_803E112C.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/collision/ActorBodyContact.h"
#include "pso/math/AngleLookup.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/base/TObjBase.h"


struct Elt_801542CC { char pad[0x18]; s32 f18; char pad2[0x2C - 0x1C]; };

struct ByteBlock_C { u8 bytes[0xc]; };

#pragma inline_depth(1)
#pragma dont_inline off
struct ByteBlock_60 { u8 bytes[0x60]; };

#include <stddef.h>
struct Stack_80155050 {
    s32 sp8;
    f32 spC;
    u8 pad_10[0x4];
    f32 sp14;
};


struct E_801547E0 { u8 pad[0xc]; f32 f; u8 pad2[0x2c - 0x10]; };

struct Obj_801547E0 { u8 pad[0xa4]; E_801547E0 *arr; };

struct Part_80156780 { u8 pad[0x2c]; };

struct Obj_80156780 { u8 pad[0x9c]; void *f9c; u8 pad2[4]; Part_80156780 *parts; s32 count; };

struct Ent_80154CB4 { u8 pad[0x1c]; u16 id; };

struct State_80154954 { s16 a; s16 b; };

struct Pkt_80154954 { s16 hdr; u16 id; s32 state; s32 kind; };

struct Obj_80154954 { u8 pad[4]; s16 kind; };

struct Player_80154954 { u8 pad[0x1C]; u16 id; u8 pad1e[0x80 - 0x1E]; Obj_80154954 *obj; };



struct Hit_801561C4 { u8 pad[0x18]; u32 flags; };

struct TObjPlayer_801561C4 { u8 pad[0xA4]; Hit_801561C4 *hit; };


struct G_80156720 { u8 pad0[0x9C]; u8 *f9c; u8 pad_A0[4]; void *fa4; };

struct Flg_8015610C { u8 pad[0x18]; u32 flags; };

struct P_8015610C { u8 pad[0xA4]; Flg_8015610C *f; };


struct Obj_80154B60 { u8 pad[0x1C]; u16 id; };
struct Obj_80156268 { u8 pad0[0x30]; u32 flags; u8 pad34[4]; Vec pos; u8 pad44[0x60 - 0x44]; s32 f60; u8 pad64[0xA4 - 0x64]; CollisionBody *a4; s32 a8; };

struct Ent_80154E3C { u8 pad0[0x1C]; Vec v; u8 pad[0x2C - 0x28]; };

struct Obj_80154E3C { u8 pad0[0x38]; Vec pos; u8 pad44[0x60 - 0x44]; s32 f60; u8 pad64[0xA4 - 0x64]; Ent_80154E3C *ents; s32 count; };


struct Obj_801547E0;
#define SHIFT_80155294(yaw)                                              \
    push_matrix_from(identity_matrix);                                      \
    rotate_matrix_y(0, (yaw));                                           \
    rotate_vector_by_current_matrix(&v, &v);                                    \
    pop_matrix();                                                        \
    vec3_add_to(&v, actor + 0x38);                           \
    if (project_actor_to_ground(reinterpret_cast<TObjCollidable *>(actor), &v, NULL) != 0) {                     \
        VecCopy__FP3VecPC3Vec(actor + 0x38, &v);                          \
        moved = 1;                                                       \
    }

#include "pso/network/protocol/subcmd_6x.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/PlayerSlots.h"

union ObjectSavedState_801548A8 {
    u32 word;
    struct { s16 flags; s16 source; } halves;
};

struct ObjectBase_801548A8 { u8 pad[0x18]; };

struct StateObject_801548A8 : ObjectBase_801548A8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(ObjectSavedState_801548A8 *, s32);
};

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *);
s32 vec3_add_to(void *, void *);
s32 rotate_matrix_y(int, int);
s32 rotate_vector_by_current_matrix(void *, void *);
extern f32 identity_matrix[12];
u8 * TObjPlayer__sub_80155028(saddr arg0, saddr arg1);
s32 build_collision_box_corners(Vec pos, s32 facing, CollisionBody *body, CollisionBox *out);
s32 subtract_vector(void *, void *);
extern s32 enable_v2_features;
extern Vec scratch_vec;
f32 atan2_float(f32 y, f32 x);
s32 angle_difference_abs(s32, s32);
}
extern saddr quest_object_entries;
void handle_6x0B_update_object_state(G_UpdateObjectState_6x0B *packet);
s32 resolve_player_box_contact(u8 *arg0, u8 *arg1, u8 *arg2);

s32 lbl_805D5868;
s32 registered_player_count;
s32 registered_enemy_count;
s32 registered_entity_count;
int player_unique_pair_entry_count;
extern "C" {
void TObjPlayer__sub_801550B8(u8 *arg0, u8 *arg1);
void TObjPlayer__sub_8015434C(CollisionBodySet *set, s32 start, s32 count);
void TObjPlayer__sub_8015431C(u8 *set);
int TObjPlayer__sub_80154E28(int a0, int a1);
void TObjPlayer__sub_80156934(void);
f32 horizontal_distance_squared(void *, void *);
s32 angle_diff_s16(s32 a, s32 b);
extern saddr TObjPlayer__data_8050D460[];
void *__construct_new_array(void *, void (*)(void *), void *, s32, s32);
Part_80156780 *init_collision_body_parts(Obj_80156780 *self, Part_80156780 *src, s32 count);
void TLobby__sub_80156BA8(void *p);
void check_enemy_body_collisions(TObjCollidable *actor);
extern unsigned char lbl_8050DAD0[];
void free_collision_body_parts(G_80156720 *arg0);
u16 TObjRoomId__sub_801A1DB8(u16);
void TObjPlayer__sub_801542F4(saddr a);
void reset_global_table(void);
void *resolve_hittable_target(u16 actorId, s16 collider);
u16 register_entity_by_id(void*);

void TObjPlayer::apply_status_effect(saddr a) {
    TObjPlayer__sub_8015434C((CollisionBodySet *)a, 0, registered_player_count);
}

void TObjPlayer__sub_801542F4(saddr a) {
    TObjPlayer__sub_8015434C((CollisionBodySet *)a, registered_player_count, registered_enemy_count);
}

void TObjPlayer__sub_8015431C(u8 *set) {
    TObjPlayer__sub_8015434C((CollisionBodySet *)set, registered_player_count + registered_enemy_count, registered_entity_count);
}

#pragma push
#pragma fp_contract on
// Places the set's bodies at its position and records (in the unique pair
// table) every body of the `count` registered actors from table slot `start`
// that one of them touches.
void TObjPlayer__sub_8015434C(CollisionBodySet *set, s32 start, s32 count) {
    CollisionBody *body;
    s32 n;
    int facing;
    f32 s;
    f32 c;
    int flags;
    s32 shape;
    saddr *entry;
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
    body = (CollisionBody *)set->colliders;
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
        entry = &TObjPlayer__data_8050D460[start];
        for (i = count; i != 0; i--) {
            actor = (TObjCollidable *)*entry++;
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
                    if (TObjPlayer::check_flags(flags, other_body->flags)) {
                        rotate_vector_by_current_matrix(other_body, &offset);
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
                        TObjPlayer::add_unique_pair_entry(actor, j);
                    }
                }
                pop_matrix();
            }
        }
    }
}

#pragma pop

void TObjPlayer::add_unique_pair_entry(TObjCollidable *target, s32 body) {
    ActorBodyHit *p;
    s32 i;
    if ((u32)player_unique_pair_entry_count < 0x10) {
        p = (ActorBodyHit *)lbl_8050DAD0;
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

void reset_global_table(void) { memset(lbl_8050DAD0, 0, 128); player_unique_pair_entry_count = 0; }

void TObjCollidable::clear_player_status_flag(s32 arg1, u32 arg2) {
    void *arg0 = (void *)this;
    arg0 = *(void **)((s8 *)arg0 + 0xA4);
    if (arg0 != 0) {
        arg0 = (char*)arg0 + (arg1 * 0x2C);
        *(u32 *)((s8 *)arg0 + 0x18) &= ~arg2;
    }
}

void TObjCollidable::set_indexed_flags(s32 index, s32 flags) {
    void *entry;
    void *arg0 = (void *)this;

    entry = (void *)*(uaddr *)((s8 *)arg0 + 0xA4);
    if (entry != NULL) {
        entry = (void *)((u8 *)entry + (index * 0x2C));
        *(s32 *)((s8 *)entry + 0x18) =
            (s32)(*(s32 *)((s8 *)entry + 0x18) | flags);
    }
}

s32 TUnk_80493450::test_elt_flag(s32 collider, s32 arg2) {
    struct Elt_801542CC *temp_r3;

    temp_r3 = *(struct Elt_801542CC * *)&this->bodies;
    if (temp_r3 != 0) {
        return (u8)((u8) ((arg2 & temp_r3[collider].f18) != 0));
    }
    return (u8)(0U);
}

f32 TObjCollidable::get_collision_body_radius(s32 i) {
    if (((Obj_801547E0 *)this)->arr != 0) {
        return ((Obj_801547E0 *)this)->arr[i].f;
    }
    return 0.0f;
}

void *resolve_hittable_target(u16 actorId, s16 collider) {
    TObjCollidable *target = find_entity_by_id(actorId);
    if (target == NULL) {
        return NULL;
    }
    if (((TObject *)target)->all_parents_unqueued_for_destruction() == 0 || ((TObjCollidable *)target)->test_actor_flags(0x04040800) != 0) {
        return NULL;
    }
    if (((TUnk_80493450 *)target)->test_elt_flag(collider, 1) == 0) {
        return NULL;
    }
    if (obj_is_hit_receivable(reinterpret_cast<const TObjCollidable *>(target)) == 0) {
        return NULL;
    }
    return target;
}
}
s32 test_collider_sphere_overlap_xz(Vec, const CollisionBody *body, CollisionSphere *out);
extern saddr player_battle_param_table[];
s32 resolve_actor_sphere_contact(u8 *actor, s32 other, saddr contact);
s32 respond_to_body_contact(u8 *actor, uaddr other, u8 *contact);
void handle_6x0B_update_object_state(G_UpdateObjectState_6x0B *packet) {
    ObjectSavedState_801548A8 state;
    ObjectSavedState_801548A8 fallback;
    StateObject_801548A8 *object;
    TLobby::bswap_60_header(packet);
    object = ((StateObject_801548A8 *)find_entity_by_id(packet->header.entity_id));
    if (object != 0) {
        ((TObjCollidable *)object)->access_object_saved_state(&state, (s16)(1));
        state.halves.flags = packet->flags;
        ((TObjCollidable *)object)->access_object_saved_state(&state, (s16)(0));
        object->m4(&state, 1);
    } else {
        fallback.word = (*(ObjectSavedState_801548A8 * *)&quest_object_entries)[packet->object_index].word;
        fallback.halves.flags = packet->flags;
        TLobby::apply_table_entry(packet->object_index, &fallback);
    }
}

void TObjCollidable::send_object_state_update(void *src_arg) {
    State_80154954 *src = (State_80154954 *)src_arg;
    State_80154954 st;
    Obj_80154954 *obj;
    if (src != 0) {
        ((TLobby *)(&st))->copy_short_fields(src);
    } else {
        access_object_saved_state(&st, 1);
    }
    obj = ((Player_80154954 *)this)->obj;
    if (obj != 0) {
        Pkt_80154954 pkt;
        TLobby__sub_80156BA8(&pkt);
        pkt.id = ((Player_80154954 *)this)->id;
        pkt.state = st.a;
        pkt.kind = obj->kind;
        ((TLobby *)(&pkt))->update_and_send_60();
    }
}

void TObjPlayer::clear_item_table() {
    s32 i;
    for (i = 0; i < 0x18c; i++) {
        TObjPlayer__data_8050D460[i] = 0;
    }
    lbl_805D5868 = 0;
}

s32 TObjCollidable::unregister_object_by_id() {
    s32 mid;
    s32 lo;
    s32 hi;
    s32 count;
    u16 id;
    lo = 0;
    id = entity_id;
    count = lbl_805D5868;
    hi = count - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (((TObjMotion *)TObjPlayer__data_8050D460[mid])->entity_id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if ((TObjCollidable *)TObjPlayer__data_8050D460[lo] == this) {
        memcpy(&TObjPlayer__data_8050D460[lo], &TObjPlayer__data_8050D460[lo + 1], (count - (lo + 1)) * 4);
        lbl_805D5868--;
        u16 k = ((TObjBase *)((saddr)this))->get_entity_id();
        if (k < 0x1000) {
            registered_player_count--;
        } else if (k < 0x4000) {
            registered_enemy_count--;
        } else {
            registered_entity_count--;
        }
        TObjPlayer__data_8050D460[lbl_805D5868] = 0;
        return (u16)(id);
    }
    return (u16)(0xFFFF);
}

void TObjCollidable::register_object_by_id() {
    get_or_assign_entity_id(0);
    register_entity_by_id(this);
}

#define o ((Obj_80154B60 *)ov)
#define TBL ((Obj_80154B60 **)TObjPlayer__data_8050D460)

u16 register_entity_by_id(void *ov) {
    u16 id;
    s32 lo;
    s32 mid;
    s32 hi;
    u16 t;

    id = o->id;
    if (id == 0xFFFF) {
        return id;
    }
    hi = lbl_805D5868 - 1;
    if (hi > -1 && id < TBL[hi]->id) {
        lo = 0;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (TBL[mid]->id < id) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (id == TBL[lo]->id) {
            return id;
        }
        memcpy(&TBL[lo + 1], &TBL[lo], (lbl_805D5868 - lo) * 4);
    } else {
        lo = lbl_805D5868;
    }
    TBL[lo] = o;
    lbl_805D5868++;
    t = ((TObjBase *)((saddr)o))->get_entity_id();
    if (t < 0x1000) {
        registered_player_count++;
    } else if (t < 0x4000) {
        registered_enemy_count++;
    } else {
        registered_entity_count++;
    }
    return id;
}
#undef TBL
#undef o

TObjCollidable *find_entity_by_id(u16 id) {
    s32 lo;
    s32 mid;
    s32 hi;
    Ent_80154CB4 *e;
    if (id == 0xffff) {
        return 0;
    }
    if (id < 12) {
        return static_cast<TObjCollidable *>(get_player_by_client_id(id));
    }
    lo = 0;
    hi = lbl_805D5868 - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (((Ent_80154CB4 **)TObjPlayer__data_8050D460)[mid]->id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    e = ((Ent_80154CB4 **)TObjPlayer__data_8050D460)[lo];
    if (e != 0 && e->id == id) {
        return reinterpret_cast<TObjCollidable *>(e);
    }
    return 0;
}

void TOTrapAncient02R__sub_80154D78(TObject *) {  }
void TObjPlayer::init_all_slots() { { int i; for (i = 0; i < 16; i++) { TObjPlayer__sub_80154E28(i, 0); } } }
s32 TObjPlayer::find_or_alloc_slot(uaddr arg0) {
    s32 var_r31;
    u32 battle_param;

    var_r31 = 0;
loop_1:
    battle_param = TObjPlayer::get_battle_param(var_r31);
    if (battle_param == arg0) {
        return var_r31;
    }
    if (battle_param == 0U) {
        return TObjPlayer__sub_80154E28(var_r31, arg0);
    }
    var_r31 += 1;
    if (var_r31 >= 0x10) {
        return -1;
    }
    goto loop_1;
}

int TObjPlayer__sub_80154E28(int a0, int a1) {
  long long new_var;
  new_var = a0;
  player_battle_param_table[new_var] = a1;
  return a0;
}

void TObjCollidable::refresh_collision_body_centers() {
    Obj_80154E3C *arg0 = (Obj_80154E3C *)this;
    Vec sp8;
    s32 n;
    s32 i;
    if (arg0 != NULL && this->bodies != NULL && ((TObject *)arg0)->all_parents_unqueued_for_destruction() != 0) {
        n = arg0->count;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, this->rotation_y);
        for (i = 0; i < n; i++) {
            VecCopy__FP3VecPC3Vec(&sp8, &arg0->ents[i]);
            rotate_vector_by_current_matrix(&sp8, &sp8);
            vec3_add_to(&sp8, &arg0->pos);
            VecCopy__FP3VecPC3Vec(&arg0->ents[i].v, &sp8);
        }
        pop_matrix();
    }
}

s32 build_collision_box_corners(Vec origin, s32 facing, CollisionBody *body, CollisionBox *out) {
    Vec pos;
    Vec c[8];
    s32 i;
    f32 y, nx, nz, ny, x, z;
    VecCopy__FP3VecPC3Vec(&pos, &body->center);
    y = 50.0f;
    pos.y = 0.0f;
    ny = -y;
    x = body->half_width;
    z = body->radius;
    nx = -x;
    nz = -z;
    c[0].x = nx;
    c[0].y = y;
    c[0].z = z;
    c[1].x = nx;
    c[1].y = y;
    c[1].z = nz;
    c[2].x = x;
    c[2].y = y;
    c[2].z = nz;
    c[3].x = x;
    c[3].y = y;
    c[3].z = z;
    c[4].x = nx;
    c[4].y = ny;
    c[4].z = z;
    c[5].x = nx;
    c[5].y = ny;
    c[5].z = nz;
    c[6].x = x;
    c[6].y = ny;
    c[6].z = nz;
    c[7].x = x;
    c[7].y = ny;
    c[7].z = z;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, facing);
    for (i = 0; i < 8; i++) {
        rotate_vector_by_current_matrix(&c[i], &c[i]);
        vec3_add_to(&c[i], &pos);
    }
    pop_matrix();
    if (out != 0) {
        TObjPlayer__sub_80155028((saddr)out, (saddr)c);
        return 1;
    }
    return 0;
}

u8 * TObjPlayer__sub_80155028(saddr arg0, saddr arg1) {
    *(ByteBlock_60 *)(arg0) = *(const ByteBlock_60 *)(arg1);
    return (u8 *)arg0;
}

s32 test_collider_sphere_overlap_xz(Vec, const CollisionBody *body, CollisionSphere *out) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80155050, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80155050, spC) == 0x4);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_80155050, sp14) == 0xC);
    Stack_80155050 stack;
    VecCopy__FP3VecPC3Vec(&stack.sp8, const_cast<Vec *>(&body->center));
    static_cast<volatile Stack_80155050 &>(stack).spC = 0.0f;
    stack.sp14 = static_cast<const volatile CollisionBody *>(body)->radius;
    if (out != NULL) {
        TObjPlayer__sub_801550B8(reinterpret_cast<u8 *>(out), reinterpret_cast<u8 *>(&stack.sp8));
        return 1;
    }
    return 0;
}

void TObjPlayer__sub_801550B8(u8 *arg0, u8 *arg1) {
    *(ByteBlock_C *)(arg0) = *(const ByteBlock_C *)(arg1);
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) *(f32 *)((s8 *)arg1 + 0xC);
}

s32 resolve_actor_sphere_contact(u8 *actor, s32 other, saddr contact) {
    Vec displacement;
    f32 tangentScale;
    s32 var_r31;
    u16 temp_r3;
    if (horizontal_distance_squared(actor + 0x38, actor + 0x44) < 9.9999994e-11f) {
        return 0;
    }
    VecCopy__FP3VecPC3Vec((void *)&displacement, (void *)(contact + 0x1C));
    subtract_vector(&displacement, actor + 0x44);
    temp_r3 = angle_diff_s16((10430.38043493439 * atan2_float(displacement.x, displacement.z)), (*(s32 *)((s8 *)actor + 0x60)));
    if ((s32) temp_r3 < 0x4000) {
        tangentScale = 0.25f;
        var_r31 = 0x4000;
        goto block_7;
    }
    var_r31 = 0xC000;
    if ((s32) temp_r3 < 0xC000) {
        return 0;
    }
    tangentScale = 0.25f;
block_7:
    if ((u16) *(u16 *)((s8 *)actor + 0x1C) >= 0x1000U) {
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, var_r31);
        rotate_vector_by_current_matrix(&displacement, &displacement);
        pop_matrix();
        if (1e-5f < ((displacement.x * displacement.x) + (displacement.z * displacement.z))) {
            displacement.y = 0.0f;
            normalize_vector(&displacement);
            displacement.x = (displacement.x * tangentScale);
            displacement.z *= tangentScale;
            vec3_add_to(&displacement, actor + 0x44);
            if (project_actor_to_ground((TObjCollidable *)(actor), (Vec *)(&displacement), (Vec *)(0)) != 0) {
                VecCopy__FP3VecPC3Vec(actor + 0x38, &displacement);
                return 1;
            }
        }
    }
    if (project_actor_to_ground((TObjCollidable *)(actor), (Vec *)(actor + 0x44), (Vec *)(0)) != 0) {
        VecCopy__FP3VecPC3Vec(actor + 0x38, actor + 0x44);
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 resolve_player_box_contact(u8 *actor, u8 *other, u8 *arg2) {
    Vec radial;
    Vec v;
    s32 moved;
    if (other == NULL || arg2 == NULL) {
        return 0;
    }
    VecCopy__FP3VecPC3Vec(&radial, actor + 0x44);
    subtract_vector(&radial, arg2 + 0x1C);
    if (enable_v2_features != 0 && *(u16 *)(actor + 0x1C) < 0x1000) {
        f32 hw = *(f32 *)(arg2 + 0x10);
        f32 hd = *(f32 *)(arg2 + 0xC);
        f32 xl;
        f32 zl;
        f32 xx;
        f32 zz;
        f32 dx;
        f32 dz;
        moved = 0;
        xl = hw * hw + ((TObjCollidable *)actor)->get_collision_body_radius(0);
        zl = hd * hd + ((TObjCollidable *)actor)->get_collision_body_radius(0);
        VecCopy__FP3VecPC3Vec(&scratch_vec, &radial);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, -*(s32 *)(other + 0x60));
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
            SHIFT_80155294(*(s32 *)(actor + 0x60));
        } else if (*(u32 *)(arg2 + 0x18) & 0x20000000) {
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
            SHIFT_80155294(*(s32 *)(other + 0x60));
        } else if (dx < dz) {
            v.x = scratch_vec.x < 0.0f ? -0.1f : 0.1f;
            v.z = v.y = 0.0f;
            SHIFT_80155294(*(s32 *)(other + 0x60));
            v.x = 0.0f;
            v.y = 0.0f;
            if (scratch_vec.z < 0.0f) {
                v.z = -0.010000001f;
            } else {
                v.z = 0.010000001f;
            }
            SHIFT_80155294(*(s32 *)(other + 0x60));
        } else {
            v.x = 0.0f;
            v.y = 0.0f;
            if (scratch_vec.z < 0.0f) {
                v.z = -0.1f;
            } else {
                v.z = 0.1f;
            }
            SHIFT_80155294(*(s32 *)(other + 0x60));
            v.x = scratch_vec.x < 0.0f ? -0.010000001f : 0.010000001f;
            v.z = v.y = 0.0f;
            SHIFT_80155294(*(s32 *)(other + 0x60));
        }
        if (moved != 0) {
            return moved;
        }
    }
    if (angle_difference_abs((s32)(10430.38043493439 * atan2_float(radial.x, radial.z)), *(s32 *)(actor + 0x60)) < 0x3000) {
        return 0;
    }
    if (project_actor_to_ground(reinterpret_cast<TObjCollidable *>(actor), reinterpret_cast<Vec *>(actor + 0x44), NULL) != 0) {
        VecCopy__FP3VecPC3Vec(actor + 0x38, actor + 0x44);
        return 1;
    }
    return 1;
}
#pragma pop

s32 respond_to_body_contact(u8 *actor, uaddr other, u8 *contact) {
    if (other != 0 && contact != NULL) {
        switch (*(s32 *)(contact + 0x14)) {
        case 0:
            return resolve_actor_sphere_contact(actor, other, (saddr)contact);
        default:
            return resolve_player_box_contact((u8 *)actor, (u8 *)other, (u8 *)((saddr)contact));
        }
    }
    return 0;
}


s32 TObjPlayer::check_flag_pair(s32 arg0, s32 arg1) {
    if (((arg0 & 0x2000) && (arg1 & 0x100)) || ((arg0 & 0x100) && (arg1 & 0x2000))) {
        return 1;
    }
    if (((arg0 & 0x4000) && (arg1 & 0x200)) || ((arg0 & 0x200) && (arg1 & 0x4000))) {
        return 1;
    }
    if (((arg0 & 0x8000) && (arg1 & 0x400)) || ((arg0 & 0x400) && (arg1 & 0x8000))) {
        return 1;
    }
    if (((arg0 & 0x10000) && (arg1 & 0x800)) || ((arg0 & 0x800) && (arg1 & 0x10000))) {
        return 1;
    }
    if (((arg0 & 0x40000) && (arg1 & 0x1000)) || ((arg0 & 0x1000) && (arg1 & 0x40000))) {
        return 1;
    }
    return 0;
}

s32 TObjPlayer::check_flags(s32 flags, s32 arg1) {
    s32 temp_r5;

    temp_r5 = flags & arg1;
    if (!(temp_r5 & 1)) {
        return 0;
    }
    if (!(temp_r5 & 6)) {
        return 0;
    }
    if (((flags & 8) && (arg1 & 0x2000)) || ((arg1 & 8) && (flags & 0x2000))) {
        return 0;
    }
    if (((flags & 0x10) && (arg1 & 0x4000)) || ((arg1 & 0x10) && (flags & 0x4000))) {
        return 0;
    }
    if (((flags & 0x20) && (arg1 & 0x8000)) || ((arg1 & 0x20) && (flags & 0x8000))) {
        return 0;
    }
    if (((flags & 0x40) && (arg1 & 0x10000)) || ((arg1 & 0x40) && (flags & 0x10000))) {
        return 0;
    }
    if (((flags & 0x80) && (arg1 & 0x40000)) || ((arg1 & 0x80) && (flags & 0x40000))) {
        return 0;
    }
    return 1;
}
s32 test_player_overlap_with_players(TObjCollidable *, TObjCollidable *self, Vec *pos, CollisionBody *out) {
    CollisionBodySet a;
    CollisionBodySet b;
    s32 i;
    TObjCollidable *o;
    CollisionBody *r;

    if (self != 0 && self->bodies != 0) {
        a.colliders = self->bodies;
        a.count = self->body_count;
        VecCopy__FP3VecPC3Vec(&a.position, pos);
        a.facing = self->rotation_y;
        for (i = registered_player_count; i < lbl_805D5868; i++) {
            o = TObjPlayer::get_player_data(i);
            if (o != 0 && o != self && o->test_actor_flags(0x80000800) == 0 && o->bodies != 0 &&
                horizontal_distance_squared(&self->position, &o->position) < 10000.0f) {
                b.colliders = o->bodies;
                b.count = o->body_count;
                VecCopy__FP3VecPC3Vec(&b.position, &o->position);
                b.facing = o->rotation_y;
                r = refresh_actor_body_spheres(a, b);
                if (r != 0) {
                    if (out != 0) {
                        copy_collision_body(out, r);
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 test_player_body_overlap_at(TObjMapWarp *, TObjCollidable *self, const Vec *pos) {
    CollisionBodySet source;
    CollisionBodySet destination;
    s32 i;
    TObjCollidable *other;
    CollisionBody *body;

    if (self != NULL && (body = self->bodies) != NULL) {
        source.colliders = body;
        source.count = self->body_count;
        VecCopy(&source.position, pos);
        source.facing = self->rotation_y;
        for (i = 0; i < lbl_805D5868; i++) {
            other = TObjPlayer::get_player_data(i);
            if (other != NULL && other != self && (body = other->bodies) != NULL) {
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
CollisionBody *refresh_actor_body_spheres(CollisionBodySet a,CollisionBodySet b) {
    CollisionBox boxAA,boxBB,boxAB,boxBA;
    Vec worldA,worldB,offsetA,offsetB;
    CollisionSphere sphereAB,sphereBA,sphereAA,sphereBB;
    CollisionBody * source;
    CollisionBody * destination;
    s32 facingA,facingB,countA,countB;
    s32 flags;
    s32 i,j;
    countA=a.count;countB=b.count;
    for (i=0;i<countA;++i) {
        source=&a.colliders[i];
        flags=source->flags;
        VecCopy__FP3VecPC3Vec(&worldA,&a.position);
        VecCopy__FP3VecPC3Vec(&offsetA,&source->offset);
        facingA=a.facing;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0,facingA);
        rotate_vector_by_current_matrix(&offsetA,&offsetA);
        pop_matrix();
        vec3_add_to(&worldA,&offsetA);
        VecCopy__FP3VecPC3Vec(&source->center,&worldA);
        VecCopy__FP3VecPC3Vec(&worldA,&a.position);
        for (j=0;j<countB;++j) {
            destination=&b.colliders[j];
            if (TObjPlayer::check_flags(flags, destination->flags)) {
                VecCopy__FP3VecPC3Vec(&worldB,&b.position);
                VecCopy__FP3VecPC3Vec(&offsetB,&destination->offset);
                facingB=b.facing;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0,facingB);
                rotate_vector_by_current_matrix(&offsetB,&offsetB);
                pop_matrix();
                vec3_add_to(&worldB,&offsetB);
                VecCopy__FP3VecPC3Vec(&destination->center,&worldB);
                VecCopy__FP3VecPC3Vec(&worldB,&b.position);
                switch (source->shape) {
                case 1:
                    switch(destination->shape) {
                    case 1:
                        build_collision_box_corners(worldA,facingA,source,&boxAA);
                        build_collision_box_corners(worldB,facingB,destination,&boxBB);
                        if (test_box_overlap(boxAA.corners, boxBB.corners)) return destination;
                        break;
                    case 0: default:
                        build_collision_box_corners(worldA,facingA,source,&boxAB);
                        test_collider_sphere_overlap_xz(worldB,destination,&sphereAB);
                        if (test_box_sphere_contact(boxAB.corners, &sphereAB)) return destination;
                        break;
                    }
                    break;
                case 0: default:
                    switch(destination->shape) {
                    case 1:
                        test_collider_sphere_overlap_xz(worldA,source,&sphereBA);
                        build_collision_box_corners(worldB,facingB,destination,&boxBA);
                        if (test_box_sphere_contact(boxBA.corners, &sphereBA)) return destination;
                        break;
                    case 0: default:
                        test_collider_sphere_overlap_xz(worldA,source,&sphereAA);
                        test_collider_sphere_overlap_xz(worldB,destination,&sphereBB);
                        if (spheres_overlap(&sphereAA, &sphereBB)) return destination;
                        break;
                    }
                    break;
                }
            }
        }
    }
    return 0;
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
            VecCopy__FP3VecPC3Vec(&source.position, &position);
            source.facing = rotation_y;
            destination.colliders = target->bodies;
            destination.count = target->body_count;
            VecCopy__FP3VecPC3Vec(&destination.position, &target->position);
            destination.facing = target->rotation_y;
            result = refresh_actor_body_spheres(source, destination);
            if (result != NULL) {
                TObjPlayer::find_or_alloc_slot(reinterpret_cast<uaddr>(target));
                return result;
            }
        }
    }
    return NULL;
}

void TObjCollidable::mark_enemy_body_contacts() {
    uaddr obj;
    s32 i;
    Flg_8015610C *f = ((P_8015610C *)this)->f;
    if (f != NULL) {
        f->flags = f->flags & 0xFFEFFFFF;
        for (i = 0; i < lbl_805D5868; i++) {
            obj = TObjPlayer__data_8050D460[i];
            if (obj == 0U) {
                break;
            }
            u16 t = ((TObjBase *)(obj))->get_entity_id();
            if (t >= 0x1000U && t < 0x4000U && check_actor_body_contact((Obj_80156268 *)obj, 100.0f) != 0U) {
                ((P_8015610C *)this)->f->flags = ((P_8015610C *)this)->f->flags | 0x100000;
            }
        }
    }
}

void TUnk_804928CC::update_body_contact_flag(f32 range) {
    Hit_801561C4 *hit = ((TObjPlayer_801561C4 *)this)->hit;
    if (hit) {
        hit->flags &= ~0x80000;
        for (s32 i = 0; i < registered_player_count; i++) {
            void *entry = ((void * *)&TObjPlayer__data_8050D460)[i];
            if (entry && check_actor_body_contact((Obj_80156268 *)entry, range)) {
                ((TObjPlayer_801561C4 *)this)->hit->flags |= 0x80000;
            }
        }
    }
}

u32 TObjCollidable::check_actor_body_contact(void *o_arg, f32 range) {
    Obj_80156268 *self = (Obj_80156268 *)this;
    Obj_80156268 *o = (Obj_80156268 *)o_arg;
    CollisionBodySet a;
    CollisionBodySet b;
    u8 *hit;

    if (o != self && o != 0 && !(this->actorFlags & 0x800) && !(o->flags & 0x80000800)) {
        if (range * range < horizontal_distance_squared(&self->pos, &o->pos)) {
            return 0;
        }
        if (this->bodies != 0 && o->a4 != 0) {
            a.colliders = this->bodies;
            a.count = self->a8;
            VecCopy__FP3VecPC3Vec(&a.position, &self->pos);
            a.facing = this->rotation_y;
            b.colliders = o->a4;
            b.count = o->a8;
            VecCopy__FP3VecPC3Vec(&b.position, &o->pos);
            b.facing = o->f60;
            hit = (u8 *)refresh_actor_body_spheres(a, b);
            if (hit != 0) {
                TObjPlayer::find_or_alloc_slot((uaddr)o);
                *(u32 *)(hit + 0x18) |= 0x04000000;
                return (uaddr)hit;
            }
        }
    }
    return 0;
}

void TObjCollidable::update_enemy_collision_flags() {
    TObjPlayer *player;
    s32 j;
    void *actor_body_contact;
    void *temp_r3_3;
    void *temp_r5;
    temp_r5 = *(void **)((s8 *)this + 0xA4);
    if (temp_r5 != NULL) {
        *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFEDFFFFF);
        for (j = registered_player_count + registered_enemy_count; j < (s32) lbl_805D5868; j++) {
            player = TObjPlayer::get_player_data(j);
            if (player != NULL) {
                actor_body_contact = find_actor_body_contact(player, 10000.0f);
                if ((actor_body_contact != NULL) && (TObjPlayer::check_flag_pair(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 0x18), *(s32 *)((s8 *)actor_body_contact + 0x18)) == 0) && (respond_to_body_contact((u8 *)this, (uaddr)player, (u8 *)actor_body_contact) != 0)) {
                    temp_r3_3 = *(void **)((s8 *)this + 0xA4);
                    *(s32 *)((s8 *)temp_r3_3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0x18) | 0x01200000);
                }
            }
        }
    }
}

void check_enemy_body_collisions(TObjCollidable *actor) {
    TObjPlayer *other;
    s32 i;
    CollisionBody *contact;
    if (actor->bodies != 0) {
        actor->bodies->flags &= ~0x900000;
        for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
            other = TObjPlayer::get_player_data(i);
            if (other != 0) {
                if (actor->room == other->room || actor->entity_id < 0x1000) {
                    contact = actor->find_actor_body_contact(other, 10000.0f);
                    if (contact != 0) {
                        actor->bodies->flags |= 0x100000;
                        if (TObjPlayer::check_flag_pair(actor->bodies->flags, contact->flags) == 0 &&
                            respond_to_body_contact((u8 *)actor, (uaddr)other, (u8 *)contact) != 0) {
                            actor->bodies->flags |= 0x800000;
                        }
                    }
                }
            }
        }
    }
}

void TObjCollidable::check_object_collisions() {
    TObjPlayer *player_data;
    s32 j;
    void *actor_body_contact;
    void *temp_r3_3;
    void *temp_r3_4;
    void *temp_r5;
    temp_r5 = *(void **)((s8 *)this + 0xA4);
    if (temp_r5 != NULL) {
        *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFB7FFFF);
        for (j = 0; j < (s32) registered_player_count; j++) {
            player_data = TObjPlayer::get_player_data(j);
            if ((player_data != NULL) && (player_data->entity_id < 0x1000U)) {
                actor_body_contact = find_actor_body_contact(player_data, 10000.0f);
                if (actor_body_contact != NULL) {
                    temp_r3_3 = *(void **)((s8 *)this + 0xA4);
                    *(s32 *)((s8 *)temp_r3_3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0x18) | 0x80000);
                    if ((TObjPlayer::check_flag_pair(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 0x18), *(s32 *)((s8 *)actor_body_contact + 0x18)) == 0) && (respond_to_body_contact((u8 *)this, (uaddr)player_data, (u8 *)actor_body_contact) != 0)) {
                        temp_r3_4 = *(void **)((s8 *)this + 0xA4);
                        *(s32 *)((s8 *)temp_r3_4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_4 + 0x18) | 0x400000);
                    }
                }
            }
        }
        if (!(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 0x18) & 0x480000)) {
            refresh_collision_body_centers();
        }
    }
}
void TObjCollidable::update_collisions() { check_object_collisions(); check_enemy_body_collisions(this); }
void TObjCollidable::clear_collision_bodies() {
    body_flags = NULL;
    bodies = NULL;
}
void*TObjCollidable::set_collision_body(void*a1) {
    body_count = 1;
    bodies = (CollisionBody *)a1;
    body_flags = &own_body_flags;
    refresh_collision_body_centers();
    return bodies;
}

void free_collision_body_parts(G_80156720 *arg0) {
    u8 *p = arg0->f9c;
    if (p != 0) {
        if (p != 0) {
            mem_free((p - 0x10));
        }
        arg0->f9c = 0;
    }
    if (arg0->fa4 != 0) {
        mem_free(arg0->fa4);
        arg0->fa4 = 0;
    }
}

Part_80156780 *init_collision_body_parts(Obj_80156780 *self, Part_80156780 *src, s32 count) {
    s32 n;
    s32 i;
    if (self->parts == 0) {
        self->count = count;
        self->parts = (Part_80156780 *)mem_alloc(self->count * 0x2c);
        for (i = 0; i < self->count; i++) {
            copy_collision_body((CollisionBody *)&self->parts[i], (const CollisionBody *)src++);
        }
        ((TObjCollidable *)self)->refresh_collision_body_centers();
    }
    if (self->f9c == 0) {
        n = self->count;
        self->f9c = __construct_new_array(mem_alloc(n * 4 + 0x10), (void (*)(void *))__ct__8FlagWordFv, 0, 4, n);
    }
    return self->parts;
}

s32 project_actor_to_ground(TObjCollidable *actor, Vec *pos, Vec *normal) {
    Vec v;
    CsnHit *hit;
    u16 r;
    CsnGroundCandidates *coll;
    s32 flags;
    VecCopy__FP3VecPC3Vec(&v, pos);
    v.y += 10.0f;
    r = TObjRoomId__sub_801A1DB8(actor->entity_id);
    flags = 0x15;
    if (r == 0) {
        flags = 0x55;
    }
    coll = actor->ground_cache;
    if (coll != 0) {
        hit = csnVectorUnder(&v, coll->groups, flags);
    } else {
        hit = csnVecterUnder(&v, flags);
    }
    if (hit == NULL) {
        return 0;
    }
    VecCopy__FP3VecPC3Vec(pos, &hit->contact->point);
    if (normal != NULL) {
        VecCopy__FP3VecPC3Vec(normal, &hit->contact->normal);
    }
    return 1;
}

void TObjCollidable::reset_motion_fields() {
    if (ground_cache != NULL) {
        ground_cache->clear();
    }
}
void TObjPlayer__sub_80156934(void) { TObjPlayer::clear_item_table(); TObjPlayer::init_all_slots(); }
void TObjPlayer::reset() { (*(int *)&lbl_805D5868) = 0; (*(int *)&registered_player_count) = 0; (*(int *)&registered_enemy_count) = 0; (*(int *)&registered_entity_count) = 0; TObjPlayer::clear_item_table(); TObjPlayer::init_all_slots(); }
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
    sub_80156A68();
}

void TObjCollidable::sub_80156A68() { hit_receive_state = 0; }
CursorAction::CursorAction() { kind = CURSOR_ACTION_NONE; }
s32 TObjCollidable::access_object_saved_state(void *lobby, s16 arg2) {
    s16 temp_r31;
    u8 *temp_r3;
    temp_r3 = *(u8 * *)&this->set_entry;
    if (temp_r3 == NULL) {
        return 0;
    }
    temp_r31 = *(s16 *)((s8 *)temp_r3 + 4);
    if ((temp_r31 < 0) || (temp_r31 > 0xB9F)) {
        return 0;
    }
    if (arg2 == 0) {
        ((TLobby *)(quest_object_entries + (temp_r31 * 4)))->copy_short_fields(lobby);
    }
    if (arg2 == 1) {
        ((TLobby *)lobby)->copy_short_fields((void *) (quest_object_entries + (temp_r31 * 4)));
    }
    return 1;
}

saddr TObjPlayer__data_8050D460[0x18C];
saddr player_battle_param_table[0x10];
unsigned char lbl_8050DAD0[0x80];
