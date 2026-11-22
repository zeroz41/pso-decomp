#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/EnemyBmlResource.h"
#pragma fp_contract on
#include "pso/map/CsnGroundQuery.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/dd/TObjEneDD_800BA754.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
const char *TObjEneDD__name = "TObjEneDD";
const char *TObjEneDD_ST__name = "TObjEneDD_ST";
extern "C" {
u16 enemy_find_nearest_player_in_range(u8 *self, f32 range);
u16 get_entity_id(void *);
u32 csnLookAt(void *, void *);
void *get_player_by_client_id(s32 i);
}

#include "pso/enemy/dd/TObjEneDD_800BABA4.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/enemy/epsilon/TObjEneEpsilon_800B92AC.h"

#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/unk/TLobby.h"
extern "C" {
f32 atan2_float(f32 y, f32 x);
}
extern "C" {
f32 normalize_vector_xz__FP3Vec(void *, f32, f32);
}
extern const f32 lbl_805D9E80 = -0.1f;
extern const f32 lbl_805D9E84 = 310.0f;
extern const f32 lbl_805D9E88 = 155.0f;
#include "pso/enemy/dd/TObjEneDD_800B9AF8.h"

extern "C" {
int TObjLight__sub_801337F8(void*);
int TObjLight__sub_801337FC(void*);
extern saddr lbl_805D555C;
extern saddr current_scene_light;
}

#include "pso/enemy/dd/TObjEneDD_800B9B84.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"


#include "pso/boss/derolle/TObjBoss2Tunnel.h"
extern "C" {
extern u8 *camera_ctrl_instance;
int is_local_client_floor_leader(void*);
int TObjPlayer__sub_801BA42C(void*);
int freeze_all_players__10TObjPlayerFv(void*);
extern s32 enable_v2_features;
extern s32 game_difficulty_selection;
}


#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/unk/text_803D96A8.h"


struct Stack_800B9D94 {
    s32 sp8;
    u8 pad_C[0x4];
    s32 sp10;
};
extern "C" {
s32 minimap_render_dot(void *, int, int, int);
int restore_scene_lighting(void*);
int select_actor_lighting(void*);
extern int model_render_flags;
}


struct Part_800BA030 { u8 pad[0x2c]; };
struct Obj_800BA030 { u8 pad[0xa4]; Part_800BA030 *parts; s32 count; };
struct Part_800BA084 { u8 pad[0x2c]; };
struct Obj_800BA084 { u8 pad[0xa4]; Part_800BA084 *parts; s32 count; };


#include "pso/enemy/dd/TObjEneDD_800BA138.h"
#include "pso/player/TUnk_804928CC.h"


#include <stddef.h>
struct VBase_18_0c879f { char pad[0x18]; };
struct VObj_18_0c879f : VBase_18_0c879f {
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
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual s32 m21(s32, s32 *, s32, s32, s32);
};
struct Stack_800BA318 {
    s32 sp8;
    f32 spC;
};
struct E_800BA1C8 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };
struct O_800BA1C8 { u8 pad[0xa4]; E_800BA1C8 *entries; s32 count; };
struct E_800BA190 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };
struct O_800BA190 { u8 pad[0xa4]; E_800BA190 *entries; s32 count; };
struct Part_800BA200 { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };
struct Obj_800BA200 { u8 pad[0x30]; u32 flags; u8 pad2[0xa4 - 0x34]; Part_800BA200 *parts; s32 count; };
struct Part_800BA244 { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };
struct Obj_800BA244 { u8 pad[0x30]; u32 flags; u8 pad2[0xa4 - 0x34]; Part_800BA244 *parts; s32 count; };
extern "C" {
struct EneDDBase2_800BA138 { char pad[0x18]; };
struct EneDDObj2_800BA138 : EneDDBase2_800BA138 {
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
    virtual void m15(void *, void *);
    virtual void m16(void *, void *);
};
struct EneDDBase_800BA138 { char pad[0x18]; };
struct EneDDObj_800BA138 : EneDDBase_800BA138 {
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
    virtual void m12(void *, void *, void *);
    virtual void m13(void *, void *, void *);
};
s32 all_parents_unqueued_for_destruction();
u8 * obj_ene_dd_instance;
}


struct E_800BA8A8 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };
struct O_800BA8A8 { u8 pad[0xa4]; E_800BA8A8 *entries; s32 count; };

int TObjEneDD__sub_800BA804(u16 arg0);
void set_collider_contact_low(u8 *arg0);
void set_collider_contact_high(u8 *arg0);
void update_collider_contact_by_height(u8 *arg0, f32 farg0);

#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"

#include "pso/math/MatrixVector.h"


struct Part_800BAAE4 { Vec a; u8 pad[0x10]; Vec b; u8 pad2[4]; };
struct Obj_800BAAE4 { u8 pad[0x38]; Vec pos; u8 pad2[0x1c]; s32 angle; u8 pad3[0x40]; Part_800BAAE4 *parts; };
struct Part_800BA9BC { Vec a; u8 pad[0x10]; Vec b; u8 pad2[4]; };
struct Obj_800BA9BC { u8 pad[0x38]; Vec pos; u8 pad2[0x1c]; s32 angle; u8 pad3[0x40]; Part_800BA9BC *parts; };
struct Col_800BAA2C { u8 pad0[0x1C]; Vec pos; u8 pad28[4]; };
struct Obj_800BAA2C { u8 pad0[0x38]; f32 x; f32 y; f32 z; u8 pad44[0x60 - 0x44]; s32 rot; u8 pad64[0xA4 - 0x64]; Col_800BAA2C *cols; s32 count; };
extern "C" {
int matrix_mult_vec(void *, void *, void *);
void set_part_position__9TObjEneDDFPvPvi(Obj_800BA9BC *self, Vec *v, s32 i);
void update_local_colliders_from_world(Obj_800BAA2C *arg0, Vec *arg1);
}


struct VBase_18_3f4583 { char pad[0x18]; };
struct VObj_18_3f4583 : VBase_18_3f4583 {
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
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void * m101();
};
struct Node_800BAF1C { u8 pad0[4]; Vec *pos; };
struct Node_800BB000 { u8 pad0[4]; u8 *wall; };
extern "C" {
f32 newton_sqrtf(f32);
}
void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
void calc_wall_slide_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
#include <dolphin/mtx.h>


#include <stddef.h>
extern "C" {
f32 fabs_float(f32);
s32 csnVector(void *, void *, int);
s32 VecCopy__FP3VecPC3Vec(void *, void *, s32);
}

