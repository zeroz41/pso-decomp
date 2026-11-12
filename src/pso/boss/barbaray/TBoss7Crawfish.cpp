#define TOBJECT_OUT_OF_LINE_HELPERS
#include <dolphin/mtx.h>
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_803D853C.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stddef.h>
#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/AngleLookup.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/boss/barbaray/TBoss7Crawfish_8030908C.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/render_util.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"

const char *bm_boss7_crawfish_model_names[3] = { "minibaru_body.nj", "minibaru_body_b.nj", NULL };
const char *bm_boss7_crawfish_motion_names[7] = {
    "begin_begin_body.njm", "damage_damage_body.njm", "ride_ride_body.njm", "walk_walk_body.njm",
    "dive_dive_body.njm", "wait_wait_body.njm", NULL
};
BmlResourceDescriptor bm_boss7_crawfish_resource_descriptor = {
    "bm_boss7_crawfish.bml", bm_boss7_crawfish_model_names, bm_boss7_crawfish_motion_names, 2, 6
};
// The action table the ctor installs (name inferred).
TObjMotionAction crawfish_action_table[6] = {
    { 2, 3, 0, 0.6f, 0x0 },
    { 3, 0, 1, 0.6f, 0x0 },
    { 2, 5, 2, 0.7f, 0x0 },
    { 1, 0, 3, 0.6f, 0x0 },
    { 3, 0, 4, 0.6f, 0x0 },
    { 1, 0, 5, 1.9f, 0x0 },
};
const char *TBoss7Crawfish__class_name = "TBoss7Crawfish";
const CollisionBody crawfish_collision_body_desc = {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};
const Vec lbl_8047559C = {0.0f, 0.0f, 0.0f};

struct Stack_80308B38 {
    s32 sp8;
    u8 pad_C[0x2];
    s16 spE;
};

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_80308840_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct Vec_803086A8 { f32 x; f32 y; f32 z; };

struct Msg_803086A8 { void *p; s32 one; Vec_803086A8 pos; s32 id; };

struct Slot_803086A8 { u32 a; s32 b; };

struct Obj_803086A8 { u8 pad[0x3A4]; s32 count; Slot_803086A8 slots[4]; };

struct VBase_18_405891 { char pad[0x18]; };
struct VObj_18_405891 : VBase_18_405891 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual s32 m18(s32, f32);
    virtual void m19();
    virtual s32 m20(s32, f32);
    virtual s32 m21(s32, s32 *, s32, s32, s32);
};

struct Pair_8030895C { s32 id; f32 v; };

extern "C" {
extern s32 game_difficulty_selection;

s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
s32 get_mode__11TCameraCtrlFPv(void *);
s32 obj_is_hit_receivable(u32);
s32 reset_global_table();
Slot_803086A8 *get_attack_entry__16TObjOnlineEndingFi(s32);
s32 apply_hit_to_target__14TBoss7CrawfishFPvPv(void *, void *);
void TBoss7Crawfish__sub_803087D4(s32 arg0, s32 arg1);
int TBoss7Crawfish__sub_80308BEC(void* p);
s32 play_sound_effect(s32, s32, s32, s32);
int change_state__14TBoss7CrawfishFl(void*, int);
int scale_current_matrix(void*);
int post_translate_matrix(void*);
int push_matrix(void);

s32 TBoss7Crawfish::sub_80308688() {
    return (u32) __cntlzw((u32) (75.0f < *(f32 *)((s8 *)this + 0x38))) >> 5;
}

void TBoss7Crawfish::register_attack_hits() {
    Msg_803086A8 msg;
    s32 i;
    Slot_803086A8 *e;
    s32 j;
    reset_global_table();
    msg.p = (u8 *)this + 0x374;
    msg.one = 1;
    VecCopy((Vec *)&msg.pos, (const Vec *)((u8 *)this + 0x38));
    msg.id = this->rotation_y;
    TObjPlayer::apply_status_effect((s32)&msg);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        if ((u32)((Obj_803086A8 *)this)->count < 4) {
            e = get_attack_entry__16TObjOnlineEndingFi(i);
            for (j = 0; j != ((Obj_803086A8 *)this)->count; j++) {
                if (((Obj_803086A8 *)this)->slots[j].a == e->a && ((Obj_803086A8 *)this)->slots[j].b == e->b) {
                    break;
                }
            }
            if (j == ((Obj_803086A8 *)this)->count && obj_is_hit_receivable(e->a) != 0) {
                ((Obj_803086A8 *)this)->slots[((Obj_803086A8 *)this)->count].a = e->a;
                ((Obj_803086A8 *)this)->slots[((Obj_803086A8 *)this)->count].b = e->b;
                ((Obj_803086A8 *)this)->count++;
                apply_hit_to_target__14TBoss7CrawfishFPvPv(((Obj_803086A8 *)this), e);
            }
        }
    }
    reset_global_table();
}

