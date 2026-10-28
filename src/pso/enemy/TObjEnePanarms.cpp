#include "types.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnePanBARA.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "dolphin/mtx.h"
#include <stddef.h>
#include "pso/TParticleCtrl.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TTecJelin.h"
#include "pso/misc/TTecResta.h"
#include "pso/misc/TTecZarua.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

typedef char PanarmsActionTimerOffset[offsetof(TObjEnePanarms, action_timer) == 0x3B4 ? 1 : -1];

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
extern const f32 TObjEnePanarms__data_805DA530;
void TObjEnePanarms__sub_800E0D1C(u8 *arg0);
s32 TObjEnePanarms__sub_800E1774(void *);
extern f32 lbl_8043CD98[];
extern const f32 lbl_805DA54C;
extern const f32 lbl_805DA574;
extern const f32 lbl_805DA578;
extern const f32 lbl_805DA57C;
f32 calc_boss4_scale__10TObjPlayerFi(void *);
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

struct RecoveredGlobal_800E0950_lbl_80495484 { s32 value; u8 remaining[0x9C]; };

typedef char RecoveredGlobal_800E0950_lbl_80495484_size[sizeof(RecoveredGlobal_800E0950_lbl_80495484) == 0xA0 ? 1 : -1];

struct Obj_800E0B9C { u8 pad0[0x38]; u8 f38[0x78]; u32 fB0; u8 padB4[0x380 - 0xB4]; s32 f380; s32 f384; s32 f388; };

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

struct ByteBlock_800E18B0 { u8 bytes[0xc]; };

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

typedef void (Panarms_800E2200::*Fn_800E2200)();

struct Ent_800E2200 { Fn_800E2200 enter; Fn_800E2200 fn; };

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

struct Obj_800E24A4 { u8 pad0[0x18]; void *vt; u8 pad1[0x37C - 0x1C]; s32 f37C; u8 pad2[0x3DC - 0x380]; s32 f3DC; u8 pad3[0x3EC - 0x3E0]; u8 f3EC[0x1C * 4]; };

struct O_800E2FB4 { u8 pad[0x378]; s32 state; };

struct Vec_800E06DC { f32 x, y, z; };

s32 find_nearest_hittable_enemy__10TObjPlayerFiPvf(void *, void *, f32);
u16 find_nearest_visible_player(void *, Vec_800E0A44 *, f32);
s32 is_split_screen();
f64 atan2_float(f32, f32, f32);
u8 * dispatch_shared_handler_a__6TLobbyFl(s32);
s32 get_camera_mode__11TCameraCtrlFv();
u32 csnLookAt(void *, void *);
s32 spawn_particle_effect(void *, int, f32);
s32 update_obstruction_fade(int, int);
void TObjEnePanarms__sub_800DFE08(u8 *arg0);
void TObjEnePanarms__sub_800E0048(u8 *arg0);
void TObjEnePanarms__sub_800E0344(u8 *arg0);
void TObjEnePanarms__sub_800E092C(void);
void TObjEnePanarms__sub_800E0930(u8 *arg0);
void TObjEnePanarms__sub_800E0950(u8 *arg0);
void TObjEnePanarms__sub_800E0A44(u8 *arg0);
void TObjEnePanarms__sub_800E0B9C(Obj_800E0B9C *arg0);
s32 try_move_with_detour__14TObjEnePanarmsFPvPv(u8 *arg0, Vec_800E18B0 *arg1);
void calc_default_part_position__14TObjEnePanarmsFPv(u8 *arg0);
void calc_part_position__14TObjEnePanBARAFPUcPl(u8 *arg0, u8 *arg1, s32 *arg2);
void TObjEnePanarms__sub_800E1C8C(void *arg0, s32 arg1, s32 arg2);
void TObjEnePanarms__sub_800E1D38(void *arg0);
int TObjEnePanarms__sub_800E1D94(void* p);
void TObjEnePanarms__sub_800E1E14(u8 *arg0);
Obj_800E24A4 * fn_800E24A4(Obj_800E24A4 *arg0, s16 arg1);
s32 TObjEnePanBARA__ct(s32, s32, s32, s32);
u8 is_phase_12__14TObjEnePanarmsFPv(void *arg0);
u8 TObjEnePanarms__sub_800E2E54(void *arg0);
u8 TObjEnePanarms__sub_800E2E68(void *arg0);
u8 is_below_half_hp__14TObjEnePanarmsFPv(void *arg0);
s32 TObjEnePanarms__sub_800E2FB4(O_800E2FB4 *self);
int clear_render_callback__8TObjFishFv(void);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, s32);
s32 TObjControl__ct(s32, s32);
void refresh_lobby_state__10TObjPlayerFv();
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
f32 horizontal_distance_squared(void *, void *);
s32 angle_difference_abs(s32, s32);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 approach_angle_limited(s32, s32, s32);
int draw__10TObjMotionFv(void*);
void advance_animation_playback(void *);
void *find_entity_by_id(u16 id);
void free_collision_body_parts(void *);
s32 project_actor_to_ground(void *, void *, int);
void submit_cursor_candidate(void *, s32);
u8 * get_player_by_client_id(s32);
void minimap_render_dot(void *, s32, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
s32 defer_render__7TObjectFv(void *);
void __dl__7TObjectFPv(void *);
s32 __nw__7TObjectFUl(s32);
void __destroy_arr(void *, void *, s32, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 scale_matrix(int, f32, f32, f32);
f32 vector_length(void *);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, void *);
s32 normalize_vector(void *);
s32 push_matrix();
s32 post_translate_matrix(void *, f32);
int set_global_state__16TObjEneRe7BeruraFl(void*);

extern const f64 TObjEnePanarms__data_8043CDD0;
extern u8 *TObjEnePanarms__entry_params_resource;
extern const f32 TObjEnePanarms__data_805DA524;
extern const f32 TObjEnePanarms__data_805DA52C;
extern const f32 TObjEnePanarms__data_805DA544;
extern const f32 TObjEnePanarms__data_805DA550;
extern const f32 TObjEnePanarms__data_805DA560;
extern u8 __dt__13TUnk_804949A8Fv[];
extern Vec_800E1A44 panarms_part_offset_table[];
extern s32 lbl_8043CD58[];
extern Vec_800E1A44 panarms_parent_offset_table[];
extern s32 lbl_8043CD78[];
extern Hit_800E1608 lbl_8043CD88[];
extern Hit_800E1608 lbl_8043CD90[];
extern s32 lbl_8043CDA0[];
extern RecoveredGlobal_800DFC18_lbl_8043CDA8 panarms_npc_binding_desc_a;
extern RecoveredGlobal_800DFC18_lbl_8043CDB8 panarms_npc_binding_desc_b;
extern RecoveredGlobal_800E0950_lbl_80495484 lbl_80495484;
extern Ent_800E2200 TObjEnePanarms__state_fn_table[];
extern s32 panarms_turn_delta_table[];
extern s32 panarms_sound_effect_pair[];
extern s32 TObjEnePanarms__sound_ids[];
extern u8 lbl_80495934[];
extern s8 lbl_805D5288;
extern s8 TObjEnePanarms__sound_ids_initialized;
extern f32 panarms_particle_frame_window;
extern u8 panarms_particle_frame_window_initialized;
extern s32 saved_model_render_flags;
extern const f32 lbl_805DA520;
extern const f32 lbl_805DA528;
extern const f32 lbl_805DA534;
extern const f32 lbl_805DA53C;
extern const f32 lbl_805DA540;
extern const f32 lbl_805DA554;
extern const f32 lbl_805DA558;
extern const f32 lbl_805DA55C;
extern const f32 lbl_805DA564;
extern const f32 lbl_805DA570;
extern const f32 lbl_805DA580;
extern const f32 lbl_805DA584;
extern const f32 lbl_805DA588;
extern const f32 lbl_805DA58C;
extern const f32 lbl_805DA590;
extern const f32 lbl_805DA594;
extern const f32 lbl_805DA598;
extern const f32 lbl_805DA59C;
extern s32 model_render_flags;
extern s32 tl_04;

int TObjEnePanarms::find_nearest_enemy_with_flag(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    u16 temp_r3;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    temp_r3 = find_nearest_hittable_enemy__10TObjPlayerFiPvf((void *)arg0, (void *)arg1, (f32)farg0);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return temp_r3;
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
  TLobby::spawn_npc_enemy((s16)(0x24), (s32)((int) (*((s32 *) (((s8 *) temp_r5) + 0x18)))), (s32)((int) (*((s32 *) (((s8 *) temp_r5) + 0x1C)))), (s32)((void *)&stack.sp18), (f32)((f32) lbl_805DA520), (f32)((f32) TObjEnePanarms__data_805DA524));
  temp_r5_2 = (u8 *) (*((u8 **) (((s8 *) TObjEnePanarms__entry_params_resource) + 0x42C)));
  TLobby::spawn_npc_enemy((s16)(0x25), (s32)((int) (*((s32 *) (((s8 *) temp_r5_2) + 0x28)))), (s32)((int) (*((s32 *) (((s8 *) temp_r5_2) + 0x2C)))), (s32)((void *)&stack.sp8), (f32)((f32) lbl_805DA520), (f32)((f32) TObjEnePanarms__data_805DA524));
}
#pragma pop

void TObjEnePanarms::update_action_timer() {
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

void TObjEnePanarms::init_attack_state() {
    void *temp_r5;

    temp_r5 = *(void * *)&this->unk_37C;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    *(s32 *)&this->unk_384 = 1;
    this->m_388 = 1;
    this->m_3b0 = (f32) TObjEnePanarms__data_805DA524;
    this->action_timer = 0x3C;
    this->m_3c4 = 1;
    if (((s32 (*)(s32, s32, void *))angle_difference_abs)(this->rotation_y, this->m_3d4, temp_r5) < 0x2000) {
        if (angle_diff_s16(this->rotation_y, this->m_3d4) >= 0) {
            this->rotation_y = (this->m_3d4 - 0x2000);
        } else {
            this->rotation_y = (this->m_3d4 + 0x2000);
        }
    }
    *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags & 0xFFFFFFFE);
    ((s32 (*)(void *, s32))set_field_b8__10TObjMotionFs)(this, 2);
}

void TObjEnePanarms__sub_800DFE08(u8 *arg0) {
    s32 temp_r0;
    s32 var_r5;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x3B4) - 1;
    *(s32 *)((s8 *)arg0 + 0x3B4) = temp_r0;
    if (temp_r0 == 0) {
        ((s32 (*)(void *, s32))set_field_b8__10TObjMotionFs)(arg0, 4);
    }
    if (lbl_805DA528 == (f32) *(s32 *)((s8 *)arg0 + 0x3B4)) {
        var_r5 = *(s32 *)((s8 *)(dispatch_shared_handler_a__6TLobbyFl(0x33)) + 0x18);
        if ((var_r5 < 0) || (var_r5 > 0xE)) {
            var_r5 = 0;
        }
        TTecResta::create((void *)arg0, arg0 + 0x38, (void *)var_r5);
        ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *) (((s32 (*)(void *, int))copy_target_state__14TObjEnePanarmsFPv)(arg0, 0x4003BC31)), arg0 + 0x38, 0, 0);
    }
    if (*(s32 *)((s8 *)arg0 + 0xB0) & 0x10) {
        ((s32 (*)(void *, int))TObjEnePanarms__sub_800E1C98)(arg0, 2);
    }
}