#include "pso/boss/goldragon/TBoss8Dragon_800BB650.h"


struct Ent_800BB484 { s16 id; f32 dist; };
extern "C" {
struct EnemyTargetCandidateTable { s32 value; u8 remaining[0x1C]; };
EnemyTargetCandidateTable enemy_target_candidate_table;
typedef struct Ent_800BB388 {
    u8 pad0[0x30];
    s32 flags30;
    u8 pad34[0x38 - 0x34];
    u8 pos[0x2FC - 0x38];
    u8 f2FC[0xC];
}
Ent_800BB388;
u16 enemy_nearest_visible_enemy_sq(Ent_800BB388 *self, f32 range);
s32 collect_enemy_target_candidates(saddr arg0, Ent_800BB484 *out, f32 farg0);
}


#include "pso/enemy/fly/TObjEneBm3Fly.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"


struct Part_800BB780 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };
struct Obj_800BB780 { u8 pad[0x30]; u32 flags; u8 pad1[0x70]; Part_800BB780 *parts; s32 count; u8 pad2[0x230]; s32 f2dc; u8 pad3[0x4c]; s16 f32c; u8 pad4[0x10]; s16 f33e; };
extern "C" {
int submit_cursor_candidate(void*, int);
}


#include "pso/unk/text_800BC4C8.h"

#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
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
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual s32 m84();
    virtual s32 m85(s16, s32);
};
struct Obj_800BB88C {
    u8 pad0[0x28]; s16 f28; s16 f2a; u8 pad2c[0xc];
    f32 f38; f32 f3c; f32 f40; u8 pad44[0x18];
    s32 f5c; s32 f60; s32 f64; u8 pad68[0x354 - 0x68];
    f32 f354[5]; s32 f368; s32 f36c;
};
extern "C" {
s32 subtractive_rng_seed(void *, int);
int fn_800FD8A0(void*);
extern s32 area_random_seed;
struct Base_800BBDD4 { char pad[0x18]; };
struct VObj_800BBDD4 : Base_800BBDD4 {
    virtual void m0(int);
};
extern int lbl_805D5870;
}

s32 tick_period_counter(s32 arg0, s32 *arg1, s32 arg2) {
    s32 temp_r3;
    temp_r3 = *arg1;
    if (temp_r3 >= arg2) {
        *arg1 = 0;
        return 1;
    }
    *arg1 = temp_r3 + 1;
    return 0;
}


int TObjEneDD::get_enemy_count() {  return lbl_805D5870; }

void TObjEneDD::create_instance() {
    void *o;
    o = TObject::operator new(0xB0);
    if (o != NULL) {
        o = __ct__13TUnk_804928CCFP7TObjectP8TObjBase((u8 *)o, 0, 0);
    }
    obj_ene_dd_instance = (u8 *)o;
}

void TObjEneDD::release_resource() {
    if (obj_ene_dd_instance != NULL) {
        if (obj_ene_dd_instance != NULL) {
            ((VObj_800BBDD4 *)obj_ene_dd_instance)->m0(1);
        }
        obj_ene_dd_instance = NULL;
    }
}

TObjEneDD::TObjEneDD(TObject *parent) : TObjEnemy(parent) {
    m_name = TObjEneDD__name;
    previous_mode = 0;
    next_mode = 0;
    wall_reach = 5.0f;
    wall_probe_failures = 0;
    ground_probe_failures = 0;
    active_flags = 0;
}

TObjEneDD::~TObjEneDD() {}

void TObjEneDD::init_position_vectors() {
    u8 *arg0 = (u8 *)this;
    VecCopy(&this->prev_position, (const Vec *)&this->position);
    VecCopy(&this->home_position, (const Vec *)&this->position);
    VecCopy(&this->center, (const Vec *)&this->position);
    ((TBoss3Volopt *)arg0)->reset_photon_effect();
    VecCopy(&this->body_center, (const Vec *)&this->position);
    *(f32 *)((s8 *)arg0 + 0x308) = 0.0f;
    this->y_speed = 0.0f;
    this->m_310 = 0.0f;
    this->ground_normal.x = 0.0f;
    ground_normal.y = 0.0f;
    this->ground_normal.z = 0.0f;
    this->target = 0;
    this->clear_lobby_object_state();
}

s32 TObjEneDD::update_status_effects() {
    if (this->has_flag_0x800() != 0) {
        this->run_death_reaction();
        return 1;
    }
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    this->update_flag30_timer();
    if (this->update_immobilizing_statuses() != 0) {
        return 4;
    }
    if (this->test_flag30_512() != 0) {
        this->run_hit_reaction();
        return 2;
    }
    return 0;
}

s32 TObjEneDD::update_immobilizing_statuses() {
    s32 r = update_action_hold_status();
    r |= update_shock_clock();
    r |= update_movement_status();
    return r;
}

void TObjEneDD::update_action_state() {
    if (((VObj_18 *)(this))->m84() == 0) {
        ((VObj_18 *)(this))->m85(this->mode, 3);
    }
    ((VObj_18 *)(this))->m85(this->mode, 0);
    sub_800BBA0C();
}

s32 TObjEneDD::has_action_state_changed() {
    return previous_mode != this->mode;
}

void TObjEneDD::transition_enemy_state(s32 state) {
    dispatch_action(mode, 5);
    dispatch_action(state, 4);
    mode = state;
}

void TObjEneDD::sub_800BBA0C() {
    previous_mode = this->mode;
}

void TObjEneDD::set_field_378(s32 v) { next_mode = v; }

BmlResource *load_enemy_bml_resource(BmlResourceDescriptor *descriptor) {
    return new BmlResource(1, descriptor, 0, 0, NULL);
}

#pragma push
#pragma scheduling off
void BmlResourceDescriptor::copy_from(const BmlResourceDescriptor &other) {
    archive_filename = other.archive_filename;
    model_filenames = other.model_filenames;
    motion_filenames = other.motion_filenames;
    model_count = other.model_count;
    motion_count = other.motion_count;
}
#pragma pop

BmlResource *load_enemy_bml_resource_named(BmlResourceDescriptor *descriptor, const char *archive_filename) {
    BmlResourceDescriptor copy;
    copy.copy_from(*descriptor);
    copy.archive_filename = archive_filename;
    return load_enemy_bml_resource(&copy);
}

void TObjEneDD::apply_enemy_state(s32 *state) {
    s16 temp_r31;

    temp_r31 = this->mode;
    TObjEnemy::apply_enemy_state(state);
    this->mode = temp_r31;
}

