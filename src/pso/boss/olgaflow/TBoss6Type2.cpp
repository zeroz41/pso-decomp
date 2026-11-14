#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include <stddef.h>
#include "pso/boss/olgaflow/TBoss6EffHyoui.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/boss/olgaflow/Boss6Type2Data.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/olgaflow/TBoss6SwordWave.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/boss/darkfalz/TObjDFJisin.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/object/ambient/TObjFish.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);

struct TBoss6Type2_802BD014;
typedef void (TBoss6Type2_802BD014::*Fn_802BD014)();
struct Boss_802B9C80;
struct T2_802BB498;
struct T2_802BB554;
struct Obj_802BCD2C;
struct Tb_802BD0C8 { s32 f0; s32 f4; s32 f8; Fn_802BD014 fn; Fn_802BD014 fn2; Fn_802BD014 fn3; };

struct Ent_802BCEF4 { s32 f0; u8 pad4[4]; f32 f8; u8 padC[8]; s32 f14; u8 pad18[4]; };

struct O_802BCEF4 { u8 pad[0x3FC]; s32 model; u8 pad400[0x498 - 0x400]; Ent_802BCEF4 ents[1]; };

struct Tb_802BCEF4 { u8 pad[8]; s32 v[1]; };

struct Hit_802BBAB0 { s32 x; f32 y; };

struct VBase_18_b27ba1 { char pad[0x18]; };

struct VObj_18_b27ba1 : VBase_18_b27ba1 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual s32 m21(void *, Hit_802BBAB0 *, s32, s32, s32);
};

struct Vec_802BBAB0 { f32 x, y, z; };

struct Obj_802BBAB0 {
    u8 pad0[0x3C];
    f32 f3C;
    u8 pad40[0x418 - 0x40];
    s32 f418;
    u8 pad41C[0x4B4 - 0x41C];
    s32 f4B4;
    u8 pad4B8[0x4E8 - 0x4B8];
    f32 f4E8;
    u8 pad4EC[0x59C - 0x4EC];
    Vec_802BBAB0 rock[19];
    Vec_802BBAB0 v680[1];
};

struct Prm_802BCAB8 { s32 a; s32 c; f32 b; f32 d; };

struct Ent_802BCAB8 { s32 a; s32 b; };

struct Obj_802BCAB8 { u8 pad[0x400]; Ent_802BCAB8 ents[2]; };

struct Vec_802BAD90 { f32 x, y, z; };

struct T2_802BA000;
struct Obj_802BC050;
struct T2_802BB768;
struct Obj_802B9D6C;
struct O_802BCEF4;
struct VBase_18_802BE0D4 { char pad[0x18]; };

struct VObj_18_802BE0D4 : VBase_18_802BE0D4 {
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
    virtual s32 m79(void *);
};

struct Tmp_802BE0D4 { s32 a; s16 b; s16 c; u8 pad[0x10]; };

struct Ent_802BE0D4 { s32 a; s32 b; };

struct Ents_802BE0D4 { u8 pad[0x400]; Ent_802BE0D4 ents[2]; };

struct Arr_802BE0D4 { u8 pad[0x378]; s32 arr[32]; };

union TypedVector_802BA6DC {
    struct { f32 x, y, z; } f;
    struct { s32 x, y, z; } bits;
};

union TypedVector_802BAA74 {
    struct { f32 x, y, z; } f;
    struct { s32 x, y, z; } bits;
};

extern "C" {
s32 get_bml_model(s32, s32);
s32 submit_cursor_candidate(void *, int);
s32 add_radar_scaled_marker(void *, int, int, int, f32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id);
void TBoss6Type2__sub_802BA7BC(u8 *o);
void TBoss6Type2__sub_802BBE20(void *);
s32 get_bml_motion(int, int);
extern s32 TBoss6Type2__motion_table[];
extern const s32 TBoss6Type2__data_805DE4B8;
u8 * get_player_by_client_id(u32);
s32 is_active__14TBoss6PlotFalzFv();
f32 xyz_distance(void *, void *);
void TBoss6Type2__sub_802BA598(TBoss6Type2 *self, s32 elapsed, s32 duration);
}
void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0);
extern "C" {
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
u8 * get_player_data__10TObjPlayerFi(s32);
void spawn__15TBoss6RockChaseFll(void *, void *);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 TObjFish__sub_800E3124(u8 *list, s32 vecs);
s32 init_collision_body_parts(void *, void *, int);
void build_tables__14TBoss6PlotFalzFPvPvi(void *, void *, int);
void TBoss6Type2__sub_802BA7B0(void* p);
s32 TBoss6Type2__sub_802BB694(TBoss6Type2 *self);
void TBoss6Type2__sub_802BB818(TBoss6Type2 *self, f32);
void TBoss6Type2__sub_802BBC74(TBoss6Type2 *self);
u16 TBoss6PlotFalz__sub_802AAE48(s32 i);
void TBoss4DarkFalz__sub_8004B4F0(void *dst, void *src);
void TBoss6Rock__sub_80354A44(void);
void *__dt__9TObjEnemyFv(TObjEnemy *self, s16 flag);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
s32 __dt__11TBoss6Type2Fv(s32 self_, s16 flag);
struct AttackMsg_802BD430 { s32 type; s32 value; };
f32 receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void *self, void *attacker, AttackMsg_802BD430 msg, void *collision, s32 tech, s32 arg5);
f32 vfunc_23__11TBoss6Type2FPvPvPvll(TBoss6Type2 *self, void *attacker, AttackMsg_802BD430 msg, void *collision, s32 tech, s32 arg5);
void set_screen_pos__11TBoss6Type2FPv(void *arg0);
void TBoss6Type2__sub_802BE4E0(s32 *arg0, s32 *arg1);
s32 create_zanzo__11TBoss6Type1FPvPvPv(void *, int, int);
extern u8 boss6_type2_collision_parts[];
extern u8 __vt__11TBoss6Type2[];
s32 TBoss6Type2__ct(s32 arg0_, s32 arg1, s32 arg2_);
void TBoss6Type2__sub_802BD938(u8 *arg0, u8 *arg1);

f64 atan2_float(f32, f32);
struct Stack_802B9D90
{
  s32 sp8;
  s32 spC;
};

struct Obj_802B9D6C { u8 pad[0x77c]; s32 arr[14]; };

struct Obj_802BA158 { u8 pad[0x55c]; u16 f55c; u8 pad2[0x570 - 0x55e]; s32 f570; u8 pad3[0x58c - 0x574]; s32 f58c; s32 f590; s32 f594; s32 f598; };

struct V3_802B9C00 { s32 x, y, z; };

struct T1_802B9C00 {
    u8 pad0[0x38];
    V3_802B9C00 pos;
};



struct Player_802B9A68 { u8 pad[0x38]; Vec_802B9A68 pos; };


struct Boss_802B9F3C {
    u8 pad0[0x38];
    Vec_802B9A68 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0x544 - 0x64];
    Ent_802B9F3C e[2];
};

struct V3_802BA078 { s32 x; f32 y; s32 z; };

struct Player_802BA078 { u8 pad0[0x30]; s32 f30; u8 pad34[4]; V3_802BA078 pos; };

struct Boss_802BA078 { u8 pad0[0x4B8]; s32 f4B8; u8 pad4BC[0x55C - 0x4BC]; u16 f55C; };

struct Ent_802B9B20 { u8 pad[0x18]; u32 flags; u8 pad1C[0x2C - 0x1C]; };

struct Boss_802B9B20 { u8 pad[0xA4]; Ent_802B9B20 *list; };

struct Vec_802B9C80 { f32 x, y, z; };

struct Tb_802B9C80 { s32 a; s32 b; };

struct Boss_802B9C80 {
    u8 pad0[0x38];
    Vec_802B9C80 pos;
    u8 pad44[0x77C - 0x44];
    u32 arr[14];
};

struct E_802B9EE4 { s32 *p; s32 a; s32 b; };

struct T2_802B9EE4 { u8 pad0[0x53C]; E_802B9EE4 e[2]; };

struct O_802BA000 { s32 h; s32 y; };

struct T2_802BA000 {
    u8 pad0[0x404];
    O_802BA000 o[2];
    u8 pad414[0x53C - 0x414];
    E_802B9EE4 e[2];
};

typedef struct Stack_802B9D90 Stack_802B9D90;

typedef struct Vec_802BA3B4 { f32 x, y, z; } Vec_802BA3B4;

struct Ent_802BA7BC { s32 idx; s32 arg; f32 lo; };

struct T2_802BA9E4 { u8 pad0[0x38]; u8 f38[0x438]; s32 f470; };

struct Boss_802BA944 { u8 pad[0x4BC]; u32 f4BC; };

struct RecoveredGlobal_802BB180_lbl_804DFAC4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_802BB180_lbl_804DFAD0 {
    s32 value;
    u8 remaining[0x8];
};

struct T2_802BB498 { u8 pad0[0x374]; s32 f374; };

struct T2_802BB554 { u8 pad0[0x374]; s32 f374; };

struct T2_802BB768 { u8 pad0[0x410]; u32 f410; u32 f414; };

struct T2_802BB7C0 { u8 pad0[0x410]; u32 f410; u32 f414; };

struct Ent_802BBD88 { u8 pad0[0x18]; u32 f; u8 pad1c[0x10]; };

struct T1_802BBD88 { u8 pad0[0xA4]; Ent_802BBD88 *p; };

struct V_802BBF54 { f32 x, y, z; };

struct Ent_802BC050 { s16 f0; s16 v[5]; };

struct Obj_802BC050 {
    u8 pad0[0x31C];
    Ent_802BC050 *ent;
    u8 pad320[0x434 - 0x320];
    Ent_802BC050 local;
    u8 pad440[0x454 - 0x440];
    s16 max;
    s16 min;
};

struct Vec_802BAB80 { f32 x, y, z; };

struct Obj_802BAB80 { u8 pad[0x38]; Vec_802BAB80 pos; };

struct Vec_802BB920 { f32 x, y, z; };

