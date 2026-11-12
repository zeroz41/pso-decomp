#include "types.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
struct TObjGoalWarpAncient;
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/fence/TOVS2Wall01.h"
#include "pso/render/RenderFadeState.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TOVS2Wreck06.h"
#include "pso/object/TOVS2Wreck05.h"
#include "pso/object/TOVS2Wreck04.h"
#include "pso/object/TOVS2Wreck03.h"
#include "pso/object/TOVS2Wreck02.h"
#include "pso/object/TOVS2Wreck01.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TOVS2.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/object/fence/TOVS2Wall01_8017C7A4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/byteswap.h"
#include "pso/object/TMotorcycle.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMapObject.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/TObjChip.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/fence/TOVS2Wall01_8017BCC8.h"
#include "pso/system/SoundEffect.h"

const char *bm_o_vs2_motion_names[1] = { NULL };

const char *bm_o_vs2_model_names[17] = {
    "fe_obj_o_vs2gareki01.gj", "fe_obj_o_vs2gareki02.gj", "fe_obj_o_vs2gareki03.gj", "fe_obj_o_vs2gareki04.gj", "fe_obj_o_vs2gareki05.gj", "fe_obj_o_vs2gareki06.gj",
    "kakusi_hahen27.gj", "kakusi_hahen01.gj", "kakusi_hahen02.gj", "kakusi_hahen03.gj", "kakusi_hahen04.gj", "kakusi_hahen05.gj",
    "kakusi_hahen06.gj", "kakusi_hahen07.gj", "kakusi_hahen08.gj", "kakusi_hahen09.gj", NULL
};
BmlResourceDescriptor bm_o_vs2_resource_descriptor = { "bm_o_vs2.bml", bm_o_vs2_model_names, bm_o_vs2_motion_names, 16, 0 };

const char *TOVS2__class_name = "TOVS2";
const char *TOVS2Wreck01__class_name = "TOVS2Wreck01";
const char *TOVS2Wreck02__class_name = "TOVS2Wreck02";
const char *TOVS2Wreck03__class_name = "TOVS2Wreck03";
const char *TOVS2Wreck04__class_name = "TOVS2Wreck04";
const char *TOVS2Wreck05__class_name = "TOVS2Wreck05";
const char *TOVS2Wreck06__class_name = "TOVS2Wreck06";
const char *TOVS2Wall01__class_name = "TOVS2Wall01";

// One body per wreck model (TOVS2::TOVS2 takes entry `index`), the last one the wall's.
CollisionBody ovs2wall01_collision_parts[7] = {
    {{0.0f, 0.0f, 0.0f}, 20.0f, 30.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 15.0f, 15.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 12.0f, 12.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 12.0f, 12.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 12.0f, 27.0f, 1, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 10.0f, 0, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x38003, {0.0f, 0.0f, 0.0f}, 0.0f}
};

BmlResource *TOVS2Wall01__bml_resource;

// ---- text_8017B9AC
struct Sub_8017BAFC { u8 pad[4]; s16 f4; };

struct Obj_8017BAFC { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x62]; Sub_8017BAFC *sub; u8 pad2[0x2A2]; s16 state; u8 pad3[0x14]; s32 f33C; };

struct Pkt_8017BAFC { u16 a; u16 b; s32 c; s32 d; u16 e; s16 f; };

struct Pkt_8017B9B0 { u16 a; u16 b; s32 c; s32 d; u16 e; u16 f; };

struct Ent_8017B9B0 { s16 a; s16 b; };

struct VBase_8017B9B0 { u8 pad[0x18]; };

struct VObj_8017B9B0 : VBase_8017B9B0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(void *, s32);
    u8 pad2[0x326 - 0x1C];
    s16 state;
};

