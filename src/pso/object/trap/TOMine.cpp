#include "types.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/system/vector.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/trap/TOMineTrapDisp.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOMineDisp.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/trap/TOMine.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/trap/TOMineTrap_8016F6F8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/object/trap/TOMineIcon01.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"

// ---- declarations carried over from the fragment TOMineTrapDisp_8016EDC8.cpp
extern "C" {
s32 is_locally_controlled__10TObjPlayerFPv(void);
f32 horizontal_distance_squared(void *, void *);
void get_player_state__6TOMineFv(void *, u16);
s32 fn_80171314(void *);
s32 get_room__8TObjBaseFv(void *);
}



// ---- the unit's data, in the original's order (.data, .sdata, .rodata, .sbss)
// The mine models in bm_o_mine.bml: the four light models, then the four bodies.
const char *bm_o_mine_model_names[9] = {
    "de_obj_o_zirai02_light.gj", "de_obj_o_zirai01_light.gj", "de_obj_o_zirai03_light.gj", "de_obj_o_zirai04_light.gj",
    "fe_obj_o_zirai01.gj",       "fe_obj_o_zirai02.gj",       "fe_obj_o_zirai03.gj",       "fe_obj_o_zirai04.gj",
    NULL,
};
const char *bm_o_mine_motion_names[1] = { NULL };
BmlResourceDescriptor mine_resource_desc = { "bm_o_mine.bml", bm_o_mine_model_names, bm_o_mine_motion_names, 8, 0 };
// TOMineTrap and the four TOMineIcon constructors install this one sphere.
CollisionBody mine_collision_body_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 3.0f, 0.0f, 0, 0x18005},
};
const char *TOMine__name = "TOMine";
int mine_trap_instance_id = 1;
f32 lbl_805D307C = 700.0f; // the attack power a TOMineTrap is built with
// Per floor area: the sound effects TOMine::vfunc_80 and vfunc_81 play (-1 = none),
// and the area scale the TOMineTrap constructor reads.
const s32 mine_trap_keymachine_table[36] = {
    -1,         0x4bc12,    0x4bc12,    0x43c11,    0x43c11,    0x43c11,    0x4004bc0b, 0x4004bc0b, 0x4004bc12,
    0x4004bc12, 0x4004bc12, -1,         -1,         -1,         -1,         -1,         0x4004bc07, 0x4004bc07,
    -1,         0x4bc07,    0x4bc07,    0x4004bc07, 0x4004bc07, 0x4bc19,    0x4bc19,    0x4bc19,    0x4bc19,
    0x4bc19,    0x4004bc19, 0x4004bc19, -1,         -1,         -1,         -1,         0x4004bc19, 0x4004bc19,
};
const s32 mine_trap_effect_table[36] = {
    -1,         0x4b913,    0x4b913,    0x43912,    0x43912,    0x43912,    0x4004b90c, 0x4004b90c, 0x4004b913,
    0x4004b913, 0x4004b913, -1,         -1,         -1,         -1,         -1,         0x4004b908, 0x4004b908,
    -1,         0x4b908,    0x4b908,    0x4004b908, 0x4004b908, 0x4b91a,    0x4b91a,    0x4b91a,    0x4b91a,
    0x4b91a,    0x4004b91a, 0x4004b91a, -1,         -1,         -1,         -1,         0x4004b91a, 0x4004b91a,
};
const f32 lbl_80442138[36] = {
    0.0f,  1.0f,  1.0f,  1.15f, 1.15f, 1.15f, 1.3f,  1.3f,  1.45f, 1.45f, 1.45f, 0.0f,
    0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  1.15f, 1.15f, 1.3f,
    1.3f,  1.3f,  1.3f,  1.3f,  1.45f, 1.45f, 0.0f,  0.0f,  0.0f,  0.0f,  1.45f, 1.45f,
};
const char *TOMineTrap__data_805D3080 = "TOMineTrap";
const char *TOMineDisp__name = "TOMineDisp";
const char *TOMineTrapDisp__name = "TOMineTrapDisp";
BmlResource *lbl_805D5A50; // bm_o_mine.bml, loaded by TOMine::load_static_resource
int mine_trap_count;

struct VBase_8016EFB4 { u8 pad[0x18]; };
struct VObj_8016EFB4 : VBase_8016EFB4 {
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
extern "C" {
s32 is_locally_controlled__10TObjPlayerFPv(void);
f32 horizontal_distance_squared(void *, void *);
void get_player_state__6TOMineFv(void *, u16);
s32 fn_80171314(void *);
s32 get_camera_mode__11TCameraCtrlFv();
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
}

// ---- declarations carried over from the fragment text_8016F1C0.cpp
extern "C" {
void *get_shared_text_buffer(void);
void text_builder_append(const char *);
}

void text_builder_reset(void);
extern "C" {
s32 is_split_screen();
extern s32 local_client_id;
}

struct Pkt_8016F558 { u8 code, words; u16 object, sub, idx; };
struct Obj_8016F64C { u8 pad0[0x2FC]; u8 sub[0x58]; s32 state; };
struct VBase_8016F418 { u8 pad[0x18]; };
struct VObj_8016F418 : VBase_8016F418 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84();
};
struct Pkt_8016F418 { u8 pad[4]; u16 id; u16 kind; };
extern "C" {
void TOMineTrap__sub_8017141C(void *);
void *spawn_particle_effect(void *pos, s32 id);
int get_player_data__10TObjPlayerFi(int a0);
s16 TOMineTrap__sub_80171340(void *);
u16 TOMineTrap__sub_80171358(void *);
extern s32 lbl_805D5868;
extern s32 registered_player_count;
extern s32 lbl_805D5870;
void handle_6x80_trigger_trap(Pkt_8016F418 *arg0);
}