typedef char RecoveredGlobal_802BB180_lbl_804DFAC4_size[sizeof(RecoveredGlobal_802BB180_lbl_804DFAC4) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_802BB180_lbl_804DFAD0_size[sizeof(RecoveredGlobal_802BB180_lbl_804DFAD0) == 0xC ? 1 : -1];



struct ByteBlock_C { u8 bytes[0xc]; };

struct Stack_802BDDF8 {
    s32 sp8;
    s8 spC;
    u8 trailing_storage[0xF];
};


struct RecoveredFields_802BC754_arg0 {
    u8 unknown_0[0x4B4];
    s32 field_4B4;
    s32 field_4B8;
    s32 field_4BC;
    s32 field_4C0;
    s32 field_4C4;
    s32 field_4C8;
    s32 field_4CC;
    s32 field_4D0;
    s32 field_4D4;
    f32 field_4D8;
    f32 field_4DC;
    f32 field_4E0;
    f32 field_4E4;
    f32 field_4E8;
    s32 field_4EC;
};

struct RecoveredFields_802BC754_temp_r3 {
    u8 unknown_0[0x4];
    f32 field_4;
    u8 unknown_8[0x8];
    f32 field_10;
    f32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2C;
};

struct RecoveredFields_802BC754_temp_r3_3 {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
};

struct RecoveredFields_802BC754_temp_r3_4 {
    u8 unknown_0[0x8];
    f32 field_8;
    f32 field_C;
};

struct Stack_802BD938 {
    u8 sp8;
    u8 sp9;
    u8 pad_A[0x2];
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
};



struct Obj_8004D8C8 { u8 pad[0x2D4]; u16 f2d4; u16 f2d6; };

struct V_802BD378 { f32 x, y, z; };

struct T2_802BD378 { u8 pad0[0x60]; s32 f60; u8 pad64[0x59C - 0x64]; V_802BD378 v[1]; };

struct T1_802BD68C {
    u8 pad0[0x378];
    s32 v[0x20];
};

struct T2_802BD76C { u8 pad0[0x42C]; s32 f42C; };

struct TBoss6Type2_802BD014;

typedef void (TBoss6Type2_802BD014::*Fn_802BD014)();

struct Tb_802BD014 { s32 f0; s32 f4; s32 f8; Fn_802BD014 fn; u8 pad[0x30 - 0x18]; };

struct TBoss6Type2_802BD014 {
    u8 pad0[0x374];
    s32 a[33];
    u8 pad3F8[0x474 - 0x3F8];
    s32 f474;
};

struct Pkt_802BDD6C { u8 d[0x18]; };


typedef char RecoveredFields_802BC754_arg0_4B4_offset[offsetof(RecoveredFields_802BC754_arg0, field_4B4) == 0x4B4 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4B8_offset[offsetof(RecoveredFields_802BC754_arg0, field_4B8) == 0x4B8 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4BC_offset[offsetof(RecoveredFields_802BC754_arg0, field_4BC) == 0x4BC ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4C0_offset[offsetof(RecoveredFields_802BC754_arg0, field_4C0) == 0x4C0 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4C4_offset[offsetof(RecoveredFields_802BC754_arg0, field_4C4) == 0x4C4 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4C8_offset[offsetof(RecoveredFields_802BC754_arg0, field_4C8) == 0x4C8 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4CC_offset[offsetof(RecoveredFields_802BC754_arg0, field_4CC) == 0x4CC ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4D0_offset[offsetof(RecoveredFields_802BC754_arg0, field_4D0) == 0x4D0 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4D4_offset[offsetof(RecoveredFields_802BC754_arg0, field_4D4) == 0x4D4 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4D8_offset[offsetof(RecoveredFields_802BC754_arg0, field_4D8) == 0x4D8 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4DC_offset[offsetof(RecoveredFields_802BC754_arg0, field_4DC) == 0x4DC ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4E0_offset[offsetof(RecoveredFields_802BC754_arg0, field_4E0) == 0x4E0 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4E4_offset[offsetof(RecoveredFields_802BC754_arg0, field_4E4) == 0x4E4 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4E8_offset[offsetof(RecoveredFields_802BC754_arg0, field_4E8) == 0x4E8 ? 1 : -1];

typedef char RecoveredFields_802BC754_arg0_4EC_offset[offsetof(RecoveredFields_802BC754_arg0, field_4EC) == 0x4EC ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_4_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_4) == 0x4 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_10_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_10) == 0x10 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_14_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_14) == 0x14 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_18_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_18) == 0x18 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_1C_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_1C) == 0x1C ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_20_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_20) == 0x20 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_24_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_24) == 0x24 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_28_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_28) == 0x28 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_2C_offset[offsetof(RecoveredFields_802BC754_temp_r3, field_2C) == 0x2C ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_3_0_offset[offsetof(RecoveredFields_802BC754_temp_r3_3, field_0) == 0x0 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_3_4_offset[offsetof(RecoveredFields_802BC754_temp_r3_3, field_4) == 0x4 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_3_8_offset[offsetof(RecoveredFields_802BC754_temp_r3_3, field_8) == 0x8 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_3_C_offset[offsetof(RecoveredFields_802BC754_temp_r3_3, field_C) == 0xC ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_4_8_offset[offsetof(RecoveredFields_802BC754_temp_r3_4, field_8) == 0x8 ? 1 : -1];

typedef char RecoveredFields_802BC754_temp_r3_4_C_offset[offsetof(RecoveredFields_802BC754_temp_r3_4, field_C) == 0xC ? 1 : -1];


struct Boss_802BC23C {
    u8 pad[0x418];
    s32 f418;
    u8 pad41c[0x4CC - 0x41C];
    s32 f4cc;
    s32 f4d0;
};

f32 receive_physical_attack__9TObjCharaFPvf(void *, u32, f32);
u8 * get_attribute_entry__10TObjPlayerFl(u32, s32);
u16 obj_getArrU16_FC(void *obj, s32 i);
u16 get_entity_id(void *);
s32 is_split_screen();
void request_follow_camera_offsets(void *arg0, void *arg1, u16 arg2);
s32 __ct__11TObjControlFP7TObject(s32, s32);
s32 mem_free(s32 *);
s32 * mem_alloc(s32);
s32 project_actor_to_ground(void *, void *, int);
s32 __nw__7TObjectFUl(s32);
int pick_random_active_player__14TBoss6PlotFalzFv(void*);
s32 is_state_1f__14TBoss6PlotFalzFUi(void *);
f32 TBoss6PlotFalz__sub_802AB684(void *);
void TBoss6PlotFalz__sub_802AC724(void *, void *);
void world_to_grid_pos__11TBoss6Type2FPvPvPv(f32 *arg0, s8 *arg1, s8 *arg2);
void grid_to_world_pos__11TBoss6Type2FccPv(s8 arg0, s8 arg1, f32 *arg2);
void init_parts__11TBoss6Type2FPv(s32 arg0);
void TBoss6Type2__sub_802B9D6C(Obj_802B9D6C *self);
void aim_toward_point__11TBoss6Type2FPv(Boss_802B9F3C *arg0, Vec_802B9A68 *arg1);
void reset_fish_fields__11TBoss6Type2Fv(Obj_802BA158 *self);
void restore_target_player_state__11TBoss6Type2Fv(u8 *arg0);
s32 grab_player__11TBoss6Type2FPvUs(u8 *arg0, u16 arg1);
s32 TBoss6Type2__sub_802BA944(Boss_802BA944 *o);
s32 TBoss6Type2__sub_802BA9E4(T2_802BA9E4 *arg0);
s32 snap_to_ground__11TBoss6Type2FPv(Obj_802BAB80 *self);
void TBoss6Type2__sub_802BAD04(s32 arg0);
struct Obj_802BB1E0 { u8 pad0[0x38]; Vec_802B9A68 pos; };
s32 request_player_camera_offsets__11TBoss6Type2FPvff(Obj_802BB1E0 *, f32, f32);
f32 fabs_float(f32);
int TBoss6Type2__sub_802BB4DC(void* p);
void TBoss6Type2__sub_802BB5B4(TBoss6Type2 *self, u16 *first, u16 *second);
void TBoss6Type2__sub_802BB768(T2_802BB768 *arg0);
void TBoss6Type2__sub_802BB7C0(T2_802BB7C0 *arg0);
u8 is_active__11TBoss6Type2Fv(void *arg0);
s32 calc_field4f0_delta__11TBoss6Type2FPv(void *arg0);
void TBoss6Type2__sub_802BCC54(void *, int);
Blk_802BCFD4 * copy_block__11TBoss6Type2FPvPv(Blk_802BCFD4 *d, const Blk_802BCFD4 *s);
void TBoss6Type2__sub_802BD340(void);
void TBoss6Type2__sub_802BD378(T2_802BD378 *arg0, s32 arg1, void *arg2, s32 *arg3);
f32 TBoss6Type2__vt20(TBoss6Type2 *arg0, u32 arg1, f32 farg0);
void TBoss6Type2__vt61(void* p);
void TBoss6Type2__vt60(TBoss6Type2 *arg0);
void TBoss6Type2__vt42(void);
void TBoss6Type2__vt43(void);
void TBoss6Type2__vt44(void);
void TBoss6Type2__vt45(void);
void TBoss6Type2__vt46(void);
void TBoss6Type2__vt47(void);
void TBoss6Type2__vt48(void);
void TBoss6Type2__sub_8032E708(void *p, s32 v);
s32 set_action_field_0x408__11TBoss6Type2Fs(s32, u16);
s32 TBoss6Type2__sub_80356E50(s32 *, s32, s32);
s32 spawn_flow_soul__11TBoss6Type2Fiii(s32 arg0, s32 arg1, s32 arg2);
f32 vec3_add_to(void *, void *);
f32 vector_length(Vec_802B9A68 *);
void subtract_vector(Vec_802B9A68 *, Vec_802B9A68 *);
f32 normalize_vector(void *);

extern RecoveredGlobal_802BB180_lbl_804DFAC4 lbl_804DFAC4;
extern RecoveredGlobal_802BB180_lbl_804DFAD0 lbl_804DFAD0;
extern Tb_802BD014 lbl_804E00DC[];
extern s32 local_client_id;
extern s32 game_difficulty_selection;
extern s32 tl_04;

extern "C" {
Blk_802BCFD4 *copy_block__11TBoss6Type2FPvPv(Blk_802BCFD4 *d, const Blk_802BCFD4 *s);
}

// Read by the TBoss6Type2_802BE588/_802BF558 units and TBoss6Rock; emitted ahead of the literal pool.
extern const f32 lbl_805DE3F0 = 400.0f;
extern const f32 lbl_805DE3F4 = 0.2f;
extern const f32 lbl_805DE3F8 = 0.35f;
extern const f32 lbl_805DE3FC = 0.42f;
extern const f32 lbl_805DE400 = 0.5f;
extern const f32 lbl_805DE404 = 0.6f;
extern const f32 lbl_805DE408 = 0.6f;

extern const s32 boss6_type2_hit_check_value_table[] = { 1, 13, 24, 26 };
extern const Ent_802BA7BC boss6_type2_motion_param_table[] = {
    { 3, 3, 11.0f }, { 4, 4, 9.0f }, { 5, 5, 5.0f }, { 8, 0, 11.0f }, { 9, 1, 9.0f }, { 10, 2, 5.0f },
};
extern const s32 boss6_type2_hit_effect_node_table[] = { 4, 9, 11, 0 };


void TBoss6Type2::draw() {
    if (*(u16 *)((s8 *)this + 0x55C) != 65535) {
        push_matrix();
        post_translate_matrix((const f32 *)((char *)this + 1568));
        rotate_matrix_y(NULL, this->m_60);
        boss6type2_draw_models((s32)((char *)this + 1396), (s32)((char *)this + 1404), (s32)((char *)this + 1412), *(u32 *)((s8 *)this + 0x58C), *(u32 *)((s8 *)this + 0x590), *(u32 *)((s8 *)this + 0x594), *(u32 *)((s8 *)this + 0x598), *(s32 *)((s8 *)this + 0x570), 1.0f);
        pop_matrix();
    }
}

void TBoss6Type2::render_body_effects() {
    s32 var_r31;

    sum_offsets();
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix((const f32 *)((u8 *)this + 0x38));
    rotate_matrix_y(NULL, this->m_60);
    var_r31 = 0;
    if ((0.0f == this->state_progress) || (1.0f == this->state_progress)) {
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        TBoss6PlotFalz__sub_802AC008(*(f32 *)&this->unk_4FC, this->m_500);
    }
    this->draw_body_models();
    if (var_r31 != 0) {
        TBoss6PlotFalz::update_camera_target();
    }
    pop_matrix();
    TParticleCtrl::end_effect_render();
    this->restore_effect_values();
}

void TBoss6Type2::render() { render_body_effects(); draw(); }

s32 TBoss6Type2::get_phase() { return this->m_37c; }

void world_to_grid_pos__11TBoss6Type2FPvPvPv(f32 *arg0, s8 *arg1, s8 *arg2) {
    f32 fa = 0.5f + ((arg0[0] - -10500.0f) / 7.874016f);
    f32 fb = 0.5f + ((arg0[2] - -500.0f) / 7.874016f);
    *arg1 = (s8)fa;
    *arg2 = (s8)fb;
}

void grid_to_world_pos__11TBoss6Type2FccPv(s8 arg0, s8 arg1, f32 *arg2) {
    arg2[0] = (f32)((7.874016f * (f32)arg0) + -10500.0f);
    arg2[1] = 0.0f;
    arg2[2] = (f32)((7.874016f * (f32)arg1) + -500.0f);
}

void TBoss6Type2::call_9A24_plus_1(s32 *arg1) {
    u8 *arg0 = (u8 *)this;
    ((TBoss6Type2 *)(arg0 + 1))->unpack_path_entry(arg1);
}

void TBoss6Type2::unpack_path_entry(s32 *arg1) {
    u8 *arg0 = (u8 *)this;
    *arg1 = (s32) (s16) ((s8) *(u8 *)((s8 *)arg0 + 2) << 8);
    ((s32 (*)(int, int, void *, void *))grid_to_world_pos__11TBoss6Type2FccPv)((int) (*(u8 *)((s8 *)arg0 + 0)), (int) (*(u8 *)((s8 *)arg0 + 1)), (void *) ((u8 *) arg1 + 4), arg0);
}

s32 TBoss6Type2::is_player_in_rock_area(s32 id) {
    Vec_802B9A68 a;
    Vec_802B9A68 b;
    f32 r;
    Player_802B9A68 *p;
    s32 i;
    f32 k;
    p = ((Player_802B9A68 *)get_player_by_client_id((u32)((u16)id)));
    if (p == NULL) {
        return 0;
    }
    i = 0;
    k = 0.0f;
    do {
        if (TBoss6Rock__sub_80353A14(i, (Vec *)&a, &r) != 0) {
            VecCopy((Vec *)&b, (const Vec *)&p->pos);
            subtract_vector(&b, &a);
            b.y = k;
            if (vector_length(&b) <= r) {
                return 1;
            }
        }
        i++;
    } while (i < 0x20);
    return 0;
}

void TBoss6Type2::spawn_hit_effects() {
    Boss_802B9B20 *o = (Boss_802B9B20 *)this;
    s32 found = 0;
    Ent_802B9B20 *e;
    s32 i;
    Ent_802B9B20 *t = *(Ent_802B9B20 * *)&this->m_a4;
    if (t != NULL) {
        e = t;
        for (i = 0; i < 3; i++, e++) {
            if (e->flags & 0x04000000) {
                spawn_particle_effect(((u8 *)o + boss6_type2_hit_effect_node_table[i] * 0xC + 0x59C), 0x223);
                found = 1;
            }
        }
    }
    if (found == 0) {
        spawn_particle_effect(((u8 *)o + 0x2FC), 0x223);
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::destroy_part(s32 arg1) {
    s32 arg0 = (s32)this;
    u32 temp_r3;
    u8 *temp_r31;
    temp_r31 = (u8 *)(arg0 + (arg1 * 4));
    temp_r3 = *(u32 *)((s8 *)temp_r31 + 0x77C);
    if (temp_r3 != 0U) {
        TParticleCtrl::release((void *)temp_r3);
        *(u32 *)((s8 *)temp_r31 + 0x77C) = 0U;
    }
}
#pragma pop

void TBoss6Type2::spawn_particle_slot(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 *p = arg0 + arg1 * 4;
    if (*(u32 *)(p + 0x77C) == 0U) {
        V3_802B9C00 v = ((T1_802B9C00 *)arg0)->pos;
        *(u32 *)(p + 0x77C) = (u32)create_particle_emitter(&v, TBoss6Type2__particle_attachment_table[arg1].a);
        if (*(u32 *)(p + 0x77C) != 0U) {
            ((TParticleCtrl *)(*(u32 *)(p + 0x77C)))->set_flags(0x40);
        }
    }
}

void TBoss6Type2::update_part_positions() {
    Boss_802B9C80 *o = (Boss_802B9C80 *)this;
    s32 i = 0;
    do {
        Vec_802B9C80 v = o->pos;
        const Tb_802B9C80 *e = &((const Tb_802B9C80 *)TBoss6Type2__particle_attachment_table)[i];
        if (o->arr[i] != 0) {
            s32 idx = e->b;
            if (idx >= 0) {
                VecCopy((Vec *)((Vec_802B9A68 *)(&v)), (const Vec *)((Vec_802B9A68 *)((Vec_802B9C80 *)((u8 *)o + idx * 0xC + 0x59C))));
            }
            ((TParticleCtrl *)(s32)o->arr[i])->set_position(&v);
        }
        i++;
    } while (i < 14);
}

void init_parts__11TBoss6Type2FPv(s32 arg0) {
    s32 var_r31;
    var_r31 = 0;
    do {
        ((TBoss6Type2 *)arg0)->destroy_part(var_r31);
        var_r31 += 1;
    } while (var_r31 < 0xE);
}

void TBoss6Type2__sub_802B9D6C(Obj_802B9D6C *self) {
    s32 i;
    for (i = 0; i < 14; i++) self->arr[i] = 0;
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::update_footstep_effects() {
    u8 *arg0 = (u8 *)this;
  Stack_802B9D90 stack;
  s32 temp_r4;
  s32 var_r30;
  u8 *temp_r29;
  s32 var_r28;
  static f32 foot_lift_height = 7.5f;
  static f32 footstep_height_threshold = 5.0f;
  stack.sp8 = (long) (((u8 *) arg0) + 0x614);
  var_r28 = 0;
  var_r30 = 0;
  stack.spC = (long) (((u8 *) arg0) + 0x5D8);
  do
  {
    temp_r4 = var_r30 + 0x554;
    if (((s32) (*((s32 *) (((s8 *) (((u8 *) arg0) + temp_r4)) + 0)))) != 0)
    {
      if ((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) (((u8 *)&stack.sp8) + var_r30)) + 0)))) + 4))) > foot_lift_height)
      {
        *((s32 *) (((s8 *) (((u8 *) arg0) + temp_r4)) + 0)) = 0;
      }
    }
    else
    {
      temp_r29 = (u8 *) (*((u8 **) (((s8 *) (((u8 *)&stack.sp8) + var_r30)) + 0)));
      if ((*((f32 *) (((s8 *) temp_r29) + 4))) < footstep_height_threshold)
      {
        *((s32 *) (((s8 *) (((u8 *) arg0) + temp_r4)) + 0)) = 1;
        ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x4006A300, (u32) temp_r29, 0, 0);
        spawn_particle_effect_with_flags(temp_r29, 0x220, 0x40);
        if (((s32)this->m_418) == 0)
        {
          spawn_particle_effect(temp_r29, 0x222);
        }
        else
        {
          spawn_particle_effect_with_flags(temp_r29, 0x229, 0x2000);
        }
        TBoss6PlotFalz::apply_radial_effect_to_players((void *)temp_r29, (s16)0xC0, (s16)0xF, 200.0f);
      }
    }
    var_r28 += 1;
    var_r30 += 4;
  }
  while (var_r28 < 2);
}
#pragma pop

void TBoss6Type2::set_fields_554() { *(s32*)((char*)this + 0x554) = 1; *(s32*)((char*)this + 0x558) = 1; }

void TBoss6Type2::restore_effect_values() {
    T2_802B9EE4 *arg0 = (T2_802B9EE4 *)this;
    s32 i;
    for (i = 0; i < 2; i++) {
        *arg0->e[i].p = arg0->e[i].a;
    }
}

void TBoss6Type2::sum_offsets() {
    T2_802B9EE4 *arg0 = (T2_802B9EE4 *)this;
    s32 i;
    for (i = 0; i < 2; i++) {
        *arg0->e[i].p = arg0->e[i].a + arg0->e[i].b;
    }
}

void TBoss6Type2::aim_toward_point(void *arg1_arg) {
    Boss_802B9F3C *arg0 = (Boss_802B9F3C *)this;
    Vec_802B9A68 *arg1 = (Vec_802B9A68 *)arg1_arg;
    Vec_802B9A68 v;
    s32 ang;
    s32 i;
    if (arg1 == NULL) {
        ang = 0;
    } else {
        VecCopy((Vec *)&v, (const Vec *)arg1);
        subtract_vector(&v, &arg0->pos);
        ang = (s16)((s32)(10430.38043493439 * atan2_float(v.x, v.z)) - this->m_60);
    }
    if (ang < -0x2800 || ang > 0x2800) {
        ang = 0;
    }
    for (i = 0; i < 2; i++) {
        arg0->e[i].a = approach_angle_limited(arg0->e[i].a, ang, 0x2AA);
    }
}

void TBoss6Type2::init_collected_entries() {
    T2_802BA000 *arg0 = (T2_802BA000 *)this;
    s32 i;
    for (i = 0; i < 2; i++) {
        arg0->e[i].p = (s32 *)((u8 *)find_model_node(arg0->o[i].h, 0x28) + 0x18);
        arg0->e[i].a = *arg0->e[i].p;
        arg0->e[i].b = 0;
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::sub_802BA078() {
    Player_802BA078 *p;
    if (((Boss_802BA078 *)this)->f55C != 0xFFFF) {
        p = (Player_802BA078 *)get_player_by_client_id(((Boss_802BA078 *)this)->f55C);
        if (is_active__14TBoss6PlotFalzFv() != 0) {
            s32 r = TBoss6PlotFalz::rand_vary_count(((Boss_802BA078 *)this)->f4B8, 0.1f);
            TBoss6PlotFalz::damage_player_hp(((Boss_802BA078 *)this)->f55C, r);
            p->f30 |= 0x200;
            spawn_particle_effect_with_flags(&p->pos, 0x212, 0x40);
            {
                V3_802BA078 v = p->pos;
                v.y += 10.0f;
                spawn_particle_effect_with_flags(&v, 0x223, 0x40);
            }
            if (this->is_target_valid() == 0) {
                ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x4000AD13, 0, 0, 0);
            }
        }
    }
}
#pragma pop

void TBoss6Type2::reset_fish_fields() {
    ((Obj_802BA158 *)this)->f55c = 0xFFFF;
    ((Obj_802BA158 *)this)->f570 = 0;
    ((Obj_802BA158 *)this)->f58c = 0;
    ((Obj_802BA158 *)this)->f590 = 0;
    ((Obj_802BA158 *)this)->f594 = 0;
    ((Obj_802BA158 *)this)->f598 = 0;
}

void TBoss6Type2::restore_target_player_state() {
    u8 *player;
    u32 id = *(u16 *)((s8 *)((u8 *)this) + 0x55C);
    if (id != 0xFFFF) {
        player = get_player_by_client_id(id);
        if (player == NULL) {
            ((TBoss6Type2 *)((Obj_802BA158 *)this))->reset_fish_fields();
            return;
        }
        ((TBoss6Type2 *)(player + 0xCF4))->copy_vec2((void*)((void *) (((u8 *)this) + 0x574)));
        ((TBoss6Type2 *)(player + 0xB88))->copy_vec2((void*)((void *) (((u8 *)this) + 0x584)));
        *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x58C);
        *(s32 *)((s8 *)player + 0x8B0) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x590);
        *(s32 *)((s8 *)player + 0x8AC) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x594);
        *(s32 *)((s8 *)player + 0x8B4) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x598);
        ((TBoss6Type2 *)((Obj_802BA158 *)this))->reset_fish_fields();
    }
}

void TBoss6Type2::copy_vec2(void* q) { *(u32*)((char*)this + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)this + 0x4) = *(u32*)((char*)q + 0x4); }

s32 grab_player__11TBoss6Type2FPvUs(u8 *arg0, u16 arg1) {
    u8 *temp_r3;
    if ((arg1 == 0xFFFF) || (*(u16 *)((s8 *)arg0 + 0x55C) != 0xFFFF)) {
        return 0;
    }
    temp_r3 = (u8 *)(((u8 * (*)(int))get_player_by_client_id)(arg1));
    if (temp_r3 == NULL) {
        return 0;
    }
    if (*(s32 *)((s8 *)temp_r3 + 0x30) & 0x800) {
        return 0;
    }
    *(u16 *)((s8 *)arg0 + 0x55C) = arg1;
    *(u8 **)((s8 *)arg0 + 0x570) = (unsigned char *) (temp_r3 + 0x85C);
    ((TBoss6Type2 *)(arg0 + 0x574))->copy_vec2(temp_r3 + 0xCF4);
    ((TBoss6Type2 *)(arg0 + 0x57C))->copy_vec2(temp_r3 + 0xA1C);
    ((TBoss6Type2 *)(arg0 + 0x584))->copy_vec2(temp_r3 + 0xB88);
    *(s32 *)((s8 *)arg0 + 0x58C) = (s32) *(s32 *)((s8 *)temp_r3 + 0x34);
    *(s32 *)((s8 *)arg0 + 0x590) = (s32) *(s32 *)((s8 *)temp_r3 + 0x8B0);
    *(s32 *)((s8 *)arg0 + 0x594) = (s32) *(s32 *)((s8 *)temp_r3 + 0x8AC);
    *(s32 *)((s8 *)arg0 + 0x598) = (s32) *(s32 *)((s8 *)temp_r3 + 0x8B4);
    ((TBoss6Type2 *)(temp_r3 + 0xCF4))->copy_vec2((void*)(*(u8 **)((s8 *)arg0 + 0x560)));
    ((TBoss6Type2 *)(temp_r3 + 0xB88))->copy_vec2((void*)(*(u8 **)((s8 *)arg0 + 0x564)));
    *(s32 *)((s8 *)temp_r3 + 0x34) = (s32) *(s32 *)((s8 *)arg0 + 0x568);
    *(s32 *)((s8 *)temp_r3 + 0x8B0) = 0;
    *(s32 *)((s8 *)temp_r3 + 0x8AC) = 0;
    *(s32 *)((s8 *)temp_r3 + 0x8B4) = (s32) *(s32 *)((s8 *)arg0 + 0x56C);
    return 1;
}

s32 TBoss6Type2::check_target() {
    if (this->m_464 == 0xFFFF) {
        return 0;
    }
    if (*(u16 *)((s8 *)this + 0x55C) != 0xFFFF) {
        ((int (*)(void))restore_target_player_state__11TBoss6Type2Fv)();
    }
    if (((int (*)(void*, void*))grab_player__11TBoss6Type2FPvUs)((void*)this, (void*)this->m_464) == 0) {
        this->m_464 = 0xFFFFU;
        return 0;
    }
    return 1;
}

int TBoss6Type2::is_falz_ready() { return pick_random_active_player__14TBoss6PlotFalzFv(this); }

void TBoss6Type2::update_possess_target() {
    Vec_802BA3B4 v;
    u8 *pl;
    s32 done;
    u16 id;
    id = *(u16 *)((s8 *)((u8 *)this) + 0x55C);
    if (id != 0xFFFF) {
        done = 0;
        pl = ((u8 * (*)(u16))get_player_by_client_id)(id);
        if (pl == NULL) {
            done = 1;
        } else if (is_active__14TBoss6PlotFalzFv() == 0) {
            VecCopy((Vec *)&v, (const Vec *)(pl + 0x38));
            v.y += 10.0f;
            spawn_flow_soul__11TBoss6Type2Fiii((s32)this, (s32)&v, 0x1E);
            ((TBoss6EffHyoui *)(*(u16 *)((s8 *)((u8 *)this) + 0x55C)))->create((void *)1, (void *)0x1E);
            if (this->is_target_valid() == 0) {
                play_sound_effect(0x40069E13, ((u8 *)this) + 0x38, 0, 1);
            }
            spawn_particle_effect(pl + 0x38, 0x36);
            done = 1;
        }
        if (done != 0) {
            ((int (*)(void *))restore_target_player_state__11TBoss6Type2Fv)(this);
            this->m_464 = 0xFFFF;
            this->m_428 = this->pick_random_other_index();
            this->m_430 = this->choose_next_index();
        }
        switch (this->m_374) {
        case 0x1A:
            ((int (*)(void *))restore_target_player_state__11TBoss6Type2Fv)(this);
            this->m_464 = 0xFFFF;
            break;
        }
    }
}

void TBoss6Type2::reset_counters() {
    if ((u16) *(u16 *)((s8 *)this + 0x55C) != 0xFFFF) {
        ((s32 (*)(void))restore_target_player_state__11TBoss6Type2Fv)();
    }
    ((s32 (*)(void *))reset_fish_fields__11TBoss6Type2Fv)(this);
    *(s32 *)((s8 *)this + 0x560) = 0;
    *(s32 *)((s8 *)this + 0x564) = 0;
    *(s32 *)((s8 *)this + 0x568) = 0;
    *(s32 *)((s8 *)this + 0x56C) = 0;
}

void TBoss6Type2::cache_fish_params() {
    ((s32 (*)(void))reset_fish_fields__11TBoss6Type2Fv)();
    *(s32 *)((s8 *)this + 0x560) = TObjFish__sub_8001EDB0(this->m_3fc, 0xB);
    *(s32 *)((s8 *)this + 0x564) = TObjFish__sub_8001EDB0(this->m_3fc, 0xA);
    *(s32 *)((s8 *)this + 0x568) = get_bml_model(this->m_3fc, 0xB);
    *(s32 *)((s8 *)this + 0x56C) = get_bml_model(this->m_3fc, 0xA);
}

void TBoss6Type2__sub_802BA598(TBoss6Type2 *self, s32 elapsed, s32 duration) {
    f32 t = 1.0f - (f32)elapsed / (f32)duration;
    f32 u;
    f32 k;
    if (t <= 0.1f) {
        u = 0.0f;
    } else if (t >= 0.7f) {
        u = 1.0f;
    } else {
        u = (t - 0.1f) / (0.7f - 0.1f);
    }
    k = TBoss6PlotFalz::cosine_ease(u);
    VecCopy((Vec *)&self->position, &boss6_arena_center);
    subtract_vector((Vec_802B9A68 *)&self->position, (Vec_802B9A68 *)self->_pad50C);
    self->position.x *= k;
    self->position.y *= k;
    self->position.z *= k;
    vec3_add_to(&self->position, self->_pad50C);
}

void TBoss6Type2::update_zako() { ((int (*)(void*, void*))vec3_add_to)((char*)this + 0x38, (char*)this + 0x524); ((int (*)(void*))snap_to_ground__11TBoss6Type2FPv)(this); }

typedef char TypedVector_802BA6DC_size[(sizeof(TypedVector_802BA6DC) == 12) ? 1 : -1];
void TBoss6Type2::update_lower_contact_delta() {
    TypedVector_802BA6DC sp20;
    TypedVector_802BA6DC sp14;
    TypedVector_802BA6DC sp8;
    s32 var_r31;
    lower_contact_delta.z = 0.0f;
    lower_contact_delta.y = 0.0f;
    lower_contact_delta.x = 0.0f;
    VecCopy((Vec *)(&sp14), (const Vec *)(&contact_point_5fc));
    subtract_vector((Vec_802B9A68 *)(&sp14), (Vec_802B9A68 *)(&position));
    VecCopy((Vec *)(&sp8), (const Vec *)(&contact_point_5c0));
    subtract_vector((Vec_802B9A68 *)(&sp8), (Vec_802B9A68 *)(&position));
    var_r31 = 0;
    VecCopy((Vec *)(&sp20), (const Vec *)(&sp14));
    if (sp14.f.y > sp8.f.y) {
        var_r31 = 1;
        VecCopy((Vec *)(&sp20), (const Vec *)(&sp8));
    }
    if ((s32) lower_contact_index == var_r31) {
        VecCopy((Vec *)(&lower_contact_delta), (const Vec *)(&previous_lower_contact));
        subtract_vector((Vec_802B9A68 *)(&lower_contact_delta), (Vec_802B9A68 *)(&sp20));
        lower_contact_delta.y = 0.0f;
    }
    lower_contact_index = var_r31;
    VecCopy((Vec *)(&previous_lower_contact), (const Vec *)(&sp20));
}

void TBoss6Type2__sub_802BA7B0(void* p) { *(s32*)((char*)p + 0x520) = -1; }

void TBoss6Type2__sub_802BA7BC(u8 *o) {
    f32 k = 20.0f;
    s32 i = 0;
    do {
        const Ent_802BA7BC *e = &boss6_type2_motion_param_table[i];
        f32 lo = e->lo;
        f32 v = *(f32 *)(o + e->idx * 0xC + 0x5A0);
        if (v < lo || v > k + lo) {
            ((TBoss6Type2 *)o)->destroy_part(e->arg);
        } else {
            ((TBoss6Type2 *)o)->spawn_particle_slot(e->arg);
        }
        i++;
    } while (i < 6);
}

s32 TBoss6Type2::is_ready_to_attack() {
    s32 temp;
    if ((s32) this->m_418 != 0) {
        return 0;
    }
    if (is_normal_difficulty() != 0) {
        return 0;
    }
    temp = calc_field4f0_delta__11TBoss6Type2FPv(this);
    return *(s32 *)((s8 *)this + 0x4C0) <= temp ? 1 : 0;
}

s32 TBoss6Type2::is_phase_complete() {
    if ((s32) this->m_418 == 0) {
        return 0;
    }
    if (((s32 (*)(void))calc_field4f0_delta__11TBoss6Type2FPv)() >= (s32) *(s32 *)((s8 *)this + 0x4C4)) {
        return 1;
    }
    if ((TBoss6PlotFalz::get_phase() == 0) && ((s32) this->m_420 >= 8)) {
        return 1;
    }
    return 0;
}

s32 TBoss6Type2__sub_802BA944(Boss_802BA944 *o) {
    s32 i;
    if (((TBoss6Type2 *)o)->count_matching_values(0xE, 3) != 0) {
        return 0;
    }
    i = 0;
    do {
        if (((TBoss6Type2 *)o)->count_matching_values(boss6_type2_hit_check_value_table[i], 2) != 0) {
            return 0;
        }
        i++;
    } while (i < 4);
    return (s32)o->f4BC <= ((TBoss6Type2 *)o)->get_hit_count() ? 1 : 0;
}

s32 TBoss6Type2__sub_802BA9E4(T2_802BA9E4 *arg0) {
    if (arg0->f470 >= 3) {
        return 1;
    }
    return TBoss6PlotFalz__sub_802AB684(arg0->f38) >= 350.0f;
}

void TBoss6Type2::trigger_screen_pos() {
    if (((s32) this->m_424 == 0) && (this->m_500 < 0.33333334f)) {
        this->m_424 = 1;
        ((s32 (*)(void))set_screen_pos__11TBoss6Type2FPv)();
    }
}

typedef char TypedVector_802BAA74_size[(sizeof(TypedVector_802BAA74) == 12) ? 1 : -1];
s32 TBoss6Type2::turn_toward_target_position() {
    s32 var_r31;
    f32 temp_f1;
    s32 temp_r30;
    TypedVector_802BAA74 sp8;
    VecCopy((Vec *)(&sp8), (const Vec *)(&target_position));
    subtract_vector((Vec_802B9A68 *)(&sp8), (Vec_802B9A68 *)(&position));
    sp8.f.y = 0.0f;
    temp_f1 = vector_length((Vec_802B9A68 *)(&sp8));
    if (temp_f1 < 10.0f) {
        return 0;
    }
    if (temp_f1 > 25.0f) {
        var_r31 = 0x1B4;
        if ((s32) m_418 != 0) {
            var_r31 = 0x369;
        }
        temp_r30 = (s32)m_60;
        m_60 = approach_angle_limited((s32)((int) ((s32)m_60)), (s32)((s32) ((s32) (10430.38043493439 * atan2_float(sp8.f.x, sp8.f.z)))), var_r31);
        if (var_r31 == angle_difference_abs(temp_r30, (int) ((s32)m_60))) {
            if ((s32) m_508 == 0) {
                play_sound_effect(0x4006A602, &position, 0, 0);
                m_508 = 1;
            }
        } else {
            m_508 = 0;
        }
    }
    return 1;
}

s32 snap_to_ground__11TBoss6Type2FPv(Obj_802BAB80 *self) {
    Vec_802BAB80 p;
    f32 t;
    VecCopy((Vec *)&p, (const Vec *)&self->pos);
    p.y += 10.0f;
    if (project_actor_to_ground(self, &p, 0) != 0) {
        VecCopy((Vec *)&self->pos, (const Vec *)&p);
        self->pos.y = 0.0f;
        return 0;
    }
    VecCopy((Vec *)&p, (const Vec *)&self->pos);
    p.x -= -10000.0f;
    p.y = 0.0f;
    t = 398.0f;
    {
        Vec_802BAB80 d = p;
        normalize_vector(&d);
        for (; t > 0.0f; t += -2.0f) {
            p.x = t * d.x + -10000.0f;
            p.y = 10.0f + self->pos.y;
            p.z = t * d.z;
            if (project_actor_to_ground(self, &p, 0) != 0) {
                break;
            }
        }
    }
    VecCopy((Vec *)&self->pos, (const Vec *)&p);
    self->pos.y = 0.0f;
    return 1;
}

void TBoss6Type2__sub_802BAD04(s32 arg0) {
    u8 *temp_r3;
    u8 *temp_r3_2;
    TBoss6Type2::create_dpb(arg0, arg0 + 0x38, 150.0f);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x410));
    if ((temp_r3 != NULL) && (((TBoss6Mag *)temp_r3)->is_phase_active() != 0)) {
        TBoss6Type2::create_dpb(arg0, (s32) (*(u8 **)((s8 *)arg0 + 0x410) + 0x38), 100.0f);
    }
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x414));
    if ((temp_r3_2 != NULL) && (((TBoss6Mag *)temp_r3_2)->is_phase_active() != 0)) {
        TBoss6Type2::create_dpb(arg0, (s32) (*(u8 **)((s8 *)arg0 + 0x414) + 0x38), 100.0f);
    }
}