void TBoss7Crawfish__sub_803087D4(s32 arg0, s32 arg1) {
    play_persistent_sound(arg1, arg0, arg0 + 0x38, 0, 0);
}

void TBoss7Crawfish::spawn_effect(s32 arg1) {
    s32 arg0 = (s32)this;
    play_sound_effect(arg1, arg0 + 0x38, 0, 0);
}

typedef char RecoveredGlobal_80308840_main_task_size[sizeof(RecoveredGlobal_80308840_main_task) == 0x34 ? 1 : -1];
s32 TBoss7Crawfish::is_visible() {
    if (get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_80308840_main_task *)&main_task).value) & 0x20) {
        if (3600.0f < horizontal_distance_squared(&lbl_8047559C, &position)) {
            return 0;
        }
        goto block_5;
    }
    if (((VObj_18_26a62c *)(this))->m8(400.0f, 20.0f) == 0) {
        return 0;
    }
block_5:
    return 1;
}

void TBoss7Crawfish::free_child() { if (*(unsigned int *)&this->m_3cc != 0) { ((TObject *)(*(void* *)&this->m_3cc))->queue_destruction(); *(int *)&this->m_3cc = 0; } }

void TBoss7Crawfish::spawn_ground_effects() {
    u8 *arg0 = (u8 *)this;
    Vec position;
    position.x = *(f32 *)((s8 *)arg0 + 0x38);
    position.y = 0.0f;
    position.z = *(f32 *)((s8 *)arg0 + 0x40);
    spawn_particle_effect((&position.x), 0x20D);
    spawn_particle_effect((&position.x), 0x20E);
}

#define arg0 ((s32)arg0_)
#define arg1 ((u8 *)arg1_)
s32 apply_hit_to_target__14TBoss7CrawfishFPvPv(void *arg0_, void *arg1_) {
    Pair_8030895C p;

    u8 *temp_r31;

    if (arg1 != NULL) {
        temp_r31 = (u8 *)(*(u8 **)((s8 *)arg1 + 0));
        if (((TBoss7Crawfish *)arg0_)->sub_80308AA8() != 0) {
            if (((VObj_18_405891 *)(temp_r31))->m18(arg0, 1.0f) != 0) {
                ((VObj_18_405891 *)(temp_r31))->m20(arg0, 1.0f);
            }
        } else if (((TObjChara *)temp_r31)->obj_isState2_324() == 0) {
            if ((s32) game_difficulty_selection == 3) {
                if ((3.0517578125e-05f * (f32) rand()) <= 0.5f) {
                    p.id = 0x10;
                } else {
                    p.id = 0x10;
                }
            } else {
                p.id = 0x12;
            }
            p.v = 100.0f;
            {
                Pair_8030895C q = p;
                ((VObj_18_405891 *)(temp_r31))->m21(arg0, (s32 *)&q, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg1 + 0)) + 0xA4) + (*(s32 *)((s8 *)arg1 + 4) * 0x2C), -1, -1);
            }
        }
    }
}
#undef arg0
#undef arg1

s32 TBoss7Crawfish::sub_80308AA8() {
    return 0.0f == *(f32 *)((s8 *)((u8 *)this) + 0x354);
}

void TBoss7Crawfish::render() { if (is_visible() != 0) { set_texlist(this->texlist); set_motion_packed_rotation(); push_matrix(); post_translate_matrix((char*)this + 0x38); rotate_matrix_yxz((s32)((void*)0), (s32)this->rotation_x, this->rotation_y, this->rotation_z); scale_current_matrix((char*)this + 0x68); draw(); pop_matrix(); clear_motion_packed_rotation(); } }