void TObjEneDD::invoke_initialization_hook(void *set_data) {
    apply_set_data(set_data);
}

void TObjEneDD::reset_state_fields() {
    s32 i;
    ((Obj_800BB88C *)this)->f38 = 0.0f;
    ((Obj_800BB88C *)this)->f3c = 0.0f;
    ((Obj_800BB88C *)this)->f40 = 0.0f;
    ((Obj_800BB88C *)this)->f5c = 0;
    ((Obj_800BB88C *)this)->f60 = 0;
    ((Obj_800BB88C *)this)->f64 = 0;
    for (i = 0; i < 5; i++) {
        ((Obj_800BB88C *)this)->f354[i] = 0.0f;
    }
    ((Obj_800BB88C *)this)->f368 = 0;
    ((Obj_800BB88C *)this)->f36c = 0;
    ((Obj_800BB88C *)this)->f28 = -1;
    ((Obj_800BB88C *)this)->f2a = -1;
}

s32 pack_debug_text_position(s32 arg0, s32 arg1) {
    return ((arg0 + 0x13) << 0x10) | (arg1 + 0x1A);
}

int TObjEneDD::get_target_info() { return fn_800FD8A0(this); }

void TObjEneDD::init_common_from(u8 *arg1) {
    reset_state_fields();
    this->room = (s16) *(s16 *)((s8 *)arg1 + 0x28);
    this->set_group = (s16) *(s16 *)((s8 *)arg1 + 0x2A);
    subtractive_rng_seed((void *) (((u8 *)this) + 0x160), (int) (this->entity_id + area_random_seed));
}


int TObjEnemy::submit_default_cursor_candidate() { return submit_cursor_candidate(this, -1); }

void TBoss8Dragon__sub_800BB7DC(void) {  }

void TBoss8Dragon__sub_800BB7D8(void) {  }

void TBoss8Dragon__sub_800BB7D4(void) {  }

void TBoss8Dragon::noop() {  }

void TObjEneDD::clear_attack_receipts() {
    s32 i;
    ((Obj_800BB780 *)this)->f33e = ((Obj_800BB780 *)this)->f32c;
    ((Obj_800BB780 *)this)->flags &= ~0x200;
    ((Obj_800BB780 *)this)->f2dc = 0;
    for (i = 0; i < ((Obj_800BB780 *)this)->count; i++) {
        ((Obj_800BB780 *)this)->parts[i].flags &= ~0x04000000;
    }
}

int TObjEneBm3Fly::was_hit_by_ranged() { return (this->m_2dc >> 1) & 0x1; }

void TObjEnemy::refresh_and_send_entity_flags() { ((TObjPlayer *)this)->refresh_lobby_state(); ((TObjEnemy *)this)->send_entity_set_flags(); }

u16 enemy_nearest_visible_player_sq(u8 *arg0, f32 farg0) {
    f32 d;
    f32 best;
    s32 n;
    u8 *p;
    u16 result;
    s32 i;
    best = farg0;
    result = 0xFFFF;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (((TObjBase *)p)->is_alive() != 0) {
            d = horizontal_distance_squared((const Vec *)(arg0 + 0x2FC), (const Vec *)(p + 0x38));
            if (d < best && csnLookAt(arg0 + 0x2FC, p + 0x2FC) == 0) {
                result = get_entity_id(p);
                best = d;
            }
        }
    }
    return result;
}


u16 enemy_find_nearest_player_in_range(u8 *self, f32 range) {
    return enemy_nearest_visible_player_sq(self, range * range);
}

void TBoss8Dragon__sub_800BB650(void* p, void* q) { *(u16*)((char*)p + 0x0) = *(u16*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); }

s32 collect_enemy_target_candidates(saddr arg0, Ent_800BB484 *out, f32 farg0) {
    s32 n;
    s32 cnt;
    Ent_800BB484 tmp;
    u8 *p;
    s32 mi;
    s32 j;
    f32 mx;
    f32 d;
    s32 k;
    n = 0;
    cnt = TLobby::get_game_mode();
    if (farg0 > 0.0f) {
        for (s32 i = 0; i < cnt; i++) {
            p = ((u8 *)TObjPlayer::get_player_data(i));
            if (((TObjBase *)p)->is_alive() != 0) {
                d = horizontal_distance_squared((const Vec *)(arg0 + 0x38), (const Vec *)(p + 0x38));
                if (d < farg0) {
                    out[n].id = get_entity_id(p);
                    out[n].dist = d;
                    n++;
                }
            }
        }
    } else {
        for (s32 i = 0; i < cnt; i++) {
            p = ((u8 *)TObjPlayer::get_player_data(i));
            if (((TObjBase *)p)->is_alive() != 0) {
                d = horizontal_distance_squared((const Vec *)(arg0 + 0x38), (const Vec *)(p + 0x38));
                out[n].id = get_entity_id(p);
                out[n].dist = d;
                n++;
            }
        }
    }
    if (n > 1) {
        for (k = n - 1; k >= 1; k--) {
            mx = out[0].dist;
            mi = 0;
            for (j = 1; j <= k; j++) {
                f32 v = out[j].dist;
                if (v > mx) {
                    mx = v;
                    mi = j;
                }
            }
            if (mi != k) {
                TBoss8Dragon__sub_800BB650(&tmp, &out[mi]);
                TBoss8Dragon__sub_800BB650(&out[mi], &out[k]);
                TBoss8Dragon__sub_800BB650(&out[k], &tmp);
            }
        }
    }
    return n;
}

void TObjEneDD::collect_target_candidates(saddr arg0, f32 farg0) {
    collect_enemy_target_candidates(arg0, (Ent_800BB484 *)(&enemy_target_candidate_table.value), farg0);
}

u16 enemy_nearest_visible_enemy_sq(Ent_800BB388 *self, f32 range) {
    s32 count;
    s32 base;
    Ent_800BB388 *p;
    u16 best;
    s32 i;
    f32 d;

    best = 0xFFFF;
    base = TLobby::get_game_mode();
    count = TObjEneDD::get_enemy_count();
    for (i = 0; i < count; i++) {
        p = (Ent_800BB388 *)TObjPlayer::get_player_data(base + i);
        if (p != self && !(p->flags30 & 0x01000000) && ((TObjBase *)p)->is_alive() != 0) {
            d = horizontal_distance_squared((const Vec *)self->f2FC, (const Vec *)p->pos);
            if (d < range && csnLookAt(self->f2FC, p->f2FC) == 0) {
                best = get_entity_id(p);
                range = d;
            }
        }
    }
    return best;
}