void TObjEnePanarms::init_open_state() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r7;
    if ((s32) this->m_380 != 1) {
        temp_r7 = (u8 *)(*(u8 * *)&this->unk_37C);
        *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
        *(s32 *)&this->unk_384 = 1;
        this->m_388 = 1;
        this->m_3b0 = (f32) TObjEnePanarms__data_805DA524;
        this->action_timer = 6;
        *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags & 0xFFFFFFFE);
        ((s32 (*)(void *, s32))set_field_b8__10TObjMotionFs)(arg0, 0);
    }
}

void TObjEnePanarms::update_move_timer() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;

    if ((TObjEnePanarms__sub_800DFB44(*(s32 *)&this->m_3a0) != 0) || (*(s32 *)&this->animationFlags & 0x10)) {
        TObjEnePanarms__sub_800E1C98(arg0, 0xA);
        return;
    }
    temp_r0 = this->action_timer - 1;
    this->action_timer = temp_r0;
    if (temp_r0 == 0) {
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B72F), (u8 *)&this->position, 0, 0);
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, this->m_3d4 - 0x800, 0x200);
}

void TObjEnePanarms::start_phase3_timer12() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r7;
    if ((s32) this->m_380 != 0) {
        temp_r7 = (u8 *)(*(u8 * *)&this->unk_37C);
        *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
        *(s32 *)&this->unk_384 = 1;
        this->m_388 = 1;
        this->m_3b0 = (f32) (*(const f32 *)&TObjEnePanarms__data_805DA524);
        this->action_timer = 0xC;
        *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags & 0xFFFFFFFE);
        set_field_b8__10TObjMotionFs(arg0, 3);
    }
}