// ---- declarations carried over from the fragment TOMineTrap_8016F6F8.cpp
struct Trap_8016F704 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x84 - 0x44]; s32 delay; u8 pad88[0x2A8 - 0x88]; void *target; u8 pad2AC[0x34C - 0x2AC]; f32 range; u8 pad350[0x35C - 0x350]; u16 targetId; };
extern "C" {
s32 obj_testFlags30__14TObjCollidableFUl(void *, u32);
s32 get_current_floor(void);
f32 horizontal_distance_squared(void *, void *);
extern u8 lobby_rule_settings[];
u16 get_entity_id(void *);
extern s32 enable_v2_features;
s32 create_placed_trap__10TOMineTrapFUiss(u32 arg0, s16 arg1, s16 arg2);
s32 is_split_screen();
extern s32 local_client_id;
}

struct VBase_18_33b813
{
  char pad[0x18];
};
struct VObj_18_33b813 : VBase_18_33b813 {
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
    virtual s32 m20(s32, f32);
};
struct Stack_80170AC8
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};
struct Node_801702C8 { u8 pad[0xC]; Node_801702C8 *next; };
struct VBase_18_1da615 { char pad[0x18]; };
struct VObj_18_1da615 : VBase_18_1da615 {
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
    virtual s32 m20(s32, f32);
    virtual f32 m21(void *, void *, s32, s32, s32);
    virtual void m22();
    virtual s32 m23(void *, f32);
};
extern "C" {
s32 get_localized_text_entry(s32 arg0, s32 arg1);
s32 get_main_phase();
s32 play_sound_effect(s32, s32, s32, s32);
void TOMineTrap__sub_80170CD4(void* p);
void record_attack_source(void *object, u16 id);
f32 atan2_float(f32 y, f32 x);
f32 vec3_add_to(void *, void *);
f32 vec_squared_length(u8 *arg0);
f32 subtract_vector(void *, void *);
f32 normalize_vector(void *);
int get_player_data__10TObjPlayerFi(int a0);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern s32 lbl_805D5868;
extern s32 TOMineIcon01__name;
extern s32 TOMineIcon02__name;
extern s32 TOMineIcon03__name;
extern s32 TOMineIcon04__name;
u8 *get_battle_param__10TObjPlayerFi(s32);
extern s32 game_difficulty_selection;
typedef struct VBase_18_33b813 VBase_18_33b813;
typedef struct VObj_18_33b813 VObj_18_33b813;
typedef struct Stack_80170AC8 Stack_80170AC8;
}

// ---- declarations carried over from the fragment TOMine.cpp
struct RecoveredFields_80170F0C_arg0
{
  u8 unknown_0[0x2A8];
  s32 field_2A8;
  u8 unknown_2AC[0xA0];
  f32 field_34C;
  u8 unknown_350[0xC];
  u16 field_35C;
};
struct VBase_801710E4 { char pad[0x18]; };
struct VObj_801710E4 : VBase_801710E4 {
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
extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u16 find_nearest_visible_player(void *, int, f32);
void push_matrix();
void post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void obj_setFlags30(void *, u32);
void free_bin_model_request(void*, int);
int submit_target_to_player_cursor(void*);
void __dl__7TObjectFPv(void *);
typedef struct RecoveredFields_80170F0C_arg0 RecoveredFields_80170F0C_arg0;
}

// ---- declarations carried over from the fragment TOMineTrap.cpp
extern "C" {
void TOMineTrap__sub_80171368(f32 farg0);
s16 TOMineTrap__sub_80171340(void* p);
int TOMineTrap__sub_80171350(void);
u16 TOMineTrap__sub_80171358(void* p);
void TOMineTrap__sub_8017141C(void* p);
}

// ---- functions, last address first (deferred codegen emits them in reverse)
extern "C" {
void TOMineTrap__sub_8017141C(void* p) { *(u8*)((char*)p + 0x0) = 128; *(u8*)((char*)p + 0x1) = 2; }
}

extern "C" {
void TOMineTrap::send_and_handle_60() { bswap_6x80_trigger_trap(); send_subcommand((u8 *)this); }
}

extern "C" {
void TOMineTrap::bswap_6x80_trigger_trap() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }
}

int TOMineTrap::calc_distance_accuracy_penalty(void *attacker, void *, void *, float) {
    if (attacker != target) {
        return 1;
    }
    return 0;
}

s32 TOMineTrap::select_melee_contact_body(void *attacker, f32) {
    if (attacker != target) {
        return 1;
    }
    return 0;
}

extern "C" {
void TOMine::vfunc_84() {  }
}

extern "C" {
void TOMineTrap::set_trap_count(int a0) { mine_trap_count = a0; }
}

extern "C" {
void TOMineTrap::set_instance(int a0) { mine_trap_instance_id = a0; }
}

extern "C" {
void TOMineTrap__sub_80171368(f32 farg0) {
    lbl_805D307C = farg0;
}
}

extern "C" {
int TOMineTrap::get_trap_count() {  return mine_trap_count; }
}

extern "C" {
u16 TOMineTrap__sub_80171358(void* p) { return *(u16*)((char*)p + 0x37e); }
}

extern "C" {
int TOMineTrap__sub_80171350(void) {  return mine_trap_instance_id; }
}

extern "C" {
void TOMineTrap::sub_80171348(u16 v) { this->m_2d8 = v; }
}

extern "C" {
s16 TOMineTrap__sub_80171340(void* p) { return *(s16*)((char*)p + 0x326); }
}

extern "C" {
u16 TOMineTrap::get_trap_type() { return this->m_2d8; }
}

