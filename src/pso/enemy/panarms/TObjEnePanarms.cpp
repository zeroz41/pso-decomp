#include "types.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnePanBARA.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "dolphin/mtx.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecJelin.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecZarua.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/object/ambient/TObjFish_800E2FFC.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/TObjEnePanBARA.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"

typedef char PanarmsActionTimerOffset[offsetof(TObjEnePanBARA, action_timer) == 0x3B4 ? 1 : -1];

struct Stack_800E0D1C {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

extern "C" {
int set_field_b8__10TObjMotionFs(void*, int);
s32 TObjEnePanarms__sub_800DFB44(s32);
void TObjEnePanarms__sub_800E1C98(void *, s32);
u8 check_can_attack__14TObjEnePanarmsFPv(void *arg0);
s32 angle_diff_s16(s32, s32);
s32 vec3_add_to(void *, void *);
s32 subtract_vector(void *, void *);
s32 TObjEnePanarms__sub_800E1774(void *);
extern f32 lbl_8043CD98[];
struct Stack_800DFC18
{
  s32 sp8;
  s32 spC;
  s32 sp10;
  s32 sp14;
  s32 sp18;
  s32 sp1C;
  s32 sp20;
  s32 sp24;
};

struct RecoveredGlobal_800DFC18_lbl_8043CDA8
{
  s32 value;
  u8 remaining[0xC];
};

struct RecoveredGlobal_800DFC18_lbl_8043CDB8
{
  s32 value;
  u8 remaining[0xC];
};

typedef struct RecoveredGlobal_800DFC18_lbl_8043CDA8 RecoveredGlobal_800DFC18_lbl_8043CDA8;

typedef struct RecoveredGlobal_800DFC18_lbl_8043CDB8 RecoveredGlobal_800DFC18_lbl_8043CDB8;

typedef struct Stack_800DFC18 Stack_800DFC18;

typedef char RecoveredGlobal_800DFC18_lbl_8043CDA8_size[((sizeof(RecoveredGlobal_800DFC18_lbl_8043CDA8)) == 0x10) ? (1) : (-1)];

typedef char RecoveredGlobal_800DFC18_lbl_8043CDB8_size[((sizeof(RecoveredGlobal_800DFC18_lbl_8043CDB8)) == 0x10) ? (1) : (-1)];

struct Stack_800E0950 {
    s32 sp8;
    f32 spC;
};




typedef struct { f32 x, y, z; } Vec_800E0A44;

struct Vec_800E0048 { f32 x, y, z; };

struct Vec_800E0ED0 { f32 x, y, z; };

struct Base_800E1D38_800E158C { char pad[0x18]; };

struct VObj_800E1D38_800E158C : Base_800E1D38_800E158C {
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
};

typedef struct { f32 x, y, z; } Vec_800E1A44;

struct Hit_800E1608 { s32 a; f32 b; };

struct VBase_18_b27ba1 { char pad[0x18]; };

struct VObj_18_b27ba1 : VBase_18_b27ba1 {
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
    virtual s32 m21(void *, Hit_800E1608 *, s32, s32, s32);
};

struct Prm_800E1608 { u8 pad[0x1c]; s32 x1c; s32 x20; };

typedef struct { f32 x, y, z; } Vec_800E18B0;

struct Obj_800E1E74 { u8 pad[0x30]; u32 flags; u8 pad2[0x378 - 0x34]; s32 state; };

struct VBase_14_aa9368 { char pad[0x14]; };

struct VObj_14_aa9368 : VBase_14_aa9368 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    s32 f18;
};

struct Obj_800E20D0 { u8 pad[0x3EC]; VObj_14_aa9368 fades[2]; };

struct Vec_800E2200 { f32 x, y, z; };

struct Tgt_800E2200 { u8 pad[0x38]; f32 x; f32 y; f32 z; };

struct Panarms_800E2200 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0xC0 - 0x44];
    f32 fC0;
    u8 padc4[0x2FC - 0xC4];
    Vec_800E2200 pos;
    u8 pad308[0x374 - 0x308];
    s32 prev_state;
    s32 state;
    u8 *f37C;
    u8 pad380[4];
    s32 f384;
    s32 f388;
    Vec_800E2200 f38C;
    u8 pad398[0x3A0 - 0x398];
    Tgt_800E2200 *target;
    u8 pad3a4[0x3C8 - 0x3A4];
    Vec_800E2200 diff;
    s32 angle;
    f32 dist;
    u8 pad3dc[0x45C - 0x3DC];
    s32 counter;
    void dummy();
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


struct O_800E2FB4 { u8 pad[0x378]; s32 state; };

struct Vec_800E06DC { f32 x, y, z; };

s32 find_nearest_hittable_enemy__10TObjPlayerFiPvf(void *, void *, f32);
u16 find_nearest_visible_player(void *, Vec_800E0A44 *, f32);
s32 is_split_screen();
f64 atan2_float(f32, f32, f32);
u8 * dispatch_shared_handler_a__6TLobbyFl(s32);
u32 csnLookAt(void *, void *);
s32 spawn_particle_effect(void *, int, f32);
s32 update__15RenderFadeStateFv(int, int);
s32 try_move_with_detour__14TObjEnePanarmsFPvPv(u8 *arg0, Vec_800E18B0 *arg1);
void calc_default_part_position__14TObjEnePanarmsFPv(u8 *arg0);
void calc_part_position__14TObjEnePanBARAFPUcPl(u8 *arg0, u8 *arg1, s32 *arg2);
s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
void TObjEnePanarms__sub_800E1D38(void *arg0);
int TObjEnePanarms__sub_800E1D94(void* p);
void TObjEnePanarms__sub_800E1E14(u8 *arg0);
u8 is_phase_12__14TObjEnePanarmsFPv(void *arg0);
u8 TObjEnePanarms__sub_800E2E54(void *arg0);
u8 TObjEnePanarms__sub_800E2E68(void *arg0);
u8 is_below_half_hp__14TObjEnePanarmsFPv(void *arg0);
s32 TObjEnePanarms__sub_800E2FB4(O_800E2FB4 *self);
void clear_render_callback__8TObjFishFv(void);
void refresh_lobby_state__10TObjPlayerFv();
f32 horizontal_distance_squared(void *, void *);
s32 angle_difference_abs(s32, s32);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 approach_angle_limited(s32, s32, s32);
void submit_cursor_candidate(void *, s32);
u8 * get_player_by_client_id(s32);
void minimap_render_dot(void *, s32, s32, s32);
s32 scale_matrix(int, f32, f32, f32);
f32 vector_length(void *);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, void *);
s32 normalize_vector(void *);
s32 push_matrix();
s32 post_translate_matrix(void *, f32);

extern BmlResource *TObjEnePanarms__entry_params_resource;
extern Vec_800E1A44 panarms_part_offset_table[];
extern s32 lbl_8043CD58[];
extern Vec_800E1A44 panarms_parent_offset_table[];
extern s32 lbl_8043CD78[];
extern Hit_800E1608 lbl_8043CD88[];
extern Hit_800E1608 lbl_8043CD90[];
extern s32 lbl_8043CDA0[];
extern RecoveredGlobal_800DFC18_lbl_8043CDA8 panarms_npc_binding_desc_a;
extern RecoveredGlobal_800DFC18_lbl_8043CDB8 panarms_npc_binding_desc_b;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

extern const char *lbl_805D2AB8;
extern const s32 lbl_8043CD38[2];

