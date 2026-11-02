#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/TObjMotion.h"
#include "pso/collision/ActorBodyContact.h"
#include "pso/math/AngleLookup.h"

struct Elt_801542CC { char pad[0x18]; s32 f18; char pad2[0x2C - 0x1C]; };

struct ByteBlock_C { u8 bytes[0xc]; };

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_60 { u8 bytes[0x60]; };

#include <stddef.h>
struct Stack_80155050 {
    s32 sp8;
    f32 spC;
    u8 pad_10[0x4];
    f32 sp14;
};

struct Vec_801550DC { f32 x, y, z; };

struct CollisionVector_80155FBC { f32 x,y,z; };

struct CollisionBody_80155FBC { void* colliders; s32 count; Vec position; s32 facing; };
struct CollisionVector_80155C54 { f32 x,y,z; };
struct Collider_80155C54 { CollisionVector_80155C54 offset; f32 radius; u32 unknown10; s32 shape; s32 flags; CollisionVector_80155C54 world; u32 unknown28; };
struct CollisionBox_80155C54 { f32 data[24]; };
struct CollisionSphere_80155C54 { CollisionVector_80155C54 center; f32 radius; };

struct E_801547E0 { u8 pad[0xc]; f32 f; u8 pad2[0x2c - 0x10]; };

struct Obj_801547E0 { u8 pad[0xa4]; E_801547E0 *arr; };

struct Part_80156780 { u8 pad[0x2c]; };

struct Obj_80156780 { u8 pad[0x9c]; void *f9c; u8 pad2[4]; Part_80156780 *parts; s32 count; };

struct Ent_80154CB4 { u8 pad[0x1c]; u16 id; };

struct State_80154954 { s16 a; s16 b; };

struct Pkt_80154954 { s16 hdr; u16 id; s32 state; s32 kind; };

struct Obj_80154954 { u8 pad[4]; s16 kind; };

struct Player_80154954 { u8 pad[0x1C]; u16 id; u8 pad1e[0x80 - 0x1E]; Obj_80154954 *obj; };

struct Coll_801564A0 { u8 pad[0x18]; s32 flags; };

struct Player_801564A0 { u8 pad[0x1C]; u16 id; u8 pad1e[0x28 - 0x1E]; s16 room; u8 pad2a[0xA4 - 0x2A]; Coll_801564A0 *coll; };

struct Hit_801561C4 { u8 pad[0x18]; u32 flags; };

struct TObjPlayer_801561C4 { u8 pad[0xA4]; Hit_801561C4 *hit; };


struct G_80156720 { u8 pad0[0x9C]; u8 *f9c; u8 pad_A0[4]; void *fa4; };

struct Flg_8015610C { u8 pad[0x18]; u32 flags; };

struct P_8015610C { u8 pad[0xA4]; Flg_8015610C *f; };


struct Vec_80156844 { f32 x, y, z; };

struct Hit_80156844 { u32 f0; Vec_80156844 *v; };

struct Obj_80154B60 { u8 pad[0x1C]; u16 id; };
struct Obj_801559D0 { u8 pad38[0x38]; CollisionVector_80155FBC pos; u8 pad44[0x60 - 0x44]; s32 f60; u8 pad64[0xA4 - 0x64]; u32 a4; s32 a8; };
struct Obj_80156268 { u8 pad0[0x30]; u32 flags; u8 pad34[4]; CollisionVector_80155FBC pos; u8 pad44[0x60 - 0x44]; s32 f60; u8 pad64[0xA4 - 0x64]; void *a4; s32 a8; };

struct V3_80154E3C { f32 x, y, z; };

struct Ent_80154E3C { u8 pad0[0x1C]; V3_80154E3C v; u8 pad[0x2C - 0x28]; };

struct Obj_80154E3C { u8 pad0[0x38]; V3_80154E3C pos; u8 pad44[0x60 - 0x44]; s32 f60; u8 pad64[0xA4 - 0x64]; Ent_80154E3C *ents; s32 count; };

struct Vec_80154EF8 { f32 x, y, z; };

struct Box_80154EF8 { u8 pad[0xC]; f32 hx; f32 hz; u8 pad2[0x1C - 0x14]; Vec_80154EF8 pos; };

struct Obj_801547E0;
#define SHIFT_80155294(yaw)                                              \
    push_matrix_from(identity_matrix);                                      \
    rotate_matrix_y(0, (yaw));                                           \
    rotate_vector_by_current_matrix(&v, &v);                                    \
    pop_matrix();                                                        \
    vec3_add_to(&v, arg0 + 0x38);                           \
    if (PATG_80155294(arg0, &v, 0) != 0) {                     \
        VecCopy__FP3VecPC3Vec(arg0 + 0x38, &v);                          \
        moved = 1;                                                       \
    }