void TObjEnePanarms__sub_800E0048(u8 *ene_panarms) {
    Vec_800E0048 v;
    if (((s32 (*)(void))check_can_attack__14TObjEnePanarmsFPv)() != 0) {
        TObjEnePanarms__sub_800E1C98(ene_panarms, 0x10);
        return;
    }
    if (--((TObjEnePanarms *)ene_panarms)->action_timer < 0 || ((s32 (*)(s32))is_phase_12__14TObjEnePanarmsFPv)(*(s32 *)((s8 *)ene_panarms + 0x3A0)) == 0) {
        TObjEnePanarms__sub_800E1C98(ene_panarms, 2);
        return;
    }
    VecCopy((Vec *)&v, (const Vec *)(ene_panarms + 0x3C8));
    if (vector_length(&v) <= TObjEnePanarms__data_805DA52C) {
        v.x = TObjEnePanarms__data_805DA530;
        v.z = TObjEnePanarms__data_805DA524;
    } else {
        normalize_vector(&v);
    }
    ((TObjEnePanarms *)ene_panarms)->rotation_y = approach_angle_limited(((TObjEnePanarms *)ene_panarms)->rotation_y, (s32)(TObjEnePanarms__data_8043CDD0 * ((f64 (*)(f32, f32))atan2_float)(v.x, v.z)), 0x888);
    if (((TObjEnePanarms *)ene_panarms)->action_timer < 0x87) {
        f32 t = ((TObjEnePanarms *)ene_panarms)->m_3b0 + lbl_805DA534;
        ((TObjEnePanarms *)ene_panarms)->m_3b0 = t;
        if (t > 1.25f) {
            ((TObjEnePanarms *)ene_panarms)->m_3b0 = 1.25f;
        }
        v.x *= ((TObjEnePanarms *)ene_panarms)->m_3b0;
        v.z *= ((TObjEnePanarms *)ene_panarms)->m_3b0;
        ((s32 (*)(void *, void *))try_move_with_detour__14TObjEnePanarmsFPvPv)(ene_panarms, &v);
    }
    if (*(f32 *)((s8 *)ene_panarms + 0x3D8) < lbl_805DA53C) {
        TObjEnePanarms__sub_800E1C98(ene_panarms, 0xE);
        return;
    }
    ((TObjEnePanarms *)ene_panarms)->spawn_periodic_particle();
}

void TObjEnePanarms::start_phase2_timer150() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r7;
    if ((s32) this->m_380 != 0) {
        temp_r7 = (u8 *)(*(u8 * *)&this->unk_37C);
        *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
        *(s32 *)&this->unk_384 = 1;
        this->m_388 = 1;
        this->m_3b0 = (f32) (*(const f32 *)&TObjEnePanarms__data_805DA524);
        this->action_timer = 0x96;
        *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags & 0xFFFFFFFE);
        set_field_b8__10TObjMotionFs(arg0, 2);
    }
}

#pragma push
#pragma fp_contract on
void TObjEnePanarms__sub_800E0214(u8 *ene_panarms) {
    s32 temp_r0;

    if (((s32 (*)(int))TObjEnePanarms__sub_800E2E68)((int) (*(s32 *)((s8 *)ene_panarms + 0x3A0))) != 0) {
        TObjEnePanarms__sub_800E1C98(ene_panarms, 0xF);
        return;
    }
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)(ene_panarms) != 0) {
        TObjEnePanarms__sub_800E1C98(ene_panarms, 0x10);
        return;
    }
    temp_r0 = ((TObjEnePanarms *)ene_panarms)->action_timer - 1;
    ((TObjEnePanarms *)ene_panarms)->action_timer = temp_r0;
    if (((temp_r0 < 0) && (((s32 (*)(int))TObjEnePanarms__sub_800E2E54)((int) (*(s32 *)((s8 *)ene_panarms + 0x3A0))) == 0)) || (TObjEnePanarms__sub_800DFB44((int) (*(s32 *)((s8 *)ene_panarms + 0x3A0))) != 0)) {
        TObjEnePanarms__sub_800E1C98(ene_panarms, 2);
        return;
    }
    ((TObjEnePanarms *)ene_panarms)->rotation_y = approach_angle_limited((int) (((TObjEnePanarms *)ene_panarms)->rotation_y), (int) ((s32) ((lbl_805DA540 * sin_table_lookup((int) (((TObjEnePanarms *)ene_panarms)->action_timer << 0xC))) + (f32) ((TObjEnePanarms *)ene_panarms)->m_3d4)), 0x1111);
    if (!(((TObjEnePanarms *)ene_panarms)->action_timer & 0x3F)) {
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(ene_panarms, 0x4003BC2D), ene_panarms + 0x38, 0, 0);
    }
    ((TObjEnePanarms *)ene_panarms)->spawn_periodic_particle();
}
#pragma pop

void TObjEnePanarms__sub_800E0344(u8 *ene_panarms) {
    u8 *temp_r7;
    if ((s32) ((TObjEnePanarms *)ene_panarms)->m_380 != 1) {
        temp_r7 = (u8 *)(*(u8 **)((s8 *)ene_panarms + 0x37C));
        *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
        *(s32 *)((s8 *)ene_panarms + 0x384) = 1;
        ((TObjEnePanarms *)ene_panarms)->m_388 = 1;
        ((TObjEnePanarms *)ene_panarms)->m_3b0 = (f32) (*(const f32 *)&TObjEnePanarms__data_805DA524);
        ((TObjEnePanarms *)ene_panarms)->action_timer = 0x96;
        *(s32 *)((s8 *)ene_panarms + 0x3C0) = 1;
        play_sound_effect((s32)((void *) (((s32)copy_target_state__14TObjEnePanarmsFPv(ene_panarms, 0x4003BC2D)))), ene_panarms + 0x38, 0, 0);
        ((TObjEnePanarms *)ene_panarms)->animationFlags = (s32) (((TObjEnePanarms *)ene_panarms)->animationFlags & 0xFFFFFFFE);
        set_field_b8__10TObjMotionFs(ene_panarms, 2);
    }
}

void TObjEnePanarms::update_attack() {
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
        ((TObjEnePanarms *)arg0)->attack_target_player(*(s32 *)&this->unk_3B8);
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B72F), (u8 *)&this->position, 0, 0);
    }
    if (this->m_c0 < TObjEnePanarms__data_805DA544) {
        temp_f3 = *(f32 *)((s8 *)entity + 0x38);
        this->rotation_y = approach_angle_limited(this->rotation_y, lbl_8043CDA0[this->m_380] + (s32) (TObjEnePanarms__data_8043CDD0 * atan2_float(temp_f3 - this->position.x, *(f32 *)((s8 *)entity + 0x40) - this->position.z, temp_f3)), 0x200);
    }
    if (*(s32 *)&this->animationFlags & 0x10) {
        TObjEnePanarms__sub_800E1C98(arg0, 0xA);
    }
}

void TObjEnePanarms::init_attack_state2() {
    int *r7 = *(int* *)&this->unk_37C;
    r7[6] = r7[6] | 0x1;
    *(int *)&this->unk_384 = 1;
    this->m_388 = 1;
    this->m_3b0 = TObjEnePanarms__data_805DA524;
    this->action_timer = 12;
    this->animationFlags = (this->animationFlags & 0xfffffffe);
    set_field_b8__10TObjMotionFs(this, 3);
}