u16 enemy_nearest_visible_enemy(void *self, f32 range) {
    return enemy_nearest_visible_enemy_sq((Ent_800BB388 *)self, range * range);
}

u8 *TObjEneDD::snap_to_ground_at(u8 *arg1) {
    Vec position;
    CsnHit *hit;
    position.x = *(f32 *)((s8 *)arg1 + 0);
    position.y = *(f32 *)((s8 *)arg1 + 4) + *(f32 *)(this->m_2b0 + 0x10);
    position.z = *(f32 *)((s8 *)arg1 + 8);
    if (csnVectorUnder(&position, (CsnGroup **)&this->m_120, 0xE0) != NULL) {
        return NULL;
    }
    hit = csnVectorUnder(&position, (CsnGroup **)&m_120, 0x15);
    if (hit == NULL) {
        return NULL;
    }
    this->position.y = hit->contact->point.y;
    return (u8 *)hit;
}

saddr TObjEneDD::enemy_probe_wall_ahead(f32 farg0, f32 farg1, f32 farg2) {
  f32 temp_f31;
  Vec stack;
  f32 temp_f30;
  temp_f30 = farg0 * farg2;
  temp_f31 = farg1 * farg2;
  if ((fabs_float(temp_f30) < 0.01f) && (fabs_float(temp_f31) < 0.01f))
  {
    return farg0 * 0;
  }
  stack.x = (*((f32 *) (((s8 *) ((u8 *)this)) + 0x38))) + temp_f30;
  stack.y = this->body_center.y;
  stack.z = (*((f32 *) (((s8 *) ((u8 *)this)) + 0x40))) + temp_f31;
  return csnVector((void *) (((u8 *)this) + 0x2FC), &stack.x, 0x88E0);
}

void TObjEneDD::calc_shot_position(u8 *arg1, f32 farg0, f32 farg1, f32 farg2) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r5;

    f32 reach = farg2 + this->wall_reach;
    if (((TObjEneDD *)arg0)->enemy_probe_wall_ahead(farg0, farg1, reach) == 0U) {
        *(f32 *)((s8 *)arg1 + 0) = (f32) ((farg0 * farg2) + *(f32 *)((s8 *)arg0 + 0x38));
        *(f32 *)((s8 *)arg1 + 4) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
        *(f32 *)((s8 *)arg1 + 8) = (f32) ((farg1 * farg2) + *(f32 *)((s8 *)arg0 + 0x40));
        this->wall_probe_failures = 0;
        return;
    }
    temp_r5 = this->wall_probe_failures;
    this->wall_probe_failures = (temp_r5 + 1);
    VecCopy__FP3VecPC3Vec(arg1, (u8 *)&this->position, temp_r5);
}


#pragma push
#pragma fp_contract on
#define e ((TObjEneDD *)arg0)
#define out ((Vec *)arg1)
void calc_wall_slide_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist) {
    Node_800BB000 *n;
    Vec v;
    n = (Node_800BB000 *)e->enemy_probe_wall_ahead(dx, dz, dist + e->wall_reach);
    if (n == NULL) {
        out->x = dx * dist + e->position.x;
        out->y = e->position.y;
        out->z = dz * dist + e->position.z;
        e->wall_probe_failures = 0;
        return;
    }
    e->wall_probe_failures++;
    v.x = *(f32 *)(n->wall + 0x14);
    v.z = -*(f32 *)(n->wall + 0xC);
    normalize_vector_xz((Vec *)(&v));
    if (dx * v.x + dz * v.z >= 0.0f) {
        dx = v.x;
        dz = v.z;
    } else {
        dx = -v.x;
        dz = -v.z;
    }
    if ((Node_800BB000 *)e->enemy_probe_wall_ahead(dx, dz, dist + e->wall_reach) == NULL) {
        out->x = dx * dist + e->position.x;
        out->y = e->position.y;
        out->z = dz * dist + e->position.z;
        return;
    }
    VecCopy((Vec *)out, (const Vec *)&e->position);
}
#undef e
#undef out
#pragma pop

#pragma push
#pragma fp_contract on
void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist) {
    TObjEneDD *e = (TObjEneDD *)arg0;
    Vec *out = (Vec *)arg1;
    Node_800BAF1C *n = (Node_800BAF1C *)e->enemy_probe_wall_ahead(dx, dz, dist + e->wall_reach);
    if (n == NULL) {
        e->wall_probe_failures = 0;
    } else {
        Vec *p;
        f32 ddx;
        f32 px;
        f32 ddz;
        e->wall_probe_failures++;
        p = n->pos;
        px = p->x;
        ddz = p->z - e->position.z;
        ddx = px - e->position.x;
        dist = ((f32 (*)(f32, f32, f32))newton_sqrtf)(ddx * ddx + ddz * ddz, px, ddz) - e->wall_reach;
    }
    out->x = dx * dist + e->position.x;
    out->y = e->position.y;
    out->z = dz * dist + e->position.z;
}
#pragma pop

u8 *TObjEneDD::try_move_actor_xz_on_ground(u8 *arg1) {
    f32 temp_f31;
    u8 *temp_r3;
    temp_f31 = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
    temp_r3 = (unsigned char *) (((VObj_18_3f4583 *)(this))->m101());
    if (temp_r3 != NULL) {
        this->prev_position.x = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x38);
        this->prev_position.y = temp_f31;
        this->prev_position.z = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x40);
        *(f32 *)((s8 *)((u8 *)this) + 0x38) = (f32) *(f32 *)((s8 *)arg1 + 0);
        *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) *(f32 *)((s8 *)arg1 + 8);
        VecCopy((Vec *)(((u8 *)this) + 0x248), (const Vec *)(*(saddr *)((s8 *)temp_r3 + 4) + 0xC));
        this->ground_probe_failures = 0;
    } else {
        this->ground_probe_failures = (this->ground_probe_failures + 1);
    }
    return temp_r3;
}

u8 *TObjEneDD::move_xz_on_ground(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    u8 *temp_r3;
    temp_f31 = *(f32 *)((s8 *)arg0 + 0x3C);
    temp_r3 = (unsigned char *) (((VObj_18_3f4583 *)(arg0))->m101());
    if (temp_r3 != NULL) {
        VecCopy((Vec *)(arg0 + 0x248), (const Vec *)(*(saddr *)((s8 *)temp_r3 + 4) + 0xC));
    }
    this->prev_position.x = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    this->prev_position.y = temp_f31;
    this->prev_position.z = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) *(f32 *)((s8 *)arg1 + 8);
    this->ground_probe_failures = 0;
    return temp_r3;
}