struct Vec_80155294 { f32 x, y, z; };

#include "pso/protocol/subcmd_6x.h"
#include "pso/TObject.h"
#include "pso/misc/TLobby.h"
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
s32 test_player_overlap_with_players(void *arg0, Obj_801559D0 *self, CollisionVector_80155FBC *pos, void *out);
s32 VecCopy__FP3VecPC3Vec(void *, void *);
s32 vec3_add_to(void *, void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 rotate_vector_by_current_matrix(void *, void *);
s32 pop_matrix();
extern f32 identity_matrix[12];
u8 * TObjPlayer__sub_80155028(s32 arg0, s32 arg1);
s32 build_collision_box_corners(Vec pos, s32 facing, CollisionBody *body, CollisionBox_80155C54 *out);
s32 subtract_vector(void *, void *);
extern s32 enable_v2_features;
f32 get_collision_body_radius(Obj_801547E0 *self, s32 i);
extern Vec_80155294 scratch_vec;
f64 atan2_float(f32, f32);
extern const f64 lbl_804400F0;
s32 angle_difference_abs(s32, s32);
void *find_entity_by_id(u16 id);
extern s32 quest_object_entries;
void handle_6x0B_update_object_state(G_UpdateObjectState_6x0B *packet);
}
s32 resolve_player_box_contact(u8 *arg0, u8 *arg1, u8 *arg2);
struct Obj_80156844 { u8 pad[0x1C]; u16 room; u8 pad2[0x90 - 0x1E]; void *f90; };