extern "C" {
s32 fn_80171314(void *p) { return ((TObjPlayer *)p)->check_flag(0x10000); }
}

extern "C" {
TOMine::TOMine(TObject *parent) : TObjChara(parent) {
    m_name = TOMine__name;
    phase = 0;
    m_350 = 0.0f;
    pad_34C = 0.0f;
    attack.power = 0.0f;
    attack.kind = 0;
    m_35c = 0xFFFF;
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    m_340 = 0;
    m_370 = 0;
    obj_setFlags30(this, 0x60000000);
    actorFlags &= ~0x40000;
}
}

TOMine::~TOMine() {}

extern "C" {
void TOMine::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &mine_resource_desc, 0, 0, 0));
    }
    (*(s32 *)&lbl_805D5A50) = var_r0;
}
}

extern "C" {
void TOMine::free_instance() {
    if (lbl_805D5A50 != NULL) {
        free_bin_model_request(lbl_805D5A50, 1);
        lbl_805D5A50 = NULL;
    }
}
}

extern "C" {
void TOMine::render() {
    VObj_801710E4 *arg0 = (VObj_801710E4 *)this;
    s32 t;
    if (*(s16 *)((s8 *)arg0 + 0x326) == 3 && arg0->m8(400.0f, 20.0f) != 0) {
        push_matrix();
        post_translate_matrix((u8 *) arg0 + 0x38);
        rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x370));
        free_parts();
        TParticleCtrl::begin_effect_render();
        t = model_render_flags;
        saved_model_render_flags = t;
        model_render_flags = t | 0x20;
        ((void (*)(void *, s32)) set_constant_material)((u8 *) arg0 + 0x360, t);
        free_sub_objects();
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}
}

extern "C" {
void TOMine::free_parts() { TObjFish::set_global_param(this->texlist); draw_ginja_object(this->model); }
}

extern "C" {
void TOMine::free_sub_objects() { TObjFish::set_global_param((s32)(*(void**)((char*)this + 0x378))); draw_ginja_object(*(void**)((char*)this + 0x374)); }
}

extern "C" {
void TOMine::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    if (TObjPlayer::check_demo_mode() != 1) {
        this->vfunc_79();
        ((TOMine *)arg0)->update_float_height();
        switch (this->mode) {
        case 2:
        case 0:
            find_target_player();
            VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x334));
            VecCopy((Vec *)(*(s32 *)&this->bodies + 0x1C), (const Vec *)(arg0 + 0x334));
            return;
        case 3:
            temp_r3 = this->set_params[2];
            this->set_params[2] = (temp_r3 - 1);
            if (temp_r3 < 0) {
                this->mode = 4;
            }
            switch (this->m_344) {
            default:
                TOMineTrap__sub_80170CD4((arg0));
                break;
            case 1:
                ((TOMine *)arg0)->sub_80170BEC();
                break;
            case 2:
                ((TOMine *)arg0)->follow_target();
                break;
            }
            submit_cursor_candidate(arg0, -1);
            return;
        case 4:
            ((TOMine *)arg0)->detonate();
            break;
        }
    }
}
}

extern "C" {
int TOMine::find_target_player() {
    u8 *arg0 = (u8 *)this;
  u16 temp_r3;
  unsigned short new_var;
  ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C = find_nearest_visible_player((void *) arg0, 0, (f32) ((RecoveredFields_80170F0C_arg0 *) arg0)->field_34C);
  temp_r3 = ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C;
  new_var = -1;
  if (temp_r3 != new_var)
  {
    ((RecoveredFields_80170F0C_arg0 *) arg0)->field_2A8 = (s32)get_player_by_client_id(temp_r3);
    ((TOMine *)arg0)->update_trigger();
  }
  return ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C;
}
}

extern "C" {
int TOMine::get_player_state() { return submit_target_to_player_cursor(this); }
}

#pragma push
#pragma fp_contract on
extern "C" {
void TOMine::detonate() {
    s32 i;
    u8 *obj;
    set_indexed_flags(0, 2);
    *(f32 *)(*(u8 * *)&this->bodies + 0xC) = this->m_350;
    TObjPlayer::init_all_slots();
    ((TObjPlayer *)((u8 *)this))->check_object_collisions();
    check_enemy_body_collisions(this);
    for (i = 0; i < 0x10; i++) {
        obj = get_battle_param__10TObjPlayerFi(i);
        if (TObjPlayer::is_valid_and_active((u32)obj) != 0) {
            DirectAttackPayload pair = attack;
            f32 r = ((VObj_18_1da615 *)obj)->m21(this, &pair, 0, -1, -1);
            if (attack.kind < 5) {
                ((VObj_18_1da615 *)obj)->m23(this, 0.1f * r);
            }
        }
    }
    this->mode = 6;
    this->clear_player_status_flag(0, 1);
    this->receive_physical_attack(0, 1.0f);
}
}

extern "C" {
void TOMineTrap::sync_position() { VecCopy(&position, &float_position); refresh_collision_body_centers(); }
}

extern "C" {
void TOMine::update_float_height() {
    f32 temp_f1;
    f32 temp_f4;
    if (!(this->m_340 & 2)) {
        temp_f4 = float_position.y;
        float_position.y = (f32) (temp_f4 + ((0.5f * ((25.0f + this->home_position.y) - temp_f4)) + 1.0f));
        temp_f1 = 25.0f + this->home_position.y;
        if (temp_f1 <= float_position.y) {
            float_position.y = temp_f1;
            this->m_340 = (s32) (this->m_340 | 2);
        }
    } else {
        *(s32 *)&this->rotation_x = (s32) (*(s32 *)&this->rotation_x + 0x800);
        float_position.y = (f32) (float_position.y + sin_table_lookup(*(s32 *)&this->rotation_x));
    }
}
}