/* A half's one collision sphere (init_collision_body_parts in the constructor). */
CollisionBody lbl_80495458[1] = {
    { { 0.0f, 16.5f, 0.0f }, 7.5f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

/* The two halves' motions, picked by the half's index through lbl_80495914. */
PanarmsMotionParam lbl_80495484[10] = {
    { 0x10000, 0x18, 0.8f, 0 }, { 0x10000, 0x1b, 0.7f, 0 }, { 0x10000, 0x15, 1.0f, 0 }, { 0x30000, 0, 0.8f, 0 },
    { 0x30000, 0x14, 0.8f, 0 }, { 0x30000, 0xa, 1.3f, 0 },  { 0x30000, 0xd, 0.7f, 0 },  { 0x30000, 0x10, 0.7f, 0 },
    { 0x30000, 0x12, 0.7f, 0 }, { 0x30000, 6, 0.6f, 0 },
};

PanarmsMotionParam lbl_80495524[10] = {
    { 0x10000, 0x19, 0.8f, 0 }, { 0x10000, 0x1c, 0.7f, 0 }, { 0x10000, 0x16, 1.0f, 0 }, { 0x30000, 1, 0.8f, 0 },
    { 0, 0, 0.0f, 0 },          { 0x30000, 0xb, 1.3f, 0 },  { 0x30000, 0xe, 0.7f, 0 },  { 0x30000, 0x11, 0.7f, 0 },
    { 0x30000, 0x13, 0.7f, 0 }, { 0x30000, 7, 0.6f, 0 },
};

typedef void (TObjEnePanBARA::*PanBARAStateFn)();

struct PanBARAState {
    PanBARAStateFn enter;
    PanBARAStateFn update;
};

void __sinit_TObjEnePanarms_cpp();
__declspec(section ".ctors") static void *const panarms_global_initializer = (void *)__sinit_TObjEnePanarms_cpp;
// Indexed by the half's state: set_state runs enter, run_task runs update.
extern PanBARAState TObjEnePanarms__state_fn_table[17];

void clear_render_callback__8TObjFishFv(void) { set_chunk_model_node_callback(0); }

s32 TObjEnePanarms__sub_800E2FB4(O_800E2FB4 *self) {
    return self->state == 9 || self->state == 11;
}

int TObjEnePanBARA::find_nearest_enemy_with_flag_alt_target(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    u16 temp_r3;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    temp_r3 = find_nearest_hittable_enemy__10TObjPlayerFiPvf((void *)arg0, (void *)arg1, (f32)farg0);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return temp_r3;
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::set_random_action_timer(int minimum, int range) {
    action_timer = (s32)((f32)range * random_ratio() + (f32)minimum);
}
#pragma pop

u8 is_below_half_hp__14TObjEnePanarmsFPv(void *arg0) {
    s32 var_r31;

    var_r31 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x380) == 0) && (TObjEnePanarms__sub_800DFB44(*(s32 *)((s8 *)arg0 + 0x3A0)) == 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x3C0) == 0) && ((s16) *(s16 *)((s8 *)arg0 + 0x32C) <= (s32) ((s32) *(s32 *)((s8 *)arg0 + 0x3BC) / 2))) {
        var_r31 = 1;
    }
    return var_r31;
}

u8 TObjEnePanarms__sub_800E2E68(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x378) == 0xE);
}

u8 TObjEnePanarms__sub_800E2E54(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x378) == 0xD);
}

u8 check_can_attack__14TObjEnePanarmsFPv(void *arg0) {
    int var_r31;

    var_r31 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 0) && (TObjEnePanarms__sub_800DFB44(*(s32 *)((s8 *)arg0 + 0x3A0)) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

u8 is_phase_12__14TObjEnePanarmsFPv(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x378) == 0xC);
}

void TObjMotion::clear_motion_flags(s32 arg1) {
  s32 *new_var;
  int new_var2;
  new_var2 = ~arg1;
  new_var = (s32 *) (((s8 *) this) + 0xB0);
  *new_var = (s32) ((this->motion_flags) & new_var2);
}

void __sinit_TObjEnePanarms_cpp() {
    TObjEnePanarms__state_fn_table[0].enter = &TObjEnePanBARA::reset_state;
    TObjEnePanarms__state_fn_table[0].update = &TObjEnePanBARA::snap_to_parent_position;
    TObjEnePanarms__state_fn_table[1].enter = &TObjEnePanBARA::init_split;
    TObjEnePanarms__state_fn_table[1].update = &TObjEnePanBARA::handle_split_flag;
    TObjEnePanarms__state_fn_table[2].enter = &TObjEnePanBARA::start_action;
    TObjEnePanarms__state_fn_table[2].update = &TObjEnePanBARA::sub_800E10D0;
    TObjEnePanarms__state_fn_table[3].enter = &TObjEnePanBARA::init_state_1;
    TObjEnePanarms__state_fn_table[3].update = &TObjEnePanBARA::update_move_to_target;
    TObjEnePanarms__state_fn_table[4].enter = &TObjEnePanBARA::init_state_16;
    TObjEnePanarms__state_fn_table[4].update = &TObjEnePanBARA::sub_800E0D1C;
    TObjEnePanarms__state_fn_table[5].enter = &TObjEnePanBARA::restore_from_linked_object;
    TObjEnePanarms__state_fn_table[5].update = &TObjEnePanBARA::update_hit_state;
    TObjEnePanarms__state_fn_table[6].enter = &TObjEnePanBARA::sub_800E0B9C;
    TObjEnePanarms__state_fn_table[6].update = &TObjEnePanBARA::apply_effect_if_flagged;
    TObjEnePanarms__state_fn_table[7].enter = &TObjEnePanBARA::sub_800E0A44;
    TObjEnePanarms__state_fn_table[7].update = &TObjEnePanBARA::sub_800E0950;
    TObjEnePanarms__state_fn_table[8].enter = &TObjEnePanBARA::sub_800E0930;
    TObjEnePanarms__state_fn_table[8].update = &TObjEnePanBARA::sub_800E092C;
    TObjEnePanarms__state_fn_table[9].enter = &TObjEnePanBARA::init_state_2;
    TObjEnePanarms__state_fn_table[9].update = &TObjEnePanBARA::update_chase_target;
    TObjEnePanarms__state_fn_table[10].enter = &TObjEnePanBARA::init_action;
    TObjEnePanarms__state_fn_table[10].update = &TObjEnePanBARA::sub_800E055C;
    TObjEnePanarms__state_fn_table[11].enter = &TObjEnePanBARA::init_attack_state2;
    TObjEnePanarms__state_fn_table[11].update = &TObjEnePanBARA::update_attack;
    TObjEnePanarms__state_fn_table[12].enter = &TObjEnePanBARA::sub_800E0344;
    TObjEnePanarms__state_fn_table[12].update = &TObjEnePanBARA::sub_800E0214;
    TObjEnePanarms__state_fn_table[13].enter = &TObjEnePanBARA::start_phase2_timer150;
    TObjEnePanarms__state_fn_table[13].update = &TObjEnePanBARA::sub_800E0048;
    TObjEnePanarms__state_fn_table[14].enter = &TObjEnePanBARA::start_phase3_timer12;
    TObjEnePanarms__state_fn_table[14].update = &TObjEnePanBARA::update_move_timer;
    TObjEnePanarms__state_fn_table[15].enter = &TObjEnePanBARA::init_open_state;
    TObjEnePanarms__state_fn_table[15].update = &TObjEnePanBARA::sub_800DFE08;
    TObjEnePanarms__state_fn_table[16].enter = &TObjEnePanBARA::init_attack_state;
    TObjEnePanarms__state_fn_table[16].update = &TObjEnePanBARA::update_action_timer;
}

PanBARAState TObjEnePanarms__state_fn_table[17] = {};

TObjFishNodeEntry lbl_804958F4[2] = {
    { 3 },
    { -1 },
};

PanarmsMotionParam *lbl_80495914[2] = { lbl_80495484, lbl_80495524 };

s32 panarms_turn_delta_table[2] = { 0x4000, -0x4000 };

s32 TObjEnePanarms::create_bara(void *setData, s32 index) {
    return (s32)new TObjEnePanBARA(new TObjControl(tl_04), setData, index);
}