extern "C" {
void TObjPlayer__sub_801550B8(u8 *arg0, u8 *arg1);
void TObjPlayer__sub_8015434C(CollisionBody_80155FBC *set, s32 start, s32 count);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern s32 registered_entity_count;
void TObjPlayer__sub_8015431C(u8 *arg0);
int TObjPlayer__sub_80154E28(int a0, int a1);
int get_player_data__10TObjPlayerFi(int a0);
extern s32 lbl_805D5868;
void TObjPlayer__sub_80156934(void);
f32 horizontal_distance_squared(void *, void *);
s32 angle_diff_s16(s32 a, s32 b);
s32 normalize_vector(void *);
void* refresh_actor_body_spheres(CollisionBody_80155FBC, CollisionBody_80155FBC);
extern s32 TObjPlayer__data_8050D460[];
void *mem_alloc(u32 size);
void *__construct_new_array(void *, void (*)(void *), void *, s32, s32);
Part_80156780 *init_collision_body_parts(Obj_80156780 *self, Part_80156780 *src, s32 count);
void *get_player_by_client_id(u32 id);
void TLobby__sub_80156BA8(void *p);
void check_enemy_body_collisions(void *arg0);
extern unsigned char lbl_8050DAD0[];
extern int player_unique_pair_entry_count;
void mem_free(void *p);
void free_collision_body_parts(G_80156720 *arg0);
u16 get_entity_id(int);
void *memcpy(void *, const void *, u32);
s32 *csnVectorUnder(s32 arg0, u32 *arg1, s32 arg2);
s32 *csnVecterUnder(s32 origin, s32 mask);
u16 TObjRoomId__sub_801A1DB8(u16);
s32 project_actor_to_ground(Obj_80156844 *self, Vec_80156844 *pos, Vec_80156844 *normal);
s32 test_box_overlap__10TObjPlayerFPvPv(CollisionBox_80155C54*,CollisionBox_80155C54*);
s32 test_box_sphere_contact(CollisionBox_80155C54*,CollisionSphere_80155C54*);
}
s32 test_collider_sphere_overlap_xz(s32 arg0, u8 *arg1, u32 arg2);
extern int player_battle_param_table[];
s32 resolve_actor_sphere_contact(u8 *arg0, s32 arg1, s32 arg2);
s32 respond_to_body_contact(u8 *arg0, u32 arg1, u8 *arg2);
s32 spheres_overlap(u8 *arg0, u8 *arg1);
extern "C" {
void TOTrapAncient02R__sub_80154D78(void);
void TObjPlayer__sub_801542F4(s32 a);
void reset_global_table(void);
u8 test_elt_flag__13TUnk_80493450Fll(void *arg0, s32 arg1, s32 arg2);
s32 obj_is_hit_receivable(void *);
s32 obj_testFlags30__14TObjCollidableFUl(void *, u32);
void *resolve_hittable_target(u16 actorId, s16 collider);
u16 register_entity_by_id(void*);
int memset(void*, void*, void*);

void TObjPlayer::apply_status_effect(s32 a) {
    TObjPlayer__sub_8015434C((CollisionBody_80155FBC *)a, 0, registered_player_count);
}

void TObjPlayer__sub_801542F4(s32 a) {
    TObjPlayer__sub_8015434C((CollisionBody_80155FBC *)a, registered_player_count, lbl_805D5870);
}

void TObjPlayer__sub_8015431C(u8 *arg0) {
    TObjPlayer__sub_8015434C((CollisionBody_80155FBC *)arg0, registered_player_count + lbl_805D5870, registered_entity_count);
}

#pragma push
#pragma fp_contract on
// Places the set's bodies at its position and records (in the unique pair
// table) every body of the `count` registered actors from table slot `start`
// that one of them touches.
void TObjPlayer__sub_8015434C(CollisionBody_80155FBC *set, s32 start, s32 count) {
    CollisionBody *body;
    s32 n;
    int facing;
    f32 s;
    f32 c;
    int flags;
    s32 shape;
    s32 *entry;
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
        CollisionBox_80155C54 box;
        CollisionSphere_80155C54 sphere;
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
                    CollisionBox_80155C54 other_box;
                    Vec offset;
                    CollisionSphere_80155C54 other_sphere;
                    hit = NULL;
                    if (TObjPlayer::check_flags(flags, other_body->flags)) {
                        rotate_vector_by_current_matrix(other_body, &offset);
                        other_body->center.x = other_pos.x + offset.x;
                        other_body->center.y = other_pos.y + offset.y;
                        other_body->center.z = other_pos.z + offset.z;
                        if (other_body->shape == 1) {
                            build_collision_box_corners(other_pos, other_facing, other_body, &other_box);
                            if (shape == 1) {
                                if (test_box_overlap__10TObjPlayerFPvPv(&box, &other_box)) {
                                    hit = other_body;
                                }
                            } else if (test_box_sphere_contact(&other_box, &sphere)) {
                                hit = other_body;
                            }
                        } else {
                            other_sphere.center.x = other_body->center.x;
                            other_sphere.center.y = 0.0f;
                            other_sphere.center.z = other_body->center.z;
                            other_sphere.radius = other_body->radius;
                            if (shape == 1) {
                                if (test_box_sphere_contact(&box, &other_sphere)) {
                                    hit = other_body;
                                }
                            } else if (spheres_overlap((u8 *)&sphere, (u8 *)&other_sphere)) {
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

void reset_global_table(void) { memset(lbl_8050DAD0, (void*)0, (void*)128); player_unique_pair_entry_count = 0; }

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

    entry = (void *)*(u32 *)((s8 *)arg0 + 0xA4);
    if (entry != NULL) {
        entry = (void *)((u8 *)entry + (index * 0x2C));
        *(s32 *)((s8 *)entry + 0x18) =
            (s32)(*(s32 *)((s8 *)entry + 0x18) | flags);
    }
}

u8 TUnk_80493450::test_elt_flag(s32 arg1, s32 arg2) {
    struct Elt_801542CC *temp_r3;

    temp_r3 = *(struct Elt_801542CC * *)&this->bodies;
    if (temp_r3 != 0) {
        return (u8) ((arg2 & temp_r3[arg1].f18) != 0);
    }
    return 0U;
}

f32 get_collision_body_radius(Obj_801547E0 *self, s32 i) {
    if (self->arr != 0) {
        return self->arr[i].f;
    }
    return 0.0f;
}

void *resolve_hittable_target(u16 actorId, s16 collider) {
    void *target = find_entity_by_id(actorId);
    if (target == NULL) {
        return NULL;
    }
    if (((TObject *)target)->all_parents_unqueued_for_destruction() == 0 || obj_testFlags30__14TObjCollidableFUl(target, 0x04040800) != 0) {
        return NULL;
    }
    if (((s32 (*)(void *, s32, s32))test_elt_flag__13TUnk_80493450Fll)(target, collider, 1) == 0) {
        return NULL;
    }
    if (obj_is_hit_receivable(target) == 0) {
        return NULL;
    }
    return target;
}

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

u16 TObjCollidable::unregister_object_by_id() {
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
        u16 k = get_entity_id((int)this);
        if (k < 0x1000) {
            registered_player_count--;
        } else if (k < 0x4000) {
            lbl_805D5870--;
        } else {
            registered_entity_count--;
        }
        TObjPlayer__data_8050D460[lbl_805D5868] = 0;
        return id;
    }
    return 0xFFFF;
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
    t = get_entity_id((int)o);
    if (t < 0x1000) {
        registered_player_count++;
    } else if (t < 0x4000) {
        lbl_805D5870++;
    } else {
        registered_entity_count++;
    }
    return id;
}
#undef TBL
#undef o

void *find_entity_by_id(u16 id) {
    s32 lo;
    s32 mid;
    s32 hi;
    Ent_80154CB4 *e;
    if (id == 0xffff) {
        return 0;
    }
    if (id < 12) {
        return get_player_by_client_id(id);
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
        return e;
    }
    return 0;
}

void TOTrapAncient02R__sub_80154D78(void) {  }
void TObjPlayer::init_all_slots() { { int i; for (i = 0; i < 16; i++) { TObjPlayer__sub_80154E28((int)((void*)i), (int)((void*)0)); } } }
s32 TObjPlayer::find_or_alloc_slot(u32 arg0) {
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
    V3_80154E3C sp8;
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

s32 build_collision_box_corners(Vec origin, s32 facing, CollisionBody *body, CollisionBox_80155C54 *out) {
    Vec_80154EF8 pos;
    Vec_80154EF8 c[8];
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
        TObjPlayer__sub_80155028((s32)out, (s32)c);
        return 1;
    }
    return 0;
}

u8 * TObjPlayer__sub_80155028(s32 arg0, s32 arg1) {
    *(ByteBlock_60 *)(arg0) = *(const ByteBlock_60 *)(arg1);
    return (u8 *)arg0;
}
}

s32 test_collider_sphere_overlap_xz(s32 arg0, u8 *arg1, u32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_80155050, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80155050, spC) == 0x4) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80155050, sp14) == 0xC) ? 1 : -1];
    Stack_80155050 stack;
    VecCopy__FP3VecPC3Vec(&stack.sp8, arg1 + 0x1C);
    stack.spC = 0.0f;
    stack.sp14 = *(f32 *)((s8 *)arg1 + 0xC);
    if (arg2 != 0U) {
        TObjPlayer__sub_801550B8((u8 *)arg2, (u8 *)((void *)&stack.sp8));
        return 1;
    }
    return 0;
}