extern "C" {
void TOMineTrap__sub_80170CD4(void* p) { ((TOMineTrap *)p)->sync_position(); }
}

extern "C" {
void TOMine::sub_80170BEC() {
    u8 *p;
    s32 i;
    switch (this->phase) {
    case 0:
        this->phase = 1;
        for (i = lbl_805D5870; i < lbl_805D5868; i++) {
            p = (u8 *)get_player_data__10TObjPlayerFi(i);
            if (p != NULL && p != ((u8 *)this) &&
                (check_value_equals__13TUnk_804B6C24Fl(p, TOMineIcon01__name) != 0 ||
                 check_value_equals__13TUnk_804B6C24Fl(p, TOMineIcon02__name) != 0 ||
                 check_value_equals__13TUnk_804B6C24Fl(p, TOMineIcon03__name) != 0 ||
                 check_value_equals__13TUnk_804B6C24Fl(p, TOMineIcon04__name) != 0) &&
                *(s32 *)(p + 0x344) == 1 && *(s32 *)(p + 0x348) == *(s32 *)(((u8 *)this) + 0x348)) {
                ((TOMine *)p)->update_trigger();
            }
        }
        break;
    }
    ((TOMineTrap *)((u8 *)this))->sync_position();
}
}

extern "C" {
void TOMine::follow_target() {
    u8 *arg0 = (u8 *)this;
  unsigned short new_var;
  Stack_80170AC8 stack;
  f32 temp_f2;
  new_var = -1U;
  if (((this->m_35c) == new_var) || ((this->target) == 0))
  {
    this->mode = 2;
    return;
  }
  VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
  VecCopy((Vec *)(&stack.sp8), (const Vec *)((this->target) + 0x38));
  stack.spC = *((f32 *) (((s8 *) arg0) + 0x3C));
  subtract_vector(&stack.sp8, (u8 *)&this->position);
  if (2.0f < vec_squared_length((u8 *)&stack.sp8))
  {
    normalize_vector(&stack.sp8);
    stack.sp8 *= 2.0f;
    stack.sp10 *= 2.0f;
  }
  vec3_add_to((u8 *)&this->position, &stack.sp8);
  ((TObjPlayer *)arg0)->update_enemy_collision_flags();
  temp_f2 = *((f32 *) (((s8 *) arg0) + 0x48));
  *((f32 *) (((s8 *) arg0) + 0x3C)) = (f32) ((0.5f * ((25.0f + (*((f32 *) ((this->target) + 0x3C)))) - temp_f2)) + temp_f2);
  ((TObjChara *)arg0)->calc_attach_pos();
  this->rotation_y = (s32) (10430.38043493439 * atan2_float((f64) stack.sp8, (f64) stack.sp10));
  ((TObjCollidable *)arg0)->refresh_collision_body_centers();
}
}

#pragma pop
extern "C" {
void TOMine::vfunc_86() {
    u8 *arg0 = (u8 *)this;
    this->mode = 2;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    ((TObjChara *)arg0)->calc_attach_pos();
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TOMine *)(arg0))->vfunc_81();
}
}

extern "C" {
void TOMine::update_trigger() {
    s16 sp8;
    if (((u16) this->entity_id >= 0x4000U) && ((u32) this->set_entry != 0U) && (access_object_saved_state(&sp8, 1) != 0)) {
        this->mode = 3;
        sp8 = this->mode;
        send_object_state_update(&sp8);
    }
}
}

extern "C" {
f32 TOMine::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
  s32 temp_r0;
  s32 var_r31;
  if (arg1 == 0)
  {
    return 0.0f;
  }
  if (this->is_target_in_list(arg1) == 1)
  {
    return 0.0f;
  }
  var_r31 = 0;
  if ((get_entity_id((void *) arg1) < 4U) && (TObjPlayer::is_locally_controlled((void *) arg1) != 0))
  {
    var_r31 = 1;
  }
  if (var_r31 != 0)
  {
    temp_r0 = payload.kind;
    if (temp_r0 != 0x13)
    {
      if ((temp_r0 < 0x13) && (temp_r0 < 5))
      {
        if (temp_r0 < 0)
        {
          if ((temp_r0 && temp_r0) && temp_r0)
          {
          }
        }
        else
        {
          goto block_13;
        }
      }
    }
    else
    {
      block_13:
      (this->receive_physical_attack(0, (1.0f)));
    }
  }
  return 0.0f;
}
}

extern "C" {
f32 TOMine::receive_weapon_special_attack(void *arg1, void *) {
    if (is_target_in_list(arg1) == 1) {
        return 0.0f;
    }
    if ((TObjPlayer::is_locally_controlled((void *)arg1) != 0) && (((TObjPlayer *)arg1)->obj_getS16_116() != 0)) {
        this->receive_physical_attack(0, 1.0f);
    }
    return 0.0f;
}
}

extern "C" {
f32 TOMine::receive_physical_attack(void *, f32) {
    s16 sp8;
    if (((u16) this->entity_id >= 0x4000U) && ((u32) this->set_entry != 0U) && (access_object_saved_state(&sp8, 1) != 0)) {
        this->mode = 5;
        sp8 = this->mode;
        send_object_state_update(&sp8);
    }
    return 0.0f;
}
}