extern "C" {
s32 check_value_equals__13TUnk_804B6C24Fl(void *, int);
extern Ent_8017B9B0 *quest_object_entries;
void handle_6x86_hit_destructible_object(Pkt_8017B9B0 *arg0);

void TOVS2Wall01__sub_8017B9AC(void *) {  }

void handle_6x86_hit_destructible_object(Pkt_8017B9B0 *arg0) {
    Ent_8017B9B0 spC;
    Ent_8017B9B0 sp8;
    VObj_8017B9B0 *o;
    u16 id;
    if (arg0 == NULL) {
        return;
    }
    ((TOVS2Wall01 *)arg0)->byteswap_hit_packet();
    id = arg0->b;
    if (id == 0xFFFF) {
        return;
    }
    if (id < 0x4000) {
        return;
    }
    o = (VObj_8017B9B0 *)find_entity_by_id(id);
    if (o != NULL) {
        if (check_value_equals__13TUnk_804B6C24Fl(o, (s32)TOVS2Wall01__class_name) == 0) {
            return;
        }
        switch (arg0->e) {
        case 0:
            switch (o->state) {
            case 1:
                break;
            default:
                o->state = 0;
            case 0:
                if (arg0->f < TOVS2Wall01__sub_8017CA50(o)) {
                    TOVS2Wall01__sub_8017CA48(o, arg0->f);
                }
                break;
            }
            break;
        case 1:
            o->state = 1;
            init__11TOVS2Wall01Fi((s32)o);
            break;
        }
        ((TObjCollidable *)o)->access_object_saved_state(&spC, 1);
        spC.a = o->state;
        ((TObjCollidable *)o)->access_object_saved_state(&spC, 0);
        o->m4(&spC, 0);
    } else {
        *(s32 *)&sp8 = *(s32 *)&quest_object_entries[arg0->d];
        if (sp8.a != 1) {
            sp8.a = arg0->c;
            TLobby::apply_table_entry(arg0->d, &sp8);
        }
    }
}

void TOVS2Wall01::save_and_send_state(u16 arg1) {
    s16 sp8;
    Pkt_8017BAFC pkt;
    s16 v = ((Obj_8017BAFC *)this)->state;
    Sub_8017BAFC *sub;
    if (arg1 == 1) {
        v = 1;
    }
    if ((((Obj_8017BAFC *)this)->sub != NULL) && (((TObjCollidable *)((Obj_8017BAFC *)this))->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = v;
        this->access_object_saved_state(&sp8, 0);
        sub = ((Obj_8017BAFC *)this)->sub;
        ((TOVS2Wall01 *)(&pkt))->init();
        pkt.b = ((Obj_8017BAFC *)this)->f1C;
        pkt.c = sp8;
        pkt.d = sub->f4;
        pkt.e = arg1;
        pkt.f = ((Obj_8017BAFC *)this)->f33C;
        ((TOVS2Wall01 *)(&pkt))->update_and_send();
    }
}

}

// ---- TOVS2Wall01 (vfunc_6, spawn_debris)
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TOVS2Wall01::vfunc_6(s16 *arg1, s32 arg2) {
    s32 temp_r0;

    if (arg1 != NULL) {
        this->mode = (s16) *arg1;
    }
    temp_r0 = this->mode;
    if (temp_r0 != 1) {
        if ((temp_r0 >= 1) || (temp_r0 < 0)) {
            this->mode = 0;
        }
    } else {
        this->m_33c = 0;
        if (arg2 != 0) {
            init__11TOVS2Wall01Fi((s32)this);
        }
    }
}

// Throws the wall's debris chips (models 7-15 of bm_o_vs2.bml, one per call).
void TOVS2Wall01::spawn_debris(s32 index) {
    TObjChipParams params = {
        { 0.25f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 7.5f, 5.0f },
        { 1024, 256, 1024 }, { 1, 20 }, { 0.0f, 0.6f }, 0, 0, 20,
    };

    params.pos[0] = m_2fc;
    params.pos[1] = m_300;
    params.pos[2] = m_304;
    params.pad_38[0] = position.y;
    params.model = get_bml_model(TOVS2Wall01__bml_resource, index);
    params.textures = TObjFish__sub_8001EDB0(TOVS2Wall01__bml_resource, index);
    new TObjChip(tl_05, &params);
}

#pragma pop

// ---- TOVS2Wall01_8017BCC8
extern "C" {

void init__11TOVS2Wall01Fi(s32 arg0) {
    s32 var_r31;

    ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
    var_r31 = 7;
    do {
        ((TOVS2Wall01 *)arg0)->spawn_debris(var_r31);
        var_r31 += 1;
    } while (var_r31 <= 0xF);
    spawn_particle_effect((void *)(arg0 + 0x38), 0x45);
    spawn_particle_effect((void *)(arg0 + 0x38), 0x46);
    play_sound_effect(0x4004BC05, (void *)(arg0 + 0x38), 0, 0);
}

f32 take_hit__11TOVS2Wall01FPvUi(u8 *ovs2_wall01, void *attacker) {
    void *player;

    player = NULL;
    get_entity_id((TObjBase *)attacker);
    if (get_entity_id((TObjBase *)attacker) < 4U) {
        player = attacker;
    }
    if ((player != NULL) && (TObjPlayer::is_locally_controlled(player) == 1)) {
        ((TOVS2Wall01 *)ovs2_wall01)->m_33c = (s32) (((TOVS2Wall01 *)ovs2_wall01)->m_33c - 1);
        if ((s32) ((TOVS2Wall01 *)ovs2_wall01)->m_33c <= 0) {
            ((TOVS2Wall01 *)ovs2_wall01)->m_33c = 0;
            ((TOVS2Wall01 *)ovs2_wall01)->save_and_send_state(1);
        } else {
            ((TOVS2Wall01 *)ovs2_wall01)->save_and_send_state(0);
        }
        spawn_particle_effect((ovs2_wall01 + 0x38), 0x1D0);
        spawn_particle_effect((ovs2_wall01 + 0x38), 1);
    }
    return 0.0f;
}

}

// ---- TOVS2Wall01_8017BE08
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
struct VBase_14_1eb8da { char pad[0x14]; };
struct VObj_14_1eb8da : VBase_14_1eb8da {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6(s32, s32);
    virtual s32 m7();
};
extern "C" {
void __ct__15RenderFadeStateFv(void *);
s32 update__15RenderFadeStateFv(void *);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void __ct__9TObjCharaFP7TObject(void *, void *);
void activate_and_dispatch__15RenderFadeStateFv(void *, s32, f32);
extern s32 __vt__11TOVS2Wall01[];
void *TOVS2Wall01__ct(TOVS2Wall01 *arg0, void *arg1);
int submit_cursor_candidate(void*, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void queue_destruction__7TObjectFv(void *arg0);
// ---- TOVS2Wreck06
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
extern s32 __vt__12TOVS2Wreck06[];
// ---- TOVS2Wreck05
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
extern s32 __vt__12TOVS2Wreck05[];
// ---- TOVS2Wreck04
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
extern s32 __vt__12TOVS2Wreck04[];
// ---- TOVS2Wreck03
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
extern s32 __vt__12TOVS2Wreck03[];
// ---- TOVS2Wreck02
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
extern s32 __vt__12TOVS2Wreck02[];
// ---- TOVS2Wreck01
struct Base_8017C640 { char pad[0x18]; };
struct VObj_8017C640 : Base_8017C640 {
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
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
extern s32 __vt__12TOVS2Wreck01[];
// ---- TOVS2Wall01_8017C7A4
s32 load_resource_from_descriptor(int, int, void *, int, int, int);
void free_bin_model_request(void*, int);
u8 *TObjGoalWarpAncient__ct(TObjGoalWarpAncient *arg0, s32 arg1, s32 arg2);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
int bswap_header__6TLobbyFv(void*);
int init__17TOBarrierEnergy01Fv(void*);
}

#pragma defer_codegen on

extern "C" {
void *TObjGoalWarpAncient__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xEC);
    if (o != NULL) {
        o = TObjGoalWarpAncient__ct((TObjGoalWarpAncient *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}
void*TOVS2Wall01::init() { init__17TOBarrierEnergy01Fv(this); *(short *)&this->m_next = 0; *(short*)((char*)this + 0xe) = 0; *(unsigned char*)(this) = 134; *(unsigned char*)((char*)this + 0x1) = 4; return this; }
void TOVS2Wall01::update_and_send() { byteswap_hit_packet(); send_subcommand((u8 *)this); }
void TOVS2Wall01::byteswap_hit_packet() { bswap_header__6TLobbyFv(this); bswap_16((u16 *)((char*)this + 0xc)); bswap_16((u16 *)((char*)this + 0xe)); }
s32 TOVS2Wall01__sub_8017CA50(void* p) { return *(s32*)((char*)p + 0x33c); }
void TOVS2Wall01__sub_8017CA48(void* p, s32 v) { *(s32*)((char*)p + 0x33c) = v; }
}
void TOVS2Wall01::apply_knockback_from_attacker(u8 *, f32) {  }
f32 TOVS2Wall01::receive_weapon_special_attack(void *attacker, void *) { return take_hit__11TOVS2Wall01FPvUi((u8 *)this, attacker); }
f32 TOVS2Wall01::receive_direct_attack(void *attacker, DirectAttackPayload, void *, s32, s32) { return take_hit__11TOVS2Wall01FPvUi((u8 *)this, attacker); }
f32 TOVS2Wall01::receive_physical_attack(void *attacker, f32) { return take_hit__11TOVS2Wall01FPvUi((u8 *)this, attacker); }
int TOVS2Wall01::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }
s32 TOVS2Wall01::select_melee_contact_body(void *, f32) { return 1; }
s32 TOVS2Wall01::roll_physical_accuracy(void *, s32, f32) { return 1; }
s32 TOVS2Wall01::try_start_action(s32, s32) { return 1; }
TOVS2::TOVS2(void *set_data, s32 index) : TObjMapObject((TObject *)tl_05) {
    m_name = TOVS2__class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(TOVS2Wall01__bml_resource, index);
    model_radius = 50.0f + *(f32 *)((s8 *)(*(void **)((s8 *)model + 4)) + 0x14);
    texlist = TObjFish__sub_8001EDB0(TOVS2Wall01__bml_resource, index);
    init_collision_body_parts(this, &ovs2wall01_collision_parts[index], 1);
    register_object_by_id();
    m_c8 = TObjMapCsn::create((s32)set_data);
    m_cc = 1;
}
TOVS2::~TOVS2() {
    if ((void *)m_c8 != NULL) {
        queue_destruction__7TObjectFv((void *)m_c8);
        m_c8 = 0;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}
extern "C" {
void TOVS2Wall01::load_resources() {
  s32 temp_r3;
  s32 var_r0;
  temp_r3 = (int)::operator new(0x440);
  var_r0 = temp_r3;
  if (var_r0 != 0)
  {
    var_r0 = load_resource_from_descriptor((int) temp_r3, 1, &bm_o_vs2_resource_descriptor, 0, 0, 0);
  }
  (*(s32 *)&TOVS2Wall01__bml_resource) = var_r0;
  TMotorcycle::add_entry(0x3A, (int) get_bml_model(TOVS2Wall01__bml_resource, 5), (int) TObjFish__sub_8001EDB0((BmlResource *)var_r0, 5), 10.0f, 0.0f);
}
void TOVS2Wall01::release_model() {
    if ((u32) TOVS2Wall01__bml_resource != 0U) {
        free_bin_model_request((void*)TOVS2Wall01__bml_resource, 1);
        TOVS2Wall01__bml_resource = 0U;
    }
}
void TOVS2::render() {
    u8 *arg0 = (u8 *)this;
    this->m_cc = ((VObj_8017C640 *)arg0)->m8(this->view_range, *(f32 *)&this->model_radius);
    if ((s32) this->m_cc == 1) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object((void *)(*(s32 *)&this->model));
        pop_matrix();
    }
}
void *TOVS2Wreck01__ct(void *arg0, void *arg1) {
    __ct__5TOVS2FPvl(arg0, arg1, 0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOVS2Wreck01;
    ((TOVS2Wreck01 *)arg0)->m_name = TOVS2Wreck01__class_name;
    return arg0;
}
}
TOVS2Wreck01::~TOVS2Wreck01() {

}
extern "C" {
void *TOVS2Wreck01__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = TOVS2Wreck01__ct(o, arg0);
    }
    return o;
}
void *TOVS2Wreck02__ct(void *arg0, void *arg1) {
    __ct__5TOVS2FPvl(arg0, arg1, 1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOVS2Wreck02;
    ((TOVS2Wreck02 *)arg0)->m_name = TOVS2Wreck02__class_name;
    return arg0;
}
}
TOVS2Wreck02::~TOVS2Wreck02() {

}
extern "C" {
void *TOVS2Wreck02__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = TOVS2Wreck02__ct(o, arg0);
    }
    return o;
}
void *TOVS2Wreck03__ct(void *arg0, void *arg1) {
    __ct__5TOVS2FPvl(arg0, arg1, 2);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOVS2Wreck03;
    ((TOVS2Wreck03 *)arg0)->m_name = TOVS2Wreck03__class_name;
    return arg0;
}
}
TOVS2Wreck03::~TOVS2Wreck03() {

}
extern "C" {
void *TOVS2Wreck03__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = TOVS2Wreck03__ct(o, arg0);
    }
    return o;
}
void *TOVS2Wreck04__ct(void *arg0, void *arg1) {
    __ct__5TOVS2FPvl(arg0, arg1, 3);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOVS2Wreck04;
    ((TOVS2Wreck04 *)arg0)->m_name = TOVS2Wreck04__class_name;
    return arg0;
}
}
TOVS2Wreck04::~TOVS2Wreck04() {

}
extern "C" {
void *TOVS2Wreck04__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = TOVS2Wreck04__ct(o, arg0);
    }
    return o;
}
void *TOVS2Wreck05__ct(void *arg0, void *arg1) {
    __ct__5TOVS2FPvl(arg0, arg1, 4);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOVS2Wreck05;
    ((TOVS2Wreck05 *)arg0)->m_name = TOVS2Wreck05__class_name;
    return arg0;
}
}
TOVS2Wreck05::~TOVS2Wreck05() {

}
extern "C" {
void *TOVS2Wreck05__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = TOVS2Wreck05__ct(o, arg0);
    }
    return o;
}
void *TOVS2Wreck06__ct(void *arg0, void *arg1) {
    __ct__5TOVS2FPvl(arg0, arg1, 5);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOVS2Wreck06;
    ((TOVS2Wreck06 *)arg0)->m_name = TOVS2Wreck06__class_name;
    return arg0;
}
}
TOVS2Wreck06::~TOVS2Wreck06() {

}
extern "C" {
void *TOVS2Wreck06__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = TOVS2Wreck06__ct(o, arg0);
    }
    return o;
}
#pragma push
#pragma opt_common_subs off
void *TOVS2Wall01__ct(TOVS2Wall01 *arg0, void *arg1) {
    s32 t;
    __ct__9TObjCharaFP7TObject(arg0, tl_05);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TOVS2Wall01;
    __ct__15RenderFadeStateFv(((void *)((u8 *)arg0 + 0x340)));
    arg0->m_name = TOVS2Wall01__class_name;
    arg0->apply_object_set_data(arg1);
    ((TObjChara *)arg0)->calc_attach_pos();
    obj_setFlags30(arg0, 0x60000000);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model(TOVS2Wall01__bml_resource, 6);
    arg0->texlist = TObjFish__sub_8001EDB0(TOVS2Wall01__bml_resource, 6);
    init_collision_body_parts(arg0, &ovs2wall01_collision_parts[6], 1);
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x08000000);
    ((TObjPlayer *)arg0)->register_object_by_id();
    arg0->mode = 0;
    *(f32 *)((s8 *)arg0 + 0x334) = 800.0f;
    arg0->m_338 = 50.0f + *(f32 *)((s8 *)(*(void **)((s8 *)arg0->model + 4)) + 0x14);
    t = arg0->set_params[0];
    arg0->m_33c = t + 0x100;
    activate_and_dispatch__15RenderFadeStateFv((u8 *)arg0 + 0x340, t, 50.0f);
    arg0->m_35c = 1;
    return arg0;
}
#pragma pop
}
TOVS2Wall01::~TOVS2Wall01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}
extern "C" {
void *TOVS2Wall01::create() {
    void *o = __nw__7TObjectFUl(0x360);
    if (o != NULL) {
        o = TOVS2Wall01__ct((TOVS2Wall01 *)o, this);
    }
    return o;
}
void TOVS2Wall01::render() {
    u8 *arg0 = (u8 *)this;
    s32 var_r31;
    update__15RenderFadeStateFv((u8 *)&this->m_340);
    *(s32 *)&this->m_35c = ((VObj_18_26a62c *)(arg0))->m8(*(f32 *)&this->unk_334, this->m_338);
    if ((s32) this->m_35c == 1) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            var_r31 = 0;
        } else {
            var_r31 = ((RenderFadeState *)(arg0 + 0x340))->updateFromCamera((const f32*)(arg0 + 0x38));
        }
        if (var_r31 != 0) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            ((VObj_14_1eb8da *)(arg0 + (832)))->m6(chunk_polygon_flags_and_mask, model_render_flags);
        }
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
        if (var_r31 != 0) {
            ((VObj_14_1eb8da *)(arg0 + (832)))->m7();
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
    }
}
void TOVS2Wall01::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TOVS2Wall01__sub_8017B9AC(arg0);
        return;
    }
    switch (this->mode) {
    default:
        this->mode = 0;
    case 0:
        interact_player_neg1();
        return;
    case 1:
        release();
        return;
    }
}
int TOVS2Wall01::interact_player_neg1() { return submit_cursor_candidate(this, -1); }
void TOVS2Wall01::release() { set_flag8(); queue_destruction__7TObjectFv(this); }
}