u8 *TObjEneDD::update_ground_contact() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    u8 *temp_r3;
    temp_f31 = *(f32 *)((s8 *)arg0 + 0x3C);
    temp_r3 = (unsigned char *) (((TObjEneDD *)(arg0))->update_actor_ground_y());
    if (temp_r3 != NULL) {
        VecCopy((Vec *)(arg0 + 0x248), (const Vec *)(*(saddr *)((s8 *)temp_r3 + 4) + 0xC));
    }
    this->prev_position.x = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    this->prev_position.y = temp_f31;
    this->prev_position.z = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    this->ground_probe_failures = 0;
    return temp_r3;
}

void TObjEneDD::move_to_shot_position(f32 farg0, f32 farg1, f32 farg2) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    ((TObjEneDD *)arg0)->calc_shot_position((u8 *)&sp8, (f32)farg0, (f32)farg1, (f32)farg2);
    ((TObjEneDD *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void TObjEneDD::move_with_wall_slide_on_ground(f32 dx, f32 dz, f32 dist) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    calc_wall_slide_destination(arg0, &sp8, dx, dz, dist);
    ((TObjEneDD *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void TObjEneDD::move_clamped_on_ground(f32 farg0, f32 farg1, f32 dist) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    calc_wall_clamped_destination(arg0, &sp8, farg0, farg1, dist);
    ((TObjEneDD *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void TObjEneDD::move_with_wall_stop(f32 farg0, f32 farg1, f32 farg2) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    ((TObjEneDD *)arg0)->calc_shot_position((u8 *)&sp8, (f32)farg0, (f32)farg1, (f32)farg2);
    this->move_xz_on_ground((u8 *)&sp8);
}

u8 *TObjEneDD::move_with_wall_slide_commit(f32 dx, f32 dz, f32 dist) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    calc_wall_slide_destination(arg0, &sp8, dx, dz, dist);
    return this->move_xz_on_ground((u8 *)&sp8);
}

void TObjEneDD::move_to_wall_clamped_destination(f32 farg0, f32 farg1, f32 dist) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    calc_wall_clamped_destination(arg0, &sp8, farg0, farg1, dist);
    this->move_xz_on_ground((u8 *)&sp8);
}

int TObjEneDD::has_move_failures(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 var_r5;
    var_r5 = 0;
    if ((this->wall_probe_failures >= arg1) || (this->ground_probe_failures >= arg1)) {
        var_r5 = 1;
    }
    return var_r5;
}


void TObjEneDD_ST::set_active() { active_flags = 1; }

void TObjEneDD::clear_field_388() { active_flags = 0; }

void TObjEneDD::init_model(CollisionBody *bodies, s32 count) {
    init_collision_body_parts(this, bodies, count);
    transform_part_positions();
}

void TObjEneDD::set_part_local_pos(void *v, s32 i) {
    Vec *p;
    VecCopy((Vec *)&((Obj_800BAAE4 *)this)->parts[i].b, (const Vec *)((Vec *)v));
    p = &((Obj_800BAAE4 *)this)->parts[i].a;
    VecCopy((Vec *)p, (const Vec *)((Vec *)v));
    subtract_vector(p, &((Obj_800BAAE4 *)this)->pos);
    rotate_xz_pair_by_angle(&p->x, &p->z, -((Obj_800BAAE4 *)this)->angle);
}

void update_local_colliders_from_world(Obj_800BAA2C *arg0, Vec *arg1) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(NULL, -arg0->rot);
    translate_matrix(0, -arg0->x, -arg0->y, -arg0->z);
    for (i = 0; i < arg0->count; i++) {
        VecCopy((Vec *)((Vec *)(&arg0->cols[i].pos)), (const Vec *)((const Vec *)(arg1)));
        matrix_mult_vec(0, arg1, &arg0->cols[i]);
        arg1++;
    }
    pop_matrix();
}

void set_part_position__9TObjEneDDFPvPvi(Obj_800BA9BC *self, Vec *v, s32 i) {
    Vec *p;
    VecCopy((Vec *)((Vec *)(&self->parts[i].a)), (const Vec *)((const Vec *)(v)));
    p = &self->parts[i].b;
    VecCopy((Vec *)((Vec *)(p)), (const Vec *)((const Vec *)(v)));
    rotate_xz_pair_by_angle(&p->x, &p->z, self->angle);
    vec3_add_to((Vec *)p, (const Vec *)&self->pos);
}

void TObjEneDD::transform_part_positions() {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    set_motion_packed_rotation();
    for (i = 0; i < this->body_count; i++) {
        matrix_mult_vec(0, &bodies[i].offset, &bodies[i].center);
    }
    clear_motion_packed_rotation();
    pop_matrix();
}


void TObjEneDD::update_body_colliders() {  }

void TObjEneDD::check_collisions() {
    this->update_body_colliders();
    this->check_object_collisions();
    check_enemy_body_collisions(this);
}

s32 TObjEneDD::vfunc_90() {
    O_800BA8A8 *self = (O_800BA8A8 *)this;
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        if (self->entries[i].flags & 0x380000) {
            return 1;
        }
    }
    return 0;
}

void set_collider_contact_high(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) | 4);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) & 0xFFFFFFFD);
}

void set_collider_contact_low(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) & 0xFFFFFFFB);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) | 2);
}

void update_collider_contact_by_height(u8 *arg0, f32 farg0) {
    if (*(f32 *)((s8 *)arg0 + 4) >= farg0) {
        set_collider_contact_high(arg0);
        return;
    }
    set_collider_contact_low(arg0);
}


s32 is_player_entity_id(u16 arg0) {
    return (u32)(arg0 - 0x1000) >> 0x1FU;
}

int TObjEneDD__sub_800BA804(u16 arg0) {
    u8 var_r3;
    var_r3 = 0;
    if ((arg0 >= 0x1000U) && (arg0 < 0x4000U)) {
        var_r3 = 1;
    }
    return var_r3;
}

s32 TObjEneDD::is_valid_target() {
    int var_r31;

    var_r31 = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction() != 0) && !(this->actorFlags & 0x06040800)) {
        var_r31 = 1;
    }
    return (u8)((u8)var_r31);
}