void TObjEnePanarms__sub_800E055C(u8 *ene_panarms) {
    Vec_800E18B0 v;
    s32 t;
    f32 sp;

    t = ((TObjEnePanarms *)ene_panarms)->action_timer - 1;
    ((TObjEnePanarms *)ene_panarms)->action_timer = t;
    if (t > 0) {
        if ((((TObjEnePanarms *)ene_panarms)->m_3b0 += -0.075f) < -1.0f) {
            ((TObjEnePanarms *)ene_panarms)->m_3b0 = -1.0f;
        }
    } else {
        if ((((TObjEnePanarms *)ene_panarms)->m_3b0 += 0.025f) >= 0.0f) {
            ((TObjEnePanarms *)ene_panarms)->m_3b0 = 0.0f;
            TObjEnePanarms__sub_800E1C98(ene_panarms, 2);
            return;
        }
    }
    v.x = ((TObjEnePanarms *)ene_panarms)->m_3b0 * sin_table_lookup(((TObjEnePanarms *)ene_panarms)->rotation_y);
    v.z = ((TObjEnePanarms *)ene_panarms)->m_3b0 * cos_table_lookup(((TObjEnePanarms *)ene_panarms)->rotation_y);
    v.y = 0.0f;
    ((void (*)(void *, Vec_800E18B0 *))try_move_with_detour__14TObjEnePanarmsFPvPv)(ene_panarms, &v);
    if (((s32 (*)(void *))is_below_half_hp__14TObjEnePanarmsFPv)(ene_panarms) != 0) {
        TObjEnePanarms__sub_800E1C98(ene_panarms, 0xC);
        return;
    }
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)(ene_panarms) != 0) {
        TObjEnePanarms__sub_800E1C98(ene_panarms, 0x10);
        return;
    }
    ((TObjEnePanarms *)ene_panarms)->spawn_periodic_particle();
}

void TObjEnePanarms::init_action() {
    void* t = *(void* *)&this->unk_37C;
    *(int*)((char*)t + 0x18) = (*(int*)((char*)t + 0x18) | 0x1);
    this->set_random_action_timer(0xF, 0x1E);
    *(int *)&this->unk_384 = 1;
    *(int *)&this->m_388 = 1;
    *(float *)&this->m_3b0 = TObjEnePanarms__data_805DA524;
    *(int *)&this->animationFlags = (*(int *)&this->animationFlags & 0xfffffffe);
    set_field_b8__10TObjMotionFs(this, 2);
}

void TObjEnePanarms::update_chase_target() {
    u8 *arg0 = (u8 *)this;
    Vec_800E06DC sp8;
    f32 v;
    u8 *p;

    p = (u8 *)find_entity_by_id((u16) *(s32 *)&this->unk_3B8);
    if (p == NULL || (*(s32 *)((s8 *)p + 0x30) & 0x02000800)) {
        TObjEnePanarms__sub_800E1C98(arg0, 2);
        return;
    }
    (this->action_timer)--;
    VecCopy((Vec *)&sp8, (const Vec *)(p + 0x38));
    subtract_vector(&sp8, (u8 *)&this->position);
    sp8.y = TObjEnePanarms__data_805DA524;
    if (vector_length(&sp8) <= TObjEnePanarms__data_805DA52C) {
        sp8.x = TObjEnePanarms__data_805DA530;
        sp8.z = TObjEnePanarms__data_805DA524;
    } else {
        normalize_vector(&sp8);
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (TObjEnePanarms__data_8043CDD0 * ((f64 (*)(f32, f32))atan2_float)(sp8.x, sp8.z)), 0x101);
    if (this->action_timer > 0) {
        this->m_3b0 = v = this->m_3b0 + lbl_805DA534;
        if (v > 1.25f) {
            this->m_3b0 = 1.25f;
        }
    } else {
        this->m_3b0 = v = this->m_3b0 - 0.075f;
        if (v < 0.0f) {
            this->m_3b0 = 0.0f;
        }
    }
    sp8.x *= this->m_3b0;
    sp8.z *= this->m_3b0;
    ((s32 (*)(void *, void *))try_move_with_detour__14TObjEnePanarmsFPvPv)(arg0, &sp8);
    if (TObjEnePanarms__data_805DA524 == this->m_3b0) {
        TObjEnePanarms__sub_800E1C98(arg0, 0xA);
        return;
    }
    if (horizontal_distance_squared(p + 0x38, (u8 *)&this->position) < lbl_805DA554) {
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

void TObjEnePanarms::init_state_2() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r7;
    temp_r7 = (u8 *)(*(u8 * *)&this->unk_37C);
    *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) | 1);
    *(s32 *)&this->unk_384 = 1;
    this->m_388 = 1;
    this->action_timer = 0x5A;
    *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags & 0xFFFFFFFE);
    set_field_b8__10TObjMotionFs(arg0, 2);
}

void TObjEnePanarms__sub_800E092C(void) {  }

void TObjEnePanarms__sub_800E0930(u8 *arg0) {
    u8 *temp_r5;
    temp_r5 = *(u8 **)((s8 *)arg0 + 0x37C);
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFFFFFFE);
    *(s32 *)((s8 *)arg0 + 0x384) = 0;
    *(s32 *)((s8 *)arg0 + 0x388) = 0;
}