void TBoss7Crawfish::clear_object_state_exchange() {
    s32 arg0 = (s32)this;
    typedef char sp8_offset[(offsetof(Stack_80308B38, sp8) == 0x0) ? 1 : -1];
    typedef char spE_offset[(offsetof(Stack_80308B38, spE) == 0x6) ? 1 : -1];
    Stack_80308B38 stack;
    if (exchange_object_state__9TObjEnemyFls((void *)arg0, &stack.sp8, 1) != 0) {
        stack.sp8 = 0;
        stack.spE = 0;
        exchange_object_state__9TObjEnemyFls((void *)arg0, &stack.sp8, 0);
    }
}

void TBoss7Crawfish::check_band_and_destroy() {
    s32 arg0 = (s32)this;
    if (((TObjMotion *)arg0)->is_passing_frame(14.0f) != 0) {
        spawn_ground_effects();
    }
    if (0.0f == ((TBoss7Crawfish *)arg0)->get_health()) {
        ((TObject *)arg0)->queue_destruction();
    }
}

int TBoss7Crawfish__sub_80308BEC(void* p) { return change_state__14TBoss7CrawfishFl(p, 5); }

}

void TBoss7Crawfish::update(s32 arg0) {
    if (((TObjMotion *)arg0)->is_passing_frame(8.0f) != 0) {
        ((TBoss7Crawfish *)arg0)->spawn_ground_effects();
        ((TBoss7Crawfish *)arg0)->spawn_effect(0x39E0D);
    }
    ((TBoss7Crawfish *)arg0)->register_attack_hits();
    if (0.0f == ((TBoss7Crawfish *)arg0)->get_health()) {
        ((TObject *)arg0)->queue_destruction();
    }
}

struct Craw_80308D1C {
    u8 pad0[0x60];
    s32 angle;
    u8 pad64[0x308 - 0x64];
    f32 vx, vy, vz;
    u8 pad314[0x3A0 - 0x314];
    f32 *speed;
};

extern "C" {
s32 TBoss7Crawfish__sub_80308ED8(TBoss7Crawfish *self, const Vec *delta);
u16 find_nearest_visible_player(void *, void *, f32);
f32 atan2_float(f32 y, f32 x);
void normalize_vector(void *);
s32 register_attack_hits__14TBoss7CrawfishFv(void *, void *, f32, f32);
void TBoss7Crawfish__sub_803087D4(s32 arg0, s32 arg1);

void TBoss7Crawfish::update_motion_and_release() {
    u8 *arg0 = (u8 *)this;
    f32 *temp_r4;

    temp_r4 = *(f32 * *)&this->m_3a0;
    this->play_speed = 0.1f * (1.0f + *temp_r4);
    register_attack_hits__14TBoss7CrawfishFv(arg0, temp_r4, 1.0f, 0.1f);
    {
        void *temp_ptr = (void *) this->m_3cc;
        if (temp_ptr != NULL) {
            ((TParticleCtrl *)temp_ptr)->set_position((u8 *)&this->position);
        }
    }
    if (TBoss7Crawfish__sub_80308ED8(this, (Vec *)this->unk_308) == 0) {
        ((TBoss7Crawfish *)arg0)->free_child();
        ((TBoss7Crawfish *)arg0)->change_state(3);
        return;
    }
    TBoss7Crawfish__sub_803087D4((s32)arg0, 0x3A80C);
}
void TBoss7Crawfish::aim_at_nearest_player() {
    Craw_80308D1C *o = (Craw_80308D1C *)this;
    u16 r = find_nearest_visible_player(o, &o->vx, 400.0f);
    f32 s = 1.0f + *o->speed;
    if (r != 0xFFFF) {
        normalize_vector(&o->vx);
        o->vx *= s;
        o->vy *= s;
        o->vz *= s;
    } else {
        o->vx = s * sin_table_lookup(o->angle);
        o->vy = 0.0f;
        o->vz = s * cos_table_lookup(o->angle);
    }
    o->angle = 10430.38043493439 * atan2_float(o->vx, o->vz);
    ((TBoss7Crawfish *)o)->change_state(2);
}

}

struct Pair_80308F8C { void *a; s32 b; };

struct Craw_80308F8C {
    u8 pad0[0x38];
    u8 f38[0xA4 - 0x38];
    s32 *fA4;
    u8 padA8[0x326 - 0xA8];
    s16 state;
    u8 pad328[0x3A0 - 0x328];
    s32 *f3A0;
    s32 f3A4;
    Pair_80308F8C pairs[4];
    s32 f3C8;
    s32 f3CC;
};