s32 TObjEneDD::is_target_unobstructed(saddr arg1) {
    saddr arg0 = (saddr)this;
    if ((((TObjBase *)arg0)->is_alive() != 0) && (csnLookAt((void *)arg1, (void *)(arg0 + 0x2FC)) == 0U)) {
        return 1;
    }
    return 0;
}

s32 is_target_unobstructed_from(TObjEneDD *self, TObjChara *target) { return ((TObjEneDD *)target)->is_target_unobstructed((saddr)((char *)self + 0x2fc)); }

s32 TObjBase::is_alive() {
    int var_r31;

    var_r31 = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction() != 0) && !(this->actorFlags & 0x02040800)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

int is_target_ranger(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_RANGER) != 0; }

int is_target_android(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_ANDROID) != 0; }

void TObjEneDD::setup_instance(saddr arg0, saddr arg1, u8 *arg2, saddr arg3) {
    ((TUnk_804928CC *)obj_ene_dd_instance)->sub_800BC3E8((u8 *)arg0);
    ((TUnk_804928CC *)obj_ene_dd_instance)->set_position_from((void *)arg1);
    *(f32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0x18) = 0x9D03;
    if (*(f32 *)((s8 *)arg2 + 8) > 100.0f) {
        ((EneDDObj_800BA138*)obj_ene_dd_instance)->m13(arg2 + 0xC, (void*)arg2, (void*)arg3);
        return;
    }
    ((EneDDObj_800BA138*)obj_ene_dd_instance)->m12(arg2 + 0xC, (void*)arg2, (void*)arg3);
}

void TObjEneDD::setup(void *p, saddr pos, saddr params) { TObjEneDD::setup_instance((saddr)p, pos, (u8 *)params, 0); }

void TObjEneDD__sub_800BA5A4(void* p, void* a1) { TObjEneDD::setup_instance((saddr)p, (saddr)((char*)p + 0x38), (u8 *)a1, (saddr)((void*)0)); }

void TObjEneDD::emit_enemy_effect(void *arg0, void *arg1, u8 *arg2, void *arg3) {
    ((TUnk_804928CC *)obj_ene_dd_instance)->sub_800BC3E8((u8 *)arg0);
    ((TUnk_804928CC *)obj_ene_dd_instance)->set_position_from(arg1);
    *(f32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0x18) = 0x9D03;
    if (*(f32 *)((s8 *)arg2 + 8) > 100.0f) {
        ((EneDDObj2_800BA138*)obj_ene_dd_instance)->m16(arg2 + 0xC, arg3);
        return;
    }
    ((EneDDObj2_800BA138*)obj_ene_dd_instance)->m15(arg2 + 0xC, arg3);
}

void TObjEneDD::emit_effect(void *p, saddr pos, saddr params) { TObjEneDD::emit_enemy_effect(p, (void *)pos, (u8 *)params, 0); }

void TObjEneDD::emit_effect_at_position(void* a1) { TObjEneDD::emit_enemy_effect(this, (char*)this + 0x38, (u8 *)a1, (void*)0); }

void TObjEneDD__sub_800BA438(s32 arg0, u8 *arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_800BA318, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_800BA318, spC) == 0x4);
    Stack_800BA318 stack = {0x12, 1.0f};
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD::inflict_poison(s32 arg0, u8 *arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_800BA318, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_800BA318, spC) == 0x4);
    Stack_800BA318 stack = {0xF, 1.0f};
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD__sub_800BA378(s32 arg0, u8 *arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_800BA318, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_800BA318, spC) == 0x4);
    Stack_800BA318 stack = {0x10, 1.0f};
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD::send_damage_message(s32 arg0, u8 *arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_800BA318, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_800BA318, spC) == 0x4);
    Stack_800BA318 stack = {0x11, 1.0f};
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD::set_state_flag_1() { add_flags_2e4(1); }

void TObjEneDD::set_state_flag_2() { add_flags_2e4(2); }

void TObjEneDD::set_state_flag_4() { add_flags_2e4(4); }

void TObjEneDD::set_state_8() { add_flags_2e4(8); }

void TObjEneDD::set_invulnerable() {
    Obj_800BA244 *self = (Obj_800BA244 *)this;
    s32 i;
    this->actorFlags |= 0x04000000;
    for (i = 0; i < this->body_count; i++) {
        self->parts[i].flags |= 0x02000000;
    }
}

void TObjEneDD::clear_invulnerable() {
    Obj_800BA200 *self = (Obj_800BA200 *)this;
    s32 i;
    this->actorFlags &= ~0x04000000;
    for (i = 0; i < this->body_count; i++) {
        self->parts[i].flags &= ~0x02000000;
    }
}

void TObjEneDD::enable_body_collision() {
    O_800BA1C8 *self = (O_800BA1C8 *)this;
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        self->entries[i].flags |= 1;
    }
}

void TObjEneDD::disable_body_collision() {
    O_800BA190 *self = (O_800BA190 *)this;
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        self->entries[i].flags &= ~1;
    }
}

void TObjEneDD::set_intangible() {
    this->set_invulnerable();
    this->disable_body_collision();
    this->actorFlags = (s32) (this->actorFlags | 0x04040000);
}

void TObjEneDD::clear_intangible() {
    this->clear_invulnerable();
    this->enable_body_collision();
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
}

void TObjEneDD::set_colliders_contact_high() {
    Obj_800BA084 *self = (Obj_800BA084 *)this;
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        set_collider_contact_high((u8 *)&self->parts[i]);
    }
}

void TObjEneDD::set_colliders_contact_low() {
    Obj_800BA030 *self = (Obj_800BA030 *)this;
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        set_collider_contact_low((u8 *)&self->parts[i]);
    }
}

s32 TObjEneDD::is_confused() {
    return (u8)(((this->actorFlags & 0x10) - 0x10) == 0);
}

f32 TObjEneDD::calc_elapsed_scaled() {
    return 2.0f * (random_ratio() - 0.5f);
}

f32 TObjEneDD::rand_range(f32 farg0, f32 farg1) {
    return ((farg1 - farg0) * this->random_ratio()) + farg0;
}

s32 TObjEneDD::get_random_scaled() {
    return (s32) (65535.0f * random_ratio());
}

void TObjEneDD::initialize_enemy_state(s32 parameter) {
    set_param(parameter);
}

void forward_split_screen_view_matrix() { TCameraCtrl::apply_split_screen_view_matrix(); }

void forward_transform_to_view(const Vec *in, Vec *out) { transform_to_view__11TCameraCtrlFii((saddr)in, (saddr)out); }