void TObjPlayer__sub_801550B8(u8 *arg0, u8 *arg1) {
    *(ByteBlock_C *)(arg0) = *(const ByteBlock_C *)(arg1);
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) *(f32 *)((s8 *)arg1 + 0xC);
}

s32 resolve_actor_sphere_contact(u8 *arg0, s32 arg1, s32 arg2) {
    Vec_801550DC displacement;
    f32 tangentScale;
    s32 var_r31;
    u16 temp_r3;
    if (horizontal_distance_squared(arg0 + 0x38, arg0 + 0x44) < 9.9999994e-11f) {
        return 0;
    }
    VecCopy__FP3VecPC3Vec((void *)&displacement, (void *)(arg2 + 0x1C));
    subtract_vector(&displacement, arg0 + 0x44);
    temp_r3 = angle_diff_s16((lbl_804400F0 * atan2_float(displacement.x, displacement.z)), (*(s32 *)((s8 *)arg0 + 0x60)));
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
    if ((u16) *(u16 *)((s8 *)arg0 + 0x1C) >= 0x1000U) {
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, var_r31);
        rotate_vector_by_current_matrix(&displacement, &displacement);
        pop_matrix();
        if (1e-5f < ((displacement.x * displacement.x) + (displacement.z * displacement.z))) {
            displacement.y = 0.0f;
            normalize_vector(&displacement);
            displacement.x = (displacement.x * tangentScale);
            displacement.z *= tangentScale;
            vec3_add_to(&displacement, arg0 + 0x44);
            if (project_actor_to_ground((Obj_80156844 *)(arg0), (Vec_80156844 *)(&displacement), (Vec_80156844 *)(0)) != 0) {
                VecCopy__FP3VecPC3Vec(arg0 + 0x38, &displacement);
                return 1;
            }
        }
    }
    if (project_actor_to_ground((Obj_80156844 *)(arg0), (Vec_80156844 *)(arg0 + 0x44), (Vec_80156844 *)(0)) != 0) {
        VecCopy__FP3VecPC3Vec(arg0 + 0x38, arg0 + 0x44);
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
struct Obj_80156844;
struct Vec_80156844;
#define PATG_80155294 ((s32 (*)(void *, void *, int))project_actor_to_ground)
s32 resolve_player_box_contact(u8 *arg0, u8 *arg1, u8 *arg2) {
    Vec_80155294 radial;
    Vec_80155294 v;
    s32 moved;
    if (arg1 == NULL || arg2 == NULL) {
        return 0;
    }
    VecCopy__FP3VecPC3Vec(&radial, arg0 + 0x44);
    subtract_vector(&radial, arg2 + 0x1C);
    if (enable_v2_features != 0 && *(u16 *)(arg0 + 0x1C) < 0x1000) {
        f32 hw = *(f32 *)(arg2 + 0x10);
        f32 hd = *(f32 *)(arg2 + 0xC);
        f32 xl;
        f32 zl;
        f32 xx;
        f32 zz;
        f32 dx;
        f32 dz;
        moved = 0;
        xl = hw * hw + get_collision_body_radius((Obj_801547E0 *)arg0, 0);
        zl = hd * hd + get_collision_body_radius((Obj_801547E0 *)arg0, 0);
        VecCopy__FP3VecPC3Vec(&scratch_vec, &radial);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, -*(s32 *)(arg1 + 0x60));
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
            SHIFT_80155294(*(s32 *)(arg0 + 0x60));
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
            SHIFT_80155294(*(s32 *)(arg1 + 0x60));
        } else if (dx < dz) {
            v.x = scratch_vec.x < 0.0f ? -0.1f : 0.1f;
            v.z = v.y = 0.0f;
            SHIFT_80155294(*(s32 *)(arg1 + 0x60));
            v.x = 0.0f;
            v.y = 0.0f;
            if (scratch_vec.z < 0.0f) {
                v.z = -0.010000001f;
            } else {
                v.z = 0.010000001f;
            }
            SHIFT_80155294(*(s32 *)(arg1 + 0x60));
        } else {
            v.x = 0.0f;
            v.y = 0.0f;
            if (scratch_vec.z < 0.0f) {
                v.z = -0.1f;
            } else {
                v.z = 0.1f;
            }
            SHIFT_80155294(*(s32 *)(arg1 + 0x60));
            v.x = scratch_vec.x < 0.0f ? -0.010000001f : 0.010000001f;
            v.z = v.y = 0.0f;
            SHIFT_80155294(*(s32 *)(arg1 + 0x60));
        }
        if (moved != 0) {
            return moved;
        }
    }
    if (angle_difference_abs((s32)(lbl_804400F0 * atan2_float(radial.x, radial.z)), *(s32 *)(arg0 + 0x60)) < 0x3000) {
        return 0;
    }
    if (PATG_80155294(arg0, arg0 + 0x44, 0) != 0) {
        VecCopy__FP3VecPC3Vec(arg0 + 0x38, arg0 + 0x44);
        return 1;
    }
    return 1;
}
#pragma pop