void TObjEnePanarms__sub_800E0950(u8 *panarms) {
    Stack_800E0950 stack;
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_r0;
    *(s32 *)((s8 *)panarms + 0x3B4) = (s32) (*(s32 *)((s8 *)panarms + 0x3B4) - 1);
    if ((s8) panarms_particle_frame_window_initialized == 0) {
        panarms_particle_frame_window_initialized = 1;
        panarms_particle_frame_window = *(f32 *)((s8 *)&lbl_80495484.value + 0x68);
    }
    temp_f2 = *(f32 *)((s8 *)panarms + 0xC0);
    if ((temp_f2 >= lbl_805DA558) && (temp_f2 < (lbl_805DA558 + panarms_particle_frame_window))) {
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(panarms + 0x3A4));
        temp_f1 = stack.spC;
        stack.spC = temp_f1 + TObjEnePanarms__data_805DA544;
        spawn_particle_effect((void *)&stack.sp8, 0xF3, temp_f1);
    }
    temp_r0 = *(s32 *)((s8 *)panarms + 0x3B4);
    if (temp_r0 <= 0x78) {
        if (temp_r0 == 0x78) {
            ((TObjPlayer *)(panarms + 0x3A4))->spawn_ground_effect(0x78);
            TObjPlayer::spawn_dead_spot_default((s32)(panarms + 0x3A4), 6);
        }
        *(f32 *)((s8 *)panarms + 0x3C) = (f32) (*(f32 *)((s8 *)panarms + 0x3C) + lbl_805DA55C);
        if ((s32) *(s32 *)((s8 *)panarms + 0x3B4) < 0) {
            TObjEnePanarms__sub_800E1C98((void *)panarms, 8);
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjEnePanarms__sub_800E0A44(u8 *ene_panarms) {
    Vec_800E0A44 v;
    s16 var_r30;
    *(s32 *)((s8 *)ene_panarms + 0x384) = 1;
    ((TObjEnePanarms *)ene_panarms)->m_388 = 0;
    refresh_lobby_state__10TObjPlayerFv();
    var_r30 = 7;
    ((TObjEnePanarms *)ene_panarms)->animationFlags &= ~1;
    if (find_nearest_visible_player(ene_panarms, &v, TObjEnePanarms__data_805DA560) != 0xFFFF) {
        if (v.x * sin_table_lookup(((TObjEnePanarms *)ene_panarms)->rotation_y) + v.z * cos_table_lookup(((TObjEnePanarms *)ene_panarms)->rotation_y) < TObjEnePanarms__data_805DA524) {
            var_r30 = 6;
        }
    }
    set_field_b8__10TObjMotionFs(ene_panarms, var_r30);
    if (TObjEnePanarms__sound_ids_initialized == 0) {
        TObjEnePanarms__sound_ids[0] = copy_target_state__14TObjEnePanarmsFPv(ene_panarms, 0x4003B836);
        TObjEnePanarms__sound_ids[1] = copy_target_state__14TObjEnePanarmsFPv(ene_panarms, 0x4003BB35);
        TObjEnePanarms__sound_ids_initialized = 1;
    }
    play_sound_effect(TObjEnePanarms__sound_ids[((TObjEnePanarms *)ene_panarms)->m_380], ene_panarms + 0x38, 0, 0);
    ((TObjEnePanarms *)ene_panarms)->action_timer = 0xA4;
}
#pragma pop

void TObjEnePanarms::apply_effect_if_flagged() {
    if (*(s32 *)&this->animationFlags & 0x10) {
        TObjEnePanarms__sub_800E1C98(this, (s32)(*(s32 *)&this->unk_374));
    }
}

void TObjEnePanarms__sub_800E0B9C(Obj_800E0B9C *arg0) {
    arg0->f384 = 1;
    arg0->f388 = 1;
    if (lbl_805D5288 == 0) {
        panarms_sound_effect_pair[0] = ((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003BC34));
        s32 t = ((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003BC33));
        lbl_805D5288 = 1;
        panarms_sound_effect_pair[1] = t;
    }
    play_sound_effect(panarms_sound_effect_pair[arg0->f380], arg0->f38, 0, 0);
    arg0->fB0 &= 0xFFFFFFFE;
    set_field_b8__10TObjMotionFs(arg0, 5);
}

void TObjEnePanarms::update_hit_state() {
    if (TObjEnePanarms__sub_800DFB44(*(s32 *)&this->m_3a0) != 0) {
        TObjEnePanarms__sub_800E1C98(this, 2);
        return;
    }
    if (this->animationFlags & 0x10) {
        TObjEnePanarms__sub_800E1C98(this, 0);
    }
}

void TObjEnePanarms::restore_from_linked_object() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;
    temp_r4 = (u8 *)(*(u8 * *)&this->unk_37C);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(*(u8 * *)&this->m_39c + 0x38));
    this->rotation_y = (s32) *(s32 *)((s8 *)((u8 *)(*(u8 * *)&this->m_39c)) + 0x60);
    *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags | 1);
    set_field_b8__10TObjMotionFs(arg0, 8);
}

#pragma push
#pragma fp_contract on
void TObjEnePanarms__sub_800E0D1C(u8 *motion) {
    typedef char sp8_offset[(offsetof(Stack_800E0D1C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800E0D1C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800E0D1C, sp10) == 0x8) ? 1 : -1];
    Stack_800E0D1C stack;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f31;
    s32 temp_r0;
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)(motion) != 0) {
        TObjEnePanarms__sub_800E1C98(motion, 0x10);
        return;
    }
    if (TObjEnePanarms__sub_800DFB44((int) (*(s32 *)((s8 *)motion + 0x3A0))) != 0) {
        TObjEnePanarms__sub_800E1C98(motion, 2);
        return;
    }
    temp_r0 = *(s32 *)((s8 *)motion + 0x3B4) - 5;
    if (temp_r0 > 0) {
        temp_f31 = TObjEnePanarms__data_805DA530 / (f32) temp_r0;
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(motion + 0x38C));
        subtract_vector(&stack.sp8, motion + 0x38);
        stack.sp8 *= temp_f31;
        stack.spC *= temp_f31;
        stack.sp10 *= temp_f31;
        vec3_add_to(motion + 0x38, &stack.sp8);
        ((TObjMotion *)motion)->rotation_y = (s32) ((temp_f31 * (f32) angle_diff_s16((int) (((TObjMotion *)motion)->rotation_y), (int) (*(s32 *)((s8 *)motion + 0x398)))) + (f32) ((TObjMotion *)motion)->rotation_y);
    } else if (temp_r0 == 0) {
        set_field_b8__10TObjMotionFs(motion, 0);
    }
    *(s32 *)((s8 *)motion + 0x3B4) = (s32) (*(s32 *)((s8 *)motion + 0x3B4) - 1);
}
#pragma pop

void TObjEnePanarms::init_state_16() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    temp_r6 = (u8 *)(*(u8 * *)&this->unk_37C);
    *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) | 1);
    this->action_timer = 0x16;
    *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags & 0xFFFFFFFE);
    set_field_b8__10TObjMotionFs(arg0, 1);
}

void TObjEnePanarms::update_move_to_target() {
    u8 *arg0 = (u8 *)this;
    Vec_800E0ED0 sp8;
    f32 dist;
    f32 v;
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
    sp8.y = (*(const f32 *)&TObjEnePanarms__data_805DA524);
    dist = vector_length(&sp8);
    if (dist <= TObjEnePanarms__data_805DA52C) {
        sp8.x = TObjEnePanarms__data_805DA530;
        sp8.z = (*(const f32 *)&TObjEnePanarms__data_805DA524);
    } else {
        normalize_vector(&sp8);
    }
    if (*(s32 *)((s8 *)(*(u8 * *)&this->unk_37C) + 0x18) & 0x01C00000) {
        f32 t = sp8.x;
        sp8.x = sp8.z;
        sp8.z = -t;
    }
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (TObjEnePanarms__data_8043CDD0 * ((f64 (*)(f32, f32))atan2_float)(sp8.x, sp8.z)), 0x208);
    if (dist > lbl_805DA564) {
        this->m_3b0 = v = this->m_3b0 + TObjEnePanarms__data_805DA550;
        if (v > 0.6f) {
            this->m_3b0 = 0.6f;
        }
    } else {
        this->m_3b0 = v = this->m_3b0 - TObjEnePanarms__data_805DA550;
        if (v < 0.3f) {
            this->m_3b0 = 0.3f;
        }
    }
    sp8.x *= this->m_3b0;
    sp8.z *= this->m_3b0;
    ((s32 (*)(void *, void *))try_move_with_detour__14TObjEnePanarmsFPvPv)(arg0, &sp8);
    if (horizontal_distance_squared((u8 *)&this->m_38c, (u8 *)&this->position) < lbl_805DA570) {
        TObjEnePanarms__sub_800E1C98(arg0, 4);
    }
}

