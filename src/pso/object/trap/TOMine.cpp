#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
struct game_command_header;

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
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/trap/TOMineTrap_8016F6F8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/object/trap/TOMineIcon01.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/BmlResourceDescriptor.h"


#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/network/client_id.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/map/area/AreaScene.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

// ---- declarations carried over from the fragment TOMineTrapDisp_8016EDC8.cpp
extern "C" {
f32 horizontal_distance_squared(void *, void *);
void get_player_state__6TOMineFv(void *, u16);
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

extern "C" {
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
// ---- declarations carried over from the fragment text_8016F1C0.cpp
s32 is_split_screen();
}
void text_builder_reset(void);
struct Obj_8016F64C { u8 pad0[0x2FC]; u8 sub[0x58]; s32 state; };
extern "C" {
s16 TOMineTrap__sub_80171340(TOMineTrap *p);
u16 TOMineTrap__sub_80171358(TOMineTrap *p);
void handle_6x80_trigger_trap(game_command_header *command);
// ---- declarations carried over from the fragment TOMineTrap_8016F6F8.cpp
s32 get_current_floor(void);
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
void TOMineTrap__sub_80170CD4(void* p);
f32 atan2_float(f32 y, f32 x);
f32 vec3_add_to(void *, void *);
f32 vec_squared_length(u8 *arg0);
f32 subtract_vector(void *, void *);
extern const char *TOMineIcon01__name;
extern const char *TOMineIcon02__name;
extern const char *TOMineIcon03__name;
extern const char *TOMineIcon04__name;
typedef struct VBase_18_33b813 VBase_18_33b813;
typedef struct VObj_18_33b813 VObj_18_33b813;
}

// ---- declarations carried over from the fragment TOMine.cpp
struct RecoveredFields_80170F0C_arg0
{
  u8 unknown_0[0x2A8];
  saddr player_by_client_id;
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
u16 find_nearest_visible_player(void *, int, f32);
void post_translate_matrix(void *);
int submit_target_to_player_cursor(void*);
typedef struct RecoveredFields_80170F0C_arg0 RecoveredFields_80170F0C_arg0;
// ---- declarations carried over from the fragment TOMineTrap.cpp
void TOMineTrap__sub_80171368(f32 farg0);
int TOMineTrap__sub_80171350(void);
// ---- functions, last address first (deferred codegen emits them in reverse)
void G_TriggerTrap_6x80::init() {
    header.subcommand = 0x80;
    header.size = 2;
}

void G_TriggerTrap_6x80::send() {
    bswap();
    send_subcommand(this);
}

void G_TriggerTrap_6x80::bswap() {
    header.bswap();
    bswap_16(&trap_number);
    bswap_16(&what);
}
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


void TOMine::vfunc_84() {  }
int TOMineTrap::set_trap_count(int trap_count) { mine_trap_count = trap_count; return trap_count; }
int TOMineTrap::set_instance(int instance) { mine_trap_instance_id = instance; return instance; }
void TOMineTrap__sub_80171368(f32 farg0) {
    lbl_805D307C = farg0;
}
int TOMineTrap::get_trap_count() {  return mine_trap_count; }
u16 TOMineTrap__sub_80171358(TOMineTrap *p) { return p->m_37e; }
int TOMineTrap__sub_80171350(void) {  return mine_trap_instance_id; }
void TOMineTrap::sub_80171348(u16 v) { this->m_2d8 = v; }
s16 TOMineTrap__sub_80171340(TOMineTrap *p) { return p->mode; }
u16 TOMineTrap::get_trap_type() { return this->m_2d8; }
s32 fn_80171314(TObjPlayer *player) { return player->check_flag(0x10000); }
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
    set_actor_flags(0x60000000);
    actorFlags &= ~0x40000;
}

TOMine::~TOMine() {}


void TOMine::load_static_resource() {
    lbl_805D5A50 = new BmlResource(1, &mine_resource_desc, NULL, NULL, NULL);
}
void TOMine::free_instance() {
    if (lbl_805D5A50 != NULL) {
        delete lbl_805D5A50;
        lbl_805D5A50 = NULL;
    }
}
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
void TOMine::free_parts() { TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist)); draw_ginja_object(this->model); }
void TOMine::free_sub_objects() {
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(light_textures));
    draw_ginja_object(light_model);
}
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
            VecCopy((Vec *)(*(saddr *)&this->bodies + 0x1C), (const Vec *)(arg0 + 0x334));
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
int TOMine::find_target_player() {
    u8 *arg0 = (u8 *)this;
  u16 client;
  unsigned short new_var;
  ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C = find_nearest_visible_player((void *) arg0, 0, (f32) ((RecoveredFields_80170F0C_arg0 *) arg0)->field_34C);
  client = ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C;
  new_var = -1;
  if (client != new_var)
  {
    ((RecoveredFields_80170F0C_arg0 *) arg0)->player_by_client_id = (saddr)get_player_by_client_id(client);
    ((TOMine *)arg0)->update_trigger();
  }
  return ((RecoveredFields_80170F0C_arg0 *) arg0)->field_35C;
}
int TOMine::get_player_state() { return submit_target_to_player_cursor(this); }
#pragma push
#pragma fp_contract on
void TOMine::detonate() {
    s32 i;
    u8 *obj;
    set_indexed_flags(0, 2);
    *(f32 *)(*(u8 * *)&this->bodies + 0xC) = this->m_350;
    TObjPlayer::init_all_slots();
    this->check_object_collisions();
    check_enemy_body_collisions(this);
    for (i = 0; i < 0x10; i++) {
        obj = (u8 *)TObjPlayer::get_battle_param(i);
        if (TObjPlayer::is_valid_and_active((uaddr)obj) != 0) {
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
void TOMineTrap::sync_position() { VecCopy(&position, &float_position); refresh_collision_body_centers(); }
void TOMine::update_float_height() {
    f32 y;
    f32 temp_f4;
    if (!(this->m_340 & 2)) {
        temp_f4 = float_position.y;
        float_position.y = (f32) (temp_f4 + ((0.5f * ((25.0f + this->home_position.y) - temp_f4)) + 1.0f));
        y = 25.0f + this->home_position.y;
        if (y <= float_position.y) {
            float_position.y = y;
            this->m_340 = (s32) (this->m_340 | 2);
        }
    } else {
        this->rotation_x = (this->rotation_x + 0x800);
        float_position.y = (f32) (float_position.y + sin_table_lookup(this->rotation_x));
    }
}
void TOMineTrap__sub_80170CD4(void* p) { ((TOMineTrap *)p)->sync_position(); }
void TOMine::sub_80170BEC() {
    u8 *p;
    s32 i;
    switch (this->phase) {
    case 0:
        this->phase = 1;
        for (i = registered_enemy_count; i < lbl_805D5868; i++) {
            p = (u8 *)TObjPlayer::get_player_data(i);
            if (p != NULL && p != ((u8 *)this) &&
                (reinterpret_cast<TObject *>(p)->check_value_equals(TOMineIcon01__name) != 0 ||
                 reinterpret_cast<TObject *>(p)->check_value_equals(TOMineIcon02__name) != 0 ||
                 reinterpret_cast<TObject *>(p)->check_value_equals(TOMineIcon03__name) != 0 ||
                 reinterpret_cast<TObject *>(p)->check_value_equals(TOMineIcon04__name) != 0) &&
                *(s32 *)(p + 0x344) == 1 && *(s32 *)(p + 0x348) == *(s32 *)(((u8 *)this) + 0x348)) {
                ((TOMine *)p)->update_trigger();
            }
        }
        break;
    }
    ((TOMineTrap *)((u8 *)this))->sync_position();
}
void TOMine::follow_target() {
    u8 *arg0 = (u8 *)this;
  unsigned short new_var;
  Vec stack;
  f32 temp_f2;
  new_var = -1U;
  if (((this->m_35c) == new_var) || ((this->target) == 0))
  {
    this->mode = 2;
    return;
  }
  VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
  VecCopy((Vec *)(&stack.x), &this->target->position);
  stack.y = *((f32 *) (((s8 *) arg0) + 0x3C));
  subtract_vector(&stack.x, (u8 *)&this->position);
  if (2.0f < vec_squared_length((u8 *)&stack.x))
  {
    normalize_vector(&stack);
    stack.x *= 2.0f;
    stack.z *= 2.0f;
  }
  vec3_add_to((u8 *)&this->position, &stack.x);
  update_enemy_collision_flags();
  temp_f2 = *((f32 *) (((s8 *) arg0) + 0x48));
  *((f32 *) (((s8 *) arg0) + 0x3C)) = (f32) ((0.5f * ((25.0f + this->target->position.y) - temp_f2)) + temp_f2);
  ((TObjChara *)arg0)->calc_attach_pos();
  this->rotation_y = (s32) (10430.38043493439 * atan2_float((f64) stack.x, (f64) stack.z));
  ((TObjCollidable *)arg0)->refresh_collision_body_centers();
}
#pragma pop
void TOMine::vfunc_86() {
    u8 *arg0 = (u8 *)this;
    this->mode = 2;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    ((TObjChara *)arg0)->calc_attach_pos();
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TOMine *)(arg0))->vfunc_81();
}
void TOMine::update_trigger() {
    s16 mode;
    if (((u16) this->entity_id >= 0x4000U) && ((uaddr) this->set_entry != 0U) && (access_object_saved_state(&mode, 1) != 0)) {
        this->mode = 3;
        mode = this->mode;
        send_object_state_update(&mode);
    }
}
f32 TOMine::receive_direct_attack(void *player, DirectAttackPayload payload, void *, s32, s32) {
  s32 kind;
  s32 var_r31;
  if (player == 0)
  {
    return 0.0f;
  }
  if (this->is_target_in_list(player) == 1)
  {
    return 0.0f;
  }
  var_r31 = 0;
  if ((((TObjBase *)player)->get_entity_id() < 4U) && (TObjPlayer::is_locally_controlled((void *) player) != 0))
  {
    var_r31 = 1;
  }
  if (var_r31 != 0)
  {
    kind = payload.kind;
    if (kind != 0x13)
    {
      if ((kind < 0x13) && (kind < 5))
      {
        if (kind < 0)
        {
          if ((kind && kind) && kind)
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
f32 TOMine::receive_weapon_special_attack(void *player, void *) {
    if (is_target_in_list(player) == 1) {
        return 0.0f;
    }
    if ((TObjPlayer::is_locally_controlled((void *)player) != 0) && (((TObjPlayer *)player)->obj_getS16_116() != 0)) {
        this->receive_physical_attack(0, 1.0f);
    }
    return 0.0f;
}
f32 TOMine::receive_physical_attack(void *, f32) {
    s16 mode;
    if (((u16) this->entity_id >= 0x4000U) && ((uaddr) this->set_entry != 0U) && (access_object_saved_state(&mode, 1) != 0)) {
        this->mode = 5;
        mode = this->mode;
        send_object_state_update(&mode);
    }
    return 0.0f;
}
void TOMine::vfunc_6(s16 *lobby, s32 arg2) {
    s16 mode;
    mode = *(s16 *)((s8 *)lobby + 0);
    if (mode == 5) {
        if (arg2 == 1) {
            sub_8017070C();
        }
        set_flag8();
        queue_destruction();
        access_object_saved_state(lobby, 0);
        return;
    }
    if (mode == 3) {
        this->mode = mode;
        set_indexed_flags(0, 1);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
        this->calc_attach_pos();
        refresh_collision_body_centers();
        this->vfunc_81();
        access_object_saved_state(lobby, 0);
        this->queue_destruction_for_each_node();
    }
}
void TOMine::sub_8017070C() {
    spawn_particle_effect((const Vec *)(((u8 *)this) + 0x2FC), 0x47);
    this->vfunc_82();
    this->vfunc_80();
}
// Slot 82: the detonation particle (inferred; was named detonate_if_triggered on TOMineTrap).
void TOMine::vfunc_82() {
    saddr arg0 = (saddr)this;
    {
        TParticleCtrl *particle = spawn_particle_effect((const Vec *)(arg0 + 0x2FC), 0x45);
        if (particle != NULL) {
            particle->set_scale(1.25f, 1.25f);
        }
    }
}
// Slot 80: plays the floor area's mine_trap_keymachine_table sound (was named attach_to_keymachine on TOMineTrap).
void TOMine::vfunc_80() {
    s32 area = get_current_floor_area();
    s32 elem = mine_trap_keymachine_table[area];
    if (elem != -1) {
        play_sound_effect(elem, &position, 0, 0);
    }
}
// Slot 81: plays the floor area's mine_trap_effect_table sound (was named spawn_effect on TOMineTrap).
void TOMine::vfunc_81() {
    s32 area = get_current_floor_area();
    s32 elem = mine_trap_effect_table[area];
    if (elem != -1) {
        play_sound_effect(elem, &position, 0, 0);
    }
}
void TOMine::update_state() {
    s32 temp_r0;
    *(s32 *)((s8 *)this + 0x348) = (s32) this->scale.z;
    temp_r0 = *(s32 *)((s8 *)this + 0x348);
    if (temp_r0 < 0) {
        this->m_344 = 0;
        return;
    }
    if (temp_r0 > 0) {
        this->m_344 = 1;
        return;
    }
    if (get_main_phase() == 0xE) {
        this->m_344 = 0;
        this->set_params[2] = 0x1E;
        return;
    }
    this->m_344 = 2;
}
const char *TOMine::get_name() { return (const char *)get_localized_text_entry(16, 16); }
void TOMine::vfunc_85() {  }
void TOMine::apply_object_set_data(void *set_data) {
    TObjBase::apply_object_set_data(set_data);
    this->spawn_disp_objects();
    VecCopy(&float_position, &position);
}
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


void TOMine::vfunc_79() {  }
void TOMine::apply_knockback_from_attacker(u8 *, f32) {  }
s32 TOMine::try_start_action(s32, s32) { return 1; }
s32 TOMine::roll_physical_accuracy(void *, s32, f32) { return 1; }
s32 TOMine::is_target_in_list(void *obj) {
    TOMine *self = this;
    if (obj != 0) {
        u32 id = ((TObjBase *)(obj))->get_entity_id();
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
#pragma push
#pragma fp_contract on
TOMineTrap::TOMineTrap(TObjBase *owner, s16 kind, s16 slot) : TOMine(tl_05) {
    TObjPlayer *player;
    s32 floor;
    f32 area_scale;

    m_name = TOMineTrap__data_805D3080;
    m_380 = 0;
    if (owner != NULL) {
        sub_80171348(owner->get_entity_id());
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
        init_position_vectors();
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
            model = (void *)get_bml_model((BmlResource *)lbl_805D5A50, 4);
            texlist = get_bml_texlist((BmlResource *)lbl_805D5A50, 4);
            light_model = (NJS_OBJECT *)get_bml_model((BmlResource *)lbl_805D5A50, 1);
            light_textures = get_bml_texlist((BmlResource *)lbl_805D5A50, 1);
            break;
        case 15:
        case 16:
        case 17:
        case 18:
            model = (void *)get_bml_model((BmlResource *)lbl_805D5A50, 5);
            texlist = get_bml_texlist((BmlResource *)lbl_805D5A50, 5);
            light_model = (NJS_OBJECT *)get_bml_model((BmlResource *)lbl_805D5A50, 0);
            light_textures = get_bml_texlist((BmlResource *)lbl_805D5A50, 0);
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

#pragma pop
TOMineTrap::~TOMineTrap() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}


void *TOMineTrap::get_mine_data_ptr() { return &float_position; }
saddr create_placed_trap__10TOMineTrapFUiss(uaddr owner, s16 kind, s16 slot) {
    u16 id;
    void *player;
    void *obj;
    if (enable_v2_features != 1 || owner == 0 || (id = ((TObjBase *)owner)->get_entity_id()) == 0xFFFF || id >= 0x1000 ||
        (player = (void *)get_player_by_client_id(id)) == 0 || ((TObjPlayer *)player)->get_floor() != get_current_floor() ||
        kind < 0 || kind >= 4 || slot < 0 || slot > 0x14) {
        return 0;
    }
    if (is_boss_area() == 1 || is_current_area_item_enabled() == 0) {
        return 0;
    }
    obj = new TOMineTrap((TObjBase *)owner, kind, slot);
    return (saddr)obj;
}
void TOMineTrap::destroy_matching_traps() {
    void *p;
    s32 i;
    for (i = registered_player_count + registered_enemy_count; i < lbl_805D5868; i++) {
        p = (void *)TObjPlayer::get_player_data(i);
        if (p != 0 && reinterpret_cast<TObject *>(p)->check_value_equals(TOMineTrap__data_805D3080) != 0) {
            ((TObject *)p)->queue_destruction();
        }
    }
}
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
        VecCopy(&body_center, &float_position);
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
            if (p == NULL || p == (TObjChara *)this || p->test_actor_flags(0x4000800) != 0) {
                continue;
            }
            if (p->alt_room != alt_room && p->room != room && p->room != alt_room) {
                continue;
            }
            id = p->get_entity_id();
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
                        target = chara;
                        switch (attack.kind) {
                        case 2:
                            ((TObjChara *)target)->apply_movement_ailment(0);
                            break;
                        default:
                            ((TObjChara *)target)->receive_direct_attack(this, attack, 0, -1, -1);
                            break;
                        }
                        ((TObjChara *)target)->record_attack_source(get_trap_type());
                    }
                    if (m_380 != 1) {
                        m_380 = show_owner_message(chara);
                    }
                }
            } else if (id < 0x4000) {
                if (horizontal_distance_squared(&position, &p->position) < m_350 * m_350) {
                    target = p;
                    switch (attack.kind) {
                    case 2:
                        ((TObjChara *)target)->apply_movement_ailment(0);
                        ((TObjChara *)target)->sync_enemy_state(0);
                        break;
                    default:
                        ((TObjChara *)target)->receive_direct_attack(attacker, attack, 0, -1, -1);
                        break;
                    }
                    ((TObjChara *)target)->record_attack_source(get_trap_type());
                }
            } else if (reinterpret_cast<TObject *>(p)->check_value_equals(TOMineTrap__data_805D3080) != 0) {
                if (horizontal_distance_squared(&position, &p->position) < m_350 * m_350) {
                    target = p;
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
void TOMineTrap::vfunc_86() {
    u8 *arg0 = (u8 *)this;
    this->mode = 2;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}
void TOMineTrap::set_triggered() {
    u8 *arg0 = (u8 *)this;
    this->mode = 3;
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}
s32 TOMineTrap::find_target_in_range() {
    TObjChara *actor;
    s32 i;
    u16 id;

    m_35c = 0xFFFF;
    target = 0;
    if (set_params[0] > 0) {
        set_params[0]--;
        return 0;
    }
    for (i = 0; i < registered_player_count + registered_enemy_count; i++) {
        actor = TObjPlayer::get_player_data(i);
        if (actor == NULL || actor == this || actor->test_actor_flags(0x800) != 0) {
            continue;
        }
        id = actor->get_entity_id();
        if (id == 0xFFFF) {
            continue;
        }
        if (id == get_trap_type() && TOMineTrap::get_trap_count() != 1 &&
            ((TLobby *)lobby_rule_settings)->get_rule_field_0() != 0) {
            continue;
        }
        if (id < 0x1000) {
            if (((TObjPlayer *)actor)->get_floor() != get_current_floor()) {
                continue;
            }
            if (horizontal_distance_squared(&position, &actor->position) < pad_34C * pad_34C) {
                m_35c = id;
                target = actor;
                return 1;
            }
        } else if (id < 0x4000) {
            if (horizontal_distance_squared(&position, &actor->position) < pad_34C * pad_34C) {
                m_35c = id;
                target = actor;
                return 1;
            }
        }
    }
    return 0;
}
void TOMineTrap::set_state() { this->mode = 4; }
void TOMineTrap::vfunc_82() {
    Obj_8016F64C *arg0 = (Obj_8016F64C *)this;
    uaddr r;
    switch (this->attack.kind) {
    default:
        r = (uaddr)spawn_particle_effect((const Vec *)arg0->sub, 0x45);
        if (r != 0U) {
            ((TParticleCtrl *)r)->set_scale(1.25f, 1.25f);
        }
        break;
    case 15:
    case 16:
    case 17:
    case 18:
        spawn_particle_effect((const Vec *)arg0->sub, 0x8E);
        spawn_particle_effect((const Vec *)arg0->sub, 0x8E);
        break;
    case 6:
    case 7:
        spawn_particle_effect((const Vec *)arg0->sub, 0x8D);
        spawn_particle_effect((const Vec *)arg0->sub, 0x8D);
        break;
    }
}

f32 TOMineTrap::receive_physical_attack(void *attacker, f32) {
    switch (mode) {
    case 0:
    case 1:
    case 2:
        if ((attacker != NULL) && (reinterpret_cast<TObject *>(attacker)->check_value_equals(TOMineTrap__data_805D3080) != 0)) {
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


void TOMineTrap::send_state_packet(u16 idx) {
    TOMineTrap *self = this;
    if (idx < 3) {
        G_TriggerTrap_6x80 packet;
        packet.init();
        packet.header.client_id = self->entity_id;
        packet.trap_number = self->m_37e;
        packet.what = idx;
        packet.send();
    }
}
void handle_6x80_trigger_trap(game_command_header *command) {
    G_TriggerTrap_6x80 *packet = (G_TriggerTrap_6x80 *)command;
    TOMineTrap *p;
    s32 i;
    if (packet == NULL) {
        return;
    }
    packet->bswap();
    for (i = registered_player_count + registered_enemy_count; i < lbl_805D5868; i++) {
        p = (TOMineTrap *)TObjPlayer::get_player_data(i);
        if (p == NULL) {
            continue;
        }
        if (reinterpret_cast<TObject *>(p)->check_value_equals(TOMineTrap__data_805D3080) == 0) {
            continue;
        }
        if (packet->trap_number != TOMineTrap__sub_80171358(p)) {
            continue;
        }
        switch (packet->what) {
        case 0:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
                p->vfunc_86();
                break;
            }
            break;
        case 1:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
            case 2:
                p->set_triggered();
                break;
            }
            break;
        case 2:
            switch (TOMineTrap__sub_80171340(p)) {
            case 0:
            case 1:
            case 2:
            case 3:
                p->set_state();
                break;
            }
            break;
        }
        return;
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
                text_builder_append((u8 *)("\x09""C4"));
                text_builder_append((u8 *)name);
                text_builder_append((u8 *)(" TRAP\n"));
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
    TObjPlayer *player;
    switch (this->m_a4) {
    case 0:
        player = get_player_by_client_id(this->m_a8);
        if (player != NULL && TObjPlayer::is_locally_controlled(player) != 0 && fn_80171314(player) != 0) {
            if (horizontal_distance_squared(&position, &player->position) <= 40000.0f ||
                player->get_room() == this->get_room()) {
                this->m_a4 = 2;
            }
        }
        break;
    case 3:
        break;
    case 2:
        get_player_state__6TOMineFv(mine, this->m_a8);
        VecCopy(&this->position, (const Vec *)(((TOMineTrap *)mine)->get_mine_data_ptr()));
        break;
    }
}

void TOMineDisp::render() {
    saddr temp_r31;
    s32 temp_r4;
    u16 id = TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_mode());
    if (id != this->m_a8) {
        return;
    }
    if (*(s32 *)&this->m_a4 != 2) {
        return;
    }
    if (this->update_object_view_visibility(400.0f, 20.0f) == 0) {
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
    TObjPlayer *pl;

    d = m_up;
    switch (m_a4) {
    case 0:
        hit = 0;
        if (TOMineTrap__sub_80171350() == 1) {
            for (i = 0; i < 4; i++) {
                pl = get_player_by_client_id(i);
                if (pl != 0 && TObjPlayer::is_locally_controlled(pl) != 0) {
                    if (fn_80171314(pl) != 0 ||
                        (TTecCtrl::is_technique_ready() != 0 && m_ac == (u16)pl->get_entity_id())) {
                        if (!(horizontal_distance_squared(&position, &pl->position) <= 40000.0f)) {
                            if ((s16)pl->get_room() != (s16)this->get_room()) {
                                continue;
                            }
                        }
                        if (m_a8 == (u16)pl->get_entity_id()) {
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

s32 TOMineTrap::matches_id(u16 id) {
    if ((id == *(u16 *)&this->body_count) && ((s32) *(s32 *)&this->bodies != 2)) {
        return 1;
    }
    return 0;
}