void TBoss6Type2::spawn_rocks_around_players() {
    Vec_802BAD90 p;
    Vec_802BAD90 q;
    s32 n;
    s32 cnt;
    s32 i;
    u8 *pl;
    n = 0;
    cnt = TLobby::get_game_mode();
    for (i = 0; i < cnt; i++) {
        pl = get_player_data__10TObjPlayerFi(i);
        if (is_active__14TBoss6PlotFalzFv() != 0) {
            f32 r = 40.0f * (3.0517578e-05f * (f32)rand()) + 10.0f;
            s32 ang = (s32)(65535.0f * (3.0517578e-05f * (f32)rand()));
            VecCopy((Vec *)&p, (const Vec *)(pl + 0x38));
            p.x += r * sin_table_lookup(ang);
            p.y = 0.0f;
            p.z += r * cos_table_lookup(ang);
            spawn__15TBoss6RockChaseFll(this, &p);
            n++;
        }
    }
    while (n < 10) {
        f32 dx = 283.68796f * (2.0f * (3.0517578e-05f * (f32)rand()) - 1.0f);
        f32 dz = 283.68796f * (2.0f * (3.0517578e-05f * (f32)rand()) - 1.0f);
        VecCopy((Vec *)&q, &boss6_arena_center);
        q.x += dx;
        q.z += dz;
        spawn__15TBoss6RockChaseFll(this, &q);
        n++;
    }
    play_sound_effect(0x4006AB1D, (void *)&boss6_arena_center, 0, 1);
}