struct PanBARAParams {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

// The 12-byte record TObjEnemy::exchange_object_state fills (mode 1) or stores (mode 0).
struct PanBARAObjectState {
    u32 unk_0;
    u16 unk_4;
    s16 unk_6;
    u8 unk_8[4];
};

TObjEnePanBARA::TObjEnePanBARA(TObject *parent, void *setData, s32 index) : TObjEnemy(parent) {
    s32 i;

    m_name = lbl_805D2AB8;
    add_flags_2e4(2);
    apply_set_data(setData);
    // Same statements as TObjEnemy::clear_lobby_object_state (0x800F5D80); the original expands them here.
    PanBARAObjectState objectState;
    if (exchange_object_state__9TObjEnemyFls(this, &objectState, 1) != 0) {
        objectState.unk_0 = 0;
        objectState.unk_6 = 0;
        exchange_object_state__9TObjEnemyFls(this, &objectState, 0);
    }
    m_380 = index;
    texlist = TObjFish__sub_8001EDB0(TObjEnePanarms__entry_params_resource, lbl_8043CD38[m_380]);
    model = (void *)get_bml_model(TObjEnePanarms__entry_params_resource, lbl_8043CD38[m_380]);
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    collision_body_parts = init_collision_body_parts(this, lbl_80495458, 1);
    set_field_d8((s32)lbl_80495914[m_380]);
    set_field_dc((s32)TObjEnePanarms__entry_params_resource->motions);
    set_animation(0);
    set_field_b8(0);
    VecCopy((Vec *)&m_2fc, &position);
    x_speed = y_speed = m_310 = 0.0f;
    target = NULL;
    switch (m_380) {
    case 0:
        bind_enemy_combat_stats((u8 *)TLobby::register_boss(50), (u8 *)TLobby::dispatch_shared_handler_b(50),
                                (u8 *)TLobby::register_object(50));
        break;
    case 1:
        bind_enemy_combat_stats((u8 *)TLobby::register_boss(51), (u8 *)TLobby::dispatch_shared_handler_b(51),
                                (u8 *)TLobby::register_object(51));
        break;
    default:
        return;
    }
    referenceHp = hp;
    ((TBoss3Volopt *)this)->reset_photon_effect(); // 0x8003F0E8: generic helper, owned under this name by 24 callers
    movementParameters = NULL;
    if (m_380 == 0) {
        set_param(23);
    } else {
        set_param(22);
    }
    m_3dc = (void *)TObjFish__sub_800E3124((u8 *)lbl_804958F4, (s32)unk_3E0);
    if (m_3dc == NULL) {
        return;
    }
    m_3b0 = 0.0f;
    m_3c4 = 0;
    if (m_380 == 0) {
        pad_460 = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(50))->unk_0;
        m_464 = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(50))->unk_4;
    } else {
        pad_460 = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(51))->unk_0;
        pad_468 = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(51))->unk_4;
        if (pad_468 < 0.0f) {
            pad_468 = 0.0f;
        } else if (pad_468 > 1.0f) {
            pad_468 = 1.0f;
        }
        m_46c = ((PanBARAParams *)TLobby::dispatch_shared_handler_a(51))->unk_8;
        if (m_46c < 0.0f) {
            m_46c = 0.0f;
        } else if (m_46c > 1.0f) {
            m_46c = 1.0f;
        }
        if (pad_468 + m_46c > 1.0f) {
            m_46c = 1.0f - pad_468;
        }
    }
    VecCopy((Vec *)unk_3A4, &position);
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    m_378 = 0;
    state = 0;
    TObjEnePanarms__sub_800E1C98(this, 0);
}

TObjEnePanBARA::~TObjEnePanBARA() {
    free_collision_body_parts(this);
    collision_body_parts = NULL;
    TObjFish::init_state_1(m_3dc);
}

void TObjEnePanBARA::run_task() {
    PanBARAStateFn fn;
    Vec_800E2200 a;
    f32 s;

    if (m_378 != 0 && TObjPlayer::check_demo_mode() != 0) {
        TObjEnePanarms__sub_800E1C98(this, 0);
    }
    pad_3c8.x = ((Tgt_800E2200 *)m_3a0)->x - position.x;
    pad_3c8.y = 0.0f;
    pad_3c8.z = ((Tgt_800E2200 *)m_3a0)->z - position.z;
    m_3d4 = 10430.38043493439 * ((f32 (*)(f32, f32))atan2_float)(pad_3c8.x, pad_3c8.z);
    pad_3d8 = vector_length(&pad_3c8);
    m_45c++;
    fn = TObjEnePanarms__state_fn_table[m_378].update;
    if (fn == 0) {
        return;
    }
    (this->*fn)();
    if (m_384 != 0) {
        ((Panarms_800E2200 *)this)->flags &= ~0x02000000;
    } else {
        ((Panarms_800E2200 *)this)->flags |= 0x02000000;
    }
    update_prev_position();
    if (m_378 == 0) {
        return;
    }
    if (m_384 != 0) {
        if (m_378 != 7) {
            submit_cursor_candidate(this, -1);
        }
        advance_animation();
        switch (m_378) {
        case 7:
            break;
        case 1:
            s = ((Panarms_800E2200 *)this)->fC0 / 35.0f;
            ((void (*)(void *, void *, s32, f32))calc_part_position__14TObjEnePanBARAFPUcPl)(this, &a, 0, ((Panarms_800E2200 *)this)->fC0);
            ((void (*)(void *, void *))subtract_vector)(&a, &m_2fc);
            a.x *= s;
            a.z *= s;
            ((void (*)(void *, void *))vec3_add_to)(&a, &m_2fc);
            minimap_render_dot(&a, -0x5DB4, 1, 0);
            break;
        case 5:
            {
            s = ((Panarms_800E2200 *)this)->fC0 / 45.0f;
            Vec_800E2200 b = *(Vec_800E2200 *)&m_2fc;
            ((void (*)(void *, void *))subtract_vector)(&b, &m_38c);
            b.x *= s;
            b.z *= s;
            ((void (*)(void *, void *))vec3_add_to)(&b, &m_38c);
            minimap_render_dot(&b, -0x5DB4, 1, 0);
            }
            break;
        default:
            minimap_render_dot(&m_2fc, -0x5DB4, 1, 0);
            break;
        }
    }
    if (m_388 == 0) {
        *(u32 *)(((Panarms_800E2200 *)this)->f37C + 0x18) &= ~1;
    }
}

void TObjEnePanBARA::render() {
    s32 temp_r4;
    s32 var_r31;
    VObj_14_aa9368 *temp_r31;
    s32 var_r30;
    if ((((VObj_18_26a62c *)(this))->m8(500.0f, 20.0f) == 0) || ((s32) *(s32 *)&this->m_384 == 0)) {
        *(f32 *)&this->unk_3AC = 0.0f;
        this->m_3a8 = 0.0f;
        *(f32 *)&this->unk_3A4 = 0.0f;
        return;
    }
    var_r31 = 0;
    if (is_split_screen() != 0) {
        var_r31 = TCameraCtrl::get_camera_mode();
    }
    TObjPlayer::toggle_particle_effect();
    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x01000000 | 1;
    temp_r31 = &((Obj_800E20D0 *) ((u8 *)this))->fades[var_r31];
    update__15RenderFadeStateFv((int)temp_r31, (int)temp_r4);
    if (((RenderFadeState *)temp_r31)->updateFromCamera((const f32*)(((u8 *)this) + 0x2FC)) != 0) {
        temp_r31->m6();
        var_r30 = 1;
        if (defer_render() != 0) {
            var_r30 = 0;
        }
        if (var_r30 != 0) {
            this->draw();
        }
        temp_r31->m7();
    } else {
        this->draw();
    }
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    this->update_linked_effect();
}

void TObjEnePanBARA::draw() { ((int (*)(void*))push_matrix)(this); ((int (*)(void*))post_translate_matrix)((char*)this + 0x38); ((int (*)(void*, void*))rotate_matrix_y)((void*)0, *(void* *)&this->rotation_y); TObjFish::set_global_param((s32)(*(void* *)&this->texlist)); ((TObjFish *)(this->m_3dc))->set_draw_callback_list(); TObjMotion::draw(); ((int (*)(void*))clear_render_callback__8TObjFishFv)(this->m_3dc); ((int (*)(void))pop_matrix)(); }