extern "C" {

void TBoss7Crawfish::update_attack_state() {
    s32 temp_r0;
    s32 temp_r3;
    void *temp_r4;

    temp_r0 = this->m_3c8 - 1;
    this->m_3c8 = temp_r0;
    if (temp_r0 < 0) {
        change_state(1);
    }
    if ((get_floor() == 2) && (is_passing_frame(9.0f) != 0)) {
        temp_r4 = this->bodies;
        if (*(s32 *)((s8 *)temp_r4 + 0x18) & 0x02000000) {
            *(s32 *)((s8 *)temp_r4 + 0x18) &= ~0x02000000;
        }
        if (sub_80308AA8() != 0) {
            spawn_effect(0x3A80A);
        } else {
            spawn_effect(0x3A80B);
        }
    }
    if (*(s32 *)((s8 *)this->bodies + 0x18) & 0x02000000) {
        register_attack_hits();
    }
}
// Moves by delta when the new position is free and still inside the arena (names inferred); returns 1 if moved.
s32 TBoss7Crawfish__sub_80308ED8(TBoss7Crawfish *self, const Vec *delta) {
    Vec pos;
    s32 moved;

    pos.x = self->position.x + delta->x;
    pos.y = self->position.y + delta->y;
    pos.z = self->position.z + delta->z;
    if (self->vfunc_18((u8 *)&pos) != 0) {
        if (self->sub_80308688() != 0) {
            moved = 1;
            self->position.x = pos.x;
            self->position.z = pos.z;
        } else {
            moved = 0;
        }
    } else {
        moved = 0;
    }
    self->update_prev_position();
    return moved;
}
void TBoss7Crawfish::change_state(s32 state) {
    Craw_80308F8C *o = (Craw_80308F8C *)this;
    s32 i;
    o->state = state;
    o->fA4[6] |= 0x02000000;
    switch (o->state) {
    case 0:
        o->f3C8 = o->f3A0[6] - 10;
        break;
    case 1:
        break;
    case 2:
        ((TBoss7Crawfish *)o)->set_anim_timer(0);
        for (i = 0; i < 4; i++) {
            o->pairs[i].a = 0;
            o->pairs[i].b = 0;
        }
        o->f3A4 = 0;
        ((TBoss7Crawfish *)o)->free_child();
        o->f3CC = (s32)create_particle_emitter(o->f38, 0x20B);
        break;
    case 3:
        ((TBoss7Crawfish *)o)->set_anim_timer(4);
        break;
    case 4:
        ((TBoss7Crawfish *)o)->spawn_effect(0x3990E);
        ((TBoss7Crawfish *)o)->set_anim_timer(1);
        break;
    case 5:
        break;
    }
}

}

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u32 TBoss7Crawfish__shared_resource;
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
s32 set_field_b8__10TObjMotionFs(void *, int);
s32 __ct__9TObjEnemyFP7TObject();
extern s32 __vt__14TBoss7Crawfish[];
int TBoss7Crawfish__sub_80308BEC(void *p);
void free_bin_model_request(void*, int);
s32 add_radar_scaled_marker(void *, int, int, int, f32);
s32 __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);