void TBoss6Type2::drop_random_rocks(s32 arg0, s32 arg1) {
    s32 avail_tbl[32];
    s32 cnt;
    s32 mult;
    s32 avail;
    s32 i;
    s32 *buf;
    s32 step;
    s32 j;
    s32 k;

    mult = 1;
    cnt = game_difficulty_selection;
    if (TBoss6PlotFalz::get_phase() == 1) {
        mult = 4;
    }
    cnt = (4 - cnt) + mult;
    if (arg1 != 0) {
        cnt *= 2;
    }
    if (cnt < 1) {
        return;
    }
    avail = 0;
    for (i = 0; i < 32; i++) {
        avail_tbl[i] = 0;
        if (TBoss6Rock::is_rock_state_2(i) == 0) {
            avail_tbl[i] = 1;
            avail++;
        }
    }
    if (avail < 1) {
        return;
    }
    if (cnt > avail) {
        cnt = avail;
    }
    buf = mem_alloc(cnt * 4);
    step = (s32)(31.0f * (3.0517578e-05f * (f32)rand()));
    j = 0;
    for (k = 0; k < cnt; k++) {
        j += step;
        if (j >= 32) {
            j = 0;
        }
        while (avail_tbl[j] == 0) {
            j++;
            if (j >= 32) {
                j = 0;
            }
        }
        buf[k] = j;
        avail_tbl[j] = 0;
    }
    TBoss6Type2__sub_80356E50(buf, cnt, arg1);
    mem_free(buf);
    ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4006AB1D, ((void *)&boss6_arena_center), 0, 1);
}

void TBoss6Type2::request_default_follow_camera() {
    request_follow_camera_offsets(&lbl_804DFAC4.value, &lbl_804DFAD0.value, 0xFFFFU);
}

void TBoss6Type2::init_range() {
    ((s32 (*)(f32, f32))request_player_camera_offsets__11TBoss6Type2FPvff)(100.0f, -125.0f);
}

s32 request_player_camera_offsets__11TBoss6Type2FPvff(Obj_802BB1E0 *self, f32 a, f32 b) {
    Vec_802B9A68 pp;
    Vec_802B9A68 me;
    Vec_802B9A68 off;
    Vec_802B9A68 d;
    Vec_802B9A68 cam;
    s32 n;
    s32 i;
    u8 *p;
    s32 flag;
    f32 step;
    f32 t;
    f32 dy;
    f32 k;
    f32 dist;
    f32 sum;
    f32 adj;
    f32 lim;

    n = TLobby::get_game_mode();
    step = 0.125f * b;
    for (i = 0; i < n; i++) {
        lim = fabs_float(b);
        p = get_player_data__10TObjPlayerFi(i);
        if (p == NULL) {
            continue;
        }
        t = 0.0f;
        while (fabs_float(t) <= lim) {
            flag = 0;
            VecCopy((Vec *)&off, (const Vec *)&lbl_80471344);
            VecCopy((Vec *)&pp, (const Vec *)(p + 0x38));
            pp.y += off.y;
            VecCopy((Vec *)&me, (const Vec *)&self->pos);
            me.y += a + t;
            VecCopy((Vec *)&d, (const Vec *)&me);
            subtract_vector(&d, &pp);
            dy = d.y;
            d.y = 0.0f;
            dist = off.z + vector_length(&d);
            if (dist <= 15.0f) {
                dist = 15.0f;
            }
            cam.x = 0.0f;
            cam.z = 55.42f;
            cam.y = 25.43f - dy * cam.z / dist;
            if (cam.y < 10.0f) {
                cam.y = 10.0f;
                if (dy > 1e-05f) {
                    k = 9.799999f * dist;
                    cam.z = k / dy;
                    if (cam.z < 47.92f) {
                        sum = 47.92f + dist;
                        cam.z = 47.92f;
                        dy = 47.92f * dy - k;
                        if (fabs_float(sum) > 1e-05f) {
                            adj = dy / sum;
                            if (adj > 2.5f) {
                                adj = 2.5f;
                                flag = 1;
                            }
                            off.y += adj;
                        }
                    }
                }
            }
            request_follow_camera_offsets(&off, &cam, get_entity_id(p));
            if (flag == 0) {
                break;
            }
            t += step;
        }
    }
}

void TBoss6Type2::sub_802BB498() {
    switch (((T2_802BB498 *)this)->f374) {
    case 0xE:
    case 0x1C:
        TBoss6Type2::request_default_follow_camera();
        break;
    default:
        TBoss6Type2::init_range();
        break;
    }
}

int TBoss6Type2__sub_802BB4DC(void* p) { return ((int (*)(void*, int))aim_toward_point__11TBoss6Type2FPv)(p, 0); }

void TBoss6Type2::update_target() {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(u16))get_player_by_client_id)(this->m_466);
    if (temp_r3 != 0) {
        ((int (*)(void*, int))aim_toward_point__11TBoss6Type2FPv)(this, temp_r3 + 0x38);
        return;
    }
    ((int (*)(void*, int))aim_toward_point__11TBoss6Type2FPv)(this, 0);
}

void TBoss6Type2::sub_802BB554() {
    switch (((T2_802BB554 *)this)->f374) {
    case 3:
    case 6: case 7: case 8: case 9: case 10: case 11:
    case 0x1B: case 0x1C: case 0x1D: case 0x1E: case 0x1F: case 0x20: case 0x21:
        this->update_target();
        break;
    default:
        TBoss6Type2__sub_802BB4DC((void*)(((T2_802BB554 *)this)));
        break;
    }
}

void TBoss6Type2__sub_802BB5B4(TBoss6Type2 *self, u16 *first, u16 *second) {
    s32 count = TBoss6PlotFalz::sort_active_players();
    *first = 0xFFFF;
    *second = 0xFFFF;
    if (count < 1) {
        return;
    }
    if ((s32)self->m_418 == 0) {
        u16 id0 = TBoss6PlotFalz__sub_802AAE48(0);
        u16 id1 = TBoss6PlotFalz__sub_802AAE48(1);
        if (self->m_478 & 1) {
            *first = id0;
            *second = id1;
        } else {
            *first = id1;
            *second = id0;
        }
        if (TBoss6PlotFalz::get_phase() == 0) {
            s8 flags = *(s8 *)&self->m_478;
            if (flags & 2) {
                if (flags & 4) {
                    *first = 0xFFFF;
                } else {
                    *second = 0xFFFF;
                }
            }
        }
    } else {
        *first = *second = TBoss6PlotFalz__sub_802AAE48(count - 1);
    }
}

#pragma push
#pragma optimization_level 2
s32 TBoss6Type2__sub_802BB694(TBoss6Type2 *self) {
    s32 TBoss6PlotFalz__sub_802AAE48(u32 i);
    s32 count = TBoss6PlotFalz::sort_active_players();
    s32 id = 0xFFFF;
    s32 i;
    if (count < 1) {
        return id;
    }
    if ((s32)self->m_418 == 0) {
        for (i = 0; i < count; i++) {
            id = TBoss6PlotFalz__sub_802AAE48(i);
            if (TBoss6Type2::is_player_in_rock_area(id) == 0) {
                break;
            }
        }
        if (i == count) {
            id = 0xFFFF;
        }
    } else {
        for (i = count - 1; i >= 0; i--) {
            id = TBoss6PlotFalz__sub_802AAE48(i);
            if (TBoss6Type2::is_player_in_rock_area(id) == 0) {
                break;
            }
        }
        if (i < 0) {
            id = 0xFFFF;
        }
    }
    return id;
}
#pragma pop

void TBoss6Type2__sub_802BB768(T2_802BB768 *arg0) {
    if (arg0->f410 == 0 || arg0->f414 == 0) {
        return;
    }
    TBoss6Type2__sub_8032E708((void *)arg0->f410, 1);
    TBoss6Type2__sub_8032E708((void *)arg0->f414, 1);
}

void TBoss6Type2__sub_802BB7C0(T2_802BB7C0 *arg0) {
    if (arg0->f410 == 0 || arg0->f414 == 0) {
        return;
    }
    TBoss6Type2__sub_8032E708((void *)arg0->f410, 0);
    TBoss6Type2__sub_8032E708((void *)arg0->f414, 0);
}