void TObjEnePanBARA::update_linked_effect() {
    u8 *arg0 = (u8 *)this;
    struct { u8 b[0x10]; } sp10;
    s32 spC;
    s32 sp8;
    f32 temp_f1;
    s32 temp_r0;

    VecCopy((Vec *)(arg0 + 0x3A4), (const Vec *)(arg0 + 0x3E0));
    if (((s32 (*)(void *, void *, void *))project_actor_to_ground)(arg0, (u8 *)&this->unk_3A4, &sp10) != 0) {
        push_matrix();
        temp_f1 = this->m_3a8;
        this->m_3a8 += 0.2f;
        post_translate_matrix((u8 *)&this->unk_3A4, temp_f1);
        direction_to_rotation_xz((u8 *)&sp10, (s32 *)((s32 *)&spC), (s32 *)((s32 *)&sp8));
        rotate_matrix_z(0, sp8);
        rotate_matrix_y(0, this->rotation_y);
        rotate_matrix_x(0, (void *)(spC + 0x4000));
        scale_matrix(0, 2.0f, 2.0f, 1.0f);
        temp_r0 = this->m_378;
        if ((temp_r0 != 7) && (temp_r0 != 8)) {
            draw_blob_shadow(0);
        }
        pop_matrix();
    }
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    s32 st = this->m_378;
    switch (st) {
    case 7:
    case 8:
        return;
    default:
        if (st == 0) {
            this->rotation_y = *(s32 *)(this->m_39c + 0x60) + panarms_turn_delta_table[this->m_380];
            VecCopy(&this->position, (const Vec *)(this->m_39c + 0x38));
            *(f32 *)((s8 *)arg0 + 0x38) += 10.0f * sin_table_lookup(this->rotation_y);
            *(f32 *)((s8 *)arg0 + 0x40) += 10.0f * cos_table_lookup(this->rotation_y);
            VecCopy((Vec *)&this->m_2fc, &this->position);
        }
        ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)(arg0, 7);
        break;
    }
}
#pragma pop

void TObjEnePanBARA::vfunc_62() {
    Obj_800E1E74 *self = (Obj_800E1E74 *)this;
    switch (self->state) {
    case 0:
    case 1:
    case 5:
    case 6:
        break;
    default:
        self->flags &= ~0x200;
        ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)(self, 6);
        break;
    }
}

void TObjEnePanBARA::vfunc_61() { this->actorFlags &= 0xfffffeff; }