void TObjEneDD::reset_hp(u8 *base_stats, u8 *attack_stats, u8 *resistance_stats) {
    bind_enemy_combat_stats(base_stats, attack_stats, resistance_stats);
    referenceHp = hp;
}

void TObjEneDD::reload_stats_keep_hp_tp(u8 *base_stats, u8 *attack_stats, u8 *resistance_stats) {
    s16 a = this->hpmax;
    s16 c = this->hp;
    s16 b = this->tpmax;
    s16 d = *(s16 *)&this->tp;
    bind_enemy_combat_stats(base_stats, attack_stats, resistance_stats);
    this->hpmax = a;
    this->hp = c;
    this->tpmax = b;
    *(s16 *)&this->tp = d;
}

int TObjEneDD::update_secondary_light() { return select_actor_lighting(this); }

int TObjEneDD::update_primary_light() { return restore_scene_lighting(this); }

void TObjEneDD::draw_oriented_shadow(const Vec *position, const Vec *normal, saddr angle, const Vec *scale) {
    Stack_800B9D94 stack;
    direction_to_rotation_xz((u8 *)normal, &stack.sp8, &stack.sp10);
    push_matrix();
    post_translate_matrix(&position->x);
    translate_matrix(0, 0.0f, 0.3f, 0.0f);
    rotate_matrix_z(0, stack.sp10);
    rotate_matrix_x(0, stack.sp8);
    rotate_matrix_y(NULL, angle);
    if (scale != NULL) {
        scale_current_matrix(&scale->x);
    }
    rotate_matrix_x(0, -0x4000);
    draw_blob_shadow(0);
    pop_matrix();
}

void TObjEneDD::draw_ground_shadow(const Vec *scale, s32 forceDraw) {
    TObjEnemy::draw_ground_shadow(scale, forceDraw);
}

void TObjEneDD::clear_global_flag_400() { model_render_flags = (model_render_flags & 0xfffffbff); }

void TObjEneDD::render_minimap_dot() {
    if (!(this->actorFlags & 0x40800)) {
        minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    }
}

s32 TObjEneDD::is_main_phase_15() {
    return get_main_phase() == 0xF;
}

s32 TObjEneDD::is_phase_e() {
    return (u8) (get_main_phase() == 0xE);
}

int TObjEneDD::update_lobby_state() { return is_local_client_floor_leader(this); }

int TObjEneDD::query_teammate_state() { return TObjPlayer::is_any_teammate_in_state(); }

void project_sound_origin_from_camera(saddr arg0, u8 *boss2_tunnel, f32 farg0) {
    f32 temp_f1;
    VecCopy((Vec *)(boss2_tunnel), (const Vec *)(arg0));
    subtract_vector((Vec *)boss2_tunnel, (const Vec *)(camera_ctrl_instance + 0x178));
    { f32 s = normalize_vector_safe((Vec *)boss2_tunnel); temp_f1 = s * farg0; }
    *(f32 *)((s8 *)boss2_tunnel + 0) = (f32) (*(f32 *)((s8 *)boss2_tunnel + 0) * temp_f1);
    *(f32 *)((s8 *)boss2_tunnel + 4) = (f32) (*(f32 *)((s8 *)boss2_tunnel + 4) * temp_f1);
    *(f32 *)((s8 *)boss2_tunnel + 8) = (f32) (*(f32 *)((s8 *)boss2_tunnel + 8) * temp_f1);
    vec3_add_to((Vec *)boss2_tunnel, (const Vec *)(camera_ctrl_instance + 0x178));
}

int TObjEneDD::get_target_state_b() { return freeze_all_players__10TObjPlayerFv(this); }

int TObjEneDD::get_target_state_a() { return TObjPlayer__sub_801BA42C(this); }

s32 TObjEneDD::check_v2_mode() {
    if (((s32) enable_v2_features != 0) && ((s32) game_difficulty_selection == 3)) {
        return 1;
    }
    return 0;
}

s32 TObjEneDD::clamp_frame_index(s32 arg0) {
    s32 limit;
    s32 idx;

    idx = arg0;
    limit = 0xE;
    if (TObjEneDD::check_v2_mode() != 0) {
        limit = 0x1D;
    }
    if (idx < 0) {
        idx = 0;
    } else if (idx >= limit) {
        idx = limit - 1;
    }
    return idx;
}

void TObjEneDD__sub_800B9B24(void) {  }

void TObjEneDD::init_lights() { TObjLight__sub_801337F8((void*)current_scene_light); TObjLight__sub_801337FC((void*)lbl_805D555C); }


TObjEneDD_ST::TObjEneDD_ST(TObject *parent) : TObjEneDD(parent) {
    m_name = TObjEneDD_ST__name;
    this->enemy_clear_target();
    init_float_params();
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
}

TObjEneDD_ST::~TObjEneDD_ST() {}


void TObjEneDD_ST::update_velocity() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)arg0 + 0x394);
    *(f32 *)((s8 *)arg0 + 0x3A0) = (f32) (temp_f2 - *(f32 *)((s8 *)arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x3A4) = 0.0f;
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x39C);
    *(f32 *)((s8 *)arg0 + 0x3A8) = (f32) (temp_f1 - *(f32 *)((s8 *)arg0 + 0x40));
    *(f32 *)((s8 *)arg0 + 0x3AC) = normalize_vector_xz__FP3Vec(arg0 + 0x3A0, temp_f1, temp_f2);
}


void TObjEneDD_ST::init_float_params() {
    destination.x = 0.0f;
    destination.y = 0.0f;
    destination.z = 0.0f;
    destination_direction.x = 0.0f;
    destination_direction.y = 0.0f;
    destination_direction.z = 0.0f;
    destination_distance = 0.0f;
}


void enemy_set_target_id(TObjEneDD_ST *self, u16 id) {
    self->target_id = id;
    if (id != 0xFFFF) {
        self->current_target = (TObjChara *)find_active_entity_by_id(self->target_id);
    } else {
        self->target_id = 0xFFFF;
        self->current_target = 0;
    }
}

void TObjEneDD_ST::set_target_player(void *player) {
    s32 n;
    s32 i;
    target_id = 0xFFFF;
    current_target = 0;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        if (player == TObjPlayer::get_player_data(i)) {
            target_id = get_entity_id(player);
            current_target = (TObjChara *)player;
            return;
        }
    }
}

void TObjEneDD_ST::enemy_clear_target() {
    current_target = 0;
    target_id = 0xFFFF;
}