struct MagParams_802BB818 {
    s16 x;
    u8 pad02[4];
    u16 z;
    s16 active;
    u8 pad0A[6];
    Vec pos;
    u8 pad1C[0x24];
    TBoss6Type2 *owner;
    Vec origin;
    s32 rotation_y;
    s32 index;
    s32 flags;
    s32 variant;
};

struct Mags_802BB818 { u8 pad[0x410]; TBoss6Type2 *mags[2]; };

extern "C" {
s32 create_mag__11TBoss6Type2Fl(MagParams_802BB818 *params);
}

void TBoss6Type2__sub_802BB818(TBoss6Type2 *self, f32) {
    MagParams_802BB818 params;
    s16 x;
    u16 z;
    s32 i;
    params.owner = self;
    VecCopy(&params.origin, (const Vec *)&self->position);
    params.origin.y += 150.0f;
    params.rotation_y = self->m_60;
    TBoss4DarkFalz__sub_8004B4F0(&params, ((TBoss6Type1 *)self->m_3f8)->get_mag_mine_ptr());
    params.active = 1;
    VecCopy(&params.pos, &params.origin);
    params.flags = self->m_2e4;
    x = params.x;
    z = params.z;
    params.variant = self->m_42c;
    for (i = 0; i < 2; i++) {
        params.index = i;
        params.x = x + lbl_8047133C[i];
        params.z = z + lbl_8047133C[i];
        ((Mags_802BB818 *)self)->mags[i] = (TBoss6Type2 *)create_mag__11TBoss6Type2Fl(&params);
    }
    if (((Mags_802BB818 *)self)->mags[0] == 0 || ((Mags_802BB818 *)self)->mags[1] == 0) {
        return;
    }
    ((Mags_802BB818 *)self)->mags[0]->set_anim_frame((s32)((Mags_802BB818 *)self)->mags[1]);
    ((Mags_802BB818 *)self)->mags[1]->set_anim_frame((s32)((Mags_802BB818 *)self)->mags[0]);
}

s32 TBoss6Type2::push_players_away(void *target, f32 range) {
    Vec_802BB920 dir;
    Vec_802BB920 pos;
    Vec_802BB920 off;
    s32 mask;
    s32 i;
    s32 n;
    u8 *pl;
    f32 t;
    f32 dist;
    mask = 0;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = get_player_data__10TObjPlayerFi(i);
        if (is_state_1f__14TBoss6PlotFalzFUi(pl) == 0) {
            continue;
        }
        VecCopy((Vec *)&dir, (const Vec *)(pl + 0x38));
        ((f32 (*)(void *, void *))subtract_vector)(&dir, target);
        dir.y = 0.0f;
        dist = ((f32 (*)(void *))vector_length)(&dir);
        if (dist >= range) {
            continue;
        }
        if (dist <= 1e-05f) {
            dir.x = 1.0f;
        }
        normalize_vector(&dir);
        for (t = range; t > 5.0f; t -= 5.0f) {
            off.x = dir.x * t;
            off.y = 10.0f;
            off.z = dir.z * t;
            VecCopy((Vec *)&pos, (const Vec *)target);
            vec3_add_to(&pos, &off);
            if (project_actor_to_ground(this, &pos, 0) != 0) {
                TBoss6PlotFalz__sub_802AC724(pl, &pos);
                break;
            }
        }
        mask |= 1 << get_entity_id(pl);
    }
    return mask;
}

void TBoss6Type2::apply_rock_hits_to_players() {
    Hit_802BBAB0 a;
    f32 range;
    s32 r;
    s32 i;
    s32 mask;
    s32 j;
    Vec_802BBAB0 *rock;
    s32 hit;
    VObj_18_b27ba1 *p;
    s32 v;
    range = 10.0f;
    for (i = 0; i < 6; i++) {
        rock = &((Obj_802BBAB0 *)this)->rock[TBoss6Type2__player_hit_rock_indices[i]];
        ((TBoss6Rock *)rock)->break_rocks_in_radius(10.0f);
        if (!(rock->y - ((Obj_802BBAB0 *)this)->f3C > range)) {
            hit = 0;
            if (xyz_distance(rock, &((Obj_802BBAB0 *)this)->v680[TBoss6Type2__player_hit_rock_indices[i]]) >= 1.0f) {
                hit = 1;
            }
            r = this->push_players_away(rock, 10.0f);
            if (hit != 0 && r != 0) {
                for (mask = 1, j = 0; j < 4; j++, mask <<= 1) {
                    if (mask & r) {
                        p = (VObj_18_b27ba1 *)((s32 (*)(s32))get_player_by_client_id)(j);
                        if (((s32 (*)(void *))is_active__14TBoss6PlotFalzFv)(p) != 0) {
                            v = ((Obj_802BBAB0 *)this)->f4B4;
                            if (((Obj_802BBAB0 *)this)->f418 != 0) {
                                v = (s32)((f32)v * ((Obj_802BBAB0 *)this)->f4E8);
                            }
                            s32 rr = TBoss6PlotFalz::rand_vary_count(v, 0.1f);
                            a.x = 0;
                            a.y = rr;
                            Hit_802BBAB0 h = a;
                            p->m21(this, &h, 0, -1, -1);
                        }
                    }
                }
            }
        }
    }
}

void TBoss6Type2__sub_802BBC74(TBoss6Type2 *self) {
    s32 end_angle = 0xFFFF;
    f32 radius = 150.0f;
    s32 start_angle = 0;
    s32 sound = 0x40069E08;
    switch (self->m_374) {
    case 15:
    case 18:
    case 21:
        radius = 839.99994f;
        start_angle = (self->m_60 - 0x1500) & 0xFFFF;
        sound = 0x40069E09;
        end_angle = start_angle + 0x8500;
        break;
    case 16:
    case 19:
    case 22:
        radius = 839.99994f;
        start_angle = (self->m_60 - 0x7000) & 0xFFFF;
        sound = 0x40069E09;
        end_angle = start_angle + 0x8500;
        break;
    case 17:
    case 20:
    case 23:
        break;
    }
    TBoss6SwordWave::create((s32)self, (s32)&self->position, start_angle, end_angle, radius);
    play_sound_effect(sound, &self->position, 0, 1);
}

void TBoss6Type2::set_owner_flag_bit0() {
    void *temp_r3;

    temp_r3 = this->m_a4;
    if (temp_r3 != NULL) {
        *(s32 *)((s8 *)temp_r3 + 0x70) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x70) | 1);
    }
}

void TBoss6Type2::set_child_flags() {
    void *temp_r3;
    void *temp_r4;

    temp_r4 = this->m_a4;
    if (temp_r4 != NULL) {
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) | 1);
        temp_r3 = this->m_a4;
        *(s32 *)((s8 *)temp_r3 + 0x44) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x44) | 1);
    }
}

void TBoss6Type2::clear_part_flags() {
    T1_802BBD88 *arg0 = (T1_802BBD88 *)this;
    Ent_802BBD88 *p = arg0->p;
    if (p != NULL) {
        Ent_802BBD88 *end = (Ent_802BBD88 *)((u8 *)p + 0x84);
        for (; p < end; p++) {
            p->f &= ~1;
        }
    }
}

void TBoss6Type2::update_parts_flags() {
    clear_part_flags();
    if (this->m_474 & 1) {
        set_child_flags();
    }
    if (this->m_474 & 2) {
        set_owner_flag_bit0();
    }
}

struct Vec_802BBE20 { f32 x, y, z; };

struct Ent_802BBE20 { Vec_802BBE20 m; u8 padC[0x1C - 0xC]; Vec_802BBE20 n; u8 pad28[0x2C - 0x28]; };


struct Boss_802BBE20 {
    u8 pad0[0x38];
    Vec_802BBE20 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xA4 - 0x64];
    Ent_802BBE20 *ents;
    u8 padA8[0x59C - 0xA8];
    Vec_802BBE20 rock[19];
};

extern "C" {
s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *arg0);
}

void TBoss6Type2__sub_802BBE20(void *self) {
    Boss_802BBE20 *arg0 = (Boss_802BBE20 *)self;
    Vec_802BBE20 v;
    s32 i;
    Vec_802BBE20 *base;
    Ent_802BBE20 *e;
    if (((TBoss6Type2 *)self)->m_a4 != NULL) {
        for (i = 0; i < 3; i++) {
            const Tbl_802BBE20 *t;
            e = &arg0->ents[i];
            t = &lbl_8047130C[i];
            base = NULL;
            switch (t->kind) {
            case 0:
                base = arg0->rock;
                break;
            }
            if (base == NULL) {
                return;
            }
            VecCopy((Vec *)&v, (const Vec *)&base[t->idx]);
            subtract_vector((Vec_802B9A68 *)&v, (Vec_802B9A68 *)&arg0->pos);
            push_matrix();
            set_matrix_identity(0);
            rotate_matrix_y(0, -((TBoss6Type2 *)self)->m_60);
            matrix_mult_vec(0, &v, e);
            pop_matrix();
            VecCopy((Vec *)&e->n, (const Vec *)e);
            vec3_add_to(&e->n, &arg0->pos);
        }
    }
}

void TBoss6Type2::advance_position() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)&this->unk_2FC, (const Vec *)(arg0 + 0x38));
    this->m_300 += 30.0f;
}

void TBoss6Type2::copy_vec_array() {
    u8 *arg0 = (u8 *)this;
    V_802BBF54 *src;
    V_802BBF54 *end;
    V_802BBF54 *dst;
    src = (V_802BBF54 *)(arg0 + 0x59C);
    dst = (V_802BBF54 *)(arg0 + 0x680);
    end = (V_802BBF54 *)((u8 *)src + 0xE4);
    for (; src < end; src++, dst++) {
        VecCopy((Vec *)dst, (const Vec *)src);
    }
}

void TBoss6Type2::update_segments() {
    s16 temp_r0;

    temp_r0 = this->m_454;
    this->m_43e = temp_r0;
    *(s16 *)&this->unk_43C = temp_r0;
    this->m_43a = temp_r0;
    *(s16 *)&this->unk_438 = temp_r0;
    this->m_436 = temp_r0;
    switch (*(s32 *)&this->m_42c) {
    case 1:
        this->m_436 = (s16) *(s16 *)&this->unk_456;
        break;
    case 2:
        *(s16 *)&this->unk_438 = (s16) *(s16 *)&this->unk_456;
        break;
    case 3:
        this->m_43a = (s16) *(s16 *)&this->unk_456;
        break;
    case 4:
        *(s16 *)&this->unk_43C = (s16) *(s16 *)&this->unk_456;
        break;
    case 5:
        this->m_43e = (s16) *(s16 *)&this->unk_456;
        break;
    }
    this->m_2f2 = (s16) this->m_436;
    *(s16 *)&this->unk_2F4 = (s16) this->m_43a;
    this->m_2f6 = (s16) *(s16 *)&this->unk_438;
    *(s16 *)&this->unk_2F8 = (s16) this->m_43e;
    this->m_2fa = (s16) *(s16 *)&this->unk_43C;
}

void TBoss6Type2::init_segment_range() {
    Obj_802BC050 *o = (Obj_802BC050 *)this;
    Ent_802BC050 *e = *(Ent_802BC050 * *)&this->m_31c;
    s32 min;
    s32 max;
    max = e->v[0];
    min = max;
    if (min > e->v[1]) { min = e->v[1]; } else if (max < e->v[1]) { max = e->v[1]; }
    if (min > e->v[2]) { min = e->v[2]; } else if (max < e->v[2]) { max = e->v[2]; }
    if (min > e->v[3]) { min = e->v[3]; } else if (max < e->v[3]) { max = e->v[3]; }
    if (min > e->v[4]) { min = e->v[4]; } else if (max < e->v[4]) { max = e->v[4]; }
    o->min = min;
    this->m_454 = max;
    ((TLobby *)(&o->local))->copy_entry(this->m_31c);
    this->m_31c = &o->local;
    update_segments();
}

void TBoss6Type2::sub_802BC124() {
    *(f32 *)&this->unk_4FC += -0.06666667f;
    if (*(f32 *)&this->unk_4FC < 0.0f) {
        *(f32 *)&this->unk_4FC = 0.0f;
    }
    this->m_500 = (f32) ((f32) this->m_32c / (f32) *(s16 *)&this->m_33e);
}

s32 TBoss6Type2::choose_turn_motion() {
    f32 temp_f3;
    f64 temp_f0;
    s32 var_r31;
    s32 var_r31_2;
    void *temp_r3;

    var_r31_2 = 0xF;
    temp_r3 = ((void * (*)(u16))get_player_by_client_id)(this->m_466);
    if (this->m_478 & 1) {
        var_r31_2 = 0x10;
    }
    if (temp_r3 == NULL) {
        return var_r31_2;
    }
    temp_f3 = *(f32 *)((s8 *)temp_r3 + 0x38);
    temp_f0 = ((f64 (*)(f32, f32, f32))atan2_float)(temp_f3 - *(f32 *)((s8 *)this + 0x38), *(f32 *)((s8 *)temp_r3 + 0x40) - *(f32 *)((s8 *)this + 0x40), temp_f3);
    var_r31 = 0xF;
    if (angle_diff_s16(this->m_60, (s32) (10430.38043493439 * temp_f0)) < 0) {
        var_r31 = 0x10;
    }
    return var_r31;
}

s32 TBoss6Type2::choose_random_motion() {
    struct Boss_802BC23C *arg0 = (struct Boss_802BC23C *)this;
    s32 m;
    f32 r;
    f32 a;
    f32 b;

    m = choose_turn_motion();
    r = (1.0f / 32768.0f) * (f32)rand();
    if (arg0->f418 == 0) {
        if (r < 0.2f) {
            return 0x11;
        }
        return m;
    }
    if (r < 0.6f) {
        m = 0x11;
    }
    r = (1.0f / 32768.0f) * (f32)rand();
    a = (f32)arg0->f4d0 / 100.0f;
    b = (f32)arg0->f4cc / 100.0f + a;
    if (r <= a) {
        m += 6;
    } else if (r <= b) {
        m += 3;
    }
    return m;
}

s32 TBoss6Type2::is_target_valid() {
    if ((s32) this->m_418 == 0) {
        return 0;
    }
    if ((u16) *(u16 *)((s8 *)this + 0x55C) == 0xFFFF) {
        return 1;
    }
    if (is_split_screen() != 0) {
        return 0;
    }
    return (local_client_id - (s32) *(u16 *)((s8 *)this + 0x55C)) != 0 ? 1 : 0;
}

void TBoss6Type2::update_attack_switch() {
    u8 *arg0 = (u8 *)this;
    if ((*(s32 *)((s8 *)arg0 + 0x518) % 24) == 0) {
        spawn_particle_effect_with_flags(arg0 + 0x38, 0x224, 0x2040);
    }
}