void TObjEnePanarms__sub_800E1E14(u8 *arg0) {
    u8 *temp_r5;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x39C) + 0x38));
    temp_r5 = *(u8 **)((s8 *)arg0 + 0x39C);
    *(s32 *)((s8 *)arg0 + 0x60) = (s32) *(s32 *)((s8 *)temp_r5 + 0x60);
    ((s32 (*)(void *, int, int))TObjEnePanarms__sub_800E1C98)((void *)arg0, 1, (int)temp_r5);
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::init_state() {
    s32 arg0 = (s32)this;
    update_offset_from_parent();
    ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)((void*)arg0, 3);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TObjEnePanarms::do_action_2(void* p) { return ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)(p, 2); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TObjEnePanarms__sub_800E1D94(void* p) { return ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)(p, 5); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::reset_split() {
    if ((s32) this->m_378 != 0) {
        ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)(this, 0);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanarms__sub_800E1D38(void *arg0) {
    struct VObj_800E1D38_800E158C *o = (struct VObj_800E1D38_800E158C *)arg0;
    o->m61();
}
#pragma pop

void TObjEnePanarms__sub_800E1C98(void *panarms, s32 state) {
    Panarms_800E2200 *self = (Panarms_800E2200 *)panarms;
    PanBARAStateFn enter;
    s32 *current = &self->state;
    if (self->prev_state != self->state) {
        self->prev_state = *current;
    }
    self->state = state;
    if (self->state < 0 || self->state >= 17) {
        return;
    }
    enter = TObjEnePanarms__state_fn_table[self->state].enter;
    if (enter) {
        (((TObjEnePanBARA *)panarms)->*enter)();
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanarms__sub_800E1C8C(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x39C) = arg1;
    *(s32 *)((s8 *)arg0 + 0x3A0) = arg2;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on
void TObjEnePanBARA::calc_part_position(u8 *arg1, s32 *arg2) {
    f32 x;
    f32 z;
    f32 s;
    f32 c;

    x = panarms_part_offset_table[this->m_380].x;
    z = panarms_part_offset_table[this->m_380].z;
    s = sin_table_lookup(*(s32 *)(this->m_39c + 0x60));
    c = cos_table_lookup(*(s32 *)(this->m_39c + 0x60));
    VecCopy((Vec *)arg1, (const Vec *)(this->m_39c + 0x38));
    *(f32 *)((s8 *)arg1 + 0) += x * c + z * s;
    *(f32 *)((s8 *)arg1 + 8) += -x * s + z * c;
    if (arg2 != NULL) {
        *arg2 = *(s32 *)(this->m_39c + 0x60) - lbl_8043CD58[this->m_380];
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void calc_default_part_position__14TObjEnePanarmsFPv(u8 *ene_pan_bara) {
    ((TObjEnePanBARA *)ene_pan_bara)->calc_part_position(ene_pan_bara + 0x38, (s32 *)(ene_pan_bara + 0x60));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on
void TObjEnePanBARA::update_offset_from_parent() {
    f32 x;
    f32 z;
    f32 s;
    f32 c;
    x = panarms_parent_offset_table[this->m_380].x;
    z = panarms_parent_offset_table[this->m_380].z;
    s = sin_table_lookup(*(s32 *)((s8 *)(*(u8 * *)&this->m_39c) + 0x60));
    c = cos_table_lookup(*(s32 *)((s8 *)(*(u8 * *)&this->m_39c) + 0x60));
    VecCopy((Vec *)&this->m_38c, (const Vec *)(*(u8 * *)&this->m_39c + 0x38));
    this->m_38c.x += x * c + z * s;
    this->m_38c.z += -x * s + z * c;
    this->m_398 = *(s32 *)((s8 *)(*(u8 * *)&this->m_39c) + 0x60);
    this->m_398 += lbl_8043CD78[this->m_380];
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on
s32 try_move_with_detour__14TObjEnePanarmsFPvPv(u8 *arg0, Vec_800E18B0 *arg1) {
    Vec_800E18B0 dir = *arg1;
    Vec_800E18B0 t;
    Vec_800E18B0 p;
    s32 i;
    s32 ang;
    f32 s;
    f32 c;
    f32 nx;
    dir.y = 0.0f;
    if (0.0f == vector_length(&dir)) {
        return 0;
    }
    VecCopy((Vec *)&t, (const Vec *)(arg0 + 0x38));
    vec3_add_to(&t, arg1);
    if (horizontal_distance_squared(&t, arg0 + 0x50) > 250000.0f) {
        return 0;
    }
    for (i = 1; i < 16; i++) {
        VecCopy((Vec *)&p, (const Vec *)(arg0 + 0x38));
        vec3_add_to(&p, &dir);
        p.y += 10.0f;
        if (project_actor_to_ground((TObjChara *)arg0, (Vec *)&p, 0) != 0 && csnLookAt(arg0 + 0x38, &p) == 0) {
            VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
            VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&p);
            ((TObjPlayer *)arg0)->update_collisions();
            return 1;
        }
        ang = i << 12;
        if (i & 1) {
            ang *= -1;
        }
        s = sin_table_lookup(ang);
        c = cos_table_lookup(ang);
        nx = c * dir.x - s * dir.z;
        dir.x = nx;
        dir.z = s * nx + c * dir.z;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern f32 lbl_8043CD80[];

s32 TObjEnePanarms__sub_800E1774(void * self_) {
    f32 vec[3];
    s32 pos;
    s32 ret;

    if ((s32)((TObjEnePanarms *)self_)->get_state_flag() != 0) {
        ret = TObjEnePanarms__sub_800E2FB4(*(O_800E2FB4 **)(((u8*)self_) + 0x3a0)) == 0
            && (*(s32*)(((u8*)self_) + 0x3b8) = pos = ((TObjEnePanBARA *)self_)->find_nearest_enemy_with_flag_alt_target((s32)vec, lbl_8043CD80[*(s32 *)((u8 *)self_ + 0x380)])) != 0xffff
            && angle_difference_abs(*(s32*)(((u8*)self_) + 0x60), (s32)(10430.38043493439 * ((f64 (*)(f32, f32))atan2_float)(vec[0], vec[2]))) < 0x400;
        return (u8)ret;
    } else {
        ret = TObjEnePanarms__sub_800E2FB4(*(O_800E2FB4 **)(((u8*)self_) + 0x3a0)) == 0
            && (*(s32*)(((u8*)self_) + 0x3b8) = pos = (u16)find_nearest_visible_player(self_, (Vec_800E0A44 *)vec, lbl_8043CD80[*(s32 *)((u8 *)self_ + 0x380)])) != 0xffff
            && angle_difference_abs(*(s32*)(((u8*)self_) + 0x60), (s32)(10430.38043493439 * ((f64 (*)(f32, f32))atan2_float)(vec[0], vec[2]))) < 0x400;
        return (u8)ret;
    }
}

#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::attack_target_player(s32 arg1) {
    u8 *t;
    f32 sc;
    s32 lv;
    t = get_player_by_client_id(arg1);
    if (t != NULL) {
        if (this->m_380 == 0) {
            Hit_800E1608 tmp = lbl_8043CD88[0];
            tmp.b = this->m_464;
            {
                Hit_800E1608 h = tmp;
                ((VObj_18_b27ba1 *)t)->m21(this, &h, 0, -1, -1);
            }
            return;
        }
        sc = random_ratio();
        if (sc <= *(f32 *)((s8 *)((u8 *)this) + 0x468)) {
            lv = ((Prm_800E1608 * (*)(s32))dispatch_shared_handler_a__6TLobbyFl)(0x33)->x1c;
            if (lv < 0 || lv > 0xE) {
                lv = 0;
            }
            TTecJelin::create((s32)this, (s32)(((u8 *)this) + 0x2FC), (s32)(t + 0x2FC), (s32)lv);
            return;
        }
        if (sc <= *(f32 *)((s8 *)((u8 *)this) + 0x468) + this->m_46c) {
            lv = ((Prm_800E1608 * (*)(s32))dispatch_shared_handler_a__6TLobbyFl)(0x33)->x20;
            if (lv < 0 || lv > 0xE) {
                lv = 0;
            }
            TTecZarua::create_instance((s32)this, (s32)(((u8 *)this) + 0x2FC), (s32)(t + 0x2FC), (s32)lv);
            return;
        }
        {
            Hit_800E1608 h2 = lbl_8043CD90[0];
            ((VObj_18_b27ba1 *)t)->m21(this, &h2, 0, -1, -1);
        }
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::spawn_periodic_particle() {
    u8 *arg0 = (u8 *)this;
    Vec position;
    if (!(this->m_45c & 7)) {
        VecCopy((Vec *)(&position.x), (const Vec *)(arg0 + 0x3A4));
        position.y += 5.0f;
        ((s32 (*)(void *, int))spawn_particle_effect)(&position.x, 0xF3);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanBARA::reset_state() { *(int*)((char*)*(int *)&this->collision_body_parts + 0x18) = (*(int*)((char*)*(int *)&this->collision_body_parts + 0x18) & 0xfffffffe); *(float *)&this->m_3b0 = 0.0f; *(int *)&this->m_384 = 0; *(int *)&this->m_388 = 0; }
#pragma pop

void TObjEnePanBARA::snap_to_parent_position() {
    VecCopy(&position, (const Vec *)(m_39c + 0x38));
    position.x += 1000.0f;
    position.y += 1000.0f;
    VecCopy((Vec *)&m_2fc, &position);
}

void TObjEnePanBARA::init_split() {
    void *temp_r7;

    temp_r7 = *(void * *)&this->collision_body_parts;
    *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) & 0xFFFFFFFE);
    *(s32 *)&this->m_384 = 1;
    this->m_388 = 0;
    this->hp = (s16) (((*(s16 *)((s8 *)(*(void * *)&this->m_39c) + 0x32C)) + 1) / 2);
    this->m_3bc = (s32) this->hp;
    *(s32 *)&this->unk_3C0 = 0;
    clear_motion_flags(0x10);
    *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags | 1);
    set_field_b8(9);
}

void TObjEnePanBARA::handle_split_flag() {
    if (this->motion_flags & 0x10) {
        ((s32 (*)(void))calc_default_part_position__14TObjEnePanarmsFPv)();
        TObjEnePanarms__sub_800E1C98(this, 2);
    }
}

void TObjEnePanBARA::start_action() {
    void *temp_r4;

    this->set_random_action_timer(0xF, 0x3C);
    temp_r4 = *(void * *)&this->collision_body_parts;
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) | 1);
    this->m_388 = 1;
    if (this->state == 1) {
        *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags | 1);
    } else {
        *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags & 0xFFFFFFFE);
    }
    set_field_b8(0);
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::sub_800E10D0() {
    Vec_800E0A44 v;
    Vec_800E0A44 a;
    f32 scale;
    s32 idx;
    f32 max;
    s32 angle;
    s32 ok;
    s32 t;
    u8 *p;
    u8 *e;

    t = *(s32 *)((s8 *)this + 0x3B4) - 1;
    *(s32 *)((s8 *)this + 0x3B4) = t;
    if (t > 0) {
        return;
    }
    if (*(s32 *)((s8 *)this + 0x3B4) == 0) {
        this->motion_flags &= ~1;
        ((TObjMotion *)this)->set_field_b8(1);
    }
    if (*(s32 *)((s8 *)this + 0x380) == 1 && ((s32 (*)(s32))is_phase_12__14TObjEnePanarmsFPv)(*(s32 *)((s8 *)this + 0x3A0)) != 0) {
        if (*(f32 *)((s8 *)this + 0x3D8) < 27.5f) {
            TObjEnePanarms__sub_800E1C98((u8 *)this, 0xA);
            return;
        }
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0xD);
        return;
    }
    idx = find_nearest_visible_player((u8 *)this, &v, 500.0f);
    ok = 0;
    if (idx != 0xFFFF) {
        angle = (s32)(10430.38043493439 * ((f64 (*)(f32, f32))atan2_float)(v.x, v.z));
        if (angle_difference_abs(this->rotation_y, angle) < 0x208) {
            ok = 1;
        }
    }
    if (ok != 0) {
        this->rotation_y = approach_angle_limited(this->rotation_y, angle, 0x208);
        scale = 75.0f;
        p = get_player_by_client_id(idx);
        if (p != NULL) {
            if (*(s32 *)((s8 *)this + 0x380) == 1) {
                scale *= -1.0f;
            }
            VecCopy((Vec *)&a, (const Vec *)(p + 0x38));
            a.x += scale * cos_table_lookup(this->rotation_y);
            a.z -= scale * sin_table_lookup(this->rotation_y);
            subtract_vector(&a, (u8 *)this + 0x38);
            a.y = 0.0f;
            if (vector_length(&a) <= 0.01f) {
                a.x = a.z = 0.0f;
            } else {
                normalize_vector(&a);
            }
        }
    } else {
        if (*(s32 *)((s8 *)this + 0x380) == 0) {
            this->rotation_y -= 0x208;
        } else {
            this->rotation_y += 0x208;
        }
        a.x = sin_table_lookup(this->rotation_y);
        a.z = cos_table_lookup(this->rotation_y);
        a.y = 0.0f;
    }
    max = lbl_8043CD98[*(s32 *)((s8 *)this + 0x380)];
    if ((this->m_3b0 += 0.025f) > max) {
        *(f32 *)((s8 *)this + 0x3B0) = max;
    }
    a.x *= *(f32 *)((s8 *)this + 0x3B0);
    a.z *= *(f32 *)((s8 *)this + 0x3B0);
    ((s32 (*)(void *, void *))try_move_with_detour__14TObjEnePanarmsFPvPv)((u8 *)this, &a);
    if (((s32 (*)(void *))is_below_half_hp__14TObjEnePanarmsFPv)((u8 *)this) != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0xC);
        return;
    }
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)((u8 *)this) != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0x10);
        return;
    }
    if (TObjEnePanarms__sub_800E1774((u8 *)this) != 0) {
        e = (u8 *)find_entity_by_id(*(s32 *)((s8 *)this + 0x3B8));
        if (e != NULL && horizontal_distance_squared(e + 0x38, (u8 *)this + 0x38) < 756.25f) {
            TObjEnePanarms__sub_800E1C98((u8 *)this, 0xA);
            return;
        }
        TObjEnePanarms__sub_800E1C98((u8 *)this, 9);
    }
}
#pragma pop