s32 respond_to_body_contact(u8 *actor, u32 arg1, u8 *arg2) {
    if (arg1 != 0 && arg2 != NULL) {
        switch (*(s32 *)(arg2 + 0x14)) {
        case 0:
            return resolve_actor_sphere_contact(actor, arg1, (s32)arg2);
        default:
            return resolve_player_box_contact((u8 *)actor, (u8 *)arg1, (u8 *)((s32)arg2));
        }
    }
    return 0;
}
extern "C" {

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

s32 TObjPlayer::check_flags(s32 arg0, s32 arg1) {
    s32 temp_r5;

    temp_r5 = arg0 & arg1;
    if (!(temp_r5 & 1)) {
        return 0;
    }
    if (!(temp_r5 & 6)) {
        return 0;
    }
    if (((arg0 & 8) && (arg1 & 0x2000)) || ((arg1 & 8) && (arg0 & 0x2000))) {
        return 0;
    }
    if (((arg0 & 0x10) && (arg1 & 0x4000)) || ((arg1 & 0x10) && (arg0 & 0x4000))) {
        return 0;
    }
    if (((arg0 & 0x20) && (arg1 & 0x8000)) || ((arg1 & 0x20) && (arg0 & 0x8000))) {
        return 0;
    }
    if (((arg0 & 0x40) && (arg1 & 0x10000)) || ((arg1 & 0x40) && (arg0 & 0x10000))) {
        return 0;
    }
    if (((arg0 & 0x80) && (arg1 & 0x40000)) || ((arg1 & 0x80) && (arg0 & 0x40000))) {
        return 0;
    }
    return 1;
}
s32 test_player_overlap_with_players(void *arg0, Obj_801559D0 *self, CollisionVector_80155FBC *pos, void *out) {
    CollisionBody_80155FBC a;
    CollisionBody_80155FBC b;
    s32 i;
    Obj_801559D0 *o;
    void *r;

    if (self != 0 && self->a4 != 0) {
        a.colliders = (void *)self->a4;
        a.count = self->a8;
        VecCopy__FP3VecPC3Vec(&a.position, pos);
        a.facing = self->f60;
        for (i = registered_player_count; i < lbl_805D5868; i++) {
            o = (Obj_801559D0 *)get_player_data__10TObjPlayerFi(i);
            if (o != 0 && o != self && obj_testFlags30__14TObjCollidableFUl(o, 0x80000800) == 0 && o->a4 != 0 &&
                horizontal_distance_squared(&self->pos, &o->pos) < 10000.0f) {
                b.colliders = (void *)o->a4;
                b.count = o->a8;
                VecCopy__FP3VecPC3Vec(&b.position, &o->pos);
                b.facing = o->f60;
                r = refresh_actor_body_spheres(a, b);
                if (r != 0) {
                    if (out != 0) {
                        copy_collision_body((CollisionBody *)out, (const CollisionBody *)r);
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 test_player_body_overlap_at(s32 arg0, u8 *self, void *pos) {
    CollisionBody_80155FBC source;
    CollisionBody_80155FBC destination;
    s32 i;
    u8 *other;
    void *data;

    if (self != NULL && (data = *(void **)(self + 0xA4)) != NULL) {
        source.colliders = data;
        source.count = *(s32 *)(self + 0xA8);
        VecCopy__FP3VecPC3Vec(&source.position, pos);
        source.facing = *(s32 *)(self + 0x60);
        for (i = 0; i < lbl_805D5868; i++) {
            other = (u8 *)get_player_data__10TObjPlayerFi(i);
            if (other != NULL && other != self && (data = *(void **)(other + 0xA4)) != NULL) {
                destination.colliders = data;
                destination.count = *(s32 *)(other + 0xA8);
                VecCopy__FP3VecPC3Vec(&destination.position, other + 0x38);
                destination.facing = *(s32 *)(other + 0x60);
                if (refresh_actor_body_spheres(source, destination) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
#define build_collision_box_corners ((void (*)(CollisionVector_80155C54,s32,Collider_80155C54*,CollisionBox_80155C54*))build_collision_box_corners)
#define test_collider_sphere_overlap_xz ((void (*)(CollisionVector_80155C54,Collider_80155C54*,CollisionSphere_80155C54*))test_collider_sphere_overlap_xz)
void* refresh_actor_body_spheres(CollisionBody_80155FBC a,CollisionBody_80155FBC b) {
    CollisionBox_80155C54 boxAA,boxBB,boxAB,boxBA;
    CollisionVector_80155C54 worldA,worldB,offsetA,offsetB;
    CollisionSphere_80155C54 sphereAB,sphereBA,sphereAA,sphereBB;
    Collider_80155C54* source;
    Collider_80155C54* destination;
    s32 facingA,facingB,countA,countB;
    s32 flags;
    s32 i,j;
    countA=a.count;countB=b.count;
    for (i=0;i<countA;++i) {
        source=&((Collider_80155C54*)a.colliders)[i];
        flags=source->flags;
        VecCopy__FP3VecPC3Vec(&worldA,&a.position);
        VecCopy__FP3VecPC3Vec(&offsetA,source);
        facingA=a.facing;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0,facingA);
        rotate_vector_by_current_matrix(&offsetA,&offsetA);
        pop_matrix();
        vec3_add_to(&worldA,&offsetA);
        VecCopy__FP3VecPC3Vec(&source->world,&worldA);
        VecCopy__FP3VecPC3Vec(&worldA,&a.position);
        for (j=0;j<countB;++j) {
            destination=&((Collider_80155C54*)b.colliders)[j];
            if (TObjPlayer::check_flags(flags, destination->flags)) {
                VecCopy__FP3VecPC3Vec(&worldB,&b.position);
                VecCopy__FP3VecPC3Vec(&offsetB,destination);
                facingB=b.facing;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0,facingB);
                rotate_vector_by_current_matrix(&offsetB,&offsetB);
                pop_matrix();
                vec3_add_to(&worldB,&offsetB);
                VecCopy__FP3VecPC3Vec(&destination->world,&worldB);
                VecCopy__FP3VecPC3Vec(&worldB,&b.position);
                switch (source->shape) {
                case 1:
                    switch(destination->shape) {
                    case 1:
                        build_collision_box_corners(worldA,facingA,source,&boxAA);
                        build_collision_box_corners(worldB,facingB,destination,&boxBB);
                        if (test_box_overlap__10TObjPlayerFPvPv(&boxAA,&boxBB)) return destination;
                        break;
                    case 0: default:
                        build_collision_box_corners(worldA,facingA,source,&boxAB);
                        test_collider_sphere_overlap_xz(worldB,destination,&sphereAB);
                        if (test_box_sphere_contact(&boxAB,&sphereAB)) return destination;
                        break;
                    }
                    break;
                case 0: default:
                    switch(destination->shape) {
                    case 1:
                        test_collider_sphere_overlap_xz(worldA,source,&sphereBA);
                        build_collision_box_corners(worldB,facingB,destination,&boxBA);
                        if (test_box_sphere_contact(&boxBA,&sphereBA)) return destination;
                        break;
                    case 0: default:
                        test_collider_sphere_overlap_xz(worldA,source,&sphereAA);
                        test_collider_sphere_overlap_xz(worldB,destination,&sphereBB);
                        if (spheres_overlap((u8 *)&sphereAA, (u8 *)&sphereBB)) return destination;
                        break;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

#undef build_collision_box_corners
#undef test_collider_sphere_overlap_xz

void*TObjCollidable::find_actor_body_contact(u8*arg1, f32 limit) {
    u8*arg0 = (u8*)this;
    CollisionBody_80155FBC source, destination;
    void* result;
    if (arg1!=arg0 && arg1 && !(*(u32*)(arg0+0x30)&0x800) && !(*(u32*)(arg1+0x30)&0x80000800)) {
        if (limit<horizontal_distance_squared((void *)(arg0+0x38), (void *)(arg1+0x38))) return 0;
        void* data=*(void**)(arg0+0xA4);
        if (data && *(void**)(arg1+0xA4)) {
            source.colliders=data;
            source.count=*(s32*)(arg0+0xA8);
            VecCopy__FP3VecPC3Vec((void *)&source.position, (void *)(arg0+0x38));
            source.facing=*(s32*)(arg0+0x60);
            destination.colliders=*(void**)(arg1+0xA4);
            destination.count=*(s32*)(arg1+0xA8);
            VecCopy__FP3VecPC3Vec((void *)&destination.position, (void *)(arg1+0x38));
            destination.facing=*(s32*)(arg1+0x60);
            result=refresh_actor_body_spheres(source,destination);
            if (result) {TObjPlayer::find_or_alloc_slot((u32)arg1);return result;}
        }
    }
    return 0;
}

void TObjCollidable::mark_enemy_body_contacts() {
    u32 obj;
    s32 i;
    Flg_8015610C *f = ((P_8015610C *)this)->f;
    if (f != NULL) {
        f->flags = f->flags & 0xFFEFFFFF;
        for (i = 0; i < lbl_805D5868; i++) {
            obj = TObjPlayer__data_8050D460[i];
            if (obj == 0U) {
                break;
            }
            u16 t = get_entity_id(obj);
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
    CollisionBody_80155FBC a;
    CollisionBody_80155FBC b;
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
                TObjPlayer::find_or_alloc_slot((u32)o);
                *(u32 *)(hit + 0x18) |= 0x04000000;
                return (u32)hit;
            }
        }
    }
    return 0;
}

void TObjCollidable::update_enemy_collision_flags() {
    s32 temp_r3;
    s32 j;
    void *actor_body_contact;
    void *temp_r3_3;
    void *temp_r5;
    temp_r5 = *(void **)((s8 *)this + 0xA4);
    if (temp_r5 != NULL) {
        *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFEDFFFFF);
        for (j = registered_player_count + lbl_805D5870; j < (s32) lbl_805D5868; j++) {
            temp_r3 = get_player_data__10TObjPlayerFi(j);
            if (temp_r3 != 0) {
                actor_body_contact = find_actor_body_contact((u8*)temp_r3, 10000.0f);
                if ((actor_body_contact != NULL) && (TObjPlayer::check_flag_pair(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 0x18), *(s32 *)((s8 *)actor_body_contact + 0x18)) == 0) && (respond_to_body_contact((u8 *)this, (u32)temp_r3, (u8 *)actor_body_contact) != 0)) {
                    temp_r3_3 = *(void **)((s8 *)this + 0xA4);
                    *(s32 *)((s8 *)temp_r3_3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0x18) | 0x01200000);
                }
            }
        }
    }
}

void check_enemy_body_collisions(void *arg0) {
    Player_801564A0 *self = (Player_801564A0 *)arg0;
    Player_801564A0 *other;
    s32 i;
    Coll_801564A0 *ct;
    if (self->coll != 0) {
        self->coll->flags &= ~0x900000;
        for (i = registered_player_count; i < registered_player_count + lbl_805D5870; i++) {
            other = (Player_801564A0 *)get_player_data__10TObjPlayerFi(i);
            if (other != 0) {
                if (self->room == other->room || self->id < 0x1000) {
                    ct = (Coll_801564A0 *)((TObjCollidable *)self)->find_actor_body_contact((u8 *)other, 10000.0f);
                    if (ct != 0) {
                        self->coll->flags |= 0x100000;
                        if (TObjPlayer::check_flag_pair(self->coll->flags, ct->flags) == 0 &&
                            respond_to_body_contact((u8 *)self, (u32)((s32)other), (u8 *)ct) != 0) {
                            self->coll->flags |= 0x800000;
                        }
                    }
                }
            }
        }
    }
}

void TObjCollidable::check_object_collisions() {
    void *temp_r3;
    s32 j;
    void *actor_body_contact;
    void *temp_r3_3;
    void *temp_r3_4;
    void *temp_r5;
    temp_r5 = *(void **)((s8 *)this + 0xA4);
    if (temp_r5 != NULL) {
        *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFB7FFFF);
        for (j = 0; j < (s32) registered_player_count; j++) {
            temp_r3 = ((void *)get_player_data__10TObjPlayerFi(j));
            if ((temp_r3 != NULL) && ((u16) *(u16 *)((s8 *)temp_r3 + 0x1C) < 0x1000U)) {
                actor_body_contact = find_actor_body_contact((u8*)temp_r3, 10000.0f);
                if (actor_body_contact != NULL) {
                    temp_r3_3 = *(void **)((s8 *)this + 0xA4);
                    *(s32 *)((s8 *)temp_r3_3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0x18) | 0x80000);
                    if ((TObjPlayer::check_flag_pair(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 0x18), *(s32 *)((s8 *)actor_body_contact + 0x18)) == 0) && (respond_to_body_contact((u8 *)this, (u32)temp_r3, (u8 *)actor_body_contact) != 0)) {
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
void TObjPlayer::update_collisions() { check_object_collisions(); check_enemy_body_collisions(this); }
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

s32 project_actor_to_ground(Obj_80156844 *self, Vec_80156844 *pos, Vec_80156844 *normal) {
    Vec_80156844 v;
    Hit_80156844 *hit;
    u16 r;
    void *coll;
    s32 flags;
    VecCopy__FP3VecPC3Vec(&v, pos);
    v.y += 10.0f;
    r = TObjRoomId__sub_801A1DB8(self->room);
    flags = 0x15;
    if (r == 0) {
        flags = 0x55;
    }
    coll = self->f90;
    if (coll != 0) {
        hit = (Hit_80156844 *)csnVectorUnder((s32)&v, (u32 *)coll, flags);
    } else {
        hit = (Hit_80156844 *)csnVecterUnder((s32)&v, flags);
    }
    if (hit == NULL) {
        return 0;
    }
    VecCopy__FP3VecPC3Vec(pos, hit->v);
    if (normal != NULL) {
        VecCopy__FP3VecPC3Vec(normal, &hit->v[1]);
    }
    return 1;
}

void TObjCollidable::reset_motion_fields() {
    if (ground_cache != NULL) {
        ((TObjPlayer *)ground_cache)->clear_ground_candidates();
    }
}
void TObjPlayer__sub_80156934(void) { TObjPlayer::clear_item_table(); TObjPlayer::init_all_slots(); }
void TObjPlayer::reset() { (*(int *)&lbl_805D5868) = 0; (*(int *)&registered_player_count) = 0; (*(int *)&lbl_805D5870) = 0; (*(int *)&registered_entity_count) = 0; TObjPlayer::clear_item_table(); TObjPlayer::init_all_slots(); }
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

void TObjCollidable::sub_80156A68() { *(s16*)((char*)this + 0x96) = 0; }
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
}

s32 TObjPlayer__data_8050D460[0x18C];
int player_battle_param_table[0x10];
unsigned char lbl_8050DAD0[0x80];