void TObjEnePanarms::init_state_1() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r5;
    temp_r5 = (u8 *)(*(u8 * *)&this->unk_37C);
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags & 0xFFFFFFFE);
    set_field_b8__10TObjMotionFs(arg0, 1);
}

#pragma push
#pragma fp_contract on
void TObjEnePanarms__sub_800E10D0(u8 *motion) {
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
    f32 w;

    t = *(s32 *)((s8 *)motion + 0x3B4) - 1;
    *(s32 *)((s8 *)motion + 0x3B4) = t;
    if (t > 0) {
        return;
    }
    if (*(s32 *)((s8 *)motion + 0x3B4) == 0) {
        ((TObjMotion *)motion)->animationFlags &= ~1;
        set_field_b8__10TObjMotionFs(motion, 1);
    }
    if (*(s32 *)((s8 *)motion + 0x380) == 1 && ((s32 (*)(s32))is_phase_12__14TObjEnePanarmsFPv)(*(s32 *)((s8 *)motion + 0x3A0)) != 0) {
        if (*(f32 *)((s8 *)motion + 0x3D8) < lbl_805DA574) {
            TObjEnePanarms__sub_800E1C98(motion, 0xA);
            return;
        }
        TObjEnePanarms__sub_800E1C98(motion, 0xD);
        return;
    }
    idx = find_nearest_visible_player(motion, &v, TObjEnePanarms__data_805DA560);
    ok = 0;
    if (idx != 0xFFFF) {
        angle = (s32)(TObjEnePanarms__data_8043CDD0 * ((f64 (*)(f32, f32))atan2_float)(v.x, v.z));
        if (angle_difference_abs(((TObjMotion *)motion)->rotation_y, angle) < 0x208) {
            ok = 1;
        }
    }
    if (ok != 0) {
        ((TObjMotion *)motion)->rotation_y = approach_angle_limited(((TObjMotion *)motion)->rotation_y, angle, 0x208);
        scale = lbl_805DA578;
        p = get_player_by_client_id(idx);
        if (p != NULL) {
            if (*(s32 *)((s8 *)motion + 0x380) == 1) {
                scale *= lbl_805DA54C;
            }
            VecCopy((Vec *)&a, (const Vec *)(p + 0x38));
            a.x += scale * cos_table_lookup(((TObjMotion *)motion)->rotation_y);
            a.z -= scale * sin_table_lookup(((TObjMotion *)motion)->rotation_y);
            subtract_vector(&a, motion + 0x38);
            a.y = TObjEnePanarms__data_805DA524;
            if (vector_length(&a) <= TObjEnePanarms__data_805DA52C) {
                a.x = a.z = TObjEnePanarms__data_805DA524;
            } else {
                normalize_vector(&a);
            }
        }
    } else {
        if (*(s32 *)((s8 *)motion + 0x380) == 0) {
            ((TObjMotion *)motion)->rotation_y -= 0x208;
        } else {
            ((TObjMotion *)motion)->rotation_y += 0x208;
        }
        a.x = sin_table_lookup(((TObjMotion *)motion)->rotation_y);
        a.z = cos_table_lookup(((TObjMotion *)motion)->rotation_y);
        a.y = TObjEnePanarms__data_805DA524;
    }
    max = lbl_8043CD98[*(s32 *)((s8 *)motion + 0x380)];
    *(f32 *)((s8 *)motion + 0x3B0) = w = *(f32 *)((s8 *)motion + 0x3B0) + TObjEnePanarms__data_805DA550;
    if (w > max) {
        *(f32 *)((s8 *)motion + 0x3B0) = max;
    }
    a.x *= *(f32 *)((s8 *)motion + 0x3B0);
    a.z *= *(f32 *)((s8 *)motion + 0x3B0);
    ((s32 (*)(void *, void *))try_move_with_detour__14TObjEnePanarmsFPvPv)(motion, &a);
    if (((s32 (*)(void *))is_below_half_hp__14TObjEnePanarmsFPv)(motion) != 0) {
        TObjEnePanarms__sub_800E1C98(motion, 0xC);
        return;
    }
    if (((s32 (*)(void *))check_can_attack__14TObjEnePanarmsFPv)(motion) != 0) {
        TObjEnePanarms__sub_800E1C98(motion, 0x10);
        return;
    }
    if (TObjEnePanarms__sub_800E1774(motion) != 0) {
        e = (u8 *)find_entity_by_id(*(s32 *)((s8 *)motion + 0x3B8));
        if (e != NULL && horizontal_distance_squared(e + 0x38, motion + 0x38) < lbl_805DA57C) {
            TObjEnePanarms__sub_800E1C98(motion, 0xA);
            return;
        }
        TObjEnePanarms__sub_800E1C98(motion, 9);
    }
}
#pragma pop

void TObjEnePanarms::start_action() {
    void *temp_r4;

    this->set_random_action_timer(0xF, 0x3C);
    temp_r4 = *(void * *)&this->unk_37C;
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) | 1);
    this->m_388 = 1;
    if ((s32) *(s32 *)&this->unk_374 == 1) {
        *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags | 1);
    } else {
        *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags & 0xFFFFFFFE);
    }
    set_field_b8__10TObjMotionFs(this, 0);
}

void TObjEnePanarms::handle_split_flag() {
    if (this->animationFlags & 0x10) {
        ((s32 (*)(void))calc_default_part_position__14TObjEnePanarmsFPv)();
        TObjEnePanarms__sub_800E1C98(this, 2);
    }
}