void TObjEnePanBARA::init_state_1() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r5;
    temp_r5 = (u8 *)(*(u8 * *)&this->collision_body_parts);
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags & 0xFFFFFFFE);
    ((TObjMotion *)arg0)->set_field_b8(1);
}

void TObjEnePanBARA::update_move_to_target() {
    u8 *arg0 = (u8 *)this;
    Vec_800E0ED0 sp8;
    f32 dist;
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)(arg0) != 0) {
        TObjEnePanarms__sub_800E1C98(arg0, 0x10);
        return;
    }
    if (TObjEnePanarms__sub_800DFB44(*(s32 *)&this->m_3a0) != 0) {
        TObjEnePanarms__sub_800E1C98(arg0, 2);
        return;
    }
    VecCopy((Vec *)&sp8, (const Vec *)&this->m_38c);
    subtract_vector(&sp8, (u8 *)&this->position);
    sp8.y = 0.0f;
    dist = vector_length(&sp8);
    if (dist <= 0.01f) {
        sp8.x = 1.0f;
        sp8.z = 0.0f;
    } else {
        normalize_vector(&sp8);
    }
    if (*(s32 *)((s8 *)(*(u8 * *)&this->collision_body_parts) + 0x18) & 0x01C00000) {
        f32 t = sp8.x;
        sp8.x = sp8.z;
        sp8.z = -t;
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (10430.38043493439 * ((f64 (*)(f32, f32))atan2_float)(sp8.x, sp8.z)), 0x208);
    if (dist > 15.0f) {
        if ((this->m_3b0 += 0.025f) > 0.6f) {
            this->m_3b0 = 0.6f;
        }
    } else {
        if ((this->m_3b0 -= 0.025f) < 0.3f) {
            this->m_3b0 = 0.3f;
        }
    }
    sp8.x *= this->m_3b0;
    sp8.z *= this->m_3b0;
    ((s32 (*)(void *, void *))try_move_with_detour__14TObjEnePanarmsFPvPv)(arg0, &sp8);
    if (horizontal_distance_squared((u8 *)&this->m_38c, (u8 *)&this->position) < 56.25f) {
        TObjEnePanarms__sub_800E1C98(arg0, 4);
    }
}

void TObjEnePanBARA::init_state_16() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    temp_r6 = (u8 *)(*(u8 * *)&this->collision_body_parts);
    *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) | 1);
    this->action_timer = 0x16;
    *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags & 0xFFFFFFFE);
    ((TObjMotion *)arg0)->set_field_b8(1);
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::sub_800E0D1C() {
    typedef char sp8_offset[(offsetof(Stack_800E0D1C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800E0D1C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800E0D1C, sp10) == 0x8) ? 1 : -1];
    Stack_800E0D1C stack;
    f32 temp_f31;
    s32 temp_r0;
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)((u8 *)this) != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0x10);
        return;
    }
    if (TObjEnePanarms__sub_800DFB44((int) (*(s32 *)((s8 *)this + 0x3A0))) != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 2);
        return;
    }
    temp_r0 = *(s32 *)((s8 *)this + 0x3B4) - 5;
    if (temp_r0 > 0) {
        temp_f31 = 1.0f / (f32) temp_r0;
        VecCopy((Vec *)(&stack.sp8), &m_38c);
        subtract_vector(&stack.sp8, &position);
        stack.sp8 *= temp_f31;
        stack.spC *= temp_f31;
        stack.sp10 *= temp_f31;
        vec3_add_to(&position, &stack.sp8);
        this->rotation_y = (s32) ((temp_f31 * (f32) angle_diff_s16((int) (this->rotation_y), (int) (*(s32 *)((s8 *)this + 0x398)))) + (f32) this->rotation_y);
    } else if (temp_r0 == 0) {
        ((TObjMotion *)this)->set_field_b8(0);
    }
    *(s32 *)((s8 *)this + 0x3B4) = (s32) (*(s32 *)((s8 *)this + 0x3B4) - 1);
}
#pragma pop

void TObjEnePanBARA::restore_from_linked_object() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;
    temp_r4 = (u8 *)(*(u8 * *)&this->collision_body_parts);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(*(u8 * *)&this->m_39c + 0x38));
    this->rotation_y = (s32) *(s32 *)((s8 *)((u8 *)(*(u8 * *)&this->m_39c)) + 0x60);
    *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags | 1);
    ((TObjMotion *)arg0)->set_field_b8(8);
}

void TObjEnePanBARA::update_hit_state() {
    if (TObjEnePanarms__sub_800DFB44(*(s32 *)&this->m_3a0) != 0) {
        TObjEnePanarms__sub_800E1C98(this, 2);
        return;
    }
    if (this->motion_flags & 0x10) {
        TObjEnePanarms__sub_800E1C98(this, 0);
    }
}

void TObjEnePanBARA::sub_800E0B9C() {
    m_384 = 1;
    m_388 = 1;
    static s32 panarms_sound_effect_pair[2] = { remap_sound_for_area(0x4003BC34), remap_sound_for_area(0x4003BC33) };
    play_sound_effect(panarms_sound_effect_pair[m_380], &position, 0, 0);
    motion_flags &= ~1;
    set_field_b8(5);
}

void TObjEnePanBARA::apply_effect_if_flagged() {
    if (*(s32 *)&this->motion_flags & 0x10) {
        TObjEnePanarms__sub_800E1C98(this, this->state);
    }
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::sub_800E0A44() {
    Vec_800E0A44 v;
    s16 var_r30;
    *(s32 *)((s8 *)this + 0x384) = 1;
    this->m_388 = 0;
    refresh_lobby_state__10TObjPlayerFv();
    var_r30 = 7;
    this->motion_flags &= ~1;
    if (find_nearest_visible_player((u8 *)this, &v, 500.0f) != 0xFFFF) {
        if (v.x * sin_table_lookup(this->rotation_y) + v.z * cos_table_lookup(this->rotation_y) < 0.0f) {
            var_r30 = 6;
        }
    }
    set_field_b8__10TObjMotionFs((u8 *)this, var_r30);
    static s32 TObjEnePanarms__sound_ids[2] = { remap_sound_for_area(0x4003B836), remap_sound_for_area(0x4003BB35) };
    play_sound_effect(TObjEnePanarms__sound_ids[this->m_380], &position, 0, 0);
    this->action_timer = 0xA4;
}
#pragma pop

void TObjEnePanBARA::sub_800E0950() {
    Stack_800E0950 stack;
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_r0;
    *(s32 *)((s8 *)this + 0x3B4) = (s32) (*(s32 *)((s8 *)this + 0x3B4) - 1);
    static f32 panarms_particle_frame_window = lbl_80495484[6].unk_8;
    temp_f2 = *(f32 *)((s8 *)this + 0xC0);
    if ((temp_f2 >= 24.0f) && (temp_f2 < (24.0f + panarms_particle_frame_window))) {
        VecCopy((Vec *)(&stack.sp8), (const Vec *)unk_3A4);
        temp_f1 = stack.spC;
        stack.spC += 5.0f;
        spawn_particle_effect((void *)&stack.sp8, 0xF3, temp_f1);
    }
    temp_r0 = *(s32 *)((s8 *)this + 0x3B4);
    if (temp_r0 <= 0x78) {
        if (temp_r0 == 0x78) {
            ((TObjPlayer *)unk_3A4)->spawn_ground_effect(0x78);
            TObjPlayer::spawn_dead_spot_default((s32)unk_3A4, 6);
        }
        this->position.y += -0.15625f;
        if ((s32) *(s32 *)((s8 *)this + 0x3B4) < 0) {
            TObjEnePanarms__sub_800E1C98((void *)this, 8);
        }
    }
}

void TObjEnePanBARA::sub_800E0930() {
    u8 *temp_r5;
    temp_r5 = *(u8 **)((s8 *)this + 0x37C);
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFFFFFFE);
    *(s32 *)((s8 *)this + 0x384) = 0;
    *(s32 *)((s8 *)this + 0x388) = 0;
}

void TObjEnePanBARA::sub_800E092C() {  }

void TObjEnePanBARA::init_state_2() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r7;
    temp_r7 = (u8 *)(*(u8 * *)&this->collision_body_parts);
    *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
    *(s32 *)&this->m_384 = 1;
    this->m_388 = 1;
    this->action_timer = 0x5A;
    *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags & 0xFFFFFFFE);
    ((TObjMotion *)arg0)->set_field_b8(2);
}