extern "C" {
void TOMine::vfunc_6(s16 *arg1, s32 arg2) {
    s16 temp_r0;
    temp_r0 = *(s16 *)((s8 *)arg1 + 0);
    if (temp_r0 == 5) {
        if (arg2 == 1) {
            sub_8017070C();
        }
        set_flag8();
        queue_destruction();
        access_object_saved_state(arg1, 0);
        return;
    }
    if (temp_r0 == 3) {
        this->mode = temp_r0;
        set_indexed_flags(0, 1);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
        this->calc_attach_pos();
        refresh_collision_body_centers();
        this->vfunc_81();
        access_object_saved_state(arg1, 0);
        this->queue_destruction_for_each_node();
    }
}
}

extern "C" {
void TOMine::sub_8017070C() {
    spawn_particle_effect(((void *) (((u8 *)this) + 0x2FC)), 0x47);
    this->vfunc_82();
    this->vfunc_80();
}
}

extern "C" {
// Slot 82: the detonation particle (inferred; was named detonate_if_triggered on TOMineTrap).
void TOMine::vfunc_82() {
    s32 arg0 = (s32)this;
    {
        TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect((void *)(arg0 + 0x2FC), 0x45);
        if (particle != NULL) {
            particle->set_scale(1.25f, 1.25f);
        }
    }
}
}

extern "C" {
// Slot 80: plays the floor area's mine_trap_keymachine_table sound (was named attach_to_keymachine on TOMineTrap).
void TOMine::vfunc_80() {
    s32 arg0 = (s32)this;
    s32 area = get_current_floor_area();
    s32 elem = mine_trap_keymachine_table[area];
    if (elem != -1) {
        play_sound_effect(elem, arg0 + 0x38, 0, 0);
    }
}
}

extern "C" {
// Slot 81: plays the floor area's mine_trap_effect_table sound (was named spawn_effect on TOMineTrap).
void TOMine::vfunc_81() {
    s32 arg0 = (s32)this;
    s32 area = get_current_floor_area();
    s32 elem = mine_trap_effect_table[area];
    if (elem != -1) {
        play_sound_effect(elem, arg0 + 0x38, 0, 0);
    }
}
}

extern "C" {
void TOMine::update_state() {
    s32 temp_r0;
    *(s32 *)((s8 *)this + 0x348) = (s32) this->scale.z;
    temp_r0 = *(s32 *)((s8 *)this + 0x348);
    if (temp_r0 < 0) {
        *(s32 *)&this->m_344 = 0;
        return;
    }
    if (temp_r0 > 0) {
        *(s32 *)&this->m_344 = 1;
        return;
    }
    if (get_main_phase() == 0xE) {
        *(s32 *)&this->m_344 = 0;
        *(s32 *)&this->set_params[2] = 0x1E;
        return;
    }
    *(s32 *)&this->m_344 = 2;
}
}

extern "C" {
const char *TOMine::get_name() { return (const char *)get_localized_text_entry(16, 16); }
}

extern "C" {
void TOMine::vfunc_85() {  }
}

extern "C" {
void TOMine::apply_object_set_data(void *set_data) {
    TObjBase::apply_object_set_data(set_data);
    this->spawn_disp_objects();
    VecCopy(&float_position, &position);
}
}

extern "C" {
void TOMine::spawn_disp_objects() {
    TOMineDisp *disp;
    u16 i;
    if (is_split_screen() == 0) {
        disp = new TOMineDisp(this, local_client_id);
        if (disp != NULL) {
            VecCopy(&disp->home_position, &home_position);
            VecCopy(&disp->position, &position);
        }
    } else {
        for (i = 0; i != 4; i++) {
            disp = new TOMineDisp(this, i);
            if (disp != NULL) {
                VecCopy(&disp->home_position, &home_position);
                VecCopy(&disp->position, &position);
            }
        }
    }
}
}

s32 TOMine::select_melee_contact_body(void *attacker, f32) {
    if (is_target_in_list(attacker) == 1) {
        return 0;
    }
    if (((s32) this->m_344 == 2) && (attacker == this->target)) {
        return 0;
    }
    if (TObjPlayer::is_locally_controlled(attacker) != 0) {
        return 1;
    }
    return 0;
}

int TOMine::calc_distance_accuracy_penalty(void *attacker, void *, void *, float) {
    if (is_target_in_list(attacker) == 1) {
        return 0;
    }
    if (((s32) this->m_344 == 2) && (attacker == this->target)) {
        return 0;
    }
    if (TObjPlayer::is_locally_controlled(attacker) != 0) {
        return 1;
    }
    return 0;
}

extern "C" {
void TOMine::vfunc_79() {  }
}

extern "C" {
void TOMine::apply_knockback_from_attacker(u8 *, f32) {  }
}

extern "C" {
s32 TOMine::try_start_action(s32, s32) { return 1; }
}

extern "C" {
s32 TOMine::roll_physical_accuracy(void *, s32, f32) { return 1; }
}