void TBoss6Type2::play_phase_sound() {
    u8 *arg0 = (u8 *)this;
    s32 var_r3;

    if (is_target_valid() == 0) {
        switch (this->m_42c) {
        case 1:
            var_r3 = 0x6852C;
            break;
        case 2:
            var_r3 = 0x6852D;
            break;
        case 3:
            var_r3 = 0x6852E;
            break;
        case 4:
            var_r3 = 0x6852F;
            break;
        case 5:
        default:
            var_r3 = 0x6852B;
            break;
        }
        play_sound_effect(var_r3, arg0 + 0x38, 0, 1);
    }
}

void TBoss6Type2::play_sound_if_no_target() {
    u8 *arg0 = (u8 *)this;
    if (is_target_valid() == 0) {
        play_sound_effect(TBoss6Type2__no_target_sound_ids[TBoss6Type2::find_index_in_table(this->m_2e4)], arg0 + 0x38, 0, 1);
    }
}

void TBoss6Type2::update_countdown() {
    s32 temp_r0;
    void *temp_r31;

    if (((s32 (*)(void))is_active__11TBoss6Type2Fv)() != 0) {
        update_attack_switch();
    }
    temp_r0 = *(s32 *)((s8 *)this + 0x518);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)this + 0x51C) = 0;
        *(s32 *)((s8 *)this + 0x518) = (s32) (*(s32 *)((s8 *)this + 0x518) - 1);
        if ((s32) *(s32 *)((s8 *)this + 0x518) < -0x12C) {
            *(s32 *)((s8 *)this + 0x518) = -0x12C;
        }
        if (((s32) this->m_418 != 0) && ((s32) *(s32 *)((s8 *)this + 0x518) == -0x12C)) {
            temp_r31 = ((void * (*)(u16))get_player_by_client_id)(*(u16 *)((s8 *)this + 0x55C));
            if ((is_active__14TBoss6PlotFalzFv() != 0) && ((s16) *(s16 *)((s8 *)temp_r31 + 0x326) == 1)) {
                start_countdown_sound_state();
            }
        }
    } else {
        if (temp_r0 == 0) {
            play_phase_sound();
        }
        *(s32 *)((s8 *)this + 0x518) = (s32) (*(s32 *)((s8 *)this + 0x518) - 1);
    }
}

u8 TBoss6Type2::is_active() {
    s32 var_r4;

    var_r4 = 0;
    if ((((s32) *(s32 *)((s8 *)this + 0x51C) != 0) && ((s32) *(s32 *)((s8 *)this + 0x518) >= 0)) || ((s32) this->m_374 == 1)) {
        var_r4 = 1;
    }
    return (u8) var_r4;
}

void TBoss6Type2::set_state_0x34() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x518) = 0x34;
    *(s32 *)((s8 *)arg0 + 0x51C) = 1;
    play_sound_if_no_target();
}

void TBoss6Type2::start_countdown_sound_state() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x518) = 0x34;
    *(s32 *)((s8 *)arg0 + 0x51C) = 0;
    play_sound_if_no_target();
}

void TBoss6Type2::reset_indices() {
    *(s32 *)((s8 *)this + 0x518) = -1;
    *(s32 *)((s8 *)this + 0x51C) = 0;
}

s32 TBoss6Type2::get_hit_count() {
    return *(s32 *)((s8 *)this + 0x4F4);
}

void TBoss6Type2::add_damage(s32 arg1) {
    s32 temp_r0;
    s32 var_r4;

    var_r4 = arg1;
    temp_r0 = this->m_374;
    if (temp_r0 < 9) {
        if (temp_r0 == 5) {
            goto block_4;
        }
        goto block_5;
    } else if (temp_r0 < 0xC) {
block_4:
        var_r4 *= 2;
    }
block_5:
    *(s32 *)((s8 *)this + 0x4F4) = (s32) (*(s32 *)((s8 *)this + 0x4F4) + var_r4);
}

void TBoss6Type2::reset_attack_counter() {
    *(s32 *)((s8 *)this + 0x4F4) = 0;
}

s32 calc_field4f0_delta__11TBoss6Type2FPv(void *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x4F0) - *(s16 *)((s8 *)arg0 + 0x32C);
}

void TBoss6Type2::copy_anim_state() {
    *(s32 *)((s8 *)this + 0x4F0) = (s32) this->m_32c;
}