void TObjEnePanBARA::update_chase_target() {
    u8 *arg0 = (u8 *)this;
    Vec_800E06DC sp8;
    u8 *p;

    p = (u8 *)find_entity_by_id((u16) *(s32 *)&this->unk_3B8);
    if (p == NULL || (*(s32 *)((s8 *)p + 0x30) & 0x02000800)) {
        TObjEnePanarms__sub_800E1C98(arg0, 2);
        return;
    }
    (this->action_timer)--;
    VecCopy((Vec *)&sp8, (const Vec *)(p + 0x38));
    subtract_vector(&sp8, (u8 *)&this->position);
    sp8.y = 0.0f;
    if (vector_length(&sp8) <= 0.01f) {
        sp8.x = 1.0f;
        sp8.z = 0.0f;
    } else {
        normalize_vector(&sp8);
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (10430.38043493439 * ((f64 (*)(f32, f32))atan2_float)(sp8.x, sp8.z)), 0x101);
    if (this->action_timer > 0) {
        if ((this->m_3b0 += 0.075f) > 1.25f) {
            this->m_3b0 = 1.25f;
        }
    } else {
        if ((this->m_3b0 -= 0.075f) < 0.0f) {
            this->m_3b0 = 0.0f;
        }
    }
    sp8.x *= this->m_3b0;
    sp8.z *= this->m_3b0;
    ((s32 (*)(void *, void *))try_move_with_detour__14TObjEnePanarmsFPvPv)(arg0, &sp8);
    if (0.0f == this->m_3b0) {
        TObjEnePanarms__sub_800E1C98(arg0, 0xA);
        return;
    }
    if (horizontal_distance_squared(p + 0x38, (u8 *)&this->position) < 625.0f) {
        TObjEnePanarms__sub_800E1C98(arg0, 0xB);
        return;
    }
    if (((s32 (*)(void *))is_below_half_hp__14TObjEnePanarmsFPv)(arg0) != 0) {
        TObjEnePanarms__sub_800E1C98(arg0, 0xC);
        return;
    }
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)(arg0) != 0) {
        TObjEnePanarms__sub_800E1C98(arg0, 0x10);
        return;
    }
    spawn_periodic_particle();
}

void TObjEnePanBARA::init_action() {
    void* t = *(void* *)&this->collision_body_parts;
    *(int*)((char*)t + 0x18) = (*(int*)((char*)t + 0x18) | 0x1);
    this->set_random_action_timer(0xF, 0x1E);
    *(int *)&this->m_384 = 1;
    *(int *)&this->m_388 = 1;
    *(float *)&this->m_3b0 = 0.0f;
    *(int *)&this->motion_flags = (*(int *)&this->motion_flags & 0xfffffffe);
    set_field_b8(2);
}

void TObjEnePanBARA::sub_800E055C() {
    Vec_800E18B0 v;
    s32 t;

    t = this->action_timer - 1;
    this->action_timer = t;
    if (t > 0) {
        if ((this->m_3b0 += -0.075f) < -1.0f) {
            this->m_3b0 = -1.0f;
        }
    } else {
        if ((this->m_3b0 += 0.025f) >= 0.0f) {
            this->m_3b0 = 0.0f;
            TObjEnePanarms__sub_800E1C98((u8 *)this, 2);
            return;
        }
    }
    v.x = this->m_3b0 * sin_table_lookup(this->rotation_y);
    v.z = this->m_3b0 * cos_table_lookup(this->rotation_y);
    v.y = 0.0f;
    ((void (*)(void *, Vec_800E18B0 *))try_move_with_detour__14TObjEnePanarmsFPvPv)((u8 *)this, &v);
    if (((s32 (*)(void *))is_below_half_hp__14TObjEnePanarmsFPv)((u8 *)this) != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0xC);
        return;
    }
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)((u8 *)this) != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0x10);
        return;
    }
    this->spawn_periodic_particle();
}

void TObjEnePanBARA::init_attack_state2() {
    int *r7 = *(int* *)&this->collision_body_parts;
    r7[6] = r7[6] | 0x1;
    *(int *)&this->m_384 = 1;
    this->m_388 = 1;
    this->m_3b0 = 0.0f;
    this->action_timer = 12;
    this->motion_flags = (this->motion_flags & 0xfffffffe);
    set_field_b8(3);
}

void TObjEnePanBARA::update_attack() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f3;
    s32 temp_r0;
    u8 *entity;

    entity = (u8 *)find_entity_by_id((u16) *(s32 *)&this->unk_3B8);
    if ((entity == NULL) || (*(s32 *)((s8 *)entity + 0x30) & 0x02000800)) {
        TObjEnePanarms__sub_800E1C98(arg0, 2);
        return;
    }
    temp_r0 = this->action_timer - 1;
    this->action_timer = temp_r0;
    if (temp_r0 == 0) {
        ((TObjEnePanBARA *)arg0)->attack_target_player(*(s32 *)&this->unk_3B8);
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003B72F)), (u8 *)&this->position, 0, 0);
    }
    if (this->frame < 5.0f) {
        temp_f3 = *(f32 *)((s8 *)entity + 0x38);
        this->rotation_y = approach_angle_limited(this->rotation_y, lbl_8043CDA0[this->m_380] + (s32) (10430.38043493439 * atan2_float(temp_f3 - this->position.x, *(f32 *)((s8 *)entity + 0x40) - this->position.z, temp_f3)), 0x200);
    }
    if (*(s32 *)&this->motion_flags & 0x10) {
        TObjEnePanarms__sub_800E1C98(arg0, 0xA);
    }
}

void TObjEnePanBARA::sub_800E0344() {
    u8 *temp_r7;
    if ((s32) this->m_380 != 1) {
        temp_r7 = (u8 *)(*(u8 **)((s8 *)this + 0x37C));
        *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
        *(s32 *)((s8 *)this + 0x384) = 1;
        this->m_388 = 1;
        this->m_3b0 = 0.0f;
        this->action_timer = 0x96;
        *(s32 *)((s8 *)this + 0x3C0) = 1;
        play_sound_effect((s32)((void *) (((s32)this->remap_sound_for_area((s32)(0x4003BC2D))))), (u8 *)this + 0x38, 0, 0);
        this->motion_flags = (s32) (this->motion_flags & 0xFFFFFFFE);
        ((TObjMotion *)this)->set_field_b8(2);
    }
}

#pragma push
#pragma fp_contract on
void TObjEnePanBARA::sub_800E0214() {
    s32 temp_r0;

    if (((s32 (*)(int))TObjEnePanarms__sub_800E2E68)((int) (*(s32 *)((s8 *)this + 0x3A0))) != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0xF);
        return;
    }
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)((u8 *)this) != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0x10);
        return;
    }
    temp_r0 = this->action_timer - 1;
    this->action_timer = temp_r0;
    if (((temp_r0 < 0) && (((s32 (*)(int))TObjEnePanarms__sub_800E2E54)((int) (*(s32 *)((s8 *)this + 0x3A0))) == 0)) || (TObjEnePanarms__sub_800DFB44((int) (*(s32 *)((s8 *)this + 0x3A0))) != 0)) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 2);
        return;
    }
    this->rotation_y = approach_angle_limited((int) (this->rotation_y), (int) ((s32) ((6144.0f * sin_table_lookup((int) (this->action_timer << 0xC))) + (f32) this->m_3d4)), 0x1111);
    if (!(this->action_timer & 0x3F)) {
        play_sound_effect(this->remap_sound_for_area((s32)(0x4003BC2D)), (u8 *)this + 0x38, 0, 0);
    }
    this->spawn_periodic_particle();
}
#pragma pop

void TObjEnePanBARA::start_phase2_timer150() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r7;
    if ((s32) this->m_380 != 0) {
        temp_r7 = (u8 *)(*(u8 * *)&this->collision_body_parts);
        *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
        *(s32 *)&this->m_384 = 1;
        this->m_388 = 1;
        this->m_3b0 = 0.0f;
        this->action_timer = 0x96;
        *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags & 0xFFFFFFFE);
        ((TObjMotion *)arg0)->set_field_b8(2);
    }
}