extern "C" {
s32 TOMine::is_target_in_list(void *obj) {
    TOMine *self = this;
    if (obj != 0) {
        u32 id = get_entity_id(obj);
        if (id < 4) {
            Node_801702C8 *n;
            for (n = *(Node_801702C8 * *)&self->m_down; n != 0; n = n->next) {
                if (((TOMineTrap *)n)->matches_id(id) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
TOMineTrap::TOMineTrap(TObjBase *owner, s16 kind, s16 slot) : TOMine(tl_05) {
    TObjPlayer *player;
    s32 floor;
    f32 area_scale;

    m_name = TOMineTrap__data_805D3080;
    m_380 = 0;
    if (owner != NULL) {
        sub_80171348(get_entity_id(owner));
    } else {
        m_2d8 = 0xFFFF;
    }
    player = NULL;
    if (get_trap_type() != 0xFFFF && get_trap_type() < 0x1000) {
        player = get_player_by_client_id(get_trap_type());
    }
    get_current_floor_area();
    floor = get_current_floor();
    if (enable_v2_features == 1 && owner != NULL && player != NULL && floor == player->get_floor() &&
        is_current_area_item_enabled() == 1 && is_boss_area() == 0) {
        switch (kind) {
        default:
            kind = 0;
        case 0:
            attack.kind = 1;
            if (((TLobby *)lobby_rule_settings)->get_rule_field_0() == 1) {
                attack.power = lbl_805D307C;
            } else {
                area_scale = lbl_80442138[get_current_floor_area()];
                attack.power = 700.0f * area_scale *
                               (2.0f * (0.01f * (f32)player->get_actor_level_index() + 0.1f));
            }
            if (attack.power < 0.0f) {
                attack.power = 0.0f;
            }
            break;
        case 1:
            attack.kind = 2;
            attack.power = 0.0f;
            break;
        case 2:
            attack.kind = 17;
            attack.power = 0.0f;
            break;
        case 3:
            attack.kind = 18;
            attack.power = 0.0f;
            break;
        }
        m_37e = slot + kind * 20 + get_trap_type() * 80u;
        VecCopy(&float_position, VecCopy(&home_position, VecCopy(&position, &owner->position)));
        ((TObjPlayer *)this)->init_position_vectors();
        calc_attach_pos();
        spawn_disp_objects();
        m_370 = owner->rotation_y;
        alt_room = owner->alt_room;
        room = owner->room;
        switch (attack.kind) {
        default:
            attack.kind = 1;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 19:
            model = (void *)get_bml_model(lbl_805D5A50, 4);
            texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 4);
            m_374 = get_bml_model(lbl_805D5A50, 1);
            m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 1);
            break;
        case 15:
        case 16:
        case 17:
        case 18:
            model = (void *)get_bml_model(lbl_805D5A50, 5);
            texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 5);
            m_374 = get_bml_model(lbl_805D5A50, 0);
            m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 0);
            break;
        }
        mode = 0;
        pad_34C = 50.0f;
        m_350 = 50.0f;
        set_params[0] = 150;
        set_params[1] = 30;
        if (game_difficulty_selection == 3 && ((TLobby *)lobby_rule_settings)->get_rule_field_0() == 0) {
            set_params[0] = 60;
            m_350 = 80.0f;
            set_trap_count(0);
            set_instance(1);
        }
        m_344 = 0;
        m_35c = 0xFFFF;
        actorFlags |= 0x60000000;
        init_collision_body_parts(this, mine_collision_body_parts, 1);
        register_object_by_id();
    } else {
        queue_destruction();
    }
}
}

#pragma pop
TOMineTrap::~TOMineTrap() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

extern "C" {
void *TOMineTrap::get_mine_data_ptr() { return &float_position; }
}

extern "C" {
s32 create_placed_trap__10TOMineTrapFUiss(u32 arg0, s16 arg1, s16 arg2) {
    u16 id;
    void *player;
    void *obj;
    if (enable_v2_features != 1 || arg0 == 0 || (id = get_entity_id((void *)arg0)) == 0xFFFF || id >= 0x1000 ||
        (player = (void *)get_player_by_client_id(id)) == 0 || ((TObjPlayer *)player)->get_floor() != get_current_floor() ||
        arg1 < 0 || arg1 >= 4 || arg2 < 0 || arg2 > 0x14) {
        return 0;
    }
    if (is_boss_area() == 1 || is_current_area_item_enabled() == 0) {
        return 0;
    }
    obj = new TOMineTrap((TObjBase *)arg0, arg1, arg2);
    return (s32)obj;
}
}

extern "C" {
void TOMineTrap::destroy_matching_traps() {
    void *p;
    s32 i;
    for (i = registered_player_count + lbl_805D5870; i < lbl_805D5868; i++) {
        p = (void *)get_player_data__10TObjPlayerFi(i);
        if (p != 0 && check_value_equals__13TUnk_804B6C24Fl(p, (s32)TOMineTrap__data_805D3080) != 0) {
            ((TObject *)p)->queue_destruction();
        }
    }
}
}

extern "C" {
void TOMineTrap::run_task() {
    TObjChara *attacker;
    TObjPlayer *p;
    s32 i;
    u16 id;

    update_float_height();
    switch (mode) {
    case 0:
    case 2:
        if (find_target_in_range() == 1) {
            set_triggered();
        }
        VecCopy((Vec *)&m_2fc, &float_position);
        VecCopy(&bodies->center, &float_position);
        break;
    case 3:
        if (set_params[1]-- < 0) {
            set_state();
            send_state_packet(2);
        }
        TOMineTrap__sub_80170CD4(this);
        submit_cursor_candidate(this, -1);
        break;
    case 4:
        attacker = get_player_by_client_id(get_trap_type());
        if (attacker == NULL) {
            attacker = this;
        }
        for (i = 0; i < lbl_805D5868; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == NULL || p == (TObjChara *)this || p->obj_testFlags30(0x4000800) != 0) {
                continue;
            }
            if (p->alt_room != alt_room && p->room != room && p->room != alt_room) {
                continue;
            }
            id = get_entity_id(p);
            if (id == 0xFFFF) {
                continue;
            }
            if (id == get_trap_type() && TOMineTrap::get_trap_count() != 1) {
                continue;
            }
            if (id < 0x1000) {
                TObjChara *chara = p;
                if (TObjPlayer::get_player_count() == 1 && p->get_floor() == get_current_floor() &&
                    horizontal_distance_squared(&position, &chara->position) < m_350 * m_350) {
                    if (chara->obj_isState2_324() == 0) {
                        target = (u8 *)chara;
                        switch (attack.kind) {
                        case 2:
                            ((TObjChara *)target)->apply_movement_ailment(0);
                            break;
                        default:
                            ((TObjChara *)target)->receive_direct_attack(this, attack, 0, -1, -1);
                            break;
                        }
                        record_attack_source(target, get_trap_type());
                    }
                    if (m_380 != 1) {
                        m_380 = show_owner_message(chara);
                    }
                }
            } else if (id < 0x4000) {
                if (horizontal_distance_squared(&position, &p->position) < m_350 * m_350) {
                    target = (u8 *)p;
                    switch (attack.kind) {
                    case 2:
                        ((TObjChara *)target)->apply_movement_ailment(0);
                        ((TObjChara *)target)->vfunc_74(0);
                        break;
                    default:
                        ((TObjChara *)target)->receive_direct_attack(attacker, attack, 0, -1, -1);
                        break;
                    }
                    record_attack_source(target, get_trap_type());
                }
            } else if (check_value_equals__13TUnk_804B6C24Fl(p, (s32)TOMineTrap__data_805D3080) != 0) {
                if (horizontal_distance_squared(&position, &p->position) < m_350 * m_350) {
                    target = (u8 *)p;
                    ((TObjChara *)target)->receive_physical_attack(this, 1.0f);
                }
            }
        }
        mode = 5;
        clear_player_status_flag(0, 1);
        sub_8017070C();
        queue_destruction();
        break;
    }
}
}