void TObjEnePanarms::init_split() {
    void *temp_r7;

    temp_r7 = *(void * *)&this->unk_37C;
    *(s32 *)((s8 *)temp_r7 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r7 + 0x18) & 0xFFFFFFFE);
    *(s32 *)&this->unk_384 = 1;
    this->m_388 = 0;
    this->hp = (s16) (((*(s16 *)((s8 *)(*(void * *)&this->m_39c) + 0x32C)) + 1) / 2);
    this->m_3bc = (s32) this->hp;
    *(s32 *)&this->unk_3C0 = 0;
    sub_800E2DE4(0x10);
    *(s32 *)&this->animationFlags = (s32) (*(s32 *)&this->animationFlags | 1);
    set_field_b8__10TObjMotionFs(this, 9);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEnePanarms::snap_to_parent_position() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(this->m_39c + 0x38));
    this->position.x = (f32) (this->position.x + lbl_805DA580);
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) + lbl_805DA580);
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanarms::reset_state() { *(int*)((char*)*(int *)&this->unk_37C + 0x18) = (*(int*)((char*)*(int *)&this->unk_37C + 0x18) & 0xfffffffe); *(float *)&this->m_3b0 = TObjEnePanarms__data_805DA524; *(int *)&this->unk_384 = 0; *(int *)&this->m_388 = 0; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanarms::spawn_periodic_particle() {
    u8 *arg0 = (u8 *)this;
    Vec position;
    if (!(this->m_45c & 7)) {
        VecCopy((Vec *)(&position.x), (const Vec *)(arg0 + 0x3A4));
        position.y += TObjEnePanarms__data_805DA544;
        ((s32 (*)(void *, int))spawn_particle_effect)(&position.x, 0xF3);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanarms::attack_target_player(s32 arg1) {
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
        sc = calc_boss4_scale__10TObjPlayerFi(this);
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
#pragma fp_contract on
s32 try_move_with_detour__14TObjEnePanarmsFPvPv(u8 *arg0, Vec_800E18B0 *arg1) {
    Vec_800E18B0 dir;
    Vec_800E18B0 t;
    Vec_800E18B0 p;
    s32 i;
    s32 ang;
    f32 s;
    f32 c;
    f32 nx;
    *(ByteBlock_800E18B0 *)&dir = *(ByteBlock_800E18B0 *)arg1;
    dir.y = (*(const f32 *)&TObjEnePanarms__data_805DA524);
    if ((*(const f32 *)&TObjEnePanarms__data_805DA524) == vector_length(&dir)) {
        return 0;
    }
    VecCopy((Vec *)&t, (const Vec *)(arg0 + 0x38));
    vec3_add_to(&t, arg1);
    if (horizontal_distance_squared(&t, arg0 + 0x50) > lbl_805DA584) {
        return 0;
    }
    for (i = 1; i < 16; i++) {
        VecCopy((Vec *)&p, (const Vec *)(arg0 + 0x38));
        vec3_add_to(&p, &dir);
        p.y += lbl_805DA588;
        if (project_actor_to_ground(arg0, &p, 0) != 0 && csnLookAt(arg0 + 0x38, &p) == 0) {
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
#pragma fp_contract on
void TObjEnePanarms::update_offset_from_parent() {
    f32 x;
    f32 z;
    f32 s;
    f32 c;
    x = panarms_parent_offset_table[this->m_380].x;
    z = panarms_parent_offset_table[this->m_380].z;
    s = sin_table_lookup(*(s32 *)((s8 *)(*(u8 * *)&this->m_39c) + 0x60));
    c = cos_table_lookup(*(s32 *)((s8 *)(*(u8 * *)&this->m_39c) + 0x60));
    VecCopy((Vec *)&this->m_38c, (const Vec *)(*(u8 * *)&this->m_39c + 0x38));
    *(f32 *)&this->m_38c += x * c + z * s;
    *(f32 *)&this->unk_394 += -x * s + z * c;
    this->m_398 = *(s32 *)((s8 *)(*(u8 * *)&this->m_39c) + 0x60);
    this->m_398 += lbl_8043CD78[this->m_380];
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void calc_default_part_position__14TObjEnePanarmsFPv(u8 *ene_pan_bara) {
    calc_part_position__14TObjEnePanBARAFPUcPl(ene_pan_bara, ene_pan_bara + 0x38, (s32 *)(ene_pan_bara + 0x60));
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
void TObjEnePanarms__sub_800E1C8C(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x39C) = arg1;
    *(s32 *)((s8 *)arg0 + 0x3A0) = arg2;
}
#pragma pop

void TObjEnePanarms__sub_800E1C98(void *panarms, s32 state) {
    Panarms_800E2200 *self = (Panarms_800E2200 *)panarms;
    Fn_800E2200 enter;
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
        (self->*enter)();
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanarms__sub_800E1D38(void *arg0) {
    struct VObj_800E1D38_800E158C *o = (struct VObj_800E1D38_800E158C *)arg0;
    o->m61();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanarms::reset_split() {
    if ((s32) this->m_378 != 0) {
        ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)(this, 0);
    }
}
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
int TObjEnePanarms::do_action_2(void* p) { return ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)(p, 2); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEnePanarms::init_state() {
    s32 arg0 = (s32)this;
    update_offset_from_parent();
    ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)((void*)arg0, 3);
}
#pragma pop

void TObjEnePanarms__sub_800E1E14(u8 *arg0) {
    u8 *temp_r5;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x39C) + 0x38));
    temp_r5 = *(u8 **)((s8 *)arg0 + 0x39C);
    *(s32 *)((s8 *)arg0 + 0x60) = (s32) *(s32 *)((s8 *)temp_r5 + 0x60);
    ((s32 (*)(void *, int, int))TObjEnePanarms__sub_800E1C98)((void *)arg0, 1, (int)temp_r5);
}

void TObjEnePanBARA::vfunc_61() { this->actorFlags &= 0xfffffeff; }

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
            *(f32 *)((s8 *)arg0 + 0x38) += lbl_805DA588 * sin_table_lookup(this->rotation_y);
            *(f32 *)((s8 *)arg0 + 0x40) += lbl_805DA588 * cos_table_lookup(this->rotation_y);
            VecCopy((Vec *)&this->m_2fc, &this->position);
        }
        ((int (*)(void*, int))TObjEnePanarms__sub_800E1C98)(arg0, 7);
        break;
    }
}
#pragma pop

void TObjEnePanarms::update_linked_effect() {
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
        this->m_3a8 = (f32) (temp_f1 + lbl_805DA58C);
        post_translate_matrix((u8 *)&this->unk_3A4, temp_f1);
        direction_to_rotation_xz((u8 *)&sp10, (s32 *)((s32 *)&spC), (s32 *)((s32 *)&sp8));
        rotate_matrix_z(0, sp8);
        rotate_matrix_y(0, this->rotation_y);
        rotate_matrix_x(0, (void *)(spC + 0x4000));
        scale_matrix(0, lbl_805DA590, lbl_805DA590, TObjEnePanarms__data_805DA530);
        temp_r0 = this->m_378;
        if ((temp_r0 != 7) && (temp_r0 != 8)) {
            draw_blob_shadow(0);
        }
        pop_matrix();
    }
}

void TObjEnePanarms::draw() { ((int (*)(void*))push_matrix)(this); ((int (*)(void*))post_translate_matrix)((char*)this + 0x38); ((int (*)(void*, void*))rotate_matrix_y)((void*)0, *(void* *)&this->rotation_y); TObjFish::set_global_param((s32)(*(void* *)&this->texlist)); ((TObjFish *)(this->m_3dc))->set_draw_callback_list(); draw__10TObjMotionFv(this); ((int (*)(void*))clear_render_callback__8TObjFishFv)(this->m_3dc); ((int (*)(void))pop_matrix)(); }

void TObjEnePanarms::draw_with_fade() {
    s32 temp_r4;
    s32 var_r31;
    VObj_14_aa9368 *temp_r31;
    s32 var_r30;
    if ((((VObj_18_26a62c *)(this))->m8(TObjEnePanarms__data_805DA560, lbl_805DA594) == 0) || ((s32) *(s32 *)&this->unk_384 == 0)) {
        *(f32 *)&this->unk_3AC = (f32) TObjEnePanarms__data_805DA524;
        this->m_3a8 = (f32) TObjEnePanarms__data_805DA524;
        *(f32 *)&this->unk_3A4 = (f32) TObjEnePanarms__data_805DA524;
        return;
    }
    var_r31 = 0;
    if (is_split_screen() != 0) {
        var_r31 = get_camera_mode__11TCameraCtrlFv();
    }
    TObjPlayer::toggle_particle_effect();
    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x01000000 | 1;
    temp_r31 = &((Obj_800E20D0 *) ((u8 *)this))->fades[var_r31];
    update_obstruction_fade((int)temp_r31, (int)temp_r4);
    if (((RenderFadeState *)temp_r31)->updateFromCamera((const f32*)(((u8 *)this) + 0x2FC)) != 0) {
        temp_r31->m6();
        var_r30 = 1;
        if (defer_render__7TObjectFv(this) != 0) {
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

void run_state_machine__14TObjEnePanarmsFPv(Panarms_800E2200 *self) {
    Fn_800E2200 fn;
    Vec_800E2200 a;
    f32 s;

    if (self->state != 0 && TObjPlayer::check_demo_mode() != 0) {
        ((void (*)(void *, s32))TObjEnePanarms__sub_800E1C98)(self, 0);
    }
    self->diff.x = self->target->x - self->x;
    self->diff.y = TObjEnePanarms__data_805DA524;
    self->diff.z = self->target->z - self->z;
    self->angle = ((const f64 *)&TObjEnePanarms__data_8043CDD0)[0] * ((f32 (*)(f32, f32))atan2_float)(self->diff.x, self->diff.z);
    self->dist = vector_length(&self->diff);
    self->counter++;
    fn = TObjEnePanarms__state_fn_table[self->state].fn;
    if (fn == 0) {
        return;
    }
    (self->*fn)();
    if (self->f384 != 0) {
        self->flags &= ~0x02000000;
    } else {
        self->flags |= 0x02000000;
    }
    ((TObjEnemy *)self)->update_prev_position();
    if (self->state == 0) {
        return;
    }
    if (self->f384 != 0) {
        if (self->state != 7) {
            submit_cursor_candidate(self, -1);
        }
        advance_animation_playback(self);
        switch (self->state) {
        case 7:
            break;
        case 1:
            s = self->fC0 / lbl_805DA598;
            ((void (*)(void *, void *, s32, f32))calc_part_position__14TObjEnePanBARAFPUcPl)(self, &a, 0, self->fC0);
            ((void (*)(void *, void *))subtract_vector)(&a, &self->pos);
            a.x *= s;
            a.z *= s;
            ((void (*)(void *, void *))vec3_add_to)(&a, &self->pos);
            minimap_render_dot(&a, -0x5DB4, 1, 0);
            break;
        case 5:
            {
            s = self->fC0 / lbl_805DA59C;
            Vec_800E2200 b = self->pos;
            ((void (*)(void *, void *))subtract_vector)(&b, &self->f38C);
            b.x *= s;
            b.z *= s;
            ((void (*)(void *, void *))vec3_add_to)(&b, &self->f38C);
            minimap_render_dot(&b, -0x5DB4, 1, 0);
            }
            break;
        default:
            minimap_render_dot(&self->pos, -0x5DB4, 1, 0);
            break;
        }
    }
    if (self->f388 == 0) {
        *(u32 *)(self->f37C + 0x18) &= ~1;
    }
}

Obj_800E24A4 *fn_800E24A4(Obj_800E24A4 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt = lbl_80495934;
        free_collision_body_parts(arg0);
        arg0->f37C = 0;
        TObjFish::init_state_1((void *)arg0->f3DC);
        __destroy_arr(arg0->f3EC, __dt__13TUnk_804949A8Fv, 0x1C, 4);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

s32 TObjEnePanarms::create_bara(s32 arg0, s32 arg1) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = __nw__7TObjectFUl(0x470);
    if (var_r31 != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        var_r31 = TObjEnePanBARA__ct(var_r31, var_r4, arg0, arg1);
    }
    return var_r31;
}

void TObjMotion::sub_800E2DE4(s32 arg1) {
  s32 *new_var;
  int new_var2;
  new_var2 = ~arg1;
  new_var = (s32 *) (((s8 *) this) + 0xB0);
  *new_var = (s32) ((this->animationFlags) & new_var2);
}

u8 is_phase_12__14TObjEnePanarmsFPv(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x378) == 0xC);
}

u8 check_can_attack__14TObjEnePanarmsFPv(void *arg0) {
    int var_r31;

    var_r31 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 0) && (TObjEnePanarms__sub_800DFB44(*(s32 *)((s8 *)arg0 + 0x3A0)) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

u8 TObjEnePanarms__sub_800E2E54(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x378) == 0xD);
}

u8 TObjEnePanarms__sub_800E2E68(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x378) == 0xE);
}