void TObjEnePanBARA::sub_800E0048() {
    Vec_800E0048 v;
    if (((s32 (*)(void))check_can_attack__14TObjEnePanarmsFPv)() != 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0x10);
        return;
    }
    if (--this->action_timer < 0 || ((s32 (*)(s32))is_phase_12__14TObjEnePanarmsFPv)(*(s32 *)((s8 *)this + 0x3A0)) == 0) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 2);
        return;
    }
    VecCopy((Vec *)&v, (const Vec *)((u8 *)this + 0x3C8));
    if (vector_length(&v) <= 0.01f) {
        v.x = 1.0f;
        v.z = 0.0f;
    } else {
        normalize_vector(&v);
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32)(10430.38043493439 * ((f64 (*)(f32, f32))atan2_float)(v.x, v.z)), 0x888);
    if (this->action_timer < 0x87) {
        if ((this->m_3b0 += 0.075f) > 1.25f) {
            this->m_3b0 = 1.25f;
        }
        v.x *= this->m_3b0;
        v.z *= this->m_3b0;
        ((s32 (*)(void *, void *))try_move_with_detour__14TObjEnePanarmsFPvPv)((u8 *)this, &v);
    }
    if (*(f32 *)((s8 *)this + 0x3D8) < 25.0f) {
        TObjEnePanarms__sub_800E1C98((u8 *)this, 0xE);
        return;
    }
    this->spawn_periodic_particle();
}

void TObjEnePanBARA::start_phase3_timer12() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r7;
    if ((s32) this->m_380 != 0) {
        temp_r7 = (u8 *)(*(u8 * *)&this->collision_body_parts);
        *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
        *(s32 *)&this->m_384 = 1;
        this->m_388 = 1;
        this->m_3b0 = 0.0f;
        this->action_timer = 0xC;
        *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags & 0xFFFFFFFE);
        ((TObjMotion *)arg0)->set_field_b8(3);
    }
}

void TObjEnePanBARA::update_move_timer() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;

    if ((TObjEnePanarms__sub_800DFB44(*(s32 *)&this->m_3a0) != 0) || (*(s32 *)&this->motion_flags & 0x10)) {
        TObjEnePanarms__sub_800E1C98(arg0, 0xA);
        return;
    }
    temp_r0 = this->action_timer - 1;
    this->action_timer = temp_r0;
    if (temp_r0 == 0) {
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003B72F)), (u8 *)&this->position, 0, 0);
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, this->m_3d4 - 0x800, 0x200);
}

void TObjEnePanBARA::init_open_state() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r7;
    if ((s32) this->m_380 != 1) {
        temp_r7 = (u8 *)(*(u8 * *)&this->collision_body_parts);
        *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
        *(s32 *)&this->m_384 = 1;
        this->m_388 = 1;
        this->m_3b0 = 0.0f;
        this->action_timer = 6;
        *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags & 0xFFFFFFFE);
        ((s32 (*)(void *, s32))set_field_b8__10TObjMotionFs)(arg0, 0);
    }
}

void TObjEnePanBARA::sub_800DFE08() {
    s32 temp_r0;
    s32 var_r5;
    temp_r0 = *(s32 *)((s8 *)this + 0x3B4) - 1;
    *(s32 *)((s8 *)this + 0x3B4) = temp_r0;
    if (temp_r0 == 0) {
        ((s32 (*)(void *, s32))set_field_b8__10TObjMotionFs)((u8 *)this, 4);
    }
    if (-15.0f == (f32) *(s32 *)((s8 *)this + 0x3B4)) {
        var_r5 = *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x33)) + 0x18);
        if ((var_r5 < 0) || (var_r5 > 0xE)) {
            var_r5 = 0;
        }
        TTecResta::create((void *)this, &position, (void *)var_r5);
        ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *) (this->remap_sound_for_area((s32)(0x4003BC31))), &position, 0, 0);
    }
    if (*(s32 *)((s8 *)this + 0xB0) & 0x10) {
        ((s32 (*)(void *, int))TObjEnePanarms__sub_800E1C98)((u8 *)this, 2);
    }
}

void TObjEnePanBARA::init_attack_state() {
    void *temp_r5;

    temp_r5 = *(void * *)&this->collision_body_parts;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    *(s32 *)&this->m_384 = 1;
    this->m_388 = 1;
    this->m_3b0 = 0.0f;
    this->action_timer = 0x3C;
    this->m_3c4 = 1;
    if (((s32 (*)(s32, s32, void *))angle_difference_abs)(this->rotation_y, this->m_3d4, temp_r5) < 0x2000) {
        if (angle_diff_s16(this->rotation_y, this->m_3d4) >= 0) {
            this->rotation_y = (this->m_3d4 - 0x2000);
        } else {
            this->rotation_y = (this->m_3d4 + 0x2000);
        }
    }
    *(s32 *)&this->motion_flags = (s32) (*(s32 *)&this->motion_flags & 0xFFFFFFFE);
    ((s32 (*)(void *, s32))set_field_b8__10TObjMotionFs)(this, 2);
}

void TObjEnePanBARA::update_action_timer() {
    s32 temp_r0;
    s32 temp_r3;

    temp_r0 = this->action_timer - 1;
    this->action_timer = temp_r0;
    if (temp_r0 < 0) {
        TObjEnePanarms__sub_800E1C98(this, 2);
        return;
    }
    temp_r3 = this->rotation_y;
    this->rotation_y = approach_angle_limited(this->rotation_y, this->m_3d4, 0x888);
    if (angle_difference_abs(temp_r3, this->rotation_y) == 0) {
        ((s32 (*)(void *, s32))set_field_b8__10TObjMotionFs)(this, 0);
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TObjEnePanarms::spawn_npc_pair() {
  s8 *new_var;
  Stack_800DFC18 stack;
  s32 temp_r8;
  u8 *temp_r5;
  u8 *temp_r5_2;
  stack.sp18 = *((s32 *) (((s8 *)&panarms_npc_binding_desc_a.value) + 0));
  stack.sp1C = *((s32 *) (((s8 *)&panarms_npc_binding_desc_a.value) + 4));
  stack.sp20 = *((s32 *) (((s8 *)&panarms_npc_binding_desc_a.value) + 8));
  stack.sp24 = *((s32 *) (((s8 *)&panarms_npc_binding_desc_a.value) + 0xC));
  temp_r8 = *((s32 *) ((new_var = (s8 *) TObjEnePanarms__entry_params_resource) + 0x430));
  stack.sp8 = *((s32 *) (((s8 *)&panarms_npc_binding_desc_b.value) + 0));
  stack.sp18 = temp_r8;
  stack.spC = *((s32 *) (((s8 *)&panarms_npc_binding_desc_b.value) + 4));
  stack.sp10 = *((s32 *) (((s8 *)&panarms_npc_binding_desc_b.value) + 8));
  stack.sp14 = *((s32 *) (((s8 *)&panarms_npc_binding_desc_b.value) + 0xC));
  stack.sp8 = temp_r8;
  temp_r5 = (u8 *) (*((u8 **) (new_var + 0x42C)));
  TLobby::spawn_npc_enemy((s16)(0x24), (s32)((int) (*((s32 *) (((s8 *) temp_r5) + 0x18)))), (NJS_TEXLIST *)((int) (*((s32 *) (((s8 *) temp_r5) + 0x1C)))), &stack.sp18, 7.5f, 0.0f);
  temp_r5_2 = (u8 *) (*((u8 **) (((s8 *) TObjEnePanarms__entry_params_resource) + 0x42C)));
  TLobby::spawn_npc_enemy((s16)(0x25), (s32)((int) (*((s32 *) (((s8 *) temp_r5_2) + 0x28)))), (NJS_TEXLIST *)((int) (*((s32 *) (((s8 *) temp_r5_2) + 0x2C)))), &stack.sp8, 7.5f, 0.0f);
}
#pragma pop

int TObjEnePanarms::find_nearest_enemy_with_flag(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    u16 temp_r3;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    temp_r3 = find_nearest_hittable_enemy__10TObjPlayerFiPvf((void *)arg0, (void *)arg1, (f32)farg0);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return temp_r3;
}

}