void set_screen_pos__11TBoss6Type2FPv(void *arg0) {
    f32 var_f0;
    f32 var_f1;

    if ((s32) *(s32 *)((s8 *)arg0 + 0x424) != 0) {
        var_f1 = 0.28f * *(f32 *)((s8 *)arg0 + 0x4E0);
        var_f0 = 0.28f * *(f32 *)((s8 *)arg0 + 0x4E4);
    } else {
        var_f1 = 0.28f * *(f32 *)((s8 *)arg0 + 0x4D8);
        var_f0 = 0.28f * *(f32 *)((s8 *)arg0 + 0x4DC);
    }
    *(f32 *)((s8 *)TBoss6Type2__motion_table + 0x2C) = var_f1;
    *(f32 *)((s8 *)TBoss6Type2__motion_table + 0x3C) = var_f1;
    *(f32 *)((s8 *)TBoss6Type2__motion_table + 0xEC) = var_f0;
}

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
void TBoss6Type2::load_battle_params() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r3_2;
    u8 *temp_r3;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    temp_r3 = (u8 *)(TLobby::dispatch_shared_handler_a(0x2C));
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B4 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_4;
    if ((f32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B4 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B4 = TBoss6Type2__default_battle_parameters.int_params[0];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B8 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_10;
    if ((f32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B8 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B8 = TBoss6Type2__default_battle_parameters.int_params[1];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D4 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_14;
    if ((f32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D4 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D4 = TBoss6Type2__default_battle_parameters.int_params[8];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4BC = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_18;
    if ((s32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4BC <= 0) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4BC = TBoss6Type2__default_battle_parameters.int_params[2];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C0 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_1C;
    if ((s32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C0 <= 0) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C0 = TBoss6Type2__default_battle_parameters.int_params[3];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C4 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_20;
    if ((s32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C4 <= 0) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C4 = TBoss6Type2__default_battle_parameters.int_params[4];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C8 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_24;
    if ((s32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C8 <= 0) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C8 = TBoss6Type2__default_battle_parameters.int_params[5];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4CC = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_28;
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D0 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_2C;
    temp_r0 = ((RecoveredFields_802BC754_arg0 *)arg0)->field_4CC;
    if ((temp_r0 < 0) || (temp_r0 > 0x64) || (temp_r3_2 = ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D0, ((temp_r3_2 < 0) != 0)) || (temp_r3_2 > 0x64) || ((s32) (temp_r0 + temp_r3_2) > 0x64)) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4CC = TBoss6Type2__default_battle_parameters.int_params[6];
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D0 = TBoss6Type2__default_battle_parameters.int_params[7];
    }
    temp_r3_3 = (u8 *)(TLobby::dispatch_shared_handler_a(0x2F));
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D8 = (f32) ((RecoveredFields_802BC754_temp_r3_3 *)temp_r3_3)->field_0;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4D8 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D8 = TBoss6Type2__default_battle_parameters.float_params[0];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4DC = (f32) ((RecoveredFields_802BC754_temp_r3_3 *)temp_r3_3)->field_4;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4DC <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4DC = TBoss6Type2__default_battle_parameters.float_params[1];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E8 = (f32) ((RecoveredFields_802BC754_temp_r3_3 *)temp_r3_3)->field_8;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4E8 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E8 = TBoss6Type2__default_battle_parameters.float_params[4];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4EC = (s32) ((RecoveredFields_802BC754_temp_r3_3 *)temp_r3_3)->field_C;
    if ((f32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4EC <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4EC = TBoss6Type2__default_battle_parameters.last_param;
    }
    temp_r3_4 = (u8 *)(TLobby::dispatch_shared_handler_a(0x2E));
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E0 = (f32) ((RecoveredFields_802BC754_temp_r3_4 *)temp_r3_4)->field_8;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4E0 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E0 = TBoss6Type2__default_battle_parameters.float_params[2];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E4 = (f32) ((RecoveredFields_802BC754_temp_r3_4 *)temp_r3_4)->field_C;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4E4 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E4 = TBoss6Type2__default_battle_parameters.float_params[3];
    }
}
#pragma pop

struct Anim_802BCD2C { u8 pad[4]; u32 n; };
struct Trk_802BCD2C { Anim_802BCD2C *anim; f32 t; f32 dt; f32 a; f32 da; Anim_802BCD2C *prev_anim; f32 prev_t; };
struct Obj_802BCD2C {
    u8 pad0[0x490];
    s32 f490;
    s32 f494;
    Trk_802BCD2C trk[1];
};
extern const s32 lbl_805DE4BC;

void TBoss6Type2::draw_body_models() {
    u8 *arg0 = (u8 *)this;
    Prm_802BCAB8 prm;
    f32 zero;
    f32 a;
    s32 b;
    u32 obj;
    s32 done;
    s32 i;
    Ent_802BCAB8 *e;
    s32 p0;
    s32 p1;
    set_motion_packed_rotation();
    obj = this->m_764;
    done = 0;
    if (obj != 0) {
        zero = 0.0f;
        for (i = 0; i < 2; i++) {
            e = &((Obj_802BCAB8 *)arg0)->ents[i];
            p0 = e->a;
            p1 = e->b;
            switch (i) {
            case 0:
                a = 1.0f - this->state_progress;
                break;
            case 1:
            default:
                a = this->state_progress;
                break;
            }
            if (zero != a) {
                if (a < 1.0f) {
                    TBoss6PlotFalz::set_fade_material_color(a);
                }
                TObjFish::set_global_param(p0);
                if (0.0f == *(f32 *)((s8 *)arg0 + 0x4A4)) {
                    if (done != 0) {
                        draw_model_motion((void *)p1, (void *)(*(s32 *)((s8 *)arg0 + 0x498)), *(f32 *)((s8 *)arg0 + 0x49C));
                    } else {
                        ((TObjFish *)obj)->set_draw_callback_list();
                        draw_model_motion((void *)p1, (void *)(*(s32 *)((s8 *)arg0 + 0x498)), *(f32 *)((s8 *)arg0 + 0x49C));
                        ((TObjFish *)obj)->clear_render_callback();
                        done = 1;
                    }
                } else {
                    prm.a = *(s32 *)((s8 *)arg0 + 0x4AC);
                    prm.b = *(f32 *)((s8 *)arg0 + 0x4B0);
                    prm.c = *(s32 *)((s8 *)arg0 + 0x498);
                    prm.d = *(f32 *)((s8 *)arg0 + 0x49C);
                    if (done != 0) {
                        draw_model_blend_motion((void *)p1, &prm, *(f32 *)((s8 *)arg0 + 0x4A4));
                    } else {
                        ((TObjFish *)obj)->set_draw_callback_list();
                        draw_model_blend_motion((void *)p1, &prm, *(f32 *)((s8 *)arg0 + 0x4A4));
                        ((TObjFish *)obj)->clear_render_callback();
                        done = 1;
                    }
                }
                if (a < 1.0f) {
                    TObjFish::reset_fish_globals();
                }
            }
        }
    }
    clear_motion_packed_rotation();
}

void TBoss6Type2__sub_802BCC54(void *p, int motion) {
    Obj_802BCD2C *self = (Obj_802BCD2C *)p;
    if (motion != -1 && motion != self->f490) {
        s32 *ent;
        s32 i;
        self->f490 = motion;
        ent = &TBoss6Type2__motion_table[motion * 4];
        self->f494 = ent[0];
        for (i = 0; i < TBoss6Type2__data_805DE4B8; i++) {
            Trk_802BCD2C *e = &self->trk[i];
            Anim_802BCD2C *anim = (Anim_802BCD2C *)get_bml_motion(((TBoss6Type2 *)p)->m_3fc, ((Tb_802BCEF4 *)ent)->v[i]);
            e->a = e->da;
            e->prev_anim = e->anim;
            e->prev_t = e->t;
            e->dt = *(f32 *)((u8 *)ent + 0xC);
            e->anim = anim;
            e->t = 0.0f;
        }
    }
}

void TBoss6Type2::update_motion_tracks() {
    Obj_802BCD2C *self = (Obj_802BCD2C *)this;
    s32 i;
    Trk_802BCD2C *e;
    f32 n;
    f32 lim;

    for (i = 0; i < TBoss6Type2__data_805DE4B8; i++) {
        if (i != lbl_805DE4BC) {
            e = &self->trk[i];
            n = (f32)e->anim->n;
            e->t += e->dt;
            if (e->t >= n) {
                e->t -= n;
            }
            if (0.0f != e->a) {
                if ((e->a += e->da) >= 1.0f) {
                    e->a = 0.0f;
                }
            }
        }
    }
    e = &self->trk[lbl_805DE4BC];
    n = (f32)e->anim->n;
    e->t += e->dt;
    switch (self->f494) {
    case 0:
        if (e->t >= n) {
            e->t -= n;
        }
        break;
    case 1:
        break;
    case 2:
        lim = n - 1.0f;
        if (e->t >= lim) {
            e->t = lim;
            TBoss6Type2__sub_802BCC54(self, TBoss6Type2__motion_table[self->f490 * 4 + 1]);
        }
        break;
    }
    if (0.0f != e->a) {
        if ((e->a += e->da) >= 1.0f) {
            e->a = 0.0f;
        }
    }
}


struct Blk_802BCFD4;

void TBoss6Type2::init_motion_entries() {
    O_802BCEF4 *o = (O_802BCEF4 *)this;
    s32 i;
    copy_block__11TBoss6Type2FPvPv((Blk_802BCFD4 *)((u8 *)o + 0x490), &boss6_type2_zero_motion_block);
    for (i = 0; i < TBoss6Type2__data_805DE4B8; i++) {
        Ent_802BCEF4 *e = &o->ents[i];
        s32 r;
        ((TBoss6Type2 *)e)->copy_transform((void *)boss6_type2_motion_entry_transform);
        r = get_bml_motion(this->m_3fc, ((Tb_802BCEF4 *)TBoss6Type2__motion_table)->v[i]);
        e->f14 = r;
        e->f0 = r;
        e->f8 = *(f32 *)((u8 *)TBoss6Type2__motion_table + 0xC);
    }
}

void TBoss6Type2::copy_transform(void* q) { *(u32*)((char*)this + 0x0) = *(u32*)((char*)q + 0x0); *(f32*)((char*)this + 0x4) = *(f32*)((char*)q + 0x4); *(f32*)((char*)this + 0x8) = *(f32*)((char*)q + 0x8); *(f32*)((char*)this + 0xc) = *(f32*)((char*)q + 0xc); *(f32*)((char*)this + 0x10) = *(f32*)((char*)q + 0x10); *(u32*)((char*)this + 0x14) = *(u32*)((char*)q + 0x14); *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x18); }

__declspec(section ".sdata2") const s32 TBoss6Type2__data_805DE4B8 = 1;
__declspec(section ".sdata2") const s32 lbl_805DE4BC = 0;

Blk_802BCFD4 *copy_block__11TBoss6Type2FPvPv(Blk_802BCFD4 *d, const Blk_802BCFD4 *s) {
    *d = *s;
    return d;
}

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
void TBoss6Type2::set_action_state(void *vv) {
    s32 i;
    Tb_802BD014 *e;
    Fn_802BD014 fn;
    ((TBoss6Type2_802BD014 *)this)->a[0] = (s32)vv;
    for (i = 31; i > 0; i--) {
        ((TBoss6Type2_802BD014 *)this)->a[i + 1] = ((TBoss6Type2_802BD014 *)this)->a[i];
    }
    ((TBoss6Type2_802BD014 *)this)->a[1] = ((TBoss6Type2_802BD014 *)this)->a[0];
    e = &lbl_804E00DC[((TBoss6Type2_802BD014 *)this)->a[0]];
    TBoss6Type2__sub_802BCC54(this, e->f4);
    ((TBoss6Type2_802BD014 *)this)->f474 = e->f8;
    fn = e->fn;
    if (fn) {
        (((TBoss6Type2_802BD014 *)this)->*fn)();
    }
}
#pragma pop

#pragma push

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::run_task() {
    u8 *arg0 = (u8 *)this;
#define o ((TBoss6Type2_802BD014 *)arg0)
    Fn_802BD014 fn;
    ((TBoss6Type2 *)arg0)->update_lower_contact_delta();
    {
        Tb_802BD0C8 *tbl = (Tb_802BD0C8 *)lbl_804E00DC;
        fn = tbl[o->a[0]].fn3;
    }
    if (fn) {
        (o->*fn)();
    }
    if (((TBoss6Type1 *)(this->m_3f8))->is_idle() != 0) {
        Tb_802BD0C8 *tbl = (Tb_802BD0C8 *)lbl_804E00DC;
        fn = tbl[o->a[0]].fn2;
        if (fn) {
            (o->*fn)();
        }
    }
#undef o
    update_motion_tracks();
    advance_position();
    TBoss6Type2__sub_802BBE20(arg0);
    update_parts_flags();
    ((TObjPlayer *)arg0)->update_collisions();
    submit_cursor_candidate(arg0, -1);
    add_radar_scaled_marker(arg0 + 0x38, -0x5DB4, 1, 1, 4.0f);
    ((TBoss6Type2 *)arg0)->apply_rock_hits_to_players();
    ((TBoss6Type2 *)arg0)->sub_802BB498();
    ((TBoss6Type2 *)arg0)->sub_802BC124();
    ((TBoss6PlotFalz *)(arg0 + 0x768))->scroll_strips_uv(8, 0);
    TObjPlayer__sub_8023DEE0((s16 *)(*(s32 *)((s8 *)(*(u8 **)((s8 *)(find_model_node(get_bml_model(this->m_3fc, 1), 1)) + 4)) + 4)), 8, 0, 0);
    ((TBoss6Type2 *)arg0)->sub_802BB554();
    copy_vec_array();
    if ((s32) this->m_418 != 0) {
        play_persistent_sound(0x4006B00C, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
    }
    update_countdown();
    ((TBoss6Type2 *)arg0)->update_possess_target();
    update_footstep_effects();
    TBoss6Type2__sub_802BA7BC(arg0);
    update_part_positions();
    this->m_4f8 = (s32) this->m_32c;
}
#pragma pop

void TBoss6Type2::copy_pos_620(s32 arg1) {
    s32 arg0 = (s32)this;
    VecCopy((Vec *)arg1, (const Vec *)(arg0 + 0x620));
}
#pragma pop

void TBoss6Type2::get_push_points(s32 arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    VecCopy((Vec *)(arg1), (const Vec *)(arg0 + 0x5FC));
    VecCopy((Vec *)(arg2), (const Vec *)(arg0 + 0x5C0));
}

void TBoss6Type2::copy_pos_59c(s32 arg1) {
    s32 arg0 = (s32)this;
    VecCopy((Vec *)arg1, (const Vec *)(arg0 + 0x59C));
}

void TBoss6Type2__sub_802BD340(void) {  }

void TBoss6Type2::apply_damage(s32 arg1) {
    if ((arg1 > 0) && ((s32) this->m_418 == 0)) {
        add_damage(arg1);
    }
}

void TBoss6Type2__sub_802BD378(T2_802BD378 *arg0, s32 arg1, void *arg2, s32 *arg3) {
    VecCopy((Vec *)(arg2), (const Vec *)(&arg0->v[arg1 + 0xE - 0]));
    *arg3 = arg0->f60;
}

s32 TBoss6Type2::get_rotation_timer() { return this->m_418; }

void TBoss6Type2::get_phase_values(u16 *a, u16 *b, u16 *out) {
    s32 i;
    *a = ((Obj_8004D8C8 *)this)->f2d6;
    *b = ((Obj_8004D8C8 *)this)->f2d4;
    for (i = 0; i < 4; i++) {
        out[i] = obj_getArrU16_FC(this, i);
    }
}

f32 vfunc_23__11TBoss6Type2FPvPvPvll(TBoss6Type2 *self, void *attacker, AttackMsg_802BD430 msg, void *collision, s32 tech, s32 arg5) {
    while ((s32)self->m_418 != 0) {
        if (msg.type == 0x14) {
            break;
        }
        if (((TObjEneDD *)self)->query_teammate_state() != 0) {
            break;
        }
        if (msg.type == (s32)self->m_42c) {
            break;
        }
        self->sub_802BA078();
        self->spawn_hit_effects();
        return 0.0f;
    }
    return receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(self, attacker, msg, collision, tech, arg5);
}

f32 TBoss6Type2__vt20(TBoss6Type2 *arg0, u32 att, f32 scale) {
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;

    var_r31 = 1;
    if (((s32) arg0->m_418 != 0) && (att != 0U)) {
        var_r30 = 0;
        var_r29 = 0;
        do {
            switch ((s32) (*get_attribute_entry__10TObjPlayerFl(att, var_r29))) {
            case 1:
                var_r30 |= 1;
                break;
            case 2:
                var_r30 |= 2;
                break;
            case 3:
                var_r30 |= 4;
                break;
            case 4:
                var_r30 |= 8;
                break;
            }
            var_r29 += 1;
        } while (var_r29 < 3);
        if (!(arg0->m_2e4 & var_r30)) {
            var_r31 = 0;
        }
    }
    if (var_r31 != 0) {
        return receive_physical_attack__9TObjCharaFPvf(arg0, att, scale);
    }
    arg0->sub_802BA078();
    arg0->spawn_hit_effects();
    return 0.0f;
}

void TBoss6Type2__vt61(void* p) { if (*(int *)&((TBoss6Type2 *)p)->m_374 != 35) { ((TBoss6Type2 *)p)->set_action_state((void*)((void*)35)); } }

void TBoss6Type2__vt60(TBoss6Type2 *boss6_type2) {
    boss6_type2->m_30 = (s32) (boss6_type2->m_30 & 0xFFFFFDFF);
    *(f32 *)((s8 *)boss6_type2 + 0x4FC) = 1.0f;
    {
        int diff = boss6_type2->m_4f8 - boss6_type2->m_32c;
        if (diff > 0) {
            boss6_type2->add_damage(diff);
        }
    }
    if ((s32) boss6_type2->m_418 != 0) {
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x68A24, (u8 *)boss6_type2 + 0x38, 0, 1);
    }
}

s32 TBoss6Type2::count_matching_values(s32 arg1, s32 arg2) {
    T1_802BD68C *arg0 = (T1_802BD68C *)this;
    s32 i;
    s32 cnt;
    if (arg2 > 0x20) {
        arg2 = 0x20;
    }
    cnt = 0;
    for (i = 0; i < arg2; i++) {
        if (arg0->v[i] == arg1) {
            cnt++;
        }
    }
    return cnt;
}

void TBoss6Type2::set_target_state(s32 arg1, s32 arg2) {
    u32 temp_r31;
    s32 temp_r30;

    temp_r31 = this->m_2e4;
    temp_r30 = *(s32 *)&this->m_42c;
    this->m_2e4 = TBoss6Type2::get_table_entry(arg1);
    *(s32 *)&this->m_42c = arg2;
    update_segments();
    if ((temp_r31 != (u32) this->m_2e4) || (temp_r30 != (s32) *(s32 *)&this->m_42c)) {
        set_state_0x34();
    }
    if (*(void * *)&this->unk_410 != 0) {
        ((TBoss6Type2 *)(*(void * *)&this->unk_410))->set_target_nodes((void*)this->m_2e4, (void*)(*(s32 *)&this->m_42c));
    }
    if (this->m_414 != 0) {
        ((TBoss6Type2 *)(this->m_414))->set_target_nodes((void*)this->m_2e4, (void*)(*(s32 *)&this->m_42c));
    }
}

s32 TBoss6Type2::choose_next_index() {
    T2_802BD76C *arg0 = (T2_802BD76C *)this;
    s32 k = (s32)(2.99f * (3.0517578e-05f * (f32)rand())) + 1;
    s32 r = arg0->f42C + k;
    if (r > 4) {
        r -= 4;
    }
    return r;
}


s32 TBoss6Type2::pick_random_other_index() {
    TBoss6Type2 *o = this;
    s32 t = TBoss6Type2::find_index_in_table(o->m_2e4);
    s32 r = t + (s32)(2.99f * (3.0517578e-05f * (f32)rand())) + 1;
    if (r >= 4) {
        r -= 4;
    }
    return r;
}

s32 TBoss6Type2::find_index_in_table(u32 v) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (v == ((const u32 *)TBoss6Type2__initial_actor_flag_masks)[i]) return i;
    }
    return 0;
}

int TBoss6Type2::get_table_entry(int a0) {  return TBoss6Type2__initial_actor_flag_masks[a0]; }

extern "C" u8 *get_enemy_entity(u16 arg0);

extern "C" void handle_6xA5_olga_flow_boss_actions(void *arg) {
    u8 *pkt = (u8 *)arg;
    TBoss6Type2 *boss;
    s32 state;
    ((TBoss6Type2 *)pkt)->handle_olga_action();
    boss = (TBoss6Type2 *)get_enemy_entity(*(u16 *)(pkt + 2));
    if (boss == NULL) {
        return;
    }
    ((TBoss6Type2 *)(pkt + 4))->call_9A24_plus_1((s32 *)&boss->m_480);
    boss->parse_action_packet(pkt);
    state = ((s8 *)pkt)[4];
    if (state < 0 || state >= 36) {
        return;
    }
    boss->set_action_state((void *)state);
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2__sub_802BD938(u8 *arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_802BD938, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_802BD938, sp9) == 0x1) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802BD938, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802BD938, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_802BD938, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_802BD938, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_802BD938, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_802BD938, sp20) == 0x18) ? 1 : -1];
    Stack_802BD938 stack;
    f32 temp_f1;
    s32 temp_r29;
    s32 temp_r29_2;
    s32 temp_r3;
    temp_r3 = ((s32)((s32 (*)(int))get_player_by_client_id)((int) ((s32) *(u16 *)((s8 *)arg0 + 0x466))));
    if (temp_r3 != 0) {
        VecCopy((Vec *)(&stack.sp18), (const Vec *)(temp_r3 + 0x38));
    } else {
        *(u16 *)((s8 *)arg0 + 0x466) = 0xFFFFU;
        temp_r29 = (s32) ((6144.0f * -((3.0517578e-05f * (f32) rand()) - 0.5f)) + (f32) *(s32 *)((s8 *)arg0 + 0x60));
        VecCopy((Vec *)(&stack.sp18), (const Vec *)(arg0 + 0x38));
        stack.sp18 += 150.0f * sin_table_lookup(temp_r29);
        stack.sp20 += 150.0f * cos_table_lookup(temp_r29);
        if (xyz_distance(arg0 + 0x38, (void *)&boss6_arena_center) > 390.0f) {
            temp_r29_2 = (s32) (65535.0f * (3.0517578e-05f * (f32) rand()));
            VecCopy((Vec *)(&stack.sp18), &boss6_arena_center);
            stack.sp18 += 150.0f * sin_table_lookup(temp_r29_2);
            stack.sp20 += 150.0f * cos_table_lookup(temp_r29_2);
        }
    }
    stack.sp1C = 0.0f;
    VecCopy((Vec *)(&stack.spC), (const Vec *)(&stack.sp18));
    ((f32 (*)(void *, void *))subtract_vector)(&stack.spC, arg0 + 0x38);
    stack.sp10 = 0.0f;
    temp_f1 = ((f32 (*)(void *))vector_length)(&stack.spC);
    if (temp_f1 < 7.874016f) {
        if (temp_f1 <= 1e-05f) {
            stack.sp18 = 1.0f;
        } else {
            normalize_vector(&stack.spC);
        }
        stack.spC *= 7.874016f;
        stack.sp14 *= 7.874016f;
        VecCopy((Vec *)(&stack.sp18), (const Vec *)(&stack.spC));
        vec3_add_to(&stack.sp18, arg0 + 0x38);
    }
    ((s32 (*)(void *, void *, void *))world_to_grid_pos__11TBoss6Type2FPvPvPv)(&stack.sp18, &stack.sp9, &stack.sp8);
    *(u8 *)((s8 *)arg1 + 0) = stack.sp9;
    *(u8 *)((s8 *)arg1 + 1) = stack.sp8;
}
#pragma pop

void TBoss6Type2::update_attack_target() {
    s32 sp8;
    s32 temp_r0;
    s32 var_r31;
    s32 var_r3;
    u16 temp_r31;
    u16 temp_r3;
    u16 var_r30;

    var_r3 = 0x21;
    if ((s32) this->m_424 != 0) {
        var_r3 = 0x1F;
    }
    temp_r0 = this->m_374;
    var_r31 = var_r3;
    switch (temp_r0) {
    case 0x1D:
        return;
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
        temp_r31 = this->m_466;
        temp_r3 = ((u16 (*)(void *))TBoss6Type2__sub_802BB694)(this);
        var_r30 = temp_r3;
        if ((u16) temp_r3 == 0xFFFF) {
            ((s32 (*)(int))get_player_by_client_id)(temp_r31);
            if (is_active__14TBoss6PlotFalzFv() != 0) {
                var_r30 = temp_r31;
            }
        }
        this->m_466 = var_r30;
        if ((TBoss6PlotFalz::get_phase() == 0) && (this->m_374 & 1)) {
            this->m_466 = 0xFFFFU;
        }
        var_r31 = this->m_374 - 1;
        break;
    }
    TBoss6Type2__sub_802BD938((u8 *)this, (u8 *)&sp8);
    send_action_packet_if_idle(var_r31, &sp8);
}


void TBoss6Type2::send_state_action_packet() {
    s32 sp8;
    s32 var_r31;
    if ((s32) this->m_424 != 0) {
        var_r31 = 7;
        if ((s32) this->m_46c == 0) {
            var_r31 = 0xA;
        }
    } else {
        var_r31 = 8;
        if ((s32) this->m_46c == 0) {
            var_r31 = 0xB;
        }
    }
    switch (this->m_374) {
    case 6:
    case 9:
        return;
    case 7:
    case 8:
    case 10:
    case 11:
        this->m_466 = ((s16 (*)(void *))TBoss6Type2__sub_802BB694)(this);
        var_r31 = this->m_374 - 1;
    default:
        TBoss6Type2__sub_802BD938(((u8 *)this), (u8 *)&sp8);
        this->send_action_packet_if_idle(var_r31, &sp8);
        break;
    }
}

void TBoss6Type2::update_action_state() {
    s32 sp8;
    s32 var_r4;

    TBoss6Type2__sub_802BD938((u8 *)this, (u8 *)&sp8);
    var_r4 = 4;
    if ((s32) this->m_46c == 0) {
        var_r4 = 5;
    }
    send_action_packet_if_idle(var_r4, &sp8);
}

void TBoss6Type2::send_action_packet_if_idle(s32 arg1, s32 *arg2) {
    Pkt_802BDD6C p;
    u8 *s; s32 i;
    if (((TBoss6Type1 *)(this->m_3f8))->is_idle() != 0) {
        ((TBoss6Type2 *)(&p))->init_packet();
        build_state_packet((u8 *)&p);
        s = (u8 *)arg2; p.d[4] = arg1;
        for (i = 1; i < 4; i++) {
            p.d[i + 4] = *s++;
        }
        ((TBoss6Type2 *)(&p))->update_and_send();
    }
}

void TBoss6Type2::send_action_packet(s8 arg1) {
    typedef char sp8_offset[(offsetof(Stack_802BDDF8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802BDDF8, spC) == 0x4) ? 1 : -1];
    Stack_802BDDF8 stack;
    if (((TBoss6Type1 *)(this->m_3f8))->is_idle() != 0) {
        ((TBoss6Type2 *)(&stack.sp8))->init_packet();
        build_state_packet((u8 *)&stack.sp8);
        stack.spC = arg1;
        ((TBoss6Type2 *)(&stack.sp8))->update_and_send();
    }
}

void TBoss6Type2::parse_action_packet(void *arg1) {
    this->m_478 = (u8) *(u8 *)((s8 *)arg1 + 8);
    this->m_47c = (s32) (s8) *(u8 *)((s8 *)arg1 + 9);
    set_target_state((s32)(*(s8 *)((s8 *)arg1 + 0xA)), (s32)(*(s8 *)((s8 *)arg1 + 0xB)));
    this->m_464 = (u16) (s8) *(u8 *)((s8 *)arg1 + 0xC);
    this->m_466 = (u16) (s8) *(u8 *)((s8 *)arg1 + 0xD);
    this->m_468 = (u16) (s8) *(u8 *)((s8 *)arg1 + 0xE);
    this->m_46a = (u16) (s8) *(u8 *)((s8 *)arg1 + 0xF);
    if ((u16) this->m_464 >= 4U) {
        this->m_464 = 0xFFFFU;
    }
    if ((u16) this->m_466 >= 4U) {
        this->m_466 = 0xFFFFU;
    }
    if ((u16) this->m_468 >= 4U) {
        this->m_468 = 0xFFFFU;
    }
    if ((u16) this->m_46a >= 4U) {
        this->m_46a = 0xFFFFU;
    }
    set_action_field_0x408__11TBoss6Type2Fs(*(s32 *)&this->unk_410, this->m_468);
    set_action_field_0x408__11TBoss6Type2Fs(*(s32 *)&this->m_414, this->m_46a);
}

void TBoss6Type2::build_state_packet(u8 *arg1) {
    u16 spA;
    u16 sp8;
    *(u16 *)((s8 *)arg1 + 2) = (u16) *(u16 *)((s8 *)((u8 *)this) + 0x1C);
    *(s8 *)((s8 *)arg1 + 8) = (s8) (127.0f * (3.0517578e-05f * (f32) rand()));
    *(s8 *)((s8 *)arg1 + 9) = this->choose_random_motion();
    *(s8 *)((s8 *)arg1 + 0xA) = (s8) this->m_428;
    *(s8 *)((s8 *)arg1 + 0xB) = (s8) this->m_430;
    *(s8 *)((s8 *)arg1 + 0xC) = (s8) this->m_464;
    *(s8 *)((s8 *)arg1 + 0xD) = (s8) this->m_466;
    ((void (*)(void *, void *, void *))TBoss6Type2__sub_802BB5B4)(this, &spA, &sp8);
    *(s8 *)((s8 *)arg1 + 0xE) = (s8) spA;
    *(s8 *)((s8 *)arg1 + 0xF) = (s8) sp8;
}

struct Fish_802BE014 { u8 pad[0x764]; void *fish[1]; };

#define self ((TBoss6Type2 *)self_)
s32 __dt__11TBoss6Type2Fv(s32 self_, s16 flag) {
    s32 i;
    if (self != 0) {
        *(u8 **)((u8 *)self + 0x18) = __vt__11TBoss6Type2;
        init_parts__11TBoss6Type2FPv(self_);
        self->reset_counters();
        TBoss6Rock__sub_80354A44();
        for (i = 0; i < 2; i++) {
            Ent_802BE0D4 *e = &((Ents_802BE0D4 *)self)->ents[i];
            e->a = 0;
            e->b = 0;
        }
        ((TBoss6PlotFalz *)&self->m_768)->free_buffer_pairs();
        for (i = 0; i < 1; i++) {
            if (((Fish_802BE014 *)self)->fish[i] != 0) {
                TObjFish::init_state_1(((Fish_802BE014 *)self)->fish[i]);
                ((Fish_802BE014 *)self)->fish[i] = 0;
            }
        }
        free_collision_body_parts(self);
        __dt__9TObjEnemyFv((TObjEnemy *)self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self_;
}
#undef self

#pragma push

#pragma push
#pragma opt_common_subs off
#define arg0 ((u8 *)arg0_)
#define arg2 ((s32 *)arg2_)
s32 TBoss6Type2__ct(s32 arg0_, s32 parent, s32 arg2_) {
    Tmp_802BE0D4 tmp;
    s32 i;
    s32 id;
    __ct__9TObjEnemyFP7TObject(arg0, (void*)parent);
    *(u8 **)((s8 *)arg0 + 0x18) = __vt__11TBoss6Type2;
    *(const char **)((s8 *)arg0 + 0) = TBoss6Type2__name;
    *(s32 *)((s8 *)arg0 + 0x3F8) = arg2[0];
    ((VObj_18_802BE0D4 *)(arg0))->m79(arg2 + 1);
    if (((TObjEnemy *)arg0)->exchange_object_state((s32)&tmp, (s16)1) != 0) {
        tmp.a = 0;
        tmp.c = 0;
        ((TObjEnemy *)arg0)->exchange_object_state((s32)&tmp, (s16)0);
    }
    *(s32 *)((s8 *)arg0 + 0x3FC) = TObjFish::get_fish_count();
    *(s32 *)((s8 *)arg0 + 0x24) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    VecCopy((Vec *)(arg0 + 0x38), &TBoss6Type2__initial_position);
    copy_xyz(arg0 + 0x5C, (void *)TBoss6Type2__initial_rotation);
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)((void *)VecCopy((Vec *)(arg0 + 0x50), (const Vec *)((void *)VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38))))));
    init_collision_body_parts(arg0, boss6_type2_collision_parts, 3);
    ((TBoss6Type2 *)arg0)->advance_position();
    *(f32 *)((s8 *)arg0 + 0x310) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x30C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x308) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x2A8) = 0;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x2C)), (u8 *)(TLobby::dispatch_shared_handler_b(0x2C)), (u8 *)(TLobby::register_object(0x2C)));
    *(s16 *)((s8 *)arg0 + 0x33E) = *(s32 *)((s8 *)arg0 + 0x4F8) = *(s16 *)((s8 *)arg0 + 0x32C);
    ((TBoss3Volopt *)arg0)->reset_photon_effect();
    ((TObjEnemy *)arg0)->set_param(0x4E);
    id = (s8)((u8 *)arg2)[0x44] % 4;
    ((TObjChara *)arg0)->add_flags_2e4(TBoss6Type2__initial_actor_flag_masks[id]);
    *(s32 *)((s8 *)arg0 + 0x428) = id;
    *(s32 *)((s8 *)arg0 + 0x42C) = *(s32 *)((s8 *)arg0 + 0x430) = boss6_type2_variant_id_table[((s8)((u8 *)arg2)[0x44] >> 2) % 4];
    ((TBoss6Type2 *)arg0)->init_segment_range();
    {
    s32 k;
    for (k = 0; k < 2; k++) {
        Ent_802BE0D4 *e = &((Ents_802BE0D4 *)arg0)->ents[k];
        id = lbl_8047128C[k];
        e->a = TObjFish__sub_8001EDB0(*(s32 *)((s8 *)arg0 + 0x3FC), id);
        e->b = get_bml_model(*(s32 *)((s8 *)arg0 + 0x3FC), id);
    }
    }
    ((TBoss6Type2 *)arg0)->init_motion_entries();
    *(s32 *)((s8 *)arg0 + 0x764) = TObjFish__sub_800E3124((u8 *)boss6_type2_effect_desc_table, (s32)(arg0 + 0x59C));
    build_tables__14TBoss6PlotFalzFPvPvi(arg0 + 0x768, (void *)boss6_type2_plot_falz_entry_table, 2);
    *(s32 *)((s8 *)arg0 + 0x458) = create_zanzo__11TBoss6Type1FPvPvPv(arg0, 7, 0xF);
    *(s8 *)((s8 *)arg0 + 0x478) = 0;
    *(s32 *)((s8 *)arg0 + 0x47C) = 0x11;
    TBoss6Type2__sub_802BE4E0((s32 *)(arg0 + 0x480), (s32 *)boss6_type2_zero_vec);
    *(s32 *)((s8 *)arg0 + 0x480) = *(s32 *)((s8 *)arg0 + 0x60);
    VecCopy((Vec *)(arg0 + 0x484), (const Vec *)(arg0 + 0x38));
    *(s32 *)((s8 *)arg0 + 0x474) = 0;
    for (i = 0; i < 32; i++) {
        ((Arr_802BE0D4 *)arg0)->arr[i] = 0;
    }
    *(s32 *)((s8 *)arg0 + 0x418) = 0;
    *(f32 *)((s8 *)arg0 + 0x41C) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x420) = 0;
    *(s32 *)((s8 *)arg0 + 0x424) = 0;
    *(u16 *)((s8 *)arg0 + 0x464) = 0xFFFF;
    *(s16 *)((s8 *)arg0 + 0x466) = ((s16 (*)(void *))TBoss6Type2__sub_802BB694)(arg0);
    *(u16 *)((s8 *)arg0 + 0x468) = 0xFFFF;
    *(u16 *)((s8 *)arg0 + 0x46A) = 0xFFFF;
    *(s32 *)((s8 *)arg0 + 0x46C) = -1;
    *(s32 *)((s8 *)arg0 + 0x470) = 0;
    ((TBoss6Type2 *)arg0)->load_battle_params();
    set_screen_pos__11TBoss6Type2FPv(arg0);
    ((TBoss6Type2 *)arg0)->copy_anim_state();
    ((TBoss6Type2 *)arg0)->reset_attack_counter();
    ((TBoss6Type2 *)arg0)->reset_indices();
    *(f32 *)((s8 *)arg0 + 0x4FC) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x500) = 1.0f;
    *(s32 *)((s8 *)arg0 + 0x508) = 0;
    TBoss6Type2__sub_802BB818((TBoss6Type2 *)arg0, 0.0f);
    TBoss6Type2__sub_802BB768((T2_802BB768 *)arg0);
    TBoss6Rock::create_rock_pool((s32)arg0);
    TBoss6Type2__sub_802BA7B0(arg0);
    TBoss6Type2::capture_player_snapshots();
    ((TBoss6Type2 *)arg0)->cache_fish_params();
    ((TBoss6Type2 *)arg0)->init_collected_entries();
    ((TBoss6Type2 *)arg0)->set_fields_554();
    TBoss6Type2__sub_802B9D6C((Obj_802B9D6C *)arg0);
    ((TBoss6Type2 *)arg0)->spawn_particle_slot(0);
    ((TBoss6Type2 *)arg0)->spawn_particle_slot(1);
    ((TBoss6Type2 *)arg0)->spawn_particle_slot(2);
    ((TBoss6Type2 *)arg0)->spawn_particle_slot(3);
    ((TBoss6Type2 *)arg0)->spawn_particle_slot(4);
    ((TBoss6Type2 *)arg0)->spawn_particle_slot(5);
    ((TBoss6Type2 *)arg0)->set_action_state(0);
    return arg0_;
}
#undef arg2
#undef arg0
#pragma pop

void TBoss6Type2__sub_802BE4E0(s32 *arg0, s32 *arg1) {
    *arg0 = *arg1;
    *(ByteBlock_C *)((s32) arg0 + 4) = *(const ByteBlock_C *)((s32) arg1 + 4);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
s32 TBoss6Type2::create(s32 arg2_) {
    s32 arg0_;
    s32 parent;

    arg0_ = __nw__7TObjectFUl(0x7B4);
    if (arg0_ != 0) {
        parent = __nw__7TObjectFUl(0x20);
        if (parent != 0) {
            parent = __ct__11TObjControlFP7TObject(parent, tl_04);
        }
        arg0_ = TBoss6Type2__ct(arg0_, parent, arg2_);
    }
    return arg0_;
}
#pragma pop

void TBoss6Type2__vt42(void) {  }

void TBoss6Type2__vt43(void) {  }

void TBoss6Type2__vt44(void) {  }

void TBoss6Type2__vt45(void) {  }

void TBoss6Type2__vt46(void) {  }

void TBoss6Type2__vt47(void) {  }

void TBoss6Type2__vt48(void) {  }
}