u8 is_below_half_hp__14TObjEnePanarmsFPv(void *arg0) {
    s32 var_r31;

    var_r31 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x380) == 0) && (TObjEnePanarms__sub_800DFB44(*(s32 *)((s8 *)arg0 + 0x3A0)) == 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x3C0) == 0) && ((s16) *(s16 *)((s8 *)arg0 + 0x32C) <= (s32) ((s32) *(s32 *)((s8 *)arg0 + 0x3BC) / 2))) {
        var_r31 = 1;
    }
    return var_r31;
}

#pragma push
#pragma fp_contract on
void TObjEnePanarms::set_random_action_timer(int minimum, int range) {
    action_timer = (s32)((f32)range * calc_boss4_scale__10TObjPlayerFi(this) + (f32)minimum);
}
#pragma pop

int TObjEnePanarms::find_nearest_enemy_with_flag_alt_target(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    u16 temp_r3;
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    temp_r3 = find_nearest_hittable_enemy__10TObjPlayerFiPvf((void *)arg0, (void *)arg1, (f32)farg0);
    this->actorFlags = (s32) (this->actorFlags & 0xFDFFFFFF);
    return temp_r3;
}

s32 TObjEnePanarms__sub_800E2FB4(O_800E2FB4 *self) {
    return self->state == 9 || self->state == 11;
}

int clear_render_callback__8TObjFishFv(void) { return set_global_state__16TObjEneRe7BeruraFl((void*)(0)); }
}