void TBoss7Crawfish::run_task() {
    u8 *arg0 = (u8 *)this;

    if (((s16) this->mode != 5) && (((TObjCollidable *)arg0)->obj_testFlags30(0x800) != 0)) {
        ((TBoss7Crawfish *)arg0)->change_state(4);
    }
    switch (this->mode) {
    case 0:
        ((TBoss7Crawfish *)arg0)->update_attack_state();
        break;
    case 1:
        ((TBoss7Crawfish *)arg0)->aim_at_nearest_player();
        break;
    case 2:
        ((TBoss7Crawfish *)arg0)->update_motion_and_release();
        break;
    case 3:
        TBoss7Crawfish::update((s32)arg0);
        break;
    case 4:
        TBoss7Crawfish__sub_80308BEC((arg0));
        break;
    case 5:
        ((TBoss7Crawfish *)arg0)->check_band_and_destroy();
        break;
    }
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    if (!(*(s32 *)((s8 *)this->bodies + 0x18) & 0x02000000)) {
        submit_cursor_candidate(arg0, -1);
    }
    add_radar_scaled_marker((u8 *)&this->position, -0x5DB4, 1, 1, 2.0f);
    ((TObjMotion *)arg0)->advance_animation();
}

}
TBoss7Crawfish::~TBoss7Crawfish() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    ((TObjCollidable *)this)->clear_collision_bodies();
    this->free_child();
}
extern "C" {

u8 *TBoss7Crawfish__ct(u8 *arg0, s32 arg1, s32 arg2) {
    Vec v;
    __ct__9TObjEnemyFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TBoss7Crawfish;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TBoss7Crawfish__class_name;
    ((TBoss7Crawfish *)arg0)->texlist = TObjFish__sub_8001EDB0(TBoss7Crawfish__shared_resource, 0);
    copy_collision_body((CollisionBody *)(arg0 + 0x374), &crawfish_collision_body_desc);
    ((TObjCollidable *)arg0)->set_collision_body(arg0 + 0x374);
    ((TObjMotion *)arg0)->set_field_d8((s32)crawfish_action_table);
    ((TObjMotion *)arg0)->set_field_dc((int) (*(s32 *)((s8 *)((u8 *)TBoss7Crawfish__shared_resource) + 0x430)));
    ((TBoss7Crawfish *)arg0)->set_anim_timer(2);
    ((TObjMotion *)arg0)->set_animation((((TBoss7Crawfish *)arg0)->requested_action));
    set_field_b8__10TObjMotionFs(arg0, (int) (((TBoss7Crawfish *)arg0)->requested_action));
    ((TObjChara *)arg0)->add_flags_2e4(2);
    ((TBoss7Crawfish *)(arg0))->apply_set_data((void *)arg2);
    if (((TBoss7Crawfish *)arg0)->sub_80308AA8() != 0) {
        ((TObjEnemy *)arg0)->set_param(0x4A);
        ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(8)), (u8 *)(TLobby::dispatch_shared_handler_b(8)), (u8 *)(TLobby::register_object(8)));
        ((TBoss7Crawfish *)arg0)->m_3a0 = dispatch_shared_handler_a__6TLobbyFl(8);
        *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model(TBoss7Crawfish__shared_resource, 0);
    } else {
        ((TObjEnemy *)arg0)->set_param(0x4B);
        ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(9)), (u8 *)(TLobby::dispatch_shared_handler_b(9)), (u8 *)(TLobby::register_object(9)));
        ((TBoss7Crawfish *)arg0)->m_3a0 = dispatch_shared_handler_a__6TLobbyFl(9);
        *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model(TBoss7Crawfish__shared_resource, 1);
    }
    ((TObjChara *)arg0)->get_or_assign_entity_id(0);
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TBoss7Crawfish *)arg0)->clear_object_state_exchange();
    ((TBoss7Crawfish *)arg0)->change_state(0);
    v.z = 0.0f;
    v.y = 0.0f;
    v.x = 0.0f;
    TBoss7Crawfish__sub_80308ED8((TBoss7Crawfish *)arg0, &v);
    if (((TBoss7Crawfish *)arg0)->sub_80308AA8() != 0) {
        *(f32 *)((s8 *)arg0 + 0x70) = 0.8f;
        ((TBoss7Crawfish *)arg0)->scale.y = 0.8f;
        ((TBoss7Crawfish *)arg0)->scale.x = 0.8f;
    } else {
        *(f32 *)((s8 *)arg0 + 0x70) = 1.0f;
        ((TBoss7Crawfish *)arg0)->scale.y = 1.0f;
        ((TBoss7Crawfish *)arg0)->scale.x = 1.0f;
    }
    ((TBoss7Crawfish *)arg0)->m_3cc = 0;
    return arg0;
}

void TBoss7Crawfish::destroy_instance() {
    if ((u32) TBoss7Crawfish__shared_resource != 0U) {
        free_bin_model_request((void*)TBoss7Crawfish__shared_resource, 1);
        TBoss7Crawfish__shared_resource = 0U;
    }
}

void TBoss7Crawfish::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_boss7_crawfish_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TBoss7Crawfish__shared_resource) = var_r0;
}

void TBoss7Crawfish::apply_poison_status() {  }
void TBoss7Crawfish::apply_paralysis() {  }
void TBoss7Crawfish::apply_slow_status() {  }
void TBoss7Crawfish::apply_confusion_status() {  }
void TBoss7Crawfish::apply_movement_ailment(s32) {  }
void TBoss7Crawfish::apply_shock_status() {  }
void TBoss7Crawfish::clear_harmful_statuses() {  }
f32 TBoss7Crawfish::get_health() { return this->play_speed; }
void TBoss7Crawfish::set_anim_timer(s16 v) { this->requested_action = v; }

}