extern "C" {
void TOMineTrap::vfunc_86() {
    u8 *arg0 = (u8 *)this;
    this->mode = 2;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}
}

extern "C" {
void TOMineTrap::set_triggered() {
    u8 *arg0 = (u8 *)this;
    this->mode = 3;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}
}

extern "C" {
s32 TOMineTrap::find_target_in_range() {
    Trap_8016F704 *self = (Trap_8016F704 *)this;
    u8 *p;
    s32 i;
    u16 id;

    self->targetId = 0xFFFF;
    self->target = 0;
    if (self->delay > 0) {
        self->delay--;
        return 0;
    }
    for (i = 0; i < registered_player_count + lbl_805D5870; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (p == 0 || p == (u8 *)self || obj_testFlags30__14TObjCollidableFUl(p, 0x800) != 0) {
            continue;
        }
        id = get_entity_id(p);
        if (id == 0xFFFF) {
            continue;
        }
        if (id == ((TOMineTrap *)self)->get_trap_type() && TOMineTrap::get_trap_count() != 1 &&
            ((TLobby *)lobby_rule_settings)->get_rule_field_0() != 0) {
            continue;
        }
        if (id < 0x1000) {
            if (((TObjPlayer *)p)->get_floor() != get_current_floor()) {
                continue;
            }
            if (horizontal_distance_squared(self->pos, p + 0x38) < self->range * self->range) {
                self->targetId = id;
                self->target = p;
                return 1;
            }
        } else if (id < 0x4000) {
            if (horizontal_distance_squared(self->pos, p + 0x38) < self->range * self->range) {
                self->targetId = id;
                self->target = p;
                return 1;
            }
        }
    }
    return 0;
}
}

extern "C" {
void TOMineTrap::set_state() { this->mode = 4; }
}

extern "C" {
void TOMineTrap::vfunc_82() {
    Obj_8016F64C *arg0 = (Obj_8016F64C *)this;
    u32 r;
    switch (this->attack.kind) {
    default:
        r = (u32)spawn_particle_effect(arg0->sub, 0x45);
        if (r != 0U) {
            ((TParticleCtrl *)r)->set_scale(1.25f, 1.25f);
        }
        break;
    case 15:
    case 16:
    case 17:
    case 18:
        spawn_particle_effect(arg0->sub, 0x8E);
        spawn_particle_effect(arg0->sub, 0x8E);
        break;
    case 6:
    case 7:
        spawn_particle_effect(arg0->sub, 0x8D);
        spawn_particle_effect(arg0->sub, 0x8D);
        break;
    }
}
}

f32 TOMineTrap::receive_physical_attack(void *attacker, f32) {
    switch (mode) {
    case 0:
    case 1:
    case 2:
        if ((attacker != NULL) && (check_value_equals__13TUnk_804B6C24Fl(attacker, (s32)TOMineTrap__data_805D3080) != 0)) {
            set_triggered();
            if (set_params[1] > 0xF) {
                set_params[1] = 0xF;
            }
            break;
        }
    case 3:
        set_state();
        send_state_packet(2);
        break;
    }
    return 0.0f;
}

extern "C" {
void TOMineTrap::send_state_packet(u16 idx) {
    TOMineTrap *self = this;
    if (idx < 3) {
        Pkt_8016F558 pkt;
        TOMineTrap__sub_8017141C(&pkt);
        pkt.object = self->entity_id;
        pkt.sub = self->m_37e;
        pkt.idx = idx;
        ((TOMineTrap *)(&pkt))->send_and_handle_60();
    }
}
}

extern "C" {
void handle_6x80_trigger_trap(Pkt_8016F418 *arg0) {
    VObj_8016F418 *p;
    s32 i;
    if (arg0 == NULL) {
        return;
    }
    ((TOMineTrap *)arg0)->bswap_6x80_trigger_trap();
    for (i = registered_player_count + lbl_805D5870; i < lbl_805D5868; i++) {
        p = (VObj_8016F418 *)get_player_data__10TObjPlayerFi(i);
        if (p == NULL) {
            continue;
        }
        if (check_value_equals__13TUnk_804B6C24Fl(p, (s32)TOMineTrap__data_805D3080) == 0) {
            continue;
        }
        if (arg0->id != TOMineTrap__sub_80171358(p)) {
            continue;
        }
        switch (arg0->kind) {
        case 0:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
                p->m84();
                break;
            }
            break;
        case 1:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
            case 2:
                ((TOMineTrap *)p)->set_triggered();
                break;
            }
            break;
        case 2:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
            case 2:
            case 3:
                ((TOMineTrap *)p)->set_state();
                break;
            }
            break;
        }
        return;
    }
}
}