void TObjEneDD_ST::enemy_init_acquire_period(s32 arg1) {
    acquire_counter = this->entity_id % arg1;
    acquire_period = arg1;
}

s32 TObjEneDD_ST::acquire_target(f32 distance) { return select_nearest_target(distance); }

s32 enemy_bind_or_clear_target(TObjEneDD_ST *self, u16 id) {
    if (id != 0xFFFF) {
        enemy_set_target_id(self, id);
        return 1;
    }
    self->enemy_clear_target();
    return 0;
}

s32 TObjEneDD_ST::select_and_apply_target(f32 range) {
    u16 temp_r3;
    u16 var_r4;

    if (this->is_confused() != 0) {
        temp_r3 = enemy_nearest_visible_enemy(this, range);
        var_r4 = temp_r3;
        if (temp_r3 == 0xFFFF) {
            var_r4 = enemy_find_nearest_player_in_range((u8 *)this, range);
        }
    } else {
        var_r4 = enemy_find_nearest_player_in_range((u8 *)this, range);
    }
    return enemy_bind_or_clear_target(this, var_r4);
}


s32 TObjEneDD_ST::select_nearest_target(f32 distance) {
    u16 target = enemy_find_nearest_player_in_range((u8 *)this, distance);
    return enemy_bind_or_clear_target(this, target);
}

s32 TObjEneDD_ST::enemy_tick_target_acquisition(s32 *counter, s32 limit, f32 scale) {
    s32 var_r31;
    if (tick_period_counter((saddr)this, counter, limit) != 0) {
        var_r31 = this->acquire_target(scale);
    } else {
        var_r31 = enemy_has_live_target();
        if (var_r31 == 0) {
            this->enemy_clear_target();
        }
    }
    return var_r31;
}

s32 TObjEneDD_ST::update_linked_position(f32 scale) {
    return this->enemy_tick_target_acquisition(&acquire_counter, acquire_period, scale);
}

void TObjEneDD_ST::enemy_copy_target_destination() {
    TObjChara *target = current_target;
    if (target != NULL) {
        set_target_destination(&target->position);
    }
}

void TObjEneDD_ST::set_target_destination(const Vec *position) { VecCopy((Vec *)((char *)this + 0x394), position); }

void TObjEneDD_ST::enemy_init_validate_period(s32 arg1) {
    validate_period = arg1;
    validate_counter = (this->entity_id + 3) % validate_period;
}

s32 enemy_validate_retained_target(TObjEneDD_ST *self) {
    if (tick_period_counter((saddr)self, &self->validate_counter, self->validate_period) != 0) {
        if (is_target_unobstructed_from(self, self->current_target) != 0) {
            return 1;
        }
        goto block_5;
    }
    if (self->enemy_has_live_target() != 0) {
        return 1;
    }
block_5:
    self->enemy_clear_target();
    return 0;
}

s32 TObjEneEpsilon::update_death_check() {
    if ((this->is_confused() == 0) && (is_player_entity_id(this->target_id) == 0)) {
        this->enemy_clear_target();
        return 0;
    }
    return enemy_validate_retained_target(this);
}

void TObjEneDD_ST::turn_toward_target_direction(s32 max_step) {
    this->rotation_y = (s16) approach_angle_limited(this->rotation_y, (s32) (10430.38043493439 * atan2_float(*(f32 *)((s8 *)this + 0x3A0), *(f32 *)((s8 *)this + 0x3A8))), max_step);
}

void TObjEneEpsilon::fire_attack_c(saddr shot_pos, s32 arg2, f32 farg0) {
    f32 temp_f30;

    temp_f30 = farg0;
    turn_toward_target_direction(arg2);
    this->calc_shot_position((u8 *)shot_pos, (f32)(sin_table_lookup(this->rotation_y)), (f32)(cos_table_lookup(this->rotation_y)), (f32)temp_f30);
}

void TObjEneEpsilon::fire_attack_b(saddr arg1, s32 arg2, f32 farg0) {
    f32 dz;
    f32 dist;

    dist = farg0;
    turn_toward_target_direction(arg2);
    dz = cos_table_lookup(this->rotation_y);
    calc_wall_slide_destination((void *)this, (void *)arg1, (f32)(sin_table_lookup(this->rotation_y)), (f32)((f32)dz), (f32)((f32)dist));
}

void TObjEneEpsilon::fire_attack_a(saddr out, s32 arg2, f32 farg0) {
    f32 dist;

    dist = farg0;
    turn_toward_target_direction(arg2);
    calc_wall_clamped_destination((void *)this, (void *)out, (f32)(sin_table_lookup(this->rotation_y)), (f32)((f32)cos_table_lookup(this->rotation_y)), (f32)((f32)dist));
}

void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)arg0)->fire_attack_c((saddr) &sp8, arg1, farg0);
    ((TObjEneDD *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)arg0)->fire_attack_b((saddr) &sp8, arg1, farg0);
    ((TObjEneDD *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}


void TObjEneEpsilon__sub_800B92F8(u8 *ene_epsilon, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)ene_epsilon)->fire_attack_b((saddr) &sp8, arg1, farg0);
    ((TObjEneEpsilon *)(ene_epsilon))->move_xz_on_ground((u8 *)&sp8);
}

void TObjEneEpsilon__sub_800B92AC(u8 *ene_epsilon, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)ene_epsilon)->fire_attack_a((saddr) &sp8, arg1, farg0);
    ((TObjEneEpsilon *)(ene_epsilon))->move_xz_on_ground((u8 *)&sp8);
}

s32 TObjEneDD_ST::update_status_effects() {
    if ((is_player_entity_id(target_id) != 0) && (get_player_by_client_id(target_id) == 0U)) {
        this->enemy_clear_target();
    }
    return TObjEneDD::update_status_effects();
}

s32 TObjEneDD_ST::enemy_check_target_valid() {
    u16 id = target_id;
    if (id == 0xFFFF) {
        return 0;
    }
    if (find_entity_by_id(id) == 0U) {
        this->enemy_clear_target();
        return 0;
    }
    return ((TObjEneDD *)current_target)->is_valid_target();
}

#pragma push
#pragma fp_contract on
s32 TObjEneDD_ST::enemy_has_live_target() {
    u32 id = target_id;
    if (id == 0xFFFF) {
        return 0;
    }
    if (find_entity_by_id(id) == 0U) {
        this->enemy_clear_target();
        return 0;
    }
    return current_target->is_alive();
}
#pragma pop