const char *TOMineTrap::get_name() {
    const char *name;
    TObjPlayer *player;

    name = NULL;
    player = get_player_by_client_id(get_trap_type());
    if (player != NULL) {
        name = player->get_name();
    }
    return name;
}

s32 TOMineTrap::show_owner_message(TObjChara *player) {
    const char *name;
    TObjPlayer *p;
    if (player != NULL && TTecCtrl::is_technique_ready() != 0) {
        p = get_player_by_client_id(get_trap_type());
        if (p != NULL) {
            name = p->get_name();
            if (name != NULL) {
                text_builder_reset();
                text_builder_append("\x09""C4");
                text_builder_append(name);
                text_builder_append(" TRAP\n");
                TWindowCtrl::init_all((void*)(get_shared_text_buffer()), (void*)0x200);
                return 1;
            }
        }
    }
    return 0;
}

void TOMineTrap::spawn_disp_objects() {
    TOMineTrapDisp *disp;
    u16 i;

    if (is_split_screen() == 0) {
        disp = new TOMineTrapDisp(this, local_client_id, get_trap_type());
        if (disp != NULL) {
            VecCopy(&disp->home_position, &home_position);
            VecCopy(&disp->position, &position);
        }
    } else {
        for (i = 0; i != 4; i++) {
            disp = new TOMineTrapDisp(this, i, get_trap_type());
            if (disp != NULL) {
                VecCopy(&disp->home_position, &home_position);
                VecCopy(&disp->position, &position);
            }
        }
    }
}

TOMineDisp::TOMineDisp(TObject *parent, u16 client) : TObjBase(parent) {
    m_name = TOMineDisp__name;
    m_a8 = client;
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    m_a4 = 0;
    m_90 = 0;
}

TOMineDisp::~TOMineDisp() {

}

void TOMineDisp::run_task() {
    void *mine = this->m_up;
    u8 *p;
    switch (this->m_a4) {
    case 0:
        p = (u8 *)get_player_by_client_id(this->m_a8);
        if (p != NULL && is_locally_controlled__10TObjPlayerFPv() != 0 && fn_80171314(p) != 0) {
            if (horizontal_distance_squared(((u8 *)this) + 0x38, p + 0x38) <= 40000.0f ||
                ((TObjBase *)p)->get_room() == this->get_room()) {
                this->m_a4 = 2;
            }
        }
        break;
    case 3:
        break;
    case 2:
        get_player_state__6TOMineFv(mine, this->m_a8);
        VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(((TOMineTrap *)mine)->get_mine_data_ptr()));
        break;
    }
}

void TOMineDisp::render() {
    s32 temp_r31;
    s32 temp_r4;
    u16 id = TCameraCtrl::get_nth_view_player_id(get_camera_mode__11TCameraCtrlFv());
    if (id != this->m_a8) {
        return;
    }
    if (*(s32 *)&this->m_a4 != 2) {
        return;
    }
    if (((VObj_8016EFB4 *)((u8 *)this))->m8(400.0f, 20.0f) == 0) {
        return;
    }
    push_matrix();
    temp_r31 = *(s32 *)&this->m_up;
    post_translate_matrix(((u8 *)this) + 0x38);
    rotate_matrix_y(0, this->rotation_y);
    ((TOMine *)temp_r31)->free_parts();
    TParticleCtrl::begin_effect_render();
    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x20;
    ((void (*)(void *, s32))set_constant_material)(((u8 *)this) + 0x94, temp_r4);
    ((TOMine *)temp_r31)->free_sub_objects();
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

TOMineTrapDisp::TOMineTrapDisp(TObject *parent, u16 client, u16 owner) : TOMineDisp(parent, client) {
    m_name = TOMineTrapDisp__name;
    m_ac = owner;
}

TOMineTrapDisp::~TOMineTrapDisp() {

}

void TOMineTrapDisp::run_task() {
    void *d;
    s32 hit;
    s32 i;
    u8 *pl;

    d = m_up;
    switch (m_a4) {
    case 0:
        hit = 0;
        if (TOMineTrap__sub_80171350() == 1) {
            for (i = 0; i < 4; i++) {
                pl = (u8 *)get_player_by_client_id(i);
                if (pl != 0 && is_locally_controlled__10TObjPlayerFPv() != 0) {
                    if (fn_80171314(pl) != 0 ||
                        (TTecCtrl::is_technique_ready() != 0 && m_ac == (u16)get_entity_id(pl))) {
                        if (!(horizontal_distance_squared(&position, pl + 0x38) <= 40000.0f)) {
                            if ((s16)get_room__8TObjBaseFv(pl) != (s16)get_room__8TObjBaseFv(this)) {
                                continue;
                            }
                        }
                        if (m_a8 == (u16)get_entity_id(pl)) {
                            hit = 1;
                        }
                    }
                }
            }
        }
        if (hit != 0) {
            m_a4 = 2;
        }
        return;
    case 1:
        break;
    case 2:
        get_player_state__6TOMineFv(d, m_a8);
        VecCopy(&position, (const Vec *)(((TOMineTrap *)d)->get_mine_data_ptr()));
        break;
    case 3:
        break;
    }
}

s32 TOMineTrap::matches_id(u16 arg1) {
    if ((arg1 == *(u16 *)&this->body_count) && ((s32) *(s32 *)&this->bodies != 2)) {
        return 1;
    }
    return 0;
}

